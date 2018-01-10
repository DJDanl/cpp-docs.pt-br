---
title: 'Passo a passo: Usando MSBuild para criar um projeto Visual C++ | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: msbuild.cpp.walkthrough.createproject
dev_langs: C++
helpviewer_keywords: 'msbuild (c++), walkthrough: create a project'
ms.assetid: 52350d1c-c373-4868-923c-5e8be6f67adb
caps.latest.revision: "27"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 92b954f334517adc22ca17f8324ec1a78819d9f1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-using-msbuild-to-create-a-visual-c-project"></a>Instruções passo a passo: usando MSBuild para criar um projeto do Visual C++
Este passo a passo demonstra como usar [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para compilar um projeto do Visual C++ em um prompt de comando. Você aprenderá como criar os arquivos de origem do C++ e um arquivo de projeto com base em XML para um aplicativo de console do Visual C++. Depois de criar o projeto, você aprenderá como personalizar o processo de compilação.  
  
 Esta explicação passo a passo ilustra as seguintes tarefas:  
  
-   Criando arquivos de origem do C++ para o seu projeto.  
  
-   Criando XML [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] arquivo de projeto.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para compilar o projeto.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para personalizar seu projeto.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você precisa dos seguintes itens para concluir esta explicação:  
  
-   [!INCLUDE[vs_dev12](../atl-mfc-shared/includes/vs_dev12_md.md)]  
  
-   Uma compreensão geral do [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] sistema.  
  
## <a name="creating-the-c-source-files"></a>Criar os arquivos de origem do C++  
 Este passo a passo, você criará um projeto que tem um arquivo de origem e um arquivo de cabeçalho. O main.cpp do arquivo de origem contém a função principal para o aplicativo de console. O main.h do arquivo de cabeçalho contém código para incluir o arquivo de cabeçalho iostream. Você pode criar esses arquivos C++ usando [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] ou um editor de texto.  
  
#### <a name="to-create-the-c-source-files-for-your-project"></a>Para criar os arquivos de origem do C++ para o seu projeto  
  
1.  Crie um diretório para seu projeto.  
  
2.  Crie um arquivo chamado main.cpp e adicione o seguinte código para este arquivo:  
  
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
  
3.  Crie um arquivo chamado main.h e adicione o seguinte código para este arquivo:  
  
    ```hlsl  
    // main.h: the application header code.  
    /* Additional source code to include. */  
    ```  
  
## <a name="creating-the-xml-msbuild-project-file"></a>Criar o arquivo de projeto do MSBuild XML  
 Um [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] arquivo de projeto é um arquivo XML que contém um elemento de raiz do projeto (\<projeto >). No projeto de exemplo a seguir, o \<projeto > elemento contém sete elementos filho:  
  
-   Três marcas de grupo de item (\<ItemGroup >) que especificam a configuração do projeto e plataforma, nome do arquivo de origem e nome do arquivo de cabeçalho.  
  
-   Três importar tags (\<Importar >) que especificam a localização das configurações do Microsoft Visual C++.  
  
-   Uma marca de grupo de propriedade (\<PropertyGroup >) que especifica as configurações do projeto.  
  
#### <a name="to-create-the-msbuild-project-file"></a>Para criar o arquivo de projeto do MSBuild  
  
1.  Use um editor de texto para criar um arquivo de projeto chamado `myproject.vcxproj`e em seguida, adicione a seguinte raiz \<projeto > elemento. Inserir os elementos nas etapas do procedimento a seguir entre a raiz \<projeto > marcas:  
  
    ```xml  
    <Project DefaultTargets="Build" ToolsVersion="12.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">  
    </Project>  
    ```  
  
2.  Adicione os dois seguintes \<ProjectConfiguration > elementos filho em um \<ItemGroup > elemento. O elemento filho Especifica depuração e configurações para um sistema de operacional do Windows de 32 bits de versão:  
  
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
  
3.  Adicione o seguinte \<importação / > elemento que especifica o caminho das configurações de C++ padrão para este projeto:  
  
    ```xml  
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />  
  
    ```  
  
4.  Adicione o seguinte elemento de grupo de propriedade (\<PropertyGroup >) que especifica duas propriedades do projeto:  
  
    ```xml  
    <PropertyGroup>  
      <ConfigurationType>Application</ConfigurationType>  
      <PlatformToolset>v120</PlatformToolset>  
    </PropertyGroup>  
    ```  
  
5.  Adicione o seguinte \<importação / > elemento que especifica o caminho das configurações atuais de C++ para este projeto:  
  
    ```xml  
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />  
    ```  
  
6.  Adicione o seguinte \<ClCompile > elemento filho em um \<ItemGroup > elemento. O elemento filho Especifica o nome do arquivo de origem C/C++ para compilar:  
  
    ```xml  
    <ItemGroup>  
      <ClCompile Include="main.cpp" />  
    </ItemGroup>  
    ```  
  
7.  Adicione o seguinte \<ClInclude > elemento filho em um \<ItemGroup > elemento. O elemento filho Especifica o nome do arquivo de cabeçalho do arquivo de origem C/C++:  
  
    ```xml  
    <ItemGroup>  
      <ClInclude Include="main.h" />  
    </ItemGroup>  
    ```  
  
8.  Adicione o seguinte \<importação > elemento que especifica o caminho do arquivo que define o destino para este projeto:  
  
    ```xml  
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Targets" />  
  
    ```  
  
### <a name="complete-project-file"></a>Arquivo de projeto concluída  
 O código a seguir mostra o arquivo de projeto completo que você criou no procedimento anterior.  
  
```xml  
<Project DefaultTargets="Build" ToolsVersion="12.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">  
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
    <PlatformToolset>v120</PlatformToolset>  
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
 Digite o seguinte comando no prompt de comando para criar seu aplicativo de console:  
  
```  
msbuild myproject.vcxproj /p:configuration=debug  
```  
  
 [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)]cria um diretório para arquivos de saída e, em seguida, compila e vincula seu projeto para gerar o programa Myproject.exe. Após a conclusão do processo de compilação, use o seguinte comando para executar o aplicativo:  
  
```  
myproject  
```  
  
 O aplicativo deve exibir "Olá, do MSBuild!" na janela do console.  
  
## <a name="customizing-your-project"></a>Personalizando seu projeto  
 [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)]permite que você execute destinos de compilação predefinidos, aplicar propriedades definidas pelo usuário e usar ferramentas personalizadas, eventos e etapas de compilação. Esta seção ilustra as seguintes tarefas:  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com destinos de compilação.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com propriedades de compilação.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com as ferramentas e o compilador de 64 bits.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com diferentes conjuntos de ferramentas.  
  
-   Adicionando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] personalizações.  
  
### <a name="using-msbuild-with-build-targets"></a>Usando MSBuild com destinos de compilação  
 Um *criar destino* é um conjunto nomeado de comandos predefinidos ou definidos pelo usuário que podem ser executadas durante a compilação. Use a opção de linha de comando de destino (**/t**) para especificar um destino de compilação. No caso do `myproject` projeto de exemplo, predefinida **limpa** destino exclui todos os arquivos na pasta de depuração e cria um novo arquivo de log.  
  
 No prompt de comando, digite o seguinte comando para limpar `myproject`.  
  
 `msbuild myproject.vcxproj /t:clean`  
  
### <a name="using-msbuild-with-build-properties"></a>Usando MSBuild com propriedades de compilação  
 A opção de linha de comando de propriedade (**/p**) permite que você substitua uma propriedade no arquivo de compilação do projeto. No `myproject` configuração de compilação de projeto, a versão ou de depuração de exemplo é especificada pelo `Configuration` propriedade. E o sistema operacional que é destinado para executar o aplicativo interno é especificado pelo `Platform` propriedade.  
  
 No prompt de comando, digite o seguinte comando para criar uma compilação de depuração do `myproject` aplicativo que se destina a ser executados no Windows de 32 bits.  
  
 `msbuild myproject.vcxproj /p:configuration=debug /p:platform=win32`  
  
 Suponha que o `myproject` exemplo projeto também define uma configuração para Windows de 64 bits e outra configuração para um sistema operacional personalizado chamado `myplatform`.  
  
 No prompt de comando, o tipo, o seguinte comando para criar uma versão de compilação que é executado no Windows de 64 bits.  
  
 `msbuild myproject.vcxproj /p:configuration=release /p:platform=x64`  
  
 No prompt de comando, digite o seguinte comando para criar uma compilação de versão para `myplatform`.  
  
 `msbuild myproject.vcxproj /p:configuration=release /p:platform=myplatform`  
  
### <a name="using-msbuild-with-the-64-bit-compiler-and-tools"></a>Usando MSBuild com as ferramentas e o compilador de 64 bits  
 Se você tiver instalado o Visual C++ no Windows de 64 bits, por padrão, 64 bits x64 nativo e entre ferramentas são instalados. Você pode configurar [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para usar o compilador de 64 bits e as ferramentas para criar seu aplicativo, definindo o `PreferredToolArchitecture` propriedade. Essa propriedade não afeta as propriedades de configuração ou a plataforma do projeto. Por padrão, a versão de 32 bits das ferramentas é usada. Para especificar a versão de 64 bits do compilador e ferramentas, adicione o seguinte elemento de grupo de propriedade para o arquivo de projeto Myproject.vcxproj após o `Microsoft.Cpp.default.props` \<importação / > elemento:  
  
```xml  
<PropertyGroup>  
    <PreferredToolArchitecture>x64</PreferredToolArchitecture>  
</PropertyGroup>  
```  
  
 No prompt de comando, digite o seguinte comando para usar as ferramentas de 64 bits para criar seu aplicativo.  
  
 `msbuild myproject.vcxproj /p:PreferredToolArchitecture=x64`  
  
### <a name="using-msbuild-with-a-different-toolset"></a>Usando MSBuild com um conjunto de ferramentas diferente  
 Se você tiver os conjuntos de ferramentas e bibliotecas para outras versões do Visual C++ instalado, [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] podem criar aplicativos para a versão atual do Visual C++ ou para as outras versões instaladas. Por exemplo, se você instalou [!INCLUDE[cpp_dev11_long](../build/includes/cpp_dev11_long_md.md)], para especificar o conjunto de ferramentas 11.0 do Visual C++ para Windows XP, adicione o seguinte elemento de grupo de propriedade para o arquivo de projeto Myproject.vcxproj após o Microsoft.Cpp.props `<Import />` elemento:  
  
```xml  
<PropertyGroup>  
    <PlatformToolset>v110_xp</PlatformToolset>  
</PropertyGroup>  
```  
  
 Para recriar seu projeto com o conjunto de ferramentas do Visual C++ 11.0 Windows XP, digite um dos comandos a seguir:  
  
 `msbuild myproject.vcxproj /p:PlatformToolset=v110_xp /t:rebuild`  
  
 `msbuild myproject.vcxproj /t:rebuild`  
  
### <a name="adding-msbuild-customizations"></a>Adicionar personalizações do MSBuild  
 [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)]fornece várias maneiras de personalizar o processo de compilação. Os tópicos a seguir mostram como adicionar etapas de compilação personalizada, ferramentas e eventos para seu [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] projeto:  
  
-   [Como adicionar uma etapa de build personalizada a projetos MSBuild](../build/how-to-add-a-custom-build-step-to-msbuild-projects.md)  
  
-   [Como adicionar ferramentas de build personalizadas a projetos MSBuild](../build/how-to-add-custom-build-tools-to-msbuild-projects.md)  
  
-   [Como usar eventos de build em projetos do MSBuild](../build/how-to-use-build-events-in-msbuild-projects.md)