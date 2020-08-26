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
ms.openlocfilehash: 9d54e4e5c49e73a12fc5d360c3963c2bcf5b2b38
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835578"
---
# <a name="cstockpropimpl-class"></a>Classe CStockPropImpl

Essa classe fornece métodos para dar suporte a valores de propriedade de estoque.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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

#### <a name="parameters"></a>parâmetros

*T*<br/>
A classe que implementa o controle e deriva de `CStockPropImpl` .

*InterfaceName*<br/>
Uma interface dupla expondo as propriedades de ações.

*piid*<br/>
Um ponteiro para o IID de `InterfaceName` .

*plibid*<br/>
Um ponteiro para o LIBID da biblioteca de tipos que contém a definição de `InterfaceName` .

*wMajor*<br/>
A versão principal da biblioteca de tipos. O valor padrão é 1.

*wMinor*<br/>
A versão secundária da biblioteca de tipos. O valor padrão é 0.

*tihclass*<br/>
A classe usada para gerenciar as informações de tipo para *T*. O valor padrão é `CComTypeInfoHolder` .

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[get_Appearance](#get_appearance)|Chame esse método para obter o estilo de pintura usado pelo controle, por exemplo, simples ou 3D.|
|[get_AutoSize](#get_autosize)|Chame esse método para obter o status do sinalizador que indica se o controle não pode ter nenhum outro tamanho.|
|[get_BackColor](#get_backcolor)|Chame esse método para obter a cor do plano de fundo do controle.|
|[get_BackStyle](#get_backstyle)|Chame esse método para obter o estilo de plano de fundo do controle, seja transparente ou opaco.|
|[get_BorderColor](#get_bordercolor)|Chame esse método para obter a cor da borda do controle.|
|[get_BorderStyle](#get_borderstyle)|Chame esse método para obter o estilo de borda do controle.|
|[get_BorderVisible](#get_bordervisible)|Chame esse método para obter o status do sinalizador que indica se a borda do controle está visível ou não.|
|[get_BorderWidth](#get_borderwidth)|Chame esse método para obter a largura (em pixels) da borda do controle.|
|[get_Caption](#get_caption)|Chame esse método para obter o texto especificado na legenda de um objeto.|
|[get_DrawMode](#get_drawmode)|Chame esse método para obter o modo de desenho do controle, por exemplo, caneta XOR ou inverter cores.|
|[get_DrawStyle](#get_drawstyle)|Chame esse método para obter o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.|
|[get_DrawWidth](#get_drawwidth)|Chame esse método para obter a largura do desenho (em pixels) usada pelos métodos de desenho do controle.|
|[get_Enabled](#get_enabled)|Chame esse método para obter o status do sinalizador que indica se o controle está habilitado.|
|[get_FillColor](#get_fillcolor)|Chame esse método para obter a cor de preenchimento do controle.|
|[get_FillStyle](#get_fillstyle)|Chame esse método para obter o estilo de preenchimento do controle, por exemplo, sólido, transparente ou com hachura cruzada.|
|[get_Font](#get_font)|Chame esse método para obter um ponteiro para as propriedades de fonte do controle.|
|[get_ForeColor](#get_forecolor)|Chame esse método para obter a cor de primeiro plano do controle.|
|[get_HWND](#get_hwnd)|Chame esse método para obter o identificador de janela associado ao controle.|
|[get_MouseIcon](#get_mouseicon)|Chame esse método para obter as propriedades da imagem do elemento gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse estiver sobre o controle.|
|[get_MousePointer](#get_mousepointer)|Chame esse método para obter o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.|
|[get_Picture](#get_picture)|Chame esse método para obter um ponteiro para as propriedades da imagem de um elemento gráfico (ícone, bitmap ou metarquivo) a ser exibido.|
|[get_ReadyState](#get_readystate)|Chame esse método para obter o estado pronto do controle, por exemplo, carregando ou carregado.|
|[get_TabStop](#get_tabstop)|Chame esse método para obter o sinalizador que indica se o controle é uma parada de tabulação ou não.|
|[get_Text](#get_text)|Chame esse método para obter o texto que é exibido com o controle.|
|[getválida](#get_valid)|Chame esse método para obter o status do sinalizador que indica se o controle é válido ou não.|
|[get_Window](#get_window)|Chame esse método para obter o identificador de janela associado ao controle. Idêntico a [CStockPropImpl:: get_HWND](#get_hwnd).|
|[put_Appearance](#put_appearance)|Chame esse método para definir o estilo de pintura usado pelo controle, por exemplo, simples ou 3D.|
|[put_AutoSize](#put_autosize)|Chame esse método para definir o valor do sinalizador que indica se o controle não pode ser qualquer outro tamanho.|
|[put_BackColor](#put_backcolor)|Chame esse método para definir a cor do plano de fundo do controle.|
|[put_BackStyle](#put_backstyle)|Chame esse método para definir o estilo de plano de fundo do controle.|
|[put_BorderColor](#put_bordercolor)|Chame esse método para definir a cor da borda do controle.|
|[put_BorderStyle](#put_borderstyle)|Chame esse método para definir o estilo de borda do controle.|
|[put_BorderVisible](#put_bordervisible)|Chame esse método para definir o valor do sinalizador que indica se a borda do controle está visível ou não.|
|[put_BorderWidth](#put_borderwidth)|Chame esse método para definir a largura da borda do controle.|
|[put_Caption](#put_caption)|Chame esse método para definir o texto a ser exibido com o controle.|
|[put_DrawMode](#put_drawmode)|Chame esse método para definir o modo de desenho do controle, por exemplo, caneta XOR ou inverter cores.|
|[put_DrawStyle](#put_drawstyle)|Chame esse método para definir o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.|
|[put_DrawWidth](#put_drawwidth)|Chame esse método para definir a largura (em pixels) usada pelos métodos de desenho do controle.|
|[put_Enabled](#put_enabled)|Chame esse método para definir o sinalizador que indica se o controle está habilitado.|
|[put_FillColor](#put_fillcolor)|Chame esse método para definir a cor de preenchimento do controle.|
|[put_FillStyle](#put_fillstyle)|Chame esse método para definir o estilo de preenchimento do controle, por exemplo, sólido, transparente ou com hachura cruzada.|
|[put_Font](#put_font)|Chame esse método para definir as propriedades da fonte do controle.|
|[put_ForeColor](#put_forecolor)|Chame esse método para definir a cor de primeiro plano do controle.|
|[put_HWND](#put_hwnd)|Esse método retorna E_FAIL.|
|[put_MouseIcon](#put_mouseicon)|Chame esse método para definir as propriedades da imagem do elemento gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse estiver sobre o controle.|
|[put_MousePointer](#put_mousepointer)|Chame esse método para definir o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.|
|[put_Picture](#put_picture)|Chame esse método para definir as propriedades de imagem de um elemento gráfico (ícone, bitmap ou metarquivo) a ser exibido.|
|[put_ReadyState](#put_readystate)|Chame esse método para definir o estado pronto do controle, por exemplo, carregando ou carregado.|
|[put_TabStop](#put_tabstop)|Chame esse método para definir o valor do sinalizador que indica se o controle é uma parada de tabulação ou não.|
|[put_Text](#put_text)|Chame esse método para definir o texto que é exibido com o controle.|
|[putvalid](#put_valid)|Chame esse método para definir o sinalizador que indica se o controle é válido ou não.|
|[put_Window](#put_window)|Esse método chama [CStockPropImpl::p ut_HWND](#put_hwnd), que retorna E_FAIL.|
|[putref_Font](#putref_font)|Chame esse método para definir as propriedades de fonte do controle, com uma contagem de referência.|
|[putref_MouseIcon](#putref_mouseicon)|Chame esse método para definir as propriedades da imagem do elemento gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse estiver sobre o controle, com uma contagem de referência.|
|[putref_Picture](#putref_picture)|Chame esse método para definir as propriedades da imagem de um elemento gráfico (ícone, bitmap ou metarquivo) a ser exibido, com uma contagem de referência.|

## <a name="remarks"></a>Comentários

`CStockPropImpl` fornece os métodos **Put** e **Get** para cada propriedade stock. Esses métodos fornecem o código necessário para definir ou obter o membro de dados associado a cada propriedade e para notificar e sincronizar com o contêiner quando qualquer propriedade for alterada.

O Visual Studio oferece suporte para propriedades de ações por meio de seus assistentes. Para obter mais informações sobre como adicionar propriedades de ações a um controle, consulte o [tutorial do ATL](../../atl/active-template-library-atl-tutorial.md).

Para compatibilidade com versões anteriores, o `CStockPropImpl` também expõe `get_Window` e `put_Window` métodos que simplesmente chamam `get_HWND` e `put_HWND` , respectivamente. A implementação padrão de `put_HWND` retorna E_FAIL desde que o HWND deva ser uma propriedade somente leitura.

As propriedades a seguir também têm uma implementação **PUTREF** :

- Fonte

- MouseIcon

- Imagem

As mesmas três propriedades Stock exigem que o membro de dados correspondente seja do tipo `CComPtr` ou alguma outra classe que forneça a contagem correta da referência de interface por meio do operador de atribuição.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

[IDispatchImpl](../../atl/reference/idispatchimpl-class.md)

`CStockPropImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

## <a name="cstockpropimplget_appearance"></a><a name="get_appearance"></a> CStockPropImpl:: get_Appearance

Chame esse método para obter o estilo de pintura usado pelo controle, por exemplo, simples ou 3D.

```
HRESULT STDMETHODCALLTYPE get_Appearance(SHORT pnAppearance);
```

### <a name="parameters"></a>parâmetros

*pnAppearance*<br/>
Variável que recebe o estilo de pintura do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_autosize"></a><a name="get_autosize"></a> CStockPropImpl:: get_AutoSize

Chame esse método para obter o status do sinalizador que indica se o controle não pode ter nenhum outro tamanho.

```
HRESULT STDMETHODCALLTYPE get_Autosize(VARIANT_BOOL* pbAutoSize);
```

### <a name="parameters"></a>parâmetros

*pbAutoSize*<br/>
Variável que recebe o status do sinalizador. VERDADEIRO indica que o controle não pode ter nenhum outro tamanho.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_backcolor"></a><a name="get_backcolor"></a> CStockPropImpl:: get_BackColor

Chame esse método para obter a cor do plano de fundo do controle.

```
HRESULT STDMETHODCALLTYPE get_BackColor(OLE_COLOR* pclrBackColor);
```

### <a name="parameters"></a>parâmetros

*pclrBackColor*<br/>
Variável que recebe a cor do plano de fundo do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_backstyle"></a><a name="get_backstyle"></a> CStockPropImpl:: get_BackStyle

Chame esse método para obter o estilo de plano de fundo do controle, seja transparente ou opaco.

```
HRESULT STDMETHODCALLTYPE get_BackStyle(LONG* pnBackStyle);
```

### <a name="parameters"></a>parâmetros

*pnBackStyle*<br/>
Variável que recebe o estilo de plano de fundo do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_bordercolor"></a><a name="get_bordercolor"></a> CStockPropImpl:: get_BorderColor

Chame esse método para obter a cor da borda do controle.

```
HRESULT STDMETHODCALLTYPE get_BorderColor(OLE_COLOR* pclrBorderColor);
```

### <a name="parameters"></a>parâmetros

*pclrBorderColor*<br/>
Variável que recebe a cor da borda do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_borderstyle"></a><a name="get_borderstyle"></a> CStockPropImpl:: get_BorderStyle

Chame esse método para obter o estilo de borda do controle.

```
HRESULT STDMETHODCALLTYPE get_BorderStyle(LONG* pnBorderStyle);
```

### <a name="parameters"></a>parâmetros

*pnBorderStyle*<br/>
Variável que recebe o estilo de borda do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_bordervisible"></a><a name="get_bordervisible"></a> CStockPropImpl:: get_BorderVisible

Chame esse método para obter o status do sinalizador que indica se a borda do controle está visível ou não.

```
HRESULT STDMETHODCALLTYPE get_BorderVisible(VARIANT_BOOL* pbBorderVisible);
```

### <a name="parameters"></a>parâmetros

*pbBorderVisible*<br/>
Variável que recebe o status do sinalizador. VERDADEIRO indica que a borda do controle está visível.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_borderwidth"></a><a name="get_borderwidth"></a> CStockPropImpl:: get_BorderWidth

Chame esse método para obter a largura da borda do controle.

```
HRESULT STDMETHODCALLTYPE get_BorderWidth(LONG* pnBorderWidth);
```

### <a name="parameters"></a>parâmetros

*pnBorderWidth*<br/>
Variável que recebe a largura da borda do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_caption"></a><a name="get_caption"></a> CStockPropImpl:: get_Caption

Chame esse método para obter o texto especificado na legenda de um objeto.

```
HRESULT STDMETHODCALLTYPE get_Caption(BSTR* pbstrCaption);
```

### <a name="parameters"></a>parâmetros

*pbstrCaption*<br/>
O texto a ser exibido com o controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_drawmode"></a><a name="get_drawmode"></a> CStockPropImpl:: get_DrawMode

Chame esse método para obter o modo de desenho do controle, por exemplo, caneta XOR ou inverter cores.

```
HRESULT STDMETHODCALLTYPE get_DrawMode(LONG* pnDrawMode);
```

### <a name="parameters"></a>parâmetros

*pnDrawMode*<br/>
Variável que recebe o modo de desenho do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_drawstyle"></a><a name="get_drawstyle"></a> CStockPropImpl:: get_DrawStyle

Chame esse método para obter o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.

```
HRESULT STDMETHODCALLTYPE get_DrawStyle(LONG* pnDrawStyle);
```

### <a name="parameters"></a>parâmetros

*pnDrawStyle*<br/>
Variável que recebe o estilo de desenho do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_drawwidth"></a><a name="get_drawwidth"></a> CStockPropImpl:: get_DrawWidth

Chame esse método para obter a largura do desenho (em pixels) usada pelos métodos de desenho do controle.

```
HRESULT STDMETHODCALLTYPE get_DrawWidth(LONG* pnDrawWidth);
```

### <a name="parameters"></a>parâmetros

*pnDrawWidth*<br/>
Variável que recebe o valor de largura do controle, em pixels.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_enabled"></a><a name="get_enabled"></a> CStockPropImpl:: get_Enabled

Chame esse método para obter o status do sinalizador que indica se o controle está habilitado.

```
HRESULT STDMETHODCALLTYPE get_Enabled(VARIANT_BOOL* pbEnabled);
```

### <a name="parameters"></a>parâmetros

*pbEnabled*<br/>
Variável que recebe o status do sinalizador. VERDADEIRO indica que o controle está habilitado.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_fillcolor"></a><a name="get_fillcolor"></a> CStockPropImpl:: get_FillColor

Chame esse método para obter a cor de preenchimento do controle.

```
HRESULT STDMETHODCALLTYPE get_FillColor(OLE_COLOR* pclrFillColor);
```

### <a name="parameters"></a>parâmetros

*pclrFillColor*<br/>
Variável que recebe a cor de preenchimento do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_fillstyle"></a><a name="get_fillstyle"></a> CStockPropImpl:: get_FillStyle

Chame esse método para obter o estilo de preenchimento do controle, por exemplo, sólido, transparente ou crosshatched.

```
HRESULT STDMETHODCALLTYPE get_FillStyle(LONG* pnFillStyle);
```

### <a name="parameters"></a>parâmetros

*pnFillStyle*<br/>
Variável que recebe o estilo de preenchimento do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_font"></a><a name="get_font"></a> CStockPropImpl:: get_Font

Chame esse método para obter um ponteiro para as propriedades de fonte do controle.

```
HRESULT STDMETHODCALLTYPE get_Font(IFontDisp** ppFont);
```

### <a name="parameters"></a>parâmetros

*ppFont*<br/>
Variável que recebe um ponteiro para as propriedades da fonte do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_forecolor"></a><a name="get_forecolor"></a> CStockPropImpl:: get_ForeColor

Chame esse método para obter a cor de primeiro plano do controle.

```
HRESULT STDMETHODCALLTYPE get_ForeColor(OLE_COLOR* pclrForeColor);
```

### <a name="parameters"></a>parâmetros

*pclrForeColor*<br/>
Variável que recebe a cor de primeiro plano dos controles.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_hwnd"></a><a name="get_hwnd"></a> CStockPropImpl:: get_HWND

Chame esse método para obter o identificador de janela associado ao controle.

```
HRESULT STDMETHODCALLTYPE get_HWND(LONG_PTR* phWnd);
```

### <a name="parameters"></a>parâmetros

*phWnd*<br/>
O identificador de janela associado ao controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_mouseicon"></a><a name="get_mouseicon"></a> CStockPropImpl:: get_MouseIcon

Chame esse método para obter as propriedades da imagem do elemento gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse estiver sobre o controle.

```
HRESULT STDMETHODCALLTYPE get_MouseIcon(IPictureDisp** ppPicture);
```

### <a name="parameters"></a>parâmetros

*ppPicture*<br/>
Variável que recebe um ponteiro para as propriedades da imagem do gráfico.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_mousepointer"></a><a name="get_mousepointer"></a> CStockPropImpl:: get_MousePointer

Chame esse método para obter o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.

```
HRESULT STDMETHODCALLTYPE get_MousePointer(LONG* pnMousePointer);
```

### <a name="parameters"></a>parâmetros

*pnMousePointer*<br/>
Variável que recebe o tipo de ponteiro do mouse.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_picture"></a><a name="get_picture"></a> CStockPropImpl:: get_Picture

Chame esse método para obter um ponteiro para as propriedades da imagem de um elemento gráfico (ícone, bitmap ou metarquivo) a ser exibido.

```
HRESULT STDMETHODCALLTYPE get_Picture(IPictureDisp** ppPicture);
```

### <a name="parameters"></a>parâmetros

*ppPicture*<br/>
Variável que recebe um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](/windows/win32/api/ocidl/nn-ocidl-ipicturedisp) para obter mais detalhes.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_readystate"></a><a name="get_readystate"></a> CStockPropImpl:: get_ReadyState

Chame esse método para obter o estado pronto do controle, por exemplo, carregando ou carregado.

```
HRESULT STDMETHODCALLTYPE get_ReadyState(LONG* pnReadyState);
```

### <a name="parameters"></a>parâmetros

*pnReadyState*<br/>
Variável que recebe o estado de pronto do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_tabstop"></a><a name="get_tabstop"></a> CStockPropImpl:: get_TabStop

Chame esse método para obter o status do sinalizador que indica se o controle é uma parada de tabulação ou não.

```
HRESULT STDMETHODCALLTYPE get_TabStop(VARIANT_BOOL* pbTabStop);
```

### <a name="parameters"></a>parâmetros

*pbTabStop*<br/>
Variável que recebe o status do sinalizador. VERDADEIRO indica que o controle é uma parada de tabulação.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_text"></a><a name="get_text"></a> CStockPropImpl:: get_Text

Chame esse método para obter o texto que é exibido com o controle.

```
HRESULT STDMETHODCALLTYPE get_Text(BSTR* pbstrText);
```

### <a name="parameters"></a>parâmetros

*pbstrText*<br/>
O texto que é exibido com o controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplgetvalid"></a><a name="get_valid"></a> CStockPropImpl:: getválida

Chame esse método para obter o status do sinalizador que indica se o controle é válido ou não.

```
HRESULT STDMETHODCALLTYPE getvalid(VARIANT_BOOL* pbValid);
```

### <a name="parameters"></a>parâmetros

*pbValid*<br/>
Variável que recebe o status do sinalizador. VERDADEIRO indica que o controle é válido.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplget_window"></a><a name="get_window"></a> CStockPropImpl:: get_Window

Chame esse método para obter o identificador de janela associado ao controle. Idêntico a [CStockPropImpl:: get_HWND](#get_hwnd).

```
HRESULT STDMETHODCALLTYPE get_Window(LONG_PTR* phWnd);
```

### <a name="parameters"></a>parâmetros

*phWnd*<br/>
O identificador de janela associado ao controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_appearance"></a><a name="put_appearance"></a> CStockPropImpl::p ut_Appearance

Chame esse método para definir o estilo de pintura usado pelo controle, por exemplo, simples ou 3D.

```
HRESULT STDMETHODCALLTYPE put_Appearance(SHORT nAppearance);
```

### <a name="parameters"></a>parâmetros

*nAppearance*<br/>
O novo estilo de pintura a ser usado pelo controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_autosize"></a><a name="put_autosize"></a> CStockPropImpl::p ut_AutoSize

Chame esse método para definir o valor do sinalizador que indica se o controle não pode ser qualquer outro tamanho.

```
HRESULT STDMETHODCALLTYPE put_AutoSize(VARIANT_BOOL bAutoSize,);
```

### <a name="parameters"></a>parâmetros

*bAutoSize*<br/>
TRUE se o controle não puder ter nenhum outro tamanho.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_backcolor"></a><a name="put_backcolor"></a> CStockPropImpl::p ut_BackColor

Chame esse método para definir a cor do plano de fundo do controle.

```
HRESULT STDMETHODCALLTYPE put_BackColor(OLE_COLOR clrBackColor);
```

### <a name="parameters"></a>parâmetros

*clrBackColor*<br/>
A cor do plano de fundo do novo controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_backstyle"></a><a name="put_backstyle"></a> CStockPropImpl::p ut_BackStyle

Chame esse método para definir o estilo de plano de fundo do controle.

```
HRESULT STDMETHODCALLTYPE put_BackStyle(LONG nBackStyle);
```

### <a name="parameters"></a>parâmetros

*nBackStyle*<br/>
O novo estilo de plano de fundo do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_bordercolor"></a><a name="put_bordercolor"></a> CStockPropImpl::p ut_BorderColor

Chame esse método para definir a cor da borda do controle.

```
HRESULT STDMETHODCALLTYPE put_BorderColor(OLE_COLOR clrBorderColor);
```

### <a name="parameters"></a>parâmetros

*clrBorderColor*<br/>
A nova cor da borda. O tipo de dados OLE_COLOR é representado internamente como um inteiro longo de 32 bits.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_borderstyle"></a><a name="put_borderstyle"></a> CStockPropImpl::p ut_BorderStyle

Chame esse método para definir o estilo de borda do controle.

```
HRESULT STDMETHODCALLTYPE put_BorderStyle(LONG nBorderStyle);
```

### <a name="parameters"></a>parâmetros

*nBorderStyle*<br/>
O novo estilo de borda.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_bordervisible"></a><a name="put_bordervisible"></a> CStockPropImpl::p ut_BorderVisible

Chame esse método para definir o valor do sinalizador que indica se a borda do controle está visível ou não.

```
HRESULT STDMETHODCALLTYPE put_BorderVisible(VARIANT_BOOL bBorderVisible);
```

### <a name="parameters"></a>parâmetros

*bBorderVisible*<br/>
TRUE se a borda for visível.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_borderwidth"></a><a name="put_borderwidth"></a> CStockPropImpl::p ut_BorderWidth

Chame esse método para definir a largura da borda do controle.

```
HRESULT STDMETHODCALLTYPE put_BorderWidth(LONG nBorderWidth);
```

### <a name="parameters"></a>parâmetros

*nBorderWidth*<br/>
A nova largura da borda do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_caption"></a><a name="put_caption"></a> CStockPropImpl::p ut_Caption

Chame esse método para definir o texto a ser exibido com o controle.

```
HRESULT STDMETHODCALLTYPE put_Caption(BSTR bstrCaption);
```

### <a name="parameters"></a>parâmetros

*bstrCaption*<br/>
O texto a ser exibido com o controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_drawmode"></a><a name="put_drawmode"></a> CStockPropImpl::p ut_DrawMode

Chame esse método para definir o modo de desenho do controle, por exemplo, caneta XOR ou inverter cores.

```
HRESULT STDMETHODCALLTYPE put_DrawMode(LONG nDrawMode);
```

### <a name="parameters"></a>parâmetros

*nDrawMode*<br/>
O novo modo de desenho para o controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_drawstyle"></a><a name="put_drawstyle"></a> CStockPropImpl::p ut_DrawStyle

Chame esse método para definir o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.

```
HRESULT STDMETHODCALLTYPE put_DrawStyle(LONG pnDrawStyle);
```

### <a name="parameters"></a>parâmetros

*nDrawStyle*<br/>
O novo estilo de desenho para o controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_drawwidth"></a><a name="put_drawwidth"></a> CStockPropImpl::p ut_DrawWidth

Chame esse método para definir a largura (em pixels) usada pelos métodos de desenho do controle.

```
HRESULT STDMETHODCALLTYPE put_DrawWidth(LONG nDrawWidth);
```

### <a name="parameters"></a>parâmetros

*nDrawWidth*<br/>
A nova largura a ser usada pelos métodos de desenho do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_enabled"></a><a name="put_enabled"></a> CStockPropImpl::p ut_Enabled

Chame esse método para definir o valor do sinalizador que indica se o controle está habilitado.

```
HRESULT STDMETHODCALLTYPE put_Enabled(VARIANT_BOOL bEnabled);
```

### <a name="parameters"></a>parâmetros

*bEnabled*<br/>
TRUE se o controle estiver habilitado.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_fillcolor"></a><a name="put_fillcolor"></a> CStockPropImpl::p ut_FillColor

Chame esse método para definir a cor de preenchimento do controle.

```
HRESULT STDMETHODCALLTYPE put_FillColor(OLE_COLOR clrFillColor);
```

### <a name="parameters"></a>parâmetros

*clrFillColor*<br/>
A nova cor de preenchimento do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_fillstyle"></a><a name="put_fillstyle"></a> CStockPropImpl::p ut_FillStyle

Chame esse método para definir o estilo de preenchimento do controle, por exemplo, sólido, transparente ou com hachura cruzada.

```
HRESULT STDMETHODCALLTYPE put_FillStyle(LONG nFillStyle);
```

### <a name="parameters"></a>parâmetros

*nFillStyle*<br/>
O novo estilo de preenchimento para o controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_font"></a><a name="put_font"></a> CStockPropImpl::p ut_Font

Chame esse método para definir as propriedades da fonte do controle.

```
HRESULT STDMETHODCALLTYPE put_Font(IFontDisp* pFont);
```

### <a name="parameters"></a>parâmetros

*pFont*<br/>
Um ponteiro para as propriedades da fonte do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_forecolor"></a><a name="put_forecolor"></a> CStockPropImpl::p ut_ForeColor

Chame esse método para definir a cor de primeiro plano do controle.

```
HRESULT STDMETHODCALLTYPE put_ForeColor(OLE_COLOR clrForeColor);
```

### <a name="parameters"></a>parâmetros

*clrForeColor*<br/>
A nova cor de primeiro plano do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_hwnd"></a><a name="put_hwnd"></a> CStockPropImpl::p ut_HWND

Esse método retorna E_FAIL.

```
HRESULT STDMETHODCALLTYPE put_HWND(LONG_PTR /* hWnd */);
```

### <a name="parameters"></a>parâmetros

*hWnd*<br/>
Reservado.

### <a name="return-value"></a>Valor Retornado

Retorna E_FAIL.

### <a name="remarks"></a>Comentários

O identificador de janela é um valor somente leitura.

## <a name="cstockpropimplput_mouseicon"></a><a name="put_mouseicon"></a> CStockPropImpl::p ut_MouseIcon

Chame esse método para definir as propriedades da imagem do elemento gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse estiver sobre o controle.

```
HRESULT STDMETHODCALLTYPE put_MouseIcon(IPictureDisp* pPicture);
```

### <a name="parameters"></a>parâmetros

*pPicture*<br/>
Um ponteiro para as propriedades da imagem do gráfico.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_mousepointer"></a><a name="put_mousepointer"></a> CStockPropImpl::p ut_MousePointer

Chame esse método para definir o tipo de ponteiro do mouse exibido quando o mouse estiver sobre o controle, por exemplo, seta, cruz ou ampulheta.

```
HRESULT STDMETHODCALLTYPE put_MousePointer(LONG nMousePointer);
```

### <a name="parameters"></a>parâmetros

*nMousePointer*<br/>
O tipo de ponteiro do mouse.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_picture"></a><a name="put_picture"></a> CStockPropImpl::p ut_Picture

Chame esse método para definir as propriedades de imagem de um elemento gráfico (ícone, bitmap ou metarquivo) a ser exibido.

```
HRESULT STDMETHODCALLTYPE put_Picture(IPictureDisp* pPicture);
```

### <a name="parameters"></a>parâmetros

*pPicture*<br/>
Um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](/windows/win32/api/ocidl/nn-ocidl-ipicturedisp) para obter mais detalhes.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_readystate"></a><a name="put_readystate"></a> CStockPropImpl::p ut_ReadyState

Chame esse método para definir o estado pronto do controle, por exemplo, carregando ou carregado.

```
HRESULT STDMETHODCALLTYPE put_ReadyState(LONG nReadyState);
```

### <a name="parameters"></a>parâmetros

*nReadyState*<br/>
O estado pronto do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_tabstop"></a><a name="put_tabstop"></a> CStockPropImpl::p ut_TabStop

Chame esse método para definir o sinalizador que indica se o controle é uma parada de tabulação ou não.

```
HRESULT STDMETHODCALLTYPE put_TabStop(VARIANT_BOOL bTabStop);
```

### <a name="parameters"></a>parâmetros

*bTabStop*<br/>
TRUE se o controle for uma parada de tabulação.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_text"></a><a name="put_text"></a> CStockPropImpl::p ut_Text

Chame esse método para definir o texto que é exibido com o controle.

```
HRESULT STDMETHODCALLTYPE put_Text(BSTR bstrText);
```

### <a name="parameters"></a>parâmetros

*bstrText*<br/>
O texto que é exibido com o controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplputvalid"></a><a name="put_valid"></a> CStockPropImpl::p utvalid

Chame esse método para definir o sinalizador que indica se o controle é válido ou não.

```
HRESULT STDMETHODCALLTYPE getvalid(VARIANT_BOOL bValid);
```

### <a name="parameters"></a>parâmetros

*bValid*<br/>
TRUE se o controle for válido.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="cstockpropimplput_window"></a><a name="put_window"></a> CStockPropImpl::p ut_Window

Esse método chama [CStockPropImpl::p ut_HWND](#put_hwnd), que retorna E_FAIL.

```
HRESULT STDMETHODCALLTYPE put_Window(LONG_PTR hWnd);
```

### <a name="parameters"></a>parâmetros

*hWnd*<br/>
O identificador da janela.

### <a name="return-value"></a>Valor Retornado

Retorna E_FAIL.

### <a name="remarks"></a>Comentários

O identificador de janela é um valor somente leitura.

## <a name="cstockpropimplputref_font"></a><a name="putref_font"></a> CStockPropImpl::p utref_Font

Chame esse método para definir as propriedades de fonte do controle, com uma contagem de referência.

```
HRESULT STDMETHODCALLTYPE putref_Font(IFontDisp* pFont);
```

### <a name="parameters"></a>parâmetros

*pFont*<br/>
Um ponteiro para as propriedades da fonte do controle.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O mesmo que [CStockPropImpl::p ut_Font](#put_font), mas com uma contagem de referência.

## <a name="cstockpropimplputref_mouseicon"></a><a name="putref_mouseicon"></a> CStockPropImpl::p utref_MouseIcon

Chame esse método para definir as propriedades da imagem do elemento gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse estiver sobre o controle, com uma contagem de referência.

```
HRESULT STDMETHODCALLTYPE putref_MouseIcon(IPictureDisp* pPicture);
```

### <a name="parameters"></a>parâmetros

*pPicture*<br/>
Um ponteiro para as propriedades da imagem do gráfico.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O mesmo que [CStockPropImpl::p ut_MouseIcon](#put_mouseicon), mas com uma contagem de referência.

## <a name="cstockpropimplputref_picture"></a><a name="putref_picture"></a> CStockPropImpl::p utref_Picture

Chame esse método para definir as propriedades da imagem de um elemento gráfico (ícone, bitmap ou metarquivo) a ser exibido, com uma contagem de referência.

```
HRESULT STDMETHODCALLTYPE putref_Picture(IPictureDisp* pPicture);
```

### <a name="parameters"></a>parâmetros

*pPicture*<br/>
Um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](/windows/win32/api/ocidl/nn-ocidl-ipicturedisp) para obter mais detalhes.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O mesmo que [CStockPropImpl::p ut_Picture](#put_picture), mas com uma contagem de referência.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)
