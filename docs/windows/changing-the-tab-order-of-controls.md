---
title: "Alterando a ordem de guia dos controles | Microsoft Docs"
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
  - "controles [C++], foco"
  - "controles [C++], ordem das guias"
  - "controles de caixas de diálogo, ordem das guias"
  - "foco, ordem das guias"
  - "controles de guia, ordem das guias"
  - "Propriedade de parada de tabulação para controles"
ms.assetid: e2cee764-4367-42d7-9563-65a68f76f5ff
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alterando a ordem de guia dos controles
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A ordem de tabulação é a ordem na qual a tecla TAB move o foco de entrada de um controle para o próximo dentro de uma caixa de diálogo.  Geralmente, a ordem de tabulação prosseguirá da esquerda para a direita e de cima para baixo em uma caixa de diálogo.  Cada controle tem um  **Tabstop**  propriedade que determina se um controle recebe foco de entrada.  
  
### Para definir o foco de entrada para um controle  
  
1.  No  [Janela Propriedades do](../Topic/Properties%20Window.md), selecione  **True** ou  **False** na  **Tabstop** propriedade.  
  
 Controles, mesmo que não possuem a propriedade Tabstop definida como verdadeira necessidade de fazer parte da ordem de tabulação.  Isso pode ser importante, por exemplo, quando você  [Definir teclas de acesso \(mnemônicos\)](../mfc/defining-mnemonics-access-keys.md) para controles que não têm legendas.  Texto estático que contém uma chave de acesso para um controle relacionado deve preceder imediatamente o controle relacionado na ordem de tabulação.  
  
> [!NOTE]
>  Se a sua caixa de diálogo contém controles sobrepostos, alterando a ordem de tabulação pode alterar a maneira como os controles são exibidos.  Controles que são fornecidos posteriormente na ordem de tabulação são sempre exibidos na parte superior do todos os controles sobrepostos que precedem\-los na ordem de tabulação.  
  
#### Para exibir a ordem de tabulação atual para todos os controles em uma caixa de diálogo  
  
1.  Sobre o  **formato** menu, clique em  **Ordem de tabulação**.  
  
 \- ou \-  
  
-   Pressione CTRL \+ d.  
  
#### Para alterar a ordem de tabulação para todos os controles em uma caixa de diálogo  
  
1.  Sobre o  **formato** menu, clique em  **Ordem de tabulação**.  
  
     Um número no canto superior esquerdo de cada controle mostra seu lugar na ordem de tabulação atual.  
  
2.  Defina a ordem de tabulação clicando em cada controle na ordem que você deseja que a tecla TAB para seguir.  
  
3.  Pressione  **ENTER** para sair do  **Ordem de tabulação** modo.  
  
    > [!TIP]
    >  Depois que você entra no modo de ordem de tabulação, você pode pressionar ESC ou ENTER para desativar a capacidade para alterar a ordem de tabulação.  
  
#### Para alterar a ordem de tabulação para dois ou mais controles  
  
1.  Do  **formato** menu, escolha  **Ordem de tabulação**.  
  
2.  Especifique onde começará a alteração na ordem.  Para fazer isso, mantenha pressionada a  **CTRL** chave e clique no controle antes para aquele onde você deseja que a ordem alterada para começar.  
  
     Por exemplo, se você quiser alterar a ordem dos controles de 7 a 9, mantenha a tecla CTRL pressionada e selecione o controle 6 pela primeira vez.  
  
    > [!NOTE]
    >  Para definir um controle específico para o número 1 \(primeiro na ordem de tabulação\), clique duas vezes no controle.  
  
3.  Solte a tecla CTRL e clique em controles na ordem que você deseja que a tecla TAB para seguir a partir desse ponto.  
  
4.  Pressione  **ENTER** para sair do  **Ordem de tabulação** modo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
### Requisitos  
 Win32  
  
## Consulte também  
 [Organização de controles em caixas de diálogo](../mfc/arrangement-of-controls-on-dialog-boxes.md)   
 [Controles em caixas de diálogo](../mfc/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)