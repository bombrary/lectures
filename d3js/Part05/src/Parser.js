class State {
  constructor(str) {
    this.str = str;
    this.i = 0;
  }
  hasNext() {
    return this.i < this.str.length;
  }
  next() {
    this.i++;
  }
  now() {
    return this.str[this.i];
  }
  substr(s, t) {
    return this.str.slice(s, t);
  }
}

class TreeNode {
  constructor(kind, s) {
    this.kind = kind
    this.value = 0;
    this.str = '';
    this.range = [s.i, -1];
    this.children = [];
  }
  pushChild(child, update) {
    update(this, child);
    this.children.push(child);
  }
  setStrFrom(s) {
    this.range[1] = s.i;
    this.str = s.substr(...this.range);
  }
}


class Parser {
  constructor() { }
  parse(str) {
    return this.expr(new State(str));
  }
  expr(s) {
    const ret = new TreeNode('expr', s);

    ret.pushChild(this.term(s), (ret, child) => {
      ret.value = child.value;
    });
    
    while (s.hasNext()) {
      if (s.now() === '+') {
        ret.pushChild(this.op(s), () => {});
        s.next();
        ret.pushChild(this.term(s), (ret, child) => {
          ret.value += child.value;
        });
      } else if (s.now() === '-') {
        ret.pushChild(this.op(s), () => {});
        s.next();
        ret.pushChild(this.term(s), (ret, child) => {
          ret.value -= child.value;
        });
      } else {
        break;
      }
    }
    ret.setStrFrom(s);
    return ret;
  }
  term(s) {
    const ret = new TreeNode('term', s);

    ret.pushChild(this.fact(s), (ret, child) => {
      ret.value = child.value;
    });

    while (s.hasNext()) {
      if (s.now() === '*') {
        ret.pushChild(this.op(s), () => {});
        s.next();
        ret.pushChild(this.fact(s), (ret, child) => {
          ret.value *= child.value;
        });
      } else if (s.now() === '/') {
        ret.pushChild(this.op(s), () => {});
        s.next();
        ret.pushChild(this.fact(s), (ret, child) => {
          ret.value /= child.value;
        });
      } else {
        break;
      }
    }
    ret.setStrFrom(s);
    return ret;
  }
  fact(s) {
    const ret = new TreeNode('fact', s);

    if (s.now() === '(') {
      ret.pushChild(this.op(s), () => {});
      s.next();
      ret.pushChild(this.expr(s), (ret, child) => {
        ret.value = child.value;
      });
      ret.pushChild(this.op(s), () => {});
      s.next();
      ret.setStrFrom(s);
      return ret;
    } else {
      ret.pushChild(this.number(s), (ret, child) => {
        ret.value = child.value;
      });
      ret.setStrFrom(s);
      return ret;
    }
  }
  number(s) {
    const ret = new TreeNode('number', s);

    while (s.hasNext() && this.isDigit(s.now())) {
      ret.value *= 10;
      ret.value += Number(s.now());
      s.next();
    }
    ret.setStrFrom(s);
    return ret;
  }
  isDigit(c) {
    return !isNaN(c);
  }
  op(s) {
    const ret = new TreeNode('op', s);
    ret.range = [s.i, s.i + 1];
    ret.str = s.now();
    return ret;
  }
}
