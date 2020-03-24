---
title: Aviso do compilador (nível 3) C4414
ms.date: 11/04/2016
f1_keywords:
- C4414
helpviewer_keywords:
- C4414
ms.assetid: bc81d3ad-55dc-4a6b-a6f2-ec0ef38347df
ms.openlocfilehash: 4625f6bdb4aa6fe86ca881a8e36e5673e55ccb87
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185588"
---
# <a name="compiler-warning-level-3-c4414"></a>Aviso do compilador (nível 3) C4414

' function ': salto curto para função convertido para Near

Os saltos curtos geram uma instrução de compactação que ramifica para um endereço dentro de um intervalo limitado da instrução. A instrução inclui um pequeno deslocamento que representa a distância entre o salto e o endereço de destino, a definição da função. Durante a vinculação, uma função pode ser movida ou sujeita a otimizações de tempo de vinculação que fazem com que a função seja movida do intervalo acessível de um pequeno deslocamento. O compilador deve gerar um registro especial para o salto, o que exige que a instrução JMP seja próxima ou extrema. O compilador fez a conversão.

Por exemplo, o código a seguir gera C4414:

```cpp
// C4414.cpp
// compile with: /W3 /c
// processor: x86
int DoParityEven();
int DoParityOdd();
unsigned char global;
int __declspec(naked) DoParityEither()
{
   __asm
   {
      test global,0
      jpe SHORT DoParityEven  // C4414
      jmp SHORT DoParityOdd   // C4414
   }
}
```
