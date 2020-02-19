---
title: Usando o Clang-reorganizar no Visual Studio
ms.date: 10/04/2019
ms.topic: conceptual
f1_keywords:
- vs.codeanalysis.clangtidy
author: frozenpandaman
ms.author: efessler
ms.openlocfilehash: 19ec35ee931822d6952512f417bbbdba14ee04b9
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418882"
---
# <a name="using-clang-tidy-in-visual-studio"></a>Usando o Clang-reorganizar no Visual Studio

A análise de código dá suporte nativamente [a Clang](https://clang.llvm.org/extra/clang-tidy/) para projetos MSBuild e CMake, seja usando conjuntos de ferramentas CLANG ou MSVC. As verificações Clang podem ser executadas como parte da análise de código em segundo plano, aparecem como avisos no editor (ondulados) e são exibidos no Lista de Erros.

Para usar o Clang, o componente "C++ ferramentas do Clang para Windows" deve ser instalado por meio do instalador do Visual Studio.

Clang-organizar é a ferramenta de análise padrão ao usar o conjunto de ferramentas LLVM/Clang-CL, disponível tanto no MSBuild quanto no CMake. Você pode configurá-lo para ser executado junto com ou substituir a experiência de análise de código padrão ao usar um conjunto de ferramentas MSVC; Se estiver usando o conjunto de ferramentas Clang-CL, a análise de código da Microsoft não estará disponível.

Clang-organizar execuções após a compilação bem-sucedida; Talvez seja necessário resolver os erros do código-fonte para obter os resultados de Clang.

## <a name="msbuild"></a>MSBuild

Você pode configurar o Clang para ser executado como parte da análise de código e da compilação na página de **análise de código** > **geral** no janela Propriedades do projeto. As opções para configurar a ferramenta podem ser encontradas no submenu Clang-organizar.

Para obter mais informações, consulte [como: definir propriedades de análise de código paraC++ C/Projects](../code-quality/how-to-set-code-analysis-properties-for-c-cpp-projects.md).

## <a name="cmake"></a>CMake

Em projetos do CMake, você pode configurar as verificações do Clang no `CMakeSettings.json`. Depois de aberto, clique em "Editar JSON" no canto superior direito do editor de configurações do projeto CMake. As seguintes chaves são reconhecidas:

- `enableMicrosoftCodeAnalysis`: habilita a análise de código da Microsoft
- `enableClangTidyCodeAnalysis`: habilita a análise Clang
- `clangTidyChecks`: configuração Clang-organizar, especificada como uma lista separada por vírgulas, ou seja, verificações a serem habilitadas ou desabilitadas

Se nenhuma das opções de "habilitar" for especificada, o Visual Studio selecionará a ferramenta de análise correspondente ao conjunto de ferramentas de plataforma usado.

## <a name="warning-display"></a>Exibição de aviso

As execuções de Clang resultam em avisos exibidos na Lista de Erros e como rabiscos no editor embaixo das seções relevantes do código. Use a coluna "categoria" no Lista de Erros para classificar e organizar os avisos Clang. Você pode configurar avisos no editor alternando a configuração "desabilitar rabiscos de análise de código" em **ferramentas** > **Opções**.

## <a name="clang-tidy-configuration"></a>Configuração do Clang-organizar

Você pode configurar as verificações que o Clang executa dentro do Visual Studio por meio da opção de **verificações de Clang** . Essa entrada é fornecida ao argumento **--verifica** da ferramenta. Qualquer configuração adicional pode ser incluída em arquivos **. Clang-organizar** personalizados. Consulte a [documentação do Clang-organizado sobre o LLVM.org](https://clang.llvm.org/extra/clang-tidy/) para obter mais detalhes.

## <a name="see-also"></a>Confira também

- [Suporte a Clang/LLVM para projetos do MSBuild](https://devblogs.microsoft.com/cppblog/clang-llvm-support-for-msbuild-projects/)
- [Suporte a Clang/LLVM para projetos de CMake](https://devblogs.microsoft.com/cppblog/visual-studio-cmake-support-clang-llvm-cmake-3-14-vcpkg-and-performance-improvements/)
