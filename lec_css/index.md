---
layout: default
title: CSS Tutorial
putsection: true
genindex: true
---

<link rel="stylesheet" href="style.css">

# CSS

CSSを学びましょう。HTMLを学んでいる人が前提知識となるので、不安な方は[HTMLチュートリアル](/lec_html/)を読みましょう。
CSSとHTMLについての説明、使い分けについてもそちらで説明しています。

## CSSを含めたテンプレ

まずはindex.htmlを作成し、以下の内容を書きます。

```html
<!DOCTYPE html>
<html lang="ja">
  <head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="style.css">
    <title>Hello Page</title>
  </head>
  <body>
  </body>
</html>
```

## style.css?

CSSファイルを読み込むのは以下のlinkタグです。
linkタグとは、外部の文書ファイルを読み込むタグです。
rel属性はrelationの略で、読み込むファイルがどんな種類なのかを指定しています。
ここではstylesheetを指定していて、これは読み込みファイルがCSSファイルであることを示しています。
href属性で読み込みファイルを指定しています。

```html
<link rel="stylesheet" href="style.css">
```

### style.cssを作ろう

style.cssを作っておきます。index.htmlと同じディレクトリにファイルを作成し、これをstyle.cssという名前のファイルで保存しておきます。
ファイルの内容は以下のようにしておきます。

```css
@charset "utf-8";
```

cssファイルでは、先頭にcharsetいう文をつけて、ファイルの文字コードを設定します。
これより下に色々な文を書いていきます。

## 例
実際にCSSがどんな風に書かれるのかを見ていきましょう。
まずindex.htmlで適当に文章を作成します。body要素については、
HTMLチュートリアルの時と同じコードを用います。

```html
<!DOCTYPE html>
<html lang="ja">
  <head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="style.css">
    <title>Hello Page</title>
  </head>
  <body>
    <h1>テーブル</h1>

    <img src="img/fantasy_pixy2.png" width="200px">

    <p>私はテーブルの妖精です。テーブルを作るのが仕事です。以下は私が作ったテーブルです。見納めください。</p>
    <table>
      <thead>
        <tr><th>商品名</th><th>値段</th><th>産地</th></tr>
      </thead>
      <tbody>
        <tr><td>りんご</td><td>1000円</td><td>りんご王国</td></tr>
        <tr><td>みかん</td><td>2300円</td><td>みかん王国</td></tr>
        <tr><td>バナナ</td><td>13200円</td><td>南国</td></tr>
      </tbody>
    </table>

    <h2>特徴</h2>
    <p>私が作ったテーブルには以下の特徴があります。</p>
    <ul>
      <li>商品名が書かれている</li>
      <li>値段が結構高い</li>
    </ul>

    <h2>感想などはこちらから</h2>
    <p>気に入ってくれた人は以下のフォームに感想を記入してください。</p>
      <form>
        <textarea></textarea>
        <p><input type="button" value="提出"></p>
        <p><label for="fav_check">面白かった: </label><input id="fav_check" type="checkbox"></p>
      </form>

    <p>サンプルなので<span style="color: red;">クリック</span>しても何も起こりません。</p>
    <p>Googleに飛びましょう、<a href="https://www.google.com">Let's Go!</a></p>
  </body>
</html>
```

