---
title: Usando Clang-Tidy no Visual Studio
description: Como usar o Clang-Tidy no Visual Studio para análise de código Microsoft C++.
ms.date: 02/19/2020
ms.topic: conceptual
f1_keywords:
- vs.codeanalysis.clangtidy
author: frozenpandaman
ms.author: efessler
ms.openlocfilehash: ff32f522eaacee67e19aedaa1153b2c68edc98d4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355159"
---
# <a name="using-clang-tidy-in-visual-studio"></a>Usando Clang-Tidy no Visual Studio

::: moniker range="<=vs-2017"

O suporte para Clang-Tidy requer visual studio versão 16.4 ou posterior. Para ver a documentação desta versão, defina o controle do seletor Visual Studio **Version** para este artigo para o Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end

::: moniker range=">=vs-2019"

A Análise de Código suporta nativamente [o Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/) para projetos MSBuild e CMake, seja usando conjuntos de ferramentas Clang ou MSVC. As verificações de Clang-Tidy podem ser executadas como parte da análise do código de fundo. Eles aparecem como avisos no editor (squiggles) e exibidos na Lista de erros.

O suporte ao Clang-Tidy está disponível a partir da versão 16.4 do Visual Studio 2019. Ele é incluído automaticamente quando você escolhe uma carga de trabalho C++ no Visual Studio Installer.

Clang-Tidy é a ferramenta de análise padrão ao usar o conjunto de ferramentas LLVM/clang-cl, disponível tanto no MSBuild quanto no CMake. Você pode configurá-lo ao usar um conjunto de ferramentas MSVC para executar ao lado ou substituir a experiência padrão de análise de código. Se você usar o conjunto de ferramentas clang-cl, o Microsoft Code Analysis não está disponível.

Clang-Tidy é executado após compilação bem sucedida. Talvez seja necessário resolver erros de código-fonte para obter resultados do Clang-Tidy.

## <a name="msbuild"></a>MSBuild

Você pode configurar o Clang-Tidy para ser executado como parte da Análise de Código e construir sob a página Geral **de Análise** > **de** Código na janela Propriedades do projeto. As opções para configurar a ferramenta podem ser encontradas no submenu Clang-Tidy.

Para obter mais informações, consulte [Como definir propriedades de análise de código para projetos C/C++.](../code-quality/how-to-set-code-analysis-properties-for-c-cpp-projects.md)

## <a name="cmake"></a>CMake

Em projetos CMake, você pode configurar verificações Clang-Tidy dentro `CMakeSettings.json`. Uma vez aberto, clique em "Editar JSON" no canto superior direito do Editor de Configurações do Projeto CMake. As seguintes chaves são reconhecidas:

- `enableMicrosoftCodeAnalysis`: Permite a análise de código da Microsoft
- `enableClangTidyCodeAnalysis`: Permite a análise clang-tidy
- `clangTidyChecks`: Configuração clang-tidy, especificada como uma lista separada por comma, ou seja, verifica-se a ser ativada ou desativada

Se nenhuma das opções "habilitar" for especificada, o Visual Studio selecionará a ferramenta de análise correspondente ao conjunto de ferramentas da plataforma usada.

## <a name="warning-display"></a>Exibição de aviso

As corridas do Clang-Tidy resultam em avisos exibidos na Lista de Erros e, à medida que o editor se arrasta por baixo de seções relevantes de código. Use a coluna "Categoria" na Lista de erros para classificar e organizar avisos Clang-Tidy. Você pode configurar avisos no editor alternando a configuração "Desativar squiggles de análise de código" em **Opções de** > **Ferramentas**.

## <a name="clang-tidy-configuration"></a>Configuração clang-tidy

Você pode configurar as verificações que o clang-tidy executa dentro do Visual Studio através da opção **Clang-Tidy Checks.** Esta entrada é fornecida para o **argumento --verifica** da ferramenta. Qualquer configuração adicional pode *`.clang-tidy`* ser incluída em arquivos personalizados. Para obter mais informações, consulte a [documentação do Clang-Tidy sobre LLVM.org](https://clang.llvm.org/extra/clang-tidy/).

## <a name="see-also"></a>Confira também

- [Suporte clang/LLVM para projetos MSBuild](https://devblogs.microsoft.com/cppblog/clang-llvm-support-for-msbuild-projects/)
- [Suporte clang/LLVM para projetos CMake](https://devblogs.microsoft.com/cppblog/visual-studio-cmake-support-clang-llvm-cmake-3-14-vcpkg-and-performance-improvements/)

::: moniker-end
