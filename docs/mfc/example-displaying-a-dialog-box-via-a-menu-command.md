---
title: "Exemplo: exibindo uma caixa de di&#225;logo por meio de um comando Menu | Microsoft Docs"
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
  - "caixas de diálogo, MFC"
  - "exemplos [MFC], caixas de diálogo"
  - "itens de menu, exemplos"
  - "caixas de diálogo MFC, exibindo"
  - "caixas de diálogo MFC, exemplos"
  - "caixas de diálogo modais, exibindo"
  - "caixas de diálogo sem modo, exibindo"
ms.assetid: e8692549-acd7-478f-9c5e-ba310ce8cccd
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exemplo: exibindo uma caixa de di&#225;logo por meio de um comando Menu
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico contém procedimentos:  
  
-   Exibe uma caixa de diálogo modal por um comando de menu.  
  
-   Exibe uma caixa de diálogo modeless por um comando de menu.  
  
 Ambos os procedimentos de exemplo são para aplicativos de MFC e funcionarão em um aplicativo que você cria com [Assistente do aplicativo MFC](../Topic/MFC%20Application%20Wizard.md).  
  
 Os procedimentos usam os seguintes nomes e valores:  
  
|Item|Nome ou valor|  
|----------|-------------------|  
|Aplicativo|DisplayDialog|  
|Comando de menu|Comando de teste no menu exibição; ID do comando \= ID\_VIEW\_TEST|  
|Caixa de diálogo|Caixa de diálogo de teste; Classe CTestDialog; \= Arquivo de cabeçalho TestDialog.h; \= \= Variável testdlg, ptestdlg|  
|Manipulador de comando|OnViewTest|  
  
### Para exibir uma caixa de diálogo modal  
  
1.  Crie o comando de menu; consulte [Criando menus ou itens de menu](../windows/creating-a-menu.md).  
  
2.  Crie a caixa de diálogo; consulte [Iniciando o publicador da caixa de diálogo](../mfc/creating-a-new-dialog-box.md).  
  
3.  Adicione uma classe para a caixa de diálogo.  Consulte [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md) para obter mais informações.  
  
4.  Em **Modo de Exibição de Classe**, selecione a classe do documento \(CDisplayDialogDoc\).  Na janela de **Propriedades** , clique no botão de **Eventos** .  Clique duas vezes na ID de comando de menu \(ID\_VIEW\_TEST\) no painel esquerdo da janela de **Propriedades** e selecione **Comando**.  No painel direito, clique na seta para baixo e selecione **\<Add\> OnViewTest**.  
  
     Se você adicionou o comando de menu à unidade central de um aplicativo MDI, selecione a classe do aplicativo \(CDisplayDialogApp\).  
  
5.  Adicione o seguinte incluem a instrução a CDisplayDialogDoc.cpp \(ou a CDisplayDialogApp.cpp\) depois da existência incluem instruções:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#42](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_1.cpp)]  
  
6.  Adicione o código a `OnViewTest` para implementar a função:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#43](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_2.cpp)]  
  
### Para exibir uma caixa de diálogo modeless  
  
1.  Execute as primeiras quatro etapas para exibir uma caixa de diálogo modal, a não ser que selecione a classe da exibição \(CDisplayDialogView\) na etapa 4.  
  
2.  Edição DisplayDialogView.h:  
  
    -   Declare a classe da caixa de diálogo que precede a declaração de primeira classe:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#44](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_3.h)]  
  
    -   Declare um ponteiro para a caixa de diálogo depois que a seção pública de atributos:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#45](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_4.h)]  
  
3.  Edição DisplayDialogView.cpp:  
  
    -   Adicione o seguinte incluem a instrução após a existência incluem instruções:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#42](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_1.cpp)]  
  
    -   Adicione o seguinte código para o construtor:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#46](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_5.cpp)]  
  
    -   Adicione o seguinte código ao destruidor:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#47](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_6.cpp)]  
  
    -   Adicione o código a `OnViewTest` para implementar a função:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#48](../mfc/codesnippet/CPP/example-displaying-a-dialog-box-via-a-menu-command_7.cpp)]  
  
 Além disso, consulte o seguinte artigo da Base de Dados de Conhecimento:  
  
-   Q251059: HOWTO: Forneça seu próprio nome de classe da janela para uma caixa de diálogo MFC  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Caixas de diálogo modais e sem janela restrita](../mfc/modal-and-modeless-dialog-boxes.md)