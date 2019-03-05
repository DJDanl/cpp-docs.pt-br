---
title: Folhas de propriedades como assistentes
ms.date: 11/04/2016
helpviewer_keywords:
- property sheets, as wizards
ms.assetid: 1ea66ecb-23b0-484a-838d-58671a2999b5
ms.openlocfilehash: c60148c099b34993bef0c9808e6561e37c26cc7f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57301669"
---
# <a name="property-sheets-as-wizards"></a>Folhas de propriedades como assistentes

Uma característica principal de uma folha de propriedades do assistente é que a navegação é fornecida com botões Avançar ou voltar, concluir e Cancelar em vez de guias. Você precisa chamar [CPropertySheet::SetWizardMode](../mfc/reference/cpropertysheet-class.md#setwizardmode) antes de chamar [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal) no objeto de planilha de propriedade para tirar proveito desse recurso.

O usuário recebe o mesmo [CPropertyPage::OnSetActive](../mfc/reference/cpropertypage-class.md#onsetactive) e [CPropertyPage::OnKillActive](../mfc/reference/cpropertypage-class.md#onkillactive) notificações durante a movimentação de uma página para outra página. Avançar e concluir botões são mutuamente exclusivos controles; ou seja, apenas um deles será mostrado por vez. Na primeira página, deve ser habilitado no botão Avançar. Se o usuário estiver na última página, o botão Concluir deve ser habilitado. Isso não é feito automaticamente pela estrutura. Você precisa chamar [CPropertySheet::SetWizardButton](../mfc/reference/cpropertysheet-class.md#setwizardbuttons) na última página para fazer isso.

Para exibir todos os botões padrão, você precisa mostrar o botão Concluir e mova o botão Avançar. Em seguida, mova o botão Voltar para que sua posição relativa para o botão Avançar é mantida.

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#5](../mfc/codesnippet/cpp/property-sheets-as-wizards_1.cpp)]

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)
