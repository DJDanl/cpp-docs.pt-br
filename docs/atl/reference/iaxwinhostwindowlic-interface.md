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
ms.openlocfilehash: d7a63fc63b8abcf8574ea9a2fed2556635dba045
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91352941"
---
# <a name="iaxwinhostwindowlic-interface"></a>Interface IAxWinHostWindowLic

Essa interface fornece métodos para manipular um controle licenciado e seu objeto de host.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinHostWindowLic : IAxWinHostWindow
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Nome|Descrição|
|-|-|
|[CreateControlLic](#createcontrollic)|Cria um controle licenciado e o anexa ao objeto de host.|
|[CreateControlLicEx](#createcontrollicex)|Cria um controle licenciado, anexa-o ao objeto de host e, opcionalmente, configura um manipulador de eventos.|

## <a name="remarks"></a>Comentários

`IAxWinHostWindowLic` herda de [IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md) e adiciona métodos que dão suporte à criação de controles licenciados.

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/atl-control-containment-faq.md#hosting-activex-controls-using-atl-axhost) para obter um exemplo que usa os membros desta interface.

## <a name="requirements"></a>Requisitos

A definição dessa interface está disponível como IDL ou C++, conforme mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|INSERI|ATLIFace. idl|
|C++|ATLIFace. h (também incluído em ATLBase. h)|

## <a name="iaxwinhostwindowliccreatecontrollic"></a><a name="createcontrollic"></a> IAxWinHostWindowLic::CreateControlLic

Cria um controle licenciado, inicializa-o e o hospeda na janela identificada por `hWnd` .

```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```

### <a name="parameters"></a>Parâmetros

*bstrLic*<br/>
no O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow:: CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol) para obter uma descrição dos parâmetros e do valor de retorno restantes.

Chamar esse método é equivalente a chamar [IAxWinHostWindowLic:: CreateControlLicEx](#createcontrollicex)

### <a name="example"></a>Exemplo

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/atl-control-containment-faq.md#hosting-activex-controls-using-atl-axhost) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLic` .

## <a name="iaxwinhostwindowliccreatecontrollicex"></a><a name="createcontrollicex"></a> IAxWinHostWindowLic::CreateControlLicEx

Cria um controle ActiveX licenciado, inicializa-o e o hospeda na janela especificada, semelhante a [IAxWinHostWindow:: CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol).

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
no O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow:: CreateControlEx](../../atl/reference/iaxwinhostwindow-interface.md#createcontrolex) para obter uma descrição dos parâmetros e do valor de retorno restantes.

### <a name="example"></a>Exemplo

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/atl-control-containment-faq.md#hosting-activex-controls-using-atl-axhost) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLicEx` .
