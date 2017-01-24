---
title: "Caixa de di&#225;logo Novo Recurso da Barra de Ferramentas | Microsoft Docs"
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
  - "vc.editors.newtoolbarresource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Caixa de diálogo Novo Recurso da Barra de Ferramentas"
ms.assetid: 52dd01ad-e748-4ab2-b3eb-59f5df990ca6
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixa de di&#225;logo Novo Recurso da Barra de Ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A caixa de diálogo novo recurso da barra de ferramentas permite que você especifique a largura e altura dos botões que você está adicionando a um recurso da barra de ferramentas.  O padrão é 16 × 15 pixels.  
  
 Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048.  Portanto, se você definir a  **Largura do botão** a 512, você só pode ter quatro botões.  Se você definir a largura para 513, você só pode ter três botões.  
  
 **Largura do botão**  
 Fornece um espaço para você digitar a largura dos botões da barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas.  As imagens são cortadas para a largura e altura especificada e as cores são ajustadas para usar cores de barra de ferramentas padrão \(16 cores\).  
  
 **Altura do botão**  
 Fornece um espaço para que você insira a altura para os botões da barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas.  As imagens são cortadas para a largura e altura especificada e as cores são ajustadas para usar cores de barra de ferramentas padrão \(16 cores\).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 MFC ou ATL  
  
## Consulte também  
 [Propriedades do botão da barra de ferramentas](../mfc/toolbar-button-properties.md)   
 [Convertendo bitmaps em barras de ferramentas](../mfc/converting-bitmaps-to-toolbars.md)   
 [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)