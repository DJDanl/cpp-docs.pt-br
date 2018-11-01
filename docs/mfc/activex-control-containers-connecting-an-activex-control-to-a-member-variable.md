---
title: 'Contêineres de controle ActiveX: conectando um controle ActiveX a uma variável membro'
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX control containers [MFC], accessing ActiveX controls
- ActiveX controls [MFC], member variables of project
- connecting ActiveX controls to container member variables
- ActiveX controls [MFC], accessing
- member variables [MFC], ActiveX controls in project
- ActiveX control containers [MFC], ActiveX controls as member variables
ms.assetid: 7898a336-440d-4a60-be43-cb062b807aee
ms.openlocfilehash: 2234647e933e37ff82845c4b40dc93cefeb55575
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50446456"
---
# <a name="activex-control-containers-connecting-an-activex-control-to-a-member-variable"></a>Contêineres de controle ActiveX: conectando um controle ActiveX a uma variável membro

É a maneira mais fácil de acessar um controle ActiveX de dentro de seu aplicativo de contêiner do controle associar o controle ActiveX uma variável de membro da classe de caixa de diálogo que contém o controle.

> [!NOTE]
>  Isso não é a única maneira de acessar um controle inserido de dentro de uma classe de contêiner, mas para os fins deste artigo é suficiente.

### <a name="adding-a-member-variable-to-the-dialog-class"></a>Adicionar uma variável de membro para a classe de caixa de diálogo

1. Na exibição de classe, clique com botão direito a classe principal da caixa de diálogo para abrir o menu de atalho. Por exemplo, `CContainerDlg`.

1. No menu de atalho, clique em **Add** e, em seguida **Adicionar variável**.

1. No Assistente para Adicionar variável de membro, clique em **variável de controle**.

1. No **ID do controle** caixa de listagem, selecione a ID do controle do controle ActiveX incorporado. Por exemplo, `IDC_CIRCCTRL1`.

1. No **nome da variável** , digite um nome.

   Por exemplo, *m_circctl*.

1. Clique em **concluir** para aceitar as opções e sair do Assistente de variável de membro adicionar.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

