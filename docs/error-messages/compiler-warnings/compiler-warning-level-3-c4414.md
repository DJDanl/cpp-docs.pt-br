---
title: Aviso do compilador (nível 3) C4414
ms.date: 11/04/2016
f1_keywords:
- C4414
helpviewer_keywords:
- C4414
ms.assetid: bc81d3ad-55dc-4a6b-a6f2-ec0ef38347df
ms.openlocfilehash: 43570cd43ca6e9d4f892dc577f615e9fa980e561
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051577"
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