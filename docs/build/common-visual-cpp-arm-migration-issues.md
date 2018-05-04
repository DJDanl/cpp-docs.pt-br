---
title: Problemas comuns de migração de ARM do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 0f4c434e-0679-4331-ba0a-cc15dd435a46
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 04253b5d71de75f6a06f2934dae24df2e6d4e3e2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="common-visual-c-arm-migration-issues"></a>Problemas de migração ARM do Visual C++

Ao usar o Microsoft Visual C++ (MSVC), o mesmo código-fonte C++ pode produzir resultados diferentes na arquitetura ARM do que em arquiteturas x86 ou x64.

## <a name="sources-of-migration-issues"></a>Fontes de problemas de migração

Muitos problemas que você pode encontrar quando migrar código das arquiteturas x86 ou x64 para a arquitetura ARM estão relacionados a construções de código-fonte que podem invocar o comportamento indefinido, definido pela implementação ou não especificado.

*Comportamento indefinido* é o comportamento padrão do C++ não define e que é causada por uma operação com nenhum resultado razoável: por exemplo, converter um valor de ponto flutuante para um inteiro sem sinal, ou um valor de deslocamento de um número de posições que é negativo ou excede o número de bits no seu tipo promovido.

*Comportamento definido pela implementação* é o comportamento padrão do C++ requer o fornecedor do compilador para definir e documentos. Um programa com segurança pode contar com comportamento definido pela implementação, mesmo que fazer assim pode não ser portátil. Exemplos de comportamento definido pela implementação incluem os tamanhos de tipos de dados internos e os requisitos de alinhamento. Um exemplo de uma operação que pode ser afetado pelo comportamento definido pela implementação está acessando a lista de argumentos variável.

*Não for especificado o comportamento* é o comportamento padrão do C++ deixa intencionalmente não determinística. Embora o comportamento é considerado não determinística, invocações específicas de comportamento especificado são determinadas pela implementação do compilador. No entanto, não há nenhum requisito para um fornecedor de compilador predeterminar o resultado ou garantir um comportamento consistente entre invocações comparáveis, e não há nenhum requisito para documentação. Um exemplo de comportamento não especificado é a ordem na qual subexpressões, que inclui argumentos para uma chamada de função, são avaliadas.

Outros problemas de migração podem ser atribuídos a diferenças de hardware entre ARM e arquiteturas x86 ou x64 que interagem com o C++ padrão de forma diferente. Por exemplo, o modelo de memória forte da arquitetura x86 e x64 fornece `volatile`-qualificado variáveis algumas propriedades adicionais que foram usadas para facilitar a determinados tipos de comunicação entre thread no passado. Mas modelo de memória baixa segurança da arquitetura ARM não dá suporte a esse uso, nem o padrão C++ requê-lo.

> [!IMPORTANT]
>  Embora `volatile` ganhos algumas propriedades que podem ser usadas para implementar limitadas formas de comunicação entre thread em x86 e x64, essas propriedades adicionais não são suficientes para implementar entre threads comunicação em geral. O padrão C++ recomenda que essa comunicação ser implementada usando primitivos de sincronização apropriado em vez disso.

Como diferentes plataformas podem express esses tipos de comportamento de forma diferente, movimentando software entre plataformas pode ser difícil e bug propensas a se ele depende do comportamento de uma plataforma específica. Embora muitos desses tipos de comportamento podem ser observados e podem aparecer estáveis, confiar neles é pelo menos não-portáteis e, no caso de um comportamento indefinido ou não especificado, também é um erro. Até mesmo o comportamento que é citado neste documento não deve ser usado e foi possível alterar futuramente compiladores ou implementações de CPU.

## <a name="example-migration-issues"></a>Problemas de migração de exemplo

O restante deste documento descreve como o comportamento diferente desses elementos de linguagem do C++ pode produzir resultados diferentes em diferentes plataformas.

### <a name="conversion-of-floating-point-to-unsigned-integer"></a>Conversão de ponto flutuante para inteiro sem sinal

