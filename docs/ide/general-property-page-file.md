---
title: Página de propriedade geral (arquivo)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCFileConfiguration.ExcludedFromBuild
- VC.Project.VCFileConfiguration.Tool
ms.assetid: 26e3711e-9e7d-4e8d-bc4c-2474538efdad
ms.openlocfilehash: 224a205bb87b89f073676275d67e3cdd127b79af
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50655241"
---
# <a name="general-property-page-file"></a>Página de propriedade geral (arquivo)

Quando um arquivo é selecionado no **Gerenciador de Soluções**, a página de propriedades **Geral** no nó **Propriedades de Configuração** contém as seguintes propriedades:

- **Excluir do Build**

   Especifica se o arquivo deve estar no build da configuração atual.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.ExcludedFromBuild%2A>.

- **Ferramenta**

   A ferramenta que será usada para compilar esse arquivo. Confira [Especificando ferramentas de build personalizadas](../ide/specifying-custom-build-tools.md) para obter mais informações.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.Tool%2A>.

Para obter informações sobre como acessar a página de propriedades **Geral** no nó **Propriedades de Configuração**, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).

Para projetos não Windows, confira [Referência de página de propriedades do Linux C++](../linux/prop-pages-linux.md)<!-- or [C++ Cross Platform Property Page Reference](../linux/prop-pages-linux.md)-->.

## <a name="see-also"></a>Consulte também

[Páginas de propriedade](../ide/property-pages-visual-cpp.md)