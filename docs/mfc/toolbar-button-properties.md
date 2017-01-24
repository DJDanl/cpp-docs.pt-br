---
title: "Propriedades do bot&#227;o da barra de ferramentas | Microsoft Docs"
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
  - "IDs de comando, botões da barra de ferramentas"
  - " (tamanho), botões da barra de ferramentas"
  - "barras de status, texto em botões da barra de ferramentas ativa"
  - "botões de barra de ferramentas (no Editor de barra de ferramentas), configurando propriedades"
  - "Editor da barra de ferramentas, propriedades de botão da barra de ferramentas"
  - "largura, botões da barra de ferramentas"
ms.assetid: b2705814-7c5d-4f24-8f77-07559b0cdda2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Propriedades do bot&#227;o da barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As propriedades de um botão da barra de ferramentas são:  
  
|Propriedade|Descrição|  
|-----------------|---------------|  
|**ID**|Define a identificação para o botão.  A lista drop\-down fornece comuns  **ID** nomes.|  
|**Width**|Define a largura do botão.  Recomenda\-se 16 pixels.|  
|**Height**|Define a altura do botão.  Observe que a altura de um botão altera a altura de todos os botões na barra de ferramentas.  é recomendável 15 pixels.|  
|**Prompt**|Define a mensagem exibida na barra de status.  Adicionar um nome e \\n adiciona uma dica de ferramenta ao botão da barra de ferramentas.  Para obter mais informações, consulte  [criar uma dica de ferramenta](../mfc/creating-a-tool-tip-for-a-toolbar-button.md).|  
  
 **Largura** e  **altura** se aplicam a todos os botões.  Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048.  Portanto, se você definir a largura do botão a 512, você só pode ter quatro botões e se você definir a largura para 513, você só pode ter três botões.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 MFC ou ATL  
  
## Consulte também  
 [Alterando as propriedades de um botão da barra de ferramentas](../mfc/changing-the-properties-of-a-toolbar-button.md)   
 [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)