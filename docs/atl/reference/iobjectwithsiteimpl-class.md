---
title: Classe IObjectWithSiteImpl
ms.date: 11/04/2016
f1_keywords:
- IObjectWithSiteImpl
- ATLCOM/ATL::IObjectWithSiteImpl
- ATLCOM/ATL::IObjectWithSiteImpl::GetSite
- ATLCOM/ATL::IObjectWithSiteImpl::SetChildSite
- ATLCOM/ATL::IObjectWithSiteImpl::SetSite
- ATLCOM/ATL::IObjectWithSiteImpl::m_spUnkSite
helpviewer_keywords:
- IObjectWithSiteImpl class
ms.assetid: 4e1f774f-bc3d-45ee-9a1c-c3533a511588
ms.openlocfilehash: e857f739e3ff7235c473e99abbef6aab0d3f4205
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495841"
---
# <a name="iobjectwithsiteimpl-class"></a>Classe IObjectWithSiteImpl

Essa classe fornece métodos que permitem que um objeto se comunique com seu site.

## <a name="syntax"></a>Sintaxe

```
template <class T>
    class ATL_NO_VTABLE IObjectWithSiteImpl :
    public IObjectWithSite
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IObjectWithSiteImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IObjectWithSiteImpl::GetSite](#getsite)|Consulta o site para um ponteiro de interface.|
|[IObjectWithSiteImpl::SetChildSite](#setchildsite)|Fornece o objeto com o ponteiro do `IUnknown` site.|
|[IObjectWithSiteImpl::SetSite](#setsite)|Fornece o objeto com o ponteiro do `IUnknown` site.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IObjectWithSiteImpl::m_spUnkSite](#m_spunksite)|Gerencia o ponteiro do `IUnknown` site.|

## <a name="remarks"></a>Comentários

A interface [IObjectWithSite](/windows/win32/api/ocidl/nn-ocidl-iobjectwithsite) permite que um objeto se comunique com seu site. Fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IObjectWithSiteImpl`

`IObjectWithSiteImpl`Especifica dois métodos. O cliente primeiro chama `SetSite`, passando o ponteiro do `IUnknown` site. Esse ponteiro é armazenado no objeto e, posteriormente, pode ser recuperado por meio de uma `GetSite`chamada para.

Normalmente, você deriva sua classe de `IObjectWithSiteImpl` quando está criando um objeto que não é um controle. Para controles, derive sua classe de [IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md), que também fornece um ponteiro de site. Não Derive sua classe do `IObjectWithSiteImpl` e `IOleObjectImpl`do.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IObjectWithSite`

`IObjectWithSiteImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="getsite"></a>  IObjectWithSiteImpl::GetSite

Consulta o site para obter um ponteiro para a interface identificada por `riid`.

```
STDMETHOD(GetSite)(
    REFIID riid,
    void** ppvSite);
```

### <a name="remarks"></a>Comentários

Se o site der suporte a essa interface, o ponteiro será `ppvSite`retornado por meio de. Caso contrário `ppvSite` , será definido como nulo.

Consulte [IObjectWithSite:: GetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-getsite) na SDK do Windows.

##  <a name="m_spunksite"></a>  IObjectWithSiteImpl::m_spUnkSite

Gerencia o ponteiro do `IUnknown` site.

```
CComPtr<IUnknown> m_spUnkSite;
```

### <a name="remarks"></a>Comentários

`m_spUnkSite`inicialmente recebe esse ponteiro por meio de uma chamada para [SetSite](#setsite).

##  <a name="setchildsite"></a>  IObjectWithSiteImpl::SetChildSite

Fornece o objeto com o ponteiro do `IUnknown` site.

```
HRESULT SetChildSite(IUnknown* pUnkSite);
```

### <a name="parameters"></a>Parâmetros

*pUnkSite*<br/>
no Ponteiro para o `IUnknown` ponteiro de interface do site que gerencia esse objeto. Se for NULL, o objeto deverá `IUnknown::Release` chamar em qualquer site existente no ponto em que o objeto não conhece mais seu site.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="setsite"></a>  IObjectWithSiteImpl::SetSite

Fornece o objeto com o ponteiro do `IUnknown` site.

```
STDMETHOD(SetSite)(IUnknown* pUnkSite);
```

### <a name="remarks"></a>Comentários

Consulte [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
