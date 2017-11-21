---
title: C2562 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2562
dev_langs: C++
helpviewer_keywords: C2562
ms.assetid: 2c41e511-9952-4b98-9976-6b1523613e1b
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: bcd98e241abd5cfd8cfce16224069470493d89b5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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