---
title: Macros de auxiliar DDX_DHtml | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- DDX_DHtml
dev_langs:
- C++
helpviewer_keywords:
- macros, exchanging data with HMTL pages
- DDX macros
- HTML pages, helper macros
- DDX (dialog data exchange), DHtml helper macros
- macros, DDX_DHtml helpers
ms.assetid: c46302d2-ea43-4fea-bfc2-6f590d99f267
caps.latest.revision: 14
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: d3c5136b52206a1ec67e1e1fc78ec291a2954faf
ms.lasthandoff: 02/25/2017

---
# <a name="ddxdhtml-helper-macros"></a>DDX_DHtml auxiliar Macros
As macros de auxiliar DDX_DHtml permitem o fácil acesso às propriedades dos controles em uma página HTML comumente usadas.  
  
### <a name="data-exchange-macros"></a>Dados Exchange Macros  
  
|||  
|-|-|  
|[DDX_DHtml_ElementValue](#ddx_dhtml_elementvalue)|Define ou recupera a propriedade Value do controle selecionado.|  
|[DDX_DHtml_ElementInnerText](#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as marcas de início e término do elemento atual.|  
|[DDX_DHtml_ElementInnerHtml](#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as marcas de início e término do elemento atual.|  
|[DDX_DHtml_Anchor_Href](#ddx_dhtml_anchor_href)|Define ou recupera o ponto de ancoragem ou URL de destino.|  
|[DDX_DHtml_Anchor_Target](#ddx_dhtml_anchor_target)|Define ou recupera a janela de destino ou quadro.|  
|[DDX_DHtml_Img_Src](#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|  
|[DDX_DHtml_Frame_Src](#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|  
|[DDX_DHtml_IFrame_Src](#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdhtml.h  

## <a name="a-nameddxdhtmlanchorhrefa-ddxdhtmlanchorhref"></a><a name="ddx_dhtml_anchor_href"></a>DDX_DHtml_Anchor_Href
Define ou recupera o ponto de ancoragem ou URL de destino.  
  
  
  
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
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLANCHORELEMENT_HREF expedição ID.

## <a name="a-nameddxdhtmlanchortargeta--ddxdhtmlanchortarget"></a><a name="ddx_dhtml_anchor_target"></a>DDX_DHtml_Anchor_Target
 Define ou recupera a janela de destino ou quadro.  
    
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
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLANCHORELEMENT_TARGET expedição ID.  

## <a name="a-nameddxdhtmlelementinnerhtmla--ddxdhtmlelementinnerhtml"></a><a name="ddx_dhtml_elementinnerhtml"></a>DDX_DHtml_ElementInnerHtml
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
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLELEMENT_INNERHTML expedição ID.  
  

## <a name="a-nameddxdhtmlelementinnertexta--ddxdhtmlelementinnertext"></a><a name="ddx_dhtml_elementinnertext"></a>DDX_DHtml_ElementInnerText
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
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLELEMENT_INNERTEXT expedição ID. 

## <a name="a-nameddxdhtmlelementvaluea-ddxdhtmlelementvalue"></a><a name="ddx_dhtml_elementvalue"></a>DDX_DHtml_ElementValue  
Define ou recupera a propriedade Value do controle selecionado.  
 
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
 Essa macro só terá êxito quando executado em controles que tenham uma propriedade de valor. Controles que tenham uma propriedade de valor incluem caixas de edição, caixas de listagem e caixas de combinação.  
  
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_A_VALUE expedição ID.  

## <a name="a-nameddxdhtmlframesrca-ddxdhtmlframesrc"></a><a name="ddx_dhtml_frame_src"></a>DDX_DHtml_Frame_Src
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
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLFRAMEBASE_SRC expedição ID.  

## <a name="a-nameddxdhtmliframesrca-ddxdhtmliframesrc"></a><a name="ddx_dhtml_iframe_src"></a>DDX_DHtml_IFrame_Src
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
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLFRAMEBASE_SRC expedição ID. 

## <a name="a-nameddxdhtmlimgsrcaddxdhtmlimgsrc"></a><a name="ddx_dhtml_img_src"></a>DDX_DHtml_Img_Src
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
 Ao usar o `DDX_DHtml_Img_Src` macro ao recuperar a propriedade src para um elemento de imagem, o objeto de imagem do Internet Explorer irá retornar a URL totalmente escape para a origem da imagem. Por exemplo, se você usar o `DDX_DHtml_Img_Src` macro para definir a propriedade src de um elemento de imagem à cadeia de caracteres "algumas imagens interessantes", quando você recupera essa propriedade, o Internet Explorer retornará a cadeia de caracteres "res://d:\myapplication\myapp.exe/some%20interesting%20picture".  
  
 Essa macro chama o [CDHtmlDialog::DDX_DHtml_ElementText](../../mfc/reference/cdhtmldialog-class.md#ddx_dhtml_elementtext) função usando o DISPID_IHTMLIMGELEMENT_SRC expedição ID.  

  
## <a name="see-also"></a>Consulte também  
 [Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)

