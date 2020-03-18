---
title: Função &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::swap
- istream/std::ws
ms.assetid: 0301ea0d-4ded-4841-83dd-4253b55b3188
ms.openlocfilehash: fc512558969bc25d2b16afa2b93219e13d0b28ca
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420151"
---
# <a name="ltistreamgt-functions"></a>Função &lt;istream&gt;

|||
|-|-|
|[swap](#istream_swap)|[ws](#ws)|

## <a name="istream_swap"></a>  swap

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

\ *à esquerda*
Um fluxo.

\ *à direita*
Um fluxo.

## <a name="ws"></a>  ws

Ignora o espaço em branco no fluxo.

```cpp
template class<Elem, Tr> basic_istream<Elem, Tr>& ws(basic_istream<Elem, Tr>& _Istr);
```

### <a name="parameters"></a>parâmetros

*_Istr*\
Um fluxo.

### <a name="return-value"></a>Valor retornado

O fluxo.

### <a name="remarks"></a>Comentários

O manipulador extrai e descarta quaisquer elementos `ch` para os quais [use_facet](../standard-library/basic-filebuf-class.md#open)< **ctype**\< **elem**> > ( [getloc](../standard-library/ios-base-class.md#getloc)). **é**( **ctype**\< **elem**>:: **Space**, **ch**) é true.

A função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **eofbit**) se encontrar o fim do arquivo enquanto extrai os elementos. Ele retorna *_Istr*.

### <a name="example"></a>Exemplo

Consulte [operator>>](../standard-library/istream-operators.md#op_gt_gt) para ver um exemplo de como usar `ws`.

## <a name="see-also"></a>Confira também

[\<istream>](../standard-library/istream.md)
