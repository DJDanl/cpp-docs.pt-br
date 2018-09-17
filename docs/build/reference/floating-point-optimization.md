---
title: Otimização do ponto flutuante do Microsoft Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 03/09/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6208e425ce4a2e1b5738932b8acaf6b11b7db24b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706674"
---
# <a name="microsoft-visual-c-floating-point-optimization"></a>Otimização de ponto flutuante do Microsoft Visual C++

Obtenha um identificador sobre como otimizar o código de ponto flutuante usando o método do compilador do Microsoft C++ de gerenciar a semântica de ponto flutuante. Crie programas rápidos, garantindo que apenas seguras otimizações são executadas em código de ponto flutuante.

## <a name="optimization-of-floating-point-code-in-c"></a>Otimização de código de ponto flutuante em C++

Um compilador de C++ de otimização não só converte o código-fonte em código de máquina, ele organiza as instruções de máquina de maneira a melhorar a eficiência e/ou reduzir o tamanho. Infelizmente, muitas otimizações comuns não são necessariamente seguras quando aplicado aos cálculos de ponto flutuante. Um bom exemplo disso pode ser visto com o seguinte algoritmo de soma, obtido da David Goldberg, "O que cada computador cientista devem saber sobre aritmética de ponto flutuante", *pesquisas de computação*, março de 1991, pg. 203:

```cpp
float KahanSum( const float A[], int n )
{
   float sum=0, C=0, Y, T;
   for (int i=0; i<n; i++)
   {
      Y = A[i] - C;
      T = sum + Y;
      C = T - sum - Y;
      sum = T;
   }
   return sum;
}
```

Essa função adiciona n **float** valores do vetor de matriz `A`. Dentro do corpo do loop, o algoritmo computa um valor de "correção" que é então aplicado para a próxima etapa do Somatório. Esse método reduz consideravelmente os erros de arredondamento cumulativos em comparação com uma soma simple, enquanto mantém a complexidade de tempo (n).

Um compilador de C++ ingênua pode pressupor que a aritmética de ponto flutuante segue as mesmas regras algébricas como o número Real de aritmética. Um compilador assim, em seguida, pode erroneamente Concluir para que

> C = T - soma - Y = = > (soma + Y) - soma - Y = = > 0;

Ou seja, o valor percebido de C é sempre um constante zero. Se esse valor constante, em seguida, é propagado para as expressões subsequentes, o corpo do loop é reduzido a uma soma simple. Para ser preciso,

> Y = [i] - C = = > Y = [i]<br/>T = soma + Y = = > T = soma + [i]<br/>soma = T = = > soma = soma + [i]

Assim, para o compilador ingênua, a transformação de lógica do `KahanSum` função seria:

```cpp
float KahanSum( const float A[], int n )
{
   float sum=0; // C, Y & T are now unused
   for (int i=0; i<n; i++)
      sum = sum + A[i];
   return sum;
}
```

Embora o algoritmo transformado é mais rápido, *não é uma representação exata da intenção do programador*. A correção de erro concebidas cuidadosamente foi removida inteiramente e nos resta um algoritmo de soma simples e direta com seu erro associado.

É claro, um compilador de C++ sofisticado saberia algébricas ou regras de Real aritmética não geralmente se aplicam a aritmética de ponto flutuante. No entanto, até mesmo um compilador C++ sofisticado ainda incorretamente pode interpretar a intenção do programador.

Considere uma otimização comuns que tenta manter todos os valores em registros possível (chamado "Registro" um valor). No `KahanSum` exemplo, essa otimização pode tentar se registre as variáveis `C`, `Y` e `T` , pois eles são usados somente dentro do corpo do loop. Se a precisão de registro é 52bits (double) em vez de 23bits (único), essa otimização efetivamente tipo promove `C`, `Y` e `T` digitar **duplo**. Se a variável de soma não for cancelado da mesma forma, ele permanecerá codificado em precisão única. Isso transforma a semântica de `KahanSum` ao seguinte

```cpp
float KahanSum( const float A[], int n )
{
   float sum=0;
   double C=0, Y, T; // now held in-register
   for (int i=0; i<n; i++)
   {
      Y = A[i] - C;
      T = sum + Y;
      C = T - sum - Y;
      sum = (float) T;
   }
   return sum;
}
```

Embora `Y`, `T` e `C` agora são calculadas em uma maior precisão, essa nova codificação pode produzir um resultado menos preciso, dependendo dos valores na `A[]`. Assim, até mesmo aparentemente inofensivas otimizações podem ter consequências negativas.

Esses tipos de problemas de otimização não são restritos ao código de ponto flutuante "complicado". Algoritmos de ponto flutuantes até mesmo simples podem falhar quando otimizado incorretamente. Considere um algoritmo simple e direta Somatório:

```cpp
float Sum( const float A[], int n )
{
   float sum=0;
   for (int i=0; i<n; i++)
      sum = sum + A[i];
   return sum;
}
```

Como algumas unidades de ponto flutuante são capazes de realizar várias operações simultaneamente, um compilador pode optar por envolver uma otimização de redução escalar. Essa otimização transforma efetivamente a função soma simple acima para o seguinte:

```cpp
float Sum( const float A[], int n )
{
   int n4 = n-n%4; // or n4=n4&(~3)
   int i;
   float sum=0, sum1=0, sum2=0, sum3=0;
   for (i=0; i<n4; i+=4)
   {
      sum = sum + A[i];
      sum1 = sum1 + A[i+1];
      sum2 = sum2 + A[i+2];
      sum3 = sum3 + A[i+3];
   }
   sum = sum + sum1 + sum2 + sum3;
   for (; i<n; i++)
      sum = sum + A[i];
   return sum;
}
```

A função agora mantém quatro somas separadas, que podem ser processadas simultaneamente em cada etapa. Embora a função otimizada agora é muito mais rápida, os resultados otimizados podem ser bastante diferentes dos resultados não otimizada. Essa alteração, o compilador presume-se associativa adição de ponto flutuante; ou seja, que essas duas expressões são equivalentes: `(a + b) + c == a + (b + c)`. No entanto, associatividade não sempre verdadeiras para números de ponto flutuante. Em vez de calcular a soma como:

```cpp
sum = A[0]+A[1]+A[2]+...+A[n-1];
```

a função transformada agora calcula o resultado como

```cpp
sum = (A[0]+A[4]+A[8]+...)
    + (A[1]+A[5]+A[9]+...)
    + (A[2]+A[6]+A[10]+...)
    + (A[3]+A[7]+A[11]+...);
```

Para alguns valores de `A[]`, essa ordem diferente das operações de adição pode produzir resultados inesperados. Para complicar ainda mais, alguns programadores podem optar por antecipar tais otimizações e compensá-los adequadamente. Nesse caso, um programa pode construir a matriz `A` em uma ordem diferente para que a soma otimizada produz os resultados esperados. Além disso, em muitas circunstâncias a precisão do resultado otimizado pode ser "próximo o suficiente". Isso é especialmente verdadeiro quando a otimização fornece benefícios de velocidade atraentes. Vídeo games, por exemplo, exigir como acelerar muito possível, mas geralmente não exigem cálculos de ponto flutuante altamente precisos. Os tomadores de compilador, portanto, devem fornecer um mecanismo para os programadores a controlar os geralmente diferentes objetivos de velocidade e precisão.

Alguns compiladores resolver a compensação entre a velocidade e precisão, fornecendo um comutador separado para cada tipo de otimização. Isso permite que os desenvolvedores desabilitar as otimizações que estão causando as alterações de ponto flutuante de precisão de seu aplicativo específico. Embora essa solução pode oferecer um alto grau de controle sobre o compilador, ele introduz vários problemas adicionais:

- Geralmente é claro que alterna para habilitar ou desabilitar.
- Desabilitar qualquer otimização única pode afetar negativamente o desempenho do código de ponto não flutuante.
- Cada comutador adicional incorre em muitas combinações de comutador novo; o número de combinações rapidamente se torna complicado.

Portanto, embora fornecendo comutadores separados para cada otimização pode parecer atraente, usando esses compiladores pode ser complicado e não confiáveis.

