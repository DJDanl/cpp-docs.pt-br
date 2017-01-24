---
title: "Instru&#231;&#245;es passo a passo: usando MSBuild para criar um projeto do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "msbuild.cpp.walkthrough.createproject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "msbuild (c++), explicações passo a passo: criar um projeto"
ms.assetid: 52350d1c-c373-4868-923c-5e8be6f67adb
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: usando MSBuild para criar um projeto do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa explicação passo a passo demonstra como usar [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para compilar um projeto [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] em um prompt de comando.  Você aprenderá como criar arquivos de origem do C\+\+ e um arquivo de projeto com base em XML para um aplicativo de console de [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] .  Após compilar o projeto, você aprenderá como personalizar o processo de compilação.  
  
 Essa explicação passo a passo mostra as seguintes tarefas:  
  
-   Criando os arquivos de origem do C\+\+ para seu projeto.  
  
-   Criando o arquivo de projeto [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] XML.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para compilar seu projeto.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para personalizar seu projeto.  
  
## Pré-requisitos  
 Você precisa dos seguintes itens para concluir esta explicação passo a passo:  
  
-   [!INCLUDE[vs_dev12](../atl-mfc-shared/includes/vs_dev12_md.md)]  
  
-   Uma compreensão geral do sistema de [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)].  
  
## Criando os arquivos de origem do C\+\+  
 Nesta explicação passo a passo, você criará um projeto com um arquivo de origem e um arquivo de cabeçalho.  O arquivo de origem main.cpp contém a função principal para o aplicativo de console.  O arquivo de cabeçalho main.h contém o código para incluir o arquivo de cabeçalho iostream.  Você pode criar esses arquivos de C\+\+ usando [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] ou um editor de texto.  
  
#### Para criar os arquivos de origem do C\+\+ para seu projeto  
  
1.  Crie um diretório para seu projeto.  
  
2.  Crie um arquivo chamado main.cpp e adicione o seguinte código a este arquivo:  
  
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
  
3.  Crie um arquivo chamado main.h e adicione o seguinte código a este arquivo:  
  
    ```hlsl  
    // main.h: the application header code.  
    /* Additional source code to include. */  
    ```  
  
## Criando o arquivo de projeto do MSBuild XML  
 Um arquivo de projeto de [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] é um arquivo XML que contém um elemento raiz do projeto \(\<Project\>\).  No projeto de exemplo a seguir, o elemento \<Projeto\> contém sete elementos filho:  
  
-   Três marcas de grupo de item \(\<ItemGroup\>\) que especificam a configuração e a plataforma do projeto, o nome do arquivo de origem e o nome do arquivo do cabeçalho.  
  
-   Três marcas de importação \(\<Importação\>\) que especificam o local das configurações do Microsoft [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  
  
-   Uma tag de grupo de propriedade \(\<PropertyGroup\>\) que especifica as configurações do projeto.  
  
#### Para criar o arquivo de projeto do MSBuild  
  
1.  Use um editor de texto para criar um arquivo de projeto chamado `myproject.vcxproj` e adicione o seguinte elemento raiz \<Projeto\>.  Insira os elementos nas etapas do procedimento a seguir entre as marcas do \>Projeto\< raiz:  
  
    ```xml  
    <Project DefaultTargets="Build" ToolsVersion="12.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">  
    </Project>  
    ```  
  
2.  Adicione os dois elementos filhos \<ProjectConfiguration\> em um elemento \<ItemGroup\>.  O elemento filho especifica configurações de depuração e versão para um sistema operacional Windows de 32 bits:  
  
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
  
3.  Adicione o seguinte elemento de \<importação\/\> que especifica o caminho das configurações padrão do C\+\+ para este projeto.  
  
    ```xml  
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />  
  
    ```  
  
4.  Adicione o seguinte elemento do grupo de propriedade \(\<PropertyGroup\>\) que especifica duas propriedades de projeto:  
  
    ```xml  
    <PropertyGroup>  
      <ConfigurationType>Application</ConfigurationType>  
      <PlatformToolset>v120</PlatformToolset>  
    </PropertyGroup>  
    ```  
  
5.  Adicione o seguinte elemento de \<importação\/\> que especifica o caminho das configurações atuais do C\+\+ para este projeto.  
  
    ```xml  
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />  
    ```  
  
6.  Adicione o seguinte elemento filho \<ClCompile\> em um elemento \<ItemGroup\>.  O elemento filho especifica o nome do arquivo de origem C\/C\+\+ a ser compilado:  
  
    ```xml  
    <ItemGroup>  
      <ClCompile Include="main.cpp" />  
    </ItemGroup>  
    ```  
  
7.  Adicione o seguinte elemento filho \<ClInclude\> em um elemento \<ItemGroup\>.  O elemento filho especifica o nome do arquivo de cabeçalho do arquivo de origem C\/C\+\+:  
  
    ```xml  
    <ItemGroup>  
      <ClInclude Include="main.h" />  
    </ItemGroup>  
    ```  
  
8.  Adicione o seguinte elemento de \<importação\> que especifica o caminho do arquivo que define o destino para este projeto:  
  
    ```xml  
    <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Targets" />  
  
    ```  
  
### Arquivo de Projeto Completo  
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
  
## Usando o MSBuild para compilar seu Projeto  
 Digite o seguinte comando no prompt de comando para compilar um aplicativo de console:  
  
```  
msbuild myproject.vcxproj /p:configuration=debug  
```  
  
 [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] cria um diretório para os arquivos de saída e em seguida, compila e vincula seu projeto para gerar o programa Myproject.exe.  Após o processo de compilação ser finalizado, use o seguinte comando para executar o aplicativo:  
  
```  
myproject  
```  
  
 O aplicativo deve exibir "Saudações do MSBuild\!" na janela do console.  
  
## Personalizando seu projeto  
 [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] permite que você execute destinos predefinidos de compilação, aplique propriedades definidas pelo usuário e use ferramentas personalizadas, eventos e etapas de compilação.  Essa seção ilustra as seguintes tarefas:  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com destinos de compilação.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com propriedades de compilação.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com o compilador e com as ferramentas de 64 bits.  
  
-   Usando [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] com conjuntos de ferramentas diferentes.  
  
-   Adicionando personalizações do [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)].  
  
