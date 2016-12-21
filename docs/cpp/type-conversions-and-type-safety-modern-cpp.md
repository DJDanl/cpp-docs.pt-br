---
title: "Convers&#245;es e seguran&#231;a de tipo (C++ moderno) | Microsoft Docs"
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
ms.assetid: 629b361a-2ce1-4700-8b5d-ab4f57b245d5
caps.latest.revision: 23
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es e seguran&#231;a de tipo (C++ moderno)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este documento identifica problemas comuns de conversão de tipos e descreve como você pode evitar os em seu código C\+\+.  
  
 Quando você grava o programa criando c, é importante garantir que é fortemente tipado.  Isso significa que cada variável, argumento da função, e valor de retorno da função estiverem armazenando um tipo de dados aceitável, e que as operações que envolvem valores de tipos diferentes “fazem sentido” e não fazem a perda de dados, a interpretação incorreta dos padrões de bit, ou corrupção de memória.  Um programa que nunca converte explicitamente ou implicitamente valores de um tipo para outro é fortemente tipado por definição.  No entanto, as conversões de tipos, mesmo conversões não seguro, são necessárias às vezes.  Por exemplo, você pode precisar armazenar o resultado de uma operação de ponto flutuante em uma variável de tipo `int`, ou talvez você precise passar o valor em `int` sem assinatura a uma função que usa `int`assinado.  Os dois exemplos a seguir ilustram conversões não segura porque podem causar perda de dados ou novamente a interpretação de um valor.  
  
 Quando o compilador detectar uma conversão não seguro, o emite um erro ou um aviso.  Um erro para a compilação; um aviso permite que a compilação continue mas indica um possível erro no código.  Porém, mesmo se seu programa cria sem avisos, ainda pode conter código que resulta em conversões de tipos implícitas que gerencia resultados incorretos.  Os erros de tipo também podem ser introduzidas por conversões explícitas, ou por conversões, no código.  
  
## Conversões de tipos implícitas  
 Quando uma expressão contiver operandos de tipos internos diferentes, e nenhuma conversão explícita estiver presente, o compilador usa *conversões padrão* internos para converter um dos operandos de forma que os tipos correspondam.  O compilador tenta as conversões em uma sequência bem definida até que uma tenha êxito.  Se a conversão selecionada é uma promoção, o compilador não emite um aviso.  Se a conversão for refinar, o compilador emite um aviso sobre a possível perda de dados.  Se a perda de dados real ocorre depende dos valores reais envolvidos, mas recomendamos que você trata esse aviso como um erro.  Se um tipo definido pelo usuário estiver envolvido, o compilador tenta usar as conversões que você especificou na definição da classe.  Se o não conseguir localizar uma conversão aceitável, o compilador emite um erro e não cria o programa.  Para obter mais informações sobre as regras que administram conversões padrão, consulte [Conversões padrão](../cpp/standard-conversions.md).  Para obter mais informações sobre conversões definidos pelo usuário, consulte [Conversões definidas pelo usuário](../dotnet/user-defined-conversions-cpp-cli.md).  
  
### Conversões da \(promoção\)  
 Em uma conversão da, um valor em uma variável menor é atribuído a uma variável maior sem perda de dados.  Como as conversões da sempre são seguras, o compilador execute silenciosamente e não o emitirá avisos.  As conversões a seguir são alargando conversões.  
  
|From|Para|  
|----------|----------|  
|O tipo integral assinado ou não assinado exceptua alguns `long long` ou `__int64`|`double`|  
|`bool` ou `char`|Qualquer outro tipo interno|  
|`short` ou `wchar_t`|`int`, `long`, `long long`|  
|`int`, `long`|`long long`|  
|`float`|`double`|  
  
