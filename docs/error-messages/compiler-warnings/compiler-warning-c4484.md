---
title: C4484 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4484
dev_langs:
- C++
helpviewer_keywords:
- C4484
ms.assetid: 3d30e5b3-2297-45b7-a37a-1360056fdd0e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 75531c207f0136f16109b4d69d689b883998aae2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-c4484"></a>C4484 de aviso do compilador
'override_function': corresponde ao método de classe ref base 'base_class_function', mas não está marcado como 'virtual', 'new' ou 'override'; 'new' (e não 'virtual') é assumido  
  
 Ao compilar com **/clr**, o compilador não substitui uma função de classe base, o que significa que a função terá um novo slot no vtable implicitamente. Para resolver, explicitamente especifique se uma função é uma substituição.  
  
 Para obter mais informações, consulte:  
  
-   [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
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