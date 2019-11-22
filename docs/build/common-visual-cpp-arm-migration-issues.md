---
title: Problemas de migração ARM do Visual C++
ms.date: 05/06/2019
ms.assetid: 0f4c434e-0679-4331-ba0a-cc15dd435a46
ms.openlocfilehash: 518b8872b301a8fcfc0f154cb3d5d0299efb0975
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303226"
---
# <a name="common-visual-c-arm-migration-issues"></a>Problemas de migração ARM do Visual C++

Ao usar o compilador C++ da Microsoft (MSVC), o C++ mesmo código-fonte pode produzir resultados diferentes na arquitetura ARM do que em arquiteturas x86 ou x64.

## <a name="sources-of-migration-issues"></a>Fontes de problemas de migração

Muitos problemas que você pode encontrar ao migrar código das arquiteturas x86 ou x64 para a arquitetura ARM estão relacionados a construções de código-fonte que podem invocar comportamento indefinido, definido pela implementação ou não especificado.

O *comportamento indefinido* é o comportamento C++ que o padrão não define, e isso é causado por uma operação que não tem nenhum resultado razoável: por exemplo, converter um valor de ponto flutuante em um inteiro não assinado ou deslocar um valor por um número de posições que é negativo ou excede o número de bits em seu tipo promovido.

O *comportamento definido pela implementação* é o comportamento C++ que o padrão exige que o fornecedor do compilador defina e documente. Um programa pode depender com segurança do comportamento definido pela implementação, mesmo que isso possa não ser portátil. Exemplos de comportamento definido pela implementação incluem os tamanhos de tipos de dados internos e seus requisitos de alinhamento. Um exemplo de uma operação que pode ser afetada pelo comportamento definido pela implementação é acessar a lista de argumentos variáveis.

O *comportamento não especificado* é o comportamento C++ que o padrão deixa intencionalmente não determinístico. Embora o comportamento seja considerado não determinístico, invocações específicas de comportamento não especificado são determinadas pela implementação do compilador. No entanto, não há nenhum requisito para um fornecedor de compilador predeterminar o resultado ou garantir o comportamento consistente entre invocações comparáveis e não há nenhum requisito para a documentação. Um exemplo de comportamento não especificado é a ordem em que as subexpressãos, que incluem argumentos para uma chamada de função, são avaliadas.

Outros problemas de migração podem ser atribuídos a diferenças de hardware entre arquiteturas ARM e x86 ou x64 que interagem com o padrão de C++ forma diferente. Por exemplo, o modelo de memória forte da arquitetura x86 e x64 fornece variáveis qualificadas para `volatile`algumas propriedades adicionais que foram usadas para facilitar determinados tipos de comunicação entre threads no passado. Mas o modelo de memória fraca da arquitetura ARM não dá suporte a esse uso, C++ nem o padrão exige.

> [!IMPORTANT]
>  Embora `volatile` Obtenha algumas propriedades que podem ser usadas para implementar formas limitadas de comunicação entre threads em x86 e x64, essas propriedades adicionais não são suficientes para implementar a comunicação entre threads em geral. O C++ padrão recomenda que essa comunicação seja implementada usando primitivos de sincronização apropriados em vez disso.

Como diferentes plataformas podem expressar esses tipos de comportamento de forma diferente, portar o software entre plataformas pode ser difícil e propenso a bugs se depender do comportamento de uma plataforma específica. Embora muitos desses tipos de comportamento possam ser observados e possam parecer estáveis, confiar neles é pelo menos não-portátil e, nos casos de comportamento indefinido ou não especificado, também é um erro. Até mesmo o comportamento citado neste documento não deve ser confiado e pode mudar em compiladores futuros ou implementações de CPU.

## <a name="example-migration-issues"></a>Exemplos de problemas de migração

O restante deste documento descreve como o comportamento diferente desses elementos de C++ linguagem pode produzir resultados diferentes em diferentes plataformas.

### <a name="conversion-of-floating-point-to-unsigned-integer"></a>Conversão de ponto flutuante para inteiro sem sinal

