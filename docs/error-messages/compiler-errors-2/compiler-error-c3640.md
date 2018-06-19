---
title: Compilador erro C3640 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3640
dev_langs:
- C++
helpviewer_keywords:
- C3640
ms.assetid: fcc56894-0f98-48af-8561-3bf7c7b2b93f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f8ec2e22033ea4cc1b475ab1f838bb77d96916e7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33267180"
---
# <a name="compiler-error-c3640"></a>C3640 de erro do compilador
'member': uma função membro referenciada ou virtual de uma classe local deve ser definida  
  
 O compilador requer determinadas funções a serem definidos.  
  
 O exemplo a seguir gera C3640:  
  
```  
// C3640.cpp  
void f()   
{  
   struct S  
   {  
      virtual void f1();   // C3640  
      // Try the following line instead:  
      // virtual void f1(){}  
   };  
}  
```