---
title: Manipulando o botão Aplicar
ms.date: 11/04/2016
helpviewer_keywords:
- Apply button in property sheet
- property sheets, Apply button
ms.assetid: 7e977015-59b8-406f-b545-aad0bfd8d55b
ms.openlocfilehash: cd1254a31491e713513f0db0d4cf87baddd9bb23
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618610"
---
# <a name="handling-the-apply-button"></a>Manipulando o botão Aplicar

As folhas de propriedades têm um recurso que as caixas de diálogo padrão não: permitem que o usuário aplique as alterações feitas antes de fechar a folha de propriedades. Isso é feito usando o botão Aplicar. Este artigo discute métodos que você pode usar para implementar esse recurso corretamente.

As caixas de diálogo modais geralmente aplicam as configurações a um objeto externo quando o usuário clica em OK para fechar a caixa de diálogo. O mesmo é verdadeiro para uma folha de propriedades: quando o usuário clica em OK, as novas configurações na folha de propriedades entram em vigor.

No entanto, talvez você queira permitir que o usuário salve as configurações sem precisar fechar a caixa de diálogo da folha de propriedades. Essa é a função do botão Aplicar. O botão Aplicar aplica as configurações atuais em todas as páginas de propriedades ao objeto externo, em vez de aplicar apenas as configurações atuais da página atualmente ativa.

Por padrão, o botão Aplicar está sempre desabilitado. Você deve escrever o código para habilitar o botão aplicar nos horários apropriados e deve escrever o código para implementar o efeito de aplicar, conforme explicado abaixo.

Se você não quiser oferecer a funcionalidade aplicar ao usuário, não será necessário remover o botão Aplicar. Você pode deixá-lo desabilitado, pois será comum entre aplicativos que usam o suporte à folha de propriedades padrão disponível em versões futuras do Windows.

Para relatar uma página como sendo modificada e habilitar o botão aplicar, chame `CPropertyPage::SetModified( TRUE )` . Se qualquer um dos relatórios de páginas estiver sendo modificado, o botão Aplicar permanecerá habilitado, independentemente de a página atualmente ativa ter sido modificada.

Você deve chamar [CPropertyPage:: SetModified](reference/cpropertypage-class.md#setmodified) sempre que o usuário alterar as configurações na página. Uma maneira de detectar quando um usuário altera uma configuração na página é implementar manipuladores de notificação de alteração para cada um dos controles na página de propriedades, como **EN_CHANGE** ou **BN_CLICKED**.

Para implementar o efeito do botão aplicar, a folha de propriedades deve informar seu proprietário ou outro objeto externo no aplicativo, para aplicar as configurações atuais nas páginas de propriedades. Ao mesmo tempo, a folha de propriedades deve desabilitar o botão Aplicar chamando `CPropertyPage::SetModified( FALSE )` para todas as páginas que aplicaram suas modificações ao objeto externo.

Para obter um exemplo desse processo, consulte o exemplo geral do MFC [PROPDLG](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](property-sheets-mfc.md)
