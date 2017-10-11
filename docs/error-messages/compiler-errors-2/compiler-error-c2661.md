---
title: C2661 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2661
dev_langs:
- C++
helpviewer_keywords:
- C2661
ms.assetid: 60021467-71cd-451b-9877-23840c69309f
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: dc5d33bbb0dd1053a200791952848146450e9a16
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2661"></a>C2661 de erro do compilador
'function': nenhuma função sobrecarregada recebe parâmetros de número  
  
 Possíveis causas:  
  
1.  Parâmetros reais incorretos na chamada de função.  
  
2.  Declaração de função ausente.  
  
 O exemplo a seguir gera C2661:  
  
```  
// C2661.cpp  
void func( int ){}  
void func( int, int ){}  
int main() {  
   func( );   // C2661 func( void ) was not declared  
   func( 1 );   // OK func( int ) was declared  
}  
```