Na arquitetura ARM, a conversão de um valor de ponto flutuante em um inteiro de 32 bits satura o valor mais próximo que o inteiro pode representar se o valor de ponto flutuante estiver fora do intervalo que o inteiro pode representar. Nas arquiteturas x86 e x64, a conversão será encapsulada se o inteiro for não assinado ou será definido como-2147483648 se o número inteiro for assinado. Nenhuma dessas arquiteturas dá suporte direto à conversão de valores de ponto flutuante para tipos de inteiro menores; em vez disso, as conversões são executadas em 32 bits e os resultados são truncados para um tamanho menor.

Para a arquitetura ARM, a combinação de saturação e truncamento significa que a conversão para tipos não assinados satura corretamente os tipos menores não assinados quando ele satura um inteiro de 32 bits, mas produz um resultado truncado para valores maiores do que o o tipo menor pode representar, porém, muito pequeno para saturar o inteiro de 32 bits completo. A conversão também satura corretamente para inteiros com sinal de 32 bits, mas o truncamento de números inteiros saturados e assinados resulta em-1 para valores saturados de forma positiva e 0 para valores saturados negativamente. A conversão para um inteiro com sinal menor produz um resultado truncado que é imprevisível.

Para as arquiteturas x86 e x64, a combinação de comportamento de encapsulamento para conversões de inteiros não assinados e a validação explícita para conversões de inteiros assinadas no estouro, junto com o truncamento, torna os resultados para a maioria dos turnos imprevisíveis se forem muito grande.

Essas plataformas também diferem em como elas tratam a conversão de NaN (não-a-número) em tipos inteiros. No ARM, NaN converte para 0x00000000; em x86 e x64, ele converte para 0x80000000.

A conversão de ponto flutuante só poderá ser contada se você souber que o valor está dentro do intervalo do tipo inteiro no qual ele está sendo convertido.

### <a name="shift-operator---behavior"></a>Comportamento do operador SHIFT (\<\< > >)

Na arquitetura ARM, um valor pode ser deslocado para a esquerda ou para a direita até 255 bits antes de o padrão começar a ser repetido. Em arquiteturas x86 e x64, o padrão é repetido em cada múltiplo de 32, a menos que a origem do padrão seja uma variável de 64 bits; Nesse caso, o padrão se repete em cada múltiplo de 64 em x64 e em cada múltiplo de 256 em x86, em que uma implementação de software é empregada. Por exemplo, para uma variável de 32 bits que tem um valor de 1 deslocado de 32 posições, no ARM, o resultado é 0, em x86, o resultado é 1 e, em x64, o resultado também é 1. No entanto, se a origem do valor for uma variável de 64 bits, o resultado em todas as três plataformas será 4294967296, e o valor não "quebrará" até que seja deslocado 64 posições nas posições x64 ou 256 no ARM e no x86.

Como o resultado de uma operação de deslocamento que excede o número de bits no tipo de origem é indefinido, o compilador não precisa ter um comportamento consistente em todas as situações. Por exemplo, se ambos os operandos de um turno forem conhecidos no momento da compilação, o compilador poderá otimizar o programa usando uma rotina interna para pré-calcular o resultado da mudança e, em seguida, substituindo o resultado no lugar da operação de deslocamento. Se o valor de deslocamento for muito grande ou negativo, o resultado da rotina interna poderá ser diferente do resultado da mesma expressão de deslocamento executada pela CPU.

### <a name="variable-arguments-varargs-behavior"></a>Comportamento de argumentos variáveis (varargs)

Na arquitetura ARM, os parâmetros da lista de argumentos variáveis que são passados na pilha estão sujeitos ao alinhamento. Por exemplo, um parâmetro de 64 bits é alinhado em um limite de 64 bits. Em x86 e x64, os argumentos que são passados na pilha não estão sujeitos a alinhamento e pacote rigidamente. Essa diferença pode causar uma função Variadic como `printf` para ler os endereços de memória que se destinam como preenchimento no ARM se o layout esperado da lista de argumentos variáveis não for correspondido exatamente, mesmo que possa funcionar para um subconjunto de alguns valores nas arquiteturas x86 ou x64. Considere este exemplo:

```C
// notice that a 64-bit integer is passed to the function, but '%d' is used to read it.
// on x86 and x64 this may work for small values because %d will "parse" the low-32 bits of the argument.
// on ARM the calling convention will align the 64-bit value and the code will print a random value
printf("%d\n", 1LL);
```

Nesse caso, o bug pode ser corrigido verificando se a especificação de formato correta é usada para que o alinhamento do argumento seja considerado. Este código está correto:

```C
// CORRECT: use %I64d for 64-bit integers
printf("%I64d\n", 1LL);
```

### <a name="argument-evaluation-order"></a>Ordem de avaliação do argumento

Como os processadores ARM, x86 e x64 são tão diferentes, eles podem apresentar requisitos diferentes para implementações de compilador e também oportunidades diferentes para otimizações. Por isso, junto com outros fatores, como as configurações de Convenção de chamada e de otimização, um compilador pode avaliar argumentos de função em uma ordem diferente em arquiteturas diferentes ou quando os outros fatores são alterados. Isso pode fazer com que o comportamento de um aplicativo que depende de uma ordem de avaliação específica seja alterado inesperadamente.

Esse tipo de erro pode ocorrer quando argumentos para uma função têm efeitos colaterais que afetam outros argumentos para a função na mesma chamada. Geralmente, esse tipo de dependência é fácil de evitar, mas às vezes pode ser obscurecido por dependências difíceis de discernir ou por sobrecarga de operador. Considere este exemplo de código:

```cpp
handle memory_handle;

memory_handle->acquire(*p);
```

Isso aparece bem definido, mas se `->` e `*` forem operadores sobrecarregados, esse código será convertido em algo parecido com este:

```cpp
Handle::acquire(operator->(memory_handle), operator*(p));
```

E se houver uma dependência entre `operator->(memory_handle)` e `operator*(p)`, o código poderá depender de uma ordem de avaliação específica, mesmo que o código original pareça que não há nenhuma dependência possível.

### <a name="volatile-keyword-default-behavior"></a>comportamento padrão de palavra-chave volátil

O compilador MSVC dá suporte a duas interpretações diferentes do qualificador de armazenamento `volatile` que você pode especificar usando opções de compilador. O comutador [/volatile: MS](reference/volatile-volatile-keyword-interpretation.md) seleciona a semântica volátil estendida da Microsoft que garante uma ordenação forte, como foi o caso tradicional para x86 e x64 devido ao modelo de memória forte nessas arquiteturas. O comutador [/volatile: ISO](reference/volatile-volatile-keyword-interpretation.md) seleciona a C++ semântica volátil padrão estrita que não garante a ordenação forte.

Na arquitetura ARM, o padrão é **/volatile: ISO** , pois os processadores ARM têm um modelo de memória de ordem fraco, e como o software ARM não tem um herdado de depender da semântica estendida de **/volatile: MS** e normalmente não tem que fazer a interface com o software que o faz. No entanto, às vezes é conveniente ou até mesmo necessário compilar um programa ARM para usar a semântica estendida. Por exemplo, pode ser muito dispendioso para portar um programa para usar a semântica C++ ISO, ou o software de driver pode ter que aderir à semântica tradicional para funcionar corretamente. Nesses casos, você pode usar o comutador **/volatile: MS** ; no entanto, para recriar a semântica volátil tradicional em destinos do ARM, o compilador deve inserir barreiras de memória em volta de cada leitura ou gravação de uma variável `volatile` para impor uma ordenação forte, o que pode ter um impacto negativo no desempenho.

Nas arquiteturas x86 e x64, o padrão é **/volatile: MS** porque grande parte do software que já foi criado para essas arquiteturas usando o MSVC depende deles. Ao compilar programas x86 e x64, você pode especificar a opção **/volatile: ISO** para ajudar a evitar a dependência desnecessária da semântica volátil tradicional e promover a portabilidade.

## <a name="see-also"></a>Consulte também

[Configurar o Visual C++ para processadores ARM](configuring-programs-for-arm-processors-visual-cpp.md)
