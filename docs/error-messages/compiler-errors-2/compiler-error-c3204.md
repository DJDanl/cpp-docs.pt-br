---
title: C3204 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3204
dev_langs:
- C++
helpviewer_keywords:
- C3204
ms.assetid: 06e578da-0262-48c8-b2ae-be1cd6d28884
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7d28da9839a82c63017d8cbd24e585e3af8aab2f
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3204"></a>C3204 de erro do compilador
alloca' não pode ser chamado de dentro de um bloco catch  
  
 Esse erro ocorre quando você usa uma chamada para [alloca](../../c-runtime-library/reference/alloca.md) de dentro de um bloco catch.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3204:  
  
```  
// C3204.cpp  
// compile with: /EHsc  
#include <malloc.h>  
  
void ShowError(void)  
{  
   try  
   {  
   }  
   catch(...)  
   {  
      _alloca(1);   // C3204  
   }  
}  
```
