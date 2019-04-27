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
ms.openlocfilehash: 2a2b11746249b6ee4f6ddd578717aacc374d53bc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62198135"
---
# <a name="iquickactivateimpl-class"></a>Classe IQuickActivateImpl

Essa classe combina a inicialização dos contêineres de controle em uma única chamada.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[IQuickActivateImpl::GetContentExtent](#getcontentextent)|Recupera o tamanho de exibição atual para um controle em execução.|
|[IQuickActivateImpl::QuickActivate](#quickactivate)|Executa a inicialização rápida de controles que está sendo carregado.|
|[IQuickActivateImpl::SetContentExtent](#setcontentextent)|Informa o controle de quanto espaço de exibição, o contêiner foi atribuído a ele.|

## <a name="remarks"></a>Comentários

O [IQuickActivate](/windows/desktop/api/ocidl/nn-ocidl-iquickactivate) interface o ajuda a contêineres evitar atrasos ao carregar controles pela combinação de inicialização em uma única chamada. O `QuickActivate` método permite que o contêiner passar um ponteiro para uma [QACONTAINER](/windows/desktop/api/ocidl/ns-ocidl-tagqacontainer) precisa de estrutura que contém ponteiros para todas as interfaces de controle. No retorno, o controle passa de volta de um ponteiro para um [QACONTROL](/windows/desktop/api/ocidl/ns-ocidl-tagqacontrol) estrutura que contém ponteiros para suas próprias interfaces, que são usadas pelo contêiner. Classe `IQuickActivateImpl` fornece uma implementação padrão de `IQuickActivate` e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IQuickActivate`

`IQuickActivateImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="getcontentextent"></a>  IQuickActivateImpl::GetContentExtent

Recupera o tamanho de exibição atual para um controle em execução.

```
STDMETHOD(GetContentExtent)(LPSIZEL pSize);
```

### <a name="remarks"></a>Comentários

O tamanho é para um processamento completo do controle e é especificado em unidades HIMETRIC.

Ver [IQuickActivate::GetContentExtent](/windows/desktop/api/ocidl/nf-ocidl-iquickactivate-getcontentextent) no Windows SDK.

##  <a name="quickactivate"></a>  IQuickActivateImpl::QuickActivate

Executa a inicialização rápida de controles que está sendo carregado.

```
STDMETHOD(QuickActivate)(
    QACONTAINER* pQACont,
    QACONTROL* pQACtrl);
```

### <a name="remarks"></a>Comentários

A estrutura contém ponteiros para as interfaces necessárias para o controle e os valores de algumas propriedades de ambiente. Após o retorno, o controle passa um ponteiro para um [QACONTROL](/windows/desktop/api/ocidl/ns-ocidl-tagqacontrol) estrutura que contém ponteiros para suas próprias interfaces que requer que o contêiner e informações de status adicionais.

Ver [IQuickActivate::QuickActivate](/windows/desktop/api/ocidl/nf-ocidl-iquickactivate-quickactivate) no Windows SDK.

##  <a name="setcontentextent"></a>  IQuickActivateImpl::SetContentExtent

Informa o controle de quanto espaço de exibição, o contêiner foi atribuído a ele.

```
STDMETHOD(SetContentExtent)(LPSIZEL pSize);
```

### <a name="remarks"></a>Comentários

O tamanho é especificado em unidades HIMETRIC.

Ver [IQuickActivate::SetContentExtent](/windows/desktop/api/ocidl/nf-ocidl-iquickactivate-setcontentextent) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
