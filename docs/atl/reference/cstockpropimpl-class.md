---
title: Classe CStockPropImpl
ms.date: 05/06/2019
f1_keywords:
- CStockPropImpl
- ATLCTL/ATL::CStockPropImpl
- ATLCTL/ATL::get_Appearance
- ATLCTL/ATL::get_AutoSize
- ATLCTL/ATL::get_BackColor
- ATLCTL/ATL::get_BackStyle
- ATLCTL/ATL::get_BorderColor
- ATLCTL/ATL::get_BorderStyle
- ATLCTL/ATL::get_BorderVisible
- ATLCTL/ATL::get_BorderWidth
- ATLCTL/ATL::get_Caption
- ATLCTL/ATL::get_DrawMode
- ATLCTL/ATL::get_DrawStyle
- ATLCTL/ATL::get_DrawWidth
- ATLCTL/ATL::get_Enabled
- ATLCTL/ATL::get_FillColor
- ATLCTL/ATL::get_FillStyle
- ATLCTL/ATL::get_Font
- ATLCTL/ATL::get_ForeColor
- ATLCTL/ATL::get_HWND
- ATLCTL/ATL::get_MouseIcon
- ATLCTL/ATL::get_MousePointer
- ATLCTL/ATL::get_Picture
- ATLCTL/ATL::get_ReadyState
- ATLCTL/ATL::get_TabStop
- ATLCTL/ATL::get_Text
- ATLCTL/ATL::getvalid
- ATLCTL/ATL::get_Window
- ATLCTL/ATL::put_Appearance
- ATLCTL/ATL::put_AutoSize
- ATLCTL/ATL::put_BackColor
- ATLCTL/ATL::put_BackStyle
- ATLCTL/ATL::put_BorderColor
- ATLCTL/ATL::put_BorderStyle
- ATLCTL/ATL::put_BorderVisible
- ATLCTL/ATL::put_BorderWidth
- ATLCTL/ATL::put_Caption
- ATLCTL/ATL::put_DrawMode
- ATLCTL/ATL::put_DrawStyle
- ATLCTL/ATL::put_DrawWidth
- ATLCTL/ATL::put_Enabled
- ATLCTL/ATL::put_FillColor
- ATLCTL/ATL::put_FillStyle
- ATLCTL/ATL::put_Font
- ATLCTL/ATL::put_ForeColor
- ATLCTL/ATL::put_HWND
- ATLCTL/ATL::put_MouseIcon
- ATLCTL/ATL::put_MousePointer
- ATLCTL/ATL::put_Picture
- ATLCTL/ATL::put_ReadyState
- ATLCTL/ATL::put_TabStop
- ATLCTL/ATL::put_Text
- ATLCTL/ATL::putvalid
- ATLCTL/ATL::put_Window
- ATLCTL/ATL::putref_Font
- ATLCTL/ATL::putref_MouseIcon
- ATLCTL/ATL::putref_Picture
helpviewer_keywords:
- CStockPropImpl class
- controls [ATL], stock properties
- stock properties, ATL controls
ms.assetid: 45f11d7d-6580-4a0e-872d-3bc8b836cfda
ms.openlocfilehash: 0aaeb1b6de0febfd5fc0d41cbcc7bad41c607af4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330668"
---
# <a name="cstockpropimpl-class"></a>Classe CStockPropImpl

Esta classe fornece métodos para apoiar os valores da propriedade de ações.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <
    class T,
    class InterfaceName,
    const IID* piid = &_ATL_IIDOF(InterfaceName),
    const GUID* plibid = &CComModule::m_libid,
    WORD wMajor = 1,
    WORD wMinor = 0,
    class tihclass = CcomTypeInfoHolder>
class ATL_NO_VTABLE CStockPropImpl :
    public IDispatchImpl<InterfaceName, piid, plibid, wMajor, wMinor, tihclass>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe que implementa o `CStockPropImpl`controle e deriva de .

*Interfacename*<br/>
Uma interface dupla expondo as propriedades do estoque.

*Piid*<br/>
Um ponteiro para o `InterfaceName`IID de .

*plibid*<br/>
Um ponteiro para o LIBID da biblioteca `InterfaceName`do tipo que contém a definição de .

*wMajor*<br/>
A versão principal da biblioteca de tipos. O valor padrão é 1.

*wMenor*<br/>
A versão secundária da biblioteca de tipos. O valor padrão é 0.

