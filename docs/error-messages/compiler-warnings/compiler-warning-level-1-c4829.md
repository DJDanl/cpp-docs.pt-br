---
title: Aviso do compilador (nível 1) C4829
ms.date: 11/04/2016
f1_keywords:
- C4829
helpviewer_keywords:
- C4829
ms.assetid: 4ffabe2b-2ddc-4c52-8564-d1355c93cfa6
ms.openlocfilehash: e8765f206d099f808ab261fbbde19273e46b5c90
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051237"
---
# <a name="compiler-warning-level-1-c4829"></a>Aviso do compilador (nível 1) C4829

Parâmetros possivelmente incorretos para função main. Considere ' intmain (Platform:: array\<plataforma:: String ^ > ^ argv) '

Determinadas funções, como Main, não podem ter parâmetros de tipo de referência. Enquanto a compilação for bem sucedido, a imagem resultante provavelmente não será executada.

O exemplo a seguir gera C4829:

```cpp
// C4829.cpp
// compile by using: cl /EHsc /ZW /W4 /c C4829.cpp
int main(Platform::String ^ s) {}   // C4829
```