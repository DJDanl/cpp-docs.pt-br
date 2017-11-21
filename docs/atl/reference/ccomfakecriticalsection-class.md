---
title: Classe CComFakeCriticalSection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComFakeCriticalSection
- ATLCORE/ATL::CComFakeCriticalSection
- ATLCORE/ATL::CComFakeCriticalSection::Init
- ATLCORE/ATL::CComFakeCriticalSection::Lock
- ATLCORE/ATL::CComFakeCriticalSection::Term
- ATLCORE/ATL::CComFakeCriticalSection::Unlock
dev_langs: C++
helpviewer_keywords: CComFakeCriticalSection class
ms.assetid: a4811b97-96bb-493b-ab9f-62822aeddb10
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b0619dc44c630ea272531fdf6ef5f5da3a487d65
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ccomfakecriticalsection-class"></a>Classe CComFakeCriticalSection
Essa classe fornece os mesmos métodos que [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) , mas não fornece uma seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComFakeCriticalSection
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComFakeCriticalSection::Init](#init)|Não faz nada porque não há nenhuma seção crítica.|  
|[CComFakeCriticalSection::Lock](#lock)|Não faz nada porque não há nenhuma seção crítica.|  
|[CComFakeCriticalSection::Term](#term)|Não faz nada porque não há nenhuma seção crítica.|  
|[CComFakeCriticalSection::Unlock](#unlock)|Não faz nada porque não há nenhuma seção crítica.|  
  
## <a name="remarks"></a>Comentários  
 `CComFakeCriticalSection`espelha os métodos encontrados em [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No entanto, `CComFakeCriticalSection` não fornece uma seção crítica; portanto, seus métodos não fazem nada.  
  
 Normalmente, você usa `CComFakeCriticalSection` por meio de um `typedef` nomear, como `AutoCriticalSection` ou `CriticalSection`. Ao usar [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md), ambos `typedef` nomes de referência `CComFakeCriticalSection`. Ao usar [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), eles fazem referência [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md) e `CComCriticalSection`, respectivamente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="init"></a>CComFakeCriticalSection::Init  
 Não faz nada porque não há nenhuma seção crítica.  
  
```
HRESULT Init() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
##  <a name="lock"></a>CComFakeCriticalSection::Lock  
 Não faz nada porque não há nenhuma seção crítica.  
  
```
HRESULT Lock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
##  <a name="term"></a>CComFakeCriticalSection::Term  
 Não faz nada porque não há nenhuma seção crítica.  
  
```
HRESULT Term() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
##  <a name="unlock"></a>CComFakeCriticalSection::Unlock  
 Não faz nada porque não há nenhuma seção crítica.  
  
```
HRESULT Unlock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
