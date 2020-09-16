---
title: Suporte a Clang/LLVM em projetos do Visual Studio CMake
ms.date: 07/01/2019
ms.description: Configure a CMake project in Visual Studio to use the Clang/LLVM toolchain.
helpviewer_keywords:
- Clang support for C++ CMake projects
ms.openlocfilehash: a23526cf5216e4cc37c3131a0d1ba94a6e923f56
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686425"
---
# <a name="clangllvm-support-in-visual-studio-cmake-projects"></a>Suporte a Clang/LLVM em projetos do Visual Studio CMake

::: moniker range="<=vs-2017"

O suporte a Clang está disponível no Visual Studio 2019.

::: moniker-end

::: moniker range="vs-2019"

Você pode usar o Visual Studio com Clang para editar e depurar projetos de CMake do C++ destinados ao Windows ou Linux.

**Windows**: o Visual Studio 2019 versão 16,1 inclui suporte para edição, criação e depuração com CLANG/LLVM em projetos CMake destinados ao Windows.

**Linux**: para projetos CMake do Linux, nenhum suporte especial ao Visual Studio é necessário. Você pode instalar o Clang usando o Gerenciador de pacotes do distribuição e adicionar os comandos apropriados no arquivo de CMakeLists.txt.

## <a name="install"></a>Instalar

Para obter o melhor suporte ao IDE no Visual Studio, é recomendável usar as ferramentas de compilador Clang mais recentes para Windows. Se você ainda não os tiver, poderá instalá-los abrindo a Instalador do Visual Studio e escolhendo **compilador C++ Clang para Windows** em **desenvolvimento de área de trabalho com** componentes opcionais do c++. Ao usar uma instalação personalizada do Clang, verifique o componente de **ferramentas de Build do C++ Clang-CL para v142** .

![Instalação do componente Clang](media/clang-install-vs2019.png)

## <a name="create-a-new-configuration"></a>Criar uma nova configuração

Para adicionar uma nova configuração de Clang a um projeto CMake:

1. Clique com o botão direito do mouse em CMakeLists.txt em **Gerenciador de soluções** e escolha **configurações de CMake para o projeto**.

1. Em **configurações**, pressione o botão **Adicionar configuração** :

   ![Adicionar configuração](media/cmake-add-config-icon.png)

1. Escolha a configuração Clang desejada (Observe que as configurações separadas do Clang são fornecidas para Windows e Linux) e pressione **selecionar**:

   ![Configuração do CMake Clang](media/cmake-clang-configuration.png)

1. Para fazer modificações nessa configuração, use o **Editor de configurações do cmake**. Para obter mais informações, consulte [Personalizar as configurações de compilação do cmake no Visual Studio](customize-cmake-settings.md).

## <a name="modify-an-existing-configuration-to-use-clang"></a>Modificar uma configuração existente para usar o Clang

Para modificar uma configuração existente para usar o Clang, siga estas etapas:

1. Clique com o botão direito do mouse em CMakeLists.txt em **Gerenciador de soluções** e escolha **configurações de CMake para o projeto**.

1. Em **geral** , selecione o menu suspenso **conjunto de ferramentas** e escolha o conjunto de ferramentas Clang desejado:

   ![Captura de tela da caixa de diálogo geral mostrando que o conjunto de ferramentas está selecionado e Clang CL x 86 está realçado.](media/cmake-clang-toolset.png)

## <a name="custom-clang-locations"></a>Locais de Clang personalizados

Por padrão, o Visual Studio procura Clang em dois locais:

- Windows A cópia do Clang/LLVM instalada internamente que vem com o instalador do Visual Studio.
- (Windows e Linux) A variável de ambiente PATH.

Você pode especificar outro local definindo as variáveis **CMAKE_C_COMPILER** e **CMAKE_CXX_COMPILER** CMAKE nas **configurações do CMAKE**:

![Captura de tela da caixa de diálogo C Make Settings com o compilador c X X realçado.](media/clang-location-cmake.png)

## <a name="clang-compatibility-modes"></a>Modos de compatibilidade do Clang

Para configurações do Windows, o CMake, por padrão, invoca Clang no modo [Clang-CL](https://llvm.org/devmtg/2014-04/PDFs/Talks/clang-cl.pdf) e links com a implementação da biblioteca padrão da Microsoft. Por padrão, o **clang-cl.exe** está localizado em `C:\Program Files (x86)\Microsoft Visual Studio\2019\Common7\IDE\CommonExtensions\Microsoft\Llvm\bin` .

Você pode modificar esses valores em **configurações de CMake** em **cache Variables and CMake**. Clique em **Mostrar variáveis avançadas**. Role para baixo até localizar **CMAKE_CXX_COMPILER**e, em seguida, clique no botão **procurar**  para especificar um caminho de compilador diferente.

## <a name="edit-build-and-debug"></a>Editar, compilar e depurar

Depois de configurar uma configuração do Clang, você pode criar e depurar o projeto. O Visual Studio detecta que você está usando o compilador Clang e fornece IntelliSense, realce, navegação e outros recursos de edição. Erros e avisos são exibidos no **janela de saída**.

Ao depurar, você pode usar pontos de interrupção, memória e visualização de dados e a maioria dos outros recursos de depuração. Alguns recursos dependentes do compilador, como editar e continuar, não estão disponíveis para configurações do Clang.

![Depuração CMake Clang](media/clang-debug-visualize.png)

::: moniker-end
