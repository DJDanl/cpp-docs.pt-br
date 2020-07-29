---
title: Classe const_mem_fun1_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun1_t
helpviewer_keywords:
- const_mem_fun1_t class
ms.assetid: 250fac30-9663-4133-9051-6303f76ea259
ms.openlocfilehash: 93d0e7a116c7c7ba7a2ed1cb46fd88585a99120d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228317"
---
# <a name="const_mem_fun1_t-class"></a>Classe const_mem_fun1_t

Uma classe de adaptador que permite que uma **`const`** função de membro que usa um único argumento seja chamada como um objeto de função binária quando inicializada com um argumento de ponteiro. Preterido no C++ 11, removido do C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
class const_mem_fun1_t : public binary_function<const Type *, Arg, Result>
{
    explicit const_mem_fun1_t(Result (Type::* member_ptr)(Arg) const);
    Result operator()(const Type* left, Arg right) const;
};
```

### <a name="parameters"></a>parâmetros

*member_ptr*\
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

*mantida*\
O **`const`** objeto no qual a função de membro de *member_ptr* é chamada.

*Certo*\
O argumento que está sendo fornecido para *member_ptr*.

## <a name="return-value"></a>Valor retornado

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *member_ptr*, que deve ser um ponteiro para uma função membro da classe `Type` , em um objeto de membro privado. Ele define sua função `operator()` de membro como retornando `(left->member_ptr)(right) const` .

## <a name="example"></a>Exemplo

O construtor de `const_mem_fun1_t` raramente é usado diretamente. `mem_fn`é usado para adaptar as funções de membro. Consulte [mem_fn](../standard-library/functional-functions.md#mem_fn) para obter um exemplo de como usar adaptadores de função membro.
