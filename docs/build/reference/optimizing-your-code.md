---
title: "Otimizando o c&#243;digo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, desempenho"
  - "código, otimizando"
  - "otimização"
  - "otimização, código C++"
  - "desempenho, Compilador "
  - "desempenho, otimizando código"
ms.assetid: 4f33e6c7-9870-43b3-9c2f-d7e44f764971
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Otimizando o c&#243;digo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Otimizando um executável, você pode obter um equilíbrio entre a velocidade de execução rápida e o tamanho de código pequeno.  Este tópico discute alguns dos mecanismos que fornece o Visual C\+\+ para ajudar a otimizar o código.  
  
## Recursos da linguagem  
 Os tópicos a seguir descrevem alguns dos recursos de otimização do idioma C\/C\+\+.  
  
 [Pragmas e palavras\-chave de otimização](../../build/reference/optimization-pragmas-and-keywords.md)  
 Uma lista de palavras\-chave e de pragmas que você pode usar em seu código para melhorar o desempenho.  
  
 [Opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md)  
 Uma lista de opções do compilador de **\/O** que afeta especificamente a velocidade de execução ou o tamanho de código.  
  
 [Declarador de referência Rvalue: &&](../../cpp/rvalue-reference-declarator-amp-amp.md)  
 As referências de Rvalue dão suporte a implementação da *semântica*da movimentação.  Se a semântica de movimentação é usada para implementar bibliotecas do modelo, o desempenho de aplicativos que usam esses modelos pode melhorar significativamente.  
  
### O pragma otimizar  
 Se uma seção otimizada de código a seguir causa erros ou diminuição, você pode usar o pragma de [otimizar](../../preprocessor/optimize.md) para desativar a otimização para essa seção.  
  
 Incluir código entre dois pragmas, como a seguir.  
  
```  
#pragma optimize("", off)  
// some code here   
#pragma optimize("", on)  
```  
  
## Práticas de programação  
 Você pode perceber mensagens de aviso adicionais quando você cria seu código com otimização.  Esse comportamento é esperado porque alguns avisos estão relacionados apenas ao código.  Você pode evitar muitos problemas de otimização se você notar esses avisos.  
  
 Paradoxal, otimizar um programa para a velocidade pode fazer com que o código seja executado com mais lenta.  Isso ocorre porque algumas otimizações para a velocidade aumentam o tamanho de código.  Por exemplo, inlining funções elimina a sobrecarga das chamadas de função.  No entanto, inlining muito código pode fazer seu programa tão grande que o número de falhas de página de memória virtual aumenta.  Consequentemente, a velocidade ganhada de eliminar chamadas de função poderá ser perdida a troca de memória.  
  
 Os tópicos a seguir abordam uma boa práticas.  
  
 [Dicas para melhorar código crítico em termos de tempo](../../build/reference/tips-for-improving-time-critical-code.md)  
 As melhores técnicas de codificação pode resultar em um melhor desempenho.  Este tópico dicas técnicas de codificação que podem ajudar a garantir que as partes críticos do código são executados satisfatoriamente.  
  
 [Práticas recomendadas de otimização](../../build/reference/optimization-best-practices.md)  
 Fornece diretrizes gerais sobre como melhor otimizar seu aplicativo.  
  
## Código otimizado depuração  
 Como a otimização pode alterar o código criado pelo compilador, recomendamos que você depura seu aplicativo e mede o desempenho, e otimizamos em seu código.  
  
 Os tópicos a seguir fornecem informações básicas sobre como depurar.  
  
-   [Depurando no Visual Studio](../Topic/Debugging%20in%20Visual%20Studio.md)  
  
-   [Problemas comuns durante a criação de uma compilação de versão](../../build/reference/common-problems-when-creating-a-release-build.md)  
  
 Os tópicos a seguir fornecem informações mais avançadas sobre como depurar.  
  
-   [Como depurar o código otimizado](../Topic/How%20to:%20Debug%20Optimized%20Code.md)  
  
-   [Por que números de ponto flutuante podem perder a precisão](../../build/reference/why-floating-point-numbers-may-lose-precision.md)  
  
 Variedade dos tópicos a seguir fornecem informações sobre como otimizar a compilação, a carga, e executar seu código.  
  
-   [Melhorando taxa de transferência do compilador](../../build/reference/improving-compiler-throughput.md)  
  
-   [O uso do nome de função sem \(\) não produz código](../Topic/Using%20Function%20Name%20Without%20\(\)%20Produces%20No%20Code.md)  
  
-   [Otimizando assembly embutido](../../assembler/inline/optimizing-inline-assembly.md)  
  
-   [Especificando otimização de compilador para um projeto ATL](../../atl/reference/specifying-compiler-optimization-for-an-atl-project.md)  
  
-   [Quais técnicas de otimização devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento?](../../build/what-optimization-techniques-should-i-use.md)  
  
-   [!INCLUDE[crabout](../Token/crabout_md.md)] como reduzir o tempo de carregamento métodos da DLL, consulte “otimizando o desempenho de tempo de carregamento de DLL” sob “na coluna de cobertura” de “no MSDN bin”[A Biblioteca MSDN](http://go.microsoft.com/fwlink/?linkid=556) no site.  
  
-   [!INCLUDE[crabout](../Token/crabout_md.md)] como minimizar a paginação em aplicativos, consulte “melhorando o desempenho de tempo de execução com a ferramenta simples de conjunto de trabalho” e “melhorando o desempenho de tempo de execução com o uso da parte simples 2 " do conjunto de trabalho na coluna de “Bugslayer” de “no MSDN bin”[A Biblioteca MSDN](http://go.microsoft.com/fwlink/?linkid=556) no site.  
  
## Consulte também  
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)