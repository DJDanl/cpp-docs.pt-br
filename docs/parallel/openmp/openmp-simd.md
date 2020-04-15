---
title: Extensão SIMD
ms.date: 03/20/2019
helpviewer_keywords:
- SIMD
- OpenMP in Visual C++, new features
- explicit parallelization, new features
ms.openlocfilehash: 0a7f1142a3a432628795341f4885b76a5c144990
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366460"
---
# <a name="simd-extension"></a>Extensão SIMD

Visual C++ atualmente suporta o padrão OpenMP 2.0, porém o Visual Studio 2019 também agora oferece funcionalidade SIMD.

> [!NOTE]
> Para usar o SIMD, `-openmp:experimental` compile com o switch que `-openmp` permite recursos adicionais de OpenMP não disponíveis ao usar o switch.
>
> Os `-openmp:experimental` subsumos `-openmp`do switch, o que significa que todos os recursos do OpenMP 2.0 estão incluídos em seu uso.

Para obter mais informações, consulte [extensão SIMD para C++ OpenMP no Visual Studio](https://devblogs.microsoft.com/cppblog/simd-extension-to-c-openmp-in-visual-studio/).

## <a name="openmp-simd-in-visual-c"></a>OpenMP SIMD no Visual C++

OpenMP SIMD, introduzido no padrão OpenMP 4.0, tem como alvo fazer loops amigáveis ao vetor. Ao usar `simd` a diretiva antes de um loop, o compilador pode ignorar dependências vetoriais, tornar o loop o mais vetorial possível e respeitar a intenção dos usuários de executar várias iterações de loop simultaneamente.

```c
    #pragma omp simd
    for (i = 0; i < count; i++)
    {
        a[i] = a[i-1] + 1;
        b[i] = *c + 1;
        bar(i);
    }
```

Visual C++ fornece pragmas de loop `#pragma vector` `#pragma ivdep`não-OpenMP similares como e , no entanto, com OpenMP SIMD, o compilador pode fazer mais, como:

- Sempre permitido ignorar as atuais dependências vetoriais.
- `/fp:fast`está ativado dentro do loop.
- Loops externos e loops com chamadas de função são vetoriais.
- Loops aninhados podem ser coalescidos em um loop e tornados vetoriais amigáveis.
- Aceleração `#pragma omp for simd` híbrida com para permitir vetores multi-rosca de grãos grossos e de grãos finos.  

Para loops vetoriais, o compilador permanece silencioso a menos que você use um interruptor de log de suporte vetorial:

```cmd
    cl -O2 -openmp:experimental -Qvec-report:2 mycode.cpp
```

```Output
    mycode.cpp(84) : info C5002: Omp simd loop not vectorized due to reason '1200'
    mycode.cpp(90) : info C5002: Omp simd loop not vectorized due to reason '1200'
    mycode.cpp(96) : info C5001: Omp simd loop vectorized
```

Para loops não-vetoriais, o compilador emite cada uma mensagem:

```cmd
    cl -O2 -openmp:experimental mycode.cpp
```

```Output
    mycode.cpp(84) : info C5002: Omp simd loop not vectorized due to reason '1200'
    mycode.cpp(90) : info C5002: Omp simd loop not vectorized due to reason '1200'
```

### <a name="clauses"></a>Cláusulas

A diretiva OpenMP SIMD também pode tomar as seguintes cláusulas para melhorar o suporte ao vetor:

|Diretiva|Descrição|
|---|---|
|`simdlen(length)`|Especifique o número de faixas vetoriais.|
|`safelen(length)`|Especifique a distância de dependência vetorial.|
|`linear(list[ : linear-step]`)|O mapeamento linear da variável de indução de loop à assinatura do array.|
|`aligned(list[ : alignment])`|O alinhamento de dados.|
|`private(list)`|Especificar privatização de dados.|
|`lastprivate(list)`|Especificar a privatização de dados com valor final da última iteração.|
|`reduction(reduction-identifier:list)`|Especifique operações de redução personalizadas.|
|`collapse(n)`|Ninho de laço de coalescing.|

> [!NOTE]
> As cláusulas SIMD não eficazes são parsed e ignoradas pelo compilador com um aviso.
>
> Por exemplo, o uso do seguinte código emite um aviso:
>
> ```c
>    #pragma omp simd simdlen(8)
>    for (i = 0; i < count; i++)
>    {
>        a[i] = a[i-1] + 1;
>        b[i] = *c + 1;
>        bar(i);
>    }
> ```
>
> ```Output
>    warning C4849: OpenMP 'simdlen' clause ignored in 'simd' directive
> ```

### <a name="example"></a>Exemplo
  
A diretiva OpenMP SIMD fornece aos usuários uma maneira de ditar que o compilador torne os loops amigáveis aos vetores. Ao anotar um loop com a diretiva OpenMP SIMD, os usuários pretendem executar várias iterações de loop executadas simultaneamente.

Por exemplo, o loop a seguir é anotado com a diretiva OpenMP SIMD. Não há um paralelismo perfeito entre iterações de loop, uma vez que há uma dependência retrógrada de a[i] para a[i-1], mas por causa da diretiva SIMD o compilador ainda é permitido embalar iterações consecutivas da primeira instrução em uma instrução vetorial e executá-las em paralelo.

```c
    #pragma omp simd
    for (i = 0; i < count; i++)
    {
        a[i] = a[i-1] + 1;
        b[i] = *c + 1;
        bar(i);
    }
```

Portanto, a seguinte forma vetorial transformada do loop é **legal** porque o compilador mantém o comportamento seqüencial de cada iteração de loop original. Em outras `a[i]` palavras, `a[-1]`é `b[i]` executado `a[i]` depois , `bar` é depois e a chamada para acontecer por último.

```c
    for (i = 0; i < count; i+=4)
    {
        a[i:i+3] = a[i-1:i+2] + 1;
        b[i:i+3] = *c + 1;
        bar(i);
        bar(i+1);
        bar(i+2);
        bar(i+3);
    }
```

Não é **legal** mover a `*c` referência de memória para fora `a[i]` do `b[i]`loop se ela pode ter alias com ou . Também não é legal reordenar as declarações dentro de uma iteração original se ela quebrar a dependência sequencial. Por exemplo, o seguinte loop transformado não é legal:

```c
    c = b;
    t = *c;
    for (i = 0; i < count; i+=4)
    {
        a[i:i+3] = a[i-1:i+2] + 1;
        bar(i);            // illegal to reorder if bar[i] depends on b[i]
        b[i:i+3] = t + 1;  // illegal to move *c out of the loop
        bar(i+1);
        bar(i+2);
        bar(i+3);
    }
```

## <a name="see-also"></a>Confira também

[/openmp (habilitar suporte a OpenMP 2.0)](../../build/reference/openmp-enable-openmp-2-0-support.md)<br/>
