---
title: "Problemas de migra&#231;&#227;o ARM do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 0f4c434e-0679-4331-ba0a-cc15dd435a46
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Problemas de migra&#231;&#227;o ARM do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O mesmo código\-fonte Visual C\+\+ pode produzir resultados diferentes em arquitetura de BRAÇO o que torna em arquiteturas ou x 86.  
  
## Fontes de problemas de migração  
 Muitos problemas que você pode encontrar quando você migre o código de x 86 ou as arquiteturas a arquitetura de BRAÇO são relacionados às compilações de origem que podem invocar indefinido, a implementação definidas, ou comportamento não especificado.  
  
 Comportamento indefinido  
 Comportamento que o padrão de C\+\+ não definir, e que é causado por uma operação que tenha não razoável resultado\- por exemplo, converter um valor de ponto flutuante a um número inteiro sem sinal, ou deslocando um valor por um número de posições que é negativo ou excede o número de bits no seu tipo alto.  
  
 Comportamento XML definido  
 Comportamento que o padrão de C\+\+ requer o fornecedor de compilador definir e documentar.  Um programa pode com segurança confiar no comportamento XML definido, mesmo que fazer isso não pode ser portátil.  Exemplos de comportamento XML definido incluem os tamanhos de tipos de dados internos e seus requisitos de alinhamento.  Um exemplo de uma operação que pode ser afetada pelo comportamento XML definido está acessando a lista de argumentos variável.  
  
 Comportamento não especificado  
 Esse comportamento padrão das folhas C\+\+ intencionalmente não determinísticas.  Embora o comportamento é considerado não determinística, as chamadas específicos do comportamento especificado não são determinadas pela implementação do compilador.  No entanto, não há necessidade para um fornecedor de compilador predetermine o resultado ou garante o comportamento consistente entre chamadas comparáveis, e não há necessidade para a documentação.  Um exemplo de comportamento especificado não é a ordem em que secundário\-expressão\- que incluem os argumentos para uma função atendimento\- são avaliados.  
  
 Outros problemas de migração podem ser atribuídos às diferenças de hardware entre o BRAÇO e as arquiteturas ou x 86 que interagem com o padrão de C\+\+ diferente.  Por exemplo, o modelo de memória forte de arquitetura e x 86 fornece `volatile`\- variáveis qualificados algumas propriedades adicionais que foram usadas para facilitar determinados tipos de comunicação de inter\- segmento no passado.  Mas o modelo de memória livre da arquitetura de BRAÇO não suporta esse uso, nem o padrão de C\+\+ requer.  
  
> [!IMPORTANT]
>  Embora `volatile` ganhe algumas propriedades que podem ser usadas para implementar formulários associados de comunicação de inter\- segmento em x 86, e nessas propriedades adicionais não são suficientes para implementar geralmente comunicação de inter\- segmento.  O padrão de C\+\+ recomendável que tal comunicação é implementada usando primitivos apropriadas de sincronização em vez disso.  
  
 Porque as plataformas diferentes podem expressar esses tipos de comportamento diferente, mova o software entre plataformas pode ser difícil e bug\- propenso se depende do comportamento de uma plataforma específica.  Embora muitos desses tipos de comportamento possam ser observados e podem parecer estável, confiar neles não é pelo menos portátil, e no caso de comportamento indefinido ou não especificado, é também um erro.  Mesmo comportamento que é mencionado neste documento não deve ser confiável sobre, e pode mudar os compiladores futuros ou nas implementações de CPU.  
  
## Problemas de migração de exemplo  
 O restante deste documento descreve como o comportamento diferente desses elementos de linguagem do C\+\+ pode produzir resultados diferentes em diferentes plataformas.  
  
