---
title: Folhas de propriedades como assistentes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- property sheets, as wizards
ms.assetid: 1ea66ecb-23b0-484a-838d-58671a2999b5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 634359763f24e02987664fe3de1094e3e7fec64c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347325"
---
# <a name="property-sheets-as-wizards"></a>Folhas de propriedades como assistentes
Uma característica chave de uma folha de propriedades do assistente é que a navegação é fornecida com os botões de próximo ou término e Cancelar em vez de guias. Você precisa chamar [CPropertySheet::SetWizardMode](../mfc/reference/cpropertysheet-class.md#setwizardmode) antes de chamar [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal) no objeto de folha de propriedade para tirar proveito desse recurso.  
  
 O usuário recebe o mesmo [CPropertyPage::OnSetActive](../mfc/reference/cpropertypage-class.md#onsetactive) e [CPropertyPage::OnKillActive](../mfc/reference/cpropertypage-class.md#onkillactive) notificações durante a movimentação de uma página para outra página. Avançar e botões de término são mutuamente exclusivos controles; ou seja, apenas um deles será mostrado por vez. Na primeira página, o botão Avançar deve ser habilitado. Se o usuário estiver na última página, deve ser habilitado no botão Concluir. Isso não é feito automaticamente pelo framework. Você precisa chamar [CPropertySheet::SetWizardButton](../mfc/reference/cpropertysheet-class.md#setwizardbuttons) na última página para fazer isso.  
  
 Para exibir todos os botões padrão, você precisa Mostrar botão Concluir e mova o botão Avançar. Mova o botão Voltar para que sua posição relativa para o botão Avançar é mantida.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#5](../mfc/codesnippet/cpp/property-sheets-as-wizards_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)

