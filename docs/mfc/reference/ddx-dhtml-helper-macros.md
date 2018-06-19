---
title: Macros de auxiliar DDX_DHtml | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- AFXDHTML/DDX_DHtml_ElementValue
- AFXDHTML/DDX_DHtml_ElementInnerText
- AFXDHTML/DDX_DHtml_ElementInnerHtml
- AFXDHTML/DDX_DHtml_Anchor_Href
- AFXDHTML/DDX_DHtml_Anchor_Target
- AFXDHTML/DDX_DHtml_Img_Src
- AFXDHTML/DDX_DHtml_Frame_Src
- AFXDHTML/DDX_DHtml_IFrame_Src
dev_langs:
- C++
helpviewer_keywords:
- macros [MFC], exchanging data with HMTL pages
- DDX macros [MFC]
- HTML pages [MFC], helper macros
- DDX (dialog data exchange), DHtml helper macros
- macros [MFC], DDX_DHtml helpers
ms.assetid: c46302d2-ea43-4fea-bfc2-6f590d99f267
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb2e9d2494463b502fda85c03fa1b861e1182cfc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33372069"
---
# <a name="ddxdhtml-helper-macros"></a>Macros de auxiliar DDX_DHtml
As macros de auxiliar DDX_DHtml permitem acesso fácil para as propriedades utilizadas de controles em uma página HTML.  
  
### <a name="data-exchange-macros"></a>Macros de troca de dados  
  
|||  
|-|-|  
|[DDX_DHtml_ElementValue](#ddx_dhtml_elementvalue)|Define ou recupera a propriedade valor do controle selecionado.|  
|[DDX_DHtml_ElementInnerText](#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as marcas de início e término do elemento atual.|  
|[DDX_DHtml_ElementInnerHtml](#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as marcas de início e término do elemento atual.|  
|[DDX_DHtml_Anchor_Href](#ddx_dhtml_anchor_href)|Define ou recupera o ponto de ancoragem ou de URL de destino.|  
|[DDX_DHtml_Anchor_Target](#ddx_dhtml_anchor_target)|Define ou recupera o quadro ou janela de destino.|  
|[DDX_DHtml_Img_Src](#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|  
|[DDX_DHtml_Frame_Src](#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|  
|[DDX_DHtml_IFrame_Src](#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdhtml.h  

## <a name="ddx_dhtml_anchor_href"></a> DDX_DHtml_Anchor_Href
Define ou recupera o ponto de ancoragem ou de URL de destino.  
  
  
  
```  
DDX_DHtml_Anchor_Href(
    CDataExchange* dx,  
    LPCTSTR name,  
    CString& var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado.  
  
## <a name="remarks"></a>Comentários  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLANCHORELEMENT_HREF expedição ID.

## <a name="ddx_dhtml_anchor_target"></a>  DDX_DHtml_Anchor_Target
 Define ou recupera o quadro ou janela de destino.  
    
```  
DDX_DHtml_Anchor_Target(
    CDataExchange* dx,  
    LPCTSTR name,  
    CString& var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado.  
  
## <a name="remarks"></a>Comentários  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLANCHORELEMENT_TARGET expedição ID.  

## <a name="ddx_dhtml_elementinnerhtml"></a>  DDX_DHtml_ElementInnerHtml
 Define ou recupera o HTML entre as marcas de início e término do elemento atual.  
  
  
  
```  
DDX_DHtml_ElementInnerHtml(
    CDataExchange* dx,  
    LPCTSTR name,  
    CString& var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado.  
  
## <a name="remarks"></a>Comentários  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLELEMENT_INNERHTML expedição ID.  
  

## <a name="ddx_dhtml_elementinnertext"></a>  DDX_DHtml_ElementInnerText
Define ou recupera o texto entre as marcas de início e término do elemento atual.  
  
  
  
```  
DDX_DHtml_ElementInnerText(
    CDataExchange* dx,  
    LPCTSTR name,  
    CString& var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado.  
  
## <a name="remarks"></a>Comentários  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLELEMENT_INNERTEXT expedição ID. 

## <a name="ddx_dhtml_elementvalue"></a> DDX_DHtml_ElementValue  
Define ou recupera a propriedade valor do controle selecionado.  
 
```  
DDX_DHtml_ElementValue(
    CDataExchange* dx,  
    LPCTSTR name,
    var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado. Consulte *valor* na [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext).  
  
## <a name="remarks"></a>Comentários  
 Esta macro terá êxito apenas quando executado em controles que têm uma propriedade de valor. Controles que têm uma propriedade de valor incluem caixas de edição, caixas de listagem e caixas de combinação.  
  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_A_VALUE expedição ID.  

## <a name="ddx_dhtml_frame_src"></a> DDX_DHtml_Frame_Src
Define ou recupera a URL do quadro associado.  
  
```  
DDX_DHtml_Frame_Src(
    CDataExchange* dx,  
    LPCTSTR name,  
    CString& var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado.  
  
## <a name="remarks"></a>Comentários  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLFRAMEBASE_SRC expedição ID.  

## <a name="ddx_dhtml_iframe_src"></a> DDX_DHtml_IFrame_Src
Define ou recupera a URL do quadro associado.  
  
  
  
```  
DDX_DHtml_IFrame_Src(
    CDataExchange* dx,  
    LPCTSTR name,  
    CString& var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado.  
  
## <a name="remarks"></a>Comentários  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLFRAMEBASE_SRC expedição ID. 

## <a name="ddx_dhtml_img_src"></a>DDX_DHtml_Img_Src
Obtém ou recupera o nome de uma imagem ou um clipe de vídeo no documento.  
  
```  
DDX_DHtml_Img_Src(
    CDataExchange* dx,  
    LPCTSTR name,  
    CString& var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dx`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `name`  
 O valor especificado para o parâmetro de ID do controle HTML.  
  
 `var`  
 O valor que está sendo trocado.  
  
## <a name="remarks"></a>Comentários  
 Ao usar o `DDX_DHtml_Img_Src` macro ao recuperar a propriedade de origem para um elemento de imagem, o objeto de imagem do Internet Explorer retornará a URL totalmente escape para a origem da imagem. Por exemplo, se você usar o `DDX_DHtml_Img_Src` macro para definir a propriedade src de um elemento de imagem para a cadeia de caracteres "alguns imagem interessante," quando você recuperar essa propriedade, o Internet Explorer retornará a cadeia de caracteres "res://d:\myapplication\myapp.exe/some% 20interesting % 20picture."  
  
 Esta macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLIMGELEMENT_SRC expedição ID.  

  
## <a name="see-also"></a>Consulte também  
 [Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)
