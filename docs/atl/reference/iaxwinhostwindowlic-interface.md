---
title: Interface IAxWinHostWindowLic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IAxWinHostWindowLic
- ATLIFACE/ATL::IAxWinHostWindowLic
- ATLIFACE/ATL::CreateControlLic
- ATLIFACE/ATL::CreateControlLicEx
dev_langs:
- C++
helpviewer_keywords:
- IAxWinHostWindowLic interface
ms.assetid: 750f1520-6bce-428c-aca0-fccbe3f063c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8c6b2537f4a4c7ba92a87bfeff2765c3c5e1b274
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088703"
---
# <a name="iaxwinhostwindowlic-interface"></a>Interface IAxWinHostWindowLic

Essa interface fornece métodos para manipular um controle licenciado e seu objeto de host.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinHostWindowLic : IAxWinHostWindow
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CreateControlLic](#createcontrollic)|Cria um controle licenciado e a anexa ao objeto de host.|
|[CreateControlLicEx](#createcontrollicex)|Cria um controle licenciado, anexa-o ao objeto de host e, opcionalmente, define um manipulador de eventos.|

## <a name="remarks"></a>Comentários

`IAxWinHostWindowLic` herda de [IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md) e adiciona métodos que oferecem suporte a criação de controles licenciados.

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa os membros desta interface.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|IDL|ATLIFace.idl|
|C++|Atliface (também é incluído em atlbase. H)|

##  <a name="createcontrollic"></a>  IAxWinHostWindowLic::CreateControlLic

Cria um controle licenciado, inicializa-o e hospeda-o na janela identificada pelo `hWnd`.

```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```

### <a name="parameters"></a>Parâmetros

*bstrLic*<br/>
[in] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Ver [IAxWinHostWindow::CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol) para obter uma descrição do valor de retorno e parâmetros restantes.

Chamar esse método é equivalente a chamar [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex)

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLic`.

##  <a name="createcontrollicex"></a>  IAxWinHostWindowLic::CreateControlLicEx

Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante à [IAxWinHostWindow::CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol).

```
STDMETHOD(CreateControlLicEx)(
    LPCOLESTR lpszTricsData,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnk,
    REFIID riidAdvise,
    IUnknown* punkAdvise,
    BSTR bstrLic);
```

### <a name="parameters"></a>Parâmetros

*bstrLic*<br/>
[in] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Ver [IAxWinHostWindow::CreateControlEx](../../atl/reference/iaxwinhostwindow-interface.md#createcontrolex) para obter uma descrição do valor de retorno e parâmetros restantes.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLicEx`.

