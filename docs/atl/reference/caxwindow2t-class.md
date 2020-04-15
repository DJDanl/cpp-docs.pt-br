---
title: Classe CAxWindow2T
ms.date: 11/04/2016
f1_keywords:
- CAxWindow2T
- ATLWIN/ATL::CAxWindow2T
- ATLWIN/ATL::CAxWindow2T::CAxWindow2T
- ATLWIN/ATL::CAxWindow2T::Create
- ATLWIN/ATL::CAxWindow2T::CreateControlLic
- ATLWIN/ATL::CAxWindow2T::CreateControlLicEx
- ATLWIN/ATL::CAxWindow2T::GetWndClassName
helpviewer_keywords:
- CAxWindow2 class
ms.assetid: b87bc943-7991-4537-b902-2138d7f4d837
ms.openlocfilehash: 14080b624132979df533135bc1eef108dc793398
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318692"
---
# <a name="caxwindow2t-class"></a>Classe CAxWindow2T

Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedar controles ActiveX licenciados.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class TBase = CWindow>
    class CAxWindow2T :
    public CAxWindowT<TBase>
```

#### <a name="parameters"></a>Parâmetros

*Tbase*<br/>
A classe `CAxWindowT` da qual deriva.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxWindow2T::CAxWindow2T](#caxwindow2t)|Constrói um objeto `CAxWindow2T`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxWindow2T::Criar](#create)|Cria uma janela de host.|
|[CAxWindow2T::CreateControlLic](#createcontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|
|[CAxWindow2T::CreateControlLicEx](#createcontrollicex)|Cria um controle ActiveX licenciado, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[CAxWindow2T::GetWndClassName](#getwndclassname)|Método estático que recupera o nome da classe da janela.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxWindow2T::operador =](#operator_eq)|Atribui um HWND a `CAxWindow2T` um objeto existente.|

## <a name="remarks"></a>Comentários

`CAxWindow2T`fornece métodos para manipular uma janela que hospeda um controle ActiveX. `CAxWindow2T`também tem suporte para hospedagem de controles ActiveX licenciados. A hospedagem é fornecida por " **AtlAxWinLic80**", que é embrulhado por `CAxWindow2T`.

A `CAxWindow2` classe é implementada como `CAxWindow2T` uma especialização da classe. Esta especialização é declarada como:

`typedef CAxWindow2T <CWindow> CAxWindow2;`

> [!NOTE]
> `CAxWindowT`os membros são documentados em [CAxWindow](../../atl/reference/caxwindow-class.md).

Consulte [Hosting ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que use os membros desta classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`CAxWindowT`

`CAxWindow2T`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="caxwindow2tcaxwindow2t"></a><a name="caxwindow2t"></a>CAxWindow2T::CAxWindow2T

Constrói um objeto `CAxWindow2T`.

```
CAxWindow2T(HWND  hWnd = NULL) : CAxWindowT<TBase>(hWnd)
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Uma alça de uma janela existente.

## <a name="caxwindow2tcreate"></a><a name="create"></a>CAxWindow2T::Criar

Cria uma janela de host.

```
HWND Create(
    HWND hWndParent,
    _U_RECT rect = NULL,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);
```

### <a name="remarks"></a>Comentários

`CAxWindow2T::Create`chama [CWindow::Criar](../../atl/reference/cwindow-class.md#create) com o parâmetro LPCTSTR *lpstrWndClass* definido para`AtlAxWinLic80`a classe de janela que fornece a hospedagem de controle ().

Consulte `CWindow::Create` a descrição dos parâmetros e do valor de retorno.

**Nota** Se 0 for usado como o valor para o parâmetro *MenuOrID,* ele deve ser especificado como 0U (o valor padrão) para evitar um erro do compilador.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `CAxWindow2T::Create`.

## <a name="caxwindow2tcreatecontrollic"></a><a name="createcontrollic"></a>CAxWindow2T::CreateControlLic

Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.

```
HRESULT CreateControlLic(
    DWORD dwResID,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    BSTR bstrLicKey = NULL);

HRESULT CreateControlLic(
    LPCOLESTR lpszName,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    BSTR bstrLicKey = NULL);
```

### <a name="parameters"></a>Parâmetros

*bstrlickey*<br/>
A chave de licença para o controle; NULL se criar um controle não licenciado.

### <a name="remarks"></a>Comentários

Consulte [CAxWindow::CreateControl](../../atl/reference/caxwindow-class.md#createcontrol) para obter uma descrição dos parâmetros restantes e do valor de retorno.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `CAxWindow2T::CreateControlLic`.

## <a name="caxwindow2tcreatecontrollicex"></a><a name="createcontrollicex"></a>CAxWindow2T::CreateControlLicEx

Cria um controle ActiveX licenciado, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.

```
HRESULT CreateControlLicEx(
    LPCOLESTR lpszName,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    IUnknown** ppUnkControl = NULL,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL,
    BSTR bstrLicKey = NULL);

    HRESULT CreateControlLicEx(
    DWORD dwResID,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    IUnknown** ppUnkControl = NULL,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL,
    BSTR bstrLickey = NULL);
```

### <a name="parameters"></a>Parâmetros

*bstrlickey*<br/>
A chave de licença para o controle; NULL se criar um controle não licenciado.

### <a name="remarks"></a>Comentários

Consulte [CAxWindow::CreateControlEx](../../atl/reference/caxwindow-class.md#createcontrolex) para obter uma descrição dos parâmetros restantes e do valor de retorno.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `CAxWindow2T::CreateControlLicEx`.

## <a name="caxwindow2tgetwndclassname"></a><a name="getwndclassname"></a>CAxWindow2T::GetWndClassName

Recupera o nome da classe da janela.

```
static LPCTSTR GetWndClassName();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma seqüência contendo`AtlAxWinLic80`o nome da classe janela ( ) que pode hospedar controles ActiveX licenciados e não licenciados.

## <a name="caxwindow2toperator-"></a><a name="operator_eq"></a>CAxWindow2T::operador =

Atribui um HWND a `CAxWindow2T` um objeto existente.

```
CAxWindow2T<TBase>& operator= (HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Uma alça de uma janela existente.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Perguntas frequentes sobre contenção de controle](../../atl/atl-control-containment-faq.md)
