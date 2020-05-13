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
ms.openlocfilehash: 620a9ec58b3a5a8fcdac63626b81fbc4620de399
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371615"
---
# <a name="activex-control-containers-connecting-an-activex-control-to-a-member-variable"></a>Contêineres de controle ActiveX: conectando um controle ActiveX a uma variável membro

A maneira mais fácil de acessar um controle ActiveX de dentro de seu aplicativo de contêiner de controle é associar o controle ActiveX a uma variável membro da classe de diálogo que conterá o controle.

> [!NOTE]
> Esta não é a única maneira de acessar um controle incorporado de dentro de uma classe de contêineres, mas para efeitos deste artigo é suficiente.

### <a name="adding-a-member-variable-to-the-dialog-class"></a>Adicionando uma variável de membro à classe de diálogo

1. Na exibição de classe, clique com o botão direito do mouse na classe de diálogo principal para abrir o menu de atalho. Por exemplo, `CContainerDlg`.

1. No menu de atalho, clique **em Adicionar** e, em seguida, **Adicionar variável**.

1. No Assistente de Variável adicionar membro, clique em **'Controlar'**

1. Na caixa de lista **de id de controle,** selecione o ID de controle do controle ActiveX incorporado. Por exemplo, `IDC_CIRCCTRL1`.

1. Na **caixa Nome de Variável,** digite um nome.

   Por exemplo, *m_circctl.*

1. Clique **em Concluir** para aceitar suas escolhas e sair do Assistente de Variável adicionar membro.

## <a name="see-also"></a>Confira também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)
