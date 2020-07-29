---
title: Acesso fortemente tipado a controles com assistentes de código
ms.date: 11/04/2016
helpviewer_keywords:
- DDX (dialog data exchange), access to controls
- code wizards
- dialog boxes [MFC], access to controls
- dialog box controls [MFC], accessing
ms.assetid: b8874393-ee48-4124-8d78-e3648a7e29b9
ms.openlocfilehash: bfbc27dbcdeeb38c40f5d989bacd65a23198d4f5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213964"
---
# <a name="type-safe-access-to-controls-with-code-wizards"></a>Acesso fortemente tipado a controles com assistentes de código

Se você estiver familiarizado com os recursos do campo DDX, poderá usar a propriedade Control no [Assistente para Adicionar variável de membro](../ide/add-member-variable-wizard.md) para criar acesso seguro de tipo. Essa abordagem é mais fácil do que criar controles sem assistentes de código.

Se você simplesmente quiser acesso ao valor de um controle, campo DDX o fornecerá. Se você quiser fazer mais do que acessar o valor de um controle, use o assistente para Adicionar variável de membro para adicionar uma variável de membro da classe apropriada à sua classe de caixa de diálogo. Anexe essa variável de membro à propriedade de controle.

As variáveis de membro podem ter uma propriedade de controle em vez de uma propriedade Value. A propriedade Value refere-se ao tipo de dados retornado do controle, como `CString` ou **`int`** . A propriedade Control permite o acesso direto ao controle por meio de um membro de dados cujo tipo é uma das classes de controle no MFC, como `CButton` ou `CEdit` .

> [!NOTE]
> Para um determinado controle, você pode, se desejar, ter várias variáveis de membro com a propriedade Value e, no máximo, uma variável de membro com a propriedade Control. Você pode ter apenas um objeto MFC mapeado para um controle porque vários objetos anexados a um controle ou qualquer outra janela levam a uma ambiguidade no mapa de mensagens.

Você pode usar esse objeto para chamar qualquer função de membro para o objeto de controle. Essas chamadas afetam o controle na caixa de diálogo. Por exemplo, para um controle de caixa de seleção representado por uma variável *m_Checkbox*, do tipo `CButton` , você poderia chamar:

[!code-cpp[NVC_MFCControlLadenDialog#52](../mfc/codesnippet/cpp/type-safe-access-to-controls-with-code-wizards_1.cpp)]

Aqui, a variável de membro *m_Checkbox* tem a mesma finalidade que a função de membro `GetMyCheckbox` mostrada em [acesso de tipo seguro a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md). Se a caixa de seleção não for uma caixa de seleção automática, você ainda precisará de um manipulador na sua classe de caixa de diálogo para a mensagem de notificação de controle de BN_CLICKED quando o botão for clicado.

Para obter mais informações sobre controles, consulte [controles](../mfc/controls-mfc.md).

## <a name="see-also"></a>Confira também

[Acesso de tipo seguro a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)<br/>
[Trabalhar com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Acesso de tipo seguro a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md)
