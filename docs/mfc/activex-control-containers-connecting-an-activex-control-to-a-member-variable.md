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
ms.openlocfilehash: 87cb560a1054a912a4e8574cfe2dee74d5e61fe6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625139"
---
# <a name="activex-control-containers-connecting-an-activex-control-to-a-member-variable"></a>Contêineres de controle ActiveX: conectando um controle ActiveX a uma variável membro

A maneira mais fácil de acessar um controle ActiveX de dentro de seu aplicativo de contêiner de controle é associar o controle ActiveX a uma variável de membro da classe Dialog que conterá o controle.

> [!NOTE]
> Essa não é a única maneira de acessar um controle incorporado de dentro de uma classe de contêiner, mas, para os fins deste artigo, é suficiente.

### <a name="adding-a-member-variable-to-the-dialog-class"></a>Adicionando uma variável de membro à classe Dialog

1. Em Modo de Exibição de Classe, clique com o botão direito do mouse na classe de caixa de diálogo principal para abrir o menu de atalho. Por exemplo, `CContainerDlg`.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar variável**.

1. No assistente Adicionar variável de membro, clique em **variável de controle**.

1. Na caixa de listagem **ID de controle** , selecione a ID de controle do controle ActiveX inserido. Por exemplo, `IDC_CIRCCTRL1`.

1. Na caixa **nome da variável** , insira um nome.

   Por exemplo, *m_circctl*.

1. Clique em **concluir** para aceitar suas escolhas e sair do assistente para Adicionar variável de membro.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](activex-control-containers.md)
