---
title: Classe CSimpleMapEqualHelperFalse | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 70cea341e7f78032cdaca260e3c891f4c762e0b6
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882618"
---
# <a name="csimplemapequalhelperfalse-class"></a>Classe CSimpleMapEqualHelperFalse
Essa classe é um auxiliar para o [CSimpleMap](../../atl/reference/csimplemap-class.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class TKey, class TVal>  
class CSimpleMapEqualHelperFalse
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleMapEqualHelperFalse::IsEqualKey](#isequalkey)|(Estático) Testes de duas chaves quanto à igualdade.|  
|[CSimpleMapEqualHelperFalse::IsEqualValue](#isequalvalue)|(Estático) Retorna falso.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de características é um suplemento para o `CSimpleMap` classe. Ele fornece um método para comparar dois elementos contidos no `CSimpleMap` objeto, especificamente dois elementos de valor ou os dois elementos principais.  
  
 A comparação de valor sempre retornará false e, além disso, irá chamar `ATLASSERT` com um argumento de false se ele nunca é referenciado. Em situações em que o teste de igualdade não está suficientemente definido, essa classe permite que um mapa que contém pares chave/valor para operar corretamente para a maioria dos métodos, mas falhar de maneira bem definida para os métodos que dependem de comparações, como [CSimpleMap:: FindVal](../../atl/reference/csimplemap-class.md#findval).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequalkey"></a>  CSimpleMapEqualHelperFalse::IsEqualKey  
 Testes de duas chaves quanto à igualdade.  
  
```
static bool IsEqualKey(const TKey& k1, const TKey& k2);
```  
  
### <a name="parameters"></a>Parâmetros  
 *K1*  
 A primeira chave.  
  
 *K2*  
 A segunda chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se as chaves são iguais, caso contrário, false.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md).  
  
##  <a name="isequalvalue"></a>  CSimpleMapEqualHelperFalse::IsEqualValue  
 Retorna false.  
  
```
static bool IsEqualValue(const TVal&, const TVal&);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna false.  
  
### <a name="remarks"></a>Comentários  
 Esse método sempre retorna false e chamará `ATLASSERT` com um argumento de false se ele nunca é referenciado. A finalidade de `CSimpleMapEqualHelperFalse::IsEqualValue` é forçar métodos usando comparações falhe de maneira bem definida, quando os testes de igualdade não foram definidos adequadamente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
