---
title: Páginas de propriedades Ferramenta de Manifesto
ms.date: 07/24/2019
ms.topic: article
f1_keywords:
- VC.Project.VCManifestTool.SuppressStartupBanner
- VC.Project.VCManifestTool.VerboseOutput
- VC.Project.VCManifestTool.AssemblyIdentity
- VC.Project.VCManifestTool.AdditionalManifestFiles
- VC.Project.VCManifestTool.InputResourceManifests
- VC.Project.VCManifestTool.EmbedManifest
- VC.Project.VCManifestTool.OutputManifestFile
- VC.Project.VCManifestTool.ResourceOutputFileName
- VC.Project.VCManifestTool.GenerateCatalogFiles
- VC.Project.VCManifestTool.ManifestFromManagedAssembly
- VC.Project.VCManifestTool.SuppressDependencyElement
- VC.Project.VCManifestTool.GenerateCategoryTags
- VC.Project.VCManifestTool.EnableDPIAwareness
- VC.Project.VCManifestTool.TypeLibraryFile
- VC.Project.VCManifestTool.RegistrarScriptFile
- VC.Project.VCManifestTool.ComponentFileName
- VC.Project.VCManifestTool.ReplacementsFile
- VC.Project.VCManifestTool.UpdateFileHashes
- VC.Project.VCManifestTool.UpdateFileHashesSearchPath
- vc.project.AdditionalOptionsPage
ms.assetid: f33499c4-7733-42d9-80e3-8a5018786965
ms.openlocfilehash: 20ca118b3aacb02333d49b67d13de30f11dc5d8d
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079495"
---
# <a name="manifest-tool-property-pages"></a>Páginas de propriedades Ferramenta de Manifesto

Use essas páginas para especificar opções gerais para [Mt. exe](/windows/win32/sbscs/mt-exe). Essas páginas são encontradas em **Propriedades** de > de **projeto** > **Propriedades de configuração** > ferramenta de **manifesto**.

## <a name="general-property-page"></a>Página de propriedades geral

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

   **Sim (/nologo)** especifica que os dados padrão de direitos autorais da Microsoft ficarão ocultos quando a ferramenta de manifesto for iniciada. Use essa opção para suprimir a saída indesejada em arquivos de log quando você executar mt.exe como parte de um processo de build ou em um ambiente de build.

### <a name="verbose-output"></a>Saída detalhada

   **Sim (/verbose)** especifica que as informações de build adicionais serão exibidas durante a geração do manifesto.

### <a name="assembly-identity"></a>Identidade do assembly * *

Usa a opção /identity para especificar uma cadeia de caracteres de identidade, que inclui os atributos para o [\<Elemento assemblyIdentity>](/visualstudio/deployment/assemblyidentity-element-clickonce-application). Uma cadeia de caracteres de identidade começa com o valor do atributo `name` e é seguida por pares *atributo* = *valor*. Os atributos de uma cadeia de caracteres de identidade são delimitados por uma vírgula.

Este é um exemplo de cadeia de caracteres de identidade: `Microsoft.Windows.Common-Controls, processorArchitecture=x86, version=6.0.0.0, type=win32, publicKeyToken=6595b64144ccf1df`

## <a name="input-and-output-property-page"></a>Página de propriedades de entrada e saída

###  <a name="additional-manifest-files"></a>Arquivos de manifesto adicionais

Usa a opção **/manifest** para especificar os caminhos completos de arquivos de manifesto adicionais que serão processados ou mesclados pela ferramenta de manifesto. Os caminhos completos são delimitados por ponto e vírgula. (-manifest [manifest1] [manifest2]...)

###  <a name="input-resource-manifests"></a>Manifestos de recurso de entrada

Usa a opção **/inputresource** para especificar o caminho completo de um recurso do tipo RT_MANIFEST, a ser inserido na ferramenta de manifesto. O caminho pode ser seguido pela ID de recurso especificada. Por exemplo:

`dll_with_manifest.dll;#1`

###  <a name="embed-manifest"></a>Inserir manifesto

