---
title: Classe IQuickActivateImpl
ms.date: 11/04/2016
f1_keywords:
- IQuickActivateImpl
- ATLCTL/ATL::IQuickActivateImpl
- ATLCTL/ATL::IQuickActivateImpl::GetContentExtent
- ATLCTL/ATL::IQuickActivateImpl::QuickActivate
- ATLCTL/ATL::IQuickActivateImpl::SetContentExtent
helpviewer_keywords:
- activating ATL controls
- controls [ATL], activating
- IQuickActivateImpl class
- IQuickActivate ATL implementation
ms.assetid: aa80c056-1041-494e-b21d-2acca7dc27ea
ms.openlocfilehash: 7e1984249caf66e2986341f9c9f7a939d7039125
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329547"
---
# <a name="iquickactivateimpl-class"></a>Classe IQuickActivateImpl

Esta classe combina a inicialização de controle dos contêineres em uma única chamada.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE IQuickActivateImpl : public IQuickActivate
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IQuickActivateImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IQuickActivateImpl::GetContentExtent](#getcontentextent)|Recupera o tamanho atual do display para um controle em execução.|
|[IQuickActivateImpl::QuickActivate](#quickactivate)|Realiza uma inicialização rápida dos controles que estão sendo carregados.|
|[IQuickActivateImpl::SetContentExtent](#setcontentextent)|Informa o controle de quanto espaço de exibição o recipiente atribuiu a ele.|

## <a name="remarks"></a>Comentários

A interface [IQuickActivate](/windows/win32/api/ocidl/nn-ocidl-iquickactivate) ajuda os contêineres a evitar atrasos ao carregar controles combinando inicialização em uma única chamada. O `QuickActivate` método permite que o contêiner passe um ponteiro para uma estrutura [QACONTAINER](/windows/win32/api/ocidl/ns-ocidl-qacontainer) que mantém ponteiros para todas as interfaces que o controle precisa. No retorno, o controle repassa um ponteiro para uma estrutura [QACONTROL](/windows/win32/api/ocidl/ns-ocidl-qacontrol) que mantém ponteiros para suas próprias interfaces, que são usadas pelo contêiner. A `IQuickActivateImpl` classe fornece `IQuickActivate` uma implementação padrão e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IQuickActivate`

`IQuickActivateImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="iquickactivateimplgetcontentextent"></a><a name="getcontentextent"></a>IQuickActivateImpl::GetContentExtent

Recupera o tamanho atual do display para um controle em execução.

```
STDMETHOD(GetContentExtent)(LPSIZEL pSize);
```

### <a name="remarks"></a>Comentários

O tamanho é para uma renderização completa do controle e é especificado em unidades HIMETRIC.

Consulte [IQuickActivate::GetContentExtent](/windows/win32/api/ocidl/nf-ocidl-iquickactivate-getcontentextent) no Windows SDK.

## <a name="iquickactivateimplquickactivate"></a><a name="quickactivate"></a>IQuickActivateImpl::QuickActivate

Realiza uma inicialização rápida dos controles que estão sendo carregados.

```
STDMETHOD(QuickActivate)(
    QACONTAINER* pQACont,
    QACONTROL* pQACtrl);
```

### <a name="remarks"></a>Comentários

A estrutura contém ponteiros para interfaces necessárias pelo controle e os valores de algumas propriedades ambientais. Após o retorno, o controle passa um ponteiro para uma estrutura [QACONTROL](/windows/win32/api/ocidl/ns-ocidl-qacontrol) que contém ponteiros para suas próprias interfaces que o contêiner requer e informações adicionais de status.

Veja [IQuickActivate::QuickActivate](/windows/win32/api/ocidl/nf-ocidl-iquickactivate-quickactivate) no SDK do Windows.

## <a name="iquickactivateimplsetcontentextent"></a><a name="setcontentextent"></a>IQuickActivateImpl::SetContentExtent

Informa o controle de quanto espaço de exibição o recipiente atribuiu a ele.

```
STDMETHOD(SetContentExtent)(LPSIZEL pSize);
```

### <a name="remarks"></a>Comentários

O tamanho é especificado em unidades HIMETRIC.

Consulte [IQuickActivate::SetContentExtent](/windows/win32/api/ocidl/nf-ocidl-iquickactivate-setcontentextent) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
