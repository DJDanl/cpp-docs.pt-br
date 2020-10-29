---
title: Página de propriedade geral (projeto)
ms.date: 07/17/2019
f1_keywords:
- VC.Project.VCConfiguration.IntermediateDirectory
- VC.Project.VCConfiguration.ConfigurationType
- VC.Project.VCConfiguration.ManagedExtensions
- VC.Project.VCConfiguration.BuildBrowserInformation
- VC.Project.VCConfiguration.BuildLogFile
- VC.Project.VCConfiguration.PlatformToolset
- VC.Project.VCConfiguration.TargetName
- VC.Project.VCConfiguration.
- VC.Project.VCConfiguration.TargetExt
- VC.Project.VCConfiguration.ATLMinimizesCRunTimeLibraryUsage
- VC.Project.VCConfiguration.ReferencesPath
- VC.Project.VCConfiguration.DeleteExtensionsOnClean
- VC.Project.VCConfiguration.useOfMfc
- VC.Project.VCConfiguration.CharacterSet
- VC.Project.VCGeneralMakefileSettings.ConfigurationType
- VC.Project.VCConfiguration.OutputDirectory
- VC.Project.VCConfiguration.AppSupport
- VC.Project.VCConfiguration.ToolFiles
- VC.Project.VCConfiguration.useOfATL
helpviewer_keywords:
- Clean Build option
- output files, setting directory
- Unicode, creating C++ build configuration
ms.openlocfilehash: eaaa2c7428809c05532642b0f9ac53146c6f01a9
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924289"
---
# <a name="general-property-page-project"></a>Página de propriedade geral (projeto)

::: moniker range=">=msvc-160"

Este tópico aplica-se aos projetos do Visual Studio para Windows. Para projetos do Linux, consulte [referência de página de propriedades do Linux C++](../../linux/prop-pages-linux.md). Para projetos do CMake, consulte [projetos do cmake no Visual Studio](../cmake-projects-in-visual-studio.md). Para projetos do Android, consulte [Propriedades gerais do projeto (Android C++)](../../cross-platform/general-android-prop-page.md). Para projetos do makefile do Android, consulte [Propriedades gerais do projeto (Android C++ makefile)](../../cross-platform/general-makefile-android-prop-page.md)

Quando você clica com o botão direito do mouse em um nó do projeto em Gerenciador de Soluções e seleciona **Propriedades** , a página de propriedades **geral** no nó **Propriedades de configuração** no painel esquerdo exibe estas propriedades:

- **Diretório de saída**

   Especifica o diretório no qual ferramentas como o vinculador colocarão todos os arquivos de saída finais criados durante o processo de build. Normalmente, isso inclui a saída de ferramentas como o vinculador, bibliotecário ou BSCMake. Por padrão, essa propriedade é o diretório especificado pelas macros $(SolutionDir)$(Configuration)\.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.OutputDirectory%2A>.

- **Diretório intermediário**

   Especifica o diretório no qual ferramentas como o compilador colocarão todos os arquivos intermediários criados durante o processo de build. Normalmente, isso inclui a saída de ferramentas, como o compilador do C/C++, MIDL e o compilador de recurso. Por padrão, essa propriedade é o diretório especificado pela macro $(Configuration)\.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.IntermediateDirectory%2A>.

- **Nome de destino**

   Especifica o nome de arquivo gerado por esse projeto. Por padrão, essa propriedade é o nome de arquivo especificado pela macro $(ProjectName).

