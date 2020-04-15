---
title: Problemas de migração ARM do Visual C++
ms.date: 05/06/2019
ms.assetid: 0f4c434e-0679-4331-ba0a-cc15dd435a46
ms.openlocfilehash: 2c29b4ffa5344b309622314970ce52c47a0ebd05
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328803"
---
# <a name="common-visual-c-arm-migration-issues"></a>Problemas de migração ARM do Visual C++

Ao usar o compilador Microsoft C++ (MSVC), o mesmo código fonte C++ pode produzir resultados diferentes na arquitetura ARM do que nas arquiteturas x86 ou x64.

## <a name="sources-of-migration-issues"></a>Fontes de problemas migratórios

Muitos problemas que você pode encontrar quando você migra código das arquiteturas x86 ou x64 para a arquitetura ARM estão relacionados a construções de código-fonte que podem invocar comportamentos indefinidos, definidos pela implementação ou não especificados.

*Comportamento indefinido* é um comportamento que o padrão C++ não define, e isso é causado por uma operação que não tem resultado razoável: por exemplo, converter um valor de ponto flutuante para um inteiro não assinado, ou mudar um valor por um número de posições que é negativo ou excede o número de bits em seu tipo promovido.

*O comportamento definido pela implementação* é o comportamento que o padrão C++ exige que o fornecedor de compiladores defina e documente. Um programa pode confiar com segurança no comportamento definido pela implementação, mesmo que isso possa não ser portátil. Exemplos de comportamento definido pela implementação incluem os tamanhos dos tipos de dados incorporados e seus requisitos de alinhamento. Um exemplo de operação que pode ser afetada pelo comportamento definido pela implementação é acessar a lista de argumentos variáveis.

*Comportamento não especificado* é comportamento que o padrão C++ deixa intencionalmente não determinista. Embora o comportamento seja considerado não determinista, invocações particulares de comportamento não especificado são determinadas pela implementação do compilador. No entanto, não há necessidade de um fornecedor de compilador predeterminar o resultado ou garantir um comportamento consistente entre invocações comparáveis, e não há necessidade de documentação. Um exemplo de comportamento não especificado é a ordem em que as subexpressões, que incluem argumentos para uma chamada de função, são avaliadas.

Outros problemas de migração podem ser atribuídos a diferenças de hardware entre as arquiteturas ARM e x86 ou x64 que interagem com o padrão C++de forma diferente. Por exemplo, o modelo de memória forte da arquitetura `volatile`x86 e x64 dá a variáveis qualificadas algumas propriedades adicionais que foram usadas para facilitar certos tipos de comunicação entre segmentos no passado. Mas o modelo de memória fraca da arquitetura ARM não suporta esse uso, nem o padrão C++ exige isso.

> [!IMPORTANT]
> Embora `volatile` ganhe algumas propriedades que podem ser usadas para implementar formas limitadas de comunicação entre segmentos em x86 e x64, essas propriedades adicionais não são suficientes para implementar a comunicação entre segmentos em geral. O padrão C++ recomenda que essa comunicação seja implementada usando primitivos de sincronização apropriados.

Como diferentes plataformas podem expressar esse tipo de comportamento de forma diferente, a portação de software entre plataformas pode ser difícil e propensa a bugs se depender do comportamento de uma plataforma específica. Embora muitos desses tipos de comportamento possam ser observados e possam parecer estáveis, confiar neles é pelo menos não portátil, e nos casos de comportamento indefinido ou não especificado, também é um erro. Mesmo o comportamento citado neste documento não deve ser confiado, e pode mudar em futuros compiladores ou implementações de CPU.

## <a name="example-migration-issues"></a>Exemplos de problemas de migração

O resto deste documento descreve como o comportamento diferente desses elementos de linguagem C++ pode produzir resultados diferentes em diferentes plataformas.

### <a name="conversion-of-floating-point-to-unsigned-integer"></a>Conversão de ponto flutuante para inteiro não assinado

