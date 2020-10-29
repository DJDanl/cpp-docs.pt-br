---
title: 'Walkthrough: usando o MSBuild para criar um projeto do Visual Studio C++'
description: Uma explicação que mostra como criar um projeto de linha de comando do MSBuild C++. vcxproj do zero.
ms.date: 10/08/2020
helpviewer_keywords:
- 'MSBuild (C++), walkthrough: create a project'
ms.openlocfilehash: b3d4e8881f926e80e95832a27f7a5106ce876265
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924340"
---
# <a name="walkthrough-using-msbuild-to-create-a-visual-c-project"></a>Instruções passo a passo: usando MSBuild para criar um projeto do Visual C++

Este tutorial demonstra como usar o MSBuild em um prompt de comando para criar um projeto do Visual Studio C++. Você aprenderá a criar um *`.vcxproj`* arquivo de projeto baseado em XML para um aplicativo de console Visual C++. Depois de criar o projeto, você aprenderá a personalizar o processo de build.

> [!IMPORTANT]
> Não use essa abordagem se pretender editar o arquivo de projeto posteriormente usando o IDE do Visual Studio. Se você criar um *`.vcxproj`* arquivo manualmente, o IDE do Visual Studio poderá não ser capaz de editá-lo ou carregá-lo, especialmente se o projeto usar curingas em itens de projeto. Para obter mais informações, consulte [ `.vcxproj` `.props` estrutura de arquivos](./reference/vcxproj-file-structure.md) e [ `.vcxproj` arquivos e curingas](./reference/vcxproj-files-and-wildcards.md).

Este tutorial ilustra essas tarefas:

- Criar arquivos de origem C++ para o projeto.

- Criar o arquivo de projeto XML do MSBuild.

- Usar o MSBuild para compilar o projeto.

- Usar o MSBuild para personalizar o projeto.

## <a name="prerequisites"></a>Pré-requisitos

Você precisa desses pré-requisitos para concluir este passo a passos:

- Uma cópia do Visual Studio com a carga de trabalho **Desenvolvimento para desktop com C++** instalada.

- Uma compreensão geral do sistema MSBuild.

::: moniker range="msvc-140"

> [!NOTE]
> A maioria das instruções de compilação de nível baixo está contida nos *`.targets`* *`.props`* arquivos e definidos na pasta destinos padrão, armazenados na propriedade `$(VCTargetsPath)` . É onde você encontrará arquivos como *`Microsoft.Cpp.Common.props`* . O caminho padrão para esses arquivos no Visual Studio 2015 e nas versões anteriores está em *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\`* .

::: moniker-end

::: moniker range="msvc-150"

> [!NOTE]
> A maioria das instruções de compilação de nível baixo está contida nos *`.targets`* *`.props`* arquivos e definidos na pasta destinos padrão, armazenados na propriedade `$(VCTargetsPath)` . É onde você encontrará arquivos como *`Microsoft.Cpp.Common.props`* . O caminho padrão para esses arquivos no Visual Studio 2017 está em *`%VSINSTALLDIR%Common7\IDE\VC\VCTargets\`* . O Visual Studio 2015 e versões anteriores os armazenaram em *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\`* .

::: moniker-end

::: moniker range=">=msvc-160"

> [!NOTE]
> A maioria das instruções de compilação de nível baixo está contida nos *`.targets`* *`.props`* arquivos e definidos na pasta destinos padrão, armazenados na propriedade `$(VCTargetsPath)` . É onde você encontrará arquivos como *`Microsoft.Cpp.Common.props`* . O caminho padrão para esses arquivos está em *`%VSINSTALLDIR%MSBuild\Microsoft\VC\<version>\`* . O `<version>` elemento Path é específico para a versão do Visual Studio. É *`v160`* para o Visual Studio 2019. O Visual Studio 2017 armazenou esses arquivos em *`%VSINSTALLDIR%Common7\IDE\VC\VCTargets\`* . O Visual Studio 2015 e versões anteriores os armazenaram em *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\`* .

::: moniker-end

## <a name="create-the-c-source-files"></a>Criar os arquivos de origem do C++

Neste passo a passo, você criará um projeto que tem um arquivo de origem e um arquivo de cabeçalho. O arquivo de origem *`main.cpp`* contém a `main` função para o aplicativo de console. O arquivo de cabeçalho *`main.h`* contém o código para incluir o *`<iostream>`* arquivo de cabeçalho. Crie esses arquivos C++ usando o Visual Studio ou um editor de texto como o Visual Studio Code.

### <a name="to-create-the-c-source-files-for-your-project"></a>Para criar os arquivos de origem C++ do projeto

1. Crie uma pasta para seu projeto.

1. Crie um arquivo chamado *`main.cpp`* e adicione este código ao arquivo:

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

1. Crie um arquivo chamado *`main.h`* e adicione este código ao arquivo:

    ```cpp
    // main.h: the application header code.
    /* Additional source code to include. */
    ```

## <a name="creating-the-xml-msbuild-project-file"></a>Como criar o arquivo de projeto XML do MSBuild

Um arquivo de projeto do MSBuild é um arquivo XML que contém um elemento raiz do projeto (`<Project>`). No projeto de exemplo que você criará, o `<Project>` elemento contém sete elementos filho:

- Três marcas de grupo de itens (`<ItemGroup>`) que especificam a configuração do projeto e a plataforma, o nome do arquivo de origem e o nome do arquivo de cabeçalho.

- Três marcas de importação (`<Import>`) que especificam a localização das configurações do Microsoft Visual C++.

- Uma tag de grupo de propriedades (`<PropertyGroup>`) que especifica as configurações do projeto.

### <a name="to-create-the-msbuild-project-file"></a>Para criar o arquivo de projeto do MSBuild

1. Use um editor de texto para criar um arquivo de projeto chamado *`myproject.vcxproj`* e, em seguida, adicione o `<Project>` elemento raiz mostrado aqui. (Use `ToolsVersion="14.0"` se você estiver usando o visual studio 2015, `ToolsVersion="15.0"` se estiver usando o visual Studio 2017 ou `ToolsVersion="16.0"` se estiver usando o Visual Studio 2019.)

    ```xml
    <Project DefaultTargets="Build" ToolsVersion="16.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
    </Project>
    ```

   Insira os elementos nas próximas etapas de procedimento entre as `<Project>` marcas raiz.

1. Adicione esses dois `<ProjectConfiguration>` elementos filho em um `<ItemGroup>` elemento. O elemento filho especifica as configurações de depuração e versão para um sistema operacional Windows de 32 bits:

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

1. Adicione um `<Import>` elemento que especifica o caminho das configurações padrão do C++ para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
    ```

