---
title: Melhores práticas de otimização
ms.date: 05/06/2019
helpviewer_keywords:
- C++, optimization
- optimization, best practices
ms.assetid: f3433148-7255-4ca6-8a4f-7c31aac88508
ms.openlocfilehash: 425fa0bb6b7aab502ce493ced8b587fad8ce59a8
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833342"
---
# <a name="optimization-best-practices"></a>Melhores práticas de otimização

Este documento descreve algumas práticas recomendadas para otimizar programas em C++ no Visual Studio.

## <a name="compiler-and-linker-options"></a>Opções do compilador e do vinculador

### <a name="profile-guided-optimization"></a>Otimização Guiada por perfil

O Visual Studio dá suporte à PGO ( *otimização guiada por perfil* ). Essa otimização usa dados de perfil de execuções de treinamento de uma versão instrumentada de um aplicativo para conduzir a otimização posterior do aplicativo. O uso de PGO pode ser demorado, portanto, pode não ser algo que todos os desenvolvedores usem, mas recomendamos o uso de PGO para a versão final da compilação de um produto. Para obter mais informações, confira [Otimizações guiadas por perfil](profile-guided-optimizations.md).

Além disso, a *otimização do programa inteiro* (também conhecido como geração de código de tempo de vinculação) e as **`/O1`** **`/O2`** otimizações foram aprimoradas. Em geral, um aplicativo compilado com uma dessas opções será mais rápido do que o mesmo aplicativo compilado com um compilador anterior.

Para obter mais informações, consulte [ `/GL` (otimização do programa inteiro)](reference/gl-whole-program-optimization.md) e [ `/O1` , `/O2` (tamanho minimizado, velocidade maximizada)](reference/o1-o2-minimize-size-maximize-speed.md).

### <a name="which-level-of-optimization-to-use"></a>Qual nível de otimização usar

Se possível, as compilações de versão final devem ser compiladas com otimizações guiadas por perfil. Se não for possível criar com PGO, seja devido à infraestrutura insuficiente para executar as compilações instrumentadas ou não ter acesso a cenários, sugerimos criar com otimização completa do programa.

A **`/Gy`** opção também é muito útil. Ele gera um COMDAT separado para cada função, dando mais flexibilidade ao vinculador quando se trata de remover COMDATs não referenciados e dobramento COMDAT. A única desvantagem de usar o **`/Gy`** é que isso pode causar problemas durante a depuração. Portanto, geralmente é recomendável usá-lo. Para obter mais informações, consulte [ `/Gy` (habilitar vinculação no nível de função)](reference/gy-enable-function-level-linking.md).

Para vincular em ambientes de 64 bits, é recomendável usar a **`/OPT:REF,ICF`** opção de vinculador e, em ambientes de 32 bits, **`/OPT:REF`** é recomendado. Para obter mais informações, consulte [/opt (otimizations)](reference/opt-optimizations.md).

Também é altamente recomendável gerar símbolos de depuração, mesmo com compilações de versão otimizadas. Ele não afeta o código gerado e torna muito mais fácil depurar seu aplicativo, se necessário.

### <a name="floating-point-switches"></a>Comutadores de ponto flutuante

A **`/Op`** opção do compilador foi removida e as quatro opções de compilador a seguir que lidam com otimizações de ponto flutuante foram adicionadas:

|Opção|Descrição|
|-|-|
|**`/fp:precise`**|Essa é a recomendação padrão e deve ser usada na maioria dos casos.|
|**`/fp:fast`**|Recomendado se o desempenho for o máximo de importância, por exemplo, em jogos. Isso resultará no desempenho mais rápido.|
|**`/fp:strict`**|Recomendado se forem desejadas exceções de ponto flutuante precisos e o comportamento do IEEE. Isso resultará no desempenho mais lento.|
|**`/fp:except[-]`**|Pode ser usado em conjunto com **`/fp:strict`** or **`/fp:precise`** , mas não **`/fp:fast`** .|

Para obter mais informações, consulte [ `/fp` (especificar comportamento de ponto flutuante)](reference/fp-specify-floating-point-behavior.md).

## <a name="optimization-declspecs"></a>Declspecs de otimização

Nesta seção, veremos dois declspecs que podem ser usados em programas para ajudar o desempenho: `__declspec(restrict)` e `__declspec(noalias)` .

O `restrict` declspec só pode ser aplicado a declarações de função que retornam um ponteiro, como `__declspec(restrict) void *malloc(size_t size);`

O `restrict` declspec é usado em funções que retornam ponteiros sem alias. Essa palavra-chave é usada para a implementação da biblioteca em tempo de execução do C `malloc` , pois ela nunca retornará um valor de ponteiro que já esteja em uso no programa atual (a menos que você esteja fazendo algo ilegal, como o uso da memória após sua liberação).

O `restrict` declspec fornece ao compilador mais informações para executar otimizações de compilador. Uma das coisas mais difíceis de um compilador determinar é o que aponta para outros ponteiros de alias e o uso dessas informações ajuda muito o compilador.

Vale a pena destacar que essa é uma promessa para o compilador, não algo que o compilador verificará. Se o seu programa usar esse `restrict` declspec incorretamente, seu programa poderá ter um comportamento incorreto.

Para obter mais informações, consulte [`restrict`](../cpp/restrict.md).

O `noalias` declspec também é aplicado somente a funções e indica que a função é uma função semipura. Uma função semipura é aquela que faz referência ou modifica somente locais, argumentos e indireções de primeiro nível de argumentos. Esse declspec é uma promessa para o compilador e, se a função referenciar globais ou indireções de segundo nível de argumentos de ponteiro, o compilador poderá gerar um código que interrompa o aplicativo.

