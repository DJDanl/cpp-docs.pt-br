---
title: "Fornecendo ajuda contextual | Microsoft Docs"
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
  - "Ajuda contextual"
  - "Ajuda contextual, Assistente Personalizado"
  - "assistentes personalizados, implementando Ajuda"
ms.assetid: c6c4d961-29d3-4d16-9f39-b12545aba540
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fornecendo ajuda contextual
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você usa o  [Assistente personalizada](../Topic/Application%20Settings,%20Custom%20Wizard.md) para criar um assistente, ele insere um  **Help** botão no seu assistente.  
  
 Cada arquivo. htm no seu projeto inclui o seguinte código para fornecer suporte para o  **Help** o botão do assistente.  
  
```  
<BUTTON CLASS="BUTTONS" ID="HelpBtn" ACCESSKEY="H"  
 onClick="window.external.OnHelp('vc.appwiz.custom.overview');">  
```  
  
 O <xref:Microsoft.VisualStudio.VsWizard.VCWizCtlClass.OnHelp%2A> Especifica a palavra\-chave do arquivo de Ajuda em HTML associado a essa página do assistente.  Para obter mais informações sobre como criar arquivos de Ajuda em HTML para associar com a página, consulte  [HTML Help Start Page](vsconhh1start).  Para fornecer sua própria ajuda para esta página do assistente, você deve substituir a seqüência de caracteres `'vc.appwiz.custom.overview'` com a palavra\-chave que identifica o tópico de Ajuda em HTML da página.  
  
 **Nota** esse arquivo. htm não pode ser integrado a Ajuda do MSDN compilado.  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)