### Conversão de ponto flutuante para o número inteiro sem sinal  
 Na arquitetura de BRAÇO, a conversão de um valor de ponto flutuante a um inteiro de 32 bits satura o valor mais próximo que o inteiro pode representar se o valor de ponto flutuante está fora do intervalo que o inteiro pode representar.  Em arquiteturas e x 86, as envolve de conversão ao redor se o inteiro é sem sinal, ou são definidas como \-2147483648 se o número for assinado.  Quaisquer dessas arquiteturas suportam diretamente a conversão de valores de ponto flutuante para tipos menores inteiro; em vez disso, as conversões são executadas a 32 bits, e os resultados são truncados para um tamanho menor.  
  
 Para a arquitetura de BRAÇO, a combinação de saturação e de truncamento significa que a conversão para tipos sem\-sinal satura corretamente tipos sem\-sinal menores quando satura um inteiro de 32 bits, mas gera um resultado truncado para valores que são maiores do que o tipo menor pode representar mas muito pequeno para saturar o inteiro de 32 bits completo.  A conversão também satura corretamente para números inteiros de 32 bits com sinal, mas truncamento de saturado, números inteiros com sinal resulta em \-1 para valores positivo\- saturados e 0 para valores negativo\- saturados.  A conversão para um inteiro com sinal menor gera um resultado truncado que é imprevisível.  
  
 Para as arquiteturas e x 86, a combinação quebra automática\- em torno de comportamento para conversões de número inteiro sem sinal e de avaliação explícita para conversões de número inteiro com sinal em estouro, juntamente com truncamento, torna os resultados para a maioria de deslocamento imprevisíveis se são muito grandes.  
  
 Essas plataformas também diferem em como manipular a conversão NaN \(Não\-um\- número\) para tipos inteiro.  No BRAÇO, converte NaN a 0x00000000; em x 86, e em converte\-se a 0x80000000.  
  
 A conversão de ponto flutuante só pode ser confiável sobre se você souber que o valor é dentro do intervalo de tipo inteiro que está sendo convertidos.  
  
### Comportamento do operador de deslocamento \(\<\< \>\>\)  
 Na arquitetura de BRAÇO, um valor pode ser deslocado para a esquerda ou até a 255 bits antes que o padrão inicie a repetir.  Em arquiteturas e x 86, o padrão é repetido em cada várias de 32 a menos que a origem do padrão é uma variável de 64 bits; nesse caso, as repetições de padrão em cada várias de 64 em 86, e em cada várias de 256 em x, onde uma implementação de software é empregada.  Por exemplo, para uma variável de 32 bits que tenha um valor de 1 deslocado para a esquerda por 32 posições, em BRAÇO o resultado é 0, x86 no resultado é 1, e em 86 o resultado também é 1.  No entanto, se a fonte do valor é uma variável de 64 bits, o resultado em todas as três plataformas são 4294967296, e o valor “não envolve ao redor” até que desloque 64 posições sobre 86, ou 256 posições sobre o BRAÇO e o x86.  
  
 Porque o resultado de uma operação de deslocamento que excede o número de bits no tipo de fonte é indefinido, o compilador não é necessário ter comportamento consistente em todas as situações.  Por exemplo, se ambos os operandos de um deslocamento são conhecidos em tempo de compilação, o compilador pode otimizar o programa usando uma rotina interna para précomputar o resultado de SHIFT e então substituindo o resultado no lugar da operação de deslocamento.  Se o valor de deslocamento é muito grande, ou negativo, o resultado da rotina interna pode ser diferente do que o resultado da mesma expressão de deslocamento que executado por CPU.  
  
### Comportamento variável de argumentos \(varargs\)  
 Na arquitetura de BRAÇO, os parâmetros da lista de argumentos variável que são passados na pilha estão sujeitos ao alinhamento.  Por exemplo, um parâmetro de 64 bits é alinhado em um limite de 64 bits.  Em x 86, e nos argumentos que são passados na pilha não estão sujeitos ao alinhamento e não obtém com segurança.  Essa diferença pode causar uma função variadic como `printf` endereços de memória de leitura que foram e como o preenchimento no BRAÇO se o layout esperado da lista de argumentos variável não é compatível com precisão, mesmo que pode trabalhar para um subconjunto de alguns valores em arquiteturas ou x 86.  Considere o exemplo:  
  