*tihclass*<br/>
A classe usada para gerenciar as informações do tipo para *T*. O valor `CComTypeInfoHolder`padrão é .

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|[get_Appearance](#get_appearance)|Chame este método para obter o estilo de pintura usado pelo controle, por exemplo, plano ou 3D.|
|[get_AutoSize](#get_autosize)|Chame este método para obter o status da bandeira que indica se o controle não pode ser de qualquer outro tamanho.|
|[get_BackColor](#get_backcolor)|Chame este método para obter a cor de fundo do controle.|
|[get_BackStyle](#get_backstyle)|Chame este método para obter o estilo de fundo do controle, transparente ou opaco.|
|[get_BorderColor](#get_bordercolor)|Chame este método para obter a cor da borda do controle.|
|[get_BorderStyle](#get_borderstyle)|Chame este método para obter o estilo de fronteira do controle.|
|[get_BorderVisible](#get_bordervisible)|Chame este método para obter o status da bandeira que indica se a borda do controle está visível ou não.|
|[get_BorderWidth](#get_borderwidth)|Chame este método para obter a largura (em pixels) da borda do controle.|
|[get_Caption](#get_caption)|Chame este método para obter o texto especificado na legenda de um objeto.|
|[get_DrawMode](#get_drawmode)|Chame este método para obter o modo de desenho do controle, por exemplo, XOR Pen ou Inverter Cores.|
|[get_DrawStyle](#get_drawstyle)|Chame este método para obter o estilo de desenho do controle, por exemplo, sólido, tracejada ou pontilhada.|
|[get_DrawWidth](#get_drawwidth)|Chame este método para obter a largura de desenho (em pixels) usada pelos métodos de desenho do controle.|
|[get_Enabled](#get_enabled)|Chame este método para obter o status do sinalizador que indica se o controle está ativado.|
|[get_FillColor](#get_fillcolor)|Chame este método para obter a cor de preenchimento do controle.|
|[get_FillStyle](#get_fillstyle)|Chame este método para obter o estilo de preenchimento do controle, por exemplo, sólido, transparente ou transversal.|
|[get_Font](#get_font)|Chame este método para obter um ponteiro para as propriedades da fonte do controle.|
|[get_ForeColor](#get_forecolor)|Chame este método para obter a cor do primeiro plano do controle.|
|[get_HWND](#get_hwnd)|Chame este método para obter a alça da janela associada ao controle.|
|[get_MouseIcon](#get_mouseicon)|Chame este método para obter as propriedades de imagem do gráfico (ícone, bitmap ou metaarquivo) a serem exibidas quando o mouse estiver sobre o controle.|
|[get_MousePointer](#get_mousepointer)|Chame este método para obter o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.|
|[get_Picture](#get_picture)|Chame este método para obter um ponteiro para as propriedades de imagem de um gráfico (ícone, bitmap ou metaarquivo) a ser exibido.|
|[get_ReadyState](#get_readystate)|Chame este método para obter o estado pronto do controle, por exemplo, carregando ou carregado.|
|[get_TabStop](#get_tabstop)|Chame este método para obter o sinalizador que indica se o controle é uma guia stop ou não.|
|[get_Text](#get_text)|Chame este método para obter o texto que é exibido com o controle.|
|[getvalid](#get_valid)|Chame este método para obter o status do sinalizador que indica se o controle é válido ou não.|
|[get_Window](#get_window)|Chame este método para obter a alça da janela associada ao controle. Idêntico ao [CStockPropImpl::get_HWND](#get_hwnd).|
|[put_Appearance](#put_appearance)|Chame este método para definir o estilo de pintura usado pelo controle, por exemplo, plano ou 3D.|
|[put_AutoSize](#put_autosize)|Chame este método para definir o valor do sinalizador que indica se o controle não pode ser de qualquer outro tamanho.|
|[put_BackColor](#put_backcolor)|Chame este método para definir a cor de fundo do controle.|
|[put_BackStyle](#put_backstyle)|Chame este método para definir o estilo de fundo do controle.|
|[put_BorderColor](#put_bordercolor)|Chame este método para definir a cor da borda do controle.|
|[put_BorderStyle](#put_borderstyle)|Chame este método para definir o estilo de borda do controle.|
|[put_BorderVisible](#put_bordervisible)|Chame este método para definir o valor da bandeira que indica se a borda do controle está visível ou não.|
|[put_BorderWidth](#put_borderwidth)|Chame este método para definir a largura da borda do controle.|
|[put_Caption](#put_caption)|Chame este método para definir o texto a ser exibido com o controle.|
|[put_DrawMode](#put_drawmode)|Chame este método para definir o modo de desenho do controle, por exemplo, XOR Pen ou Inverter Cores.|
|[put_DrawStyle](#put_drawstyle)|Chame este método para definir o estilo de desenho do controle, por exemplo, sólido, tracejada ou pontilhada.|
|[put_DrawWidth](#put_drawwidth)|Chame este método para definir a largura (em pixels) usada pelos métodos de desenho do controle.|
|[put_Enabled](#put_enabled)|Chame este método para definir o sinalizador que indica se o controle está ativado.|
|[put_FillColor](#put_fillcolor)|Chame este método para definir a cor de preenchimento do controle.|
|[put_FillStyle](#put_fillstyle)|Chame este método para definir o estilo de preenchimento do controle, por exemplo, sólido, transparente ou transtornado.|
|[put_Font](#put_font)|Chame este método para definir as propriedades da fonte do controle.|
|[put_ForeColor](#put_forecolor)|Chame este método para definir a cor do primeiro plano do controle.|
|[Put_hwnd](#put_hwnd)|Este método retorna E_FAIL.|
|[put_MouseIcon](#put_mouseicon)|Chame este método para definir as propriedades de imagem do gráfico (ícone, bitmap ou metaarquivo) a serem exibidas quando o mouse estiver sobre o controle.|
|[put_MousePointer](#put_mousepointer)|Chame este método para definir o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.|
|[put_Picture](#put_picture)|Chame este método para definir as propriedades de imagem de um gráfico (ícone, bitmap ou metaarquivo) a serem exibidas.|
|[put_ReadyState](#put_readystate)|Chame este método para definir o estado pronto do controle, por exemplo, carregando ou carregando.|
|[put_TabStop](#put_tabstop)|Chame este método para definir o valor do sinalizador que indica se o controle é uma guia stop ou não.|
|[put_Text](#put_text)|Chame este método para definir o texto exibido com o controle.|
|[putvalid](#put_valid)|Chame este método para definir o sinalizador que indica se o controle é válido ou não.|
|[put_Window](#put_window)|Este método chama [CStockPropImpl::put_HWND](#put_hwnd), que retorna E_FAIL.|
|[putref_Font](#putref_font)|Chame este método para definir as propriedades da fonte do controle, com uma contagem de referência.|
|[putref_MouseIcon](#putref_mouseicon)|Chame este método para definir as propriedades de imagem do gráfico (ícone, bitmap ou metaarquivo) a serem exibidas quando o mouse estiver sobre o controle, com uma contagem de referência.|
|[putref_Picture](#putref_picture)|Chame este método para definir as propriedades de imagem de um gráfico (ícone, bitmap ou metaarquivo) a ser exibida, com uma contagem de referência.|

## <a name="remarks"></a>Comentários

`CStockPropImpl`fornece **colocar** e **obter** métodos para cada propriedade de ações. Esses métodos fornecem o código necessário para definir ou obter o membro de dados associado a cada propriedade e notificar e sincronizar com o contêiner quando qualquer propriedade for alterado.

O Visual Studio fornece suporte para propriedades de estoque através de seus assistentes. Para obter mais informações sobre como adicionar propriedades de estoque a um controle, consulte o [Tutorial ATL](../../atl/active-template-library-atl-tutorial.md).

Para compatibilidade `CStockPropImpl` retrógrada, também expõe `get_HWND` `put_HWND` `get_Window` e `put_Window` métodos que simplesmente chamam e, respectivamente. A implementação `put_HWND` padrão de retornos E_FAIL já que o HWND deve ser uma propriedade somente leitura.

As seguintes propriedades também têm uma implementação **putref:**

- Fonte

- MouseIcon

- Imagem

As mesmas três propriedades de estoque exigem `CComPtr` que seu membro de dados correspondente seja do tipo ou de alguma outra classe que forneça a contagem correta de referência de interface por meio do operador de atribuição.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

[Idispatchimpl](../../atl/reference/idispatchimpl-class.md)

`CStockPropImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="cstockpropimplget_appearance"></a><a name="get_appearance"></a>CStockPropImpl::get_Appearance

Chame este método para obter o estilo de pintura usado pelo controle, por exemplo, plano ou 3D.

```
HRESULT STDMETHODCALLTYPE get_Appearance(SHORT pnAppearance);
```

### <a name="parameters"></a>Parâmetros

*pnAppearance*<br/>
Variável que recebe o estilo de pintura do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_autosize"></a><a name="get_autosize"></a>CStockPropImpl::get_AutoSize

Chame este método para obter o status da bandeira que indica se o controle não pode ser de qualquer outro tamanho.

```
HRESULT STDMETHODCALLTYPE get_Autosize(VARIANT_BOOL* pbAutoSize);
```

### <a name="parameters"></a>Parâmetros

*pbAutoSize*<br/>
Variável que recebe o status da bandeira. TRUE indica que o controle não pode ser de outro tamanho.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_backcolor"></a><a name="get_backcolor"></a>CStockPropImpl::get_BackColor

Chame este método para obter a cor de fundo do controle.

```
HRESULT STDMETHODCALLTYPE get_BackColor(OLE_COLOR* pclrBackColor);
```

### <a name="parameters"></a>Parâmetros

*pclrBackColor*<br/>
Variável que recebe a cor de fundo do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_backstyle"></a><a name="get_backstyle"></a>CStockPropImpl::get_BackStyle

Chame este método para obter o estilo de fundo do controle, transparente ou opaco.

```
HRESULT STDMETHODCALLTYPE get_BackStyle(LONG* pnBackStyle);
```

### <a name="parameters"></a>Parâmetros

*pnBackStyle*<br/>
Variável que recebe o estilo de fundo do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_bordercolor"></a><a name="get_bordercolor"></a>CStockPropImpl::get_BorderColor

Chame este método para obter a cor da borda do controle.

```
HRESULT STDMETHODCALLTYPE get_BorderColor(OLE_COLOR* pclrBorderColor);
```

### <a name="parameters"></a>Parâmetros

*pclrBorderColor*<br/>
Variável que recebe a cor da borda do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_borderstyle"></a><a name="get_borderstyle"></a>CStockPropImpl::get_BorderStyle

Chame este método para obter o estilo de fronteira do controle.

```
HRESULT STDMETHODCALLTYPE get_BorderStyle(LONG* pnBorderStyle);
```

### <a name="parameters"></a>Parâmetros

*pnBorderStyle*<br/>
Variável que recebe o estilo de borda do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_bordervisible"></a><a name="get_bordervisible"></a>CStockPropImpl::get_BorderVisible

Chame este método para obter o status da bandeira que indica se a borda do controle está visível ou não.

```
HRESULT STDMETHODCALLTYPE get_BorderVisible(VARIANT_BOOL* pbBorderVisible);
```

### <a name="parameters"></a>Parâmetros

*pbBorderVisible*<br/>
Variável que recebe o status da bandeira. TRUE indica que a borda do controle é visível.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_borderwidth"></a><a name="get_borderwidth"></a>CStockPropImpl::get_BorderWidth

Chame este método para obter a largura da fronteira do controle.

```
HRESULT STDMETHODCALLTYPE get_BorderWidth(LONG* pnBorderWidth);
```

### <a name="parameters"></a>Parâmetros

*pnBorderWidth*<br/>
Variável que recebe a largura da borda do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_caption"></a><a name="get_caption"></a>CStockPropImpl::get_Caption

Chame este método para obter o texto especificado na legenda de um objeto.

```
HRESULT STDMETHODCALLTYPE get_Caption(BSTR* pbstrCaption);
```

### <a name="parameters"></a>Parâmetros

*pbstrCaption*<br/>
O texto a ser exibido com o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_drawmode"></a><a name="get_drawmode"></a>CStockPropImpl::get_DrawMode

Chame este método para obter o modo de desenho do controle, por exemplo, XOR Pen ou Inverter Cores.

```
HRESULT STDMETHODCALLTYPE get_DrawMode(LONG* pnDrawMode);
```

### <a name="parameters"></a>Parâmetros

*pnDrawMode*<br/>
Variável que recebe o modo de desenho do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_drawstyle"></a><a name="get_drawstyle"></a>CStockPropImpl::get_DrawStyle

Chame este método para obter o estilo de desenho do controle, por exemplo, sólido, tracejada ou pontilhada.

```
HRESULT STDMETHODCALLTYPE get_DrawStyle(LONG* pnDrawStyle);
```

### <a name="parameters"></a>Parâmetros

*pnDrawStyle*<br/>
Variável que recebe o estilo de desenho do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_drawwidth"></a><a name="get_drawwidth"></a>CStockPropImpl::get_DrawWidth

Chame este método para obter a largura de desenho (em pixels) usada pelos métodos de desenho do controle.

```
HRESULT STDMETHODCALLTYPE get_DrawWidth(LONG* pnDrawWidth);
```

### <a name="parameters"></a>Parâmetros

*pnDrawWidth*<br/>
Variável que recebe o valor de largura do controle, em pixels.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_enabled"></a><a name="get_enabled"></a>CStockPropImpl::get_Enabled

Chame este método para obter o status do sinalizador que indica se o controle está ativado.

```
HRESULT STDMETHODCALLTYPE get_Enabled(VARIANT_BOOL* pbEnabled);
```

### <a name="parameters"></a>Parâmetros

*pbEnabled*<br/>
Variável que recebe o status da bandeira. TRUE indica que o controle está ativado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_fillcolor"></a><a name="get_fillcolor"></a>CStockPropImpl::get_FillColor

Chame este método para obter a cor de preenchimento do controle.

```
HRESULT STDMETHODCALLTYPE get_FillColor(OLE_COLOR* pclrFillColor);
```

### <a name="parameters"></a>Parâmetros

*pclrFillColor*<br/>
Variável que recebe a cor de preenchimento do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_fillstyle"></a><a name="get_fillstyle"></a>CStockPropImpl::get_FillStyle

Chame este método para obter o estilo de preenchimento do controle, por exemplo, sólido, transparente ou crosshatched.

```
HRESULT STDMETHODCALLTYPE get_FillStyle(LONG* pnFillStyle);
```

### <a name="parameters"></a>Parâmetros

*pnFillStyle*<br/>
Variável que recebe o estilo de preenchimento do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_font"></a><a name="get_font"></a>CStockPropImpl::get_Font

Chame este método para obter um ponteiro para as propriedades da fonte do controle.

```
HRESULT STDMETHODCALLTYPE get_Font(IFontDisp** ppFont);
```

### <a name="parameters"></a>Parâmetros

*ppFont*<br/>
Variável que recebe um ponteiro para as propriedades da fonte do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_forecolor"></a><a name="get_forecolor"></a>CStockPropImpl::get_ForeColor

Chame este método para obter a cor do primeiro plano do controle.

```
HRESULT STDMETHODCALLTYPE get_ForeColor(OLE_COLOR* pclrForeColor);
```

### <a name="parameters"></a>Parâmetros

*pclrForeColor*<br/>
Variável que recebe a cor do primeiro plano dos controles.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_hwnd"></a><a name="get_hwnd"></a>CStockPropImpl::get_HWND

Chame este método para obter a alça da janela associada ao controle.

```
HRESULT STDMETHODCALLTYPE get_HWND(LONG_PTR* phWnd);
```

### <a name="parameters"></a>Parâmetros

*PhWnd*<br/>
A alça da janela associada ao controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_mouseicon"></a><a name="get_mouseicon"></a>CStockPropImpl::get_MouseIcon

Chame este método para obter as propriedades de imagem do gráfico (ícone, bitmap ou metaarquivo) a serem exibidas quando o mouse estiver sobre o controle.

```
HRESULT STDMETHODCALLTYPE get_MouseIcon(IPictureDisp** ppPicture);
```

### <a name="parameters"></a>Parâmetros

*ppPicture*<br/>
Variável que recebe um ponteiro para as propriedades da imagem do gráfico.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_mousepointer"></a><a name="get_mousepointer"></a>CStockPropImpl::get_MousePointer

Chame este método para obter o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.

```
HRESULT STDMETHODCALLTYPE get_MousePointer(LONG* pnMousePointer);
```

### <a name="parameters"></a>Parâmetros

*pnMousePointer*<br/>
Variável que recebe o tipo de ponteiro do mouse.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_picture"></a><a name="get_picture"></a>CStockPropImpl::get_Picture

Chame este método para obter um ponteiro para as propriedades de imagem de um gráfico (ícone, bitmap ou metaarquivo) a ser exibido.

```
HRESULT STDMETHODCALLTYPE get_Picture(IPictureDisp** ppPicture);
```

### <a name="parameters"></a>Parâmetros

*ppPicture*<br/>
Variável que recebe um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](/windows/win32/api/ocidl/nn-ocidl-ipicturedisp) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_readystate"></a><a name="get_readystate"></a>CStockPropImpl::get_ReadyState

Chame este método para obter o estado pronto do controle, por exemplo, carregando ou carregado.

```
HRESULT STDMETHODCALLTYPE get_ReadyState(LONG* pnReadyState);
```

### <a name="parameters"></a>Parâmetros

*pnReadyState*<br/>
Variável que recebe o estado pronto do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_tabstop"></a><a name="get_tabstop"></a>CStockPropImpl::get_TabStop

Chame este método para obter o status do sinalizador que indica se o controle é uma guia stop ou não.

```
HRESULT STDMETHODCALLTYPE get_TabStop(VARIANT_BOOL* pbTabStop);
```

### <a name="parameters"></a>Parâmetros

*pbTabStop*<br/>
Variável que recebe o status da bandeira. TRUE indica que o controle é uma parada de guia.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_text"></a><a name="get_text"></a>CStockPropImpl::get_Text

Chame este método para obter o texto que é exibido com o controle.

```
HRESULT STDMETHODCALLTYPE get_Text(BSTR* pbstrText);
```

### <a name="parameters"></a>Parâmetros

*pbstrText*<br/>
O texto que é exibido com o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplgetvalid"></a><a name="get_valid"></a>CStockPropImpl::getvalid

Chame este método para obter o status do sinalizador que indica se o controle é válido ou não.

```
HRESULT STDMETHODCALLTYPE getvalid(VARIANT_BOOL* pbValid);
```

### <a name="parameters"></a>Parâmetros

*pbValid*<br/>
Variável que recebe o status da bandeira. TRUE indica que o controle é válido.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplget_window"></a><a name="get_window"></a>CStockPropImpl::get_Window

Chame este método para obter a alça da janela associada ao controle. Idêntico ao [CStockPropImpl::get_HWND](#get_hwnd).

```
HRESULT STDMETHODCALLTYPE get_Window(LONG_PTR* phWnd);
```

### <a name="parameters"></a>Parâmetros

*PhWnd*<br/>
A alça da janela associada ao controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_appearance"></a><a name="put_appearance"></a>CStockPropImpl::put_Appearance

Chame este método para definir o estilo de pintura usado pelo controle, por exemplo, plano ou 3D.

```
HRESULT STDMETHODCALLTYPE put_Appearance(SHORT nAppearance);
```

### <a name="parameters"></a>Parâmetros

*nAparição*<br/>
O novo estilo de pintura a ser usado pelo controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_autosize"></a><a name="put_autosize"></a>CStockPropImpl::put_AutoSize

Chame este método para definir o valor do sinalizador que indica se o controle não pode ser de qualquer outro tamanho.

```
HRESULT STDMETHODCALLTYPE put_AutoSize(VARIANT_BOOL bAutoSize,);
```

### <a name="parameters"></a>Parâmetros

*bAutoSize*<br/>
VERDADE se o controle não pode ser de outro tamanho.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_backcolor"></a><a name="put_backcolor"></a>CStockPropImpl::put_BackColor

Chame este método para definir a cor de fundo do controle.

```
HRESULT STDMETHODCALLTYPE put_BackColor(OLE_COLOR clrBackColor);
```

### <a name="parameters"></a>Parâmetros

*clrBackColor*<br/>
A nova cor de fundo de controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_backstyle"></a><a name="put_backstyle"></a>CStockPropImpl::put_BackStyle

Chame este método para definir o estilo de fundo do controle.

```
HRESULT STDMETHODCALLTYPE put_BackStyle(LONG nBackStyle);
```

### <a name="parameters"></a>Parâmetros

*nBackStyle*<br/>
O novo estilo de fundo de controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_bordercolor"></a><a name="put_bordercolor"></a>CStockPropImpl::put_BorderColor

Chame este método para definir a cor da borda do controle.

```
HRESULT STDMETHODCALLTYPE put_BorderColor(OLE_COLOR clrBorderColor);
```

### <a name="parameters"></a>Parâmetros

*clrBorderColor*<br/>
A nova cor da fronteira. O OLE_COLOR tipo de dados é representado internamente como um inteiro de 32 bits de comprimento.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_borderstyle"></a><a name="put_borderstyle"></a>CStockPropImpl::put_BorderStyle

Chame este método para definir o estilo de borda do controle.

```
HRESULT STDMETHODCALLTYPE put_BorderStyle(LONG nBorderStyle);
```

### <a name="parameters"></a>Parâmetros

*nBorderStyle*<br/>
O novo estilo de fronteira.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_bordervisible"></a><a name="put_bordervisible"></a>CStockPropImpl::put_BorderVisible

Chame este método para definir o valor da bandeira que indica se a borda do controle está visível ou não.

```
HRESULT STDMETHODCALLTYPE put_BorderVisible(VARIANT_BOOL bBorderVisible);
```

### <a name="parameters"></a>Parâmetros

*bBorderVisible*<br/>
VERDADE se a fronteira for visível.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_borderwidth"></a><a name="put_borderwidth"></a>CStockPropImpl::put_BorderWidth

Chame este método para definir a largura da borda do controle.

```
HRESULT STDMETHODCALLTYPE put_BorderWidth(LONG nBorderWidth);
```

### <a name="parameters"></a>Parâmetros

*nBorderWidth*<br/>
A nova largura da fronteira do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_caption"></a><a name="put_caption"></a>CStockPropImpl::put_Caption

Chame este método para definir o texto a ser exibido com o controle.

```
HRESULT STDMETHODCALLTYPE put_Caption(BSTR bstrCaption);
```

### <a name="parameters"></a>Parâmetros

*bstrCaption*<br/>
O texto a ser exibido com o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_drawmode"></a><a name="put_drawmode"></a>CStockPropImpl::put_DrawMode

Chame este método para definir o modo de desenho do controle, por exemplo, XOR Pen ou Inverter Cores.

```
HRESULT STDMETHODCALLTYPE put_DrawMode(LONG nDrawMode);
```

### <a name="parameters"></a>Parâmetros

*nDrawMode*<br/>
O novo modo de desenho para o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_drawstyle"></a><a name="put_drawstyle"></a>CStockPropImpl::put_DrawStyle

Chame este método para definir o estilo de desenho do controle, por exemplo, sólido, tracejada ou pontilhada.

```
HRESULT STDMETHODCALLTYPE put_DrawStyle(LONG pnDrawStyle);
```

### <a name="parameters"></a>Parâmetros

*nDrawStyle*<br/>
O novo estilo de desenho para o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_drawwidth"></a><a name="put_drawwidth"></a>CStockPropImpl::put_DrawWidth

Chame este método para definir a largura (em pixels) usada pelos métodos de desenho do controle.

```
HRESULT STDMETHODCALLTYPE put_DrawWidth(LONG nDrawWidth);
```

### <a name="parameters"></a>Parâmetros

*nDrawWidth*<br/>
A nova largura a ser usada pelos métodos de desenho do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_enabled"></a><a name="put_enabled"></a>CStockPropImpl::put_Enabled

Chame este método para definir o valor do sinalizador que indica se o controle está ativado.

```
HRESULT STDMETHODCALLTYPE put_Enabled(VARIANT_BOOL bEnabled);
```

### <a name="parameters"></a>Parâmetros

*bEnabled*<br/>
TRUE se o controle estiver ativado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_fillcolor"></a><a name="put_fillcolor"></a>CStockPropImpl::put_FillColor

Chame este método para definir a cor de preenchimento do controle.

```
HRESULT STDMETHODCALLTYPE put_FillColor(OLE_COLOR clrFillColor);
```

### <a name="parameters"></a>Parâmetros

*clrFillColor*<br/>
A nova cor de preenchimento para o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_fillstyle"></a><a name="put_fillstyle"></a>CStockPropImpl::put_FillStyle

Chame este método para definir o estilo de preenchimento do controle, por exemplo, sólido, transparente ou transtornado.

```
HRESULT STDMETHODCALLTYPE put_FillStyle(LONG nFillStyle);
```

### <a name="parameters"></a>Parâmetros

*nFillStyle*<br/>
O novo estilo de preenchimento para o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_font"></a><a name="put_font"></a>CStockPropImpl::put_Font

Chame este método para definir as propriedades da fonte do controle.

```
HRESULT STDMETHODCALLTYPE put_Font(IFontDisp* pFont);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
Um ponteiro para as propriedades da fonte do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_forecolor"></a><a name="put_forecolor"></a>CStockPropImpl::put_ForeColor

Chame este método para definir a cor do primeiro plano do controle.

```
HRESULT STDMETHODCALLTYPE put_ForeColor(OLE_COLOR clrForeColor);
```

### <a name="parameters"></a>Parâmetros

*clrForeColor*<br/>
A nova cor do primeiro plano do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_hwnd"></a><a name="put_hwnd"></a>CStockPropImpl::put_HWND

Este método retorna E_FAIL.

```
HRESULT STDMETHODCALLTYPE put_HWND(LONG_PTR /* hWnd */);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Retorna E_FAIL.

### <a name="remarks"></a>Comentários

A alça da janela é um valor somente leitura.

## <a name="cstockpropimplput_mouseicon"></a><a name="put_mouseicon"></a>CStockPropImpl::put_MouseIcon

Chame este método para definir as propriedades de imagem do gráfico (ícone, bitmap ou metaarquivo) a serem exibidas quando o mouse estiver sobre o controle.

```
HRESULT STDMETHODCALLTYPE put_MouseIcon(IPictureDisp* pPicture);
```

### <a name="parameters"></a>Parâmetros

*pImagem*<br/>
Um ponteiro para as propriedades da imagem do gráfico.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_mousepointer"></a><a name="put_mousepointer"></a>CStockPropImpl::put_MousePointer

Chame este método para definir o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.

```
HRESULT STDMETHODCALLTYPE put_MousePointer(LONG nMousePointer);
```

### <a name="parameters"></a>Parâmetros

*nMousePointer*<br/>
O tipo de ponteiro do mouse.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_picture"></a><a name="put_picture"></a>CStockPropImpl::put_Picture

Chame este método para definir as propriedades de imagem de um gráfico (ícone, bitmap ou metaarquivo) a serem exibidas.

```
HRESULT STDMETHODCALLTYPE put_Picture(IPictureDisp* pPicture);
```

### <a name="parameters"></a>Parâmetros

*pImagem*<br/>
Um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](/windows/win32/api/ocidl/nn-ocidl-ipicturedisp) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_readystate"></a><a name="put_readystate"></a>CStockPropImpl::put_ReadyState

Chame este método para definir o estado pronto do controle, por exemplo, carregando ou carregando.

```
HRESULT STDMETHODCALLTYPE put_ReadyState(LONG nReadyState);
```

### <a name="parameters"></a>Parâmetros

*nReadyState*<br/>
O controle está pronto.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_tabstop"></a><a name="put_tabstop"></a>CStockPropImpl::put_TabStop

Chame este método para definir o sinalizador que indica se o controle é uma guia stop ou não.

```
HRESULT STDMETHODCALLTYPE put_TabStop(VARIANT_BOOL bTabStop);
```

### <a name="parameters"></a>Parâmetros

*bTabStop*<br/>
TRUE se o controle for uma parada de guia.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_text"></a><a name="put_text"></a>CStockPropImpl::put_Text

Chame este método para definir o texto exibido com o controle.

```
HRESULT STDMETHODCALLTYPE put_Text(BSTR bstrText);
```

### <a name="parameters"></a>Parâmetros

*bstrText*<br/>
O texto que é exibido com o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplputvalid"></a><a name="put_valid"></a>CStockPropImpl::putvalid

Chame este método para definir o sinalizador que indica se o controle é válido ou não.

```
HRESULT STDMETHODCALLTYPE getvalid(VARIANT_BOOL bValid);
```

### <a name="parameters"></a>Parâmetros

*bValid*<br/>
TRUE se o controle for válido.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cstockpropimplput_window"></a><a name="put_window"></a>CStockPropImpl::put_Window

Este método chama [CStockPropImpl::put_HWND](#put_hwnd), que retorna E_FAIL.

```
HRESULT STDMETHODCALLTYPE put_Window(LONG_PTR hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
O identificador da janela.

### <a name="return-value"></a>Valor retornado

Retorna E_FAIL.

### <a name="remarks"></a>Comentários

A alça da janela é um valor somente leitura.

## <a name="cstockpropimplputref_font"></a><a name="putref_font"></a>CStockPropImpl::putref_Font

Chame este método para definir as propriedades da fonte do controle, com uma contagem de referência.

```
HRESULT STDMETHODCALLTYPE putref_Font(IFontDisp* pFont);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
Um ponteiro para as propriedades da fonte do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

O mesmo que [CStockPropImpl::put_Font,](#put_font)mas com uma contagem de referências.

## <a name="cstockpropimplputref_mouseicon"></a><a name="putref_mouseicon"></a>CStockPropImpl::putref_MouseIcon

Chame este método para definir as propriedades de imagem do gráfico (ícone, bitmap ou metaarquivo) a serem exibidas quando o mouse estiver sobre o controle, com uma contagem de referência.

```
HRESULT STDMETHODCALLTYPE putref_MouseIcon(IPictureDisp* pPicture);
```

### <a name="parameters"></a>Parâmetros

*pImagem*<br/>
Um ponteiro para as propriedades da imagem do gráfico.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

O mesmo que [CStockPropImpl::put_MouseIcon](#put_mouseicon), mas com uma contagem de referências.

## <a name="cstockpropimplputref_picture"></a><a name="putref_picture"></a>CStockPropImpl::putref_Picture

Chame este método para definir as propriedades de imagem de um gráfico (ícone, bitmap ou metaarquivo) a ser exibida, com uma contagem de referência.

```
HRESULT STDMETHODCALLTYPE putref_Picture(IPictureDisp* pPicture);
```

### <a name="parameters"></a>Parâmetros

*pImagem*<br/>
Um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](/windows/win32/api/ocidl/nn-ocidl-ipicturedisp) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

O mesmo que [CStockPropImpl::put_Picture,](#put_picture)mas com uma contagem de referências.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)
