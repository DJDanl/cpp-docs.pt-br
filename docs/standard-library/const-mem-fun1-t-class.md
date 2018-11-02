---
title: Classe const_mem_fun1_t
ms.date: 11/04/2016
f1_keywords:
- xfunctional/std::const_mem_fun1_t
helpviewer_keywords:
- const_mem_fun1_t class
ms.assetid: 250fac30-9663-4133-9051-6303f76ea259
ms.openlocfilehash: 53724c3d9b795d8cbde7a4bcda3531e43d41c4a3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548779"
---
# <a name="constmemfun1t-class"></a>Classe const_mem_fun1_t

Uma classe de adaptador que permite que uma função de membro **const** que usa um único argumento seja chamada como um objeto de função binário quando inicializada com um argumento de ponteiro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
class const_mem_fun1_t : public binary_function<const Type *, Arg, Result>
{
    explicit const_mem_fun1_t(Result (Type::* _Pm)(Arg) const);
    Result operator()(const Type* _Pleft, Arg right) const;
};
```

### <a name="parameters"></a>Parâmetros

*_Pm*<br/>
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

*Pleft*<br/>
O **const** do objeto que o *_Pm* função de membro é chamada em.

*right*<br/>
O argumento que está sendo fornecido para *_Pm*.

## <a name="return-value"></a>Valor de retorno

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia dos *_Pm*, que deve ser um ponteiro para uma função de membro de classe `Type`, em um objeto de membro privado. Ela define sua função de membro `operator()` como de retorno ( *pleft*->\*<em>Pm</em>) ( *direita* ) **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun1_t` não é usado diretamente; a função auxiliar `mem_fun` é usada para adaptar funções membro. Consulte [mem_fun](../standard-library/functional-functions.md#mem_fun) para obter um exemplo de como usar adaptadores de função membro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
