---
title: Classe CSimpleMapEqualHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b4bfef99d12ae724c2ca6e70375f08a8dc1fb15b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32361834"
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
 O elemento de chave.  
  
 `TVal`  
 O elemento de valor.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleMapEqualHelper::IsEqualKey](#isequalkey)|(Estático) Testa as duas chaves para igualdade.|  
|[CSimpleMapEqualHelper::IsEqualValue](#isequalvalue)|(Estático) Testa dois valores para igualdade.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de características é um suplemento de `CSimpleMap` classe. Fornece métodos para comparar dois `CSimpleMap` elementos (especificamente, os componentes de chave e valor) para igualdade do objeto. Por padrão, as chaves e valores são comparados usando `operator==()`, mas se o mapa contém tipos de dados complexos que não têm seu próprios operador de igualdade, essa classe pode ser substituída para fornecer a funcionalidade extra necessária.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequalkey"></a>  CSimpleMapEqualHelper::IsEqualKey  
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
 Retorna VERDADEIRO se as chaves forem iguais; caso contrário, false.  
  
##  <a name="isequalvalue"></a>  CSimpleMapEqualHelper::IsEqualValue  
 Testa dois valores para igualdade.  
  
```
static bool IsEqualValue(const TVal& v1, const TVal& v2);
```  
  
### <a name="parameters"></a>Parâmetros  
 *V1*  
 O primeiro valor.  
  
 *V2*  
 O segundo valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os valores forem iguais; caso contrário, false.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleMapEqualHelperFalse](../../atl/reference/csimplemapequalhelperfalse-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
