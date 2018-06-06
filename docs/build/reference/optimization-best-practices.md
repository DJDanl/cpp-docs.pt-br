---
title: Práticas recomendadas de otimização | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, optimization
- optimization, best practices
ms.assetid: f3433148-7255-4ca6-8a4f-7c31aac88508
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 63d3437a08e3c8b69b564176e0f377566ab491e6
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704234"
---
# <a name="optimization-best-practices"></a>Práticas recomendadas de otimização

Este documento descreve algumas práticas recomendadas para otimização em Visual C++.

## <a name="compiler-and-linker-options"></a>Compilador e opções do vinculador

### <a name="profile-guided-optimization"></a>Otimização Guiada por perfil

Visual C++ dá suporte a *Otimização Guiada por perfil* (PGO). Essa otimização usa dados de perfil de execuções de treinamento de uma versão instrumentada de um aplicativo para otimização posterior do aplicativo da unidade. Usar PGO pode ser demorado, portanto, não pode ser algo que cada desenvolvedor usa, mas é recomendável usar PGO para a compilação de lançamento final de um produto. Para obter mais informações, consulte [Profile-Guided otimizações](../../build/reference/profile-guided-optimizations.md).

Além disso, *otimização de programa total* (também conhecidos como geração de código de tempo de vinculação) e o **/O1** e **/O2** otimizações foram aprimoradas. Em geral, um aplicativo compilado com uma dessas opções será mais rápido do que o mesmo aplicativo compilado com um compilador anterior. 

Para obter mais informações, consulte [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md) e [/O1, /O2 (minimizar tamanho, maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md).

### <a name="which-level-of-optimization-to-use"></a>O nível de otimização para usar

Se possível, compilações de lançamento final devem ser compiladas com otimizações guiadas por perfil. Se não for possível criar com PGO, devido a infraestrutura suficiente para executar as compilações instrumentadas ou não ter acesso aos cenários, é recomendável construção com otimização de programa total.

O **/Gy** também é muito útil. Ele gera um COMDAT separado para cada função, fornecendo o vinculador mais flexibilidade quando se trata de remoção não referenciada COMDATs e COMDAT dobra. A única desvantagem de usar **/Gy** é que ele pode causar problemas durante a depuração. Portanto, geralmente é recomendável usá-lo. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](../../build/reference/gy-enable-function-level-linking.md).

Para vincular em ambientes de 64 bits, é recomendável usar o **/OPT: REF, ICF** opção de vinculador e em ambientes de 32 bits, **/OPT: REF** é recomendado. Para obter mais informações, consulte [/OPÇ (otimizações)](../../build/reference/opt-optimizations.md).

Também recomenda para gerar os símbolos de depuração, mesmo com compilações de lançamento otimizada. Ele não afetam o código gerado, e ele torna muito mais fácil depurar seu aplicativo, se precisa ser.

### <a name="floating-point-switches"></a>Opções de ponto flutuantes

O **/Op** opção de compilador foi removida e as quatro opções do compilador lidar com otimizações de ponto de flutuante foram adicionadas:

|||
|-|-|
|**/FP: preciso**|Essa é a recomendação padrão e deve ser usada na maioria dos casos.|
|**Fast**|Recomendado se o desempenho é mais importante, por exemplo, nos jogos. Isso resulta em melhor desempenho.|
|**/FP: strict**|Se recomendado exceções de ponto flutuantes de precisa e IEEE comportamento é desejado. Isso resultará no desempenho mais lento.|
|**/FP: except [-]**|Pode ser usado em conjunto com **/fp: strict** ou **/fp: preciso**, mas não **Fast**.|

Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md).

## <a name="optimization-declspecs"></a>Otimização declspecs

Nesta seção examinaremos duas declspecs que pode ser usados em programas para ajudar no desempenho: `__declspec(restrict)` e `__declspec(noalias)`.

O `restrict` declspec só pode ser aplicado a declarações de função que retornam um ponteiro, como `__declspec(restrict) void *malloc(size_t size);`

O `restrict` declspec é usada em funções que retornam ponteiros sem alias. Esta palavra-chave é usada para a implementação de biblioteca de tempo de execução C de `malloc` desde que ele nunca retornarão um valor de ponteiro que já está em uso no programa atual (a menos que você esteja fazendo algo ilegal, como o uso de memória após ele ter sido liberado).

O `restrict` declspec fornece o compilador mais informações para executar otimizações do compilador. Uma das coisas mais difíceis para determinar um compilador é o alias de ponteiros outros ponteiros e usando essas informações muito ajuda o compilador.

Vale a pena destacar que se trata de uma promessa para o compilador, não seja algo que o compilador vai verificar. Se seu programa usa esse `restrict` declspec inadequadamente, seu programa pode ter um comportamento incorreto.

Para obter mais informações, consulte [restringir](../../cpp/restrict.md).

O `noalias` declspec também se aplica apenas a funções e indica que a função é uma função pura semi-estruturados. Uma função pura semi-estruturados é aquele que faz referência ou modifica apenas locais, argumentos e referências indiretas de primeiro nível de argumentos. Este declspec é uma promessa para o compilador, e quando a função faz referência globais ou referências indiretas de segundo nível de argumentos de ponteiro, o compilador podem gerar o código que interrompe o aplicativo.

Para obter mais informações, consulte [noalias](../../cpp/noalias.md).

## <a name="optimization-pragmas"></a>Pragmas de otimização

