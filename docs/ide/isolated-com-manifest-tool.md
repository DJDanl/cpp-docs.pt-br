---
title: "Caixa de di&#225;logo COM Isolado, Ferramenta de Manifesto, Propriedades de Configura&#231;&#227;o, P&#225;ginas de Propriedade de &lt;Projectname&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCManifestTool.RegistrarScriptFile"
  - "VC.Project.VCManifestTool.ComponentFileName"
  - "VC.Project.VCManifestTool.TypeLibraryFile"
  - "VC.Project.VCManifestTool.ReplacementsFile"
dev_langs: 
  - "C++"
ms.assetid: 457582b8-cfde-49c0-92e3-3a6b9e8c08eb
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixa de di&#225;logo COM Isolado, Ferramenta de Manifesto, Propriedades de Configura&#231;&#227;o, P&#225;ginas de Propriedade de &lt;Projectname&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use essa caixa de diálogo para especificar  **Isolado COM** opções para  [Mt.exe](http://msdn.microsoft.com/library/aa375649).  
  
 Para acessar esta caixa de diálogo da página de propriedade, abra as páginas de propriedades para o seu projeto ou sua folha de propriedades.  Expanda o  **Ferramenta de manifesto** nó em  **Propriedades comuns**e selecione  **Isolado COM**.  
  
## Lista de Tarefas  
  
-   [Como compilar aplicativos isolados para consumir componentes COM](../Topic/How%20to:%20Build%20Isolated%20Applications%20to%20Consume%20COM%20Components.md)  
  
## Lista UIElement  
 **Arquivo de biblioteca de tipo**  
 Usa a opção \/tlb para especificar o nome do arquivo de biblioteca tipo \(arquivo. tlb\) que usará a ferramenta de manifesto para gerar o arquivo de manifesto.  
  
 **Arquivo de Script de registrador**  
 Usa a opção \/rgs para especificar o nome do arquivo de script registrador \(arquivo. rgs\) que usará a ferramenta de manifesto para gerar o arquivo de manifesto.  
  
 **Nome de arquivo do componente**  
 Usa a opção \/dll para especificar o nome do recurso que geram a ferramenta de manifesto.  Você deve inserir um valor para essa propriedade quando valores para um  **Arquivo de biblioteca de tipo** ou  **Arquivo de Script de registrador** são especificados.  
  
 **Arquivo de substituições**  
 Usa a opção \/replacements para especificar o caminho completo para o arquivo que contém valores de seqüências de caracteres substituíveis em arquivo. rgs.  
  
## Consulte também  
 [Aplicativos isolados](http://msdn.microsoft.com/library/aa375190)   
 [conjuntos lado a lado](_win32_side_by_side_assemblies)   
 [Manifesto de aplicativo ClickOnce](../Topic/ClickOnce%20Application%20Manifest.md)   
 [Páginas de propriedades Ferramenta de Manifesto](../ide/manifest-tool-property-pages.md)   
 [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md)   
 [Como editar folhas de propriedades do projeto](../misc/how-to-edit-project-property-sheets.md)