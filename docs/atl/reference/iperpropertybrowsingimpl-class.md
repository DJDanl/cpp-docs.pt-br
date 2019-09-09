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
ms.openlocfilehash: 263f6826ac921d864dee646ef063c8b456b00af1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495722"
---
# <a name="iperpropertybrowsingimpl-class"></a>Classe IPerPropertyBrowsingImpl

Essa classe implementa `IUnknown` e permite que um cliente acesse as informações nas páginas de propriedades de um objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPerPropertyBrowsingImpl::GetDisplayString](#getdisplaystring)|Recupera uma cadeia de caracteres que descreve uma determinada propriedade.|
|[IPerPropertyBrowsingImpl::GetPredefinedStrings](#getpredefinedstrings)|Recupera uma matriz de cadeias de caracteres correspondentes aos valores que uma determinada propriedade pode aceitar.|
|[IPerPropertyBrowsingImpl::GetPredefinedValue](#getpredefinedvalue)|Recupera uma variante que contém o valor de uma propriedade identificada por um DISPID especificado. O DISPID é associado ao nome da cadeia de caracteres `GetPredefinedStrings`recuperado de. A implementação da ATL retorna E_NOTIMPL.|
|[IPerPropertyBrowsingImpl::MapPropertyToPage](#mappropertytopage)|Recupera o CLSID da página de propriedades associada a uma determinada propriedade.|

## <a name="remarks"></a>Comentários

A interface [IPerPropertyBrowsing](/windows/win32/api/ocidl/nn-ocidl-iperpropertybrowsing) permite que um cliente acesse as informações nas páginas de propriedades de um objeto. Fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IPerPropertyBrowsingImpl`

> [!NOTE]
>  Se você estiver usando o Microsoft Access como o aplicativo de contêiner, você deve derivar `IPerPropertyBrowsingImpl`sua classe de. Caso contrário, o Access não carregará seu controle.

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPerPropertyBrowsing`

`IPerPropertyBrowsingImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="getdisplaystring"></a>  IPerPropertyBrowsingImpl::GetDisplayString

Recupera uma cadeia de caracteres que descreve uma determinada propriedade.

```
STDMETHOD(GetDisplayString)(
    DISPID dispID,
    BSTR* pBstr);
```

### <a name="remarks"></a>Comentários

Consulte [IPerPropertyBrowsing:: Getdisplaystring](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-getdisplaystring) na SDK do Windows.

##  <a name="getpredefinedstrings"></a>  IPerPropertyBrowsingImpl::GetPredefinedStrings

Preenche cada matriz com zero itens.

```
STDMETHOD(GetPredefinedStrings)(
    DISPID dispID,
    CALPOLESTR* pCaStringsOut,
    CADWORD* pCaCookiesOut);
```

### <a name="return-value"></a>Valor de retorno

A implementação da ATL de [predefinevalue](#getpredefinedvalue) retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPerPropertyBrowsing:: GetPredefinedStrings](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings) na SDK do Windows.

##  <a name="getpredefinedvalue"></a>  IPerPropertyBrowsingImpl::GetPredefinedValue

Recupera uma variante que contém o valor de uma propriedade identificada por um DISPID especificado. O DISPID é associado ao nome da cadeia de caracteres `GetPredefinedStrings`recuperado de.

```
STDMETHOD(GetPredefinedValue)(
    DISPID dispID,
    DWORD dwCookie,
    VARIANT* pVarOut);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

A implementação da ATL de [GetPredefinedStrings](#getpredefinedstrings) não recupera nenhuma cadeia de caracteres correspondente.

Consulte [IPerPropertyBrowsing:: predefinevalue](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue) na SDK do Windows.

##  <a name="mappropertytopage"></a>  IPerPropertyBrowsingImpl::MapPropertyToPage

Recupera o CLSID da página de propriedades associada à propriedade especificada.

```
STDMETHOD(MapPropertyToPage)(
    DISPID dispID,
    CLSID* pClsid);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedades do objeto para obter essas informações.

Consulte [IPerPropertyBrowsing:: MapPropertyToPage](/windows/win32/api/ocidl/nf-ocidl-iperpropertybrowsing-mappropertytopage) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)<br/>
[Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
