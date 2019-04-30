---
title: Conversões e segurança de tipo (C++ moderno)
ms.date: 11/04/2016
ms.topic: conceptual
ms.assetid: 629b361a-2ce1-4700-8b5d-ab4f57b245d5
ms.openlocfilehash: 79285e4870b73ff01ed3b230a0162f87c0400aa8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404683"
---
# <a name="type-conversions-and-type-safety-modern-c"></a>Conversões e segurança de tipo (C++ moderno)

Este documento identifica problemas de conversão de tipo comuns e descreve como você pode evitá-las em seu código C++.

Quando você escreve um programa C++, é importante garantir que ele seja fortemente tipada. Isso significa que cada variável, o argumento de função e a função retornar o valor está armazenando um tipo aceitável de dados, e que as operações que envolvem valores de tipos diferentes de "sentido" e não fazem com que a perda de dados, interpretação incorreta de padrões de bit, ou corrupção de memória. Um programa que nunca explícita ou implicitamente converte valores de um tipo para outro é fortemente tipado por definição. No entanto, as conversões de tipo, até mesmo conversões não seguras, às vezes, são necessários. Por exemplo, você talvez precise armazenar o resultado de flutuante operação em uma variável do tipo de ponto **int**, ou talvez você precise passar o valor em um unsigned **int** para uma função que usa com um sinal  **int**. Ambos os exemplos ilustram as conversões não seguras porque podem causar perda de dados ou re interpretação de um valor.

Quando o compilador detecta uma conversão não segura, ele emite um erro ou um aviso. Um erro interrompe a compilação; um aviso permite que a compilação continuar, mas indica um possível erro no código. No entanto, mesmo se o seu programa é compilado sem avisos, ele ainda pode conter código que leva a conversões de tipo implícito que produzem resultados incorretos. Erros de tipo também podem ser introduzidos por conversões explícitas ou conversões, no código.

## <a name="implicit-type-conversions"></a>Conversões de tipo implícito

Quando uma expressão contém operandos dos tipos internos diferentes e não há conversões explícitas estão presentes, o compilador usa interna *conversões padrão* para converter um dos operandos para que os tipos correspondentes. O compilador tenta as conversões em uma sequência bem definida até obter êxito. Se a conversão selecionada for uma promoção, o compilador não emitirá um aviso. Se a conversão é uma redução, o compilador emite um aviso sobre a possível perda de dados. Se ocorre perda de dados real depende dos valores reais envolvidos, mas é recomendável que você trate esse aviso como um erro. Se um tipo definido pelo usuário estiver envolvido, o compilador tentará usar as conversões que você especificou na definição de classe. Se ele não é possível localizar uma conversão aceitável, o compilador emitirá um erro e não o programa. Para obter mais informações sobre as regras que regem as conversões padrão, consulte [conversões padrão](../cpp/standard-conversions.md). Para obter mais informações sobre conversões definidas pelo usuário, consulte [conversões definidas pelo usuário (C++/CLI)](../dotnet/user-defined-conversions-cpp-cli.md).

### <a name="widening-conversions-promotion"></a>Conversões (promoção) de expansão

Em uma conversão de ampliação, um valor em uma variável menor é atribuído a uma variável maior sem perda de dados. Porque as conversões de expansão são sempre seguras, o compilador executa-los silenciosamente e não emite avisos. As conversões a seguir são conversões de ampliação.

|De|Para|
|----------|--------|
|Qualquer um com sinal ou um tipo integral, exceto **long long** ou **__int64**|**double**|
|**bool** ou **char**|Qualquer outro tipo interno|
|**curto** ou **wchar_t**|**int**, **long**, **long long**|
|**int**, **long**|**long long**|
|**float**|**double**|

### <a name="narrowing-conversions-coercion"></a>Conversões de estreitamento (coerção)

O compilador executa conversões de estreitamento implicitamente, mas ele avisará sobre possíveis perdas de dados. Levar esses avisos muito a sério. Se você tiver certeza de que nenhuma perda de dados porque os valores na variável maior sempre se encaixe na menor variável, em seguida, adicione uma conversão explícita para que o compilador não emitirá um aviso. Se você não tiver certeza de que a conversão é segura, adicione ao seu código algum tipo de verificação de tempo de execução para lidar com a possível perda de dados para que ele não faz com que seu programa produzir resultados incorretos.

Nenhuma conversão de flutuante ponto de tipo para um tipo integral é uma conversão redutora porque o valor de ponto a parte fracionária de flutuante é descartado e perdido.

O exemplo de código a seguir mostra alguns implícito de estreitamento conversões e os avisos que o compilador emite para eles.

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

### <a name="signed---unsigned-conversions"></a>Conectado - conversões sem sinal

Um tipo integral com sinal e sua contraparte não assinado são sempre o mesmo tamanho, mas eles diferem em como o padrão de bit é interpretado para transformação de valor. O exemplo de código a seguir demonstra o que acontece quando o mesmo padrão de bit é interpretado como um valor com sinal e um valor sem sinal. O padrão de bits armazenado em ambos `num` e `num2` nunca muda do que é mostrado na ilustração anterior.

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

Observe que os valores são reinterpretados em ambas as direções. Se seu programa produz resultados estranhos na qual o sinal do valor parece invertidos da esperada, procure por conversões implícitas entre tipos integrais assinados e não assinados. No exemplo a seguir, o resultado da expressão (0 - 1) é convertido implicitamente de **int** à **unsigned int** quando ele é armazenado em `num`. Isso faz com que o padrão de bit sejam reinterpretados.

