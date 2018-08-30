---
title: Classe IConnectionPointImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IConnectionPointImpl
- ATLCOM/ATL::IConnectionPointImpl
- ATLCOM/ATL::IConnectionPointImpl::Advise
- ATLCOM/ATL::IConnectionPointImpl::EnumConnections
- ATLCOM/ATL::IConnectionPointImpl::GetConnectionInterface
- ATLCOM/ATL::IConnectionPointImpl::GetConnectionPointContainer
- ATLCOM/ATL::IConnectionPointImpl::Unadvise
- ATLCOM/ATL::IConnectionPointImpl::m_vec
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], implementing
- IConnectionPointImpl class
ms.assetid: 27992115-3b86-45dd-bc9e-54f32876c557
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d578aeea847ff04bf29fab11ecf7db2a1776b04f
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43217597"
---
# <a name="iconnectionpointimpl-class"></a>Classe IConnectionPointImpl
Essa classe implementa um ponto de conexão.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T, const IID* piid, class CDV = CComDynamicUnkArray>  
class ATL_NO_VTABLE IConnectionPointImpl : public _ICPLocator<piid>
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IConnectionPointImpl`.  
  
 *piid*  
 Um ponteiro para o IID da interface representada pelo objeto de ponto de conexão.  
  
 *CDV*  
 Uma classe que gerencia as conexões. O valor padrão é [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que permite conexões ilimitadas. Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IConnectionPointImpl::Advise](#advise)|Estabelece uma conexão entre o ponto de conexão e um coletor.|  
|[IConnectionPointImpl::EnumConnections](#enumconnections)|Cria um enumerador para iterar por meio de conexões para o ponto de conexão.|  
|[IConnectionPointImpl::GetConnectionInterface](#getconnectioninterface)|Recupera o IID da interface representado pelo ponto de conexão.|  
|[IConnectionPointImpl::GetConnectionPointContainer](#getconnectionpointcontainer)|Recupera um ponteiro de interface para o objeto conectável.|  
|[IConnectionPointImpl::Unadvise](#unadvise)|Encerra uma conexão estabelecida anteriormente por meio `Advise`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IConnectionPointImpl::m_vec](#m_vec)|Gerencia as conexões para o ponto de conexão.|  
  
## <a name="remarks"></a>Comentários  
 `IConnectionPointImpl` implementa um ponto de conexão, que permite que um objeto para expor uma interface de saída para o cliente. O cliente implementa essa interface em um objeto chamado coletor.  
  
 Usa o ATL [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md) para implementar o objeto conectável. Cada ponto de conexão dentro do objeto conectável representa uma interface de saída, identificada por *piid*. Classe *CDV* gerencia as conexões entre o ponto de conexão e um coletor. Cada conexão é identificada exclusivamente por um "cookie".  
  
 Para obter mais informações sobre como usar pontos de conexão no ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_ICPLocator`  
  
 `IConnectionPointImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="advise"></a>  IConnectionPointImpl::Advise  
 Estabelece uma conexão entre o ponto de conexão e um coletor.  
  
```
STDMETHOD(Advise)(
    IUnknown* pUnkSink,
    DWORD* pdwCookie);
```  
  
### <a name="remarks"></a>Comentários  
 Use [Unadvise](#unadvise) para encerrar a chamada de conexão.  
  
 Ver [IConnectionPoint::](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise) no Windows SDK.  
  
##  <a name="enumconnections"></a>  IConnectionPointImpl::EnumConnections  
 Cria um enumerador para iterar por meio de conexões para o ponto de conexão.  
  
```
STDMETHOD(EnumConnections)(IEnumConnections** ppEnum);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IConnectionPoint::EnumConnections](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-enumconnections) no Windows SDK.  
  
##  <a name="getconnectioninterface"></a>  IConnectionPointImpl::GetConnectionInterface  
 Recupera o IID da interface representado pelo ponto de conexão.  
  
```
STDMETHOD(GetConnectionInterface)(IID* piid2);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IConnectionPoint::GetConnectionInterface](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-getconnectioninterface) no Windows SDK.  
  
##  <a name="getconnectionpointcontainer"></a>  IConnectionPointImpl::GetConnectionPointContainer  
 Recupera um ponteiro de interface para o objeto conectável.  
  
```
STDMETHOD(GetConnectionPointContainer)(IConnectionPointContainer** ppCPC);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IConnectionPoint::GetConnectionPointContainer](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-getconnectionpointcontainer) no Windows SDK.  
  
##  <a name="m_vec"></a>  IConnectionPointImpl::m_vec  
 Gerencia as conexões entre o objeto de ponto de conexão e um coletor.  
  
```
CDV m_vec;
```     
  
### <a name="remarks"></a>Comentários  
 Por padrão, `m_vec` é do tipo [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md).  
  
##  <a name="unadvise"></a>  IConnectionPointImpl::Unadvise  
 Encerra uma conexão estabelecida anteriormente por meio [Advise](#advise).  
  
```
STDMETHOD(Unadvise)(DWORD dwCookie);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IConnectionPoint:: UnAdvise](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-unadvise) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [IConnectionPoint](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
