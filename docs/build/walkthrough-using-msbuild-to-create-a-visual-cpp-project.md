---
title: 'Passo a passo: Usando MSBuild para criar um projeto do Visual C++'
ms.date: 09/24/2018
f1_keywords:
- msbuild.cpp.walkthrough.createproject
helpviewer_keywords:
- 'msbuild (c++), walkthrough: create a project'
ms.assetid: 52350d1c-c373-4868-923c-5e8be6f67adb
ms.openlocfilehash: c7b038ede8c03f7016c5e9f81a9db785c49da448
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62313591"
---
# <a name="walkthrough-using-msbuild-to-create-a-visual-c-project"></a>Passo a passo: Usando MSBuild para criar um projeto do Visual C++

Este passo a passo demonstra como usar o MSBuild para compilar um projeto do Visual C++ em um prompt de comando. Você aprenderá a criar os arquivos de origem do C++ e um arquivo de projeto com base em XML para um aplicativo de console do Visual C++. Depois de criar o projeto, você aprenderá como personalizar o processo de compilação.

Esta explicação passo a passo ilustra as seguintes tarefas:

- Criando os arquivos de origem do C++ para o seu projeto.

- Criando o arquivo de projeto do MSBuild XML.

- Usando o MSBuild para compilar seu projeto.

- Usando o MSBuild para personalizar seu projeto.

## <a name="prerequisites"></a>Pré-requisitos

Você precisa dos seguintes itens para concluir esta explicação:

- Uma cópia do Visual Studio com o **desenvolvimento para Desktop com C++** carga de trabalho instalada.

- Uma compreensão geral do sistema MSBuild.

> [!NOTE]
> Não use essa abordagem se você pretende editar o arquivo de projeto mais tarde usando o IDE do Visual Studio. Se você criar manualmente um arquivo. vcxproj, o IDE do Visual Studio pode não ser capaz de editar ou carregá-lo, especialmente se o projeto usa caracteres curinga em itens de projeto.

> [!NOTE]
> A maioria das instruções de compilação de nível inferior está contida na **. targets** e **Props** arquivos que são definidos no diretório VCTargets, armazenado na propriedade `$(VCTargetsPath)`. O caminho padrão para esses arquivos no Visual Studio 2017 Enterprise Edition é c:\\arquivos de programas (x86)\\Microsoft Visual Studio\\2017\\Enterprise\\Common7\\IDE\\ VC\\VCTargets\\.

## <a name="creating-the-c-source-files"></a>Criando os arquivos de origem do C++

Neste passo a passo, você criará um projeto que tem um arquivo de origem e um arquivo de cabeçalho. A fonte arquivo cpp contém a função principal para o aplicativo de console. O arquivo de cabeçalho Main. h contém código para incluir o arquivo de cabeçalho iostream. Você pode criar esses arquivos de C++ usando Visual Studio ou um texto de editor como o Visual Studio Code.

### <a name="to-create-the-c-source-files-for-your-project"></a>Para criar os arquivos de origem do C++ para o seu projeto

1. Crie um diretório para seu projeto.

1. Crie um arquivo chamado main cpp e adicione o seguinte código para este arquivo:

    ```cpp
    // main.cpp : the application source code.
    #include <iostream>
    #include "main.h"
    int main()
    {
       std::cout << "Hello, from MSBuild!\n";
       return 0;
    }
    ```

1. Crie um arquivo chamado main. h e adicione o seguinte código para este arquivo:

    ```cpp
    // main.h: the application header code.
    /* Additional source code to include. */
    ```

## <a name="creating-the-xml-msbuild-project-file"></a>Criando o arquivo de projeto do MSBuild XML

Um arquivo de projeto do MSBuild é um arquivo XML que contém um elemento raiz do projeto (`<Project>`). No projeto de exemplo a seguir, o `<Project>` elemento contém sete elementos filho:

- Três marcas do grupo de itens (`<ItemGroup>`) que especificam a configuração do projeto e plataforma, nome do arquivo de origem e o nome de arquivo do cabeçalho.

- Três marcas de importação (`<Import>`) que especificam a localização das configurações do Microsoft Visual C++.

- Uma marca de grupo de propriedade (`<PropertyGroup>`) que especifica as configurações do projeto.

### <a name="to-create-the-msbuild-project-file"></a>Para criar o arquivo de projeto do MSBuild

