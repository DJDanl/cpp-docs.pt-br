---
title: Avançado, ferramenta de manifesto, propriedades de configuração, &lt;Projectname > caixa de diálogo páginas de propriedade
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCManifestTool.KeyFile
- VC.Project.VCManifestTool.UpdateFileHashes
- VC.Project.VCManifestTool.UpdateFileHashesSearchPath
- VC.Project.VCManifestTool.ValidateSignature
- VC.Project.VCManifestTool.KeyContainer
ms.assetid: 3d587366-05ea-4956-a978-313069660735
ms.openlocfilehash: a20e474deb69099c53ad656dda5406e7161a1695
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62295130"
---
# <a name="advanced-manifest-tool-configuration-properties-ltprojectnamegt-property-pages-dialog-box"></a>Caixa de diálogo Avançado, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de &lt;Projectname&gt;

Use essa caixa de diálogo para especificar opções avançadas para [Mt.exe](https://msdn.microsoft.com/library/aa375649).

Para acessar essa caixa de diálogo da página de propriedades, abra as páginas de propriedades do projeto ou da folha de propriedades. Expanda o nó **Ferramenta de Manifesto** em **Propriedades de Configuração** e, em seguida, selecione **Avançado**.

## <a name="uielement-list"></a>Lista UIElement

- **Atualizar Hashes de Arquivo**

   Usa a opção /hashupdate para especificar que a ferramenta de manifesto calculará o hash dos arquivos especificados em elementos `<file>` e, em seguida, atualizará os atributos de hash com o valor calculado.

- **Atualizar Caminho de Pesquisa de Hashes de Arquivo**

   Especifica o caminho de pesquisa para arquivos referenciados em elementos `<file>`. Essa opção também usa a opção /hashupdate.

## <a name="see-also"></a>Consulte também

[\<Elemento file>](/visualstudio/deployment/file-element-clickonce-application)<br>
[Manifesto de aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest)<br>
[Páginas de propriedades da ferramenta de manifesto](manifest-tool-property-pages.md)<br>
[Definição das propriedades de compilação do C++ no Visual Studio](../working-with-project-properties.md)
