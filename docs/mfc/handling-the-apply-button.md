---
title: Manipulando o botão Aplicar
ms.date: 11/04/2016
helpviewer_keywords:
- Apply button in property sheet
- property sheets, Apply button
ms.assetid: 7e977015-59b8-406f-b545-aad0bfd8d55b
ms.openlocfilehash: 30ee549a334a684deeb4a845f2fc49ee8bbe11db
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58770831"
---
# <a name="handling-the-apply-button"></a>Manipulando o botão Aplicar

Folhas de propriedade tem um recurso que caixas de diálogo padrão não: Eles permitem que o usuário aplicar as alterações feitas antes de fechar a folha de propriedades. Isso é feito usando o botão Aplicar. Este artigo descreve métodos que você pode usar para implementar este recurso corretamente.

Caixas de diálogo modais geralmente se aplicam as configurações a um objeto externo quando o usuário clica Okey para fechar a caixa de diálogo. O mesmo é verdadeiro para uma folha de propriedades: Quando o usuário clica Okey, as novas configurações na folha de propriedades entram em vigor.

No entanto, você talvez queira permitir que o usuário ao salvar as configurações sem fechar a caixa de diálogo da folha de propriedade. Essa é a função do botão Aplicar. O botão Aplicar aplica as configurações atuais em todas as páginas de propriedade para o objeto externo, em vez de aplicar apenas as configurações atuais da página ativa no momento.

Por padrão, o botão Aplicar está sempre desabilitado. Você deve escrever código para habilitar o botão Aplicar nos momentos apropriados, e você deve escrever código para implementar o efeito de aplicar, conforme explicado abaixo.

Se não desejar oferecer a funcionalidade de aplicar ao usuário, não é necessário remover o botão Aplicar. Você pode deixá-la desabilitada, pois será comum entre aplicativos que usam o suporte de folha de propriedade padrão disponível em versões futuras do Windows.

Para relatar uma página como sendo modificadas e habilitar o botão Aplicar, chame `CPropertyPage::SetModified( TRUE )`. Se houver páginas do relatório de tabela que está sendo modificado, o botão Aplicar permanecerá habilitado, independentemente se a página ativa no momento foi modificada.

Você deve chamar [CPropertyPage::SetModified](../mfc/reference/cpropertypage-class.md#setmodified) sempre que o usuário altera as configurações na página. Uma maneira de detectar quando um usuário altera uma configuração na página é implementar manipuladores de notificação de alteração para cada um dos controles na página de propriedades, tais como **eventos EN_CHANGE** ou **BN_CLICKED**.

Para implementar o efeito de no botão Aplicar, a folha de propriedades deve informar ao seu proprietário ou algum outro objeto externo do aplicativo, para aplicar as configurações atuais nas páginas de propriedades. Ao mesmo tempo, a folha de propriedades deve desabilitar o botão Aplicar chamando `CPropertyPage::SetModified( FALSE )` para todas as páginas que são aplicadas a suas modificações para o objeto externo.

Para obter um exemplo desse processo, consulte o exemplo de MFC geral [PROPDLG](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)
