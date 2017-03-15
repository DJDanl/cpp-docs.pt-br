---
title: "Enumera&#231;&#245;es (C++) | Microsoft Docs"
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
  - "enum"
  - "enum_cpp"
  - "enum class"
  - "enum struct"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "declarações, enumerações"
  - "declarando enumerações"
  - "palavra-chave enum [C++]"
  - "enumeradores, declarando"
  - "constantes nomeadas, declarações de enumeração"
ms.assetid: 081829db-5dca-411e-a53c-bffef315bcb3
caps.latest.revision: 27
caps.handback.revision: 27
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Enumera&#231;&#245;es (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma enumeração é um tipo definido pelo usuário que consiste em um conjunto de constantes integrais nomeadas que são conhecidas como enumeradores.  
  
> [!NOTE]
>  Este artigo abrange o tipo `enum` da Linguagem C\+\+ Padrão ISO e o tipo `enum class` com escopo \(ou fortemente tipado\) que foi introduzido no C\+\+11.  Para obter informações sobre a `public enum class` ou `private enum class` tipos em C\+\+ c\+\+ \/CLI e c\+\+ \/CX, consulte [enum class](../windows/enum-class-cpp-component-extensions.md).  
  
## Sintaxe  
  
```  
// unscoped enum:  
enum [identifier] [: type]  
  
{enum-list};   
  
// scoped enum:  
enum [class|struct]   
[identifier] [: type]   
{enum-list};  
```  
  
```  
// Forward declaration of enumerations  (C++11):  
enum A : int; // non-scoped enum must have type specified  
enum class B; // scoped enum defaults to int  
enum class C : short;  
```  
  
#### Parâmetros  
 `identifier`  
 O nome do tipo dado à enumeração.  
  
 `type`  
 O tipo subjacente dos enumeradores; todos os enumeradores têm o mesmo tipo subjacente.  Pode ser qualquer tipo integral.  
  
 `enum-list`  
 Uma lista separada por vírgulas dos enumeradores na enumeração.  Cada enumerador ou nome de variável no escopo deve ser exclusivo.  No entanto, os valores podem ser duplicados.  Em um enum sem escopo, o escopo será o escopo adjacente; em um enum com escopo, o escopo será o próprio `enum-list`.  
  
 `class`  
 Ao usar essa palavra\-chave na declaração, você especifica que o enum possui escopo e que um `identifier` deve ser fornecido.  Você também pode usar a palavra\-chave `struct` no lugar de `class`, porque elas são equivalentes semanticamente nesse contexto.  
  
## Comentários  
 Uma enumeração fornece o contexto para descrever um intervalo de valores que são representados como constantes nomeadas e que também são chamados de enumeradores.  Nos tipos de enum originais de C e C\+\+, os enumeradores não qualificados são visíveis em todo o escopo no qual o enum é declarado.  Em enums com escopo, o nome do enumerador deve ser qualificado pelo nome do tipo enum.  O exemplo a seguir demonstra essa diferença básica entre os dois tipos de enums:  
  
```cpp  
namespace CardGame_Scoped  
{  
    enum class Suit { Diamonds, Hearts, Clubs, Spades };  
  
    void PlayCard(Suit suit)  
    {  
        if (suit == Suit::Clubs) // Enumerator must be qualified by enum type  
        { /*...*/}  
    }  
}  
  
namespace CardGame_NonScoped  
{  
    enum Suit { Diamonds, Hearts, Clubs, Spades };  
  
    void PlayCard(Suit suit)  
    {  
        if (suit == Clubs) // Enumerator is visible without qualification  
        { /*...*/  
        }  
    }  
}  
```  
  
 Cada nome em uma enumeração recebe um valor integral que corresponde ao seu local na ordem dos valores na enumeração.  Por padrão, o primeiro valor é atribuído a 0, o seguinte é atribuído a 1, e assim por diante, mas você pode definir explicitamente o valor de um enumerador, como mostrado aqui:  
  
```cpp  
  
enum Suit { Diamonds = 1, Hearts, Clubs, Spades };  
  
```  
  
 O enumerador `Diamonds` recebe o valor `1`.  Os enumeradores subsequentes, se não recebem um valor explícito, recebem o valor do enumerador anterior mais um.  No exemplo anterior, `Hearts` teria o valor 2, `Clubs` teria 3 e assim por diante.  
  
 Cada enumerador é tratado como uma constante e deve ter um nome exclusivo no escopo onde `enum` é definido \(para enums sem escopo\) ou dentro do enum em si \(para enums com escopo\).  Os valores dados para os nomes não devem ser exclusivos.  Por exemplo, se a declaração de um enum sem escopo `Suit` for esta:  
  
```cpp  
enum Suit { Diamonds = 5, Hearts, Clubs = 4, Spades };  
```  
  
 Os valores de `Diamonds`, `Hearts`, `Clubs` e `Spades` são 5, 6, 4, e 5, respectivamente.  Observe que 5 será usado mais de uma vez; isso é permitido mesmo que não seja pretendido.  Essas regras são as mesmas para enums com escopo.  
  
 **Regras de conversão**  
  
 As constantes enum sem escopo podem ser convertidas implicitamente em `int`, mas um `int` nunca pode ser convertido implicitamente em um valor enum.  O exemplo a seguir mostra o que acontece se você tentar atribuir a `hand` um valor que não seja `Suit`:  
  
```cpp  
int account_num = 135692;  
Suit hand;  
hand = account_num; // error C2440: '=' : cannot convert from 'int' to 'Suit'  
  
```  
  
 Uma conversão é necessária para converter um `int` em um enumerador com escopo ou sem escopo.  No entanto, você pode promover um enumerador para um valor inteiro sem uma conversão.  
  
```cpp  
int account_num = Hearts; //OK if Hearts is in a unscoped enum  
```  
  
 O uso de conversões implícitas dessa maneira pode levar a efeitos colaterais não intencionais.  Para ajudar a eliminar erros de programação associados aos enums sem escopo, os valores enum com escopo são fortemente tipados.  Os enumeradores com escopo devem ser qualificados pelo nome do tipo enum \(identificador\) e não podem ser convertidos implicitamente, conforme mostrado no exemplo a seguir:  
  
```cpp  
namespace ScopedEnumConversions  
{  
    enum class Suit { Diamonds, Hearts, Clubs, Spades };  
  
    void AttemptConversions()  
    {  
        Suit hand;   
        hand = Clubs; // error C2065: 'Clubs' : undeclared identifier  
        hand = Suit::Clubs; //Correct.  
        int account_num = 135692;  
        hand = account_num; // error C2440: '=' : cannot convert from 'int' to 'Suit'  
        hand = static_cast<Suit>(account_num); // OK, but probably a bug!!!  
  
        account_num = Suit::Hearts; // error C2440: '=' : cannot convert from 'Suit' to 'int'  
        account_num = static_cast<int>(Suit::Hearts); // OK  
}  
  
```  
  
 Observe que a linha `hand = account_num;` ainda causa o erro que ocorre com enums sem escopo, como mostrado anteriormente.  É permitido com uma conversão explícita.  No entanto, com enums com escopo, a conversão tentada na próxima instrução, `account_num = Suit::Hearts;`, não é mais permitida sem uma conversão explícita.  
  
## Consulte também  
 [Declarações de enumeração C](../c-language/c-enumeration-declarations.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)