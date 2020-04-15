---
title: Suporte a Clang/LLVM em projetos do Visual Studio Visual Studio
ms.date: 08/30/2019
ms.description: Configure a Visual Studio MSBuild project to use the Clang/LLVM toolchain.
helpviewer_keywords:
- Clang support for C++ MSBuild projects
ms.openlocfilehash: 8d7d7fec979d3e7b8f665e56094ee1c309e3b686
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323115"
---
# <a name="clangllvm-support-in-visual-studio-projects"></a>Suporte ao Clang/LLVM em projetos do Visual Studio

::: moniker range="<=vs-2017"

O suporte ao Clang para projetos CMake e MSBuild está disponível no Visual Studio 2019.

::: moniker-end

::: moniker range="vs-2019"

Você pode usar o Visual Studio 2019 versão 16.2 com Clang para editar, construir e depurar projetos C++ Visual Studio (MSBuild) que visam o Windows ou o Linux.

## <a name="install"></a>Instalar

Para obter o melhor suporte ao IDE no Visual Studio, recomendamos usar as ferramentas mais recentes do compilador Clang para Windows. Se você ainda não tiver esses, você pode instalá-los abrindo o Visual Studio Installer e escolhendo **ferramentas C++ Clang para Windows** em desenvolvimento de Desktop com componentes opcionais **C++.** Se você preferir usar uma instalação Clang existente em sua máquina, escolha o **C++ Clang-cl para ferramentas de compilação v142.** componente opcional. A Biblioteca Padrão Microsoft C++ atualmente requer pelo menos Clang 8.0.0; a versão empacotada do Clang será atualizada automaticamente para se manter atualizada com as atualizações na implementação da Biblioteca Padrão pela Microsoft.

![Instalação de componentes de clang](media/clang-install-vs2019.png)

## <a name="configure-a-windows-project-to-use-clang-tools"></a>Configure um projeto do Windows para usar ferramentas Clang

Para configurar um projeto do Visual Studio para usar o Clang, clique com o botão direito do mouse no nó do projeto no **Solution Explorer** e escolha **Propriedades**. Normalmente, você deve primeiro escolher **Todas as configurações** na parte superior da caixa de diálogo. Em seguida, em **General** > **Platform Toolset,** escolha **LLVM (clang-cl)** e, em seguida, **OK**.

![Instalação de componentes de clang](media/clang-msbuild-prop-page.png)

Se você estiver usando as ferramentas Clang que são empacotadas com o Visual Studio, não são necessárias etapas adicionais. Para projetos do Windows, o Visual Studio por padrão invoca Clang no modo [clang-cl](https://llvm.org/devmtg/2014-04/PDFs/Talks/clang-cl.pdf) e vincula-se à implementação da Biblioteca Padrão pela Microsoft. Por padrão, **clang-cl.exe** está `C:\Program Files (x86)\Microsoft Visual Studio\2019\Common7\IDE\CommonExtensions\Microsoft\Llvm\bin`localizado em .

Se você estiver usando uma instalação clang personalizada, você pode modificar**propriedades** >  **do projeto** > **VC++ DIrectories** > **Configuration Properties** > **Executable Directories** adicionando a raiz de instalação clang personalizada como o primeiro diretório lá, ou alterar o `LLVMInstallDir` valor da propriedade. Consulte [Definir um local LLVM personalizado](#custom_llvm_location) para obter mais informações.

## <a name="configure-a-linux-project-to-use-clang-tools"></a>Configure um projeto Linux para usar ferramentas Clang

Para projetos Linux, o Visual Studio usa o frontend compatível com Clang GCC. As propriedades do projeto e quase todas as bandeiras do compilador são idênticas

Para configurar um projeto do Visual Studio Linux para usar o Clang:

1. Clique com o botão direito do mouse no nó do projeto no **Solution Explorer** e escolha **Propriedades**.
1. Normalmente, você deve primeiro escolher **Todas as configurações** na parte superior da caixa de diálogo.
1. Em **General** > **Platform Toolset**, escolha **WSL_Clang_1_0** se você está usando o Windows Subsystem para Linux ou **Remote_Clang_1_0** se você estiver usando uma máquina remota ou VM.
1. Pressione **OK**.

![Instalação de componentes de clang](media/clang-msbuild-prop-page.png)

No Linux, o Visual Studio por padrão usa o primeiro local de Clang que ele encontra na propriedade do ambiente PATH. Se você estiver usando uma instalação clang personalizada, `LLVMInstallDir` então você deve alterar o valor da propriedade ou então substituir um caminho em **Project** > **Properties** > **VC++ DIrectories** > **Configuration Properties** > **Executable Directories**. Consulte [Definir um local LLVM personalizado](#custom_llvm_location) para obter mais informações.

## <a name="set-a-custom-llvm-location"></a><a name="custom_llvm_location"></a>Defina um local LLVM personalizado

Você pode definir um caminho personalizado para LLVM para um ou mais projetos criando um arquivo *Directory.build.props* e adicionando esse arquivo à pasta raiz de qualquer projeto. Você pode adicioná-lo à pasta de solução raiz para aplicá-lo a todos os projetos da solução. O arquivo deve ficar assim (mas substitua seu caminho real):

```xml
<Project>
  <PropertyGroup>
    <LLVMInstallDir>c:\MyLLVMRootDir</LLVMInstallDir>
  </PropertyGroup>
</Project>
```

## <a name="set-additional-properties-edit-build-and-debug"></a>Defina propriedades adicionais, edite, construa e depura

Depois de configurar uma configuração de Clang, clique com o botão direito do mouse novamente no nó do projeto e escolha **Recarregar projeto**. Agora você pode construir e depurar o projeto usando as ferramentas Clang. O Visual Studio detecta que você está usando o compilador Clang e fornece intelliSense, destaque, navegação e outros recursos de edição. Erros e avisos são exibidos na **janela de saída**. As páginas de propriedade do projeto para uma configuração de Clang são muito semelhantes às do MSVC, embora alguns recursos dependentes do compilador, como Edit e Continue, não estejam disponíveis para configurações de Clang. Para definir uma opção de compilador clang ou linker que não está disponível nas páginas da propriedade, você pode adicioná-lo manualmente nas páginas de propriedade em **Propriedades de** > configuração**C/C++ (ou Linker)** > **Opções adicionais****da linha** > de comando .

Ao depurar, você pode usar pontos de interrupção, visualização de memória e dados e a maioria dos outros recursos de depuração.  

![Depuração de Clang](media/clang-debug-msbuild.png)

::: moniker-end
