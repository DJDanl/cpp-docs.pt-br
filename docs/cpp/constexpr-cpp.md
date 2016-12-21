---
title: "constexpr (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "constexpr"
  - "constexpr_cpp"
dev_langs: 
  - "C++"
ms.assetid: c6458ccb-51c6-4a16-aa61-f69e6f4e04f7
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# constexpr (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave `constexpr` foi introduzido no C\+\+ 11 e aprimorado no C\+\+ 14.  Isso significa *expressão constante*.  Como `const`, ele pode ser aplicado às variáveis para que um erro do compilador será gerado se nenhum código tenta modificar o valor.  Ao contrário de `const`, `constexpr` também podem ser aplicadas às funções e construtores de classe.  `constexpr` indica que o valor ou valor de retorno é constante e, se possível, será calculado em tempo de compilação.  Um `constexpr` valor integral pode ser usado sempre que um integer const é exigido, como argumentos de modelo e declarações de matriz.  E, quando um valor pode ser calculado em tempo de compilação, em vez de tempo de execução, ele pode ajudar o seu programa pode executar mais rapidamente e usar menos memória.  
  
## Sintaxe  
  
```vb  
  
constexpr  literal-type  identifier = constant-expression;  
constexpr  literal-type  identifier { constant-expression };  
constexpr literal-type identifier(params );  
constexpr ctor (params);  
```  
  
#### Parâmetros  
 `params`  
 Um ou mais parâmetros que devem ser um tipo literal \(conforme listado abaixo\) e devem\-se ser uma expressão constante.  
  
## Valor de retorno  
 Uma variável de constexpr ou a função deve retornar um dos tipos de literal, como listado abaixo.  
  
## Tipos literais  
 Para limitar a complexidade da compilação de computação constantes de tempo e seus possíveis impactos de tempo de compilação, C \+ \+ 14 padrão requer que os tipos envolvidos em expressões constantes seja restrito a tipos de literal.  Um tipo de literal é aquele cujo layout pode ser determinado em tempo de compilação.  A seguir estão os tipos literais:  
  
1.  void  
  
2.  tipos escalares  
  
3.  Referências  
  
4.  Matrizes de void, escalar tipos ou faz referência  
  
5.  Uma classe que tenha um destruidor trivial e um ou mais construtores constexpr que não são mover ou copiar construtores.  Além disso, todos os seus membros de dados não estáticos e classes base devem ser tipos literais e não volátil.  
  
## variáveis de constexpr  
 A principal diferença entre const e variáveis de constexpr é que a inicialização de uma variável const pode ser adiada até o tempo de execução, enquanto que uma variável constexpr deve ser inicializada em tempo de compilação.  Todas as variáveis de constexpr são const.  
  
```  
constexpr float x = 42.0;  
constexpr float y{108};  
constexpr float z = exp(5, 3);  
constexpr int i; // Error! Not initialized  
int j = 0;  
constexpr int k = j + 1; //Error! j not a constant expression  
```  
  
## funções de constexpr  
 Um `constexpr` função é um cujo valor de retorno pode ser computado em compilação ao código de consumo exige.  Um `constexpr` função deve aceitar e retornar apenas os tipos de literal.  Quando os argumentos são `constexpr` valores e código de consumo requer que o valor de retorno em tempo de compilação, por exemplo, para inicializar um `constexpr` variável ou fornecer um argumento de modelo sem tipo, ele produz uma constante de tempo de compilação.  Quando chamado com não \-`constexpr` argumentos, ou quando seu valor não é necessário em tempo de compilação, ele produz um valor em tempo de execução como uma função regular.  \(Esse comportamento dual poupa de ter que escrever `constexpr` e não\-`constexpr` versões da mesma função.\)  
  
```  
constexpr float exp(float x, int n)  
{  
    return n == 0 ? 1 :  
        n % 2 == 0 ? exp(x * x, n / 2) :  
        exp(x * x, (n - 1) / 2) * x;  
};  
```  
  
