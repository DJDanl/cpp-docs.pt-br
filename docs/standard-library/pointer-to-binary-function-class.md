---
title: Classe pointer_to_binary_function
ms.date: 02/21/2019
f1_keywords:
- functional/std::pointer_to_binary
helpviewer_keywords:
- pointer_to_binary_function function
- pointer_to_binary_function class
ms.assetid: fb50599f-bcb3-4076-a669-6dcc3eb189a5
ms.openlocfilehash: 890ebb7d4c2b8fbd51a4460e21efba3e763ead7e
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687189"
---
# <a name="pointer_to_binary_function-class"></a>Classe pointer_to_binary_function

Converte um ponteiro de função binária em uma função binária adaptável. Preterido no C++ 11, removido do C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Arg1, class Arg2, class Result>
class pointer_to_binary_function
    : public binary_function <Arg1, Arg2, Result>
{
    explicit pointer_to_binary_function(
        Result(*pfunc)(Arg1, Arg2));
    Result operator()(Arg1 left, Arg2 right) const;
};
```

### <a name="parameters"></a>Parâmetros

\ *pFunc*
A função binária a ser convertida.

\ *à esquerda*
O objeto à esquerda no qual *\*pfunc* é chamado.

\ *à direita*
O objeto à direita no qual *\*pfunc* é chamado.

## <a name="return-value"></a>Valor retornado

O modelo de classe armazena uma cópia de `pfunc`. Ele define sua função membro `operator()` como retorno `(* pfunc)(Left, right)`.

## <a name="remarks"></a>Comentários

Um ponteiro de função binária é um objeto de função e pode ser passado para qualquer algoritmo da Biblioteca Padrão C++ que esperar uma função binária como parâmetro, mas não é adaptável. Para usá-lo com um adaptador, como associar um valor a ele ou usá-lo com um negador, ele deve ser fornecido com os tipos aninhados `first_argument_type`, `second_argument_type` e `result_type` que possibilitam tal adaptação. A conversão por `pointer_to_binary_function` permite que os adaptadores de função funcionem com ponteiros de função binária.

## <a name="example"></a>Exemplo

O construtor de `pointer_to_binary_function` raramente é usado diretamente. Consulte a função auxiliar [ptr_fun](../standard-library/functional-functions.md#ptr_fun) para ver um exemplo de como declarar e usar o predicado do adaptador `pointer_to_binary_function`.
