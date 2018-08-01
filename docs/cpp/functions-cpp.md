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
ms.openlocfilehash: 25172bc44c21fcb11ec3f7c77224d3214e21c5f2
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404604"
---
# <a name="functions-c"></a>Funções (C++)

Uma função é um bloco de código que executa alguma operação. Uma função pode, opcionalmente, definir parâmetros de entrada que permitem que os chamadores passar argumentos para a função. Uma função pode, opcionalmente, retornar um valor como saída. Funções são úteis para encapsular operações comuns em um único bloco reutilizável, de preferência com um nome que descreva claramente que a função faz. A função a seguir aceita dois inteiros de um chamador e retorna sua soma; *uma* e *b* são *parâmetros* do tipo **int**.

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

A função pode ser invocada, ou *chamado*, de qualquer número de lugares no programa. Os valores que são passados para a função são as *argumentos*, cujos tipos devem ser compatíveis com os tipos de parâmetro na definição de função.

```cpp
int main()
{
    int i = sum(10, 32);
    int j = sum(i, 66);
    cout << "The value of j is" << j << endl; // 108
}
```

Não há nenhum limite prático para o comprimento da função, mas um bom design tem como objetivo para funções que executam uma única tarefa bem definida. Algoritmos complexos devem ser divididos em fáceis de entender mais simples funções sempre que possível.

Funções que são definidas no escopo da classe são chamadas de funções de membro. No C++, ao contrário de outras linguagens, uma função também pode ser definida no escopo do namespace (incluindo o namespace global implícito). Essas funções são chamadas *funções livres* ou *funções não membro*; elas são usadas amplamente na biblioteca padrão.

Funções podem ser *sobrecarregados*, que significa que diferentes versões de uma função pode compartilhar o mesmo nome se eles diferem por número e/ou tipo de parâmetros formais. Para obter mais informações, consulte [sobrecarregamento de função](../cpp/function-overloading.md).

## <a name="parts-of-a-function-declaration"></a>Partes de uma declaração de função

Uma função mínima *declaração* consiste o tipo de retorno, o nome da função e a lista de parâmetros (que pode estar vazia), juntamente com as palavras-chave opcional que fornecem instruções adicionais para o compilador. O exemplo a seguir é uma declaração de função:

```cpp
int sum(int a, int b);
```

Uma definição de função consiste em uma declaração, mais as *corpo*, que é todo o código entre chaves:

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

Uma declaração de função seguida por um ponto e vírgula pode aparecer em vários locais em um programa. Ele deve aparecer antes de qualquer chamada para essa função em cada unidade de conversão. A definição da função deve aparecer apenas uma vez no programa de acordo com a regra de definição de um (ODR).

As partes necessárias de uma declaração de função são:

1. O tipo de retorno, que especifica o tipo do valor que retorna a função, ou **void** se nenhum valor é retornado. No c++11, **automática** é um tipo de retorno válido que instrui o compilador a inferir o tipo da instrução return. No C++ 14, decltype (Auto) também é permitido. Para obter mais informações, consulte a dedução de tipo em tipos de retorno abaixo.

1. O nome de função, que deve começar com uma letra ou sublinhado e não pode conter espaços. Em geral, sublinhados em nomes de função de biblioteca padrão indicam as funções de membro particular ou funções não membro que não são destinadas para usam por seu código.

1. Lista de parâmetros, uma chave delimitado, separada por vírgulas de conjunto de zero ou mais parâmetros que especificam o tipo e, opcionalmente, um nome local pelo qual os valores podem ser acessados dentro do corpo da função.

Partes opcionais de uma declaração de função são:

1. `constexpr`, que indica que o valor de retorno da função é um valor constante pode ser calculado em tempo de compilação.

    ```cpp
    constexpr float exp(float x, int n)
    {
        return n == 0 ? 1 :
            n % 2 == 0 ? exp(x * x, n / 2) :
            exp(x * x, (n - 1) / 2) * x;
    };
    ```

1. Sua especificação de vinculação **extern** ou **estático**.

    ```cpp
    //Declare printf with C linkage.
    extern "C" int printf( const char *fmt, ... );

    ```

     Para obter mais informações, consulte [programa e ligação](../cpp/program-and-linkage-cpp.md).

1. **embutido**, que instrui o compilador substitua cada chamada para a função com o código de função em si. inlining pode ajudar o desempenho em cenários em que uma função é executada rapidamente e é invocada repetidamente em uma seção crítica de desempenho do código.

    ```cpp
    inline double Account::GetBalance()
    {
        return balance;
    }
    ```

     Para obter mais informações, consulte [funções embutidas](../cpp/inline-functions-cpp.md).

1. Um `noexcept` expressão, que especifica se a função pode gerar uma exceção. No exemplo a seguir, a função não gera uma exceção se o `is_pod` expressão é avaliada como **verdadeiro**.

    ```cpp
    #include <type_traits>

    template <typename T>
    T copy_object(T& obj) noexcept(std::is_pod<T>) {...}
    ```

     Para obter mais informações, consulte [noexcept](../cpp/noexcept-cpp.md).

