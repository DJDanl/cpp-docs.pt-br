---
title: "Agrupando bot&#245;es de op&#231;&#227;o em uma caixa de di&#225;logo | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.dialog.grouping"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "controles de caixas de diálogo, agrupando botões de opção"
  - "agrupando controles"
  - "variáveis de membro, adicionando a grupos de botões de opção"
  - "botões de opção, agrupando em caixas de diálogo"
  - "variáveis, variáveis de membro de controle de caixa de diálogo"
ms.assetid: 3cc43f9e-56c8-4faa-9930-ce81733c69de
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Agrupando bot&#245;es de op&#231;&#227;o em uma caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você adiciona botões de opção em uma caixa de diálogo, tratá\-los como um grupo, definindo uma propriedade de grupo na janela Propriedades para o primeiro botão no grupo. Uma ID de controle para esse botão aparece no [Assistente para adição de variável de membro](../ide/add-member-variable-wizard.md), permitindo que você adicione uma variável de membro do grupo de botões de opção.  
  
 Você pode ter mais de um grupo de botões de opção em uma caixa de diálogo, e cada grupo deve ser adicionado usando o procedimento a seguir.  
  
### Para adicionar um grupo de botões de opção em uma caixa de diálogo  
  
1.  Selecione o controle de botão de opção no [janela Toolbox](../Topic/Toolbox.md) e clique no local na caixa de diálogo onde você deseja colocar o controle.  
  
2.  Repita a etapa 1 para adicionar botões de opção quantas forem necessárias. Certifique\-se de que os botões de opção no grupo são consecutivos na ordem de tabulação \(para obter mais informações, consulte [alterando a ordem dos controles de guia](../mfc/changing-the-tab-order-of-controls.md)\).  
  
3.  No [janela propriedades](../Topic/Properties%20Window.md), defina o **grupo** propriedade o *primeiro* botão na ordem de tabulação para **True**.  
  
     Alterando o **grupo** propriedade **True** adiciona o estilo WS\_GROUP a entrada do botão no objeto de caixa de diálogo do script de recurso e garante que um usuário pode selecionar apenas um botão de rádio por vez no grupo de botões \(quando o usuário clica em um botão de opção, os outros no grupo são desmarcados\).  
  
    > [!NOTE]
    >  Somente o primeiro botão de opção do grupo deve ter o **grupo** definida como **True**. Se você tiver controles adicionais que não fazem parte do grupo de botões, defina o **grupo** propriedade do primeiro controle *que está fora do grupo* para **True** também. Você pode identificar rapidamente o primeiro controle fora do grupo, pressionando CTRL \+ D para exibir a ordem de tabulação.  
  
### Para adicionar uma variável de membro para o grupo de botões de opção  
  
1.  Clique com botão direito do controle de botão de rádio primeiro na ordem de tabulação \(o controle dominante e com a **grupo** propriedade definida como True\).  
  
2.  Escolha **Adicionar variável** no menu de atalho.  
  
3.  No [Assistente Adicionar variável membro](../ide/add-member-variable-wizard.md), selecione o **variável de controle** caixa de seleção e, em seguida, selecione o **valor** botão de opção.  
  
4.  No **nome de variável** digite um nome para a nova variável de membro.  
  
5.  No **tipo de variável** caixa de listagem, selecione **int** ou tipo **int**.  
  
6.  Agora você pode modificar seu código para especificar qual botão de opção deverá aparecer selecionado. Por exemplo, m\_radioBox1 \= 0; Seleciona o primeiro botão de opção no grupo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Organização de controles em caixas de diálogo](../mfc/arrangement-of-controls-on-dialog-boxes.md)   
 [Controles em caixas de diálogo](../mfc/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)