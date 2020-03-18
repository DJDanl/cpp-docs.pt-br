---
title: Classe value_compare (&lt;map&gt;)
ms.date: 11/04/2016
f1_keywords:
- std::value_compare
- std.value_compare
- map/std::value_compare
helpviewer_keywords:
- std::value_compare
ms.assetid: ea97c1d0-04b2-4d42-8d96-23522c04cc41
ms.openlocfilehash: 1f872edce6f0114be7c90a8108ba248fd793a989
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447576"
---
# <a name="value_compare-class-ltmapgt"></a>Classe value_compare (&lt;map&gt;)

Fornece um objeto de função que pode comparar os elementos de um mapa ao comparar os valores de suas chaves para determinar sua ordem relativa no mapa.

## <a name="syntax"></a>Sintaxe

```cpp
class value_compare : public binary_function<value_type, value_type, bool>
{
public:
    bool operator()(const value_type& left, const value_type& right) const;
    value_compare(key_compare pred) : comp(pred);
protected:
    key_compare comp;
};
```

## <a name="remarks"></a>Comentários

O critério de comparação fornecido por `value_compare` entre `value_types` de elementos inteiros contidos por um mapa é induzido por meio de uma comparação entre as chaves dos respectivos elementos pela construção da classe auxiliar. O operador de função de membro usa o objeto `comp` do tipo `key_compare` armazenado no objeto de função fornecido pelo `value_compare` para comparar os componentes de chave de classificação de dois elementos.

Para conjuntos e multiconjuntos, que são contêineres simples nos quais os valores de chave são idênticos aos valores dos elementos, `value_compare` é equivalente a `key_compare`; para mapas e multimapas eles não são, uma vez que o valor dos elementos do tipo `pair` não é idêntico ao valor da chave do elemento.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [value_comp](../standard-library/map-class.md#value_comp) para obter um exemplo de como declarar e usar `value_compare`.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** > do mapa de \<

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Struct binary_function](../standard-library/binary-function-struct.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
