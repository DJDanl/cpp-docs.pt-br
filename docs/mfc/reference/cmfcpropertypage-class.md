---
title: Classe CMFCPropertyPage | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCPropertyPage
- AFXPROPERTYPAGE/CMFCPropertyPage
- AFXPROPERTYPAGE/CMFCPropertyPage::CMFCPropertyPage
dev_langs:
- C++
helpviewer_keywords:
- CMFCPropertyPage [MFC], CMFCPropertyPage
ms.assetid: d279d7f2-2d81-418d-9f23-6147d6e8df09
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b3352841b1b495d1718ffa6be034239ecd7e50c6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfcpropertypage-class"></a>Classe CMFCPropertyPage
O `CMFCPropertyPage` classe oferece suporte a exibição de menus pop-up em uma página de propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCPropertyPage : public CPropertyPage  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPropertyPage::CMFCPropertyPage](#cmfcpropertypage)|Constrói um objeto `CMFCPropertyPage`.|  
|`CMFCPropertyPage::~CMFCPropertyPage`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCPropertyPage::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|`CMFCPropertyPage::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|`CMFCPropertyPage::OnSetActive`|Essa função de membro é chamada pelo framework quando a página é escolhida pelo usuário e torna-se a página ativa. (Substitui [CPropertyPage::OnSetActive](../../mfc/reference/cpropertypage-class.md#onsetactive).)|  
|`CMFCPropertyPage::PreTranslateMessage`|Converte as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. Para obter mais informações e sintaxe de método, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CPropertyPage::PreTranslateMessage`.)|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCPropertyPage` classe representa as páginas individuais de uma folha de propriedades, também conhecido como uma caixa de diálogo de guia.  
  
 Use o `CMFCPropertyPage` classe junto com o [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) classe. Para usar os menus em uma página de propriedades, substitua todas as ocorrências de `CPropertyPage` classe com o `CMFCPropertyPage` classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CPropertyPage](../../mfc/reference/cpropertypage-class.md)  
  
 [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpropertypage.h  
  
##  <a name="cmfcpropertypage"></a>  CMFCPropertyPage::CMFCPropertyPage  
 Constrói um objeto `CMFCPropertyPage`.  
  
```  
CMFCPropertyPage(
    UINT nIDTemplate,  
    UINT nIDCaption=0);

 
CMFCPropertyPage(
    LPCTSTR lpszTemplateName,  
    UINT nIDCaption=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDTemplate`  
 ID do recurso de modelo para esta página.  
  
 `nIDCaption`  
 ID do recurso do rótulo para colocar na guia para esta página. Se for 0, o nome é obtido do modelo de caixa de diálogo para essa página. O valor padrão é 0.  
  
 `lpszTemplateName`  
 Aponta para o nome do modelo desta página. Não pode ser `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre os parâmetros do construtor, consulte [CPropertyPage::CPropertyPage](../../mfc/reference/cpropertypage-class.md#cpropertypage).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)
