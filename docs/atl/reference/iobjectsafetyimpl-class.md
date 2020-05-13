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
ms.openlocfilehash: 6eee7585bc3c5587e106ab6b0cefb4b7129df59f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329659"
---
# <a name="iobjectsafetyimpl-class"></a>Classe IObjectSafetyImpl

Essa classe fornece uma `IObjectSafety` implementação padrão da interface para permitir que um cliente recupere e defina os níveis de segurança de um objeto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T,DWORD dwSupportedSafety>
class IObjectSafetyImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IObjectSafetyImpl`.

*dwSupportedSafety*<br/>
Especifica as opções de segurança suportadas para o controle. Pode ser um dos seguintes valores:

- INTERFACESAFE_FOR_UNTRUSTED_CALLER A interface identificada pelo parâmetro `riid` [SetInterfaceSafetyOptions](#setinterfacesafetyoptions) deve ser segura para scripts.

- INTERFACESAFE_FOR_UNTRUSTED_DATA A interface `SetInterfaceSafetyOptions` identificada `riid` pelo parâmetro deve ser segura para dados não confiáveis durante a inicialização.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IObjectSafetyImpl::GetInterfaceSafetyOptions](#getinterfacesafetyoptions)|Recupera as opções de segurança suportadas pelo objeto, bem como as opções de segurança atualmente definidas para o objeto.|
|[IObjectSafetyImpl::SetInterfaceSafetyOptions](#setinterfacesafetyoptions)|Torna o objeto seguro para inicialização ou scripting.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IObjectSafetyImpl::m_dwCurrentSafety](#m_dwcurrentsafety)|Armazena o nível de segurança atual do objeto.|

## <a name="remarks"></a>Comentários

A `IObjectSafetyImpl` classe fornece `IObjectSafety`uma implementação padrão de . A `IObjectSafety` interface permite que um cliente recupere e defina os níveis de segurança de um objeto. Por exemplo, um navegador `IObjectSafety::SetInterfaceSafetyOptions` da Web pode ligar para tornar um controle seguro para inicialização ou seguro para scripts.

Observe que o uso da [IMPLEMENTED_CATEGORY](category-macros.md#implemented_category) macro com as categorias de componentes CATID_SafeForScripting e CATID_SafeForInitializing fornece uma maneira alternativa de especificar que um componente é seguro.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IObjectSafety`

`IObjectSafetyImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="iobjectsafetyimplgetinterfacesafetyoptions"></a><a name="getinterfacesafetyoptions"></a>IObjectSafetyImpl::GetInterfaceSafetyOptions

Recupera as opções de segurança suportadas pelo objeto, bem como as opções de segurança atualmente definidas para o objeto.

```
HRESULT GetInterfaceSafetyOptions(
    REFIID riid,
    DWORD* pdwSupportedOptions,
    DWORD* pdwEnabledOptions);
```

### <a name="remarks"></a>Comentários

A implementação retorna os valores apropriados para qualquer `IUnknown::QueryInterface`interface suportada pela implementação do objeto.

> [!IMPORTANT]
> Qualquer objeto que `IObjectSafety` suporte é responsável por sua própria segurança, e de qualquer objeto que delegue. O programador deve levar em conta os problemas decorrentes da execução de código no contexto do usuário, o scripting entre sites e realizar a verificação de zona adequada.

Consulte [IObjectSafety::GetInterfaceSafetyOptions](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768223\(v=vs.85\)) no Windows SDK.

## <a name="iobjectsafetyimplm_dwcurrentsafety"></a><a name="m_dwcurrentsafety"></a>IObjectSafetyImpl::m_dwCurrentSafety

Armazena o nível de segurança atual do objeto.

```
DWORD m_dwCurrentSafety;
```

## <a name="iobjectsafetyimplsetinterfacesafetyoptions"></a><a name="setinterfacesafetyoptions"></a>IObjectSafetyImpl::SetInterfaceSafetyOptions

Torna o objeto seguro para inicialização ou scripting definindo o [membro m_dwCurrentSafety](#m_dwcurrentsafety) para o valor apropriado.

```
HRESULT SetInterfaceSafetyOptions(
    REFIID riid,
    DWORD dwOptionsSetMask,
    DWORD dwEnabledOptions);
```

### <a name="remarks"></a>Comentários

O retorno da implementação E_NOINTERFACE para qualquer interface `IUnknown::QueryInterface`não suportada pela implementação do objeto.

> [!IMPORTANT]
> Qualquer objeto que `IObjectSafety` suporte é responsável por sua própria segurança, e de qualquer objeto que delegue. O programador deve levar em conta os problemas decorrentes da execução de código no contexto do usuário, o scripting entre sites e realizar a verificação de zona adequada.

Consulte [IObjectSafety::SetInterfaceSafetyOptions](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768225\(v=vs.85\)) no Windows SDK.

## <a name="see-also"></a>Confira também

[IObjectSafety Interface](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768224\(v=vs.85\))<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