Na arquitetura ARM, a conversão de um valor de ponto flutuante para um inteiro de 32 bits satura até o valor mais próximo que o inteiro pode representar se o valor de ponto flutuante estiver fora do intervalo que o inteiro pode representar. Nas arquiteturas x86 e x64, a conversão envolve se o inteiro não está assinado, ou está definido como -2147483648 se o inteiro estiver assinado. Nenhuma dessas arquiteturas suporta diretamente a conversão de valores de ponto flutuante para tipos inteiros menores; em vez disso, as conversões são realizadas em 32 bits, e os resultados são truncados para um tamanho menor.

Para a arquitetura ARM, a combinação de saturação e truncação significa que a conversão para tipos não assinados satura corretamente tipos menores não assinados quando satura um inteiro de 32 bits, mas produz um resultado truncado para valores que são maiores do que o tipo menor pode representar, mas muito pequeno para saturar o inteiro inteiro de 32 bits inteiro. A conversão também satura corretamente para inteiros assinados de 32 bits, mas a truncação de inteiros saturados e assinados resulta em -1 para valores positivamente saturados e 0 para valores saturados negativamente. A conversão para um inteiro assinado menor produz um resultado truncado que é imprevisível.

Para as arquiteturas x86 e x64, a combinação de comportamento em wrap-around para conversões de inteiros não assinadas e avaliação explícita para conversões inteiras assinadas no estouro, juntamente com a truncação, tornam os resultados para a maioria das mudanças imprevisíveis se forem muito grandes.

Essas plataformas também diferem na forma como lidam com a conversão de NaN (Not-a-Number) para tipos inteiros. Na ARM, a NaN converte-se em 0x00000000; em x86 e x64, ele se converte em 0x800000000.

A conversão de ponto flutuante só pode ser confiada se você souber que o valor está dentro do intervalo do tipo inteiro ao qual está sendo convertido.

### <a name="shift-operator---behavior"></a>Comportamento do\< \< operador de turno ( >>)

Na arquitetura ARM, um valor pode ser deslocado para a esquerda ou para a direita até 255 bits antes que o padrão comece a se repetir. Nas arquiteturas x86 e x64, o padrão é repetido em cada múltiplo de 32, a menos que a fonte do padrão seja uma variável de 64 bits; nesse caso, o padrão se repete em cada múltiplo de 64 em x64, e cada múltiplo de 256 em x86, onde uma implementação de software é empregada. Por exemplo, para uma variável de 32 bits que tem um valor de 1 deslocado deixado por 32 posições, no ARM o resultado é 0, em x86 o resultado é 1, e em x64 o resultado também é 1. No entanto, se a fonte do valor é uma variável de 64 bits, então o resultado em todas as três plataformas é 4294967296, e o valor não "envolve" até que ele tenha mudado 64 posições em x64, ou 256 posições em ARM e x86.

Como o resultado de uma operação de turno que excede o número de bits no tipo de origem é indefinido, o compilador não é obrigado a ter um comportamento consistente em todas as situações. Por exemplo, se ambos os operands de uma mudança são conhecidos no momento da compilação, o compilador pode otimizar o programa usando uma rotina interna para precalcular o resultado da mudança e, em seguida, substituir o resultado no lugar da operação de turno. Se a quantidade de deslocamento for muito grande, ou negativa, o resultado da rotina interna pode ser diferente do resultado da mesma expressão de turno executada pela CPU.

### <a name="variable-arguments-varargs-behavior"></a>Comportamento de argumentos variáveis (varargs)

Na arquitetura ARM, os parâmetros da lista de argumentos variáveis que são passados na pilha estão sujeitos ao alinhamento. Por exemplo, um parâmetro de 64 bits está alinhado em um limite de 64 bits. Em x86 e x64, os argumentos que são passados na pilha não estão sujeitos a alinhamento e embalam firmemente. Essa diferença pode causar uma `printf` função variada como ler endereços de memória que foram destinados como preenchimento no ARM se o layout esperado da lista de argumentos variáveis não for exatamente compatível, mesmo que possa funcionar para um subconjunto de alguns valores nas arquiteturas x86 ou x64. Considere este exemplo:

