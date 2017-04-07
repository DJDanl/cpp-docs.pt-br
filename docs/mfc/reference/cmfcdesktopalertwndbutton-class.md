---
title: Classe CMFCDesktopAlertWndButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCDesktopAlertWndButton
- AFXDESKTOPALERTWND/CMFCDesktopAlertWndButton
- AFXDESKTOPALERTWND/CMFCDesktopAlertWndButton::IsCaptionButton
- AFXDESKTOPALERTWND/CMFCDesktopAlertWndButton::IsCloseButton
dev_langs:
- C++
helpviewer_keywords:
- CMFCDesktopAlertWndButton class
ms.assetid: df39a0c8-0c39-4ab0-8c64-78c5b2c4ecaf
caps.latest.revision: 23
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 52294143c6caf5a8e0458c152540c41f7df78c57
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcdesktopalertwndbutton-class"></a>Classe CMFCDesktopAlertWndButton
Permite que os botões a serem adicionados a uma caixa de diálogo de alerta da área de trabalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDesktopAlertWndButton : public CMFCButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDesktopAlertWndButton::CMFCDesktopAlertWndButton`|Construtor padrão.|  
|`CMFCDesktopAlertWndButton::~CMFCDesktopAlertWndButton`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCDesktopAlertWndButton::IsCaptionButton](#iscaptionbutton)|Determina se o botão é exibido na área de legenda da caixa de diálogo de alerta.|  
|[CMFCDesktopAlertWndButton::IsCloseButton](#isclosebutton)|Determina se o botão fecha a caixa de diálogo de alerta.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDesktopAlertWndButton::m_bIsCaptionButton`|Um valor booleano que especifica se o botão é exibido na área de legenda da caixa de diálogo de alerta.|  
|`CMFCDesktopAlertWndButton::m_bIsCloseButton`|Um valor booleano que especifica se o botão fecha a caixa de diálogo de alerta.|  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o construtor define o `m_bIsCaptionButton` e `m_bIsCloseButton` membros de dados `FALSE`. O pai `CMFCDesktopAlertDialog` conjuntos de objetos `m_bIsCaptionButton` para `TRUE` se o botão é posicionado na área de legenda da caixa de diálogo de alerta. O `CMFCDesktopAlertDialog` classe cria um `CMFCDesktopAlertWndButton` objeto que serve como o botão que fecha a caixa de diálogo alerta caixa e define `m_bIsCloseButton` para `TRUE`.  
  
 Adicionar `CMFCDesktopAlertWndButton` objetos para uma `CMFCDesktopAlertDialog` objeto como faria ao adicionar um botão. Para obter mais informações sobre `CMFCDesktopAlertDialog`, consulte [CMFCDesktopAlertDialog classe](../../mfc/reference/cmfcdesktopalertdialog-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SetImage` método o `CMFCDesktopAlertWndButton` classe. Este trecho de código é parte do [exemplo de demonstração de alerta de área de trabalho](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DesktopAlertDemo n º&4;](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndbutton-class_1.h)]  
[!code-cpp[NVC_MFC_DesktopAlertDemo n º&5;](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndbutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCButton](../../mfc/reference/cmfcbutton-class.md)  
  
 [CMFCDesktopAlertWndButton](../../mfc/reference/cmfcdesktopalertwndbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdesktopalertwnd.h  
  
##  <a name="iscaptionbutton"></a>CMFCDesktopAlertWndButton::IsCaptionButton  
 Determina se o botão é exibido na área de legenda da caixa de diálogo de alerta.  
  
```  
BOOL IsCaptionButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão é exibido na área de legenda da caixa de diálogo de alerta; Caso contrário, 0.  
  
##  <a name="isclosebutton"></a>CMFCDesktopAlertWndButton::IsCloseButton  
 Determina se o botão fecha a caixa de diálogo de alerta.  
  
```  
BOOL IsCloseButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão fecha a caixa de diálogo de alerta. Caso contrário, 0.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)

