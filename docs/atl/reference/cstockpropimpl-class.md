---
title: Classe CStockPropImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CStockPropImpl class
- controls [ATL], stock properties
- stock properties, ATL controls
ms.assetid: 45f11d7d-6580-4a0e-872d-3bc8b836cfda
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 366da264f62364a39f6dfe9903a1a19a89266d33
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cstockpropimpl-class"></a>Classe CStockPropImpl
Essa classe fornece métodos para dar suporte a valores de propriedade de estoque.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class InterfaceName,
    const IID* piid = &_ATL_IIDOF(InterfaceName),
    const GUID* plibid = &CComModule::m_libid,
    WORD wMajor = 1,
    WORD wMinor = 0, class tihclass = CcomTypeInfoHolder>  
class ATL_NO_VTABLE CStockPropImpl : public IDispatchImpl<InterfaceName, piid,
 plibid,
    wMajor,
 wMinor,
    tihclass>
```   
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe implementando o controle e derivando de `CStockPropImpl`.  
  
 `InterfaceName`  
 Uma interface dupla expor as propriedades de estoque.  
  
 `piid`  
 Um ponteiro para o IID da `InterfaceName`.  
  
 `plibid`  
 Um ponteiro para a ID da biblioteca da biblioteca de tipos que contém a definição de `InterfaceName`.  
  
 `wMajor`  
 A versão principal da biblioteca de tipos. O valor padrão é 1.  
  
 `wMinor`  
 A versão secundária da biblioteca de tipos. O valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar as informações de tipo de `T`. O valor padrão é `CComTypeInfoHolder`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|[get_Appearance](#get_appearance)|Chame esse método para obter o estilo de pintura usada pelo controle, por exemplo, simples ou 3D.|  
|[get_AutoSize](#get_autosize)|Chame esse método para obter o status do sinalizador que indica se o controle não pode ser qualquer outro tamanho.|  
|[get_BackColor](#get_backcolor)|Chame esse método para obter a cor de plano de fundo do controle.|  
|[get_BackStyle](#get_backstyle)|Chame esse método para obter o estilo de plano de fundo do controle, transparente ou opaco.|  
|[get_BorderColor](#get_bordercolor)|Chame esse método para obter a cor da borda do controle.|  
|[get_BorderStyle](#get_borderstyle)|Chame esse método para obter o estilo da borda do controle.|  
|[get_BorderVisible](#get_bordervisible)|Chame esse método para obter o status do sinalizador que indica se a borda do controle está visível ou não.|  
|[get_BorderWidth](#get_borderwidth)|Chame esse método para obter a largura (em pixels) da borda do controle.|  
|[get_Caption](#get_caption)|Chame esse método para obter o texto especificado em legenda um objeto.|  
|[get_DrawMode](#get_drawmode)|Chame esse método para obter o modo de desenho do controle, por exemplo, XOR caneta ou Inverter cores.|  
|[get_DrawStyle](#get_drawstyle)|Chame esse método para obter o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.|  
|[get_DrawWidth](#get_drawwidth)|Chame esse método para obter a desenho largura (em pixels) usada por métodos de desenho do controle.|  
|[get_Enabled](#get_enabled)|Chame esse método para obter o status do sinalizador que indica se o controle está habilitado.|  
|[get_FillColor](#get_fillcolor)|Chame esse método para obter a cor de preenchimento do controle.|  
|[get_FillStyle](#get_fillstyle)|Chame esse método para obter o estilo de preenchimento do controle, por exemplo, sólido, transparente ou diagonais.|  
|[get_Font](#get_font)|Chame esse método para obter um ponteiro para propriedades de fonte do controle.|  
|[get_ForeColor](#get_forecolor)|Chame esse método para obter a cor de primeiro plano do controle.|  
|[get_HWND](#get_hwnd)|Chame esse método para obter o identificador de janela associado ao controle.|  
|[get_MouseIcon](#get_mouseicon)|Chame esse método para obter as propriedades da imagem do gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse está sobre o controle.|  
|[get_MousePointer](#get_mousepointer)|Chame esse método para obter o tipo de ponteiro de mouse exibido quando o mouse está sobre o controle, por exemplo, seta, cruzada ou ampulheta.|  
|[get_Picture](#get_picture)|Chame esse método para obter um ponteiro para as propriedades da imagem de um gráfico (ícone, bitmap ou metarquivo) a ser exibido.|  
|[get_ReadyState](#get_readystate)|Chame esse método para obter o estado pronto do controle, por exemplo, carregar ou carregado.|  
|[get_TabStop](#get_tabstop)|Chame esse método para obter o sinalizador que indica se o controle é uma parada de tabulação ou não.|  
|[get_Text](#get_text)|Chame esse método para obter o texto que é exibido com o controle.|  
|[getvalid](#get_valid)|Chame esse método para obter o status do sinalizador que indica se o controle é válido ou não.|  
|[get_Window](#get_window)|Chame esse método para obter o identificador de janela associado ao controle. Idêntico ao [CStockPropImpl::get_HWND](#get_hwnd).|  
|[put_Appearance](#put_appearance)|Chame esse método para definir o estilo de pintura usada pelo controle, por exemplo, simples ou 3D.|  
|[put_AutoSize](#put_autosize)|Chame esse método para definir o valor do sinalizador que indica se o controle não pode ser qualquer outro tamanho.|  
|[put_BackColor](#put_backcolor)|Chame esse método para definir a cor de plano de fundo do controle.|  
|[put_BackStyle](#put_backstyle)|Chame esse método para definir o estilo de plano de fundo do controle.|  
|[put_BorderColor](#put_bordercolor)|Chame esse método para definir a cor da borda do controle.|  
|[put_BorderStyle](#put_borderstyle)|Chame esse método para definir o estilo da borda do controle.|  
|[put_BorderVisible](#put_bordervisible)|Chame esse método para definir o valor do sinalizador que indica se a borda do controle está visível ou não.|  
|[put_BorderWidth](#put_borderwidth)|Chame esse método para definir a largura da borda do controle.|  
|[put_Caption](#put_caption)|Chame esse método para definir o texto a ser exibido com o controle.|  
|[put_DrawMode](#put_drawmode)|Chame esse método para definir o modo do controle desenho, por exemplo, XOR caneta ou Inverter cores.|  
|[put_DrawStyle](#put_drawstyle)|Chame esse método para definir o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.|  
|[put_DrawWidth](#put_drawwidth)|Chame esse método para definir a largura (em pixels) usada por métodos de desenho do controle.|  
|[put_Enabled](#put_enabled)|Chame esse método para definir o sinalizador que indica se o controle está habilitado.|  
|[put_FillColor](#put_fillcolor)|Chame esse método para definir a cor de preenchimento do controle.|  
|[put_FillStyle](#put_fillstyle)|Chame esse método para definir o estilo de preenchimento do controle, por exemplo, sólido, transparente ou diagonais.|  
|[put_Font](#put_font)|Chame esse método para definir propriedades da fonte do controle.|  
|[put_ForeColor](#put_forecolor)|Chame esse método para definir a cor de primeiro plano do controle.|  
|[put_HWND](#put_hwnd)|Esse método retornará E_FAIL.|  
|[put_MouseIcon](#put_mouseicon)|Chame esse método para definir as propriedades da imagem do gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse está sobre o controle.|  
|[put_MousePointer](#put_mousepointer)|Chame esse método para definir o tipo de ponteiro de mouse exibido quando o mouse está sobre o controle, por exemplo, seta, cruzada ou ampulheta.|  
|[put_Picture](#put_picture)|Chame esse método para definir as propriedades da imagem de um gráfico (ícone, bitmap ou metarquivo) a ser exibido.|  
|[put_ReadyState](#put_readystate)|Chame esse método para definir o estado pronto do controle, por exemplo, carregar ou carregado.|  
|[put_TabStop](#put_tabstop)|Chame esse método para definir o valor do sinalizador que indica se o controle é uma parada de tabulação ou não.|  
|[put_Text](#put_text)|Chame esse método para definir o texto que é exibido com o controle.|  
|[putvalid](#put_valid)|Chame esse método para definir o sinalizador que indica se o controle é válido ou não.|  
|[put_Window](#put_window)|Esse método chama [CStockPropImpl::put_HWND](#put_hwnd), que retornará E_FAIL.|  
|[putref_Font](#putref_font)|Chame esse método para definir propriedades de fonte do controle, com uma contagem de referência.|  
|[putref_MouseIcon](#putref_mouseicon)|Chame esse método para definir as propriedades da imagem do gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse está sobre o controle, com uma contagem de referência.|  
|[putref_Picture](#putref_picture)|Chame esse método para definir as propriedades da imagem de um gráfico (ícone, bitmap ou metarquivo) a ser exibida, com uma contagem de referência.|  
  
## <a name="remarks"></a>Comentários  
 `CStockPropImpl`Fornece **colocar** e **obter** métodos para cada propriedade de estoque. Esses métodos fornecem o código necessário para definir ou obter o membro de dados associado a cada propriedade para notificar e sincronizar com o contêiner quando qualquer propriedade alterada.  
  
 Visual C++ oferece suporte para propriedades de estoque por meio de seus assistentes. Para obter mais informações sobre como adicionar propriedades de estoque a um controle, consulte o [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md).  
  
 Para compatibilidade com versões anteriores, `CStockPropImpl` também expõe `get_Window` e `put_Window` métodos que simplesmente chamar `get_HWND` e `put_HWND`, respectivamente. A implementação padrão de `put_HWND` retorna **E_FAIL** como `HWND` deve ser uma propriedade somente leitura.  
  
 As propriedades a seguir também tem um **putref** implementação:  
  
-   Fonte  
  
-   MouseIcon  
  
-   Imagem  
  
 As mesmas propriedades de estoque três exigem seu membro de dados correspondente ser do tipo `CComPtr` ou alguma outra classe que fornece a referência de interface correta de contagem por meio do operador de atribuição.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `T`  
  
 [IDispatchImpl](../../atl/reference/idispatchimpl-class.md)  
  
 `CStockPropImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="get_appearance"></a>CStockPropImpl::get_Appearance  
 Chame esse método para obter o estilo de pintura usada pelo controle, por exemplo, simples ou 3D.  
  