1. Use um editor de texto para criar um arquivo de projeto é denominado `myproject.vcxproj`e em seguida, adicione a seguinte raiz `<Project>` elemento. Inserir os elementos nas etapas do procedimento a seguir entre a raiz do `<Project>` marcas:

    ```xml
    <Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
    </Project>
    ```

1. Adicione as duas seguintes `<ProjectConfiguration>` elementos filho em um `<ItemGroup>` elemento. O elemento filho Especifica depuração e configurações para um sistema de operacional do Windows de 32 bits de versão:

    ```xml
    <ItemGroup>
      <ProjectConfiguration Include="Debug|Win32">
        <Configuration>Debug</Configuration>
        <Platform>Win32</Platform>
      </ProjectConfiguration>
      <ProjectConfiguration Include="Release|Win32">
        <Configuration>Release</Configuration>
        <Platform>Win32</Platform>
      </ProjectConfiguration>
    </ItemGroup>
    ```

1. Adicione o seguinte `<Import>` elemento que especifica o caminho das configurações padrão do C++ para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
    ```

1. Adicione o seguinte elemento de grupo de propriedade (`<PropertyGroup>`) que especifica duas propriedades do projeto:

    ```xml
    <PropertyGroup>
      <ConfigurationType>Application</ConfigurationType>
      <PlatformToolset>v141</PlatformToolset>
    </PropertyGroup>
    ```

1. Adicione o seguinte `<Import>` elemento que especifica o caminho das configurações atuais de C++ para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
    ```

1. Adicione o seguinte `<ClCompile>` elemento filho em um `<ItemGroup>` elemento. O elemento filho Especifica o nome do arquivo de origem C/C++ para compilar:

    ```xml
    <ItemGroup>
      <ClCompile Include="main.cpp" />
    </ItemGroup>
    ```

   > [!NOTE]
   > `<ClCompile>` é um *destino de build* e é definido na **VCTargets** directory.

1. Adicione o seguinte `<ClInclude>` elemento filho em um `<ItemGroup>` elemento. O elemento filho Especifica o nome do arquivo de cabeçalho para o arquivo de origem do C/C++:

    ```xml
    <ItemGroup>
      <ClInclude Include="main.h" />
    </ItemGroup>
    ```

