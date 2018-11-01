---
title: Problemas de migração ARM do Visual C++
ms.date: 11/04/2016
ms.assetid: 0f4c434e-0679-4331-ba0a-cc15dd435a46
ms.openlocfilehash: 6aea623bc9f096265decbe91ccdc5d5f1f6ecef1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618500"
---
# <a name="common-visual-c-arm-migration-issues"></a>Problemas de migração ARM do Visual C++

Ao usar o Microsoft Visual C++ (MSVC), o mesmo código-fonte C++ pode produzir resultados diferentes na arquitetura ARM do que em arquiteturas x86 ou x64.

## <a name="sources-of-migration-issues"></a>Fontes de problemas de migração

Muitos problemas que você pode encontrar quando migrar código das arquiteturas x86 ou x64 para a arquitetura do ARM estão relacionados a construções de código-fonte que podem invocar um comportamento indefinido, definido pela implementação ou não especificado.

*Um comportamento indefinido* é o comportamento que o padrão C++ não define e que é causada por uma operação com nenhum resultado razoável: por exemplo, converter um valor de ponto flutuante para um inteiro sem sinal ou um valor de deslocamento de um número de posições que é negativo ou exceder o número de bits no tipo promovido.

*Comportamento definido pela implementação* é o comportamento que o padrão C++ requer que o fornecedor de compilador para definir e documentar. Um programa com segurança pode confiar no comportamento definido pela implementação, mesmo que fazer caso pode não ser portátil. Exemplos de comportamento definido pela implementação incluem os tamanhos dos tipos de dados internos e seus requisitos de alinhamento. Um exemplo de uma operação que pode ser afetado pelo comportamento definido pela implementação está acessando a lista de argumentos variáveis.

*Não for especificado o comportamento* é o comportamento padrão do C++ deixa intencionalmente não determinístico. Embora o comportamento seja considerado não determinístico, invocações particulares do comportamento não especificado são determinadas pela implementação do compilador. No entanto, há nenhum requisito para um fornecedor de compilador predeterminar o resultado ou garantir um comportamento consistente entre invocações comparáveis e não há nenhum requisito para a documentação. Um exemplo de comportamento não especificado é a ordem na qual as subexpressões, que incluem argumentos para uma chamada de função, são avaliadas.

Outros problemas de migração podem ser atribuídos às diferenças de hardware entre o ARM e arquiteturas x86 ou x64 que interagem com o padrão C++ de forma diferente. Por exemplo, o modelo de memória forte da arquitetura x86 e x64 oferece `volatile`-qualificado variáveis algumas propriedades adicionais que foram usadas para facilitar a determinados tipos de comunicação entre threads no passado. Mas o modelo de memória fraco da arquitetura ARM não dá suporte a esse uso, nem o padrão C++ requê-lo.

> [!IMPORTANT]
>  Embora `volatile` ganhos de algumas propriedades que podem ser usadas para implementar limitadas formas de comunicação entre threads em x86 e x64, essas propriedades adicionais não são suficientes para implementar de comunicação de thread entre em geral. O padrão do C++ recomenda que essa comunicação ser implementado usando primitivos de sincronização apropriado em vez disso.

Como diferentes plataformas podem express esses tipos de comportamento de forma diferente, a portabilidade de software entre plataformas pode ser difícil e propensa a bugs se ele depende do comportamento de uma plataforma específica. Embora muitos desses tipos de comportamento podem ser observados e podem aparecer estáveis, confiar nelas é pelo menos não portátil e, no caso de um comportamento indefinido ou não especificado, também é um erro. Até mesmo o comportamento que é citado neste documento não deve ser usado em e pode mudar no futuro, os compiladores ou implementações de CPU.

## <a name="example-migration-issues"></a>Problemas de migração de exemplo

O restante deste documento descreve como o comportamento diferente desses elementos de linguagem C++ pode produzir resultados diferentes em diferentes plataformas.

### <a name="conversion-of-floating-point-to-unsigned-integer"></a>Conversão de ponto flutuante para o inteiro sem sinal

