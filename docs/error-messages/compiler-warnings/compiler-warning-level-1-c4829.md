---
title: Aviso do compilador (nível 1) C4829
ms.date: 11/04/2016
f1_keywords:
- C4829
helpviewer_keywords:
- C4829
ms.assetid: 4ffabe2b-2ddc-4c52-8564-d1355c93cfa6
ms.openlocfilehash: a5c7cd062f22e9888e484f6d254fcf173cf83d1a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199375"
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