1. Adicione o seguinte `<Import>` elemento que especifica o caminho do arquivo que define o destino para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Targets" />
    ```

### <a name="complete-project-file"></a>Arquivo de projeto completo

O código a seguir mostra o arquivo de projeto completo que você criou no procedimento anterior.

```xml
<Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <ProjectConfiguration Include="Debug|Win32">
      <Configuration>Debug</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|Win32">
      <Configuration>Release</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
  <PropertyGroup>
    <ConfigurationType>Application</ConfigurationType>
    <PlatformToolset>v141</PlatformToolset>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ItemGroup>
    <ClCompile Include="main.cpp" />
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="main.h" />
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Targets" />
</Project>
```

## <a name="using-msbuild-to-build-your-project"></a>Usando o MSBuild para compilar seu projeto

Digite o seguinte comando no prompt de comando para compilar seu aplicativo de console:

`msbuild myproject.vcxproj /p:configuration=debug`

MSBuild cria um diretório para arquivos de saída e, em seguida, compila e vincula seu projeto para gerar o programa Myproject.exe. Depois que o processo de compilação for concluída, use o seguinte comando para executar o aplicativo a partir da pasta de depuração:

`myproject`

O aplicativo deve exibir "Hello, do MSBuild!" na janela do console.

## <a name="customizing-your-project"></a>Personalizando seu projeto

MSBuild permite que você execute destinos predefinidos de compilação, aplique propriedades definidas pelo usuário e use ferramentas personalizadas, eventos e etapas de compilação. Esta seção ilustra as seguintes tarefas:

- Usando o MSBuild com destinos de compilação.

- Usando o MSBuild com propriedades de compilação.

- Usando o MSBuild com o compilador de 64 bits e ferramentas.

- Usando o MSBuild com diferentes conjuntos de ferramentas.

- Adicionando personalizações do MSBuild.

### <a name="using-msbuild-with-build-targets"></a>Usando o MSBuild com destinos de compilação

Um *destino de build* é um conjunto nomeado de comandos predefinidos ou definidos pelo usuário que podem ser executadas durante a compilação. Use a opção de linha de comando de destino (`/t`) para especificar um destino de compilação. Para o `myproject` projeto de exemplo, predefinida **limpa** destino exclui todos os arquivos na pasta de depuração e cria um novo arquivo de log.

No prompt de comando, digite o seguinte comando para limpar `myproject`.

`msbuild myproject.vcxproj /t:clean`

### <a name="using-msbuild-with-build-properties"></a>Usando o MSBuild com propriedades de compilação

A opção de linha de comando de propriedade (`/p`) permite que você substitua uma propriedade em seu arquivo de compilação do projeto. No `myproject` configuração de build de projeto, a versão ou depuração de exemplo é especificada pelo `Configuration` propriedade. E o sistema operacional que destina-se para executar o aplicativo compilado é especificado pelo `Platform` propriedade.

No prompt de comando, digite o seguinte comando para criar uma compilação de depuração a `myproject` aplicativo destina-se para ser executado no Windows de 32 bits.

`msbuild myproject.vcxproj /p:configuration=debug /p:platform=win32`

Suponha que o `myproject` exemplo de projeto também define uma configuração para Windows de 64 bits e outra configuração para um sistema operacional personalizado chamado `myplatform`.

No prompt de comando, digite o seguinte comando para criar uma versão de compilação que é executado no Windows de 64 bits.

`msbuild myproject.vcxproj /p:configuration=release /p:platform=x64`

No prompt de comando, digite o seguinte comando para criar um build de versão para `myplatform`.

`msbuild myproject.vcxproj /p:configuration=release /p:platform=myplatform`

### <a name="using-msbuild-with-the-64-bit-compiler-and-tools"></a>Usando o MSBuild com o compilador de 64 bits e ferramentas

Se você tiver instalado o Visual C++ no Windows de 64 bits, por padrão, 64 bits x64 nativos e cruzados ferramentas são instaladas. Você pode configurar o MSBuild para usar o compilador de 64 bits e ferramentas para compilar seu aplicativo definindo o `PreferredToolArchitecture` propriedade. Essa propriedade não afeta as propriedades de configuração ou da plataforma do projeto. Por padrão, a versão de 32 bits das ferramentas é usada. Para especificar a versão de 64 bits do compilador e ferramentas, adicione o seguinte elemento de grupo de propriedade ao arquivo de projeto myproject. vcxproj após o `Microsoft.Cpp.default.props` \<importação / > elemento:

```xml
<PropertyGroup>
    <PreferredToolArchitecture>x64</PreferredToolArchitecture>
</PropertyGroup>
```

No prompt de comando, digite o seguinte comando para usar as ferramentas de 64 bits para compilar seu aplicativo.

`msbuild myproject.vcxproj /p:PreferredToolArchitecture=x64`

### <a name="using-msbuild-with-a-different-toolset"></a>Usando o MSBuild com um conjunto de ferramentas diferente

Se você tiver os conjuntos de ferramentas e bibliotecas para outras versões do Visual C++ instalado, o MSBuild pode criar aplicativos para a versão do Visual C++ atual ou para as outras versões instaladas. Por exemplo, se você tiver instalado o Visual Studio 2012, para especificar o conjunto de ferramentas do Visual C++ 11.0 para o Windows XP, adicione o seguinte elemento de grupo de propriedade ao arquivo de projeto myproject. vcxproj após o `Microsoft.Cpp.props` \<importação / > elemento:

```xml
<PropertyGroup>
    <PlatformToolset>v110_xp</PlatformToolset>
</PropertyGroup>
```

Para recompilar o projeto com o conjunto de ferramentas do Visual C++ 11.0 Windows XP, digite os seguintes comandos:

`msbuild myproject.vcxproj /p:PlatformToolset=v110_xp /t:rebuild`

### <a name="adding-msbuild-customizations"></a>Adicionando personalizações do MSBuild

O MSBuild fornece várias maneiras para personalizar o processo de compilação. Os tópicos a seguir mostram como adicionar etapas de compilação personalizada, ferramentas e eventos ao seu projeto do MSBuild:

- [Como: Adicionar uma etapa personalizada de build a projetos do MSBuild](how-to-add-a-custom-build-step-to-msbuild-projects.md)

- [Como: Adicionar ferramentas personalizadas de build a projetos do MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md)

- [Como: Usar eventos de build em projetos do MSBuild](how-to-use-build-events-in-msbuild-projects.md)
