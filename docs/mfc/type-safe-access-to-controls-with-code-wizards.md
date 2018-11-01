---
title: Acesso fortemente tipado a controles com assistentes de código
ms.date: 11/04/2016
helpviewer_keywords:
- DDX (dialog data exchange), access to controls
- code wizards
- dialog boxes [MFC], access to controls
- dialog box controls [MFC], accessing
ms.assetid: b8874393-ee48-4124-8d78-e3648a7e29b9
ms.openlocfilehash: 5f0bf03adff83ef25f3537291516368151a31a03
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50436277"
---
# <a name="type-safe-access-to-controls-with-code-wizards"></a>Acesso fortemente tipado a controles com assistentes de código

Se você estiver familiarizado com os recursos DDX, você pode usar a propriedade de controle na [Adicionar Assistente de variável de membro](../ide/add-member-variable-wizard.md) criar acesso fortemente tipado. Essa abordagem é mais fácil do que a criação de controles sem assistentes de código.

Se você quiser simplesmente acesso ao valor de um controle, DDX fornece a ele. Se você quiser fazer mais de acessar o valor de um controle, use o Assistente para adição de variável de membro para adicionar uma variável de membro da classe apropriada à sua classe de caixa de diálogo. Anexe a essa variável de membro para a propriedade de controle.

Variáveis de membro podem ter uma propriedade de controle, em vez de uma propriedade de valor. A propriedade de valor se refere ao tipo de dados retornados de controle, como `CString` ou **int**. A propriedade de controle permite acesso direto para o controle por meio de um membro de dados cujo tipo é uma das classes no MFC, controle, como `CButton` ou `CEdit`.

> [!NOTE]
>  Para um determinado controle, você pode, se desejar, ter diversas variáveis de membro com a propriedade de valor e no máximo a variável de um membro com a propriedade de controle. Você pode ter apenas um objeto MFC mapeado para um controle porque vários objetos anexados a um controle ou qualquer outra janela, poderia levar a uma ambiguidade no mapa de mensagens.

Você pode usar esse objeto para chamar qualquer função membro para o objeto de controle. Essas chamadas afetam o controle na caixa de diálogo. Por exemplo, para um controle de caixa de seleção representada por uma variável *m_Checkbox*, do tipo `CButton`, você poderia chamar:

[!code-cpp[NVC_MFCControlLadenDialog#52](../mfc/codesnippet/cpp/type-safe-access-to-controls-with-code-wizards_1.cpp)]

Aqui, a variável de membro *m_Checkbox* tem a mesma finalidade, como a função de membro `GetMyCheckbox` mostrado na [acesso fortemente tipado a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md). Se a caixa de seleção não for uma caixa de seleção automática, ainda seria necessário um manipulador em sua classe de caixa de diálogo para a mensagem de notificação de controle BN_CLICKED quando o botão é clicado.

Para obter mais informações sobre controles, consulte [controles](../mfc/controls-mfc.md).

## <a name="see-also"></a>Consulte também

[Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Acesso fortemente tipado a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md)

