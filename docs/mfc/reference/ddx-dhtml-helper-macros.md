---
title: Macros auxiliares DDX_DHtml
ms.date: 11/04/2016
f1_keywords:
- AFXDHTML/DDX_DHtml_ElementValue
- AFXDHTML/DDX_DHtml_ElementInnerText
- AFXDHTML/DDX_DHtml_ElementInnerHtml
- AFXDHTML/DDX_DHtml_Anchor_Href
- AFXDHTML/DDX_DHtml_Anchor_Target
- AFXDHTML/DDX_DHtml_Img_Src
- AFXDHTML/DDX_DHtml_Frame_Src
- AFXDHTML/DDX_DHtml_IFrame_Src
helpviewer_keywords:
- macros [MFC], exchanging data with HMTL pages
- DDX macros [MFC]
- HTML pages [MFC], helper macros
- DDX (dialog data exchange), DHtml helper macros
- macros [MFC], DDX_DHtml helpers
ms.assetid: c46302d2-ea43-4fea-bfc2-6f590d99f267
ms.openlocfilehash: f78a923a498713867c13ccc88e3e30c1f0a23885
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365867"
---
# <a name="ddx_dhtml-helper-macros"></a>Macros auxiliares DDX_DHtml

As macros auxiliares DDX_DHtml permitem acesso fácil às propriedades comumente usadas dos controles em uma página HTML.

### <a name="data-exchange-macros"></a>Macros de troca de dados

|||
|-|-|
|[DDX_DHtml_ElementValue](#ddx_dhtml_elementvalue)|Define ou recupera a propriedade Valor do controle selecionado.|
|[DDX_DHtml_ElementInnerText](#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as tags inicial e final do elemento atual.|
|[DDX_DHtml_ElementInnerHtml](#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as tags inicial e final do elemento atual.|
|[DDX_DHtml_Anchor_Href](#ddx_dhtml_anchor_href)|Define ou recupera a URL de destino ou ponto de ancoragem.|
|[DDX_DHtml_Anchor_Target](#ddx_dhtml_anchor_target)|Define ou recupera a janela de destino ou o quadro.|
|[DDX_DHtml_Img_Src](#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|
|[DDX_DHtml_Frame_Src](#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|
|[DDX_DHtml_IFrame_Src](#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml.h

## <a name="ddx_dhtml_anchor_href"></a><a name="ddx_dhtml_anchor_href"></a>DDX_DHtml_Anchor_Href

Define ou recupera a URL de destino ou ponto de ancoragem.

```
DDX_DHtml_Anchor_Href(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de despacho de DISPID_IHTMLANCHORELEMENT_HREF.

## <a name="ddx_dhtml_anchor_target"></a><a name="ddx_dhtml_anchor_target"></a>DDX_DHtml_Anchor_Target

Define ou recupera a janela de destino ou o quadro.

```
DDX_DHtml_Anchor_Target(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de expedição DISPID_IHTMLANCHORELEMENT_TARGET.

## <a name="ddx_dhtml_elementinnerhtml"></a><a name="ddx_dhtml_elementinnerhtml"></a>DDX_DHtml_ElementInnerHtml

Define ou recupera o HTML entre as tags inicial e final do elemento atual.

```
DDX_DHtml_ElementInnerHtml(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de despacho DISPID_IHTMLELEMENT_INNERHTML.

## <a name="ddx_dhtml_elementinnertext"></a><a name="ddx_dhtml_elementinnertext"></a>DDX_DHtml_ElementInnerText

Define ou recupera o texto entre as tags inicial e final do elemento atual.

```
DDX_DHtml_ElementInnerText(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de expedição DISPID_IHTMLELEMENT_INNERTEXT.

## <a name="ddx_dhtml_elementvalue"></a><a name="ddx_dhtml_elementvalue"></a>DDX_DHtml_ElementValue

Define ou recupera a propriedade Valor do controle selecionado.

```
DDX_DHtml_ElementValue(
    CDataExchange* dx,
    LPCTSTR name,
    var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado. Veja *o valor* em [CDHtmlDiálogo::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext).

## <a name="remarks"></a>Comentários

Essa macro só terá sucesso quando for executada em controles que tenham uma propriedade Valor. Os controles que possuem uma propriedade Valor incluem caixas de edição, caixas de lista e caixas de combinação.

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de despacho DISPID_A_VALUE.

## <a name="ddx_dhtml_frame_src"></a><a name="ddx_dhtml_frame_src"></a>DDX_DHtml_Frame_Src

Define ou recupera a URL do quadro associado.

```
DDX_DHtml_Frame_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de despacho DISPID_IHTMLFRAMEBASE_SRC.

## <a name="ddx_dhtml_iframe_src"></a><a name="ddx_dhtml_iframe_src"></a>DDX_DHtml_IFrame_Src

Define ou recupera a URL do quadro associado.

```
DDX_DHtml_IFrame_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de despacho DISPID_IHTMLFRAMEBASE_SRC.

## <a name="ddx_dhtml_img_src"></a><a name="ddx_dhtml_img_src"></a>DDX_DHtml_Img_Src

Obtém ou recupera o nome de uma imagem ou um clipe de vídeo no documento.

```
DDX_DHtml_Img_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*Dx*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*name*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Ao usar a DDX_DHtml_Img_Src macro para recuperar a propriedade src para um elemento IMAGE, o objeto de imagem do Internet Explorer retornará a URL totalmente escapada para a fonte de imagem. Por exemplo, se você usar a macro DDX_DHtml_Img_Src para definir a propriedade src de um elemento IMAGE na string "alguma imagem interessante", quando você recuperar essa propriedade, o Internet Explorer retornará a string "res://d:\myapplication\myapp.exe/some%20interessante%20picture".

Esta macro chama a função [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando o ID de expedição DISPID_IHTMLIMGELEMENT_SRC.

## <a name="see-also"></a>Confira também

[Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)
