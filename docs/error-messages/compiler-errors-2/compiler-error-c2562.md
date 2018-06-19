---
title: C2562 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2562
dev_langs:
- C++
helpviewer_keywords:
- C2562
ms.assetid: 2c41e511-9952-4b98-9976-6b1523613e1b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ab3fd1a5eae008785a688bcbade674425fc8b2ef
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33231598"
---
# <a name="compiler-error-c2562"></a>C2562 de erro do compilador
'Identificador': retornando um valor de função 'void'  
  
 A função é declarada como `void` , mas retorna um valor.  
  
 Esse erro pode ser causado por um protótipo de função incorreta.  
  
 Esse erro pode ser corrigido, se você especificar o tipo de retorno na declaração da função.  
  
 O exemplo a seguir gera C2562:  
  
```  
// C2562.cpp  
// compile with: /c  
void testfunc() {  
   int i;  
   return i;   // C2562 delete the return to resolve  
}  
```