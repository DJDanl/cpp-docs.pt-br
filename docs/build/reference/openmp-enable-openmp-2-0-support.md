---
title: -openmp (Habilitar suporte a OpenMP 2.0) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /openmp
- VC.Project.VCCLCompilerTool.OpenMP
dev_langs: C++
helpviewer_keywords:
- /openmp compiler option [C++]
- -openmp compiler option [C++]
ms.assetid: 9082b175-18d3-4378-86a7-c0eb95664e13
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a8d3aaeb5d3e71dfced4bf78384a62898d99a5ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="openmp-enable-openmp-20-support"></a>/openmp (habilitar suporte a OpenMP 2.0)
Faz com que o compilador a processar `#pragma` [omp](../../preprocessor/omp.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/openmp  
```  
  
## <a name="remarks"></a>Comentários  
 `#pragma omp`é usado para especificar [diretivas](../../parallel/openmp/reference/openmp-directives.md) e [cláusulas](../../parallel/openmp/reference/openmp-clauses.md). Se **/openmp** não for especificado em uma compilação, o compilador ignora diretivas e cláusulas OpenMP. [Função OpenMP](../../parallel/openmp/reference/openmp-functions.md) chamadas são processadas pelo mesmo-se compilador **/openmp** não for especificado.  
  
 Um aplicativo compilado com **/openmp** e usando o [bibliotecas](../../parallel/openmp/reference/openmp-libraries.md) só pode ser executado no Windows 2000 ou sistemas operacionais posteriores.  
  
 Os aplicativos compilados com **/openmp** e **/clr** só pode ser executado em um processo de domínio de aplicativo único; não há suporte para vários domínios de aplicativo. Ou seja, quando o construtor de módulo (. cctor) é executado, ele detectará o processo é compilado com **/openmp** e se o aplicativo está sendo carregado em um tempo de execução não padrão. Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md), [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md), e [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).  
  
 Se você tentar carregar um aplicativo compilado com **/openmp** e **/clr** em um domínio de aplicativo não padrão, um <xref:System.TypeInitializationException> exceção será lançada fora do depurador e um OpenMPWithMultipleAppdomainsException exceção será lançada no depurador.  
  
 Essas exceções também podem ser geradas nas seguintes situações:  
  
-   Se seu aplicativo compilado com **/clr**, mas não com **/openmp**, é carregado em um domínio de aplicativo não padrão, mas em que o processo inclui um aplicativo que foi compilado com **/ OpenMP**.  
  
-   Se você passar o **/clr** aplicativo a um utilitário, como regasm.exe ([Regasm.exe (ferramenta de registro de Assembly)](/dotnet/framework/tools/regasm-exe-assembly-registration-tool)), que carrega seus assemblies de destino em um domínio de aplicativo não padrão.  
  
 Segurança de acesso ao código do common language runtime não funciona em regiões OpenMP. Se você aplicar um atributo de segurança de acesso de código CLR fora de uma região parallel, ele não será em vigor na região paralela.  
  
 O Microsoft avisa que não gravar **/openmp** aplicativos que permite parcialmente confiável chamadores, usando <xref:System.Security.AllowPartiallyTrustedCallersAttribute>, ou quaisquer atributos de segurança de acesso do código CLR.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **C/C++** nó.  
  
4.  Selecione o **idioma** página de propriedades.  
  
5.  Modificar o **suporte OpenMP** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OpenMP%2A>.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra alguns dos efeitos de inicialização threadpool versus usando o threadpool depois que ele iniciado. Supondo que o x64, núcleo único, processador duplo threadpool leva aproximadamente 16 ms para inicialização. Depois que embora há muito pouco custo para o threadpool.  
  
 Quando você compila com **/openmp**, a segunda chamada para test2 nunca será executado mais tempo do que se você compilar com **/openmp-**, pois não há nenhuma inicialização threadpool. Em iterações de um milhão de **/openmp** versão é mais rápido do que o **/openmp-** versão para a segunda chamada para test2 e em 25 iterações **/openmp-** e **/openmp** versões register menor do que a granularidade do relógio.  
  
 Portanto, se você tiver apenas um loop em seu aplicativo e ele é executado em menos de 15 ms (ajustado para a sobrecarga aproximada em seu computador), **/openmp** pode não ser apropriado, mas se for mais do que isso, você talvez queira considerar usando **/openmp**.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)