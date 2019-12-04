---
title: Erro do compilador C2057
ms.date: 11/04/2016
f1_keywords:
- C2057
helpviewer_keywords:
- C2057
ms.assetid: 038a99d6-1f5a-42fa-8449-03b4ff11ee0b
ms.openlocfilehash: 37dbc2f6ae0614215f0a3de20baa601b48db9450
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74742438"
---
# <a name="compiler-error-c2057"></a>Erro do compilador C2057

expressão constante esperada

O contexto requer uma expressão constante, uma expressão cujo valor é conhecido no momento da compilação.

O compilador deve saber o tamanho de um tipo em tempo de compilação a fim de alocar espaço para uma instância desse tipo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2057 e mostra como corrigi-lo:

```cpp
// C2057.cpp
int i;
int b[i];   // C2057 - value of i is unknown at compile time
int main() {
   const int i = 8;
   int b[i]; // OK - value of i is fixed and known to compiler
}
```

## <a name="example"></a>Exemplo

C tem regras mais restritivas para expressões constantes.  O exemplo a seguir gera C2057 e mostra como corrigi-lo:

```
// C2057b.c
#define ArraySize1 10
int main() {
   const int ArraySize2 = 10;
   int h[ArraySize2];   // C2057 - C does not allow variables here
   int h[ArraySize1];   // OK - uses preprocessor constant
}
```
