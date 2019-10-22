---
title: Classe const_mem_fun_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::const_mem_fun_t
helpviewer_keywords:
- const_mem_fun_t class
ms.assetid: f169d381-019b-4a0e-a9a3-54da6d948270
ms.openlocfilehash: 5263612a26b2bcb606ad712a2a8e0a521ce9437a
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688204"
---
# <a name="const_mem_fun_t-class"></a>Classe const_mem_fun_t

Uma classe de adaptador que permite que uma função de membro const que não usa argumentos seja chamada como um objeto de função unária quando inicializado com um argumento de referência. Preterido no C++ 11, removido do C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type>
class const_mem_fun_t : public unary_function <Type *, Result>
{
    explicit const_mem_fun_t(Result (Type::* Pm)() const);
    Result operator()(const Type* Pleft) const;
};
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *PM*
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

@No__t_1 *pleft*
O objeto no qual a função de membro *PM* é chamada.

## <a name="return-value"></a>Valor retornado

Uma função unária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *PM*, que deve ser um ponteiro para uma função membro da classe `Type`, em um objeto de membro privado. Ele define sua função membro `operator()` como o retorno (`Pleft` -> \* `Pm`) () **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun_t` não é usado diretamente; a função auxiliar `mem_fun` é usada para adaptar funções membro. Consulte [mem_fun](../standard-library/functional-functions.md#mem_fun) para obter um exemplo de como usar adaptadores de função membro.
