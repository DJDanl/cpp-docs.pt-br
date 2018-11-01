---
title: /openmp (habilitar suporte a OpenMP 2.0)
ms.date: 11/04/2016
f1_keywords:
- /openmp
- VC.Project.VCCLCompilerTool.OpenMP
helpviewer_keywords:
- /openmp compiler option [C++]
- -openmp compiler option [C++]
ms.assetid: 9082b175-18d3-4378-86a7-c0eb95664e13
ms.openlocfilehash: 03992a0e8eef3ba9b2683ecb87809b53cb551636
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50518060"
---
# <a name="openmp-enable-openmp-20-support"></a>/openmp (habilitar suporte a OpenMP 2.0)

Faz com que o compilador processar `#pragma` [omp](../../preprocessor/omp.md).

## <a name="syntax"></a>Sintaxe

```
/openmp
```

## <a name="remarks"></a>Comentários

`#pragma omp` é usado para especificar [diretivas](../../parallel/openmp/reference/openmp-directives.md) e [cláusulas](../../parallel/openmp/reference/openmp-clauses.md). Se **/openmp** não for especificado em uma compilação, o compilador ignora cláusulas e diretivas OpenMP. [Função OpenMP](../../parallel/openmp/reference/openmp-functions.md) chamadas são processadas pelo mesmo-se compilador **/openmp** não for especificado.

Aplicativos compilados com **/openmp** e **/clr** só pode ser executado em um processo de domínio de aplicativo único; não há suporte para vários domínios de aplicativo. Ou seja, quando o construtor de módulo (. cctor) é executado, ele detectará o processo é compilado com **/openmp** e se o aplicativo está sendo carregado em um tempo de execução não padrão. Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md), [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md), e [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).

Se você tentar carregar um aplicativo compilado com **/openmp** e **/clr** em um domínio de aplicativo não padrão, um <xref:System.TypeInitializationException> exceção será lançada fora do depurador e um OpenMPWithMultipleAppdomainsException exceção será lançada no depurador.

Essas exceções também podem ser geradas nas seguintes situações:

- Se seu aplicativo compilado com **/clr**, mas não com **/openmp**, é carregado em um domínio de aplicativo não padrão, mas em que o processo inclui um aplicativo que foi compilado com **/ OpenMP**.

- Se você passar seu **/clr** aplicativo a um utilitário, como regasm.exe ([Regasm.exe (ferramenta de registro de Assembly)](/dotnet/framework/tools/regasm-exe-assembly-registration-tool)), que carrega seus assemblies de destino em um domínio de aplicativo não padrão.

Segurança de acesso do código do common language runtime não funciona nas regiões do OpenMP. Se você aplicar um atributo de segurança de acesso de código do CLR fora de uma região paralela, ficará em vigor na região paralela.

Microsoft avisa que não gravar **/openmp** aplicativos que permite parcialmente confiáveis chamadores, usando <xref:System.Security.AllowPartiallyTrustedCallersAttribute>, ou quaisquer atributos de segurança de acesso do código CLR.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **C/C++** nó.

1. Selecione o **linguagem** página de propriedades.

1. Modificar a **suporte para OpenMP** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OpenMP%2A>.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra alguns dos efeitos de inicialização de threadpool em vez de usar threadpool depois de iniciado para cima. Supondo que um x64, único núcleo, o pool de threads de processador duplo leva aproximadamente 16 ms para inicialização. Depois no entanto há muito pouco custo para o pool de threads.

Quando você compila com **/openmp**, a segunda chamada para test2 nunca é executado mais tempo do que se você compilar com **/openmp-**, pois não há nenhuma inicialização threadpool. Em iterações de um milhão de **/openmp** versão é mais rápido do que o **/openmp-** versão para a segunda chamada para test2 e em 25 iterações **/openmp-** e **/openmp** versões register menor do que a granularidade de relógio.

Portanto, se você tiver apenas um loop em seu aplicativo e ele é executado em menos de 15 ms (ajustada para a sobrecarga aproximada em seu computador), **/openmp** pode não ser apropriado, mas se for nada mais do que isso, você talvez queira considerar o uso de **/openmp**.

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

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)