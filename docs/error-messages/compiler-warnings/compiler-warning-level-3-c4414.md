---
title: "Compilador aviso (nível 3) C4414 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4414
dev_langs:
- C++
helpviewer_keywords:
- C4414
ms.assetid: bc81d3ad-55dc-4a6b-a6f2-ec0ef38347df
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 36dfb834d5f3cb64b15d696aa86ea6d320fa91f8
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4414"></a>Compilador C4414 de aviso (nível 3)
'function': salto curto para função convertido em próximo  
  
 Saltos curtos geram instrução compact quais ramificações para um endereço dentro de um intervalo limitado da instrução. A instrução inclui um deslocamento curto que representa a distância entre o salto e o endereço de destino, a definição da função. Durante a vinculação de uma função pode ser movidas ou sujeitas a otimizações de link-time que fazer com que a função seja movido fora do intervalo pode ser acessado de um deslocamento curto. O compilador deve gerar um registro de salto, o que exige que a instrução jmp próximo ou muito especial. O compilador feita a conversão.  
  
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