- **Sim** especifica que o sistema de projeto inserirá o arquivo de manifesto do aplicativo no assembly.

- **Não** especifica que o sistema de projeto criará o arquivo de manifesto do aplicativo como um arquivo autônomo.

###  <a name="output-manifest-file"></a>Arquivo de manifesto de saída

Especifica o nome do arquivo de manifesto de saída. Essa propriedade é opcional quando apenas um arquivo de manifesto é operado pela ferramenta de manifesto. (-out: [arquivo]; # [ID do recurso])

###  <a name="manifest-resource-file"></a>Arquivo de recurso de manifesto

Especifica o arquivo de recurso de saída usado para inserir o manifesto na saída do projeto.

###  <a name="generate-catalog-files"></a>Gerar arquivos de catálogo

Usa a opção **/makecdfs** para especificar que a ferramenta de manifesto gerará arquivos de definição de catálogo (arquivos .cdf), que são usados para criar catálogos. /makecdfs

###  <a name="generate-manifest-from-managedassembly"></a>Gerar manifesto de ManagedAssembly

Gera um manifesto com base em um assembly gerenciado. (-managedassemblyname: [arquivo])

###  <a name="suppress-dependency-element"></a>Suprimir elemento de dependência

Usado com-ManagedAssembly. suprime a geração de elementos de dependência no manifesto final. (-nodependency)

###  <a name="generate-category-tags"></a>Gerar marcas de categoria

Usado com-ManagedAssembly. -Category faz com que as marcas de categoria sejam geradas. (-categoria)

###  <a name="dpi-awareness"></a>Reconhecimento de DPI

Especifica se o aplicativo tem reconhecimento de DPI. Por padrão, a configuração é **Sim** para projetos MFC e **Não** caso contrário, porque apenas os projetos MFC têm reconhecimento de DPI interno. Você poderá substituir a configuração por **Sim** se adicionar um código para lidar com diferentes configurações de DPI. O aplicativo poderá parecer difuso ou pequeno se você defini-lo como tendo reconhecimento de DPI quando ele não tiver.

**Opções**

- **Nenhuma**
- **Alto reconhecimento de DPI**
- **Reconhecimento de DPI alto por monitor**

## <a name="isolated-com-property-page"></a>Página de propriedades COM isolada

Para obter mais informações sobre COM isolado, consulte [aplicativos isolados](/windows/win32/SbsCs/isolated-applications) e [como criar aplicativos isolados para consumir componentes com](../how-to-build-isolated-applications-to-consume-com-components.md).

###  <a name="type-library-file"></a>Arquivo de biblioteca de tipos

Especifica a biblioteca de tipos a ser usada para suporte ao manifesto COM do RegFree. (-tlb: [arquivo])

###  <a name="registrar-script-file"></a>Arquivo de script do registrador

Especifica o arquivo de script do registrador a ser usado para o suporte ao manifesto COM do RegFree. (-RGS: [arquivo])

###  <a name="component-file-name"></a>Nome do arquivo de componente

Especifica o nome do arquivo do componente que é criado a partir do. tlb ou. rgs especificado. (-DLL: [arquivo])

###  <a name="replacements-file"></a>Arquivo de substituições

Especifica o arquivo que contém valores para cadeias de caracteres substituíveis no arquivo RGS. (substituições: [arquivo])

## <a name="advanced-property-page"></a>Página de propriedades avançada

###  <a name="update-file-hashes"></a>Atualizar hashes de arquivo

Computa o hash de arquivos especificados nos elementos de arquivo e atualiza o atributo de hash com esse valor. (hashupdate: [caminho])

###  <a name="update-file-hashes-search-path"></a>Atualizar caminho de pesquisa de hashes de arquivo

Especifica o caminho de pesquisa a ser usado ao atualizar os hashes de arquivo.

###  <a name="additional-options"></a>Opções adicionais

Opções adicionais

## <a name="see-also"></a>Confira também

[C++referência de página de propriedades do projeto](property-pages-visual-cpp.md)
