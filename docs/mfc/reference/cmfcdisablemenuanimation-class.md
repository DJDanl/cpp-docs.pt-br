---
title: Classe CMFCDisableMenuAnimation | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCDisableMenuAnimation
- AFXPOPUPMENU/CMFCDisableMenuAnimation
- AFXPOPUPMENU/CMFCDisableMenuAnimation::Restore
dev_langs: C++
helpviewer_keywords: CMFCDisableMenuAnimation [MFC], Restore
ms.assetid: c6eb07da-c382-43d6-8028-007f2320e50e
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4a0549f553d7e458fa3499bea758cb0c4a5179eb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cmfcdisablemenuanimation-class"></a>Classe CMFCDisableMenuAnimation
Desativa a animação de menu pop-up.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDisableMenuAnimation  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDisableMenuAnimation::CMFCDisableMenuAnimation`|Constrói um objeto `CMFCDisableMenuAnimation`.|  
|`CMFCDisableMenuAnimation::~CMFCDisableMenuAnimation`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCDisableMenuAnimation::Restore](#restore)|Restaura a animação anterior a estrutura usada para exibir um menu pop-up.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDisableMenuAnimation::m_animType`|Armazena o tipo de animação anterior do menu pop-up.|  
  
### <a name="remarks"></a>Comentários  
 Use esta classe auxiliar para desabilitar temporariamente a animação de menu pop-up (por exemplo, quando você processar comandos de mouse ou teclado).  
  
 Um `CMFCDisableMenuAnimation` objeto desativa a animação de menu pop-up durante seu ciclo de vida. O construtor armazena o tipo atual de animação de menu pop-up no `m_animType` campo e define a animação atual tipo `CMFCPopupMenu::NO_ANIMATION`. O destruidor restaura o tipo de animação anterior.  
  
 Você pode criar um `CMFCDisableMenuAnimation` objeto na pilha para desabilitar a animação de menu pop-up ao longo de uma única função. Se você quiser desabilitar a animação de menus pop-up entre as funções, criar um `CMFCDisableMenuAnimation` no heap de objeto e, em seguida, excluí-lo quando você deseja restaurar a animação do menu pop-up.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar a pilha para desabilitar temporariamente a animação de menu.  
  
 [!code-cpp[NVC_MFC_Misc#1](../../mfc/reference/codesnippet/cpp/cmfcdisablemenuanimation-class_1.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCDisableMenuAnimation](../../mfc/reference/cmfcdisablemenuanimation-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpopupmenu.h  
  
##  <a name="restore"></a>CMFCDisableMenuAnimation::Restore  
 Restaura a animação anterior a estrutura usada para exibir um menu pop-up.  
  
```  
void Restore ();
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pelo `CMFCDisableMenuAnimation` destruidor para restaurar a animação anterior a estrutura usada para exibir um menu pop-up.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)
