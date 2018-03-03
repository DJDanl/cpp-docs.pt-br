---
title: Folhas de propriedades como assistentes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- property sheets, as wizards
ms.assetid: 1ea66ecb-23b0-484a-838d-58671a2999b5
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 65aedc5dbeb8a740d5713983f66eefe693864937
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="property-sheets-as-wizards"></a>Folhas de propriedades como assistentes
Uma característica chave de uma folha de propriedades do assistente é que a navegação é fornecida com os botões de próximo ou término e Cancelar em vez de guias. Você precisa chamar [CPropertySheet::SetWizardMode](../mfc/reference/cpropertysheet-class.md#setwizardmode) antes de chamar [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal) no objeto de folha de propriedade para tirar proveito desse recurso.  
  
 O usuário recebe o mesmo [CPropertyPage::OnSetActive](../mfc/reference/cpropertypage-class.md#onsetactive) e [CPropertyPage::OnKillActive](../mfc/reference/cpropertypage-class.md#onkillactive) notificações durante a movimentação de uma página para outra página. Avançar e botões de término são mutuamente exclusivos controles; ou seja, apenas um deles será mostrado por vez. Na primeira página, o botão Avançar deve ser habilitado. Se o usuário estiver na última página, deve ser habilitado no botão Concluir. Isso não é feito automaticamente pelo framework. Você precisa chamar [CPropertySheet::SetWizardButton](../mfc/reference/cpropertysheet-class.md#setwizardbuttons) na última página para fazer isso.  
  
 Para exibir todos os botões padrão, você precisa Mostrar botão Concluir e mova o botão Avançar. Mova o botão Voltar para que sua posição relativa para o botão Avançar é mantida.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#5](../mfc/codesnippet/cpp/property-sheets-as-wizards_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)

