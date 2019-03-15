---
title: Otimizando o código
ms.date: 12/10/2018
helpviewer_keywords:
- performance, optimizing code
- optimization
- cl.exe compiler, performance
- optimization, C++ code
- code, optimizing
- performance, compiler
ms.openlocfilehash: ae60070959c683a6365992e7b6cc510fd4111b36
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824672"
---
# <a name="optimizing-your-code"></a>Otimizando o código

Ao otimizar um executável, você pode obter um equilíbrio entre velocidade de execução rápida e o tamanho do código pequeno. Este tópico discute alguns dos mecanismos que o Visual C++ oferece para ajudá-lo a otimizar o código.

## <a name="language-features"></a>Funcionalidades da linguagem

Os tópicos a seguir descrevem alguns dos recursos de otimização na linguagem C/C++.

[Pragmas e palavras-chave de otimização](optimization-pragmas-and-keywords.md)<br/>
Uma lista de palavras-chave e pragmas que você pode usar em seu código para melhorar o desempenho.

[Opções de Compilador Listadas por Categoria](reference/compiler-options-listed-by-category.md)<br/>
Uma lista dos **/O** opções do compilador que afeta especificamente o tamanho de velocidade ou código de execução.

[Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md)<br/>
A implementação de dar suporte a referências de Rvalue *semântica de movimentação*. Se a semântica é usada para implementar as bibliotecas de modelo, o desempenho de aplicativos que usam esses modelos de movimentação pode melhorar significativamente.

### <a name="the-optimize-pragma"></a>O pragma optimize

Se uma seção com otimização de código causa erros ou uma lentidão, você pode usar o [otimizar](../preprocessor/optimize.md) pragma para desligar a otimização para essa seção.

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

[Dicas para melhorar código crítico em termos de tempo](tips-for-improving-time-critical-code.md)<br/>
Criando códigos melhores técnicas podem resultar em melhor desempenho. Este tópico sugere técnicas que podem ajudar a garantir que as partes críticas de seu código um desempenho satisfatório de codificação.

[Melhores práticas de otimização](optimization-best-practices.md)<br/>
Fornece diretrizes gerais sobre a melhor maneira de otimizar o aplicativo.

## <a name="debugging-optimized-code"></a>Depurar o código otimizado

Como otimização pode alterar o código criado pelo compilador, é recomendável que você depura seu aplicativo e medir seu desempenho e, em seguida, otimizar seu código.

Os tópicos a seguir fornecem informações sobre como depurar a versão se baseia.

- [Depurando no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio)

- [Como: Depurar o código otimizado](/visualstudio/debugger/how-to-debug-optimized-code)

- [Por que números de ponto flutuante podem perder a precisão](why-floating-point-numbers-may-lose-precision.md)


Os tópicos a seguir fornecem informações sobre como otimizar a criação, carregar e executar seu código.

- [Melhorando a taxa de transferência do compilador](improving-compiler-throughput.md)

- [Usar o nome de função sem () não produz código](using-function-name-without-parens-produces-no-code.md)

- [Otimizando o assembly embutido](../assembler/inline/optimizing-inline-assembly.md)

- [Especificação de otimização do compilador para um projeto da ATL](../atl/reference/specifying-compiler-optimization-for-an-atl-project.md)

- [Quais técnicas de otimização devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento?](../build/dll-frequently-asked-questions.md#mfc_optimization)


## <a name="in-this-section"></a>Nesta seção

[Pragmas e palavras-chave de otimização](optimization-pragmas-and-keywords.md)<br/>
[Melhorando a taxa de transferência do compilador](improving-compiler-throughput.md)<br/>
[Por que números de ponto flutuante podem perder a precisão](why-floating-point-numbers-may-lose-precision.md)<br/>
[Representação de ponto flutuante IEEE](ieee-floating-point-representation.md)<br/>
[Dicas para melhorar código crítico em termos de tempo](tips-for-improving-time-critical-code.md)<br/>
[Usar o nome de função sem () não produz código](using-function-name-without-parens-produces-no-code.md)<br/>
[Melhores práticas de otimização](optimization-best-practices.md)<br/>
[Otimizações guiadas por perfil](profile-guided-optimizations.md)<br/>
[Variáveis de ambiente para otimizações guiadas por perfil](environment-variables-for-profile-guided-optimizations.md)<br/>
[PgoAutoSweep](pgoautosweep.md)<br/>
[pgomgr](pgomgr.md)<br/>
[pgosweep](pgosweep.md)<br/>
[Como: mesclar vários perfis do PGO em um único perfil](how-to-merge-multiple-pgo-profiles-into-a-single-profile.md)<br/>
[Suplemento de PGO do Visual Studio 2013 no Hub de desempenho e de diagnóstico](profile-guided-optimization-in-the-performance-and-diagnostics-hub.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](reference/c-cpp-building-reference.md)
