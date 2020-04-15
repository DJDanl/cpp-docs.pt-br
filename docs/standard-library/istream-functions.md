---
title: Função &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::swap
- istream/std::ws
ms.assetid: 0301ea0d-4ded-4841-83dd-4253b55b3188
ms.openlocfilehash: 3d647c7b05a3868ec0359410cc0e703306b874ba
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363075"
---
# <a name="ltistreamgt-functions"></a>Função &lt;istream&gt;

|||
|-|-|
|[Trocar](#istream_swap)|[Ws](#ws)|

## <a name="swap"></a><a name="istream_swap"></a>Trocar

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

### <a name="parameters"></a>Parâmetros

*Deixou*\
Um fluxo.

*Certo*\
Um fluxo.

## <a name="ws"></a><a name="ws"></a>Ws

Ignora o espaço em branco no fluxo.

```cpp
template class<Elem, Tr> basic_istream<Elem, Tr>& ws(basic_istream<Elem, Tr>& _Istr);
```

### <a name="parameters"></a>Parâmetros

*_Istr*\
Um fluxo.

### <a name="return-value"></a>Valor retornado

O fluxo.

### <a name="remarks"></a>Comentários

O manipulador extrai e descarta `ch` quaisquer elementos para os quais [use_facet](../standard-library/basic-filebuf-class.md#open)< **ctype** \< **Elem**> > [(getloc).](../standard-library/ios-base-class.md#getloc) **is**( **ctype**\< **Elem**>:: **space**, **ch**) for verdadeiro.

A função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **eofbit**) se encontrar o fim do arquivo enquanto extrai os elementos. Ele retorna *_Istr*.

### <a name="example"></a>Exemplo

Consulte [operator>>](../standard-library/istream-operators.md#op_gt_gt) para ver um exemplo de como usar `ws`.

## <a name="see-also"></a>Confira também

[\<istream>](../standard-library/istream.md)
