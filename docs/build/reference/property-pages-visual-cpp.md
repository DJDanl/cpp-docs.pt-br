---
title: Referência C++ de página de propriedades do projeto do Windows-Visual Studio
ms.date: 08/28/2019
helpviewer_keywords:
- project-file macro
- project properties [C++], default values
- user-defined values
- project properties [C++], setting
- macros, project-file
- property pages, project settings
- C++ projects, properties
- build macro
- user-defined macros
ms.assetid: 13ffe3ea-1bc3-4bee-be5e-053a8a99cce4
ms.openlocfilehash: c9fd4fc00e86e0660972fc0bd37b66b2fea02ee0
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177477"
---
# <a name="windows-c-project-property-page-reference"></a>Referência C++ de página de propriedades do projeto do Windows

No Visual Studio, você especifica opções de compilador e vinculador, caminhos de arquivo e outras configurações de compilação por meio das páginas de propriedades do projeto. As propriedades e páginas de propriedade que estão disponíveis dependem do tipo de projeto. Por exemplo, um projeto makefile tem uma página de propriedades NMake, que não está presente em um projeto de console do MFC ou do Win32. Para abrir as **páginas de propriedades**, escolha**Propriedades** do **projeto** > no menu principal ou clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades**. Os arquivos individuais também têm páginas de propriedades que permitem definir opções de compilação e compilação apenas para esse arquivo. A imagem a seguir mostra as páginas de propriedades de um projeto do MFC.

![Páginas de propriedades C++ do projeto](media/example-prop-page.png)

Esta seção fornece uma referência rápida para as próprias páginas de propriedades. As opções e configurações expostas nas páginas de propriedades são documentadas mais completamente em seus próprios tópicos e são vinculadas dos tópicos da página de propriedades. Para obter mais informações sobre as propriedades do projeto, consulte [ C++ definir compilador e propriedades de compilação no Visual Studio](../working-with-project-properties.md).

Para páginas de propriedades em projetos do Linux, consulte [referência de página de propriedades do Linux C++ ](../../linux/prop-pages-linux.md).

## <a name="in-this-section"></a>Nesta seção

- [Página de propriedades gerais (projeto)](general-property-page-project.md)
- [Página de propriedades gerais (arquivo)](general-property-page-file.md)
- [Página de propriedades avançada](advanced-property-page.md)
- [Página de propriedades dos diretórios do VC++](vcpp-directories-property-page.md)
- [Páginas de propriedades do vinculador](linker-property-pages.md)
- [Páginas de propriedades da ferramenta de manifesto](manifest-tool-property-pages.md)
- [Páginas de propriedade HLSL](hlsl-property-pages.md)
- [Página de propriedades de linha de comando](command-line-property-pages.md)
- [Página de propriedades da Etapa de Compilação Personalizada: geral](custom-build-step-property-page-general.md)
- [Adicionando referências](../adding-references-in-visual-cpp-projects.md)
- [Página de propriedades de recursos gerenciados](managed-resources-property-page.md)
- [Páginas de propriedades de MIDL](midl-property-pages.md)
- [Página de propriedades de NMake](nmake-property-page.md)
- [Páginas de propriedades de recursos](resources-property-pages.md)
- [Página de propriedades de referências Web](web-references-property-page.md)
- [Página de propriedades da Ferramenta de Gerador de Dados XML](xml-data-generator-tool-property-page.md)
- [Páginas de propriedade da Ferramenta de Gerador de Documento XML](xml-document-generator-tool-property-pages.md)

## <a name="see-also"></a>Consulte também

[Como: criar e remover dependências de projeto](/visualstudio/ide/how-to-create-and-remove-project-dependencies)<br/>
[Como: Criar e editar configurações](/visualstudio/ide/how-to-create-and-edit-configurations)<br/>
[Referência C++ de página de propriedades do Linux](../../linux/prop-pages-linux.md)
