---
title: Interface IAxWinHostWindowLic
ms.date: 11/04/2016
f1_keywords:
- IAxWinHostWindowLic
- ATLIFACE/ATL::IAxWinHostWindowLic
- ATLIFACE/ATL::CreateControlLic
- ATLIFACE/ATL::CreateControlLicEx
helpviewer_keywords:
- IAxWinHostWindowLic interface
ms.assetid: 750f1520-6bce-428c-aca0-fccbe3f063c7
ms.openlocfilehash: aca3970d13db53ffa04fe9582bbe9b8db78e820d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62275984"
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