1. Adicione um elemento de grupo de Propriedades ( `<PropertyGroup>` ) que especifica duas propriedades de projeto `<ConfigurationType>` e `<PlatformToolset>` . (Use `v140` como o `<PlatformToolset>` valor se você estiver usando o visual Studio 2015, `v141` se você estiver usando o Visual Studio 2017 ou `v142` se estiver usando o Visual Studio 2019.)

    ```xml
    <PropertyGroup>
      <ConfigurationType>Application</ConfigurationType>
      <PlatformToolset>v142</PlatformToolset>
    </PropertyGroup>
    ```

1. Adicione um `<Import>` elemento que especifica o caminho das configurações C++ atuais para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
    ```

1. Adicione um `<ClCompile>` elemento filho em um `<ItemGroup>` elemento. O elemento filho especifica o nome do arquivo de origem C/C++ a ser compilado:

    ```xml
    <ItemGroup>
      <ClCompile Include="main.cpp" />
    </ItemGroup>
    ```

   > [!NOTE]
   > `<ClCompile>` é um *destino de compilação* e é definido na pasta destinos padrão.

1. Adicione um `<ClInclude>` elemento filho em um `<ItemGroup>` elemento. O elemento filho especifica o nome do arquivo de cabeçalho do arquivo de origem C/C++:

    ```xml
    <ItemGroup>
      <ClInclude Include="main.h" />
    </ItemGroup>
    ```

1. Adicione um `<Import>` elemento que especifica o caminho do arquivo que define o destino para este projeto:

    ```xml
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Targets" />
    ```

### <a name="complete-project-file"></a>Arquivo de projeto completo

Esse código mostra o arquivo de projeto completo que você criou no procedimento anterior. (Use o `ToolsVersion="15.0"` para visual studio 2017 ou `ToolsVersion="14.0"` para visual Studio 2015.)

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

Digite este comando no prompt de comando para criar o aplicativo de console:

> `msbuild myproject.vcxproj /p:configuration=debug`

O MSBuild cria uma pasta para os arquivos de saída e, em seguida, compila e vincula seu projeto para gerar o *`Myproject.exe`* programa. Após a conclusão do processo de compilação, use este comando para executar o aplicativo da pasta de depuração:

> `myproject`

O aplicativo deverá exibir "Olá do MSBuild!" na janela do console.

## <a name="customizing-your-project"></a>Como personalizar seu projeto

O MSBuild permite que você execute destinos de build predefinidos, aplique propriedades definidas pelo usuário e use ferramentas, etapas de build e eventos personalizados. Esta seção ilustra estas tarefas:

- Usar o MSBuild com destinos de build.

- Usar o MSBuild com propriedades de build.

- Usar o MSBuild com as ferramentas e o compilador de 64 bits.

- Usar o MSBuild com diferentes conjuntos de ferramentas.

- Adicionar personalizações do MSBuild.

### <a name="using-msbuild-with-build-targets"></a>Como usar o MSBuild com destinos de build

Um *destino de build* é um conjunto nomeado de comandos predefinidos ou definidos pelo usuário que podem ser executados durante o build. Use a opção de linha de comando de destino ( **`/t`** ) para especificar um destino de compilação. Para o `myproject` projeto de exemplo, o **`clean`** destino predefinido exclui todos os arquivos na pasta de depuração e cria um novo arquivo de log.

No prompt de comando, digite este comando para limpar `myproject` :

> `msbuild myproject.vcxproj /t:clean`

### <a name="using-msbuild-with-build-properties"></a>Como usar o MSBuild com propriedades de build

A opção de linha de comando de propriedade (`/p`) permite que você substitua uma propriedade no arquivo de build do projeto. No projeto de exemplo `myproject`, a configuração de build de versão ou depuração é especificada pela propriedade `Configuration`. O sistema operacional que você usará para executar o aplicativo compilado é especificado pela `Platform` propriedade.

No prompt de comando, digite este comando para criar uma compilação de depuração do `myproject` aplicativo a ser executada no Windows de 32 bits:

> `msbuild myproject.vcxproj /p:configuration=debug /p:platform=win32`

Suponha que o projeto de exemplo `myproject` também defina uma configuração para o Windows de 64 bits e outra configuração para um sistema operacional personalizado chamado `myplatform`.

No prompt de comando, digite este comando para criar uma compilação de versão que é executada no Windows de 64 bits:

> `msbuild myproject.vcxproj /p:configuration=release /p:platform=x64`

No prompt de comando, digite este comando para criar uma compilação de versão para `myplatform` :

> `msbuild myproject.vcxproj /p:configuration=release /p:platform=myplatform`

### <a name="using-msbuild-with-the-64-bit-compiler-and-tools"></a>Como usar o MSBuild com as ferramentas e o compilador de 64 bits

Se você tiver instalado o Visual Studio no Windows de 64 bits, as ferramentas nativas e cruzadas do 64-bit x64 serão instaladas por padrão. Configure o MSBuild para usar as ferramentas e o compilador de 64 bits a fim de compilar seu aplicativo definindo a propriedade `PreferredToolArchitecture`. Essa propriedade não afeta as propriedades de configuração do projeto nem da plataforma. Por padrão, a versão de 32 bits das ferramentas é usada. Para especificar a versão de 64 bits do compilador e das ferramentas, adicione este elemento de grupo de propriedades ao *`Myproject.vcxproj`* arquivo de projeto após o *`Microsoft.Cpp.default.props`* `<Import />` elemento file:

```xml
<PropertyGroup>
    <PreferredToolArchitecture>x64</PreferredToolArchitecture>
