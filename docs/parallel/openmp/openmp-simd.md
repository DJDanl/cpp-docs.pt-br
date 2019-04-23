---
title: Extensão SIMD
ms.date: 03/20/2019
helpviewer_keywords:
- SIMD
- OpenMP in Visual C++, new features
- explicit parallelization, new features
ms.openlocfilehash: 52402aa553c6d68d3073aba26ecac7b784522ee9
ms.sourcegitcommit: 14b292596bc9b9b883a9c58cd3e366b282a1f7b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2019
ms.locfileid: "60125167"
---
# <a name="simd-extension"></a>Extensão SIMD

O Visual C++ atualmente dá suporte a OpenMP 2.0 padrão, no entanto, o Visual Studio de 2019 agora também oferece a funcionalidade SIMD.

> [!NOTE]
> Para usar SIMD, compilar com o `-openmp:experimental` comutador que habilita recursos de OpenMP adicionais não disponíveis ao usar o `-openmp` alternar.
>
> O `-openmp:experimental` incorporou switch `-openmp`, que significa que todos os recursos do OpenMP 2.0 estão incluídos no seu uso.

Para obter mais informações, consulte [SIMD extensão para C++ OpenMP no Visual Studio](https://devblogs.microsoft.com/cppblog/simd-extension-to-c-openmp-in-visual-studio/).

## <a name="openmp-simd-in-visual-c"></a>SIMD OpenMP no VisualC++

OpenMP SIMD, introduzido no 4.0 OpenMP standard, fazer loops amigável para o vetor de destinos. Usando o `simd` diretiva antes de um loop, o compilador pode ignorar as dependências de vetor, faça loop como vetor amigável quanto possível e respeita a intenção dos usuários para ter várias iterações do loop executadas simultaneamente.

```c
    #pragma omp simd
    for (i = 0; i < count; i++)
    {
        a[i] = a[i-1] + 1;
        b[i] = *c + 1;
        bar(i);
    }
```

O Visual C++ fornece como semelhante pragmas de loop não OpenMP `#pragma vector` e `#pragma ivdep`, no entanto, com o OpenMP SIMD, o compilador pode fazer mais, como:

- Sempre é permitido para ignorar as dependências de vetor presente.
- `/fp:fast` está habilitado dentro do loop.
- Loops externas e loops com chamadas de função são amigável para o vetor.
- Loops aninhados podem ser Unidos em um loop e feitos amigável para o vetor.
- Aceleração híbrida com `#pragma omp for simd` para habilitar os vetores de multithreading e refinados de alta granularidade.  

Loops de vetor amigável, o compilador permanece sem confirmação, a menos que você use uma opção de log do vetor de suporte:

```cmd
    cl -O2 -openmp:experimental -Qvec-report:2 mycode.cpp
```

```Output
    mycode.cpp(84) : info C5002: Omp simd loop not vectorized due to reason '1200'
    mycode.cpp(90) : info C5002: Omp simd loop not vectorized due to reason '1200'
    mycode.cpp(96) : info C5001: Omp simd loop vectorized
```

Loops não amigáveis de vetor, o compilador emite cada uma mensagem:

```cmd
    cl -O2 -openmp:experimental mycode.cpp
```

```Output
    mycode.cpp(84) : info C5002: Omp simd loop not vectorized due to reason '1200'
    mycode.cpp(90) : info C5002: Omp simd loop not vectorized due to reason '1200'
```

### <a name="clauses"></a>Cláusulas

A diretiva de OpenMP SIMD também pode executar as seguintes cláusulas para aprimorar o vetor de suporte:

|Diretiva|Descrição|
|---|---|
|`simdlen(length)`|Especifique o número de pistas de vetor.|
|`safelen(length)`|Especifique a distância de dependência do vetor.|
|`linear(list[ : linear-step]`)|O mapeamento linear de variável de indução do loop para assinatura de matriz.|
|`aligned(list[ : alignment])`|O alinhamento dos dados.|
|`private(list)`|Especifique a privatização de dados.|
|`lastprivate(list)`|Especifique a privatização de dados com o valor final da última iteração.|
|`reduction(reduction-identifier:list)`|Especifica as operações de redução personalizado.|
|`collapse(n)`|Aninhamento de loops de união.|

> [!NOTE]
> Cláusulas SIMD não eficiente são analisadas e ignoradas pelo compilador, com um aviso.
>
> Por exemplo, use os seguintes problemas de código um aviso:
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
  
A diretiva de OpenMP SIMD fornece aos usuários uma maneira para ditar o compilador verifique loops vetor compatível com. Anotando um loop com a diretiva de OpenMP SIMD, os usuários pretendem ter várias iterações do loop executadas simultaneamente.

Por exemplo, o seguinte loop é anotado com a diretiva de OpenMP SIMD. Não há nenhum perfeito paralelismo entre iterações do loop, pois há uma dependência com versões anteriores do [i] para [i-1], mas devido à diretiva SIMD que o compilador ainda tem permissão para pacote de iterações consecutivas da primeira instrução em uma instrução de vetor e executar -los em paralelo.

```c
    #pragma omp simd
    for (i = 0; i < count; i++)
    {
        a[i] = a[i-1] + 1;
        b[i] = *c + 1;
        bar(i);
    }
```

Portanto, é o seguinte formato de vetor transformado do loop **legal** porque o compilador mantém o comportamento sequencial de cada iteração do loop original. Em outras palavras, `a[i]` é executado após `a[-1]`, `b[i]` após `a[i]` e a chamada para `bar` acontece pela última vez.

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

Ele tem **não legais** para mover a referência de memória `*c` o loop se ele pode ser alias com `a[i]` ou `b[i]`. Também não é legal para reordenar as instruções dentro de uma iteração original se ele quebrar a dependência sequencial. Por exemplo, o seguinte loop transformado não é legal:

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

## <a name="see-also"></a>Consulte também

[/openmp (habilitar suporte para OpenMP 2.0)](../../build/reference/openmp-enable-openmp-2-0-support.md)<br/>
