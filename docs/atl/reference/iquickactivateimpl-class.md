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
ms.openlocfilehash: 2169686ebbf756c5caf9232f5031532c62ac8265
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495516"
---
# <a name="iquickactivateimpl-class"></a>Classe IQuickActivateImpl

Essa classe combina a inicialização do controle de contêineres em uma única chamada.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE IQuickActivateImpl : public IQuickActivate
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IQuickActivateImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IQuickActivateImpl::GetContentExtent](#getcontentextent)|Recupera o tamanho de exibição atual de um controle em execução.|
|[IQuickActivateImpl::QuickActivate](#quickactivate)|Executa inicialização rápida de controles sendo carregados.|
|[IQuickActivateImpl::SetContentExtent](#setcontentextent)|Informa o controle de quanto espaço de exibição o contêiner atribuiu a ele.|

## <a name="remarks"></a>Comentários

A interface [IQuickActivate](/windows/win32/api/ocidl/nn-ocidl-iquickactivate) ajuda os contêineres a evitar atrasos ao carregar controles combinando a inicialização em uma única chamada. O `QuickActivate` método permite que o contêiner passe um ponteiro para uma estrutura [QACONTAINER](/windows/win32/api/ocidl/ns-ocidl-qacontainer) que contém ponteiros para todas as interfaces das quais o controle precisa. No retorno, o controle passa de volta um ponteiro para uma estrutura [QACONTROL](/windows/win32/api/ocidl/ns-ocidl-qacontrol) que mantém ponteiros para suas próprias interfaces, que são usadas pelo contêiner. Fornece uma implementação padrão de `IQuickActivate` e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IQuickActivateImpl`

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IQuickActivate`

`IQuickActivateImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="getcontentextent"></a>  IQuickActivateImpl::GetContentExtent

Recupera o tamanho de exibição atual de um controle em execução.

```
STDMETHOD(GetContentExtent)(LPSIZEL pSize);
```

### <a name="remarks"></a>Comentários

O tamanho é para uma renderização completa do controle e é especificado em unidades HIMETRIC.

Consulte [IQuickActivate:: GetContentExtent](/windows/win32/api/ocidl/nf-ocidl-iquickactivate-getcontentextent) na SDK do Windows.

##  <a name="quickactivate"></a>  IQuickActivateImpl::QuickActivate

Executa inicialização rápida de controles sendo carregados.

```
STDMETHOD(QuickActivate)(
    QACONTAINER* pQACont,
    QACONTROL* pQACtrl);
```

### <a name="remarks"></a>Comentários

A estrutura contém ponteiros para interfaces necessárias para o controle e os valores de algumas propriedades de ambiente. No retorno, o controle passa um ponteiro para uma estrutura [QACONTROL](/windows/win32/api/ocidl/ns-ocidl-qacontrol) que contém ponteiros para suas próprias interfaces que o contêiner requer e informações de status adicionais.

Consulte [IQuickActivate:: QuickActivate](/windows/win32/api/ocidl/nf-ocidl-iquickactivate-quickactivate) na SDK do Windows.

##  <a name="setcontentextent"></a>  IQuickActivateImpl::SetContentExtent

Informa o controle de quanto espaço de exibição o contêiner atribuiu a ele.

```
STDMETHOD(SetContentExtent)(LPSIZEL pSize);
```

### <a name="remarks"></a>Comentários

O tamanho é especificado em unidades HIMETRIC.

Consulte [IQuickActivate:: SetContentExtent](/windows/win32/api/ocidl/nf-ocidl-iquickactivate-setcontentextent) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
