---
title: Novidades do Visual C++ de 2003 até 2015
ms.date: 11/04/2016
ms.assetid: c4afde6f-3d75-40bf-986f-be57e3818e26
ms.openlocfilehash: bc0092aeb8910f960befc174c1f71ce05c4eb131
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54894348"
---
# <a name="visual-c-what39s-new-2003-through-2015"></a>Novidades do Visual C++ de 2003 até 2015

Esta página reúne todas as páginas de "Novidades" para todas as versões de Visual C++ do Visual Studio 2015, remontando a 2003. Essas informações são fornecidas como uma conveniência, caso possam ser úteis útil ao atualizar de versões anteriores do Visual C++.

> [!NOTE]
> Para obter informações sobre o Visual Studio 2017, consulte [Novidades do Visual C++ no Visual Studio 2017](../what-s-new-for-visual-cpp-in-visual-studio.md) e [Melhorias de conformidade no Visual C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md).

## <a name="whats-new-for-c-in-visual-studio-2015"></a>Novidades do C++ no Visual Studio 2015

No Visual Studio 2015 e posterior, as melhorias contínuas na conformidade do compilador podem, às vezes, alterar a forma pela qual o compilador entende o código-fonte existente. Quando isso acontecer, você poderá encontrar erros novos ou diferentes durante o build ou até diferenças de comportamento no código que foi compilado anteriormente e parecia executar corretamente.

Felizmente, essas diferenças têm pouco ou nenhum impacto sobre a maior parte do código-fonte e quando as alterações de código-fonte ou outras alterações são necessárias para resolver essas diferenças, as correções geralmente são pequenas e descomplicadas. Incluímos muitos exemplos de código-fonte que eram aceitáveis e que, talvez, precisem ser alterados *(antes)* e as correções para corrigi-los *(depois)*.

Embora essas diferenças podem afetar seu código-fonte ou outros artefatos de build, elas não afetam a compatibilidade binária entre as atualizações de versões do Visual C++. Um tipo mais grave de alteração, ao *alteração significativa* pode afetar a compatibilidade binária, mas esses tipos de interrupções de compatibilidade binária ocorrem somente entre as versões principais do Visual C++. Por exemplo, entre o Visual C++ 2013 e Visual C++ 2015. Para obter informações sobre as alterações significativas que ocorreram entre o Visual C++ 2013 e o Visual C++ 2015, consulte [Histórico de alterações do Visual C++ de 2003 a 2015](../porting/visual-cpp-change-history-2003-2015.md).

