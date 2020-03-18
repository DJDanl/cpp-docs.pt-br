---
title: Classe value_compare
ms.date: 11/04/2016
f1_keywords:
- hash_map/std::value_compare
helpviewer_keywords:
- value_compare class
ms.assetid: c306c5b9-3505-4357-aa6b-216451b951ed
ms.openlocfilehash: d64d51869ca8db1ed42e9d33691f59da4473d8d0
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447568"
---
# <a name="value_compare-class"></a>Classe value_compare

Fornece um objeto de função que pode comparar os elementos de um hash_map comparando os valores de suas chaves para determinar sua ordem relativa no hash_map.

## <a name="syntax"></a>Sintaxe

```cpp
class value_compare
    : std::public binary_function<value_type, value_type, bool>
{
public:
    bool operator()(
        const value_type& left,
        const value_type& right) const
    {
        return (comp(left.first, right.first));
    }

protected:
    value_compare(const key_compare& c) : comp (c) { }
    key_compare comp;
};
```

## <a name="remarks"></a>Comentários

Os critérios de comparação fornecidos por value_compare entre `value_types` de elementos inteiros contidos por uma hash_map são induzidos de uma comparação entre as chaves dos respectivos elementos pela construção da classe auxiliar. O operador de função de membro usa o objeto `comp` do tipo `key_compare` armazenado no objeto de função fornecido pelo value_compare para comparar os componentes de chave de classificação de dois elementos.

Para hash_sets e hash_multisets, que são contêineres simples nos quais os valores de chave são idênticos aos valores dos elementos, value_compare é equivalente a `key_compare`; para hash_maps e hash_multimaps eles não são, uma vez que o valor dos elementos do tipo `pair` não é idêntico ao valor da chave do elemento.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Veja o exemplo de [hash_map::value_comp](../standard-library/hash-map-class.md#value_comp) para obter um exemplo de como declarar e usar value_compare.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** \<hash_map >

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[Struct binary_function](../standard-library/binary-function-struct.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