```cpp
unsigned int u3 = 0 - 1;
cout << u3 << endl; // prints 4294967295
```

O compilador não avisa sobre conversões implícitas entre tipos integrais assinados e não assinados. Portanto, é recomendável que você evite conversões signed para unsigned completamente. Se você não é possível evitá-las, em seguida, adicionar ao seu código uma verificação de tempo de execução para detectar se o valor sendo convertido for maior que ou igual a zero e menor ou igual ao valor máximo do tipo com sinal. Os valores nesse intervalo transferirá do assinados de sem sinal ou sem sinal em assinadas sem sendo reinterpretado.

### <a name="pointer-conversions"></a>Conversões de ponteiro

Em várias expressões, uma matriz C-style é convertida implicitamente em um ponteiro para o primeiro elemento na matriz e conversões de constante podem acontecer silenciosamente. Embora isso seja conveniente, também é potencialmente sujeito a erros. Por exemplo, o seguinte exemplo de código projetado inadequadamente parece não fizer sentido e ainda assim ele será compilado no Visual C++ e produz um resultado de 'p'. Primeiro, o literal de constante de cadeia de caracteres "Help" é convertido em um `char*` que aponta para o primeiro elemento da matriz; em seguida, esse ponteiro é incrementado por três elementos para que ele agora aponta para o último elemento 'p'.

```cpp
char* s = "Help" + 3;
```

## <a name="explicit-conversions-casts"></a>Conversões explícitas (casts)

Usando uma operação de conversão, você pode instruir o compilador para converter um valor de um tipo em outro tipo. O compilador gerará um erro em alguns casos, se os dois tipos são completamente não relacionados, mas em outros casos ele não irá gerar um erro, mesmo se a operação não é fortemente tipada. Use conversões com moderação, pois qualquer conversão de um tipo para outro é uma fonte potencial de erro de programa. No entanto, conversões, às vezes, são necessárias, e nem todas as conversões são igualmente perigosos. Um uso eficiente de uma conversão é quando seu código executa uma conversão de estreitamento e você sabe que a conversão não está causando o seu programa produzir resultados incorretos. Na verdade, isso informa ao compilador que você sabe o que está fazendo e pare de se preocupar é com avisos sobre ele. Outro uso é convertido de uma classe derivada ponteiro para uma classe base de ponteiro. Outro uso é para eliminar a **const**- ness de uma variável para passá-lo para uma função que requer um não -**const** argumento. A maioria dessas operações de conversão envolve algum risco.

Na programação de estilo C, o mesmo operador de conversão de estilo C é usado para todos os tipos de conversões.

```cpp
(int) x; // old-style cast, old-style syntax
int(x); // old-style cast, functional syntax
```

O operador de conversão C-style é idêntico para o operador de chamada () e, portanto, é fácil negligenciar e discreta no código. Ambos são ruins, porque eles são difíceis de serem reconhecidas em um piscar de olhos ou pesquisar, e eles são diferentes o suficiente para invocar qualquer combinação de **estáticos**, **const**, e **reinterpret_cast**. Descobrir o que uma conversão de estilo antigo, na verdade, faz pode ser difícil e propensas a erro. Por esses motivos, quando uma conversão é necessária, recomendamos que você use um dos seguintes operadores de conversão de C++, que, em alguns casos são significativamente mais fortemente tipadas e muito mais explicitamente expresso a intenção da programação:

- **static_cast**, para conversões que são verificados durante a compilação de tempo somente. **static_cast** retornará um erro se o compilador detecta que você está tentando converter entre tipos que não são totalmente compatíveis. Você também pode usá-lo para converter entre o base de ponteiro e o ponteiro para derivado, mas o compilador sempre não é possível determinar se essas conversões sejam seguros em tempo de execução.

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

- **dynamic_cast**, para seguros, verificada pelo tempo de execução de conversões de ponteiro para a base a ponteiro para derivado. Um **dynamic_cast** é mais segura do que uma **static_cast** para downcasts, mas o tempo de execução seleção gera uma sobrecarga.

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

- **const_cast**, para conversão imediatamente o **const**- ness de uma variável ou convertendo uma não -**const** variável para ser **const**. Distância de conversão **const**-ness usando esse operador é apenas tão propenso a erro pois está usando um C-style cast, exceto que com **conversão const** será menos provável executar a conversão acidentalmente. Às vezes, você tem que eliminar a **const**-ness de uma variável, por exemplo, para passar um **const** variável para uma função que usa um não**const** parâmetro. O exemplo a seguir mostra como fazer isso.

    ```cpp
    void Func(double& d) { ... }
    void ConstCast()
    {
       const double pi = 3.14;
       Func(const_cast<double&>(pi)); //No error.
    }
    ```

   Para obter mais informações, consulte [const_cast](../cpp/const-cast-operator.md).

- **reinterpret_cast**, para conversões entre não relacionado a tipos, como **ponteiro** à **int**.

    > [!NOTE]
    >  Esse operador de conversão não é usado sempre que os outros e não há garantia de que seja portátil para outros compiladores.

   O exemplo a seguir ilustra como **reinterpret_cast** difere **static_cast**.

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

[Sistema do tipo C++ (C++ moderno)](../cpp/cpp-type-system-modern-cpp.md)<br/>
[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
