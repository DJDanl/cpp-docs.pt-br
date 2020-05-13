---
title: MSBuild na linha de comando-C++
ms.date: 12/12/2018
helpviewer_keywords:
- MSBuild
ms.assetid: 7a1be7ff-0312-4669-adf2-5f5bf507d560
ms.openlocfilehash: e95d99cf5c63c824bb9bade8e76bc3ca99079669
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220568"
---
# <a name="msbuild-on-the-command-line---c"></a>MSBuild na linha de comando-C++

Em geral, recomendamos que você use o Visual Studio para definir as propriedades do projeto e invocar o sistema MSBuild. No entanto, você pode usar a ferramenta **MSBuild** diretamente do prompt de comando. O processo de compilação é controlado pelas informações em um arquivo de projeto (. vcxproj) que você pode criar e editar. O arquivo de projeto especifica opções de Build com base em estágios de compilação, condições e eventos. Além disso, você pode especificar zero ou mais argumentos de *Opções* de linha de comando.

> **MSBuild. exe** [ *project_file* ] [ *Opções* ]

Use as opções de linha de comando **/target** (ou **/t**) e **/Property** (ou **/p**) para substituir propriedades específicas e destinos especificados no arquivo de projeto.

Uma função essencial do arquivo de projeto é especificar um *destino*, que é uma operação específica aplicada ao seu projeto, e as entradas e saídas necessárias para executar essa operação. Um arquivo de projeto pode especificar um ou mais destinos, que podem incluir um destino padrão.

Cada destino consiste em uma sequência de uma ou mais *tarefas*. Cada tarefa é representada por uma classe .NET Framework que contém um comando executável. Por exemplo, a [tarefa CL](/visualstudio/msbuild/cl-task) contém o comando [CL. exe](reference/compiling-a-c-cpp-program.md) .

Um *parâmetro de tarefa* é uma propriedade da tarefa de classe e normalmente representa uma opção de linha de comando do comando executável. Por exemplo, o `FavorSizeOrSpeed` parâmetro da `CL` tarefa corresponde às opções do compilador **/os** e **/OT** .

Os parâmetros de tarefa adicionais dão suporte à infraestrutura do MSBuild. Por exemplo, o `Sources` parâmetro Task especifica um conjunto de tarefas que podem ser consumidas por outras tarefas. Para obter mais informações sobre tarefas do MSBuild, consulte [referência de tarefas](/visualstudio/msbuild/msbuild-task-reference).

A maioria das tarefas requer entradas e saídas, como nomes de arquivo, caminhos e parâmetros de cadeia de caracteres, numéricos ou boolianos. Por exemplo, uma entrada comum é o nome de um arquivo de origem. cpp a ser compilado. Um parâmetro de entrada importante é uma cadeia de caracteres que especifica a configuração e a plataforma de compilação,\|por exemplo, "depurar Win32". Entradas e saídas são especificadas por um ou mais elementos XML `Item` definidos pelo usuário contidos em um `ItemGroup` elemento.

Um arquivo de projeto também pode especificar *Propriedades* e `ItemDefinitionGroup` *itens*definidos pelo usuário. Propriedades e itens formam pares de nome/valor que podem ser usados como variáveis na compilação. O componente de nome de um par define uma *macro*e o componente de valor declara o *valor da macro*. Uma macro de propriedade é acessada usando a notação $ (*Name*), e uma macro de item é acessada usando%(*Name*).

Outros elementos XML em um arquivo de projeto podem testar macros e, em seguida, definir condicionalmente o valor de qualquer macro ou controlar a execução da compilação. Nomes de macro e cadeias de caracteres literais podem ser concatenados para gerar construções, como um caminho e um nome de arquivo. Na linha de comando, a opção **/Property** define ou substitui uma propriedade de projeto. Itens não podem ser referenciados na linha de comando.

O sistema MSBuild pode executar condicionalmente um destino antes ou depois de outro destino. Além disso, o sistema pode criar um destino com base em se os arquivos que o destino consome são mais novos do que os arquivos emitidos.

Para obter mais informações sobre o MSBuild, consulte:

- [MSBuild](/visualstudio/msbuild/msbuild) Visão geral dos conceitos do MSBuild.

- [Referência do MSBuild](/visualstudio/msbuild/msbuild-reference) Informações de referência sobre o sistema MSBuild.

- [Referência de esquema de arquivo de projeto](/visualstudio/msbuild/msbuild-project-file-schema-reference) Lista os elementos do esquema XML do MSBuild, junto com seus atributos e elementos pai e filho. Observe especialmente os elementos [rowgroup](/visualstudio/msbuild/itemgroup-element-msbuild), [PropertyGroup](/visualstudio/msbuild/propertygroup-element-msbuild), [target](/visualstudio/msbuild/target-element-msbuild)e [Task](/visualstudio/msbuild/task-element-msbuild) .

- [Referência de linha de comando](/visualstudio/msbuild/msbuild-command-line-reference) Descreve os argumentos de linha de comando e as opções que você pode usar com o MSBuild. exe.

- [Referência de tarefa](/visualstudio/msbuild/msbuild-task-reference) Descreve as tarefas do MSBuild. Observe especialmente essas tarefas, que são específicas para Visual C++: [tarefa BSCMAKE](/visualstudio/msbuild/bscmake-task), [tarefa CL](/visualstudio/msbuild/cl-task), [Tarefa CPPClean](/visualstudio/msbuild/cppclean-task), tarefa [lib](/visualstudio/msbuild/lib-task), tarefa [link](/visualstudio/msbuild/link-task), [tarefa de MIDL](/visualstudio/msbuild/midl-task), [tarefa MT](/visualstudio/msbuild/mt-task), [tarefa RC](/visualstudio/msbuild/rc-task), tarefa de [setenv](/visualstudio/msbuild/setenv-task), tarefa de [VCMessage](/visualstudio/msbuild/vcmessage-task)

## <a name="in-this-section"></a>Nesta seção

|Termo|Definição|
|----------|----------------|
|[Walkthrough: usando o MSBuild para criar um projeto do C++](walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)|Demonstra como criar um projeto do Visual Studio C++ usando o **MSBuild**.|
|[Como usar eventos de build em projetos de MSBuild](how-to-use-build-events-in-msbuild-projects.md)|Demonstra como especificar uma ação que ocorre em um estágio particuler na compilação: antes do início da compilação; antes de iniciar a etapa do link; ou após o término da compilação.|
|[Como adicionar uma etapa de build personalizada a projetos MSBuild](how-to-add-a-custom-build-step-to-msbuild-projects.md)|Demonstra como adicionar um estágio definido pelo usuário à sequência de compilação.|
|[Como adicionar ferramentas de compilação personalizadas a projetos MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md)|Demonstra como associar uma ferramenta de compilação a um arquivo específico.|
|[Como integrar ferramentas personalizar a propriedades de projeto](how-to-integrate-custom-tools-into-the-project-properties.md)|Demonstra como adicionar opções para uma ferramenta personalizada às propriedades do projeto.|
|[Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](how-to-modify-the-target-framework-and-platform-toolset.md)|Demonstra como compilar um projeto para várias estruturas ou conjuntos de ferramentas.|

## <a name="see-also"></a>Confira também

[Uso do conjunto de ferramentas MSVC da linha de comando](building-on-the-command-line.md)
