---
title: Erro do compilador C2854
ms.date: 11/04/2016
f1_keywords:
- C2854
helpviewer_keywords:
- C2854
ms.assetid: 917fec9c-790a-4149-8dfc-00d17a09199c
ms.openlocfilehash: 70b763afa4d511823a62d4d3770fc030ab9fb2ec
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745883"
---
# <a name="compiler-error-c2854"></a>Erro do compilador C2854

erro de sintaxe em #pragma hdrstop

O `#pragma hdrstop` fornece um nome de arquivo inválido. O pragma pode ser seguido por um nome de arquivo opcional entre parênteses e aspas:

O exemplo a seguir gera C2854:

```cpp
// C2854.cpp
// compile with: /c
#pragma hdrstop( "\\source\\pchfiles\\myheader.pch" ]   // C2854
// try the following line instead
// #pragma hdrstop( "\\source\\pchfiles\\myheader.pch" )
```
