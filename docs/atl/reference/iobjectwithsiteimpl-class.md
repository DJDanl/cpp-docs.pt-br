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
ms.openlocfilehash: ad27c4288d7e16949fe38ea6b8a686e3d6916ee6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62275224"
---
# <a name="iobjectwithsiteimpl-class"></a>Classe IObjectWithSiteImpl

Essa classe fornece métodos que permitem a um objeto para se comunicar com seu site.

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
|[IObjectWithSiteImpl::SetChildSite](#setchildsite)|Fornece o objeto com o site `IUnknown` ponteiro.|
|[IObjectWithSiteImpl::SetSite](#setsite)|Fornece o objeto com o site `IUnknown` ponteiro.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IObjectWithSiteImpl::m_spUnkSite](#m_spunksite)|Gerencia o site `IUnknown` ponteiro.|

## <a name="remarks"></a>Comentários

O [IObjectWithSite](/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) interface permite que um objeto para se comunicar com seu site. Classe `IObjectWithSiteImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

`IObjectWithSiteImpl` Especifica os dois métodos. O cliente primeiro chama `SetSite`, passando o site `IUnknown` ponteiro. Esse ponteiro é armazenado dentro do objeto e podem ser recuperado posteriormente por meio de uma chamada para `GetSite`.

Normalmente, você deriva sua classe de `IObjectWithSiteImpl` quando você estiver criando um objeto que não é um controle. Para controles, derive sua classe de [IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md), que também fornece um ponteiro de site. Deriva sua classe ambos `IObjectWithSiteImpl` e `IOleObjectImpl`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IObjectWithSite`

`IObjectWithSiteImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="getsite"></a>  IObjectWithSiteImpl::GetSite

Consulta o site de um ponteiro para a interface identificada pelo `riid`.

```
STDMETHOD(GetSite)(
    REFIID riid,
    void** ppvSite);
```

### <a name="remarks"></a>Comentários

Se o site oferece suporte a essa interface, o ponteiro é retornado por meio de `ppvSite`. Caso contrário, `ppvSite` é definido como NULL.

Ver [IObjectWithSite::GetSite](/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-getsite) no Windows SDK.

##  <a name="m_spunksite"></a>  IObjectWithSiteImpl::m_spUnkSite

Gerencia o site `IUnknown` ponteiro.

```
CComPtr<IUnknown> m_spUnkSite;
```

### <a name="remarks"></a>Comentários

`m_spUnkSite` inicialmente recebe esse ponteiro por meio de uma chamada para [SetSite](#setsite).

##  <a name="setchildsite"></a>  IObjectWithSiteImpl::SetChildSite

Fornece o objeto com o site `IUnknown` ponteiro.

```
HRESULT SetChildSite(IUnknown* pUnkSite);
```

### <a name="parameters"></a>Parâmetros

*pUnkSite*<br/>
[in] Ponteiro para o `IUnknown` ponteiro de interface do site gerenciando este objeto. Se for NULL, o objeto deve chamar `IUnknown::Release` em qualquer site existente no ponto em que o objeto não sabe que seu site.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="setsite"></a>  IObjectWithSiteImpl::SetSite

Fornece o objeto com o site `IUnknown` ponteiro.

```
STDMETHOD(SetSite)(IUnknown* pUnkSite);
```

### <a name="remarks"></a>Comentários

Ver [IObjectWithSite::SetSite](/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
