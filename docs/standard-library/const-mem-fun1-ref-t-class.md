---
title: Classe const_mem_fun1_ref_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun1_ref_t
helpviewer_keywords:
- const_mem_fun1_ref_t class
ms.assetid: 8220d373-fa1c-44be-a21d-96d49b3ea6bb
ms.openlocfilehash: f9f426b7280872846695e204f2c9843d2622fe19
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228330"
---
# <a name="const_mem_fun1_ref_t-class"></a>Classe const_mem_fun1_ref_t

Uma classe de adaptador que permite que uma **`const`** função de membro que usa um único argumento seja chamada como um objeto de função binária quando inicializada com um argumento de referência. Preterido no C++ 11, removido do C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
    class const_mem_fun1_ref_t
        : public binary_function<Type, Arg, Result>
{
    explicit const_mem_fun1_ref_t(Result (Type::* Pm)(Arg) const);
    Result operator()(const Type& left, Arg right) const;
};
```

### <a name="parameters"></a>parâmetros

*PM*\
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

*mantida*\
O **`const`** objeto no qual a função de membro *PM* é chamada.

*Certo*\
O argumento que está sendo atribuído a *PM*.

## <a name="return-value"></a>Valor retornado

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *PM*, que deve ser um ponteiro para uma função de membro da classe `Type` , em um objeto de membro privado. Ele define sua função `operator()` de membro como retornando ( `left` . \* *PM*) ( `right` ) **`const`** .

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun1_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter exemplos de como usar adaptadores de função membro.
