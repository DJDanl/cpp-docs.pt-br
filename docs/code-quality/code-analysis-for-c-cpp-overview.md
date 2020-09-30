---
title: Análise de código para visão geral do C/C++
ms.date: 04/28/2018
ms.topic: conceptual
helpviewer_keywords:
- annotations, code analysis
- build integration, code analysis
- C/C++ code analysis
- IDE, code analysis
- pragma directive, code analysis
- code analysis, C/C++
- code analysis tool
- command line, code analysis
- C++, code analysis
- check-in policies, code analysis
- '#pragma directives, code analysis'
- C, code analysis
ms.assetid: 81f0c9e8-f471-4de5-aac4-99db336a8809
ms.openlocfilehash: f128c9722138f453c72ca97b09cc1a69a737dbf6
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504195"
---
# <a name="code-analysis-for-cc-overview"></a>Análise de código para visão geral do C/C++

A ferramenta de análise de código do C/C++ fornece informações sobre possíveis defeitos em seu código-fonte C/C++. Entre os erros de codificação comuns reportados pela ferramenta estão estouros de buffer, memória não inicializada, desreferências de ponteiro nulo, memória e perdas de recurso. A ferramenta também pode executar verificações no [diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).

## <a name="ide-integrated-development-environment-integration"></a>Integração do IDE (ambiente de desenvolvimento integrado)

A ferramenta de análise de código está totalmente integrada no IDE do Visual Studio.

Durante o processo de build, todos os avisos gerados para o código-fonte aparecem na Lista de Erros. Você pode navegar para o código-fonte que causou o aviso e ver informações adicionais sobre a causa e possíveis soluções do problema.

## <a name="command-line-support"></a>Suporte de linha de comando

Você também pode usar a ferramenta de análise na linha de comando, conforme mostrado no exemplo a seguir:

```cmd
C:\>cl /analyze Sample.cpp
```

**Visual Studio 2017 versão 15,7 e posterior:** Você pode executar a ferramenta na linha de comando com qualquer sistema de compilação, incluindo CMake.

## <a name="pragma-support"></a>suporte a #pragma

Você pode usar a `#pragma` diretiva para tratar avisos como erros; habilitar ou desabilitar avisos e suprimir avisos para linhas individuais de código. Para obter mais informações, consulte [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md).

## <a name="annotation-support"></a>Suporte a anotações

As anotações melhoram a precisão da análise de código. As anotações fornecem informações adicionais sobre pré e pós-condições nos parâmetros de função e nos tipos retornados. Para obter mais informações, consulte [usando anotações de sal para reduzir os defeitos de código C/C++](../code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects.md).

## <a name="run-analysis-tool-as-part-of-check-in-policy"></a>Execute a ferramenta de análise como parte da política de check-in

Talvez você queira exigir que todos os check-ins do código-fonte satisfaçam determinadas políticas. Em particular, convém verificar se a análise foi executada como uma etapa do build local mais recente. Para obter mais informações sobre como habilitar uma política de check-in de análise de código, consulte [criando e usando políticas de check-in de análise de código](/visualstudio/code-quality/how-to-create-or-update-standard-code-analysis-check-in-policies).

## <a name="team-build-integration"></a>Integração do Team Build

Você pode usar os recursos integrados do sistema de compilação para executar a ferramenta de análise de código como uma etapa do processo de compilação do Azure DevOps. Para obter mais informações, confira [Azure Pipelines](/azure/devops/pipelines/index).

## <a name="see-also"></a>Consulte também

- [Início Rápido: análise de código para C/C++](quick-start-code-analysis-for-c-cpp.md)
- [Walkthrough: analisar o código C/C++ para defeitos](walkthrough-analyzing-c-cpp-code-for-defects.md)
- [Análise de código para avisos C/C++](code-analysis-for-c-cpp-warnings.md)
- [Usar os verificadores de Diretrizes Principais do C++](using-the-cpp-core-guidelines-checkers.md)
- [Referência do verificador de Diretrizes Principais do C++](code-analysis-for-cpp-corecheck.md)
- [Usar conjuntos de regras para especificar as regras do C++ a serem executadas](using-rule-sets-to-specify-the-cpp-rules-to-run.md)
- [Analisar a qualidade do driver usando ferramentas de análise de código](/windows-hardware/drivers/develop/analyzing-driver-quality-by-using-code-analysis-tools)
- [Análise de código para avisos de drivers](/windows-hardware/drivers/devtest/prefast-for-drivers-warnings)
