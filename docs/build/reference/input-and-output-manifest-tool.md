---
title: Ferramenta de manifesto C++ propriedades de entrada e saída
ms.date: 08/27/2018
f1_keywords:
- VC.Project.VCManifestTool.OutputManifestFile
- VC.Project.VCManifestTool.InputResourceManifests
- VC.Project.VCManifestTool.EmbedManifest
- VC.Project.VCManifestTool.AdditionalManifestFiles
- VC.Project.VCManifestTool.DependencyInformationFile
- VC.Project.VCManifestTool.OutputResourceManifest
- VC.Project.VCManifestTool.GenerateCatalogFiles
ms.assetid: a8bb20f6-7ace-45ca-bab0-b4f4a5caf170
ms.openlocfilehash: 1731665ffa6117896490115028b4744e195beae2
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824601"
---
# <a name="input-and-output-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Caixa de diálogo Entrada e Saída, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de &lt;Projectname&gt;

Use essa caixa de diálogo para especificar as opções de entrada e saída para [Mt.exe](/windows/desktop/SbsCs/mt-exe).

Para acessar essa caixa de diálogo da página de propriedades, abra as páginas de propriedades do projeto ou da folha de propriedades. Expanda o nó **Ferramenta de Manifesto** em **Propriedades de Configuração** e, em seguida, selecione **Entrada e Saída**.

## <a name="uielement-list"></a>Lista UIElement

**Arquivos de Manifesto Adicionais**<br/>
Usa a opção **/manifest** para especificar os caminhos completos de arquivos de manifesto adicionais que serão processados ou mesclados pela ferramenta de manifesto. Os caminhos completos são delimitados por ponto e vírgula.

**Manifestos de Recurso de Entrada**<br/>
Usa a opção **/inputresource** para especificar o caminho completo de um recurso do tipo RT_MANIFEST, a ser inserido na ferramenta de manifesto. O caminho pode ser seguido pela ID de recurso especificada. Por exemplo:

`dll_with_manifest.dll;#1`

A ID de recurso é opcional e o usa como padrão CREATEPROCESS_MANIFEST_RESOURCE_ID em winuser.h.

**Inserir Manifesto**<br/>
- **Sim** especifica que o sistema de projeto inserirá o arquivo de manifesto do aplicativo no assembly.

- **Não** especifica que o sistema de projeto criará o arquivo de manifesto do aplicativo como um arquivo autônomo.

**Arquivo de Manifesto de Saída**<br/>
Especifica o nome do arquivo de manifesto de saída. Essa propriedade é opcional quando apenas um arquivo de manifesto é operado pela ferramenta de manifesto.

**Arquivo de Recurso de Manifesto**<br/>
Especifica os arquivos de recurso de saída usados para inserir o manifesto na saída do projeto.

**Gerar Arquivos de Catálogo**<br/>
Usa a opção **/makecdfs** para especificar que a ferramenta de manifesto gerará arquivos de definição de catálogo (arquivos .cdf), que são usados para criar catálogos.

**Gerar Manifesto com base em ManagedAssembly**<br/>
Gera um manifesto com base em um assembly gerenciado. (**-managedassemblyname:**<em>file</em>).

**Suprimir Elemento de Dependência**<br/>
Usado com a opção **-managedassembly**. Essa marcação suprime a geração de elementos de dependência no manifesto final.

**Gerar Marcas de Categoria**<br/>
Usado com a opção **-managedassembly**. Essa marcação faz com que as marcas de categoria sejam geradas.

**Habilitar Reconhecimento de DPI**<br/>
Especifica se o aplicativo tem reconhecimento de DPI. Por padrão, a configuração é **Sim** para projetos MFC e **Não** caso contrário, porque apenas os projetos MFC têm reconhecimento de DPI interno. Você poderá substituir a configuração por **Sim** se adicionar um código para lidar com diferentes configurações de DPI. O aplicativo poderá parecer difuso ou pequeno se você defini-lo como tendo reconhecimento de DPI quando ele não tiver.

## <a name="see-also"></a>Consulte também

[Manifesto de aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)<br/>
[Páginas de propriedades da ferramenta de manifesto](manifest-tool-property-pages.md)<br/>
[Defina o compilador C++ e compilar propriedades no Visual Studio](../working-with-project-properties.md)<br/>
