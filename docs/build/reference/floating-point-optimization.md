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
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 35c9263fa6252469124eefb0dfd575ef5bd2ac34
ms.sourcegitcommit: 5e932a0e110e80bc241e5f69e3a1a7504bfab1f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/21/2018
ms.locfileid: "34422726"
---
# <a name="microsoft-visual-c-floating-point-optimization"></a>Otimização de ponto flutuante do Microsoft Visual C++

Obtenha um identificador em otimizar o código de ponto flutuante usando o método do compilador do Microsoft C++ de gerenciar a semântica de ponto flutuante. Crie programas rápidos, garantindo que somente seguras otimizações são executadas em código de ponto flutuante.

## <a name="optimization-of-floating-point-code-in-c"></a>Otimização de código de ponto flutuante em C++

Um compilador de C++ otimização não só converte o código-fonte em código de máquina, organiza as instruções de máquina de forma a melhorar a eficiência e/ou reduzir o tamanho. Infelizmente, muitos otimizações comuns não são necessariamente seguras quando aplicado a cálculos de ponto flutuantes. Um bom exemplo disso pode ser visto com o seguinte algoritmo de soma, obtido David Goldberg, "O que cada computador cientista deve saber sobre aritmética de ponto flutuante", *computação pesquisas*, março de 1991, grupo de proteção. 203:

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

Essa função adiciona n **float** valores do vetor de matriz `A`. Dentro do corpo do loop, o algoritmo calcula um valor de "correção", que é então aplicado para a próxima etapa do Somatório. Esse método reduz consideravelmente os erros de arredondamento cumulativos em comparação com uma soma simple, enquanto mantém a complexidade de tempo (n).

Um compilador de C++ ingênua pode assumir a aritmética de ponto flutuante segue as mesmas regras algébricas aritmética de número Real. Tal um compilador, em seguida, pode erroneamente Concluir para que

> C = T - soma - Y = = > (soma + Y) - soma - Y = = > 0;

Ou seja, o valor percebido de C é sempre um constante zero. Se esse valor constante, em seguida, é propagado para as expressões subsequentes, o corpo do loop será reduzido para uma soma simple. Para ser preciso,

> Y = [i] - C = = > Y = [i]<br/>T = soma + Y = = > T = soma + [i]<br/>Sum = T = = > soma = soma + [i]

Portanto, ao compilador simples, uma transformação de lógica do `KahanSum` função seria:

```cpp
float KahanSum( const float A[], int n )
{
   float sum=0; // C, Y & T are now unused
   for (int i=0; i<n; i++)
      sum = sum + A[i];
   return sum;
}
```

Embora o algoritmo transformado é mais rápido, *não é uma representação precisa do intenção do programador*. A correção de erro concebidas cuidadosamente foi removida completamente e, nos resta com um algoritmo de soma simples e direto com seu erro associado.

Logicamente, um compilador de C++ sofisticado saberia algébricas ou regras de Real aritmética não geralmente se aplicam a aritmética de ponto flutuante. No entanto, até mesmo um compilador de C++ sofisticado ainda incorretamente pode interpretar a intenção do programador.

Considere uma otimização comuns que tenta manter todos os valores nos registros possível (chamado "Registro" um valor). No `KahanSum` exemplo, essa otimização pode tentar registre as variáveis `C`, `Y` e `T` desde que eles são usados somente dentro do corpo do loop. Se a precisão de registro é 52bits (double) em vez de 23bits (único), essa otimização efetivamente tipo promove `C`, `Y` e `T` digitar **duplo**. Se a variável de soma não é registrado da mesma forma, ele permanecerá codificado na precisão única. Isto transforma a semântica de `KahanSum` à seguinte

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

Embora `Y`, `T` e `C` agora são computadas em uma maior precisão, essa nova codificação pode produzir um resultado de menos preciso que dependem de valores em `A[]`. Assim, até mesmo aparentemente inofensivas otimizações podem ter consequências negativas.

Esses tipos de problemas de otimização não são restritos ao código de ponto flutuante "difícil". Algoritmos de ponto flutuantes simples podem falhar quando a otimização incorretamente. Considere um algoritmo simple e direto de resumo:

```cpp
float Sum( const float A[], int n )
{
   float sum=0;
   for (int i=0; i<n; i++)
      sum = sum + A[i];
   return sum;
}
```

Como algumas unidades de ponto flutuantes são capazes de realizar várias operações simultaneamente, um compilador pode optar por envolver uma otimização de redução de escalar. Essa otimização efetivamente transforma a função soma simple acima para o seguinte:

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

Agora, a função mantém quatro somas separadas, que podem ser processadas simultaneamente em cada etapa. Embora a função otimizada agora é muito mais rápida, os resultados otimizados podem ser bastante diferentes dos resultados não otimizada. Para fazer essa alteração, o compilador assumido associativa adição de ponto flutuante; ou seja, se essas duas expressões são equivalentes: `(a + b) + c == a + (b + c)`. No entanto, capacidade de associação não sempre são verdadeiras para números de ponto flutuante. Em vez de calcular a soma como:

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

Para alguns valores de `A[]`, essa ordem diferente das operações de adição pode produzir resultados inesperados. Para complicar as coisas ainda mais, alguns programadores podem optar por antecipar tais otimizações e compensá-los corretamente. Nesse caso, um programa pode construir a matriz `A` em uma ordem diferente para que a soma otimizada produz os resultados esperados. Além disso, em muitas circunstâncias a exatidão do resultado otimizado pode ser "perto o suficiente". Isso é especialmente verdadeiro quando a otimização oferece benefícios de velocidade atraentes. Jogos de vídeo, por exemplo, exigem muito acelerar possível, mas geralmente não exigem cálculos de ponto flutuantes altamente precisos. Criadores de compilador, portanto, devem fornecer um mecanismo para programadores controlar os diferentes geralmente objetivos de precisão e a velocidade.

Alguns compiladores resolver a compensação entre a precisão e a velocidade, fornecendo um comutador separado para cada tipo de otimização. Isso permite aos desenvolvedores desabilitar otimizações que estão causando as alterações de ponto flutuante de precisão para seu aplicativo em particular. Embora essa solução pode oferecer um alto grau de controle sobre o compilador, ele apresenta vários problemas adicionais:

- Geralmente é claro que alterna para habilitar ou desabilitar.
- Desabilitar qualquer otimização única pode afetar negativamente o desempenho do código ponto não flutuante.
- Cada comutador adicional incorre em muitas combinações de comutador novo; o número de combinações rapidamente se tornar complicado.

