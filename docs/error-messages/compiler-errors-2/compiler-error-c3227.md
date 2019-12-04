---
title: Erro do compilador C3227
ms.date: 11/04/2016
f1_keywords:
- C3227
helpviewer_keywords:
- C3227
ms.assetid: 7939c23a-96c8-43c2-89e9-f217d132d155
ms.openlocfilehash: 460000531dba77e42379199f276c9e2e02f43a9b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743413"
---
# <a name="compiler-error-c3227"></a>Erro do compilador C3227

' Parameter ': não é possível usar ' keyword ' para alocar um tipo genérico

Para criar uma instância de um tipo, é necessário um construtor apropriado. No entanto, o compilador não é capaz de garantir que um construtor apropriado esteja disponível.

Você pode usar modelos em vez de genéricos para resolver esse erro ou pode usar um dos vários métodos para criar uma instância do tipo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3227.

```cpp
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
