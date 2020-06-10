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
ms.openlocfilehash: 7d4fc9005ff368ef6a83252e8cf0b2005ecf2cef
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619659"
---
# <a name="commonly-overridden-member-functions"></a>Funções de membro normalmente substituídas

A tabela a seguir lista as funções de membro mais prováveis para substituir em sua `CDialog` classe derivada.

### <a name="commonly-overridden-member-functions-of-class-cdialog"></a>Funções de membro comumente substituídas da classe CDialog

|Função de membro|Mensagem que responde a|Finalidade da substituição|
|---------------------|----------------------------|-----------------------------|
|`OnInitDialog`|**WM_INITDIALOG**|Inicialize os controles da caixa de diálogo.|
|`OnOK`|**BN_CLICKED** para o botão **IDOK**|Responder quando o usuário clicar no botão OK.|
|`OnCancel`|**BN_CLICKED** para o botão **IDCANCEL**|Responder quando o usuário clicar no botão Cancelar.|

`OnInitDialog`, `OnOK` e `OnCancel` são funções virtuais. Para substituí-los, você declara uma função de substituição em sua classe de caixa de diálogo derivada usando o [Assistente de classe do MFC](reference/mfc-class-wizard.md).

`OnInitDialog`é chamado logo antes da caixa de diálogo ser exibida. Você deve chamar o `OnInitDialog` manipulador padrão de sua substituição — geralmente como a primeira ação no manipulador. Por padrão, `OnInitDialog` retorna **true** para indicar que o foco deve ser definido para o primeiro controle na caixa de diálogo.

`OnOK`normalmente é substituído para as caixas de diálogo sem janela restrita, mas não modal. Se você substituir esse manipulador para uma caixa de diálogo modal, chame a versão da classe base da sua substituição — para garantir que `EndDialog` seja chamado — ou chame-o por `EndDialog` conta própria.

`OnCancel`geralmente é substituído por caixas de diálogo sem janela restrita.

Para obter mais informações sobre essas funções de membro, consulte classe [CDialog](reference/cdialog-class.md) na *referência do MFC* e a discussão sobre como [trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md).

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](dialog-boxes.md)<br/>
[Funções de membro normalmente adicionadas](commonly-added-member-functions.md)