```C
// notice that a 64-bit integer is passed to the function, but '%d' is used to read it.
// on x86 and x64 this may work for small values because %d will "parse" the low-32 bits of the argument.
// on ARM the calling convention will align the 64-bit value and the code will print a random value
printf("%d\n", 1LL);
```

Neste caso, o bug pode ser corrigido certificando-se de que a especificação de formato correta seja usada para que o alinhamento do argumento seja considerado. Este código está correto:

```C
// CORRECT: use %I64d for 64-bit integers
printf("%I64d\n", 1LL);
```

### <a name="argument-evaluation-order"></a>Ordem de avaliação de argumentos

Como os processadores ARM, x86 e x64 são tão diferentes, eles podem apresentar diferentes requisitos para implementações de compiladores, e também diferentes oportunidades de otimização. Por causa disso, juntamente com outros fatores como configurações de convenção de chamada e otimização, um compilador pode avaliar argumentos de função em uma ordem diferente em diferentes arquiteturas ou quando os outros fatores são alterados. Isso pode causar o comportamento de um aplicativo que depende de uma ordem de avaliação específica para mudar inesperadamente.

Esse tipo de erro pode ocorrer quando argumentos para uma função têm efeitos colaterais que impactam outros argumentos para a função na mesma chamada. Geralmente esse tipo de dependência é fácil de evitar, mas às vezes pode ser obscurecida por dependências difíceis de discernir, ou por sobrecarga do operador. Considere este exemplo de código:

```cpp
handle memory_handle;

memory_handle->acquire(*p);
```

Isso parece bem definido, `->` `*` mas se e forem operadores sobrecarregados, então este código é traduzido para algo que se assemelha a isso:

```cpp
Handle::acquire(operator->(memory_handle), operator*(p));
```

E se houver uma dependência `operator->(memory_handle)` `operator*(p)`entre e , o código pode depender de uma ordem de avaliação específica, mesmo que o código original pareça que não há dependência possível.

### <a name="volatile-keyword-default-behavior"></a>comportamento padrão de palavra-chave volátil

O compilador MSVC suporta duas interpretações `volatile` diferentes do qualificador de armazenamento que você pode especificar usando switches compiladores. O switch [/volátil:ms](reference/volatile-volatile-keyword-interpretation.md) seleciona a semântica volátil estendida da Microsoft que garante um forte pedido, como tem sido o caso tradicional para x86 e x64 por causa do modelo de memória forte nessas arquiteturas. O [interruptor /volátil:iso seleciona](reference/volatile-volatile-keyword-interpretation.md) a semântica volátil padrão C++ estrita que não garante uma forte encomenda.

Na arquitetura ARM, o padrão é **/volátil:iso** porque os processadores ARM têm um modelo de memória fracamente ordenado, e porque o software ARM não tem um legado de confiar na semântica estendida de **/volátil:ms** e geralmente não precisa interagir com o software que o faz. No entanto, ainda é às vezes conveniente ou mesmo necessário para compilar um programa ARM para usar a semântica estendida. Por exemplo, pode ser muito caro portar um programa para usar a semântica ISO C++, ou o software do driver pode ter que aderir à semântica tradicional para funcionar corretamente. Nestes casos, você pode usar o interruptor **/volátil:ms;** no entanto, para recriar a semântica volátil tradicional em alvos ARM, o `volatile` compilador deve inserir barreiras de memória em torno de cada leitura ou gravação de uma variável para impor uma forte ordenação, o que pode ter um impacto negativo no desempenho.

Nas arquiteturas x86 e x64, o padrão é **/volátil:ms** porque grande parte do software que já foi criado para essas arquiteturas usando MSVC depende deles. Ao compilar programas x86 e x64, você pode especificar o interruptor **/volátil:iso** para ajudar a evitar a dependência desnecessária da semântica volátil tradicional e promover a portabilidade.

## <a name="see-also"></a>Confira também

[Configurar o Visual C++ para processadores ARM](configuring-programs-for-arm-processors-visual-cpp.md)
