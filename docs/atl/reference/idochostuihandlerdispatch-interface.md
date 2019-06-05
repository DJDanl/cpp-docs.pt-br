---
title: Interface IDocHostUIHandlerDispatch
ms.date: 11/04/2016
f1_keywords:
- IDocHostUIHandlerDispatch
- atlbase/ATL::IDocHostUIHandlerDispatch
helpviewer_keywords:
- IDocHostUIHandlerDispatch interface
ms.assetid: 6963a301-601a-4ac3-8bef-f7b252ea2fc6
ms.openlocfilehash: f4f5024e282885797858c800640bc5651819ca20
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66503065"
---
# <a name="idochostuihandlerdispatch-interface"></a>Interface IDocHostUIHandlerDispatch

Uma interface para a análise de HTML da Microsoft e o mecanismo de renderização.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
interface IDocHostUIHandlerDispatch : IDispatch
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

> [!NOTE]
>  Os links na tabela a seguir são para os tópicos de referência de SDK INet para os membros do [IDocUIHostHandler](/windows/internet-explorer/ie-developer/platform-apis/aa753260\(v=vs.85\)) interface. `IDocHostUIHandlerDispatch` tem a mesma funcionalidade que `IDocUIHostHandler`, com a diferença sendo que `IDocHostUIHandlerDispatch` é um dispinterface enquanto `IDocUIHostHandler` é uma interface personalizada.

|||
|-|-|
|[EnableModeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\))|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::EnableModeless](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-enablemodeless). Também é chamado quando o MSHTML exibe a interface do usuário modal.|
|[FilterDataObject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\))|Chamado no host pelo MSHTML para permitir que o host substituir o objeto de dados do MSHTML.|
|[GetDropTarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\))|Chamado pelo MSHTML quando ele está sendo usado como um destino de soltar para permitir que o host fornecer uma alternativa [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget).|
|[GetExternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\))|Chamado pelo MSHTML para obter a interface IDispatch do host.|
|[GetHostInfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\))|Recupera os recursos de interface do usuário do host MSHTML.|
|[GetOptionKeyPath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\))|Retorna a chave do registro sob a qual MSHTML armazena as preferências do usuário.|
|[HideUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753259\(v=vs.85\))|Chamado quando MSHTML remove seus menus e barras de ferramentas.|
|[OnDocWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\))|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::OnDocWindowActivate](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-ondocwindowactivate).|
|[OnFrameWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\))|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::OnFrameWindowActivate](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-onframewindowactivate).|
|[ResizeBorder](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753263\(v=vs.85\))|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::ResizeBorder](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-resizeborder).|
|[ShowContextMenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\))|Chamado de MSHTML para exibir um menu de contexto.|
|[ShowUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\))|Permite que o host substituir as barras de ferramentas e menus MSHTML.|
|[TranslateAccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\))|Chamado pelo MSHTML quando [IOleInPlaceActiveObject::TranslateAccelerator](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-translateaccelerator) ou [IOleControlSite::TranslateAccelerator](/windows/desktop/api/ocidl/nf-ocidl-iolecontrolsite-translateaccelerator) é chamado.|
|[TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\))|Chamado pelo MSHTML para permitir que o host a oportunidade de modificar a URL a ser carregado.|
|[UpdateUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753268\(v=vs.85\))|Notifica o host que o estado do comando foi alterado.|

## <a name="remarks"></a>Comentários

Um host pode substituir os menus, barras de ferramentas e menus de contexto usados pela análise de HTML da Microsoft e o mecanismo de renderização (MSHTML) implementando essa interface.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|IDL|ATLIFace.idl|
|C++|Atliface (também é incluído em atlbase. H)|

## <a name="see-also"></a>Consulte também

[IDocUIHostHandler](/windows/internet-explorer/ie-developer/platform-apis/aa753260\(v=vs.85\))
