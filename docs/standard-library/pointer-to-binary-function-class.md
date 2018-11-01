---
title: Classe pointer_to_binary_function
ms.date: 11/04/2016
f1_keywords:
- xfunctional/std::pointer_to_binary
helpviewer_keywords:
- pointer_to_binary_function function
- pointer_to_binary_function class
ms.assetid: fb50599f-bcb3-4076-a669-6dcc3eb189a5
ms.openlocfilehash: 42e57c9fd5dafb60a866b24a7a5b8496643d1c76
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50487074"
---
# <a name="pointertobinaryfunction-class"></a>Classe pointer_to_binary_function

Converte um ponteiro de função binária em uma função binária adaptável.

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

A classe de modelo armazena uma cópia de `pfunc`. Ela define sua função membro `operator()` como de retorno (\* **pfunc**)(_ *Left*, \_ *Right*).

## <a name="remarks"></a>Comentários

Um ponteiro de função binária é um objeto de função e pode ser passado para qualquer algoritmo da Biblioteca Padrão C++ que esperar uma função binária como parâmetro, mas não é adaptável. Para usá-lo com um adaptador, como associar um valor a ele ou usá-lo com um negador, ele deve ser fornecido com os tipos aninhados `first_argument_type`, `second_argument_type`, e `result_type` que possibilitam essa adaptação. A conversão por `pointer_to_binary_function` permite que os adaptadores de função funcionem com ponteiros de função binária.

## <a name="example"></a>Exemplo

O construtor de `pointer_to_binary_function` raramente é usado diretamente. Consulte a função auxiliar [ptr_fun](../standard-library/functional-functions.md#ptr_fun) para ver um exemplo de como declarar e usar o predicado do adaptador `pointer_to_binary_function`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
