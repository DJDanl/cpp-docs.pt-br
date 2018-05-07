---
title: Ferramenta de manifesto isolado COM propriedades (Visual C++) | Microsoft Docs
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
ms.openlocfilehash: c425a71f8bb8a7972ade29fb0d18cf3eab7debb5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="isolated-com-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Isolar as propriedades de configuração do DCOM, ferramenta de manifesto, &lt;Projectname&gt; caixa de diálogo de páginas de propriedades
Use essa caixa de diálogo para especificar **isolado COM** opções de [Mt.exe](http://msdn.microsoft.com/library/aa375649).  
  
 Para acessar essa caixa de diálogo de página de propriedade, abra as páginas de propriedades para o projeto ou a folha de propriedades. Expanda o **ferramenta de manifesto** nó **propriedades comuns**e, em seguida, selecione **isolado COM**.  
  
## <a name="task-list"></a>Lista de Tarefas  
  
-   [Como compilar aplicativos isolados para consumir componentes COM](../build/how-to-build-isolated-applications-to-consume-com-components.md)  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Arquivo de biblioteca de tipo**  
 Usa a opção /tlb para especificar o nome do arquivo de biblioteca de tipo (arquivo. tlb) que usará a ferramenta de manifesto para gerar o arquivo de manifesto.  
  
 **Arquivo de Script de registrador**  
 Usa a opção /rgs para especificar o nome do arquivo de script de registrador (arquivo. rgs) que usará a ferramenta de manifesto para gerar o arquivo de manifesto.  
  
 **Nome de arquivo do componente**  
 Usa a opção /dll para especificar o nome do recurso que gerarão a ferramenta de manifesto. Você deve inserir um valor para essa propriedade quando os valores para o **arquivo de biblioteca de tipo** ou **arquivo Script de registrador** são especificados.  
  
 **Arquivo de substituições**  
 Usa a opção /replacements para especificar o caminho completo para o arquivo que contém os valores de cadeias de caracteres substituíveis no arquivo. rgs.  
  
## <a name="see-also"></a>Consulte também  
 [Aplicativos isolados](http://msdn.microsoft.com/library/aa375190)   
 [Manifesto do aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)   
 [Páginas de propriedade da ferramenta de manifesto](../ide/manifest-tool-property-pages.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)   