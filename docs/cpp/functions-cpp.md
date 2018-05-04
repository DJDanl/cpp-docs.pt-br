---
title: Funções (C++) | Microsoft Docs
ms.custom: ''
ms.date: 01/25/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- defaults, arguments
- function definitions
- function definitions, about function definitions
- default arguments
- declarators, functions
ms.assetid: 33ba01d5-75b5-48d2-8eab-5483ac7d2274
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 720147992540b53c51e731db361cd9946a7a5313
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="functions-c"></a>Funções (C++)

Uma função é um bloco de código que executa uma operação. Uma função pode, opcionalmente, definir parâmetros de entrada que permitem que os chamadores passar argumentos para a função. Uma função, opcionalmente, pode retornar um valor como saída. Funções são úteis para encapsular as operações comuns em um único bloco reutilizável, de preferência com um nome que descreva claramente que a função faz. A função a seguir aceita dois inteiros de um chamador e retorna a soma; `a` e `b` são *parâmetros* do tipo **int**.

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

A função pode ser invocada, ou *chamado*, de qualquer número de locais no programa. Os valores que são passados para a função são o *argumentos*, cujos tipos devem ser compatíveis com os tipos de parâmetro na definição de função.

```cpp
int main()
{
    int i = sum(10, 32);
    int j = sum(i, 66);
    cout << "The value of j is" << j << endl; // 108
}
```

Não há nenhum limite prático para tamanho de função, mas o bom design tem como objetivo para funções que executam uma única tarefa bem definida. Algoritmos complexos devem ser divididos em fáceis de entender mais simples funções sempre que possível.

Funções que são definidas no escopo da classe são chamadas de funções de membro. No C++, ao contrário de outros idiomas, uma função também pode ser definida no escopo do namespace (incluindo o namespace global implícita). Essas funções são chamadas *livre funções* ou *funções não membro*; eles são usados extensivamente na biblioteca padrão.

Funções podem ser *sobrecarregado*, que significa que as versões diferentes de uma função pode compartilhar o mesmo nome se eles forem diferentes, o número e/ou tipo de parâmetros formais. Para obter mais informações, consulte [sobrecarga de função](../cpp/function-overloading.md).

## <a name="parts-of-a-function-declaration"></a>Partes de uma declaração de função

Uma função mínima *declaração* consiste o tipo de retorno, o nome da função e a lista de parâmetros (que pode estar vazia), junto com as palavras-chave opcional que fornecem instruções adicionais para o compilador. O exemplo a seguir é uma declaração de função:

```cpp
int sum(int a, int b);
```

Uma definição de função consiste em uma declaração, mais o *corpo*, que é todo o código entre as chaves:

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

Uma declaração da função seguida por um ponto e vírgula pode aparecer em vários locais em um programa. Ele deve aparecer antes de qualquer chamada para essa função em cada unidade de tradução. A definição da função deve aparecer apenas uma vez no programa de acordo com uma definição de regra (ODR).

As partes necessárias de uma declaração de função são:

1. O tipo de retorno, que especifica o tipo do valor que retorna a função, ou **void** se nenhum valor será retornado. No C++ 11, **automática** é um tipo de retorno válido que instrui o compilador para inferir o tipo da instrução de retorno. No C++ 14, decltype (Auto) também é permitido. Para obter mais informações, consulte dedução de tipo em tipos de retorno abaixo.

1. O nome da função, que deve começar com uma letra ou sublinhado e não pode conter espaços. Em geral, sublinhados em nomes de função de biblioteca padrão indicam funções de membro privado ou funções não membro que não são destinadas para usam seu código.

1. A lista de parâmetros, delimitada por uma chave, separada por vírgulas de conjunto de zero ou mais parâmetros que especificam o tipo e, opcionalmente, um nome local pelo qual os valores podem ser acessados dentro do corpo de função.

Opcionais partes de uma declaração de função são:

1. **constexpr**, que indica que o valor de retorno da função é um valor constante pode ser calculado em tempo de compilação.

    ```cpp
    constexpr float exp(float x, int n)
    {
        return n == 0 ? 1 :
            n % 2 == 0 ? exp(x * x, n / 2) :
            exp(x * x, (n - 1) / 2) * x;
    };
    ```

1. Sua especificação de vinculação, **extern** ou **estático**.

    ```cpp
    //Declare printf with C linkage.
    extern "C" int printf( const char *fmt, ... );

    ```

     Para obter mais informações, consulte [programa e ligação](../cpp/program-and-linkage-cpp.md).

1. **embutido**, que instrui o compilador para substituir todas as chamadas para a função com o código de função. inlining pode ajudar no desempenho em cenários onde uma função executa rapidamente e é chamada repetidamente em uma seção crítica ao desempenho do código.

    ```cpp
    inline double Account::GetBalance()
    {
        return balance;
    }
    ```

     Para obter mais informações, consulte [funções embutidas](../cpp/inline-functions-cpp.md).

1. Um **noexcept** expressão, que especifica se a função pode lançar uma exceção. No exemplo a seguir, a função não lançará uma exceção se o `is_pod` expressão é avaliada como **true**.

    ```cpp
    #include <type_traits>

    template <typename T>
    T copy_object(T& obj) noexcept(std::is_pod<T>) {...}
    ```

     Para obter mais informações, consulte [noexcept](../cpp/noexcept-cpp.md).

1. (Somente para funções de membro) Os qualificadores cv, que especifica se a função é **const** ou **volátil**.

1. (Somente para funções de membro) **virtual**, **substituir**, ou **final**. **virtual** Especifica que uma função pode ser substituída em uma classe derivada. **substituir** significa que uma função em uma classe derivada é uma função virtual de substituição. **final** significa que uma função não pode ser substituída em qualquer ainda mais a classe derivada. Para obter mais informações, consulte [funções virtuais](../cpp/virtual-functions.md).

1. (somente para funções de membro) **estático** aplicado a um membro de função significa que a função não está associada a qualquer instância de objeto da classe.