- **Tipo de Configuração**

  Há vários tipos de configuração para escolher:

  - **Aplicativo (.exe)**

     Exibe o conjunto de ferramentas do vinculador (Compilador C/C++, MIDL, Compilador de Recurso, Vinculador, BSCMake, Gerador de Proxy de Serviço Web XML, build personalizado, eventos de pré-build, pré-vínculo e pós-build).

  - **Biblioteca Dinâmica (.dll)**

     Exibe o conjunto de ferramentas do vinculador, especifica a opção /DLL do vinculador e adiciona a definição de _WINDLL a CL.

  - **Makefile**

     Exibe o conjunto de ferramentas de makefile (NMake).

  - **Biblioteca estática (.lib)**

     Exibe o conjunto de ferramentas do bibliotecário (o mesmo que o conjunto de ferramentas do vinculador, exceto pela substituição do bibliotecário pelo vinculador e omissão do Gerador de Proxy de Serviço Web XML).

  - **Utilitário**

     Exibe o conjunto de ferramentas do utilitário (MIDL, build personalizado, eventos de pré-build e pós-build).

  Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.ConfigurationType%2A>.

- **Versão do SDK do Windows**

   Para a plataforma de destino do Windows, isso especifica a versão do SDK do Windows necessária para o projeto. Quando você instala uma Carga de Trabalho do C++ usando o Instalador do Visual Studio, as partes necessárias do SDK do Windows também são instaladas. Caso você tenha outras versões do SDK do Windows no computador, cada versão das SDK Tools instalada será exibida na lista suspensa.

   Para ter o Windows 7 ou o Windows Vista como destino, use o valor **8.1** , pois o SDK do Windows 8.1 é compatível com versões anteriores dessas plataformas. Além disso, você deve definir o valor apropriado como **_WIN32_WINNT** em targetver.h. Para o Windows 7, isso é 0x0601. Confira [Modificando WINVER e _WIN32_WINNT](../../porting/modifying-winver-and-win32-winnt.md).

   Instale o conjunto de ferramentas da plataforma Windows XP incluído no Visual Studio para usar a versão atual das bibliotecas para compilar projetos do Windows XP e do Windows Server 2003. Para obter informações sobre como obter e usar esse conjunto de ferramentas da plataforma, confira [Configurando programas para o Windows XP](../configuring-programs-for-windows-xp.md). Para obter mais informações sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../how-to-modify-the-target-framework-and-platform-toolset.md).

- **Conjunto de ferramentas da plataforma**

   Permite que o projeto seja direcionado a uma versão diferente do compilador e das bibliotecas do Visual C++. Os projetos do Visual Studio C++ podem ter como destino o conjunto de ferramentas padrão instalado pelo Visual Studio, ou um dos conjuntos de ferramentas instalados por várias versões anteriores do Visual Studio, incluindo conjuntos de ferramentas que criam executáveis que podem ser executados no Windows XP. Para obter informações sobre como alterar o conjunto de ferramentas da plataforma, confira [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../how-to-modify-the-target-framework-and-platform-toolset.md).

- **Padrão de linguagem C++**

   Especifica qual idioma padrão usar. O padrão é/std: c++ 14. Especifique/std: c++ 17 para usar os recursos do C++ 17 ou/std: c++ + mais recente para usar C++ 20 ou outros recursos experimentais. Para obter mais informações, consulte [/STD (especificar versão padrão do idioma)](std-specify-language-standard-version.md)

::: moniker-end

::: moniker range="<=msvc-150"

No Visual Studio 2015 e no Visual Studio 2017, quando você clica com o botão direito do mouse em um nó do projeto em **Gerenciador de soluções** e seleciona **Propriedades** , a página de propriedades **geral** no nó **Propriedades de configuração** no painel esquerdo exibe duas seções de propriedades:

- Geral

- Padrões de Projeto

## <a name="general"></a>Geral

- **Plataforma de Destino**

   Especifica a plataforma na qual o projeto será executado. Por exemplo, Windows, Android ou iOS. O valor **Windows 10** significa que o projeto é direcionado à Plataforma Universal do Windows. Caso você tenha como destino versões anteriores do Windows, a versão não será listada e o valor neste campo será exibido apenas como **Windows** . Esse é um campo somente leitura definido quando você cria um projeto.

