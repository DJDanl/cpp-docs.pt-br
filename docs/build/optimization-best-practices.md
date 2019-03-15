---
title: Melhores práticas de otimização
ms.date: 11/04/2016
helpviewer_keywords:
- Visual C++, optimization
- optimization, best practices
ms.assetid: f3433148-7255-4ca6-8a4f-7c31aac88508
ms.openlocfilehash: edb036292b87593a3f8bb9b3f5ec5f7beb84c3a5
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824606"
---
# <a name="optimization-best-practices"></a>Melhores práticas de otimização

Este documento descreve algumas práticas recomendadas para otimização no Visual C++.

## <a name="compiler-and-linker-options"></a>Compilador e as opções do vinculador

### <a name="profile-guided-optimization"></a>Otimização Guiada por perfil

Visual C++ suporta *Otimização Guiada por perfil* (PGO). Essa otimização usa dados de perfil de execuções de treinamento de uma versão instrumentada de um aplicativo para direcionar a otimização mais recente do aplicativo. Usar a PGO pode ser demorado, portanto, não pode ser algo que todo desenvolvedor usa, mas recomendamos usar a PGO para a compilação de lançamento final de um produto. Para obter mais informações, consulte [otimizações guiadas pelo perfil](profile-guided-optimizations.md).

Além disso, *otimização de programa inteiro* (também conhecidos como geração de código de tempo de vinculação) e o **/O1** e **/O2** otimizações foram aprimoradas. Em geral, um aplicativo compilado com uma dessas opções será mais rápido do que o mesmo aplicativo compilado com um compilador anterior.

Para obter mais informações, consulte [/GL (otimização de programa inteiro)](reference/gl-whole-program-optimization.md) e [/O1, / O2 (minimizar tamanho, maximizar velocidade)](reference/o1-o2-minimize-size-maximize-speed.md).

### <a name="which-level-of-optimization-to-use"></a>Qual nível de otimização para usar

Se possível, os builds de lançamento final devem ser compilados com otimizações guiadas por perfil. Se não for possível compilar com a PGO, seja devido à infra-estrutura insuficientes para executar as compilações instrumentadas ou não ter acesso a cenários, sugerimos prédio com otimização de programa total.

O **/Gy** switch também é muito útil. Ele gera uma COMDAT separada para cada função, fornecendo o vinculador mais flexibilidade quando se trata de remoção não referenciado COMDATs e COMDAT dobra. A única desvantagem de usar **/Gy** é que ele pode causar problemas durante a depuração. Portanto, geralmente, é recomendável usá-lo. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](reference/gy-enable-function-level-linking.md).

Para vinculação em ambientes de 64 bits, é recomendável usar o **/OPT: REF, ICF** opção de vinculador e em ambientes de 32 bits **/OPT: REF** é recomendado. Para obter mais informações, consulte [/OPT (otimizações)](reference/opt-optimizations.md).

Também é recomendável gerar símbolos de depuração, mesmo com compilações de versão otimizada. Ele não afeta o código gerado, e ele torna muito mais fácil de depurar seu aplicativo, se precisa ser.

### <a name="floating-point-switches"></a>Opções de ponto flutuantes

O **/Op** a opção de compilador foi removida e as quatro opções do compilador lidando com otimizações de ponto de flutuante foram adicionadas:

|||
|-|-|
|**/fp:precise**|Isso é a recomendação padrão e deve ser usado na maioria dos casos.|
|**/fp:fast**|Recomendado se o desempenho é de extrema importância, por exemplo, em jogos. Isso resulta em melhor desempenho.|
|**/fp:strict**|Recomendado se preciso exceções de ponto flutuante e IEEE comportamento é desejado. Isso resultará no desempenho mais lento.|
|**/fp:except[-]**|Pode ser usado em conjunto com **/fp: strict** ou **/fp: preciso**, mas não **Fast**.|

Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](reference/fp-specify-floating-point-behavior.md).

## <a name="optimization-declspecs"></a>Otimização declspecs

Nesta seção vamos examinar dois declspecs que podem ser usados em programas para ajudar a desempenho: `__declspec(restrict)` e `__declspec(noalias)`.

O `restrict` declspec só pode ser aplicado a declarações de função que retornam um ponteiro, como `__declspec(restrict) void *malloc(size_t size);`

O `restrict` declspec é usada em funções que retornam ponteiros sem alias. Essa palavra-chave é usada para a implementação de biblioteca de tempo de execução C de `malloc` , desde que ele nunca retornará um valor de ponteiro que já está em uso no programa atual (a menos que você esteja fazendo algo ilegal, como o uso de memória após ele ter sido liberado).

O `restrict` declspec concede ao compilador para obter mais informações para executar as otimizações do compilador. Uma das coisas mais difíceis para determinar um compilador é o alias de ponteiros outros ponteiros e usando essas informações bastante ajuda o compilador.

Vale a pena salientar que se trata de uma promessa para o compilador, não seja algo que o compilador verificará. Se seu programa usa isso `restrict` declspec inadequadamente, seu programa pode ter um comportamento incorreto.

Para obter mais informações, consulte [restringir](../cpp/restrict.md).

O `noalias` declspec também se aplica somente a funções e indica que a função é uma função pura semiestruturados. Uma função pura parcial é aquele que faz referência ou modifica somente locais, argumentos e indireções de primeiro nível de argumentos. Esse declspec é uma promessa para o compilador e, se a função faz referência globals ou referências indiretas de segundo nível argumentos de ponteiro, em seguida, o compilador podem gerar o código que interrompe o aplicativo.

