---
title: Erro do compilador C3114
ms.date: 11/04/2016
f1_keywords:
- C3114
helpviewer_keywords:
- C3114
ms.assetid: b5d2df4f-87d0-4292-9981-25c6a6013c05
ms.openlocfilehash: 481e0ac5a395b38bc9d1874959b010ecd71f9fb5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233373"
---
# <a name="compiler-error-c3114"></a>Erro do compilador C3114

' Argument ': não é um argumento de atributo nomeado válido

Para que um membro de dados da classe de atributo seja um argumento nomeado válido, ele não deve ser marcado como **`static`** , **`const`** ou **`literal`** . Se uma propriedade, a propriedade não deve ser **`static`** e deve ter acessadores get e Set.

Para obter mais informações, consulte [Propriedade](../../extensions/property-cpp-component-extensions.md) e [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3114.

```cpp
// C3114.cpp
// compile with: /clr /c
public ref class A : System::Attribute {
public:
   static property int StaticProp {
      int get();
   }

   property int Prop2 {
      int get();
      void set(int i);
   }
};

[A(StaticProp=123)]   // C3114
public ref class R {};

[A(Prop2=123)]   // OK
public ref class S {};
```
