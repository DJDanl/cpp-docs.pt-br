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
ms.openlocfilehash: da30d647947e98146cd89f255c2e05991c1be562
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301503"
---
# <a name="functions-c"></a>Funções (C++)

Uma função é um bloco de código que executa alguma operação. Uma função pode, opcionalmente, definir parâmetros de entrada que permitem aos chamadores passar argumentos para a função. Uma função pode, opcionalmente, retornar um valor como saída. As funções são úteis para encapsular operações comuns em um único bloco reutilizável, idealmente com um nome que descreve claramente o que a função faz. A função a seguir aceita dois inteiros de um chamador e retorna sua soma; *a* e *b* são *parâmetros* do tipo **int**.

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

A função pode ser invocada, ou *chamada*, de qualquer número de locais no programa. Os valores que são passados para a função são os *argumentos*, cujos tipos devem ser compatíveis com os tipos de parâmetro na definição de função.

```cpp
int main()
{
    int i = sum(10, 32);
    int j = sum(i, 66);
    cout << "The value of j is" << j << endl; // 108
}
```

Não há nenhum limite prático para o comprimento da função, mas bom design visa funções que executam uma única tarefa bem definida. Algoritmos complexos devem ser divididos em funções simples e fáceis de entender, sempre que possível.

As funções definidas no escopo de classe são chamadas de funções de membro. No C++, ao contrário de outras linguagens, uma função também pode ser definida no escopo do namespace (incluindo o namespace global implícito). Essas funções são chamadas de funções *gratuitas* ou *de funções que não são de membro*; Eles são usados extensivamente na biblioteca padrão.

As funções podem estar *sobrecarregadas*, o que significa que versões diferentes de uma função podem compartilhar o mesmo nome se diferirem pelo número e/ou tipo de parâmetros formais. Para obter mais informações, consulte [sobrecarga de função](../cpp/function-overloading.md).

## <a name="parts-of-a-function-declaration"></a>Partes de uma declaração de função

Uma *declaração* de função mínima consiste no tipo de retorno, nome da função e lista de parâmetros (que pode estar vazio), juntamente com palavras-chave opcionais que fornecem instruções adicionais ao compilador. O exemplo a seguir é uma declaração de função:

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

Uma declaração de função seguida por um ponto-e-vírgula pode aparecer em vários lugares em um programa. Ele deve aparecer antes de qualquer chamada para essa função em cada unidade de tradução. A definição da função deve aparecer apenas uma vez no programa, de acordo com a regra de definição única (ODR).

As partes necessárias de uma declaração de função são:

1. O tipo de retorno, que especifica o tipo do valor que a função retorna, ou **void** se nenhum valor for retornado. No C++ 11, **auto** é um tipo de retorno válido que instrui o compilador a inferir o tipo da instrução return. No C++ 14, o decltype (auto) também é permitido. Para obter mais informações, consulte dedução de tipo em tipos de retorno abaixo.

1. O nome da função, que deve começar com uma letra ou sublinhado e não pode conter espaços. Em geral, os sublinhados à esquerda nos nomes de função de biblioteca padrão indicam funções de membro privado ou funções não-membro que não se destinam ao uso pelo seu código.

1. A lista de parâmetros, uma chave delimitada, um conjunto separado por vírgulas de zero ou mais parâmetros que especificam o tipo e, opcionalmente, um nome local pelo qual os valores podem ser acessados dentro do corpo da função.

As partes opcionais de uma declaração de função são:

1. `constexpr`, que indica que o valor de retorno da função é um valor constante pode ser calculado em tempo de compilação.

    ```cpp
    constexpr float exp(float x, int n)
    {
        return n == 0 ? 1 :
            n % 2 == 0 ? exp(x * x, n / 2) :
            exp(x * x, (n - 1) / 2) * x;
    };
    ```

