---
title: "Problemas de migração de ponto flutuante | Microsoft Docs"
ms.custom: 
ms.date: 05/17/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 36a1b552-2f2b-4919-bc9d-c17f42434954
caps.latest.revision: "1"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 59898a5ad6af6728b16163c766f6295c850dc577
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="floating-point-migration-issues"></a>Problemas de migração de ponto flutuante  
  
Às vezes, ao atualizar os projetos para uma versão mais nova do Visual Studio, você poderá achar que os resultados de algumas operações de ponto flutuantes foram alterados. Isso geralmente ocorre por um desses dois motivos: alterações de geração de código que aproveitam melhor o processador disponível e correções de bugs ou alterações nos algoritmos usados em funções matemáticas no CRT (biblioteca em tempo de execução C). Em geral, os novos resultados estão corretos e estão dentro dos limites especificados pelo padrão da linguagem. Continue lendo para descobrir o que mudou e se isso for importante, como obter os mesmos resultados obtidos antes pelas funções.  

## <a name="new-math-functions-and-universal-crt-changes"></a>Novas funções matemáticas e alterações do CRT Universal  
  
A maioria das funções matemáticas do CRT está disponível no Visual Studio há vários anos, mas a partir do Visual Studio 2013, todas as funções exigidas pela ISO C99 estão incluídas. Essas funções são implementadas para equilibrar o desempenho com exatidão. Uma vez que produzir o resultado arredondado corretamente pode ter um custo proibitivo em todos os casos, essas funções foram criadas para produzir de forma eficiente um resultado próximo ao resultado arredondado corretamente. Na maioria dos casos, o resultado produzido está dentro de +/-1 unidade da precisão mínima ou *ulp*, do resultado arredondado corretamente, embora possa haver casos em que a imprecisão é maior. Se você estava usando outra biblioteca de matemática para obter essas funções antes, as diferenças de implementação podem ser responsáveis pela alteração nos resultados.   
    
Quando as funções matemáticas foram movidas para o CRT Universal no Visual Studio 2015, alguns novos algoritmos foram utilizados e vários bugs na implementação das funções que eram novas no Visual Studio 2013 foram corrigidos. Essas alterações podem levar a diferenças detectáveis nos resultados de cálculos de ponto flutuante que usam essas funções. As funções que tiveram problemas de bugs foram erf, exp2, remainder, remquo, scalbln, scalbn e suas variantes de flutuação e longo duplo.  Outras alterações no Visual Studio 2015 corrigiram problemas de preservação de palavra de status de ponto flutuante e informações de estado de exceção nas funções _clear87, _clearfp, fegetenv, fesetenv e feholdexcept.  
  
## <a name="processor-differences-and-compiler-flags"></a>Diferenças de processador e sinalizadores de compilador  
  
Muitas das funções da biblioteca de matemática de ponto flutuante têm implementações diferentes para diferentes arquiteturas de CPU. Por exemplo, o CRT x86 de 32 bits pode ter uma implementação diferente do CRT x64 de 64 bits. Além disso, algumas das funções podem ter várias implementações para uma determinada arquitetura de CPU. A implementação mais eficiente é selecionada dinamicamente em tempo de execução dependendo dos conjuntos de instruções com suporte da CPU. Por exemplo, no CRT x86 de 32 bits, algumas funções têm uma implementação x87 e uma implementação SSE2. Quando executado em uma CPU com suporte para SSE2, é usada a implementação SSE2 mais rápida. Quando executado em uma CPU sem suporte para SSE2, é usada a implementação x87 mais lenta. Você poderá ver isso ao migrar o código antigo, porque a opção de arquitetura x86 padrão do compilador foi alterada para [/arch:SSE2](../build/reference/arch-x86.md) no Visual Studio 2012. Uma vez que diferentes implementações das funções da biblioteca de matemática podem usar diferentes instruções de CPU e diferentes algoritmos para produzir seus resultados, as funções podem produzir resultados diferentes em plataformas diferentes. Na maioria dos casos, os resultados são dentro de +/-1 ulp do resultado arredondado corretamente, mas os resultados reais podem variar entre CPUs.  
  
Melhorias de correção de geração de código em diferentes modos de ponto flutuante no Visual Studio também podem afetar os resultados de operações de ponto flutuante quando o código antigo é comparado com o novo, mesmo ao usar os mesmos sinalizadores de compilador. Por exemplo, o código gerado pelo Visual Studio 2010 quando [/fp:precise](../build/reference/fp-specify-floating-point-behavior.md) (o padrão) ou **/fp:strict** tiver sido especificado pode não ter propagado valores NaN (não é um número) intermediários por meio de expressões corretamente. Portanto, algumas expressões que forneciam um resultado numérico nos compiladores antigos agora podem produzir corretamente um resultado NaN. Também é possível ver diferenças, pois as otimizações de código habilitadas para **/fp:fast** agora aproveitam mais recursos do processador. Essas otimizações podem usar menos instruções, mas podem afetar os resultados gerados, já que algumas operações intermediárias anteriormente visíveis foram removidas.  
  
## <a name="how-to-get-identical-results"></a>Como obter resultados idênticos  
  
Na maioria dos casos, as alterações de ponto flutuante nas bibliotecas e nos compiladores mais novos resultam em um comportamento mais rápido ou mais correto, ou ambos. Você poderá até mesmo observar um melhor desempenho de energia do processador quando as instruções SSE2 substituem as instruções x87. No entanto, se você tiver um código que deve replicar com precisão o comportamento de ponto flutuante de um compilador mais antigo, considere o uso das funcionalidades de multiplataforma nativa do Visual Studio e compile o projeto afetado com o conjunto de ferramentas mais antigo. Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md).  
  
## <a name="see-also"></a>Consulte também  
  
[Atualizando projetos de versões anteriores do Visual C++](upgrading-projects-from-earlier-versions-of-visual-cpp.md)  
[Visão geral de possíveis problemas de atualização (Visual C++)](overview-of-potential-upgrade-issues-visual-cpp.md)  
[Histórico de alterações de 2003 a 2015 do Visual C++](visual-cpp-change-history-2003-2015.md)  
