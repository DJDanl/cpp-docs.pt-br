---
title: Classe gslice_array
ms.date: 11/04/2016
f1_keywords:
- valarray/std::gslice_array
helpviewer_keywords:
- gslice_array class
ms.assetid: ad1b4514-b14a-4baf-a293-d5a8e8674c75
ms.openlocfilehash: 37c54d09fdfe920c832c4baa7984fee4e090d04a
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68448927"
---
# <a name="gslicearray-class"></a>Classe gslice_array

Uma classe de modelo auxiliar interna, que dá suporte a objetos de fatia geral fornecendo operações entre matrizes de subconjunto definidas pela fatia geral de um valarray.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class gslice_array : public gsplice {
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

A classe descreve um objeto que armazena uma referência a um objeto `va` da classe [valarray](../standard-library/valarray-class.md) **\<do tipo >** , juntamente com um `gs` objeto da classe [GSlice](../standard-library/gslice-class.md) que descreve a sequência de elementos a serem selecionados o `valarray<Type>` objeto.

Você constrói um `gslice_array<Type>` objeto apenas escrevendo uma expressão do formulário [VA&#91;GS&#93;](../standard-library/valarray-class.md#op_at). As funções de membro da classe gslice_array se comportam como as assinaturas de `valarray<Type>`função correspondentes definidas para, exceto que apenas a sequência de elementos selecionados é afetada.

A classe de modelo é criada indiretamente por determinadas operações de valarray e não pode ser usada diretamente no programa. Em vez disso, uma classe de modelo auxiliar interna é usada pelo operador de subscrito da fatia:

`gslice_array`\< **Tipo**> `valarray`\< **Tipo**>:: `operator[]` ( **constgslice&** ).

Você constrói um `gslice_array<Type>` objeto apenas escrevendo uma expressão do formulário `va[gsl]`, para uma fatia `gsl` de valarray `va`. As funções de membro da classe gslice_array se comportam como as assinaturas de `valarray<Type>`função correspondentes definidas para, exceto que apenas a sequência de elementos selecionados é afetada. A sequência controlada por gslice_array é definida pelos três parâmetros do construtor de fatia, o índice do primeiro elemento na primeira fatia, o número de elementos em cada fatia e a distância entre os elementos de cada fatia.

No exemplo a seguir:

```cpp
const size_t lv[] = {2, 3};
const size_t dv[] = {7, 2};
const valarray<size_t> len(lv, 2), str(dv, 2);

// va[gslice(3, len, str)] selects elements with
//   indices 3, 5, 7, 10, 12, 14
```

Os índices devem ser válidos para que o procedimento seja válido.

## <a name="example"></a>Exemplo

Veja o exemplo de [gslice::gslice](../standard-library/gslice-class.md#gslice) para obter um exemplo de como declarar e usar um slice_array.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
