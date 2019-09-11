---
title: Funções de membro normalmente substituídas
ms.date: 09/06/2019
helpviewer_keywords:
- CDialog class [MFC], members
- OnInitDialog function
- dialog classes [MFC], commonly overridden member functions
- OnCancel function
- overriding, dialog class members
- OnOK function
- MFC dialog boxes [MFC], overriding member functions
ms.assetid: 78eb566c-e361-4c86-8db5-c7e2791b249a
ms.openlocfilehash: f63dd6079b96181305f3207d4a1ef823df8d8ba4
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907683"
---
# <a name="commonly-overridden-member-functions"></a>Funções de membro normalmente substituídas

A tabela a seguir lista as funções de membro mais prováveis para substituir `CDialog`em sua classe derivada.

### <a name="commonly-overridden-member-functions-of-class-cdialog"></a>Funções de membro comumente substituídas da classe CDialog

|Função de membro|Mensagem que responde a|Finalidade da substituição|
|---------------------|----------------------------|-----------------------------|
|`OnInitDialog`|**WM_INITDIALOG**|Inicialize os controles da caixa de diálogo.|
|`OnOK`|**BN_CLICKED** para o botão **IDOK**|Responder quando o usuário clicar no botão OK.|
|`OnCancel`|**BN_CLICKED** para o botão **IDCANCEL**|Responder quando o usuário clicar no botão Cancelar.|

`OnInitDialog`, `OnOK` e`OnCancel` são funções virtuais. Para substituí-los, você declara uma função de substituição em sua classe de caixa de diálogo derivada usando o [Assistente de classe do MFC](reference/mfc-class-wizard.md).

`OnInitDialog`é chamado logo antes da caixa de diálogo ser exibida. Você deve chamar o manipulador `OnInitDialog` padrão de sua substituição — geralmente como a primeira ação no manipulador. Por padrão, `OnInitDialog` retorna **true** para indicar que o foco deve ser definido para o primeiro controle na caixa de diálogo.

`OnOK`normalmente é substituído para as caixas de diálogo sem janela restrita, mas não modal. Se você substituir esse manipulador para uma caixa de diálogo modal, chame a versão da classe base da sua substituição — para `EndDialog` garantir que seja chamado — `EndDialog` ou chame-o por conta própria.

`OnCancel`geralmente é substituído por caixas de diálogo sem janela restrita.

Para obter mais informações sobre essas funções de membro, consulte classe [CDialog](../mfc/reference/cdialog-class.md) na *referência do MFC* e a discussão sobre o [ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md).

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Funções de membro normalmente adicionadas](../mfc/commonly-added-member-functions.md)
