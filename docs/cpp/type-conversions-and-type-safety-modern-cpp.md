---
title: Conversões e segurança de tipo
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: 629b361a-2ce1-4700-8b5d-ab4f57b245d5
ms.openlocfilehash: dbca9057622ab1a92b74e2958b8dfbe8d810fede
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246120"
---
# <a name="type-conversions-and-type-safety"></a>Conversões e segurança de tipo

Este documento identifica problemas comuns de conversão de tipos e descreve como você pode evitá- C++ los em seu código.

Quando você escreve um C++ programa, é importante garantir que ele seja de tipo seguro. Isso significa que cada variável, um argumento de função e um valor de retorno de função estão armazenando um tipo aceitável de dados e as operações que envolvem valores de diferentes tipos "fazem sentido" e não causam perda de dados, interpretação incorreta de padrões de bits ou corrupção de memória. Um programa que nunca converte valores explicitamente ou implicitamente de um tipo para outro é de tipo seguro por definição. No entanto, as conversões de tipo, mesmo as conversões não seguras, às vezes são necessárias. Por exemplo, talvez você precise armazenar o resultado de uma operação de ponto flutuante em uma variável do tipo **int**, ou pode ter que passar o valor em um **int** não assinado para uma função que usa um **int**assinado. Ambos os exemplos ilustram conversões não seguras porque podem causar perda de dados ou nova interpretação de um valor.

Quando o compilador detecta uma conversão não segura, ele emite um erro ou um aviso. Um erro para a compilação; um aviso permite que a compilação Continue, mas indica um possível erro no código. No entanto, mesmo que o programa seja compilado sem avisos, ele ainda pode conter código que leva a conversões implícitas de tipo que produzem resultados incorretos. Os erros de tipo também podem ser introduzidos por conversões explícitas, ou conversões no código.

## <a name="implicit-type-conversions"></a>Conversões de tipo implícitas

Quando uma expressão contém operandos de diferentes tipos internos e nenhuma conversão explícita está presente, o compilador usa *conversões padrão* internas para converter um dos operandos para que os tipos sejam correspondentes. O compilador tenta as conversões em uma sequência bem definida até obter um sucesso. Se a conversão selecionada for uma promoção, o compilador não emitirá um aviso. Se a conversão for um estreitamento, o compilador emitirá um aviso sobre possível perda de dados. A perda de dados real depende dos valores reais envolvidos, mas recomendamos que você trate esse aviso como um erro. Se um tipo definido pelo usuário estiver envolvido, o compilador tentará usar as conversões que você especificou na definição de classe. Se não for possível encontrar uma conversão aceitável, o compilador emitirá um erro e não compilará o programa. Para obter mais informações sobre as regras que regem as conversões padrão, consulte [conversões padrão](../cpp/standard-conversions.md). Para obter mais informações sobre conversões definidas pelo usuário, consulte [conversões definidas pelo usuário (C++/CLI)](../dotnet/user-defined-conversions-cpp-cli.md).

### <a name="widening-conversions-promotion"></a>Conversões de alargamento (promoção)

Em uma conversão de ampliação, um valor em uma variável menor é atribuído a uma variável maior sem perda de dados. Como as conversões de alargamento são sempre seguras, o compilador as executa silenciosamente e não emite avisos. As conversões a seguir são conversões ampliadas.

|De|{1&gt;Para&lt;1}|
|----------|--------|
|Qualquer tipo integral assinado ou não assinado, exceto **longo** ou **__int64**|**double**|
|**bool** ou **Char**|Qualquer outro tipo interno|
|**curto** ou **wchar_t**|**int**, **Long**, **longo longo**|
|**int**, **Long**|**long long**|
|**float**|**double**|

### <a name="narrowing-conversions-coercion"></a>Refinando conversões (coerção)

O compilador executa conversões estreitas implicitamente, mas avisa sobre potencial perda de dados. Considere esses avisos muito seriamente. Se você tiver certeza de que nenhuma perda de dados ocorrerá porque os valores na variável maior sempre se ajustarão à variável menor e, em seguida, adicionará uma conversão explícita para que o compilador não emita mais um aviso. Se você não tiver certeza de que a conversão é segura, adicione ao seu código algum tipo de verificação de tempo de execução para lidar com a possível perda de dados para que ele não faça com que o programa produza resultados incorretos.

Qualquer conversão de um tipo de ponto flutuante para um tipo integral é uma conversão de restrição, pois a parte fracionária do valor de ponto flutuante é descartada e perdida.

O exemplo de código a seguir mostra algumas conversões de estreitamento implícitas e os avisos que o compilador emite para elas.

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

### <a name="signed---unsigned-conversions"></a>Conversões assinadas com sinal

Um tipo integral assinado e sua contraparte não assinada são sempre do mesmo tamanho, mas diferem em como o padrão de bit é interpretado para transformação de valor. O exemplo de código a seguir demonstra o que acontece quando o mesmo padrão de bit é interpretado como um valor assinado e como um valor não assinado. O padrão de bit armazenado em ambos os `num` e `num2` nunca altera o que é mostrado na ilustração anterior.

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

Observe que os valores são reinterpretados em ambas as direções. Se o seu programa produzir resultados estranhos em que o sinal do valor pareça invertido do esperado, procure conversões implícitas entre tipos integrais assinados e não assinados. No exemplo a seguir, o resultado da expressão (0-1) é implicitamente convertido de **int** para **int não assinado** quando armazenado em `num`. Isso faz com que o padrão de bit seja reinterpretado.

```cpp
unsigned int u3 = 0 - 1;
cout << u3 << endl; // prints 4294967295
```

