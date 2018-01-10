---
title: "Funções &lt;istream&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- istream/std::swap
- istream/std::ws
ms.assetid: 0301ea0d-4ded-4841-83dd-4253b55b3188
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 30bf6fb6bba318d2ab4d150fb242a28e4148083d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ltistreamgt-functions"></a>Função &lt;istream&gt;
|||  
|-|-|  
|[swap](#istream_swap)|[ws](#ws)|  
  
##  <a name="istream_swap"></a>  swap  
 Troca os elementos de dois objetos de fluxo.  
  
```  
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
 `left`  
 Um fluxo.  
  
 `right`  
 Um fluxo.  
  
##  <a name="ws"></a>  ws  
 Ignora o espaço em branco no fluxo.  
  
```  
template class<Elem, Tr> basic_istream<Elem, Tr>& ws(basic_istream<Elem, Tr>& _Istr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Istr`  
 Um fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo.  
  
### <a name="remarks"></a>Comentários  
 O manipulador extrai e descarta quaisquer elementos `ch` para os quais [use_facet](../standard-library/basic-filebuf-class.md#open)< **ctype**\< **Elem**> >( [getloc](../standard-library/ios-base-class.md#getloc)). **is**( **ctype**\< **Elem**>:: **space**, **ch**) for verdadeiro.  
  
 A função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **eofbit**) se encontrar o fim do arquivo enquanto extrai os elementos. Ele retorna `_Istr`.  
  
### <a name="example"></a>Exemplo  
  Consulte [operator>>](../standard-library/istream-operators.md#op_gt_gt) para ver um exemplo de como usar `ws`.  
  
## <a name="see-also"></a>Consulte também  
 [\<istream>](../standard-library/istream.md)

