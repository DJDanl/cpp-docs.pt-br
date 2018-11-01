---
title: Erro do compilador C3227
ms.date: 11/04/2016
f1_keywords:
- C3227
helpviewer_keywords:
- C3227
ms.assetid: 7939c23a-96c8-43c2-89e9-f217d132d155
ms.openlocfilehash: b175b14af55a9a462e040f064cc6e38d13fffb94
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50632486"
---
# <a name="compiler-error-c3227"></a>Erro do compilador C3227

'parameter': não é possível usar 'palavra-chave' para alocar um tipo genérico

Para criar uma instância de um tipo, um construtor apropriado é necessário. No entanto, o compilador não é capaz de garantir que um construtor apropriado está disponível.

Você pode usar modelos, em vez de genéricos para resolver esse erro, ou você pode usar um dos vários métodos para criar uma instância do tipo.

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