Muitos compiladores de C++ oferecem uma *consistência* modelo de ponto flutuante (por meio de um **/Op** ou **/fltconsistency** alternar) que permite que um desenvolvedor criar programas em conformidade com a semântica estrita de ponto flutuante. Quando estiver encaixada, esse modelo impede que o compilador usando a maioria das otimizações em cálculos de ponto flutuante, permitindo que essas otimizações de código de ponto não flutuante. O modelo de consistência, no entanto, tem um lado-escuro. Para não retornar resultados previsíveis em diferentes arquiteturas FPU, quase todas as implementações de **/Op** round expressões intermediárias para o usuário especificado precisão; por exemplo, considere a seguinte expressão:

```cpp
float a, b, c, d, e;
// . . .
a = b * c + d * e;
```

Para produzir resultados consistentes e reproduzíveis sob **/Op**, essa expressão será avaliada como se ele foi implementado da seguinte maneira:

```cpp
float x = b  *c;
float y = d * e;
a = x + y;
```

O resultado final agora sofre de precisão simples erros de arredondamento *em cada etapa na avaliação da expressão*. Embora essa interpretação estritamente não violam nenhuma regra de semântica de C++, quase nunca é a melhor maneira de avaliar as expressões de ponto flutuantes. É geralmente mais desejável para computar intermediários resulta em tão alta precisão, por praticidade. Por exemplo, seria melhor computar a expressão `a = b * c + d * e` em uma maior precisão como em

```cpp
double x = b * c;
double y = d * e;
double z = x + y;
a = (float)z;
```

ou ainda melhor

```cpp
long double x = b * c;
long double y = d * e
long double z = x + y;
a = (float)z;
```

Ao calcular os resultados intermediários em uma maior precisão, o resultado final é significativamente mais preciso. Ironicamente, ao adotar um modelo de consistência, a probabilidade de erro é aumentada precisamente quando o usuário está tentando reduzir o erro desabilitando as otimizações não seguras. Assim, o modelo de consistência pode reduzir drasticamente a eficiência e não fornecer simultaneamente nenhuma garantia de aumento de precisão. Para programadores numéricos sérios, isso não parece um bom equilíbrio e é o principal motivo que o modelo não é geralmente bem recebido.

Compilador começando na versão 8.0 (Visual C++® 2005), o Microsoft C++ fornece uma alternativa muito melhor. Ele permite que os programadores a selecionar um dos três modos de ponto flutuantes gerais: fp: precise, /FP: Fast e fp: estrita.

- Em fp: preciso, somente as otimizações de seguras são executadas no código de ponto flutuante e, ao contrário **/Op**, cálculos intermediários consistentemente são executados com a maior precisão prática.
- modo /FP: Fast alivia a regras de ponto flutuantes, permitindo a otimização mais agressiva às custas da precisão.
- FP: modo estrito fornece todas as a exatidão geral do fp: precisos ao mesmo tempo permitindo que a semântica de exceção de fp e impedindo transformações ilegais na presença de alterações de ambiente FPU (por exemplo, alterações à register precisão, arredondamento direção etc).

Semântica de exceção de ponto flutuante pode ser controlada independentemente por linha de comando ou um pragma de compilador; Por padrão, a semântica de exceção de ponto flutuante é desabilitada em fp: precisos e habilitado em fp: estrita. O compilador também fornece controle sobre a sensibilidade do ambiente FPU e certas otimizações específicas de ponto flutuantes, como contrações. Esse modelo simples fornece aos desenvolvedores uma grande quantidade de controle sobre a compilação de código de ponto flutuante sem a sobrecarga de excesso de comutadores de compilador ou a perspectiva de efeitos colaterais indesejáveis.

## <a name="the-fpprecise-mode-for-floating-point-semantics"></a>O fp: modo preciso para a semântica de ponto flutuante

O modo padrão de semântica de ponto flutuante é fp: precisos. Quando este modo é selecionado, o compilador estritamente segue um conjunto de regras de segurança durante a otimização das operações de ponto flutuante. Essas regras permitem que o compilador para gerar o código de máquina eficiente, mantendo a precisão dos cálculos de ponto flutuante. Para facilitar a produção de fast programas, o fp: modelo preciso desabilita a semântica de exceção de ponto flutuante (embora elas podem ser habilitadas explicitamente). A Microsoft selecionou fp: precisas como o modo de ponto flutuante padrão, pois ele cria programas rápidos e precisos.

Para solicitar explicitamente o fp: modo preciso usando o compilador de linha de comando, use o [/fp: preciso](fp-specify-floating-point-behavior.md) mudar:

> Cl /fp: source.cpp precisas