- [Melhorias de conformidade no Visual Studio 2015](#VS_RTM)

- [Melhorias de conformidade no Visual Studio 2015 – Atualização 1](#VS_Update1)

- [Melhorias de conformidade no Visual Studio 2015 – Atualização 2](#VS_Update2)

- [Melhorias de conformidade no Visual Studio 2015 – Atualização 3](#VS_Update3)

### <a name="VS_RTM"></a> Melhorias de conformidade no Visual Studio 2015

- **Opção /Zc:forScope-**

   A opção do compilador `/Zc:forScope-` foi preterida e será removida em uma versão futura.

   ```output
    Command line warning  D9035: option 'Zc:forScope-' has been deprecated and will be removed in a future release
   ```

   A opção foi comumente usada para permitir código não padrão que usa variáveis de loop após o momento em que deveriam ter saído do escopo, de acordo com o padrão. Ela só era necessária para compilar com a opção `/Za`, uma vez que sem `/Za`, o uso de uma variável for loop após o final do loop sempre é permitido. Se a conformidade com os padrões não for importante nesse caso (por exemplo, se o código não se destinar à portabilidade para outros compiladores), você poderá desabilitar a opção `/Za` (ou definir a propriedade **Desabilitar extensões de linguagem** como **Não**). Se você deseja escrever código portátil e em conformidade com os padrões, você deve reescrever o código, movendo a declaração de tais variáveis para um ponto fora do loop, para ficar em conformidade com o padrão.

   ```cpp
    // zc_forScope.cpp
    // compile with: /Zc:forScope- /Za
    // C2065 expected
    int main() {
       // Uncomment the following line to resolve.
       // int i;
       for (int i =0; i < 1; i++)
          ;
       i = 20;   // i has already gone out of scope under /Za
    }
   ```

- **Opção do compilador Zg.**

   A opção do compilador `/Zg` (Gerar Protótipos de Função) não está mais disponível. Essa opção do compilador foi anteriormente preterida.

- Não é possível executar testes de unidade com C++/CLI na linha de comando com mstest.exe. Em vez disso, use vstest.console.exe

- **palavra-chave mutável.**

   O especificador de classe de armazenamento **mutable** não é mais permitido em locais em que anteriormente era compilado sem erros. Agora, o compilador gera um erro C2071 (classe de armazenamento inválida). Segundo o padrão, o especificador mutable só pode ser aplicado a nomes de membros de dados de classe e não pode ser aplicado a nomes declarados const ou static e também não pode ser aplicado para fazer referência a membros.

   Por exemplo, considere o seguinte código:

   ```cpp
    struct S {
        mutable int &r;
    };
   ```

   Versões anteriores do compilador do Visual C++ aceitavam isso, mas agora o compilador retorna o seguinte erro:

   ```Output
    error C2071: 'S::r': illegal storage class
   ```

   Para corrigir o erro, basta remover a palavra-chave redundante **mutable**.

- **char_16_t e char32_t**

   Você não pode usar mais `char16_t` ou `char32_t` como aliases em um typedef, porque esses tipos agora são tratados como internos. É comum que usuários e autores de biblioteca definam `char16_t` e `char32_t` como aliases de `uint16_t` e `uint32_t`, respectivamente.

   ```cpp
    #include <cstdint>

    typedef uint16_t char16_t; //C2628
    typedef uint32_t char32_t; //C2628

    int main(int argc, char* argv[])
    {
    uint16_t x = 1; uint32_t y = 2;
    char16_t a = x;
    char32_t b = y;
    return 0;
    }
   ```

   Para atualizar o código, remova as declarações de **typedef** e renomeie todos os outros identificadores que estiverem em conflito com esses nomes.

- **Parâmetros de modelo de não tipo**

   Alguns códigos que envolvem os parâmetros de modelo de não tipo agora têm a compatibilidade de tipo corretamente verificada quando você fornece argumentos de modelo explícitos. Por exemplo, o seguinte código compilado sem erros nas versões anteriores do Visual C++.

   ```cpp
    struct S1
    {
        void f(int);
        void f(int, int);
    };

    struct S2
    {
        template <class C, void (C::*Function)(int) const> void f() {}
    };

    void f()
    {
        S2 s2;
        s2.f<S1, &S1::f>();
    }
   ```

   O compilador atual corretamente apresentará um erro, porque o tipo de parâmetro de modelo não corresponde ao argumento de modelo (o parâmetro é um ponteiro para um membro const, mas a função f é não const):

   ```Output
    error C2893: Failed to specialize function template 'void S2::f(void)'note: With the following template arguments:note: 'C=S1'note: 'Function=S1::f'
   ```

   Para resolver esse erro em seu código, verifique se o tipo do argumento de modelo que você usa corresponde ao tipo declarado do parâmetro do modelo.

- **__declspec(align)**

   O compilador não aceita mais `__declspec(align)` em funções. Isso sempre foi ignorado, mas agora produz um erro do compilador.

   ```cpp
    error C3323: 'alignas' and '__declspec(align)' are not allowed on function declarations
   ```

   Para corrigir esse problema, remova `__declspec(align)` da declaração da função. Uma vez que ela não tinha efeito, removê-la não altera nada.

- **Tratamento de exceções**

   Há algumas alterações para o tratamento de exceções. Primeiro, os objetos de exceção precisam ser copiáveis ou móveis. O código a seguir era compilado no Visual Studio 2013, mas não é compilado no Visual Studio 2015:

   ```cpp
    struct S {
    public:
        S();
    private:
        S(const S &);
    };

    int main()
    {
        throw S(); // error
    }
   ```

   O problema é que o construtor de cópia é particular, portanto o objeto não pode ser copiado como acontece no curso normal de tratamento de exceção. O mesmo se aplica quando o construtor de cópia é declarado como **explicit**.

   ```cpp
    struct S {
        S();
        explicit S(const S &);
    };

    int main()
    {
        throw S(); // error
    }
   ```

   Para atualizar o código, verifique se o construtor de cópia do objeto de exceção é público e não está marcado como **explicit**.

   A captura de uma exceção pelo valor também exige que o objeto de exceção seja copiável. O código a seguir era compilado no Visual Studio 2013, mas não é compilado no Visual Studio 2015:

   ```cpp
    struct B {
    public:
        B();
    private:
        B(const B &);
    };

    struct D : public B {
    };

    int main()
    {
        try
        {
        }
        catch (D d) // error
        {
        }
    }
   ```

   Você pode corrigir esse problema alterando o tipo de parâmetro de **catch** para uma referência.

   ```cpp
    catch(D& d)
    {
    }
   ```

- **Literais de cadeia de caracteres seguidos de macros**

   Agora o compilador oferece suporte a literais definidos pelo usuário. Como consequência, os literais de cadeia de caracteres seguidos de macros sem qualquer espaço em branco de intervenção são interpretados como literais definidos pelo usuário, o que pode causar erros ou resultados inesperados. Por exemplo, nos compiladores anteriores o seguinte código foi compilado com êxito:

   ```cpp
    #define _x "there"
    char* func() {
        return "hello"_x;
    }
    int main()
    {
        char * p = func();
        return 0;
    }
   ```

   O compilador interpretou isso como uma cadeia de caracteres literal "hello" seguida por uma macro, que é "there" expandida e, em seguida, os dois literais de cadeia de caracteres foram concatenados em um. No Visual Studio 2015, o compilador interpreta isso como um literal definido pelo usuário, mas como não há nenhum literal _x definido pelo usuário correspondente, ele gera um erro.

   ```cpp
    error C3688: invalid literal suffix '_x'; literal operator or literal operator template 'operator ""_x' not found
    note: Did you forget a space between the string literal and the prefix of the following string literal?

   ```

   Para corrigir esse problema, adicione um espaço entre o literal de cadeia de caracteres e a macro.

- **Literais de cadeia de caracteres adjacentes**

   Assim como os anteriores, devido a alterações na análise de cadeia de caracteres, os literais de cadeia de caracteres adjacentes (literais de cadeia de caracteres largos ou estreitos) sem nenhum espaço em branco foram interpretados como uma única cadeia de caracteres concatenada nas versões anteriores do Visual C++. No Visual Studio 2015, agora você precisa adicionar um espaço em branco entre as duas cadeias de caracteres. Por exemplo, o código a seguir deve ser alterado:

   ```cpp
    char * str = "abc""def";
   ```

   Basta adicionar um espaço entre as duas cadeias de caracteres.

   ```cpp
    char * str = "abc" "def";
   ```

- **Posicionamento de new e delete**

   Uma alteração foi feita no operador **delete** para colocá-lo em conformidade com o padrão C++14. Detalhes da alteração dos padrões podem ser encontrados em [Desalocação dimensionada de C++](http://isocpp.org/files/papers/n3778.html). As alterações adicionam uma forma do operador **delete** global que usa um parâmetro de tamanho. A alteração da falha é que, se você já estava usando um operador **delete** com a mesma assinatura (para corresponder a um operador **placement new**), ocorre um erro do compilador (C2956, que ocorre no ponto em que o **placement new** é usado, já que essa é a posição no código em que o compilador tenta identificar um operador **delete** correspondente apropriado).

   A função `void operator delete(void *, size_t)` era um operador **placement delete** correspondente à função **placement new** função `void * operator new(size_t, size_t)` no C++11. Com a desalocação dimensionada de C++14, essa função **delete** é agora uma *função de desalocação comum* (operador **delete** global). O padrão indica que, se o uso de um **placement new** procurar uma função **delete** correspondente e localizar uma função de desalocação comum, o programa estará mal formado.

   Por exemplo, suponha que seu código defina um **placement new** e um **placement delete**:

   ```cpp
    void * operator new(std::size_t, std::size_t);
    void operator delete(void*, std::size_t) noexcept;
   ```

   O problema ocorre devido à correspondência nas assinaturas de função entre um operador **placement delete** que você definiu e o novo operador **delete** de dimensionamento global. Considere se você pode usar um tipo diferente de `size_t` para operadores **placement new** e **delete**.  Observe que o tipo de **typedef** `size_t` depende do compilador. Trata-se de um **typedef** para **unsigned int** no Visual C++. Uma boa solução é usar um tipo enumerado como este:

   ```cpp
    enum class my_type : size_t {};
   ```

   Em seguida, altere sua definição de posicionamento **new** e **delete** use esse tipo como o segundo argumento, em vez de `size_t`. Você também precisará atualizar as chamadas a **placement new** para passar o novo tipo (por exemplo, usando `static_cast<my_type>` para converter do valor inteiro) e atualizar a definição de **new** e **delete** para retroceder ao tipo inteiro. Você não precisa usar uma **enumeração** para isso. Um tipo de uma classe com um membro `size_t` também funciona.

   Uma solução alternativa é que você poderá eliminar completamente o **placement new**. Se seu código usar **placement new** para implementar um pool de memória no qual o argumento de posicionamento é o tamanho do objeto que está sendo alocado ou excluído, o recurso de desalocação dimensionada poderá ser adequado para substituir seu próprio código de pool de memória personalizado e você poderá abandonar as funções de posicionamento e simplesmente usar seu próprio operador **delete** de dois argumentos em vez das funções de posicionamento.

   Se você não quiser atualizar o código imediatamente, reverta para o comportamento antigo usando a opção do compilador `/Zc:sizedDealloc-`. Se você usar essa opção, as funções **delete** de dois argumentos não existirão e não causarão conflito com o operador **placement delete**.

- **Membros de dados de união**

   Membros de dados de uniões não podem mais ter tipos de referência. O código a seguir era compilado com êxito no Visual Studio 2013, mas gera um erro no Visual Studio 2015.

   ```cpp
    union U1 {
        const int i;
    };
    union U2 {
       int &i;
    };
    union U3 {
        struct {int &i;};
    };
   ```

   O código anterior produz os seguintes erros:

   ```Output
    test.cpp(67): error C2625: 'U2::i': illegal union member; type 'int &' is reference type
    test.cpp(70): error C2625: 'U3::i': illegal union member; type 'int &' is reference type
   ```

   Para resolver esse problema, altere os tipos de referência para um ponteiro ou um valor. Alterar o tipo para um ponteiro exige alterações no código que usa o campo de união. Alterar o código para um valor alteraria os dados armazenados na união, o que afeta outros campos, pois os campos nos tipos de união compartilham a mesma memória. Dependendo do tamanho do valor, ele também pode alterar o tamanho da união.

- **Uniões anônimas**

   agora estão mais em conformidade com o padrão. As versões anteriores do compilador geravam um construtor e um destruidor explícitos de uniões anônimas. Eles foram excluídos no Visual Studio 2015.

   ```cpp
   struct S {
      S();
   };

   union {
      struct {
         S s;
      };
   } u; // C2280
   ```

   O código anterior gera o seguinte erro no Visual Studio 2015:

   ```cpp
    error C2280: '<unnamed-type-u>::<unnamed-type-u>(void)': attempting to reference a deleted function
    note: compiler has generated '<unnamed-type-u>::<unnamed-type-u>' here
   ```

   Para resolver esse problema, forneça suas próprias definições do construtor e/ou do destruidor.

   ```cpp
    struct S {
       // Provide a default constructor by adding an empty function body.
       S() {}
    };

    union {
       struct {
          S s;
       };
    } u;
   ```

- **Uniões com structs anônimos**

   Para entrar em conformidade com o padrão, o comportamento do tempo de execução foi alterado para membros de estruturas anônimas em uniões. O construtor para membros de estrutura anônima em uma união não é mais implicitamente chamado quando a união é criada. Além disso, o destruidor para membros de estrutura anônima em uma união não é mais implicitamente chamado quando a união sai do escopo. Considere o código a seguir, em que uma união U contém uma estrutura anônima que contém um membro que é uma estrutura nomeada S que tem um destruidor.

   ```cpp
    #include <stdio.h>
    struct S {
        S() { printf("Creating S\n"); }
        ~S(){ printf("Destroying S\n"); }
    };
    union U {
        struct {
        S s;
    };
        U() {}
        ~U(){}
    };

    void f()
    {
        U u;
        // Destructor implicitly called here.
    }

    int main()
    {
        f();

        char s[1024];
        printf("Press any key.\n");
        gets_s(s);
        return 0;
    }
   ```

   No Visual Studio 2013, o construtor para S é chamado quando a união é criada, e o destruidor para S é chamado quando a pilha da função f é limpa. Mas, no Visual Studio 2015, nem o construtor e nem o destruidor são chamados. O compilador dá um aviso sobre essa alteração de comportamento.

   ```Output
    warning C4587: 'U::s': behavior change: constructor is no longer implicitly calledwarning C4588: 'U::s': behavior change: destructor is no longer implicitly called
   ```

   Para restaurar o comportamento original, nomeie a estrutura anônima. O comportamento de tempo de execução de estruturas não anônimas é o mesmo, independentemente da versão do compilador.

   ```cpp
    #include <stdio.h>

    struct S {
        S() { printf("Creating S.\n"); }
        ~S() { printf("Destroying S\n"); }
    };
    union U {
        struct {
            S s;
        } namedStruct;
        U() {}
        ~U() {}
    };

    void f()
    {
        U u;
    }

    int main()
    {
        f();

        char s[1024];
        printf("Press any key.\n");
        gets_s(s);
        return 0;
    }
   ```

   Como alternativa, tente mover o código do construtor e do destruidor para novas funções e adicionar chamadas para essas funções do construtor e do destruidor da união.

   ```cpp
    #include <stdio.h>

    struct S {
        void Create() { printf("Creating S.\n"); }
        void Destroy() { printf("Destroying S\n"); }
    };
    union U {
        struct {
            S s;
        };
        U() { s.Create();  }
        ~U() { s.Destroy(); }
    };

    void f()
    {
        U u;
    }

    int main()
    {
        f();

    char s[1024];
    printf("Press any key.\n");
    gets_s(s);
    return 0;
    }
   ```

- **Resolução de modelo**

   Foram feitas alterações na resolução de nomes dos modelos. No C++, esse pode ser o caso de um ou mais nomes em consideração como correspondências possíveis causando uma instanciação de modelo inválida, ao considerar candidatos para a resolução de um nome. Essas instanciações inválidas normalmente não causam erros de compilador, um princípio que é conhecido como SFINAE (Substitution Failure Is Not An Error – Falha de substituição não é um erro).

   Agora, se o SFINAE exige que o compilador instancie a especialização de um modelo de classe, os erros que ocorrem durante esse processo são erros de compilador. Nas versões anteriores, o compilador ignoraria esses erros. Por exemplo, considere o seguinte código:

   ```cpp
    #include <type_traits>

    template<typename T>
    struct S
    {
    S() = default;
    S(const S&);
    S(S&&);

    template<typename U, typename = typename std::enable_if<std::is_base_of<T, U>::value>::type>
    S(S<U>&&);
    };

    struct D;

    void f1()
    {
    S<D> s1;
        S<D> s2(s1);
    }

    struct B
    {
    };

    struct D : public B
    {
    };

    void f2()
    {
    S<D> s1;
        S<D> s2(s1);
    }
   ```

   Se você compilar com o compilador atual, você obterá o seguinte erro:

   ```Output
    type_traits(1110): error C2139: 'D': an undefined class is not allowed as an argument to compiler intrinsic type trait '__is_base_of'
    ..\t331.cpp(14): note: see declaration of 'D'
    ..\t331.cpp(10): note: see reference to class template instantiation 'std::is_base_of<T,U>' being compiled
            with
            [
                T=D,
                U=D
            ]
   ```

   Isso ocorre porque no momento da primeira invocação de is_base_of, a classe 'D' ainda não foi definida.

   Nesse caso, a correção é não usar essas características de tipo até que a classe seja definida. Se você mover as definições de B e D para o início do arquivo de código, o erro será resolvido. Se as definições estiverem em arquivos de cabeçalho, verifique a ordem das instruções include dos arquivos de cabeçalho para certificar-se de que nenhuma definição de classe é compilada antes que os modelos problemáticos sejam usados.

- **Construtores de cópia**

   No Visual Studio 2013 e Visual Studio 2015, o compilador gera um construtor de cópia para uma classe quando essa classe tem um construtor de movimento definido pelo usuário, mas nenhum construtor de cópia definido pelo usuário. No Dev14, esse construtor de cópia implicitamente gerado também é marcado "= delete".

### <a name="VS_Update1"></a> Melhorias de conformidade no Visual Studio 2015 – Atualização 1

- **Classes base virtuais particulares e herança indireta**

   As versões anteriores do compilador permitiam que uma classe derivada chamasse funções membro de suas classes base *derivadas indiretamente*`private virtual`. Esse comportamento antigo estava incorreto e não estava em conformidade com o padrão C++. O compilador não aceita mais código escrito dessa maneira e emite o erro do compilador C2280 como resultado.

   ```Output
    error C2280: 'void *S3::__delDtor(unsigned int)': attempting to reference a deleted function
   ```

   Exemplo (antes)

   ```cpp
    class base
    {
    protected:
        base();
        ~base();
    };

    class middle: private virtual base {};class top: public virtual middle {};

    void destroy(top *p)
    {
        delete p;  //
    }
   ```

   Exemplo (depois)

   ```cpp
    class base;  // as above

    class middle: protected virtual base {};
    class top: public virtual middle {};

    void destroy(top *p)
    {
        delete p;
    }
   ```

  \-ou-

   ```cpp
    class base;  // as above

    class middle: private virtual base {};
    class top: public virtual middle, private virtual bottom {};

    void destroy(top *p)
    {
        delete p;
    }
   ```

- **Operador new sobrecarregado e operador delete**

   Versões anteriores do compilador permitiam que o não membro **operator new** e o não membro **operator delete** fossem declarados como estáticos e fossem declarados em namespaces diferentes do namespace global.  Esse comportamento antigo criava um risco de o programa não chamar a implementação do operador **new** ou **delete** pretendida pelo programador, resultando em um comportamento incorreto e silencioso do tempo de execução. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C2323.

   ```Output
    error C2323: 'operator new': non-member operator new or delete functions may not be declared static or in a namespace other than the global namespace.
   ```

   Exemplo (antes)

   ```cpp
    static inline void * __cdecl operator new(size_t cb, const std::nothrow_t&)  // error C2323
   ```

   Exemplo (depois)

   ```cpp
    void * __cdecl operator new(size_t cb, const std::nothrow_t&)  // removed 'static inline'
   ```

   Além disso, embora o compilador não forneça um diagnóstico específico, o operador new embutido é considerado mal formado.

- **Chamando '*tipo*de operador ()' (conversão definida pelo usuário) em tipos diferentes de classe** Versões anteriores do compilador permitiram que o '*tipo*de operador ()' fosse chamado em tipos diferentes de classe, enquanto o ignoravam silenciosamente. Esse comportamento antigo criava um risco de geração silenciosa de código incorreto, resultando em um comportamento imprevisível do tempo de execução. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C2228.

   ```Output
    error C2228: left of '.operator type' must have class/struct/union
   ```

   Exemplo (antes)

   ```cpp
    typedef int index_t;

    void bounds_check(index_t index);

    void login(int column)
    {
        bounds_check(column.operator index_t());  // error C2228
    }
   ```

   Exemplo (depois)

   ```cpp
    typedef int index_t;

    void bounds_check(index_t index);

    void login(int column)
    {
         bounds_check(column);  // removed cast to 'index_t', 'index_t' is an alias of 'int'
    }
   ```

- **Typename redundante em especificadores de tipo elaborados** As versões anteriores do compilador permitiam **typename** em especificadores de tipo elaborados. O código escrito dessa maneira é semanticamente incorreto. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C3406.

   ```Output
    error C3406: 'typename' cannot be used in an elaborated type specifier
   ```

   Exemplo (antes)

   ```cpp
    template <typename class T>
    class container;
   ```

   Exemplo (depois)

   ```cpp
    template <class T>  // alternatively, could be 'template <typename T>'; 'typename' is not elaborating a type specifier in this case
    class container;
   ```

- **Dedução de tipo de matriz de uma lista de inicializadores** Versões anteriores do compilador não davam suporte a dedução de tipos de matriz de uma lista de inicializadores. Agora o compilador oferece suporte a essa forma de dedução de tipo e, como resultado, as chamadas de modelos de função usando listas de inicializadores podem ser ambíguas ou pode ser escolhida uma sobrecarga diferente das versões anteriores do compilador. Para resolver esses problemas, o programa agora deve especificar explicitamente a sobrecarga pretendida pelo programador.

   Quando esse novo comportamento faz com que a resolução de sobrecarga considere um candidato adicional que é igualmente tão bom quanto o candidato histórico, a chamada se torna ambígua e o compilador emite o erro do compilador C2668 como resultado.

   ```Output
    error C2668: 'function' : ambiguous call to overloaded function.
   ```

   Exemplo 1: chamada ambígua à função sobrecarregada (antes)

   ```cpp
    // In previous versions of the compiler, code written in this way would unambiguously call f(int, Args...)
    template <typename... Args>
    void f(int, Args...);  //

    template <int N, typename... Args>
    void f(const int (&)[N], Args...);

    int main()
    {
        // The compiler now considers this call ambiguous, and issues a compiler error
        f({3});  error C2668: 'f' ambiguous call to overloaded function
    }
   ```

   Exemplo 1: chamada ambígua a função sobrecarregada (depois)

   ```cpp
    template <typename... Args>
    void f(int, Args...);  //

    template <int N, typename... Args>
    void f(const int (&)[N], Args...);

    int main()
    {
        // To call f(int, Args...) when there is just one expression in the initializer list, remove the braces from it.
        f(3);
    }
   ```

   Quando esse novo comportamento faz com que a resolução de sobrecarga considere um candidato adicional que é uma melhor correspondência que o candidato histórico, a chamada resolve-se, sem ambiguidade, no novo candidato, causando uma alteração no comportamento do programa que é, provavelmente, diferente do que o programador pretendia.

   Exemplo 2: alteração na resolução de sobrecarga (antes)

   ```cpp
    // In previous versions of the compiler, code written in this way would unambiguously call f(S, Args...)
    struct S
    {
        int i;
        int j;
    };

    template <typename... Args>
    void f(S, Args...);

    template <int N, typename... Args>
    void f(const int *&)[N], Args...);

    int main()
    {
        // The compiler now resolves this call to f(const int (&)[N], Args...) instead
        f({1, 2});
    }
   ```

   Exemplo 2: alteração na resolução de sobrecarga (depois)

   ```cpp
    struct S;  // as before

    template <typename... Args>
    void f(S, Args...);

    template <int N, typename... Args>
    void f(const int *&)[N], Args...);

    int main()
    {
        // To call f(S, Args...), perform an explicit cast to S on the initializer list.
        f(S{1, 2});
    }
   ```

- **Restauração de avisos de instrução switch**

   Uma versão anterior do compilador removeu avisos previamente existentes relacionados a instruções **switch**; esses avisos agora foram restaurados. Agora o compilador emite os avisos restaurados e os avisos relacionados a casos específicos (incluindo o caso padrão) são emitidos na linha que contém o caso com problema, em vez de na última linha da instrução switch. Como resultado da emissão desses avisos em linhas diferentes do que era no passado, os avisos que anteriormente eram suprimidos usando `#pragma warning(disable:####)` não podem mais ser suprimidos como esperado. Para suprimir esses avisos conforme o esperado, talvez seja necessário mover a diretriz `#pragma warning(disable:####)` para uma linha acima do primeiro caso potencialmente problemático. A seguir estão os avisos restaurados.

   ```Output
    warning C4060: switch statement contains no 'case' or 'default' labels
   ```

   ```Output
    warning C4061: enumerator 'bit1' in switch of enum 'flags' is not explicitly handled by a case label
   ```

   ```Output
    warning C4062: enumerator 'bit1' in switch of enum 'flags' is not handled
   ```

   ```Output
    warning C4063: case 'bit32' is not a valid value for switch of enum 'flags'
   ```

   ```Output
    warning C4064: switch of incomplete enum 'flags'
   ```

   ```Output
    warning C4065: switch statement contains 'default' but no 'case' labels
   ```

   ```Output
    warning C4808: case 'value' is not a valid value for switch condition of type 'bool'
   ```

   ```Output
    Warning C4809: switch statement has redundant 'default' label; all possible 'case' labels are given
   ```

   Exemplo de C4063 (antes)

   ```cpp
    class settings
    {
    public:
        enum flags
        {
            bit0 = 0x1,
            bit1 = 0x2,
            ...
        };
        ...
    };

    int main()
    {
        auto val = settings::bit1;

        switch (val)
        {
        case settings::bit0:
            break;

        case settings::bit1:
            break;

        case settings::bit0 | settings::bit1:  // warning C4063
            break;
        }
    };
   ```

   Exemplo de C4063 (depois)

   ```cpp
    class settings {...};  // as above

    int main()
    {
        // since C++11, use std::underlying_type to determine the underlying type of an enum
        typedef std::underlying_type<settings::flags>::type flags_t;

        auto val = settings::bit1;

        switch (static_cast<flags_t>(val))
        {
        case settings::bit0:
            break;

        case settings::bit1:
            break;

        case settings::bit0 | settings::bit1:  // ok
            break;
        }
    };
   ```

   Os exemplos dos outros avisos restaurados são fornecidos em suas respectivas documentações.

- **#include: uso do especificador do diretório pai '..' no nome de caminho** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam o uso do especificador '..' de diretório pai no nome do caminho de diretivas `#include`. O código escrito dessa maneira geralmente se destina a incluir cabeçalhos que existem fora do projeto usando caminhos relativos de projeto de forma incorreta. Esse comportamento antigo criava um risco de que o programa poderia ser compilado pela inclusão de um arquivo de origem diferente do pretendido pelo programador ou desses caminhos relativos não serem portáteis para outros ambientes de build. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C4464 opcional, caso esteja habilitado.

   ```Output
    warning C4464: relative include path contains '..'
   ```

   Exemplo (antes)

   ```cpp
    #include "..\headers\C4426.h"  // emits warning C4464
   ```

   Exemplo (depois)

   ```cpp
    #include "C4426.h"  // add absolute path to 'headers\' to your project's include directories
   ```

   Além disso, embora o compilador não forneça um diagnóstico específico, também é recomendável que especificador ".." de diretório pai não seja usado para especificar diretórios de inclusão de seu projeto.

- **#pragma optimize() ultrapassa o fim do arquivo de cabeçalho** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam alterações nas configurações de sinalizador de otimização que escapam de um arquivo de cabeçalho incluído em uma unidade de tradução. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C4426 opcional no local do `#include` problemático, caso esteja habilitado. Esse aviso será emitido apenas se as alterações estiverem em conflito com os sinalizadores de otimização definidos por argumentos de linha de comando para o compilador.

   ```Output
    warning C4426: optimization flags changed after including header, may be due to #pragma optimize()
   ```

   Exemplo (antes)

   ```cpp
    // C4426.h
    #pragma optimize("g", off)
    ...
    // C4426.h ends

    // C4426.cpp
    #include "C4426.h"  // warning C4426
   ```

   Exemplo (depois)

   ```cpp
    // C4426.h
    #pragma optimize("g", off)
    ...
    #pragma optimize("", on)  // restores optimization flags set via command-line arguments
    // C4426.h ends

    // C4426.cpp
    #include "C4426.h"
   ```

- **#pragma warning(push)** e **#pragma warning(pop) incompatíveis** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam a combinação de alterações de estado `#pragma warning(push)` com alterações de estado `#pragma warning(pop)` em um arquivo de origem diferente, o que é raramente pretendido. Esse comportamento antigo criava um risco do programa ser compilado com um conjunto de avisos habilitados diferentes do que o programador pretendia, resultando, possivelmente, em comportamento silencioso de tempo de execução incorreto. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C5031 opcional no local do `#pragma warning(pop)` correspondente, caso esteja habilitado. Esse aviso inclui uma observação que referencia o local do `#pragma warning(push)` correspondente.

   ```Output
    warning C5031: #pragma warning(pop): likely mismatch, popping warning state pushed in different file
   ```

   Exemplo (antes)

   ```cpp
    // C5031_part1.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    // C5031_part1.h ends without #pragma warning(pop)

    // C5031_part2.h
    ...
    #pragma warning(pop)  // pops a warning state not pushed in this source file
    ...
    // C5031_part1.h ends

    // C5031.cpp
    #include "C5031_part1.h" // leaves #pragma warning(push) 'dangling'
    ...
    #include "C5031_part2.h" // matches 'dangling' #pragma warning(push), resulting in warning C5031
    ...
   ```

   Exemplo (depois)

   ```cpp
    // C5031_part1.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    #pragma warning(pop)  // pops the warning state pushed in this source file
    // C5031_part1.h ends without #pragma warning(pop)

    // C5031_part2.h
    #pragma warning(push)  // pushes the warning state pushed in this source file
    #pragma warning(disable:####)
    ...
    #pragma warning(pop)
    // C5031_part1.h ends

    // C5031.cpp
    #include "C5031_part1.h" // #pragma warning state changes are self-contained and independent of other source files or their #include order.
    ...
    #include "C5031_part2.h"
    ...
   ```

   Embora incomum, às vezes o código é escrito intencionalmente dessa maneira. O código escrito dessa maneira é sensível às alterações na ordem `#include`; quando possível, é recomendável que os arquivos de código-fonte gerenciem o estado de aviso de forma autocontida.

- **#pragma warning(push) sem correspondência** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam alterações de estado `#pragma warning(push)` sem correspondência no final de uma unidade de tradução. O compilador agora detecta e notifica o programador sobre código escrito dessa maneira e emite um aviso C5032 opcional do compilador no local do `#pragma warning(push)` sem correspondência, quando habilitado. Esse aviso será emitido somente se não houver erros de compilação na unidade de tradução.

   ```Output
    warning C5032: detected #pragma warning(push) with no corresponding #pragma warning(pop)
   ```

   Exemplo (antes)

   ```cpp
    // C5032.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    // C5032.h ends without #pragma warning(pop)

    // C5032.cpp
    #include "C5032.h"
    ...
    // C5032.cpp ends -- the translation unit is completed without #pragma warning(pop), resulting in warning C5032 on line 1 of C5032.h
   ```

   Exemplo (depois)

   ```cpp
    // C5032.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    #pragma warning(pop) // matches #pragma warning (push) on line 1
    // C5032.h ends

    // C5032.cpp
    #include "C5032.h"
    ...
    // C5032.cpp ends -- the translation unit is completed without unmatched #pragma warning(push)
   ```

- **Avisos adicionais podem ser emitidos como resultado de um controle de estado de aviso #pragma aprimorado**

   As versões anteriores do compilador controlavam as alterações de estado de `#pragma warning` de forma insuficientemente adequada para emitir todos os avisos pretendidos. Esse comportamento criava um risco de que certos avisos seriam efetivamente suprimidos em circunstâncias diferentes das que o programador pretendia. Agora o compilador acompanha o estado de `#pragma warning` de uma forma melhor, principalmente com relação às alterações de estado de `#pragma warning` dentro de modelos e, opcionalmente, emite novos avisos C5031 e C5032 para ajudar o programador a localizar usos não intencionais de `#pragma warning(push)` e `#pragma warning(pop)`.

   Como resultado da melhoria do controle de alterações de estado de `#pragma warning`, os avisos que antes eram suprimidos incorretamente ou os avisos relacionados a problemas que eram mal diagnosticados agora podem ser emitidos.

- **Identificação aprimorada de código inacessível**

   As alterações da Biblioteca Padrão do C++ e capacidade aprimorada para chamadas de função embutida em relação às versões anteriores do compilador podem permitir que o compilador comprove que determinado código está inacessível no momento. Esse novo comportamento pode resultar em emissões novas e mais frequentes de instâncias do aviso C4720.

   ```Output
    warning C4720: unreachable code
   ```

   Em muitos casos, esse aviso só pode ser emitido durante a compilação com otimizações habilitadas, já que as otimizações podem embutir mais chamadas de função, eliminar código redundante ou, caso contrário, possibilitar a determinação de que determinado código está inacessível. Observamos que as novas instâncias do aviso C4720 ocorriam frequentemente nos blocos **try/catch**, principalmente em relação ao uso de [std::find](assetId:///std::find?qualifyHint=False&autoUpgrade=True).

   Exemplo (antes)

   ```cpp
    try
    {
        auto iter = std::find(v.begin(), v.end(), 5);
    }
    catch(...)
    {
        do_something();  // ok
    }
   ```

   Exemplo (depois)

   ```cpp
    try
    {
        auto iter = std::find(v.begin(), v.end(), 5);
    }
    catch(...)
    {
        do_something();  // warning C4702: unreachable code
    }
   ```

### <a name="VS_Update2"></a> Melhorias de conformidade no Visual Studio 2015 – Atualização 2

- **Erros e avisos adicionais podem ser emitidos como resultado do suporte parcial à expressão SFINAE**

   As versões anteriores do compilador não analisavam determinados tipos de expressões dentro de especificadores **decltype** devido à falta de suporte para a expressão SFINAE. Esse comportamento antigo estava incorreto e não estava em conformidade com o padrão C++. Agora o compilador analisa essas expressões e tem suporte parcial à expressão SFINAE devido às melhorias contínuas de conformidade. Como resultado, o compilador emite avisos e erros encontrados nas expressões que as versões anteriores do compilador não analisavam.

   Quando esse novo comportamento analisa uma expressão **decltype** que inclui um tipo que não ainda foi declarado, o compilador emite o erro do compilador C2039 como resultado.

   ```Output
    error C2039: 'type': is not a member of '`global namespace''
   ```

   Exemplo 1: uso de um tipo não declarado (antes)

   ```cpp
    struct s1
    {
      template <typename T>
      auto f() -> decltype(s2<T>::type::f());  // error C2039

      template<typename>
      struct s2 {};
    }
   ```

   Exemplo 1 (depois)

   ```cpp
    struct s1
    {
      template <typename>  // forward declare s2struct s2;

      template <typename T>
      auto f() -> decltype(s2<T>::type::f());

      template<typename>
      struct s2 {};
    }
   ```

   Quando esse novo comportamento analisa uma expressão **decltype** na qual está ausente um uso necessário da palavra-chave **typename** para especificar que um nome dependente é um tipo, o compilador emite o aviso do compilador C4346 junto com o erro do compilador C2923.

   ```Output
    warning C4346: 'S2<T>::Type': dependent name is not a type
   ```

   ```Output
    error C2923: 's1': 'S2<T>::Type' is not a valid template type argument for parameter 'T'
   ```

   Exemplo 2: o nome dependente não é um tipo (antes)

   ```cpp
    template <typename T>
    struct s1
    {
      typedef T type;
    };

    template <typename T>
    struct s2
    {
      typedef T type;
    };

    template <typename T>
    T declval();

    struct s
    {
      template <typename T>
      auto f(T t) -> decltype(t(declval<S1<S2<T>::type>::type>()));  // warning C4346, error C2923
    };
   ```

   Exemplo 2 (depois)

   ```cpp
    template <typename T> struct s1 {...};  // as above
    template <typename T> struct s2 {...};  // as above

    template <typename T>
    T declval();

    struct s
    {
      template <typename T>
      auto f(T t) -> decltype(t(declval<S1<typename S2<T>::type>::type>()));
    };
   ```

- `volatile` **Variáveis de membro evitam operadores de atribuição e construtores definidos implicitamente** As versões anteriores do compilador permitiam que os construtores padrão de copiar/mover e os operadores de atribuição padrão de copiar/mover de uma classe com variáveis de membro **volatile** fossem gerados automaticamente. Esse comportamento antigo estava incorreto e não estava em conformidade com o padrão C++. Agora o compilador considera que uma classe que tem variáveis de membro voláteis tenha operadores de construção e de atribuição não triviais que impedem que as implementações padrão desses operadores sejam geradas automaticamente. Quando essa classe é um membro de uma união (ou uma união anônima dentro de uma classe), os construtores copiar/mover e os operadores de atribuição copiar/mover da união (ou a classe que contém a união anônima) serão implicitamente definidos como excluídos. A tentativa de construir ou copiar a união (ou a classe que contém a união anônima) sem defini-la explicitamente é um erro e o compilador emite um erro de compilador C2280 como resultado.

   ```Output
    error C2280: 'B::B(const B &)': attempting to reference a deleted function
   ```

   Exemplo (antes)

   ```cpp
    struct A
    {
      volatile int i;
      volatile int j;
    };

    extern A* pa;

    struct B
    {
      union
      {
        A a;
        int i;
      };
    };

    B b1 {*pa};
    B b2 (b1);  // error C2280
   ```

   Exemplo (depois)

   ```cpp
    struct A
    {
      int i;int j;
    };

    extern volatile A* pa;

    A getA()  // returns an A instance copied from contents of pa
    {
      A a;
      a.i = pa->i;
      a.j = pa->j;
      return a;
    }

    struct B;  // as above

    B b1 {GetA()};
    B b2 (b1);  // error C2280
   ```

- **Funções de membro estático não dão suporte a qualificadores cv.**

   As versões anteriores do Visual C++ 2015 permitiam que funções de membro estático tivessem qualificadores cv. Esse comportamento era devido a uma regressão no Visual C++ 2015 e no Visual C++ 2015 Atualização 1. O Visual C++ 2013 e as versões anteriores do Visual C++ rejeitam o código escrito dessa maneira. O comportamento do Visual C++ 2015 e do Visual C++ 2015 Atualização 1 está incorreto e não está em conformidade com o padrão C++.  O Visual Studio 2015 Atualização 2 rejeita o código escrito dessa maneira e, em vez disso, emite o erro do compilador C2511.

   ```Output
    error C2511: 'void A::func(void) const': overloaded member function not found in 'A'
   ```

   Exemplo (antes)

   ```cpp
    struct A
    {
      static void func();
    };

    void A::func() const {}  // C2511
   ```

   Exemplo (depois)

   ```cpp
    struct A
    {
      static void func();
    };

    void A::func() {}  // removed const
   ```

- **A declaração de encaminhamento de enum não é permitida no código do WinRT** (afeta apenas `/ZW`)

   O código compilado para o WinRT (Windows Runtime) não permite que tipos **enum** sejam declarados como de encaminhamento, de forma semelhante a quando o código C++ gerenciado é compilado para o .NET Framework usando a opção de compilador `/clr`. Esse comportamento garante que o tamanho de uma enumeração seja sempre conhecido e seja projetado corretamente para o sistema de tipos WinRT. O compilador rejeita o código escrito dessa maneira e emite um erro do compilador C2599 junto com o erro do compilador C3197.

   ```Output
    error C2599: 'CustomEnum': the forward declaration of a WinRT enum is not allowed
   ```

   ```Output
    error C3197: 'public': can only be used in definitions
   ```

   Exemplo (antes)

   ```cpp
    namespace A {
      public enum class CustomEnum: int32;  // forward declaration; error C2599, error C3197
    }

    namespace A {
      public enum class CustomEnum: int32
      {
        Value1
      };
    }

    public ref class Component sealed
    {
    public:
      CustomEnum f()
      {
        return CustomEnum::Value1;
      }
    };
   ```

   Exemplo (depois)

   ```cpp
              // forward declaration of CustomEnum removed
    namespace A {
      public enum class CustomEnum: int32
      {
        Value1
      };
    }

    public ref class Component sealed
    {
    public:
      CustomEnum f()
      {
        return CustomEnum::Value1;
      }
    };
   ```

- **Operador new de não membro sobrecarregado e operador delete não podem ser declarados embutidos** (Nível 1 (`/W1`) ativado por padrão)

   As versões anteriores do compilador não emitem um aviso quando o **operador new** de não membro e as funções do **operador delete** são declarados embutidos. O código escrito dessa maneira é malformado (não é necessário nenhum diagnóstico) e pode causar problemas de memória resultantes da falta de correspondência entre os operadores new e delete (principalmente quando usados em conjunto com desalocação dimensionada) que podem ser difíceis de diagnosticar. Agora o compilador emite o aviso do compilador C4595 para ajudar a identificar o código escrito dessa forma.

   ```Output
    warning C4595: 'operator new': non-member operator new or delete functions may not be declared inline
   ```

   Exemplo (antes)

   ```cpp
    inline void* operator new(size_t sz)  // warning C4595
    {
      ...
    }
   ```

   Exemplo (depois)

   ```cpp
    void* operator new(size_t sz)  // removed inline
    {
      ...
    }
   ```

   A correção do código escrito dessa maneira pode exigir que as definições de operador sejam retiradas de um arquivo de cabeçalho e movidas para um arquivo de origem correspondente.

### <a name="VS_Update3"></a> Melhorias de conformidade no Visual Studio 2015 – Atualização 3

- **std::is_convertable agora detecta autoatribuição**(biblioteca padrão) Versões anteriores da característica de tipo `std::is_convertable` não detectam corretamente autoatribuição de um tipo de classe quando o construtor de cópia é particular ou excluído. Agora, `std::is_convertable<>::value` é definido corretamente como **false** quando aplicado a um tipo de classe com um construtor de cópia particular ou excluído.

   Não há nenhum diagnóstico de compilador associado a essa alteração.

   Exemplo

   ```cpp
    #include <type_traits>

    class X1
    {
    public:
        X1(const X1&) = delete;
    };

    class X2
    {
    private:
        X2(const X2&);
    };

    static_assert(std::is_convertible<X1&, X1>::value, "BOOM");static_assert(std::is_convertible<X2&, X2>::value, "BOOM");
   ```

   Nas versões anteriores do Visual C++, as asserções estáticas na parte inferior deste exemplo passavam porque `std::is_convertable<>::value` era definido incorretamente como **true**. Agora, `std::is_convertable<>::value` é definido corretamente como **false**, fazendo com que as asserções estáticas falhem.

- **Construtores triviais de cópia e movimentação padronizados ou excluídos respeitam especificadores de acesso**

   As versões anteriores do compilador não verificavam o especificador de acesso dos construtores triviais de cópia e movimentação padronizados ou excluídos antes de permitir que fossem chamados. Esse comportamento antigo estava incorreto e não estava em conformidade com o padrão C++. Em alguns casos, esse comportamento antigo criava um risco de geração silenciosa de código incorreto, resultando em um comportamento imprevisível do tempo de execução. Agora o compilador verifica o especificador de acesso dos construtores triviais de cópia e movimentação padrão ou excluídos para determinar se eles podem ser chamados e, caso não possam, emite um aviso do compilador C2248 como resultado.

   ```Output
    error C2248: 'S::S' cannot access private member declared in class 'S'
   ```

   Exemplo (antes)

   ```cpp
    class S {
    public:
       S() = default;
    private:
        S(const S&) = default;
    };

    void f(S);  // pass S by value

    int main()
    {
        S s;
        f(s);  // error C2248, can't invoke private copy constructor
    }
   ```

   Exemplo (depois)

   ```cpp
    class S {
    public:
       S() = default;
    private:
        S(const S&) = default;
    };

    void f(const S&);  // pass S by reference

    int main()
    {
        S s;
        f(s);
    }
   ```

- **Preterimento do suporte a código ATL atribuído** (Nível 1 [`/W1`] ativado por padrão)

   As versões anteriores do compilador ofereciam suporte ao código ATL atribuído. Como um passo seguinte da remoção do suporte ao código ATL atribuído que [começou no Visual C++ 2008](https://msdn.microsoft.com/library/bb384632), o código ATL atribuído foi preterido. Agora o compilador emite o aviso do compilador C4467 para ajudar a identificar esse tipo de código preterido.

   ```Output
    warning C4467: Usage of ATL attributes is deprecated
   ```

   Se você deseja continuar usando o código ATL atribuído até que o suporte seja removido do compilador, você pode desabilitar esse aviso, passando os argumentos de linha de comando `/Wv:18` ou `/wd4467` para o compilador ou adicionando `#pragma warning(disable:4467)` em seu código-fonte.

   Exemplo 1 (antes)

   ```cpp
              [uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")]
    class A {};
   ```

   Exemplo 1 (depois)

   ```cpp
    __declspec(uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")) A {};
   ```

   Talvez você queira ou seja necessário criar um arquivo IDL para evitar o uso de atributos ATL preteridos, como no código de exemplo abaixo

   Exemplo 2 (antes)

   ```cpp
    [emitidl];
    [module(name="Foo")];

    [object, local, uuid("9e66a290-4365-11d2-a997-00c04fa37ddb")]
    __interface ICustom {
        HRESULT Custom([in] long l, [out, retval] long *pLong);
        [local] HRESULT CustomLocal([in] long l, [out, retval] long *pLong);
    };

    [coclass, appobject, uuid("9e66a294-4365-11d2-a997-00c04fa37ddb")]
    class CFoo : public ICustom
    {
        // ...
    };
   ```

   Primeiro, crie o arquivo *.idl; o arquivo vc140.idl gerado pode ser usado para obter um arquivo \*.idl que contém as interfaces e as anotações.

   Em seguida, adicione uma etapa MIDL ao seu build para certificar-se de que as definições de interface de C++ são geradas.

   Exemplo 2 IDL (depois)

   ```cpp
    import "docobj.idl";

    [
        object,local,uuid(9e66a290-4365-11d2-a997-00c04fa37ddb)
    ]

    interface ICustom : IUnknown {
        HRESULT  Custom([in] long l, [out,retval] long *pLong);
        [local] HRESULT  CustomLocal([in] long l, [out,retval] long *pLong);
    };

    [ version(1.0), uuid(29079a2c-5f3f-3325-99a1-3ec9c40988bb) ]
    library Foo
    {
        importlib("stdole2.tlb");
        importlib("olepro32.dll");
            [
                version(1.0),
                appobject,uuid(9e66a294-4365-11d2-a997-00c04fa37ddb)
            ]

        coclass CFoo {
            interface ICustom;
        };
    }
   ```

   Em seguida, use a ATL diretamente no arquivo de implementação, como no código de exemplo abaixo.

   Exemplo 2 Implementação (Depois)

   ```cpp
    #include <idl.header.h>
    #include <atlbase.h>

    class ATL_NO_VTABLE CFooImpl :
        public ICustom,
        public ATL::CComObjectRootEx<CComMultiThreadModel>
    {
    public:
        BEGIN_COM_MAP(CFooImpl)
        COM_INTERFACE_ENTRY(ICustom)
        END_COM_MAP()
    };
   ```

- **Arquivos de PCH (cabeçalho pré-compilado) e diretivas #include incompatíveis** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador aceitavam diretivas `#include` incompatíveis em arquivos de origem entre compilações `-Yc` e `-Yu` ao usar arquivos de PCH (cabeçalho pré-compilado). O código escrito dessa maneira não é mais aceito pelo compilador. Agora o compilador emite o aviso do compilador CC4598 para ajudar a identificar diretivas `#include` incompatíveis ao usar arquivos de PCH.

   ```Output
    warning C4598: 'b.h': included header file specified for Ycc.h at position 2 does not match Yuc.h at that position
   ```

   Exemplo (antes):

   X.cpp (-Ycc.h)

   ```cpp
    #include "a.h"
    #include "b.h"
    #include "c.h"
   ```

   Z.cpp (-Yuc.h)

   ```cpp
    #include "b.h"
    #include "a.h"  // mismatched order relative to X.cpp
    #include "c.h"
   ```

   Exemplo (depois)

   X.cpp (-Ycc.h)

   ```cpp
    #include "a.h"
    #include "b.h"
    #include "c.h"
   ```

   Z.cpp (-Yuc.h)

   ```cpp
    #include "a.h"
    #include "b.h" // matched order relative to X.cpp
    #include "c.h"
   ```

- **Arquivos de PCH (cabeçalho pré-compilado) e diretórios #include incompatíveis** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador aceitavam argumentos de linha de comando de diretórios de inclusão incompatíveis (`-I`) para o compilador entre compilações `-Yc` e `-Yu` ao usar arquivos de PCH (cabeçalho pré-compilado). O código escrito dessa maneira não é mais aceito pelo compilador.   Agora o compilador emite o aviso do compilador CC4599 para ajudar a identificar argumentos de linha de comando de diretórios de inclusão incompatíveis (`-I`) ao usar arquivos de PCH.

   ```Output
    warning C4599: '-I..' : specified for Ycc.h at position 1 does not match Yuc.h at that position
   ```

   Exemplo (antes)

   ```ms-dos
    cl /c /Wall /Ycc.h -I.. X.cpp
    cl /c /Wall /Yuc.h Z.cpp
   ```

   Exemplo (depois)

   ```ms-dos
    cl /c /Wall /Ycc.h -I.. X.cpp
    cl /c /Wall /Yuc.h -I.. Z.cpp
   ```

## <a name="whats-new-for-c-in-visual-studio-2013"></a>Novidades do C++ no Visual Studio 2013

### <a name="improved-iso-cc-standards-support"></a>Suporte aprimorado a padrões ISO C/C++

#### <a name="compiler"></a>Compilador

O compilador Microsoft Visual C++ é compatível com esses recursos de linguagem ISO C++11:

- Argumentos de modelo padrão para modelos de função.
- Delegação de construtores
- Operadores de conversão explícita.
- Listas de inicializador e inicialização uniforme.
- Literais brutos de cadeia de caracteres.
- Modelos Variadic.
- Modelos de alias.
- Funções excluídas.
- NSDMIs (inicializadores de membros de dados não estáticos).
- Funções usadas como padrão. \*
- Oferece suporte a estes recursos de idioma ISO C99:
- _Bool
- Literais compostos.
- Inicializadores designados.
- Mistura de declarações com código.
- A conversão de literal de cadeia de caracteres em valores modificáveis pode ser desautorizada usando a nova opção do compilador `/Zc:strictStrings`. No C++98, a conversão de literais de cadeia de caracteres em `char*` (e dos literais de cadeia de caracteres largos em `wchar_t*`) foi preterida. No C++11, a conversão foi totalmente removida. Embora o compilador possa estar estritamente em conformidade com o padrão, em vez disso ele fornece a opção `/Zc:strictStrings` de modo que você possa controlar a conversão. Por padrão, a opção está desativada. Observe que quando você estiver usando essa opção no modo de depuração, a STL não será compilada.
- Conversão de referência rvalue/lvalue. Com referências de rvalue, o C++11 pode distinguir claramente entre lvalues e rvalues. Anteriormente, o compilador não fornecia isso em cenários de conversão específicos. Uma nova opção do compilador, `/Zc:rvalueCast`, foi adicionada para tornar o compilador compatível com o Documento de trabalho da linguagem C++ (confira a seção 5.4, [expr.cast]/1). O comportamento padrão quando essa opção não é especificada é o mesmo no Visual Studio 2012.

> [!NOTE]
> Para funções padrão, não há suporte para o uso de =default para solicitar construtores de movimentação de membros e operadores de atribuição de movimentação.

### <a name="c99-libraries"></a>Bibliotecas C99

Declarações e implementações são adicionadas a funções ausentes nestes cabeçalhos: math.h, ctype.h, wctype.h, stdio.h, stdlib.h e wchar.h. Também são adicionados novos cabeçalhos complex.h, stdbool.h, fenv.h e inttypes.h, e implementações para todas as funções declaradas neles. Há novos cabeçalhos de wrapper do C++ (ccomplex, cfenv, cinttypes, ctgmath) e outros foram atualizados (ccomplex, cctype, clocale, cmath, cstdint, cstdio, cstring, cwchar e cwctype).

### <a name="standard-template-library"></a>Biblioteca de Modelos Padrão

Suporte para operadores de conversão explícitos do C++11, listas de inicialização, enums com escopo e modelos variadic.
Todos os contêineres agora suportam os requisitos de elementos refinados do C++11.
Suporte para estes recursos do C++14:

- "Transparent operator functors" less<>, greater<>, plus<>, multiplies<>, e assim por diante.
- make_unique<T>(args...) e make_unique<T[]>(n)
- funções de não membro cbegin()/cend(), rbegin()/rend() e crbegin()/crend().
- \<atomic> recebeu inúmeras melhorias de desempenho.
- \<type_traits> recebeu grande estabilização e correções de código.

### <a name="breaking-changes"></a>Alterações significativas

Esse suporte aperfeiçoado para padrões ISO C/C++ pode exigir alterações do código existente de modo que ele fique em conformidade com o C++11 e seja compilado corretamente no Visual C++ e Visual Studio 2013.

### <a name="visual-c-library-enhancements"></a>Aprimoramentos da biblioteca do Visual C++

- O SDK do C++ REST foi adicionado. Tem uma implementação moderna do C++ de serviços REST.
- O suporte à textura do C++ AMP foi aprimorado. Inclui agora suporte para mipmaps e novos modos de amostragem.
- As tarefas de PPL dão suporte a várias tecnologias de agendamento e depuração assíncrona. Novas APIs permitem a criação de tarefas de PPL para resultados normais e condições de exceção.

### <a name="c-application-performance"></a>Desempenho do aplicativo C++

- O Vetorizador Automático agora reconhece e otimiza mais padrões do C++ para tornar a execução do código mais rápida.
- Melhorias de qualidade de código da plataforma ARM e da microarquitetura Atom.
- A convenção de chamada __vectorcall foi adicionada. Passe argumentos de tipo de vetor usando a convenção de chamada __vectorcall para uso de registros de vetor.
- Novas opções de vinculador. As opções `/Gw` (compilador) e `/Gy` (montador) permitem otimizações de vinculador para gerar binários mais enxutos.
- Suporte a memória compartilhada do C++ AMP para reduzir ou eliminar cópia de dados entre a CPU e a GPU.

### <a name="profile-guided-optimization-pgo-enhancements"></a>Melhorias na PGO (Otimização Guiada por Perfil)

- Melhorias de desempenho de uma redução no conjunto de trabalho de aplicativos otimizados usando PGO.
- Nova PGO para desenvolvimento de aplicativos do Windows Runtime.

### <a name="windows-runtime-app-development-support"></a>Suporte ao desenvolvimento de aplicativos do Windows Runtime

- **Suporte para tipos demarcados em estruturas de valor.**

   Agora você pode definir tipos de valor usando campos que podem ser nulos. Por exemplo, `IBox<int>^` em vez de **int**. Isso significa que os campos podem ter um valor ou ser igual a **nullptr**.

- **Informações de exceção mais completas.**

   C++/CX oferece suporte ao novo modelo de erros do Windows que habilita a captura e a propagação de informações completas de exceção através da ABI (interface binária de aplicativo); isso inclui pilhas de chamada e cadeias de caracteres de mensagens personalizadas.

- **Object::ToString() agora é virtual.**

   Agora você pode substituir ToString em tipos de referência do Windows Runtime definidos pelo usuário.

- **Suporte para APIs preteridas.**

   As APIs públicas do Tempo de Execução do Windows agora podem ser preteridas e apresentar uma mensagem personalizada que aparecerá como um aviso de compilação, além de poderem oferecer orientação sobre a migração.

- **Melhorias no depurador.**

   Suporte para depuração de interoperação nativa/JavaScript, diagnóstico de exceção do Tempo de Execução do Windows e depuração de código assíncrono (Tempo de Execução do Windows e PPL).

> [!NOTE]
> Além das melhorias e dos recursos específicos do C++ descritos nesta seção, outras melhorias do Visual Studio também podem ajudá-lo a escrever aplicativos do Windows Runtime ainda melhores.

### <a name="diagnostics-enhancements"></a>Aprimoramentos no diagnóstico

- Melhorias no depurador. Suporte para depuração assíncrona e depuração Apenas Meu Código.
- Categorias de análise de código. Agora é possível exibir a saída categorizada do analisador de código para ajudar a localizar e corrigir defeitos de código.
- Diagnósticos XAML. Agora é possível diagnosticar problemas da interface do usuário e de capacidade de bateria no XAML.
- Melhorias nos gráficos e na depuração da GPU.
- Captura e reprodução remotas em dispositivos reais.
- Depuração simultânea do C++ AMP e da CPU.
- Diagnóstico do tempo de execução C++ AMP aprimorado.
- Depuração de rastreamento do sombreador de cálculo de HLSL.

### <a name="3-d-graphics-enhancements"></a>Aprimoramentos de elementos gráficos 3D

- Suporte a Pipeline de conteúdo da imagem para formato DDS alfa pré-multiplicado.
- O Editor de Imagens usa internamente o alfa pré-multiplicado na renderização e, assim, evita a renderização de artefatos como auréolas escuras.
- Editores de imagem e modelo. Agora o Shader Designer, o Editor de Imagens e o Editor de Modelos permitem a criação de filtros definidos pelo usuário.

### <a name="ide-and-productivity"></a>IDE e produtividade

**Formatação de código aprimorada**. É possível aplicar mais configurações de formatação ao seu código de C++. Usando essas configurações, você pode controlar o posicionamento de nova linha de chaves e palavras-chave, recuo, espaçamento e quebra automática de linha. O código é formatado automaticamente quando você conclui instruções e blocos, e quando cola o código em um arquivo.

**Preenchimento de chaves.** O código em C++ agora preenche automaticamente os caracteres de fechamento correspondentes a esses caracteres de abertura:

- { (chave)
- [ (colchete)
- ( (parênteses)
- ' (aspas simples)
- "(aspas duplas)

**Recursos adicionais de preenchimento automático do C++.**

- Adiciona o ponto e vírgula para tipos de classe.
- Preenche parênteses para literais de cadeia de caracteres bruta.
- Conclui comentários de várias linhas (/\* \*/)

**Localizar Todas as Referências** agora resolve e filtra automaticamente referências em segundo plano depois que exibe a lista de correspondências textuais.

**Filtragem da lista de membros baseada no contexto.** Os membros inacessíveis são filtrados e retirados das listas de membros do IntelliSense. Por exemplo, os membros particulares não são exibidos na lista de membros a menos que você esteja alterando o código que implementa o tipo. Enquanto a lista de membros está aberta, você pode pressionar **Ctrl**+**J** para remover um nível de filtragem (aplica-se somente à janela de lista de membros atual). Você pode pressionar **Ctrl**+**J** novamente para remover a filtragem textual e exibir todos os membros.

**Rolagem da ajuda do parâmetro.** A assinatura de função exibida na dica de ferramenta de parameter-help agora muda de acordo com o número de parâmetros digitados, em vez de mostrar apenas uma assinatura arbitrária e não atualizá-la com base no contexto atual. A ajuda de parâmetro também funciona corretamente quando exibida em funções aninhadas.

**Alternar Cabeçalho/Arquivo de Código.** Agora é possível alternar entre um cabeçalho e seu arquivo de código correspondente usando um comando no menu de atalho ou um atalho de teclado.

**Janela Propriedades do projeto C++ redimensionável**

**Geração automática de código do manipulador de eventos em C++/CX e C++/CLI.**  Quando estiver digitando o código para adicionar um manipulador de eventos em um arquivo de código em C++/CX ou C++/CLI, o editor pode gerar automaticamente a instância delegate e a definição de manipulador de evento. Uma janela de dica de ferramenta aparece quando o código do manipulador de eventos pode ser gerado automaticamente.

**Melhoria de reconhecimento de DPI.** A configuração Reconhecimento de DPI para arquivos de manifesto de aplicativo agora oferece suporte à configuração "Reconhecimento de DPI Alto por Monitor".

**Alternância mais rápida de configuração.** Em grandes aplicativos, a alternância de configurações, principalmente operações de alternância subsequentes, é executada com muito mais rapidez+.

**Eficiência do tempo de compilação.** Diversas otimizações e o uso de vários núcleos tornam as compilações mais rápidas, principalmente para projetos grandes. As compilações incrementais para aplicativos C++ que têm referências a C++ WinMD também estão muito mais rápidas.

## <a name="whats-new-for-c-in-visual-studio-2012"></a>Novidades do C++ no Visual Studio 2012

### <a name="improved-c11-standards-support"></a>Suporte a padrões do C++11 aperfeiçoados

#### <a name="standard-template-library"></a>Biblioteca de Modelos Padrão

- Suporte para novos cabeçalhos STL: \<atomic>, \<chrono>, \<condition_variable>, \<filesystem>, \<future>, \<mutex>, \<ratio> e \<thread>.
- Para otimizar o uso de recursos de memória, os contêineres agora são menores. Por exemplo, no modo de versão x86 com configurações padrão, `std::vector` foi reduzido de 16 bytes no Visual Studio 2010 para 12 bytes no Visual Studio 2012 e `std::map` foi reduzido de 16 bytes no Visual Studio 2010 para 8 bytes no Visual Studio 2012.
- Permitido, mas não exigido pelo padrão C++ 11, os iteradores SCARY foram implementados.

#### <a name="other-c11-enhancements"></a>Outras melhorias no C++11

- Baseado em intervalos para loops. Você pode escrever loops mais robustos que funcionam com matrizes, contêineres STL e coleções do Windows Runtime no formulário for ( for-range-declaration : expression ). Isso faz parte do suporte à linguagem base.
- Lambdas sem monitoração de estado, que são blocos de código que começam com um Introdutor [] de lambda vazio e não capturam variáveis locais, agora são implicitamente convertidos em ponteiros de função, conforme exigido pelo padrão C++11.
- Suporte a enumerações em escopo. Agora há suporte para a chave de enumeração da classe C++ enum. O código a seguir demonstra como a chave de enumeração é diferente do comportamento anterior do enum.

   ```cpp
  enum class Element { Hydrogen, Helium, Lithium, Beryllium };
  void func1(Element e);
  func1(Hydrogen); // error C2065: 'Hydrogen' : undeclared identifier
  func1(Element::Helium); // OK
   ```

### <a name="windows-runtime-app-development-support"></a>Suporte ao desenvolvimento de aplicativos do Windows Runtime

- **Modelo de interface do usuário baseada em XAML nativo**. Para aplicativos do Windows Runtime, você pode usar o novo modelo de interface do usuário baseada em XAML nativo.
- **Extensões de componentes do Visual C++**. Essas extensões simplificam o consumo de objetos do Windows Runtime, que são uma parte necessária dos aplicativos do Windows Runtime. Para obter mais informações, confira [Roadmap for Windows Runtime apps using C++](../windows/universal-windows-apps-cpp.md) (Roteiro para aplicativos do Windows Runtime usando C++) e [Referência de linguagem do Visual C++ (C++/CX)](../cppcx/visual-c-language-reference-c-cx.md)
- **Jogos do DirectX**. Você pode desenvolver jogos envolventes usando o novo suporte do DirectX para aplicativos do Windows Runtime.
- **Interoperabilidade XAML/DirectX**. Os aplicativos do Windows Runtime que usam XAML e DirectX agora são interoperados com eficiência.
- **Desenvolvimento de DLL do Componente do Tempo de Execução do Windows**. Desenvolvimento de DLL do componente torna o ambiente do Windows Runtime extensível.

### <a name="compiler-and-linker"></a>Compilador e vinculador

- **Vetorizador automático**. O compilador analisa loops no código e, quando possível, emite instruções que usam registros do vetor e instruções presentes em todos os processadores modernos. Isso agiliza a execução dos loops. (As instruções de processador são conhecidas como SSE, para extensões SIMD de Streaming). Você não precisa habilitar nem solicitar essa otimização porque ela é aplicada automaticamente.
- **Paralelizador automático**. O compilador pode analisar loops no código e emitir instruções que abrangem os cálculos de vários núcleos ou processadores. Isso pode agilizar a execução dos loops. Essa otimização não é habilitada por padrão, é necessário solicitá-la. Em muitos casos, é interessante incluir um `#pragma loop(hint_parallel(N))` no código imediatamente antes dos loops que você deseja em paralelo.
- O vetorizador automático e paralelizador automático podem trabalhar juntos para que os cálculos são distribuídos em vários núcleos e o código em cada núcleo usa seus registros de vetor.

### <a name="new-in-visual-studio-2012-update-1"></a>Novidades no Visual Studio 2012 – Atualização 1

Windows XP como destino ao compilar o código C++.
Você pode usar o compilador do Visual C++ e as bibliotecas para Windows XP e Windows Server 2003 como destino.

#### <a name="parallel-programming-support"></a>Suporte a programação paralela

##### <a name="c-accelerated-massive-parallelism-amp"></a>C++ Accelerated Massive Parallelism (AMP)

O C++ AMP acelera a execução do código C++, aproveitando o hardware paralelo de dados que geralmente está presente como uma GPU em uma placa gráfica discreta. O modelo de programação do C++ AMP inclui matrizes multidimensionais, indexação, transferência de memória, agrupamento lado a lado e uma biblioteca de funções matemáticas. Usando extensões de linguagem do C++ AMP e restrições do compilador, controle como os dados são movidos da CPU para a GPU e vice-versa.

**Depuração.** A experiência de depuração para aplicativos que usam o C++ AMP para a GPU de destino é exatamente igual a depuração de outros aplicativos em C++. Isso inclui as novas adições de depuração paralela mencionadas anteriormente.

**Criação de perfil.** Atualmente, o suporte à criação de perfil para atividades de GPU é baseado em C++ AMP e outros modelos de programação baseados em Direct3D.

#### <a name="general-parallel-programming-enhancements"></a>Melhorias na programação paralela em geral

Com o hardware migrando para arquiteturas de vários núcleos, os desenvolvedores não podem mais depender das crescentes velocidades de clock de um único núcleo. O suporte à programação paralela em Tempo de Execução de Simultaneidade permite que os desenvolvedores aproveitem essas novas arquiteturas.
No Visual Studio 2010, foram introduzidas bibliotecas de paralelização avançadas em C++ , como a Biblioteca de padrões paralelos, juntamente com recursos para aproveitar a simultaneidade ao expressar pipelines de fluxo de dados sofisticados. No Visual Studio 2012, essas bibliotecas foram estendidas para fornecer melhor desempenho, mais controle e suporte mais amplo a padrões paralelos que os desenvolvedores tanto precisam. A abrangência da oferta agora inclui:

- Um rico modelo de programação baseado em tarefas que é compatível com a assincronia e continuações.
- Algoritmos paralelos, que dão suporte ao paralelismo fork-join (parallel_for, parallel_for with affinity, parallel_for_each, parallel_sort, parallel_reduce, parallel_transform).
- Contêineres à prova de simultaneidade, que fornecem versões thread-safe de estruturas de dados std, como priority_queue, fila, vetor e mapa.
- A Biblioteca de agentes assíncronos, que os desenvolvedores podem usar para expressar pipelines de fluxos de dados, que se decompõem naturalmente em unidades simultâneas.
- Um agendador personalizável e um gerenciador de recursos para facilitar a composição suave dos padrões nessa lista.

##### <a name="general-parallel-debugging-enhancements"></a>Melhorias na depuração paralela em geral

Além da janela **Tarefas Paralelas** e **Pilhas Paralelas**, o Visual Studio 2012 oferece uma nova janela **Inspeção Paralela** para que você possa examinar os valores de uma expressão em todos os threads e processos e realizar classificação e filtragem do resultado. Você também pode usar seus próprios visualizadores para estender a janela, além de aproveitar o novo suporte de vários processos em todas as janelas de ferramenta.

### <a name="ide"></a>IDE

**Suporte a modelos do Visual Studio.** Agora você pode usar a tecnologia de modelos do Visual Studio para criar modelos de projeto e item em C++.

**Carga da solução assíncrona.** Os projetos agora são carregados de forma assíncrona, as partes principais da solução primeiro — para que você possa começar a trabalhar mais rapidamente.

**Implantação automatizada para depuração remota.** A implantação de arquivos para depuração remota no Visual C++ foi simplificada. A opção **Implantar** no menu de contexto do projeto copia automaticamente para o computador remoto os arquivos especificados nas propriedades de configuração de depuração. Não é mais necessário copiar arquivos manualmente no computador remoto.

**IntelliSense para C++/CLI.** C++/CLI agora tem total suporte IntelliSense. Recursos de IntelliSense, como informações rápidas, ajuda de parâmetro, membros da lista e preenchimento automático agora funcionam para C++/CLI. Além disso, outras melhorias de IntelliSense e IDE listadas neste documento também funcionam para C++/CLI.

**Dicas mais valiosas da ferramenta IntelliSense.** As dicas de ferramenta Informações Rápidas do IntelliSense do C++ agora apresentam informações de estilo de comentários de documentação XML mais valiosas. Se você estiver usando uma API de uma biblioteca – por exemplo, C++ AMP – que tenha comentários de documentação XML, a dica de ferramenta do IntelliSense mostrará mais informações do que apenas a declaração. Além disso, se o seu código tiver os comentários de documentação XML, as dicas de ferramentas do IntelliSense mostrarão informações mais valiosas.

**Construções de código C++.** O código de esqueleto está disponível para alternância, if-else, loop e outras construções básicas de código, na lista suspensa Membros da Lista. Selecione um trecho de código da lista para inseri-lo em seu código e, em seguida, preencha a lógica necessária. Crie também seus próprios trechos personalizados de código para uso no editor.

**Melhorias nos membros da lista.** A lista suspensa **Membros da Lista** aparece automaticamente quando você digita o código no editor de código. Os resultados são filtrados, para que apenas os membros relevantes sejam exibidos conforme você digita. Você pode controlar o tipo de lógica de filtragem usada pela Lista de Membros na caixa de diálogo **Opções**, em **Editor de Texto** > **C/C++** > **Avançado**.

**Colorização Semântica.** Tipos, enumerações, macros e outros tokens C++ agora têm colorização por padrão.

**Realce de referência.** A seleção de um símbolo agora realça todas as instâncias do símbolo no arquivo atual. Pressione **Ctrl**+**Shift**+**Seta para Cima** ou **Ctrl**+**Shift**+**Seta para Baixo** para percorrer as referências realçadas. Você pode desabilitar esse recurso na caixa de diálogo **Opções**, em **Editor de Texto** > **C/C++** > **Avançado**.

### <a name="application-lifecycle-management-tools"></a>Ferramentas de gerenciamento de ciclo de vida do aplicativo

#### <a name="static-code-analysis"></a>Análise de código estático

Análise estática para C++ foi atualizada para fornecer informações de contexto de erro mais avançadas, mais regras de análise, e melhores resultados de análise. Na nova janela Análise de Código, filtre as mensagens por palavra-chave, projeto e severidade. Quando você seleciona uma mensagem na janela, a linha no código em que a mensagem foi acionada é realçada no editor de códigos. Para determinados avisos de C++, a mensagem de lista linhas de origem que mostram o caminho de execução que leva ao aviso. Pontos de decisão e os motivos para esse caminho específico são realçados.
A análise de código é incluída na maioria das edições do Visual Studio 2012. Nas edições Professional, Premium e Ultimate, todas as regras são incluídas. Nas edições Express do Windows 8 e Windows Phone, apenas os avisos mais críticos são incluídos. A análise de código não está incluída na edição Express para Web.
Aqui estão algumas outras melhorias da análise de código:

- Novos avisos de simultaneidade ajudarão você a evitar bugs de simultaneidade, assegurando o uso correto das disciplinas de bloqueio em programas multi-threaded do C/C++. O analisador detecta possíveis condições de corrida, inversões na ordem de bloqueio, violações de contrato de bloqueio de chamador/receptor, operações de sincronização não correspondentes e outros bugs de simultaneidade.
- Especifique as regras de C++ que você quer aplicar em execuções de análise de código usando conjuntos de regras.
- Na janela **Análise de Código**, é possível inserir um pragma no código-fonte que suprime um aviso selecionado.
- Melhore a precisão e a integridade da análise de código estático usando a nova versão de SAL (Linguagem de Anotação do Código-Fonte) da Microsoft para descrever como uma função usa seus parâmetros, as suposições que faz sobre eles e as garantias que oferece quando concluída.
- Suporte para projetos do C++ de 64 bits.

#### <a name="updated-unit-test-framework"></a>Estrutura de teste de unidade atualizada

Use a nova estrutura de teste da unidade C++ no Visual Studio para escrever testes de unidade do C++. Adicione um novo projeto de teste da unidade à solução C++ existente, posicionando o modelo de projeto de teste da unidade C++ sob a categoria Visual C++, na caixa de diálogo Novo Projeto. Comece a gravar os testes de unidade no stub do código TEST_METHOD gerado, no arquivo Unittest1.cpp. Quando o código de teste for escrito, compile a solução. Quando você quiser executar os testes, abra uma janela **Gerenciador de Testes de Unidade** escolhendo **Exibir** > **Outras Janelas** > **Gerenciador de Testes de Unidade** e em seguida, no menu de atalho do caso de teste que você deseja, escolha **Executar teste selecionado**. Após a execução do teste, exiba os resultados do teste e as informações adicionais de rastreamento de pilha na mesma janela.

#### <a name="architecture-dependency-graphs"></a>Gráficos de dependência de arquitetura

Para entender melhor o seu código, gere gráficos de dependência para binário, classe, namespace e arquivos de inclusão em uma solução. Na barra de menus, escolha **Arquitetura** > **Gerar Grafo de Dependência** e, em seguida, **Para Solução** ou **Para Arquivo de Inclusão** para gerar um grafo de dependência. Quando a geração do gráfico for concluída, você poderá explorá-lo expandindo cada nó, saber mais sobre os relacionamentos de dependência percorrendo os nós e procurar o código-fonte escolhendo **Exibir Conteúdo** no menu de atalho de um nó. Para gerar um grafo de dependência para arquivos de inclusão, no menu de atalho de um arquivo de código-fonte \*.cpp ou arquivo de cabeçalho \*.h, escolha **Gerar Grafo de Arquivos de Inclusão**.

#### <a name="architecture-explorer"></a>Architecture Explorer

Usando o **Gerenciador de Arquitetura**, você pode explorar os ativos, projetos ou arquivos em sua solução C++. Na barra de menus, escolha **Arquitetura** > **Windows** > **Gerenciador de Arquitetura**. Você pode selecionar um nó em que esteja interessado, por exemplo, **Modo de Exibição de Classe**. Nesse caso, o lado direito da janela de ferramentas é expandido com uma lista de namespaces. Se você selecionar um namespace, uma nova coluna mostrará uma lista de classes, estruturas e enumerações nesse namespace. Continue a explorar esses ativos ou volte para a coluna na extremidade esquerda para iniciar outra consulta. Confira **Localizar código com o Gerenciador de Arquitetura**.

#### <a name="code-coverage"></a>Cobertura de código

A cobertura de código foi atualizada para instrumentar dinamicamente arquivos binários em tempo de execução. Isso reduz a sobrecarga de configuração e fornece melhor desempenho. Colete dados de cobertura de código dos testes de unidade para aplicativos em C++. Depois de criar testes de unidade do C++, use o **Gerenciador de Testes de Unidade** para descobrir testes em sua solução. Para executar os testes de unidade e coletar dados de cobertura de código para eles, no **Gerenciador de Testes de Unidade**, escolha **Analisar Cobertura de Código**. Examine os resultados da cobertura de código na janela **Resultados de Cobertura de Código**. Na barra de menus, escolha **Teste** > **Windows** > **Resultados da Cobertura de Código**.

## <a name="whats-new-for-c-in-visual-studio-2010"></a>Novidades do C++ no Visual Studio 2010

### <a name="c-compiler-and-linker"></a>Compilador e vinculador do C++

**Palavra-chave auto** A palavra-chave **auto** tem uma nova finalidade. Use o significado padrão da palavra-chave **auto** para declarar uma variável cujo tipo é deduzido da expressão de inicialização na declaração da variável. A opção do compilador `/Zc:auto` invoca o significado novo ou anterior da palavra-chave **auto**.

**Especificador de tipo decltype.** O especificador de tipo **decltype** retorna o tipo de uma expressão especificada. Use o especificador de tipo **decltype** em combinação com a palavra-chave **auto** para declarar um tipo complexo ou conhecido apenas pelo compilador. Por exemplo, use a combinação para declarar uma função de modelo cujo tipo de retorno depende dos tipos de argumentos do modelo. Ou, declare uma função de modelo que chame outra função e, em seguida, retorna o tipo de retorno da função chamada.

**Expressões lambda.** Funções “lambda” têm um corpo de função, mas não têm nome. Elas combinam as melhores características de ponteiros de função e objetos de função. Use uma função lambda sozinha, como um parâmetro de função de modelo em vez de um objeto de função, ou em conjunto com a palavra-chave **auto** para declarar uma variável cujo tipo é uma lambda.

**Referência Rvalue.** O declarador de referência RValue (&&) declara uma referência a um rvalue. Uma referência rvalue permite usar semântica de transferência de recursos e encaminhamento perfeito para gravar construtores, funções e modelos mais eficientes.

**Declaração static_assert.** Uma declaração **static_assert** testa uma asserção de software no tempo de compilação, ao contrário de outros mecanismos de asserção, que testam no tempo de execução. Se a asserção falhar, a compilação falhará e uma mensagem de erro específica será emitida.

**Palavras-chave nullptr e __nullptr.** O compilador do Visual C++ permite que você use a palavra-chave **nullptr** com o código nativo ou com o código gerenciado. A palavra-chave **nullptr** indica que um identificador de objeto, ponteiro interior ou tipo de ponteiro nativo não aponta para um objeto. O compilador interpreta **nullptr** como código gerenciado quando você usa a opção do compilador `/clr` e como código nativo quando você não usa a opção `/clr`.
A palavra-chave **__nullptr** específica da Microsoft tem o mesmo significado que **nullptr**, mas aplica-se apenas ao código nativo. Se você compilar o código C/C++ nativo usando a opção do compilador `/clr`, o compilador não poderá determinar se a palavra-chave **nullptr** é um termo nativo ou gerenciado. Para tornar sua intenção clara para o compilador, use a palavra-chave nullptr para especificar o termo gerenciado e **__nullptr** para especificar o termo nativo.

**Opção do compilador /Zc:trigraphs.** Por padrão, o suporte para trígrafos está desabilitado. Use a opção do compilador `/Zc:trigraphs` para habilitar o suporte a trígrafos.
Um trígrafo consiste em dois pontos de interrogação consecutivos (??) seguidos por um terceiro caractere exclusivo. O compilador substitui um trígrafo por um caractere de pontuação correspondente. Por exemplo, o compilador substitui o trígrafo ??= pelo caractere # (sinal de número). Use trígrafos em arquivos de origem C que utilizam um conjunto de caracteres sem determinados caracteres de pontuação.

**Nova opção Otimização Guiada Por Perfil.** PogoSafeMode é uma nova opção de otimização guiada por perfil que permite que você especifique se quer usar o modo de segurança ou o modo rápido ao otimizar o aplicativo. O modo de segurança é thread-safe, mas é mais lento do que o modo rápido. Modo rápido é o comportamento padrão.

**Nova opção de CLR (Common Language Runtime) /clr:nostdlib.** Uma nova opção foi adicionada para `/clr` (Compilação do Common Language Runtime). Será emitido um erro de compilação se versões diferentes da mesma biblioteca forem incluídas. A nova opção permite que você exclua as bibliotecas CLR padrão, para que seu programa possa usar uma versão especificada.

**Nova diretiva pragma detect_mismatch.** A diretiva de pragma detect_mismatch permite que você coloque uma marca em seus arquivos que seja comparada a outras com o mesmo nome. Se houver diversos valores para o mesmo nome, o vinculador emitirá um erro.

**Intrínsecos de XOP, FMA4 e LWP.** Novas funções intrínsecas foram adicionadas para dar suporte a intrínsecos de XOP adicionados para Visual Studio 2010 SP1, intrínsecos de FMA4 adicionados para Visual Studio 2010 SP1 e intrínsecos de LWP adicionados para tecnologias de processador do Visual Studio 2010 SP1. Use __cpuid, __cpuidex para determinar quais tecnologias de processador são compatíveis com um computador específico.

### <a name="visual-c-projects-and-the-build-system"></a>Projetos do Visual C++ e o sistema de compilação

**MSBuild.** Projetos e soluções do Visual C++ agora são criados usando o MSBuild.exe, que substitui o VCBuild.exe. MSBuild é a mesma ferramenta de compilação extensível, flexível e baseada em XML, usada por outras linguagens e tipos de projeto do Visual Studio. Por causa dessa alteração, os arquivos do projeto Visual C++ agora usam um formato de arquivo XML e têm a extensão de nome de arquivo .vcxproj. Arquivos de projeto do Visual C ++ de versões anteriores do Visual Studio são convertidos automaticamente ao novo formato de arquivo.

**Diretórios VC++.** A configuração dos diretórios VC++ agora está localizada em dois locais. Use páginas de propriedades do projeto para definir valores por projeto para diretórios VC++. Use o **Gerenciador de Propriedades** e uma folha de propriedades para definir valores globais para cada configuração para os diretórios VC++.

**Dependências por projeto.** Em versões anteriores, dependências definidas entre projetos eram armazenadas no arquivo de soluções. Quando essas soluções são convertidas no novo formato de arquivo de projeto, as dependências são convertidas em referências por projeto. Essa alteração pode afetar os aplicativos porque os conceitos de dependências de solução e as referências por projeto são diferentes.

**Macros e variáveis de ambiente.** A nova macro _ITERATOR_DEBUG_LEVEL invoca o suporte à depuração de iteradores. Use esta macro em vez das macros _SECURE_SCL e _HAS_ITERATOR_DEBUGGING mais antigas.

### <a name="visual-c-libraries"></a>Bibliotecas do Visual C++

**Bibliotecas de Tempo de Execução de Simultaneidade.** A estrutura de Tempo de Execução de Simultaneidade é compatível com aplicativos e componentes executados simultaneamente e é a estrutura para a programação de aplicativos simultâneos no Visual C++. Para dar suporte à programação de aplicativo simultâneos, a PPL (Biblioteca de Padrões Paralelos) fornece algoritmos e contêineres para fins gerais, para executar o paralelismo refinado. A Biblioteca de Agentes Assíncronos fornece um modelo de programação baseado em ator e interfaces de passagem de mensagens para tarefas de fluxo de dados e pipelining de alta granularidade.

**Biblioteca C++ padrão.** A lista a seguir descreve muitas das alterações feitas na Biblioteca C++ padrão.

- O novo recurso de linguagem C++ de referência rvalue foi usado para implementar semântica de transferência de recursos e encaminhamento perfeito para muitas funções na Biblioteca de Modelos Padrão. Semântica de transferência de recursos e encaminhamento perfeito melhoram significativamente o desempenho das operações que alocam ou atribuem variáveis ou parâmetros.
- As referências a Rvalue também são usadas para implementar a nova classe `unique_ptr`, que é um tipo de ponteiro inteligente mais seguro do que a classe `auto_ptr`. A classe `unique_ptr` é móvel, mas não copiável, implementa uma semântica de propriedade estrita sem afetar a segurança e funciona bem com contêineres que reconhecem as referências de rvalue. A classe `auto_ptr` foi preterida.
- Quinze novas funções, por exemplo, `find_if_not`, `copy_if` e `is_sorted`, foram adicionadas ao cabeçalho \<algorithm>.
- No cabeçalho \<memory>, a nova função make_shared é uma maneira conveniente, robusta e eficiente de fazer com que um ponteiro compartilhado aponte para um objeto enquanto o objeto é construído.
- O cabeçalho \<forward_list > é compatível com listas vinculadas individualmente.
- As novas funções de membro `cbegin`, `cend`, `crbegin` e `crend` fornecem um `const_iterator` que se move para frente ou para trás em um contêiner.
- O cabeçalho \<system_error > e os modelos relacionados dão suporte ao processamento de erros de sistema de baixo nível. Membros da classe `exception_ptr` podem ser usados para transportar exceções entre threads.
- O cabeçalho \<codecvt > é compatível com a conversão de várias codificações de caracteres Unicode em outras codificações.
- O cabeçalho \<allocators> define vários modelos que ajudam a alocar e a liberar blocos de memória para contêineres baseados em nós.
- Há várias atualizações para o cabeçalho \<random>.

### <a name="microsoft-foundation-class-mfc-library"></a>Biblioteca MFC (Microsoft Foundation Class)

**Recursos do Windows 7.** O MFC é compatível com muitos recursos do Windows 7, como interface do usuário da faixa de opções (IU), barra de tarefas, lista de atalhos, miniaturas com guias, visualizações de miniatura, barra de progresso, sobreposição de ícone e indexação de pesquisa. Como o MFC é automaticamente compatível com muitos recursos do Windows 7, talvez você não tenha que modificar o aplicativo existente. Para dar suporte a outros recursos em novos aplicativos, use o Assistente de aplicativo MFC para especificar a funcionalidade que você quer usar.

**Reconhecimento de multitoque.** O MFC é compatível com aplicativos que têm uma interface de usuário multitoque, por exemplo, aplicativos gravados para o sistema operacional Microsoft Surface. Um aplicativo multitoque pode processar mensagens de toque e gesto do Windows, que são combinações de mensagens de toque. Basta registrar o aplicativo para eventos de toque e gesto, e o sistema operacional encaminhará os eventos multitoque para os manipuladores de eventos.

**Reconhecimento de alto DPI.** Por padrão, os aplicativos MFC agora reconhecem DPI alto. Se um aplicativo tiver alto DPI (pontos altos por polegada), o sistema operacional poderá dimensionar janelas, texto e outros elementos de interface do usuário para a resolução da tela atual. Isso significa que uma imagem dimensionada tem mais probabilidade de ser posicionada corretamente e não recortada ou pixelada.

**Gerenciador de reinicialização.** O Gerenciador de reinicialização salva documentos automaticamente e reinicia o aplicativo se ele fecha ou reinicia inesperadamente. Por exemplo, você pode usar o gerenciador de reinicialização para iniciar o aplicativo depois que ele é fechado por uma atualização automática. Para obter mais informações sobre como configurar seu aplicativo para usar o gerenciador de reinicialização, confira **Como adicionar suporte ao gerenciador de reinicialização**.

**CTaskDialog.** A classe `CTaskDialog` pode ser usada em vez da caixa de mensagens `AfxMessageBox` padrão. A classe `CTaskDialog` exibe e reúne mais informações do que a caixa de mensagens padrão.

#### <a name="safeint-library"></a>Biblioteca de SafeInt

A nova biblioteca de SafeInt executa operações aritméticas seguras que levam em conta o estouro de inteiros. Essa biblioteca também compara os diferentes tipos de inteiros.

#### <a name="new-active-template-library-atl-macros"></a>Novas macros de ATL (Active Template Library)

Foram adicionadas novas macros à ATL para expandir a funcionalidade de PROP_ENTRY_TYPE e PROP_ENTRY_TYPE_EX. PROP_ENTRY_INTERFACE e PROP_ENTRY_INTERFACE_EX permitem que você adicione uma lista de CLSIDs válidos. PROP_ENTRY_INTERFACE_CALLBACK e PROP_ENTRY_INTERFACE_CALLBACK_EX permitem que você especifique uma função de retorno de chamada para determinar se um CLSID é válido.

#### <a name="analyze-warnings"></a>Avisos de /analyze

A maioria dos avisos `/analyze` (Análise de Código da Empresa) foi removida das bibliotecas CRT (C Run-Time), MFC e ATL.

#### <a name="animation-and-d2d-support"></a>Animação e suporte D2D

O MFC agora é compatível com a animação e elementos gráficos do Direct2D. A biblioteca do MFC tem várias novas classes MFC e funções para dar suporte a essa funcionalidade. Também há dois novos passo a passo que mostram como adicionar um objeto D2D e um objeto de animação a um projeto. Estes passo a passos são **Passo a passo: adicionando um objeto D2D a um projeto MFC** e **Passo a passo: adicionando animação a um projeto MFC**.

### <a name="ide"></a>IDE

**IntelliSense aperfeiçoado.** O IntelliSense para o Visual C++ foi completamente reformulado para ser mais rápido, preciso e capaz de processar projetos maiores. Para alcançar essa melhoria, o IDE faz distinção entre como um desenvolvedor exibe e modifica o código-fonte e como o IDE usa configurações de projeto e o código-fonte para criar uma solução.
Devido a essa separação de obrigações, os recursos de navegação, como **Modo de Exibição de Classe** e a nova caixa de diálogo **Navegar Para**, são tratados por um sistema baseado em um novo arquivo de banco de dados de desktop do SQL Server (.sdf), que substitui o antigo arquivo de navegação não compilado (.ncb). Recursos do IntelliSense, como Informações rápidas, Preenchimento automático e Ajuda do parâmetro só analisa unidades de tradução quando necessário. Os recursos híbridos, como a nova janela **Hierarquia de Chamada**, usam uma combinação dos recursos de navegação e do IntelliSense.
Como o IntelliSense só processa as informações que você precisa no momento, o IDE é mais ágil na resposta. Além disso, como informações mais atualizadas, janelas e exibições IDE são mais precisas. Por fim, como a infraestrutura do IDE é mais bem organizada, mais capaz e escalonável, pode processar projetos maiores.

**Detecção aperfeiçoada de erros do IntelliSense.** O IDE detecta melhor os erros que podem causar perda do IntelliSense e exibe sublinhados ondulados vermelhos sob eles. Além disso, o IDE informa os erros do IntelliSense para a **Janela de Lista de Erros**. Para exibir o código que está causando o problema, clique duas vezes no erro na **Janela de Lista de Erros**.

**Recurso #include de preenchimento automático.** O IDE dá suporte para preenchimento automático da palavra-chave `#include`. Quando você digita `#include`, o IDE cria uma caixa de listagem suspensa de arquivos de cabeçalho válidos. Se continuar digitando um nome de arquivo, o IDE filtrará a lista com base na sua entrada. A qualquer momento,selecione na lista o arquivo que você quer incluir. Isso permite que você inclua arquivos rapidamente sem saber o nome exato deles.

**Navegar Para.** A caixa de diálogo **Navegar Para** permite procurar todos os símbolos e arquivos no projeto que correspondem a uma cadeia de caracteres especificada. Os resultados da pesquisa são revisados imediatamente conforme você digita caracteres adicionais na cadeia de pesquisa. O campo de comentários **Resultados** informa o número de itens encontrados e ajuda você a decidir se deseja restringir a pesquisa. Os campos de comentários **Tipo/Escopo**, **Local** e **Visualização** ajudam a desfazer a ambiguidade de itens com nomes semelhantes. Além disso, você pode estender esse recurso para dar suporte a outras linguagens de programação.

**Depuração e criação de perfil paralelas.** O depurador do Visual Studio está ciente do Tempo de Execução de Simultaneidade e ajuda você a solucionar problemas de aplicativos de processamento paralelo. Use a nova ferramenta de criador de perfil de simultaneidade para visualizar o comportamento geral do aplicativo. Use também a nova janela de ferramentas para visualizar o estado de tarefas e suas pilhas de chamadas.

**Designer da faixa de opções.** O **Designer de Faixa de Opções** é um editor gráfico que permite criar e modificar uma interface do usuário da faixa de opções do MFC. A faixa de opções final da interface do usuário é representada por um arquivo de recurso baseado em XML (.mfcribbon-ms). Para aplicativos existentes, capture a interface do usuário da faixa de opções atual adicionando temporariamente algumas linhas de código e invocando o **Designer de Faixa de Opções**. Depois que o arquivo de recursos da faixa de opções é criado, substitua a interface do usuário da faixa de opções manuscrita com algumas instruções que carregam o recurso de faixa de opções.

**Hierarquia de Chamadas.** A janela **Hierarquia de Chamadas** permite navegar para todas as funções chamadas por uma função específica ou para todas as funções que chamam uma função específica.

### <a name="tools"></a>Ferramentas

**Assistente de classe do MFC.** O Visual C++ 2010 recupera a conceituada ferramenta Assistente de classe do MFC. O Assistente de classe MFC é uma maneira conveniente de adicionar classes, mensagens e variáveis em um projeto sem a necessidade de modificar manualmente os conjuntos de arquivos de origem.

**Assistente de controle de ATL.** O Assistente de Controle de ATL não preenche mais o campo `ProgID` automaticamente. Se um controle de ATL não tiver um `ProgID`, outras ferramentas poderão não funcionar com ele. Um exemplo de uma ferramenta que requer que os controles tenham uma `ProgID` é a caixa de diálogo **Inserir Controle Ativo**. Para obter mais informações sobre a caixa de diálogo, confira **Inserir caixa de diálogo de controle ActiveX**.

### <a name="microsoft-macro-assembler-reference"></a>Referência do Microsoft Macro Assembler

A adição do tipo de dados YMMWORD é compatível com operandos multimídia de 256 bits, incluídos nas instruções de AVX (Extensões de Vetor Avançadas).

## <a name="whats-new-for-c-in-visual-studio-2008"></a>Novidades do C++ no Visual Studio 2008

### <a name="visual-c-integrated-development-environment-ide"></a>IDE (Ambiente de Desenvolvimento Integrado) do Visual C++

- Caixas de diálogo criadas em aplicativos ATL, MFC e Win32 agora estão em conformidade com as diretrizes de estilo do Windows Vista. Quando você cria um novo projeto usando o Visual Studio 2008, todas as caixas de diálogo inseridas no aplicativo deverão estar em conformidade com as diretrizes de estilo do Windows Vista. Se você recompilar um projeto criado com uma versão anterior do Visual Studio, as caixas de diálogo existentes manterão a mesma aparência de antes. Para obter mais informações de como inserir caixas de diálogo em seu aplicativo, confira **Editor de Caixa de Diálogo**.

- O assistente do **Projeto de ATL** agora tem uma opção para registrar componentes para todos os usuários. Começando com o Visual Studio 2008, os componentes COM e as bibliotecas de tipos criados pelo assistente de **Projeto de ATL** são registrados no nó HKEY_CURRENT_USER do Registro, a menos que você selecione **Registrar componente para todos os usuários**.
- O assistente de **Projeto de ATL** não fornece mais uma opção para criar projetos de ATL atribuídos. Começando com o Visual Studio 2008, o assistente de **Projeto da ATL** não tem uma opção para alterar o status atribuído de um novo projeto. Todos os novos projetos de ATL que o assistente cria agora são não atribuídos.
- A gravação do Registro pode ser redirecionada. Com a introdução do Windows Vista, a gravação em certas áreas do Registro exige um programa para ser executado no modo elevado. Não é aconselhável executar o Visual Studio sempre no modo elevado. O redirecionamento por usuário redireciona automaticamente gravações de Registro de HKEY_CLASSES_ROOT para HKEY_CURRENT_USER sem qualquer alteração na programação.
- O **Designer de Classe** agora tem suporte limitado para código C++ nativo. Nas versões anteriores do Visual Studio, o **Designer de Classe** funcionava somente com Visual C# e Visual Basic. Os usuários do C++ agora podem usar o **Designer de Classe**, mas apenas no modo somente leitura. Para obter mais informações de como usar o **Designer de Classe** com o C++, confira **Working with Visual C++ Code in Class Designer** (Trabalhando com código do Visual C++ no Designer de Classe).
- O Assistente de projeto não tem mais uma opção de criar um projeto do SQL Server do C++. A partir do Visual Studio 2008, o assistente de novo projeto não tem uma opção para criar um projeto do SQL Server do C++. Os projetos do SQL Server criados usando uma versão anterior do Visual Studio ainda serão compilados e funcionarão corretamente.

### <a name="visual-c-libraries"></a>Bibliotecas do Visual C++

#### <a name="general"></a>Geral

- Aplicativos podem ser associados a versões específicas de bibliotecas do Visual C++. Às vezes, um aplicativo depende de atualizações feitas nas bibliotecas do Visual C++ após uma versão. Nesse caso, a execução do aplicativo em um computador com versões anteriores das bibliotecas pode causar um comportamento inesperado. Agora você pode associar um aplicativo a uma versão específica das bibliotecas para que ele não seja executado em um computador com uma versão anterior das bibliotecas.

#### <a name="stlclr-library"></a>Biblioteca STL/CLR

- O Visual C++ agora inclui a biblioteca STL/CLR. A biblioteca STL/CLR é um pacote do STL (Biblioteca de Modelos Padrão), um subconjunto da biblioteca C++ padrão, para uso com C++ e CLR (Common Language Runtime) do .NET Framework. Com o STL/CLR, agora você pode usar todos os contêineres, iteradores e algoritmos de STL em um ambiente gerenciado.

#### <a name="mfc-library"></a>Biblioteca do MFC

- O Windows Vista é compatível com controles comuns. Mais de 150 métodos em 18 classes novas ou existentes foram adicionados para dar suporte a recursos no Windows Vista, ou para melhorar a funcionalidade das classes atuais do MFC.
- A nova classe `CNetAddressCtrl` permite inserir e validar endereços IPv4 e IPv6 ou nomes DNS.
- A nova classe `CPagerCtrl` simplifica o uso do controle de paginação do Windows.
- A nova classe `CSplitButton` simplifica o uso do controle splitbutton do Windows para selecionar uma ação padrão ou opcional.

#### <a name="c-support-library"></a>Biblioteca de suporte do C++

- O C++ apresenta a biblioteca de marshaling. A biblioteca de marshaling fornece uma maneira fácil e otimizada para realizar marshaling de dados entre ambientes gerenciados e nativos. A biblioteca é uma alternativa para abordagens mais complexas e menos eficientes, como o uso de PInvoke. Para obter mais informações, consulte **Visão geral de marshaling no C++**.

#### <a name="atl-server"></a>Servidor ATL

- O servidor ATL é liberado como um projeto de origem compartilhado.
- A maior parte da base de código do servidor ATL foi liberada como um projeto de origem compartilhada no CodePlex e não está instalada como parte do Visual Studio 2008. Vários arquivos associados ao servidor ATL não fazem mais parte do Visual Studio. Para obter a lista de arquivos removidos, confira **Arquivos do servidor ATL removidos**.
- As classes de codificação e decodificação de dados das funções de atlenc.h e utilitários e classes de atlutil.h e atlpath.h agora fazem parte da biblioteca ATL.
- A Microsoft continuará a dar suporte a versões de servidor ATL incluídas em versões anteriores do Visual Studio, enquanto houver suporte para essas versões do Visual Studio. O CodePlex continuará o desenvolvimento do código do servidor ATL como um projeto comunitário. A Microsoft não dá suporte à versão de CodePlex do servidor ATL.

### <a name="visual-c-compiler-and-linker"></a>Compilador e vinculador do Visual C++

#### <a name="compiler-changes"></a>Alterações no compilador

- O compilador é compatível com compilações incrementais gerenciadas. Quando você especifica essa opção, o compilador não recompila o código quando um assembly referenciado é alterado. Em vez disso, ele executa uma compilação incremental. Os arquivos só serão recompilados se as alterações afetarem o código dependente.
- Não há mais suporte para atributos relacionados ao servidor ATL. O compilador não é mais compatível com vários atributos diretamente associados ao Servidor ATL. Para obter uma lista completa dos atributos removidos, consulte Alterações significativas.
- O compilador é compatível com a microarquitetura Intel Core. O compilador contém de ajuste para a microarquitetura Intel Core durante a geração de código. Por padrão, esse ajuste permanece ativo e não pode ser desabilitado, pois também ajuda o Pentium 4 e outros processadores.
- Intrínsecos dão suporte a processadores AMD e Intel mais recentes. Várias novas instruções intrínsecas dão suporte a mais funcionalidades em processadores AMD e Intel mais recentes. Para obter mais informações sobre os novos intrínsecos, confira **Supplemental Streaming SIMD Extensions 3 Instructions** (Instruções suplementais de extensões SIMD de streaming 3), **Streaming SIMD Extensions 4 Instructions** (Instruções de streaming de extensões SIMD 4), **SSE4A and Advanced Bit Manipulation Intrinsics** (Intrínsecos avançados de manipulação de bits e SSE4A), **AES Intrinsics** (Intrínsecos AES), **_mm_clmulepi64_si128** e **__rdtscp**.
- A função `__cpuid` foi atualizada. As funções `__cpuid` e `__cpuidex` agora dão suporte a vários novos recursos das últimas revisões dos processadores AMD e Intel. O intrínseco `__cpuidex` é novo e reúne mais informações de processadores recentes.
- A opção do compilador `/MP` reduz o tempo de build total. A opção `/MP` pode reduzir significativamente o tempo total para compilar vários arquivos de origem com a criação de vários processos que compilam os arquivos simultaneamente. Essa opção é especialmente útil em computadores que dão suporte a hyperthreading, vários processadores ou vários núcleos.
- A opção do compilador `/Wp64` e a palavra-chave **__w64** foram preteridas. A opção do compilador `/Wp64` e a palavra-chave **__w64**, que detectam problemas de portabilidade de 64 bits, foram preteridas e serão removidas em uma versão futura do compilador. Em vez dessa opção do compilador e palavra-chave, use um compilador do Visual C++ para uma plataforma de 64 bits.
- `/Qfast_transcendentals` gera código embutido para funções transcendentais.
- `/Qimprecise_fwaits` remove os comandos fwait internos para tentar blocos quando você usa a opção do compilador `/fp:except`.

### <a name="linker-changes"></a>Alterações no vinculador

- As informações do Controle de conta de usuário agora são incorporadas em arquivos de manifesto para executáveis pelo vinculador do Visual C ++ (link.exe). Esse recurso é habilitado por padrão. Para obter mais informações de como desabilitar esse recurso ou de como modificar o comportamento padrão, confira `/MANIFESTUAC` (insere informações de UAC no manifesto).
- O vinculador agora tem a opção `/DYNAMICBASE` para habilitar o recurso de Aleatoriedade de Layout do Espaço de Endereço do Windows Vista. Essa opção modifica o cabeçalho de um executável para indicar se o aplicativo deve trocar de base aleatoriamente de novo no tempo de carregamento.

## <a name="whats-new-for-c-in-visual-studio-2005"></a>Novidades do C++ no Visual Studio 2005

Os seguintes recursos são novos no Visual Studio 2005 – Service Pack 1:

### <a name="intrinsics-for-x86-and-x64"></a>Intrínsecos para x86 e x64

- __halt
- __lidt
- __nop
- __readcr8
- __sidt
- __svm_clgi
- __svm_invlpga
- __svm_skinit
- __svm_stgi
- __svm_vmload
- __svm_vmrun
- __svm_vmsave
- __ud2
- __vmx_off
- __vmx_vmptrst
- __writecr8

### <a name="intrinsics-for-x64-only"></a>Intrínsecos para x64 somente

- __vmx_on
- __vmx_vmclear
- __vmx_vmlaunch
- __vmx_vmptrld
- __vmx_vmread
- __vmx_vmresume
- __vmx_vmwrite

### <a name="new-language-keywords"></a>Novas palavras-chave de linguagem

__sptr, __uptr

### <a name="new-compiler-features"></a>Novos recursos do compilador

O compilador tem alterações significativas nesta versão.

- Compiladores nativos e cruzados de 64 bits.
- A opção do compilador `/analyze` (Análise de Código da Empresa) foi adicionada.
- A opção do compilador `/bigobj` foi adicionada.
- `/clr:pure`, `/clr:safe` e `/clr:oldSyntax` foram adicionados. (Posteriormente preterido no Visual Studio 2015 e removido no Visual Studio 2017.)
- Opções do compilador preteridas: muitas opções de compilador foram preteridas nesta versão. Confira **Opções do compilador preteridas** para obter mais informações.
- A conversão dupla no código `/clr` foi reduzida. Confira **Conversão dupla (C++)** para obter mais informações.
- O `/EH` (Modelo de Tratamento de Exceção) ou o `/EHs` não pode ser mais usado para capturar exceções geradas com algo que não seja um lançamento. Use `/EHa`.
- A opção do compilador `/errorReport` (Relatar Erros Internos do Compilador) foi adicionada.
- A opção do compilador `/favor` (Otimizar para 64) foi adicionada.
- A opção do compilador `/FA`, `/Fa` (Arquivo de Listagem) foi adicionada.
- A opção do compilador `/FC` (Caminho Completo do Arquivo de Código-fonte no Diagnóstico) foi adicionada.
- A opção do compilador `/fp` (Especificar Comportamento de Ponto Flutuante) foi adicionada.
- A opção do compilador `/G` (Otimizar para Processador) foi adicionada.
- A opção do compilador `/G` (Otimizar para Processador) foi adicionada.
- As opções do compilador `/G3`, `/G4`, `/G5`, `/G6`, `/G7` e `/GB` foram removidas. Agora, o compilador usa um "modelo combinado" que as tentativas de criar o melhor arquivo de saída para todas as arquiteturas.
- `/Gf` foi removido. Use `/GF` (Eliminar Cadeias de Caracteres Duplicadas).
- A `/GL` (Otimização de Programa Inteiro) agora é compatível com `/CLRHEADER`.
- `/GR` agora é habilitada por padrão.
- A `/GS` (Verificação de Segurança do Buffer) agora fornece proteção de segurança para parâmetros de ponteiro vulneráveis. `/GS` agora é habilitada por padrão. `/GS` agora também funciona em funções compiladas para MSIL com `/clr` (Compilação do Common Language Runtime).
- A opção do compilador `/homeparams` (Copiar Parâmetros de Registro para Pilha) foi adicionada.
- A opção do compilador `/hotpatch` (Criar Imagem Hotpatchable) foi adicionada.
- A heurística da função embutida foi atualizada. Veja **inline**, **__inline**, **__forceinline** e **inline_depth** para obter mais informações
- Muitas novas funções intrínsecas foram adicionadas e muitos intrínsecos não documentados anteriormente agora estão documentados.
- Por padrão, qualquer nova chamada que falhe lançará uma exceção.
- As opções do compilador `/ML` e `/MLd` foram removidas. O Visual C ++ não é mais compatível com a biblioteca CRT estatisticamente vinculada, single-threaded.
- O compilador implementou a Otimização de Valor Retornado Nomeado, que é habilitada quando você compila com `/O1`, `/O2` (Minimizar Tamanho, Maximizar Velocidade), `/Og` (Otimizações Globais) e `/Ox` (Otimização Completa).
- A opção do compilador `/Oa` foi removida, mas será ignorada silenciosamente. Use os modificadores `noalias` ou `restrict__declspec` para especificar como o compilador faz o alias.
- A opção do compilador `/Op` foi removida. Use `/fp` (Especificar Comportamento de Ponto Flutuante).
- Agora OpenMP é compatível com o Visual C++.
- A opção do compilador `/openmp` (Habilitar Suporte a OpenMP 2.0) foi adicionada.
- A opção do compilador `/Ow` foi removida, mas será ignorada silenciosamente. Use os modificadores `noalias` ou `restrict__declspec` para especificar como o compilador faz o alias.

### <a name="profile-guided-optimizations"></a>Otimizações orientadas a perfil

- `/QI0f` foi removido.
- A `/QIfdiv` foi removida.
- A opção do compilador `/QIPF_B` (Errata de Execução em Etapas da CPU B) foi adicionada.
- A opção do compilador `/QIPF_C` (Errata de Execução em Etapas da CPU C) foi adicionada.
- A opção do compilador `/QIPF_fr32` (Não Usar Registros de Ponto Flutuante Acima de 96) foi adicionada.
- A opção do compilador `/QIPF_noPIC` (Gerar código dependente de posição) foi adicionada.
- A opção do compilador `/QIPF_restrict_plabels` (Supor que Nenhuma Função Foi Criada no Tempo de Execução) foi adicionada.

### <a name="unicode-support-in-the-compiler-and-linker"></a>Suporte Unicode no compilador e vinculador

- `/vd` (Desabilitar Deslocamentos de Construção) agora permite que você use o operador dynamic_cast em um objeto que está sendo construído (/vd2)
- A opção do compilador `/YX` foi removida. Use `/Yc` (Criar Arquivo de Cabeçalho Pré-compilado) ou `/Yu` (Usar Arquivo de Cabeçalho Pré-compilado). Se você remover `/YX` das configurações de build e não o substituir por nada, o resultado poderá ser builds mais rápidos.
- `/Zc:forScope` agora é habilitada por padrão.
- `/Zc:wchar_t` agora é habilitada por padrão.
- A opção do compilador `/Zd` foi removida. Não há mais suporte para informações de depuração apenas em número de linha. Use `/Zi` (veja **/Z7, /Zi, /ZI (Formato de Informações de Depuração)** para obter mais informações).
- `/Zg` agora só é válida em arquivos de código-fonte C e não em arquivos de código-fonte C++.
- A opção do compilador `/Zx` (Depurar Código de Itanium Otimizado) foi adicionada.

### <a name="new-language-features"></a>Novos recursos de linguagem

- O attributeattribute foi preterido.
- O modificador `appdomain__declspec` foi adicionado.
- A convenção de chamada `__clrcall` foi adicionada.
- O modificador **declspec** preterido (C++) agora permite que você especifique uma cadeia de caracteres que será exibida no tempo de compilação, quando um usuário tentar acessar uma classe ou função preterida.
- O operador **dynamic_cast** apresenta alterações da falha.
- Enumerações nativas agora permitem que você especifique o tipo subjacente.
- O modificador `jitintrinsicdeclspec` foi adicionado.
- O modificador `noaliasdeclspec` foi adicionado.
- O modificador `process__declspec` foi adicionado.
- **abstract**, **override** e **sealed** são válidos para compilações nativas.
- A palavra-chave **__restrict** foi adicionada.
- O modificador `restrictdeclspec` foi adicionado.
- **__thiscall** agora é uma palavra-chave.
- A palavra-chave **__unaligned** agora está documentada.
- O comportamento de **volatile** (C++) foi atualizado em relação a otimizações.

### <a name="new-preprocessor-features"></a>Novos recursos do pré-processador

- A macro __CLR_VER predefinida foi adicionada.
- O pragma de comentário (C/C++) agora aceita `/MANIFESTDEPENDENCY` como um comentário do vinculador. A opção exestr para comentário foi preterida.
- O atributo `embedded_idl` (a diretiva `#import`) agora aceita um parâmetro opcional.
- Pragma `fenv_access`
- Pragma `float_control`
- Pragma `fp_contract`
- Variáveis globais não serão inicializadas na ordem em que são declarados se houver variáveis globais no pragma gerenciado, não gerenciado e seções não gerenciadas. Essa será uma mudança potencial significativa se, por exemplo, uma variável global não gerenciada for inicializada com variáveis globais gerenciadas e for necessário um objeto gerenciado totalmente construído.
- Seções especificadas com init_seg agora são somente leitura e não de leitura/gravação como nas versões anteriores.
- O inline_depth padrão agora é 16. Um padrão de 16 também estava em vigor no Visual C++ .NET 2003.
- A macro predefinida _INTEGRAL_MAX_BITS foi adicionada, consulte Macros predefinidas.
- Macros _M_CEE, _M_CEE_PURE e _M_CEE_SAFE predefinidas foram adicionadas, consulte Macros predefinidas.
- A macro _M_IX86_FP predefinida foi adicionada.
- A macro _M_X64 predefinida foi adicionada.
- Pragma `make_public`
- A sintaxe do pragma `managed`, `unmanaged` foi atualizada (agora tem `push` e `pop`)
- mscorlib.dll agora é referenciado implicitamente pela diretiva `#using` em todas as compilações de `/clr`.
- A macro _OPENMP predefinida foi adicionada.
- a otimização do pragma foi atualizada, a e w não são mais parâmetros válidos.
- o atributo no_registry#import foi adicionado.
- Os pragmas `region`, `endregion` foram adicionados
- A macro _VC_NODEFAULTLIB predefinida foi adicionada.
- Macros Variadic agora são implementadas.
- `vtordisp` foi preterido e será removido em uma versão futura do Visual C++.
- O pragma `warning` agora tem o especificador supressão.

### <a name="new-linker-features"></a>Novos recursos do vinculador

- Módulos (arquivos de saída MSIL de não assembly) agora são permitidos como entrada para o vinculador.
- A opção de vinculador `/ALLOWISOLATION` (Pesquisa de Manifesto) foi adicionada.
- `/ASSEMBLYRESOURCE` (Inserir um Recurso Gerenciado) foi atualizada para permitir que você especifique o nome do recurso no assembly e especifique que o recurso é particular no assembly.
- A opção de vinculador `/CLRIMAGETYPE` (Especificar Tipo de Imagem do CLR) foi adicionada.
- A opção do vinculador `/CLRSUPPORTLASTERROR` (Preservar Último Código de Erro para Chamadas PInvoke) foi adicionada.
- A opção do vinculador `/CLRTHREADATTRIBUTE` (Definir Atributo de Thread do CLR) foi adicionada.
- A opção do vinculador `/CLRUNMANAGEDCODECHECK` (Adicionar SuppressUnmanagedCodeSecurityAttribute) foi adicionada.
- A opção do vinculador `/ERRORREPORT` (Relatar Erros Internos do Vinculador) foi adicionada.
- A opção do vinculador `/EXETYPE` foi removida. O vinculador não oferece mais suporte para a criação de drivers de dispositivo do Windows 95 e Windows 98. Use um DDK apropriado para criar esses drivers de dispositivo. A palavra-chave EXETYPE não é mais válida para arquivos de definição de módulo.
- A opção do vinculador `/FUNCTIONPADMIN` (Criar Imagem Hotpatchable) foi adicionada.
- A opção do vinculador `/LTCG` agora é compatível com módulos compilados com `/clr`. A `/LTCG` também foi atualizada para dar suporte a otimizações guiadas por perfil.
- A opção do vinculador `/MANIFEST` (Criar Manifesto do Assembly Lado a Lado) foi adicionada.
- A opção do vinculador `/MANIFESTDEPENDENCY` (Especificar Dependências de Manifesto) foi adicionada.
- A opção do vinculador `/MANIFESTFILE` (Nomear Arquivo de Manifesto) foi adicionada.
- A opção do vinculador `/MAPINFO:LINES` foi removida.
- A opção de vinculador `/NXCOMPAT` (Compatível com Prevenção de Execução de Dados) foi adicionada.
- A opção do vinculador `/PGD` (Especificar Banco de Dados para Otimizações Guiadas por Perfil) foi adicionada.
- A opção do vinculador `/PROFILE` (Criador de Perfil de Ferramentas de Desempenho) foi adicionada.
- A opção do vinculador `/SECTION` (Especificar Atributos de Seção) agora é dá suporte para negação de atributo e não dá mais suporte para os atributos L ou D (relacionados a VxD).
- Suporte Unicode no compilador e vinculador
- A opção do vinculador `/VERBOSE` (Imprimir Mensagens de Andamento) agora também aceita ICF e REF.
- A opção do vinculador `/VXD` foi removida. O vinculador não oferece mais suporte para a criação de drivers de dispositivo do Windows 95 e Windows 98. Use um DDK apropriado para criar esses drivers de dispositivo. A palavra-chave VXD não é mais válida para arquivos de definição de módulo.
- A opção do vinculador `/WS` foi removida. `/WS` foi usado para modificar imagens direcionadas ao Windows NT 4.0. O nome de arquivo IMAGECFG.exe -R pode ser usado em vez de `/WS`. IMAGECFG.exe pode ser encontrado no CD-ROM do Windows NT 4.0, em SUPPORT\DEBUG\I386\IMAGECFG.EXE.
- A opção do vinculador `/WX` (Tratar Avisos do Vinculador como Erros) agora está documentada.

### <a name="new-linker-utility-features"></a>Novos recursos utilitários do vinculador

- A opção editbin `/ALLOWISOLATION` foi adicionada
- A instrução do arquivo de definição do módulo DESCRIPTION foi removida. O vinculador não permite a criação de drivers de dispositivo virtual.
- A opção `/ERRORREPORT` foi adicionada a bscmake.exe, dumpbin.exe, editbin.exe e lib.exe.
- A opção lib `/LTCG` foi adicionada.
- A opção editbin `/NXCOMPAT` foi adicionada.
- A opção dumpbin `/RANGE` foi adicionada.
- A opção dumpbin `/TLS` foi adicionada.
- A opção editbin `/WS` foi removida. `/WS` foi usado para modificar imagens direcionadas ao Windows NT 4.0. O nome de arquivo IMAGECFG.exe -R pode ser usado em vez de `/WS`. IMAGECFG.exe pode ser encontrado no CD-ROM do Windows NT 4.0, em SUPPORT\DEBUG\I386\IMAGECFG.EXE.
- A opção lib /WX[:NO] foi adicionada.

### <a name="new-nmake-features"></a>Novos recursos NMAKE

- A `/ERRORREPORT` foi adicionada.
- A `/G` foi adicionada.
- As regras predefinidas foram atualizadas.
- A macro $(MAKE), que está documentada em Macros de recursão, agora fornece o caminho completo para nmake.exe.

### <a name="new-masm-features"></a>Novos recursos MASM

- As expressões MASM agora têm valores de 64 bits. Em versões anteriores, as expressões MASM eram valores de 32 bits.
- A instrução __asm int 3 agora faz com que uma função seja compilada como nativa.
- O ALIAS (MASM) agora está documentado.
- A opção ml.exe e ml64.exe `/ERRORREPORT` foi adicionada.
- .FPO agora está documentado.
- H2INC.exe não será incluído no Visual C++ 2005. Se você precisa continuar a usar o H2INC, use o H2INC.exe de uma versão anterior do Visual C++.
- O operador IMAGEREL foi adicionado.
- O operador HIGH32 foi adicionado.
- O operador LOW32 foi adicionado.
- ml64.exe é uma versão do MASM para a arquitetura x64. Ele monta arquivos .asm x64 em arquivos de objeto x64. A linguagem assembly embutida não é compatível com o compilador x64. As seguintes diretivas MASM foram adicionadas para ml64.exe (x64):
- .ALLOCSTACK
- .ENDPROLOG
- .PUSHFRAME
- .PUSHREG
- .SAVEREG
- .SAVEXMM128
- .SETFRAME Além disso, a diretiva PROC foi atualizada com sintaxe apenas de x64.
- A diretiva MMWORD foi adicionada
- A `/omf` (opção de linha de comando de ML.exe) agora implica `/c`. ML.exe não dá suporte a vinculação de objetos de formato OMF.
- A diretiva SEGMENT agora é compatível com atributos adicionais.
- O operador SECTIONREL foi adicionado.
- A diretiva XMMWORD foi adicionada

### <a name="new-crt-features"></a>Novos recursos de CRT

- Versões seguras de algumas funções foram adicionadas. Essas funções tratam erros de uma maneira melhor e exigem controles mais rígidos em buffers para ajudar a evitar falhas de segurança comuns. As novas versões seguras são identificadas pelo sufixo **_s**.
- Versões existentes menos seguras de muitas funções foram preteridas. Para desabilitar avisos de reprovação, defina _CRT_SECURE_NO_WARNINGS.
- Muitas funções existentes agora validam seus parâmetros e invocam o manipulador de parâmetro inválido quando um parâmetro inválido é passado.
- Muitas funções existentes agora definem `errno` onde antes não faziam.
- A typedef `errno_t` com o tipo inteiro foi adicionada. `errno_t` é usado sempre que um tipo ou parâmetro de retorno de função lida com códigos de erro de `errno`. `errno_t` substitui `errcode`.
- Funções dependentes de localidade agora têm versões que usam a localidade como parâmetro em vez de usar a localidade atual. Essas novas funções têm o sufixo **_l**. Várias novas funções foram adicionadas para trabalhar com objetos de localidade. As novas funções incluem `_get_current_locale`, `_create_locale` e `_free_locale`.
- Novas funções foram adicionadas para dar suporte a identificadores de arquivo de bloqueio e desbloqueio.
- A família de funções `_spawn` não redefine errno como zero em caso de sucesso, como nas versões anteriores.
- Estão disponíveis versões da família de funções `printf` que permitem especificar a ordem em que os argumentos são usados.
- Agora, o Unicode é um formato de texto com suporte. A função `_open` dá suporte aos atributos _O_TEXTW, _O_UTF8 e _O_UTF16. A função `fopen` dá suporte ao método "ccs=ENCODING" de especificação de um formato Unicode.
- Uma nova versão das bibliotecas CRT compiladas em código gerenciado (MSIL) agora está disponível e é usada ao compilar com a opção `/clr`(Compilação Common Language Runtime).
- _fileinfo foi removido.
- O tamanho padrão de `time_t` agora é 64 bits, que expande o intervalo de `time_t` e várias das funções de tempo até o ano 3000.
- O CRT agora é compatível com a configuração de localidade, por thread. A função `_configthreadlocale` foi adicionada para dar suporte a esse recurso.
- As funções `_statusfp2` e `__control87_2` foram adicionadas para permitir acesso e controle da palavra de controle de ponto flutuante no processador de ponto flutuante x87 e SSE2.
- As funções `_mkgmtime` e `_mkgmtime64` foram adicionadas para dar suporte à conversão de horários (struct tm) ao GMT (Horário do Meridiano de Greenwich).
- Foram feitas alterações em `swprintf` e `vswprintf` para melhorar a conformidade com o padrão.
- Um novo arquivo de cabeçalho, INTRIN. H, fornece protótipos para algumas funções intrínsecas.
- A função `fopen` agora tem o atributo N.
- A função `_open` agora tem o atributo _O_NOINHERIT.
- A função `atoi` agora retorna INT_MAX e define `errno` como ERANGE no estouro. Nas versões anteriores, o comportamento de estouro era indefinido.
- A família de funções `printf` dá suporte para a saída de ponto flutuante hexadecimal implementada de acordo com o padrão ANSI C99 usando os especificadores de tipo de formato %a e %A.
- A família `printf` agora dá suporte ao prefixo de tamanho "ll" (long long).
- A função `_controlfp` foi otimizada para melhorar o desempenho.
- Versões de depuração de algumas funções foram adicionadas.
- Foram adicionadas `_chgsignl` e `_cpysignl` (versões long double).
- Foi adicionado o tipo `_locale_t` para a tabela de tipos.
- Nova macro `_countof` adicionada para calcular o número de elementos em uma matriz.
- Em cada tópico de função, foi adicionada uma seção em equivalentes do .NET Framework.
- Várias funções de cadeia de caracteres agora têm a opção de truncamento de cadeias de caracteres em vez de falha quando os buffers de saída são muito pequenos. Confira **_TRUNCATE**.
- O `_set_se_translator` agora requer o uso da opção do compilador `/EHa`.
- O `fpos_t` agora é um **__int64** em `/Za` (para o código C) e quando __STDC__ é definido manualmente (para código C++). Antes ele era um **struct**.
- _CRT_DISABLE_PERFCRIT_LOCKS pode melhorar o desempenho de E/S de programas single-threaded.
- Os nomes de POSIX foram preteridos e substituídos pelos nomes compatíveis com a ISO C++ (por exemplo, use `_getch` em vez de `getch`).
- Novos arquivos. obj das opções de link estão disponíveis para o modo pure
- `_recalloc` combina os recursos de `realloc` e `calloc`.

## <a name="whats-new-for-c-in-visual-studio-2003"></a>Novidades do C++ no Visual Studio 2003

### <a name="compiler"></a>Compilador

- Informações sobre como executar extensões gerenciadas de aplicativo C++ compilado com o compilador da versão atual em uma versão anterior do tempo de execução.
- Perguntas frequentes sobre extensões gerenciadas para C++.
- Foi adicionado um passo a passo que mostra como portar um aplicativo nativo existente para usar as Managed Extensions for C++: Passo a passo: portando um aplicativo C++ nativo existente para interoperar com componentes do .NET Framework.
- Agora você pode criar um delegado em um método de um tipo de valor.
- Conformidade do compilador com o padrão do C++ foi aprimorada significativamente para o Visual C++ .NET 2003.
- A opção do compilador `/arch` foi adicionada.
- `/Gf` foi preterido e será removido na próxima versão do Visual C++.
- A opção do compilador `/G7` foi adicionada.
- A opção do compilador `/GS` foi melhorada para ajudar a proteger as variáveis locais contra estouros de buffer.
- A opção do compilador `/noBool` foi removida. O compilador agora permite que **bool** apareça somente como uma palavra-chave (não como um identificador) em um arquivo de código-fonte C++.
- O tipo **long long** agora está disponível como a **typedef** **__int64** Observe que ainda não há suporte para **long long** no CRT.
- A opção do compilador `/Zm` agora especifica o limite de alocação da memória do cabeçalho pré-compilado.
- O intrínseco _InterlockedCompareExchange agora está documentado.
- O intrínseco _InterlockedDecrement agora está documentado.
- O intrínseco _InterlockedExchange agora está documentado.
- O intrínseco _InterlockedExchangeAdd agora está documentado.
- O intrínseco _InterlockedIncrement agora está documentado.
- O intrínseco _ReadWriteBarrier foi adicionado.

### <a name="attributes"></a>Atributos

- O atributo `implements` agora está documentado.

### <a name="linker-features"></a>Recursos do vinculador

As seguintes opções de vinculador foram adicionadas:

- /ASSEMBLYDEBUG
- /ASSEMBLYLINKRESOURCE
- DELAYSIGN
- /KEYFILE
- /KEYCONTAINER
- /SAFESEH

### <a name="masm"></a>MASM

A diretiva .SAFESEH e a opção `/safeseh` do ml.exe foram adicionadas.

## <a name="see-also"></a>Consulte também

[Guia de atualização e portabilidade do Visual C++](visual-cpp-porting-and-upgrading-guide.md)
