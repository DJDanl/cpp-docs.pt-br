---
title: Compilador aviso (níveis 3 e 4) C4244 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4244
dev_langs:
- C++
helpviewer_keywords:
- C4244
ms.assetid: f116bb09-c479-4b4e-a647-fe629a1383f6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 55c862ee304c0ad0d95cbde34a5b6bb9b52798d9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46039498"
---
# <a name="compiler-warning-levels-3-and-4-c4244"></a>Compilador aviso (níveis 3 e 4) C4244

conversão de 'conversion' de 'type1' em 'type2', possível perda de dados

Um tipo inteiro é convertido em um tipo de inteiro menor. Este é um aviso de nível 4 se *type1* é `int` e *type2* é menor do que `int`. Caso contrário, ele é um nível 3 (atribuídos um valor do tipo [__int64](../../cpp/int8-int16-int32-int64.md) a uma variável do tipo `unsigned int`). Uma possível perda de dados pode ter ocorrido.

Se você receber C4244, você deve alterar seu programa usar tipos compatíveis ou adicionar alguma lógica ao seu código, para garantir que o intervalo de valores possíveis sempre será compatível com os tipos que você está usando.

Também pode ser acionado C4244 no nível 2; ver [aviso do compilador (nível 2) C4244](../../error-messages/compiler-warnings/compiler-warning-level-2-c4244.md) para obter mais informações.

A conversão pode ter um problema devido a conversões implícitas.

O exemplo a seguir gera C4244:

```
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

```
// C4244_level3.cpp
// compile with: /W3
int main() {
   __int64 i = 8;
   unsigned int ii = i;   // C4244
}
```

Aviso C4244 pode ocorrer quando a criação de código para destinos de 64 bits que não gera o aviso ao compilar para destinos de 32 bits. Por exemplo, uma diferença entre ponteiros é uma quantidade de 32 bits em plataformas de 32 bits, mas uma quantidade de 64 bits em plataformas de 64 bits.

O exemplo a seguir gera C4244 quando compilado para destinos de 64 bits:

```
// C4244_level3_b.cpp
// compile with: /W3
int main() {
   char* p1 = 0;
   char* p2 = 0;
   int x = p2 - p1;   // C4244
}
```