1. Sua especificação de vinculação, **externa** ou **estática**.

    ```cpp
    //Declare printf with C linkage.
    extern "C" int printf( const char *fmt, ... );

    ```

   Para obter mais informações, consulte [unidades de tradução e ligação](../cpp/program-and-linkage-cpp.md).

1. **embutido**, que instrui o compilador a substituir cada chamada à função pelo próprio código de função. o inalinhamento pode ajudar o desempenho em cenários em que uma função é executada rapidamente e é invocada repetidamente em uma seção de código crítica de desempenho.

    ```cpp
    inline double Account::GetBalance()
    {
        return balance;
    }
    ```

   Para obter mais informações, consulte [funções embutidas](../cpp/inline-functions-cpp.md).

1. Uma expressão `noexcept`, que especifica se a função pode ou não gerar uma exceção. No exemplo a seguir, a função não lançará uma exceção se a expressão de `is_pod` for avaliada como **true**.

    ```cpp
    #include <type_traits>

    template <typename T>
    T copy_object(T& obj) noexcept(std::is_pod<T>) {...}
    ```

   Para obter mais informações, consulte [noexcept](../cpp/noexcept-cpp.md).

1. (Somente funções de membro) Os qualificadores CV, que especificam se a função é **const** ou **volátil**.

1. (Somente funções de membro) **virtual**, `override`ou `final`. **virtual** especifica que uma função pode ser substituída em uma classe derivada. `override` significa que uma função em uma classe derivada está substituindo uma função virtual. `final` significa que uma função não pode ser substituída em nenhuma classe derivada adicional. Para obter mais informações, consulte [funções virtuais](../cpp/virtual-functions.md).

1. (somente funções de membro) o **estático** aplicado a uma função de membro significa que a função não está associada a nenhuma instância de objeto da classe.

