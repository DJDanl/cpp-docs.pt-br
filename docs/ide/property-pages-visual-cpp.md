---
title: "Páginas de propriedade (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.NotAProp.Edit
dev_langs:
- C++
helpviewer_keywords:
- project-file macro
- project properties [C++], default values
- user-defined values
- project properties [C++], setting
- macros, project-file
- property pages, project settings
- Visual C++ projects, properties
- build macro
- user-defined macros
ms.assetid: 13ffe3ea-1bc3-4bee-be5e-053a8a99cce4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b0c342148266dff9551d2705f8095250daf2b096
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="property-pages-visual-c"></a>Páginas de propriedade (Visual C++)

Usando páginas de propriedades, você pode especificar configurações para projetos do Visual Studio. Para abrir o **páginas de propriedade** projeto caixa de diálogo para um Visual Studio, no **projeto** menu, escolha **propriedades**.

Você pode especificar configurações de projeto para que elas se aplicam todas as configurações de compilação, ou você pode especificar propriedades de projeto diferente para cada configuração de compilação. Por exemplo, você pode especificar algumas configurações para a configuração de versão e outras configurações para a configuração de depuração.

Nem todas as páginas disponíveis aparecem necessariamente o **páginas de propriedade** caixa de diálogo. As páginas exibidas depende dos tipos de arquivo no projeto.

Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).

Para projetos de não-Windows, consulte [referência da página de propriedade do Linux C++](../linux/prop-pages-linux.md)<!-- or [C++ Cross Platform Property Page Reference](../linux/prop-pages-linux.md)-->.

## <a name="default-properties-vs-modified-properties"></a>Vs de propriedades padrão. Propriedades modificadas

Quando você usa o **novo projeto** caixa de diálogo para criar um projeto, o Visual Studio usa o modelo de projeto especificado para inicializar as propriedades do projeto. Portanto, os valores de propriedade no modelo podem ser pensados como valores padrão para esse tipo de projeto. Em outros tipos de projeto, as propriedades podem ter valores padrão diferentes.

Um valor de propriedade do projeto aparece em negrito se forem modificado. Uma propriedade de projeto pode ser modificada pelos seguintes motivos:

- O Assistente de aplicativo altera a propriedade porque ele requer um valor de propriedade diferente daquela que é especificado no modelo de projeto.

- Especifique um valor de propriedade diferente no **novo projeto** caixa de diálogo.

- Você pode especificar um valor de propriedade diferente em uma página de propriedades do projeto.

> [!TIP]
> Para ver o conjunto final de valores de propriedade que usa o MSBuild para compilar o projeto, examine o arquivo de saída de pré-processador, que pode ser produzida usando a linha de comando: **MSBuild / pré-processamento:** *preprocessor_output_ nome de arquivo*<sub>aceitação</sub> *project_filename*<sub>aceitar</sub>

## <a name="resetting-properties"></a>Redefinir propriedades

Quando você exibe o **páginas de propriedade** caixa de diálogo para um projeto e o nó do projeto está selecionada no **Solution Explorer**, para várias propriedades, você pode selecionar **herdar do pai ou de projeto padrões** ou modificar o valor de outra maneira.

Quando você exibe o **páginas de propriedade** caixa de diálogo para um projeto e um arquivo é selecionada na **Solution Explorer**, para várias propriedades, você pode selecionar **herdar do pai ou padrões de projeto** ou modificar o valor de outra maneira. No entanto, se o projeto contém o número de arquivos que têm valores de propriedade que diferem entre os valores padrão de projeto, o projeto levará mais tempo para compilar.

> [!TIP]
> Para atualizar o **páginas de propriedade** caixa de diálogo para que ele exibe as seleções mais recentes, escolha **aplicar**.

A maioria dos padrões de projeto são os padrões do sistema (plataforma). Alguns padrões de projeto derivam as folhas de estilo que são aplicadas quando você atualiza as propriedades no **padrões de projeto** seção o **geral** página de propriedades de configuração para o projeto. Para obter mais informações, consulte [página de propriedade geral (projeto)](../ide/general-property-page-project.md).

## <a name="specifying-user-defined-values"></a>Especificando valores definidos pelo usuário

Você deve definir o valor de determinadas propriedades. Um valor definido pelo usuário pode conter um ou mais caracteres alfanuméricos ou nomes de macro de arquivo de projeto. Algumas dessas propriedades podem demorar apenas um valor definido pelo usuário, mas outras pessoas podem levar uma lista separada por ponto-e-vírgula de vários valores.

Para especificar um valor definido pelo usuário para uma propriedade ou uma lista se a propriedade pode aceitar vários valores definidos pelo usuário, na coluna à direita do nome da propriedade, execute uma das seguintes ações:

- Digite o valor ou a lista de valores.

