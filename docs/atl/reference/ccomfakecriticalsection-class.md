---
title: Classe CComFakeCriticalSection | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CComFakeCriticalSection
- CComFakeCriticalSection
- ATL::CComFakeCriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CComFakeCriticalSection class
ms.assetid: a4811b97-96bb-493b-ab9f-62822aeddb10
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
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: 2c1269288e03a8ac9f359dad9acf1a81ddbc84c2
ms.lasthandoff: 02/25/2017

---
# <a name="ccomfakecriticalsection-class"></a>Classe CComFakeCriticalSection
Essa classe fornece os mesmos métodos que [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) , mas não oferece uma seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComFakeCriticalSection
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComFakeCriticalSection::Init](#init)|Não fará nada, pois há uma seção crítica.|  
|[CComFakeCriticalSection::Lock](#lock)|Não fará nada, pois há uma seção crítica.|  
|[CComFakeCriticalSection::Term](#term)|Não fará nada, pois há uma seção crítica.|  
|[CComFakeCriticalSection::Unlock](#unlock)|Não fará nada, pois há uma seção crítica.|  
  
## <a name="remarks"></a>Comentários  
 `CComFakeCriticalSection`espelha os métodos encontrados em [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No entanto, `CComFakeCriticalSection` não fornece uma seção crítica; portanto, seus métodos não fazem nada.  
  
 Normalmente, você usa `CComFakeCriticalSection` por meio de um `typedef` nomear, como `AutoCriticalSection` ou `CriticalSection`. Ao usar [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md), ambos `typedef` nomes de referência `CComFakeCriticalSection`. Ao usar [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), eles fazem referência [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md) e `CComCriticalSection`, respectivamente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="a-nameinita--ccomfakecriticalsectioninit"></a><a name="init"></a>CComFakeCriticalSection::Init  
 Não fará nada, pois há uma seção crítica.  
  
```
HRESULT Init() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
##  <a name="a-namelocka--ccomfakecriticalsectionlock"></a><a name="lock"></a>CComFakeCriticalSection::Lock  
 Não fará nada, pois há uma seção crítica.  
  
```
HRESULT Lock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
##  <a name="a-nameterma--ccomfakecriticalsectionterm"></a><a name="term"></a>CComFakeCriticalSection::Term  
 Não fará nada, pois há uma seção crítica.  
  
```
HRESULT Term() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
##  <a name="a-nameunlocka--ccomfakecriticalsectionunlock"></a><a name="unlock"></a>CComFakeCriticalSection::Unlock  
 Não fará nada, pois há uma seção crítica.  
  
```
HRESULT Unlock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