O compilador não avisa sobre conversões implícitas entre tipos integrais assinados e não assinados. Portanto, recomendamos que você evite totalmente as conversões assinadas sem assinatura. Se você não puder evitá-los, adicione ao seu código uma verificação de tempo de execução para detectar se o valor que está sendo convertido é maior ou igual a zero e menor ou igual ao valor máximo do tipo assinado. Os valores neste intervalo serão transferidos de assinados para não assinados ou de não assinados para assinados sem serem reinterpretados.

### <a name="pointer-conversions"></a>Conversões de ponteiro

Em muitas expressões, uma matriz C-Style é implicitamente convertida em um ponteiro para o primeiro elemento na matriz, e conversões constantes podem ocorrer silenciosamente. Embora isso seja conveniente, ele também é potencialmente propenso a erros. Por exemplo, o seguinte exemplo de código criado incorretamente parece não-e, ainda assim, será compilado e produzirá um resultado de "p". Primeiro, o literal de constante de cadeia de caracteres "Help" é convertido em um `char*` que aponta para o primeiro elemento da matriz; Esse ponteiro é então incrementado por três elementos para que agora ele aponte para o último elemento ' p '.

```cpp
char* s = "Help" + 3;
```

## <a name="explicit-conversions-casts"></a>Conversões explícitas (difusões)

Usando uma operação de conversão, você pode instruir o compilador a converter um valor de um tipo para outro tipo. O compilador gerará um erro em alguns casos se os dois tipos estiverem completamente não relacionados, mas em outros casos ele não gerará um erro mesmo que a operação não seja de tipo seguro. Use as conversões com moderação porque qualquer conversão de um tipo para outro é uma fonte potencial de erro do programa. No entanto, às vezes as conversões são necessárias, e nem todas as conversões são igualmente perigosas. Um uso eficaz de uma conversão é quando seu código executa uma conversão de restrição e você sabe que a conversão não está fazendo com que seu programa produza resultados incorretos. Na verdade, isso informa ao compilador que você sabe o que está fazendo e para parar de incomodar com avisos sobre ele. Outro uso é para converter de uma classe de ponteiro para derivada para uma classe de ponteiro para base. Outro uso é fazer a conversão de **const**-qualidade de uma variável para passá-la para uma função que requer um argumento não**const** . A maioria dessas operações de conversão envolve alguns riscos.

Na programação em estilo C, o mesmo operador de conversão C-Style é usado para todos os tipos de conversões.

```cpp
(int) x; // old-style cast, old-style syntax
int(x); // old-style cast, functional syntax
```

O operador de conversão C-Style é idêntico ao operador de chamada () e, portanto, é inevidente no código e fácil de ignorar. Ambos são ruins porque são difíceis de reconhecer rapidamente ou Pesquisar, e são diferentes o suficiente para invocar qualquer combinação de **static**, **const**e **reinterpret_cast**. Descobrir o que uma conversão de estilo antigo realmente pode ser difícil e propenso a erros. Por todos esses motivos, quando uma conversão é necessária, recomendamos que você use um dos seguintes C++ operadores de conversão, que, em alguns casos, são significativamente mais fortemente tipados e que expressam muito mais explicitamente a intenção de programação:

- **static_cast**, para conversões que são verificadas somente no momento da compilação. **static_cast** retornará um erro se o compilador detectar que você está tentando fazer a conversão entre tipos que são completamente incompatíveis. Você também pode usá-lo para converter entre ponteiro para base e ponteiro para derivado, mas o compilador nem sempre informa se essas conversões serão seguras no tempo de execução.

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

- **dynamic_cast**, para conversões seguras e verificadas em tempo de execução de ponteiro para base a ponteiro para derivado. Uma **dynamic_cast** é mais segura do que uma **static_cast** para downcasts, mas a verificação de tempo de execução incorre em sobrecarga.

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

- **const_cast**, para a conversão de **const**-qualidade de uma variável ou a conversão de uma variável não**const** para ser **const**. A conversão de **const**-qualidade usando esse operador é tão propenso a erros quanto o uso de uma conversão em estilo C, exceto que com a **conversão const** , é menos provável que você execute a conversão acidentalmente. Às vezes, você precisa fazer a conversão de **const**-qualidade de uma variável, por exemplo, para passar uma variável **const** para uma função que usa um parâmetro não**const** . O exemplo a seguir mostra como fazer isso.

    ```cpp
    void Func(double& d) { ... }
    void ConstCast()
    {
       const double pi = 3.14;
       Func(const_cast<double&>(pi)); //No error.
    }
    ```

   Para obter mais informações, consulte [const_cast](../cpp/const-cast-operator.md).

- **reinterpret_cast**, para conversões entre tipos não relacionados, como **ponteiro** para **int**.

    > [!NOTE]
    >  Esse operador cast não é usado com frequência como os outros, e não é garantido que seja portátil para outros compiladores.

   O exemplo a seguir ilustra como **reinterpret_cast** difere de **static_cast**.

    ```cpp
    const char* str = "hello";
    int i = static_cast<int>(str);//error C2440: 'static_cast' : cannot
                                  // convert from 'const char *' to 'int'
    int j = (int)str; // C-style cast. Did the programmer really intend
                      // to do this?
    int k = reinterpret_cast<int>(str);// Programming intent is clear.
                                       // However, it is not 64-bit safe.
    ```

   Para obter mais informações, consulte [operador de reinterpret_cast](../cpp/reinterpret-cast-operator.md).

## <a name="see-also"></a>Consulte também

[C++sistema de tipos](../cpp/cpp-type-system-modern-cpp.md)<br/>
[Bem-vindo de volta paraC++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
