---
title: C3904 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3904
dev_langs:
- C++
helpviewer_keywords:
- C3904
ms.assetid: 08297605-e4f2-4c6c-b637-011f1fd40631
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 31a6f728fdbfb9540245cf85879adef8c1827d2e
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3904"></a>C3904 de erro do compilador
'property_accessor': deve especificar o parâmetro de número (s)  
  
 Verifique o número de parâmetros no seu `get` e `set` métodos em dimensões de propriedade.  
  
-   O número de parâmetros para o `get` método deve ser igual ao número de dimensões da propriedade ou ser zero para propriedades não indexadas.  
  
-   O número de parâmetros do `set` método deve ser maior que o número de dimensões da propriedade.  
  
 Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3904.  
  
```  
// C3904.cpp  
// compile with: /clr /c  
ref class X {  
   property int P {  
      // set  
      void set();   // C3904  
      // try the following line instead  
      // void set(int);  
  
      // get  
      int get(int, int);   // C3904  
      // try the following line instead  
      // int get();  
   };  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3904.  
  
```  
// C3904b.cpp  
// compile with: /clr /c  
ref struct X {  
   property int Q[double, double, float, float, void*, int] {  
      // set  
      void set(double, void*);   // C3904  
      // try the following line instead  
      // void set(double, double, float, float, void*, int, int);  
  
      // get  
      int get();   // C3904  
      // try the following line instead  
      // int get(double, double, float, float, void*, int);  
   }  
};  
```
