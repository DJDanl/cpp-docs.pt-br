---
title: "Testando uma caixa de di&#225;logo | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "Comando Testar Caixa de Diálogo"
  - "teste, caixas de diálogo"
  - "caixas de diálogo, testando"
ms.assetid: 45034ee9-c554-4f4b-8c46-6ddefdee8951
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Testando uma caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você estiver criando uma caixa de diálogo, você pode simular e testar seu comportamento de tempo de execução sem compilar seu programa. Nesse modo, você pode:  
  
-   Digite um texto, selecione nas listas de caixa de combinação, ativar ou desativar as opções e escolher comandos.  
  
-   Teste a ordem de tabulação.  
  
-   Teste o agrupamento de controles como caixas de seleção e botões de opção.  
  
-   Teste os atalhos de teclado para controles na caixa de diálogo.  
  
    > [!NOTE]
    >  Conexões feitas por meio de assistentes de código de caixa de diálogo não são incluídos na simulação.  
  
 Quando você testa uma caixa de diálogo, normalmente exibe em um local relativo a janela principal do programa. Se você definiu a propriedade de alinhar absoluto da caixa de diálogo como True, a caixa de diálogo exibe em uma posição em relação ao canto superior esquerdo da tela.  
  
### Para testar uma caixa de diálogo  
  
1.  Quando o editor de diálogo é a janela ativa, na barra de menus, escolha **formato**, **caixa de diálogo testar**.  
  
2.  Para finalizar a simulação, pressione Esc ou escolha o **Fechar** botão na caixa de diálogo que você está testando.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos de área de trabalho](../Topic/Resources%20in%20Desktop%20Apps.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Controles em caixas de diálogo](../mfc/controls-in-dialog-boxes.md)   
 [Editor de Caixa de Diálogo](../mfc/dialog-editor.md)   
 [Mostrando ou ocultando a barra de ferramentas Editor de Caixa de Diálogo](../mfc/showing-or-hiding-the-dialog-editor-toolbar.md)