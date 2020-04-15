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
ms.openlocfilehash: 034e5dd42f6e10286520bb2a08effc40b0aca71a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329639"
---
# <a name="iobjectwithsiteimpl-class"></a>Classe IObjectWithSiteImpl

Esta classe fornece métodos que permitem que um objeto se comunique com seu site.

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

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iObjectWithSiteImpl::GetSite](#getsite)|Consulta o site para um ponteiro de interface.|
|[iObjectWithSiteImpl::SetChildSite](#setchildsite)|Fornece o objeto com `IUnknown` o ponteiro do site.|
|[iObjectWithSiteImpl::SetSite](#setsite)|Fornece o objeto com `IUnknown` o ponteiro do site.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[iObjectWithSiteImpl::m_spUnkSite](#m_spunksite)|Gerencia o ponteiro `IUnknown` do site.|

## <a name="remarks"></a>Comentários

A interface [IObjectWithSite](/windows/win32/api/ocidl/nn-ocidl-iobjectwithsite) permite que um objeto se comunique com seu site. A `IObjectWithSiteImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

`IObjectWithSiteImpl`especifica dois métodos. O cliente `SetSite`primeiro chama , `IUnknown` passando o ponteiro do site. Este ponteiro é armazenado dentro do objeto e pode `GetSite`ser recuperado posteriormente através de uma chamada para .

Normalmente, você obtém `IObjectWithSiteImpl` sua classe de quando você está criando um objeto que não é um controle. Para controles, obtenha sua classe de [IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md), que também fornece um ponteiro do site. Não desperte `IObjectWithSiteImpl` sua `IOleObjectImpl`classe de ambos e .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IObjectWithSite`

`IObjectWithSiteImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="iobjectwithsiteimplgetsite"></a><a name="getsite"></a>iObjectWithSiteImpl::GetSite

Consulta o site para obter um `riid`ponteiro para a interface identificada por .

```
STDMETHOD(GetSite)(
    REFIID riid,
    void** ppvSite);
```

### <a name="remarks"></a>Comentários

Se o site suportar essa interface, o `ppvSite`ponteiro será devolvido via . Caso contrário, `ppvSite` está definido como NULO.

Consulte [IObjectWithSite::GetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-getsite) no Windows SDK.

## <a name="iobjectwithsiteimplm_spunksite"></a><a name="m_spunksite"></a>iObjectWithSiteImpl::m_spUnkSite

Gerencia o ponteiro `IUnknown` do site.

```
CComPtr<IUnknown> m_spUnkSite;
```

### <a name="remarks"></a>Comentários

`m_spUnkSite`inicialmente recebe este ponteiro através de uma chamada para [SetSite](#setsite).

## <a name="iobjectwithsiteimplsetchildsite"></a><a name="setchildsite"></a>iObjectWithSiteImpl::SetChildSite

Fornece o objeto com `IUnknown` o ponteiro do site.

```
HRESULT SetChildSite(IUnknown* pUnkSite);
```

### <a name="parameters"></a>Parâmetros

*pUnkSite*<br/>
[em] Ponteiro para `IUnknown` o ponteiro de interface do site que gerencia este objeto. Se NULL, o `IUnknown::Release` objeto deve chamar qualquer site existente em que ponto o objeto não conhece mais seu site.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="iobjectwithsiteimplsetsite"></a><a name="setsite"></a>iObjectWithSiteImpl::SetSite

Fornece o objeto com `IUnknown` o ponteiro do site.

```
STDMETHOD(SetSite)(IUnknown* pUnkSite);
```

### <a name="remarks"></a>Comentários

Consulte [IObjectWithSite::SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite) no Windows SDK.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
