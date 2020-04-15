---
title: Melhores práticas de otimização
ms.date: 05/06/2019
helpviewer_keywords:
- C++, optimization
- optimization, best practices
ms.assetid: f3433148-7255-4ca6-8a4f-7c31aac88508
ms.openlocfilehash: 541114b4cbf7d3d063e48b50ab265b4c95c6237c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328446"
---
# <a name="optimization-best-practices"></a>Melhores práticas de otimização

Este documento descreve algumas práticas recomendadas para otimizar programas C++ no Visual Studio.

## <a name="compiler-and-linker-options"></a>Opções de compilador e linker

### <a name="profile-guided-optimization"></a>Otimização guiada por perfil

O Visual Studio suporta *otimização guiada por perfil* (PGO). Essa otimização usa dados de perfil de execuções de treinamento de uma versão instrumentada de um aplicativo para impulsionar a otimização posterior do aplicativo. O uso do PGO pode ser demorado, por isso pode não ser algo que todo desenvolvedor usa, mas recomendamos o uso do PGO para a compilação final de um produto. Para obter mais informações, confira [Otimizações guiadas por perfil](profile-guided-optimizations.md).

Além disso, *a Otimização de Programas Inteiros* (também sabe como Geração de Código de Tempo de Link) e as otimizações **/O1** e **/O2** foram melhoradas. Em geral, um aplicativo compilado com uma dessas opções será mais rápido do que o mesmo aplicativo compilado com um compilador anterior.

Para obter mais informações, consulte [/GL (Otimização total do programa)](reference/gl-whole-program-optimization.md) e [/O1, /O2 (Minimizar tamanho, maximizar a velocidade)](reference/o1-o2-minimize-size-maximize-speed.md).

### <a name="which-level-of-optimization-to-use"></a>Qual nível de otimização usar

Se possível, as compilações de versão final devem ser compiladas com otimizações guiadas por perfil. Se não for possível construir com PGO, seja por insuficiência de infraestrutura para execução das construções instrumentadas ou não ter acesso a cenários, então sugerimos a construção com Otimização de Programa Inteiro.

O **interruptor /Gy** também é muito útil. Ele gera um COMDAT separado para cada função, dando ao linker mais flexibilidade quando se trata de remover COMDATs não referenciados e dobramento COMDAT. A única desvantagem de usar **/Gy** é que ele pode causar problemas ao depurar. Portanto, é geralmente recomendado usá-lo. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](reference/gy-enable-function-level-linking.md).

Para vincular em ambientes de 64 bits, recomenda-se usar a opção **/OPT:REF, ICF** linker e em ambientes de 32 bits, é recomendado **/OPT:REF.** Para obter mais informações, consulte [/OPT (Otimizações)](reference/opt-optimizations.md).

Também é fortemente recomendado gerar símbolos de depuração, mesmo com compilações de liberação otimizadas. Ele não afeta o código gerado, e torna muito mais fácil depurar sua aplicação, se necessário.

### <a name="floating-point-switches"></a>Interruptores de ponto flutuante

A opção **compilador /Op** foi removida e as quatro opções de compilador a seguir que lidam com otimizações de pontos flutuantes foram adicionadas:

|||
|-|-|
|**/fp:preciso**|Esta é a recomendação padrão e deve ser usada na maioria dos casos.|
|**/fp:rápido**|Recomendado se o desempenho é de extrema importância, por exemplo, em jogos. Isso resultará no desempenho mais rápido.|
|**/fp:rigoroso**|Recomenda-se que exceções precisas de ponto flutuante e comportamento iEEE seja desejado. Isso resultará no desempenho mais lento.|
|**/fp:exceto[-]**|Pode ser usado em conjunto com **/fp:strict** ou **/fp:preciso**, mas não **/fp:rápido**.|

Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](reference/fp-specify-floating-point-behavior.md).

## <a name="optimization-declspecs"></a>Especificações de otimização de otimização

Nesta seção, analisaremos duas declspecções que podem ser `__declspec(restrict)` usadas `__declspec(noalias)`em programas para ajudar o desempenho: e .

A `restrict` declspec só pode ser aplicada a declarações de função que retornam um ponteiro, como`__declspec(restrict) void *malloc(size_t size);`

A `restrict` declspec é usada em funções que retornam ponteiros não aliased. Esta palavra-chave é usada para a `malloc` implementação da Biblioteca C-Runtime, uma vez que nunca retornará um valor de ponteiro que já está em uso no programa atual (a menos que você esteja fazendo algo ilegal, como usar a memória depois de ser liberada).

A `restrict` declspec fornece ao compilador mais informações para a realização de otimizações de compiladores. Uma das coisas mais difíceis para um compilador determinar é o que aponta alias outros ponteiros, e usar essas informações ajuda muito o compilador.

Vale ressaltar que esta é uma promessa para o compilador, não algo que o compilador irá verificar. Se o seu `restrict` programa usar essa declspec de forma inadequada, seu programa pode ter um comportamento incorreto.

Para obter mais informações, consulte [restringir](../cpp/restrict.md).

O `noalias` declspec também é aplicado apenas às funções, e indica que a função é uma função semi-pura. Uma função semi-pura é aquela que faz referências ou modifica apenas locais, argumentos e indireções de primeiro nível de argumentos. Essa declspec é uma promessa para o compilador, e se a função faz referência a globals ou indireções de segundo nível de argumentos de ponteiro, então o compilador pode gerar código que quebra o aplicativo.

Para obter mais informações, consulte [noalias](../cpp/noalias.md).