Também há vários pragmas útil para ajudar a otimizar o código. A primeira, discutiremos é `#pragma optimize`:

```cpp
#pragma optimize("{opt-list}", on | off)
```

Esse pragma permite que você defina um nível de otimização determinado em uma base de função pela função. Isso é ideal para as raras ocasiões em que seu aplicativo falhar quando uma determinada função é compilada com a otimização. Você pode usar isso para desativar otimizações para uma única função:

```cpp
#pragma optimize("", off)
int myFunc() {...}
#pragma optimize("", on)
```

Para obter mais informações, consulte [otimizar](../../preprocessor/optimize.md).

Inlining é uma das mais importantes otimizações que o compilador executa e aqui falarmos sobre os pragmas que ajudam a modificar esse comportamento.

`#pragma inline_recursion` é útil para especificar se deseja ou não que o aplicativo para poder embutido uma chamada recursiva. Por padrão, ele está desativado. Para a recursão superficial de pequenas funções talvez você precise ative esta opção. Para obter mais informações, consulte [inline_recursion](../../preprocessor/inline-recursion.md).

Outro pragma útil para limitar a profundidade de inlining é `#pragma inline_depth`. Isso é normalmente útil em situações em que você está tentando limitar o tamanho de um programa ou a função. Para obter mais informações, consulte [inline_depth](../../preprocessor/inline-depth.md).

## <a name="restrict-and-assume"></a>Restrict e \__assume

Há algumas das palavras-chave no Visual C++ que pode ajudar no desempenho: [Restrict](../../cpp/extension-restrict.md) e [__assume](../../intrinsics/assume.md).

Primeiro, deve-se observar que `__restrict` e `__declspec(restrict)` são duas coisas diferentes. Enquanto eles estiverem ligeiramente relacionados, sua semântica é diferente. `__restrict` é um qualificador de tipo, como `const` ou `volatile`, mas apenas para tipos de ponteiro.

Um ponteiro que é modificado com `__restrict` é conhecido como um *Restrict ponteiro*. Um ponteiro de __restrict é um ponteiro que só pode ser acessado por meio de \_ponteiro restrito. Em outras palavras, o outro ponteiro não pode ser usado para acessar os dados que aponta para o \_ponteiro restrito.

`__restrict` pode ser uma ferramenta poderosa para o otimizador do Visual C++, mas usá-lo com muito cuidado. Se usado incorretamente, o otimizador pode realizar uma otimização que interrompe o aplicativo.

O `__restrict` palavra-chave substitui o **/Oa** alternar de versões anteriores.

Com `__assume`, um desenvolvedor pode informar ao compilador para fazer suposições sobre o valor da variável de alguns.

Por exemplo `__assume(a < 5);` informa que o otimizador na linha de código a variável `a` é menor que 5. Novamente, essa é uma promessa para o compilador. Se `a` for realmente 6 neste ponto no programa, o comportamento do programa depois otimizou o compilador não pode ser o que você esperaria. `__assume` é mais útil antes de instruções switch e/ou expressões condicionais.

Existem algumas limitações para `__assume`. Primeiro, como `__restrict`, é apenas uma sugestão, portanto, o compilador é livre para ignorá-lo. Além disso, `__assume` atualmente só funciona com variável desigualdades em constantes. Ele não se propaga desigualdades simbólicas, por exemplo, assume(a < b).

## <a name="intrinsic-support"></a>Suporte intrínseco

Intrínsecos são função chama em que o compilador não tem conhecimento intrínseco sobre a chamada e, em vez de chamar uma função em uma biblioteca, ele emite código para essa função. O arquivo de cabeçalho \<intrin.h > contém todos os intrínsecos disponíveis para cada uma das plataformas de hardware com suporte.

Intrínsecos dar o programador a capacidade de fazer profundamente o código sem precisar usar o assembly. Há vários benefícios ao usar intrínsecos:

- Seu código é mais portáteis. Vários os intrínsecos estão disponíveis em várias arquiteturas de CPU.

- Seu código é mais fácil de ler, pois o código ainda está escrito em C/C++.

- O código obtém o benefício de otimizações do compilador. Como o compilador fica melhor, melhora a geração de código para os intrínsecos.

Para obter mais informações, consulte [intrínsecos do compilador](../../intrinsics/compiler-intrinsics.md).

## <a name="exceptions"></a>Exceções

Há um desempenho ocorrências associadas ao uso de exceções. Algumas restrições são apresentadas ao usar blocos try que impedem o compilador executem certas otimizações. X86 plataformas há degradação de desempenho adicionais de tente blocos devido a informações de estado adicionais que devem ser gerados durante a execução de código. Nas plataformas de 64 bits, tente blocos não prejudicar o desempenho máximo, mas depois que uma exceção será lançada, o processo de localizar o manipulador e desenrolamento da pilha pode ser caro.

Portanto, é recomendável para evitar introduzir blocos try/catch em código que não realmente precisa. Se você precisar usar exceções, use exceções síncronas, se possível. Para obter mais informações, consulte [manipulação de exceções estruturado (C/C++)](../../cpp/structured-exception-handling-c-cpp.md).

Por fim, lançar exceções para somente os casos excepcionais. Usar exceções para o fluxo de controle geral provavelmente fará desempenho ser afetado.

## <a name="see-also"></a>Consulte também

- [Otimizando seu código](../../build/reference/optimizing-your-code.md)
