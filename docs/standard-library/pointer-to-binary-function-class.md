---
title: Classe pointer_to_binary_function
ms.date: 02/21/2019
f1_keywords:
- functional/std::pointer_to_binary
helpviewer_keywords:
- pointer_to_binary_function function
- pointer_to_binary_function class
ms.assetid: fb50599f-bcb3-4076-a669-6dcc3eb189a5
ms.openlocfilehash: 88d38be258c6ceb1054e0d31cc52e4d8d25186ec
ms.sourcegitcommit: 4299caac2dc9e806c74ac833d856a3838b0f52a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2019
ms.locfileid: "57006793"
---
# <a name="pointertobinaryfunction-class"></a>Classe pointer_to_binary_function

Converte um ponteiro de função binária em uma função binária adaptável. Preterido no c++11, removido do c++17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Arg1, class Arg2, class Result>
class pointer_to_binary_function
    : public binary_function <Arg1, Arg2, Result>
{
public:
    explicit pointer_to_binary_function(
        Result(*pfunc)(Arg1, Arg2));
    Result operator()(Arg1 left, Arg2 right) const;
};
```

### <a name="parameters"></a>Parâmetros

*pfunc*<br/>
A função binária a ser convertida.

*left*<br/>
O objeto à esquerda no qual *\*pfunc* é chamado.

*right*<br/>
O objeto à direita no qual *\*pfunc* é chamado.

## <a name="return-value"></a>Valor de retorno

A classe de modelo armazena uma cópia de `pfunc`. Ela define sua função de membro `operator()` como retornando `(* pfunc)(Left, right)`.

## <a name="remarks"></a>Comentários

Um ponteiro de função binária é um objeto de função e pode ser passado para qualquer algoritmo da Biblioteca Padrão C++ que esperar uma função binária como parâmetro, mas não é adaptável. Para usá-lo com um adaptador, como associar um valor a ele ou usá-lo com um negador, ele deve ser fornecido com os tipos aninhados `first_argument_type`, `second_argument_type`, e `result_type` que possibilitam essa adaptação. A conversão por `pointer_to_binary_function` permite que os adaptadores de função funcionem com ponteiros de função binária.

## <a name="example"></a>Exemplo

O construtor de `pointer_to_binary_function` raramente é usado diretamente. Consulte a função auxiliar [ptr_fun](../standard-library/functional-functions.md#ptr_fun) para ver um exemplo de como declarar e usar o predicado do adaptador `pointer_to_binary_function`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
