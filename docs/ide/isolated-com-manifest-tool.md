---
title: Propriedades de COM Isolado da Ferramenta de Manifesto (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCManifestTool.RegistrarScriptFile
- VC.Project.VCManifestTool.ComponentFileName
- VC.Project.VCManifestTool.TypeLibraryFile
- VC.Project.VCManifestTool.ReplacementsFile
dev_langs:
- C++
ms.assetid: 457582b8-cfde-49c0-92e3-3a6b9e8c08eb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5439e04fdb2563748bc21fb494cc09fd7bd5c929
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720090"
---
# <a name="isolated-com-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Caixa de diálogo COM Isolado, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de &lt;Projectname&gt;
Use essa caixa de diálogo para especificar as opções de **COM Isolado** para [Mt.exe](https://msdn.microsoft.com/library/aa375649).  
  
Para acessar essa caixa de diálogo da página de propriedades, abra as páginas de propriedades do projeto ou da folha de propriedades. Expanda o nó **Ferramenta de Manifesto** em **Propriedades Comuns** e, em seguida, selecione **COM Isolado**.  
  
## <a name="task-list"></a>Lista de Tarefas  
  
-   [Como compilar aplicativos isolados para consumir componentes COM](../build/how-to-build-isolated-applications-to-consume-com-components.md)  
  
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
 [Aplicativos isolados](/windows/desktop/SbsCs/isolated-applications)   
 [Manifesto do aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)   
 [Páginas de propriedades da Ferramenta de Manifesto](../ide/manifest-tool-property-pages.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)   