</PropertyGroup>
```

No prompt de comando, digite este comando para usar as ferramentas de 64 bits para criar seu aplicativo:

> `msbuild myproject.vcxproj /p:PreferredToolArchitecture=x64`

### <a name="using-msbuild-with-a-different-toolset"></a>Como usar o MSBuild com um conjunto de ferramentas diferente

Se você tiver os conjuntos de ferramentas e as bibliotecas de outras versões do Visual C++ instaladas, o MSBuild poderá compilar aplicativos para a versão atual do Visual C++ ou para as outras versões instaladas. Por exemplo, se você tiver instalado o Visual Studio 2012, para especificar o conjunto de ferramentas Visual C++ 11,0 para o Windows XP, adicione esse elemento de grupo de propriedades ao *`Myproject.vcxproj`* arquivo de projeto após o *`Microsoft.Cpp.props`* `<Import />` elemento file:

```xml
<PropertyGroup>
    <PlatformToolset>v110_xp</PlatformToolset>
</PropertyGroup>
```

Para recriar seu projeto com o conjunto de ferramentas Visual C++ 11,0 do Windows XP, digite este comando:

> `msbuild myproject.vcxproj /p:PlatformToolset=v110_xp /t:rebuild`

### <a name="adding-msbuild-customizations"></a>Como adicionar personalizações do MSBuild

O MSBuild fornece várias maneiras de personalizar o processo de build. Estes artigos mostram como adicionar etapas, ferramentas e eventos de compilação personalizados ao seu projeto do MSBuild:

- [Como adicionar uma etapa de compilação personalizada a projetos do MSBuild](how-to-add-a-custom-build-step-to-msbuild-projects.md)

- [Como: Adicionar ferramentas de Build personalizadas a projetos do MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md)

- [Como: usar eventos de compilação em projetos do MSBuild](how-to-use-build-events-in-msbuild-projects.md)