Então embora possa parecer atraente fornecer comutadores separados para cada otimização, usando esses compiladores pode ser complicadas e não confiável.

Muitos compiladores C++ oferecem um *consistência* modelo de ponto flutuante (por meio de um **/Op** ou **/fltconsistency** alternar) que permite que um desenvolvedor crie programas compatíveis com a semântica estrita de ponto flutuante. Quando estiver encaixada, esse modelo impede que o compilador usando a maioria das otimizações em cálculos de ponto flutuantes ao mesmo tempo, permitindo que essas otimizações para ponto não flutuante código. O modelo de consistência, no entanto, tem um lado escuro. Para retornar resultados previsíveis em arquiteturas diferentes de FPU, quase todas as implementações de **/Op** round expressões intermediárias para o usuário especificado precisão; por exemplo, considere a seguinte expressão:

```cpp
float a, b, c, d, e;
// . . .
a = b * c + d * e;
```

Para produzir resultados consistentes e repetíveis em **/Op**, essa expressão é avaliada como se ela foi implementada da seguinte maneira:

```cpp
float x = b  *c;
float y = d * e;
a = x + y;
```

O resultado final agora tem erros de arredondamento de precisão única *em cada etapa da avaliação da expressão*. Embora essa interpretação estritamente não violam nenhuma regra de semântica de C++, quase nunca é a melhor maneira de avaliar expressões de ponto flutuantes. É geralmente mais desejável para calcular o intermediário resulta em mais alto precisão conforme é prático. Por exemplo, seria melhor computar a expressão `a = b * c + d * e` em uma maior precisão, como em

```cpp
double x = b * c;
double y = d * e;
double z = x + y;
a = (float)z;
```

ou, melhor ainda

```cpp
long double x = b * c;
long double y = d * e
long double z = x + y;
a = (float)z;
```

Ao calcular os resultados intermediários em uma maior precisão, o resultado final é significativamente mais preciso. Ironicamente, adotando um modelo de consistência, a probabilidade de erro é aumentada precisamente quando o usuário está tentando reduzir erro desabilitando otimizações não seguras. Assim, o modelo de consistência pode reduzir drasticamente eficiência enquanto simultaneamente não fornece nenhuma garantia de aumento da precisão. Para programadores numéricos sérios, isso não parece um bom equilíbrio e é o principal motivo que o modelo não for geralmente bem recebido.

Compilador começando na versão 8.0 (Visual C++® 2005), o Microsoft C++ fornece uma alternativa muito melhor. Ele permite que os programadores selecionar um dos três modos de ponto flutuantes gerais: fp: precise, /FP: Fast e fp: estrito.

- Em fp: precisas, somente as otimizações de seguras são executadas no código de ponto flutuante e, ao contrário de **/Op**, cálculos intermediários consistentemente são executados na mais alta precisão prática.
- modo /FP: Fast alivia permitindo mais agressiva otimização às custas de precisão de regras de ponto flutuantes.
- FP: modo estrito fornece todos os a exatidão geral do fp: preciso ao habilitar a semântica de exceção de fp e evitando a transformações ilegais na presença de alterações de ambiente de FPU (por exemplo, as alterações para a precisão de registro, arredondando direção etc).

Semântica de exceção de ponto flutuante pode ser controlada independentemente por linha de comando ou um pragma de compilador; Por padrão, a semântica de exceção de ponto flutuante está desabilitada em fp: precisas e habilitado em fp: estrito. O compilador também fornece controle sobre a sensibilidade do ambiente de FPU e certas otimizações específicas de ponto flutuantes, como contrações. Esse modelo direta oferece aos desenvolvedores um grande controle sobre a compilação de código de ponto flutuante sem a sobrecarga de muitas opções de compilador ou a perspectiva de efeitos colaterais indesejáveis.

## <a name="the-fpprecise-mode-for-floating-point-semantics"></a>Fp: modo preciso para semântica de ponto flutuante

O modo padrão de semântica de ponto flutuante é fp: precisas. Quando este modo é selecionado, o compilador estritamente segue um conjunto de regras de segurança durante a otimização das operações de ponto flutuante. Essas regras permitem que o compilador para gerar o código de máquina eficiente, mantendo a precisão dos cálculos de ponto flutuantes. Para facilitar a produção de fast programas, fp: modelo preciso desabilita a semântica de exceção de ponto flutuante (embora eles podem ser explicitamente habilitados). Microsoft selecionou fp: preciso como o modo de ponto flutuante padrão porque ele cria programas rápidos e precisos.

Para solicitar explicitamente o fp: modo preciso usando o compilador de linha de comando, use o [/fp: preciso](fp-specify-floating-point-behavior.md) alternar:

> Cl /fp: source.cpp preciso

