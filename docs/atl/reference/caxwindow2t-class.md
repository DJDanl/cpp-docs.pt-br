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
ms.openlocfilehash: 0d5991dcbf79d1c2415594636a09908586d1dc2f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78864708"
---
# <a name="caxwindow2t-class"></a>Classe CAxWindow2T

Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedar controles ActiveX licenciados.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class TBase = CWindow>
    class CAxWindow2T :
    public CAxWindowT<TBase>
```

#### <a name="parameters"></a>Parâmetros

*TBase*<br/>
A classe da qual `CAxWindowT` deriva.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAxWindow2T::CAxWindow2T](#caxwindow2t)|Constrói um objeto `CAxWindow2T`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAxWindow2T:: criar](#create)|Cria uma janela de host.|
|[CAxWindow2T::CreateControlLic](#createcontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|
|[CAxWindow2T::CreateControlLicEx](#createcontrollicex)|Cria um controle ActiveX licenciado, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[CAxWindow2T::GetWndClassName](#getwndclassname)|Método estático que recupera o nome da classe de janela.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAxWindow2T:: Operator =](#operator_eq)|Atribui um HWND a um objeto de `CAxWindow2T` existente.|

## <a name="remarks"></a>Comentários

`CAxWindow2T` fornece métodos para manipular uma janela que hospeda um controle ActiveX. `CAxWindow2T` também tem suporte para hospedar controles ActiveX licenciados. A hospedagem é fornecida por " **AtlAxWinLic80**", que é encapsulado por `CAxWindow2T`.

A classe `CAxWindow2` é implementada como uma especialização da classe `CAxWindow2T`. Essa especialização é declarada como:

`typedef CAxWindow2T <CWindow> CAxWindow2;`

> [!NOTE]
> `CAxWindowT` Membros estão documentados em [CAxWindow](../../atl/reference/caxwindow-class.md).

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa os membros desta classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`CAxWindowT`

`CAxWindow2T`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlwin. h

##  <a name="caxwindow2t"></a>CAxWindow2T::CAxWindow2T

Constrói um objeto `CAxWindow2T`.

```
CAxWindow2T(HWND  hWnd = NULL) : CAxWindowT<TBase>(hWnd)
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Um identificador de uma janela existente.

##  <a name="create"></a>CAxWindow2T:: criar

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

`CAxWindow2T::Create` chama [CWindow:: Create](../../atl/reference/cwindow-class.md#create) com o parâmetro LPCTSTR *lpstrWndClass* definido como a classe Window que fornece hospedagem de controle (`AtlAxWinLic80`).

Consulte `CWindow::Create` para obter uma descrição dos parâmetros e valor de retorno.

**Observação** Se 0 for usado como o valor para o parâmetro *MenuOrID* , ele deverá ser especificado como 0u (o valor padrão) para evitar um erro do compilador.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::Create`.

##  <a name="createcontrollic"></a>CAxWindow2T::CreateControlLic

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

*bstrLicKey*<br/>
A chave de licença para o controle; NULL se a criação de um controle não licenciado.

### <a name="remarks"></a>Comentários

Consulte [CAxWindow:: CreateControl](../../atl/reference/caxwindow-class.md#createcontrol) para obter uma descrição dos parâmetros e do valor de retorno restantes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::CreateControlLic`.

##  <a name="createcontrollicex"></a>CAxWindow2T::CreateControlLicEx

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

*bstrLicKey*<br/>
A chave de licença para o controle; NULL se a criação de um controle não licenciado.

### <a name="remarks"></a>Comentários

Consulte [CAxWindow:: CreateControlEx](../../atl/reference/caxwindow-class.md#createcontrolex) para obter uma descrição dos parâmetros e do valor de retorno restantes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::CreateControlLicEx`.

##  <a name="getwndclassname"></a>CAxWindow2T::GetWndClassName

Recupera o nome da classe de janela.

```
static LPCTSTR GetWndClassName();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma cadeia de caracteres que contém o nome da classe de janela (`AtlAxWinLic80`) que pode hospedar controles ActiveX licenciados e não licenciados.

##  <a name="operator_eq"></a>CAxWindow2T:: Operator =

Atribui um HWND a um objeto de `CAxWindow2T` existente.

```
CAxWindow2T<TBase>& operator= (HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Um identificador de uma janela existente.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Perguntas frequentes sobre confinamento de controle](../../atl/atl-control-containment-faq.md)
