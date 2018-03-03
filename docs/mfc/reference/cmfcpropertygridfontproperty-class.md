---
title: Classe CMFCPropertyGridFontProperty | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCPropertyGridFontProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty::CMFCPropertyGridFontProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty::GetColor
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty::GetLogFont
dev_langs:
- C++
helpviewer_keywords:
- CMFCPropertyGridFontProperty [MFC], CMFCPropertyGridFontProperty
- CMFCPropertyGridFontProperty [MFC], GetColor
- CMFCPropertyGridFontProperty [MFC], GetLogFont
ms.assetid: 83693f33-bbd3-4fcb-a9ad-fa79fcf2ca24
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 505f48bcfb867ae8444d8dbbee360bb04e23d8e5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcpropertygridfontproperty-class"></a>Classe CMFCPropertyGridFontProperty
O `CMFCPropertyGridFileProperty` classe oferece suporte a um item de controle de lista de propriedade que abre uma caixa de diálogo de seleção de fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCPropertyGridFontProperty : public CMFCPropertyGridProperty  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPropertyGridFontProperty::CMFCPropertyGridFontProperty](#cmfcpropertygridfontproperty)|Constrói um objeto `CMFCPropertyGridFontProperty`.|  
|`CMFCPropertyGridFontProperty::~CMFCPropertyGridFontProperty`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCPropertyGridFontProperty::FormatProperty`|Formata a representação de texto de um valor de propriedade. (Substitui [CMFCPropertyGridProperty::FormatProperty](../../mfc/reference/cmfcpropertygridproperty-class.md#formatproperty).)|  
|[CMFCPropertyGridFontProperty::GetColor](#getcolor)|Recupera a cor da fonte que o usuário seleciona na caixa de diálogo de fonte.|  
|[CMFCPropertyGridFontProperty::GetLogFont](#getlogfont)|Recupera a fonte que o usuário seleciona na caixa de diálogo de fonte.|  
|`CMFCPropertyGridFontProperty::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|`CMFCPropertyGridFontProperty::OnClickButton`|Chamado pelo framework quando o usuário clica em um botão que está contido em uma propriedade. (Substitui [CMFCPropertyGridProperty::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|  
  
## <a name="remarks"></a>Comentários  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)  
  
 [CMFCPropertyGridFontProperty](../../mfc/reference/cmfcpropertygridfontproperty-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpropertygridctrl.h  
  
##  <a name="cmfcpropertygridfontproperty"></a>CMFCPropertyGridFontProperty::CMFCPropertyGridFontProperty  
 Constrói um objeto `CMFCPropertyGridFontProperty`.  
  
```  
CMFCPropertyGridFontProperty(
    const CString& strName,  
    LOGFONT& lf,  
    DWORD dwFontDialogFlags = CF_EFFECTS | CF_SCREENFONTS,  
    LPCTSTR lpszDescr = NULL,  
    DWORD_PTR dwData = 0,  
    COLORREF color = (COLORREF)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strName`  
 O nome da propriedade.  
  
 [in] `lf`  
 Uma estrutura de fonte lógica que especifica os atributos da fonte.  
  
 [in] `dwFontDialogFlags`  
 Estilos que são aplicados à caixa de diálogo de fonte que é exibida quando você clicar no botão de menu suspenso de valor de propriedade. O valor padrão é a combinação de bit a bit (ou) de CF_EFFECTS e CF_SCREENFONTS. Para obter mais informações, consulte o `Flags` parâmetro o [CHOOSEFONT estrutura](http://msdn.microsoft.com/library/windows/desktop/ms646832).  
  
 [in] `lpszDescr`  
 Descrição da propriedade font. O valor padrão é `NULL`.  
  
 [in] `dwData`  
 Dados específicos do aplicativo, como um inteiro ou um ponteiro para outros dados que está associados com a propriedade. O valor padrão é 0.  
  
 [in] `color`  
 A cor da fonte. O valor padrão é a cor padrão.  
  
### <a name="remarks"></a>Comentários  
 Um `CMFCPropertyGridFontProperty` objeto representa uma propriedade de fonte em um controle de fonte de grade de propriedade.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCPropertyGridFontProperty` classe. Este exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#26](../../mfc/reference/codesnippet/cpp/cmfcpropertygridfontproperty-class_1.cpp)]  
  
##  <a name="getcolor"></a>CMFCPropertyGridFontProperty::GetColor  
 Recupera a cor da fonte que o usuário seleciona na caixa de diálogo de fonte.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB que representa a cor de fonte selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getlogfont"></a>CMFCPropertyGridFontProperty::GetLogFont  
 Recupera a fonte que o usuário seleciona na caixa de diálogo de fonte.  
  
```  
LPLOGFONT GetLogFont();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura que descreve a fonte selecionada.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)   
 [Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