## <a name="optimization-pragmas"></a>Pragmas de otimização

Há também vários pragmas úteis para ajudar a otimizar o código. O primeiro que discutiremos é: `#pragma optimize`

```cpp
#pragma optimize("{opt-list}", on | off)
```

Este pragma permite definir um determinado nível de otimização em uma base de função por função. Isso é ideal para aquelas raras ocasiões em que seu aplicativo falha quando uma determinada função é compilada com otimização. Você pode usar isso para desativar otimizações para uma única função:

```cpp
#pragma optimize("", off)
int myFunc() {...}
#pragma optimize("", on)
```

Para obter mais informações, consulte [otimizar](../preprocessor/optimize.md).

O inlineamento é uma das otimizações mais importantes que o compilador realiza e aqui falamos sobre alguns dos pragmas que ajudam a modificar esse comportamento.

`#pragma inline_recursion`é útil para especificar se você quer ou não que o aplicativo seja capaz de inlinear uma chamada recursiva. Por padrão, está desligado. Para recursão superficial de pequenas funções, você pode ligar isso. Para obter mais informações, consulte [inline_recursion](../preprocessor/inline-recursion.md).

Outro pragma útil para limitar a `#pragma inline_depth`profundidade de inforrar é . Isso é normalmente útil em situações onde você está tentando limitar o tamanho de um programa ou função. Para obter mais informações, consulte [inline_depth](../preprocessor/inline-depth.md).

## <a name="__restrict-and-__assume"></a>__restrict \_e _assume

Existem algumas palavras-chave no Visual Studio que podem ajudar no desempenho: [__restrict](../cpp/extension-restrict.md) e [__assume](../intrinsics/assume.md).

Em primeiro lugar, `__restrict` deve-se notar que e `__declspec(restrict)` são duas coisas diferentes. Embora estejam um pouco relacionados, sua semântica é diferente. `__restrict`é um qualificador `const` `volatile`de tipo, como ou , mas exclusivamente para tipos de ponteiros.

Um ponteiro modificado `__restrict` com é referido como um *ponteiro __restrict*. Um ponteiro __restrict é um ponteiro que \_só pode ser acessado através do ponteiro _restrict. Em outras palavras, outro ponteiro não pode ser \_usado para acessar os dados apontados pelo ponteiro _restrict.

`__restrict`pode ser uma ferramenta poderosa para o otimizador Microsoft C++, mas usá-lo com muito cuidado. Se usado incorretamente, o otimizador pode realizar uma otimização que quebraria sua aplicação.

A `__restrict` palavra-chave substitui o **switch /Oa** das versões anteriores.

Com `__assume`, um desenvolvedor pode dizer ao compilador para fazer suposições sobre o valor de alguma variável.

Por `__assume(a < 5);` exemplo, diz ao otimizador que `a` nessa linha de código a variável é menor que 5. Mais uma vez esta é uma promessa para o compilador. Se `a` é realmente 6 neste ponto do programa, então o comportamento do programa após o compilador ter otimizado pode não ser o que você esperaria. `__assume`é mais útil antes de trocar declarações e/ou expressões condicionais.

Existem algumas limitações para. `__assume` Primeiro, `__restrict`é apenas uma sugestão, então o compilador é livre para ignorá-lo. Além `__assume` disso, atualmente trabalha apenas com desigualdades variáveis contra constantes. Não propaga desigualdades simbólicas, por exemplo, assumem(a < b).

## <a name="intrinsic-support"></a>Suporte intrínseco

Intrínsecos são chamadas de função onde o compilador tem conhecimento intrínseco sobre a chamada, e em vez de chamar uma função em uma biblioteca, ele emite código para essa função. O arquivo \<de cabeçalho intrin.h> contém todas as intrínsecas disponíveis para cada uma das plataformas de hardware suportadas.

Os intrínsecos dão ao programador a capacidade de ir fundo no código sem ter que usar a montagem. Existem vários benefícios para o uso de intrínsecas:

- Seu código é mais portátil. Vários dos intrínsecos estão disponíveis em várias arquiteturas de CPU.

- Seu código é mais fácil de ler, já que o código ainda está escrito em C/C++.

- Seu código obtém o benefício das otimizações do compilador. À medida que o compilador melhora, a geração de código para os intrínsecos melhora.

Para obter mais informações, consulte [Intrínseca](../intrinsics/compiler-intrinsics.md)do Compilador .

## <a name="exceptions"></a>Exceções

Há um sucesso de desempenho associado ao uso de exceções. Algumas restrições são introduzidas ao usar blocos de tentativa que inibem o compilador de realizar certas otimizações. Em plataformas x86 há degradação adicional de desempenho de blocos de tentativa devido a informações adicionais de estado que devem ser geradas durante a execução do código. Nas plataformas de 64 bits, os blocos de teste não degradam tanto o desempenho, mas uma vez que uma exceção é lançada, o processo de encontrar o manipulador e desenrolar a pilha pode ser caro.

Portanto, recomenda-se evitar introduzir blocos de tentativa/captura em código que realmente não precisa dele. Se você deve usar exceções, use exceções síncronas, se possível. Para obter mais informações, consulte [Tratamento estruturado de exceções (C/C++)](../cpp/structured-exception-handling-c-cpp.md).

Por último, lance exceções apenas para casos excepcionais. O uso de exceções para o fluxo de controle geral provavelmente fará o desempenho sofrer.

## <a name="see-also"></a>Confira também

- [Otimizando o código](optimizing-your-code.md)