Na arquitetura ARM, conversão de um valor de ponto flutuante para um inteiro de 32 bits esteja saturado para o valor mais próximo que o número inteiro pode representar se o valor de ponto flutuante está fora do intervalo que pode representar o número inteiro. Em arquiteturas x86 e x64, a conversão envolve se o número inteiro não está assinado ou é definido como -2147483648 se o inteiro assinado. Nenhum essas arquiteturas suporte diretamente a conversão de valores de ponto flutuante para tipos de inteiro menores; em vez disso, as conversões são executadas para 32 bits, e os resultados são truncados para um tamanho menor.

Para a arquitetura ARM, a combinação de saturação e truncamento significa que a conversão em tipos não assinados corretamente esteja saturado menores tipos não assinados em esteja saturado um inteiro de 32 bits, mas produz um resultado truncado para valores que são maiores do que o tipo menor pode representar mas muito pequeno para saturar o inteiro de 32 bits completa. Conversão também esteja saturado corretamente para inteiros com sinal de 32 bits, mas o truncamento de inteiros saturados, assinados resulta em -1 para valores positivamente saturada e 0 para valores negativamente saturada. Conversão para um inteiro assinado menor produz um resultado truncado que é imprevisível.

Para arquiteturas x86 e x64, a combinação de comportamento de delimitadores para conversões de número inteiro sem sinal e avaliação explícita para conversões de inteiro no estouro, junto com o truncamento, verifique os resultados para a maioria das mudanças imprevisíveis se eles estiverem muito grande.

Essas plataformas também diferem no modo como tratam a conversão de NaN (não um número) para tipos de inteiro. Em ARM, NaN converte 0x00000000; em x86 e x64, converte 0x80000000.

Conversão de ponto flutuante pode apenas ser usada se você souber que o valor está dentro do intervalo do tipo inteiro que ele está sendo convertido em.

### <a name="shift-operator---behavior"></a>Operador de deslocamento (\< \< >>) comportamento

Na arquitetura ARM, um valor pode ser transferido para a esquerda ou direita até 255 bits antes de começa o padrão repetir. Em arquiteturas x86 e x64, o padrão é repetido em cada múltiplo de 32 a menos que a origem do padrão é uma variável de 64 bits; Nesse caso, o padrão se repete a cada múltiplo de 64 em x64, e cada múltiplo de 256 em x86, onde uma implementação de software é utilizada. Por exemplo, para uma variável de 32 bits que tem um valor de 1 deslocada à esquerda por 32 posições, em ARM o resultado é 0, x86, o resultado será 1 e em x64 o resultado também será 1. No entanto, se a fonte do valor é uma variável de 64 bits, em seguida, o resultado em todas as plataformas de três é 4294967296 e o valor não "delimitado" até que ele mudou 64 posições em x64 ou 256 posições em ARM e x86.

Como o resultado de uma operação de shift que excede o número de bits no tipo de origem é indefinido, o compilador não deve ter um comportamento consistente em todas as situações. Por exemplo, se ambos os operandos de um turno são conhecidos no tempo de compilação, o compilador pode otimizar o programa usando uma rotina interna para pré-calcular o resultado do turno e, em seguida, substituindo o resultado em vez da operação de turno. Se o valor de deslocamento é muito grande ou negativo, o resultado da rotina interno pode ser diferente que o resultado da expressão shift mesmo executadas pela CPU.

### <a name="variable-arguments-varargs-behavior"></a>Comportamento de argumentos de variável (varargs)

Na arquitetura ARM, os parâmetros da lista de argumentos variáveis que são passados na pilha estão sujeitos alinhamento. Por exemplo, um parâmetro de 64 bits é alinhado em um limite de 64 bits. Em x86 e x64, argumentos que são passados na pilha não estão sujeitos alinhamento e pacote totalmente. Essa diferença pode causar uma função variadic como `printf` para ler os endereços de memória criadas como preenchimento ARM se o layout esperado da lista de argumentos variável não corresponder exatamente, mesmo que ele pode funcionar para um subconjunto de alguns valores em x86 ou x64 arquiteturas. Considere este exemplo:

