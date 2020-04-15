---
title: Suporte a Clang/LLVM em projetos do Visual Studio CMake
ms.date: 07/01/2019
ms.description: Configure a CMake project in Visual Studio to use the Clang/LLVM toolchain.
helpviewer_keywords:
- Clang support for C++ CMake projects
ms.openlocfilehash: 46bfe788c13df3a37dd9cba654d16cfe4c3fe177
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323189"
---
# <a name="clangllvm-support-in-visual-studio-cmake-projects"></a>Suporte a Clang/LLVM em projetos do Visual Studio CMake

::: moniker range="<=vs-2017"

O suporte ao Clang está disponível no Visual Studio 2019.

::: moniker-end

::: moniker range="vs-2019"

Você pode usar o Visual Studio com Clang para editar e depurar projetos C++ CMake que visam o Windows ou linux.

**Windows**: Visual Studio 2019 versão 16.1 inclui suporte para edição, construção e depuração com Clang/LLVM em projetos CMake direcionados ao Windows.

**Linux**: Para projetos Linux CMake, nenhum suporte especial do Visual Studio é necessário. Você pode instalar o Clang usando o gerenciador de pacotes do seu distro e adicionar os comandos apropriados no arquivo CMakeLists.txt.

## <a name="install"></a>Instalar

Para obter o melhor suporte ao IDE no Visual Studio, recomendamos usar as ferramentas mais recentes do compilador Clang para Windows. Se você ainda não tiver esses, você pode instalá-los abrindo o Visual Studio Installer e escolhendo o **compilador C++ Clang para Windows** em desenvolvimento de Desktop com componentes opcionais **C++.** Ao usar uma instalação clang personalizada, verifique o **C++ Clang-cl para obter o componente de ferramentas de compilação v142.**

![Instalação de componentes de clang](media/clang-install-vs2019.png)

## <a name="create-a-new-configuration"></a>Criar uma nova configuração

Para adicionar uma nova configuração de Clang a um projeto CMake:

1. Clique com o botão direito do mouse em CMakeLists.txt no **Solution Explorer** e escolha **configurações CMake para projeto**.

1. Em **Configurações,** pressione o botão **Adicionar configuração:**

   ![Adicionar configuração](media/cmake-add-config-icon.png)

1. Escolha a configuração Clang desejada (observe que configurações clang separadas são fornecidas para Windows e Linux) e **pressione Select**:

   ![Configuração cMake Clang](media/cmake-clang-configuration.png)

1. Para fazer modificações nesta configuração, use o **CMake Settings Editor**. Para obter mais informações, consulte [Personalizar configurações de compilação cMake no Visual Studio](customize-cmake-settings.md).

## <a name="modify-an-existing-configuration-to-use-clang"></a>Modificar uma configuração existente para usar Clang

Para modificar uma configuração existente para usar Clang, siga estas etapas:

1. Clique com o botão direito do mouse em CMakeLists.txt no **Solution Explorer** e escolha **configurações CMake para projeto**.

1. Em **Geral,** selecione a seda de **configuração** de ferramentas e escolha o conjunto de ferramentas Clang desejado:

   ![Conjunto de ferramentas CMake Clang](media/cmake-clang-toolset.png)

## <a name="custom-clang-locations"></a>Localizações personalizadas de Clang

Por padrão, o Visual Studio procura clang em dois lugares:

- (Windows) A cópia internamente instalada do Clang/LLVM que vem com o instalador do Visual Studio.
- (Windows e Linux) A variável de ambiente PATH.

Você pode especificar outro local definindo as **variáveis CMAKE_C_COMPILER** e **CMAKE_CXX_COMPILER** CMake em **Configurações CMake**:

![Conjunto de ferramentas CMake Clang](media/clang-location-cmake.png)

## <a name="clang-compatibility-modes"></a>Modos de compatibilidade de clang

Para configurações do Windows, cMake por padrão invoca Clang no modo [clang-cl](https://llvm.org/devmtg/2014-04/PDFs/Talks/clang-cl.pdf) e vincula com a implementação da Biblioteca Padrão pela Microsoft. Por padrão, **clang-cl.exe** está `C:\Program Files (x86)\Microsoft Visual Studio\2019\Common7\IDE\CommonExtensions\Microsoft\Llvm\bin`localizado em .

Você pode modificar esses valores em **Configurações CMake** em **CMake variáveis e cache**. Clique **em Mostrar variáveis avançadas**. Role para baixo para encontrar **CMAKE_CXX_COMPILER**e clique no botão **Procurar** para especificar um caminho de compilador diferente.

## <a name="edit-build-and-debug"></a>Editar, construir e depurar

Depois de configurar uma configuração Clang, você pode construir e depurar o projeto. O Visual Studio detecta que você está usando o compilador Clang e fornece intelliSense, destaque, navegação e outros recursos de edição. Erros e avisos são exibidos na **janela de saída**.

Ao depurar, você pode usar pontos de interrupção, visualização de memória e dados e a maioria dos outros recursos de depuração. Alguns recursos dependentes do compilador, como Edit e Continue, não estão disponíveis para configurações de Clang.

![Depuração cmake Clang](media/clang-debug-visualize.png)

::: moniker-end
