---
title: Classe CSimpleMapEqualHelperFalse | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleMapEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse::IsEqualKey
- ATLSIMPCOLL/ATL::CSimpleMapEqualHelperFalse::IsEqualValue
dev_langs:
- C++
helpviewer_keywords:
- CSimpleMapEqualHelperFalse class
ms.assetid: a873eea3-e130-45cc-a476-61ee79511c3b
caps.latest.revision: 19
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
ms.openlocfilehash: 68a08ffc0ba126c523a779e3d1a72217dead6235
ms.lasthandoff: 02/25/2017

---
# <a name="csimplemapequalhelperfalse-class"></a>Classe CSimpleMapEqualHelperFalse
Essa classe é um auxiliar de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class TKey, class TVal>  
class CSimpleMapEqualHelperFalse
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleMapEqualHelperFalse::IsEqualKey](#isequalkey)|(Estático) Testa as duas chaves para igualdade.|  
|[CSimpleMapEqualHelperFalse::IsEqualValue](#isequalvalue)|(Estático) Retorna falso.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de características é um suplemento de `CSimpleMap` classe. Ele fornece um método para comparar dois elementos contidos no `CSimpleMap` objeto, especificamente dois elementos de valor ou dois elementos principais.  
  
 A comparação do valor sempre retornará false e, além disso, chamará `ATLASSERT` com um argumento de false se ele já é referenciado. Em situações em que o teste de igualdade suficientemente não está definido, essa classe permite que um mapa que contém pares chave/valor para operar corretamente para a maioria dos métodos, mas falhar de maneira bem definida para os métodos que dependem de comparações como [CSimpleMap::FindVal](../../atl/reference/csimplemap-class.md#findval).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequalkey"></a>CSimpleMapEqualHelperFalse::IsEqualKey  
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
  
### <a name="remarks"></a>Comentários  
 Esse método chama [CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md).  
  
##  <a name="isequalvalue"></a>CSimpleMapEqualHelperFalse::IsEqualValue  
 Retorna false.  
  
```
static bool IsEqualValue(const TVal&, const TVal&);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna false.  
  
### <a name="remarks"></a>Comentários  
 Esse método sempre retorna false e chamará `ATLASSERT` com um argumento de false se ele já é referenciado. A finalidade de `CSimpleMapEqualHelperFalse::IsEqualValue` é forçar métodos usando comparações falha de maneira bem definida em testes de igualdade não foram definidas corretamente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