1. (Somente funções membro não estáticas) O qualificador de referência, que especifica para o compilador que sobrecarga de uma função escolher quando o parâmetro de objeto implícito (\*isso) é uma referência rvalue versus uma referência lvalue. Para obter mais informações, consulte [sobrecarga de função](function-overloading.md#ref-qualifiers).

A figura a seguir mostra as partes de uma definição de função. A área sombreada é o corpo da função.

![Partes de uma definição de função](../cpp/media/vc38ru1.gif "Partes de uma definição de função") <br/>
Partes de uma definição de função

## <a name="function-definitions"></a>Definições de função

Uma *definição de função* consiste na declaração e no corpo da função, entre chaves, que contém declarações de variáveis, instruções e expressões. O exemplo a seguir mostra uma definição de função completa:

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

Variáveis declaradas dentro do corpo são chamadas de variáveis locais ou locais. Eles saem do escopo quando a função é encerrada; Portanto, uma função nunca deve retornar uma referência a um local!

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

Você pode declarar uma função de membro como **const** para especificar que a função não tem permissão para alterar os valores de quaisquer membros de dados na classe. Ao declarar uma função de membro como **const**, você ajuda o compilador a impor a *exatidão da constante*. Se alguém tentar modificar o objeto por engano usando uma função declarada como **const**, um erro do compilador será gerado. Para obter mais informações, consulte [const](const-cpp.md).

Declare uma função como `constexpr` quando o valor que ele produz pode ser determinado em tempo de compilação. Uma função constexpr geralmente é executada mais rapidamente do que uma função regular. Para obter mais informações, consulte [constexpr](constexpr-cpp.md).

## <a name="function-templates"></a>Modelos de função

Um modelo de função é semelhante a um modelo de classe; Ele gera funções concretas com base nos argumentos do modelo. Em muitos casos, o modelo é capaz de inferir os argumentos de tipo e, portanto, não é necessário especificá-los explicitamente.

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

## <a name="function-parameters-and-arguments"></a>Parâmetros de função e argumentos

Uma função tem uma lista de parâmetros separados por vírgulas de zero ou mais tipos, cada um com um nome pelo qual ele pode ser acessado dentro do corpo da função. Um modelo de função pode especificar parâmetros de tipo ou valor adicionais. O chamador passa argumentos, que são valores concretos cujos tipos são compatíveis com a lista de parâmetros.

Por padrão, os argumentos são passados para a função por valor, o que significa que a função recebe uma cópia do objeto que está sendo passado. Para objetos grandes, fazer uma cópia pode ser caro e nem sempre é necessário. Para fazer com que os argumentos sejam passados por referência (especificamente referência lvalue), adicione um quantificador de referência ao parâmetro:

```cpp
void DoSomething(std::string& input){...}
```

Quando uma função modifica um argumento que é passado por referência, ela modifica o objeto original, não uma cópia local. Para impedir que uma função modifique tal argumento, qualifique o parâmetro como const &:

```cpp
void DoSomething(const std::string& input){...}
```

**C++ 11:**  Para manipular explicitamente argumentos que são passados por rvalue-Reference ou lvalue-Reference, use um e comercial duplo no parâmetro para indicar uma referência universal:

```cpp
void DoSomething(const std::string&& input){...}
```

Uma função declarada com a palavra-chave Single **void** na lista de declarações de parâmetro não usa argumentos, desde que a palavra-chave **void** seja o primeiro e único membro da lista de declarações de argumento. Os argumentos do tipo **void** em outro lugar na lista produzem erros. Por exemplo:

```cpp

// OK same as GetTickCount()
long GetTickCount( void );
```

Observe que, embora seja ilegal especificar um argumento **void** , exceto como descrito aqui, os tipos derivados do tipo **void** (como ponteiros para **void** e matrizes de **void**) podem aparecer em qualquer lugar da lista de declaração de argumento.

### <a name="default-arguments"></a>Argumentos padrão

O último parâmetro ou parâmetros em uma assinatura de função pode ser atribuído a um argumento padrão, o que significa que o chamador pode deixar o argumento ao chamar a função, a menos que queira especificar algum outro valor.

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

Uma função pode não retornar outra função ou uma matriz interna; no entanto, ele pode retornar ponteiros para esses tipos ou um *lambda*, que produz um objeto de função. Exceto para esses casos, uma função pode retornar um valor de qualquer tipo que esteja no escopo ou pode não retornar nenhum valor; nesse caso, o tipo de retorno é **void**.

### <a name="trailing-return-types"></a>Tipos de retorno à direita

Um tipo de retorno "comum" está localizado no lado esquerdo da assinatura da função. Um *tipo de retorno à* direita está localizado no lado direito da assinatura e é precedido pelo operador->. Os tipos de retorno à direita são especialmente úteis em modelos de função quando o tipo de valor de retorno depende de parâmetros de modelo.

```cpp
template<typename Lhs, typename Rhs>
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
```

Quando **auto** é usado em conjunto com um tipo de retorno à direita, ele serve apenas como um espaço reservado para qualquer coisa que a expressão decltype produz e não executa a dedução de tipo.

## <a name="function-local-variables"></a>Variáveis locais de função

Uma variável que é declarada dentro de um corpo de função é chamada de *variável local* ou simplesmente um *local*. Locais não estáticos só são visíveis dentro do corpo da função e, se eles forem declarados na pilha, saem do escopo quando a função é encerrada. Quando você constrói uma variável local e a retorna por valor, o compilador geralmente pode executar a *otimização do valor de retorno nomeado* para evitar operações de cópia desnecessárias. Se você retornar uma variável local por referência, o compilador emitirá um aviso porque qualquer tentativa feita pelo chamador para usar essa referência ocorrerá depois que o local for destruído.

Em C++ uma variável local pode ser declarada como estática. A variável só é visível dentro do corpo da função, mas existe uma única cópia da variável para todas as instâncias da função. Os objetos estáticos locais são destruídos durante o término especificado por `atexit`. Se um objeto estático não foi construído porque o fluxo de programa do controle ignorou a declaração dele, nenhuma tentativa de destruição de objeto será feita.

##  <a name="type_deduction"></a>Dedução de tipo em tipos de retorno (C++ 14)

No C++ 14, você pode usar **auto** para instruir o compilador a inferir o tipo de retorno do corpo da função sem precisar fornecer um tipo de retorno à direita. Observe que **auto** sempre é deduzido para um retorno por valor. Use `auto&&` para instruir o compilador a deduzir uma referência.

Neste exemplo, **auto** será deduzido como uma cópia de valor não const da soma de LHS e RHS.

```cpp
template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs; //returns a non-const object by value
}
```

Observe que **auto** não preserva o const-qualidade do tipo que ele deduz. Para funções de encaminhamento cujo valor de retorno precisa preservar o const-qualidade ou ref-qualidade de seus argumentos, você pode usar a palavra-chave **decltype (auto)** , que usa as regras de inferência de tipo **decltype** e preserva todas as informações de tipo. **decltype (auto)** pode ser usado como um valor de retorno comum no lado esquerdo ou como um valor de retorno à direita.

O exemplo a seguir (com base no código de [N3493](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2013/n3493.html)), mostra o **decltype (auto)** que está sendo usado para habilitar o encaminhamento perfeito de argumentos de função em um tipo de retorno que não é conhecido até que o modelo seja instanciado.

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

## <a name="multi_val"></a>Retornando vários valores de uma função

Há várias maneiras de retornar mais de um valor de uma função:

1. Encapsula os valores em uma classe nomeada ou objeto de struct. Requer que a definição de classe ou estrutura seja visível para o chamador:

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

1. Retornar um objeto std:: tupla ou std::p Air:

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

1. **Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): Use associações estruturadas. A vantagem das associações estruturadas é que as variáveis que armazenam os valores de retorno são inicializadas ao mesmo tempo em que são declaradas, o que, em alguns casos, pode ser significativamente mais eficiente. Nesta instrução--`auto[x, y, z] = f();`--os colchetes apresentam e inicializam nomes que estão no escopo do bloco de função inteiro.

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

