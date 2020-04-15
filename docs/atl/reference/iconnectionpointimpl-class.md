---
title: Classe IConnectionPointImpl
ms.date: 11/04/2016
f1_keywords:
- IConnectionPointImpl
- ATLCOM/ATL::IConnectionPointImpl
- ATLCOM/ATL::IConnectionPointImpl::Advise
- ATLCOM/ATL::IConnectionPointImpl::EnumConnections
- ATLCOM/ATL::IConnectionPointImpl::GetConnectionInterface
- ATLCOM/ATL::IConnectionPointImpl::GetConnectionPointContainer
- ATLCOM/ATL::IConnectionPointImpl::Unadvise
- ATLCOM/ATL::IConnectionPointImpl::m_vec
helpviewer_keywords:
- connection points [C++], implementing
- IConnectionPointImpl class
ms.assetid: 27992115-3b86-45dd-bc9e-54f32876c557
ms.openlocfilehash: c62ac3310a579379674674a7a9a517e3f2fd60e5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329849"
---
# <a name="iconnectionpointimpl-class"></a>Classe IConnectionPointImpl

Esta classe implementa um ponto de conexão.

## <a name="syntax"></a>Sintaxe

```
template<class T, const IID* piid, class CDV = CComDynamicUnkArray>
class ATL_NO_VTABLE IConnectionPointImpl : public _ICPLocator<piid>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IConnectionPointImpl`.

*Piid*<br/>
Um ponteiro para o IID da interface representado pelo objeto de ponto de conexão.

*Cdv*<br/>
Uma classe que gerencia as conexões. O valor padrão é [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que permite conexões ilimitadas. Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IConnectionPointImpl:::Aconselhar](#advise)|Estabelece uma conexão entre o ponto de conexão e uma pia.|
|[IConnectionPointImpl::EnumConnections](#enumconnections)|Cria um enumerador para iterar através das conexões para o ponto de conexão.|
|[IConnectionPointImpl::GetConnectionInterface](#getconnectioninterface)|Recupera o IID da interface representada pelo ponto de conexão.|
|[IConnectionPointImpl::GetConnectionPointContainer](#getconnectionpointcontainer)|Recupera um ponteiro de interface para o objeto conectável.|
|[IConnectionPointImpl::Unadvise](#unadvise)|Termina uma conexão previamente `Advise`estabelecida através de .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IConnectionPointImpl::m_vec](#m_vec)|Gerencia as conexões para o ponto de conexão.|

## <a name="remarks"></a>Comentários

`IConnectionPointImpl`implementa um ponto de conexão, que permite que um objeto exponha uma interface de saída ao cliente. O cliente implementa essa interface em um objeto chamado pia.

A ATL usa [o IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md) para implementar o objeto conectável. Cada ponto de conexão dentro do objeto conectável representa uma interface de saída, identificada por *piid*. A classe *CDV* gerencia as conexões entre o ponto de conexão e uma pia. Cada conexão é identificada exclusivamente por um "cookie".

Para obter mais informações sobre o uso de pontos de conexão no ATL, consulte o artigo [Pontos de Conexão](../../atl/atl-connection-points.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_ICPLocator`

`IConnectionPointImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="iconnectionpointimpladvise"></a><a name="advise"></a>IConnectionPointImpl:::Aconselhar

Estabelece uma conexão entre o ponto de conexão e uma pia.

```
STDMETHOD(Advise)(
    IUnknown* pUnkSink,
    DWORD* pdwCookie);
```

### <a name="remarks"></a>Comentários

Use [Unadvise](#unadvise) para encerrar a chamada de conexão.

Consulte [IConnectionPoint::Aconselhar](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-advise) no Windows SDK.

## <a name="iconnectionpointimplenumconnections"></a><a name="enumconnections"></a>IConnectionPointImpl::EnumConnections

Cria um enumerador para iterar através das conexões para o ponto de conexão.

```
STDMETHOD(EnumConnections)(IEnumConnections** ppEnum);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint::EnumConnections](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-enumconnections) no Windows SDK.

## <a name="iconnectionpointimplgetconnectioninterface"></a><a name="getconnectioninterface"></a>IConnectionPointImpl::GetConnectionInterface

Recupera o IID da interface representada pelo ponto de conexão.

```
STDMETHOD(GetConnectionInterface)(IID* piid2);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint::GetConnectionInterface](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-getconnectioninterface) no Windows SDK.

## <a name="iconnectionpointimplgetconnectionpointcontainer"></a><a name="getconnectionpointcontainer"></a>IConnectionPointImpl::GetConnectionPointContainer

Recupera um ponteiro de interface para o objeto conectável.

```
STDMETHOD(GetConnectionPointContainer)(IConnectionPointContainer** ppCPC);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint::GetConnectionPointContainer](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-getconnectionpointcontainer) no Windows SDK.

## <a name="iconnectionpointimplm_vec"></a><a name="m_vec"></a>IConnectionPointImpl::m_vec

Gerencia as conexões entre o objeto do ponto de conexão e uma pia.

```
CDV m_vec;
```

### <a name="remarks"></a>Comentários

Por padrão, `m_vec` é do tipo [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md).

## <a name="iconnectionpointimplunadvise"></a><a name="unadvise"></a>IConnectionPointImpl::Unadvise

Encerra uma conexão previamente estabelecida através [do Conselho](#advise).

```
STDMETHOD(Unadvise)(DWORD dwCookie);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint::Unadvise](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-unadvise) no SDK do Windows.

## <a name="see-also"></a>Confira também

[IConnectionPoint](/windows/win32/api/ocidl/nn-ocidl-iconnectionpoint)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
