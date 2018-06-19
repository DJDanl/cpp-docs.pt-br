---
title: Funções de membro normalmente substituídas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CDialog class [MFC], members
- OnInitDialog function
- dialog classes [MFC], commonly overridden member functions
- OnCancel function
- overriding, dialog class members
- OnOK function
- MFC dialog boxes [MFC], overriding member functions
ms.assetid: 78eb566c-e361-4c86-8db5-c7e2791b249a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ed090057394c385dd12825864c5de9ff7d079e29
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33345830"
---
# <a name="commonly-overridden-member-functions"></a>Funções de membro normalmente substituídas
A tabela a seguir lista mais provavelmente funções de membro para substituir em seu `CDialog`-classe derivada.  
  
### <a name="commonly-overridden-member-functions-of-class-cdialog"></a>Funções de membro de classe CDialog normalmente substituídas  
  
|Função de membro|Responder à mensagem de|Finalidade da substituição|  
|---------------------|----------------------------|-----------------------------|  
|`OnInitDialog`|**WM_INITDIALOG**|Inicialize os controles da caixa de diálogo.|  
|`OnOK`|**BN_CLICKED** botão **IDOK**|Responda quando o usuário clica no botão Okey.|  
|`OnCancel`|**BN_CLICKED** botão **IDCANCEL**|Responda quando o usuário clica no botão Cancelar.|  
  
 `OnInitDialog`, `OnOK`, e `OnCancel` são funções virtuais. Para substituí-los, você deve declarar uma função de substituição em sua classe de caixa de diálogo derivada usando o [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
 `OnInitDialog` é chamado antes da caixa de diálogo é exibida. Você deve chamar o padrão `OnInitDialog` manipulador da sua substituição — normalmente como a primeira ação no manipulador. Por padrão, `OnInitDialog` retorna **TRUE** para indicar que o foco deve ser definido como o primeiro controle na caixa de diálogo.  
  
 `OnOK` normalmente é substituído para caixas de diálogo sem janela restrita, mas não modal. Se você substituir esse manipulador para uma caixa de diálogo modal, chame a versão da classe base da sua substituição, para garantir que `EndDialog` é chamado — ou chamar `EndDialog` por conta própria.  
  
 `OnCancel` geralmente é substituído para caixas de diálogo sem janela restrita.  
  
 Para obter mais informações sobre essas funções de membro, consulte a classe [CDialog](../mfc/reference/cdialog-class.md) no *referência MFC* e a discussão sobre [ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md).  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Funções de membro normalmente adicionadas](../mfc/commonly-added-member-functions.md)
