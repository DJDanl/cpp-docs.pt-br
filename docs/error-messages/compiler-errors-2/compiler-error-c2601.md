---
title: Erro do compilador C2601
ms.date: 11/04/2016
f1_keywords:
- C2601
helpviewer_keywords:
- C2601
ms.assetid: 88275582-5f37-45d7-807d-05f06ba00965
ms.openlocfilehash: 87b5afe2133bb737a8f9c855b0652c2f50ca27ec
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74740514"
---
# <a name="compiler-error-c2601"></a>Erro do compilador C2601

' function ': definições de função local são ilegais

O código tenta definir uma função dentro de uma função.

Ou pode haver uma chave extra em seu código-fonte antes do local do erro C2601.

O exemplo a seguir gera C2601:

```cpp
// C2601.cpp
int main() {
   int i = 0;

   void funcname(int j) {   // C2601
      j++;
   }
}
```
