---
title: C3236 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3236
dev_langs:
- C++
helpviewer_keywords:
- C3236
ms.assetid: 4ef1871f-a348-44ae-922b-1e2081de20d0
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6ba4ddab60c9d9abc0febc7124df9f20c9be7b40
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3236"></a>C3236 de erro do compilador
instanciação explícita de um genérico não é permitida  
  
 O compilador não permite a instanciação explícita de classes genéricas.  
  
 O exemplo a seguir gera C3236:  
  
```  
// C3236.cpp  
// compile with: /clr  
generic<class T>  
public ref class X {};  
  
generic ref class X<int>;   // C3236  
```  
  
 O exemplo a seguir demonstra uma possível resolução:  
  
```  
// C3236b.cpp  
// compile with: /clr /c  
generic<class T>  
public ref class X {};  
```
