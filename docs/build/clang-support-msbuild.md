---
title: Suporte a Clang/LLVM em projetos do Visual Studio Visual Studio
ms.date: 08/30/2019
ms.description: Configure a Visual Studio MSBuild project to use the Clang/LLVM toolchain.
helpviewer_keywords:
- Clang support for C++ MSBuild projects
ms.openlocfilehash: 5bd90141cdc7646dce206e6b02a605b73d78de95
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078803"
---
# <a name="clangllvm-support-in-visual-studio-projects"></a>Suporte a Clang/LLVM em projetos do Visual Studio

::: moniker range="<=vs-2017"

O suporte do Clang para projetos CMake e MSBuild está disponível no Visual Studio 2019.

::: moniker-end

::: moniker range="vs-2019"

Você pode usar o Visual Studio 2019 versão 16,2 com Clang para editar, compilar e depurar C++ projetos do Visual Studio (MSBuild) que se destinam ao Windows ou Linux.

## <a name="install"></a>Instalar

Para obter o melhor suporte ao IDE no Visual Studio, é recomendável usar as ferramentas de compilador Clang mais recentes para Windows. Se você ainda não os tiver, poderá instalá-los abrindo a instalador do Visual Studio e escolhendo  **C++ Clang Tools for Windows** em **desenvolvimento de área de C++ trabalho com** componentes opcionais. Se preferir usar uma instalação existente do Clang em seu computador, escolha as  **C++ ferramentas de Build Clang-CL para v142.** componente opcional. A biblioteca C++ padrão da Microsoft atualmente requer pelo menos Clang 8.0.0; a versão em pacote do Clang será atualizada automaticamente para se manter atualizada com as atualizações na implementação da Microsoft da biblioteca padrão.

![Instalação do componente Clang](media/clang-install-vs2019.png)

## <a name="configure-a-windows-project-to-use-clang-tools"></a>Configurar um projeto do Windows para usar as ferramentas do Clang

Para configurar um projeto do Visual Studio para usar o Clang, clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades**. Normalmente, você deve primeiro escolher **todas as configurações** na parte superior da caixa de diálogo. Em seguida, em **geral** > **conjunto de ferramentas de plataforma**, escolha **LLVM (Clang-CL)** e, em seguida, **OK**.

![Instalação do componente Clang](media/clang-msbuild-prop-page.png)

Se você estiver usando as ferramentas do Clang que são agrupadas com o Visual Studio, nenhuma etapa adicional será necessária. Para projetos do Windows, o Visual Studio por padrão invoca Clang no modo [Clang-CL](https://llvm.org/devmtg/2014-04/PDFs/Talks/clang-cl.pdf) e links com a implementação da biblioteca padrão da Microsoft. Por padrão, o **Clang-CL. exe** está localizado em `C:\Program Files (x86)\Microsoft Visual Studio\2019\Common7\IDE\CommonExtensions\Microsoft\Llvm\bin`.

Se você estiver usando uma instalação personalizada do Clang, poderá modificar **as propriedades** de > do **projeto** > **diretórios do vc + +**  > **Propriedades de configuração** > **diretórios executáveis** adicionando a raiz de instalação personalizada do Clang como o primeiro diretório ou altere o valor da propriedade `LLVMInstallDir`. Consulte [definir um local LLVM personalizado](#custom_llvm_location) para obter mais informações.

## <a name="configure-a-linux-project-to-use-clang-tools"></a>Configurar um projeto do Linux para usar as ferramentas do Clang

Para projetos do Linux, o Visual Studio usa o front-end compatível com GCC Clang. As propriedades do projeto e quase todos os sinalizadores do compilador são idênticos

Para configurar um projeto do Visual Studio Linux para usar o Clang:

1. Clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades**.
1. Normalmente, você deve primeiro escolher **todas as configurações** na parte superior da caixa de diálogo.
1. Em **geral** > **conjunto de ferramentas de plataforma**, escolha **WSL_Clang_1_0** se você estiver usando o subsistema do Windows para Linux ou **Remote_Clang_1_0** se estiver usando um computador remoto ou VM.
1. Pressione **OK**.

![Instalação do componente Clang](media/clang-msbuild-prop-page.png)

No Linux, o Visual Studio usa, por padrão, o primeiro local Clang que encontra na propriedade de ambiente PATH. Se você estiver usando uma instalação personalizada do Clang, deverá alterar o valor da propriedade `LLVMInstallDir` ou, caso contrário, substituir um caminho em **Propriedades** do **projeto** >  > **vc + + diretórios** > **Propriedades de configuração** > **diretórios executáveis**. Consulte [definir um local LLVM personalizado](#custom_llvm_location) para obter mais informações.

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

Depois de configurar uma configuração do Clang, clique com o botão direito do mouse novamente no nó do projeto e escolha **recarregar projeto**. Agora você pode criar e depurar o projeto usando as ferramentas do Clang. O Visual Studio detecta que você está usando o compilador Clang e fornece IntelliSense, realce, navegação e outros recursos de edição. Erros e avisos são exibidos no **janela de saída**. As páginas de propriedades do projeto para uma configuração Clang são muito semelhantes às do MSVC, embora alguns recursos dependentes do compilador, como editar e continuar, não estejam disponíveis para as configurações de Clang. Para definir um compilador Clang ou opção de vinculador que não está disponível nas páginas de propriedades, você pode adicioná-lo manualmente nas páginas de propriedades em **Propriedades de configuração** > **CC++ /(ou vinculador)**  > linha de **comando** > **Opções adicionais**.

Ao depurar, você pode usar pontos de interrupção, memória e visualização de dados e a maioria dos outros recursos de depuração.  

![Depuração Clang](media/clang-debug-msbuild.png)

::: moniker-end
