---
title: C3227 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3227
dev_langs:
- C++
helpviewer_keywords:
- C3227
ms.assetid: 7939c23a-96c8-43c2-89e9-f217d132d155
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c4d156e70a1ac2c0b05e212ace81b8ccc32d8f2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33249529"
---
# <a name="compiler-error-c3227"></a>C3227 de erro do compilador
'parameter': não é possível usar 'palavra-chave' para alocar um tipo genérico  
  
 Para criar uma instância de um tipo, é necessário um construtor apropriado. No entanto, o compilador não é capaz de garantir que um construtor apropriado está disponível.  
  
 Você pode usar os modelos em vez de genéricos para resolver esse erro, ou você pode usar um dos vários métodos para criar uma instância do tipo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3227.  
  
```  
// C3227.cpp  
// compile with: /clr /c  
generic<class T> interface class ICreate {  
   static T Create();  
};  
  
generic <class T>  
where T : ICreate<T>  
ref class C {  
   void f() {  
      T t = new T;   // C3227  
  
      // OK  
      T t2 = ICreate<T>::Create();  
      T t3 = safe_cast<T>( System::Activator::CreateInstance(T::typeid) );  
   }  
};  
```