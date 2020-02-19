---
title: Como definir propriedades de análise de código para projetos do C/C++
ms.date: 11/04/2016
ms.topic: conceptual
f1_keywords:
- vs.codeanalysis.propertypages.native
- VC.Project.VCCLCompilerTool.EnablePrefast
- VC.Project.VCFxCopTool.EnablePREfast
- VC.Project.VCFxCopTool.IgnoreGeneratedCode
helpviewer_keywords:
- properties, C/C++ Code Analysis
- properties, Code Analysis
- code analysis properties
- C/C++ code analysis properties
ms.assetid: 7af52097-6d44-4785-9b9f-43b7a7d447d7
ms.openlocfilehash: 0f1f5b18255c9d39c2922c5c4f049f1cbe40d37e
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418798"
---
# <a name="how-to-set-code-analysis-properties-for-cc-projects"></a>Como definir propriedades de análise de código para projetos do C/C++

Você pode configurar quais regras a ferramenta de análise de código usa para analisar o código em cada configuração do seu projeto. Além disso, você pode direcionar a análise de código para suprimir avisos do código que foi gerado e adicionado ao seu projeto por uma ferramenta de terceiros.

## <a name="code-analysis-property-page"></a>Página de propriedades de análise de código

A página de propriedades de **análise de código** contém todas as definições de configuração de análise de código para um projeto do MSBuild. Para abrir a página de propriedades de análise de código de um projeto no **Gerenciador de soluções**, clique com o botão direito do mouse no projeto e clique em **Propriedades**. Em seguida, expanda **Propriedades de configuração** e selecione a guia **análise de código** .

## <a name="project-configuration-and-platform"></a>Configuração e plataforma de projeto

A lista de **configurações** e a lista de **plataformas** na parte superior da janela permitem aplicar diferentes configurações de análise de código a diferentes combinações de plataforma e configuração de projeto. Por exemplo, você pode direcionar a análise de código para aplicar um conjunto de regras ao seu projeto para compilações de depuração e um conjunto diferente para compilações de versão.

## <a name="enabling-code-analysis"></a>Habilitando análise de código

Você pode habilitar a análise de código para seu projeto alternando as opções **Habilitar análise de código da Microsoft** e **habilitar Clang-organizar** e, em seguida, configurar se ele for executado na compilação selecionando **Habilitar análise de código na compilação**. Em combinação com a lista de **configuração** , você pode, por exemplo, decidir desabilitar a análise de código para compilações de depuração e habilitá-la para compilações de versão.

A análise de código foi projetada para ajudá-lo a melhorar a qualidade do seu código e evitar armadilhas comuns. Portanto, considere atentamente se a análise de código deve ser desabilitada. Geralmente, é melhor desabilitar conjuntos de regras, regras individuais ou verificações individuais que você não deseja aplicar ao seu projeto.

## <a name="cmake-configuration"></a>Configuração do CMake

Em projetos CMake, altere o valor da `enableMicrosoftCodeAnalysis` e `enableClangTidyCodeAnalysis` chaves dentro de `CMakeSettings.json` para habilitar ou desabilitar a análise de código. Consulte [usando o Clang no Visual Studio](../code-quality/clang-tidy.md) para obter mais informações.

## <a name="see-also"></a>Confira também

- [Analisando a qualidade do código gerenciado](/visualstudio/code-quality/code-analysis-for-managed-code-overview)
- [Análise de código para avisos do C/C++](../code-quality/code-analysis-for-c-cpp-warnings.md)
- [Usar conjuntos de regras para especificar C++ as regras a serem executadas](using-rule-sets-to-specify-the-cpp-rules-to-run.md)
- [Usando Clang-organizar](../code-quality/clang-tidy.md)
