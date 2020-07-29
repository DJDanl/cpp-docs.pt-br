---
title: Classe const_mem_fun_ref_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun_ref_t
helpviewer_keywords:
- const_mem_fun_ref_t class
ms.assetid: 316ddbaa-9f46-4931-8eba-ea4ca66360ef
ms.openlocfilehash: 09d8569253dbeb1a873f4fc7b64b55658511d18e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228356"
---
# <a name="const_mem_fun_ref_t-class"></a>Classe const_mem_fun_ref_t

Uma classe de adaptador que permite que uma **`const`** função de membro que não usa argumentos seja chamada como um objeto de função unário quando inicializada com um argumento de referência. Preterido no C++ 11, removido do C++ 17.

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

### <a name="parameters"></a>parâmetros

*PM*\
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

*mantida*\
O objeto no qual a função de membro *PM* é chamada.

## <a name="return-value"></a>Valor retornado

Uma função unária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *PM*, que deve ser um ponteiro para uma função de membro da classe `Type` , em um objeto de membro privado. Ele define sua função `operator()` de membro como retornando (**Left**. \* `Pm` ) () **`const`**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter um exemplo de como usar adaptadores de função membro.
