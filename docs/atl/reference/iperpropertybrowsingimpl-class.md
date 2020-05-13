---
title: Classe IPerPropertyBrowsingImpl
ms.date: 11/04/2016
f1_keywords:
- IPerPropertyBrowsingImpl
- ATLCTL/ATL::IPerPropertyBrowsingImpl
- ATLCTL/ATL::IPerPropertyBrowsingImpl::GetDisplayString
- ATLCTL/ATL::IPerPropertyBrowsingImpl::GetPredefinedStrings
- ATLCTL/ATL::IPerPropertyBrowsingImpl::GetPredefinedValue
- ATLCTL/ATL::IPerPropertyBrowsingImpl::MapPropertyToPage
helpviewer_keywords:
- IPerPropertyBrowsingImpl class
- property pages, accessing information
- IPerPropertyBrowsing, ATL implementation
ms.assetid: 0b1a9be3-d242-4767-be69-663a21e4b728
ms.openlocfilehash: f8fb80cc38e775b9b26afa033647faac694e968a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326508"
---
# <a name="iperpropertybrowsingimpl-class"></a>Classe IPerPropertyBrowsingImpl

Essa classe `IUnknown` implementa e permite que um cliente acesse as informações nas páginas de propriedade de um objeto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```

template <class T>
class ATL_NO_VTABLE IPerPropertyBrowsingImpl :
    public IPerPropertyBrowsing
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPerPropertyBrowsingImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IPerPropertyBrowsingImpl::GetDisplayString](#getdisplaystring)|Recupera uma seqüência descrevendo uma determinada propriedade.|
|[IPerPropertyBrowsingImpl::GetPredefinedStrings](#getpredefinedstrings)|Recupera uma matriz de strings correspondente aos valores que uma determinada propriedade pode aceitar.|
|[IPerPropertyBrowsingImpl::GetPredefinedValue](#getpredefinedvalue)|Recupera uma VARIANT contendo o valor de uma propriedade identificada por um determinado DISPID. O DISPID está associado ao nome `GetPredefinedStrings`da seqüência recuperado de . A implementação da ATL retorna E_NOTIMPL.|
|[IPerPropertyBrowsingImpl:MapPropertyToPage](#mappropertytopage)|Recupera o CLSID da página de propriedade associada a uma determinada propriedade.|

## <a name="remarks"></a>Comentários

A interface [IPerPropertyBrowsing](/windows/win32/api/ocidl/nn-ocidl-iperpropertybrowsing) permite que um cliente acesse as informações nas páginas de propriedade de um objeto. A `IPerPropertyBrowsingImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

> [!NOTE]
> Se você estiver usando o Microsoft Access como aplicativo `IPerPropertyBrowsingImpl`de contêiner, você deve derivar sua classe de . Caso contrário, o Access não carregará seu controle.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPerPropertyBrowsing`

`IPerPropertyBrowsingImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="iperpropertybrowsingimplgetdisplaystring"></a><a name="getdisplaystring"></a>IPerPropertyBrowsingImpl::GetDisplayString

Recupera uma seqüência descrevendo uma determinada propriedade.

```
STDMETHOD(GetDisplayString)(
    DISPID dispID,
    BSTR* pBstr);
```

### <a name="remarks"></a>Comentários

Consulte [IPerPropertyBrowsing::GetDisplayString](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-getdisplaystring) no Windows SDK.

## <a name="iperpropertybrowsingimplgetpredefinedstrings"></a><a name="getpredefinedstrings"></a>IPerPropertyBrowsingImpl::GetPredefinedStrings

Preenche cada matriz com zero itens.

```
STDMETHOD(GetPredefinedStrings)(
    DISPID dispID,
    CALPOLESTR* pCaStringsOut,
    CADWORD* pCaCookiesOut);
```

### <a name="return-value"></a>Valor retornado

A implementação do [GetPredefinedValue](#getpredefinedvalue) da ATL retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPerPropertyBrowsing::GetPredefinedStrings](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings) no Windows SDK.

## <a name="iperpropertybrowsingimplgetpredefinedvalue"></a><a name="getpredefinedvalue"></a>IPerPropertyBrowsingImpl::GetPredefinedValue

Recupera uma VARIANT contendo o valor de uma propriedade identificada por um determinado DISPID. O DISPID está associado ao nome `GetPredefinedStrings`da seqüência recuperado de .

```
STDMETHOD(GetPredefinedValue)(
    DISPID dispID,
    DWORD dwCookie,
    VARIANT* pVarOut);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

A implementação do [GetPredefinedStrings](#getpredefinedstrings) da ATL não recupera seqüências correspondentes.

Consulte [IPerPropertyBrowsing::GetPredefinedValue](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue) no Windows SDK.

## <a name="iperpropertybrowsingimplmappropertytopage"></a><a name="mappropertytopage"></a>IPerPropertyBrowsingImpl:MapPropertyToPage

Recupera o CLSID da página de propriedade associada à propriedade especificada.

```
STDMETHOD(MapPropertyToPage)(
    DISPID dispID,
    CLSID* pClsid);
```

### <a name="remarks"></a>Comentários

O ATL usa o mapa de propriedade do objeto para obter essas informações.

Consulte [IPerPropertyBrowsing::MapPropertyToPage](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-mappropertytopage) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)<br/>
[ISpecifiePropertyPagesImpl Class](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