画像表示のために、[こちらの「いらすとや」](https://www.irasutoya.com/2013/05/blog-post.html)から、妖精の画像をダウンロードしましょう。
画像を右クリックして、「画像を保存」「画像をダウンロード」のような文面のボタンを選択します。
画像ファイル名はデフォルトで「fantasy_pixy2.png」になっていると思います。ダウンロードした画像ですが、
index.htmlファイルと同じディレクトリにimgディレクトリを新たに作成し、その中に入れます。
ディレクトリ構成は以下の通りになります。

<img src="img/dir.png" width="400px">

結果は以下のようになります。

<div class="output">
  <h1>テーブル</h1>

  <img src="img/fantasy_pixy2.png" width="200px">

  <p>私はテーブルの妖精です。テーブルを作るのが仕事です。以下は私が作ったテーブルです。見納めください。</p>
  <table>
    <thead>
      <tr><th>商品名</th><th>値段</th><th>産地</th></tr>
    </thead>
    <tbody>
      <tr><td>りんご</td><td>1000円</td><td>りんご王国</td></tr>
      <tr><td>みかん</td><td>2300円</td><td>みかん王国</td></tr>
      <tr><td>バナナ</td><td>13200円</td><td>南国</td></tr>
    </tbody>
  </table>

  <h2>特徴</h2>
  <p>私が作ったテーブルには以下の特徴があります。</p>
  <ul>
    <li>商品名が書かれている</li>
    <li>値段が結構高い</li>
  </ul>

  <h2>感想などはこちらから</h2>
  <p>気に入ってくれた人は以下のフォームに感想を記入してください。</p>
    <form>
      <textarea></textarea>
      <p><input type="button" value="提出"></p>
      <p><label for="fav_check">面白かった: </label><input id="fav_check" type="checkbox"></p>
    </form>

  <p>サンプルなので<span style="color: red;">クリック</span>しても何も起こりません。</p>
  <p>Googleに飛びましょう、<a href="https://www.google.com">Let's Go!</a></p>
</div>

## Step01: 枠線

さてお待ちかね、CSSを書いていきます。style.cssに以下の文を書き足します。

```css
h1 {
  border-left: 5px solid #1E88E5;
  border-bottom: 2px dotted #1E88E5;
}
```

h1タグが以下のような見出しで描画されます。


<div class="output">
  <h1 style="border-left: 5px solid #1E88E5; border-bottom: 2px dotted #1E88E5;">テーブル</h1>
</div>

### CSSの方法
CSSの基本は、「要素を**選択**して**装飾**」することです。

- どの要素を選択するかを決める文法を**セレクタ**と言います。
- 装飾するための文法のことを**プロパティ**と言います。

次のような書式で書きます。

```text
セレクタ {
  プロパティ名: 値;
  プロパティ名: 値;
  ...
}
```

なので、次のような書き方で、「h1要素に対して2つのプロパティを設定している」ことがわかります。
```css
h1 {
  border-left: 5px solid #1E88E5;
  border-bottom: 2px dotted #1E88E5;
}
```

### セレクタ
セレクタとして単にh1と書くだけで、h1要素を選択することができることが、先ほどの例でわかりました。
要素名で指定するセレクタを「**要素セレクタ**」と呼びますが、もちろんこれ以外にもセレクタはたくさんあります。
セレクタを覚えることで、より柔軟に要素を選択することができるようになります。

また、JavaScriptやそのライブラリであるJQueryやD3.jsにおいても、同じような文法を用いて要素を選択することがあります。

最低限、以下のセレクタを覚えておきましょう。

- 要素セレクタ(今やった)
- クラスセレクタ(後でやる)
- 子孫セレクタ(後でやる)

### プロパティ

余白、色、枠線などの様々な装飾要素はプロパティで指定します。
プロパティはセレクタ以上に大量にあります。また、どんなプロパティが適用できるのかは要素によります。
経験を重ねて、様々なスタイルを覚えていきましょう。

### borderプロパティ

枠線を設定するプロパティです。
必ず「線の太さ 線のスタイル 線の色」という順で指定します。
線のスタイルとしてどんなものが指定できるのかについては
[border - スタイルシートリファレンス](http://www.htmq.com/style/border.shtml)を参照してください。
以下はsolidを指定しているので、実線が引かれます。

色設定については後で補足します。

```html
<p>Hello</p>
```

```css
p {
  border: 1px solid #000;
}
```

<div class="output">
<p style="border: 1px solid #000">Hello</p>
</div>

#### border-&#x25cb;&#x25cb;&#x25cb;プロパティ

borderプロパティは四方の枠線を指定します。
しかし、それだと例えば「左だけ枠線を追加したい」などの要求に答えられません。
そんな人のために、個別で設定できるborder-left/border-right/border-bottom/border-topプロパティがあります。

```html
<p>Hello</p>
```

```css
p {
  border-left: 3px double #1E88E5;
  border-bottom: 3px double #1E88E5;
}
```

<div class="output">
  <p style="border-left: 3px double #1e88e5; border-bottom: 3px double #1e88e5;">Hello</p>
</div>



#### 補足: 色指定

色を指定する方法にはいくつかありますが、ここでは「カラーコードで指定する方法」と「色名で指定する方法」があります。

##### カラーコードで指定する方法  
カラーコードは必ず#で始まり、その後16進数の数字が6つ続きます。
先頭の2桁が赤、次の2桁が緑、最後の2桁が青を表します。RGBという順番で覚えておきましょう。
数字が大きいほどその色の成分が強くなり、例えば`#00ff00`は緑色を表したり、`#ffff00`は黄色を表したりします。
また簡便記法として**3桁のみで記述する方法**があります。例えば`#0f0`は`#00ff00`と同義であり、`#ff0`は`#ffff00`と同義です。

```html
<p>Hello</p>
```
```css
p {
  border: 1px solid #00ff00;
}
```
<div class="output">
<p style="border: 1px solid #00ff00;">Hello</p>
</div>

いい感じの色を探したいなら[Flat UI Colors](https://flatuicolors.com)をお勧めします。フラットデザインに適した色を集めたサイトです。

##### 色名で指定する方法  
CSSであらかじめ用意された色名で指定する方法があります。どんなものがあるかは[color - MDN](https://developer.mozilla.org/ja/docs/Web/CSS/color_value)で確認できます。

```html
<p>Hello</p>
```
```css
p {
  border: 1px solid orangered;
}
```
<div class="output">
<p style="border: 1px solid orangered;">Hello</p>
</div>

### style.cssの修正

h2にも同じスタイルを指定しましょう。
style.cssを次のように修正します。

```css
h1, h2 {
  border-left: 5px solid #1E88E5;
  border-bottom: 2px dotted #1E88E5;
}
```

**カンマで区切ることで、複数要素を選択することができます**。これで、h1とh2に同じプロパティを設定することができました。


## Step02: 背景色と文字色

style.cssに以下の文を書き足します。

```css
thead tr {
  background-color: #2196f3;
  color: white;
}

tbody tr:nth-child(odd) {
  background-color: #e3f2fd;
}

ul {
  border: 1px solid #888;
  background-color: #eee;
}
```

これだけでいい感じの装飾になります。

<div class="output css-sample02">
  <h1>テーブル</h1>

  <img src="img/fantasy_pixy2.png" width="200px">

  <p>私はテーブルの妖精です。テーブルを作るのが仕事です。以下は私が作ったテーブルです。見納めください。</p>
  <table>
    <thead>
      <tr><th>商品名</th><th>値段</th><th>産地</th></tr>
    </thead>
    <tbody>
      <tr><td>りんご</td><td>1000円</td><td>りんご王国</td></tr>
      <tr><td>みかん</td><td>2300円</td><td>みかん王国</td></tr>
      <tr><td>バナナ</td><td>13200円</td><td>南国</td></tr>
    </tbody>
  </table>

  <h2>特徴</h2>
  <p>私が作ったテーブルには以下の特徴があります。</p>
  <ul>
    <li>商品名が書かれている</li>
    <li>値段が結構高い</li>
  </ul>

  <h2>感想などはこちらから</h2>
  <p>気に入ってくれた人は以下のフォームに感想を記入してください。</p>
    <form>
      <textarea></textarea>
      <p><input type="button" value="提出"></p>
      <p><label for="fav_check">面白かった: </label><input id="fav_check" type="checkbox"></p>
    </form>

  <p>サンプルなので<span style="color: red;">クリック</span>しても何も起こりません。</p>
  <p>Googleに飛びましょう、<a href="https://www.google.com">Let's Go!</a></p>
</div>

新しいプロパティとセレクタが出てきましたので、紹介します。

### background-colorプロパティ

要素の背景色を指定するプロパティです。

```html
<p>Hello</p>
```
```css
p {
  background-color: skyblue;
}
```
<div class="output">
  <p style="background-color: skyblue">Hello</p>
</div>

### colorプロパティ

文字色を指定するプロパティです。
```html
<p>Hello</p>
```
```css
p {
  color: skyblue;
}
```
<div class="output">
  <p style="color: skyblue;">Hello</p>
</div>

### 子孫セレクタ

**A B Cのようにスペースキーで区切って要素を指定すると、「Aの要素に含まれるBを選択し、さらにBに含まれるCを選択する」という意味になります**。
この記法を「**子孫セレクタ**」と呼びます。

次のようなhtmlファイルがあったとします。

```html
<p>Hello</p>
<ul>
  <li><p>Taro</p></li>
  <li><p>Jiro</p></li>
  <li>
    <p>Saburo</p>
    <p>Shiro</p>
  </li>
</ul>
```

以下は、「liの中のpに対してborder-bottomプロパティを指定する」という意味になります。

```css
li p {
  border-bottom: 3px double #000;
}
```

liに包まれたpには下線が引かれ、liの外にあるp(Helloという文字列)は下線が引かれていないことがわかります。

<div class="output css-sample02-02">
  <p>Hello</p>
  <ul>
    <li><p>Taro</p></li>
    <li><p>Jiro</p></li>
    <li>
      <p>Saburo</p>
      <p>Shiro</p>
    </li>
  </ul>
</div>

### クラスセレクタ

例えば、「ある特定のリストのみ装飾したい」というケースがあるかもしれません。
そんな時に、クラスセレクタが威力を発揮します。

まずは、**装飾したい特定の要素にclass属性**を指定します。
今回は、「果物リストは赤枠線で、人々リストは青枠線で囲みたい」というケースを想定します。

```html
<ul class="fruit">
  <li>Apple</li>
  <li>Orange</li>
  <li>Banana</li>
</ul>

<ul class="people">
  <li>Taro</li>
  <li>Jiro</li>
  <li>Saburo</li>
</ul>
```

CSSは以下のように設定します。
この`.クラス名`という書式がクラスセレクタです。
クラス名とclass属性が合致する要素が選択されます。
```css
.fruit {
  border: 1px solid salmon;
}
.people {
  border: 1px solid steelblue;
}
```

<div class="output css-sample02-03">
  <ul class="fruit">
    <li>Apple</li>
    <li>Orange</li>
    <li>Banana</li>
  </ul>

  <ul class="people">
    <li>Taro</li>
    <li>Jiro</li>
    <li>Saburo</li>
  </ul>
</div>

もし「ulのうち、あるクラスに属するもの」という風に要素を絞りたい場合は次のように書きます。

```css
ul.fruit {
  border: 1px solid salmon;
}
ul.people {
  border: 1px solid steelblue;
}
```

### 擬似クラスセレクタ

**特定の状態を表すクラスを擬似クラス(pseudo-class)と呼びます**。ある要素の擬似クラスを指定したいときは、`要素:擬似クラス`と書きます。
擬似クラスにも色々ありますが、とりあえずfirst-child、last-childとnth-childを初めに紹介します。

#### first-child/last-child

first-childは選択された要素のうち最初の要素を表す擬似クラスです。
last-childは選択された要素のうち最後の要素を表す擬似クラスです。

```html
<ul>
  <li>Apple</li>
  <li>Orange</li>
  <li>Banana</li>
</ul>
```

```css
ul li:first-child {
  color: red;
}
```

<div class="output css-sample02-04">
  <ul>
    <li>Apple</li>
    <li>Orange</li>
    <li>Banana</li>
  </ul>
</div>

#### nth-child()

first-child/last-childよりも柔軟な指定ができる擬似クラスです。

- nth-child(An+B): AとBには整数値を指定する。An+Bで表せる番号の色が変化します。番号は1から始まります。  
  例: nth-child(4)で4番めの要素を選択
- nth-child(odd): 奇数番目の要素を指定する
- nth-child(even): 偶数番目の要素を指定する

```html
<ul>
  <li>Apple</li>
  <li>Orange</li>
  <li>Banana</li>
</ul>
```

```css
ul li:nth-child(odd) {
  color: orange;
}
```

<div class="output css-sample02-05">
  <ul class="fruit">
    <li>Apple</li>
    <li>Orange</li>
    <li>Banana</li>
  </ul>
</div>


## Step03: Padding

<div class="output">
<h1 style="border-left:5px solid #1e88e5; border-bottom:2px dotted #1e88e5;">テーブル</h1>
</div>

なんか左側が詰まってる感じがありません？余白を開けましょう。

style.cssのh1,h2要素について、プロパティを追加します。

```css
h1, h2 {
  border-left: 5px solid #1E88E5;
  border-bottom: 2px dotted #1E88E5;
  padding-left: 10px;
}
```

いい感じになりました。

<div class="output">
<h1 style="padding-left: 10px; border-left:5px solid #1e88e5; border-bottom:2px dotted #1e88e5;">テーブル</h1>
</div>

### paddingプロパティ

**要素内部の余白(padding)**を指定するプロパティです。
borderの時と同様、padding-left/padding-right/padding-bottom/padding-topプロパティがあります。
それだけでなく、paddingプロパティ単体でも様々な書式を持っています。

```css
/* 上下左右のpaddingを10pxにする */
padding: 10px; 
/* 上下のpaddingを10px、左右のpaddingを5pxにする */
padding: 10px 5px; 
/* 上、左右、下の順に指定 */
padding: 5px 10px 5px; 
/* 上右下左(上から初めて時計回り)の順に指定 */
padding: 5px 10px 5px 10px; 
```

単位としてpxを設定していますが、0の場合は単位は必要ありません。

## Step04: Margin

<div class="output css-sample02">
<ul >
<li>商品名が書かれている</li>
<li>値段が結構高い</li>
</ul>
</div>

なんか詰まっている感じがしませんか? 二つのliとの間隔を空けたいです。

style.cssに以下の文を追記します。

```css
li {
  margin: 5px 0;
}
```

いい感じですね。

<div class="output css-sample04">
<ul>
<li>商品名が書かれている</li>
<li>値段が結構高い</li>
</ul>
</div>

### marginプロパティ

**要素外部の余白(margin)**を指定するプロパティです。
書式についてはpaddingと同様です。
paddingとの違いをちゃんと意識しましょう。

#### paddingとmargin

念のため比較用のコードを書いてみます。
背景色と枠線を設定しておきます。

```html
<ul>
  <li>Apple</li>
  <li>Orange</li>
  <li>Banana</li>
</ul>
```

```css
li {
  border: 1px solid #333;
  background-color: #ccc;
}
```
<div class="output css-sample04-02">
  <ul>
    <li>Apple</li>
    <li>Orange</li>
    <li>Banana</li>
  </ul>
</div>

paddingとmarginの指定の違いを以下に見せます。

##### paddingの場合
```css
li {
  border: 1px solid #333;
  background-color: #ccc;
  padding: 10px 0;
}
```

要素内部の余白が上下方向に10px空きます。
<div class="output css-sample04-03">
  <ul>
    <li>Apple</li>
    <li>Orange</li>
    <li>Banana</li>
  </ul>
</div>

##### marginの場合

```css
li {
  border: 1px solid #333;
  background-color: #ccc;
  margin: 10px 0;
}
```

要素外部の余白が上下方向に10px空きます。
<div class="output css-sample04-04">
  <ul>
    <li>Apple</li>
    <li>Orange</li>
    <li>Banana</li>
  </ul>
</div>


画像とテーブルが中央寄せになりました。

## ここまでのstyle.css

paddingとmarginを少しいじった結果を記しておきます。

```css
@charset "utf-8";

h1, h2 {
  border-left: 5px solid #1E88E5;
  border-bottom: 2px dotted #1E88E5;
  padding-left: 10px;
}

th, td {
  padding: 5px;
}

thead tr {
  background-color: #2196F3;
  color: white;
}

tbody tr:nth-child(odd) {
  background-color: #E3F2FD;
}

ul {
  border: 1px solid #888;
  background-color: #eee;
  color: #000;
  margin: 0 0 0 20px;
  padding: 10px 20px;
}

li {
  margin-top: 5px;
}
```

<div class="css-sample04-05 output">
  <h1>テーブル</h1>

  <img src="img/fantasy_pixy2.png" width="200px">

  <p>私はテーブルの妖精です。テーブルを作るのが仕事です。以下は私が作ったテーブルです。見納めください。</p>
  <table>
    <thead>
      <tr><th>商品名</th><th>値段</th><th>産地</th></tr>
    </thead>
    <tbody>
      <tr><td>りんご</td><td>1000円</td><td>りんご王国</td></tr>
      <tr><td>みかん</td><td>2300円</td><td>みかん王国</td></tr>
      <tr><td>バナナ</td><td>13200円</td><td>南国</td></tr>
    </tbody>
  </table>

  <h2>特徴</h2>
  <p>私が作ったテーブルには以下の特徴があります。</p>
  <ul>
    <li>商品名が書かれている</li>
    <li>値段が結構高い</li>
  </ul>

  <h2>感想などはこちらから</h2>
  <p>気に入ってくれた人は以下のフォームに感想を記入してください。</p>
    <form>
      <textarea></textarea>
      <p><input type="button" value="提出"></p>
      <p><label for="fav_check">面白かった: </label><input id="fav_check" type="checkbox"></p>
    </form>

  <p>サンプルなので<span style="color: red;">クリック</span>しても何も起こりません。</p>
  <p>Googleに飛びましょう、<a href="https://www.google.com">Let's Go!</a></p>
</div>

## Step05: 要素の表示形式

以下の灰色領域が横に伸びてしまい、右側の空白が気になります。
これをなんとか解決できないでしょうか。

<div class="css-sample04-05 output">
  <ul>
    <li>商品名が書かれている</li>
    <li>値段が結構高い</li>
  </ul>
</div>

できます。以下のように、ulのプロパティとしてdisplayを追加します。

```css
ul {
  display: inline-block;
  border: 1px solid #888;
  background-color: #eee;
  color: #000;
  margin: 0 0 0 20px;
  padding: 10px 20px;
}
```

<div class="css-sample05 output">
  <ul>
    <li>商品名が書かれている</li>
    <li>値段が結構高い</li>
  </ul>
</div>

### displayプロパティ

要素の表示形式を指定するプロパティです。指定できる形式は様々ですが、ここではひとまず

- inline
- block
- inline-block

の3点について説明します。

#### inline

inlineが指定された要素は、テキストの一部のように扱われます。
大きな特徴は次の2点です。

- **ある要素があった場合、その横に配置される**
- **widthやheightを指定することができず、自動で要素の大きさを変える**

デフォルトでinlineである要素はaやspanです。
```html
<p>
  <span style="border: 1px solid red;">Hello</span>,
  <span style="border: 1px solid blue;">World</span>
</p>
```

<div class="output">
<p>
  <span style="border: 1px solid red;">Hello</span>,
  <span style="border: 1px solid blue;">World</span>
</p>
</div>

#### block

blockが指定された要素は、文書のあるひとかたまりのように扱われます。
大きな特徴は次の2点です。

- **ある要素があった場合、改行されて次の行に配置される**
- **widthやheightを指定して、自由に大きさを変えられる**

デフォルトでblockである要素はliやdivです。

```html
<ul>
  <li style="border: 1px solid red;">Hello</li>
  <li style="border: 1px solid blue;">World</li>
</ul>
```

<div class="output">
<ul>
  <li style="border: 1px solid red;">Hello</li>
  <li style="border: 1px solid blue;">World</li>
</ul>
</div>

#### inline-block

inlineとblockの特徴を混ぜたような表示形式です。

- **ある要素があった場合、その横に配置される**
- **widthやheightを指定して、自由に大きさを変えられる**
  ただし、**width/heightを指定しない場合は自動伸縮する**

ということで、ul要素に`display:inline-block`を指定すると、以下のようになります。
```html
<ul style="display: inline-block;">
  <li style="border: 1px solid red;">Hello</li>
  <li style="border: 1px solid blue;">World</li>
</ul>
```

<div class="output">
  <ul style="display: inline-block;">
    <li style="border: 1px solid red;">Hello</li>
    <li style="border: 1px solid blue;">World</li>
  </ul>
</div>

他に重要なdisplayの値として**flex**というものがあります。
これについては後で説明します。

## Step06: 色々寄せる

次のような要求を叶えましょう。

- 画像とテーブルを中央寄せしたい
- テーブルの文章を寄せたい

style.cssに以下の文を付け足します。

```css
img {
  display: block;
  margin: 0 auto;
}
table {
  margin: 0 auto;
}
th {
  text-align: center;
}
td {
  text-align: right;
}
```

<div class="css-sample06 output">
  <h1>テーブル</h1>

  <img src="img/fantasy_pixy2.png" width="200px">

  <p>私はテーブルの妖精です。テーブルを作るのが仕事です。以下は私が作ったテーブルです。見納めください。</p>
  <table>
    <thead>
      <tr><th>商品名</th><th>値段</th><th>産地</th></tr>
    </thead>
    <tbody>
      <tr><td>りんご</td><td>1000円</td><td>りんご王国</td></tr>
      <tr><td>みかん</td><td>2300円</td><td>みかん王国</td></tr>
      <tr><td>バナナ</td><td>13200円</td><td>南国</td></tr>
    </tbody>
  </table>

  <h2>特徴</h2>
  <p>私が作ったテーブルには以下の特徴があります。</p>
  <ul>
    <li>商品名が書かれている</li>
    <li>値段が結構高い</li>
  </ul>

  <h2>感想などはこちらから</h2>
  <p>気に入ってくれた人は以下のフォームに感想を記入してください。</p>
    <form>
      <textarea></textarea>
      <p><input type="button" value="提出"></p>
      <p><label for="fav_check">面白かった: </label><input id="fav_check" type="checkbox"></p>
    </form>

  <p>サンプルなので<span style="color: red;">クリック</span>しても何も起こりません。</p>
  <p>Googleに飛びましょう、<a href="https://www.google.com">Let's Go!</a></p>
</div>


### block要素を中央寄せする

marginプロパティにautoをつけると、marginを自動計算してくれます。これによって、**コンテンツの中央寄せ**を実現できます。

style.cssに以下の文を付け足します。

```css
@charset "utf-8";

h1, h2 {
  border-left: 5px solid #1E88E5;
  border-bottom: 2px dotted #1E88E5;
  padding-left: 10px;
}

img {
  display: block;
  margin: 0 auto;
}

table {
  border-collapse: collapse;
  margin: 0 auto;
}
th, td{
  padding: 5px;
  font-size: 18px;
}

th {
  text-align: center;
}

td {
  text-align: right;
}
th {
  background-color: #2196F3;
  color: white;
}

tr:nth-child(odd) {
  background-color: #E3F2FD;
}

ul{
  display: inline-block;
  list-style-type: none;
  border: 1px solid #888;
  background-color: #eee;
  color: #000;
  margin: 0 0 0 20px;
  padding: 10px 20px;
  font-weight: bold;
}

li {
  margin-top: 5px;
}

textarea {
  resize: none;
  width: 200px;
  height: 200px;
}

form p {
  padding: 0;
  margin: 0;
}

form input[type="button"] {
  background-color: #2196F3; 
  width: 50px;
  height: 25px;
  color: white;
  border: none;
  font-weight: bold;
  font-size: 12px;
}
form input[type="button"]:hover {
  color: #2196F3; 
  background-color: white;
}
```

<div class="css-sample output">
  <h1>テーブル</h1>

  <img src="img/fantasy_pixy2.png" width="200px">

  <p>私はテーブルの妖精です。テーブルを作るのが仕事です。以下は私が作ったテーブルです。見納めください。</p>
  <table>
    <thead>
      <tr><th>商品名</th><th>値段</th><th>産地</th></tr>
    </thead>
    <tbody>
      <tr><td>りんご</td><td>1000円</td><td>りんご王国</td></tr>
      <tr><td>みかん</td><td>2300円</td><td>みかん王国</td></tr>
      <tr><td>バナナ</td><td>13200円</td><td>南国</td></tr>
    </tbody>
  </table>

  <h2>特徴</h2>
  <p>私が作ったテーブルには以下の特徴があります。</p>
  <ul>
    <li>商品名が書かれている</li>
    <li>値段が結構高い</li>
  </ul>

  <h2>感想などはこちらから</h2>
  <p>気に入ってくれた人は以下のフォームに感想を記入してください。</p>
    <form>
      <textarea></textarea>
      <p><input type="button" value="提出"></p>
      <p><label for="fav_check">面白かった: </label><input id="fav_check" type="checkbox"></p>
    </form>

  <p>サンプルなので<span style="color: red;">クリック</span>しても何も起こりません。</p>
  <p>Googleに飛びましょう、<a href="https://www.google.com">Let's Go!</a></p>
</div>



## 紹介するスタイル
- background-color, color
- font-size
- margin, padding
- display:flex

## やってみよう
### ページの背景色変更
#### タグ名を指定するセレクタ
#### background-color
#### カラーコード
### フォントを大きくする
#### font-size
### ある特定の段落だけ文字色，背景色を変えたい
#### クラス
#### クラスセレクタ
#### color
### 余白がもうちょい欲しい
#### padding
### タグとの感覚を空けたい
#### margin
### 特定の段落の特定の文字の色を変えたい
#### 子孫セレクタ
スペースで区切るだけ
### 枠で囲みたい，大きさ固定
#### divタグの有用性
#### widthとheight

## inlineとblock

## flex
### はじめに
物体を横に並べたい欲求
昔はfloatを巧みに使っていた
### flex
新しいCSSから
コンテンツを並べるのが柔軟になった
```css
display:flex
```
#### display
### 横並べにしたい
#### flex-direction
### 縦並べにしたい
### 左右中央寄せにしたい
#### justify-content
### 上下中央寄せにしたい
#### align-items

## chromeのデバッガを使おう
