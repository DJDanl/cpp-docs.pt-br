---
title: Propriedades de COM isolado da ferramenta de manifesto (Visual C++)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCManifestTool.RegistrarScriptFile
- VC.Project.VCManifestTool.ComponentFileName
- VC.Project.VCManifestTool.TypeLibraryFile
- VC.Project.VCManifestTool.ReplacementsFile
ms.assetid: 457582b8-cfde-49c0-92e3-3a6b9e8c08eb
ms.openlocfilehash: 9eea3b2765bad6bd08cc9ee91a801e2b891511e5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50546505"
---
# <a name="isolated-com-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Caixa de diálogo COM Isolado, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de &lt;Projectname&gt;

Use essa caixa de diálogo para especificar as opções de **COM Isolado** para [Mt.exe](https://msdn.microsoft.com/library/aa375649).

Para acessar essa caixa de diálogo da página de propriedades, abra as páginas de propriedades do projeto ou da folha de propriedades. Expanda o nó **Ferramenta de Manifesto** em **Propriedades Comuns** e, em seguida, selecione **COM Isolado**.

## <a name="task-list"></a>Lista de Tarefas

- [Como compilar aplicativos isolados para consumir componentes COM](../build/how-to-build-isolated-applications-to-consume-com-components.md)

## <a name="uielement-list"></a>Lista UIElement

- **Arquivo de Biblioteca de Tipos**

   Usa a opção /tlb para especificar o nome do arquivo de biblioteca de tipos (arquivo .tlb) que será usado pela ferramenta de manifesto para gerar o arquivo de manifesto.

- **Arquivo de Script do Registrador**

   Usa a opção /rgs para especificar o nome do arquivo de script do registrador (arquivo .rgs) que será usado pela ferramenta de manifesto para gerar o arquivo de manifesto.

- **Nome de Arquivo do Componente**

   Usa a opção /dll para especificar o nome do recurso que será gerado pela ferramenta de manifesto. É necessário inserir um valor para essa propriedade quando os valores de **Arquivo de Biblioteca de Tipos** ou **Arquivo de Script do Registrador** são especificados.

- **Arquivo de Substituições**

   Usa a opção /replacements para especificar o caminho completo para o arquivo que contém os valores das cadeias de caracteres substituíveis no arquivo .rgs.

## <a name="see-also"></a>Consulte também

[Aplicativos isolados](/windows/desktop/SbsCs/isolated-applications)<br>
[Manifesto de aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)<br>
[Páginas de propriedades da ferramenta de manifesto](../ide/manifest-tool-property-pages.md)<br>
[Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)