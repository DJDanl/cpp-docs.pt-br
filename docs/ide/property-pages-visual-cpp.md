---
title: Páginas de propriedades (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c1dc831dff6d1e3dbef4fc762712e8125a5b20e1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33339703"
---
# <a name="property-pages-visual-c"></a>Páginas de propriedade (Visual C++)

Usando páginas de propriedades, você pode especificar configurações para projetos do Visual Studio. Para abrir a caixa de diálogo **Páginas de Propriedades** de um projeto do Visual Studio, no menu **Projeto**, escolha **Propriedades**.

Especifique as configurações de projeto, de modo que elas se apliquem a todas as configurações de build, ou especifique propriedades de projeto diferentes para cada configuração de build. Por exemplo, você pode especificar algumas configurações para a configuração de Versão e outras para a configuração de Depuração.

Nem todas as páginas disponíveis são necessariamente exibidas na caixa de diálogo **Páginas de Propriedades**. As páginas exibidas dependem dos tipos de arquivo no projeto.

Para obter mais informações, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).

Para projetos não Windows, confira [Referência de página de propriedades do Linux C++](../linux/prop-pages-linux.md)<!-- or [C++ Cross Platform Property Page Reference](../linux/prop-pages-linux.md)-->.

## <a name="default-properties-vs-modified-properties"></a>Propriedades Padrão vs. Propriedades Modificadas

Quando você usa a caixa de diálogo **Novo Projeto** para criar um projeto, o Visual Studio usa o modelo de projeto especificado para inicializar as propriedades do projeto. Portanto, os valores da propriedade no modelo podem ser considerados como valores padrão para esse tipo de projeto. Em outros tipos de projeto, as propriedades podem ter valores padrão diferentes.

Um valor da propriedade do projeto é exibido em negrito se é modificado. Uma propriedade de projeto pode ser modificada pelos seguintes motivos:

- O assistente de aplicativo altera a propriedade porque exige um valor de propriedade diferente daquele especificado no modelo de projeto.

- Especifique outro valor de propriedade na caixa de diálogo **Novo Projeto**.

- Especifique outro valor de propriedade em uma página de propriedades do projeto.

> [!TIP]
> Para ver o conjunto final de valores de propriedade que o MSBuild usa para compilar o projeto, examine o arquivo de saída do pré-processador, que pode ser produzido usando a linha de comando: **MSBuild /preprocess:** *nome_do_arquivo_de_saída_do_pré-processador*<sub>opt</sub> *nome_do_arquivo _do_projeto*<sub>opt</sub>

## <a name="resetting-properties"></a>Redefinindo propriedades

Quando você exibe a caixa de diálogo **Páginas de Propriedades** de um projeto e o nó do projeto está selecionado no **Gerenciador de Soluções**, para muitas propriedades, você pode selecionar **Herdar do pai ou padrões de projeto** ou modificar o valor de outra maneira.

Quando você exibe a caixa de diálogo **Páginas de Propriedades** de um projeto e um arquivo está selecionado no **Gerenciador de Soluções**, para muitas propriedades, você pode selecionar **Herdar do pai ou padrões de projeto** ou modificar o valor de outra maneira. No entanto, se o projeto contiver muitos arquivos que têm valores de propriedade diferentes dos valores padrão do projeto, o projeto levará mais tempo para ser compilado.

> [!TIP]
> Para atualizar a caixa de diálogo **Páginas de Propriedades** para que ela exiba as últimas seleções, escolha **Aplicar**.

A maioria dos padrões de projeto são os padrões do sistema (plataforma). Alguns padrões de projeto derivam das folhas de estilos aplicadas quando você atualiza as propriedades na seção **Padrões de Projeto** da página de propriedades de configuração **Geral** do projeto. Para obter mais informações, confira [Página de propriedades Geral (projeto)](../ide/general-property-page-project.md).

## <a name="specifying-user-defined-values"></a>Especificando valores definidos pelo usuário

É necessário definir o valor de algumas propriedades. Um valor definido pelo usuário pode conter um ou mais caracteres alfanuméricos ou nomes de macro de arquivo de projeto. Algumas dessas propriedades podem usar apenas um valor definido pelo usuário, mas outras podem usar uma lista delimitada por ponto-e-vírgula de vários valores.

Para especificar um valor definido pelo usuário para uma propriedade ou uma lista se a propriedade puder aceitar vários valores definidos pelo usuário, na coluna à direita do nome da propriedade, execute uma das seguintes ações:

- Digite o valor ou a lista de valores.

- Escolha a seta suspensa. Se a opção **Editar** estiver disponível, escolha-a e, em seguida, na caixa de texto, digite o valor ou uma lista de valores. Uma maneira alternativa de especificar uma lista é digitar cada valor em uma linha separada na caixa de texto. Na página de propriedades, os valores serão exibidos como uma lista delimitada por ponto-e-vírgula.

   Para inserir uma macro de arquivo de projeto como um valor, escolha **Macros** e, em seguida, clique duas vezes no nome da macro.

- Escolha a seta suspensa. Se a opção **Procurar** estiver disponível, escolha-a e, em seguida, selecione um ou mais valores.

Para uma propriedade com valores múltiplos, a opção **Herdar do pai ou padrões de projeto** está disponível quando você escolhe a seta suspensa na coluna à direita do nome da propriedade e, em seguida, escolhe **Editar**. Por padrão, a opção está selecionada.

Observe que uma página de propriedades exibe apenas as configurações no nível atual de uma propriedade com valores múltiplos que herda de outro nível. Por exemplo, se um arquivo está selecionado no **Gerenciador de Soluções** e você seleciona a propriedade **Definições do Pré-processador** do C/C++, as definições no nível de arquivo são exibidas, mas as definições no nível de projeto herdadas não são exibidas. Para exibir os valores do nível atual e herdados, escolha a seta suspensa na coluna à direita do nome da propriedade e, em seguida, escolha **Editar**. Se você usar o [Modelo de projeto do Visual C++](https://docs.microsoft.com/dotnet/api/microsoft.visualstudio.vcprojectengine), esse comportamento também entrará em vigor para os objetos em arquivos e projetos. Ou seja, quando você consultar os valores em uma propriedade no nível de arquivo, você não terá os valores para essa mesma propriedade no nível de projeto. Explicitamente, você precisa obter os valores da propriedade no nível de projeto. Além disso, alguns valores herdados de uma propriedade podem ser obtidos de uma folha de estilos, que não está acessível de forma programática.

## <a name="in-this-section"></a>Nesta seção

[Caixa de diálogo Avançado, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de \<Projectname>](../ide/advanced-manifest-tool.md)

[Página de propriedades de linha de comando](../ide/command-line-property-pages.md)

[Página de Propriedades de Etapa de Compilação Personalizada: geral](../ide/custom-build-step-property-page-general.md)

[Adicionando referências](../ide/adding-references-in-visual-cpp-projects.md)

[Página de propriedades gerais (arquivo)](../ide/general-property-page-file.md)

[Página de propriedades gerais (projeto)](../ide/general-property-page-project.md)

[Caixa de diálogo Geral, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de \<Projectname>](../ide/general-manifest-tool-configuration-properties.md)

[Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)

[Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)

[Páginas de propriedade HLSL: geral](../ide/hlsl-property-pages-general.md)

[Páginas de propriedades HLSL: arquivos de saída](../ide/hlsl-property-pages-output-files.md)

[Caixa de diálogo Entrada e Saída, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de \<Projectname>](../ide/input-and-output-manifest-tool.md)

[Caixa de diálogo COM Isolado, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedades de \<Projectname>](../ide/isolated-com-manifest-tool.md)

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
