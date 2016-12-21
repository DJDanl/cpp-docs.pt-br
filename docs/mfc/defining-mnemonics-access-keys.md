---
title: "Definindo mnem&#244;nica (teclas de acesso) | Microsoft Docs"
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
  - "chaves de acesso [C++]"
  - "chaves de acesso [C++], adicionando"
  - "chaves de acesso [C++], verificando"
  - "Comando Verificar Mnemônico"
  - "controles [C++], teclas de acesso"
  - "controles de caixas de diálogo, mnemônico"
  - "atalhos de teclado [C++], controles"
  - "atalhos de teclado [C++], verificação de exclusividade"
  - "mnemônico"
  - "mnemônico, verificando a existência de duplicações"
  - "mnemônico, controles de caixas de diálogo"
ms.assetid: 60a85435-aa30-4c5c-98b6-42fb045b9eb2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo mnem&#244;nica (teclas de acesso)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Normalmente, os usuários de teclado mover o foco de entrada de um controle para outro em uma caixa de diálogo com as teclas de direção e TAB.  No entanto, você pode definir uma tecla de acesso \(um nome mnemônico ou fácil de lembrar\) que permite que os usuários escolham um controle pressionando uma única chave.  
  
### Para definir uma tecla de acesso para um controle com uma legenda visível \(botões de ação, caixas de seleção e botões de opção\)  
  
1.  Selecione o controle na caixa de diálogo.  
  
2.  No  [Janela Propriedades do](../Topic/Properties%20Window.md), no  **legenda** propriedade, digite um novo nome para o controle, digitando um e comercial \(**&**\) na frente da letra que deseja como a chave de acesso para o controle.  Por exemplo, `&Radio1`.  
  
3.  Pressione  **Digite**.  
  
     Um sublinhado aparece na legenda exibida para indicar a chave de acesso, por exemplo,  **r**adio1.  
  
### Para definir uma tecla de acesso para um controle sem uma legenda visível  
  
1.  Fazer uma legenda para o controle, usando um  **Texto estático** controlar no  [caixa de ferramentas](../Topic/Toolbox.md).  
  
2.  Na legenda de texto estático, digite um e comercial \(**e**\) na frente da letra que deseja como a tecla de acesso.  
  
3.  Verifique se que o controle de texto estático imediatamente precede o controle que ele rotula na ordem de tabulação.  
  
 Todas as chaves de acesso dentro de uma caixa de diálogo devem ser exclusivas.  
  
#### Para verificar se as teclas de acesso duplicadas  
  
1.  Sobre o  **formato** menu, clique em  **Verificar mnemônicos**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
### Requisitos  
 Win32  
  
## Consulte também  
 [Controles em caixas de diálogo](../mfc/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)