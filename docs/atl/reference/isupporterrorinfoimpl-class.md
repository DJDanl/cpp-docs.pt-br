---
title: Classe ISupportErrorInfoImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ISupportErrorInfoImpl
- ATLCOM/ATL::ISupportErrorInfoImpl
- ATLCOM/ATL::ISupportErrorInfoImpl::InterfaceSupportsErrorInfo
dev_langs: C++
helpviewer_keywords:
- ISupportErrorInfo ATL implementation
- ISupportErrorInfoImpl class
- error information, ATL
ms.assetid: e33a4b11-a123-41cf-bcea-7b19743902af
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 61e8dc6b277f8eb59ade428d3ef8ea3dd5c083ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="isupporterrorinfoimpl-class"></a>Classe ISupportErrorInfoImpl
Essa classe fornece uma implementação padrão de [ISupportErrorInfo Interface](http://msdn.microsoft.com/en-us/42d33066-36b4-4a5b-aa5d-46682e560f32) e pode ser usada quando somente uma única interface gera erros em um objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<const IID* piid>  
class ATL_NO_VTABLE ISupportErrorInfoImpl 
   : public ISupportErrorInfo
```  
  
#### <a name="parameters"></a>Parâmetros  
 `piid`  
 Um ponteiro para o IID da interface que oferece suporte a [IErrorInfo](http://msdn.microsoft.com/en-us/4dda6909-2d9a-4727-ae0c-b5f90dcfa447).  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[ISupportErrorInfoImpl::InterfaceSupportsErrorInfo](#interfacesupportserrorinfo)|Indica se a interface identificado por `riid` oferece suporte a [IErrorInfo](http://msdn.microsoft.com/en-us/4dda6909-2d9a-4727-ae0c-b5f90dcfa447) interface.|  
  
## <a name="remarks"></a>Comentários  
 O [ISupportErrorInfo Interface](http://msdn.microsoft.com/en-us/42d33066-36b4-4a5b-aa5d-46682e560f32) garante que as informações de erro podem ser retornadas ao cliente. Objetos que usam **IErrorInfo** deve implementar **ISupportErrorInfo**.  
  
 Classe `ISupportErrorInfoImpl` fornece uma implementação padrão de **ISupportErrorInfo** e pode ser usada quando somente uma única interface gera erros em um objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#48](../../atl/codesnippet/cpp/isupporterrorinfoimpl-class_1.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ISupportErrorInfo`  
  
 `ISupportErrorInfoImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="interfacesupportserrorinfo"></a>ISupportErrorInfoImpl::InterfaceSupportsErrorInfo  
 Indica se a interface identificado por `riid` oferece suporte a [IErrorInfo](http://msdn.microsoft.com/en-us/4dda6909-2d9a-4727-ae0c-b5f90dcfa447) interface.  
  
```
STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [ISupportErrorInfo::InterfaceSupportsErrorInfo](http://msdn.microsoft.com/en-us/a54ef18d-ee3f-4483-ac4a-99d758f0960a) no SDK do Windows.  
  
##  <a name="getsize"></a>IThreadPoolConfig::GetSize  
 Chame este método para obter o número de threads no pool.  
  
```
STDMETHOD(GetSize)(int* pnNumThreads);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pnNumThreads`  
 [out] Endereço da variável que, em caso de sucesso, recebe o número de threads no pool.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#134](../../atl/codesnippet/cpp/isupporterrorinfoimpl-class_2.cpp)]  
  
##  <a name="gettimeout"></a>IThreadPoolConfig::GetTimeout  
 Chame este método para obter o tempo máximo em milissegundos que o pool de threads esperará por um thread desligar.  
  
```
STDMETHOD(GetTimeout)(DWORD* pdwMaxWait);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pdwMaxWait`  
 [out] Endereço da variável que, em caso de sucesso, recebe o tempo máximo, em milissegundos, que aguarda um thread desligar o pool de threads.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
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
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Consulte [IThreadPoolConfig::GetSize](#getsize).  
  
##  <a name="settimeout"></a>IThreadPoolConfig::SetTimeout  
 Chame esse método para definir o tempo máximo em milissegundos que o pool de threads esperará por um thread desligar.  
  
```
STDMETHOD(SetTimeout)(DWORD dwMaxWait);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMaxWait`  
 O tempo máximo solicitado em milissegundos que o pool de threads esperará por um thread desligar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Consulte [IThreadPoolConfig::GetSize](#getsize).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
