---
title: "Projetando um assistente | Microsoft Docs"
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
  - "assistentes personalizados [C++], projetando para projetos"
  - "projetos [C++], assistentes personalizados"
  - "Projetos Visual C++, assistentes personalizados"
  - "assistentes [C++], personalizado"
ms.assetid: a7c0be7e-9297-4fed-83e3-5645c896d56b
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Projetando um assistente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Talvez você precise criar projetos com recursos padronizados que diferem dos assistentes de aplicativo que são fornecidos no Visual C\+\+.  Para executar tarefas, você pode usar a arquitetura de Assistente do Visual C\+\+, destina\-se a personalização e extensibilidade fácil.  Você pode criar um assistente usando o  [Assistente personalizada do Visual C\+\+](../ide/creating-a-custom-wizard.md).  Depois de criar seu assistente, você pode configurá\-lo para gerar os arquivos de starter que necessários para seus projetos.  
  
 Um Assistente do Visual C\+\+ é um controle HTML.  Ele usa o mecanismo de Assistente do Visual C\+\+, <xref:Microsoft.VisualStudio.VsWizard.IVCWizCtlUI>, que oferece serviços comuns, como <xref:Microsoft.VisualStudio.VsWizard.IVCWizCtlUI.NavigateToCommandHandler%2A>, <xref:Microsoft.VisualStudio.VsWizard.IVCWizCtlUI.OkCancelAlert%2A>e assim por diante.  O assistente também usa o mecanismo de script, que permite que um Assistente para entender os dois VBScript e [JScript .NET](http://msdn.microsoft.com/pt-br/c7e636ee-c10f-45b1-85ec-fe2daca30bf5).  
  
 A arquitetura do assistente permite que você acesse os seguintes modelos de objeto diretamente em seus assistentes e chamar seus métodos, propriedades e eventos de arquivos HTML ou o JScript.  \(Veja os exemplos em  [Os arquivos HTML](../ide/html-files.md) e  [O arquivo JScript](../ide/jscript-file.md) para obter mais informações.\)  
  
-   [Modelo de objeto de ambiente \(DTE\) de ferramentas de desenvolvedor](../Topic/Extending%20the%20Visual%20Studio%20Environment.md)  
  
-   [Modelo de código C\+\+ Visual](http://msdn.microsoft.com/pt-br/dd6452c2-1054-44a1-b0eb-639a94a1216b)  
  
-   [Modelo do Visual C\+\+ Project](http://msdn.microsoft.com/pt-br/06c1bbd9-4c79-4f97-ad6d-2b1dea8ecd1f)  
  
-   [Modelo do Visual C\+\+ Assistente](http://msdn.microsoft.com/pt-br/159395ac-33c7-47bf-ad42-4e1435ddc758)  
  
 Consulte  [Arquivos criados para o Assistente para o](../ide/files-created-for-your-wizard.md) para obter uma descrição de cada elemento de projetar um assistente.  
  
## Consulte também  
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Etapas para projetar um assistente](../ide/steps-to-designing-a-wizard.md)   
 [Personalizando o assistente](../ide/customizing-your-wizard.md)