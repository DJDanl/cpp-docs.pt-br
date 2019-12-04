---
title: Erro do compilador C3399
ms.date: 11/04/2016
f1_keywords:
- C3399
helpviewer_keywords:
- C3399
ms.assetid: 306ad199-d150-4f6c-bcf1-24a7948b93be
ms.openlocfilehash: d20b5e816930969278536fe3771df4ad38c3c86b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74737511"
---
# <a name="compiler-error-c3399"></a>Erro do compilador C3399

' type ': não é possível fornecer argumentos ao criar uma instância de um parâmetro genérico

Ao especificar a restrição de `gcnew()`, você especifica que o tipo de restrição terá um construtor sem parâmetros. Portanto, é um erro tentar criar uma instância desse tipo e passar um parâmetro.

Consulte [restrições em parâmetros de tipo genéricoC++(/CLI)](../../extensions/constraints-on-generic-type-parameters-cpp-cli.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3399.

```cpp
// C3399.cpp
// compile with: /clr /c
generic <class T>
where T : gcnew()
void f() {
   T t = gcnew T(1);   // C3399
   T t2 = gcnew T();   // OK
}
```
