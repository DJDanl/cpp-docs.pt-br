---
title: Classe CNoWorkerThread | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CNoWorkerThread
- ATLUTIL/ATL::CNoWorkerThread
- ATLUTIL/ATL::CNoWorkerThread::AddHandle
- ATLUTIL/ATL::CNoWorkerThread::AddTimer
- ATLUTIL/ATL::CNoWorkerThread::GetThreadHandle
- ATLUTIL/ATL::CNoWorkerThread::GetThreadId
- ATLUTIL/ATL::CNoWorkerThread::Initialize
- ATLUTIL/ATL::CNoWorkerThread::RemoveHandle
- ATLUTIL/ATL::CNoWorkerThread::Shutdown
dev_langs:
- C++
helpviewer_keywords:
- CNoWorkerThread class
ms.assetid: 29f06bae-b658-4aac-9c14-331e996d25d1
caps.latest.revision: 21
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 4c38d778849a31d55a657fc1022c2e9f4a370eec
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cnoworkerthread-class"></a>Classe CNoWorkerThread
Use essa classe como o argumento para o `MonitorClass` parâmetro de modelo para classes do cache se você quiser desabilitar a manutenção de cache dinâmico.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CNoWorkerThread
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CNoWorkerThread::AddHandle](#addhandle)|Não funcional equivalente de [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).|  
|[CNoWorkerThread::AddTimer](#addtimer)|Não funcional equivalente de [CWorkerThread::AddTimer](../../atl/reference/cworkerthread-class.md#addtimer).|  
|[CNoWorkerThread::GetThreadHandle](#getthreadhandle)|Não funcional equivalente de [CWorkerThread::GetThreadHandle](../../atl/reference/cworkerthread-class.md#getthreadhandle).|  
|[CNoWorkerThread::GetThreadId](#getthreadid)|Não funcional equivalente de [CWorkerThread::GetThreadId](../../atl/reference/cworkerthread-class.md#getthreadid).|  
|[CNoWorkerThread::Initialize](#initialize)|Não funcional equivalente de [CWorkerThread::Initialize](../../atl/reference/cworkerthread-class.md#initialize).|  
|[CNoWorkerThread::RemoveHandle](#removehandle)|Não funcional equivalente de [CWorkerThread::RemoveHandle](../../atl/reference/cworkerthread-class.md#removehandle).|  
|[CNoWorkerThread::Shutdown](#shutdown)|Não funcional equivalente de [CWorkerThread::Shutdown](../../atl/reference/cworkerthread-class.md#shutdown).|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece a mesma interface pública que [CWorkerThread](../../atl/reference/cworkerthread-class.md). Essa interface deve ser fornecido pelo `MonitorClass` classes de cache de parâmetro de modelo.  
  
 Os métodos nessa classe são implementados para não fazer nada. Os métodos que retornam um HRESULT sempre retornam S_OK e os métodos que retornam uma ID de identificador ou thread sempre retornam 0.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="addhandle"></a>CNoWorkerThread::AddHandle  
 Não funcional equivalente de [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).  
  
```
HRESULT AddHandle(HANDLE /* hObject
 */,
    IWorkerThreadClient* /* pClient
 */,
    DWORD_PTR /* dwParam
 */) throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 A implementação fornecida por essa classe não fará nada.  
  
##  <a name="addtimer"></a>CNoWorkerThread::AddTimer  
 Não funcional equivalente de [CWorkerThread::AddTimer](../../atl/reference/cworkerthread-class.md#addtimer).  
  
```
HRESULT AddTimer(DWORD /* dwInterval
 */,
    IWorkerThreadClient* /* pClient
 */,
    DWORD_PTR /* dwParam
 */,
    HANDLE* /* phTimer
 */) throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 A implementação fornecida por essa classe não fará nada.  
  
##  <a name="getthreadhandle"></a>CNoWorkerThread::GetThreadHandle  
 Não funcional equivalente de [CWorkerThread::GetThreadHandle](../../atl/reference/cworkerthread-class.md#getthreadhandle).  
  
```
HANDLE GetThreadHandle() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna NULL.  
  
### <a name="remarks"></a>Comentários  
 A implementação fornecida por essa classe não fará nada.  
  
##  <a name="getthreadid"></a>CNoWorkerThread::GetThreadId  
 Não funcional equivalente de [CWorkerThread::GetThreadId](../../atl/reference/cworkerthread-class.md#getthreadid).  
  
```
DWORD GetThreadId() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação fornecida por essa classe não fará nada.  
  
##  <a name="initialize"></a>CNoWorkerThread::Initialize  
 Não funcional equivalente de [CWorkerThread::Initialize](../../atl/reference/cworkerthread-class.md#initialize).  
  
```
HRESULT Initialize() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 A implementação fornecida por essa classe não fará nada.  
  
##  <a name="removehandle"></a>CNoWorkerThread::RemoveHandle  
 Não funcional equivalente de [CWorkerThread::RemoveHandle](../../atl/reference/cworkerthread-class.md#removehandle).  
  
```
HRESULT RemoveHandle(HANDLE /* hObject
 */) throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 A implementação fornecida por essa classe não fará nada.  
  
##  <a name="shutdown"></a>CNoWorkerThread::Shutdown  
 Não funcional equivalente de [CWorkerThread::Shutdown](../../atl/reference/cworkerthread-class.md#shutdown).  
  
```
HRESULT Shutdown(DWORD dwWait = ATL_WORKER_THREAD_WAIT) throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 A implementação fornecida por essa classe não fará nada.

