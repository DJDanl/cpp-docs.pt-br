---
title: DDX_DHtml macros auxiliares
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
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866651"
---
# <a name="ddx_dhtml-helper-macros"></a>DDX_DHtml macros auxiliares

As macros auxiliares DDX_DHtml permitem acesso fácil às propriedades de controles geralmente usadas em uma página HTML.

### <a name="data-exchange-macros"></a>Macros de troca de dados

|||
|-|-|
|[DDX_DHtml_ElementValue](#ddx_dhtml_elementvalue)|Define ou recupera a propriedade Value do controle selecionado.|
|[DDX_DHtml_ElementInnerText](#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as marcas de início e de fim do elemento atual.|
|[DDX_DHtml_ElementInnerHtml](#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as marcas de início e de fim do elemento atual.|
|[DDX_DHtml_Anchor_Href](#ddx_dhtml_anchor_href)|Define ou recupera a URL de destino ou o ponto de ancoragem.|
|[DDX_DHtml_Anchor_Target](#ddx_dhtml_anchor_target)|Define ou recupera a janela ou o quadro de destino.|
|[DDX_DHtml_Img_Src](#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|
|[DDX_DHtml_Frame_Src](#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|
|[DDX_DHtml_IFrame_Src](#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxdhtml. h

## <a name="ddx_dhtml_anchor_href"></a>DDX_DHtml_Anchor_Href

Define ou recupera a URL de destino ou o ponto de ancoragem.

```
DDX_DHtml_Anchor_Href(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_IHTMLANCHORELEMENT_HREF.

## <a name="ddx_dhtml_anchor_target"></a>DDX_DHtml_Anchor_Target

Define ou recupera a janela ou o quadro de destino.

```
DDX_DHtml_Anchor_Target(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_IHTMLANCHORELEMENT_TARGET.

## <a name="ddx_dhtml_elementinnerhtml"></a>DDX_DHtml_ElementInnerHtml

Define ou recupera o HTML entre as marcas de início e de fim do elemento atual.

```
DDX_DHtml_ElementInnerHtml(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_IHTMLELEMENT_INNERHTML.

## <a name="ddx_dhtml_elementinnertext"></a>DDX_DHtml_ElementInnerText

Define ou recupera o texto entre as marcas de início e de fim do elemento atual.

```
DDX_DHtml_ElementInnerText(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_IHTMLELEMENT_INNERTEXT.

## <a name="ddx_dhtml_elementvalue"></a>DDX_DHtml_ElementValue

Define ou recupera a propriedade Value do controle selecionado.

```
DDX_DHtml_ElementValue(
    CDataExchange* dx,
    LPCTSTR name,
    var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado. Confira o *valor* em [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext).

## <a name="remarks"></a>Comentários

Essa macro só terá sucesso quando executada em controles que tenham uma propriedade Value. Controles que têm uma propriedade Value incluem caixas de edição, caixas de listagem e caixas de combinação.

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_A_VALUE.

## <a name="ddx_dhtml_frame_src"></a>DDX_DHtml_Frame_Src

Define ou recupera a URL do quadro associado.

```
DDX_DHtml_Frame_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_IHTMLFRAMEBASE_SRC.

## <a name="ddx_dhtml_iframe_src"></a>DDX_DHtml_IFrame_Src

Define ou recupera a URL do quadro associado.

```
DDX_DHtml_IFrame_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_IHTMLFRAMEBASE_SRC.

## <a name="ddx_dhtml_img_src"></a>DDX_DHtml_Img_Src

Obtém ou recupera o nome de uma imagem ou um clipe de vídeo no documento.

```
DDX_DHtml_Img_Src(
    CDataExchange* dx,
    LPCTSTR name,
    CString& var)
```

#### <a name="parameters"></a>Parâmetros

*DX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*name*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*var*<br/>
O valor que está sendo trocado.

## <a name="remarks"></a>Comentários

Ao usar a macro DDX_DHtml_Img_Src para recuperar a propriedade src para um elemento IMAGE, o objeto de imagem do Internet Explorer retornará a URL de saída completa para a origem da imagem. Por exemplo, se você usar a macro DDX_DHtml_Img_Src para definir a propriedade src de um elemento IMAGE como a cadeia de caracteres "alguma imagem interessante", quando você recuperar essa propriedade, o Internet Explorer retornará a cadeia de caracteres "res: nó//d: \ MyApplication \ MyApp. exe/some %2 0, %2 0 de imagem interessante".

Essa macro chama a função [CDHtmlDialog::D DX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) usando a ID de expedição DISPID_IHTMLIMGELEMENT_SRC.

## <a name="see-also"></a>Consulte também

[Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)