Para obter mais informações, consulte [noalias](../cpp/noalias.md).

## <a name="optimization-pragmas"></a>Pragmas de otimização

Também há vários pragmas úteis para ajudar a otimizar o código. O primeiro que discutiremos é `#pragma optimize`:

```cpp
#pragma optimize("{opt-list}", on | off)
```

Esse pragma permite que você defina um nível de otimização determinado em uma base de função por função. Isso é ideal para essas ocasiões raras em que o aplicativo falha quando uma determinada função é compilada com a otimização. Você pode usar isso para desativar otimizações para uma única função:

```cpp
#pragma optimize("", off)
int myFunc() {...}
#pragma optimize("", on)
```

Para obter mais informações, consulte [otimizar](../preprocessor/optimize.md).

Inlining é uma das otimizações mais importantes que o compilador executa e aqui podemos falar sobre alguns dos pragmas do que ajudam a modificar esse comportamento.

`#pragma inline_recursion` é útil para especificar se deseja ou não que o aplicativo seja capaz de embutir uma chamada recursiva. Por padrão, ele está desativado. Para recursão superficial de pequenas funções você poderá para ativar essa configuração. Para obter mais informações, consulte [inline_recursion](../preprocessor/inline-recursion.md).

Outro pragma útil para limitar a profundidade do inlining é `#pragma inline_depth`. Isso é normalmente útil em situações em que você está tentando limitar o tamanho de um programa ou função. Para obter mais informações, consulte [inline_depth](../preprocessor/inline-depth.md).

## <a name="restrict-and-assume"></a>Restrict e \__assume

Há algumas das palavras-chave no Visual C++ que podem ajudar o desempenho: [Restrict](../cpp/extension-restrict.md) e [assume](../intrinsics/assume.md).

Primeiro, é importante observar que `__restrict` e `__declspec(restrict)` são duas coisas diferentes. Enquanto eles estiverem ligeiramente relacionados sua semântica é diferente. `__restrict` é um qualificador de tipo, como `const` ou `volatile`, mas exclusivamente para tipos de ponteiro.

Um ponteiro que é modificado com `__restrict` é conhecido como um *Restrict ponteiro*. Um ponteiro de Restrict é um ponteiro que só pode ser acessado por meio de \__restrict ponteiro. Em outras palavras, o outro ponteiro não pode ser usado para acessar os dados apontados pelo \__restrict ponteiro.

`__restrict` pode ser uma ferramenta poderosa para o otimizador do Visual C++, mas usá-lo com muito cuidado. Se usado incorretamente, o otimizador pode executar uma otimização que interromperia a seu aplicativo.

O `__restrict` palavra-chave substitui o **/Oa** mudar de versões anteriores.

Com `__assume`, um desenvolvedor pode dizer ao compilador fazer suposições sobre o valor de alguma variável.

Por exemplo `__assume(a < 5);` informa que o otimizador na linha de código a variável `a` é menor que 5. Novamente, essa é uma promessa para o compilador. Se `a` é, na verdade, 6 neste ponto no programa, em seguida, o comportamento do programa depois que o compilador otimizou pode não ser o que você esperaria. `__assume` é mais útil antes de instruções switch e/ou expressões condicionais.

Existem algumas limitações para `__assume`. Em primeiro lugar, como `__restrict`, é apenas uma sugestão, portanto, o compilador é livre para ignorá-la. Além disso, `__assume` atualmente funciona apenas com variável desigualdade em relação a constantes. Ele não propaga as desigualdades simbólicas, por exemplo, assume(a < b).

## <a name="intrinsic-support"></a>Suporte intrínseco

Intrínsecos são a função chama em que o compilador não tem conhecimento intrínseco sobre a chamada e, em vez de chamar uma função em uma biblioteca, ele emite código para essa função. O arquivo de cabeçalho \<intrin. h > contém todos os intrínsecos disponíveis para cada uma das plataformas de hardware com suporte.

Intrínsecos permitem que o programador se aprofundar no código sem precisar usar o assembly. Há vários benefícios ao usar intrínsecos:

- Seu código seja mais portátil. Vários dos intrínsecos estão disponíveis em várias arquiteturas de CPU.

- Seu código é mais fácil de ler, já que o código ainda é escrito em C/C++.

- Seu código obtém o benefício das otimizações do compilador. Como o compilador fica melhor, melhora a geração de código para os intrínsecos.

Para obter mais informações, consulte [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).

## <a name="exceptions"></a>Exceções

Há um desempenho ocorrências associadas ao uso de exceções. Algumas restrições são apresentadas ao usar blocos try que impedem o compilador execute determinadas otimizações. Em x86 plataformas há degradação de desempenho adicional de tente blocos devido a informações de estado adicionais que devem ser gerados durante a execução de código. Nas plataformas de 64 bits, tente blocos não prejudicam o desempenho máximo, mas depois que uma exceção é lançada, o processo de localizar o manipulador e desenrolar a pilha pode ser caro.

Portanto, é recomendável evitar a introdução de blocos try/catch no código que realmente precisar dela. Se você precisar usar exceções, use exceções síncronas, se possível. Para obter mais informações, consulte [tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md).

Por fim, lança exceções para somente os casos excepcionais. Usar exceções para o fluxo de controle geral provavelmente fará desempenho ser afetado.

## <a name="see-also"></a>Consulte também

- [Otimizando seu código](optimizing-your-code.md)
