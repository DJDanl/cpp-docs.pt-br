---
title: 'Instruções passo a passo: usando MSBuild para criar um projeto do Visual C++'
ms.date: 05/16/2019
helpviewer_keywords:
- 'msbuild (c++), walkthrough: create a project'
ms.assetid: 52350d1c-c373-4868-923c-5e8be6f67adb
ms.openlocfilehash: c93867f3be3b17f703c549aa5c05f3d327934c26
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417183"
---
# <a name="walkthrough-using-msbuild-to-create-a-visual-c-project"></a>Instruções passo a passo: usando MSBuild para criar um projeto do Visual C++

Este passo a passo demonstra como usar o MSBuild para criar um projeto do Visual Studio C++ em um prompt de comando. Você aprenderá a criar arquivos de origem C++ e um arquivo de projeto baseado em XML para um aplicativo de console Visual C++. Depois de criar o projeto, você aprenderá a personalizar o processo de build.

Este passo a passo ilustra as seguintes tarefas:

- Criar arquivos de origem C++ para o projeto.

- Criar o arquivo de projeto XML do MSBuild.

- Usar o MSBuild para compilar o projeto.

- Usar o MSBuild para personalizar o projeto.

## <a name="prerequisites"></a>Prerequisites

{1&gt;Você precisa dos seguintes itens para concluir esta explicação:&lt;1}

- Uma cópia do Visual Studio com a carga de trabalho **Desenvolvimento para desktop com C++** instalada.

- Uma compreensão geral do sistema MSBuild.

> [!NOTE]
> Não use essa abordagem se você pretende editar o arquivo de projeto posteriormente usando o IDE do Visual Studio. Se você criar um arquivo .vcxproj manualmente, talvez o IDE do Visual Studio não consiga editá-lo nem carregá-lo, especialmente se o projeto usar curingas nos itens de projeto.

> [!NOTE]
> A maioria das instruções de build de nível inferior está contida nos arquivos **.targets** e **.props** definidos no diretório VCTargets, armazenado na propriedade `$(VCTargetsPath)`. O caminho padrão para esses arquivos no Visual Studio 2019 Enterprise Edition é C:\Arquivos de Programas (x86)\Microsoft Visual Studio\2019\Enterprise\MSBuild\Microsoft\VC\v160\Microsoft.Cpp.Common.props.

## <a name="creating-the-c-source-files"></a>Como criar os arquivos de origem C++

Neste passo a passo, você criará um projeto que tem um arquivo de origem e um arquivo de cabeçalho. O arquivo de origem main.cpp contém a função principal para o aplicativo de console. O arquivo de cabeçalho main.h contém o código para incluir o arquivo de cabeçalho iostream. Crie esses arquivos C++ usando o Visual Studio ou um editor de texto como o Visual Studio Code.

### <a name="to-create-the-c-source-files-for-your-project"></a>Para criar os arquivos de origem C++ do projeto

1. Crie um diretório para o projeto.

1. Crie um arquivo chamado main.cpp e adicione o seguinte código a esse arquivo:

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

1. Crie um arquivo chamado main.h e adicione o seguinte código a esse arquivo:

    ```cpp
    // main.h: the application header code.
    /* Additional source code to include. */
    ```

## <a name="creating-the-xml-msbuild-project-file"></a>Como criar o arquivo de projeto XML do MSBuild

Um arquivo de projeto do MSBuild é um arquivo XML que contém um elemento raiz do projeto (`<Project>`). No seguinte projeto de exemplo, o elemento `<Project>` contém sete elementos filho:

- Três marcas de grupo de itens (`<ItemGroup>`) que especificam a configuração do projeto e a plataforma, o nome do arquivo de origem e o nome do arquivo de cabeçalho.

- Três marcas de importação (`<Import>`) que especificam a localização das configurações do Microsoft Visual C++.

- Uma tag de grupo de propriedades (`<PropertyGroup>`) que especifica as configurações do projeto.

### <a name="to-create-the-msbuild-project-file"></a>Para criar o arquivo de projeto do MSBuild

