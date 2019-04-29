---
title: Página de propriedade geral (projeto)
ms.date: 11/04/2016
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
ms.openlocfilehash: c9b0eae9c0a1e074fb4f3f12ac38a737ef14c644
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62270883"
---
# <a name="general-property-page-project"></a>Página de propriedade geral (projeto)

Quando você clica com o botão direito do mouse em um nó de projeto no Gerenciador de Soluções e seleciona **Propriedades**, a página de propriedades **Geral** no nó **Propriedades de Configuração** do painel esquerdo exibe duas seções de propriedades:

- Geral

- Padrões de Projeto

Para projetos de não-Windows, consulte [referência de página de propriedades do Linux C++](../../linux/prop-pages-linux.md).

## <a name="general"></a>Geral

As propriedades na seção Geral afetam o local dos arquivos criados no processo de build e quais arquivos excluir quando a opção **Limpar** (menu **Build**) está selecionada.

- **Plataforma de Destino**

   Especifica a plataforma na qual o projeto será executado. Por exemplo, Windows, Android ou iOS. O valor **Windows 10** significa que o projeto é direcionado à Plataforma Universal do Windows. Caso você tenha como destino versões anteriores do Windows, a versão não será listada e o valor neste campo será exibido apenas como **Windows**. Esse é um campo somente leitura definido quando você cria um projeto.

- **Versão do SDK do Windows**

   Para a plataforma de destino do Windows, isso especifica a versão do SDK do Windows necessária para o projeto. Quando você instala uma Carga de Trabalho do C++ usando o Instalador do Visual Studio, as partes necessárias do SDK do Windows também são instaladas. Caso você tenha outras versões do SDK do Windows no computador, cada versão das SDK Tools instalada será exibida na lista suspensa.

   Para ter o Windows 7 ou o Windows Vista como destino, use o valor **8.1**, pois o SDK do Windows 8.1 é compatível com versões anteriores dessas plataformas. Além disso, você deve definir o valor apropriado como **_WIN32_WINNT** em targetver.h. Para o Windows 7, isso é 0x0601. Confira [Modificando WINVER e _WIN32_WINNT](../../porting/modifying-winver-and-win32-winnt.md).

   Instale o conjunto de ferramentas da plataforma Windows XP incluído no Visual Studio para usar a versão atual das bibliotecas para compilar projetos do Windows XP e do Windows Server 2003. Para obter informações sobre como obter e usar esse conjunto de ferramentas da plataforma, confira [Configurando programas para o Windows XP](../configuring-programs-for-windows-xp.md). Para obter informações adicionais sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como: Modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../how-to-modify-the-target-framework-and-platform-toolset.md).

- **Versão Mín. da Plataforma de Destino**

   Especifica a versão mais antiga da plataforma na qual o projeto pode ser executado. Essa propriedade é exibida somente se o tipo de projeto dá suporte a ela, como em projetos Universais do Windows. Se o aplicativo pode aproveitar as funcionalidades em uma versão mais recente do SDK do Windows, mas ainda pode ser executado em versões anteriores sem essas funcionalidades, talvez com alguma perda de funcionalidade, o valor dessas duas propriedades pode ser diferente. Nesse caso, o código deve verificar a versão da plataforma na qual ela está em execução em tempo de execução e não tentar usar as funcionalidades não disponíveis na versão mais antiga da plataforma.

   Observe que o Visual C++ não impõe essa opção. Ela é incluída para manter a consistência com outras linguagens, como C# e JavaScript, e como um guia para qualquer pessoa que usa o projeto. O Visual C++ não gerará um erro se você usar um recurso que não está disponível na versão mínima.

- **Diretório de Saída**

   Especifica o diretório no qual ferramentas como o vinculador colocarão todos os arquivos de saída finais criados durante o processo de build. Normalmente, isso inclui a saída de ferramentas como o vinculador, bibliotecário ou BSCMake. Por padrão, essa propriedade é o diretório especificado pelas macros $(SolutionDir)$(Configuration)\.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.OutputDirectory%2A>.

