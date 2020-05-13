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
ms.openlocfilehash: e1d0f1ac889cb915216ceb70d48e36efe4ad21bc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336306"
---
# <a name="manifest-tool-property-pages"></a>Páginas de propriedades Ferramenta de Manifesto

Use essas páginas para especificar opções gerais para [Mt.exe](/windows/win32/sbscs/mt-exe). Essas páginas são encontradas **na** > **Properties** > ferramenta manifesto propriedades > de**configuração****de propriedades do projeto**.

## <a name="general-property-page"></a>Página de propriedades gerais

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

   **Sim (/nologo)** especifica que os dados padrão de direitos autorais da Microsoft ficarão ocultos quando a ferramenta de manifesto for iniciada. Use essa opção para suprimir a saída indesejada em arquivos de log quando você executar mt.exe como parte de um processo de build ou em um ambiente de build.

### <a name="verbose-output"></a>Saída de Verbose

   **Sim (/verbose)** especifica que as informações de build adicionais serão exibidas durante a geração do manifesto.

### <a name="assembly-identity"></a>Identidade do Assembly

Usa a opção /identity para especificar uma seqüência de identidade, que compreende os atributos do [ \<elemento assemblyIdentity> .](/visualstudio/deployment/assemblyidentity-element-clickonce-application) Uma seqüência de identidade `name` começa com o valor do atributo e é seguida por pares de*valor* *de atributo.* =  Os atributos de uma cadeia de caracteres de identidade são delimitados por uma vírgula.

Este é um exemplo de seqüência de identidade:`Microsoft.Windows.Common-Controls, processorArchitecture=x86, version=6.0.0.0, type=win32, publicKeyToken=6595b64144ccf1df`

## <a name="input-and-output-property-page"></a>Página de propriedade de entrada e saída

### <a name="additional-manifest-files"></a>Arquivos de Manifesto Adicionais

Usa a opção **/manifest** para especificar os caminhos completos de arquivos de manifesto adicionais que serão processados ou mesclados pela ferramenta de manifesto. Os caminhos completos são delimitados por ponto e vírgula. (-manifesto [manifesto1] [manifesto2] ...)

### <a name="input-resource-manifests"></a>Manifestos de Recurso de Entrada

Usa a opção **/inputresource** para especificar o caminho completo de um recurso do tipo RT_MANIFEST, a ser inserido na ferramenta de manifesto. O caminho pode ser seguido pela ID de recurso especificada. Por exemplo:

`dll_with_manifest.dll;#1`

### <a name="embed-manifest"></a>Inserir Manifesto

- **Sim** especifica que o sistema de projeto inserirá o arquivo de manifesto do aplicativo no assembly.

- **Não** especifica que o sistema de projeto criará o arquivo de manifesto do aplicativo como um arquivo autônomo.

### <a name="output-manifest-file"></a>Arquivo de Manifesto de Saída

Especifica o nome do arquivo de manifesto de saída. Essa propriedade é opcional quando apenas um arquivo de manifesto é operado pela ferramenta de manifesto. (out:[file];#[ID de recurso])

### <a name="manifest-resource-file"></a>Arquivo de Recurso de Manifesto

Especifica o arquivo de recurso de saída usado para inserir o manifesto na saída do projeto.

### <a name="generate-catalog-files"></a>Gerar Arquivos de Catálogo

Usa a opção **/makecdfs** para especificar que a ferramenta de manifesto gerará arquivos de definição de catálogo (arquivos .cdf), que são usados para criar catálogos. (/makecdfs)

### <a name="generate-manifest-from-managedassembly"></a>Gerar Manifesto com base em ManagedAssembly

Gera um manifesto com base em um assembly gerenciado. (-managedassemblyname:\[file])

### <a name="suppress-dependency-element"></a>Suprimir Elemento de Dependência

Usado com montagem gerenciada. suprime a geração de elementos de dependência no manifesto final. (-nodependency)

### <a name="generate-category-tags"></a>Gerar Marcas de Categoria

Usado com montagem gerenciada. -categoria faz com que as tags de categoria sejam geradas. (-categoria)

### <a name="dpi-awareness"></a>Conscientização da DPI

Especifica se o aplicativo tem reconhecimento de DPI. Por padrão, a configuração é **Sim** para projetos MFC e **Não** caso contrário, porque apenas os projetos MFC têm reconhecimento de DPI interno. Você poderá substituir a configuração por **Sim** se adicionar um código para lidar com diferentes configurações de DPI. O aplicativo poderá parecer difuso ou pequeno se você defini-lo como tendo reconhecimento de DPI quando ele não tiver.

**Opções**

- **Nenhum**
- **Alto DPI Consciente**
- **Por monitor alto dpi aware**

## <a name="isolated-com-property-page"></a>Página de propriedade com isolada

Para obter mais informações sobre com [isolados,](/windows/win32/SbsCs/isolated-applications) consulte Aplicativos Isolados e [Como: Construir aplicativos isolados para consumir componentes COM](../how-to-build-isolated-applications-to-consume-com-components.md).

### <a name="type-library-file"></a>Arquivo de Biblioteca de Tipos

Especifica a biblioteca de tipo a ser usada para suporte manifesto COM gratuito. (-tlb:[arquivo])

### <a name="registrar-script-file"></a>Arquivo de Script do Registrador

Especifica o arquivo de script do registrador para usar para suporte manifesto com resciso. (-rgs:[arquivo])

### <a name="component-file-name"></a>Nome de Arquivo do Componente

Especifica o nome do arquivo do componente que é construído a partir do .tlb ou .rgs especificado. (-dll:[arquivo])

### <a name="replacements-file"></a>Arquivo de Substituições

Especifica o arquivo que contém valores para strings substituíveis no arquivo RGS. (substituições:[arquivo])

## <a name="advanced-property-page"></a>Página de propriedade avançada

### <a name="update-file-hashes"></a>Atualizar Hashes de Arquivo

Calcula o hash dos arquivos especificados nos elementos do arquivo e atualiza o atributo hash com este valor. (hashupdate:[path])

### <a name="update-file-hashes-search-path"></a>Atualizar Caminho de Pesquisa de Hashes de Arquivo

Especifica o caminho de pesquisa a ser usado ao atualizar os hashes do arquivo.

### <a name="additional-options"></a>Opções adicionais

Opções adicionais

## <a name="see-also"></a>Confira também

[Referência da página de propriedade do projeto C++](property-pages-visual-cpp.md)