1. Use um editor de texto para criar um arquivo de projeto chamado `myproject.vcxproj` e, em seguida, adicione o elemento `<Project>` raiz a seguir. Insira os elementos nas etapas do procedimento a seguir entre as marcas `<Project>` raiz. (Use ToolsVersion="15.0" se estiver usando o Visual Studio 2017 ou ToolsVersion="16.0" se estiver usando o Visual Studio 2019.)

    ```xml
    <Project DefaultTargets="Build" ToolsVersion="16.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
    </Project>
    ```

1. Adicione os dois elementos filho `<ProjectConfiguration>` a seguir a um elemento `<ItemGroup>`. O elemento filho especifica as configurações de depuração e versão para um sistema operacional Windows de 32 bits:

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

1. Adicione o elemento `<Import>` a seguir que especifica o caminho das configurações padrão do C++ para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
    ```

1. Adicione o elemento de grupo de propriedades (`<PropertyGroup>`) a seguir que especifica duas propriedades do projeto. (Use v141 se estiver usando o Visual Studio 2017 ou v142 se estiver usando o Visual Studio 2019.)

    ```xml
    <PropertyGroup>
      <ConfigurationType>Application</ConfigurationType>
      <PlatformToolset>v142</PlatformToolset>
    </PropertyGroup>
    ```

1. Adicione o elemento `<Import>` a seguir que especifica o caminho das configurações atuais do C++ para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
    ```

1. Adicione o elemento filho `<ClCompile>` a seguir a um elemento `<ItemGroup>`. O elemento filho especifica o nome do arquivo de origem C/C++ a ser compilado:

    ```xml
    <ItemGroup>
      <ClCompile Include="main.cpp" />
    </ItemGroup>
    ```

   > [!NOTE]
   > `<ClCompile>` é um *destino de build* e é definido no diretório **VCTargets**.

1. Adicione o elemento filho `<ClInclude>` a seguir a um elemento `<ItemGroup>`. O elemento filho especifica o nome do arquivo de cabeçalho do arquivo de origem C/C++:

    ```xml
    <ItemGroup>
      <ClInclude Include="main.h" />
    </ItemGroup>
    ```

1. Adicione o elemento `<Import>` a seguir que especifica o caminho do arquivo que define o destino para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Targets" />
    ```

### <a name="complete-project-file"></a>Arquivo de projeto completo

O código a seguir mostra o arquivo de projeto completo criado no procedimento anterior. (Use ToolsVersion="15.0" para o Visual Studio 2017.)

```xml
<Project DefaultTargets="Build" ToolsVersion="16.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
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
    <PlatformToolset>v142</PlatformToolset>
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

## <a name="using-msbuild-to-build-your-project"></a>Como usar o MSBuild para compilar seu projeto

Digite o seguinte comando no prompt de comando para compilar seu aplicativo de console:

`msbuild myproject.vcxproj /p:configuration=debug`

O MSBuild cria um diretório para os arquivos de saída e, em seguida, compila e vincula o projeto para gerar o programa Myproject.exe. Depois que o processo de build for concluído, use o seguinte comando para executar o aplicativo na pasta de depuração:

`myproject`

O aplicativo deverá exibir "Olá do MSBuild!" na janela do console.

## <a name="customizing-your-project"></a>Como personalizar seu projeto

O MSBuild permite que você execute destinos de build predefinidos, aplique propriedades definidas pelo usuário e use ferramentas, etapas de build e eventos personalizados. Esta seção ilustra as seguintes tarefas:

- Usar o MSBuild com destinos de build.

- Usar o MSBuild com propriedades de build.

- Usar o MSBuild com as ferramentas e o compilador de 64 bits.

- Usar o MSBuild com diferentes conjuntos de ferramentas.

- Adicionar personalizações do MSBuild.

### <a name="using-msbuild-with-build-targets"></a>Como usar o MSBuild com destinos de build

Um *destino de build* é um conjunto nomeado de comandos predefinidos ou definidos pelo usuário que podem ser executados durante o build. Use a opção de linha de comando de destino (`/t`) para especificar um destino de build. Para o projeto de exemplo `myproject`, o destino **clean** predefinido exclui todos os arquivos da pasta de depuração e cria um arquivo de log.

