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
# <a name="clangllvm-support-in-visual-studio-projects"></a>Suporte a Clang/LLVM em projetos do Visual Studio

::: moniker range="<=vs-2017"

O suporte do Clang para projetos CMake e MSBuild está disponível no Visual Studio 2019.

::: moniker-end

::: moniker range="vs-2019"

Você pode usar o Visual Studio 2019 versão 16,2 com Clang para editar, compilar e depurar projetos do Visual Studio do C++ (MSBuild) destinados ao Windows ou Linux.

## <a name="install"></a>Instalar

Para obter o melhor suporte ao IDE no Visual Studio, é recomendável usar as ferramentas de compilador Clang mais recentes para Windows. Se você ainda não os tiver, poderá instalá-los abrindo a Instalador do Visual Studio e escolhendo **C++ Clang Tools for Windows** em **desenvolvimento de área de trabalho com** componentes opcionais do c++. Se preferir usar uma instalação existente do Clang em seu computador, escolha as **ferramentas de Build C++ Clang-CL para v142.** componente opcional. Atualmente, a biblioteca Microsoft C++ Standard requer pelo menos Clang 8.0.0; a versão em pacote do Clang será atualizada automaticamente para se manter atualizada com as atualizações na implementação da Microsoft da biblioteca padrão.

![Instalação do componente Clang](media/clang-install-vs2019.png)

## <a name="configure-a-windows-project-to-use-clang-tools"></a>Configurar um projeto do Windows para usar as ferramentas do Clang

Para configurar um projeto do Visual Studio para usar o Clang, clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades**. Normalmente, você deve primeiro escolher **todas as configurações** na parte superior da caixa de diálogo. Em seguida, em**conjunto de ferramentas de plataforma** **geral** > , escolha **LLVM (Clang-CL)** e, em seguida, **OK**.

![Instalação do componente Clang](media/clang-msbuild-prop-page.png)

Se você estiver usando as ferramentas do Clang que são agrupadas com o Visual Studio, nenhuma etapa adicional será necessária. Para projetos do Windows, o Visual Studio por padrão invoca Clang no modo [Clang-CL](https://llvm.org/devmtg/2014-04/PDFs/Talks/clang-cl.pdf) e links com a implementação da biblioteca padrão da Microsoft. Por padrão, o **Clang-CL. exe** está localizado `C:\Program Files (x86)\Microsoft Visual Studio\2019\Common7\IDE\CommonExtensions\Microsoft\Llvm\bin`em.

Se você estiver usando uma instalação personalizada do Clang, poderá modificar as **Project** > **Propriedades** > do projeto diretórios do**vc + +** > **Propriedades** > de configuração de diretórios do**executável** adicionando a raiz de instalação personalizada do Clang como o primeiro diretório ou alterar `LLVMInstallDir` o valor da propriedade. Consulte [definir um local LLVM personalizado](#custom_llvm_location) para obter mais informações.

## <a name="configure-a-linux-project-to-use-clang-tools"></a>Configurar um projeto do Linux para usar as ferramentas do Clang

Para projetos do Linux, o Visual Studio usa o front-end compatível com GCC Clang. As propriedades do projeto e quase todos os sinalizadores do compilador são idênticos

Para configurar um projeto do Visual Studio Linux para usar o Clang:

1. Clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades**.
1. Normalmente, você deve primeiro escolher **todas as configurações** na parte superior da caixa de diálogo.
1. Em **General** > **conjunto de ferramentas de plataforma**geral, escolha **WSL_Clang_1_0** se você estiver usando o subsistema do Windows para Linux ou **Remote_Clang_1_0** se estiver usando uma máquina ou VM remota.
1. Pressione **OK**.

![Instalação do componente Clang](media/clang-msbuild-prop-page.png)

No Linux, o Visual Studio usa, por padrão, o primeiro local Clang que encontra na propriedade de ambiente PATH. Se você estiver `LLVMInstallDir` usando uma instalação personalizada do Clang, será necessário alterar o valor da propriedade ou substituir um caminho em**Propriedades** > do **projeto** > diretórios do**vc + +** > diretórios do**executável**propriedades > de**configuração**. Consulte [definir um local LLVM personalizado](#custom_llvm_location) para obter mais informações.

## <a name="set-a-custom-llvm-location"></a><a name="custom_llvm_location"></a>Definir um local LLVM personalizado

Você pode definir um caminho personalizado para LLVM para um ou mais projetos criando um arquivo *Directory. Build. props* e adicionando esse arquivo à pasta raiz de qualquer projeto. Você pode adicioná-lo à pasta de solução raiz para aplicá-lo a todos os projetos na solução. O arquivo deve ter a seguinte aparência (mas substitua o caminho real):

```xml
<Project>
  <PropertyGroup>
    <LLVMInstallDir>c:\MyLLVMRootDir</LLVMInstallDir>
  </PropertyGroup>
</Project>
```

## <a name="set-additional-properties-edit-build-and-debug"></a>Definir propriedades, editar, compilar e depurar adicionais

Depois de configurar uma configuração do Clang, clique com o botão direito do mouse novamente no nó do projeto e escolha **recarregar projeto**. Agora você pode criar e depurar o projeto usando as ferramentas do Clang. O Visual Studio detecta que você está usando o compilador Clang e fornece IntelliSense, realce, navegação e outros recursos de edição. Erros e avisos são exibidos no **janela de saída**. As páginas de propriedades do projeto para uma configuração Clang são muito semelhantes às do MSVC, embora alguns recursos dependentes do compilador, como editar e continuar, não estejam disponíveis para as configurações de Clang. Para definir um compilador Clang ou opção de vinculador que não está disponível nas páginas de propriedades, você pode adicioná-lo manualmente nas páginas de propriedades em **Propriedades** > de configuração**C/C++ (ou vinculador)** > **Command Line** > **Opções adicionais**de linha de comando.

Ao depurar, você pode usar pontos de interrupção, memória e visualização de dados e a maioria dos outros recursos de depuração.  

![Depuração Clang](media/clang-debug-msbuild.png)

::: moniker-end
