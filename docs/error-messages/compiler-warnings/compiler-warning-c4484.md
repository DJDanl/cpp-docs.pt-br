---
title: C4484 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4484
dev_langs:
- C++
helpviewer_keywords:
- C4484
ms.assetid: 3d30e5b3-2297-45b7-a37a-1360056fdd0e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fa5f209dd3a77bcc4ec3c21d589fb8ba1ed3faf1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4484"></a>C4484 de aviso do compilador
'override_function': corresponde ao método de classe ref base 'base_class_function', mas não está marcado como 'virtual', 'new' ou 'override'; 'new' (e não 'virtual') é assumido  
  
 Ao compilar com **/clr**, o compilador não substitui uma função de classe base, o que significa que a função terá um novo slot no vtable implicitamente. Para resolver, explicitamente especifique se uma função é uma substituição.  
  
 Para obter mais informações, consulte:  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [override](../../windows/override-cpp-component-extensions.md)  
  
-   [novo (novo slot em vtable)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md)  
  
 C4484 sempre é emitido como um erro. Use o [aviso](../../preprocessor/warning.md) pragma para suprimir C4484.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4484.  
  
```  
// C4484.cpp  
// compile with: /clr  
ref struct A {  
   virtual void Test() {}  
};  
  
ref struct B : A {  
   void Test() {}   // C4484  
};  
  
// OK  
ref struct C {  
   virtual void Test() {}  
   virtual void Test2() {}  
};  
  
ref struct D : C {  
   virtual void Test() new {}  
   virtual void Test2() override {}  
};  
```