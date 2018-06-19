---
title: Conversões e segurança de tipos (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 629b361a-2ce1-4700-8b5d-ab4f57b245d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 13dabba7b7cfc769d91471c2dfc6f92f1b414996
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32424770"
---
# <a name="type-conversions-and-type-safety-modern-c"></a>Conversões e segurança de tipo (C++ moderno)
Este documento identifica problemas de conversão de tipo comuns e descreve como evitá-los em seu código C++.  
  
 Quando você escreve um programa C++, é importante garantir que ele seja fortemente tipado. Isso significa que cada variável, o argumento de função e a função retornar o valor está armazenando um tipo aceitável de dados e que as operações que envolvem valores de tipos diferentes de "fazem sentido" e não causarem perda de dados, interpretação incorreta de padrões de bit, ou corrupção de memória. Um programa que nunca explícita ou implicitamente converte valores de um tipo para outro é fortemente tipado por definição. No entanto, conversões de tipo, mesmo conversões unsafe, às vezes, são necessárias. Por exemplo, você pode ter que armazenar o resultado de um flutuante operação de ponto em uma variável do tipo `int`, ou talvez você precise passar o valor sem um sinal `int` para uma função que usa um `int`. Ambos os exemplos ilustram conversões não seguras porque eles podem causar perda de dados ou interpretação novamente de um valor.  
  
 Quando o compilador detecta uma conversão não segura, ele emite um erro ou um aviso. Um erro interrompe a compilação; um aviso permite compilação continuar, mas indica um possível erro no código. No entanto, mesmo que o programa é compilado sem avisos, ele ainda pode conter código que leva a conversões de tipo implícito que produzem resultados incorretos. Erros de tipo também podem ser introduzidos por conversões explícitas ou conversões no código.  
  
## <a name="implicit-type-conversions"></a>Conversões de tipo implícito  
 Quando uma expressão contém operandos dos tipos internos diferentes e não há conversões explícitas estão presentes, o compilador usa internas *conversões padrão* para converter um dos operandos de forma que os tipos correspondentes. O compilador tenta as conversões em uma sequência bem definida até obter êxito. Se a conversão selecionada é uma promoção, o compilador não emitirá um aviso. Se a conversão é uma restrição, o compilador emite um aviso sobre a possível perda de dados. Se ocorre perda de dados real depende dos valores reais envolvidos, mas é recomendável que você trate esse aviso como um erro. Se um tipo definido pelo usuário estiver envolvido, o compilador tenta usar as conversões que você especificou na definição de classe. Se ele não encontra uma conversão aceitável, o compilador emite um erro e não compila o programa. Para obter mais informações sobre as regras que controlam as conversões padrão, consulte [conversões padrão](../cpp/standard-conversions.md). Para obter mais informações sobre conversões definidas pelo usuário, consulte [conversões definidas pelo usuário (C + + CLI)](../dotnet/user-defined-conversions-cpp-cli.md).  
  
### <a name="widening-conversions-promotion"></a>(Promoção) de conversões ampliadoras  
 Em uma conversão de ampliação, um valor em uma variável menor é atribuído a uma variável maior sem perda de dados. Como conversões ampliadoras são sempre seguras, o compilador executa silenciosamente e emita avisos. As conversões a seguir são conversões ampliadoras.  
  
|De|Para|  
|----------|--------|  
|Qualquer assinados ou não assinados tipo integral exceto `long long` ou `__int64`|`double`|  
|`bool` ou `char`|Qualquer outro tipo interno|  
|`short` ou `wchar_t`|`int`, `long`, `long long`|  
|`int`, `long`|`long long`|  
|`float`|`double`|  
  
### <a name="narrowing-conversions-coercion"></a>Conversões de estreitamento (coerção)  
 O compilador executa conversões de estreitamento implicitamente, mas ele avisa sobre uma possível perda de dados. Levar esses avisos muito sério. Se você tiver certeza de que nenhuma perda de dados porque os valores da variável maior sempre se encaixe na variável menor, em seguida, adicione uma conversão explícita para que o compilador não emitirá um aviso. Se você não tiver certeza de que a conversão é segura, adicione ao seu código algum tipo de verificação de tempo de execução para lidar com a possível perda de dados para que ele não faz com que seu programa a gerar resultados incorretos. 
  
 Nenhuma conversão de um flutuante ponto de tipo para um tipo integral é uma conversão de restrição porque o valor de ponto a parte fracionária de flutuante é descartado e perdido.  
  
 O exemplo de código a seguir mostra alguns implícito restringir conversões e os avisos que o compilador emite para eles.  
  
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
  
### <a name="signed---unsigned-conversions"></a>Conectado - conversões não assinados  
 Um tipo inteiro assinado e sua contraparte não assinado são sempre o mesmo tamanho, mas elas podem diferir em como o padrão de bits é interpretado para transformação do valor. O exemplo de código a seguir demonstra o que acontece quando o mesmo padrão de bit é interpretado como um valor assinado e como um valor não assinado. O padrão de bits armazenado no `num` e `num2` nunca é alterado de que é mostrado na ilustração anterior.  
  
```cpp  
using namespace std;  
unsigned short num = numeric_limits<unsigned short>::max(); // #include <limits>  
short num2 = num;  
cout << "unsigned val = " << num << " signed val = " << num2 << endl;  
// Prints: unsigned val = 65535 signed val = -1  
  
// Go the other way.  
num2 = -1;  
num = num2;  
cout << "unsigned val = " << num << " signed val = " << num2 << endl;  
// Prints: unsigned val = 65535 signed val = -1  
  
```  
  
 Observe que os valores são reinterpretados em ambas as direções. Se seu programa produz resultados estranhos no qual o sinal do valor parece invertidos do esperado, procure conversões implícitas entre tipos integrais assinados e não assinados. No exemplo a seguir, o resultado da expressão (0 - 1) é convertido implicitamente de `int` para `unsigned int` quando ele é armazenado em `num`. Isso faz com que o bit padrão a ser reinterpretadas.  
  
```cpp  
unsigned int u3 = 0 - 1;  
cout << u3 << endl; // prints 4294967295  
  
```  
  
 O compilador não avisar sobre conversões implícitas entre tipos integrais assinados e não assinados. Portanto, é recomendável que você evite conversões assinado para unsigned completamente. Se você não pode evitá-los, em seguida, adicionar ao seu código uma verificação de tempo de execução para detectar se o valor sendo convertido é maior que ou igual a zero e menor ou igual ao valor máximo do tipo assinado. Os valores nesse intervalo transferirá do assinado em não assinado ou não assinado em assinado sem sendo reinterpretados.  
  
### <a name="pointer-conversions"></a>Conversões de ponteiro  
 Em muitas expressões, uma matriz C-style é convertida implicitamente em um ponteiro para o primeiro elemento na matriz e conversões constantes podem acontecer silenciosamente. Embora seja conveniente, também é potencialmente propensas a erros. Por exemplo, o seguinte exemplo de código mal projetado parece não fizer sentido e ainda, ela será compilado no Visual C++ e produz um resultado de 'p'. Primeiro, o literal de constante de cadeia de caracteres "Help" é convertido em um `char*` que aponta para o primeiro elemento da matriz; esse ponteiro, em seguida, é incrementado em três elementos de forma que ele agora aponta para o último elemento 'p'.  
  
```cpp  
char* s = "Help" + 3;  
  
```  
  
## <a name="explicit-conversions-casts"></a>Conversões explícitas (projeções)  
 Usando uma operação de conversão, você pode instruir o compilador para converter um valor de um tipo em outro tipo. O compilador gerará um erro em alguns casos, se os dois tipos são completamente diferente, mas em outros casos ele não gerará um erro mesmo se a operação não é do tipo seguro. Use conversões com moderação porque nenhuma conversão de um tipo para outro é uma origem potencial de erro de programa. No entanto, conversões, às vezes, são necessárias, e nem todas as conversões são igualmente perigosos. Um uso eficiente de uma conversão é quando seu código executa uma conversão de restrição e você souber que a conversão não está causando o programa a gerar resultados incorretos. Na verdade, isso informa ao compilador que você sabe o que está fazendo e pare de se preocupar você com avisos sobre ele. Outro uso é convertido de uma classe derivada ponteiro para uma classe base de ponteiro. Outro uso é eliminar a `const`- qualidade de uma variável para passá-lo para uma função que requer uma não -`const` argumento. A maioria dessas operações de conversão envolve algum risco.  
  
 Na programação do estilo C, o mesmo operador de conversão C-style é usado para todos os tipos de conversões.  
  
```cpp  
(int) x; // old-style cast, old-style syntax  
int(x); // old-style cast, functional syntax  
  
```  
  
 O operador de conversão C-style é idêntico para o operador de chamada () e, portanto, discreta no código e fácil de ignorar. Ambos são inválidas porque é difícil reconhecer em um relance ou pesquisar, e eles são diferentes para invocar qualquer combinação de `static`, `const`, e `reinterpret_cast`. Descobrir o que uma conversão de estilo antigo realmente faz pode ser difícil e propenso a erros. Por esses motivos, quando uma conversão é necessária, recomendamos que você use um dos seguintes operadores cast C++, que, em alguns casos são significativamente mais fortemente tipado, e muito mais explicitamente expresso a intenção de programação:  
  
-   `static_cast`, para conversões que são verificadas durante a compilação de tempo somente. `static_cast` Retorna um erro se o compilador detecta que você está tentando converter entre tipos que não são totalmente compatíveis. Você também pode usar isso para converter entre ponteiro-para-base e o ponteiro para derivado, mas o compilador não pode sempre informar se tais conversões sejam seguros em tempo de execução.  
  
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
  
     Para obter mais informações, consulte [static_cast](../cpp/static-cast-operator.md).  
  
-   `dynamic_cast`, para seguras verificada em tempo de execução, conversões de ponteiro para base a ponteiro para derivado. Um `dynamic_cast` é mais segura do que uma `static_cast` para downcasts, mas o tempo de execução seleção gera uma sobrecarga.  
  
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
  
     Para obter mais informações, consulte [dynamic_cast](../cpp/dynamic-cast-operator.md).  
  
-   `const_cast`, para conversão imediatamente o `const`- qualidade de uma variável ou convertendo uma não -`const` variável para ser `const`. Rejeitando `const`-qualidade usando esse operador é apenas como propensas a erros que esteja usando um C-style cast, exceto que, com `const-cast` menos prováveis de executar a conversão acidentalmente. Às vezes, você precisa eliminar o `const`-qualidade de uma variável, por exemplo, para passar um `const` variável para uma função que usa uma não -`const` parâmetro. O exemplo a seguir mostra como fazer isso.  
  
    ```cpp  
    void Func(double& d) { ... }  
    void ConstCast()  
    {  
       const double pi = 3.14;  
       Func(const_cast<double&>(pi)); //No error.  
    }  
  
    ```  
  
     Para obter mais informações, consulte [const_cast](../cpp/const-cast-operator.md).  
  
-   `reinterpret_cast`, para conversões entre não relacionados a tipos como `pointer` para `int`.  
  
    > [!NOTE]
    >  Este operador cast não é usado sempre que os outros, e não há garantia de que ser portátil para outros compiladores.  
  
     O exemplo a seguir ilustra como `reinterpret_cast` difere `static_cast`.  
  
    ```cpp  
    const char* str = "hello";  
    int i = static_cast<int>(str);//error C2440: 'static_cast' : cannot  
                                  // convert from 'const char *' to 'int'  
    int j = (int)str; // C-style cast. Did the programmer really intend  
                      // to do this?  
    int k = reinterpret_cast<int>(str);// Programming intent is clear.  
                                       // However, it is not 64-bit safe.  
  
    ```  
  
     Para obter mais informações, consulte [operador reinterpret_cast](../cpp/reinterpret-cast-operator.md).  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipo C++](../cpp/cpp-type-system-modern-cpp.md)   
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)