1. (Somente para funções de membro não estático) O qualificador de referência, que especifica o compilador qual sobrecarga de uma função para escolher quando o parâmetro de objeto implícito (\*isso) é uma referência de rvalue vs. uma referência lvalue. Para obter mais informações, consulte [sobrecarga de função](function-overloading.md#ref-qualifiers).

A figura a seguir mostra as partes de uma definição de função. A área sombreada é o corpo da função.

 ![Partes de uma definição de função](../cpp/media/vc38ru1.gif "vc38RU1") partes de uma definição de função

## <a name="function-definitions"></a>Definições de função

Um *definição de função* consiste de declaração e o corpo da função, entre chaves, que contém declarações de variáveis, expressões e instruções. O exemplo a seguir mostra uma definição de função completa:

```cpp
    int foo(int i, std::string s)
    {
       int value {i};
       MyClass mc;
       if(strcmp(s, "default") != 0)
       {
            value = mc.do_something(i);
       }
       return value;
    }
```

As variáveis declaradas no corpo são chamadas de variáveis locais ou variáveis locais. Saem do escopo quando a função for encerrada; Portanto, uma função nunca deve retornar uma referência a um local!

```cpp
    MyClass& boom(int i, std::string s)
    {
       int value {i};
       MyClass mc;
       mc.Initialize(i,s);
       return mc;
    }
```

## <a name="const-and-constexpr-functions"></a>funções const e constexpr

Você pode declarar uma função de membro como **const** para especificar que a função não tem permissão para alterar os valores de quaisquer membros de dados na classe. Declarando uma função de membro como **const**, ajudar o compilador para impor *exatidão const*. Se alguém erroneamente tentar modificar o objeto usando uma função declarada como **const**, será gerado um erro do compilador. Para obter mais informações, consulte [const](const-cpp.md).

Declarar uma função como **constexpr** quando o valor produz pode possivelmente ser determinada em tempo de compilação. Uma função constexpr geralmente executa mais rápido do que uma função regular. Para obter mais informações, consulte [constexpr](constexpr-cpp.md).

## <a name="function-templates"></a>Modelos de função

Um modelo de função é semelhante a um modelo de classe; ele gera concretas funções baseadas em argumentos de modelo. Em muitos casos, o modelo é capaz de inferir os argumentos de tipo e, portanto, não é necessário especificá-los explicitamente.

```cpp
template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs;
}

auto a = Add2(3.13, 2.895); // a is a double
auto b = Add2(string{ "Hello" }, string{ " World" }); // b is a std::string
```

Para obter mais informações, consulte [modelos de função](../cpp/function-templates.md)

## <a name="function-parameters-and-arguments"></a>Argumentos e parâmetros de função

Uma função tem uma lista separada por vírgulas de parâmetro de zero ou mais tipos de cada um deles tem um nome pelo qual ele possa ser acessado dentro do corpo de função. Um modelo de função pode especificar parâmetros adicionais de tipo ou valor. O chamador passa os argumentos que são valores concretos cujos tipos são compatíveis com a lista de parâmetros.

Por padrão, os argumentos são passados para a função por valor, o que significa que a função recebe uma cópia do objeto que está sendo passado. Para objetos grandes, fazer uma cópia pode ser caro e nem sempre é necessário. Para fazer com que os argumentos a serem passados por referência (especificamente referência lvalue), adicione um quantificador referência ao parâmetro:

```cpp
void DoSomething(std::string& input){...}
```

Quando uma função modifica um argumento que é passado por referência, ela modifica o objeto original, não uma cópia local. Para impedir que uma função de modificação de um argumento, qualifique o parâmetro como const &:

```cpp
void DoSomething(const std::string& input){...}
```

 **C++ 11:** para manipular explicitamente os argumentos que são transmitidos por referência rvalue ou referência lvalue, use um duplo-"e" comercial no parâmetro para indicar uma referência universal:

```cpp
void DoSomething(const std::string&& input){...}
```

Uma função declarada com a palavra-chave única **void** na declaração do parâmetro lista não utiliza argumentos, contanto que a palavra-chave **void** é o primeiro e somente os membros da lista de declaração de argumentos. Argumentos de tipo **void** em outro lugar na lista geram erros. Por exemplo:

```cpp

// OK same as GetTickCount()
long GetTickCount( void );
```

Observe que, embora não é possível especificar um **void** argumento exceto conforme descrito aqui, tipos derivados do tipo **void** (como ponteiros para **void** e matrizes de **void**) podem aparecer em qualquer lugar da lista de declaração de argumentos.

### <a name="default-arguments"></a>Argumentos padrão

O último ou mais parâmetros em uma assinatura de função podem ser atribuídos um argumento padrão, o que significa que o chamador pode omitir o argumento ao chamar a função, a menos que eles desejam especificar algum outro valor.

```cpp
int DoSomething(int num,
    string str,
    Allocator& alloc = defaultAllocator)
{ ... }

// OK both parameters are at end
int DoSomethingElse(int num,
    string str = string{ "Working" },
    Allocator& alloc = defaultAllocator)
{ ... }

// C2548: 'DoMore': missing default parameter for parameter 2
int DoMore(int num = 5, // Not a trailing parameter!
    string str,
    Allocator& = defaultAllocator)
{...}
```

Para obter mais informações, consulte [argumentos padrão](../cpp/default-arguments.md).

## <a name="function-return-types"></a>Tipos de retorno de função

Uma função não pode retornar outra função, ou uma matriz interna; No entanto, ele pode retornar ponteiros para esses tipos, ou um *lambda*, que gera um objeto de função. Exceto para esses casos, uma função pode retornar um valor de qualquer tipo que está no escopo, ou não pode retornar nenhum valor, caso em que o tipo de retorno é **void**.

### <a name="trailing-return-types"></a>Tipos de retorno à direita

Um tipo de retorno "normal" está localizado no lado esquerdo da assinatura de função. Um *o tipo de retorno à direita* está localizado no lado mais à direita da assinatura e é precedida pelo operador ->. Tipos de retorno à direita são especialmente útil em modelos de função quando o tipo do valor de retorno depende de parâmetros de modelo.

```cpp
template<typename Lhs, typename Rhs>
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
```

Quando **automática** é usado em conjunto com um tipo de retorno à direita, ele simplesmente serve como um espaço reservado para qualquer expressão decltype produz e não em si executa dedução de tipo.


## <a name="function-local-variables"></a>Variáveis locais de função

Uma variável que é declarada dentro de um corpo de função é chamada uma *variável local* ou simplesmente *local*. Locais não-estático só são visíveis dentro do corpo de função e, se eles são declarados na pilha de ir fora do escopo quando a função for encerrada. Quando você criar uma variável local e retorná-lo por valor, o compilador normalmente pode executar a otimização de valor de retorno para evitar operações de cópia desnecessários. Se você retornar uma variável local por referência, o compilador emitirá um aviso porque qualquer tentativa de usar essa referência pelo chamador ocorrerá após local foi destruído.

Em C++ uma variável local pode ser declarada como estática. A variável só é visível dentro do corpo de função, mas existe uma única cópia da variável para todas as instâncias da função. Objetos de estáticos locais são destruídos durante o encerramento especificado pelo **atexit**. Se um objeto estático não foi construído porque o fluxo de programa do controle ignorou a declaração dele, nenhuma tentativa de destruição de objeto será feita.

##  <a name="type_deduction"></a> Dedução de tipo em tipos de retorno (C + + 14)

No C++ 14, você pode usar **automática** para instruir o compilador para inferir o tipo do corpo da função de retorno sem ter que fornecer um tipo de retorno à direita. Observe que **automática** sempre deduz um retorno por valor. Use **auto & &** para instruir o compilador para deduzir uma referência.

Neste exemplo, **automática** será deduzido como uma cópia do valor não constante da soma de lhs e rhs.

```cpp
template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs; //returns a non-const object by value
}
```

Observe que **automática** não preserva a qualidade de const do tipo deduz por ele. Para funções cujo valor de retorno precisa preservar a qualidade de const ou ref qualidade de seus argumentos de encaminhamento, você pode usar o **decltype (Auto)** palavra-chave, que usa o **decltype** regras de inferência de tipo e preserva todas as informações de tipo. **decltype (Auto)** pode ser usado como um valor de retorno comuns no lado esquerdo ou como um valor de retorno à direita.

O exemplo a seguir (com base no código de [N3493](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2013/n3493.html)), mostra **decltype (Auto)** que está sendo usado para habilitar o encaminhamento perfeito dos argumentos de função em um tipo de retorno não é conhecido até que o modelo é criar uma instância.

```cpp
template<typename F, typename Tuple = tuple<T...>, int... I>
decltype(auto) apply_(F&& f, Tuple&& args, index_sequence<I...>)
{
    return std::forward<F>(f)(std::get<I>(std::forward<Tuple>(args))...);
}

template<typename F, typename Tuple = tuple<T...>,
    typename Indices = make_index_sequence<tuple_size<Tuple>::value >>
   decltype( auto)
    apply(F&& f, Tuple&& args)
{
    return apply_(std::forward<F>(f), std::forward<Tuple>(args), Indices());
}
}
```

## <a name="returning-multiple-values-from-a-function"></a>Retornar vários valores de uma função

Há várias maneiras para retornar mais de um valor de uma função:

1. Encapsule os valores em um objeto nomeado de classe ou estrutura. Requer a definição de classe ou estrutura fique visível para o chamador:

    ```cpp
    #include <string>
    #include <iostream>
    
    using namespace std;
    
    struct S
    {
        string name;
        int num;
    };
    
    S g()
    {
        string t{ "hello" };
        int u{ 42 };
        return { t, u };
    }
    
    int main()
    {
        S s = g();
        cout << s.name << " " << s.num << endl;
        return 0;
    }
    ```
    
1. Retorne um objeto std::tuple ou std:

    ```cpp
    #include <tuple>
    #include <string>
    #include <iostream>
    
    using namespace std;
        
    tuple<int, string, double> f()
    {
        int i{ 108 };
        string s{ "Some text" };
        double d{ .01 };
        return { i,s,d };
    }
    
    int main()
    {
        auto t = f();
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
     
        // --or--
    
        int myval;
        string myname;
        double mydecimal;
        tie(myval, myname, mydecimal) = f();
        cout << myval << " " << myname << " " << mydecimal << endl;
    
        return 0;
    }
    ```

1. **Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): Use estruturado associações. A vantagem de associações estruturadas é que as variáveis que armazenam os valores de retorno são inicializadas ao mesmo tempo em que eles são declarados, que, em alguns casos pode ser significativamente mais eficiente. Nesta instrução –`auto[x, y, z] = f();`– os colchetes introduzir e inicializar nomes que estão no escopo do bloco de função inteira.

    ```cpp
    #include <tuple>
    #include <string>
    #include <iostream>
    
    using namespace std;
    
    tuple<int, string, double> f()
    {
        int i{ 108 };
        string s{ "Some text" };
        double d{ .01 };
        return { i,s,d };
    }
    struct S
    {
        string name;
        int num;
    };
    
    S g()
    {
        string t{ "hello" };
        int u{ 42 };
        return { t, u };
    }
    
    int main()
    {
        auto[x, y, z] = f(); // init from tuple
        cout << x << " " << y << " " << z << endl;
    
        auto[a, b] = g(); // init from POD struct
        cout << a << " " << b << endl;
        return 0;
    }
    ```
    