- **Diretório Intermediário**

   Especifica o diretório no qual ferramentas como o compilador colocarão todos os arquivos intermediários criados durante o processo de build. Normalmente, isso inclui a saída de ferramentas, como o compilador do C/C++, MIDL e o compilador de recurso. Por padrão, essa propriedade é o diretório especificado pela macro $(Configuration)\.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.IntermediateDirectory%2A>.

- **Nome de Destino**

   Especifica o nome de arquivo gerado por esse projeto. Por padrão, essa propriedade é o nome de arquivo especificado pela macro $(ProjectName).

- **Extensão de Destino**

   Especifica a extensão de nome de arquivo gerada por esse projeto; por exemplo, .exe ou .dll.

- **Extensões a Serem Excluídas na Limpeza**

   A opção **Limpar** (menu **Build**) exclui arquivos do diretório intermediário no qual uma configuração do projeto é compilada. Arquivos com extensões especificadas com essa propriedade serão excluídos quando a opção **Limpar** for executada ou quando você executar uma recompilação. Além dos arquivos dessas extensões no diretório intermediário, o sistema de build também excluirá todas as saídas de build conhecidas, independentemente de sua localização (incluindo saídas intermediárias, como arquivos .obj). Observe que você pode especificar caracteres curinga.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.DeleteExtensionsOnClean%2A>.

- **Arquivo de Log de Build**

   Permite que você especifique um local não padrão para o arquivo de log criado sempre que um projeto é compilado. A localização padrão é especificada pelas macros $(IntDir)$(MSBuildProjectName).log.

   Use as macros do projeto para alterar o local do diretório. Ver [macros comuns para compilar comandos e propriedades](common-macros-for-build-commands-and-properties.md).

- **Conjunto de Ferramentas da Plataforma**

   Permite que o projeto seja direcionado a uma versão diferente do compilador e das bibliotecas do Visual C++. Os projetos do Visual C++ podem ser direcionados ao conjunto de ferramentas padrão instalado pelo Visual Studio ou a um dos conjuntos de ferramentas instalados por várias versões anteriores do Visual Studio, incluindo conjuntos de ferramentas que criam executáveis que podem ser executados no Windows XP. Para obter informações sobre como alterar o conjunto de ferramentas de plataforma, consulte [como: Modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../how-to-modify-the-target-framework-and-platform-toolset.md).

- **Habilitar Build Incremental Gerenciado**

   Para projetos gerenciados, isso habilita a detecção de visibilidade externa quando você gera assemblies. Se uma alteração em um projeto gerenciado não está visível para outros projetos, os projetos dependentes não são recompilados. Isso pode melhorar de maneira significativa os tempos de build em soluções que incluem projetos gerenciados.

## <a name="project-defaults"></a>Padrões de Projeto

As propriedades na seção Padrão de Projeto representam as propriedades padrão que podem ser modificadas. A definição dessas propriedades pode ser encontrada nos arquivos .props no *Diretório de Instalação*\VC\VCProjectDefaults.

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

  - **Utility**

     Exibe o conjunto de ferramentas do utilitário (MIDL, build personalizado, eventos de pré-build e pós-build).

  Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.ConfigurationType%2A>.

- **Uso do MFC**

   Especifica se o projeto MFC será vinculado estática ou dinamicamente à DLL do MFC. Os projetos não MFC podem selecionar **Usar Bibliotecas Padrão do Windows** para serem vinculados a várias bibliotecas do Win32 incluídas quando você usa o MFC.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfMfc%2A>.

- **Uso da ATL**

   Especifica se o projeto ATL será vinculado estática ou dinamicamente à .DLL da ATL. Se você especificar qualquer coisa diferente de **Não Usar ATL**, a definição será adicionada à página de propriedades de **Linha de Comando** do compilador.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfATL%2A>.

- **Conjunto de Caracteres**

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

## <a name="see-also"></a>Consulte também

[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)