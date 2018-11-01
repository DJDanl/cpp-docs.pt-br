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
ms.openlocfilehash: ce7c581d4378cb1f6e5556d488164a9b5fd9098a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50585296"
---
# <a name="iperpropertybrowsingimpl-class"></a>Classe IPerPropertyBrowsingImpl

Essa classe implementa `IUnknown` e permite que um cliente acessar as informações nas páginas de propriedades de um objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[IPerPropertyBrowsingImpl::GetPredefinedStrings](#getpredefinedstrings)|Recupera uma matriz de cadeias de caracteres que correspondem aos valores de uma determinada propriedade pode aceitar.|
|[IPerPropertyBrowsingImpl::GetPredefinedValue](#getpredefinedvalue)|Recupera uma VARIANTE que contém o valor de uma propriedade identificada por um DISPID determinado. O DISPID está associado com o nome de cadeia de caracteres recuperado do `GetPredefinedStrings`. A implementação de ATL retornará E_NOTIMPL.|
|[IPerPropertyBrowsingImpl::MapPropertyToPage](#mappropertytopage)|Recupera o CLSID da página de propriedades associada com uma determinada propriedade.|

## <a name="remarks"></a>Comentários

O [IPerPropertyBrowsing](/windows/desktop/api/ocidl/nn-ocidl-iperpropertybrowsing) interface permite que um cliente acessar as informações nas páginas de propriedades de um objeto. Classe `IPerPropertyBrowsingImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

> [!NOTE]
>  Se você estiver usando o Microsoft Access como o aplicativo de contêiner, você deve derivar sua classe de `IPerPropertyBrowsingImpl`. Caso contrário, o acesso não carregará seu controle.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPerPropertyBrowsing`

`IPerPropertyBrowsingImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="getdisplaystring"></a>  IPerPropertyBrowsingImpl::GetDisplayString

Recupera uma cadeia de caracteres que descreve uma determinada propriedade.

```
STDMETHOD(GetDisplayString)(
    DISPID dispID,
    BSTR* pBstr);
```

### <a name="remarks"></a>Comentários

Ver [IPerPropertyBrowsing::GetDisplayString](/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getdisplaystring) no Windows SDK.

##  <a name="getpredefinedstrings"></a>  IPerPropertyBrowsingImpl::GetPredefinedStrings

Preenche cada matriz com zero itens.

```
STDMETHOD(GetPredefinedStrings)(
    DISPID dispID,
    CALPOLESTR* pCaStringsOut,
    CADWORD* pCaCookiesOut);
```

### <a name="return-value"></a>Valor de retorno

Implementação do ATL [GetPredefinedValue](#getpredefinedvalue) retornará E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IPerPropertyBrowsing: GetPredefinedStrings](/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings) no Windows SDK.

##  <a name="getpredefinedvalue"></a>  IPerPropertyBrowsingImpl::GetPredefinedValue

Recupera uma VARIANTE que contém o valor de uma propriedade identificada por um DISPID determinado. O DISPID está associado com o nome de cadeia de caracteres recuperado do `GetPredefinedStrings`.

```
STDMETHOD(GetPredefinedValue)(
    DISPID dispID,
    DWORD dwCookie,
    VARIANT* pVarOut);
```

### <a name="return-value"></a>Valor de retorno

Retornará E_NOTIMPL.

### <a name="remarks"></a>Comentários

Implementação do ATL [GetPredefinedStrings](#getpredefinedstrings) recupera sem cadeias de caracteres correspondentes.

Ver [IPerPropertyBrowsing::GetPredefinedValue](/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue) no Windows SDK.

##  <a name="mappropertytopage"></a>  IPerPropertyBrowsingImpl::MapPropertyToPage

Recupera o CLSID da página de propriedades associada com a propriedade especificada.

```
STDMETHOD(MapPropertyToPage)(
    DISPID dispID,
    CLSID* pClsid);
```

### <a name="remarks"></a>Comentários

ATL usa o mapa de propriedade do objeto para obter essas informações.

Ver [IPerPropertyBrowsing::MapPropertyToPage](/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-mappropertytopage) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)<br/>
[Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
