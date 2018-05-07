---
title: C3231 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3231
dev_langs:
- C++
helpviewer_keywords:
- C3231
ms.assetid: fe5dc352-e634-45fa-9534-3da176294c98
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4925055caac0f3d26922eebf6a043ad51c83efa2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3231"></a>C3231 de erro do compilador
'arg': argumento de tipo de modelo não é possível usar um parâmetro de tipo genérico  
  
 Modelos são instanciados no tempo de compilação, mas são instanciados genéricos em tempo de execução. Portanto, não é possível gerar o código genérico que pode chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico é conhecido por último.  
  
 O exemplo a seguir gera C3231:  
  
```  
// C3231.cpp  
// compile with: /clr /LD  
template <class T> class A;  
  
generic <class T>  
ref class C {  
   void f() {  
      A<T> a;   // C3231  
   }  
};  
```