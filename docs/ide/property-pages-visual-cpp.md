---
title: "P&#225;ginas de propriedade (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.NotAProp.Edit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "macro de compilação"
  - "Macros , arquivo de projeto"
  - "propriedades de projeto [C++], valores padrão"
  - "propriedades de projeto [C++], configuração"
  - "macro de arquivo de projeto"
  - "páginas de propriedade, configurações de projeto"
  - "macros definidas pelo usuário"
  - "valores definidos pelo usuário"
  - "Projetos Visual C++, propriedades"
ms.assetid: 13ffe3ea-1bc3-4bee-be5e-053a8a99cce4
caps.latest.revision: 22
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;ginas de propriedade (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usando páginas de propriedades, você pode especificar configurações para projetos do Visual Studio.  Para abrir o **Property Pages** caixa de diálogo de um Visual Studio do projeto, no **projeto** menu, clique em **propriedades**.  
  
 Você pode especificar configurações de projeto para que eles se aplicam todas as configurações de compilação, ou você pode especificar propriedades de projeto diferente para cada configuração da compilação.  Por exemplo, você pode especificar determinadas configurações para a configuração de versão e outras configurações para a configuração de depuração.  
  
 Nem todas as páginas disponíveis aparecem necessariamente o **Property Pages** caixa de diálogo.  As páginas exibidas depende dos tipos de arquivo do projeto.  
  
 Para obter mais informações, consulte [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).  
  
## Propriedades vs como padrão.Propriedades modificadas  
 Quando você usa o **novo projeto** caixa de diálogo para criar um projeto, [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] usa o modelo de projeto especificado para inicializar as propriedades do projeto.  Portanto, os valores de propriedade no modelo podem ser pensados como valores padrão para esse tipo de projeto.  Em outros tipos de projeto, as propriedades podem ter diferentes valores padrão.  
  
 Um valor de propriedade do projeto aparece em negrito se ele é modificado.  Uma propriedade de projeto pode ser modificada pelos seguintes motivos:  
  
-   O Assistente para aplicativo altera a propriedade porque ele requer um valor de propriedade diferente daquela que é especificado no modelo de projeto.  
  
-   Especifique um valor de propriedade diferente no **novo projeto** caixa de diálogo.  
  
-   Você pode especificar um valor de propriedade diferente em uma página de propriedades do projeto.  
  
> [!TIP]
>  Para ver o conjunto final de valores de propriedade que usa o MSBuild para compilar seu projeto, examine o arquivo de saída do pré\-processador, que pode ser produzida usando a linha de comando: **MSBuild \/preprocess:***preprocessor\_output\_filename*aceitação *project\_filename*aceitação  
  
## Redefinindo propriedades  
 Quando você exibe o **páginas de propriedades** caixa de diálogo para um projeto e o nó do projeto está selecionada em **Solution Explorer**, para várias propriedades, você pode selecionar **Herdar do pai ou padrões de projeto** ou modificar o valor outra maneira.  
  
 Quando você exibe o **Property Pages** caixa de diálogo para um projeto e um arquivo é selecionada no **Solution Explorer**, para várias propriedades, você pode selecionar **Herdar do pai ou padrões de projeto** ou modificar o valor outra maneira.  No entanto, se o projeto contiver muitos arquivos que possuem valores de propriedade diferentes dos valores padrão de projeto, o projeto levará mais tempo para compilar.  
  
> [!TIP]
>  Para atualizar o **Property Pages** caixa de diálogo para que ele exiba as últimas seleções, clique em **Aplicar**.  
  
 A maioria dos padrões de projeto são padrões do sistema \(plataforma\).  Alguns padrões de projeto derivam as folhas de estilo que são aplicadas quando você atualiza as propriedades no **padrões de projeto** seção o **geral** página de propriedades de configuração para o projeto.  Para obter mais informações, consulte [Página de propriedade geral \(projeto\)](../Topic/General%20Property%20Page%20\(Project\).md).  
  
## Especificando valores definidos pelo usuário  
 Você deve definir o valor de determinadas propriedades.  Um valor definido pelo usuário pode conter um ou mais caracteres alfanuméricos ou nomes de macro do arquivo de projeto.  Algumas dessas propriedades podem ter apenas um valor definido pelo usuário, mas outras pessoas possam tirar uma lista delimitada por ponto e vírgula de vários valores.  
  
 Para especificar um valor definido pelo usuário para uma propriedade ou uma lista se a propriedade pode ter vários valores definidos pelo usuário, na coluna à direita do nome da propriedade, execute uma das seguintes ações:  
  
-   Digite o valor ou a lista de valores.  
  
-   Clique na seta suspensa.  Se **Editar** estiver disponível, clique nele e, em seguida, na caixa de texto, digite o valor ou uma lista de valores.  É uma forma alternativa de especificar uma lista para o tipo de cada valor em uma linha separada na caixa de texto.  Na página de propriedade, os valores aparecerá como uma lista delimitada por ponto e vírgula.  
  
     Para inserir uma macro de arquivo de projeto como um valor, clique em **Macros** e, em seguida, clique duas vezes no nome da macro.  
  
-   Clique na seta suspensa.  Se **Procurar** estiver disponível, clique nele e, em seguida, selecione um ou mais valores.  
  
 Para uma propriedade com vários valores, o **Herdar do pai ou padrões de projeto** opção está disponível quando você clica na seta suspensa na coluna à direita do nome da propriedade e, em seguida, clique em **Editar**.  Por padrão, a opção é selecionada.  
  
 Observe que uma página de propriedades exibe apenas as configurações no nível atual para uma propriedade com valores múltiplos que herda de outro nível.  Por exemplo, se um arquivo é selecionado no **Solution Explorer** e selecione C\/C\+\+ **definições de pré\-processador** propriedade, definições de nível de arquivo são exibidas, mas herdadas definições em nível de projeto não são exibidas.  Para exibir os valores de nível atual e herdadas, clique na seta suspensa na coluna à direita do nome da propriedade e, em seguida, clique em **Editar**.  Se você usar o [modelo de projeto do Visual C\+\+](http://msdn.microsoft.com/pt-br/06c1bbd9-4c79-4f97-ad6d-2b1dea8ecd1f), esse comportamento também está em vigor para os objetos em projetos e arquivos.  Ou seja, quando você consulta para os valores em uma propriedade em nível de arquivo, você não obterá os valores para a mesma propriedade no nível do projeto.  Você deve explicitamente obter os valores da propriedade no nível do projeto.  Além disso, alguns valores herdados de uma propriedade podem vir de uma folha de estilos não está acessível por meio de programação.  
  
## Nesta seção  
  
1.  [Caixa de diálogo Adicionar Caminho de Pesquisa da Referência](http://msdn.microsoft.com/pt-br/4520d80d-aa9f-4d11-b92b-2f64a1fd5cb2)  
  
2.  [Avançado, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedade de \<Projectname\>](../Topic/Advanced,%20Manifest%20Tool,%20Configuration%20Properties,%20%3CProjectname%3E%20Property%20Pages%20Dialog%20Box.md)  
  
3.  [Páginas de propriedades Linha de Comando](../ide/command-line-property-pages.md)  
  
4.  [Página de propriedades Etapa de Compilação Personalizada: geral](../ide/custom-build-step-property-page-general.md)  
  
5.  [Adicionando referências](../ide/adding-references-in-visual-cpp-projects.md)  
  
6.  [Página de propriedade geral \(arquivo\)](../ide/general-property-page-file.md)  
  
7.  [Página de propriedade geral \(projeto\)](../Topic/General%20Property%20Page%20\(Project\).md)  
  
8.  [Caixa de diálogo Geral, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedade de \<Projectname\>](../ide/general-manifest-tool-configuration-properties.md)  
  
9. [Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)  
  
10. [Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)  
  
11. [Páginas de propriedade HLSL: geral](../ide/hlsl-property-pages-general.md)  
  
12. [Páginas de propriedades HLSL: arquivos de saída](../ide/hlsl-property-pages-output-files.md)  
  
13. [Caixa de diálogo Entrada e Saída, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedade de \<Projectname\>](../ide/input-and-output-manifest-tool.md)  
  
14. [Caixa de diálogo COM Isolado, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedade de \<Projectname\>](../ide/isolated-com-manifest-tool.md)  
  
15. [Páginas de propriedade do vinculador](../ide/linker-property-pages.md)  
  
16. [Página de propriedades Recursos Gerenciados](../ide/managed-resources-property-page.md)  
  
17. [Páginas de propriedades Ferramenta de Manifesto](../ide/manifest-tool-property-pages.md)  
  
18. [Páginas de propriedade MIDL](../ide/midl-property-pages.md)  
  
19. [Páginas de propriedade MIDL: avançado](../ide/midl-property-pages-advanced.md)  
  
20. [Páginas de propriedade MDL: geral](../ide/midl-property-pages-general.md)  
  
21. [Páginas de propriedades MIDL: saída](../ide/midl-property-pages-output.md)  
  
22. [Página de propriedades NMake](../ide/nmake-property-page.md)  
  
23. [Páginas de propriedades Recursos](../ide/resources-property-pages.md)  
  
24. [Página de propriedade dos diretórios do VC\+\+](../ide/vcpp-directories-property-page.md)  
  
25. [Página de propriedades Referências Web](../ide/web-references-property-page.md)  
  
26. [Página de propriedades Ferramenta de Gerador de Dados XML](../ide/xml-data-generator-tool-property-page.md)  
  
27. [Páginas de propriedade da ferramenta geradora de documento XML](../Topic/XML%20Document%20Generator%20Tool%20Property%20Pages.md)  
  
## Consulte também  
 [Como criar e remover dependências de projeto](../Topic/How%20to:%20Create%20and%20Remove%20Project%20Dependencies.md)   
 [Como criar e editar configurações de teste](../Topic/How%20to:%20Create%20and%20Edit%20Configurations.md)   
 [implantação de aplicativos](http://msdn.microsoft.com/pt-br/4ff8881d-0daf-47e7-bfe7-774c625031b4)