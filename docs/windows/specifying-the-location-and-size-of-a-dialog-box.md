---
title: "Especificando o local e o tamanho de uma caixa de di&#225;logo | Microsoft Docs"
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
  - "caixas de diálogo, posicionando"
  - "caixas de diálogo,  (tamanho)"
ms.assetid: 2b7c495e-6595-4cfb-9664-80b2826d0851
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificando o local e o tamanho de uma caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O local e o tamanho de uma caixa de diálogo, bem como o local e tamanho dos controles dentro dele, são medidos em unidades de diálogo.  Os valores para controles individuais e a caixa de diálogo é exibida no canto inferior direito da barra quando você seleciona, o status de Visual Studio.  
  
 Há três propriedades que podem ser definidas no  [Janela Propriedades do](../Topic/Properties%20Window.md) para especificar onde uma caixa de diálogo será exibida na tela.  A propriedade do centro é booleano; Se você definir o valor como True, a caixa de diálogo sempre aparecerá no centro da tela.  Se você defini\-la como False, você pode então definir as propriedades XPos e YPos para definir explicitamente onde na tela para que a caixa de diálogo será exibida.  As propriedades de posição são valores de deslocamento a partir do canto superior esquerdo da área de visualização, que é definido como {X \= 0, Y \= 0}.  A posição também se baseia o  **Alinhar absoluto** propriedade: se for True, as coordenadas são em relação à tela; Se for falso, as coordenadas são em relação à janela do proprietário da caixa de diálogo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Controles em caixas de diálogo](../mfc/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)