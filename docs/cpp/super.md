---
title: __super
ms.date: 11/04/2016
f1_keywords:
- __super_cpp
helpviewer_keywords:
- __super keyword [C++]
ms.assetid: f0957c31-9256-405b-b402-cad182404b5f
ms.openlocfilehash: 3afc2e8049cfcca40db389bed84baa6f42dae126
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213145"
---
# `__super`

**Específico da Microsoft**

Permite que você indique explicitamente que está chamando uma implementação da classe base para uma função que está substituindo.

## <a name="syntax"></a>Sintaxe

```
__super::member_function();
```

## <a name="remarks"></a>Comentários

Todos os métodos acessíveis da classe base são considerados durante a fase de resolução de sobrecarga e a função que fornece a melhor correspondência é a chamada.

**`__super`** Só pode aparecer dentro do corpo de uma função de membro.

**`__super`** Não pode ser usado com uma declaração using. Consulte [usando a declaração](../cpp/using-declaration.md) para obter mais informações.

Com a introdução de [atributos](../windows/attributes/attributes-alphabetical-reference.md) que injetam código, seu código pode conter uma ou mais classes base cujos nomes você talvez não conheça, mas que contêm métodos que você deseja chamar.

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

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
