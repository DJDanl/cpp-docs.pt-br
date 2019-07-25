---
title: Classe slice_array
ms.date: 11/04/2016
f1_keywords:
- valarray/std::slice_array
helpviewer_keywords:
- slice_array class
ms.assetid: a182d5f7-f35c-4e76-86f2-b5ac64ddc846
ms.openlocfilehash: cf33c5f627a88698c84947f9b803edaebccf5566
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68450408"
---
# <a name="slicearray-class"></a>Classe slice_array

Uma classe de modelo auxiliar interna, que dá suporte a objetos de fatia fornecendo operações entre matrizes de subconjunto definidas pela fatia de um valarray.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class slice_array : public slice {
public:
    typedef Type value_type;
    void operator=(const valarray<Type>& x) const;
    void operator=(const Type& x) const;
    void operator*=(const valarray<Type>& x) const;
    void operator/=(const valarray<Type>& x) const;
    void operator%=(const valarray<Type>& x) const;
    void operator+=(const valarray<Type>& x) const;
    void operator-=(const valarray<Type>& x) const;
    void operator^=(const valarray<Type>& x) const;
    void operator&=(const valarray<Type>& x) const;
    void operator|=(const valarray<Type>& x) const;
    void operator<<=(const valarray<Type>& x) const;
    void operator>>=(const valarray<Type>& x) const;
    // The rest is private or implementation defined
}
```

## <a name="remarks"></a>Comentários

A classe descreve um objeto que armazena uma referência a um objeto da classe [valarray](../standard-library/valarray-class.md) **\<Type>** , bem como um objeto da classe [slice](../standard-library/slice-class.md), que descreve a sequência de elementos a serem selecionados do objeto **valarray\<Type>** .

A classe de modelo é criada indiretamente por determinadas operações de valarray e não pode ser usada diretamente no programa. Uma classe de modelo auxiliar interna que é usada pelo operador de subscrito da slice:

`slice_array`\<**Type**> `valarray`< **Type**:: `operator[]` ( `slice`).

Você constrói um `slice_array<Type>` objeto apenas escrevendo uma expressão do formulário [VA&#91;SL&#93;](../standard-library/valarray-class.md#op_at), para uma fatia `sl` de valarray `va`. As funções de membro da classe slice_array se comportam como as assinaturas de `valarray<Type>`função correspondentes definidas para, exceto que apenas a sequência de elementos selecionados é afetada. A sequência controlada por slice_array é definida pelos três parâmetros do construtor de slice, o índice do primeiro elemento na slice, o número de elementos e a distância entre os elementos. Um slice_array recortar de `va` valarray declarado por VA `slice`[(2, 5, 3)] seleciona elementos com os índices 2, 5, 8, 11 e 14 `va`de. Os índices devem ser válidos para que o procedimento seja válido.

## <a name="example"></a>Exemplo

Veja o exemplo de [slice::slice](../standard-library/slice-class.md#slice) para obter um exemplo de como declarar e usar um slice_array.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
