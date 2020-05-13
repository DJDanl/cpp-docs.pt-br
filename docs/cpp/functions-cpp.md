---
title: Funções (C++)
ms.date: 11/19/2018
helpviewer_keywords:
- defaults, arguments
- function definitions
- function definitions, about function definitions
- default arguments
- declarators, functions
ms.assetid: 33ba01d5-75b5-48d2-8eab-5483ac7d2274
ms.openlocfilehash: 1425ddebffc150158e88e44b1d2c22e3f85e5a31
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375733"
---
# <a name="functions-c"></a>Funções (C++)

Uma função é um bloco de código que realiza alguma operação. Uma função pode definir opcionalmente parâmetros de entrada que permitem que os chamadores passem argumentos para a função. Uma função pode, opcionalmente, retornar um valor como saída. As funções são úteis para encapsular operações comuns em um único bloco reutilizável, idealmente com um nome que descreve claramente o que a função faz. A função a seguir aceita dois inteiros de um chamador e retorna sua soma; *a* e *b* são *parâmetros* do tipo **int**.

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

A função pode ser invocada, ou *chamada,* de qualquer número de lugares do programa. Os valores que são passados para a função são os *argumentos,* cujos tipos devem ser compatíveis com os tipos de parâmetros na definição da função.

```cpp
int main()
{
    int i = sum(10, 32);
    int j = sum(i, 66);
    cout << "The value of j is" << j << endl; // 108
}
```

Não há limite prático para o comprimento da função, mas o bom design visa funções que executam uma única tarefa bem definida. Algoritmos complexos devem ser divididos em funções mais simples e fáceis de entender sempre que possível.

As funções definidas no escopo da classe são chamadas de funções de membro. Em C++, ao contrário de outros idiomas, uma função também pode ser definida no escopo namespace (incluindo o namespace global implícito). Tais funções são chamadas *de funções livres* ou *funções não-membros;* eles são usados extensivamente na Biblioteca Padrão.

As funções podem estar *sobrecarregadas,* o que significa que diferentes versões de uma função podem compartilhar o mesmo nome se diferem pelo número e/ou tipo de parâmetros formais. Para obter mais informações, consulte [Sobrecarga de função](../cpp/function-overloading.md).

## <a name="parts-of-a-function-declaration"></a>Partes de uma declaração de função

Uma *declaração* de função mínima consiste no tipo de retorno, nome da função e lista de parâmetros (que podem estar vazios), juntamente com palavras-chave opcionais que fornecem instruções adicionais ao compilador. O exemplo a seguir é uma declaração de função:

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

Uma declaração de função seguida de ponto e vírgula pode aparecer em vários lugares de um programa. Deve aparecer antes de qualquer chamada para essa função em cada unidade de tradução. A definição de função deve aparecer apenas uma vez no programa, de acordo com a Regra de Uma Definição (ODR).

As partes exigidas de uma declaração de função são:

1. O tipo de retorno, que especifica o tipo do valor que a função retorna, ou **anular** se nenhum valor for devolvido. Em C++11, **auto** é um tipo de retorno válido que instrui o compilador a inferir o tipo da instrução de retorno. Em C++14, decltype (auto) também é permitido. Para obter mais informações, consulte Dedução de tipo em Tipos de Retorno abaixo.

1. O nome da função, que deve começar com uma letra ou sublinhado e não pode conter espaços. Em geral, os principais sublinhados nos nomes das funções da Biblioteca Padrão indicam funções privadas de membros ou funções não-membros que não são destinadas ao uso pelo seu código.

1. A lista de parâmetros, uma cinta delimitada, conjunto separado por vírgula de zero ou mais parâmetros que especificam o tipo e, opcionalmente, um nome local pelo qual os valores podem ser acessados dentro do corpo de função.

As partes opcionais de uma declaração de função são:

1. `constexpr`, o que indica que o valor de retorno da função é um valor constante pode ser calculado no momento da compilação.

    ```cpp
    constexpr float exp(float x, int n)
    {
        return n == 0 ? 1 :
            n % 2 == 0 ? exp(x * x, n / 2) :
            exp(x * x, (n - 1) / 2) * x;
    };
    ```

