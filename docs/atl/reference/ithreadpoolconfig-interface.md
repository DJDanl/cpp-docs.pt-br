---
title: Interface IThreadPoolConfig | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IThreadPoolConfig
- ATLUTIL/ATL::IThreadPoolConfig
- ATLUTIL/ATL::GetSize
- ATLUTIL/ATL::GetTimeout
- ATLUTIL/ATL::SetSize
- ATLUTIL/ATL::SetTimeout
dev_langs:
- C++
helpviewer_keywords:
- IThreadPoolConfig interface
ms.assetid: 69e642bf-6925-46e6-9a37-cce52231b1cc
caps.latest.revision: 24
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: e10885373442890978feff42cda99309692a21d0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ithreadpoolconfig-interface"></a>Interface IThreadPoolConfig
Essa interface fornece métodos para configurar um pool de threads.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
__interface
    __declspec(uuid("B1F64757-6E88-4fa2-8886-7848B0D7E660")) IThreadPoolConfig : public IUnknown
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetSize](#getsize)|Chame esse método para obter o número de threads no pool.|  
|[GetTimeout](#gettimeout)|Chame esse método para obter o tempo máximo em milissegundos que o pool de threads irá aguardar por um segmento para desligar.|  
|[SetSize](#setsize)|Chame esse método para definir o número de threads no pool.|  
|[SetTimeout](#settimeout)|Chame esse método para definir o tempo máximo em milissegundos que o pool de threads irá aguardar por um segmento para desligar.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é implementada por [CThreadPool](../../atl/reference/cthreadpool-class.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="getsize"></a>IThreadPoolConfig::GetSize  
 Chame esse método para obter o número de threads no pool.  
  
```
STDMETHOD(GetSize)(int* pnNumThreads);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pnNumThreads`  
 [out] Endereço da variável que, em caso de sucesso, recebe o número de threads no pool.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities&#134;](../../atl/codesnippet/cpp/ithreadpoolconfig-interface_1.cpp)]  
  
##  <a name="gettimeout"></a>IThreadPoolConfig::GetTimeout  
 Chame esse método para obter o tempo máximo em milissegundos que o pool de threads irá aguardar por um segmento para desligar.  
  
```
STDMETHOD(GetTimeout)(DWORD* pdwMaxWait);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pdwMaxWait`  
 [out] Endereço da variável que, em caso de sucesso, recebe o tempo máximo em milissegundos que o pool de threads irá aguardar por um segmento para desligar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Consulte [IThreadPoolConfig::GetSize](#getsize).  
  
##  <a name="setsize"></a>IThreadPoolConfig::SetSize  
 Chame esse método para definir o número de threads no pool.  
  
```
STDMETHOD(SetSize)int nNumThreads);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNumThreads`  
 O número solicitado de threads no pool.  
  
 Se `nNumThreads` for negativo, seu valor absoluto será multiplicado pelo número de processadores na máquina para obter o número total de threads.  
  
 Se `nNumThreads` for zero, [ATLS_DEFAULT_THREADSPERPROC](http://msdn.microsoft.com/library/e0dcf107-72a9-4122-abb4-83c63aa7d571) será multiplicado pelo número de processadores na máquina para obter o número total de threads.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Consulte [IThreadPoolConfig::GetSize](#getsize).  
  
##  <a name="settimeout"></a>IThreadPoolConfig::SetTimeout  
 Chame esse método para definir o tempo máximo em milissegundos que o pool de threads irá aguardar por um segmento para desligar.  
  
```
STDMETHOD(SetTimeout)(DWORD dwMaxWait);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMaxWait`  
 O tempo máximo solicitado em milissegundos que o pool de threads irá aguardar por um segmento para desligar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Consulte [IThreadPoolConfig::GetSize](#getsize).  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../atl/reference/atl-classes.md)   
 [Classe CThreadPool](../../atl/reference/cthreadpool-class.md)

