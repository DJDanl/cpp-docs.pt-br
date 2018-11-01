---
title: Classe const_mem_fun_ref_t
ms.date: 11/04/2016
f1_keywords:
- xfunctional/std::const_mem_fun_ref_t
helpviewer_keywords:
- const_mem_fun_ref_t class
ms.assetid: 316ddbaa-9f46-4931-8eba-ea4ca66360ef
ms.openlocfilehash: 3f0a87b71f39847590c5fbc4e94038b216ec4b1a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515512"
---
# <a name="constmemfunreft-class"></a>Classe const_mem_fun_ref_t

Uma classe de adaptador que permite que uma função de membro **const** que não usa argumentos seja chamada como um objeto de função unária quando inicializado com um argumento de referência.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type>
class const_mem_fun_ref_t
: public unary_function<Type, Result>
{
    explicit const_mem_fun_t(Result (Type::* Pm)() const);
    Result operator()(const Type& left) const;
};
```

### <a name="parameters"></a>Parâmetros

*PM*<br/>
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

*left*<br/>
O objeto que o *Pm* função de membro é chamada em.

## <a name="return-value"></a>Valor de retorno

Uma função unária adaptável.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia dos *Pm*, que deve ser um ponteiro para uma função de membro de classe `Type`, em um objeto de membro privado. Ela define sua função de membro `operator()` como de retorno ( **esquerdo**.\* `Pm`) () **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter um exemplo de como usar adaptadores de função membro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
