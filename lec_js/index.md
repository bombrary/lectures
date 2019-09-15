---
layout: default
title: JavaScript Tutorial
---

# Cと比較するJavaScript

## JavaScriptとは

## オブジェクト指向言語
他言語とは異質な書き方
&rArr; ES6で機能追加されてふつうのクラスの書き方ができるようになった

### オブジェクトとは
あとで説明すると思う

## 関数型言語
## Hello, World(1)
## chromeのデバッガを使おう
console.log
## Hello, World(2)

## Cと同じところ
- forとかifとかの文法
- 変数の代入とかも同じ
- Cの演算子のほとんどはJSでも使える

## Cと違うところ
- 変数の型を明示しない
- forに複数の書き方がある
- 関数の書き方が違う&複数の書き方がある
- 型がCに比べて豊富
- オブジェクトという概念がある
- 文字/文字列の扱いが大分違う(文字型の配列ではない)
- printfみたいな書式指定の出力関数は無い(テンプレートリテラルという便利なものがあります)

## 変数
型を明示しない
暗黙の型変換がすごすぎる
配列もあるよ
違う型のものも代入し直せる

### let, const
- letはふつうの変数
- constは再代入不能な変数

スコープの扱いはCのときと同じ

### NG
- 何もつけないで変数宣言
- varをつけて宣言
これらはスコープの扱いが奇妙なので利用すべきでない

```js
x = 1;
var y = 0
```

## for文
とりあえずこの書き方ができることを覚えておくだけでよい

```js
a=[1,2,4,8];
for(let i=0; i<a.length; i++){
  console.log(a[i]);
}
```
```js
a=[1,2,4,8];
for(let e of a){
  console.log(e);
}
```

## 分割代入
- pythonでいうアンパックのこと
- 便利なので覚えておくとよい
```js
let [a, b] = [3, 4]
```

## 関数の書き方

### function(1)
```js
function add(a,b){
  return a+b;
}
```

### function(2)

```js
let add = function(a,b){
  return a+b;
};
```
- ここでのfunctionは無名関数と呼ばれる
- 関数を変数に代入している!

### アロー関数
```js
let add = (a,b)=>{
  return a+b;
};
```
前スライドの簡便記法かと思いきや、thisの扱いが違う
(JSの特徴にthisがありますが、ここではお話しません)

## データ型
6 種類のプリミティブデータ型:
- Boolean
- Null
- Undefined
- Number
- String
- Symbol
と
- Object
  これがさらにいくつかに分かれる
