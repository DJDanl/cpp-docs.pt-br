---
title: __super
ms.date: 11/04/2016
f1_keywords:
- __super_cpp
helpviewer_keywords:
- __super keyword [C++]
ms.assetid: f0957c31-9256-405b-b402-cad182404b5f
ms.openlocfilehash: a69d177bb83ce404a18d50c8f966be5d81f5fa72
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62330525"
---
# <a name="super"></a>__super

**Seção específica da Microsoft**

Permite que você indique explicitamente que está chamando uma implementação da classe base para uma função que está substituindo.

## <a name="syntax"></a>Sintaxe

```
__super::member_function();
```

## <a name="remarks"></a>Comentários

Todos os métodos acessíveis da classe base são considerados durante a fase de resolução de sobrecarga e a função que fornece a melhor correspondência é a chamada.

**Super** só pode aparecer dentro do corpo de uma função de membro.

**Super** não pode ser usado com o uso de uma declaração. Ver [usando a declaração](../cpp/using-declaration.md) para obter mais informações.

Com a introdução da [atributos](../windows/attributes/attributes-alphabetical-reference.md) que injetam código, seu código pode conter uma ou mais classes base cujos nomes você talvez não saiba, mas que contêm métodos que você deseja chamar.

## <a name="example"></a>Exemplo

```cpp
// deriv_super.cpp
// compile with: /c
struct B1 {
   void mf(int) {}
};

struct B2 {
   void mf(short) {}

   void mf(char) {}
};

struct D : B1, B2 {
   void mf(short) {
      __super::mf(1);   // Calls B1::mf(int)
      __super::mf('s');   // Calls B2::mf(char)
   }
};
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)