---
title: C3227 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3227
dev_langs:
- C++
helpviewer_keywords:
- C3227
ms.assetid: 7939c23a-96c8-43c2-89e9-f217d132d155
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5e332ab40ae9b561656eae29108d4be5ab816d29
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3227"></a>C3227 de erro do compilador
'parâmetro': não é possível usar 'palavra-chave' para alocar um tipo genérico  
  
 Para criar uma instância de um tipo, um construtor apropriado é necessário. No entanto, o compilador não é capaz de garantir que um construtor apropriado está disponível.  
  
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
