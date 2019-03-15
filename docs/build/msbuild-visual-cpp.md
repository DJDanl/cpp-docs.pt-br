---
title: MSBuild na linha de comando – C++
ms.date: 12/12/2018
f1_keywords:
- MSBuild
helpviewer_keywords:
- MSBuild
ms.assetid: 7a1be7ff-0312-4669-adf2-5f5bf507d560
ms.openlocfilehash: 565b1c47b4476fa7cb830e15b978b389f4344ee1
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820462"
---
# <a name="msbuild-on-the-command-line---c"></a>MSBuild na linha de comando – C++

Em geral, é recomendável usar o Visual Studio para definir as propriedades do projeto e invoque o sistema MSBuild. No entanto, você pode usar o **MSBuild** ferramenta diretamente do prompt de comando. O processo de compilação é controlado pelas informações em um arquivo de projeto (. vcxproj) que você pode criar e editar. O arquivo de projeto Especifica opções de compilação com base na compilação estágios, condições e eventos. Além disso, você pode especificar zero ou mais de linha de comando *opções* argumentos.

> **msbuild.exe** [ *project_file* ] [ *options* ]

Use o **/Target** (ou **/t**) e **/p.** (ou **p**) opções de linha de comando para substituir as propriedades específicas e os destinos que estão especificado no arquivo de projeto.

Uma função essencial do arquivo de projeto é especificar uma *destino*, que é uma operação específica aplicada ao seu projeto e as entradas e saídas que são necessárias para executar essa operação. Um arquivo de projeto pode especificar um ou mais destinos, que podem incluir um destino padrão.

Cada destino consiste em uma sequência de um ou mais *tarefas*. Cada tarefa é representada por uma classe do .NET Framework que contém um comando executável. Por exemplo, o [tarefa CL](/visualstudio/msbuild/cl-task) contém o [cl.exe](reference/compiling-a-c-cpp-program.md) comando.

Um *parâmetro de tarefa* é uma propriedade da tarefa de classe e normalmente representa uma opção de linha de comando do comando executável. Por exemplo, o `FavorSizeOrSpeed` parâmetro do `CL` tarefa corresponde à **/Os** e **/Ot** opções do compilador.

Parâmetros adicionais de tarefa dão suporte a infraestrutura do MSBuild. Por exemplo, o `Sources` parâmetro de tarefa especifica um conjunto de tarefas que podem ser consumidos por outras tarefas. Para obter mais informações sobre tarefas do MSBuild, consulte [referência da tarefa](/visualstudio/msbuild/msbuild-task-reference).

A maioria das tarefas exige entradas e saídas, como nomes de arquivos, caminhos e cadeia de caracteres, parâmetros numéricos ou booleanos. Por exemplo, uma entrada comum é o nome de um arquivo de origem. cpp para compilar. Um parâmetro de entrada importante é uma cadeia de caracteres que especifica a configuração de compilação e a plataforma, por exemplo, "depurar\|Win32". Entradas e saídas são especificadas por um ou mais XML definidos pelo usuário `Item` elementos contidos em um `ItemGroup` elemento.

Um arquivo de projeto também pode especificar definidos pelo usuário *propriedades* e `ItemDefinitionGroup` *itens*. Propriedades e itens formam pares nome/valor que podem ser usados como variáveis na compilação. O componente de nome de um par define uma *macro*, e o componente value declara o *valor de macro*. Uma macro de propriedade é acessada usando $(*nome*) notação e uma macro de item é acessado usando %(*nome*) notação.

Outros elementos XML em um arquivo de projeto podem testar macros e, em seguida, defina o valor de qualquer macro ou condicionalmente controlar a execução da compilação. Nomes de macro e cadeias de caracteres literais podem ser concatenadas para gerar construções como um nome de arquivo e caminho. Na linha de comando, o **/p.** opção define ou substitui uma propriedade de projeto. Itens não podem ser referenciados na linha de comando.

O sistema MSBuild pode executar condicional um destino antes ou após outro destino. Além disso, o sistema pode criar um destino com base em se os arquivos que o destino consome são mais recentes que os arquivos que ele emite.

Para obter mais informações sobre o MSBuild, consulte:

- [MSBuild](/visualstudio/msbuild/msbuild) conceitos de visão geral do MSBuild.

- [Referência do MSBuild](/visualstudio/msbuild/msbuild-reference) informações de referência sobre o sistema MSBuild.

- [Referência de esquema de arquivo de projeto](/visualstudio/msbuild/msbuild-project-file-schema-reference) lista os elementos de esquema XML do MSBuild, juntamente com seus atributos e elementos pai e filho. Observe especialmente os [ItemGroup](/visualstudio/msbuild/itemgroup-element-msbuild), [PropertyGroup](/visualstudio/msbuild/propertygroup-element-msbuild), [destino](/visualstudio/msbuild/target-element-msbuild), e [tarefa](/visualstudio/msbuild/task-element-msbuild) elementos.

- [Referência de linha de comando](/visualstudio/msbuild/msbuild-command-line-reference) descreve os argumentos de linha de comando e opções que você pode usar com msbuild.exe.

- [Referência de tarefa](/visualstudio/msbuild/msbuild-task-reference) tarefas do MSBuild descreve. Observe especialmente estas tarefas, que são específicas para o Visual C++: [Tarefa BscMake](/visualstudio/msbuild/bscmake-task), [tarefa CL](/visualstudio/msbuild/cl-task), [tarefa CPPClean](/visualstudio/msbuild/cppclean-task), [tarefa LIB](/visualstudio/msbuild/lib-task), [vincular tarefas](/visualstudio/msbuild/link-task), [tarefa MIDL](/visualstudio/msbuild/midl-task), [Tarefa MT](/visualstudio/msbuild/mt-task), [tarefa RC](/visualstudio/msbuild/rc-task), [tarefa SetEnv](/visualstudio/msbuild/setenv-task), [tarefa VCMessage](/visualstudio/msbuild/vcmessage-task)

## <a name="in-this-section"></a>Nesta seção

|Termo|Definição|
|----------|----------------|
|[Passo a passo: Usando o MSBuild para criar um projeto em Visual C++](walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)|Demonstra como criar um projeto do Visual C++ usando **MSBuild**.|
|[Como: Usar eventos de build em projetos do MSBuild](how-to-use-build-events-in-msbuild-projects.md)|Demonstra como especificar uma ação que ocorre em um estágio particuler na compilação: antes de inicia a compilação; antes do início da etapa de link; ou, após a conclusão da compilação.|
|[Como: Adicionar uma etapa personalizada de build a projetos do MSBuild](how-to-add-a-custom-build-step-to-msbuild-projects.md)|Demonstra como adicionar um estágio definidas pelo usuário para a sequência de compilação.|
|[Como: Adicionar ferramentas personalizadas de build a projetos do MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md)|Demonstra como associar uma ferramenta de compilação de um arquivo específico.|
|[Como: Integrar ferramentas personalizadas a propriedades de projeto](how-to-integrate-custom-tools-into-the-project-properties.md)|Demonstra como adicionar opções para uma ferramenta personalizada para as propriedades do projeto.|
|[Como: Modificar a estrutura de destino e o conjunto de ferramentas da plataforma](how-to-modify-the-target-framework-and-platform-toolset.md)|Demonstra como compilar um projeto para várias estruturas ou conjuntos de ferramentas.|

## <a name="see-also"></a>Consulte também

[Usar o conjunto de ferramentas do MSVC da linha de comando](building-on-the-command-line.md)
