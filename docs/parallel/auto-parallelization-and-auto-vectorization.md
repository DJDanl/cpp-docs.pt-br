---
title: Paralelização automática e vetorização automática
ms.date: 11/04/2016
ms.assetid: ec71583a-287b-4599-8767-1d255e080fe3
ms.openlocfilehash: adc0dd9346cc2850b02e01804e26044c367f2d14
ms.sourcegitcommit: fcc3aeb271449f8be80348740cffef39ba543407
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2020
ms.locfileid: "82538621"
---
# <a name="auto-parallelization-and-auto-vectorization"></a>Paralelização automática e vetorização automática

Auto-paralelizador automático e auto-Vetorizador automático são projetados para fornecer ganhos de desempenho automáticos para loops em seu código.

## <a name="auto-parallelizer"></a>Paralelizador automático automático

A opção de compilador [/Qpar](../build/reference/qpar-auto-parallelizer.md) permite a *paralelização automática* de loops em seu código. Quando você especifica esse sinalizador sem alterar o código existente, o compilador avalia o código para localizar loops que podem se beneficiar da paralelização. Como ele pode encontrar loops que não fazem muito trabalho e, portanto, não se beneficiará da paralelização e, como toda a paralelização desnecessária pode conceberár a geração de um pool de threads, uma sincronização extra ou outro processamento que tende a reduzir o desempenho em vez de melhorá-lo, o compilador é conservador na seleção dos loops que ele paralelize. Por exemplo, considere o exemplo a seguir no qual o limite superior do loop não é conhecido no momento da compilação:

```cpp
void loop_test(int u) {
   for (int i=0; i<u; ++i)
      A[i] = B[i] * C[i];
}
```

Como `u` pode ser um valor pequeno, o compilador não irá paralelizar automaticamente esse loop. No entanto, você ainda pode querer que ele seja paralelizado `u` porque sabe que sempre será grande. Para habilitar a paralelização automática, especifique [#pragma loop (hint_parallel (n))](../preprocessor/loop.md), em que `n` é o número de threads para colocar em paralelo. No exemplo a seguir, o compilador tentará paralelizar o loop entre 8 threads.

```cpp
void loop_test(int u) {
#pragma loop(hint_parallel(8))
   for (int i=0; i<u; ++i)
      A[i] = B[i] * C[i];
}
```

Assim como acontece com todas as [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), também `__pragma(loop(hint_parallel(n)))` há suporte para a sintaxe de pragma alternativa.

Há alguns loops que o compilador não pode paralelizar, mesmo que você queira fazê-lo. Aqui está um exemplo:

```cpp
#pragma loop(hint_parallel(8))
for (int i=0; i<upper_bound(); ++i)
    A[i] = B[i] * C[i];
```

A função `upper_bound()` pode mudar toda vez que for chamada. Como o limite superior não pode ser conhecido, o compilador pode emitir uma mensagem de diagnóstico que explica por que ele não pode paralelizar esse loop. O exemplo a seguir demonstra um loop que pode ser paralelizado, um loop que não pode ser paralelizado, a sintaxe do compilador a ser usada no prompt de comando e a saída do compilador para cada opção de linha de comando:

```cpp
int A[1000];
void test() {
#pragma loop(hint_parallel(0))
    for (int i=0; i<1000; ++i) {
        A[i] = A[i] + 1;
    }

    for (int i=1000; i<2000; ++i) {
        A[i] = A[i] + 1;
    }
}
```

Compilando usando este comando:

`cl d:\myproject\mylooptest.cpp /O2 /Qpar /Qpar-report:1`

produz esta saída:

```Output
--- Analyzing function: void __cdecl test(void)
d:\myproject\mytest.cpp(4) : loop parallelized
```

Compilando usando este comando:

`cl d:\myproject\mylooptest.cpp /O2 /Qpar /Qpar-report:2`

produz esta saída:

```Output
--- Analyzing function: void __cdecl test(void)
d:\myproject\mytest.cpp(4) : loop parallelized
d:\myproject\mytest.cpp(4) : loop not parallelized due to reason '1008'
```

Observe a diferença na saída entre as duas opções diferentes do [/Qpar-Report (nível de relatório do paralelizador automático automático)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md) . `/Qpar-report:1`gera mensagens paralelizador automático somente para loops que são paralelizados com êxito. `/Qpar-report:2`gera mensagens paralelizador automático para parallelizations de loop com e sem êxito.

Para obter mais informações sobre códigos de motivo e mensagens, consulte [mensagens vetorizador automático e paralelizador automático](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).

## <a name="auto-vectorizer"></a>Vetorizador automático automático

O Vetorizador automático analisa loops em seu código e usa os registros de vetor e as instruções no computador de destino para executá-los, se possível. Isso pode melhorar o desempenho do seu código. O compilador tem como alvo as instruções SSE2, AVX e AVX2 nos processadores Intel ou AMD, ou as instruções NEON em processadores ARM, de acordo com o comutador [/Arch](../build/reference/arch-minimum-cpu-architecture.md) .

O Vetorizador automático automático pode gerar instruções diferentes das `/arch` especificadas pela opção. Essas instruções são protegidas por uma verificação de tempo de execução para garantir que o código ainda seja executado corretamente. Por exemplo, quando você compila `/arch:SSE2`, as instruções do SSE 4.2 podem ser emitidas. Uma verificação de tempo de execução verifica se o SSE 4.2 está disponível no processador de destino e salta para uma versão não SSE 4.2 do loop se o processador não oferecer suporte a essas instruções.

Por padrão, o Vetorizador automático automático está habilitado. Se você quiser comparar o desempenho do seu código em Vetorização, poderá usar [#pragma loop (no_vector)](../preprocessor/loop.md) para desabilitar a vetorização de qualquer loop especificado.

```cpp
#pragma loop(no_vector)
for (int i = 0; i < 1000; ++i)
   A[i] = B[i] + C[i];
```

Assim como acontece com todas as [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), também `__pragma(loop(no_vector))` há suporte para a sintaxe de pragma alternativa.

Assim como ocorre com o paralelizador automático automático, você pode especificar a opção de linha de comando [/Qvec-Report (auto-vetorizador automático Reporting Level)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md) para relatar somente loops vetorizados`/Qvec-report:1`com êxito — ou ambos loops vetorizados com êxito e sem êxito`/Qvec-report:2`—).

Para obter mais informações sobre códigos de motivo e mensagens, consulte [mensagens vetorizador automático e paralelizador automático](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).

Para ver um exemplo que mostra como o vetorizador automático funciona na prática, consulte [Austin do projeto parte 2 de 6: rotação de página](https://devblogs.microsoft.com/cppblog/project-austin-part-2-of-6-page-curling/)

## <a name="see-also"></a>Confira também

[loop](../preprocessor/loop.md)<br/>
[Programação paralela em código nativo](/archive/blogs/nativeconcurrency)<br/>
[/Qpar (auto-paralelizador automático)](../build/reference/qpar-auto-parallelizer.md)<br/>
[/Qpar-Report (nível de relatório do paralelizador automático automático)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md)<br/>
[/Qvec-Report (nível de relatório do Vetorizador automático automático)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md)<br/>
[Mensagens do vetorizador e do paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md)