### Usando o MSBuild com destinos de compilação  
 Um *destino de compilação* é chamado um conjunto de comandos predefinidos ou definidos pelo usuário que podem ser executados durante a compilação.  Use a opção de linha de comando de destino \(**\/t**\) para especificar um destino de compilação.  No caso do projeto de exemplo `myproject`, o destino predefinido de **clean** exclui todos os arquivos na pasta de depuração e cria um novo arquivo de log.  
  
 No prompt de comando, digite o seguinte comando para limpar `myproject`.  
  
 `msbuild myproject.vcxproj /t:clean`  
  
### Usando o MSBuild com propriedades de compilação  
 A opção de linha de comando de propriedade \(**\/p**\) permite que você substitua uma propriedade no arquivo de compilação do projeto.  No projeto de exemplo `myproject`, a configuração de versão ou de compilação de depuração é especificada pela propriedade `Configuration`.  E o sistema operacional que destina\-se a executar o aplicativo compilado é especificado pela propriedade de `Platform`.  
  
 No prompt de comando, digite o seguinte comando para criar uma compilação de depuração do aplicativo de `myproject` que destina\-se a ser executado no Windows 32 bits.  
  
 `msbuild myproject.vcxproj /p:configuration=debug /p:platform=win32`  
  
 Suponha que o projeto de `myproject` também define uma configuração do Windows 64 bits, e outra configuração para um sistema operacional personalizado chamado `myplatform`.  
  
 No prompt de comando, digite o seguinte comando para criar uma compilação de lançamento que funciona em Windows 64 bits.  
  
 `msbuild myproject.vcxproj /p:configuration=release /p:platform=x64`  
  
 No prompt de comando, digite o seguinte comando para criar uma compilação de lançamento para o `myplatform`.  
  
 `msbuild myproject.vcxproj /p:configuration=release /p:platform=myplatform`  
  
### Usando o MSBuild com o compilador e com ferramentas de 64 bits  
 Se você instalou o [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] no Windows de 64 bits, por padrão, as ferramentas nativas do x64 e cruzadas serão instaladas.  Você pode configurar [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] para usar o compilador e ferramentas de 64 bits para compilar seu aplicativo definindo a propriedade de `PreferredToolArchitecture` .  Essa propriedade não afeta as propriedades de configuração ou da plataforma do projeto.  Por padrão, a versão de 32 bits de ferramentas é usada.  Para especificar a versão de 64 bits do compilador e as ferramentas, adicione o seguinte elemento do grupo de propriedade para o arquivo de projeto Myproject.vcxproj após o elemento de `Microsoft.Cpp.default.props` \<Importação \/\>:  
  
```xml  
<PropertyGroup>  
    <PreferredToolArchitecture>x64</PreferredToolArchitecture>  
</PropertyGroup>  
```  
  
 No prompt de comando, digite o seguinte comando para usar as ferramentas de 64 bits para compilar seu aplicativo.  
  
 `msbuild myproject.vcxproj /p:PreferredToolArchitecture=x64`  
  
### Usando o MSBuild com um Conjunto de Ferramentas diferente  
 Se você tiver conjuntos de ferramentas e bibliotecas para outras versões do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] instalados, o [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] poderá criar aplicativos para a versão atual do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] ou para as outras versões instaladas.  Por exemplo, se você instalou o [!INCLUDE[cpp_dev11_long](../build/includes/cpp_dev11_long_md.md)] para especificar o kit de ferramentas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] 11.0 para o Windows XP, adicione o seguinte elemento do grupo de propriedade ao arquivo de projeto Myproject.vcxproj após o elemento `<Import />` de Microsoft.Cpp.props:  
  
```xml  
<PropertyGroup>  
    <PlatformToolset>v110_xp</PlatformToolset>  
</PropertyGroup>  
```  
  
 Para recriar o seu projeto com o conjunto de ferramentas 11.0 do Windows XP [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], digite qualquer um dos seguintes comandos:  
  
 `msbuild myproject.vcxproj /p:PlatformToolset=v110_xp /t:rebuild`  
  
 `msbuild myproject.vcxproj /t:rebuild`  
  
### Adicionando personalizações do MSBuild  
 [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] fornece várias maneiras para personalizar o processo de compilação.  Os tópicos a seguir mostram como adicionar etapas da compilação, ferramentas e eventos personalizados ao seu projeto do [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)]:  
  
-   [Como adicionar uma etapa de build personalizada a projetos MSBuild](../Topic/How%20to:%20Add%20a%20Custom%20Build%20Step%20to%20MSBuild%20Projects.md)  
  
-   [Como adicionar ferramentas de compilação personalizadas a projetos MSBuild](../build/how-to-add-custom-build-tools-to-msbuild-projects.md)  
  
-   [Como usar eventos de compilação em projetos de MSBuild](../build/how-to-use-build-events-in-msbuild-projects.md)