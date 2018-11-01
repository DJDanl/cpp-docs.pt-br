---
title: Paralelização automática e vetorização automática
ms.date: 11/04/2016
ms.assetid: ec71583a-287b-4599-8767-1d255e080fe3
ms.openlocfilehash: 06ab255e7769bfa56d5a8d22cdbe19d415ce6b31
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618330"
---
# <a name="auto-parallelization-and-auto-vectorization"></a>Paralelização automática e vetorização automática

Autoparalelizador e o Autovetorizador são projetados para fornecer ganhos de desempenho automática de loops no código.

## <a name="auto-parallelizer"></a>Paralelizador automático

O [/Qpar](../build/reference/qpar-auto-parallelizer.md) habilita a opção de compilador *paralelização automática* de loops em seu código. Quando você especifica esse sinalizador sem alterar seu código existente, o compilador avalia o código para localizar loops que podem se beneficiar de paralelização. Porque ele pode localizar loops que não faz muita coisa trabalhar e, portanto, não se beneficiar da paralelização e porque cada paralelização desnecessária pode engender a geração de um pool de threads, sincronização adicional ou outro processamento que seria tendem a lenta desempenho, em vez de melhorá-lo, o compilador é conservadora na seleção dos loops que ele processa. Por exemplo, considere o exemplo a seguir em que o limite superior do loop não é conhecido em tempo de compilação:

```cpp
void loop_test(int u) {
   for (int i=0; i<u; ++i)
      A[i] = B[i] * C[i];
}
```

Porque `u` poderia ser um valor pequeno, o compilador não paraleliza automaticamente esse loop. No entanto, talvez ainda queira em paralelo porque você sabe que `u` sempre será grande. Para habilitar a paralelização automática, especifique [#pragma loop(hint_parallel(n))](../preprocessor/loop.md), onde `n` é o número de threads para paralelizar em. No exemplo a seguir, o compilador tentará paralelizar o loop em 8 threads.

```cpp
void loop_test(int u) {
#pragma loop(hint_parallel(8))
   for (int i=0; i<u; ++i)
      A[i] = B[i] * C[i];
}
```

Assim como acontece com todos os [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), a sintaxe de pragma alternativo `__pragma(loop(hint_parallel(n)))` também tem suporte.

Há alguns loops em que o compilador não é possível paralelizar mesmo se você deseja que ele. Veja um exemplo:

```cpp
#pragma loop(hint_parallel(8))
for (int i=0; i<upper_bound(); ++i)
    A[i] = B[i] * C[i];
```

A função `upper_bound()` pode ser alterado toda vez que ele é chamado. Como o limite superior não pode ser conhecido, o compilador pode emitir uma mensagem de diagnóstico que explica por que ele não é possível paralelizar esse loop. O exemplo a seguir demonstra um loop que pode ser paralelizado, um loop que não pode ser colocado em paralelo, a sintaxe de compilador para usar no prompt de comando e a saída do compilador para cada opção de linha de comando:

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

Observe a diferença na saída entre os dois diferentes [/Qpar-report (nível de relatórios do Paralelizador automático)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md) opções. `/Qpar-report:1` gera mensagens de paralelizador somente para loops que são colocados em paralelo com êxito. `/Qpar-report:2` gera mensagens de paralelizador para ambos os parallelizations loop bem-sucedidas e malsucedidas.

Para obter mais informações sobre códigos de motivo e mensagens, consulte [mensagens do Vetorizador e Paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).

## <a name="auto-vectorizer"></a>Vetorizador automático

O Vetorizador automático analisa loops no código e usa os registros de vetor e as instruções no computador de destino para executá-los, se possível. Isso pode melhorar o desempenho do seu código. O compilador direciona as instruções SSE2, AVX e AVX2 em processadores Intel ou AMD ou as instruções de NEON em processadores ARM, acordo com o [/arch](../build/reference/arch-minimum-cpu-architecture.md) alternar.

O Vetorizador automático pode gerar instruções diferentes que o especificado pelo `/arch` alternar. Essas instruções são protegidas por uma verificação de tempo de execução para certificar-se de que código ainda seja executado corretamente. Por exemplo, quando você compila `/arch:SSE2`, instruções SSE4.2 podem ser emitidas. Uma verificação de tempo de execução verifica se SSE4.2 está disponível no processador de destino e salta para uma versão não SSE4.2 do loop, se o processador não oferece suporte a essas instruções.

Por padrão, o Vetorizador automático está habilitado. Se você quiser comparar o desempenho do seu código sob a vetorização, você pode usar [#pragma loop(no_vector)](../preprocessor/loop.md) para desativar a vetorização do loop qualquer determinado.

```cpp
#pragma loop(no_vector)
for (int i = 0; i < 1000; ++i)
   A[i] = B[i] + C[i];
```

Assim como acontece com todos os [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), a sintaxe de pragma alternativo `__pragma(loop(no_vector))` também tem suporte.

Como com o Paralelizador automático, você pode especificar o [/Qvec-report (nível de relatórios do Vetorizador automático)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md) opção de linha de comando para qualquer um de relatório com êxito vetorizado loops apenas —`/Qvec-report:1`— ou ambos com êxito e sem êxito vetorizado loops —`/Qvec-report:2`).

Para obter mais informações sobre códigos de motivo e mensagens, consulte [mensagens do Vetorizador e Paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).

Para obter um exemplo mostrando como o vetorizador funciona na prática, consulte [Project Austin parte 2 de 6: Ondulação de página](http://blogs.msdn.com/b/vcblog/archive/2012/09/27/10348494.aspx)

## <a name="see-also"></a>Consulte também

[loop](../preprocessor/loop.md)<br/>
[Programação paralela em código nativo](http://go.microsoft.com/fwlink/p/?linkid=263662)<br/>
[/Qpar (paralelizador automático)](../build/reference/qpar-auto-parallelizer.md)<br/>
[/Qpar-report (nível de relatórios do paralelizador automático)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md)<br/>
[/Qvec-report (nível de relatórios do vetorizador automático)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md)<br/>
[Mensagens do vetorizador e do paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md)