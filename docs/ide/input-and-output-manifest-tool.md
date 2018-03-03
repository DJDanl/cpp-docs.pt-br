---
title: "Manifesto de ferramenta propriedades de entrada e saída (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCManifestTool.OutputManifestFile
- VC.Project.VCManifestTool.InputResourceManifests
- VC.Project.VCManifestTool.EmbedManifest
- VC.Project.VCManifestTool.AdditionalManifestFiles
- VC.Project.VCManifestTool.DependencyInformationFile
- VC.Project.VCManifestTool.OutputResourceManifest
- VC.Project.VCManifestTool.GenerateCatalogFiles
dev_langs:
- C++
ms.assetid: a8bb20f6-7ace-45ca-bab0-b4f4a5caf170
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 77137e9bc0a4af60080234aac85afa59034d2c6a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="input-and-output-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Entrada e saída, a ferramenta, propriedades de configuração de manifesto &lt;Projectname&gt; caixa de diálogo de páginas de propriedades
Use essa caixa de diálogo para especificar opções de entrada e saídas para [Mt.exe](http://msdn.microsoft.com/library/aa375649).  
  
 Para acessar essa caixa de diálogo de página de propriedade, abra as páginas de propriedades para o projeto ou a folha de propriedades. Expanda o **ferramenta de manifesto** nó **propriedades de configuração**e, em seguida, selecione **de entrada e saída**.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Arquivos de manifesto adicionais**  
 Usa o **/manifesto** opção para especificar os caminhos completos de arquivos de manifesto adicionais que processará a ferramenta de manifesto ou de mesclagem. Caminhos completos são delimitados por ponto e vírgula.  
  
 **Manifestos de recurso de entrada**  
 Usa o **/inputresource** opção para especificar o caminho completo de um recurso do tipo RT_MANIFEST, a entrada para a ferramenta de manifesto. O caminho pode ser seguido pela ID de recurso especificado. Por exemplo:  
  
 `dll_with_manifest.dll;#1`  
  
 A ID de recurso é opcional e o padrão é CREATEPROCESS_MANIFEST_RESOURCE_ID em winuser.  
  
 **Inserir manifesto**  
 **Sim** Especifica que o sistema de projeto incorporar o arquivo de manifesto do aplicativo no assembly.  
  
 **Não** Especifica que o sistema de projeto irá criar o arquivo de manifesto do aplicativo como um arquivo autônomo.  
  
 **Arquivo de manifesto de saída**  
 Especifica o nome do arquivo de manifesto de saída. Essa propriedade é opcional quando apenas um arquivo de manifesto é operado pela ferramenta de manifesto.  
  
 **Arquivo de recurso de manifesto**  
 Especifica a saída que os arquivos de recursos usados para inserir o manifesto na saída do projeto.  
  
 **Gerar arquivos de catálogo**  
 Usa o **/makecdfs** opção para especificar que a ferramenta de manifesto irá gerar arquivos de definição de catálogo (arquivos. CDF), que são usados para criar catálogos.  
  
 **Gerar manifesto a partir de ManagedAssembly**  
 Gera um manifesto de um assembly gerenciado. (**- managedassemblyname:***arquivo*).  
  
 **Suprimir o elemento de dependência**  
 Usado com o **- managedassembly** opção. Essa marca suprime a geração de elementos de dependência no manifesto final.  
  
 **Gerar rótulos de categoria**  
 Usado com o **- managedassembly** opção. Essa marca fará com que os rótulos de categoria a ser gerado.  
  
 **Habilitar o reconhecimento DPI**  
 Especifica se o aplicativo com reconhecimento de DPI. Por padrão, a configuração é **Sim** para projetos MFC e **não** caso contrário, porque apenas os projetos MFC criados no reconhecimento DPI. Você pode substituir a configuração para **Sim** se você adicionar código para lidar com diferentes configurações de DPI. Seu aplicativo pode aparecer difusa ou pequeno se você defini-lo como reconhecimento de DPI quando não for.  
  
## <a name="see-also"></a>Consulte também  
 [Manifesto do aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)   
 [Páginas de propriedade da ferramenta de manifesto](../ide/manifest-tool-property-pages.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)   