```
HRESULT STDMETHODCALLTYPE get_Appearance(SHORT pnAppearance);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnAppearance*  
 Variável que recebe o estilo de pintura do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_autosize"></a>CStockPropImpl::get_AutoSize  
 Chame esse método para obter o status do sinalizador que indica se o controle não pode ser qualquer outro tamanho.  
  
```
HRESULT STDMETHODCALLTYPE get_Autosize(VARIANT_BOOL* pbAutoSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbAutoSize*  
 Variável que recebe o status do sinalizador. TRUE indica que o controle não pode ser qualquer outro tamanho.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_backcolor"></a>CStockPropImpl::get_BackColor  
 Chame esse método para obter a cor de plano de fundo do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_BackColor(OLE_COLOR* pclrBackColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pclrBackColor*  
 Variável que recebe a cor de plano de fundo do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_backstyle"></a>CStockPropImpl::get_BackStyle  
 Chame esse método para obter o estilo de plano de fundo do controle, transparente ou opaco.  
  
```
HRESULT STDMETHODCALLTYPE get_BackStyle(LONG* pnBackStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnBackStyle*  
 Variável que recebe o estilo de plano de fundo do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_bordercolor"></a>CStockPropImpl::get_BorderColor  
 Chame esse método para obter a cor da borda do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_BorderColor(OLE_COLOR* pclrBorderColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pclrBorderColor*  
 Variável que recebe a cor da borda do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_borderstyle"></a>CStockPropImpl::get_BorderStyle  
 Chame esse método para obter o estilo da borda do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_BorderStyle(LONG* pnBorderStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnBorderStyle*  
 Variável que recebe o estilo da borda do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_bordervisible"></a>CStockPropImpl::get_BorderVisible  
 Chame esse método para obter o status do sinalizador que indica se a borda do controle está visível ou não.  
  
```
HRESULT STDMETHODCALLTYPE get_BorderVisible(VARIANT_BOOL* pbBorderVisible);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbBorderVisible*  
 Variável que recebe o status do sinalizador. TRUE indica que a borda do controle está visível.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_borderwidth"></a>CStockPropImpl::get_BorderWidth  
 Chame esse método para obter a largura da borda do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_BorderWidth(LONG* pnBorderWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnBorderWidth*  
 Variável que recebe a largura da borda do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_caption"></a>CStockPropImpl::get_Caption  
 Chame esse método para obter o texto especificado em legenda um objeto.  
  
```
HRESULT STDMETHODCALLTYPE get_Caption(BSTR* pbstrCaption);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbstrCaption*  
 O texto a ser exibido com o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_drawmode"></a>CStockPropImpl::get_DrawMode  
 Chame esse método para obter o modo de desenho do controle, por exemplo, XOR caneta ou Inverter cores.  
  
```
HRESULT STDMETHODCALLTYPE get_DrawMode(LONG* pnDrawMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnDrawMode*  
 Variável que recebe o modo de desenho do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_drawstyle"></a>CStockPropImpl::get_DrawStyle  
 Chame esse método para obter o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.  
  
```
HRESULT STDMETHODCALLTYPE get_DrawStyle(LONG* pnDrawStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnDrawStyle*  
 Variável que recebe o estilo de desenho do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_drawwidth"></a>CStockPropImpl::get_DrawWidth  
 Chame esse método para obter a desenho largura (em pixels) usada por métodos de desenho do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_DrawWidth(LONG* pnDrawWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnDrawWidth*  
 Variável que recebe o valor do controle largura, em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_enabled"></a>CStockPropImpl::get_Enabled  
 Chame esse método para obter o status do sinalizador que indica se o controle está habilitado.  
  
```
HRESULT STDMETHODCALLTYPE get_Enabled(VARIANT_BOOL* pbEnabled);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbEnabled`  
 Variável que recebe o status do sinalizador. TRUE indica que o controle está habilitado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_fillcolor"></a>CStockPropImpl::get_FillColor  
 Chame esse método para obter a cor de preenchimento do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_FillColor(OLE_COLOR* pclrFillColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pclrFillColor*  
 Variável que recebe a cor de preenchimento do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_fillstyle"></a>CStockPropImpl::get_FillStyle  
 Chame esse método para obter o estilo de preenchimento do controle, por exemplo, sólido, transparente ou crosshatched.  
  
```
HRESULT STDMETHODCALLTYPE get_FillStyle(LONG* pnFillStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnFillStyle*  
 Variável que recebe o estilo de preenchimento do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_font"></a>CStockPropImpl::get_Font  
 Chame esse método para obter um ponteiro para propriedades de fonte do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_Font(IFontDisp** ppFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppFont`  
 Variável que recebe um ponteiro para propriedades de fonte do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_forecolor"></a>CStockPropImpl::get_ForeColor  
 Chame esse método para obter a cor de primeiro plano do controle.  
  
```
HRESULT STDMETHODCALLTYPE get_ForeColor(OLE_COLOR* pclrForeColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pclrForeColor*  
 Variável que recebe a cor de primeiro plano de controles.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_hwnd"></a>CStockPropImpl::get_HWND  
 Chame esse método para obter o identificador de janela associado ao controle.  
  
```
HRESULT STDMETHODCALLTYPE get_HWND(LONG_PTR* phWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `phWnd`  
 O identificador de janela associado ao controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_mouseicon"></a>CStockPropImpl::get_MouseIcon  
 Chame esse método para obter as propriedades da imagem do gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse está sobre o controle.  
  
```
HRESULT STDMETHODCALLTYPE get_MouseIcon(IPictureDisp** ppPicture);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppPicture`  
 Variável que recebe um ponteiro para as propriedades da imagem do gráfico.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_mousepointer"></a>CStockPropImpl::get_MousePointer  
 Chame esse método para obter o tipo de ponteiro de mouse exibido quando o mouse está sobre o controle, por exemplo, seta, cruzada ou ampulheta.  
  
```
HRESULT STDMETHODCALLTYPE get_MousePointer(LONG* pnMousePointer);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnMousePointer*  
 Variável que recebe o tipo de ponteiro de mouse.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_picture"></a>CStockPropImpl::get_Picture  
 Chame esse método para obter um ponteiro para as propriedades da imagem de um gráfico (ícone, bitmap ou metarquivo) a ser exibido.  
  
```
HRESULT STDMETHODCALLTYPE get_Picture(IPictureDisp** ppPicture);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppPicture`  
 Variável que recebe um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](http://msdn.microsoft.com/library/windows/desktop/ms680762) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_readystate"></a>CStockPropImpl::get_ReadyState  
 Chame esse método para obter o estado pronto do controle, por exemplo, carregar ou carregado.  
  
```
HRESULT STDMETHODCALLTYPE get_ReadyState(LONG* pnReadyState);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnReadyState*  
 Variável que recebe o estado pronto do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_tabstop"></a>CStockPropImpl::get_TabStop  
 Chame esse método para obter o status do sinalizador que indica se o controle é uma parada de tabulação ou não.  
  
```
HRESULT STDMETHODCALLTYPE get_TabStop(VARIANT_BOOL* pbTabStop);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbTabStop*  
 Variável que recebe o status do sinalizador. TRUE indica que o controle é uma parada de tabulação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_text"></a>CStockPropImpl::get_Text  
 Chame esse método para obter o texto que é exibido com o controle.  
  
```
HRESULT STDMETHODCALLTYPE get_Text(BSTR* pbstrText);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbstrText*  
 O texto que é exibido com o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_valid"></a>CStockPropImpl::getvalid  
 Chame esse método para obter o status do sinalizador que indica se o controle é válido ou não.  
  
```
HRESULT STDMETHODCALLTYPE getvalid(VARIANT_BOOL* pbValid);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbValid*  
 Variável que recebe o status do sinalizador. TRUE indica que o controle é válido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="get_window"></a>CStockPropImpl::get_Window  
 Chame esse método para obter o identificador de janela associado ao controle. Idêntico ao [CStockPropImpl::get_HWND](#get_hwnd).  
  
```
HRESULT STDMETHODCALLTYPE get_Window(LONG_PTR* phWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `phWnd`  
 O identificador de janela associado ao controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_appearance"></a>CStockPropImpl::put_Appearance  
 Chame esse método para definir o estilo de pintura usada pelo controle, por exemplo, simples ou 3D.  
  
```
HRESULT STDMETHODCALLTYPE put_Appearance(SHORT nAppearance);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nAppearance`  
 O novo estilo de pintura a ser usado pelo controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_autosize"></a>CStockPropImpl::put_AutoSize  
 Chame esse método para definir o valor de sinalizador que indica se o controle não pode ser qualquer outro tamanho.  
  
```
HRESULT STDMETHODCALLTYPE put_AutoSize(VARIANT_BOOL bAutoSize,);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAutoSize*  
 TRUE se o controle não pode ser qualquer outro tamanho.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_backcolor"></a>CStockPropImpl::put_BackColor  
 Chame esse método para definir a cor de plano de fundo do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_BackColor(OLE_COLOR clrBackColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clrBackColor*  
 A nova cor de plano de fundo do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_backstyle"></a>CStockPropImpl::put_BackStyle  
 Chame esse método para definir o estilo de plano de fundo do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_BackStyle(LONG nBackStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBackStyle*  
 O novo estilo de plano de fundo do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_bordercolor"></a>CStockPropImpl::put_BorderColor  
 Chame esse método para definir a cor da borda do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_BorderColor(OLE_COLOR clrBorderColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clrBorderColor*  
 A nova cor de borda. O tipo de dados OLE_COLOR é representado internamente como um inteiro longo de 32 bits.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_borderstyle"></a>CStockPropImpl::put_BorderStyle  
 Chame esse método para definir o estilo da borda do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_BorderStyle(LONG nBorderStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBorderStyle*  
 O novo estilo de borda.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_bordervisible"></a>CStockPropImpl::put_BorderVisible  
 Chame esse método para definir o valor do sinalizador que indica se a borda do controle está visível ou não.  
  
```
HRESULT STDMETHODCALLTYPE put_BorderVisible(VARIANT_BOOL bBorderVisible);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bBorderVisible*  
 TRUE se a borda deve ser visível.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_borderwidth"></a>CStockPropImpl::put_BorderWidth  
 Chame esse método para definir a largura da borda do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_BorderWidth(LONG nBorderWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBorderWidth`  
 A nova largura da borda do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_caption"></a>CStockPropImpl::put_Caption  
 Chame esse método para definir o texto a ser exibido com o controle.  
  
```
HRESULT STDMETHODCALLTYPE put_Caption(BSTR bstrCaption);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bstrCaption*  
 O texto a ser exibido com o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_drawmode"></a>CStockPropImpl::put_DrawMode  
 Chame esse método para definir o modo do controle desenho, por exemplo, XOR caneta ou Inverter cores.  
  
```
HRESULT STDMETHODCALLTYPE put_DrawMode(LONG nDrawMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nDrawMode`  
 O novo modo de desenho do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_drawstyle"></a>CStockPropImpl::put_DrawStyle  
 Chame esse método para definir o estilo de desenho do controle, por exemplo, sólido, tracejado ou pontilhado.  
  
```
HRESULT STDMETHODCALLTYPE put_DrawStyle(LONG pnDrawStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDrawStyle*  
 O novo estilo de desenho do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_drawwidth"></a>CStockPropImpl::put_DrawWidth  
 Chame esse método para definir a largura (em pixels) usada por métodos de desenho do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_DrawWidth(LONG nDrawWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDrawWidth*  
 A nova largura a ser usado pelo controle de métodos de desenho.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_enabled"></a>CStockPropImpl::put_Enabled  
 Chame esse método para definir o valor do sinalizador que indica se o controle está habilitado.  
  
```
HRESULT STDMETHODCALLTYPE put_Enabled(VARIANT_BOOL bEnabled);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnabled`  
 TRUE se o controle está habilitado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_fillcolor"></a>CStockPropImpl::put_FillColor  
 Chame esse método para definir a cor de preenchimento do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_FillColor(OLE_COLOR clrFillColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clrFillColor*  
 A nova cor de preenchimento do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_fillstyle"></a>CStockPropImpl::put_FillStyle  
 Chame esse método para definir o estilo de preenchimento do controle, por exemplo, sólido, transparente ou diagonais.  
  
```
HRESULT STDMETHODCALLTYPE put_FillStyle(LONG nFillStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nFillStyle*  
 O novo estilo de preenchimento para o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_font"></a>CStockPropImpl::put_Font  
 Chame esse método para definir propriedades da fonte do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_Font(IFontDisp* pFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFont`  
 Um ponteiro para propriedades de fonte do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_forecolor"></a>CStockPropImpl::put_ForeColor  
 Chame esse método para definir a cor de primeiro plano do controle.  
  
```
HRESULT STDMETHODCALLTYPE put_ForeColor(OLE_COLOR clrForeColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clrForeColor*  
 A nova cor de primeiro plano do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_hwnd"></a>CStockPropImpl::put_HWND  
 Esse método retornará E_FAIL.  
  
```
HRESULT STDMETHODCALLTYPE put_HWND(LONG_PTR /* hWnd */);
```  
  
### <a name="parameters"></a>Parâmetros  
 */\*hWnd\*/*  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_FAIL.  
  
### <a name="remarks"></a>Comentários  
 O identificador de janela é um valor somente leitura.  
  
##  <a name="put_mouseicon"></a>CStockPropImpl::put_MouseIcon  
 Chame esse método para definir as propriedades da imagem do gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse está sobre o controle.  
  
```
HRESULT STDMETHODCALLTYPE put_MouseIcon(IPictureDisp* pPicture);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPicture`  
 Um ponteiro para as propriedades da imagem do gráfico.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_mousepointer"></a>CStockPropImpl::put_MousePointer  
 Chame esse método para definir o tipo de ponteiro de mouse exibido quando o mouse está sobre o controle, por exemplo, seta, cruzada ou ampulheta.  
  
```
HRESULT STDMETHODCALLTYPE put_MousePointer(LONG nMousePointer);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nMousePointer*  
 O tipo de ponteiro do mouse.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_picture"></a>CStockPropImpl::put_Picture  
 Chame esse método para definir as propriedades da imagem de um gráfico (ícone, bitmap ou metarquivo) a ser exibido.  
  
```
HRESULT STDMETHODCALLTYPE put_Picture(IPictureDisp* pPicture);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPicture`  
 Um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](http://msdn.microsoft.com/library/windows/desktop/ms680762) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_readystate"></a>CStockPropImpl::put_ReadyState  
 Chame esse método para definir o estado pronto do controle, por exemplo, carregar ou carregado.  
  
```
HRESULT STDMETHODCALLTYPE put_ReadyState(LONG nReadyState);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nReadyState*  
 O estado do controle pronto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_tabstop"></a>CStockPropImpl::put_TabStop  
 Chame esse método para definir o sinalizador que indica se o controle é uma parada de tabulação ou não.  
  
```
HRESULT STDMETHODCALLTYPE put_TabStop(VARIANT_BOOL bTabStop);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bTabStop*  
 TRUE se o controle é uma parada de tabulação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_text"></a>CStockPropImpl::put_Text  
 Chame esse método para definir o texto que é exibido com o controle.  
  
```
HRESULT STDMETHODCALLTYPE put_Text(BSTR bstrText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrText`  
 O texto que é exibido com o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_valid"></a>CStockPropImpl::putvalid  
 Chame esse método para definir o sinalizador que indica se o controle é válido ou não.  
  
```
HRESULT STDMETHODCALLTYPE getvalid(VARIANT_BOOL bValid);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bValid*  
 TRUE se o controle é válido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="put_window"></a>CStockPropImpl::put_Window  
 Esse método chama [CStockPropImpl::put_HWND](#put_hwnd), que retornará E_FAIL.  
  
```
HRESULT STDMETHODCALLTYPE put_Window(LONG_PTR hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 O identificador da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_FAIL.  
  
### <a name="remarks"></a>Comentários  
 O identificador de janela é um valor somente leitura.  
  
##  <a name="putref_font"></a>CStockPropImpl::putref_Font  
 Chame esse método para definir propriedades de fonte do controle, com uma contagem de referência.  
  
```
HRESULT STDMETHODCALLTYPE putref_Font(IFontDisp* pFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFont`  
 Um ponteiro para propriedades de fonte do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O mesmo que [CStockPropImpl::put_Font](#put_font), mas com uma contagem de referência.  
  
##  <a name="putref_mouseicon"></a>CStockPropImpl::putref_MouseIcon  
 Chame esse método para definir as propriedades da imagem do gráfico (ícone, bitmap ou metarquivo) a ser exibida quando o mouse está sobre o controle, com uma contagem de referência.  
  
```
HRESULT STDMETHODCALLTYPE putref_MouseIcon(IPictureDisp* pPicture);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPicture`  
 Um ponteiro para as propriedades da imagem do gráfico.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O mesmo que [CStockPropImpl::put_MouseIcon](#put_mouseicon), mas com uma contagem de referência.  
  
##  <a name="putref_picture"></a>CStockPropImpl::putref_Picture  
 Chame esse método para definir as propriedades da imagem de um gráfico (ícone, bitmap ou metarquivo) a ser exibida, com uma contagem de referência.  
  
```
HRESULT STDMETHODCALLTYPE putref_Picture(IPictureDisp* pPicture);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPicture`  
 Um ponteiro para as propriedades da imagem. Consulte [IPictureDisp](http://msdn.microsoft.com/library/windows/desktop/ms680762) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O mesmo que [CStockPropImpl::put_Picture](#put_picture), mas com uma contagem de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)

