---
title: '&lt;mapa&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::<map>
- std.<map>
- <map>
dev_langs:
- C++
helpviewer_keywords:
- map header
ms.assetid: bbf76680-7362-456e-88fa-ecda93561b6a
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
translationtype: Machine Translation
ms.sourcegitcommit: 2d05749ba2837a3879c91886b9266de47dd2ece6
ms.openlocfilehash: fad398e9f18c2f45de7e071be464e3eff2e9243e
ms.lasthandoff: 02/25/2017

---
# <a name="ltmapgt"></a>&lt;map&gt;
Define o mapa e o multimapa das classes de modelo do contêiner e seus modelos de suporte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <map>  
  
```  
  
## <a name="members"></a>Membros  
  
### <a name="operators"></a>Operadores  
  
|Versão do mapa|Versão do multimapa|Descrição|  
|-----------------|----------------------|-----------------|  
|[operator!= (map)](../standard-library/map-operators.md#operator_neq)|[operator!= (multimap)](../standard-library/map-operators.md#operator_neq)|Testa se o objeto do mapa ou multimapa à esquerda do operador é diferente do objeto do mapa ou multimapa à direita.|  
|[operator< (mapa)](../standard-library/map-operators.md#operator_eq_eq)|[operator< (multimapa)](../standard-library/map-operators.md#operator_eq_eq)|Testa se o objeto do mapa ou multimapa à esquerda do operador é menor que o objeto de mapa ou multimapa à direita.|  
|[operator<= (mapa)](../standard-library/map-operators.md#operator_lt_)|[operator\<= (multimapa)](../standard-library/map-operators.md#operator_lt_)|Testa se o objeto do mapa ou multimapa à esquerda do operador é menor ou igual ao objeto do mapa ou multimapa à direita.|  
|[operator== (mapa)](../standard-library/map-operators.md#operator_lt__eq)|[operator== (multimapa)](../standard-library/map-operators.md#operator_lt__eq)|Testa se o objeto do mapa ou multimapa à esquerda do operador é igual ao objeto do mapa ou multimapa à direita.|  
|[operator> (mapa)](../standard-library/map-operators.md#operator_gt_)|[operator> (multimapa)](../standard-library/map-operators.md#operator_gt_)|Testa se o objeto do mapa ou multimapa à esquerda do operador é maior que o objeto do mapa ou multimapa à direita.|  
|[operator>= (mapa)](../standard-library/map-operators.md#operator_gt__eq)|[operator>= (multimapa)](../standard-library/map-operators.md#operator_gt__eq)|Testa se o objeto do mapa ou multimapa à esquerda do operador é maior ou igual ao objeto do mapa ou multimapa à direita.|  
  
### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas  
  
|Versão do mapa|Versão do multimapa|Descrição|  
|-----------------|----------------------|-----------------|  
|[swap (map)](../standard-library/map-functions.md#swap)|[swap (multimap)](../standard-library/map-functions.md#swap)|Troca os elementos de dois mapas ou multimapas.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe value_compare](../standard-library/value-compare-class-map.md)|Fornece um objeto de função que pode comparar os elementos de um mapa ao comparar os valores de suas chaves para determinar sua ordem relativa no mapa.|  
|[Classe map](../standard-library/map-class.md)|Usada para o armazenamento e recuperação de dados de uma coleção em que cada um dos elementos tem uma chave exclusiva, com a qual os dados são automaticamente ordenados.|  
|[Classe multimap](../standard-library/multimap-class.md)|Usada para o armazenamento e recuperação de dados de uma coleção em que cada um dos elementos tem uma chave, com a qual os dados são automaticamente ordenados e as chaves não precisam ter valores exclusivos.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