- **Versão da plataforma de destino (Visual Studio 2015)**

   Especifica a versão mais antiga da plataforma na qual o projeto pode ser executado. Essa propriedade será exibida somente se o tipo de projeto oferecer suporte a ela. Se o aplicativo pode aproveitar as funcionalidades em uma versão mais recente do SDK do Windows, mas ainda pode ser executado em versões anteriores sem essas funcionalidades, talvez com alguma perda de funcionalidade, o valor dessas duas propriedades pode ser diferente. Nesse caso, o código deve verificar a versão da plataforma na qual ela está em execução em runtime e não tentar usar as funcionalidades não disponíveis na versão mais antiga da plataforma.

   O sistema de projeto C++ não impõe essa opção. Ela é incluída para manter a consistência com outras linguagens, como C# e JavaScript, e como um guia para qualquer pessoa que usa o projeto. O Visual C++ não gerará um erro se você usar um recurso que não está disponível na versão mínima.

- **Versão SDK do Windows (Visual Studio 2017)**

   Para a plataforma de destino do Windows, isso especifica a versão do SDK do Windows necessária para o projeto. Quando você instala uma Carga de Trabalho do C++ usando o Instalador do Visual Studio, as partes necessárias do SDK do Windows também são instaladas. Caso você tenha outras versões do SDK do Windows no computador, cada versão das SDK Tools instalada será exibida na lista suspensa.

   Para ter o Windows 7 ou o Windows Vista como destino, use o valor **8.1** , pois o SDK do Windows 8.1 é compatível com versões anteriores dessas plataformas. Além disso, você deve definir o valor apropriado como **_WIN32_WINNT** em targetver.h. Para o Windows 7, isso é 0x0601. Confira [Modificando WINVER e _WIN32_WINNT](../../porting/modifying-winver-and-win32-winnt.md).

   Instale o conjunto de ferramentas da plataforma Windows XP incluído no Visual Studio para usar a versão atual das bibliotecas para compilar projetos do Windows XP e do Windows Server 2003. Para obter informações sobre como obter e usar esse conjunto de ferramentas da plataforma, confira [Configurando programas para o Windows XP](../configuring-programs-for-windows-xp.md). Para obter mais informações sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../how-to-modify-the-target-framework-and-platform-toolset.md).

- **Diretório de saída**

   Especifica o diretório no qual ferramentas como o vinculador colocarão todos os arquivos de saída finais criados durante o processo de build. Normalmente, isso inclui a saída de ferramentas como o vinculador, bibliotecário ou BSCMake. Por padrão, essa propriedade é o diretório especificado pelas macros $(SolutionDir)$(Configuration)\.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.OutputDirectory%2A>.

- **Diretório intermediário**

   Especifica o diretório no qual ferramentas como o compilador colocarão todos os arquivos intermediários criados durante o processo de build. Normalmente, isso inclui a saída de ferramentas, como o compilador do C/C++, MIDL e o compilador de recurso. Por padrão, essa propriedade é o diretório especificado pela macro $(Configuration)\.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.IntermediateDirectory%2A>.

- **Nome de destino**

   Especifica o nome de arquivo gerado por esse projeto. Por padrão, essa propriedade é o nome de arquivo especificado pela macro $(ProjectName).

- **Extensão de destino**

   Especifica a extensão de nome de arquivo gerada por esse projeto; por exemplo, .exe ou .dll.

- **Extensões a serem excluídas na limpeza**

   A opção **Limpar** (menu **Build** ) exclui arquivos do diretório intermediário no qual uma configuração do projeto é compilada. Arquivos com extensões especificadas com essa propriedade serão excluídos quando a opção **Limpar** for executada ou quando você executar uma recompilação. Além dos arquivos dessas extensões no diretório intermediário, o sistema de build também excluirá todas as saídas de build conhecidas, independentemente de sua localização (incluindo saídas intermediárias, como arquivos .obj). Observe que você pode especificar caracteres curinga.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.DeleteExtensionsOnClean%2A>.

- **Arquivo de log de build**

   Permite que você especifique um local não padrão para o arquivo de log criado sempre que um projeto é compilado. A localização padrão é especificada pelas macros $(IntDir)$(MSBuildProjectName).log.

   Use as macros do projeto para alterar o local do diretório. Consulte [macros comuns para comandos e propriedades de compilação](common-macros-for-build-commands-and-properties.md).

