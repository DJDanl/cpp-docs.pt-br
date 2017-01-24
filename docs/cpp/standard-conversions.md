---
title: "Convers&#245;es padr&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conversões, padrão"
  - "valores L"
  - "conversões padrão, categorias de"
ms.assetid: ce7ac8d3-5c99-4674-8229-0672de05528d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A linguagem C\+\+ define conversões entre seus tipos fundamentais. Ele também define conversões de ponteiro, referência e tipos derivados de ponteiro para membro. Essas conversões são chamadas "conversões padrão". \(Para obter mais informações sobre tipos derivados de tipos e tipos padrão, consulte [tipos](http://msdn.microsoft.com/pt-br/6882ee83-ea32-4373-8d57-c3efbbc15af0).\)  
  
 Esta seção aborda as seguintes conversões padrão:  
  
-   Promoções integrais  
  
-   Conversões integrais  
  
-   Conversões flutuantes  
  
-   Conversões flutuantes e integrais  
  
-   Conversões aritméticas  
  
-   Conversões de ponteiro  
  
-   Conversões de referência  
  
-   Conversões de ponteiro para membro  
  
    > [!NOTE]
    >  Tipos definidos pelo usuário podem especificar suas próprias conversões. Conversão de tipos definidos pelo usuário é abordado em [construtores](../cpp/constructors-cpp.md) e [conversões](../cpp/user-defined-type-conversions-cpp.md).  
  
 O código a seguir causa conversões \(neste exemplo, promoções de integral\):  
  
```  
long  long_num1, long_num2;  
int   int_num;  
  
// int_num promoted to type long prior to assignment.  
long_num1 = int_num;  
  
// int_num promoted to type long prior to multiplication.  
long_num2 = int_num * long_num2;  
```  
  
 O resultado de uma conversão é um l\-value somente se ele produz um tipo de referência. Por exemplo, uma conversão definida pelo usuário é declarado como `operator int&()` retorna uma referência e é um l\-value. No entanto, uma conversão declarada como `operator int()`retorna um objeto e não é um l\-value.  
  
## Promoções integrais  
 Objetos de um tipo integral podem ser convertidos em outro tipo integral mais amplo \(isto é, um tipo que pode representar um conjunto maior de valores\). Esse tipo amplo de conversão é chamado de "promoção integral". Com a promoção integral, você pode usar o seguinte em uma expressão sempre que outro tipo integral pode ser usado:  
  
-   Objetos, literais e constantes do tipo `char` e `short int`  
  
-   Tipos de enumeração  
  
-   `int` campos de bits  
  
-   Enumeradores  
  
 As promoções C\+\+ são "preservadoras." Ou seja, o valor após a promoção é garantido para ser o mesmo que o valor antes da promoção. Em promoções de preservação, objetos de tipos integrais mais curtos \(como campos de bits ou objetos do tipo `char`\) são promovidos para digitar `int` se `int` pode representar o intervalo completo do tipo original. Se `int` não pode representar o intervalo completo de valores, em seguida, o objeto seja promovido para o tipo `unsigned int`. Embora essa estratégia é a mesma usada por ANSI C, conversões de preservação de valor não preservam o "signedness" do objeto.  
  
 Preservação e promoções que preservam o signedness normalmente produzem os mesmos resultados. No entanto, eles podem produzir resultados diferentes se o objeto promovido for um dos seguintes:  
  
-   An operand of **\/**, `%`, `/=`, `%=`, **\<**, **\<\=**, **\>**, or **\>\=**  
  
     Esses operadores dependem do sinal para determinar o resultado. Portanto, promoções de preservação e preservando a entrada produzem resultados diferentes quando aplicadas a esses operandos.  
  
-   O operando esquerdo do **\>\>** ou **\>\> \=**  
  
     Esses operadores tratam quantidades assinadas e não assinadas diferente ao executar uma operação de deslocamento. Para quantidades assinadas, a mudança de uma quantidade para a direita faz com que o bit de sinal seja propagado para as posições de bits vagas. Para quantidades não assinadas, as posições de bits vagas são preenchidas com zeros.  
  
-   Um argumento para uma função sobrecarregada ou operando de um operador sobrecarregado que depende de signedness do tipo de operando para correspondência de argumento. \(Consulte [operadores sobrecarregados](../cpp/operator-overloading.md) para obter mais informações sobre como definir operadores sobrecarregados.\)  
  
## Conversões integrais  
 Conversões integrais são executadas entre tipos integrais. Os tipos integrais são `char`, `int`, e **longo** \(e o **curto**, **assinado**, e `unsigned` versões desses tipos\).  
  
 **Assinado em não assinado**  
  
 Objetos de tipos integrais assinados podem ser convertidos para tipos não assinados correspondentes. Quando essas conversões ocorrem, o padrão de bits real não é alterado; No entanto, altera a interpretação dos dados. Considere este código:  
  
```  
  
#include <iostream>  
  
using namespace std;  
int main()  
{  
    short  i = -3;  
    unsigned short u;  
  
    cout << (u = i) << "\n";  
}  
// Output: 65533  
  
```  
  
 No exemplo anterior, um `signed short`, `i`, é definido e inicializado como um número negativo. A expressão `(u = i)` faz com que `i` a ser convertido em um **curto sem sinal** antes de atribuição para `u`.  
  
 **Não assinado em assinado**  
  
 Objetos de tipos integrais não assinados podem ser convertidos para tipos com sinal correspondentes. No entanto, essa conversão pode causar má interpretação dos dados se o valor do objeto sem sinal estiver fora do intervalo representável pelo tipo com sinal, como demonstrado no exemplo a seguir:  
  
```  
  
#include <iostream>  
  
using namespace std;  
int main()  
{  
 short  i;  
 unsigned short u = 65533;  
  
 cout << (i = u) << "\n";  
}  
//Output: -3  
```  
  
 No exemplo anterior, `u` é um `unsigned` **curto** objeto integral que deve ser convertido em uma quantidade com sinal para avaliar a expressão `(i = u)`.  Porque seu valor não pode ser representado adequadamente em um `signed short`, os dados são interpretados incorretamente, conforme mostrado.  
  
## Conversões de ponto flutuante  
 Um objeto de um tipo flutuante pode ser convertido em um tipo flutuante mais preciso com segurança — ou seja, a conversão resulta em nenhuma perda de significância. Por exemplo, conversões de **float** para **duplo** ou **duplo** para `long double` são seguras e o valor é alterada.  
  
 Um objeto de um tipo flutuante também pode ser convertido em um tipo menos preciso, se ele estiver em um intervalo representável pelo tipo. \(Consulte [limites flutuantes](../cpp/floating-limits.md) para os intervalos de tipos flutuantes.\) Se o valor original não pode ser representado com precisão, ele pode ser convertido em um próximo superior ou o próximo valor representável inferior. Se tal valor não existir, o resultado será indefinido. Considere o exemplo a seguir:  
  
```  
cout << (float)1E300 << endl;  
```  
  
 O valor máximo representável pelo tipo **float** é 3.402823466E38 — um número muito menor do que 1E300. Portanto, o número é convertido em infinito, e o resultado será 1. \#INF.  
  
## Conversões entre tipos de ponto flutuante e integral  
 Algumas expressões podem causar objetos de tipo a ser convertido em tipos integrais, ou vice\-versa flutuante. Quando um objeto do tipo integral é convertido em um tipo flutuante e o valor original não pode ser representado exatamente, o resultado é o próximo maior ou o próximo valor representável inferior.  
  
 Quando um objeto de tipo flutuante é convertido em um tipo integral, a parte fracionária é truncada. Nenhum arredondamento ocorre no processo de conversão. Truncamento significa que um número como 1,3 é convertido em 1 e – 1,3 é convertido em – 1.  
  
## Conversões aritméticas  
 Muitos operadores binários \(discutidos [expressões com operadores binários](../cpp/expressions-with-binary-operators.md)\) provocam conversões de operandos e produzem resultados da mesma maneira. A maneira como esses operadores provocam conversões é chamado "conversões aritméticas usuais." Conversões aritméticas de operandos de tipos nativos diferentes são executadas conforme mostrado na tabela a seguir. Os tipos TypeDef se comportam de acordo com seus tipos nativos subjacentes.  
  
### Condições para a conversão de tipo  
  
|Condições atendidas|Conversão|  
|-------------------------|---------------|  
|Ambos os operandos é do tipo **longo duplo**.|Outro operando é convertido para o tipo **longo duplo**.|  
|Precede a condição não atendida e qualquer um dos operandos é do tipo **duplo**.|Outro operando é convertido para o tipo **duplo**.|  
|Anterior condições não atendidas e qualquer um dos operandos é do tipo **float**.|Outro operando é convertido para o tipo **float**.|  
|Precede condições não atendidas \(nenhum dos operandos é de tipo flutuante\).|Promoções integrais são executadas nos operandos como segue:<br /><br /> -   Se ambos os operandos é do tipo `unsigned` **longo**, o outro operando é convertido para o tipo `unsigned long`.<br />-   Se a condição anterior não atendidos e se ambos os operandos é do tipo **longo** e outro do tipo `unsigned` `int`, ambos os operandos são convertidos para o tipo `unsigned long`.<br />-   Se as duas condições anteriores não forem atendidas e se ambos os operandos é do tipo **longo**, o outro operando é convertido para o tipo **longo**.<br />-   Se as três condições anteriores não forem atendidas e se ambos os operandos é do tipo `unsigned int`, o outro operando é convertido para o tipo `unsigned int`.<br />-   Se nenhuma das condições anteriores forem atendidas, ambos os operandos são convertidos para o tipo `int`.|  
  
 O código a seguir ilustra as regras de conversão descritas na tabela:  
  
```  
  
double dVal;  
float fVal;  
int iVal;  
unsigned long ulVal;  
  
int main() {  
   // iVal converted to unsigned long  
   // result of multiplication converted to double  
   dVal = iVal * ulVal;  
  
   // ulVal converted to float  
   // result of addition converted to double  
   dVal = ulVal + fVal;  
}  
```  
  
 A primeira instrução no exemplo anterior mostra a multiplicação de dois tipos integrais, `iVal` e `ulVal`. A condição atendida é que nenhum dos operandos é do tipo flutuante e um operando for do tipo `unsigned int`. Portanto, o outro operando, `iVal`, é convertido para o tipo `unsigned int`. O resultado é atribuído a `dVal`. A condição atendida é que um operando é do tipo **duplo**; portanto, o `unsigned int` o resultado da multiplicação é convertido para o tipo **duplo**.  
  
 A segunda instrução no exemplo anterior mostra a adição de um **float** e um tipo integral, `fVal` e `ulVal`. O `ulVal` variável é convertida para o tipo **float** \(terceira condição na tabela\). O resultado da adição é convertido para o tipo **duplo** \(segunda condição na tabela\) e atribuído a `dVal`.  
  
## Conversões de ponteiro  
 Os ponteiros podem ser convertidos durante a inicialização, atribuição, comparação e outras expressões.  
  
### Ponteiro para classes  
 Há dois casos em que um ponteiro para uma classe pode ser convertido em um ponteiro para uma classe base.  
  
 O primeiro caso é quando a classe base especificada é acessível e a conversão for inequívoca. \(Consulte [várias Classes Base](../cpp/multiple-base-classes.md) para obter mais informações sobre referências de classe base ambíguas.\)  
  
 Se uma classe base é acessível depende do tipo de herança usado na derivação. Considere a herança ilustrada na figura a seguir.  
  
 ![Acessibilidade de classe Base do gráfico de herança](../cpp/media/vc38xa1.png "vc38XA1")  
Gráfico de herança para ilustração de acessibilidade de classe Base  
  
 A tabela a seguir mostra a acessibilidade de classe base para a situação ilustrada na figura.  
  
### Acessibilidade de classe base  
  
|Tipo de função|Derivação|Conversão de<br /><br /> B \* para Legal de um?|  
|--------------------|---------------|---------------------------------------------|  
|Função externa \(não do escopo da classe\)|Particular|Não|  
||Protegido|Não|  
||Público|Sim|  
|Função de membro B \(no escopo de B\)|Particular|Sim|  
||Protegido|Sim|  
||Público|Sim|  
|Função de membro C \(no escopo de C\)|Particular|Não|  
||Protegido|Sim|  
||Público|Sim|  
  
 O segundo caso em que um ponteiro para uma classe pode ser convertido em um ponteiro para uma classe base é quando você usa uma conversão implícita de tipo. \(Consulte [expressões com conversões de tipo explícitas](http://msdn.microsoft.com/pt-br/060ad6b4-9592-4f3e-8509-a20ac84a85ae) para obter mais informações sobre conversões de tipo explícitas.\)  
  
 O resultado dessa conversão é um ponteiro para o "subobjeto", a parte do objeto que é totalmente descrita pela classe base.  
  
 O código a seguir define duas classes, `A` e `B`, onde `B` é derivado de `A`. \(Para obter mais informações sobre herança, consulte [Classes derivadas de](../cpp/inheritance-cpp.md).\) Ele define `bObject`, um objeto do tipo `B`, e dois ponteiros \(`pA` e `pB`\) que apontam para o objeto.  
  
```  
// C2039 expected  
class A  
{  
public:  
    int AComponent;  
    int AMemberFunc();  
};  
  
class B : public A  
{  
public:  
    int BComponent;  
    int BMemberFunc();  
};  
int main()  
{  
   B bObject;  
   A *pA = &bObject;  
   B *pB = &bObject;  
  
   pA->AMemberFunc();   // OK in class A  
   pB->AMemberFunc();   // OK: inherited from class A  
   pA->BMemberFunc();   // Error: not in class A  
}  
```  
  
 O ponteiro `pA` é do tipo `A *`, que pode ser interpretado como "ponteiro para um objeto do tipo `A`." Membros da `bObject` `(`como `BComponent` e `BMemberFunc`\) são exclusivos ao tipo `B` e, portanto, podem ser acessadas por meio de `pA`.  O `pA` ponteiro permite o acesso apenas a essas características \(funções de membro e dados\) do objeto que são definidas na classe `A`.  
  
### Ponteiro para função  
 Um ponteiro para uma função pode ser convertido no tipo **void \***, se tipo **void \*** é grande o suficiente para reter esse ponteiro.  
  
### Ponteiro para void  
 Ponteiros para o tipo `void` podem ser convertidos em ponteiros para qualquer outro tipo, mas apenas com uma conversão de tipo explícito \(ao contrário do C\). \(Consulte [expressões com conversões de tipo explícitas](http://msdn.microsoft.com/pt-br/060ad6b4-9592-4f3e-8509-a20ac84a85ae) para obter mais informações sobre conversões de tipo.\) Um ponteiro para qualquer tipo pode ser convertido implicitamente em um ponteiro para o tipo `void`. Um ponteiro para um objeto incompleto de um tipo pode ser convertido em um ponteiro para `void` \(implicitamente\) e vice\-versa \(explicitamente\). O resultado dessa conversão é igual ao valor do ponteiro original. Um objeto é considerado incompleto se ela é declarada, mas não há informações suficientes disponíveis para determinar seu tamanho ou a classe base.  
  
 Um ponteiro para qualquer objeto que não esteja **const** ou `volatile` pode ser convertido implicitamente em um ponteiro de tipo **void \***.  
  
### ponteiros const e volatile  
 C\+\+ não fornece uma conversão padrão de um **const** ou `volatile` tipo para um tipo que não seja **const** ou `volatile`. No entanto, qualquer tipo de conversão pode ser especificado usando as conversões de tipo explícito \(inclusive as conversões que não são seguras\).  
  
> [!NOTE]
>  Os ponteiros C\+\+ para membros, exceto ponteiros para membros estáticos, são diferentes dos ponteiros normais e não têm as mesmas conversões padrão. Ponteiros para membros estáticos são ponteiros normais e têm as mesmas conversões que ponteiros normais. \(Consulte [\(NOTINBUILD\) tipos derivados diretamente](http://msdn.microsoft.com/pt-br/d2d611d1-dbff-4fb4-9858-e1572544f5c3) para obter mais informações.\)  
  
### conversões de ponteiro nulo  
 Uma expressão de constante integral que é avaliada como zero ou uma expressão convertido em um tipo de ponteiro é convertida para um ponteiro chamado "ponteiro nulo". Esse ponteiro é garantido para comparar diferentes em um ponteiro para qualquer objeto ou função válidos \(exceto os ponteiros para objetos baseados, que podem ter o mesmo deslocamento e ainda apontar para objetos diferentes\).  
  
 No C\+\+ 11 a [nullptr](../Topic/nullptr.md) tipo deve ser preferencial para o ponteiro nulo do estilo C.  
  
### Conversões de expressão de ponteiro  
 Qualquer expressão com um tipo de matriz pode ser convertido em um ponteiro do mesmo tipo. O resultado da conversão é um ponteiro para o primeiro elemento da matriz. O exemplo a seguir demonstra essa conversão:  
  
```  
char szPath[_MAX_PATH]; // Array of type char.  
char *pszPath = szPath; // Equals &szPath[0].  
```  
  
 Uma expressão que resulta em uma função que retorna um tipo específico é convertida em um ponteiro para uma função que retorna um tipo, exceto quando:  
  
-   A expressão é usada como um operando para o operador address\-of \(**&**\).  
  
-   A expressão é usada como um operando para o operador de chamada de função.  
  
## Conversões de referência  
 Uma referência a uma classe pode ser convertida em uma referência a uma classe base nos seguintes casos:  
  
-   A classe base especificada é acessível \(conforme definido em [ponteiros para Classes](../misc/pointers-to-classes.md)\).  
  
-   A conversão for inequívoca. \(Consulte [várias Classes Base](../cpp/multiple-base-classes.md) para obter mais informações sobre referências de classe base ambíguas.\)  
  
 O resultado da conversão é um ponteiro para o subobjeto que representa a classe base.  
  
## Ponteiro para membro  
 Ponteiros para membros de classe podem ser convertidos durante a inicialização, atribuição, comparação e outras expressões. Esta seção descreve as seguintes conversões de ponteiro para membro:  
  
## Ponteiro para membro da classe base  
 Um ponteiro para um membro de uma classe base pode ser convertido em um ponteiro para um membro de uma classe derivada, quando as seguintes condições forem atendidas:  
  
-   A conversão inversa, de ponteiro para classe derivada em ponteiro de classe base, está acessível.  
  
-   A classe derivada não praticamente herdam da classe base.  
  
 Quando o operando esquerdo é um ponteiro para membro, o operando direito deve ser do tipo de ponteiro para membro ou ser uma expressão constante que é avaliada como 0. Essa atribuição é válida somente nos seguintes casos:  
  
-   O operando da direita é um ponteiro para um membro da mesma classe que o operando esquerdo.  
  
-   O operando esquerdo é um ponteiro para um membro de uma classe derivada publicamente e sem ambigüidade da classe do operando à direita.  
  
## Conversões de constantes integrais  
 Uma expressão de constante integral que é avaliada como zero é convertida em um ponteiro chamado "ponteiro nulo". Esse ponteiro é garantido para comparar diferentes em um ponteiro para qualquer objeto ou função válidos \(exceto os ponteiros para objetos baseados, que podem ter o mesmo deslocamento e ainda apontar para objetos diferentes\).  
  
 O código a seguir ilustra a definição de um ponteiro para membro `i` na classe `A`. O ponteiro, `pai`, é inicializada como 0, o que é o ponteiro nulo.  
  
```  
class A  
{  
public:  
 int i;  
};  
  
int A::*pai = 0;  
  
int main()  
{  
}  
```  
  
## Consulte também  
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)