> [!TIP]
>  Observação: No depurador do Visual Studio, você pode informar se um `constexpr` função está sendo avaliada em tempo de compilação, colocando um ponto de interrupção dentro dele.  Se o ponto de interrupção for atingido, a função foi chamada em tempo de execução.  Caso contrário, a função foi chamada em tempo de compilação.  
  
## Regras de constexpr geral  
 Para função, variável, construtor ou membro de dados estáticos sejam definidos como `constexpr`, ele deve atender a determinados requisitos:  
  
-   Um `constexpr` função pode ser recursivas.  Ele não pode ser [virtual](../cpp/virtual-cpp.md), e seu tipo de retorno e os tipos de parâmetro devem todos tipos de literal.  O corpo pode ser definido como `= default` ou `= delete`.  Caso contrário, ele deve seguir estas regras: ele não contém nenhuma `goto` instruções, tente blocos, variáveis não inicializadas ou definições de variáveis que não são tipos de literal ou que são estáticas ou locais de thread.  Além disso, um construtor não pode ser definido como constexpr da classe delimitadora tem quaisquer classes base virtuais.  
  
-   Uma variável pode ser declarada com `constexpr`, se ele tem um tipo literal e é inicializado.  Se a inicialização é executada por um construtor, o construtor deve ser declarado como `constexpr`.  
  
-   Uma referência pode ser declarada como constexpr se o objeto que ele faz referência foi inicializado por uma expressão constante e as conversões implícitas são chamadas durante a inicialização também são expressões constantes.  
  
-   Todas as declarações de um `constexpr` variável ou função deve ter o `constexpr` especificador.  
  
-   Uma especialização explícita de um modelo de constexpr não pode ser declarada como `constexpr`:  
  
-   Uma especialização explícita de um `constexpr` modelo não tem que ser também `constexpr`:  
  
-   Um `constexpr` função ou um construtor é implicitamente `inline`.  
  
## Exemplo  
 A exemplo a seguir mostra `constexpr` variáveis, funções e um tipo definido pelo usuário.  Observe que na última instrução no Main \(\), o `constexpr` a função de membro GetValue \(\) é uma chamada de tempo de execução porque o valor não é necessário para ser conhecido em tempo de compilação.  
  
```  
#include <iostream>  
  
using namespace std;  
  
// Pass by value   
constexpr float exp(float x, int n)  
{  
    return n == 0 ? 1 :  
        n % 2 == 0 ? exp(x * x, n / 2) :  
        exp(x * x, (n - 1) / 2) * x;  
};  
  
// Pass by reference  
constexpr float exp2(const float& x, const int& n)  
{  
    return n == 0 ? 1 :  
        n % 2 == 0 ? exp2(x * x, n / 2) :  
        exp2(x * x, (n - 1) / 2) * x;  
};  
  
// Compile time computation of array length  
template<typename T, int N>  
constexpr int length(const T(&ary)[N])   
{   
    return N;   
}   
  
// Recursive constexpr function  
constexpr int fac(int n)  
{   
    return n == 1 ? 1 : n*fac(n - 1);   
}  
  
// User-defined type  
class Foo  
{  
public:  
    constexpr explicit Foo(int i) : _i(i) {}  
    constexpr int GetValue()  
    {  
        return _i;  
    }  
private:  
    int _i;  
};  
  
int main()  
{  
    //foo is const:  
    constexpr Foo foo(5);   
    // foo = Foo(6); //Error!  
  
    //Compile time:  
    constexpr float x = exp(5, 3);   
    constexpr float y { exp(2, 5) };  
    constexpr int val = foo.GetValue();   
    constexpr int f5 = fac(5);  
    const int nums[] { 1, 2, 3, 4 };  
    const int nums2[length(nums) * 2] { 1, 2, 3, 4, 5, 6, 7, 8 };  
  
    //Run time:   
    cout << "The value of foo is " << foo.GetValue() << endl;   
  
}  
  
```  
  
## Requisitos  
 Visual Studio 2015  
  
## Consulte também  
 [Declarações e definições](../cpp/declarations-and-definitions-cpp.md)   
 [const](../cpp/constexpr-cpp.md)