1. Sua especificação de ligação, **extern** ou **estática.**

    ```cpp
    //Declare printf with C linkage.
    extern "C" int printf( const char *fmt, ... );

    ```

   Para obter mais informações, consulte [unidades de tradução e vinculação](../cpp/program-and-linkage-cpp.md).

1. **inline**, que instrui o compilador a substituir cada chamada para a função pelo próprio código de função. o inlineamento pode ajudar o desempenho em cenários onde uma função é executada rapidamente e é invocada repetidamente em uma seção crítica de desempenho do código.

    ```cpp
    inline double Account::GetBalance()
    {
        return balance;
    }
    ```

   Para obter mais informações, consulte [Funções inline](../cpp/inline-functions-cpp.md).

1. Uma `noexcept` expressão, que especifica se a função pode ou não abrir uma exceção. No exemplo a seguir, a função não `is_pod` lança uma exceção se a expressão avaliar como **verdadeira**.

    ```cpp
    #include <type_traits>

    template <typename T>
    T copy_object(T& obj) noexcept(std::is_pod<T>) {...}
    ```

   Para obter mais informações, consulte [noexcept](../cpp/noexcept-cpp.md).

1. (Somente funções de membros) Os cv-qualifiers, que especificam se a função é **const** ou **volátil**.

1. (Somente funções de membros) **virtual,** `override`ou `final`. **virtual** especifica que uma função pode ser substituída em uma classe derivada. `override`significa que uma função em uma classe derivada está substituindo uma função virtual. `final`significa que uma função não pode ser substituída em nenhuma classe derivada. Para obter mais informações, consulte [Funções Virtuais](../cpp/virtual-functions.md).

1. (somente funções de membros) **estática** aplicada a uma função de membro significa que a função não está associada a nenhuma instância de objeto da classe.

