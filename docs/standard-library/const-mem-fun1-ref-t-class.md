---
title: Classe const_mem_fun1_ref_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun1_ref_t
helpviewer_keywords:
- const_mem_fun1_ref_t class
ms.assetid: 8220d373-fa1c-44be-a21d-96d49b3ea6bb
ms.openlocfilehash: 76fae1ce29cb4c47870e45e8f946f6ff1fea1885
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688182"
---
# <a name="const_mem_fun1_ref_t-class"></a>Classe const_mem_fun1_ref_t

Uma classe de adaptador que permite que uma função membro **const** que usa um único argumento seja chamada como um objeto de função binária quando inicializado com um argumento de referência. Preterido no C++ 11, removido do C++ 17.

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

### <a name="parameters"></a>Parâmetros

@No__t_1 *PM*
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

\ *à esquerda*
O objeto **const** no qual a função de membro *PM* é chamada.

\ *à direita*
O argumento que está sendo atribuído a *PM*.

## <a name="return-value"></a>Valor retornado

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *PM*, que deve ser um ponteiro para uma função membro da classe `Type`, em um objeto de membro privado. Ele define sua função membro `operator()` como o retorno (`left`. \* *PM*) (`right`) **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun1_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter exemplos de como usar adaptadores de função membro.
