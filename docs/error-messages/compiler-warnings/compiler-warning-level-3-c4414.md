---
title: Compilador aviso (nível 3) C4414 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4414
dev_langs:
- C++
helpviewer_keywords:
- C4414
ms.assetid: bc81d3ad-55dc-4a6b-a6f2-ec0ef38347df
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fd0868fea89cd868178956c0aba171ce6525bd75
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46043203"
---
# <a name="compiler-warning-level-3-c4414"></a>Compilador aviso (nível 3) C4414

'function': salto short para função convertido para near

Saltos curtos geram a instrução compact quais ramificações para um endereço dentro de um intervalo limitado da instrução. A instrução inclui um deslocamento curto que representa a distância entre o salto e o endereço de destino, a definição da função. Durante a vinculação de uma função pode ser movidas ou sujeitas a otimizações de tempo de vinculação que fazem com que a função a ser movido fora do intervalo pode ser acessado de um deslocamento de curto. O compilador deve gerar um registro especial para o salto, o que exige que a instrução de jmp para estar próximo ou muito. O compilador feita a conversão.

Por exemplo, o código a seguir gera C4414:

```
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