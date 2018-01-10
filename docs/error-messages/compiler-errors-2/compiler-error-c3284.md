---
title: C3284 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3824
dev_langs: C++
helpviewer_keywords: C3284
ms.assetid: e582f316-e9db-4d27-9c70-fdfa737a9d5f
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9ec3f536b17a2cc8ec180d87270b85938e9a9637
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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