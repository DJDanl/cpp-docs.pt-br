---
title: C3412 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3412
dev_langs:
- C++
helpviewer_keywords:
- C3412
ms.assetid: aa4dd43b-54ce-4cda-85c1-1a77dd6e34fa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7c5b2c86b91160eb7ae342b39ea6a63ffad364bb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33250637"
---
# <a name="compiler-error-c3412"></a>C3412 de erro do compilador
'template': não é possível especializar template no escopo atual  
  
 Um modelo não pode ser especializado no escopo de classe, em global ou escopo de namespace.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3412.  
  
```  
// C3412.cpp  
template <class T>  
struct S {  
   template <>  
   struct S<int> {};   // C3412 in a class  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra uma possível resolução.  
  
```  
// C3412b.cpp  
// compile with: /c  
template <class T>  
struct S {};  
  
template <>  
struct S<int> {};  
```