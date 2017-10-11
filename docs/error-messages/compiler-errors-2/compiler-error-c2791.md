---
title: C2791 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2791
dev_langs:
- C++
helpviewer_keywords:
- C2791
ms.assetid: 938ad1fb-75d9-4ce2-ad92-83d6249005b5
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 894f0fb735e4fea7d590eb53401243c0d8581c49
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2791"></a>C2791 de erro do compilador
Uso inválido de 'super': 'class' não tem nenhuma classe base  
  
 A palavra-chave [super](../../cpp/super.md) foi usada no contexto de uma função de membro de uma classe que não tenha todas as classes base.  
  
 O exemplo a seguir gera C2791:  
  
```  
// C2791.cpp  
struct D {  
   void mf() {  
      __super::mf();   // C2791  
   }  
};  
```
