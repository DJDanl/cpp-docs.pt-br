---
title: Classe const_mem_fun1_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun1_t
helpviewer_keywords:
- const_mem_fun1_t class
ms.assetid: 250fac30-9663-4133-9051-6303f76ea259
ms.openlocfilehash: 1af44635400037c6359b13c4f2925c3ac7f2d9d5
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689746"
---
# <a name="const_mem_fun1_t-class"></a>Classe const_mem_fun1_t

Uma classe de adaptador que permite que uma função de membro **const** que usa um único argumento seja chamada como um objeto de função binário quando inicializada com um argumento de ponteiro. Preterido no C++ 11, removido do C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
class const_mem_fun1_t : public binary_function<const Type *, Arg, Result>
{
    explicit const_mem_fun1_t(Result (Type::* member_ptr)(Arg) const);
    Result operator()(const Type* left, Arg right) const;
};
```

### <a name="parameters"></a>Parâmetros

\ *member_ptr*
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

\ *à esquerda*
O objeto **const** no qual a função de membro *member_ptr* é chamada.

\ *à direita*
O argumento que está sendo fornecido para *member_ptr*.

## <a name="return-value"></a>Valor retornado

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *member_ptr*, que deve ser um ponteiro para uma função de membro da classe `Type`, em um objeto de membro privado. Ele define sua função membro `operator()` como retorno `(left->member_ptr)(right) const`.

## <a name="example"></a>Exemplo

O construtor de `const_mem_fun1_t` raramente é usado diretamente. `mem_fn` é usado para adaptar as funções de membro. Consulte [mem_fn](../standard-library/functional-functions.md#mem_fn) para obter um exemplo de como usar adaptadores de função membro.
