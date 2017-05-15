---
title: '&lt;utility&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- <utility>
- utility/std::<utility>
- std.<utility>
- std::<utility>
dev_langs:
- C++
helpviewer_keywords:
- utility header
ms.assetid: c4491103-5da9-47a1-9c2b-ed8bc64b0599
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 1a65dea30745ce3afa680c0851fe33cc9f386404
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="ltutilitygt"></a>&lt;utility&gt;
Define os tipos, funções e operadores da Biblioteca Padrão C++ que ajudam a construir e gerenciar pares de objetos úteis sempre que dois objetos precisam ser tratados como se fossem um.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <utility>  
  
```  
  
## <a name="remarks"></a>Comentários  
 Os pares são amplamente usados na Biblioteca Padrão C++. Eles são necessários como os argumentos e valores retornados para diversas funções e como tipos de elemento para contêineres como a [classe map](../standard-library/map-class.md) e a [classe multimap](../standard-library/multimap-class.md). O cabeçalho \<utility> é incluído automaticamente por \<map> para auxiliar no gerenciamento de elementos do tipo par chave/valor.  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[tuple_element](../standard-library/tuple-element-class-tuple.md)|Uma classe que encapsula o tipo de um elemento `pair`.|  
|[tuple_size](../standard-library/tuple-size-class-tuple.md)|Uma classe que encapsula a contagem do elemento `pair`.|  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[forward](../standard-library/utility-functions.md#forward)|Evita que o tipo de referência (`lvalue` ou `rvalue`) do argumento seja obscurecido por encaminhamento perfeito.|  
|[get](../standard-library/utility-functions.md#get)|Uma função que obtém um elemento de um objeto `pair`.|  
|[make_pair](../standard-library/utility-functions.md#make_pair)|Uma função modelo auxiliar usada para construir objetos do tipo `pair`, em que os tipos de componente são baseados nos tipos de dados transmitidos como parâmetros.|  
|[move](../standard-library/utility-functions.md#move)|Retorna o que foi passado no argumento como uma referência `rvalue`.|  
|[swap](../standard-library/utility-functions.md#swap)|Troca os elementos de dois objetos `pair`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator!=](../standard-library/utility-operators.md#op_neq)|Testa se o objeto pair à esquerda do operador é diferente do objeto pair à direita.|  
|[operator==](../standard-library/utility-operators.md#op_eq_eq)|Testa se o objeto pair à esquerda do operador é igual ao objeto pair à direita.|  
|[operator<](../standard-library/utility-operators.md#op_lt)|Testa se o objeto pair à esquerda do operador é menor que o objeto pair à direita.|  
|[operator\<=](../standard-library/utility-operators.md#op_gt_eq)|Testa se o objeto pair à esquerda do operador é menor que ou igual ao objeto pair à direita.|  
|[operator>](../standard-library/utility-operators.md#op_gt)|Testa se o objeto pair à esquerda do operador é maior que o objeto pair à direita.|  
|[operator>=](../standard-library/utility-operators.md#op_gt_eq)|Testa se o objeto pair à esquerda do operador é maior que ou igual ao objeto pair à direita.|  
  
### <a name="structs"></a>Structs  
  
|||  
|-|-|  
|[identity](../standard-library/identity-structure.md)||  
|[pair](../standard-library/pair-structure.md)|Um tipo que fornece a capacidade de tratar dois objetos como um único objeto.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




