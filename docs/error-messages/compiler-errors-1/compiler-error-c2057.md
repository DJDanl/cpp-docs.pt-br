---
title: Erro do compilador C2057
ms.date: 11/04/2016
f1_keywords:
- C2057
helpviewer_keywords:
- C2057
ms.assetid: 038a99d6-1f5a-42fa-8449-03b4ff11ee0b
ms.openlocfilehash: 1c873a0ba956adedea3311ac8e1844a629caa44b
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302023"
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

```c
// C2057b.c
#define ArraySize1 10
int main() {
   const int ArraySize2 = 10;
   int h[ArraySize2];   // C2057 - C does not allow variables here
   int h[ArraySize1];   // OK - uses preprocessor constant
}
```
