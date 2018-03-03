---
title: "Avançado, ferramenta de manifesto, propriedades de configuração, &lt;Projectname&gt; caixa de diálogo páginas de propriedade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCManifestTool.KeyFile
- VC.Project.VCManifestTool.UpdateFileHashes
- VC.Project.VCManifestTool.UpdateFileHashesSearchPath
- VC.Project.VCManifestTool.ValidateSignature
- VC.Project.VCManifestTool.KeyContainer
dev_langs:
- C++
ms.assetid: 3d587366-05ea-4956-a978-313069660735
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c756da4ef7b89113ce26e7218011d708ff4c935c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="advanced-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Avançado, ferramenta de manifesto, propriedades de configuração, &lt;Projectname&gt; caixa de diálogo de páginas de propriedades
Use essa caixa de diálogo para especificar opções avançadas para [Mt.exe](http://msdn.microsoft.com/library/aa375649).  
  
 Para acessar essa caixa de diálogo de página de propriedade, abra as páginas de propriedades para o projeto ou a folha de propriedades. Expanda o **ferramenta de manifesto** nó **propriedades de configuração**e, em seguida, selecione **avançado**.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Atualizar Hashes de arquivo**  
 Usa a opção /hashupdate para especificar que a ferramenta de manifesto calculará o hash de arquivos especificados na `<file>` elementos e atualize o hash de atributos com o valor calculado.  
  
 **Atualizar caminho de pesquisa de Hashes de arquivo**  
 Especifica o caminho de pesquisa para arquivos que são referenciados na `<file>` elementos. Essa opção também usa a opção /hashupdate.  
  
## <a name="see-also"></a>Consulte também  
 [\<arquivo > elemento](/visualstudio/deployment/file-element-clickonce-application)   
 [Manifesto do aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)   
 [Páginas de propriedade da ferramenta de manifesto](../ide/manifest-tool-property-pages.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)   