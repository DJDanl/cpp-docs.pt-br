---
title: Classe CComCritSecLock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComCritSecLock
- ATLBASE/ATL::CComCritSecLock
- ATLBASE/ATL::CComCritSecLock::CComCritSecLock
- ATLBASE/ATL::CComCritSecLock::Lock
- ATLBASE/ATL::CComCritSecLock::Unlock
dev_langs:
- C++
helpviewer_keywords:
- CComCritSecLock class
ms.assetid: 223152a1-86c3-4ef9-89a7-f455fe791b0e
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 71b9ab8b11adc946656c2192c2f0f06555ef1254
ms.lasthandoff: 02/25/2017

---
# <a name="ccomcritseclock-class"></a>Classe CComCritSecLock
Essa classe fornece métodos para bloqueio e desbloqueio de um objeto da seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class TLock> class CComCritSecLock
```  
  
#### <a name="parameters"></a>Parâmetros  
 *TLock*  
 O objeto a ser bloqueada e desbloqueada.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCritSecLock::CComCritSecLock](#ctor)|O construtor.|  
|[CComCritSecLock:: ~ CComCritSecLock](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCritSecLock::Lock](#lock)|Chame esse método para bloquear o objeto da seção crítica.|  
|[CComCritSecLock::Unlock](#unlock)|Chame esse método para desbloquear o objeto da seção crítica.|  
  
## <a name="remarks"></a>Comentários  
 Use esta classe para bloquear e desbloquear objetos de uma maneira mais segura do que com o [CComCriticalSection classe](../../atl/reference/ccomcriticalsection-class.md) ou [CComAutoCriticalSection classe](../../atl/reference/ccomautocriticalsection-class.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="ctor"></a>CComCritSecLock::CComCritSecLock  
 O construtor.  
  
```
CComCritSecLock(TLock& cs, bool bInitialLock = true);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CS*  
 O objeto da seção crítica.  
  
 `bInitialLock`  
 O estado inicial de bloqueio: **true** significa bloqueada.  
  
### <a name="remarks"></a>Comentários  
 Inicializa o objeto da seção crítica.  
  
##  <a name="dtor"></a>CComCritSecLock:: ~ CComCritSecLock  
 O destruidor.  
  
```
~CComCritSecLock() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Desbloqueia o objeto da seção crítica.  
  
##  <a name="lock"></a>CComCritSecLock::Lock  
 Chame esse método para bloquear o objeto da seção crítica.  
  
```
HRESULT Lock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK se o objeto foi bloqueado com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto já está bloqueado, ocorrerá um erro ASSERT em compilações de depuração.  
  
##  <a name="unlock"></a>CComCritSecLock::Unlock  
 Chame esse método para desbloquear o objeto da seção crítica.  
  
```
void Unlock() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto já está desbloqueado, ocorrerá um erro ASSERT em compilações de depuração.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)   
 [Classe CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)

