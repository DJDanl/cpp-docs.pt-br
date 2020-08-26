---
title: Função &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::swap
- istream/std::ws
ms.assetid: 0301ea0d-4ded-4841-83dd-4253b55b3188
ms.openlocfilehash: 6d1fede2726d3d8f5dd678b95fd7a22a301ea95a
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840967"
---
# <a name="ltistreamgt-functions"></a>Função &lt;istream&gt;

[permuta](#istream_swap)\
[Federation](#ws)

## <a name="swap"></a><a name="istream_swap"></a> permuta

Troca os elementos de dois objetos de fluxo.

```cpp
template <class Elem, class Tr>
void swap(
    basic_istream<Elem, Tr>& left,
    basic_istream<Elem, Tr>& right);

template <class Elem, class Tr>
void swap(
    basic_iostream<Elem, Tr>& left,
    basic_iostream<Elem, Tr>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um fluxo.

*Certo*\
Um fluxo.

## <a name="ws"></a><a name="ws"></a> Federation

Ignora o espaço em branco no fluxo.

```cpp
template class<Elem, Tr> basic_istream<Elem, Tr>& ws(basic_istream<Elem, Tr>& _Istr);
```

### <a name="parameters"></a>parâmetros

*_Istr*\
Um fluxo.

### <a name="return-value"></a>Valor Retornado

O fluxo.

### <a name="remarks"></a>Comentários

O manipulador extrai e descarta quaisquer elementos `ch` para os quais [use_facet](../standard-library/basic-filebuf-class.md#open) <  **CType** \< **Elem**> > ( [getloc](../standard-library/ios-base-class.md#getloc)). **is**( **CType** \< **Elem**> :: **Space**, **ch**) é true.

A função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **eofbit**) se encontrar o fim do arquivo enquanto extrai os elementos. Ele retorna *_Istr*.

### <a name="example"></a>Exemplo

Consulte [operator>>](../standard-library/istream-operators.md#op_gt_gt) para ver um exemplo de como usar `ws`.

## <a name="see-also"></a>Confira também

[\<istream>](../standard-library/istream.md)
