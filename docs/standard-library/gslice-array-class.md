---
title: Classe gslice_array
ms.date: 11/04/2016
f1_keywords:
- valarray/std::gslice_array
helpviewer_keywords:
- gslice_array class
ms.assetid: ad1b4514-b14a-4baf-a293-d5a8e8674c75
ms.openlocfilehash: 68ce774128395e941ff80580a02c4ee28a74a4e4
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689593"
---
# <a name="gslice_array-class"></a>Classe gslice_array

Um modelo de classe auxiliar interno que dá suporte a objetos de fatia geral, fornecendo operações entre as matrizes de subconjuntos definidas pela fatia geral de um valarray.

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

A classe descreve um objeto que armazena uma referência a um objeto `va` da classe [valarray](../standard-library/valarray-class.md)  **\<Type >** , juntamente com um objeto `gs` da classe [GSlice](../standard-library/gslice-class.md) , que descreve a sequência de elementos a serem selecionados no objeto `valarray<Type>`.

Você constrói um objeto `gslice_array<Type>` apenas escrevendo uma expressão do formulário [VA&#91;GS&#93;](../standard-library/valarray-class.md#op_at). As funções de membro da classe gslice_array se comportam como as assinaturas de função correspondentes definidas para `valarray<Type>`, exceto que apenas a sequência de elementos selecionados é afetada.

O modelo de classe é criado indiretamente por determinadas operações valarray e não pode ser usado diretamente no programa. Em vez disso, um modelo de classe auxiliar interno é usado pelo operador subscrito de fatia:

`gslice_array`\< **Tipo**> `valarray`\< **Tipo**>:: `operator[]` ( **constgslice&** ).

Você constrói um objeto `gslice_array<Type>` apenas escrevendo uma expressão do formulário `va[gsl]`, para uma fatia `gsl` de valarray `va`. As funções de membro da classe gslice_array se comportam como as assinaturas de função correspondentes definidas para `valarray<Type>`, exceto que apenas a sequência de elementos selecionados é afetada. A sequência controlada por gslice_array é definida pelos três parâmetros do construtor de fatia, o índice do primeiro elemento na primeira fatia, o número de elementos em cada fatia e a distância entre os elementos de cada fatia.

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
