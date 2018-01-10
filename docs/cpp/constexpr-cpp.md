---
title: constexpr (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: constexpr_cpp
dev_langs: C++
ms.assetid: c6458ccb-51c6-4a16-aa61-f69e6f4e04f7
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cf1094be23074fe71e65a3077de51263f01a81c6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="constexpr-c"></a>constexpr (C++)
A palavra-chave `constexpr` foi introduzido no C++ 11 e aprimorado na 14 C + +. Isso significa que *expressão constante*. Como `const`, ele pode ser aplicado a variáveis de modo que será gerado um erro do compilador se qualquer código tentar modificar o valor. Ao contrário de `const`, `constexpr` também podem ser aplicadas às funções e construtores de classe. `constexpr`indica que o valor ou o valor de retorno é constante e, se possível, será calculado em tempo de compilação.  Um `constexpr` valor integral pode ser usado sempre que um inteiro constante é necessário, como em argumentos de template e declarações de matriz. E quando um valor pode ser calculado em tempo de compilação em vez de tempo de execução, ele pode ajudar seu programa executado mais rapidamente e usar menos memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
constexpr  literal-type  identifier = constant-expression;
constexpr  literal-type  identifier { constant-expression };
constexpr literal-type identifier(params );
constexpr ctor (params);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `params`  
 Um ou mais parâmetros que devem ser um tipo literal (conforme listado abaixo) e devem-se ser uma expressão constante.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma variável constexpr ou função deve retornar um dos tipos de literal, como listado abaixo.  
  
## <a name="literal-types"></a>Tipos literais  
 Para limitar a complexidade da compilação computação constantes de tempo e seus possíveis impactos de tempo de compilação, C + + 14 padrão requer que os tipos envolvidos em expressões de constante seja restrito a tipos de literal. Um tipo literal é uma cujo layout pode ser determinado em tempo de compilação. Esses são os tipos de literal:  
  
1.  void  
  
2.  tipos escalares  
  
3.  referências  
  
4.  Matrizes de void, escalar tipos ou faz referência  
  
5.  Uma classe que tenha um destruidor trivial e um ou mais construtores de constexpr que não são mover ou copiar construtores. Além disso, todas as suas classes base e membros de dados não estáticos devem ser tipos de literal e não volátil.  
  
## <a name="constexpr-variables"></a>variáveis de constexpr  
 A principal diferença entre const e variáveis de constexpr é que a inicialização de uma variável const poderá ser adiada até o tempo de execução, enquanto uma variável constexpr deve ser inicializada em tempo de compilação.  Todas as variáveis de constexpr são constantes.  

-  Uma variável pode ser declarada com `constexpr`, se ele tem um tipo literal e é inicializado. Se a inicialização é executada por um construtor, o construtor deve ser declarado como `constexpr`.  
  
-   Uma referência pode ser declarada como constexpr se o objeto que faz referência foi inicializado por uma expressão constante e quaisquer conversões implícitas que são chamados durante a inicialização também são expressões de constante.  
  
-   Todas as declarações de um `constexpr` variável ou função deve ter o `constexpr` especificador.  
  
 
  
 
  
```cpp  
constexpr float x = 42.0;  
constexpr float y{108};  
constexpr float z = exp(5, 3);  
constexpr int i; // Error! Not initialized  
int j = 0;  
constexpr int k = j + 1; //Error! j not a constant expression  
```  
  
## <a name="constexpr-functions"></a>funções constexpr  
 Um `constexpr` função é uma cujo valor de retorno pode ser computado em compilação quando o código de consumo exija isso.  Quando os argumentos são `constexpr` valores e código requer que o valor de retorno em tempo de compilação, por exemplo, para inicializar um `constexpr` variável ou forneça um argumento de tipo não template, ele produz uma constante de tempo de compilação. Quando chamado com não`constexpr` argumentos, ou quando seu valor não é necessário no tempo de compilação, ele gera um valor de tempo de execução como uma função regular.  (Esse comportamento duplo elimina a necessidade de escrever `constexpr` e não-`constexpr` versões da mesma função.)  
 
 Um `constexpr` construtor ou função é implicitamente `inline`. 
 
 As seguintes regras se aplicam a funções constexpr:

- Um `constexpr` função deve aceitar e retornar apenas os tipos de literal. 

- Um `constexpr` função pode ser recursivo. 

- Ele não pode ser [virtual](../cpp/virtual-cpp.md). A um construtor não pode ser definido como constexpr se a classe delimitador tem todas as classes base virtuais.

- O corpo pode ser definido como `= default` ou `= delete`. 

- O corpo não pode conter `goto` instruções ou blocos try. 

- Uma especialização explícita de um modelo de constexpr não pode ser declarada como `constexpr`:  
  
- Uma especialização explícita de um `constexpr` modelo não tem também `constexpr`: 


<!--conformance note-->
As seguintes regras se aplicam a funções de constexpr no Visual Studio de 2017 e posterior: 

- Pode conter se e alternar instruções e todas as instruções em loop, incluindo, baseada em intervalo, ao mesmo tempo e fazer-enquanto
    
- Ele pode conter declarações de variável local, mas a variável deve ser inicializada, deve ser um tipo literal e não pode ser estático ou o local de thread. A variável local declarada não é necessário para ser const e pode modificar.

- Uma função de membro não estática constexpr não deve ser implicitamente const.

  
```cpp  
constexpr float exp(float x, int n)  
{  
    return n == 0 ? 1 :  
        n % 2 == 0 ? exp(x * x, n / 2) :  
        exp(x * x, (n - 1) / 2) * x;  
};  
```  
  
> [!TIP]
>  Observação: No depurador do Visual Studio, você pode informar se um `constexpr` função está sendo avaliada em tempo de compilação, colocando um ponto de interrupção dentro dele. Se o ponto de interrupção é atingido, a função foi chamada em tempo de execução.  Caso contrário, a função foi chamada em tempo de compilação.  
  
 
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra `constexpr` variáveis, funções e um tipo definido pelo usuário. Observe que na última instrução em Main (), o `constexpr` a função de membro GetValue() é uma chamada de tempo de execução porque o valor não deve ser conhecido em tempo de compilação.  
  
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
  
## <a name="requirements"></a>Requisitos  
 Visual Studio 2015  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e definições](../cpp/declarations-and-definitions-cpp.md)   
 [const](../cpp/const-cpp.md)