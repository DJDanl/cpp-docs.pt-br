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
ms.openlocfilehash: b715f3cc6bc505d9698484ad7c47b8262f2bc728
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444405"
---
# <a name="optimizing-your-code"></a>Otimizando o código

Ao otimizar um executável, você pode obter um equilíbrio entre velocidade de execução rápida e o tamanho do código pequeno. Este tópico discute alguns dos mecanismos que o Visual C++ oferece para ajudá-lo a otimizar o código.

## <a name="language-features"></a>Funcionalidades da linguagem

Os tópicos a seguir descrevem alguns dos recursos de otimização na linguagem C/C++.

[Pragmas e palavras-chave de otimização](../../build/reference/optimization-pragmas-and-keywords.md)<br/>
Uma lista de palavras-chave e pragmas que você pode usar em seu código para melhorar o desempenho.

[Opções de Compilador Listadas por Categoria](../../build/reference/compiler-options-listed-by-category.md)<br/>
Uma lista dos **/O** opções do compilador que afeta especificamente o tamanho de velocidade ou código de execução.

[Declarador de referência Rvalue: &&](../../cpp/rvalue-reference-declarator-amp-amp.md)<br/>
A implementação de dar suporte a referências de Rvalue *semântica de movimentação*. Se a semântica é usada para implementar as bibliotecas de modelo, o desempenho de aplicativos que usam esses modelos de movimentação pode melhorar significativamente.

### <a name="the-optimize-pragma"></a>O pragma optimize

Se uma seção com otimização de código causa erros ou uma lentidão, você pode usar o [otimizar](../../preprocessor/optimize.md) pragma para desligar a otimização para essa seção.

Coloque o código entre dois pragmas, conforme mostrado aqui:

```cpp
#pragma optimize("", off)
// some code here
#pragma optimize("", on)
```

## <a name="programming-practices"></a>Práticas recomendadas de programação

Você pode observar as mensagens de aviso adicionais quando você compila seu código com a otimização. Esse comportamento é esperado porque alguns avisos estão relacionados apenas a código otimizado. Você pode evitar muitos problemas de otimização se prestar atenção a esses avisos.

Paradoxalmente, otimização de um programa para velocidade pode fazer com que código seja executado mais lentamente. Isso ocorre porque algumas otimizações para velocidade de aumentam o tamanho do código. Por exemplo, as funções de inlining elimina a sobrecarga das chamadas de função. No entanto, inlining muito código pode tornar o seu programa tão grande que o número da página de memória virtual de falhas aumenta. Portanto, a velocidade obtida com a eliminação de chamadas de função pode ser perdida para troca de memória.

Os tópicos a seguir discutem práticas de programação.

[Dicas para melhorar código crítico em termos de tempo](../../build/reference/tips-for-improving-time-critical-code.md)<br/>
Criando códigos melhores técnicas podem resultar em melhor desempenho. Este tópico sugere técnicas que podem ajudar a garantir que as partes críticas de seu código um desempenho satisfatório de codificação.

[Melhores práticas de otimização](../../build/reference/optimization-best-practices.md)<br/>
Fornece diretrizes gerais sobre a melhor maneira de otimizar o aplicativo.

## <a name="debugging-optimized-code"></a>Depurar o código otimizado

Como otimização pode alterar o código criado pelo compilador, é recomendável que você depura seu aplicativo e medir seu desempenho e, em seguida, otimizar seu código.

Os tópicos a seguir fornecem informações básicas sobre como depurar.

- [Depurando no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio)

- [Problemas comuns durante a criação de um build de versão](../../build/reference/common-problems-when-creating-a-release-build.md)

Os tópicos a seguir fornecem informações mais avançadas sobre como depurar.

- [Como depurar o código otimizado](/visualstudio/debugger/how-to-debug-optimized-code)

- [Por que números de ponto flutuante podem perder a precisão](../../build/reference/why-floating-point-numbers-may-lose-precision.md)

Os tópicos a seguir fornecem informações sobre como otimizar a criação, carregar e executar seu código.

- [Melhorando a taxa de transferência do compilador](../../build/reference/improving-compiler-throughput.md)

- [Usar o nome de função sem () não produz código](../../build/reference/using-function-name-without-parens-produces-no-code.md)

- [Otimizando o assembly embutido](../../assembler/inline/optimizing-inline-assembly.md)

- [Especificação de otimização do compilador para um projeto da ATL](../../atl/reference/specifying-compiler-optimization-for-an-atl-project.md)

- [Quais técnicas de otimização devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento?](../../build/dll-frequently-asked-questions.md#mfc_optimization)

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)
