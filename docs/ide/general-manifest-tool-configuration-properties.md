---
title: "Caixa de di&#225;logo Geral, Ferramenta de Manifesto, Propriedades de Configura&#231;&#227;o, P&#225;ginas de Propriedade de &lt;Projectname&gt; | Microsoft Docs"
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
  - "VC.Project.VCManifestTool.MergeRulesFile"
  - "VC.Project.VCManifestTool.UseUnicodeResponseFiles"
  - "VC.Project.VCManifestTool.SuppressStartupBanner"
  - "VC.Project.VCManifestTool.UseFAT32Workaround"
  - "VC.Project.VCManifestTool.VerboseOutput"
  - "VC.Project.VCManifestTool.AssemblyIdentity"
dev_langs: 
  - "C++"
ms.assetid: b99368a5-6819-482c-a06e-f2409290cfd1
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixa de di&#225;logo Geral, Ferramenta de Manifesto, Propriedades de Configura&#231;&#227;o, P&#225;ginas de Propriedade de &lt;Projectname&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use essa caixa de diálogo para especificar opções gerais para  [Mt.exe](http://msdn.microsoft.com/library/aa375649).  
  
 Para acessar esta caixa de diálogo da página de propriedade, abra as páginas de propriedades para o seu projeto ou sua folha de propriedades.  Expanda o  **Ferramenta de manifesto** nó em  **Propriedades de configuração**e selecione  **Geral**.  
  
## Lista UIElement  
 **Suprimir faixa de inicialização**  
 **Sim \(\/ \/nologo\)** Especifica que dados de direitos autorais Microsoft padrão serão ocultos quando a ferramenta de manifesto é iniciada.  Use esta opção para suprimir a saída indesejados nos arquivos de log, quando você executa o mt.exe como parte de um processo de compilação ou de um ambiente de compilação.  
  
 **Saída detalhada**  
 **Sim \(\/verbose\)** Especifica que as informações de compilação adicionais serão exibidas durante a geração de manifesto.  
  
 **Identidade do assembly**  
 Usa a opção \/identity para especificar uma cadeia de identidade, que compreendem os atributos para o [Elemento \<assemblyIdentity\>](../Topic/%3CassemblyIdentity%3E%20Element%20\(ClickOnce%20Application\).md).  Uma seqüência de caracteres de identidade começa com o valor para o `name` de atributo e é seguido por  *atributo* \=  *valor* pares.  Os atributos de uma cadeia de caracteres de identidade são delimitados por vírgulas.  
  
 Este é um exemplo de seqüência de identidade:  
  
 `Microsoft.Windows.Common-Controls, processorArchitecture=x86, version=6.0.0.0, type=win32, publicKeyToken=6595b64144ccf1df`  
  
## Consulte também  
 [Manifesto de aplicativo ClickOnce](../Topic/ClickOnce%20Application%20Manifest.md)   
 [Páginas de propriedades Ferramenta de Manifesto](../ide/manifest-tool-property-pages.md)   
 [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md)   
 [Como editar folhas de propriedades do projeto](../misc/how-to-edit-project-property-sheets.md)