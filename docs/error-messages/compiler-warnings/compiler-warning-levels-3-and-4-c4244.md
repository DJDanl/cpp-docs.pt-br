---
title: Aviso do compilador (níveis 3 e 4) C4244
ms.date: 11/04/2016
ms.assetid: f116bb09-c479-4b4e-a647-fe629a1383f6
ms.openlocfilehash: a12bee4591df8a7a952dc741c4b26c637bb5256c
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991080"
---
# <a name="compiler-warning-levels-3-and-4-c4244"></a>Aviso do compilador (níveis 3 e 4) C4244

conversão de ' conversão ' de ' type1 ' para ' type2 ', possível perda de dados

Um tipo inteiro é convertido em um tipo de inteiro menor. Esse é um aviso de nível 4 se *type1* for `int` e *type2* for menor do que `int`. Caso contrário, é um nível 3 (atribuído um valor do tipo [__int64](../../cpp/int8-int16-int32-int64.md) a uma variável do tipo `unsigned int`). Pode ter ocorrido uma possível perda de dados.

Se você receber C4244, deverá alterar seu programa para usar tipos compatíveis ou adicionar alguma lógica ao seu código, para garantir que o intervalo de valores possíveis sempre seja compatível com os tipos que você está usando.

O C4244 também pode ser acionado no nível 2; consulte [aviso do compilador (nível 2) C4244](../../error-messages/compiler-warnings/compiler-warning-level-2-c4244.md) para obter mais informações.

A conversão pode ter um problema devido a conversões implícitas.

O exemplo a seguir gera C4244:

```cpp
// C4244_level4.cpp
// compile with: /W4
int aa;
unsigned short bb;
int main() {
   int b = 0, c = 0;
   short a = b + c;   // C4244

   bb += c;   // C4244
   bb = bb + c;   // C4244
   bb += (unsigned short)aa;   // C4244
   bb = bb + (unsigned short)aa;   // OK
}
```

Para obter mais informações, consulte [conversões aritméticas usuais](../../c-language/usual-arithmetic-conversions.md).

```cpp
// C4244_level3.cpp
// compile with: /W3
int main() {
   __int64 i = 8;
   unsigned int ii = i;   // C4244
}
```

Aviso C4244 pode ocorrer ao compilar código para destinos de 64 bits que não gera o aviso ao compilar para destinos de 32 bits. Por exemplo, uma diferença entre ponteiros é uma quantidade de 32 bits em plataformas de 32 bits, mas uma quantidade de 64 bits em plataformas de 64 bits.

O exemplo a seguir gera C4244 quando compilado para destinos de 64 bits:

```cpp
// C4244_level3_b.cpp
// compile with: /W3
int main() {
   char* p1 = 0;
   char* p2 = 0;
   int x = p2 - p1;   // C4244
}
```
