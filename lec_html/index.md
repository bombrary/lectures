---
layout: default
title: HTML Tutorial
---

# HTMLとCSS
## HTMLとは
## CSSとは
## 分業を心がける
HTMLで「文章の意味」をまとめる
- ここは見出しにしたい
- ここは段落にしたい
- ここはコンテンツを並べたい
CSSで文章を飾る
- この見出しの文字サイズを小さめに
- 余白をもう少しとったほうがよいな
- 背景色を変えよう

# HTML
## テンプレ(不完全)
```html
<html>
<head>
</head>
<body>
</body>
<\html>
```
これをファイル名.htmlで保存してダブルクリックすると、ブラウザが表示してくれる

### タグ(tag)
タグのルール:
入れ子にできる
### htmlタグ
### headタグ
### bodyタグ
## テンプレ(ほぼ完全)
```html
<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="utf-8">
<title>Hello Page</title>
</head>
<body>
</body>
<\html>
```
### 属性(attribute)
多くの場合CSSで代用できる
### titleタグ
### metaタグ

## タグ覚えゲー
HTMLはタグしかない

## 実際に何か書いてみよう
以降は，特に断りがない限りbodyタグの中身に書くものとします

### ちゃんと紹介するタグ
- p
- table
  - thead, tbody
  - tr, td
- ol, ul
  - li
- span
- div
- button
- textarea

### ちゃんと紹介しないけど大事なタグ

- a
- img
- h1,h2,...,h5
- header,footer
- article,section

### p
段落(paragraph)を記述するタグ。段落なのでタグごとに改行されている

### table
#### thead
#### tbody
#### tr
#### td
### ol
#### li
### ul
olと同じ書き方
### span
### div
括るだけのタグ
CSSと組み合わせて真価を発揮する
むやみにdivを使うのはやめましょう
他で代用できる「意味」のあるタグを探す
### button
### textarea

## 注意
文法エラーが起こらない

## chromeのデバッガを使おう