No prompt de comando, digite o comando a seguir para limpar `myproject`.

`msbuild myproject.vcxproj /t:clean`

### <a name="using-msbuild-with-build-properties"></a>Como usar o MSBuild com propriedades de build

A opção de linha de comando de propriedade (`/p`) permite que você substitua uma propriedade no arquivo de build do projeto. No projeto de exemplo `myproject`, a configuração de build de versão ou depuração é especificada pela propriedade `Configuration`. O sistema operacional destinado a executar o aplicativo compilado é especificado pela propriedade `Platform`.

No prompt de comando, digite o comando a seguir para criar um build de depuração do aplicativo `myproject` destinado a ser executado no Windows de 32 bits.

`msbuild myproject.vcxproj /p:configuration=debug /p:platform=win32`

Suponha que o projeto de exemplo `myproject` também defina uma configuração para o Windows de 64 bits e outra configuração para um sistema operacional personalizado chamado `myplatform`.

No prompt de comando, digite o comando a seguir para criar um build de versão que é executado no Windows de 64 bits.

`msbuild myproject.vcxproj /p:configuration=release /p:platform=x64`

No prompt de comando, digite o comando a seguir para criar um build de versão para `myplatform`.

`msbuild myproject.vcxproj /p:configuration=release /p:platform=myplatform`

### <a name="using-msbuild-with-the-64-bit-compiler-and-tools"></a>Como usar o MSBuild com as ferramentas e o compilador de 64 bits

Se você tiver instalado o Visual Studio no Windows de 64 bits, por padrão, as ferramentas nativas e cruzadas do x64 de 64 bits estarão instaladas. Configure o MSBuild para usar as ferramentas e o compilador de 64 bits a fim de compilar seu aplicativo definindo a propriedade `PreferredToolArchitecture`. Essa propriedade não afeta as propriedades de configuração do projeto nem da plataforma. Por padrão, a versão de 32 bits das ferramentas é usada. Para especificar a versão de 64 bits do compilador e das ferramentas, adicione o seguinte elemento de grupo de propriedades ao arquivo de projeto MyProject. vcxproj após o elemento `Microsoft.Cpp.default.props` \<importar/>:

```xml
<PropertyGroup>
    <PreferredToolArchitecture>x64</PreferredToolArchitecture>
</PropertyGroup>
```

No prompt de comando, digite o comando a seguir para usar as ferramentas de 64 bits para compilar o aplicativo.

`msbuild myproject.vcxproj /p:PreferredToolArchitecture=x64`

### <a name="using-msbuild-with-a-different-toolset"></a>Como usar o MSBuild com um conjunto de ferramentas diferente

Se você tiver os conjuntos de ferramentas e as bibliotecas de outras versões do Visual C++ instaladas, o MSBuild poderá compilar aplicativos para a versão atual do Visual C++ ou para as outras versões instaladas. Por exemplo, se você tiver instalado o Visual Studio 2012, para especificar o C++ conjunto de ferramentas do Visual 11,0 para Windows XP, adicione o seguinte elemento de grupo de propriedades ao arquivo de projeto MyProject. vcxproj após o elemento `Microsoft.Cpp.props` \<importação/>:

```xml
<PropertyGroup>
    <PlatformToolset>v110_xp</PlatformToolset>
</PropertyGroup>
```

Para recompilar o projeto com o Conjunto de ferramentas do Visual C++ 11.0 para Windows XP, digite os seguintes comandos:

`msbuild myproject.vcxproj /p:PlatformToolset=v110_xp /t:rebuild`

### <a name="adding-msbuild-customizations"></a>Como adicionar personalizações do MSBuild

O MSBuild fornece várias maneiras de personalizar o processo de build. Os seguintes tópicos mostram como adicionar etapas de build, ferramentas e eventos personalizados ao projeto do MSBuild:

- [Como adicionar uma etapa de build personalizada a projetos MSBuild](how-to-add-a-custom-build-step-to-msbuild-projects.md)

- [Como adicionar ferramentas de build personalizadas a projetos MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md)

- [Como usar eventos de build em projetos do MSBuild](how-to-use-build-events-in-msbuild-projects.md)
