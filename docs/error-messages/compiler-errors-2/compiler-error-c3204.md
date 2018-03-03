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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 88ee07c8319e3b8c28eaca0b7295ef1ce6e06d00
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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