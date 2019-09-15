---
layout: default
title: SVG Tutorial
---

# SVG
## SVGとは
## ラスタ画像とベクタ画像
## svgタグ
#### width, height
CSSでも指定可能
## やってみる
### 原点に円を書く
#### circleタグ
属性
- r
- cx, cy
- fill, stroke
- stroke-width
#### 座標系
原点は右上
### 中央に長方形を書く
#### rectタグ
属性
- width,height
- x,y
### 文字を書く
#### textタグ
属性
- x,y
- dx,dy
- font-size
### メガネを中央に配置
#### gタグ
グループとしてまとめる
属性
- transform:移動とか回転とかを制御
  - translate
  - rotate
### グループ内でテキストを中央に
#### text-anchor
#### dominant-baseline
### 思い通りの直線/曲線を
#### pathタグ
lineタグもあるけどこっちのほうがJSにとって都合がよい(文字列処理できるため)
属性: d
#### d属性
- M
- L
- C

## chromeのデバッガを使おう
