---
title: "/openmp (habilitar suporte a OpenMP 2.0) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/openmp"
  - "VC.Project.VCCLCompilerTool.OpenMP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /openmp (C++)"
  - "Opção de compilador -openmp [C++]"
ms.assetid: 9082b175-18d3-4378-86a7-c0eb95664e13
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /openmp (habilitar suporte a OpenMP 2.0)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Faz com que o compilador processa `#pragma`[omp](../../preprocessor/omp.md).  
  
## Sintaxe  
  
```  
/openmp  
```  
  
## Comentários  
 `#pragma omp` é usado para especificar [Directives](../../parallel/openmp/reference/openmp-directives.md) e [Clauses](../../parallel/openmp/reference/openmp-clauses.md).  Se **\/openmp** não é especificado em uma compilação, o compilador ignora as cláusulas e políticas OpenMP.  as chamadas de[Função OpenMP](../../parallel/openmp/reference/openmp-functions.md) são processados pelo compilador **\/openmp** mesmo se não for especificado.  
  
 Um aplicativo compilado com **\/openmp** e a utilização de [Libraries](../../parallel/openmp/reference/openmp-libraries.md) só pode ser executado no Windows 2000 ou em sistemas operacionais mais tarde.  
  
 Os aplicativos criados com **\/openmp** e **\/clr** só podem ser executados em um único processo de domínio do aplicativo; vários domínios de aplicativo não têm suporte.  Ou seja, quando o construtor de módulo \(.cctor\) é executado, o detectará o processo é criado com **\/openmp** e se o aplicativo estiver sendo carregado no tempo de execução não padrão.  Para obter mais informações, consulte [appdomain](../Topic/appdomain.md), [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) e [Inicialização de assemblies mistos](../Topic/Initialization%20of%20Mixed%20Assemblies.md).  
  
 Se você tentar carregar um aplicativo compilado com **\/openmp** e **\/clr** em um domínio de aplicativo não padrão, uma exceção será lançada de <xref:System.TypeInitializationException> fora do depurador e uma exceção de OpenMPWithMultipleAppdomainsException será gerada no depurador.  
  
 Essas exceções também podem ser geradas nas seguintes situações:  
  
-   Se seu aplicativo compilado com **\/clr**, mas não com **\/openmp**, é carregado em um domínio de aplicativo não padrão mas em que o processo inclui um aplicativo que foi compilado com **\/openmp**.  
  
-   Se você passa o aplicativo de **\/clr** a um utilitário, como regasm.exe \([Regasm.exe \(Ferramenta de Registro de Assembly\)](../Topic/Regasm.exe%20\(Assembly%20Registration%20Tool\).md)\), que carrega os assemblies de destino em um domínio de aplicativo não padrão.  
  
 A segurança de acesso do código de Common Language Runtime não funciona em regiões OpenMP.  Se você aplicar um atributo de segurança de acesso do código CLR de fora de uma região em paralelo, não será aplicado na região paralela.  
  
 A Microsoft recomenda não gravar aplicativos de **\/openmp** que permite chamadores parcialmente confiáveis, usando <xref:System.Security.AllowPartiallyTrustedCallersAttribute>, ou todos os atributos de segurança de acesso do código do CLR.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó de **C\/C\+\+** .  
  
4.  Selecione a página de propriedades de **Idioma** .  
  
5.  Modifique a propriedade de **Suporte OpenMP** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OpenMP%2A>.  
  
## Exemplo  
 O exemplo a seguir mostra alguns dos efeitos de inicialização de threadpool na utilização de threadpool depois que iniciou acima.  Supondo x64, núcleo único processador, vezes que o threadpool assume 16ms a inicialização.  Depois que embora haja um custo muito pequenos para o threadpool.  
  
 Quando você compila com **\/openmp**, o segundo chamada para test2 nunca é executado por mais tempo que se você compila com **\/openmp\-**, pois não há inicialização de threadpool.  Em milhões de iterações a versão de **\/openmp** é mais rápida que a versão de **\/openmp\-** para o segundo chamada para test2, e 25 iterações as versões de **\/openmp\-** e de **\/openmp** registram menor que a granularidade do relógio.  
  
 Isso se você tiver apenas um loop em seu aplicativo e executa em menor que 15ms \(ajustado para a sobrecarga aproximada em seu computador\), **\/openmp** não pode ser apropriado, mas se nada for maior que o, talvez queira considerar o uso **\/openmp**.  
  
```  
// cpp_compiler_options_openmp.cpp  
#include <omp.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
  
volatile DWORD dwStart;  
volatile int global = 0;  
  
double test2(int num_steps) {  
   int i;  
   global++;  
   double x, pi, sum = 0.0, step;  
  
   step = 1.0 / (double) num_steps;  
  
   #pragma omp parallel for reduction(+:sum) private(x)  
   for (i = 1; i <= num_steps; i++) {  
      x = (i - 0.5) * step;  
      sum = sum + 4.0 / (1.0 + x*x);  
   }  
  
   pi = step * sum;  
   return pi;  
}  
  
int main(int argc, char* argv[]) {  
   double   d;  
   int n = 1000000;  
  
   if (argc > 1)  
      n = atoi(argv[1]);  
  
   dwStart = GetTickCount();  
   d = test2(n);  
   printf_s("For %d steps, pi = %.15f, %d milliseconds\n", n, d, GetTickCount() - dwStart);  
  
   dwStart = GetTickCount();  
   d = test2(n);  
   printf_s("For %d steps, pi = %.15f, %d milliseconds\n", n, d, GetTickCount() - dwStart);  
}  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)