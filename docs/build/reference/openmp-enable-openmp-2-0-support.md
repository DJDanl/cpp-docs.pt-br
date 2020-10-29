---
title: /OpenMP (habilitar suporte de OpenMP)
ms.date: 04/15/2019
f1_keywords:
- /openmp
- VC.Project.VCCLCompilerTool.OpenMP
helpviewer_keywords:
- /openmp compiler option [C++]
- -openmp compiler option [C++]
ms.assetid: 9082b175-18d3-4378-86a7-c0eb95664e13
ms.openlocfilehash: 6bd1ffcd9b21bfe22ed9424ee77edf43100abf6c
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921224"
---
# <a name="openmp-enable-openmp-support"></a>/OpenMP (habilitar suporte de OpenMP)

Faz com que o compilador processe as [`#pragma omp`](../../preprocessor/omp.md) diretivas no suporte de OpenMP.

## <a name="syntax"></a>Syntax

::: moniker range=">= msvc-160"

> **/OpenMP** \[ **:**__experimental__ ]

::: moniker-end

::: moniker range="<= msvc-150"

> **/OpenMP**

::: moniker-end

## <a name="remarks"></a>Comentários

`#pragma omp` é usado para especificar [diretivas](../../parallel/openmp/reference/openmp-directives.md) e [cláusulas](../../parallel/openmp/reference/openmp-clauses.md). Se **/OpenMP** não for especificado em uma compilação, o compilador ignorará cláusulas e diretivas OpenMP. As chamadas de [função de OpenMP](../../parallel/openmp/reference/openmp-functions.md) são processadas pelo compilador, mesmo se **/OpenMP** não for especificado.

::: moniker range=">= msvc-160"

O compilador C++ atualmente dá suporte ao padrão de OpenMP 2,0. No entanto, o Visual Studio 2019 agora também oferece a funcionalidade SIMD. Para usar o SIMD, compile usando a opção **/OpenMP: experimental** . Essa opção habilita os recursos de OpenMP usuais e os recursos de OpenMP SIMD adicionais não disponíveis ao usar o comutador **/OpenMP** .

::: moniker-end

Os aplicativos compilados usando **/OpenMP** e **/CLR** só podem ser executados em um único processo de domínio de aplicativo. Não há suporte para vários domínios de aplicativo. Ou seja, quando o construtor do módulo ( `.cctor` ) é executado, ele detecta se o processo é compilado usando **/OpenMP** e se o aplicativo é carregado em um tempo de execução não padrão. Para obter mais informações, consulte [AppDomain](../../cpp/appdomain.md), [/CLR (compilação Common Language Runtime)](clr-common-language-runtime-compilation.md)e [inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).

Se você tentar carregar um aplicativo compilado usando **/OpenMP** e **/CLR** em um domínio de aplicativo não padrão, uma <xref:System.TypeInitializationException> exceção será lançada fora do depurador e uma `OpenMPWithMultipleAppdomainsException` exceção será lançada no depurador.

Essas exceções também podem ser geradas nas seguintes situações:

- Se seu aplicativo é compilado usando **/CLR** , mas não **/OpenMP** , e é carregado em um domínio de aplicativo não padrão, em que o processo inclui um aplicativo compilado usando **/OpenMP** .

- Se você passar seu aplicativo **/CLR** para um utilitário, como [regasm.exe](/dotnet/framework/tools/regasm-exe-assembly-registration-tool), que carrega seus assemblies de destino em um domínio de aplicativo não padrão.

A segurança de acesso ao código do Common Language Runtime não funciona em regiões de OpenMP. Se você aplicar um atributo de segurança de acesso ao código CLR fora de uma região paralela, ele não estará em vigor na região paralela.

A Microsoft não recomenda que você escreva aplicativos **/OpenMP** que permitam chamadores parcialmente confiáveis. Não use <xref:System.Security.AllowPartiallyTrustedCallersAttribute> nem qualquer atributo de segurança de acesso ao código CLR.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda a página de **Propriedades** de linguagem configuração do  >  **C/C++**  >  **Language** .

1. Modifique a propriedade de **suporte de OpenMP** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OpenMP%2A>.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra alguns dos efeitos da inicialização do pool de threads versus usando o pool de threads depois que ele é iniciado. Supondo que um processador x64, Single core, dual, o pool de threads leva cerca de 16 MS para iniciar. Depois disso, há pouco custo extra para o pool de threads.

Quando você compila usando **/OpenMP** , a segunda chamada para test2 nunca é executada mais do que se você compilar usando **/OpenMP-** , pois não há nenhuma inicialização do pool de threads. Em um milhão de iterações, a versão **/OpenMP** é mais rápida do que a versão **/OpenMP-** da segunda chamada para test2. A 25 iterações, as versões **/OpenMP-** e **/OpenMP** registram menos que a granularidade do relógio.

Se você tiver apenas um loop em seu aplicativo e ele for executado em menos de 15 ms (ajustado para a sobrecarga aproximada em seu computador), **/OpenMP** poderá não ser apropriado. Se for maior, talvez você queira considerar o uso de **/OpenMP** .

```cpp
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

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md) \
[Sintaxe de Command-Line do compilador MSVC](compiler-command-line-syntax.md) \
[OpenMP no MSVC](../../parallel/openmp/openmp-in-visual-cpp.md)
