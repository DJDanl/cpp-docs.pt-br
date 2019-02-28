---
title: Classe pointer_to_unary_function
ms.date: 02/21/2019
f1_keywords:
- functional/std::pointer_to_unary
helpviewer_keywords:
- pointer_to_unary_function function
- pointer_to_unary_function class
ms.assetid: 05600207-b916-4759-beca-6b6facd2d6f6
ms.openlocfilehash: 710453711e60f4607a20eb3e71b65127c8dd5316
ms.sourcegitcommit: 4299caac2dc9e806c74ac833d856a3838b0f52a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2019
ms.locfileid: "57006650"
---
# <a name="pointertounaryfunction-class"></a>Classe pointer_to_unary_function

Converte um ponteiro de função unária em uma função unária adaptável. Preterido no c++11, removido do c++17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Arg, class Result>
class pointer_to_unary_function
    : public unary_function<Arg, Result>
{
public:
    explicit pointer_to_unary_function(Result(*pfunc)(Arg));
    Result operator()(Arg left) const;
};
```

### <a name="parameters"></a>Parâmetros

*pfunc*<br/>
A função binária a ser convertida.

*left*<br/>
O objeto no qual o  *\*pfunc* é chamado.

## <a name="return-value"></a>Valor de retorno

A classe de modelo armazena uma cópia de `pfunc`. Ela define sua função membro `operator()` como de retorno (\* **pfunc**)(_ *Left*).

## <a name="remarks"></a>Comentários

Um ponteiro de função unária é um objeto de função e pode ser passado para qualquer algoritmo da Biblioteca Padrão C++ que esperar uma função unária como parâmetro, mas não é adaptável. Para usá-lo com um adaptador, como associar um valor a ele ou usá-lo com um negador, ele deve ser fornecido com os tipos aninhados `argument_type` e `result_type` que possibilitam essa adaptação. A conversão por `pointer_to_unary_function` permite que os adaptadores de função funcionem com ponteiros de função binária.

## <a name="example"></a>Exemplo

O construtor de `pointer_to_unary_function` raramente é usado diretamente. Consulte a função auxiliar [ptr_fun](../standard-library/functional-functions.md#ptr_fun) para ver um exemplo de como declarar e usar o predicado do adaptador `pointer_to_unary_function`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
