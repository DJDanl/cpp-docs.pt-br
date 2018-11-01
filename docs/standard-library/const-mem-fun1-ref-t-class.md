---
title: Classe const_mem_fun1_ref_t
ms.date: 11/04/2016
f1_keywords:
- xfunctional/std::const_mem_fun1_ref_t
helpviewer_keywords:
- const_mem_fun1_ref_t class
ms.assetid: 8220d373-fa1c-44be-a21d-96d49b3ea6bb
ms.openlocfilehash: e90ac09543c0704cf900e0fc5448e295034dcb66
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516435"
---
# <a name="constmemfun1reft-class"></a>Classe const_mem_fun1_ref_t

Uma classe de adaptador que permite que uma função membro **const** que usa um único argumento seja chamada como um objeto de função binária quando inicializado com um argumento de referência.

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

*PM*<br/>
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

*left*<br/>
O **const** do objeto que o *Pm* função de membro é chamada em.

*right*<br/>
O argumento que está sendo fornecido para *Pm*.

## <a name="return-value"></a>Valor de retorno

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia dos *Pm*, que deve ser um ponteiro para uma função de membro de classe `Type`, em um objeto de membro privado. Ela define sua função membro `operator()` como de retorno ( `left`.\* Pm)( `right`) **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun1_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter exemplos de como usar adaptadores de função membro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
