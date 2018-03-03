---
title: Classe CComApartment | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComApartment
- ATLBASE/ATL::CComApartment
- ATLBASE/ATL::CComApartment::CComApartment
- ATLBASE/ATL::CComApartment::Apartment
- ATLBASE/ATL::CComApartment::GetLockCount
- ATLBASE/ATL::CComApartment::Lock
- ATLBASE/ATL::CComApartment::Unlock
- ATLBASE/ATL::CComApartment::m_dwThreadID
- ATLBASE/ATL::CComApartment::m_hThread
- ATLBASE/ATL::CComApartment::m_nLockCnt
dev_langs:
- C++
helpviewer_keywords:
- apartments in ATL EXE modules
- CComApartment class
ms.assetid: dbc177d7-7ee4-45f2-b563-d578a467ca93
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a3fecd77e93c0c51a37d7363e6ec1472d157d6d1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomapartment-class"></a>Classe CComApartment
Essa classe fornece suporte para gerenciar um apartamento em um módulo EXE pool de thread.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComApartment
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComApartment::CComApartment](#ccomapartment)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComApartment::Apartment](#apartment)|Marca o endereço inicial do segmento.|  
|[CComApartment::GetLockCount](#getlockcount)|Retorna a contagem de bloqueio atual do thread.|  
|[CComApartment::Lock](#lock)|Incrementa a contagem de bloqueio do thread.|  
|[CComApartment::Unlock](#unlock)|Contagem de bloqueio do thread diminui.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComApartment::m_dwThreadID](#m_dwthreadid)|Contém o identificador do segmento.|  
|[CComApartment::m_hThread](#m_hthread)|Contém o identificador do segmento.|  
|[CComApartment::m_nLockCnt](#m_nlockcnt)|Contém a contagem de bloqueio atual do thread.|  
  
## <a name="remarks"></a>Comentários  
 `CComApartment`é usado pelo [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) para gerenciar um apartment em um módulo EXE pool de thread. `CComApartment`fornece métodos para incrementar e decrementar o bloqueio de contagem em um thread.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="apartment"></a>CComApartment::Apartment  
 Marca o endereço inicial do segmento.  
  
```
DWORD Apartment();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre 0.  
  
### <a name="remarks"></a>Comentários  
 Definir automaticamente durante a [CComAutoThreadModule::Init](../../atl/reference/ccomautothreadmodule-class.md#init).  
  
##  <a name="ccomapartment"></a>CComApartment::CComApartment  
 O construtor.  
  
```
CComApartment();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa o `CComApartment` membros de dados [m_nLockCnt](#m_nlockcnt) e [m_hThread](#m_hthread).  
  
##  <a name="getlockcount"></a>CComApartment::GetLockCount  
 Retorna a contagem de bloqueio atual do thread.  
  
```
LONG GetLockCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de bloqueio no thread.  
  
##  <a name="lock"></a>CComApartment::Lock  
 Incrementa a contagem de bloqueio do thread.  
  
```
LONG Lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para um diagnóstico ou teste.  
  
### <a name="remarks"></a>Comentários  
 Chamado pelo [CComAutoThreadModule::Lock](../../atl/reference/ccomautothreadmodule-class.md#lock).  
  
 A contagem de bloqueio no thread é usada para fins estatísticos.  
  
##  <a name="m_dwthreadid"></a>CComApartment::m_dwThreadID  
 Contém o identificador do segmento.  
  
```
DWORD m_dwThreadID;
```  
  
##  <a name="m_hthread"></a>CComApartment::m_hThread  
 Contém o identificador do segmento.  
  
```
HANDLE m_hThread;
```  
  
##  <a name="m_nlockcnt"></a>CComApartment::m_nLockCnt  
 Contém a contagem de bloqueio atual do thread.  
  
```
LONG m_nLockCnt;
```  
  
##  <a name="unlock"></a>CComApartment::Unlock  
 Contagem de bloqueio do thread diminui.  
  
```
LONG Unlock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para um diagnóstico ou teste.  
  
### <a name="remarks"></a>Comentários  
 Chamado pelo [CComAutoThreadModule::Unlock](../../atl/reference/ccomautothreadmodule-class.md#lock).  
  
 A contagem de bloqueio no thread é usada para fins estatísticos.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