Isso instrui o compilador a usar fp: semântica precisa ao gerar código para o arquivo source.cpp. O fp: modelo preciso também pode ser chamado em uma base de função por função usando o [float_control (pragma) compilador](#the-float-control-pragma).

Sob o fp: modo preciso, o compilador nunca executa qualquer otimização que perturbar a precisão dos cálculos de ponto flutuante. O compilador será sempre arredondar corretamente em atribuições, typecasts e chamadas de função e arredondamento intermediário será consistentemente executado com a mesma precisão como o FPU registra. Otimizações de seguras, como contrações, são habilitadas por padrão. Semântica de exceção e sensibilidade de ambiente FPU são desabilitados por padrão.

|FP: semântica precisa|Explicação|
|-|-|
|Semântica de arredondamento|Arredondamento explícita no atribuições, typecasts e chamadas de função. Expressões intermediárias serão avaliadas com precisão de registro.|
|Transformações algébricas|Estrita aderência a álgebra de ponto flutuante não associativo, não distributiva, a menos que uma transformação é garantido que sempre produzem os mesmos resultados.|
|Contrações|Permitido por padrão. Para obter mais informações, consulte a seção [pragma fp_contract](#the-fp-contract-pragma).|
|Ordem de avaliação de ponto flutuante|O compilador pode reordenar a avaliação de expressões de ponto flutuantes, desde que os resultados finais não são alterados.|
|Acesso ao ambiente FPU|Desabilitado por padrão. Para obter mais informações, consulte a seção [pragma fenv_access](#the-fenv-access-pragma). O modo de arredondamento e precisão padrão será assumido.|
|Semântica de exceção de ponto flutuante|Desabilitado por padrão. Para obter mais informações, consulte [/fp: except](fp-specify-floating-point-behavior.md).|

### <a name="rounding-semantics-for-floating-point-expressions-under-fpprecise"></a>Arredondamento de semântica de expressões de ponto flutuante em fp: preciso

O fp: modelo preciso sempre executa cálculos intermediários com a maior precisão prático, arredondamento explicitamente somente em determinados pontos na avaliação da expressão. Arredondamento para a precisão especificada pelo usuário sempre ocorre em quatro lugares: (a) quando uma atribuição é feita, (b) quando uma conversão de tipo é executada, (c) quando um valor de ponto flutuante é passado como um argumento para uma função e (d) quando um valor de ponto flutuante é retornado de um função. Porque cálculos intermediários sempre são executados com precisão de registro, a precisão dos resultados intermediários é dependente de plataforma (embora a precisão sempre será pelo menos tão precisa como o usuário especificado precisão).

Considere a expressão de atribuição no código a seguir. A expressão no lado direito da atribuição operador '=' será computada com precisão de registro e, em seguida, explicitamente arredondada para o tipo do lado esquerdo da atribuição.

```cpp
float a, b, c, d;
double x;
...
x = a*b + c*d;
```

é calculado como

```cpp
float a, b, c, d;
double x;
...
register tmp1 = a*b;
register tmp2 = c*d;
register tmp3 = tmp1+tmp2;
x = (double) tmp3;
```

Para arredondar explicitamente um resultado intermediário, introduza uma conversão de tipo. Por exemplo, se o código anterior for modificado pela adição explícita conversão de tipo, a expressão intermediária (c * 1!d) será arredondado para o tipo da conversão de tipo.

```cpp
float a, b, c, d;
double x;
// . . .
x = a*b + (float)(c*d);
```

é calculado como

```cpp
float a, b, c, d;
double x;
// . . .
register tmp1 = a*b;
float tmp2 = c*d;
register tmp3 = tmp1+tmp2;
x = (double) tmp3;
```

Uma implicação desse método de arredondamento é que algumas transformações aparentemente equivalentes, na verdade, não tem semântica idêntica. Por exemplo, a seguinte transformação divide uma expressão de atribuição simples em duas expressões de atribuição.

```cpp
float a, b, c, d;
// . . .
a = b*(c+d);
```

NÃO é equivalente a

```cpp
float a, b, c, d;
// . . .
a = c+d;
a = b*a;
```

Da mesma forma:

```cpp
a = b*(c+d);
```

NÃO é equivalente a

```cpp
a = b*(a=c+d);
```

Essas codificações não têm semântica equivalente porque as codificações segundo cada, introduziram uma operação de atribuição adicionais e, portanto, um adicional de arredondamento de ponto.

Quando uma função retorna um valor de ponto flutuante, o valor será arredondado para o tipo da função. Quando um valor de ponto flutuante é passado como um parâmetro para uma função, o valor será arredondado para o tipo do parâmetro. Por exemplo:

```cpp
float sumsqr(float a, float b)
{
   return a*a + b*b;
}
```

é calculado como

```cpp
float sumsqr(float a, float b)
{
    register tmp3 = a*a;
    register tmp4 = b*b;
    register tmp5 = tmp3+tmp4;
    return (float) tmp5;
}
```

Da mesma forma:

```cpp
float w, x, y, z;
double c;
...
c = symsqr(w*x+y, z);
```

é calculado como

```cpp
float x, y, z;
double c;
...
register tmp1 = w*x;
register tmp2 = tmp1+y;
float tmp3 = tmp2;
c = symsqr( tmp3, z);
```

### <a name="architecture-specific-rounding-under-fpprecise"></a>Arredondamento de arquitetura específicas em fp: preciso

|Processador|Arredondando a precisão para expressões intermediárias|
|-|-|
|x86|Expressões intermediárias são computadas com a precisão de 53 bits padrão com uma extensa variedade fornecida por um expoente de 16 bits. Quando esses valores 53:16 são "derramamento" para a memória (como pode ocorrer durante uma chamada de função), expoente intervalo estendido será ser restringido a 11 bits. Ou seja, os valores despejados são convertidos para o formato padrão de precisão dupla com apenas um expoente de 11 bits.<br/>Um usuário pode alternar para precisão estendida de 64 bits para o arredondamento intermediário alterando a palavra de controle de ponto flutuante usando `_controlfp` e habilitando o acesso ao ambiente FPU (consulte [pragma fenv_access](#the-fenv-access-pragma)). No entanto, quando os valores do registro de precisão estendida são despejados para a memória, os resultados intermediários ainda serão arredondados à precisão dupla.<br/>Este semântico específico está sujeita a alterações.|
|amd64|Semântica FP em amd64 é um pouco diferente de outras plataformas. Por motivos de desempenho, operações intermediárias são computadas com a maior precisão de qualquer um dos operandos em vez de com a maior precisão disponível.  Para forçar os cálculos para ser calculado usando uma precisão maior do que os operandos, os usuários precisam apresentar uma operação de conversão em pelo menos um operando em uma subexpressão.<br/>Este semântico específico está sujeita a alterações.|

### <a name="algebraic-transformations-under-fpprecise"></a>Transformações algébricas sob fp: preciso

Quando o fp: modo preciso estiver habilitado, o compilador nunca será executar transformações algébricas *, a menos que o resultado final é idêntico provavelmente*. Muitas das regras algébricas familiares para o número Real de aritmética não sempre valem para aritmética de ponto flutuante. Por exemplo, as expressões a seguir são equivalentes para reais, mas não necessariamente para flutuações.

|Formulário|Descrição|
|-|-|
|`(a+b)+c = a+(b+c)`|Regra de associação para adição|
|`(a*b)*c = a*(b*c)`|Regra de associação para multiplicação|
|`a*(b+c) = a*b + b*c`|Distribuição de multiplicação de adição|
|`(a+b)(a-b) = a*a-b*b`|Fatorar algébricas|
|`a/b = a*(1/b)`|Divisão por inverso de multiplicação|
|`a*1.0 = a`|Identidade de multiplicação|

Conforme ilustrado no exemplo de Introdução com a função `KahanSum`, o compilador pode ser tentado para executar várias transformações algébricas para produzir programas consideravelmente mais rápidos. Embora, otimizações dependentes essas transformações algébricas quase sempre estão incorretas, há ocasiões em que para os quais eles estão seguros perfeitamente. Por exemplo, às vezes é desejável para substituir a divisão por um *constante* valor com a multiplicação por multiplicação inversa da constante:

```cpp
const double four = 4.0;
double a, b;
...

a = b/four;
```

Podem ser transformados em

```cpp
const double four = 4.0;
const double tmp0 = 1/4.0;
double a, b;
...
a = b*tmp0;
```

Isso é uma transformação segura porque o otimizador pode determinar no tempo de compilação que x / 4.0 = = x*(1/4.0) para todos os valores de ponto flutuantes de x, incluindo os infinitos e NaN. Substituindo uma operação de divisão por uma multiplicação, o compilador pode salvar vários ciclos — especialmente em FPUs que não implementam a divisão diretamente, mas exigem o compilador para gerar uma combinação de aproximação recíproco e adicionar multiplicação instruções. O compilador pode executar essa otimização em fp: preciso apenas quando a multiplicação de substituição produz exatamente mesmo resultado da divisão. O compilador também pode executar transformações triviais em fp: preciso, desde que os resultados são idênticos. Elas incluem:

|Formulário|Descrição
|-|-|
|`(a+b) == (b+a)`|Regra comutativa para serem adicionados|
|`(a*b) == (b*a)`|Regra comutativa para multiplicação|
|`1.0*x*y == x*1.0*y == x*y*1.0 == x*y`|Multiplicação por 1.0|
|`x/1.0*y == x*y/1.0 == x*y`|Divisão por 1.0|
|`2.0*x == x+x`|Multiplicação por 2.0|

### <a name="contractions-under-fpprecise"></a>Contrações sob fp: preciso

Um recurso importante de arquitetura de muitas unidades de ponto flutuantes modernos é a capacidade de executar uma multiplicação seguida por uma adição como uma única operação com nenhum erro de arredondamento intermediário. Por exemplo, da arquitetura da Intel Itanium fornece instruções para combinar cada uma dessas operações ternários, (um*b + c), (uma*b-c) e (c-a * b), em uma única instrução de ponto flutuante (fma, fms e fnma, respectivamente). Essas instruções únicas são mais rápido do que executar separado multiplicar e adicione as instruções e são mais precisas, pois não há nenhum arredondamento intermediário do produto. Essa otimização significativamente pode acelerar a funções que contém várias intercalados multiply e adicionar operações. Por exemplo, considere o seguinte algoritmo que calcula o produto escalar de dois vetores de n-dimensional.

```cpp
float dotProduct( float x[], float y[], int n )
{
   float p=0.0;
   for (int i=0; i<n; i++)
      p += x[i]*y[i];
   return p;
}
```

Esse cálculo pode ser executado uma série de adição de instruções do formulário p a multiplicar = p + x [i] * y [i].

A otimização de contração pode ser controlada independentemente usando o `fp_contract` pragma de compilador. Por padrão, o fp: modelo preciso permite contrações como melhorar a velocidade e precisão. Em fp: preciso, o compilador nunca será contrato uma expressão com o arredondamento explícita.
Exemplos

```cpp
float a, b, c, d, e, t;
...
d = a*b + c;         // may be contracted
d += a*b;            // may be contracted
d = a*b + e*d;       // may be contracted into a mult followed by a mult-add
etc...

d = (float)a*b + c;  // won't be contracted because of explicit rounding

t = a*b;             // (this assignment rounds a*b to float)
d = t + c;           // won't be contracted because of rounding of a*b
```

### <a name="order-of-floating-point-expression-evaluation-under-fpprecise"></a>Ordem de avaliação de expressão de ponto flutuante em fp: preciso

Otimizações que preservam a ordem de avaliação de expressão de ponto flutuante são sempre seguras e, portanto, são permitidas sob o fp: modo preciso. Considere a seguinte função que calcula o produto escalar de dois vetores de n-dimensional de precisão simples. O primeiro bloco de código abaixo é a função original como ele pode ser codificado, um programador, seguida pela mesma função após uma otimização parcial de desenrolamento de loop.

```cpp
//original function
float dotProduct( float x[], float y[], int n )
{
   float p=0;
   for (int i=0; i<n; i++)
      p += x[i]*y[i];
   return p;
}

//after a partial loop-unrolling
float dotProduct( float x[], float y[], int n )
{
   int n4= n/4*4; // or n4=n&(~3);
   float p=0;
   int i;

   for (i=0; i<n4; i+=4)
   {
      p+=x[i]*y[i];
      p+=x[i+1]*y[i+1];
      p+=x[i+2]*y[i+2];
      p+=x[i+3]*y[i+3];
   }

   // last n%4 elements
   for (; i<n; i++)
      p+=x[i]*y[i];

   return p;
}
```

A principal vantagem dessa otimização é que ela reduz o número de ramificação condicional de loop em 75%. Além disso, aumentando o número de operações dentro do corpo do loop, o compilador agora pode ter mais oportunidades para otimizar ainda mais. Por exemplo, alguns FPUs podem ser capazes de executar a adicionar multiplicação em + p = x [i] * y [i] ao buscar simultaneamente os valores de x [i + 1] e y [i + 1] para uso na próxima etapa. Esse tipo de otimização é perfeitamente seguro para cálculos de ponto flutuante, porque ele preserva a ordem das operações.

Muitas vezes é vantajoso para o compilador reordenar operações inteiras para produzir um código mais rápido. Considere o código a seguir:

```cpp
double a, b, c, d;
double x, y, z;
...
x = a*a*a + b*b*b + c*c*c;
...
y = a*a + b*b + c*c;
...
z = a + b + c;
```

Regras semânticas do C++ indicam que o programa deve produzir resultados como se ela primeiro computada x, em seguida, y e, finalmente, z. Suponha que o compilador tem apenas quatro registros de ponto flutuantes disponíveis. Se o compilador é forçado a computação x, y e z em ordem, ele pode optar por gerar código com a seguinte semântica:

```cpp
double a, b, c, d;
double x, y, z;
register r0, r1, r2, r3;
...
// Compute x
r0 = a;         // r1 = a*a*a
r1 = r0*r0;
r1 = r1*r0;
r0 = b;         // r2 = b*b*b
r2 = r0*r0;
r2 = r2*r0;
r0 = c;         // r3 = c*c*c
r3 = r0*r0;
r3 = r3*r0;
r0 = r1 + r2;
r0 = r0 + r3;
x = r0;         // x = r1+r2+r3
// . . .
// Compute y
r0 = a;         // r1 = a*a
r1 = r0*r0;
r0 = b;         // r2 = b*b
r2 = r0*r0;
r0 = c;         // r3 = c*c
r3 = r0*r0;
r0 = r1 + r2;
r0 = r0 + r3;
y = r0;         // y = r1+r2+r3
// . . .
// Compute z
r1 = a;
r2 = b;
r3 = c;
r0 = r1 + r2;
r0 = r0 + r3;
z = r0;         // z = r1+r2+r3
```

Há várias operações claramente redundantes é essa codificação. Se o compilador estritamente segue regras semânticas do C++, essa classificação é necessário porque o programa pode acessar o ambiente de FPU entre cada atribuição. No entanto, as configurações padrão de fp: preciso permitir que o compilador otimizar como se o programa não acessar o ambiente, permitindo que ele reordenar essas expressões. Em seguida, é gratuito para remover as redundâncias Computando os três valores na ordem inversa, da seguinte maneira:

```cpp
double a, b, c, d;
double x, y, z;
register r0, r1, r2, r3;
...
// Compute z
r1 = a;
r2 = b;
r3 = c;
r0 = r1+r2;
r0 = r0+r3;
z = r0;
...
// Compute y
r1 = r1*r1;
r2 = r2*r2;
r3 = r3*r3;
r0 = r1+r2;
r0 = r0+r3;
y = r0;
...
// Compute x
r0 = a;
r1 = r1*r0;
r0 = b;
r2 = r2*r0;
r0 = c;
r3 = r3*r0;
r0 = r1+r2;
r0 = r0+r3;
x = r0;
```

Essa codificação é claramente superior, ter reduzido o número de instruções de fp em quase 40%. Os resultados para x, y e z são os mesmos de antes, mas computado com menos sobrecarga.

Em fp: preciso, o compilador também poderá *entrelaçar* subexpressões comuns para produzir um código mais rápido. Por exemplo, código para calcular as raízes de uma equação quadrática pode ser escrito da seguinte maneira:

```cpp
double a, b, c, root0, root1;
...
root0 = (-b + sqrt(b*b-4*a*c))/(2*a);
root1 = (-b - sqrt(b*b-4*a*c))/(2*a);
```

Embora essas expressões diferem somente por uma única operação, o programador pode escrevê-los dessa forma, para garantir que cada valor de raiz será calculada na prática precisão mais alta. Em fp: preciso, o compilador é livre para o cálculo de root0 e root1 remover subexpressões comuns sem perda da precisão de entrelaçamento. Por exemplo, o seguinte removeu várias etapas redundantes, produzindo a mesma resposta exata.

```cpp
double a, b, c, root0, root1;
...
register tmp0 = -b;
register tmp1 = sqrt(b*b-4*a*c);
register tmp2 = 2*a;
root0 = (tmp0+tmp1)/tmp2;
root1 = (tmp0-tmp1)/tmp2;
```

Outras otimizações podem tentar mover a avaliação de determinadas expressões independentes. Considere o seguinte algoritmo que contém uma ramificação condicional dentro de um corpo de loop.

```cpp
vector<double> a(n);
double d, s;
// . . .
for (int i=0; i<n; i++)
{
   if (abs(d)>1.0)
      s = s+a[i]/d;
   else
      s = s+a[i]*d;
}
```

O compilador pode detectar que o valor da expressão (abs(d) > 1) é invariável dentro do corpo do loop. Isso permite que o compilador "elevar" if instrução fora do corpo do loop, transformando o código acima para o seguinte:

```cpp
vector<double> a(n);
double d, s;
// . . .
if (abs(d)>1.0)
   for (int i=0; i<n; i++)
      s = s+a[i]/d;
else
   for (int i=0; i<n; i++)
      s = s+a[i]*d;
```

Após a transformação não é mais uma ramificação condicional em ambos os corpos de loop, aumentando bastante o desempenho geral do loop. Esse tipo de otimização é perfeitamente seguro porque a avaliação da expressão (abs(d) > 1.0) é independente de outras expressões.

Na presença de acesso ao ambiente FPU ou exceções de ponto flutuante, esses tipos de otimização são contraindicated porque eles alteram o fluxo de semântico. Essas otimizações só estão disponíveis sob o fp: modo preciso porque a semântica de exceção de ponto flutuante e de acesso ao ambiente FPU é desabilitada por padrão. Funções que acessam o ambiente FPU poderá desabilitar explicitamente tais otimizações ao usar o `fenv_access` pragma de compilador. Da mesma forma, as funções usando exceções de ponto flutuante devem usar o `float_control(except ... )` compilador pragma (ou usar o **/fp: exceto** opção de linha de comando).

Em resumo, o fp: modo preciso permite que o compilador para reordenar a avaliação de expressões de ponto flutuantes sob condição de que os resultados finais não são alterados e que os resultados não são dependentes no ambiente FPU ou em exceções de ponto flutuante.

### <a name="fpu-environment-access-under-fpprecise"></a>Acesso ao ambiente FPU em fp: preciso

Quando o fp: modo preciso estiver habilitado, o compilador pressupõe que um programa não acessar ou alterar o ambiente de FPU. Conforme mencionado anteriormente, essa suposição permite que o compilador reordenar ou mover as operações de ponto flutuante para melhorar a eficiência em fp: precisos.

Alguns programas podem alterar a ponto flutuante de arredondamento direção usando o `_controlfp` função. Por exemplo, alguns programas de computação superior e inferiores limites de erro em operações aritméticas, executando o mesmo cálculo duas vezes, primeiro ao arredondamento para o infinito negativo, em seguida, enquanto arredondamento para o infinito positivo. Como o FPU fornece uma maneira conveniente para controlar o arredondamento, um programador pode optar por alterar o modo de arredondamento, alterar o ambiente de FPU. O código a seguir calcula o que erro exato associados de uma multiplicação de ponto flutuante por alterar o ambiente de FPU.

```cpp
double a, b, cLower, cUpper;
// . . .
_controlfp( _RC_DOWN, _MCW_RC );    // round to -&infin;
cLower = a*b;
_controlfp( _RC_UP, _MCW_RC );    // round to +&infin;
cUpper = a*b;
_controlfp( _RC_NEAR, _MCW_RC );    // restore rounding mode
```

Em fp: precisas, o compilador sempre pressupõe que o ambiente de FPU padrão, para que o otimizador está livre para ignorar as chamadas para `_controlfp` e reduzir as atribuições acima para cUpper = cLower = um * b; isso claramente poderia produzir resultados incorretos. Para evitar tais otimizações, habilitar o acesso ao ambiente FPU usando o `fenv_access` pragma de compilador.

Outros programas podem tentar detectar alguns erros de ponto flutuantes, verificando a palavra de status de FPU. Por exemplo, o código a seguir verifica as condições de divisão por zero e inexatos

```cpp
double a, b, c, r;
float x;
// . . .
_clearfp();
r = (a*b + sqrt(b*b-4*a*c))/(2*a);
if (_statusfp() & _SW_ZERODIVIDE)
   handle divide by zero as a special case
_clearfp();
x = r;
if (_statusfp() & _SW_INEXACT)
   handle inexact error as a special case
etc...
```

Em fp: preciso, otimizações que reordenar a avaliação da expressão podem alterar os pontos em que certos erros ocorrem. Programas que acessam a palavra de status devem habilitar o acesso ao ambiente FPU usando o `fenv_access` pragma de compilador.

Para obter mais informações, consulte a seção [pragma fenv_access](#the-fenv-access-pragma).

### <a name="floating-point-exception-semantics-under-fpprecise"></a>Semântica de exceção de ponto flutuante em fp: preciso

Por padrão, a semântica de exceção de ponto flutuante é desabilitada em fp: precisos. A maioria dos programadores de C++ preferem lidar com condições excepcionais de ponto flutuantes sem usar o sistema ou as exceções do C++. Além disso, conforme mencionado anteriormente, desabilitando a semântica de exceção de ponto flutuante permite uma flexibilidade maior do compilador durante a otimização das operações de ponto flutuante. Use o **/fp: exceto** alternar ou o `float_control` pragma de habilitar a semântica de exceção de ponto flutuante ao usar o fp: modelo preciso.

Para obter mais informações, consulte a seção [habilitando a semântica de exceção de ponto flutuante](#enabling-floating-point-exception-semantics).

## <a name="the-fpfast-mode-for-floating-point-semantics"></a>O modo de /FP: Fast para semântica de ponto flutuante

Quando o modo /FP: Fast está habilitado, o compilador alivia as regras que fp: preciso usa durante a otimização das operações de ponto flutuante. Esse modo é permite que o compilador otimizar ainda mais o código de ponto flutuante para velocidade às custas da precisão de ponto flutuante e a exatidão. Programas que não dependem de cálculos de ponto flutuante altamente precisos podem enfrentar uma melhoria de velocidade significativos, habilitando o modo /FP: Fast.

O modo de ponto flutuante /FP: Fast é habilitado usando o [Fast](fp-specify-floating-point-behavior.md) comutador de compilador de linha de comando da seguinte maneira:

> Cl Fast source.cpp

Este exemplo instrui o compilador use /FP: Fast semântica ao gerar código para o arquivo source.cpp. O modelo /FP: Fast também pode ser chamado em uma base de função por função usando o `float_control` pragma de compilador.

Para obter mais informações, consulte a seção [pragma float_control](#the-float-control-pragma).

No modo de /FP: Fast, o compilador pode executar otimizações que alteram a precisão dos cálculos de ponto flutuante. O compilador pode não arredondar corretamente em atribuições, typecasts ou chamadas de função e arredondamento intermediário não será sempre executado. Ponto flutuantes otimizações específicas, como contrações, estão sempre habilitadas. Semântica de exceção de ponto flutuante e sensibilidade de ambiente FPU são desabilitados e não está disponível.

|/FP: Fast semântica|Explicação
|-|-|
|Semântica de arredondamento|Arredondamento explícita no atribuições, typecasts e chamadas de função podem ser ignoradas.<br/>Expressões intermediárias podem ser arredondadas em menos de registrar a precisão de acordo com os requisitos de desempenho.|
|Transformações algébricas|O compilador pode transformar a expressões de acordo com o número real álgebra associativa, distributiva; Essas transformações não são garantidas para ser precisas ou correto.|
|Contrações|Sempre ativado; não pode ser desabilitada pelo pragma `fp_contract`|
|Ordem de avaliação de ponto flutuante|O compilador pode reordenar a avaliação de expressões de ponto flutuantes, mesmo quando essas alterações podem alterar os resultados finais.|
|Acesso ao ambiente FPU|Desabilitado. Não disponível|
|Semântica de exceção de ponto flutuante|Desabilitado. Não disponível|

### <a name="rounding-semantics-for-floating-point-expressions-under-fpfast"></a>Arredondamento de semântica de expressões de ponto flutuante em /FP: Fast

Ao contrário o fp: modelo preciso, o modelo /FP: Fast executa cálculos intermediários precisão mais conveniente. Arredondamento de atribuições, typecasts e chamadas de função não podem ocorrer sempre. Por exemplo, a primeira função abaixo apresenta três variáveis de precisão simples (`C`, `Y` e `T`). O compilador pode optar por Registre essas variáveis, em vigor de promoção de tipo `C`, `Y` e `T` para precisão dupla.

Função original:

```cpp
float KahanSum( const float A[], int n )
{
   float sum=0, C=0, Y, T;
   for (int i=0; i<n; i++)
   {
      Y = A[i] - C;
      T = sum + Y;
      C = T - sum - Y;
      sum = T;
   }
   return sum;
}
```

Cancelado de variáveis:

```cpp
float KahanSum( const float A[], int n )
{
   float sum=0;
   double C=0, Y, T; // now held in-register
   for (int i=0; i<n; i++)
   {
      Y = A[i] - C;
      T = sum + Y;
      C = T - sum - Y;
      sum = (float) T;
   }
   return sum;
}
```

Neste exemplo, /FP: Fast tem subverted a intenção da função original. Final com otimização de resultado, mantido na variável `sum`, pode ser bastante perturbed do resultado correto.

Sob /FP: Fast, o compilador normalmente tentará manter pelo menos a precisão especificada pelo código-fonte. No entanto, em alguns casos o compilador pode optar por executar expressões intermediárias em uma *menor precisão* que o especificado no código-fonte. Por exemplo, o primeiro bloco de código abaixo chama uma versão de precisão dupla da função raiz quadrada. Sob /FP: Fast, em determinadas circunstâncias, como quando o resultado e operandos da função são convertidos explicitamente para precisão única, o compilador pode optar por substituir a chamada para o de precisão dupla `sqrt` com uma chamada para uma precisão única `sqrtf`função. Porque as conversões de garantir que o valor entram `sqrt` e o valor de saída são arredondadas para precisão única, isso altera apenas o lugar de arredondamento. Se o valor que chegam ao sqrt era um valor de precisão dupla e o compilador realizar essa transformação, metade dos bits de precisão pode ser incorreta.

Função original

```cpp
double sqrt(double);
// . . .
double a, b, c;
float f1, f2;
// . . .
float length = (float)sqrt((float)(a*a + b*b + c*c));
float sum = (float) ((double)f1 + (double)f2);
```

Função otimizada

```cpp
float sqrtf(float)...
// . . .
double a, b, c;
float f1, f2;
// . . .
double tmp0 = a*a + b*b + c*c;
float tmp1 = tmp0;    // round of parameter value
float length = sqrtf(tmp1); // rounded sqrt result
float sum = f1 + f2;
```

Embora menos precisos, essa otimização pode ser especialmente útil ao redirecionar para processadores que fornecem a precisão, versões intrínseco funções como `sqrt`. Apenas com precisão quando o compilador usará essas otimizações é dependente de plataforma e o contexto.

Além disso, há sem garantia de consistência para a precisão dos cálculos intermediários, que podem ser executadas em qualquer nível de precisão disponível para o compilador. Embora o compilador tentará manter pelo menos o nível de precisão especificada pelo código, /FP: Fast permite que o otimizador downcast cálculos intermediários para produzir o código de máquina rápido ou menor. Por exemplo, o compilador pode otimizar ainda mais o código acima para algumas das multiplicações intermediárias para precisão única ida e volta.

```cpp
float sqrtf(float)...
// . . .
double a, b, c;
float f1, f2;
// . . .
float tmp0 = a*a;     // round intermediate a*a to single-precision
float tmp1 = b*b;     // round intermediate b*b to single-precision
double tmp2 = c*c;    // do NOT round intermediate c*c to single-precision
float tmp3 = tmp0 + tmp1 + tmp2;
float length = sqrtf(tmp3);
float sum = f1 + f2;
```

Este tipo de arredondamento adicional pode resultar do uso de uma menor unidade ponto flutuante de precisão, como SSE2, executar alguns dos cálculos intermediários. A precisão de arredondamento /FP: Fast, portanto, é dependente de plataforma; código que compila bem para um processador pode não necessariamente funcionar bem para outro processador. Ele é deixado para o usuário para determinar se os benefícios de velocidade superam os problemas de precisão.

Se a otimização /FP: Fast é especialmente problemática para uma função específica, o modo de ponto flutuante pode ser alternado localmente para fp: preciso usando o `float_control` pragma de compilador.

### <a name="algebraic-transformations-under-fpfast"></a>Transformações algébricas sob /FP: Fast

O modo de /FP: Fast permite que o compilador a executar determinadas, expressões de ponto de transformações algébricas inseguras para flutuante. Por exemplo, as seguintes otimizações não seguras podem ser empregadas em /FP: Fast.

||||
|-|-|-|
|Código original|Etapa 1 #|Etapa 2 #
|`double a, b, c;`<br/>`double x, y, z;`<br/><br/>`y = (a + b);`<br/>`z = y – a – b;`<br/><br/>`c = x – z;`<br/><br/>`c = x * z;`<br/><br/>`c = x - z;`<br/><br/>`c = x + z;`<br/><br/>`c = z-x;`|`double a, b, c;`<br/>`double x, y, z;`<br/><br/>`y = (a + b);`<br/>`z = 0;`<br/><br/>`c = x – 0;`<br/><br/>`c = x * 0;`<br/><br/>`c = x - 0;`<br/><br/>`c = x + 0;`<br/><br/>`c = 0 - x;`|`double a, b, c;`<br/>`double x, y, z;`<br/><br/>`y = (a + b);`<br/>`z = 0;`<br/><br/>`c = x;`<br/><br/>`c = 0;`<br/><br/>`c = x;`<br/><br/>`c = x;`<br/><br/>`c = -x;`|

Na etapa 1, o compilador observa que `z = y – a – b` é sempre igual a zero. Embora seja tecnicamente uma observação inválida, ele é permitido sob /FP: Fast. O compilador, em seguida, propaga o valor da constante zero para cada uso subsequente da variável z. Na etapa 2, ainda mais o compilador otimiza, observando que `x - 0 == x`, `x * 0 == 0`, etc. Novamente, mesmo que essas observações não são estritamente válidas, eles são permitidos sob /FP: Fast. O código otimizado agora é muito mais rápido, mas também pode ser consideravelmente menos precisos ou até mesmo incorreto.

Qualquer uma das seguintes regras algébricas (perigoso) pode ser empregado pelo otimizador de quando o modo /FP: Fast está habilitado:

|||
|-|-|
|Formulário|Descrição|
|`(a + b) + c = a + (b + c)`|Regra de associação para adição|
|`(a * b) * c = a * (b * c)`|Regra de associação para multiplicação|
|`a * (b + c) = a * b + b * c`|Distribuição de multiplicação de adição|
|`(a + b)(a - b) = a * a - b * b`|Fatorar algébricas|
|`a / b = a * (1 / b)`|Divisão por inverso de multiplicação|
|`a * 1.0 = a, a / 1.0 = a`|Identidade de multiplicação|
|`a ± 0.0 = a, 0.0 - a = -a`|Identidade de adição|
|`a / a = 1.0, a - a = 0.0`|Cancelamento|

Se a otimização /FP: Fast é especialmente problemática para uma função específica, o modo de ponto flutuante pode ser alternado localmente para fp: preciso usando o `float_control` pragma de compilador.

### <a name="order-of-floating-point-expression-evaluation-under-fpfast"></a>Ordem de avaliação de expressão de ponto flutuante em /FP: Fast

Ao contrário o fp: precise, /FP: Fast permite que o compilador reordenar as operações de ponto flutuante para produzir um código mais rápido. Portanto, algumas otimizações sob /FP: Fast podem não preservar a ordem planejada de expressões. Por exemplo, considere a seguinte função que calcula o produto escalar de dois vetores de n-dimensional.

```cpp
float dotProduct( float x[], float y[],
                  int n )
{
   float p=0;
   for (int i=0; i<n; i++)
      p += x[i]*y[i];
   return p;
}
```

Sob /FP: Fast, o otimizador pode realizar uma redução escalar do `dotProduct` funcionar efetivamente transformar a função da seguinte maneira:

```cpp
float dotProduct( float x[], float y[],int n )
{
    int n4= n/4*4; // or n4=n&(~3);
    float p=0, p2=0, p3=0, p4=0;
    int i;

    for (i=0; i<n4; i+=4)
    {
        p+=x[i]*y[i];
        p2+=x[i+1]*y[i+1];
        p3+=x[i+2]*y[i+2];
        p4+=x[i+3]*y[i+3];
    }
    p+=p2+p3+p4;

    // last n%4 elements
    for (; i<n; i++)
    p+=x[i]*y[i];

    return p;
}
```

Na versão otimizada da função quatro separado para somas de produto são executadas simultaneamente e, em seguida, adicionadas juntos. Essa otimização pode acelerar a computação do `dotProduct` por tanto quanto um fator de quatro, dependendo do processador de destino, mas o resultado final pode não ser tão precisas para torná-lo inútil. Se essas otimizações são particularmente problemáticas para única função ou unidade de tradução, o modo de ponto flutuante pode ser alternado localmente para fp: preciso usando o `float_control` pragma de compilador.

## <a name="the-fpstrict-mode-for-floating-point-semantics"></a>O fp: modo estrito para a semântica de ponto flutuante

Quando o fp: modo estrito está habilitado, o compilador segue as mesmas regras que fp: preciso usa durante a otimização das operações de ponto flutuante. Esse modo também permite que a semântica de exceção de ponto flutuante e sensibilidade ao ambiente FPU e desabilita determinadas otimizações como contrações. É o modo mais rígido de operação.

O fp: modo estrito de ponto flutuante é habilitado usando o [/fp: strict](fp-specify-floating-point-behavior.md) comutador de compilador de linha de comando da seguinte maneira:

> Cl /fp: strict source.cpp

Este exemplo instrui o compilador a usar fp: semântica estrita ao gerar código para o arquivo source.cpp. O fp: modelo estrito também pode ser chamado em uma base de função por função usando o `float_control` pragma de compilador.

Para obter mais informações, consulte a seção [pragma float_control](#the-float-control-pragma).

Sob o fp: modo estrito, o compilador nunca executa qualquer otimização que perturbar a precisão dos cálculos de ponto flutuante. O compilador será sempre arredondar corretamente em atribuições, typecasts e chamadas de função e arredondamento intermediário será consistentemente executado com a mesma precisão como o FPU registra. Semântica de exceção de ponto flutuante e sensibilidade de ambiente FPU são habilitadas por padrão. Determinadas otimizações, tais como contrações, estão desabilitadas porque o compilador não pode garantir a exatidão em todos os casos.

|/FP: strict semântica|Explicação|
|-|-|
|Semântica de arredondamento|Arredondamento explícita no atribuições, typecasts e chamadas de função<br/>Expressões intermediárias serão avaliadas com precisão de registro.<br/>Mesmo que fp: preciso|
|Transformações algébricas|Estrita aderência a álgebra de ponto flutuante não associativo, não distributiva, a menos que uma transformação é garantido que sempre produzem os mesmos resultados.<br/>Mesmo que fp: preciso|
|Contrações|Sempre desabilitado|
|Ordem de avaliação de ponto flutuante|O compilador não reorganizará a avaliação de expressões de ponto flutuantes|
|Acesso ao ambiente FPU|Sempre habilitado.|
|Semântica de exceção de ponto flutuante|Habilitado por padrão.|

### <a name="floating-point-exception-semantics-under-fpstrict"></a>Semântica de exceção de ponto flutuante em /FP: strict

Por padrão, a semântica de exceção de ponto flutuante é habilitada em fp: modelo estrito. Para desabilitar essa semântica, use o **/fp: exceto-** alternar ou introduzir um `float_control(except, off)` pragma.

Para obter mais informações, consulte as seções [habilitando a semântica de exceção de ponto flutuante](#enabling-floating-point-exception-semantics) e [o float_control (Pragma)](#the-float-control-pragma).

## <a name="the-fenvaccess-pragma"></a>O pragma fenv_access

Uso:

```cpp
#pragma fenv_access( [ on  | off ] )
```

O [fenv_access](../../preprocessor/fenv-access.md) pragma permite que o compilador fazer determinadas otimizações que podem subverter FPU testes de sinalizadores e alterações de modo FPU. Quando o estado do `fenv_access` estiver desabilitado, o compilador pode assumir os modos FPU padrão estão em vigor e que não foram testados sinalizadores FPU. Por padrão, o acesso ao ambiente está desabilitado para o fp: modo preciso, embora ele pode ser habilitado explicitamente com esse pragma. Sob /FP: strict, `fenv_access` está sempre habilitado e não pode ser desabilitada. Sob /FP: Fast, `fenv_access` está sempre desabilitado e não pode ser habilitado.

Conforme descrito em fp: seção precisa, alguns programadores podem alterar a direção de arredondamento de ponto flutuante usando o `_controlfp` função. Por exemplo, para calcular os limites superiores e inferiores de erro em operações aritméticas, alguns programas executam duas vezes, o mesmo cálculo primeiro ao arredondamento para o infinito negativo, em seguida, ao mesmo tempo em que o arredondamento para o infinito positivo. Como o FPU fornece uma maneira conveniente para controlar o arredondamento, um programador pode optar por alterar o modo de arredondamento, alterar o ambiente de FPU. O código a seguir calcula o que erro exato associados de uma multiplicação de ponto flutuante por alterar o ambiente de FPU.

```cpp
double a, b, cLower, cUpper;
// . . .
_controlfp( _RC_DOWN, _MCW_RC );    // round to -infinity
cLower = a*b;
_controlfp( _RC_UP, _MCW_RC );       // round to +infinity
cUpper = a*b;
_controlfp( _RC_NEAR, _MCW_RC );    // restore rounding mode
```

Quando desabilitado, o `fenv_access` pragma permite que o compilador para assumir o ambiente de FPU padrão; portanto, o otimizador está livre para ignorar as chamadas para `_controlfp` e reduzir as atribuições acima para `cUpper = cLower = a*b`. Quando habilitado, no entanto, `fenv_access` impede essas otimizações.

Programas também podem verificar a palavra de status FPU para detectar alguns erros de ponto flutuantes. Por exemplo, o código a seguir verifica as condições de divisão por zero e inexatos

```cpp
double a, b, c, r;
float x;
// . . .
_clearfp();
r = (a*b + sqrt(b*b-4*a*c))/(2*a);
if (_statusfp() & _SW_ZERODIVIDE)
   handle divide by zero as a special case
_clearfp();
x = (a*b + sqrt(b*b-4*a*c))/(2*a);
if (_statusfp() & _SW_INEXACT)
   handle inexact error as a special case
etc...
```

Quando `fenv_access` é desabilitado, o compilador pode reorganizar a ordem de execução das expressões de ponto flutuantes, assim, possivelmente Subvertendo as verificações de status FPU. Habilitando `fenv_access` impede essas otimizações.

## <a name="the-fpcontract-pragma"></a>O fp_contract (pragma)

Uso:

```cpp
#pragma fp_contract( [ on | off ] )
```

Conforme descrito em fp: seção precisa, contração é um recurso de arquitetura fundamental para muitas unidades de ponto flutuantes modernos. Contrações fornecem a capacidade de executar uma multiplicação seguida por uma adição como uma única operação com nenhum erro de arredondamento intermediário. Essas instruções únicas são mais rápido do que executar separado multiplicar e adicione as instruções e são mais precisas, pois não há nenhum arredondamento intermediário do produto. Uma operação contratada pode calcula o valor de `(a*b+c)` como se as duas operações foram computadas para precisão infinita e, em seguida, arredondadas para o mais próximo do número de ponto flutuante. Essa otimização significativamente pode acelerar a funções que contém várias intercalados multiply e adicionar operações. Por exemplo, considere o seguinte algoritmo que calcula o produto escalar de dois vetores de n-dimensional.

```cpp
float dotProduct( float x[], float y[], int n )
{
   float p=0.0;
   for (int i=0; i<n; i++)
      p += x[i]*y[i];
   return p;
}
```

Esse cálculo pode ser executado uma série de adição de instruções do formulário a multiplicar `p = p + x[i]*y[i]`.

O [fp_contract](../../preprocessor/fp-contract.md) pragma Especifica se as expressões de ponto flutuante podem ser reduzidas. Por padrão, o fp: modo preciso permite contrações como melhorar a velocidade e precisão. Contrações estão sempre habilitadas para o modo /FP: Fast. No entanto, pois contrações podem subverter a detecção explícita de condições de erro, o `fp_contract` pragma está sempre desabilitado em fp: modo estrito. Exemplos de expressões que podem ser contratado quando o `fp_contract` pragma está habilitado:

```cpp
float a, b, c, d, e, t;
...
d = a*b + c;         // may be contracted
d += a*b;            // may be contracted
d = a*b + e*d;       // may be contracted into a mult followed by a mult-add etc...

d = (float)a*b + c;  // won't be contracted because of explicit rounding

t = a*b;             // (this assignment rounds a*b to float)
d = t + c;           // won't be contracted because of rounding of a*b
```

## <a name="the-floatcontrol-pragma"></a>O float_control (pragma)

O **/fp: preciso**, **Fast**, **/fp: strict** e **/fp: exceto** opções controlam a semântica de ponto flutuante em um arquivo por arquivo base. O [float_control](../../preprocessor/float-control.md) pragma fornece controle desse tipo em uma base de função por função.

Uso:

```cpp
#pragma float_control(push)
#pragma float_control(pop)
#pragma float_control( precise, on | off [, push] )
#pragma float_control( except, on | off [, push] )
```

Os pragmas `float_control(push)` e `float_control(pop)` respectivamente enviar por push e pop-o estado atual do modo de ponto flutuante e a opção de exceção para uma pilha. Observe que o estado do `fenv_access` e `fp_contract` pragma não são afetados por `pragma float_control(push/pop)`.

Chamar o pragma `float_control(precise, on)` habilitará e `float_control(precise, off)` desabilitará a semântica de modo preciso. Da mesma forma, o pragma `float_control(except, on)` habilitará e `float_control(except, off)` desabilitará a semântica de exceção. Semântica de exceção só pode ser habilitada quando a semântica precisa também é habilitada. Quando opcional `push` argumento estiver presente, os estados do `float_control` opções são enviados por push antes da alteração semântica.

### <a name="setting-the-floating-point-semantic-mode-on-a-function-by-function-basis"></a>Definindo o modo de semântico de ponto flutuante em uma base de função por função

As opções de linha de comando são, na verdade, uma abreviação para definir os pragmas de ponto flutuantes quatro diferentes. Para escolher explicitamente um determinado modo semântico ponto flutuante em uma base de função por função, selecione cada uma os quatro pragmas de ponto flutuante opção conforme descrito na tabela a seguir:

||||||
|-|-|-|-|-|
||float_control(precise)|float_control(EXCEPT)|fp_contract|fenv_access|
|/FP: strict|em|em|Desativar|em|
|/FP: strict /fp: except-|em|Desativar|Desativar|em|
|/FP: preciso|em|Desativar|em|Desativar|
|/FP: preciso /fp: except|em|em|em|Desativar|
|Fast|Desativar|Desativar|em|Desativar|

Por exemplo, a seguir habilita explicitamente /FP: Fast semântica.

```cpp
#pragma float_control( except, off )   // disable exception semantics
#pragma float_control( precise, off )  // disable precise semantics
#pragma fp_contract(on)                // enable contractions
#pragma fenv_access(off)               // disable fpu environment sensitivity
```

> [!Note]
> Semântica de exceção deve ser desativada antes de desligar a semântica de "precisa".

## <a name="enabling-floating-point-exception-semantics"></a>Habilitando a semântica de exceção de ponto flutuante

Determinadas condições excepcionais de ponto flutuantes, como divisão por zero, podem fazer com que o FPU sinalizar uma exceção de hardware. Exceções de ponto flutuante são desabilitadas por padrão. Exceções de ponto flutuante são habilitadas, modificando a palavra de controle FPU com o `_controlfp` função. Por exemplo, o código a seguir habilita a exceção de ponto flutuante de divisão por zero:

```cpp
_clearfp(); // always call _clearfp before
            // enabling/unmasking a FPU exception
_controlfp( _EM_ZERODIVIDE, _MCW_EM );
```

Quando a exceção de divisão por zero está habilitada, qualquer operação de divisão com um denominador igual a zero fará com que uma exceção de FPU seja sinalizado.

Para restaurar a palavra de controle FPU para o modo padrão, chame `_controlfp(_CW_DEFAULT, ~0)`.

Habilitando a semântica de exceção de ponto flutuante com o **/fp: except** sinalizador não é igual a habilitar exceções de ponto flutuante. Quando a semântica de exceção de ponto flutuante é habilitada, o compilador deve considerar a possibilidade de que qualquer operação de ponto flutuante pode gerar uma exceção. Como o FPU é uma unidade de processador separado, as instruções em execução no FPU podem ser executadas simultaneamente com instruções sobre outras unidades.

Quando uma exceção de ponto flutuante está habilitada, o FPU cessar a execução da instrução incorreta e, em seguida, sinalizar uma condição excepcional, definindo a palavra de status FPU. Quando a CPU atinge a próxima instrução de ponto flutuante, ele verifica primeiro quaisquer exceções de FPU pendentes. Se houver uma exceção pendente, o processador intercepta-lo ao chamar um manipulador de exceção fornecido pelo sistema operacional. Isso significa que, quando uma operação de ponto flutuante encontra uma condição excepcional, a exceção correspondente não será detectada até que a próxima operação de ponto flutuante seja executada. Por exemplo, o código a seguir intercepta uma exceção de divisão por zero:

```cpp
double a, b, c;
// . . .
// ...unmasking of FPU exceptions omitted...
__try
{
   b/c; // assume c==0.0
   printf("This line shouldn't be reached when c==0.0\n");
   c = 2.0*b;
}
__except( EXCEPTION_EXECUTE_HANDLER )
{
   printf("SEH Exception Detected\n");
}
// . . .
```

Se ocorre uma condição de divisão por zero na expressão de um = b/c, o FPU não interceptação/geram a exceção até a próxima operação de ponto flutuante na expressão 2.0 * b. Isso resulta na seguinte saída:

```Output
This line shouldn't be reached when c==0.0
SEH Exception Detected
```

Printf correspondente para a primeira linha da saída deve não forem atingido; ele foi atingido porque a exceção de ponto flutuante causada pela expressão b/c não foi gerada até que a execução atingido 2.0 * b. Para gerar a exceção logo depois de executar b/c, o compilador deve apresentar uma instrução de "espera":

```cpp
// . . .
   __try
   {
      b/c; // assume this expression will cause a "divide-by-zero" exception
      __asm fwait;
      printf("This line shouldn't be reached when c==0.0\n");
      c = 2.0*b;
   }
// . . .
```

Essa instrução "espera" força o processador para sincronizar com o estado do FPU e tratar qualquer exceção pendente. O compilador gerará somente essas "espera" instruções quando semântica de ponto flutuante é habilitada. Quando essa semântica está desabilitada, pois há por padrão, programas podem encontrar erros de sincronia, semelhantes ao acima, ao usar exceções de ponto flutuante.

Quando a semântica de ponto flutuante estiver habilitada, o compilador não introduzirá somente instruções de "espera", ele também impede o compilador ilegalmente otimizando o código de ponto flutuante na presença de exceções possíveis. Isso inclui todas as transformações que alteram os pontos em que as exceções são geradas. Devido a esses fatores, permitindo que a semântica de ponto flutuante pode reduzir consideravelmente a eficiência do código de máquina gerado degradando assim o desempenho de um aplicativo.

Semântica de exceção de ponto flutuante é habilitada por padrão sob o fp: modo estrito. Para habilitar essa semântica no fp: modo preciso, adicione a **/fp: exceto** alternar para o compilador de linha de comando. Semântica de exceção de ponto flutuante também pode ser habilitada e desabilitada em uma base de função por função usando o `float_control` pragma.

### <a name="floating-point-exceptions-as-c-exceptions"></a>Exceções de ponto flutuante como exceções C++

Como com todas as exceções de hardware, exceções de ponto flutuante intrinsecamente não causam uma exceção de C++, mas em vez disso, disparam uma exceção estruturada. Para mapear exceções estruturadas de ponto flutuantes para exceções do C++, os usuários podem introduzir um tradutor de exceção SEH personalizado. Primeiro, apresente uma exceção de C++ correspondente a cada exceção de ponto flutuante:

```cpp
class float_exception : public std::exception {};

class fe_denormal_operand : public float_exception {};
class fe_divide_by_zero : public float_exception {};
class fe_inexact_result : public float_exception {};
class fe_invalid_operation : public float_exception {};
class fe_overflow : public float_exception {};
class fe_stack_check : public float_exception {};
class fe_underflow : public float_exception {};
```

Em seguida, introduzir uma função de conversão que detectará uma exceção SEH de ponto flutuante e lançar a exceção de C++ correspondente. Para usar essa função, defina o tradutor de manipulador de exceção estruturado para o thread atual do processo com o [set_se_translator](../../c-runtime-library/reference/set-se-translator.md) função da biblioteca de tempo de execução.

```cpp
void se_fe_trans_func( unsigned int u, EXCEPTION_POINTERS* pExp )
{
    switch (u)
    {
    case STATUS_FLOAT_DENORMAL_OPERAND:   throw fe_denormal_operand();
    case STATUS_FLOAT_DIVIDE_BY_ZERO:     throw fe_divide_by_zero();
   etc...
    };
}
// . . .
_set_se_translator(se_fe_trans_func);
```

Depois que esse mapeamento é inicializado, exceções de ponto flutuante se comportará como se fossem exceções do C++. Por exemplo:

```cpp
try
{
   // floating-point code that might throw divide-by-zero
   // or other floating-point exception
}
catch(fe_divide_by_zero)
{
    cout << "fe_divide_by_zero exception detected" << endl;
}
catch(float_exception)
{
    cout << "float_exception exception detected" << endl;
}
```

## <a name="references"></a>Referências

[O que cada cientista da computação deve saber sobre aritmética de ponto flutuante](http://pages.cs.wisc.edu/~david/courses/cs552/S12/handouts/goldberg-floating-point.pdf) por David Camargo.

## <a name="see-also"></a>Consulte também

[Otimizando seu código](optimizing-your-code.md)<br/>
