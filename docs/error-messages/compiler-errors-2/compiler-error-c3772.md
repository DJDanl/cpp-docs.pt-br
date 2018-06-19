---
title: C3772 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3772
dev_langs:
- C++
helpviewer_keywords:
- C3772
ms.assetid: 63e938d4-088d-41cc-a562-5881a05b5710
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 01003a4d474b80c152d271546f659d418f3c4df7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33275444"
---
# <a name="compiler-error-c3772"></a>C3772 de erro do compilador
"name": declaração de modelo friend inválido  
  
Não é válido para declarar um friend de uma especialização de modelo de classe. Você não pode declarar uma especialização explícita ou parcial de um modelo de classe e na mesma instrução declare um amigo dessa especialização. O *nome* espaço reservado identifica declaração inválida.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Não declare um amigo de uma especialização de modelo de classe.  
  
-   Se for apropriado para seu aplicativo, declare um amigo do modelo de classe ou declare um amigo de uma especialização parcial ou explícita específica.  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir falha porque ele declara um friend de uma especialização parcial de um modelo de classe.  
  
```cpp  
// c3772.cpp  
// compile with: /c  
  
// A class template.  
    template<class T> class A {};  
  
// A partial specialization of the class template.  
    template<class T> class A<T*> {};  
  
// An explicit specialization.  
    template<> class A<char>;  
  
class X {  
// Invalid declaration of a friend of a partial specialization.  
    template<class T> friend class A<T*>; // C3772  
  
// Instead, if it is appropriate for your application, declare a   
// friend of the class template. Consequently, all specializations   
// of the class template are friends:  
//    template<class T> friend class A;  
// Or declare a friend of a particular partial specialization:  
//    friend class A<int*>;  
// Or declare a friend of a particular explicit specialization:  
//    friend class A<char>;  
};  
```  
  
## <a name="see-also"></a>Consulte também  
[Modelos](../../cpp/templates-cpp.md)   
[Especialização de modelo](../../cpp/template-specialization-cpp.md)   
