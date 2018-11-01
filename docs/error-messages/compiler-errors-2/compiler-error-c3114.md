---
title: Erro do compilador C3114
ms.date: 11/04/2016
f1_keywords:
- C3114
helpviewer_keywords:
- C3114
ms.assetid: b5d2df4f-87d0-4292-9981-25c6a6013c05
ms.openlocfilehash: 6ce5b9860cd75619f26a3585981af5807c33535a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50606668"
---
# <a name="compiler-error-c3114"></a>Erro do compilador C3114

'argumento': argumento de atributo nomeado não válido

Em ordem para um membro de dados de classe de atributo ser um argumento nomeado válido, ele não deve ser marcado `static`, `const`, ou `literal`. Se uma propriedade, a propriedade não deve ser `static` e deve ter get e definir acessadores.

Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md) e [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3114.

```
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