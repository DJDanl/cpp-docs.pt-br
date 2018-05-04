---
title: Otimizando o código | Microsoft Docs
ms.custom: ''
ms.date: 12/28/2017
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- performance, optimizing code
- optimization
- cl.exe compiler, performance
- optimization, C++ code
- code, optimizing
- performance, compiler
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a8b18ba4ce00eb751d8f30debbab3e87b9cce53e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="optimizing-your-code"></a>Otimizando o código

Otimizando um executável, você pode obter um equilíbrio entre a velocidade de execução rápida e tamanho de código pequeno. Este tópico discute alguns dos mecanismos fornecidos para ajudá-lo a otimizar código Visual C++.

## <a name="language-features"></a>Funcionalidades da linguagem

Os tópicos a seguir descrevem alguns dos recursos de otimização na linguagem C/C++.

[Pragmas e palavras-chave de otimização](../../build/reference/optimization-pragmas-and-keywords.md)  
Uma lista de palavras-chave e pragmas que você pode usar em seu código para melhorar o desempenho.

[Opções de Compilador Listadas por Categoria](../../build/reference/compiler-options-listed-by-category.md)  
Uma lista de **/O** opções do compilador que afeta especificamente o tamanho de código ou velocidade de execução.

[Declarador de referência Rvalue: &&](../../cpp/rvalue-reference-declarator-amp-amp.md)  
A implementação do suportam a referências a Rvalue *mover semântica*. Se mover semântica é usada para implementar as bibliotecas de modelo, o desempenho de aplicativos que usam esses modelos pode melhorar significativamente.

### <a name="the-optimize-pragma"></a>O pragma de otimizar

Se uma seção otimizada de código causa erros ou uma diminuição, você pode usar o [otimizar](../../preprocessor/optimize.md) pragma para desativar a otimização para essa seção.

Coloque o código entre dois pragmas, conforme mostrado aqui:

```cpp
#pragma optimize("", off)
// some code here
#pragma optimize("", on)
```

## <a name="programming-practices"></a>Práticas recomendadas de programação

Você pode notar mais mensagens de aviso quando você compila o código com a otimização. Esse comportamento é esperado, pois alguns avisos relacionam apenas para o código otimizado. Você pode evitar muitos problemas de otimização se prestar atenção a esses avisos.

Paradoxal, otimização de um programa para velocidade pode causar o código para executar mais lentamente. Isso ocorre porque algumas otimizações para velocidade de aumentam o tamanho do código. Por exemplo, as funções de inlining elimina a sobrecarga das chamadas de função. No entanto, inlining muitos códigos podem tornar seu programa tão grande que o número da página de memória virtual falhas aumenta. Portanto, a velocidade obtida com a eliminação de chamadas de função pode ser perdida para troca de memória.

Os tópicos a seguir discutem práticas de programação.

[Dicas para melhorar código crítico em termos de tempo](../../build/reference/tips-for-improving-time-critical-code.md)  
Técnicas de codificação melhor podem resultar em melhor desempenho. Este tópico sugere codificação técnicas que podem ajudar a garantir que as partes críticas de seu código um desempenho satisfatório.

[Melhores práticas de otimização](../../build/reference/optimization-best-practices.md)  
Fornece diretrizes gerais sobre a melhor maneira de otimizar seu aplicativo.

## <a name="debugging-optimized-code"></a>Depurar o código otimizado

Como otimização pode alterar o código criado pelo compilador, recomendamos que você depura seu aplicativo e medir o desempenho e otimizar o seu código.

Os tópicos a seguir fornecem informações básicas sobre como depurar.

- [Depurando no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio)

- [Problemas comuns durante a criação de um build de versão](../../build/reference/common-problems-when-creating-a-release-build.md)

Os tópicos a seguir fornecem informações mais avançadas sobre como depurar.

- [Como depurar o código otimizado](/visualstudio/debugger/how-to-debug-optimized-code)

- [Por que números de ponto flutuante podem perder a precisão](../../build/reference/why-floating-point-numbers-may-lose-precision.md)

Os tópicos a seguir fornecem informações sobre como otimizar o compilar, carregar e executar seu código.

- [Melhorando a taxa de transferência do compilador](../../build/reference/improving-compiler-throughput.md)

- [Usar o nome de função sem () não produz código](../../build/reference/using-function-name-without-parens-produces-no-code.md)

- [Otimizando o assembly embutido](../../assembler/inline/optimizing-inline-assembly.md)

- [Especificação de otimização do compilador para um projeto da ATL](../../atl/reference/specifying-compiler-optimization-for-an-atl-project.md)

- [As técnicas de otimização devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento?](../../build/dll-frequently-asked-questions.md#mfc_optimization)

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)  
