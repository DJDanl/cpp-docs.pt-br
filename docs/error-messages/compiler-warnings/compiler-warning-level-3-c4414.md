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
ms.openlocfilehash: a1526b20732d7a1b08ec8d753cb64e33e42dd809
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4414"></a>Compilador C4414 de aviso (nível 3)
'function': salto short para função convertido para near  
  
 Curto vai gera instrução compact que se ramifica para um endereço dentro de um intervalo limitado da instrução. A instrução inclui um deslocamento curto que representa a distância entre o salto e o endereço de destino, a definição da função. Durante a vinculação de uma função pode ser movidas ou sujeitas a otimizações de tempo de vinculação que fazer com que a função a ser movido fora do intervalo pode ser acessado de um deslocamento de curto. O compilador deve gerar um registro especial de salto, o que exige que a instrução jmp próximo ou muito. O compilador feita a conversão.  
  
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