1. (Somente para funções de membro) Os qualificadores cv, que especifica se a função é **const** ou **volátil**.

1. (Somente para funções de membro) **virtual**, `override`, ou `final`. **virtual** Especifica que uma função pode ser substituída em uma classe derivada. `override` significa que uma função em uma classe derivada é uma função virtual de substituição. `final` significa que uma função não pode ser substituída ainda mais em qualquer classe derivada. Para obter mais informações, consulte [funções virtuais](../cpp/virtual-functions.md).

1. (somente para funções de membro) **estático** aplicado a um membro da função significa que a função não está associada com qualquer instância de objeto da classe.

1. (Somente para funções de membro não estático) O qualificador de referência, que especifica para o compilador qual sobrecarga de uma função para escolher quando o parâmetro de objeto implícitos (\*isso) é uma referência de rvalue vs. uma referência de lvalue. Para obter mais informações, consulte [sobrecarregamento de função](function-overloading.md#ref-qualifiers).

A figura a seguir mostra as partes de uma definição de função. A área sombreada é o corpo da função.

 ![Partes de uma definição de função](../cpp/media/vc38ru1.gif "vc38RU1") partes de uma definição de função

## <a name="function-definitions"></a>Definições de função

Um *definição de função* consiste de declaração e o corpo da função, entre chaves, que contém declarações de variáveis, expressões e instruções. O exemplo a seguir mostra uma definição de função completos:

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

As variáveis declaradas dentro do corpo são chamadas de variáveis locais ou variáveis locais. Eles saem do escopo quando a função for encerrada; Portanto, uma função nunca deve retornar uma referência a um local!

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

Você pode declarar uma função de membro como **const** para especificar que a função não tem permissão para alterar os valores de todos os membros de dados na classe. Ao declarar uma função de membro como **const**, você ajuda o compilador imponha *exatidão de const*. Se alguém por engano tenta modificar o objeto usando uma função declarada como **const**, será gerado um erro do compilador. Para obter mais informações, consulte [const](const-cpp.md).

Declarar uma função como `constexpr` quando o valor que ele produz pode possivelmente ser determinada no tempo de compilação. Uma função constexpr geralmente é executada mais rapidamente do que uma função regular. Para obter mais informações, consulte [constexpr](constexpr-cpp.md).

## <a name="function-templates"></a>Modelos de função

Um modelo de função é semelhante a um modelo de classe; ele gera funções concretas com base nos argumentos de modelo. Em muitos casos, o modelo é capaz de inferir os argumentos de tipo e, portanto, não é necessário especificá-los explicitamente.

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

Uma função tem uma lista de parâmetros separados por vírgulas de zero ou mais tipos, cada um deles tem um nome pelo qual ele pode ser acessado dentro do corpo da função. Um modelo de função pode especificar parâmetros adicionais de tipo ou valor. O chamador passa os argumentos, que são valores concretos cujos tipos são compatíveis com a lista de parâmetros.

Por padrão, os argumentos são passados para a função por valor, o que significa que a função recebe uma cópia do objeto que está sendo passado. Para objetos grandes, fazendo uma cópia pode ser caro e nem sempre é necessário. Para fazer com que os argumentos a serem passados por referência (referência de lvalue especificamente), adicione um quantificador de referência para o parâmetro:

```cpp
void DoSomething(std::string& input){...}
```

Quando uma função modifica um argumento que é passado por referência, ele modifica o objeto original, não uma cópia local. Para impedir que uma função de modificação de um argumento, qualifique o parâmetro como const &:

```cpp
void DoSomething(const std::string& input){...}
```

 **C++ 11:** para manipular explicitamente os argumentos são passados por referência de rvalue ou referência de lvalue, use um duplo e comercial no parâmetro para indicar uma referência universal:

```cpp
void DoSomething(const std::string&& input){...}
```

Uma função declarada com a palavra-chave única **void** na declaração do parâmetro lista não utiliza argumentos, contanto que a palavra-chave **void** é o primeiro e o único membro da lista de argumentos de declaração. Argumentos de tipo **void** em outro lugar da lista gera erros. Por exemplo:

```cpp

// OK same as GetTickCount()
long GetTickCount( void );
```

Observe que, embora seja ilegal especificar um **void** argumento, exceto conforme descrito aqui, tipos derivados do tipo **void** (como ponteiros para **void** e matrizes de **void**) pode aparecer em qualquer lugar a lista de declarações de argumento.

### <a name="default-arguments"></a>Argumentos padrão

O último parâmetro ou parâmetros em uma assinatura de função podem ser atribuídos um argumento padrão, o que significa que o chamador pode deixar o argumento ao chamar a função, a menos que eles desejam especificar algum outro valor.

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

Uma função não pode retornar outra função, ou uma matriz interna; No entanto, ele pode retornar ponteiros para esses tipos, ou um *lambda*, que produz um objeto de função. Exceto para esses casos, uma função pode retornar um valor de qualquer tipo que está no escopo, ou não pode retornar nenhum valor, nesse caso, o tipo de retorno será **void**.

### <a name="trailing-return-types"></a>Tipos de retorno à direita

Um tipo de retorno "comum" está localizado no lado esquerdo da assinatura de função. Um *tipo de retorno à direita* está localizado no lado mais à direita da assinatura e é precedido pelo operador ->. Tipos de retorno à direita são especialmente úteis em modelos de função quando o tipo do valor de retorno depende de parâmetros de modelo.

```cpp
template<typename Lhs, typename Rhs>
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
```

Quando **automática** é usado em conjunto com um tipo de retorno à direita, ele simplesmente serve como um espaço reservado para qualquer expressão decltype produz, e não em si faz a dedução de tipo.


## <a name="function-local-variables"></a>Variáveis locais de função

Uma variável que é declarada dentro de um corpo de função é chamada uma *variável local* ou simplesmente *local*. Locais de não-estático visíveis apenas dentro do corpo de função e, se eles são declarados na pilha saem do escopo quando a função for encerrada. Quando você construir uma variável local e retorná-la por valor, o compilador normalmente pode executar a otimização de valor de retorno para evitar operações de cópia desnecessárias. Se você retornar uma variável local por referência, o compilador emitirá um aviso, pois qualquer tentativa de usar essa referência pelo chamador ocorrerá depois que o local foi destruído.

No C++ uma variável local pode ser declarada como estática. A variável só é visível dentro do corpo de função, mas existe uma única cópia da variável para todas as instâncias da função. Os objetos estáticos locais são destruídos durante o término especificado por `atexit`. Se um objeto estático não foi construído porque o fluxo de programa do controle ignorou a declaração dele, nenhuma tentativa de destruição de objeto será feita.

##  <a name="type_deduction"></a> Dedução de tipo em tipos de retorno (c++14)

No C++ 14, você pode usar **automática** para instruir o compilador a inferir o tipo de retorno do corpo da função sem ter que fornecer um tipo de retorno à direita. Observe que **automática** sempre deduz a um retorno de por valor. Use `auto&&` para instruir o compilador a deduzir uma referência.

Neste exemplo, **automática** será deduzido como uma cópia do valor não constante da soma do lhs e rhs.

```cpp
template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs; //returns a non-const object by value
}
```

Observe que **automática** não preserva a qualidade de const do tipo deduz por ele. Para funções cujo valor de retorno precisa preservar a qualidade de const ou ref-ness de seus argumentos de encaminhamento, você pode usar o **decltype (Auto)** palavra-chave, que usa o **decltype** regras de inferência de tipo e preserva todas as informações de tipo. **decltype (Auto)** pode ser usado como um valor de retorno comum no lado esquerdo ou como um valor de retorno à direita.

O exemplo a seguir (com base no código do [N3493](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2013/n3493.html)), mostra **decltype (Auto)** que está sendo usado para habilitar o encaminhamento perfeito dos argumentos de função em um tipo de retorno não é conhecido até que o modelo é criar uma instância.

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

Há várias maneiras de retornar mais de um valor de uma função:

1. Encapsule os valores em um objeto de classe ou struct nomeado. Requer a definição de classe ou struct fique visível para o chamador:

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
    
1. Retorne um objeto std:: Tuple ou std:

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

1. **Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): uso estruturado de associações. A vantagem de associações estruturadas é que as variáveis que armazenam os valores de retorno são inicializadas ao mesmo tempo em que são declarados, que, em alguns casos pode ser significativamente mais eficiente. Nesta instrução –`auto[x, y, z] = f();`– os colchetes introduzir e inicializar nomes que estão no escopo para o bloco de função inteira.

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
    