Para obter mais informações, consulte [`noalias`](../cpp/noalias.md).

## <a name="optimization-pragmas"></a>Pragmas de otimização

Também há vários pragmas úteis para ajudar a otimizar o código. A primeira que discutiremos é `#pragma optimize` :

```cpp
#pragma optimize("{opt-list}", on | off)
```

Esse pragma permite que você defina um determinado nível de otimização em uma base função a função. Isso é ideal para as raras ocasiões em que o aplicativo falha quando uma determinada função é compilada com otimização. Você pode usar isso para desativar otimizações para uma única função:

```cpp
#pragma optimize("", off)
int myFunc() {...}
#pragma optimize("", on)
```

Para obter mais informações, consulte [`optimize`](../preprocessor/optimize.md).

A inalinhamento é uma das otimizações mais importantes que o compilador executa e aqui falamos sobre alguns dos pragmas que ajudam a modificar esse comportamento.

`#pragma inline_recursion` é útil para especificar se você deseja ou não que o aplicativo seja capaz de embutir em linha uma chamada recursiva. Por padrão, ele está desativado. Para recursão superficial de pequenas funções, você pode ativar essa opção. Para obter mais informações, consulte [`inline_recursion`](../preprocessor/inline-recursion.md).

Outro pragma útil para limitar a profundidade de inalinhamento é `#pragma inline_depth` . Isso é normalmente útil em situações em que você está tentando limitar o tamanho de um programa ou função. Para obter mais informações, consulte [`inline_depth`](../preprocessor/inline-depth.md).

## <a name="__restrict-and-__assume"></a>`__restrict` e `__assume`

Há algumas palavras-chave no Visual Studio que podem ajudar o desempenho: [__restrict](../cpp/extension-restrict.md) e [__assume](../intrinsics/assume.md).

Primeiro, deve-se observar que **`__restrict`** e `__declspec(restrict)` são duas coisas diferentes. Embora estejam um pouco relacionados, sua semântica é diferente. **`__restrict`** é um qualificador de tipo, como **`const`** ou **`volatile`** , mas exclusivamente para tipos de ponteiro.

Um ponteiro que é modificado com o **`__restrict`** é chamado de *ponteiro __restrict*. Um ponteiro de __restrict é um ponteiro que só pode ser acessado por meio do \_ ponteiro de _restrict. Em outras palavras, não é possível usar outro ponteiro para acessar os dados apontados pelo \_ ponteiro de _restrict.

**`__restrict`** pode ser uma ferramenta poderosa para o otimizador do Microsoft C++, mas use-a com muito cuidado. Se for usado de forma inadequada, o otimizador poderá executar uma otimização que interromperia seu aplicativo.

A **`__restrict`** palavra-chave substitui a opção **/OA** de versões anteriores.

Com **`__assume`** o, um desenvolvedor pode instruir o compilador a fazer suposições sobre o valor de alguma variável.

Por exemplo `__assume(a < 5);` , informa ao otimizador que, nessa linha de código, a variável `a` é menor que 5. Novamente, essa é uma promessa para o compilador. Se `a` for realmente 6 neste ponto do programa, o comportamento do programa após a otimização do compilador poderá não ser o que você esperaria. **`__assume`** é mais útil antes de instruções switch e/ou expressões condicionais.

Há algumas limitações para o **`__assume`** . Primeiro, como **`__restrict`** , é apenas uma sugestão, portanto, o compilador está livre para ignorá-lo. Além disso, **`__assume`** atualmente só funciona com desigualdades de variáveis em constantes. Ele não propaga desigualdades simbólicas, por exemplo, suponha que (a < b).

## <a name="intrinsic-support"></a>Suporte intrínseco

Intrínsecos são chamadas de função em que o compilador tem conhecimento intrínseco sobre a chamada e em vez de chamar uma função em uma biblioteca, ele emite o código para essa função. O arquivo de cabeçalho \<intrin.h> contém todos os intrínsecos disponíveis para cada uma das plataformas de hardware com suporte.

Os intrínsecos dão ao programador a capacidade de aprofundar-se no código sem precisar usar o assembly. Há vários benefícios em usar intrínsecos:

- Seu código é mais portátil. Vários dos intrínsecos estão disponíveis em várias arquiteturas de CPU.

- Seu código é mais fácil de ler, pois o código ainda é escrito em C/C++.

- Seu código obtém o benefício das otimizações do compilador. À medida que o compilador é melhor, a geração de código para os intrínsecos melhora.

Para obter mais informações, consulte [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).

## <a name="exceptions"></a>Exceções

Há um impacto no desempenho associado ao uso de exceções. Algumas restrições são introduzidas ao usar blocos try que impedem o compilador de executar determinadas otimizações. Em plataformas x86, há degradação de desempenho adicional de blocos try devido a informações de estado adicionais que devem ser geradas durante a execução do código. Nas plataformas de 64 bits, os blocos try não prejudicam o desempenho, mas depois que uma exceção é lançada, o processo de localizar o manipulador e desenrolar a pilha pode ser caro.

Portanto, é recomendável evitar a introdução de blocos try/catch em código que não realmente precise dele. Se você precisar usar exceções, use exceções síncronas, se possível. Para obter mais informações, consulte [manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md).

Por fim, lance exceções apenas para casos excepcionais. O uso de exceções para o fluxo de controle geral provavelmente fará com que o desempenho seja afetado.

## <a name="see-also"></a>Confira também

- [Otimizando seu código](optimizing-your-code.md)
