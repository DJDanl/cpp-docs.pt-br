---
title: Otimizando o código
ms.date: 05/06/2019
helpviewer_keywords:
- performance, optimizing code
- optimization
- cl.exe compiler, performance
- optimization, C++ code
- code, optimizing
- performance, compiler
ms.openlocfilehash: 00356cf50ca8e50c80e8a1142adf654816490c9b
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078499"
---
# <a name="optimizing-your-code"></a>Otimizando seu código

Ao otimizar um executável, você pode obter um equilíbrio entre a velocidade de execução rápida e o tamanho de código pequeno. Este tópico discute alguns dos mecanismos que o Visual Studio fornece para ajudá-lo a otimizar o código.

## <a name="language-features"></a>Funcionalidades da linguagem

Os tópicos a seguir descrevem alguns dos recursos de otimização na linguagem C/C++.

[Pragmas de otimização e palavras-chave](optimization-pragmas-and-keywords.md) \
Uma lista de palavras-chave e pragmas que você pode usar em seu código para melhorar o desempenho.

[Opções de compilador listadas por categoria](reference/compiler-options-listed-by-category.md) \
Uma lista de opções de compilador **/o** que afetam especificamente a velocidade de execução ou o tamanho do código.

[Declarador de referência rvalue:  &&](../cpp/rvalue-reference-declarator-amp-amp.md) \
As referências a rvalue dão suporte à implementação da *semântica de movimentação*. Se a semântica de movimentação for usada para implementar bibliotecas de modelos, o desempenho dos aplicativos que usam esses modelos poderá melhorar significativamente.

### <a name="the-optimize-pragma"></a>O pragma de otimização

Se uma seção otimizada do código causar erros ou uma lentidão, você poderá usar a opção [otimizar](../preprocessor/optimize.md) pragma para desativar a otimização para essa seção.

Coloque o código entre dois pragmas, conforme mostrado aqui:

```cpp
#pragma optimize("", off)
// some code here
#pragma optimize("", on)
```

## <a name="programming-practices"></a>Práticas de programação

Você pode notar mensagens de aviso adicionais ao compilar seu código com otimização. Esse comportamento é esperado porque alguns avisos estão relacionados apenas ao código otimizado. Você pode evitar muitos problemas de otimização se você prestar esses avisos.

Paradoxalmente, otimizar um programa para velocidade pode fazer com que o código seja executado mais lentamente. Isso ocorre porque algumas otimizações para velocidade aumentam o tamanho do código. Por exemplo, as funções de inalinhamento eliminam a sobrecarga das chamadas de função. No entanto, o inalinhamento excessivo de código pode tornar o seu programa tão grande que o número de falhas de páginas de memória virtual aumenta. Portanto, a velocidade obtida com a eliminação de chamadas de função pode ser perdida para a troca de memória.

Os tópicos a seguir discutem boas práticas de programação.

[Dicas para melhorar o código de tempo crítico](tips-for-improving-time-critical-code.md) \
Melhores técnicas de codificação podem produzir um melhor desempenho. Este tópico sugere técnicas de codificação que podem ajudá-lo a garantir que as partes de tempo crítico do seu código sejam executadas satisfatoriamente.

[Práticas recomendadas de otimização](optimization-best-practices.md) \
Fornece diretrizes gerais sobre como otimizar melhor seu aplicativo.

## <a name="debugging-optimized-code"></a>Depuração de código otimizado

Como a otimização pode alterar o código criado pelo compilador, recomendamos que você depure seu aplicativo e meça seu desempenho e, em seguida, Otimize seu código.

Os tópicos a seguir fornecem informações sobre como Depurar compilações de versão.

- [Depurando no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio)

- [Como: depurar código otimizado](/visualstudio/debugger/how-to-debug-optimized-code)

- [Por que números de ponto flutuante podem perder a precisão](why-floating-point-numbers-may-lose-precision.md)

Os tópicos a seguir fornecem informações sobre como otimizar a criação, o carregamento e a execução de seu código.

- [Melhorando a taxa de transferência do compilador](improving-compiler-throughput.md)

- [Usar o nome de função sem () não produz código](using-function-name-without-parens-produces-no-code.md)

- [Otimizando o assembly embutido](../assembler/inline/optimizing-inline-assembly.md)

- [Especificação de otimização do compilador para um projeto da ATL](../atl/reference/specifying-compiler-optimization-for-an-atl-project.md)

- [Quais técnicas de otimização devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento?](../build/dll-frequently-asked-questions.md#mfc_optimization)

## <a name="in-this-section"></a>Nesta seção

[Pragmas de otimização e palavras-chave](optimization-pragmas-and-keywords.md) \
[Melhorando a taxa de transferência do compilador](improving-compiler-throughput.md) \
[Por que os números de ponto flutuante podem perder a precisão](why-floating-point-numbers-may-lose-precision.md) \
[Representação de ponto flutuante de IEEE](ieee-floating-point-representation.md) \
[Dicas para melhorar o código de tempo crítico](tips-for-improving-time-critical-code.md) \
[O uso de nome de função sem () não produz nenhum código](using-function-name-without-parens-produces-no-code.md) \
[Práticas recomendadas de otimização](optimization-best-practices.md) \
[Otimizações guiadas por perfil](profile-guided-optimizations.md) \
[Variáveis de ambiente para otimizações guiadas por perfil](environment-variables-for-profile-guided-optimizations.md) \
[PgoAutoSweep](pgoautosweep.md) \
[pgomgr](pgomgr.md) \
[pgosweep](pgosweep.md) \
[Como mesclar vários perfis PGO em um único perfil](how-to-merge-multiple-pgo-profiles-into-a-single-profile.md)

## <a name="see-also"></a>Confira também

[Referência de build C/C++](reference/c-cpp-building-reference.md)