1. Além de usar o valor de retorno, você pode "return" valores com a definição de qualquer número de parâmetros para usar passagem por referência, para que a função possa modificar ou inicializar os valores dos objetos que fornece o chamador. Para obter mais informações, consulte [argumentos de função do tipo de referência](reference-type-function-arguments.md).

## <a name="function-pointers"></a>Ponteiros de função

C++ oferece suporte a ponteiros de função da mesma maneira que a linguagem C. No entanto uma alternativa mais tipo seguro é normalmente usar um objeto de função.

É recomendável que **typedef** ser usada para declarar um alias para o tipo de ponteiro de função se declarar uma função que retorna um tipo de ponteiro de função.  Por exemplo

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
 [Sobrecarga de função](../cpp/function-overloading.md)  
 [Funções com listas de argumentos variáveis](../cpp/functions-with-variable-argument-lists-cpp.md)  
 [Funções explicitamente usadas como padrão e excluídas](../cpp/explicitly-defaulted-and-deleted-functions.md)  
 [Pesquisa de nome dependente de argumento (Koenig) em funções](../cpp/argument-dependent-name-koenig-lookup-on-functions.md)  
 [Argumentos padrão](../cpp/default-arguments.md)  
 [Funções Embutidas](../cpp/inline-functions-cpp.md)