- **Conjunto de ferramentas da plataforma**

   Permite que o projeto seja direcionado a uma versão diferente do compilador e das bibliotecas do Visual C++. Os projetos do Visual Studio C++ podem ter como destino o conjunto de ferramentas padrão instalado pelo Visual Studio, ou um dos conjuntos de ferramentas instalados por várias versões anteriores do Visual Studio, incluindo conjuntos de ferramentas que criam executáveis que podem ser executados no Windows XP. Para obter informações sobre como alterar o conjunto de ferramentas da plataforma, confira [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../how-to-modify-the-target-framework-and-platform-toolset.md).

- **Habilitar Build Incremental Gerenciado**

   Para projetos gerenciados, isso habilita a detecção de visibilidade externa quando você gera assemblies. Se uma alteração em um projeto gerenciado não está visível para outros projetos, os projetos dependentes não são recompilados. Isso pode melhorar de maneira significativa os tempos de build em soluções que incluem projetos gerenciados.

## <a name="project-defaults"></a>Padrões de Projeto

As propriedades na seção Padrão de Projeto representam as propriedades padrão que podem ser modificadas. A definição dessas propriedades pode ser encontrada nos arquivos .props no *Diretório de Instalação* \VC\VCProjectDefaults.

- **Tipo de Configuração**

  Há vários tipos de configuração para escolher:

  - **Aplicativo (.exe)**

     Exibe o conjunto de ferramentas do vinculador (Compilador C/C++, MIDL, Compilador de Recurso, Vinculador, BSCMake, Gerador de Proxy de Serviço Web XML, build personalizado, eventos de pré-build, pré-vínculo e pós-build).

  - **Biblioteca Dinâmica (.dll)**

     Exibe o conjunto de ferramentas do vinculador, especifica a opção /DLL do vinculador e adiciona a definição de _WINDLL a CL.

  - **Makefile**

     Exibe o conjunto de ferramentas de makefile (NMake).

  - **Biblioteca estática (.lib)**

     Exibe o conjunto de ferramentas do bibliotecário (o mesmo que o conjunto de ferramentas do vinculador, exceto pela substituição do bibliotecário pelo vinculador e omissão do Gerador de Proxy de Serviço Web XML).

  - **Utilitário**

     Exibe o conjunto de ferramentas do utilitário (MIDL, build personalizado, eventos de pré-build e pós-build).

  Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.ConfigurationType%2A>.

- **Uso do MFC**

   Especifica se o projeto MFC será vinculado estática ou dinamicamente à DLL do MFC. Os projetos não MFC podem selecionar **Usar Bibliotecas Padrão do Windows** para serem vinculados a várias bibliotecas do Win32 incluídas quando você usa o MFC.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfMfc%2A>.

- **Conjunto de caracteres**

   Define se _UNICODE ou _MBCS deve ser definido. Também afeta o ponto de entrada do vinculador, quando apropriado.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.CharacterSet%2A>.

- **Suporte a Common Language Runtime**

   Faz com que a opção do compilador [/clr](clr-common-language-runtime-compilation.md) seja usada.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.ManagedExtensions%2A>.

- **Versão da Estrutura de Destino .NET**

   Em projetos gerenciados, especifica a versão do .NET Framework de destino.

- **Otimização do Programa Inteiro**

   Especifica a opção do compilador [/GL](gl-whole-program-optimization.md) e a opção [/LTCG](ltcg-link-time-code-generation.md) do vinculador. Por padrão, isso está desabilitado para configurações de Depuração e habilitado para configurações de Varejo.

- **Suporte a Aplicativos da Windows Store**

   Especifica se esse projeto dá suporte a aplicativos da Plataforma Universal do Windows (Windows Runtime). Para obter mais informações, confira [/ZW (Compilação do Windows Runtime)](zw-windows-runtime-compilation.md) e o Centro de Desenvolvedores do Windows.

::: moniker-end

## <a name="see-also"></a>Veja também

[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)
