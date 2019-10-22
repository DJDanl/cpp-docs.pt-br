---
title: Classe const_mem_fun_ref_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun_ref_t
helpviewer_keywords:
- const_mem_fun_ref_t class
ms.assetid: 316ddbaa-9f46-4931-8eba-ea4ca66360ef
ms.openlocfilehash: 8ce29eb0d2122dbd95fea34fa59f3fa11b9b388e
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689769"
---
# <a name="const_mem_fun_ref_t-class"></a>Classe const_mem_fun_ref_t

Uma classe de adaptador que permite que uma função de membro **const** que não usa argumentos seja chamada como um objeto de função unária quando inicializado com um argumento de referência. Preterido no C++ 11, removido do C++ 17.

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

@No__t_1 *PM*
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

\ *à esquerda*
O objeto no qual a função de membro *PM* é chamada.

## <a name="return-value"></a>Valor retornado

Uma função unária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *PM*, que deve ser um ponteiro para uma função membro da classe `Type`, em um objeto de membro privado. Ele define sua função membro `operator()` como retorno (**Left**. \* `Pm`) () **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter um exemplo de como usar adaptadores de função membro.
