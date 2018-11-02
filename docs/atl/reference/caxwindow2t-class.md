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
ms.openlocfilehash: 3e28bfe15c55342cbdfb50b125243c170ba97698
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665420"
---
# <a name="caxwindow2t-class"></a>Classe CAxWindow2T

Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedagem de controles do ActiveX licenciados.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class TBase = CWindow>
    class CAxWindow2T :
    public CAxWindowT<TBase>
```

#### <a name="parameters"></a>Parâmetros

*Tdígitos de base*<br/>
A classe da qual `CAxWindowT` deriva.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxWindow2T::CAxWindow2T](#caxwindow2t)|Constrói um objeto `CAxWindow2T`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxWindow2T::Create](#create)|Cria uma janela de host.|
|[CAxWindow2T::CreateControlLic](#createcontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|
|[CAxWindow2T::CreateControlLicEx](#createcontrollicex)|Cria um controle ActiveX licenciado, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[CAxWindow2T::GetWndClassName](#getwndclassname)|Método estático que recupera o nome da classe de janela.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxWindow2T::operator =](#operator_eq)|Atribui um HWND um existente `CAxWindow2T` objeto.|

## <a name="remarks"></a>Comentários

`CAxWindow2T` fornece métodos para manipular uma janela que hospeda um controle ActiveX. `CAxWindow2T` também tem suporte para hospedagem de controles do ActiveX licenciados. A hospedagem é fornecida por " **AtlAxWinLic80**", que é encapsulado por `CAxWindow2T`.

Classe `CAxWindow2` é implementado como uma especialização do `CAxWindow2T` classe. Essa especialização é declarada como:

`typedef CAxWindow2T <CWindow> CAxWindow2;`

> [!NOTE]
> `CAxWindowT` os membros estão documentados em [CAxWindow](../../atl/reference/caxwindow-class.md).

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa os membros dessa classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`CAxWindowT`

`CAxWindow2T`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="caxwindow2t"></a>  CAxWindow2T::CAxWindow2T

Constrói um objeto `CAxWindow2T`.

```
CAxWindow2T(HWND  hWnd = NULL) : CAxWindowT<TBase>(hWnd)
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Um identificador de uma janela existente.

##  <a name="create"></a>  CAxWindow2T::Create

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

`CAxWindow2T::Create` chamadas [CWindow::Create](../../atl/reference/cwindow-class.md#create) com o LPCTSTR *lpstrWndClass* parâmetro definido como a classe de janela que fornece hospedagem de controles (`AtlAxWinLic80`).

Consulte `CWindow::Create` para obter uma descrição dos parâmetros e valor de retorno.

**Observação** se 0 for usado como o valor para o *MenuOrID* parâmetro, ele deve ser especificado como 0U (o valor padrão) para evitar um erro do compilador.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::Create`.

##  <a name="createcontrollic"></a>  CAxWindow2T::CreateControlLic

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
A chave de licença para o controle; NULL se a criação de um controle nonlicensed.

### <a name="remarks"></a>Comentários

Ver [CAxWindow::CreateControl](../../atl/reference/caxwindow-class.md#createcontrol) para obter uma descrição do valor de retorno e parâmetros restantes.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::CreateControlLic`.

##  <a name="createcontrollicex"></a>  CAxWindow2T::CreateControlLicEx

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
A chave de licença para o controle; NULL se a criação de um controle nonlicensed.

### <a name="remarks"></a>Comentários

Ver [CAxWindow::CreateControlEx](../../atl/reference/caxwindow-class.md#createcontrolex) para obter uma descrição do valor de retorno e parâmetros restantes.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::CreateControlLicEx`.

##  <a name="getwndclassname"></a>  CAxWindow2T::GetWndClassName

Recupera o nome da classe de janela.

```
static LPCTSTR GetWndClassName();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma cadeia de caracteres que contém o nome da classe de janela (`AtlAxWinLic80`) que pode hospedar controles do ActiveX licenciados e nonlicensed.

##  <a name="operator_eq"></a>  CAxWindow2T::operator =

Atribui um HWND um existente `CAxWindow2T` objeto.

```
CAxWindow2T<TBase>& operator= (HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Um identificador de uma janela existente.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Perguntas frequentes sobre contenção de controle](../../atl/atl-control-containment-faq.md)
