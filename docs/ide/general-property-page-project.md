---
title: "Página de propriedade geral (projeto) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs: C++
helpviewer_keywords:
- Clean Build option
- output files, setting directory
- Unicode, creating C++ build configuration
ms.assetid: 593b383c-cd0f-4dcd-ad65-9ec9b4b19c45
caps.latest.revision: "30"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9b702c1835ed1a3b280e6fe38dff91161d92c661
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="general-property-page-project"></a>Página de propriedade geral (projeto)
Quando você com o botão direito em um nó de projeto no Gerenciador de soluções e selecione **propriedades**, o **geral** página de propriedade no **propriedades de configuração** nó a painel esquerdo exibe duas seções de propriedades:  
  
-   Geral  
  
-   Padrões de projeto  
  
## <a name="general"></a>Geral  
 As propriedades na seção geral afetam o local dos arquivos que são criados no processo de compilação e quais arquivos excluir quando o **limpar** opção (**criar** menu) está selecionado.  
  
 **Plataforma de destino**  
 Especifica a plataforma que o projeto será executado. Por exemplo, Windows, Android ou iOS. O valor **Windows 10** significa que o projeto utiliza a plataforma Universal do Windows. Se você está visando a versões anteriores do Windows, a versão não estiver listada e o valor neste campo é exibido como apenas **Windows**. Este é um campo somente leitura que é definido quando você cria um projeto.  
  
 **Versão SDK do Windows**  
 Para a plataforma de destino do Windows, isso Especifica a versão do SDK do Windows que requer que seu projeto. Quando você instala uma carga de trabalho C++ usando o instalador do Visual Studio, os componentes necessários do SDK do Windows também são instalados. Se você tiver outras versões do SDK do Windows em seu computador, cada versão das ferramentas do SDK que você instalou aparece na lista suspensa.  
  
 Para direcionar o Windows 7 ou Windows Vista, use o valor **8.1**, pois o SDK do Windows 8.1 é compatível com versões anteriores para essas plataformas. Além disso, você deve definir o valor apropriado para **_WIN32_WINNT** em targetver.h. Para o Windows 7, que é 0x0601. Consulte [modificando WINVER e _WIN32_WINNT](../porting/modifying-winver-and-win32-winnt.md).  
  
 Você pode instalar o conjunto de ferramentas de plataforma Windows XP incluído no Visual Studio para usar a versão atual das bibliotecas para compilar projetos do Windows XP e Windows Server 2003. Para obter informações sobre como obter e usar esse conjunto de ferramentas da plataforma, consulte [configurando programas para o Windows XP](../build/configuring-programs-for-windows-xp.md). Para obter mais informações sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../build/how-to-modify-the-target-framework-and-platform-toolset.md).  
  
 **Min de plataforma de destino. Versão**  
 Especifica a versão mais antiga da plataforma que o projeto pode ser executada em. Essa propriedade será exibida somente se o tipo de projeto dá suporte a ele, como em projetos universais do Windows. Se seu aplicativo pode tirar proveito dos recursos em uma versão mais recente do SDK do Windows, mas ainda pode executar em versões anteriores sem esses recursos, talvez com alguma perda de funcionalidade, em seguida, o valor dessas propriedades pode ser diferente. Se assim, seu código deve verificar a versão da plataforma ele esteja em execução em tempo de execução e não tente usar os recursos que não estão disponíveis na versão mais antiga de plataforma.  
  
 Observe que o Visual C++ não impõe essa opção. Ele está incluído para manter a consistência com outras linguagens, como c# e JavaScript e como um guia para qualquer pessoa que usa seu projeto. Visual C++ não irá gerar um erro se você usar um recurso que não está disponível na versão mínima.  
  
 **Diretório de saída**  
 Especifica o diretório onde ferramentas como o vinculador colocará todos os arquivos de saída final que são criados durante o processo de compilação. Normalmente, isso inclui a saída de ferramentas como o vinculador, bibliotecário ou BSCMake. Por padrão, essa propriedade é o diretório especificado pelas macros $(SolutionDir) $(configuração) \.  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.OutputDirectory%2A>.  
  
 **Diretório intermediário**  
 Especifica o diretório onde ferramentas como o compilador colocará todos os arquivos intermediários criados durante o processo de compilação. Normalmente, isso inclui a saída das ferramentas, como o compilador do C/C++, MIDL e o compilador de recurso. Por padrão, essa propriedade é o diretório especificado por $ a macro (configuração) \.  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.IntermediateDirectory%2A>.  
  
 **Nome de destino**  
 Especifica o nome do arquivo que gera este projeto. Por padrão, essa propriedade é o nome do arquivo especificado pela macro $(ProjectName).  
  
 **Extensão de destino**  
 Especifica a extensão de nome de arquivo que gera este projeto; Por exemplo, .exe ou. dll.  
  
 **Extensões para excluir na limpeza**  
 O **limpar** opção (**criar** menu) exclui arquivos do diretório intermediário onde uma configuração de projeto é criada. Arquivos com extensões especificadas com essa propriedade será excluído quando **limpar** é executada ou quando você executa uma recriação. Além dos arquivos dessas extensões no diretório intermediário, o sistema de compilação também excluirá todas as saídas da compilação, independentemente de onde ele está localizado (incluindo saídas intermediárias, como arquivos. obj) conhecidas. Observe que você pode especificar os caracteres curinga.  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.DeleteExtensionsOnClean%2A>.  
  
 **Criar arquivo de Log**  
 Permite que você especifique um local diferente do padrão para o arquivo de log é criado sempre que você compilar um projeto. O local padrão é especificado pelo $(MSBuildProjectName) de $(IntDir) de macros. log.  
  
 Você pode usar macros do projeto para alterar o local do diretório. Consulte [comuns Macros para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md).  
  
 **Conjunto de ferramentas de plataforma**  
 Permite que o projeto para o destino de uma versão diferente do compilador e bibliotecas do Visual C++. Projetos Visual C++ podem direcionar qualquer o conjunto de ferramentas padrão instalado pelo Visual Studio, ou um dos conjuntos de ferramentas que instalado por várias versões anteriores do Visual Studio, incluindo conjuntos de ferramentas que criar executáveis que podem ser executados em Windowx XP. Para obter informações sobre como alterar o conjunto de ferramentas da plataforma, consulte [como: modificar a estrutura de destino e o conjunto de ferramentas de plataforma](../build/how-to-modify-the-target-framework-and-platform-toolset.md).  
  
