---
title: IDocHostUIHandlerDispatch Interface
ms.date: 07/02/2019
f1_keywords:
- IDocHostUIHandlerDispatch
- atlbase/ATL::IDocHostUIHandlerDispatch
helpviewer_keywords:
- IDocHostUIHandlerDispatch interface
ms.assetid: 6963a301-601a-4ac3-8bef-f7b252ea2fc6
ms.openlocfilehash: b7072b80b738aa12635427a2604b38fb3585b452
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329719"
---
# <a name="idochostuihandlerdispatch-interface"></a>IDocHostUIHandlerDispatch Interface

Uma interface para o mecanismo de análise e renderização do Microsoft HTML.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
interface IDocHostUIHandlerDispatch : IDispatch
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

> [!NOTE]
> Os links na tabela a seguir são para os tópicos de referência do INet SDK para os membros da interface [IDocUIHostHandler.](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753260\(v=vs.85\)) `IDocHostUIHandlerDispatch`tem a mesma `IDocUIHostHandler`funcionalidade que, com `IDocHostUIHandlerDispatch` a diferença sendo `IDocUIHostHandler` que é uma dispinterface enquanto que é uma interface personalizada.

|||
|-|-|
|[Enablemodeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\))|Chamado da implementação MSHTML do [IOleInPlaceActiveObject::EnableModeless](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-enablemodeless). Também chamado quando o MSHTML exibe ui modal.|
|[Filterdataobject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\))|Chamado ao host pelo MSHTML para permitir que o host substitua o objeto de dados do MSHTML.|
|[Getdroptarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\))|Chamado por MSHTML quando está sendo usado como um alvo de queda para permitir que o host forneça um [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget)alternativo .|
|[GetExternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\))|Chamado por MSHTML para obter a interface IDispatch do host.|
|[Gethostinfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\))|Recupera os recursos de IA do host MSHTML.|
|[Getoptionkeypath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\))|Retorna a chave de registro sob a qual o MSHTML armazena as preferências do usuário.|
|[HideUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753259\(v=vs.85\))|Chamado quando o MSHTML remove seus menus e barras de ferramentas.|
|[Ondocwindowactivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\))|Chamado da implementação MSHTML do [IOleInPlaceActiveObject::OnDocWindowActivate](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-ondocwindowactivate).|
|[Onframewindowactivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\))|Chamado da implementação MSHTML do [IOleInPlaceActiveObject::OnFrameWindowActivate](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-onframewindowactivate).|
|[Resizeborder](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753263\(v=vs.85\))|Chamado da implementação MSHTML do [IOleInPlaceActiveObject::RedimensionBorder](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-resizeborder).|
|[ShowContextMenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\))|Chamado do MSHTML para exibir um menu de contexto.|
|[Showui](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\))|Permite que o host substitua menus MSHTML e barras de ferramentas.|
|[Translateaccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\))|Chamado por MSHTML quando [IOleInPlaceActiveObject::TranslateAccelerator](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-translateaccelerator) ou [IOleControlSite::TranslateAccelerator](/windows/win32/api/ocidl/nf-ocidl-iolecontrolsite-translateaccelerator) é chamado.|
|[TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\))|Chamado pelo MSHTML para permitir ao host uma oportunidade de modificar a URL a ser carregada.|
|[Updateui](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753268\(v=vs.85\))|Notifica o anfitrião de que o estado de comando mudou.|

## <a name="remarks"></a>Comentários

Um host pode substituir os menus, barras de ferramentas e menus de contexto usados pelo mecanismo de renderização e análise do Microsoft HTML (MSHTML) implementando esta interface.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível como IDL ou C++, como mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|Idl|ATLIFace.idl|
|C++|ATLIFace.h (também incluído no ATLBase.h)|

## <a name="see-also"></a>Confira também

[IDocUIHostHandler](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753260\(v=vs.85\))
