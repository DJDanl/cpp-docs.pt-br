---
title: Classe IObjectSafetyImpl
ms.date: 11/04/2016
f1_keywords:
- IObjectSafetyImpl
- ATLCTL/ATL::IObjectSafetyImpl
- ATLCTL/ATL::IObjectSafetyImpl::GetInterfaceSafetyOptions
- ATLCTL/ATL::IObjectSafetyImpl::SetInterfaceSafetyOptions
- ATLCTL/ATL::IObjectSafetyImpl::m_dwCurrentSafety
helpviewer_keywords:
- controls [ATL], safe
- safe for scripting and initialization (controls)
- IObjectSafety, ATL implementation
- IObjectSafetyImpl class
ms.assetid: 64e32082-d910-4a8a-a5bf-ebed9145359d
ms.openlocfilehash: e9035a8573a917e732f3452aeb7fd07af160517f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50471780"
---
# <a name="iobjectsafetyimpl-class"></a>Classe IObjectSafetyImpl

Essa classe fornece uma implementação padrão da `IObjectSafety` interface para permitir que um cliente recuperar e definir níveis de segurança de um objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T,DWORD dwSupportedSafety>
class IObjectSafetyImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IObjectSafetyImpl`.

*dwSupportedSafety*<br/>
Especifica as opções de segurança com suporte para o controle. pode ser um dos seguintes valores:

- INTERFACESAFE_FOR_UNTRUSTED_CALLER a interface identificada pelo [SetInterfaceSafetyOptions](#setinterfacesafetyoptions) parâmetro `riid` deve ser feita seguros para script.

- INTERFACESAFE_FOR_UNTRUSTED_DATA a interface identificada pelo `SetInterfaceSafetyOptions` parâmetro `riid` deve ser feita seguro para dados não confiáveis durante a inicialização.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IObjectSafetyImpl::GetInterfaceSafetyOptions](#getinterfacesafetyoptions)|Recupera as opções de segurança com suporte pelo objeto, bem como as opções de segurança definidas no momento para o objeto.|
|[IObjectSafetyImpl::SetInterfaceSafetyOptions](#setinterfacesafetyoptions)|Torna o objeto seguro para inicialização ou de script.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IObjectSafetyImpl::m_dwCurrentSafety](#m_dwcurrentsafety)|Armazena o nível de segurança atual do objeto.|

## <a name="remarks"></a>Comentários

Classe `IObjectSafetyImpl` fornece uma implementação padrão de `IObjectSafety`. O `IObjectSafety` interface permite que um cliente recuperar e definir níveis de segurança de um objeto. Por exemplo, um navegador da web pode chamar `IObjectSafety::SetInterfaceSafetyOptions` para fazer um controle seguro para inicialização ou de seguros para script.

Observe que o uso de [IMPLEMENTED_CATEGORY](category-macros.md#implemented_category) macro com as categorias de componente CATID_SafeForScripting e CATID_SafeForInitializing fornece uma maneira alternativa de especificar que um componente é seguro.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IObjectSafety`

`IObjectSafetyImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="getinterfacesafetyoptions"></a>  IObjectSafetyImpl::GetInterfaceSafetyOptions

Recupera as opções de segurança com suporte pelo objeto, bem como as opções de segurança definidas no momento para o objeto.

```
HRESULT GetInterfaceSafetyOptions(
    REFIID riid,
    DWORD* pdwSupportedOptions,
    DWORD* pdwEnabledOptions);
```

### <a name="remarks"></a>Comentários

A implementação retorna os valores apropriados para qualquer interface compatível com a implementação do objeto de `IUnknown::QueryInterface`.

> [!IMPORTANT]
>  Qualquer objeto que dá suporte a `IObjectSafety` é responsável por sua própria segurança e de qualquer objeto que ela delega. O programador deve levar em conta surgirem devido a executem o código no contexto do usuário, scripts entre sites e executar a verificação de zona adequada.

Ver [IObjectSafety::GetInterfaceSafetyOptions](https://msdn.microsoft.com/library/aa768223.aspx) no Windows SDK.

##  <a name="m_dwcurrentsafety"></a>  IObjectSafetyImpl::m_dwCurrentSafety

Armazena o nível de segurança atual do objeto.

```
DWORD m_dwCurrentSafety;
```

##  <a name="setinterfacesafetyoptions"></a>  IObjectSafetyImpl::SetInterfaceSafetyOptions

Torna o objeto seguro para inicialização ou de script definindo a [m_dwCurrentSafety](#m_dwcurrentsafety) membro para o valor apropriado.

```
HRESULT SetInterfaceSafetyOptions(
    REFIID riid,
    DWORD dwOptionsSetMask,
    DWORD dwEnabledOptions);
```

### <a name="remarks"></a>Comentários

A implementação retorna E_NOINTERFACE para qualquer interface que não tem suportada pela implementação do objeto do `IUnknown::QueryInterface`.

> [!IMPORTANT]
>  Qualquer objeto que dá suporte a `IObjectSafety` é responsável por sua própria segurança e de qualquer objeto que ela delega. O programador deve levar em conta surgirem devido a executem o código no contexto do usuário, scripts entre sites e executar a verificação de zona adequada.

Ver [IObjectSafety::SetInterfaceSafetyOptions](https://msdn.microsoft.com/library/aa768225.aspx) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Interface IObjectSafety](https://msdn.microsoft.com/library/aa768224.aspx)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
