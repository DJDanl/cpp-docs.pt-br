---
title: C3771 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3771
dev_langs:
- C++
helpviewer_keywords:
- C3771
ms.assetid: 68c23b25-7f21-4eaa-8f7e-38fda1130a69
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 65e7a7bd56096fbeec61b651ab494d82edef9c90
ms.openlocfilehash: 448bb34ce51cea50d1f1c5d61b28b13a7ea02ff8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3771"></a>C3771 de erro do compilador
"identificador": declaração friend não pode ser encontrada no escopo de namespace mais próximo  
  
Declaração de modelo de classe para o modelo especificado *identificador* não pode ser encontrado no namespace atual.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Certifique-se de que a declaração de modelo de classe para o identificador do modelo é definida no namespace atual ou o identificador do modelo é um nome totalmente qualificado.  
  
## <a name="example"></a>Exemplo  
O exemplo de código a seguir declara um modelo de classe e uma função no namespace `NA`, mas tentar declarar um modelo de função friend no namespace `NB`.  
  
```cpp  
// C3771.cpp   
// compile with: /c  
  
namespace NA {  
template<class T> class A {  
    void aFunction(T t) {};  
    };  
}  
// using namespace NA;  
namespace NB {  
    class X {  
        template<class T> friend void A<T>::aFunction(T); // C3771  
// try the following line instead  
//      template<class T> friend void NA::A<T>::aFunction(T);  
// or try "using namespace NA;" instead.  
    };  
}  
```  
  
## <a name="see-also"></a>Consulte também  
[Modelos](../../cpp/templates-cpp.md)  
