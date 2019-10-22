---
title: Classe slice_array
ms.date: 11/04/2016
f1_keywords:
- valarray/std::slice_array
helpviewer_keywords:
- slice_array class
ms.assetid: a182d5f7-f35c-4e76-86f2-b5ac64ddc846
ms.openlocfilehash: 358348a57b823fcea82cd296967c83778819361d
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688955"
---
# <a name="slice_array-class"></a>Classe slice_array

Um modelo de classe auxiliar interno que dá suporte a objetos de fatia, fornecendo operações entre as matrizes de subconjuntos definidas pela fatia de um valarray.

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

O modelo de classe é criado indiretamente por determinadas operações valarray e não pode ser usado diretamente no programa. Um modelo de classe auxiliar interno que é usado pelo operador subscrito de fatia:

`slice_array`\<**Type**> `valarray`< **Type**:: `operator[]` ( `slice`).

Você constrói um objeto `slice_array<Type>` apenas escrevendo uma expressão do formulário [VA&#91;SL&#93;](../standard-library/valarray-class.md#op_at), para uma fatia `sl` de `va` valarray. As funções de membro da classe slice_array se comportam como as assinaturas de função correspondentes definidas para `valarray<Type>`, exceto que apenas a sequência de elementos selecionados é afetada. A sequência controlada por slice_array é definida pelos três parâmetros do construtor de slice, o índice do primeiro elemento na slice, o número de elementos e a distância entre os elementos. Um slice_array recortar do valarray `va` declarado por **VA**[`slice` (2, 5, 3)] seleciona elementos com os índices 2, 5, 8, 11 e 14 de `va`. Os índices devem ser válidos para que o procedimento seja válido.

## <a name="example"></a>Exemplo

Veja o exemplo de [slice::slice](../standard-library/slice-class.md#slice) para obter um exemplo de como declarar e usar um slice_array.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