Na arquitetura ARM, a conversão de um valor de ponto flutuante para um inteiro de 32 bits esteja saturado para o valor mais próximo que o inteiro pode representar se o valor de ponto flutuante está fora do intervalo que o inteiro pode representar. Em arquiteturas x86 e x64, a conversão encapsulá-se o inteiro não estiver assinado ou é definido como -2147483648 se o inteiro é assinado. Nenhum arquiteturas diretamente dão suporte à conversão de valores de ponto flutuante em tipos de inteiro menores; em vez disso, as conversões são executadas para 32 bits, e os resultados são truncados para um tamanho menor.

Para a arquitetura ARM, a combinação de saturação e truncamento significa que a conversão em tipos não assinados corretamente esteja saturado tipos sem sinal de menores quando ele esteja saturado um inteiro de 32 bits, mas produz um resultado truncado para valores que são maiores do que o tipo menor pode representar, mas muito pequeno para saturar o inteiro de 32 bits completo. Conversão também esteja saturado corretamente para inteiros com sinal de 32 bits, mas o truncamento de inteiros com sinal, saturados resulta em -1 para valores positivamente saturada e 0 para valores negativamente saturado. A conversão em um inteiro com sinal menor produz um resultado truncado que é imprevisível.

Para arquiteturas x86 e x64, a combinação de comportamento de delimitadores para conversões de inteiro sem sinal e avaliação explícita para conversões de inteiro com sinal no estouro, junto com o truncamento, verifique os resultados para a maioria dos turnos imprevisíveis se eles forem muito grande.

Essas plataformas também diferem em como eles lidam com conversão de NaN (não um número) para tipos de inteiro. No ARM, NaN converte 0x00000000; em x86 e x64, ele converte em 0x80000000.

Conversão de ponto flutuante só pode ser usada em se você souber que o valor está dentro do intervalo do tipo inteiro que ele está sendo convertido em.

### <a name="shift-operator---behavior"></a>Operador de deslocamento (\< \< >>) comportamento

Na arquitetura ARM, um valor pode ser deslocados para a esquerda ou à direita até 255 bits antes que o padrão comece a ser repetido. Em arquiteturas x86 e x64, o padrão é repetido em cada múltiplo de 32, a menos que a origem do padrão é uma variável de 64 bits; Nesse caso, o padrão se repete em cada múltiplo de 64 no x64, e cada múltiplo de 256 em x86, em que uma implementação de software é empregada. Por exemplo, para uma variável de 32 bits que tem um valor de 1 deslocados para a esquerda por 32 posições, no ARM, o resultado é 0, em x86, o resultado será 1 e em x64 o resultado também é 1. No entanto, se a origem do valor é uma variável de 64 bits, em seguida, o resultado em todas as três plataformas é 4294967296 e o valor não "encapsular" até que ele foi deslocada 64 posições em x64 ou 256 posições no ARM e x86.

Como o resultado de uma operação de deslocamento que excede o número de bits no tipo de origem é indefinido, o compilador não deve ter um comportamento consistente em todas as situações. Por exemplo, se ambos os operandos de um turno são conhecidos em tempo de compilação, o compilador pode otimizar o programa usando uma rotina interna para pré-calcular o resultado do turno e, em seguida, substituindo o resultado no lugar da operação de deslocamento. Se o valor de deslocamento é muito grande ou negativo, o resultado da rotina interno pode ser diferente que o resultado da expressão shift mesmo executadas pela CPU.

### <a name="variable-arguments-varargs-behavior"></a>Comportamento de argumentos variáveis (varargs)

Na arquitetura ARM, os parâmetros da lista de argumentos variáveis que são passados na pilha estão sujeitos a alinhamento. Por exemplo, um parâmetro de 64 bits é alinhado em um limite de 64 bits. Em x86 e x64, argumentos que são passados na pilha não são sujeitos a alinhamento e pacote rigidamente. Essa diferença pode causar uma função variadic como `printf` para ler os endereços de memória que pretendiam como preenchimento no ARM se o layout previsto da lista de argumentos variável não tiver uma correspondência exata, mesmo que ele pode funcionar para um subconjunto de alguns valores no x86 ou x64 arquiteturas. Considere este exemplo:

```C
// notice that a 64-bit integer is passed to the function, but '%d' is used to read it.
// on x86 and x64 this may work for small values because %d will “parse” the low-32 bits of the argument.
// on ARM the calling convention will align the 64-bit value and the code will print a random value
printf("%d\n", 1LL);
```

Nesse caso, o bug pode ser corrigido, certificando-se de que a especificação de formato correto é usada para que o alinhamento do argumento é considerado. Esse código está correto:

```C
// CORRECT: use %I64d for 64-bit integers
printf("%I64d\n", 1LL);
```

### <a name="argument-evaluation-order"></a>Ordem de avaliação de argumentos

Porque o ARM, x86 e x64 processadores são tão diferentes, eles podem apresentar requisitos diferentes para implementações de compilador e oportunidades diferentes para otimizações. Por isso, junto com outros fatores, como configurações de convenção de chamada e a otimização, um compilador pode avaliar os argumentos de função em uma ordem diferente em diferentes arquiteturas, ou quando os outros fatores são alterados. Isso pode causar o comportamento de um aplicativo que se baseia em uma ordem de classificação específica a ser alterado inesperadamente.

Esse tipo de erro pode ocorrer quando os argumentos para uma função tem efeitos colaterais que afetam outros argumentos para a função na mesma chamada. Normalmente, esse tipo de dependência é fácil evitar, mas, às vezes, pode ser obscurecido por dependências que são difíceis de serem assimilados ou pela sobrecarga de operador. Considere este exemplo de código:

```cpp
handle memory_handle;

memory_handle->acquire(*p);
```

Isso parece bem definido, mas se `->` e `*` são operadores sobrecarregados, em seguida, esse código é convertido em algo que se parece com isso:

```cpp
Handle::acquire(operator->(memory_handle), operator*(p));
```

E se há uma dependência entre `operator->(memory_handle)` e `operator*(p)`, o código pode depender de uma ordem de classificação específica, mesmo que o código original se parece com não há nenhuma dependência possíveis.

### <a name="volatile-keyword-default-behavior"></a>comportamento padrão de palavra-chave volátil

O compilador MSVC dá suporte a dois diversas interpretações do `volatile` qualificador de armazenamento que você pode especificar usando opções do compilador. O [/volatile: MS](../build/reference/volatile-volatile-keyword-interpretation.md) switch seleciona a estendidas semântica volátil que garantem a ordenação de alta segurança, pois foi o caso tradicional para x86 e x64 por causa do modelo de memória alta segurança nessas arquiteturas da Microsoft. O [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) switch seleciona a estrito C++ standard semântica volátil que não garante a ordenação de alta segurança.

Na arquitetura ARM, o padrão é **/volatile: ISO** como processadores ARM têm um fracamente ordenados de modelo de memória e como software ARM não tem um herdado de contar com a semântica estendida de **/volatile: MS**  e geralmente não tem a interface com o software que faz. No entanto, é conveniente ainda, às vezes, ou até mesmo necessário para compilar um programa ARM, use a semântica estendida. Por exemplo, ele pode ser muito caro portar um programa para usar a semântica do ISO C++ ou talvez seja necessário que o software de driver seguem a semântica tradicional para funcionar corretamente. Nesses casos, você pode usar o **/volatile: MS** comutador; no entanto, para recriar a semântica volátil tradicional em destinos ARM, o compilador deve inserir barreiras de memória em torno de cada leitura ou gravação de um `volatile` variável impor ordenação de alta segurança, que pode ter um impacto negativo no desempenho.

Em arquiteturas x86 e x64, o padrão é **/volatile: MS** porque grande parte do software que já foi criado para essas arquiteturas usando MSVC dependa delas. Quando você compila programas x86 e x64, você pode especificar o **/volatile: ISO** alterne para ajudar a evitar desnecessário depender da semântica volátil tradicional e, para promover a portabilidade.

## <a name="see-also"></a>Consulte também

[Configurar o Visual C++ para processadores ARM](../build/configuring-programs-for-arm-processors-visual-cpp.md)