**Habilitar compilação Incremental gerenciada**  
Para projetos gerenciados, isso habilita a detecção de visibilidade externa ao gerar assemblies. Se uma alteração em um projeto gerenciado não é visível para outros projetos, projetos dependentes não são recriados. Isso pode melhorar drasticamente os tempos de compilação em soluções que incluem projetos gerenciados.  
  
## <a name="project-defaults"></a>Padrões de projeto  
 As propriedades na seção de projeto padrão representam propriedades padrão que você pode modificar. A definição dessas propriedades pode ser encontrada nos arquivos .props no *diretório de instalação*\VC\VCProjectDefaults.  
  
 **Tipo de configuração**  
 Há vários tipos de configuração para escolher:  
  
-   **Aplicativo (.exe)**, exibe o conjunto de ferramentas de vinculador (compilador de C/C++, MIDL, compilador de recurso, vinculador, BSCMake, gerador de Proxy de serviço Web XML, compilação personalizada, eventos prebuild, prelink, postbuild).  
  
-   **Biblioteca dinâmica (. dll)**, exibe o conjunto de ferramentas de vinculador, especifica a opção de vinculador /DLL e adiciona o _WINDLL definem a CL.  
  
-   **Makefile**, exibe o conjunto de ferramentas de makefile (NMake).  
  
-   **Biblioteca estática (. lib)**, exibe o conjunto de ferramentas do bibliotecário (mesmo que o conjunto de ferramentas de vinculador exceto substituir bibliotecário vinculador e omitir o gerador de Proxy de serviço Web XML).  
  
-   **Utilitário**, exibe o conjunto de ferramentas do utilitário (MIDL, compilação personalizada, eventos prebuild, postbuild).  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.ConfigurationType%2A>.  
  
 **Uso de MFC**  
 Especifica se o projeto MFC estática ou dinamicamente vinculará a DLL do MFC. Projetos MFC não podem selecionar **usar bibliotecas padrão do Windows** para vincular a várias bibliotecas de Win32 que são incluídas quando você usar MFC.  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfMfc%2A>.  
  
 **Uso de ATL**  
 Especifica se o projeto ATL será estática ou dinamicamente vinculado a ATL. DLL. Se você especificar qualquer coisa diferente de **usando ATL não**, definir será adicionada para o compilador **linha de comando** página de propriedades.  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfATL%2A>.  
  
 **Conjunto de caracteres**  
 Define se Unicode ou MBCS devem ser definidas. Também afeta o ponto de entrada de vinculador quando apropriado.  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.CharacterSet%2A>.  
  
 **Suporte a Common Language Runtime**  
 Faz com que o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador a ser usado.  
  
 Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.ManagedExtensions%2A>.  
  
**Versão de destino do .NET Framework**  
Em projetos gerenciados, especifica a versão do .NET framework de destino.  
  
 **Otimização de programa parcial**  
 Especifica o [/GL](../build/reference/gl-whole-program-optimization.md) opção de compilador e [/LTCG](../build/reference/ltcg-link-time-code-generation.md) opção de vinculador. Por padrão, isso é desabilitado para configurações de depuração e habilitado para configurações de varejo.  
  
 **Suporte de aplicativo da Windows Store**  
 Especifica se este projeto dá suporte a aplicativos da Windows Store. Para obter mais informações, consulte [/ZW (compilação de tempo de execução do Windows)](../build/reference/zw-windows-runtime-compilation.md)e o Centro de desenvolvedores do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)