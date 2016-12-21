---
title: "Caixa de di&#225;logo Entrada e Sa&#237;da, Ferramenta de Manifesto, Propriedades de Configura&#231;&#227;o, P&#225;ginas de Propriedade de &lt;Projectname&gt; | Microsoft Docs"
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
  - "VC.Project.VCManifestTool.OutputManifestFile"
  - "VC.Project.VCManifestTool.InputResourceManifests"
  - "VC.Project.VCManifestTool.EmbedManifest"
  - "VC.Project.VCManifestTool.AdditionalManifestFiles"
  - "VC.Project.VCManifestTool.DependencyInformationFile"
  - "VC.Project.VCManifestTool.OutputResourceManifest"
  - "VC.Project.VCManifestTool.GenerateCatalogFiles"
dev_langs: 
  - "C++"
ms.assetid: a8bb20f6-7ace-45ca-bab0-b4f4a5caf170
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixa de di&#225;logo Entrada e Sa&#237;da, Ferramenta de Manifesto, Propriedades de Configura&#231;&#227;o, P&#225;ginas de Propriedade de &lt;Projectname&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use essa caixa de diálogo para especificar as opções de entrada e saídas de  [Mt.exe](http://msdn.microsoft.com/library/aa375649).  
  
 Para acessar esta caixa de diálogo da página de propriedade, abra as páginas de propriedades para o seu projeto ou sua folha de propriedades.  Expanda o  **Ferramenta de manifesto** nó em  **Propriedades de configuração**e selecione  **de entrada e saída**.  
  
## Lista UIElement  
 **Arquivos de manifesto adicionais**  
 Usa a **\/manifest** opção para especificar os caminhos completos dos arquivos de manifesto adicionais que processará a ferramenta de manifesto ou de mesclagem.  Caminhos completos são delimitados por ponto e vírgula.  
  
 **Manifestos de recurso de entrada**  
 Usa a **\/inputresource** opção para especificar o caminho completo de um recurso do tipo RT\_MANIFEST, para a entrada para a ferramenta de manifesto.  O caminho pode ser seguido do ID do recurso especificado.  Por exemplo:  
  
 `dll_with_manifest.dll;#1`  
  
 A identificação do recurso é opcional e o padrão é CREATEPROCESS\_MANIFEST\_RESOURCE\_ID em WinUser. h.  
  
 **Manifesto incorporado**  
 **Sim** Especifica que o sistema do projeto irá incorporar o arquivo de manifesto do aplicativo no assembly.  
  
 **Não** Especifica que o sistema do projeto irá criar o arquivo de manifesto do aplicativo como um arquivo autônomo.  
  
 **Arquivo de manifesto de saída**  
 Especifica o nome do arquivo de manifesto de saída.  Esta propriedade é opcional quando somente um arquivo de manifesto é operado pela ferramenta de manifesto.  
  
 **Arquivo de recurso de manifesto**  
 Especifica a saída de arquivos de recursos usados para incorporar o manifesto na saída do projeto.  
  
 **Gerar arquivos de catálogo**  
 Usa a **\/makecdfs** opção para especificar que a ferramenta de manifesto irá gerar arquivos de definição de catálogo \(arquivos. CDF\), que são usados para criar catálogos.  
  
 **Gere o manifesto do ManagedAssembly**  
 Gera um manifesto de um assembly gerenciado.  \(**\-managedassemblyname:***file*\).  
  
 **Suprimir o elemento de dependência**  
 Usado com o **\-managedassembly** opção.  Esta marca suprime a geração de elementos de dependência no manifesto do final.  
  
 **Gerar marcas de categoria**  
 Usado com o **\-managedassembly** opção.  Esta marca faz com que as marcas de categoria a ser gerado.  
  
 **Habilitar o reconhecimento DPI**  
 Especifica se o aplicativo com reconhecimento de DPI.  Por padrão, a configuração é  **Sim** para projetos MFC e  **não** caso contrário, porque somente a projetos MFC criaram no reconhecimento de DPI.  Você pode substituir a configuração para  **Sim** se você adicionar código para tratar diferentes configurações DPI.  Seu aplicativo pode aparecer distorcida ou pequenas, se você definir como o reconhecimento de DPI, quando não estiver.  
  
## Consulte também  
 [Manifesto de aplicativo ClickOnce](../Topic/ClickOnce%20Application%20Manifest.md)   
 [Páginas de propriedades Ferramenta de Manifesto](../ide/manifest-tool-property-pages.md)   
 [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md)   
 [Como editar folhas de propriedades do projeto](../misc/how-to-edit-project-property-sheets.md)