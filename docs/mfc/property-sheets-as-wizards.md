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
ms.openlocfilehash: 73b6b0462012fc54b3bd6f2cb22422f5b1431288
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374204"
---
# <a name="property-sheets-as-wizards"></a>Folhas de propriedades como assistentes

Uma característica principal de uma folha de propriedades do assistente é que a navegação é fornecida com botões Avançar ou voltar, concluir e Cancelar em vez de guias. Você precisa chamar [CPropertySheet::SetWizardMode](../mfc/reference/cpropertysheet-class.md#setwizardmode) antes de chamar [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal) no objeto de planilha de propriedade para tirar proveito desse recurso.

O usuário recebe o mesmo [CPropertyPage::OnSetActive](../mfc/reference/cpropertypage-class.md#onsetactive) e [CPropertyPage::OnKillActive](../mfc/reference/cpropertypage-class.md#onkillactive) notificações durante a movimentação de uma página para outra página. Avançar e concluir botões são mutuamente exclusivos controles; ou seja, apenas um deles será mostrado por vez. Na primeira página, deve ser habilitado no botão Avançar. Se o usuário estiver na última página, o botão Concluir deve ser habilitado. Isso não é feito automaticamente pela estrutura. Você precisa chamar [CPropertySheet::SetWizardButton](../mfc/reference/cpropertysheet-class.md#setwizardbuttons) na última página para fazer isso.

Para exibir todos os botões padrão, você precisa mostrar o botão Concluir e mova o botão Avançar. Em seguida, mova o botão Voltar para que sua posição relativa para o botão Avançar é mantida.

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#5](../mfc/codesnippet/cpp/property-sheets-as-wizards_1.cpp)]

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)

