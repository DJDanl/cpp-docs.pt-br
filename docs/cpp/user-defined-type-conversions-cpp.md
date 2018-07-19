---
title: Conversões de tipo (C++) definido pelo usuário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- explicit_cpp
dev_langs:
- C++
helpviewer_keywords:
- constructors [C++], and constants
- conversion functions [C++]
- explicit keyword [C++]
- type conversion
- constructors [C++], drawbacks
- conversion constructors
- type conversion [C++], explicit conversion
- coercion [C++]
- conversions [C++], explicit
- objects [C++], converting
- conversion functions [C++], rules for declaring
- declaring functions [C++], conversion functions
- functions [C++], conversion
- converting objects
- constructors [C++], conversion
- conversions [C++], by constructors
- data type conversion [C++], explicit
ms.assetid: d40e4310-a190-4e95-a34c-22c5c20aa0b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4c41e2cf0765c036715377038357d587a755196f
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942351"
---
# <a name="user-defined-type-conversions-c"></a>Conversões de tipo definido pelo usuário (C++)
Um *conversão* produz um novo valor de algum tipo de um valor de um tipo diferente. *Conversões padrão* são criados sobre a linguagem C++ e o suporte de seus tipos internos e você pode criar *conversões definidas pelo usuário* para realizar conversões para, de ou entre tipos definidos pelo usuário.  
  
 As conversões padrão realizam conversões entre tipos internos, entre ponteiros ou referências para tipos relacionados por herança, para os ponteiros void e nulo. Para obter mais informações, consulte [conversões padrão](../cpp/standard-conversions.md). As conversões definidas pelo usuário realizam conversões entre tipos definidos pelo usuário ou entre tipos definidos pelo usuário e tipos internos. Você pode implementá-los como [construtores de conversão](#ConvCTOR) ou como [funções de conversão](#ConvFunc).  
  
 As conversões podem ser implícitas (quando as chamadas do programador de um tipo a ser convertido para outro, como em uma inicialização direta ou convertida) ou implícita (quando o programa ou a linguagem chama um tipo diferente daquele fornecido pelo programador).  
  
 As conversões implícitas são tentadas quando:  
  
-   Um argumento fornecido para uma função não tem o mesmo tipo do parâmetro correspondente.  
  
-   O valor retornado de uma função não tem o mesmo tipo do tipo de retorno de função.  
  
-   Uma expressão de inicializador não tem o mesmo tipo do objeto que está sendo inicializado.  
  
-   Uma expressão que controla uma instrução condicional, constructos de loop ou opção não tem o tipo de resultado necessário para controlá-la.  
  
-   Um operando fornecido para um operador não tem o mesmo tipo do parâmetro do operando correspondente. Para operadores internos, ambos os operandos devem ter o mesmo tipo e são convertidos para um tipo comum que pode representar ambos. Para obter mais informações, consulte [conversões padrão](standard-conversions.md). Para operadores definidos por usuários, cada operando deve ter o mesmo tipo do parâmetro operando correspondente.  
  
 Quando uma conversão padrão não pode concluir uma conversão implícita, o compilador pode usar uma conversão definida pelo usuário, seguida opcionalmente por uma conversão padrão adicional, para completá-la.  
  
 Quando duas ou mais conversões definidas pelo usuário que executam a mesma conversão estão disponíveis em um site de conversão, a conversão é chamada de ambígua. Essas ambiguidades são um erro porque o compilador não pode determinar qual das conversões disponíveis deve escolher. No entanto, não é errado apenas definir várias maneira de realizar a mesma conversão porque o conjunto de conversões disponíveis pode ser diferente em locais diferentes no código-fonte, por exemplo, dependendo de quais arquivos de cabeçalho estão incluídos no arquivo fonte. Enquanto apenas uma conversão estiver disponível no local da conversão, não há ambiguidade. Conversões ambíguas podem ocorrer de várias maneiras, mas as mais comuns são:  
  
-   Herança múltipla. A conversão é definida em mais de uma classe base. 
  
-   Chamada de função ambígua. A conversão é defina como um construtor de conversão do tipo de destino e como uma função de conversão do tipo de fonte. Para obter mais informações, consulte [funções de conversão](#ConvFunc).  
  
 Geralmente, você pode resolver uma ambiguidade apenas por meio da qualificação do nome do tipo envolvido ou realizando uma conversão explícita para esclarecer sua intenção.  
  
 Ambos, construtores de conversão e funções de conversão obedecem regras de controle de acesso de membro, mas a acessibilidade das conversões é apenas considerada se e quando uma conversão ambígua puder ser determinada. Isso significa que uma conversão pode ser ambígua ainda que o nível de acesso de uma conversão concorrente impeça o seu uso. Para obter mais informações sobre acessibilidade de membro, consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md).  
  
## <a name="the-explicit-keyword-and-problems-with-implicit-conversion"></a>A palavra-chave e problemas explícitos com conversão implícita  
 Por padrão, ao criar uma conversão definida pelo usuário, o compilador pode usá-la para executar conversões implícitas. Algumas vezes pode ser que você queira isso, mas outras vezes as regras simples que guiam o compilador para fazer conversões implícitas pode levá-lo a aceitar códigos que não quer.  
  
 Um exemplo bem conhecido de uma conversão implícita que pode causar problemas é a conversão em **bool**. Há muitas razões que você talvez queira criar um tipo de classe que pode ser usado em um contexto booliano — por exemplo, assim que ele pode ser usada para controlar uma **se** instrução ou loop — mas quando o compilador executa uma conversão definida pelo usuário para um tipo interno, o compilador tem permissão para aplicar posteriormente uma conversão de padrão adicional. A intenção dessa conversão padrão adicional é permitir coisas como promoções de **curto** à **int**, mas ele também abre a porta para conversões menos óbvias — por exemplo, de  **bool** à **int**, que permite que seu tipo de classe a ser usado em contextos de inteiros, você nunca desejou. Esse problema específico é conhecido como o *problema de Bool seguro*. Esse tipo de problema é o local onde o **explícita** pode ajudar a palavra-chave.  
  
 O **explícita** palavra-chave informa ao compilador que a conversão especificada não pode ser usada para executar conversões implícitas. Se você quisesse a conveniência sintática de conversões implícitas antes do **explícita** foi introduzida a palavra-chave, você teria que aceitar as consequências não intencionais que a conversão implícita às vezes, é criada ou usar menos convenientes, funções de conversão nomeada como uma solução alternativa. Agora, usando o **explícita** palavra-chave, você pode criar conversões convenientes que só pode ser usado para executar conversões explícitas ou inicialização direta e que não resultam nos tipos de problemas exemplificados pelo problema de Bool seguro.  
  
 O **explícita** palavra-chave pode ser aplicada para construtores de conversão desde c++98 e funções de conversão desde c++11. As seções a seguir contêm mais informações sobre como usar o **explícita** palavra-chave.  
  
##  <a name="ConvCTOR"></a> Construtores de conversão  
 Os construtores de conversão definem conversões de tipos internos ou definidos pelo usuário para um tipo definido pelo usuário. O exemplo a seguir demonstra um construtor de conversão que converte do tipo interno **duplas** para um tipo definido pelo usuário `Money`.  
  
```cpp 
#include <iostream>  
  
class Money  
{  
public:  
    Money() : amount{ 0.0 } {};  
    Money(double _amount) : amount{ _amount } {};  
  
    double amount;  
};  
  
void display_balance(const Money balance)  
{  
    std::cout << "The balance is: " << balance.amount << std::endl;  
}  
  
int main(int argc, char* argv[])  
{  
    Money payable{ 79.99 };  
  
    display_balance(payable);  
    display_balance(49.95);  
    display_balance(9.99f);  
  
    return 0;  
}  
```  
  
 Observe que a primeira chamada para a função `display_balance`, que leva um argumento do tipo `Money`, não necessita de uma conversão porque seu argumento é do tipo correto. No entanto, na segunda chamada para `display_balance`, uma conversão é necessária porque o tipo do argumento, uma **duplo** com um valor de `49.95`, é não o que a função espera. A função não é possível usar esse valor diretamente, mas porque há uma conversão do tipo do argumento —**duplas**— para o tipo de parâmetro correspondente —`Money`— um valor temporário do tipo `Money` é construído a partir de o argumento e utilizado para completar a chamada de função. Na terceira chamada para `display_balance`, observe que o argumento não é um **duplo**, mas em vez disso, uma **float** com um valor de `9.99`— e ainda a chamada de função pode ainda ser concluída porque o compilador pode executar uma conversão padrão — nesse caso, a partir **float** à **duplo**— e, em seguida, executar a conversão definida pelo usuário do **double** para `Money` para concluir a conversão necessária.  
  
### <a name="declaring-conversion-constructors"></a>Declaração de construtores de conversão  
 As regras a seguir aplicam-se à declaração de um construtor de conversão:  
  
-   O tipo de destino da conversão é o tipo definido pelo usuário que está sendo construído.  
  
-   Geralmente, os construtores de conversão usam exatamente um argumento, que é o do tipo do código-fonte. No entanto, um construtor de conversão pode especificar parâmetros adicionais, caso cada parâmetro adicional tenha um valor padrão. O tipo de código-fonte permanece o tipo do primeiro parâmetro.  
  
-   Os construtores de conversão, como todos os construtores, não especificam um tipo de retorno. Especificar um tipo de retorno na declaração é um erro.  
  
-   Os construtores de conversão podem ser explícitos.  
  
### <a name="explicit-conversion-constructors"></a>Construtores de conversão explícita  
 Ao declarar um construtor de conversão como **explícita**, ele só pode ser usado para executar a inicialização direta de um objeto ou para executar uma conversão explícita. Isso evita que funções que aceitam um argumento do tipo de classe também aceitem argumentos implicitamente do tipo de fonte do construtor de conversão, evitando que o tipo de classe seja inicializado por cópia a partir de um valor do tipo de fonte. O exemplo a seguir demonstra como definir um construtor de conversão explícita e o efeito que tem sobre qual código é bem formado.  
  
```cpp 
#include <iostream>  
  
class Money  
{  
public:  
    Money() : amount{ 0.0 } {};  
    explicit Money(double _amount) : amount{ _amount } {};  
  
    double amount;  
};  
  
void display_balance(const Money balance)  
{  
    std::cout << "The balance is: " << balance.amount << std::endl;  
}  
  
int main(int argc, char* argv[])  
{  
    Money payable{ 79.99 };        // Legal: direct initialization is explicit.  
  
    display_balance(payable);      // Legal: no conversion required  
    display_balance(49.95);        // Error: no suitable conversion exists to convert from double to Money.  
    display_balance((Money)9.99f); // Legal: explicit cast to Money  
  
    return 0;  
}  
```  
  
 Nesse exemplo, observe que você pode ainda usar o construtor de conversão explícita para executar a inicialização direta de `payable`. Se ao invés disso você tivesse que inicializar `Money payable = 79.99;` por cópia, o resultado seria um erro. A primeira chamada para `display_balance` é sem efeito porque o argumento é o tipo correto. A segunda chamada para `display_balance` é um erro, porque o construtor de conversão não pode ser usado para executar conversões implícitas. A terceira chamada para `display_balance` é legal por causa da conversão explícita para `Money`, mas observe que o compilador ainda ajudou a completar a conversão ao inserir uma conversão implícita de **float** para **double**.  
  
 Embora a praticidade de permitir conversões implícitas possa ser tentadora, fazer isso pode introduzir bugs difíceis de encontrar. A regra recomendada é tornar explícitos todos os construtores de conversão, exceto quando você tem certeza que deseja que uma conversão específica ocorra implicitamente.  
  
##  <a name="ConvFunc"></a> Funções de conversão  
 As funções de conversão definem conversões de um tipo definidas pelo usuário para outros tipos. Essas funções são algumas vezes chamadas como operadores cast pois, juntamente com os construtores de conversão, são chamadas quando um valor é convertido para um tipo diferente. O exemplo a seguir demonstra uma função de conversão que converte do tipo definido pelo usuário, `Money`, para um tipo interno, **duplo**:  
  
```cpp 
#include <iostream>  
  
class Money  
{  
public:  
    Money() : amount{ 0.0 } {};  
    Money(double _amount) : amount{ _amount } {};  
  
    operator double() const { return amount; }  
private:  
    double amount;  
};  
  
void display_balance(const Money balance)  
{  
    std::cout << "The balance is: " << balance << std::endl;  
}  
  
```  
  
 Observe que a variável de membro `amount` se torna privada e que a função de tipo de uma conversão pública **duplo** é introduzida apenas para retornar o valor de `amount`. Na função `display_balance`, uma conversão implícita ocorre quando o valor de `balance` é transmitido para saída padrão usando o operador de inserção de fluxo `<<`. Como Nenhum operador de inserção de fluxo é definido para o tipo definido pelo usuário `Money`, mas há um para o tipo interno **duplo**, o compilador pode usar a função de conversão de `Money` para **duplo** para atender o operador de inserção de fluxo.  
  
 As funções de conversão são herdadas por classes derivadas. As funções de conversão em uma classe derivada apenas substitui uma função de conversão herdada quando convertidas exatamente para o mesmo tipo. Por exemplo, uma função de conversão definida pelo usuário da classe derivada **operador int** não substitui — ou influencia — uma função de conversão definida pelo usuário da classe base **operador curto**, até mesmo Embora as conversões padrão definam uma relação de conversão entre **int** e **curto**.  
  
### <a name="declaring-conversion-functions"></a>Declaração de funções de conversão  
 As regras a seguir são aplicadas ao declarar uma função de conversão:  
  
-   O tipo de destino da conversão deve ser declarado antes da declaração da função de conversão. Classes, estruturas, enumerações e typedefs não podem ser declarados na declaração da função de conversão.  
  
    ```cpp 
    operator struct String { char string_storage; }() // illegal  
    ```  
  
-   As funções de conversão não têm argumentos. Especificar quaisquer parâmetros na declaração é um erro.  
  
-   As funções de conversão têm um tipo de retorno que é especificado pelo nome da função de conversão, que é também o nome do tipo de destino da conversão. Especificar um tipo de retorno na declaração é um erro.  
  
-   As funções de conversão podem ser virtuais.  
  
-   As funções de conversão podem ser explícitas.  
  
### <a name="explicit-conversion-functions"></a>Funções de conversão explícitas  
 Quando uma função de conversão é declarada como explícita, ele pode ser usada para executar uma conversão explícita. Isso evita que funções que aceitam um argumento do tipo de destino da função de conversão também aceitem implicitamente argumentos do tipo de classe, além de evitar que o tipo de destino seja inicializado por cópia, a partir de um valor do tipo de classe. O exemplo a seguir demonstra como definir uma função de conversão explícita e o efeito que tem sobre qual código é bem formado.  
  
```cpp 
#include <iostream>  
  
class Money  
{  
public:  
    Money() : amount{ 0.0 } {};  
    Money(double _amount) : amount{ _amount } {};  
  
    explicit operator double() const { return amount; }  
private:  
    double amount;  
};  
  
void display_balance(const Money balance)  
{  
    std::cout << "The balance is: " << (double)balance << std::endl;  
}  
  
```  
  
 Aqui a função de conversão **operador double** foi feita explícita e uma conversão explícita para o tipo **duplo** foi introduzida na função `display_balance` para realizar a conversão. Se essa conversão for omitida, o compilador será incapaz de localizar um operador de inserção de fluxo adequado `<<` de tipo `Money` e poderá ocorrer um erro.  
  
