---
title: Manifesto de propriedades de configuração da ferramenta (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCManifestTool.MergeRulesFile
- VC.Project.VCManifestTool.UseUnicodeResponseFiles
- VC.Project.VCManifestTool.SuppressStartupBanner
- VC.Project.VCManifestTool.UseFAT32Workaround
- VC.Project.VCManifestTool.VerboseOutput
- VC.Project.VCManifestTool.AssemblyIdentity
dev_langs:
- C++
ms.assetid: b99368a5-6819-482c-a06e-f2409290cfd1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1953e7c37c07f66845510efe037015a537aa7baa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="general-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Ferramenta de manifesto, geral, propriedades de configuração, &lt;Projectname&gt; caixa de diálogo de páginas de propriedades
Use essa caixa de diálogo para especificar opções gerais para [Mt.exe](http://msdn.microsoft.com/library/aa375649).  
  
 Para acessar essa caixa de diálogo de página de propriedade, abra as páginas de propriedades para o projeto ou a folha de propriedades. Expanda o **ferramenta de manifesto** nó **propriedades de configuração**e, em seguida, selecione **geral**.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Suprimir faixa de inicialização**  
 **Sim (/ /nologo)** Especifica que dados de direitos autorais Microsoft padrão serão ocultos, quando a ferramenta de manifesto é iniciada. Use esta opção para suprimir a saída indesejada nos arquivos de log, quando você executa mt.exe como parte de um processo de compilação ou de um ambiente de compilação.  
  
 **Saída detalhada**  
 **Sim (/verbose)** Especifica que as informações de compilação adicionais serão exibidas durante a geração de manifesto.  
  
 **Identidade do assembly**  
 Usa a opção /identity para especificar uma cadeia de caracteres de identidade, que inclui os atributos para o [ \<assemblyIdentity > elemento](/visualstudio/deployment/assemblyidentity-element-clickonce-application). Uma cadeia de caracteres de identidade começa com o valor para o `name` de atributo e é seguido por *atributo* = *valor* pares. Os atributos em uma cadeia de caracteres de identidade são delimitados por uma vírgula.  
  
 Uma cadeia de caracteres de identidade de exemplo é o seguinte:  
  
 `Microsoft.Windows.Common-Controls, processorArchitecture=x86, version=6.0.0.0, type=win32, publicKeyToken=6595b64144ccf1df`  
  
## <a name="see-also"></a>Consulte também  
 [Manifesto do aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)   
 [Páginas de propriedade da ferramenta de manifesto](../ide/manifest-tool-property-pages.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)   