---
title: /openmp (Ativar suporte openMP)
ms.date: 04/15/2019
f1_keywords:
- /openmp
- VC.Project.VCCLCompilerTool.OpenMP
helpviewer_keywords:
- /openmp compiler option [C++]
- -openmp compiler option [C++]
ms.assetid: 9082b175-18d3-4378-86a7-c0eb95664e13
ms.openlocfilehash: d3454650bfaaacd756e5cfc73df056441a39f5ac
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336199"
---
# <a name="openmp-enable-openmp-support"></a>/openmp (Ativar suporte openMP)

Faz com que o [`#pragma omp`](../../preprocessor/omp.md) compilador processe diretivas em apoio ao OpenMP.

## <a name="syntax"></a>Sintaxe

::: moniker range=">= vs-2019"

> **/openmp**\[**:**__experimental__]

::: moniker-end

::: moniker range="<= vs-2017"

> **/openmp**

::: moniker-end

## <a name="remarks"></a>Comentários

`#pragma omp`é usado para especificar [Diretivas](../../parallel/openmp/reference/openmp-directives.md) e [Cláusulas](../../parallel/openmp/reference/openmp-clauses.md). Se **/openmp** não for especificado em uma compilação, o compilador ignorará as cláusulas e diretivas do OpenMP. As chamadas [da função OpenMP](../../parallel/openmp/reference/openmp-functions.md) são processadas pelo compilador, mesmo que **/openmp** não esteja especificado.

::: moniker range=">= vs-2019"

O compilador C++ atualmente suporta o padrão OpenMP 2.0. No entanto, o Visual Studio 2019 também agora oferece funcionalidade SIMD. Para usar o SIMD, compile usando a opção **/openmp:experimental.** Esta opção permite tanto os recursos usuais do OpenMP quanto os recursos adicionais do OpenMP SIMD não disponíveis ao usar o switch **/openmp.**

::: moniker-end

Os aplicativos compilados usando **o openmp** e **o /clr** só podem ser executados em um único processo de domínio de aplicativo. Vários domínios de aplicativos não são suportados. Ou seja, quando o`.cctor`construtor do módulo () é executado, ele detecta se o processo é compilado usando **/openmp**, e se o aplicativo é carregado em um tempo de execução não padrão. Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md), [/clr (Common Language Runtime Compilation)](clr-common-language-runtime-compilation.md)e [Initialization of Mixed Assemblies](../../dotnet/initialization-of-mixed-assemblies.md).

Se você tentar carregar um aplicativo compilado usando **/openmp** **e/clr** em <xref:System.TypeInitializationException> um domínio de aplicativo não padrão, uma exceção será lançada fora do depurador e uma `OpenMPWithMultipleAppdomainsException` exceção será lançada no depurador.

Essas exceções também podem ser levantadas nas seguintes situações:

- Se o aplicativo for compilado usando **/clr,** mas não **/openmp,** e for carregado em um domínio de aplicativo não padrão, onde o processo inclui um aplicativo compilado usando **/openmp**.

- Se você passar seu aplicativo **/clr** para um utilitário, como [regasm.exe](/dotnet/framework/tools/regasm-exe-assembly-registration-tool), que carrega seus conjuntos de destino em um domínio de aplicativo não padrão.

O segurança de acesso ao código do idioma comum não funciona em regiões OpenMP. Se você aplicar um atributo de segurança de acesso a código CLR fora de uma região paralela, ele não estará em vigor na região paralela.

A Microsoft não recomenda que você escreva **/openmp** apps que permitam chamadas parcialmente confiáveis. Não use <xref:System.Security.AllowPartiallyTrustedCallersAttribute>ou quaisquer atributos de segurança de acesso a código CLR.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda a página **de propriedade de configuração** > **C/C++** > **Idioma.**

1. Modifique a propriedade **OpenMP Support.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OpenMP%2A>.

## <a name="example"></a>Exemplo

A amostra a seguir mostra alguns dos efeitos da inicialização do pool de segmentos versus o uso do pool de segmentos depois de iniciado. Assumindo um x64, núcleo único, processador duplo, o pool de roscas leva cerca de 16 ms para iniciar. Depois disso, há pouco custo extra para a piscina de fios.

Quando você compila usando **/openmp**, a segunda chamada para test2 nunca é executada por mais tempo do que se você compilar usando **/openmp-**, pois não há inicialização do pool de segmentos. Com um milhão de iterações, a versão **/openmp** é mais rápida que a versão **/openmp** para a segunda chamada para teste2. Com 25 iterações, as versões **openmp** e **/openmp** registram menos que a granularidade do relógio.

Se você tiver apenas um loop em sua aplicação e ele for executado em menos de 15 ms (ajustado para a sobrecarga aproximada em sua máquina), **/openmp** pode não ser apropriado. Se for mais alto, você pode querer considerar o uso **de /openmp**.

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

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md) \
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md) \
[OpenMP no MSVC](../../parallel/openmp/openmp-in-visual-cpp.md)