1. Além de usar o valor de retorno, você pode "return" valores definindo qualquer número de parâmetros para usar passagem por referência, para que a função possa modificar ou inicializar valores de objetos que fornece o chamador. Para obter mais informações, consulte [argumentos de função de tipo de referência](reference-type-function-arguments.md).

## <a name="function-pointers"></a>Ponteiros de função

C++ dá suporte a ponteiros de função da mesma maneira como a linguagem C. No entanto uma alternativa mais segura de tipo é geralmente usam um objeto de função.

É recomendável que **typedef** ser usadas para declarar um alias para o tipo de ponteiro de função se declarar uma função que retorna um tipo de ponteiro de função.  Por exemplo

```cpp
typedef int (*fp)(int);
fp myFunction(char* s); // function returning function pointer
```

Se isso não for feito, a sintaxe adequada para a declaração de função pode ser deduzida da sintaxe do declarador para o ponteiro de função substituindo o identificador (`fp` no exemplo acima) pelo nome das funções e a lista de argumentos, como segue:

```cpp
int (*myFunction(char* s))(int);
```

A declaração anterior é equivalente à declaração que usa typedef acima.

## <a name="see-also"></a>Consulte também

- [Sobrecarga de função](../cpp/function-overloading.md)
- [Funções com listas de argumentos variáveis](../cpp/functions-with-variable-argument-lists-cpp.md)
- [Funções explicitamente usadas como padrão e excluídas](../cpp/explicitly-defaulted-and-deleted-functions.md)
- [Pesquisa de nome dependente de argumento (Koenig) em funções](../cpp/argument-dependent-name-koenig-lookup-on-functions.md)
- [Argumentos padrão](../cpp/default-arguments.md)
- [Funções Embutidas](../cpp/inline-functions-cpp.md)