### Refinando conversões \(coerção\)  
 O compilador refinar executa conversões implicitamente, mas o advertirá sobre a perda potencial de dados.  Faça esses avisos muito seriamente.  Se você tiver certeza de que nenhuma perda de dados ocorrerá porque os valores na variável maior se ajustarão sempre na variável menor, adicione uma conversão explícita de modo que o compilador não emita um aviso.  Se você não tiver certeza de que a conversão é seguro, adicionar ao seu código algum tipo de verificação de tempo de execução a possível perda de dados de forma que não cause seu programa para resultados incorretos do produto.  Para obter sugestões sobre como tratar esse cenário, consulte [\(NOTINBUILD\)How to: Handle Narrowing Conversions \(C\+\+\)](http://msdn.microsoft.com/pt-br/e483237e-501e-4a12-ac24-51526f6ddeaa).  
  
 Qualquer conversão de um tipo de ponto flutuante a um tipo integral é uma conversão refinando como a parte fracionária do valor de ponto flutuante é rejeitada e perdida.  
  
 O exemplo de código a seguir mostra algumas conversões implícitas, limitando e os avisos que o compilador emite para eles.  
  
```cpp  
  
int i = INT_MAX + 1; //warning C4307:'+':integral constant overflow  
wchar_t wch = 'A'; //OK  
char c = wch; // warning C4244:'initializing':conversion from 'wchar_t'  
              // to 'char', possible loss of data  
unsigned char c2 = 0xfffe; //warning C4305:'initializing':truncation from  
                           // 'int' to 'unsigned char'  
int j = 1.9f; // warning C4244:'initializing':conversion from 'float' to  
              // 'int', possible loss of data  
int k = 7.7; // warning C4244:'initializing':conversion from 'double' to  
             // 'int', possible loss of data  
  
```  
  
### Assinada \- conversões não assinados  
 Um tipo integral assinado e suas contrapartes não assinados são sempre o mesmo tamanho, mas diferente de como o padrão de bits é interpretado para a transformação de valor.  O exemplo de código a seguir demonstra o que acontece quando o mesmo padrão de bits é interpretado como um valor assinado e como um valor sem assinatura.  O padrão de bits armazenado no `num` e `num2` nunca muda do que é mostrado na ilustração anterior.  
  
```cpp  
  
using namespace std;  
unsigned short num = numeric_limits<unsigned short>::max(); // #include <limits>  
short num2 = num;  
cout << "unsigned val = " << num << " signed val = " << num2 << endl;  
// Prints: unsigned val = 65535 signed val = -1  
  
// Go the other way.  
num2 = -1;  
num = num2;  
cout << "unsigned val = " << num << " signed val = " << num2 << endl;  
// Prints: unsigned val = 65535 signed val = -1  
  
```  
  
 Observe que os valores reinterpreted nas duas direções.  Se seu programa gerencia os resultados não no sinal do valor aparece inversa do que você espera, procure conversões implícitas entre tipos assinados e não assinados de integral.  No exemplo a seguir, o resultado da expressão \(0 – 1\) será convertido implicitamente de `int` a `unsigned int` quando armazenados em `num`.  Isso faz com que o padrão de bit a ser reinterpreted.  
  
```cpp  
  
unsigned int u3 = 0 - 1;  
cout << u3 << endl; // prints 4294967295  
  
```  
  
 O compilador não avisará sobre conversões implícitas entre tipos integrais assinados e não assinados.  Consequentemente, recomendamos que você evite conversões assinar\-à\- não assinados por meio de.  Se você não pode impedir o, adicione ao seu código uma verificação de tempo de execução para detectar se o valor que está sendo convertido for maior ou igual a zero e menor ou igual ao valor máximo do tipo assinado.  Os valores nesse intervalo transferirão da assinatura sem assinado ou não assinado da assinatura sem ser reinterpreted.  
  
### Conversões do ponteiro  
 Em muitas expressões, c a matriz de estilo? a implicitamente a um ponteiro para o primeiro elemento da matriz, e as conversões constantes pode acontecer silenciosamente.  Embora isso é conveniente, também é potencialmente sujeito a erros.  Por exemplo, o exemplo de código ruim criado é sem\-sentido, e ainda criará no Visual C\+\+ e gerencie um resultado de “p”.  Primeiro, o literal constante de cadeia de caracteres de “ajuda” é convertido em `char*` que aponta para o primeiro elemento da matriz; esse ponteiro é incrementado por três elementos de modo que ele agora pontos para o elemento o último “p”.  
  
```cpp  
  
char* s = "Help" + 3;  
  
```  
  
## Conversões explícitas \(conversões\)  
 Usando uma operação de conversão, você pode instruir o compilador para converter um valor de um tipo para outro tipo.  O compilador gerará um erro em alguns casos se os dois tipos são completamente não relacionadas, mas em outros casos não gerará um erro se a operação não será fortemente tipado.  O uso converte moderadamente porque qualquer conversão de um tipo para outro é uma origem do erro potencial de programa.  No entanto, as conversões são necessárias às vezes, e nem todas as conversões são igualmente perigosas.  Um uso eficiente de uma conversão é quando o código executar uma conversão refinando e você souber que a conversão não está causando o programa aos resultados incorretos do produto.  De fato, isso diz ao compilador que você souber qual você está fazendo e interromper de incomodar com avisos sobre ele.  Outro uso é converter de uma classe derivada ponteiro\-à\- a uma classe de ponteiro\-à\- base.  Outro uso é acionado converter `const`\- Ness de uma variável para passá\-lo para uma função que requer um argumento não de`const` .  A maioria dessas operações de conversão envolvem certo risco.  
  
 Em programação do C \- estilo, o mesmo operador cast do c \- estilo 2.0 é usado para todos os tipos de conversões.  
  
```cpp  
  
(int) x; // old-style cast, old-style syntax  
int(x); // old-style cast, functional syntax  
  
```  
  
 O operador cast de estilo 2.0 \- c é idêntico ao operador de chamada \(\) e é como consequência imperceptível em código e fácil de negligenciar.  Ambos são incorretos porque são difíceis de reconhecer em um relance ou pesquisando, e são distintos o suficiente para invocar qualquer combinação de `static`, de `const`, e de `reinterpret_cast`.  Figurar do que uma conversão torne desatualizada de fato pode ser difícil e susceptível a erros.  Para todas essas razões, quando uma conversão é necessária, recomendamos que você use um dos seguintes operadores de conversão C\+\+, que são significativamente em alguns casos tipo mais seguro, e que especificam muito mais explicitamente a intenção de programação:  
  
-   `static_cast`, para as conversões que são verificadas em tempo de compilação somente.  `static_cast` retorna um erro se o compilador detectar que você está tentando converter entre os tipos que são completamente incompatíveis.  Você também pode usá\-lo para converter entre a ponteiro\-à\- base e ponteiro\-à\- derivada, mas o compilador não sempre poderá indicar se tais conversões são seguras em tempo de execução.  
  
    ```cpp  
  
    double d = 1.58947;  
    int i = d;  // warning C4244 possible loss of data  
    int j = static_cast<int>(d);       // No warning.  
    string s = static_cast<string>(d); // Error C2440:cannot convert from  
                                       // double to std:string  
  
    // No error but not necessarily safe.  
    Base* b = new Base();  
    Derived* d2 = static_cast<Derived*>(b);  
  
    ```  
  
     Para obter mais informações, consulte [static\_cast](../cpp/static-cast-operator.md).  
  
-   `dynamic_cast`, para segura, em tempo de compilação verificou conversões de ponteiro\-à\- base a ponteiro\-à\- derivada.  `dynamic_cast` é mais segura que `static_cast` para entradas de aérea, mas a verificação de tempo de execução incorre alguma sobrecarga.  
  
    ```cpp  
  
    Base* b = new Base();  
  
    // Run-time check to determine whether b is actually a Derived*  
    Derived* d3 = dynamic_cast<Derived*>(b);  
  
    // If b was originally a Derived*, then d3 is a valid pointer.  
    if(d3)  
    {  
       // Safe to call Derived method.  
       cout << d3->DoSomethingMore() << endl;  
    }  
    else  
    {  
       // Run-time check failed.  
       cout << "d3 is null" << endl;  
    }  
  
    //Output: d3 is null;  
  
    ```  
  
     Para obter mais informações, consulte [dynamic\_cast](../cpp/dynamic-cast-operator.md).  
  
-   `const_cast`, para converter acionado `const`\- Ness de uma variável, ou converter uma variável não de`const` para ser `const`.  Convertendo está ausente `const`\- Ness usando esse operador tão sujeito a erros quanto estiver usando a c o estilo da conversão, exceto que a `const-cast` que é menos provável acidentalmente executar a conversão.  Às vezes você precisa converter acionado `const`\- Ness de uma variável, por exemplo, para passar uma variável de `const` a uma função que usa um parâmetro não de`const` .  O exemplo a seguir mostra como fazer isto:  
  
    ```cpp  
  
    void Func(double& d) { ... }  
    void ConstCast()  
    {  
       const double pi = 3.14;  
       Func(const_cast<double&>(pi)); //No error.  
    }  
  
    ```  
  
     Para obter mais informações, consulte [const\_cast](../Topic/const_cast%20Operator.md).  
  
-   `reinterpret_cast`, para conversões entre tipos não relacionados como `pointer` a `int`.  
  
    > [!NOTE]
    >  Esse operador cast não é usado com tanta frequência quanto o outro e, se não garante para ser portátil para outros compiladores.  
  
     O exemplo a seguir ilustra como `reinterpret_cast` difere de `static_cast`.  
  
    ```cpp  
  
    const char* str = "hello";  
    int i = static_cast<int>(str);//error C2440: 'static_cast' : cannot  
                                  // convert from 'const char *' to 'int'  
    int j = (int)str; // C-style cast. Did the programmer really intend  
                      // to do this?  
    int k = reinterpret_cast<int>(str);// Programming intent is clear.  
                                       // However, it is not 64-bit safe.  
  
    ```  
  
     Para obter mais informações, consulte [Operador reinterpret\_cast](../cpp/reinterpret-cast-operator.md).  
  
## Consulte também  
 [Sistema do tipo C\+\+](../Topic/C++%20Type%20System%20\(Modern%20C++\).md)   
 [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)