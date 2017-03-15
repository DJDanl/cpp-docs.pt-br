---
title: "Cont&#234;ineres de controle ActiveX: conectando um controle ActiveX a uma vari&#225;vel membro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Contêineres de controle ActiveX [C++], acessando controles ActiveX"
  - "Contêineres de controle ActiveX [C++], Controles ActiveX como variáveis de membro"
  - "Controles ActiveX [C++], acessando"
  - "Controles ActiveX [C++], variáveis de membro de projeto"
  - "conectando controles ActiveX a variáveis de membro de contêiner"
  - "variáveis de membro [C++], Controles ActiveX no projeto"
ms.assetid: 7898a336-440d-4a60-be43-cb062b807aee
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres de controle ActiveX: conectando um controle ActiveX a uma vari&#225;vel membro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira mais fácil de acessar um controle ActiveX de dentro de seu aplicativo de contêiner do controle é associar o controle ActiveX com uma variável de membro da classe da caixa de diálogo que conterá o controle.  
  
> [!NOTE]
>  Esta não é a única forma de acessar um controle inserido dentro de uma classe do contêiner, mas para fins deste artigo é suficiente.  
  
### Adicionando uma variável de membro à classe da caixa de diálogo  
  
1.  Em vez da classe, clique com o botão direito do mouse na classe principal da caixa de diálogo para abrir o menu de atalho.  Por exemplo, `CContainerDlg`.  
  
2.  No menu de atalho, clique **Adicionar** e depois **Adicionar variável**.  
  
3.  No assistente variável de membro adicionar, clique **Control variable**.  
  
4.  Na caixa de listagem de **ID de Controle** , selecione a ID do controle ActiveX inserido.  Por exemplo, `IDC_CIRCCTRL1`.  
  
5.  Na caixa de **Nome da variável** , digite um nome.  
  
     Por exemplo, `m_circctl`.  
  
6.  Clique em para aceitar **Concluir** suas opções e para sair do assistente da variável de membro adicionar.  
  
## Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)