---
title: C3284 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3824
dev_langs:
- C++
helpviewer_keywords:
- C3284
ms.assetid: e582f316-e9db-4d27-9c70-fdfa737a9d5f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f75cc4e3d6d7eb30f125a016c43b72609d467c57
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3284"></a>C3284 de erro do compilador
as restrições de parâmetro genérico 'parameter' da função 'function' devem corresponder às restrições de parâmetro genérico 'parameter' da função 'function'  
  
 Uma função genérica virtual deve usar as mesmas restrições que uma função virtual com o mesmo nome e o conjunto de argumentos na classe base.  
  
 O exemplo a seguir gera C3284:  
  
```  
// C3284.cpp  
// compile with: /clr /c  
// C3284 expected  
public interface class IGettable {  
   int Get();  
};  
  
public interface class B {  
   generic<typename T>  
   where T : IGettable  
   virtual int mf(T t);  
};  
  
public ref class D : public B {  
public:  
   generic<typename T>  
   // Uncomment the following line to resolve.  
   // where T : IGettable  
   virtual int mf(T t) {  
      return 4;  
   }  
};  
```