[Source](https://developer.mozilla.org/ja/docs/Web/JavaScript/Data_structures)

### あれ，配列は？
Object型の一種です

### 関数は?
- 関数もObject型の一種です
- 変数に代入できたり関数を返す関数が作れたりする

### 結局お世話になるのは
- Boolean
- Number
- String
- Object
  - 特にArray(とfunction)
だけ．
必要になったら他のも覚えよう

## オブジェクト
- 様々なデータをひとまとめにしたもの
- Cでいう構造体みたいなもの
- Cとは違って**関数が入れられる**
  **JSでは**これを特別に**メソッド**という

### 作ってみる
#### 点
```js
let x=1;
let y=3;
```
#### をまとめる
```js
let p = {
  x:1,
  y:3
};
console.log(p.x,p.y);
```
#### 線分
```js
let ps = {
  x:1,
  y:3
};
let pt = {
  x:5,
  y:6
};
```
#### をまとめる
```js
let l={
  ps:{ x:1, y:3 },
  pt:{ x:5, y:6 }
};
```
#### 距離を求める関数
```js
let l={
  ps:{ x:1, y:3 },
  pt:{ x:5, y:6 },
  dist: function(){
    const dx=this.ps.x-this.pt.x;
    const dy=this.ps.y-this.pt.y;
    return Math.sqrt(dx*dx+d*dy);
  }
};
console.log(l.dist());
```
#### もっとつくりたい
```js
l la=[
{
  ps:{ x:1, y:3 },
  pt:{ x:5, y:6 },
  dist: function(){
    const dx=this.ps.x-this.pt.x;
    const dy=this.ps.y-this.pt.y;
    return Math.sqrt(dx*dx+d*dy);
  }
},
{
  ps:{ x:1, y:3 },
  pt:{ x:4, y:2 },
  dist: function(){
    const dx=this.ps.x-this.pt.x;
    const dy=this.ps.y-this.pt.y;
    return Math.sqrt(dx*dx+d*dy);
  }
},
...
};
```
流石にこれは書きたくない

## クラス
Cでいう構造体宣言
初期化用の関数はconstructerで行う
newで宣言
### 書き直してみる

#### 点
```js
class Point(x,y){
  constructor(x,y){
    this.x=x;
    this.y=y;
  }
}
```
#### 線分
```js
class Line{
  constructor(xs,ys,xt,yt){
    this.ps={x:xs, y:ys};
    this.pt={x:xt, y:yt};
  }
  function dist(){
    const dx=this.ps.x-this.pt.x;
    const dy=this.ps.y-this.pt.y;
    return Math.sqrt(dx*dx+d*dy);
  }
}
```

#### 宣言
```js
let p=new Point(1,3);
let l=new Line(1,3,5,4);
```
#### 配列だってできる
```js
let la=[ 
  new Line(1,3,4,5),
  new Line(1,2,4,3),
  new Line(6,3,4,-1),
  new Line(5,3,4,0),
];
```

## Array
C++知っている人向け: 配列というよりunorderd_map
- というかすべてのObjectはハッシュテーブルで実装されてる
可変
要素がメモリ上で連続していることは保証されてない
pushやshiftがあるのでスタックとしてもキューとしても使える(計算量についてはここでは触れないことにする)

### 宣言
簡単
```js
let a = [];
```
### この使い方が多い気がする
pushして初期化
```js
for(let i=0; i<5; i++){
  a.push(0);
}
```
二次元配列の場合
```js
for(let i=0; i<5; i++){
  a.push([]);
  for(let j=0; j<5; j++){
    a[i].push(0);
  }
}
```

### 要素数指定(すごい注意)
```js
let a = new Array(5)
```
実はa.length=5になっただけで何も入ってない(入れる領域すら確保されてない(Objectはハッシュなので))

### fillというのが最近追加された
```js
let a = new Array(5).fill(0)
```
これで入れる領域は確保される

### アクセス
Cと同じ

### なんでも入れられる
```js
let a=[1,2.3,'Hello',new Point(1,3)];
```

## 文字列処理
- 再代入できないのがCとの大きな違い
- シングルクォーテーションとダブルクォーテーションの違いは無い
### immutableなオブジェクト
- 変更不可能なオブジェクトのこと
### 基本的な使い方
連結の演算子
```js
let h='Hello';
let w='world';
console.log(w+h+'Taro');
```
### split
- 指定された文字で文字列を分割して配列にする
- 「スペース区切りの文字列からデータを抽出したい」ときに重宝
```js
const str='Hello,world,Taro!';
const a=str.split(',');
console.log(a); 
```
### テンプレートリテラル
従来
```js
const t='Taro';
const str='Hello'+String(1234)+', '+t+'!';
```
テンプレートリテラル
```js
const t='Taro';
const str=`Hello${1234}, ${t}!;
```
短く書けて嬉しい

## 関数型プログラミング
ある問題を解こう、となったときに、この手順を「副作用の無い関数」の集まりで記述しよう、というプログラミングスタイル、だと思う。

### もっと簡単に
関数をふつうの変数みたいに扱って、「関数を引数にとるぜ」とか「関数を返す関数を作ろうぜ」とかやるスタイル

### コールバック関数
他の関数の引数にとして渡された関数のこと

### 自分で作ってみる
```js
function add(a,b,callback){
  return callback(a+b);
}
console.log(add(1,2,function(x){
  return x*x;
}));
```
アロー関数を使うと簡潔に書ける
```js
console.log(add(1,2,x=>x*x);
```

### map
- 配列の各要素に対して関数fを適用した結果を返す
- 配列自身は変更されない
```js
[1,3,5,7,9] -> [f(1),f(3),f(5),f(7),f(9)]
```
```js
const a=[1,3,5,7,9];
const b=a.map(x=>x*x);
console.log(b);
```
全てのデータをforループを使わずに整形できる

```js
const a=[1,3,5,7,9];
const b=a.map((x,i)=>i*x);
console.log(b);
```
第2引数にindexを指定できる

### forEach
- 配列の各要素に対して何か処理する
- for-of文の関数版

```js
const a=[1,3,5,7,9];
a.forEach((e,i)=>{
  console.log(`a[${i}]=${a[i]}`);
});
```

### reduce
- C++でいうacccumulate
- 配列の各要素に対して関数を実行して単一の値にする
```js
const a=[1,3,5,7,9];
const sum=a.reduce((acc, e)=>acc+e);
console.log(sum)
```
以下の操作と同義
```js
for (e of a){
  acc=acc+e;
}
return acc;
```
分散を書く
```js
const a=[1,3,5,7,9];
const sum=a.reduce((acc, e)=>acc+e);
const ave=sum/a.length;
const vari=a.reduce((acc, e)=>acc+(e-ave)*(e-ave));
console.log(sum);
```

### filter
条件を満たす要素だけ取り出して配列にして返す
```js
const a=[1,3,4,9,8,0,5,5];
const b=a.filter((e)=>e%2==1);
console.log(b);
```

## Web用の言語なのにWeb関係あるの？
今からやります

### DOM

HTML文書をプログラミングで扱い易くしたモデル
DOM APIを用いてアクセスする

### divがあります
```html
```
### getElementById
```js
const div0=getElementById('div0');
const p=div0.appendChild('p');
p.text('Hello, world!');
```

### addEventListener
```js
document.getElementById('btn0')
.addEventListener('onclick',e=>{
   document.getElementById('div0')
  .appendChild('p')
  .text('Hello, world!');
});
```
### D3.jsにおいては
- これらは使いません
- もっと簡単に書けるようにD3.jsがラッピングしてくれてる

## まだまだありますJavaScriptの機能
- promise
- クロージャ
- thisの扱い
- 諸々の型

## 参考
[ブラウザのしくみ: データ構造とアルゴリズムと雰囲気で理解する DOM と Shadow DOM ](https://hayato.io/2017/dom/)
