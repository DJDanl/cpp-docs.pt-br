---
title: Propriedades de configuração da ferramenta de manifesto (Visual C++)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCManifestTool.MergeRulesFile
- VC.Project.VCManifestTool.UseUnicodeResponseFiles
- VC.Project.VCManifestTool.SuppressStartupBanner
- VC.Project.VCManifestTool.UseFAT32Workaround
- VC.Project.VCManifestTool.VerboseOutput
- VC.Project.VCManifestTool.AssemblyIdentity
ms.assetid: b99368a5-6819-482c-a06e-f2409290cfd1
ms.openlocfilehash: 9bd2f0bb67e06fbf462ea6a7779de07b2cc54592
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57745117"
---
# <a name="general-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Caixa de diálogo Geral, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de &lt;Projectname&gt;

Use essa caixa de diálogo para especificar opções gerais para [Mt.exe](https://msdn.microsoft.com/library/aa375649).

Para acessar essa caixa de diálogo da página de propriedades, abra as páginas de propriedades do projeto ou da folha de propriedades. Expanda o nó **Ferramenta de Manifesto** em **Propriedades de Configuração** e, em seguida, selecione **Geral**.

## <a name="uielement-list"></a>Lista UIElement

- **Suprimir Faixa de Inicialização**

   **Sim (/nologo)** especifica que os dados padrão de direitos autorais da Microsoft ficarão ocultos quando a ferramenta de manifesto for iniciada. Use essa opção para suprimir a saída indesejada em arquivos de log quando você executar mt.exe como parte de um processo de build ou em um ambiente de build.

- **Saída Detalhada**

   **Sim (/verbose)** especifica que as informações de build adicionais serão exibidas durante a geração do manifesto.

- **Identidade do Assembly**

   Usa a opção /identity para especificar uma cadeia de caracteres de identidade, que inclui os atributos para o [\<Elemento assemblyIdentity>](/visualstudio/deployment/assemblyidentity-element-clickonce-application). Uma cadeia de caracteres de identidade começa com o valor do atributo `name` e é seguida por pares *atributo* = *valor*. Os atributos de uma cadeia de caracteres de identidade são delimitados por uma vírgula.

   Este é um exemplo de cadeia de caracteres de identidade:

   `Microsoft.Windows.Common-Controls, processorArchitecture=x86, version=6.0.0.0, type=win32, publicKeyToken=6595b64144ccf1df`

## <a name="see-also"></a>Consulte também

[Manifesto de aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)<br>
[Páginas de propriedades da ferramenta de manifesto](../ide/manifest-tool-property-pages.md)<br>
[Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)
