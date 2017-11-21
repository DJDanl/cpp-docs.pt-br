---
title: "Contêineres de controle ActiveX: Conectando um controle ActiveX a uma variável de membro | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ActiveX control containers [MFC], accessing ActiveX controls
- ActiveX controls [MFC], member variables of project
- connecting ActiveX controls to container member variables
- ActiveX controls [MFC], accessing
- member variables [MFC], ActiveX controls in project
- ActiveX control containers [MFC], ActiveX controls as member variables
ms.assetid: 7898a336-440d-4a60-be43-cb062b807aee
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 140be0aaaf614796d85fe30a33f93058cafafa57
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="activex-control-containers-connecting-an-activex-control-to-a-member-variable"></a>Contêineres de controle ActiveX: conectando um controle ActiveX a uma variável membro
É a maneira mais fácil para um controle ActiveX de dentro de seu aplicativo de contêiner de controle de acesso associar o controle ActiveX uma variável de membro da classe de caixa de diálogo que contém o controle.  
  
> [!NOTE]
>  Isso não é a única maneira de acessar um controle inserido de dentro de uma classe de contêiner, mas para a finalidade deste artigo é suficiente.  
  
### <a name="adding-a-member-variable-to-the-dialog-class"></a>Adicionar uma variável de membro para a classe de caixa de diálogo  
  
1.  Exibição de classe, clique com botão direito a classe principal da caixa de diálogo para abrir o menu de atalho. Por exemplo, `CContainerDlg`.  
  
2.  No menu de atalho, clique em **adicionar** e **Adicionar variável**.  
  
3.  No Assistente para Adicionar variável de membro, clique em **variável de controle**.  
  
4.  No **ID de controle** caixa de listagem, selecione a ID do controle do controle ActiveX incorporado. Por exemplo, `IDC_CIRCCTRL1`.  
  
5.  No **nome da variável** , digite um nome.  
  
     Por exemplo, `m_circctl`.  
  
6.  Clique em **concluir** para aceitar as opções e sair do Assistente de variável de membro adicionar.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