- Clique na seta suspensa. Se **editar** estiver disponível, escolha-o e, em seguida, na caixa de texto, digite o valor ou uma lista de valores. É uma maneira alternativa para especificar uma lista para o tipo de cada valor em uma linha separada na caixa de texto. Na página de propriedade, os valores serão exibidos como uma lista separada por ponto-e-vírgula.

   Para inserir uma macro de arquivo de projeto como um valor, escolha **Macros** e, em seguida, clique duas vezes no nome da macro.

- Clique na seta suspensa. Se **procurar** estiver disponível, escolha-o e, em seguida, selecione um ou mais valores.

Para uma propriedade com vários valores, o **herdar do pai ou padrões de projeto** opção está disponível quando você clique na seta suspensa na coluna à direita do nome da propriedade e, em seguida, escolha **editar**. Por padrão, a opção é selecionada.

Observe que uma página de propriedades exibe apenas as configurações no nível atual para uma propriedade de valores múltiplos que herda de outro nível. Por exemplo, se um arquivo está selecionado no **Solution Explorer** e selecione do C/C++ **definições de pré-processador** propriedade, definições de nível de arquivo são exibidas, mas herdada definições de nível de projeto não são exibidos. Para exibir valores nível atual e herdados, clique na seta suspensa na coluna à direita do nome da propriedade e, em seguida, escolha **editar**. Se você usar o [modelo de projeto do Visual C++](https://docs.microsoft.com/dotnet/api/microsoft.visualstudio.vcprojectengine), esse comportamento também está em vigor para os objetos em projetos e arquivos. Ou seja, quando você consulta para os valores em uma propriedade no nível de arquivo, você não terá os valores para a mesma propriedade em nível de projeto. Explicitamente, você deve obter os valores da propriedade no nível do projeto. Além disso, alguns valores herdadas de uma propriedade podem vir de uma folha de estilos não está acessível por meio de programação.

## <a name="in-this-section"></a>Nesta seção

[Avançado, ferramenta de manifesto, propriedades de configuração, \<Projectname > caixa de diálogo de páginas de propriedades](../ide/advanced-manifest-tool.md)

[Página de propriedades de linha de comando](../ide/command-line-property-pages.md)

[Página de Propriedades de Etapa de Compilação Personalizada: geral](../ide/custom-build-step-property-page-general.md)

[Adicionando referências](../ide/adding-references-in-visual-cpp-projects.md)

[Página de propriedades gerais (arquivo)](../ide/general-property-page-file.md)

[Página de propriedades gerais (projeto)](../ide/general-property-page-project.md)

[Ferramenta de manifesto, geral, propriedades de configuração, \<Projectname > caixa de diálogo de páginas de propriedades](../ide/general-manifest-tool-configuration-properties.md)

[Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)

[Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)

[Páginas de propriedade HLSL: geral](../ide/hlsl-property-pages-general.md)

[Páginas de propriedades HLSL: arquivos de saída](../ide/hlsl-property-pages-output-files.md)

[Entrada e saída, a ferramenta, propriedades de configuração de manifesto \<Projectname > caixa de diálogo de páginas de propriedades](../ide/input-and-output-manifest-tool.md)

[Isolar as propriedades de configuração do DCOM, ferramenta de manifesto, \<Projectname > caixa de diálogo de páginas de propriedades](../ide/isolated-com-manifest-tool.md)

[Páginas de propriedades do vinculador](../ide/linker-property-pages.md)

[Página de propriedades de recursos gerenciados](../ide/managed-resources-property-page.md)

[Páginas de propriedades da ferramenta de manifesto](../ide/manifest-tool-property-pages.md)

[Páginas de propriedades de MIDL](../ide/midl-property-pages.md)

[Páginas de propriedades de MIDL: avançado](../ide/midl-property-pages-advanced.md)

[Páginas de propriedades de MDL: geral](../ide/midl-property-pages-general.md)

[Páginas de propriedades de MIDL: saída](../ide/midl-property-pages-output.md)

[Página de propriedades de NMake](../ide/nmake-property-page.md)

[Páginas de propriedades de recursos](../ide/resources-property-pages.md)

[Página de propriedades dos diretórios do VC++](../ide/vcpp-directories-property-page.md)

[Página de propriedades de referências Web](../ide/web-references-property-page.md)

[Página de propriedades da Ferramenta de Gerador de Dados XML](../ide/xml-data-generator-tool-property-page.md)

[Páginas de propriedade da Ferramenta de Gerador de Documento XML](../ide/xml-document-generator-tool-property-pages.md)

## <a name="see-also"></a>Consulte também

[Como criar e remover dependências do projeto](/visualstudio/ide/how-to-create-and-remove-project-dependencies)  
[Como criar e editar configurações](/visualstudio/ide/how-to-create-and-edit-configurations)  
