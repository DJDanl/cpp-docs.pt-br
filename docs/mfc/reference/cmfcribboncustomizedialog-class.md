---
title: Classe CMFCRibbonCustomizeDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- GetThisClass
- CMFCRibbonCustomizeDialog
- ~CMFCRibbonCustomizeDialog
- CMFCRibbonCustomizeDialog::GetThisClass
- CMFCRibbonCustomizeDialog.~CMFCRibbonCustomizeDialog
- CMFCRibbonCustomizeDialog.GetThisClass
- CMFCRibbonCustomizeDialog::~CMFCRibbonCustomizeDialog
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonCustomizeDialog class
- CMFCRibbonCustomizeDialog class, destructor
- ~CMFCRibbonCustomizeDialog destructor
- GetThisClass method
ms.assetid: ce67de7f-5eaa-4c75-9b94-f290f36df073
caps.latest.revision: 22
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
ms.openlocfilehash: d27247f89901adad1778313cdde6fe206a569f0d
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribboncustomizedialog-class"></a>Classe CMFCRibbonCustomizeDialog
Exibe a faixa de opções **personalizar** página.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonCustomizeDialog : public CMFCPropertySheet  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonCustomizeDialog::CMFCRibbonCustomizeDialog](#cmfcribboncustomizedialog)|Constrói um objeto `CMFCRibbonCustomizeDialog`.|  
|`CMFCRibbonCustomizeDialog::~CMFCRibbonCustomizeDialog`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonCustomizeDialog::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
  
## <a name="remarks"></a>Comentários  
 MFC cria uma instância dessa classe automaticamente se você não processar a mensagem AFX_WM_ON_RIBBON_CUSTOMIZE, ou se você retornar 0 do manipulador de mensagens.  
  
 Se você deseja usar essa classe em seu aplicativo para exibir a faixa de opções **personalizar** caixa de diálogo caixa, apenas uma instância e chamar o `DoModal` método.  
  
 Como essa classe é derivada de [CMFCPropertySheet classe](../../mfc/reference/cmfcpropertysheet-class.md), você pode adicionar páginas personalizadas usando o `CMFCPropertySheet` API.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CPropertySheet](../../mfc/reference/cpropertysheet-class.md)  
  
 [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)  
  
 [CMFCRibbonCustomizeDialog](../../mfc/reference/cmfcribboncustomizedialog-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribboncustomizedialog.h  
  
##  <a name="a-namecmfcribboncustomizedialoga--cmfcribboncustomizedialogcmfcribboncustomizedialog"></a><a name="cmfcribboncustomizedialog"></a>CMFCRibbonCustomizeDialog::CMFCRibbonCustomizeDialog  
 Constrói um objeto `CMFCRibbonCustomizeDialog`.  
  
```  
CMFCRibbonCustomizeDialog(
    CWnd* pWndParent,  
    CMFCRibbonBar* pRibbon);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Um ponteiro para a janela pai (geralmente o quadro principal).  
  
 [in] `pRibbon`  
 Um ponteiro para o `CMFCRibbonBar` que deve ser personalizado.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCRibbonCustomizeDialog` objeto.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&18;](../../mfc/reference/codesnippet/cpp/cmfcribboncustomizedialog-class_1.cpp)]  
  
### <a name="remarks"></a>Comentários  
 O construtor instancia um [CMFCRibbonCustomizePropertyPage classe](../../mfc/reference/cmfcribboncustomizepropertypage-class.md) do objeto e o adiciona à coleção de páginas de propriedade.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

