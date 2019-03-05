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
ms.openlocfilehash: 90c80dbc5c8b6788f3afad3cf77d796139fbd946
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326641"
---
# <a name="ddxdhtml-helper-macros"></a>Macros auxiliares DDX_DHtml

As macros auxiliares DDX_DHtml permitem o fácil acesso às propriedades de controles em uma página HTML comumente usadas.

### <a name="data-exchange-macros"></a>Macros de troca de dados

|||
|-|-|
|[DDX_DHtml_ElementValue](#ddx_dhtml_elementvalue)|Define ou recupera a propriedade Value do controle selecionado.|
|[DDX_DHtml_ElementInnerText](#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as marcas de início e término do elemento atual.|
|[DDX_DHtml_ElementInnerHtml](#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as marcas de início e término do elemento atual.|
|[DDX_DHtml_Anchor_Href](#ddx_dhtml_anchor_href)|Define ou recupera o destino URL ou ponto de ancoragem.|
|[DDX_DHtml_Anchor_Target](#ddx_dhtml_anchor_target)|Define ou recupera a janela de destino ou quadro.|
|[DDX_DHtml_Img_Src](#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|
|[DDX_DHtml_Frame_Src](#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|
|[DDX_DHtml_IFrame_Src](#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml.h

## <a name="ddx_dhtml_anchor_href"></a> DDX_DHtml_Anchor_Href

Define ou recupera o destino URL ou ponto de ancoragem.

```
DDX_DHtml_Anchor_Href(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLANCHORELEMENT_HREF expedir ID.

## <a name="ddx_dhtml_anchor_target"></a>  DDX_DHtml_Anchor_Target

Define ou recupera a janela de destino ou quadro.

```
DDX_DHtml_Anchor_Target(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLANCHORELEMENT_TARGET expedir ID.

## <a name="ddx_dhtml_elementinnerhtml"></a>  DDX_DHtml_ElementInnerHtml

Define ou recupera o HTML entre as marcas de início e término do elemento atual.

```
DDX_DHtml_ElementInnerHtml(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLELEMENT_INNERHTML expedir ID.

## <a name="ddx_dhtml_elementinnertext"></a>  DDX_DHtml_ElementInnerText

Define ou recupera o texto entre as marcas de início e término do elemento atual.

```
DDX_DHtml_ElementInnerText(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLELEMENT_INNERTEXT expedir ID.

## <a name="ddx_dhtml_elementvalue"></a> DDX_DHtml_ElementValue

Define ou recupera a propriedade Value do controle selecionado.

```
DDX_DHtml_ElementValue(
    CDataExchange* dx,
    LPCTSTR name,
    var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado. Ver *valor* na [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext).

## <a name="remarks"></a>Comentários

Essa macro terá êxito apenas quando executado em controles que têm uma propriedade de valor. Controles que têm uma propriedade de valor incluem caixas de combinação, caixas de listagem e caixas de edição.

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_A_VALUE expedir ID.

## <a name="ddx_dhtml_frame_src"></a> DDX_DHtml_Frame_Src

Define ou recupera a URL do quadro associado.

```
DDX_DHtml_Frame_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLFRAMEBASE_SRC expedir ID.

## <a name="ddx_dhtml_iframe_src"></a> DDX_DHtml_IFrame_Src

Define ou recupera a URL do quadro associado.

```
DDX_DHtml_IFrame_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLFRAMEBASE_SRC expedir ID.

## <a name="ddx_dhtml_img_src"></a>DDX_DHtml_Img_Src

Obtém ou recupera o nome de uma imagem ou um clipe de vídeo no documento.

```
DDX_DHtml_Img_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*dx*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*name*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*var*<br/>
O valor sendo trocado.

## <a name="remarks"></a>Comentários

Ao usar a macro DDX_DHtml_Img_Src para recuperar a propriedade src para um elemento de imagem, o objeto de imagem do Internet Explorer retornará a URL totalmente escape para a origem da imagem. Por exemplo, se você usar a macro DDX_DHtml_Img_Src para definir a propriedade src de um elemento de imagem na cadeia de caracteres "alguns imagem interessante", quando você recuperar essa propriedade, o Internet Explorer retornará a cadeia de caracteres "res://d:\myapplication\myapp.exe/some% 20interesting % 20picture."

Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLIMGELEMENT_SRC expedir ID.

## <a name="see-also"></a>Consulte também

[Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)