Isso instrui o compilador use fp: semântica precisa ao gerar o código para o arquivo source.cpp. Fp: modelo preciso também pode ser chamado em uma base por função de função usando o [float_control (pragma) compilador](#the-float-control-pragma).

Sob o fp: modo preciso, o compilador nunca executa qualquer otimizações que perturbar a precisão dos cálculos de ponto flutuantes. O compilador sempre será arredondado corretamente em atribuições, typecasts e chamadas de função e arredondamento intermediário serão consistentemente executado na mesma precisão que registra o FPU. Otimizações de seguras, como contrações, são habilitadas por padrão. Semântica de exceção e a sensibilidade do ambiente de FPU estão desabilitados por padrão.

|FP: semântica precisa|Explicação|
|-|-|
|Semântica de arredondamento|Arredondamento explícita em atribuições, typecasts e chamadas de função. Intermediárias expressões serão avaliadas no registro de precisão.|
|Transformações algébricas|Estrita aderência a álgebra de ponto flutuante não associativa, não distributivo, a menos que uma transformação é garantida que sempre produzir os mesmos resultados.|
|Contrações|Permitido por padrão. Para obter mais informações, consulte a seção [o pragma fp_contract](#the-fp-contract-pragma).|
|Ordem de avaliação de ponto flutuante|O compilador pode reordenar a avaliação de expressões de ponto flutuantes, desde que os resultados finais não são alterados.|
|Acesso ao ambiente FPU|Desabilitado por padrão. Para obter mais informações, consulte a seção [o pragma fenv_access](#the-fenv-access-pragma). A precisão padrão e o modo de arredondamento será assumido.|
|Semântica de exceção de ponto flutuante|Desabilitado por padrão. Para obter mais informações, consulte [/fp: exceto](fp-specify-floating-point-behavior.md).|

### <a name="rounding-semantics-for-floating-point-expressions-under-fpprecise"></a>Semântica de expressões de ponto flutuantes em fp de arredondamento: preciso

Fp: modelo preciso sempre executa cálculos intermediários na mais alta precisão prático, explicitamente arredondamento somente em determinados pontos na avaliação da expressão. Para a precisão especificada pelo usuário sempre arredondamento em quatro casas: (a) quando uma atribuição é feita, (b) quando uma conversão de tipo é executada, (c) quando um valor de ponto flutuante é passado como um argumento para uma função e (d) quando um valor de ponto flutuante é retornado de um função. Como cálculos intermediários sempre são executados no registro de precisão, a precisão dos resultados intermediários é dependente de plataforma (embora a precisão será sempre pelo menos tão precisa quanto o usuário especificado precisão).

Considere a expressão de atribuição no código a seguir. A expressão no lado direito da atribuição operador '=' será calculada no registro de precisão e explicitamente arredondada para o tipo do lado esquerdo da atribuição.

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

Para arredondar explicitamente um resultado intermediário, introduza um typecast. Por exemplo, se o código anterior for modificado pela adição explícita conversão de tipo, a expressão intermediária (c * d) será arredondado para o tipo do typecast.

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

Uma implicação deste método de arredondamento é que algumas transformações aparentemente equivalentes, na verdade, não tem semântica idêntica. Por exemplo, a seguinte transformação divide uma expressão de atribuição único em duas expressões de atribuição.

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

Essas codificações não tem semântica equivalente porque as codificações segundo cada introduziram uma operação de atribuição adicionais e, portanto, aponte a um arredondamento adicionais.

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

### <a name="architecture-specific-rounding-under-fpprecise"></a>Específica da arquitetura de arredondamento em fp: preciso

|Processador|Arredondando a precisão para expressões intermediárias|
|-|-|
|x86|Expressões intermediárias são computadas na precisão de 53 bits padrão com um intervalo estendido fornecido por um expoente de 16 bits. Quando esses valores 53:16 são "derramamento" para a memória (como pode ocorrer durante uma chamada de função), o intervalo de expoente estendido serão restritas para 11-bits. Ou seja, derramados valores são convertidos para o formato padrão de precisão dupla com apenas um expoente 11 bits.<br/>Um usuário pode alternar para precisão estendida de 64 bits de arredondamento intermediário alterando a palavra de controle de ponto flutuante usando `_controlfp` e habilitando o acesso ao ambiente FPU (consulte [o pragma fenv_access](#the-fenv-access-pragma)). No entanto, quando os valores do registro de precisão estendida são vazados em memória, os resultados intermediários ainda serão arredondados à precisão dupla.<br/>Semântica específico está sujeita a alterações.|
|amd64|Semântica FP em amd64 é um pouco diferente de outras plataformas. Por motivos de desempenho, operações intermediárias são computadas na precisão mais ampla de ambos os operandos em vez de em maior precisão disponível.  Para forçar os cálculos para ser calculado usando uma precisão maior que os operandos, os usuários precisam apresentar uma operação de conversão em pelo menos um operando em uma subexpressão.<br/>Semântica específico está sujeita a alterações.|

### <a name="algebraic-transformations-under-fpprecise"></a>Transformações algébricas em fp: preciso

Quando o fp: modo preciso estiver habilitado, o compilador nunca irá executar transformações algébricas *, a menos que o resultado final é idêntico provavelmente*. Muitas das regras algébricas familiares para aritmética de número Real não mantenha sempre para aritmética de ponto flutuante. Por exemplo, as expressões a seguir são equivalentes para reais, mas não necessariamente para flutuações.

|Formulário|Descrição|
|-|-|
|`(a+b)+c = a+(b+c)`|Regra de associação para adição|
|`(a*b)*c = a*(b*c)`|Regra de associação de multiplicação|
|`a*(b+c) = a*b + b*c`|Distribuição de multiplicação de adição|
|`(a+b)(a-b) = a*a-b*b`|Fatorar algébricas|
|`a/b = a*(1/b)`|Divisão por multiplicative inverso|
|`a*1.0 = a`|Identidade de multiplicação|

Conforme ilustrado no exemplo de Introdução com a função `KahanSum`, o compilador pode ser tentado a realizar várias transformações algébricas para produzir programas consideravelmente mais rápidos. Embora otimizações dependentes essas transformações algébricas quase sempre estão incorretas, há ocasiões em que eles são perfeitamente seguros. Por exemplo, às vezes é desejável para substituir a divisão por um *constante* valor com a multiplicação pela multiplicação inversa da constante:

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

Isso é uma transformação de segurança porque o otimizador pode determinar em tempo de compilação que x / 4.0 = = x*(1/4.0) para todos os valores de ponto flutuantes de x, incluindo infinitos e NaN. Substituindo uma operação de divisão por uma multiplicação, o compilador pode salvar vários ciclos — especialmente em FPUs que não implementam a divisão diretamente, mas requerem o compilador para gerar uma combinação de aproximação recíproca e multiplique-adicionar instruções. O compilador pode executar essa otimização em fp: precisa apenas quando a multiplicação de substituição produz exato mesmo resultado da divisão. O compilador também pode executar transformações triviais em fp: precisas, desde que os resultados são idênticos. Elas incluem:

|Formulário|Descrição
|-|-|
|`(a+b) == (b+a)`|Regra comutativa para adição|
|`(a*b) == (b*a)`|Regra de comutativa de multiplicação|
|`1.0*x*y == x*1.0*y == x*y*1.0 == x*y`|Multiplicação por 1.0|
|`x/1.0*y == x*y/1.0 == x*y`|Divisão por 1.0|
|`2.0*x == x+x`|Multiplicação pelo 2.0|

### <a name="contractions-under-fpprecise"></a>Contrações em fp: preciso

Um recurso importante de arquitetura de muitas unidades de ponto flutuantes modernos é a capacidade de executar uma multiplicação seguida por uma adição como uma única operação sem erros de arredondamento intermediário. Por exemplo, da arquitetura da Intel Itanium fornece instruções para combinar cada uma dessas operações Ternário, (um*b + c), (um*b-c) e (c-a * b), em uma única instrução de ponto flutuante (fma, fms e fnma respectivamente). Essas instruções único são mais rápido do que executar separado multiplicar e adicionar instruções e são mais precisas porque não há nenhum arredondamento intermediário do produto. Essa otimização significativamente pode acelerar a funções que contém várias intercaladas multiplicar e adicionar operações. Por exemplo, considere o seguinte algoritmo que calcula o produto de ponto de dois vetores de n-dimensional.

```cpp
float dotProduct( float x[], float y[], int n )
{
   float p=0.0;
   for (int i=0; i<n; i++)
      p += x[i]*y[i];
   return p;
}
```

Esse cálculo pode ser realizado uma série de adição de instruções do formulário p a multiplicação = p + x [i] * y [i].

A otimização contração pode ser controlada de forma independente usando o `fp_contract` pragma do compilador. Por padrão, o fp: modelo preciso permite contrações como melhorar a precisão e a velocidade. Em fp: precisas, o compilador nunca será contrato uma expressão com o arredondamento explícita.
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

Otimizações que preservam a ordem de avaliação de expressão de ponto flutuante são sempre seguras e, portanto, são permitidas sob o fp: modo preciso. Considere a seguinte função que calcula o produto de dois vetores n-dimensional de precisão única. O primeiro bloco de código abaixo é a função original como ele pode ser codificado por um programador, seguida pela mesma função após uma otimização parcial unrolling de loop.

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

A principal vantagem dessa otimização é que ela reduz o número de ramificação de loop condicional em 75%. Além disso, aumentando o número de operações no corpo do loop, o compilador agora pode ter mais oportunidades para otimizar ainda mais. Por exemplo, alguns FPUs podem ser capazes de executar o multiplicar-adicionar no + p = x [i] * y [i] ao buscar simultaneamente os valores de x [i + 1] e y [i + 1] para uso na próxima etapa. Esse tipo de otimização é perfeitamente seguro para cálculos de ponto flutuantes porque ele preserva a ordem das operações.

Muitas vezes é vantajoso para o compilador reordenar operações inteiras para gerar código mais rápido. Considere o código a seguir:

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

As regras semânticas do C++ indicam que o programa deve produzir resultados como se ele primeiro computado x e y e, finalmente, z. Suponha que o compilador tenha apenas quatro registros de ponto flutuantes disponíveis. Se o compilador é forçado a computação x, y e z em ordem, ele pode optar por gerar o código com a seguinte semântica:

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

Há várias operações claramente redundantes é essa codificação. Se o compilador estritamente segue as regras semânticas do C++, essa ordem é necessária porque o programa pode acessar o ambiente de FPU entre cada atribuição. No entanto, as configurações padrão de fp: preciso permitir que o compilador otimizar como se o programa não acesse o ambiente, permitindo que ele reordenar nessas expressões. Em seguida, é gratuito remover as redundâncias computando três valores na ordem inversa, da seguinte maneira:

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

Essa codificação é claramente melhor, redução do número de instruções de fp em quase 40%. Os resultados para x, y e z são os mesmos de antes, mas computado com menos sobrecarga.

Em fp: precisas, o compilador pode também *de entrelaçamento* subexpressões comuns para gerar código mais rápido. Por exemplo, código para calcular as raízes de uma equação quadrática pode ser escrito da seguinte maneira:

```cpp
double a, b, c, root0, root1;
...
root0 = (-b + sqrt(b*b-4*a*c))/(2*a);
root1 = (-b - sqrt(b*b-4*a*c))/(2*a);
```

Embora essas expressões diferem apenas por uma única operação, o programador pode escrevê-los dessa maneira para garantir que cada valor de raiz será calculado a mais alta precisão prático. Em fp: precisas, o compilador é livre para o cálculo da root0 e root1 remover subexpressões comuns sem perda de precisão de entrelaçamento. Por exemplo, o seguinte removeu várias etapas redundantes e apresente a mesma resposta exata.

```cpp
double a, b, c, root0, root1;
...
register tmp0 = -b;
register tmp1 = sqrt(b*b-4*a*c);
register tmp2 = 2*a;
root0 = (tmp0+tmp1)/tmp2;
root1 = (tmp0-tmp1)/tmp2;
```

Outras otimizações podem tentar mover a avaliação de determinadas expressões independentes. Considere o seguinte algoritmo que contém uma ramificação condicional dentro de um corpo do loop.

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

Após a transformação não é mais uma ramificação condicional em ambos os corpos de loop, melhorando assim o desempenho geral do loop. Esse tipo de otimização é perfeitamente seguro porque a avaliação da expressão (abs(d) > 1.0) é independente de outras expressões.

Na presença de acesso ao ambiente FPU ou exceções de ponto flutuante, esses tipos de otimização são contraindicated porque eles alteram o fluxo de semântico. Tais otimizações só estão disponíveis em fp: modo preciso porque o acesso ao ambiente FPU e a semântica de exceção de ponto flutuante é desabilitada por padrão. Funções que acessam o ambiente de FPU poderá desabilitar explicitamente tais otimizações usando o `fenv_access` pragma do compilador. Da mesma forma, as funções que usam exceções de ponto flutuante devem usar o `float_control(except ... )` compilador pragma (ou use o **/fp: exceto** opção de linha de comando).

Em resumo, fp: modo preciso permite que o compilador para reordenar a avaliação de expressões de ponto flutuantes em condição de que os resultados finais não são alterados e que os resultados não são dependentes no ambiente de FPU ou em exceções de ponto flutuante.

### <a name="fpu-environment-access-under-fpprecise"></a>O acesso ao ambiente FPU em fp: preciso

Quando o fp: modo preciso estiver habilitado, o compilador assumirá que um programa não acessar ou alterar o ambiente de FPU. Conforme mencionado anteriormente, essa suposição permite que o compilador reorganizar ou mover operações de ponto flutuante para melhorar a eficiência em fp: precisas.

Alguns programas podem alterar a ponto flutuante arredondamento direção usando o `_controlfp` função. Por exemplo, alguns programas de computação superior e inferiores limites de erro em operações aritméticas, executando o mesmo cálculo duas vezes, primeiro ao arredondamento em direção infinito negativo, em seguida, enquanto arredondamento até o infinito positivo. Como o FPU fornece uma maneira conveniente para controlar o arredondamento, um programador pode optar por alterar o modo de arredondamento alterando o ambiente de FPU. O código a seguir calcula o que erro exato associado de uma multiplicação de ponto flutuante alterando o ambiente de FPU.

```cpp
double a, b, cLower, cUpper;
// . . .
_controlfp( _RC_DOWN, _MCW_RC );    // round to -&infin;
cLower = a*b;
_controlfp( _RC_UP, _MCW_RC );    // round to +&infin;
cUpper = a*b;
_controlfp( _RC_NEAR, _MCW_RC );    // restore rounding mode
```

Em fp: precisas, o compilador sempre assume o ambiente de FPU padrão, portanto, é livre para ignorar as chamadas para o otimizador `_controlfp` e reduzir as atribuições acima para cUpper = cLower = um * b; isso claramente produziria resultados incorretos. Para evitar tais otimizações, habilitar o acesso ao ambiente FPU usando o `fenv_access` pragma do compilador.

Outros programas podem tentar detectar alguns erros de ponto flutuantes verificando palavra de status de FPU. Por exemplo, o código a seguir verifica as condições de divisão por zero e inexatas

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

Em fp: precisas, otimizações que reordenar a avaliação da expressão podem alterar os pontos que certos erros ocorrem. Programas que acessam a palavra de status devem habilitar o acesso ao ambiente FPU usando o `fenv_access` pragma do compilador.

Para obter mais informações, consulte a seção [o pragma fenv_access](#the-fenv-access-pragma).

### <a name="floating-point-exception-semantics-under-fpprecise"></a>Semântica de exceção de ponto flutuante em fp: preciso

Por padrão, a semântica de exceção de ponto flutuante está desabilitada em fp: precisas. A maioria dos programadores C++ preferir lidar com condições de ponto flutuantes excepcionais sem usar o sistema ou as exceções do C++. Além disso, conforme mencionado anteriormente, desabilitando a semântica de exceção de ponto flutuante permite a flexibilidade do compilador durante a otimização das operações de ponto flutuante. Use o **/fp: exceto** alternar ou `float_control` pragma para habilitar a semântica de exceção de ponto flutuante ao usar o fp: modelo preciso.

Para obter mais informações, consulte a seção [habilitando a semântica de exceção de ponto flutuante](#enabling-floating-point-exception-semantics).

## <a name="the-fpfast-mode-for-floating-point-semantics"></a>O modo de /FP: Fast de semântica de ponto flutuante

Quando o modo /FP: Fast estiver habilitado, o compilador alivia as regras que fp: preciso usa durante a otimização das operações de ponto flutuante. Este modo é permite que o compilador otimizar ainda mais o código de ponto flutuante para velocidade às custas de precisão de ponto flutuante e precisão. Programas que não dependem de alta precisão cálculos de ponto flutuantes podem enfrentar uma melhoria significativa de velocidade, permitindo que o modo /FP: Fast.

O modo de ponto flutuante /FP: Fast é habilitado por meio de [Fast](fp-specify-floating-point-behavior.md) opção de compilador de linha de comando da seguinte maneira:

> Cl Fast source.cpp

Este exemplo instrui o compilador use /FP: Fast semântica ao gerar o código para o arquivo source.cpp. O modelo /FP: Fast também pode ser chamado em uma base por função de função usando o `float_control` pragma do compilador.

Para obter mais informações, consulte a seção [o float_control (pragma)](#the-float-control-pragma).

No modo de /FP: Fast, o compilador pode executar otimizações que alterar a precisão dos cálculos de ponto flutuantes. O compilador não arredondará corretamente em atribuições, typecasts ou chamadas de função e arredondamento intermediária não será sempre executado. Ponto flutuantes otimizações específicas, como contrações, estão sempre habilitadas. Semântica de exceção de ponto flutuante e sensibilidade do ambiente de FPU são desabilitados e não está disponível.

|semântica de /FP: Fast|Explicação
|-|-|
|Semântica de arredondamento|Arredondamento explícita em atribuições, typecasts e chamadas de função podem ser ignoradas.<br/>Expressões intermediárias podem ser arredondadas no menor do que registrar a precisão de acordo com os requisitos de desempenho.|
|Transformações algébricas|O compilador pode transformar expressões de acordo com o número real álgebra associativa, distributiva; Não há garantia de que essas transformações ser precisos ou correto.|
|Contrações|Sempre ativada; não pode ser desabilitado por pragma `fp_contract`|
|Ordem de avaliação de ponto flutuante|O compilador pode reordenar a avaliação de expressões de ponto flutuantes, mesmo quando essas alterações podem alterar os resultados finais.|
|Acesso ao ambiente FPU|Desabilitado. Não disponível|
|Semântica de exceção de ponto flutuante|Desabilitado. Não disponível|

### <a name="rounding-semantics-for-floating-point-expressions-under-fpfast"></a>Arredondamento semântica de expressões de ponto flutuantes sob /FP: Fast

Ao contrário de fp: modelo preciso, o modelo de /FP: Fast executa cálculos intermediários precisão mais conveniente. Arredondamento em atribuições, typecasts e chamadas de função não podem ocorrer sempre. Por exemplo, a primeira função abaixo apresenta três variáveis de precisão simples (`C`, `Y` e `T`). O compilador pode optar por Registre essas variáveis, na verdade de promoção de tipo `C`, `Y` e `T` para precisão dupla.

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

Variáveis registrado:

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

Neste exemplo, /FP: Fast tem subverted a intenção da função original. Otimização de final de resultados, mantido na variável `sum`, pode ser bastante perturbed do resultado correto.

Sob /FP: Fast, o compilador normalmente tentará manter pelo menos a precisão especificada pelo código-fonte. No entanto, em alguns casos o compilador poderá optar por executar expressões intermediárias em um *menor precisão* que o especificado no código-fonte. Por exemplo, o primeiro bloco de código abaixo chama uma versão de precisão dupla da função raiz quadrada. Sob /FP: Fast, em certas circunstâncias, como quando o resultado e operandos da função são lançados explicitamente a precisão simples, o compilador pode optar por substituir a chamada para a precisão dupla `sqrt` com uma chamada para um única precisão `sqrtf`função. Como conversões Certifique-se de que o valor de entrar em `sqrt` e o valor de saída são arredondados para precisão única, isso altera apenas o lugar de arredondamento. Se o valor entram sqrt era um valor de precisão dupla e o compilador executada essa transformação, a metade dos bits de precisão pode estar errada.

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

Embora menos precisos, essa otimização pode ser especialmente útil quando o objetivo de processadores que fornecem precisão única, intrínsecas versões das funções, como `sqrt`. Apenas precisamente quando o compilador usará essas otimizações é dependente de plataforma e o contexto.

Além disso, há sem garantia de consistência para a precisão dos cálculos intermediários, que pode ser executada em qualquer nível de precisão disponível para o compilador. Embora o compilador tentará manter pelo menos o nível de precisão conforme especificado pelo código, /FP: Fast permite que o otimizador cálculos intermediários baixá-los para gerar o código de máquina rápido ou menor. Por exemplo, o compilador pode otimizar ainda mais o código acima para arredondar alguns as multiplicações intermediárias de precisão única.

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

Esse tipo de arredondamento adicionais pode resultar de usando uma menor unidade ponto flutuante de precisão, como SSE2, para executar algumas dos cálculos intermediários. A precisão de arredondamento /FP: Fast, portanto, é dependente de plataforma; código que compila bem para um processador necessariamente pode não funcionar bem para outro processador. Ele é mantido ao usuário para determinar se os benefícios de velocidade superam os problemas de precisão.

Se a otimização /FP: Fast é especialmente problemática para uma função específica, o modo de ponto flutuante pode ser alternado localmente para fp: precisas usando o `float_control` pragma do compilador.


### <a name="algebraic-transformations-under-fpfast"></a>Transformações algébricas sob /FP: Fast

O modo /FP: Fast permite que o compilador executar certas, transformações algébricas inseguras para flutuante ponto expressões. Por exemplo, as seguintes otimizações não seguras podem ser empregadas sob /FP: Fast.

||||
|-|-|-|
|Código original|Etapa 1 #|Etapa 2 #
|`double a, b, c;`<br/>`double x, y, z;`<br/><br/>`y = (a + b);`<br/>`z = y – a – b;`<br/><br/>`c = x – z;`<br/><br/>`c = x * z;`<br/><br/>`c = x - z;`<br/><br/>`c = x + z;`<br/><br/>`c = z-x;`|`double a, b, c;`<br/>`double x, y, z;`<br/><br/>`y = (a + b);`<br/>`z = 0;`<br/><br/>`c = x – 0;`<br/><br/>`c = x * 0;`<br/><br/>`c = x - 0;`<br/><br/>`c = x + 0;`<br/><br/>`c = 0 - x;`|`double a, b, c;`<br/>`double x, y, z;`<br/><br/>`y = (a + b);`<br/>`z = 0;`<br/><br/>`c = x;`<br/><br/>`c = 0;`<br/><br/>`c = x;`<br/><br/>`c = x;`<br/><br/>`c = -x;`|

Na etapa 1, o compilador observa que `z = y – a – b` é sempre igual a zero. Embora seja tecnicamente uma observação inválida, é permitido sob /FP: Fast. O compilador, em seguida, propaga o valor da constante zero para cada uso subsequente da variável z. Na etapa 2, o compilador mais otimiza observando que `x - 0 == x`, `x * 0 == 0`, etc. Novamente, mesmo que essas observações não são estritamente válidas, são permitidas sob /FP: Fast. O código otimizado agora é muito mais rápido, mas também pode ser consideravelmente menos precisos ou até mesmo incorreto.

Qualquer uma das seguintes regras algébricas (seguras) pode ser empregado pelo otimizador de quando o modo /FP: Fast está habilitado:

|||
|-|-|
|Formulário|Descrição|
|`(a + b) + c = a + (b + c)`|Regra de associação para adição|
|`(a * b) * c = a * (b * c)`|Regra de associação de multiplicação|
|`a * (b + c) = a * b + b * c`|Distribuição de multiplicação de adição|
|`(a + b)(a - b) = a * a - b * b`|Fatorar algébricas|
|`a / b = a * (1 / b)`|Divisão por multiplicative inverso|
|`a * 1.0 = a, a / 1.0 = a`|Identidade de multiplicação|
|`a ± 0.0 = a, 0.0 - a = -a`|Aditivo identidade|
|`a / a = 1.0, a - a = 0.0`|Cancelamento|

Se a otimização /FP: Fast é especialmente problemática para uma função específica, o modo de ponto flutuante pode ser alternado localmente para fp: precisas usando o `float_control` pragma do compilador.

### <a name="order-of-floating-point-expression-evaluation-under-fpfast"></a>Ordem de avaliação de expressão de ponto flutuante sob /FP: Fast

Ao contrário de fp: precise, /FP: Fast permite que o compilador reordenar as operações de ponto flutuante para produzir um código mais rápido. Assim, algumas otimizações sob /FP: Fast podem não preservar a ordem desejada de expressões. Por exemplo, considere a seguinte função que calcula o produto de dois vetores de n-dimensional.

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

Sob /FP: Fast, o otimizador pode realizar uma redução escalar do `dotProduct` função transformar efetivamente a função da seguinte maneira:

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

Na versão otimizada da função quatro separado para somas de produto são executadas simultaneamente e, em seguida, adicionadas juntos. Essa otimização pode acelerar o cálculo do `dotProduct` por tanto quanto um fator de quatro dependendo do processador de destino, mas o resultado final pode não ser tão precisas sobre inutilizá-lo. Se essas otimizações são especialmente problemáticas para função único ou unidade de tradução, o modo de ponto flutuante pode ser alternado localmente para fp: precisas usando o `float_control` pragma do compilador.

## <a name="the-fpstrict-mode-for-floating-point-semantics"></a>Fp: modo estrito de semântica de ponto flutuante

Quando o fp: modo estrito está habilitado, o compilador segue as mesmas regras que fp: preciso usa durante a otimização das operações de ponto flutuante. Esse modo também permite que a semântica de exceção de ponto flutuante e sensibilidade para o ambiente de FPU e desabilita determinadas otimizações como contrações. É o modo mais rígido de operação.

Fp: modo estrito de ponto flutuante é habilitado por meio de [/fp: strict](fp-specify-floating-point-behavior.md) opção de compilador de linha de comando da seguinte maneira:

> Cl /fp: strict source.cpp

Este exemplo instrui o compilador use fp: semântica estrita ao gerar o código para o arquivo source.cpp. Fp: estrito modelo também pode ser chamado em uma base por função de função usando o `float_control` pragma do compilador.

Para obter mais informações, consulte a seção [o float_control (pragma)](#the-float-control-pragma).

Sob o fp: modo estrito, o compilador nunca executa qualquer otimizações que perturbar a precisão dos cálculos de ponto flutuantes. O compilador sempre será arredondado corretamente em atribuições, typecasts e chamadas de função e arredondamento intermediário serão consistentemente executado na mesma precisão que registra o FPU. Semântica de exceção de ponto flutuante e sensibilidade do ambiente de FPU estão habilitados por padrão. Certas otimizações, como contrações, estão desabilitadas porque o compilador não pode garantir a exatidão em todos os casos.

|FP: semântica estrita|Explicação|
|-|-|
|Semântica de arredondamento|Arredondamento explícita em atribuições, typecasts e chamadas de função<br/>Intermediárias expressões serão avaliadas no registro de precisão.<br/>Mesmo que fp: preciso|
|Transformações algébricas|Estrita aderência a álgebra de ponto flutuante não associativa, não distributivo, a menos que uma transformação é garantida que sempre produzir os mesmos resultados.<br/>Mesmo que fp: preciso|
|Contrações|Sempre desabilitado|
|Ordem de avaliação de ponto flutuante|O compilador não reorganizará a avaliação de expressões de ponto flutuantes|
|Acesso ao ambiente FPU|Sempre habilitado.|
|Semântica de exceção de ponto flutuante|Habilitado por padrão.|

### <a name="floating-point-exception-semantics-under-fpstrict"></a>Semântica de exceção de ponto flutuante em fp: estrito

Por padrão, semântica de exceção de ponto flutuante é habilitada em fp: modelo estrito. Para desabilitar essa semântica, use o **/fp: exceto-** alternar ou apresentar um `float_control(except, off)` pragma.

Para obter mais informações, consulte as seções [habilitando a semântica de exceção de ponto flutuante](#enabling-floating-point-exception-semantics) e [o Pragma float_control](#the-float-control-pragma).

## <a name="the-fenvaccess-pragma"></a>O pragma fenv_access

Uso:

```cpp
#pragma fenv_access( [ on  | off ] )
```

O [fenv_access](../../preprocessor/fenv-access.md) pragma permite que o compilador tornar certas otimizações que talvez possa subverter FPU sinalizador testes e alterações de modo FPU. Quando o estado do `fenv_access` estiver desabilitado, o compilador pode assumir os modos FPU padrão estão em vigor e que não foram testados sinalizadores FPU. Por padrão, o acesso ao ambiente está desabilitado para o fp: modo preciso, embora ele pode ser explicitamente habilitado usando este pragma. Em fp: strict, `fenv_access` está sempre habilitado e não pode ser desabilitado. Sob /FP: Fast, `fenv_access` sempre está desabilitado e não pode ser habilitado.

Conforme descrito em fp: seção precisa, alguns programadores podem alterar a direção de arredondamento de ponto flutuante usando o `_controlfp` função. Por exemplo, para calcular os limites superior e inferior de erro em operações aritméticas, alguns programas de executam a computação mesmo duas vezes, primeiro ao arredondamento em direção infinito negativo, em seguida, ao arredondamento até o infinito positivo. Como o FPU fornece uma maneira conveniente para controlar o arredondamento, um programador pode optar por alterar o modo de arredondamento alterando o ambiente de FPU. O código a seguir calcula o que erro exato associado de uma multiplicação de ponto flutuante alterando o ambiente de FPU.

```cpp
double a, b, cLower, cUpper;
// . . .
_controlfp( _RC_DOWN, _MCW_RC );    // round to -infinity
cLower = a*b;
_controlfp( _RC_UP, _MCW_RC );       // round to +infinity
cUpper = a*b;
_controlfp( _RC_NEAR, _MCW_RC );    // restore rounding mode
```

Quando desabilitado, o `fenv_access` pragma permite ao compilador para assumir o ambiente de FPU padrão; assim, o otimizador está livre para ignorar as chamadas para `_controlfp` e reduzir as atribuições acima para `cUpper = cLower = a*b`. Quando habilitada, entretanto, `fenv_access` impede que tais otimizações.

Programas também podem verificar a palavra de status FPU para detectar alguns erros de ponto flutuantes. Por exemplo, o código a seguir verifica as condições de divisão por zero e inexatas

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

Quando `fenv_access` é desabilitado, o compilador pode reorganizar a ordem de execução, as expressões de ponto flutuante, assim, possivelmente Subvertendo as verificações de status FPU. Habilitando `fenv_access` impede que tais otimizações.

## <a name="the-fpcontract-pragma"></a>O fp_contract (pragma)

Uso:

```cpp
#pragma fp_contract( [ on | off ] )
```

Conforme descrito em fp: seção precisa, contração é um recurso de arquitetura fundamental para muitas unidades de ponto flutuantes modernos. Contrações fornecem a capacidade de executar uma multiplicação seguida por uma adição como uma única operação sem erros de arredondamento intermediário. Essas instruções único são mais rápido do que executar separado multiplicar e adicionar instruções e são mais precisas porque não há nenhum arredondamento intermediário do produto. Uma operação contratada pode calcula o valor de `(a*b+c)` como se as duas operações foram computadas para precisão infinito e, em seguida, arredondadas para o mais próximo do número de ponto flutuante. Essa otimização significativamente pode acelerar a funções que contém várias intercaladas multiplicar e adicionar operações. Por exemplo, considere o seguinte algoritmo que calcula o produto de ponto de dois vetores de n-dimensional.

```cpp
float dotProduct( float x[], float y[], int n )
{
   float p=0.0;
   for (int i=0; i<n; i++)
      p += x[i]*y[i];
   return p;
}
```

Esse cálculo pode ser executado multiplicar-adicionar instruções do formulário de uma série de `p = p + x[i]*y[i]`.

O [fp_contract](../../preprocessor/fp-contract.md) pragma Especifica se as expressões de ponto flutuantes podem ser reduzidas. Por padrão, o fp: modo preciso permite contrações como melhorar a precisão e a velocidade. Contrações estão sempre habilitadas para o modo /FP: Fast. No entanto, pois contrações podem eliminar a detecção explícita de condições de erro, o `fp_contract` pragma sempre fica desabilitada em fp: modo estrito. Exemplos de expressões que podem ser reduzida quando o `fp_contract` pragma está habilitado:

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

O **/fp: preciso**, **Fast**, **/fp: strict** e **/fp: exceto** comutadores semântica de ponto flutuante em um arquivo por arquivo de controle base. O [float_control](../../preprocessor/float-control.md) pragma fornece esse controle em uma base de função pela função.

Uso:

```cpp
#pragma float_control(push)
#pragma float_control(pop)
#pragma float_control( precise, on | off [, push] )
#pragma float_control( except, on | off [, push] )
```

Os pragmas `float_control(push)` e `float_control(pop)` respectivamente push e pop o estado atual do modo de ponto flutuante e a opção para uma pilha de exceção. Observe que o estado do `fenv_access` e `fp_contract` pragma não são afetados por `pragma float_control(push/pop)`.

Chamar o pragma `float_control(precise, on)` habilitará e `float_control(precise, off)` desabilitará a semântica de modo preciso. Da mesma forma, o pragma `float_control(except, on)` habilitará e `float_control(except, off)` desabilitará a semântica de exceção. Semântica de exceção só pode ser habilitada quando a semântica precisa também será habilitada. Quando opcional `push` argumento estiver presente, os estados do `float_control` opções são enviados por push antes da alteração semântica.

### <a name="setting-the-floating-point-semantic-mode-on-a-function-by-function-basis"></a>Configurar o modo de semântico de ponto flutuante por função por função

As opções de linha de comando são na verdade abreviação para definir os quatro pragmas de ponto flutuantes diferentes. Para escolher explicitamente um determinado modo semântico ponto flutuante em cada função pela função, selecione cada uma os quatro pragmas de ponto flutuante opção conforme descrito na tabela a seguir:

||||||
|-|-|-|-|-|
||float_control(precise)|float_control(EXCEPT)|fp_contract|fenv_access|
|/FP: strict|em|em|Desativar|em|
|/FP: strict /fp: exceto-|em|Desativar|Desativar|em|
|/FP: preciso|em|Desativar|em|Desativar|
|/FP: preciso /fp: exceto|em|em|em|Desativar|
|Fast|Desativar|Desativar|em|Desativar|

Por exemplo, a seguir habilita explicitamente /FP: Fast semântica.

```cpp
#pragma float_control( except, off )   // disable exception semantics
#pragma float_control( precise, off )  // disable precise semantics
#pragma fp_contract(on)                // enable contractions
#pragma fenv_access(off)               // disable fpu environment sensitivity
```

> [!Note]
> Semântica de exceção deve ser desligada antes de desligar a semântica de "precisa".

## <a name="enabling-floating-point-exception-semantics"></a>Habilitando a semântica de exceção de ponto flutuante

Determinadas condições excepcionais de ponto flutuantes, como divisão por zero, podem causar FPU sinalizar uma exceção de hardware. Exceções de ponto flutuante são desabilitadas por padrão. Exceções de ponto flutuante são habilitadas, modificando a palavra de controle FPU com o `_controlfp` função. Por exemplo, o código a seguir habilita a exceção de ponto flutuante de divisão por zero:

```cpp
_clearfp(); // always call _clearfp before
            // enabling/unmasking a FPU exception
_controlfp( _EM_ZERODIVIDE, _MCW_EM );
```

Quando a exceção de divisão por zero está habilitada, qualquer operação de divisão com um denominador igual a zero fará com que uma exceção de FPU ser sinalizado.

Para restaurar a palavra de controle FPU para o modo padrão, chame `_controlfp(_CW_DEFAULT, ~0)`.

Habilitando a semântica de exceção de ponto flutuante com o **/fp: exceto** sinalizador não é igual a habilitar exceções de ponto flutuante. Quando a semântica de exceção de ponto flutuante está habilitada, o compilador deve considerar a possibilidade de que qualquer operação de ponto flutuante pode lançar uma exceção. Como o FPU é uma unidade de processamento diferentes, as instruções em execução de FPU podem ser realizadas simultaneamente com instruções sobre outras unidades.

Quando uma exceção de ponto flutuante está habilitada, o FPU será interromper a execução da instrução incorreta e, em seguida, sinalizar uma condição excepcional definindo a palavra de status FPU. Quando a CPU atinge a próxima instrução de ponto flutuante, ela verifica primeiro quaisquer exceções de FPU pendentes. Se houver uma exceção pendente, o processador intercepta chamando um manipulador de exceção fornecido pelo sistema operacional. Isso significa que, quando uma operação de ponto flutuante encontra uma condição excepcional, a exceção correspondente não será detectada até que a próxima operação de ponto flutuante é executada. Por exemplo, o código a seguir intercepta uma exceção de divisão por zero:

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

Se uma condição de divisão por zero ocorre na expressão de um = b/c, o FPU não interceptação/acionar a exceção até a próxima operação de ponto flutuante na expressão 2.0 * b. Isso resulta na seguinte saída:

```Output
This line shouldn't be reached when c==0.0
SEH Exception Detected
```

A função printf correspondente para a primeira linha da saída deve não foi atingido; ele foi alcançado porque a exceção de ponto flutuante causada por expressão b/c não foi gerada até que a execução atingido 2.0 * b. Para aumentar a exceção somente após a execução de b/c, o compilador deve apresentar uma instrução "espera":

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

Esta instrução "espera" força o processador para sincronizar com o estado de FPU e lidar com todas as exceções pendentes. O compilador gerará somente essas "espera" instruções quando semântica de ponto flutuante está habilitada. Quando essa semântica está desabilitada, pois há por padrão, programas poderão encontrar erros de sincronia, semelhantes ao anterior, ao usar exceções de ponto flutuante.

Quando a semântica de ponto flutuante está habilitada, o compilador não apresentará somente instruções "espera", também evita o compilador de ilegalmente otimizando o código de ponto flutuante na presença de exceções possíveis. Isso inclui todas as transformações que alterar os pontos em que as exceções são geradas. Devido a esses fatores, permitindo que a semântica de ponto flutuante pode reduzir consideravelmente a eficiência do código gerado de máquina, portanto, afetar o desempenho de um aplicativo.

Semântica de exceção de ponto flutuante é habilitada por padrão em fp: modo estrito. Para habilitar essa semântica em fp: modo preciso, adicione o **/fp: exceto** alternar para o compilador de linha de comando. Semântica de exceção de ponto flutuante também pode ser habilitada e desabilitada em uma base por função de função usando o `float_control` pragma.

### <a name="floating-point-exceptions-as-c-exceptions"></a>Exceções de ponto flutuante como exceções C++

Como com todas as exceções de hardware, exceções de ponto flutuante intrinsecamente não causam uma exceção de C++, mas em vez disso, disparam uma exceção estruturada. Para mapear exceções estruturadas de ponto flutuantes para exceções do C++, os usuários podem introduzir um conversor de exceção SEH personalizado. Primeiro, apresente uma exceção de C++ correspondente a cada exceção de ponto flutuante:

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

Em seguida, apresente uma função de conversão que detecta uma exceção de ponto flutuante SEH e lançar a exceção de C++ correspondente. Para usar essa função, defina o tradutor de manipulador de exceção estruturado para o thread do processo atual com o [set_se_translator](../../c-runtime-library/reference/set-se-translator.md) função da biblioteca de tempo de execução.

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

Depois que esse mapeamento é inicializado, exceções de ponto flutuante se comportarão como se estivessem exceções do C++. Por exemplo:

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

[O que cada computador cientista deve saber sobre aritmética de ponto flutuante](http://pages.cs.wisc.edu/~david/courses/cs552/S12/handouts/goldberg-floating-point.pdf) por David Camargo.

## <a name="see-also"></a>Consulte também

[Otimizando seu código](optimizing-your-code.md)<br/>
