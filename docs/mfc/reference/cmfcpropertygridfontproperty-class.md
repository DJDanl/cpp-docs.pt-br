---
title: Classe CMFCPropertyGridFontProperty | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3ea43fefabe43bec8a5bf9b00404491a405e5416
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37852975"
---
# <a name="cmfcpropertygridfontproperty-class"></a>Classe CMFCPropertyGridFontProperty
O `CMFCPropertyGridFileProperty` classe dá suporte a um item de controle de lista de propriedade que abre uma caixa de diálogo de seleção de fonte.  
  
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
|`CMFCPropertyGridFontProperty::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|  
|`CMFCPropertyGridFontProperty::OnClickButton`|Chamado pelo framework quando o usuário clica em um botão que está contido em uma propriedade. (Substitui [CMFCPropertyGridProperty::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|  
  
## <a name="remarks"></a>Comentários  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)  
  
 [CMFCPropertyGridFontProperty](../../mfc/reference/cmfcpropertygridfontproperty-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpropertygridctrl.h  
  
##  <a name="cmfcpropertygridfontproperty"></a>  CMFCPropertyGridFontProperty::CMFCPropertyGridFontProperty  
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
 [in] *strName*  
 O nome da propriedade.  
  
 [in] *lf*  
 Uma estrutura de fonte lógica que especifica os atributos da fonte.  
  
 [in] *dwFontDialogFlags*  
 Estilos que são aplicados à caixa de diálogo de fonte que é exibida quando você clicar no botão de lista suspensa de valor de propriedade. O valor padrão é a combinação bit a bit (OR) de CF_EFFECTS e CF_SCREENFONTS. Para obter mais informações, consulte o *sinalizadores* parâmetro do [CHOOSEFONT estrutura](http://msdn.microsoft.com/library/windows/desktop/ms646832).  
  
 [in] *lpszDescr*  
 Descrição da propriedade da fonte. O valor padrão é NULL.  
  
 [in] *dwData*  
 Dados específicos do aplicativo, como um inteiro ou um ponteiro para outros dados que está associados com a propriedade. O valor padrão é 0.  
  
 [in] *cor*  
 A cor da fonte. O valor padrão é a cor padrão.  
  
### <a name="remarks"></a>Comentários  
 Um `CMFCPropertyGridFontProperty` objeto representa uma propriedade de fonte em um controle de fonte de grade de propriedade.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto do `CMFCPropertyGridFontProperty` classe. Este exemplo é parte do [exemplo de novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#26](../../mfc/reference/codesnippet/cpp/cmfcpropertygridfontproperty-class_1.cpp)]  
  
##  <a name="getcolor"></a>  CMFCPropertyGridFontProperty::GetColor  
 Recupera a cor da fonte que o usuário seleciona na caixa de diálogo de fonte.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB que representa a cor da fonte selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getlogfont"></a>  CMFCPropertyGridFontProperty::GetLogFont  
 Recupera a fonte que o usuário seleciona na caixa de diálogo de fonte.  
  
```  
LPLOGFONT GetLogFont();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura que descreve a fonte selecionada.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)   
 [Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