```C
// notice that a 64-bit integer is passed to the function, but '%d' is used to read it.
// on x86 and x64 this may work for small values because %d will “parse” the low-32 bits of the argument.
// on ARM the calling convention will align the 64-bit value and the code will print a random value
printf("%d\n", 1LL);
```

Nesse caso, o erro pode ser corrigido, certificando-se de que a especificação de formato correto é usada para que o alinhamento do argumento é considerado. Esse código está correto:

```C
// CORRECT: use %I64d for 64-bit integers
printf("%I64d\n", 1LL);
```

### <a name="argument-evaluation-order"></a>Ordem de avaliação de argumento

Porque ARM, x86 e x64 processadores são tão diferentes, eles podem apresentar requisitos diferentes implementações de compilador e oportunidades diferentes para otimizações. Por isso, junto com outros fatores, como configurações de convenção de chamada e otimização, um compilador pode avaliar os argumentos de função em uma ordem diferente em arquiteturas diferentes ou quando os outros fatores são alterados. Isso pode causar o comportamento de um aplicativo que se baseia em uma ordem de avaliação específicos para alterar inesperadamente.

Esse tipo de erro pode ocorrer quando uma função tem efeitos colaterais que afetam outros argumentos da função na mesma chamada. Geralmente é fácil de evitar esse tipo de dependência, mas às vezes pode ser encoberta dependências que são difíceis de distinguir ou sobrecarga de operador. Considere este exemplo de código:

```cpp
handle memory_handle;

memory_handle->acquire(*p);
```

Isso aparece bem definido, mas se `->` e `*` são operadores sobrecarregados, em seguida, esse código é convertido para algo semelhante a isso:

```cpp
Handle::acquire(operator->(memory_handle), operator*(p));
```

E se há uma dependência entre `operator->(memory_handle)` e `operator*(p)`, o código pode depender de uma ordem de avaliação específico, mesmo que o código original pareça não há nenhuma dependência possíveis.

### <a name="volatile-keyword-default-behavior"></a>comportamento padrão de palavra-chave volatile

O compilador MSVC dá suporte a dois diferentes interpretações do `volatile` qualificador de armazenamento que você pode especificar usando opções do compilador. O [/volatile:ms](../build/reference/volatile-volatile-keyword-interpretation.md) opção seleciona o Microsoft estendidos semântica voláteis que garantem a ordenação de alta segurança, como foi o caso tradicional para x86 e x64 devido ao modelo de memória forte sobre essas arquiteturas. O [/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) opção seleciona a estrito C++ padrão voláteis semântica não garante a ordenação de alta segurança.

Na arquitetura ARM, o padrão é **/volatile:iso** como processadores ARM têm um fraco ordenados do modelo de memória e software ARM não tem um herdado de contar com a semântica estendida de **/volatile:ms**  e geralmente não tem a interface com o software que faz. No entanto, é conveniente ainda, às vezes, ou até mesmo necessários para compilar um programa ARM para usar a semântica estendida. Por exemplo, pode ser muito caro para a porta de um programa, use a semântica de ISO C++ ou software de driver talvez precise cumprir a semântica tradicional para funcionar corretamente. Nesses casos, você pode usar o **/volatile:ms** comutador; no entanto, para recriar a semântica volátil tradicional em destinos do ARM, o compilador deve inserir barreiras de memória em torno de cada leitura ou gravação de um `volatile` variável para impor ordenação de alta segurança, que pode ter um impacto negativo no desempenho.

Em arquiteturas x86 e x64, o padrão é **/volatile:ms** porque grande parte do software que já foi criado para essas arquiteturas usando MSVC depende deles. Quando você compila programas x86 e x64, você pode especificar o **/volatile:iso** switch para ajudar a evitar o desnecessária depende da semântica volátil tradicional e para promover a portabilidade.

## <a name="see-also"></a>Consulte também

[Configurar o Visual C++ para processadores ARM](../build/configuring-programs-for-arm-processors-visual-cpp.md)  
