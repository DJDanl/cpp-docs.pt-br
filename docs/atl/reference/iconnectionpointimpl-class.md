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
ms.openlocfilehash: bd88fd5d00df0347c0bd2161129b8cfa3ca35406
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496089"
---
# <a name="iconnectionpointimpl-class"></a>Classe IConnectionPointImpl

Essa classe implementa um ponto de conexão.

## <a name="syntax"></a>Sintaxe

```
template<class T, const IID* piid, class CDV = CComDynamicUnkArray>
class ATL_NO_VTABLE IConnectionPointImpl : public _ICPLocator<piid>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IConnectionPointImpl`.

*piid*<br/>
Um ponteiro para o IID da interface representada pelo objeto de ponto de conexão.

*CDV*<br/>
Uma classe que gerencia as conexões. O valor padrão é [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que permite conexões ilimitadas. Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IConnectionPointImpl::Advise](#advise)|Estabelece uma conexão entre o ponto de conexão e um coletor.|
|[IConnectionPointImpl::EnumConnections](#enumconnections)|Cria um enumerador para iterar pelas conexões do ponto de conexão.|
|[IConnectionPointImpl::GetConnectionInterface](#getconnectioninterface)|Recupera o IID da interface representada pelo ponto de conexão.|
|[IConnectionPointImpl::GetConnectionPointContainer](#getconnectionpointcontainer)|Recupera um ponteiro de interface para o objeto que pôde ser conectado.|
|[IConnectionPointImpl::Unadvise](#unadvise)|Encerra uma conexão estabelecida anteriormente por meio `Advise`do.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IConnectionPointImpl::m_vec](#m_vec)|Gerencia as conexões para o ponto de conexão.|

## <a name="remarks"></a>Comentários

`IConnectionPointImpl`implementa um ponto de conexão, que permite que um objeto exponha uma interface de saída para o cliente. O cliente implementa essa interface em um objeto chamado coletor.

A ATL usa [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md) para implementar o objeto conectável. Cada ponto de conexão dentro do objeto conectável representa uma interface de saída, identificada por *piid*. A classe *CDV* gerencia as conexões entre o ponto de conexão e um coletor. Cada conexão é identificada exclusivamente por um "cookie".

Para obter mais informações sobre como usar pontos de conexão na ATL, consulte o artigo [pontos de conexão](../../atl/atl-connection-points.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_ICPLocator`

`IConnectionPointImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="advise"></a>IConnectionPointImpl:: Advise

Estabelece uma conexão entre o ponto de conexão e um coletor.

```
STDMETHOD(Advise)(
    IUnknown* pUnkSink,
    DWORD* pdwCookie);
```

### <a name="remarks"></a>Comentários

Use [Unadvise](#unadvise) para encerrar a chamada de conexão.

Consulte [IConnectionPoint:: Advise](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-advise) na SDK do Windows.

##  <a name="enumconnections"></a>  IConnectionPointImpl::EnumConnections

Cria um enumerador para iterar pelas conexões do ponto de conexão.

```
STDMETHOD(EnumConnections)(IEnumConnections** ppEnum);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint:: EnumConnections](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-enumconnections) na SDK do Windows.

##  <a name="getconnectioninterface"></a>  IConnectionPointImpl::GetConnectionInterface

Recupera o IID da interface representada pelo ponto de conexão.

```
STDMETHOD(GetConnectionInterface)(IID* piid2);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint:: GetConnectionInterface](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-getconnectioninterface) na SDK do Windows.

##  <a name="getconnectionpointcontainer"></a>  IConnectionPointImpl::GetConnectionPointContainer

Recupera um ponteiro de interface para o objeto que pôde ser conectado.

```
STDMETHOD(GetConnectionPointContainer)(IConnectionPointContainer** ppCPC);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint:: GetConnectionPointContainer](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-getconnectionpointcontainer) na SDK do Windows.

##  <a name="m_vec"></a>  IConnectionPointImpl::m_vec

Gerencia as conexões entre o objeto de ponto de conexão e um coletor.

```
CDV m_vec;
```

### <a name="remarks"></a>Comentários

Por padrão, `m_vec` é do tipo [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md).

##  <a name="unadvise"></a>IConnectionPointImpl:: Unadvise

Encerra uma conexão estabelecida anteriormente por meio de [Advise](#advise).

```
STDMETHOD(Unadvise)(DWORD dwCookie);
```

### <a name="remarks"></a>Comentários

Consulte [IConnectionPoint:: Unadvise](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-unadvise) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[IConnectionPoint](/windows/win32/api/ocidl/nn-ocidl-iconnectionpoint)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