1. Além de usar o próprio valor de retorno, você pode "retornar" valores definindo qualquer número de parâmetros para usar passagem por referência para que a função possa modificar ou inicializar os valores dos objetos que o chamador fornece. Para obter mais informações, consulte [argumentos da função de tipo de referência](reference-type-function-arguments.md).

## <a name="function-pointers"></a>Ponteiros de função

C++dá suporte a ponteiros de função da mesma maneira que a linguagem C. No entanto, uma alternativa mais segura de tipo é geralmente usar um objeto de função.

É recomendável que **typedef** seja usado para declarar um alias para o tipo de ponteiro de função se declarar uma função que retorne um tipo de ponteiro de função.  Por exemplo

```cpp
typedef int (*fp)(int);
fp myFunction(char* s); // function returning function pointer
```

Se isso não for feito, a sintaxe adequada para a declaração de função pode ser deduzida da sintaxe do declarador para o ponteiro de função substituindo o identificador (`fp` no exemplo acima) pelo nome das funções e a lista de argumentos, como segue:

```cpp
int (*myFunction(char* s))(int);
```

A declaração anterior é equivalente à declaração que usa typedef acima.

## <a name="see-also"></a>Veja também

[Sobrecarga de função](../cpp/function-overloading.md)<br/>
[Funções com listas de argumentos variáveis](../cpp/functions-with-variable-argument-lists-cpp.md)<br/>
[Funções explicitamente usadas como padrão e excluídas](../cpp/explicitly-defaulted-and-deleted-functions.md)<br/>
[Pesquisa de nome dependente de argumento (Koenig) em funções](../cpp/argument-dependent-name-koenig-lookup-on-functions.md)<br/>
[Argumentos padrão](../cpp/default-arguments.md)<br/>
[Funções Embutidas](../cpp/inline-functions-cpp.md)
