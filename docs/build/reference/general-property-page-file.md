---
title: Página de propriedade geral (arquivo)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCFileConfiguration.ExcludedFromBuild
- VC.Project.VCFileConfiguration.Tool
ms.assetid: 26e3711e-9e7d-4e8d-bc4c-2474538efdad
ms.openlocfilehash: 66e26cabf5af85091000e6cda144898789c581df
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824210"
---
# <a name="general-property-page-file"></a>Página de propriedade geral (arquivo)

Quando um arquivo é selecionado no **Gerenciador de Soluções**, a página de propriedades **Geral** no nó **Propriedades de Configuração** contém as seguintes propriedades:

- **Excluir do Build**

   Especifica se o arquivo deve estar no build da configuração atual.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.ExcludedFromBuild%2A>.

- **Ferramenta**

   A ferramenta que será usada para compilar esse arquivo. Confira [Especificando ferramentas de build personalizadas](../specifying-custom-build-tools.md) para obter mais informações.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.Tool%2A>.

Para obter informações sobre como acessar o **gerais** página de propriedade sob a **propriedades de configuração** nó, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

Para projetos de não-Windows, consulte [referência de página de propriedades do Linux C++](../../linux/prop-pages-linux.md).

## <a name="see-also"></a>Consulte também

[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)