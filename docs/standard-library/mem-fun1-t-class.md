---
title: Classe mem_fun1_t
ms.date: 02/21/2019
f1_keywords:
- functional/std::mem_fun1_t
helpviewer_keywords:
- mem_fun1_t class
ms.assetid: 01a8c2c2-b2f7-4e3f-869c-5b5b9f06ea54
ms.openlocfilehash: 00d9322a8f0530da2e48b3f16fb52c00f9d1b075
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687741"
---
# <a name="mem_fun1_t-class"></a>Classe mem_fun1_t

Uma classe de adaptador que permite que um `non_const` função membro que usa um único argumento para ser chamado como um objeto de função binária quando inicializado com um argumento de ponteiro. Preterido no C++ 11, removido do C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
class mem_fun1_t : public binary_function<Type *, Arg, Result> {
    explicit mem_fun1_t(
    Result (Type::* _Pm)(Arg));

    Result operator()(
    Type* _Pleft,
    Arg right) const;
};
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *_Pm*
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

@No__t_1 *_Pleft*
O objeto no qual a função de membro *_Pm* é chamada.

\ *à direita*
O argumento que está sendo fornecido para *_Pm*.

## <a name="return-value"></a>Valor retornado

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de *_Pm*, que deve ser um ponteiro para uma função de membro da classe `Type`, em um objeto de membro privado. Ele define sua função membro `operator()` como retorno ( **_Pleft** -> \* `_Pm`) (**direita**).

## <a name="example"></a>Exemplo

Normalmente, o construtor de `mem_fun1_t` não é usado diretamente; a função auxiliar `mem_fun` é usada para adaptar funções membro. Consulte [mem_fun](../standard-library/functional-functions.md#mem_fun) para obter um exemplo de como usar adaptadores de função membro.
