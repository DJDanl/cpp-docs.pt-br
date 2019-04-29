---
title: Classe const_mem_fun1_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun1_t
helpviewer_keywords:
- const_mem_fun1_t class
ms.assetid: 250fac30-9663-4133-9051-6303f76ea259
ms.openlocfilehash: df984d90f8b632f8e3e3b183943343952d45b8be
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62211969"
---
# <a name="constmemfun1t-class"></a>Classe const_mem_fun1_t

Uma classe de adaptador que permite que uma função de membro **const** que usa um único argumento seja chamada como um objeto de função binário quando inicializada com um argumento de ponteiro. Preterido no c++11, removido do c++17.

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

*member_ptr*<br/>
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

*left*<br/>
O **const** do objeto que o *member_ptr* função de membro é chamada em.

*right*<br/>
O argumento que está sendo fornecido para *member_ptr*.

## <a name="return-value"></a>Valor de retorno

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia dos *member_ptr*, que deve ser um ponteiro para uma função de membro de classe `Type`, em um objeto de membro privado. Ela define sua função de membro `operator()` como retornando `(left->member_ptr)(right) const`.

## <a name="example"></a>Exemplo

O construtor de `const_mem_fun1_t` raramente é usado diretamente. `mem_fn` é usado para se adaptar a funções de membro. Ver [mem_fn](../standard-library/functional-functions.md#mem_fn) para obter um exemplo de como usar adaptadores de função de membro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
