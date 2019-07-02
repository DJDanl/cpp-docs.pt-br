---
title: Suporte de clang/LLVM em projetos do CMake do Visual Studio
ms.date: 07/01/2019
ms.description: Configure a CMake project in Visual Studio to use the Clang/LLVM toolchain.
helpviewer_keywords:
- Clang support for C++
ms.openlocfilehash: 6773d9cdb076ef305ba635306f3bc9c6575d2203
ms.sourcegitcommit: b233f05adae607f75815111006a771c432df5a9d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2019
ms.locfileid: "67517101"
---
# <a name="clangllvm-support-in-visual-studio-cmake-projects"></a>Suporte de clang/LLVM em projetos do CMake do Visual Studio

::: moniker range="<=vs-2017"

Suporte de clang está disponível no Visual Studio de 2019.

::: moniker-end

::: moniker range="vs-2019"

Você pode usar o Visual Studio com Clang para editar e depurar C++ projetos do CMake esse destino Windows ou Linux.

**Windows**: Visual Studio 2019 versão 16.1 inclui suporte para editar, compilar e depurar com Clang/LLVM em projetos do CMake visando o Windows. 

**Linux**: Para projetos do Linux CMake, não há suporte do Visual Studio especial é necessário. Você pode instalar Clang com o Gerenciador de pacotes da sua distribuição e adicione os comandos apropriados no arquivo cmakelists. txt.

## <a name="install"></a>Instalar o

Para obter melhor suporte IDE no Visual Studio, é recomendável usar as ferramentas mais recentes do compilador Clang para Windows. Se você ainda não tiver esses, você pode instalá-los abrindo o instalador do Visual Studio e escolhendo **compilador Clang para Windows** sob **desenvolvimento para Desktop com C++**  componentes opcionais.

![Instalação de componentes de clang](media/clang-install-vs2019.png)

## <a name="create-a-new-configuration"></a>Criar uma nova configuração

Para adicionar uma nova configuração de Clang a um projeto do CMake:

1. Clique duas vezes em cmakelists. txt na **Gerenciador de soluções** e escolha **configurações de CMake para o projeto**.

1. Sob **configurações**, pressione a **Adicionar configuração** botão:

   ![Adicionar configuração](media/cmake-add-config-icon.png)

1. Escolha a configuração desejada de Clang (Observe que as configurações de Clang separadas são fornecidas para Windows e Linux), em seguida, pressione **selecionar**:

   ![Configuração do CMake Clang](media/cmake-clang-configuration.png)

1. Para fazer modificações a essa configuração, use o **Editor de configurações do CMake**. Para obter mais informações, consulte [CMake personalizar compilar configurações no Visual Studio](customize-cmake-settings.md).

## <a name="modify-an-existing-configuration-to-use-clang"></a>Modificar uma configuração existente para usar Clang

Para modificar uma configuração existente para usar Clang, siga estas etapas:

1. Clique duas vezes em cmakelists. txt na **Gerenciador de soluções** e escolha **configurações de CMake para o projeto**.

1. Sob **gerais** selecionar a **conjunto de ferramentas** lista suspensa e escolha o conjunto de ferramentas de Clang desejado:

   ![Conjunto de ferramentas de CMake Clang](media/cmake-clang-toolset.png)

## <a name="custom-clang-locations"></a>Locais personalizados de Clang

Por padrão, o Visual Studio procura por Clang em dois locais:

- (Windows) A cópia do Clang/LLVM que vem com o instalador do Visual Studio internamente instalada.
- (Windows e Linux) A variável de ambiente PATH.

Você pode especificar outro local, definindo o **CMAKE_C_COMPILER** e **CMAKE_CXX_COMPILER** variáveis do CMake na **configurações de CMake**:

![Conjunto de ferramentas de CMake Clang](media/clang-location-cmake.png)

## <a name="clang-compatibility-modes"></a>Modos de compatibilidade de clang

Para configurações do Windows, o CMake por padrão invoca Clang na [clang-cl](https://llvm.org/devmtg/2014-04/PDFs/Talks/clang-cl.pdf) modo e links com a implementação da Microsoft da biblioteca padrão. Por padrão, **clang cl.exe** está localizado em `C:\Program Files (x86)\Microsoft Visual Studio\2019\Common7\IDE\CommonExtensions\Microsoft\Llvm\bin`.

 Você pode modificar esses valores no **configurações de CMake** sob **CMake variáveis e cache**. Clique em **Show advanced variáveis**. Role para baixo até encontrar **CMAKE_CXX_COMPILER**, em seguida, clique o **procurar** botão para especificar um caminho diferente do compilador.

## <a name="edit-build-and-debug"></a>Editar, compilar e depurar

Depois de definir uma configuração de Clang, você pode compilar e depurar o projeto. Visual Studio detecta que você está usando o compilador Clang e fornece o IntelliSense, realce, navegação e outros recursos de edição. Erros e avisos são exibidos na **janela de saída**.

Durante a depuração, você pode usar pontos de interrupção, memória e visualização de dados e a maioria dos outros recursos de depuração. Alguns recursos dependente de compilador, como editar e continuar não estão disponíveis para configurações de Clang.

![Clang de CMake de depuração](media/clang-debug-visualize.png)

::: moniker-end