1. (Somente funções de membros não estáticos) O ref-qualifier, que especifica para o compilador qual sobrecarga de uma função\*para escolher quando o parâmetro de objeto implícito (isso) é uma referência de valor versus uma referência de valor. Para obter mais informações, consulte [Sobrecarga de função](function-overloading.md#ref-qualifiers).

A figura a seguir mostra as partes de uma definição de função. A área sombreada é o corpo da função.

![Partes de uma definição de função](../cpp/media/vc38ru1.gif "Partes de uma definição de função") <br/>
Partes de uma definição de função

## <a name="function-definitions"></a>Definições de função

Uma definição de *função* consiste na declaração e no corpo função, fechadoem em aparelhos encaracolados, que contém declarações variáveis, declarações e expressões. O exemplo a seguir mostra uma definição completa de função:

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

As variáveis declaradas dentro do corpo são chamadas de variáveis locais ou locais. Eles saem do escopo quando a função sai; portanto, uma função nunca deve retornar uma referência a um local!

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

Você pode declarar uma função de membro como **const** para especificar que a função não está autorizada a alterar os valores de quaisquer membros de dados da classe. Ao declarar uma função de membro como **const,** você ajuda o compilador a impor a *correção do const*. Se alguém tentar erroneamente modificar o objeto usando uma função declarada como **const,** um erro de compilador é levantado. Para obter mais informações, consulte [const](const-cpp.md).

Declare uma `constexpr` função como quando o valor que ela produz pode possivelmente ser determinado no momento da compilação. Uma função constexpr geralmente é executada mais rápido do que uma função regular. Para obter mais informações, consulte [constexpr](constexpr-cpp.md).

## <a name="function-templates"></a>Modelos de função

Um modelo de função é semelhante a um modelo de classe; gera funções concretas com base nos argumentos do modelo. Em muitos casos, o modelo é capaz de inferir os argumentos do tipo e, portanto, não é necessário especificá-los explicitamente.

```cpp
template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs;
}

auto a = Add2(3.13, 2.895); // a is a double
auto b = Add2(string{ "Hello" }, string{ " World" }); // b is a std::string
```

Para obter mais informações, consulte [Modelos de função](../cpp/function-templates.md)

## <a name="function-parameters-and-arguments"></a>Parâmetros de função e argumentos

Uma função tem uma lista de parâmetros separados por comma de zero ou mais tipos, cada um dos quais tem um nome pelo qual pode ser acessado dentro do corpo de função. Um modelo de função pode especificar parâmetros adicionais de tipo ou valor. O chamador passa argumentos, que são valores concretos cujos tipos são compatíveis com a lista de parâmetros.

Por padrão, os argumentos são passados para a função por valor, o que significa que a função recebe uma cópia do objeto que está sendo passado. Para objetos grandes, fazer uma cópia pode ser caro e nem sempre é necessário. Para fazer com que os argumentos sejam passados por referência (especificamente referência de valor), adicione um quantificador de referência ao parâmetro:

```cpp
void DoSomething(std::string& input){...}
```

Quando uma função modifica um argumento que é passado por referência, ele modifica o objeto original, não uma cópia local. Para evitar que uma função modifique esse argumento, qualifique o parâmetro como const&:

```cpp
void DoSomething(const std::string& input){...}
```

**C++ 11:**  Para lidar explicitamente com argumentos que são passados por referência de valor ou referência de valor, use um ampersand duplo no parâmetro para indicar uma referência universal:

```cpp
void DoSomething(const std::string&& input){...}
```

Uma função declarada com a **única palavra-chave nula** na lista de declaração de parâmetro não tem argumentos, desde que a palavra-chave **nula** seja o primeiro e único membro da lista de declaração de argumento. Argumentos de **vazio** de tipo em outros lugares da lista produzem erros. Por exemplo:

```cpp

// OK same as GetTickCount()
long GetTickCount( void );
```

Observe que, embora seja ilegal especificar um argumento **de vazio,** exceto como descrito aqui, tipos derivados do **vazio** de tipo (como ponteiros para **anular** e matrizes de **vazio)** podem aparecer em qualquer lugar da lista de declaração de argumento.

### <a name="default-arguments"></a>Argumentos padrão

O último parâmetro ou parâmetros em uma assinatura de função pode ser atribuído um argumento padrão, o que significa que o chamador pode deixar de fora o argumento ao chamar a função, a menos que queira especificar algum outro valor.

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

Para obter mais informações, consulte [Argumentos padrão](../cpp/default-arguments.md).

## <a name="function-return-types"></a>Tipos de retorno de função

Uma função não pode retornar outra função ou uma matriz incorporada; no entanto, ele pode retornar ponteiros para esses tipos, ou um *lambda*, que produz um objeto de função. Com exceção desses casos, uma função pode retornar um valor de qualquer tipo que esteja no escopo, ou pode não retornar nenhum valor, nesse caso o tipo de retorno é **nulo**.

### <a name="trailing-return-types"></a>Tipos de retorno em trilha

Um tipo de retorno "ordinário" está localizado no lado esquerdo da assinatura da função. Um *tipo de retorno de arrasto* está localizado no lado direito da assinatura e é precedido pelo operador ->. Os tipos de retorno de arrasto são especialmente úteis em modelos de função quando o tipo de valor de retorno depende dos parâmetros do modelo.

```cpp
template<typename Lhs, typename Rhs>
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
```

Quando **o auto** é usado em conjunto com um tipo de retorno de arrasto, ele serve apenas como um espaço reservado para qualquer que seja a expressão de decltype produz, e não realiza em si a dedução do tipo.

## <a name="function-local-variables"></a>Função variáveis locais

Uma variável que é declarada dentro de um corpo de função é chamada de *variável local* ou simplesmente *local*. Os locais não estáticos só são visíveis dentro do corpo de função e, se forem declarados na pilha, saem do escopo quando a função sai. Quando você constrói uma variável local e a devolve por valor, o compilador geralmente pode executar a *otimização de valor de retorno nomeada* para evitar operações de cópia desnecessárias. Se você retornar uma variável local por referência, o compilador emitirá um aviso porque qualquer tentativa do chamador de usar essa referência ocorrerá após a destruição do local.

Em C++ uma variável local pode ser declarada como estática. A variável só é visível dentro do corpo da função, mas existe uma única cópia da variável para todas as instâncias da função. Os objetos estáticos locais são destruídos durante o término especificado por `atexit`. Se um objeto estático não foi construído porque o fluxo de programa do controle ignorou a declaração dele, nenhuma tentativa de destruição de objeto será feita.

## <a name="type-deduction-in-return-types-c14"></a><a name="type_deduction"></a>Dedução de tipo em tipos de devolução (C++14)

Em C++14, você pode usar **o automático** para instruir o compilador a inferir o tipo de retorno do corpo da função sem ter que fornecer um tipo de retorno de arrasto. Observe que **o auto** sempre deduz para um retorno por valor. Use `auto&&` para instruir o compilador a deduzir uma referência.

Neste exemplo, **o auto** será deduzido como uma cópia de valor não const da soma de lhs e rhs.

```cpp
template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs; //returns a non-const object by value
}
```

Observe que **o auto** não preserva o const-ness do tipo que deduz. Para funções de encaminhamento cujo valor de retorno precisa preservar o const-ness ou ref-ness de seus argumentos, você pode usar a palavra-chave **decltype (auto),** que usa as regras de inferência do tipo **de cltype** e preserva todas as informações do tipo. **decltype(auto)** pode ser usado como um valor de retorno comum no lado esquerdo, ou como um valor de retorno em arrasto.

O exemplo a seguir (baseado no código de [N3493),](https://wg21.link/n3493)mostra **o decltype (auto)** sendo usado para permitir o encaminhamento perfeito de argumentos de função em um tipo de retorno que não é conhecido até que o modelo seja instanciado.

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
```

## <a name="returning-multiple-values-from-a-function"></a><a name="multi_val"></a>Retornando múltiplos valores de uma função

Existem várias maneiras de retornar mais de um valor de uma função:

1. Encapsular os valores em um objeto de estrutura ou de estrutura nomeada. Requer que a definição de classe ou estrutura seja visível ao chamador:

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

1. Retornar um std::tuple ou std::pobjeto de ar:

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

1. **Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std:c++17](../build/reference/std-specify-language-standard-version.md)): Use amarras estruturadas. A vantagem das ligações estruturadas é que as variáveis que armazenam os valores de retorno são inicializadas ao mesmo tempo em que são declaradas, o que em alguns casos pode ser significativamente mais eficiente. Nesta declaração`auto[x, y, z] = f();`,--- os suportes introduzem e inicializam nomes que estão no escopo de todo o bloco de funções.

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

1. Além de usar o próprio valor de retorno, você pode "retornar" valores definindo qualquer número de parâmetros para usar pass-by-reference para que a função possa modificar ou inicializar os valores dos objetos que o chamador fornece. Para obter mais informações, consulte [Argumentos de função de tipo de referência](reference-type-function-arguments.md).

## <a name="function-pointers"></a>Ponteiros de função

C++ suporta ponteiros de função da mesma maneira que a linguagem C. No entanto, uma alternativa mais segura de tipo é geralmente usar um objeto de função.

Recomenda-se que **o typedef** seja usado para declarar um alias para o tipo de ponteiro de função se declarar uma função que retorna um tipo de ponteiro de função.  Por exemplo

```cpp
typedef int (*fp)(int);
fp myFunction(char* s); // function returning function pointer
```

Se isso não for feito, a sintaxe adequada para a declaração de função pode ser deduzida da sintaxe do declarador para o ponteiro de função substituindo o identificador (`fp` no exemplo acima) pelo nome das funções e a lista de argumentos, como segue:

```cpp
int (*myFunction(char* s))(int);
```

A declaração anterior é equivalente à declaração que usa typedef acima.

## <a name="see-also"></a>Confira também

[Sobrecarga de função](../cpp/function-overloading.md)<br/>
[Funções com listas de argumentos variáveis](../cpp/functions-with-variable-argument-lists-cpp.md)<br/>
[Funções explicitamente usadas como padrão e excluídas](../cpp/explicitly-defaulted-and-deleted-functions.md)<br/>
[Pesquisa de nome dependente de argumento (Koenig) em funções](../cpp/argument-dependent-name-koenig-lookup-on-functions.md)<br/>
[Argumentos padrão](../cpp/default-arguments.md)<br/>
[Funções inline](../cpp/inline-functions-cpp.md)
