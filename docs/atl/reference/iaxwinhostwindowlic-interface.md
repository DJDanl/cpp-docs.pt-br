---
title: IAxWinHostWindowLic Interface
ms.date: 11/04/2016
f1_keywords:
- IAxWinHostWindowLic
- ATLIFACE/ATL::IAxWinHostWindowLic
- ATLIFACE/ATL::CreateControlLic
- ATLIFACE/ATL::CreateControlLicEx
helpviewer_keywords:
- IAxWinHostWindowLic interface
ms.assetid: 750f1520-6bce-428c-aca0-fccbe3f063c7
ms.openlocfilehash: 561a65702f1d4f57b4db1afc75769ce4cc523c1c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329917"
---
# <a name="iaxwinhostwindowlic-interface"></a>IAxWinHostWindowLic Interface

Esta interface fornece métodos para manipular um controle licenciado e seu objeto host.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinHostWindowLic : IAxWinHostWindow
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CreateControlLic](#createcontrollic)|Cria um controle licenciado e o anexa ao objeto host.|
|[CreateControlLicEx](#createcontrollicex)|Cria um controle licenciado, anexa-o ao objeto host e, opcionalmente, configura um manipulador de eventos.|

## <a name="remarks"></a>Comentários

`IAxWinHostWindowLic`herda do [IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md) e adiciona métodos que suportam a criação de controles licenciados.

Consulte [Hosting ActiveX Controls Usando atl AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que use os membros desta interface.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível como IDL ou C++, como mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|Idl|ATLIFace.idl|
|C++|ATLIFace.h (também incluído no ATLBase.h)|

## <a name="iaxwinhostwindowliccreatecontrollic"></a><a name="createcontrollic"></a>IAxWinHostWindowlic::CreateControlLic

Cria um controle licenciado, inicializa-o e hospeda-o na janela identificada por `hWnd`.

```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```

### <a name="parameters"></a>Parâmetros

*bstrlic*<br/>
[em] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow::CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol) para obter uma descrição dos parâmetros restantes e do valor de retorno.

Chamar esse método é equivalente a chamar [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex)

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `IAxWinHostWindowLic::CreateControlLic`.

## <a name="iaxwinhostwindowliccreatecontrollicex"></a><a name="createcontrollicex"></a>IAxWinHostWindowliclic::CreateControlLicEx

Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol).

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

*bstrlic*<br/>
[em] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow::CreateControlEx](../../atl/reference/iaxwinhostwindow-interface.md#createcontrolex) para obter uma descrição dos parâmetros restantes e do valor de retorno.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `IAxWinHostWindowLic::CreateControlLicEx`.