```  
// notice that a 64-bit integer is passed to the function, but '%d' is used to read it.  
// on x86 and x64 this may work for small values because %d will “parse” the low-32 bits of the argument.  
// on ARM the calling convention will align the 64-bit value and the code will print a random value  
printf("%d\n", 1LL);  
  
```  
  
 Nesse caso, o erro pode ser corrigido certificar\-se que a especificação correta de formato é usada de modo que o alinhamento de argumento é considerada.  Esse código está correto:  
  
```  
// CORRECT: use %I64d for 64-bit integers  
printf("%I64d\n", 1LL);  
  
```  
  
### Ordem de classificação de argumento  
 O BRAÇO, porque os processadores x 86, e são tão diferentes, pode apresentar requisitos diferentes implementações do compilador, e também oportunidades diferentes para otimizações.  Devido a isso, junto com outros fatores como de configurações de chamada\- convenção e otimização, um compilador pode avaliar argumentos de função em uma ordem diferente em diferentes arquiteturas ou quando os outros fatores são alterados.  Isso pode causar o comportamento de um aplicativo que se baseia em uma determinada ordem de classificação alterar inesperado.  
  
 Este tipo de erro pode ocorrer quando os argumentos para uma função têm os efeitos colaterais que afetam outros argumentos para a função no mesmo chamada.  Geralmente este tipo de dependência é fácil de evitar, mas às vezes pode ser obscurecido pelas dependências que são difíceis de distinguir, ou por sobrecarga de operador.  Considere este exemplo de código a seguir:  
  
```  
handle memory_handle;  
  
memory_handle->acquire(*p);  
  
```  
  
 Este aparecerá bem definido, mas se `->` e `*` estão operadores sobrecarregados, então esse código é convertido para algo que lembra este:  
  
```  
Handle::acquire(operator->(memory_handle), operator*(p));  
```  
  
 E se houver uma dependência entre `operator->(memory_handle)` e `operator*(p)`, o código pode confiar em uma determinada ordem de classificação, mesmo que os aspectos originais de código como não existem nenhuma dependência possível.  
  
### comportamento temporário de opção de palavras\-chave  
 O compilador do Microsoft C\+\+ suporta duas interpretações diferentes qualificadores de armazenamento temporário que você pode especificar usando opções de compilador.  Alterne de **\/volatile:ms** seleciona a semântica temporária estendida Microsoft que garante ordenação forte, como foi os argumentos tradicionais para x 86 e o compilador do Microsoft devido ao modelo de memória forte nessas arquiteturas.  Alterne de **\/volatile:iso** seleciona a semântica temporária padrão estritamente de C\+\+ que não garante ordenação forte.  
  
 Na arquitetura de BRAÇO, o padrão é **\/volatile:iso** porque os processadores de BRAÇO têm um modelo de memória fraca ordenada, e como o software de BRAÇO não tem um legados de confiança na semântica de **\/volatile:ms** estendido e não tem que geralmente interface com software que faz.  No entanto, ainda é conveniente às vezes ou mesmo necessário para criar um programa de armamento para usar a semântica estendido.  Por exemplo, pode ser muito cara mover um programa para usar a semântica ISO C\+\+, ou o software de driver pode ter que aderir a semântica tradicional para funcionar corretamente.  Nesses casos, você pode usar a opção de **\/volatile:ms** ; entretanto, para recriar a semântica temporária tradicional em destinos de BRAÇO, o compilador deve inserir barreiras de memória em torno de cada leitura ou gravação de uma variável de `volatile` para impor ordenação forte, que pode ter um impacto no desempenho negativo.  
  
 Em arquiteturas e x 86, o padrão é **\/volatile:ms** como muito de software que já foi criado para essas arquiteturas usando o compilador do Microsoft C\+\+ confia neles.  Quando você compila os programas e x 86, você pode especificar a opção de **\/volatile:iso** para ajudar a evitar confiança desnecessária em semântica temporária tradicional, e a promover a portabilidade.  
  
## Consulte também  
 [Configurando programas para processadores ARM](../Topic/Configuring%20Programs%20for%20ARM%20Processors%20\(Visual%20C++\).md)