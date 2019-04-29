---
title: /OpenMP (Habilitar suporte a OpenMP)
ms.date: 04/15/2019
f1_keywords:
- /openmp
- VC.Project.VCCLCompilerTool.OpenMP
helpviewer_keywords:
- /openmp compiler option [C++]
- -openmp compiler option [C++]
ms.assetid: 9082b175-18d3-4378-86a7-c0eb95664e13
ms.openlocfilehash: caa06d89c590abd2b3a74a5a6b118d6ba4acd910
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320208"
---
# <a name="openmp-enable-openmp-support"></a>/OpenMP (Habilitar suporte a OpenMP)

Faz com que o compilador processar [ `#pragma omp` ](../../preprocessor/omp.md) diretivas para dar suporte a OpenMP.

## <a name="syntax"></a>Sintaxe

::: moniker range=">= vs-2019"

> **/openmp**\[**:**__experimental__]

::: moniker-end

::: moniker range="<= vs-2017"

> **/openmp**

::: moniker-end

## <a name="remarks"></a>Comentários

`#pragma omp` é usado para especificar [diretivas](../../parallel/openmp/reference/openmp-directives.md) e [cláusulas](../../parallel/openmp/reference/openmp-clauses.md). Se **/openmp** não for especificado em uma compilação, o compilador ignora cláusulas e diretivas OpenMP. [Função OpenMP](../../parallel/openmp/reference/openmp-functions.md) chamadas são processadas pelo mesmo-se compilador **/openmp** não for especificado.

::: moniker range=">= vs-2019"

O C++ no momento, o compilador é compatível com o padrão de OpenMP 2.0. No entanto, o Visual Studio de 2019 agora também oferece funcionalidade SIMD. Para usar SIMD, compilar, usando o **/openmp: experimental** opção. Essa opção permite que os dois recursos comuns de OpenMP e SIMD OpenMP recursos adicionais não disponíveis ao usar o **/openmp** alternar.

::: moniker-end

Aplicativos compilados usando ambos **/openmp** e **/clr** só pode ser executado em um processo de domínio de aplicativo único. Não há suporte para vários domínios de aplicativo. Ou seja, quando o construtor de módulo (`.cctor`) é executado, ele detecta se o processo é compilado usando **/openmp**, e se o aplicativo for carregado em um tempo de execução não padrão. Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md), [/clr (compilação de tempo de execução de linguagem comum)](clr-common-language-runtime-compilation.md), e [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).

Se você tentar carregar um aplicativo compilado usando ambos **/openmp** e **/clr** em um domínio de aplicativo não padrão, uma <xref:System.TypeInitializationException> exceção for lançada fora do depurador e um `OpenMPWithMultipleAppdomainsException` exceção é lançada no depurador.

Essas exceções também podem ser geradas nas seguintes situações:

- Se seu aplicativo for compilado usando **/clr** , mas não **/openmp**e é carregado em um domínio de aplicativo não padrão, em que o processo inclui um aplicativo compilado usando **/openmp**.

- Se você passar seu **/clr** aplicativo a um utilitário, como [regasm.exe](/dotnet/framework/tools/regasm-exe-assembly-registration-tool), que carrega seus assemblies de destino em um domínio de aplicativo não padrão.

Segurança de acesso do código do common language runtime não funciona nas regiões do OpenMP. Se você aplicar um atributo de segurança de acesso de código do CLR fora de uma região paralela, ficará em vigor na região paralela.

A Microsoft não recomenda que você escreva **/openmp** aplicativos que permitem parcialmente confiável para os chamadores. Não use <xref:System.Security.AllowPartiallyTrustedCallersAttribute>, ou quaisquer atributos de segurança de acesso do código CLR.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o **propriedades de configuração** > **C /C++** > **idioma** página de propriedades.

1. Modificar a **suporte para OpenMP** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OpenMP%2A>.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra alguns dos efeitos de inicialização do pool de thread em vez de usar o pool de segmentos, depois de iniciada. Supondo que um x64, núcleo único, processador duplo, o pool de threads leva aproximadamente 16 ms para ser inicializado. Depois disso, não há é pouco custo extra para o pool de threads.

Quando você compila usando **/openmp**, a segunda chamada para test2 nunca é executado mais tempo do que se você compilar usando **/openmp-**, pois não há nenhuma inicialização do pool de thread. Em um milhão de iterações, o **/openmp** versão é mais rápido do que o **/openmp-** versão para a segunda chamada para test2. Em 25 iterações, ambos **/openmp-** e **/openmp** versões register menor do que a granularidade de relógio.

Se você tiver apenas um loop em seu aplicativo e ele é executado em menos de 15 ms (ajustadas para a sobrecarga aproximada em seu computador), **/openmp** pode não ser apropriado. Se ele for maior, você talvez queira considerar o uso **/openmp**.

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

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md) \
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md) \
[OpenMP no MSVC](../../parallel/openmp/openmp-in-visual-cpp.md)
