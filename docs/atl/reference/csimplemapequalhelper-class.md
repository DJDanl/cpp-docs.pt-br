---
title: Classe CSimpleMapEqualHelper | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleMapEqualHelper
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelper
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelper::IsEqualKey
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelper::IsEqualValue
dev_langs:
- C++
helpviewer_keywords:
- CSimpleMapEqualHelper class
ms.assetid: 9bb2968a-d609-405c-8272-ff3b42df6164
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: ddb793889748446b9613c91ce6fcefe28da32eb3
ms.lasthandoff: 02/25/2017

---
# <a name="csimplemapequalhelper-class"></a>Classe CSimpleMapEqualHelper
Essa classe é um auxiliar de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class TKey, class TVal>  
class CSimpleMapEqualHelper
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TKey`  
 O elemento chave.  
  
 `TVal`  
 O elemento de valor.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleMapEqualHelper::IsEqualKey](#isequalkey)|(Estático) Testa as duas chaves para igualdade.|  
|[CSimpleMapEqualHelper::IsEqualValue](#isequalvalue)|(Estático) Testa dois valores de igualdade.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de características é um suplemento de `CSimpleMap` classe. Fornece métodos para comparar dois `CSimpleMap` elementos (especificamente, os componentes de chave e valor) de igualdade do objeto. Por padrão, as chaves e valores são comparados usando `operator==()`, mas se o mapa contém tipos de dados complexos que não possuem seu próprios operador de igualdade, essa classe pode ser substituída para fornecer a funcionalidade adicional necessária.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequalkey"></a>CSimpleMapEqualHelper::IsEqualKey  
 Testa as duas chaves para igualdade.  
  
```
static bool IsEqualKey(const TKey& k1, const TKey& k2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `k1`  
 A primeira chave.  
  
 `k2`  
 A segunda chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se as chaves forem iguais; caso contrário, false.  
  
##  <a name="isequalvalue"></a>CSimpleMapEqualHelper::IsEqualValue  
 Testa dois valores de igualdade.  
  
```
static bool IsEqualValue(const TVal& v1, const TVal& v2);
```  
  
### <a name="parameters"></a>Parâmetros  
 *v1*  
 O primeiro valor.  
  
 *v2*  
 O segundo valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os valores forem iguais; caso contrário, false.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleMapEqualHelperFalse](../../atl/reference/csimplemapequalhelperfalse-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

