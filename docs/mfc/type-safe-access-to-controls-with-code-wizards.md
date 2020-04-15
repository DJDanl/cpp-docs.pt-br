---
title: Acesso fortemente tipado a controles com assistentes de código
ms.date: 11/04/2016
helpviewer_keywords:
- DDX (dialog data exchange), access to controls
- code wizards
- dialog boxes [MFC], access to controls
- dialog box controls [MFC], accessing
ms.assetid: b8874393-ee48-4124-8d78-e3648a7e29b9
ms.openlocfilehash: b49c1b6f21dfe5270e40649241812320303ad411
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370911"
---
# <a name="type-safe-access-to-controls-with-code-wizards"></a>Acesso fortemente tipado a controles com assistentes de código

Se você estiver familiarizado com os recursos do DDX, você pode usar a propriedade Control no [Assistente de Variável adicionar membro](../ide/add-member-variable-wizard.md) para criar acesso seguro de tipo. Essa abordagem é mais fácil do que criar controles sem assistentes de código.

Se você simplesmente quiser ter acesso ao valor de um controle, o DDX o fornece. Se você quiser fazer mais do que acessar o valor de um controle, use o Assistente de Variável adicionar membro para adicionar uma variável de membro da classe apropriada à sua classe de diálogo. Anexe esta variável membro à propriedade Control.

As variáveis de membro podem ter uma propriedade Control em vez de uma propriedade Valor. A propriedade Valor refere-se ao tipo de dados `CString` retornados do controle, como ou **int**. A propriedade Control permite o acesso direto ao controle através de um membro de `CButton` `CEdit`dados cujo tipo seja uma das classes de controle em MFC, como ou .

> [!NOTE]
> Para um determinado controle, você pode, se desejar, ter várias variáveis de membro com a propriedade Valor e, no máximo, uma variável de membro com a propriedade Control. Você pode ter apenas um objeto MFC mapeado para um controle porque vários objetos conectados a um controle, ou qualquer outra janela, levaria a uma ambiguidade no mapa de mensagens.

Você pode usar este objeto para chamar qualquer função de membro para o objeto de controle. Tais chamadas afetam o controle na caixa de diálogo. Por exemplo, para um controle de caixa de `CButton`seleção representado por uma variável *m_Checkbox,* de tipo, você pode chamar:

[!code-cpp[NVC_MFCControlLadenDialog#52](../mfc/codesnippet/cpp/type-safe-access-to-controls-with-code-wizards_1.cpp)]

Aqui, a variável membro *m_Checkbox* serve `GetMyCheckbox` ao mesmo propósito que a função de membro mostrada no [Tipo-Safe Access to Controls Without Code Wizards](../mfc/type-safe-access-to-controls-without-code-wizards.md). Se a caixa de seleção não for uma caixa de seleção automática, você ainda precisará de um manipulador na sua classe de diálogo para a mensagem de BN_CLICKED de notificação de controle quando o botão for clicado.

Para obter mais informações sobre controles, consulte [Controles](../mfc/controls-mfc.md).

## <a name="see-also"></a>Confira também

[Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)<br/>
[Trabalhar com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Acesso fortemente tipado a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md)
