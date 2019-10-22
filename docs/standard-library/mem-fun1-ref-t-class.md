---
title: Classe mem_fun1_ref_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::mem_fun1_ref_t
helpviewer_keywords:
- mem_fun1_ref_t class
ms.assetid: 7d6742f6-19ba-4523-b3c8-0e5b8f11464f
ms.openlocfilehash: 238d6147b2afa5ca3e143bc57aa4892e17d2c869
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687751"
---
# <a name="mem_fun1_ref_t-class"></a>Classe mem_fun1_ref_t

Uma classe de adaptador que permite que um `non_const` função membro que usa um único argumento para ser chamado como um objeto de função binária quando inicializado com um argumento de referência. Preterido no C++ 11, removido do C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
class mem_fun1_ref_t : public binary_function<Type, Arg, Result> {
    explicit mem_fun1_ref_t(
    Result (Type::* _Pm)(Arg));

    Result operator()(
    Type& left,
    Arg right) const;
};
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *_Pm*
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

\ *à esquerda*
O objeto no qual a função de membro *_Pm* é chamada.

\ *à direita*
O argumento que está sendo fornecido para *_Pm*.

## <a name="return-value"></a>Valor retornado

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *_Pm*, que deve ser um ponteiro para uma função de membro da classe `Type`, em um objeto de membro privado. Ele define sua função membro `operator()` como retorno (**Left**. \* `_Pm`) (**direita**).

## <a name="example"></a>Exemplo

Normalmente, o construtor de `mem_fun1_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter um exemplo de como usar adaptadores de função membro.
