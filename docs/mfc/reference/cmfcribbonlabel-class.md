---
title: Classe CMFCRibbonLabel | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonLabel
- AFXRIBBONLABEL/CMFCRibbonLabel
- AFXRIBBONLABEL/CMFCRibbonLabel::CMFCRibbonLabel
- AFXRIBBONLABEL/CMFCRibbonLabel::SetACCData
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonLabel class
ms.assetid: 0346c891-83bf-4f20-b8a1-c84cf2aadced
caps.latest.revision: 21
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
ms.openlocfilehash: b93e0f6c46818515c8d6bcd8d71b78dcaa435ea6
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbonlabel-class"></a>Classe CMFCRibbonLabel
Implementa um rótulo de texto não clicável para uma faixa de opções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonLabel : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonLabel::CMFCRibbonLabel](#cmfcribbonlabel)|Constrói e inicializa um `CMFCRibbonLabel` objeto com a cadeia de caracteres de texto especificado.|  
|`CMFCRibbonLabel::~CMFCRibbonLabel`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonLabel::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|`CMFCRibbonLabel::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCRibbonLabel::SetACCData](#setaccdata)|Determina os dados de acessibilidade para o elemento de rótulo de faixa de opções atual. (Substitui [CMFCRibbonButton::SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|  
  
### <a name="remarks"></a>Comentários  
 Depois de criar um rótulo de faixa de opções, adicioná-lo a um painel chamando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).  
  
 Você não pode adicionar um rótulo de faixa de opções para a barra de ferramentas de acesso rápido.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonLabel](../../mfc/reference/cmfcribbonlabel-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonLabel.h  
  
##  <a name="cmfcribbonlabel"></a>CMFCRibbonLabel::CMFCRibbonLabel  
 Constrói e inicializa um [CMFCRibbonLabel](../../mfc/reference/cmfcribbonlabel-class.md) objeto que exibe a cadeia de caracteres de texto especificado.  
  
```  
CMFCRibbonLabel(
    LPCTSTR lpszText,  
    BOOL bIsMultiLine = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszText`  
 O texto exibido no rótulo.  
  
 [in] `bIsMultiLine`  
 `TRUE`para especificar que o rótulo é um rótulo de várias linha; Caso contrário, `FALSE`.  
  
##  <a name="setaccdata"></a>CMFCRibbonLabel::SetACCData  
 Determina os dados de acessibilidade para o elemento de rótulo de faixa de opções atual.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParent`  
 Representa a janela pai do rótulo da faixa de opções atual.  
  
 [out] `data`  
 Um objeto do tipo `CAccessibilityData` que é preenchida com os dados de acessibilidade do rótulo da faixa de opções atual.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o `data` parâmetro estava com êxito preenchido com os dados de acessibilidade do rótulo da faixa de opções atual; caso contrário, `FALSE`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

