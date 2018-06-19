---
title: Funções &lt;istream&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- istream/std::swap
- istream/std::ws
ms.assetid: 0301ea0d-4ded-4841-83dd-4253b55b3188
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6310281aa86c48ae0a8b0fb313e79994d0b9b538
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33863885"
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

### <a name="parameters"></a>Parâmetros

`left` Um fluxo.

`right` Um fluxo.

## <a name="ws"></a>  ws

Ignora o espaço em branco no fluxo.

```cpp
template class<Elem, Tr> basic_istream<Elem, Tr>& ws(basic_istream<Elem, Tr>& _Istr);
```

### <a name="parameters"></a>Parâmetros

`_Istr` Um fluxo.

### <a name="return-value"></a>Valor de retorno

O fluxo.

### <a name="remarks"></a>Comentários

O manipulador extrai e descarta quaisquer elementos `ch` para os quais [use_facet](../standard-library/basic-filebuf-class.md#open)< **ctype**\< **Elem**> >( [getloc](../standard-library/ios-base-class.md#getloc)). **is**( **ctype**\< **Elem**>:: **space**, **ch**) for verdadeiro.

A função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **eofbit**) se encontrar o fim do arquivo enquanto extrai os elementos. Ele retorna `_Istr`.

### <a name="example"></a>Exemplo

Consulte [operator>>](../standard-library/istream-operators.md#op_gt_gt) para ver um exemplo de como usar `ws`.

## <a name="see-also"></a>Consulte também

[\<istream>](../standard-library/istream.md)<br/>
