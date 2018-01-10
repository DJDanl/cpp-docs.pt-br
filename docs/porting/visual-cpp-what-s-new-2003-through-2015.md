---
title: "Novidades do Visual C++ de 2003 até 2015 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: c4afde6f-3d75-40bf-986f-be57e3818e26
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 512665a243a0c24c143242084a51f6b3025c1a19
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="visual-c-what39s-new-2003-through-2015"></a>Novidades do Visual C++ de 2003 até 2015

**Observação** Para obter informações sobre o Visual Studio 2017, consulte [Novidades do Visual C++ no Visual Studio 2017](../what-s-new-for-visual-cpp-in-visual-studio.md) e [Melhorias de conformidade no Visual C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md).

Algumas vezes, os aprimoramentos contínuos para conformidade do compilador no Visual C++ 2015 e versões posteriores, podem alterar a maneira pela qual o compilador compreende seu código-fonte existente. Quando isso acontecer, você poderá encontrar erros novos ou diferentes durante o build ou até diferenças de comportamento no código que foi compilado anteriormente e parecia executar corretamente.  
  
 Felizmente, essas diferenças têm pouco ou nenhum impacto sobre a maior parte do código-fonte e quando as alterações de código-fonte ou outras alterações são necessárias para resolver essas diferenças, as correções geralmente são pequenas e descomplicadas. Incluímos muitos exemplos de código-fonte que eram aceitáveis e que, talvez, precisem ser alterados *(antes)* e as correções para corrigi-los *(depois)*.  
  
 Embora essas diferenças podem afetar seu código-fonte ou outros artefatos de build, elas não afetam a compatibilidade binária entre as atualizações de versões do Visual C++. Um tipo mais grave de alteração, ao *alteração significativa* pode afetar a compatibilidade binária, mas esses tipos de interrupções de compatibilidade binária ocorrem somente entre as versões principais do Visual C++. Por exemplo, entre o Visual C++ 2013 e Visual C++ 2015. Para obter informações sobre as alterações significativas que ocorreram entre o Visual C++ 2013 e o Visual C++ 2015, consulte [Histórico de alterações do Visual C++ de 2003 a 2015](../porting/visual-cpp-change-history-2003-2015.md).  
  
-   [Aprimoramentos de conformidade no Visual C++ 2015](#VS_RTM)  
  
-   [Aprimoramentos de conformidade na Atualização 1](#VS_Update1)  
  
-   [Aprimoramentos de conformidade na Atualização 2](#VS_Update2)  
  
-   [Aprimoramentos de conformidade na Atualização 3](#VS_Update3)  
  
##  <a name="VS_RTM"></a> Aprimoramentos de conformidade no Visual C++ 2015  
  
-   Opção /Zc:forScope-  
  
     A opção do compilador **/Zc:forScope-** foi preterida e será removida em uma versão futura.  
  
    ```  
    Command line warning  D9035: option 'Zc:forScope-' has been deprecated and will be removed in a future release  
    ```  
  
     A opção foi comumente usada para permitir código não padrão que usa variáveis de loop após o momento em que deveriam ter saído do escopo, de acordo com o padrão. Ela só era necessária quando você estava compilando com a opção /Za, pois sem /Za, o uso de a como uma variável de loop após o final do loop é sempre permitido. Se você não se importa com conformidade com os padrões (por exemplo, se seu código não se destina a portabilidade com outros compiladores), você pode desligar a opção /Za (ou definir a propriedade Desabilitar Extensões de Linguagem como Não). Se você deseja escrever código portátil e em conformidade com os padrões, você deve reescrever o código, movendo a declaração de tais variáveis para um ponto fora do loop, para ficar em conformidade com o padrão.  
  
    ```  
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
  
-   **Opção do compilador /Zg**  
  
     A opção do compilador /Zg (Gerar Protótipos de Função) não está mais disponível. Essa opção do compilador foi anteriormente preterida.  
  
-   Não é possível executar testes de unidade com C++/CLI na linha de comando com mstest.exe. Em vez disso, use vstest.console.exe. Consulte [Opções de linha de comando de VSTest.Console.exe](/devops-test-docs/test/vstest-console-exe-command-line-options).  
  
-   **palavra-chave mutable**  
  
     O especificador de classe de armazenamento `mutable` não é mais permitido em locais em que anteriormente era compilado sem erros. Agora, o compilador gera um erro C2071 (classe de armazenamento inválida). Segundo o padrão, o especificador mutable só pode ser aplicado a nomes de membros de dados de classe e não pode ser aplicado a nomes declarados const ou static e também não pode ser aplicado para fazer referência a membros.  
  
     Por exemplo, considere o seguinte código:  
  
    ```  
    struct S {  
        mutable int &r;  
    };  
    ```  
  
     Versões anteriores do compilador do Visual C++ aceitavam isso, mas agora o compilador retorna o seguinte erro:  
  
    ```Output  
    error C2071: 'S::r': illegal storage class  
    ```  
  
     Para corrigir o erro, simplesmente remova a palavra-chave mutable redundante.  
  
-   **char_16_t e char32_t**  
  
     Você não pode usar mais `char16_t` ou `char32_t` como aliases em um typedef, porque esses tipos agora são tratados como internos. Era comum os usuários e autores de biblioteca definirem char16_t e char32_t como aliases de uint16_t e uint32_t, respectivamente.  
  
    ```  
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
  
     Para atualizar seu código, remova as declarações de typedef e renomeie todos os outros identificadores que entrarem em conflito com esses nomes.  
  
-   **Parâmetros de modelo de não tipo**  
  
     Alguns códigos que envolvem os parâmetros de modelo de não tipo agora têm a compatibilidade de tipo corretamente verificada quando você fornece argumentos de modelo explícitos. Por exemplo, o seguinte código compilado sem erros nas versões anteriores do Visual C++.  
  
    ```  
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
  
-   **__declspec(align)**  
  
     O compilador não aceita mais `__declspec(align)` em funções. Isso sempre foi ignorado, mas agora produz um erro do compilador.  
  
    ```  
    error C3323: 'alignas' and '__declspec(align)' are not allowed on function declarations  
    ```  
  
     Para corrigir esse problema, remova `__declspec(align)` da declaração da função. Uma vez que ela não tinha efeito, removê-la não altera nada.  
  
-   **Tratamento de exceções**  
  
     Há algumas alterações para o tratamento de exceções. Primeiro, os objetos de exceção precisam ser copiáveis ou móveis. O seguinte código foi compilado no [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], mas não compila no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)]:  
  
    ```  
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
  
     O problema é que o construtor de cópia é particular, portanto o objeto não pode ser copiado como acontece no curso normal de tratamento de exceção. O mesmo se aplica quando o construtor de cópia é declarado `explicit`.  
  
    ```  
    struct S {  
        S();  
        explicit S(const S &);  
    };  
  
    int main()  
    {  
        throw S(); // error  
    }  
  
    ```  
  
     Para atualizar seu código, verifique se o construtor de cópia do objeto de exceção é público e não está marcado como `explicit`.  
  
     A captura de uma exceção pelo valor também exige que o objeto de exceção seja copiável. O seguinte código foi compilado no [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], mas não compila no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)]:  
  
    ```  
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
  
     Você pode corrigir esse problema alterando o tipo de parâmetro do `catch` para uma referência.  
  
    ```  
    catch(D& d)  
    {  
    }  
    ```  
  
-   **Literais de cadeia de caracteres seguidos de macros**  
  
     Agora o compilador oferece suporte a literais definidos pelo usuário. Como consequência, os literais de cadeia de caracteres seguidos de macros sem qualquer espaço em branco de intervenção são interpretados como literais definidos pelo usuário, o que pode causar erros ou resultados inesperados. Por exemplo, nos compiladores anteriores o seguinte código foi compilado com êxito:  
  
    ```  
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
  
     O compilador interpretou isso como uma cadeia de caracteres literal "hello" seguida por uma macro, que é "there" expandida e, em seguida, os dois literais de cadeia de caracteres foram concatenados em um. No [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], o compilador interpreta isso como um literal definido pelo usuário, mas como não há nenhum literal _x definido correspondente definido pelo usuário, ele gera um erro.  
  
    ```  
    error C3688: invalid literal suffix '_x'; literal operator or literal operator template 'operator ""_x' not found  
    note: Did you forget a space between the string literal and the prefix of the following string literal?  
  
    ```  
  
     Para corrigir esse problema, adicione um espaço entre o literal de cadeia de caracteres e a macro.  
  
-   **Literais de cadeia de caracteres adjacentes**  
  
     Assim como os anteriores, devido a alterações na análise de cadeia de caracteres, os literais de cadeia de caracteres adjacentes (literais de cadeia de caracteres largos ou estreitos) sem nenhum espaço em branco foram interpretados como uma única cadeia de caracteres concatenada nas versões anteriores do Visual C++. Já no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], você deve adicionar espaço em branco entre as duas cadeias de caracteres. Por exemplo, o código a seguir deve ser alterado:  
  
    ```  
    char * str = "abc""def";  
    ```  
  
     Basta adicionar um espaço entre as duas cadeias de caracteres.  
  
    ```  
    char * str = "abc" "def";  
    ```  
  
-   **Posicionamento de new e delete**  
  
     Uma alteração foi feita no operador delete para colocá-lo em conformidade com o padrão C++14. Detalhes da alteração dos padrões podem ser encontrados em [Desalocação dimensionada de C++](http://isocpp.org/files/papers/n3778.html). As alterações adicionam uma forma do operador delete global que assume um parâmetro de tamanho. A alteração significativa é que, se você estava usando anteriormente um operador delete com a mesma assinatura (para corresponder a um operador new de posicionamento), você receberá um erro do compilador (C2956, que ocorre no ponto em que o new de posicionamento é usado, já que esta é a posição no código em que o compilador tenta identificar um operador delete correspondente apropriado).  
  
     A função `void operator delete(void *, size_t)` era um operador delete de posicionamento correspondente à função new de posicionamento "void \* operator new(size_t, size_t)" no C++11. Com a desalocação dimensionada de C++14, essa função delete é agora uma *função de desalocação comum* (operador delete global). O padrão exige que, se o uso de um new de posicionamento procura uma função delete correspondente e localiza uma função de desalocação comum, o programa está mal formado.  
  
     Por exemplo, suponha que seu código define um new de posicionamento e um delete de posicionamento:  
  
    ```  
    void * operator new(std::size_t, std::size_t);  
    void operator delete(void*, std::size_t) noexcept;  
  
    ```  
  
     O problema ocorre devido a correspondência em assinaturas de função entre um operador delete de posicionamento que você definiu e o novo operador global delete dimensionado. Considere se é possível usar um tipo diferente que não seja o size_t para qualquer operador new e delete de posicionamento.  Observe que o tipo do typedef size_t é dependente de compilador; é um typedef para int sem sinal no Visual C++. Uma boa solução é usar um tipo enumerado como este:  
  
    ```  
    enum class my_type : size_t {};  
  
    ```  
  
     Em seguida, altere sua definição de new e delete de posicionamento para usar esse tipo como o segundo argumento, em vez de size_t. Você também precisará atualizar as chamadas ao new de posicionamento para passar o novo tipo (por exemplo, usando `static_cast<my_type>` para converter do valor inteiro) e atualizar a definição de new e delete para retroceder para o tipo de inteiro. Você não precisa usar um enum para isso. Um tipo de classe com um membro size_t também funcionaria.  
  
     Uma solução alternativa é que você poderá eliminar o new de posicionamento completamente. Se seu código usa o new de posicionamento para implementar um pool de memória no qual o argumento de posicionamento é o tamanho do objeto que está sendo alocado ou excluído, então o recurso de desalocação dimensionada poderá ser adequado para substituir seu próprio código de pool de memória personalizado e você poderá se livrar das funções de posicionamento e simplesmente usar seu próprio operador delete de dois argumentos em vez das funções de posicionamento.  
  
     Se você não quiser atualizar seu código imediatamente, você poderá reverter para o comportamento antigo usando a opção do compilador /Zc:sizedDealloc-. As funções delete de dois argumentos não existem, se você usar essa opção e não causarão conflito com seu operador delete de posicionamento.  
  
-   **Membros de dados de união**  
  
     Membros de dados de uniões não podem mais ter tipos de referência. O seguinte código foi compilado com êxito no [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], mas gera um erro no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)].  
  
    ```  
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
  
-   As uniões anônimas são agora mais compatíveis com o padrão. As versões anteriores do compilador geravam um construtor e um destruidor explícitos de uniões anônimas. Eles foram excluídos no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)].  
  
    ```  
    struct S {  
      S();  
     };  
  
     union {  
      struct {  
       S s;  
      };  
     } u; // C2280  
    ```  
  
     O código anterior gera o seguinte erro no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)]:  
  
    ```  
    error C2280: '<unnamed-type-u>::<unnamed-type-u>(void)': attempting to reference a deleted function  
    note: compiler has generated '<unnamed-type-u>::<unnamed-type-u>' here  
    ```  
  
     Para resolver esse problema, forneça suas próprias definições do construtor e/ou do destruidor.  
  
    ```  
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
  
-   **Uniões com structs anônimos**  
  
     Para entrar em conformidade com o padrão, o comportamento do tempo de execução foi alterado para membros de estruturas anônimas em uniões. O construtor para membros de estrutura anônima em uma união não é mais implicitamente chamado quando a união é criada. Além disso, o destruidor para membros de estrutura anônima em uma união não é mais implicitamente chamado quando a união sai do escopo. Considere o código a seguir, em que uma união U contém uma estrutura anônima que contém um membro que é uma estrutura nomeada S que tem um destruidor.  
  
    ```  
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
  
     No [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], o construtor para S é chamado quando a união é criada e o destruidor para S é chamado quando a pilha da função f é limpa. Mas no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], o construtor e destruidor não são chamados. O compilador dá um aviso sobre essa alteração de comportamento.  
  
    ```Output  
    warning C4587: 'U::s': behavior change: constructor is no longer implicitly calledwarning C4588: 'U::s': behavior change: destructor is no longer implicitly called  
    ```  
  
     Para restaurar o comportamento original, nomeie a estrutura anônima. O comportamento de tempo de execução de estruturas não anônimas é o mesmo, independentemente da versão do compilador.  
  
    ```  
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
  
    ```  
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
  
-   **Resolução de modelo**  
  
     Foram feitas alterações na resolução de nomes dos modelos. No C++, esse pode ser o caso de um ou mais nomes em consideração como correspondências possíveis causando uma instanciação de modelo inválida, ao considerar candidatos para a resolução de um nome. Essas instanciações inválidas normalmente não causam erros de compilador, um princípio que é conhecido como SFINAE (Substitution Failure Is Not An Error – Falha de substituição não é um erro).  
  
     Agora, se o SFINAE exige que o compilador instancie a especialização de um modelo de classe, os erros que ocorrem durante esse processo são erros de compilador. Nas versões anteriores, o compilador ignoraria esses erros. Por exemplo, considere o seguinte código:  
  
    ```  
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
  
-   **Construtores de cópia**  
  
     Tanto no [!INCLUDE[vs_dev12](../atl-mfc-shared/includes/vs_dev12_md.md)] quanto no Visual Studio 2015, o compilador gera um construtor de cópia para uma classe se essa classe tem um construtor de movimentação definido pelo usuário, mas não tem um construtor de cópia definido pelo usuário. No Dev14, esse construtor de cópia implicitamente gerado também é marcado "= delete".  
  
##  <a name="VS_Update1"></a> Aprimoramentos de conformidade na Atualização 1  
  
-   **Classes base virtuais particulares e herança indireta**  
  
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
  
     -ou-  
  
    ```  
    class base;  // as above  
  
    class middle: private virtual base {};  
    class top: public virtual middle, private virtual bottom {};  
  
    void destroy(top *p)  
    {  
        delete p;  
    }  
    ```  
  
-   **Operador new sobrecarregado e operador delete**  
  
     As versões anteriores do compilador permitiam que `operator new` não membro e `operator delete` não membro fossem declarados estáticos e que fossem declarados em namespaces diferentes do namespace global.  Esse comportamento antigo criava um risco do programa não chamar a implementação do operador `new` ou `delete` pretendida pelo programador, resultando em comportamento silencioso de tempo de execução incorreto. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C2323.  
  
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
  
-   **Chamar 'operator *type*()' (conversão definida pelo usuário) em tipos de não classe**  
  
     As versões anteriores do compilador permitiam que o 'operator *type*()' fosse chamado em tipos de não classe ignorando-o silenciosamente. Esse comportamento antigo criava um risco de geração silenciosa de código incorreto, resultando em um comportamento imprevisível do tempo de execução. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C2228.  
  
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
  
-   **Typename redundante em especificadores de tipo elaborados**  
  
     As versões anteriores do compilador permitiam `typename` em especificadores de tipo elaborado. O código escrito dessa maneira é semanticamente incorreto. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C3406.  
  
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
  
-   **Dedução de tipo de matrizes de uma lista de inicializadores**  
  
     As versões anteriores do compilador não ofereciam suporte à dedução de tipo de matrizes de uma lista de inicializadores. Agora o compilador oferece suporte a essa forma de dedução de tipo e, como resultado, as chamadas de modelos de função usando listas de inicializadores podem ser ambíguas ou pode ser escolhida uma sobrecarga diferente das versões anteriores do compilador. Para resolver esses problemas, o programa agora deve especificar explicitamente a sobrecarga pretendida pelo programador.  
  
     Quando esse novo comportamento faz com que a resolução de sobrecarga considere um candidato adicional que é igualmente tão bom quanto o candidato histórico, a chamada se torna ambígua e o compilador emite o erro do compilador C2668 como resultado.  
  
    ```Output  
    error C2668: 'function' : ambiguous call to overloaded function.  
    ```  
  
     Exemplo 1: chamada ambígua a função sobrecarregada (antes)  
  
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
  
-   **Restauração de avisos de instrução switch**  
  
     Uma versão anterior do compilador removeu avisos previamente existentes relacionados a instruções `switch`; esses avisos agora foram restaurados. Agora o compilador emite os avisos restaurados e os avisos relacionados a casos específicos (incluindo o caso padrão) são emitidos na linha que contém o caso com problema, em vez de na última linha da instrução switch. Como resultado da emissão desses avisos em linhas diferentes do que era no passado, os avisos que anteriormente eram suprimidos usando `#pragma warning(disable:####)` não podem mais ser suprimidos como esperado. Para suprimir esses avisos conforme o esperado, talvez seja necessário mover a diretriz `#pragma warning(disable:####)` para uma linha acima do primeiro caso potencialmente problemático. A seguir estão os avisos restaurados.  
  
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
  
-   **#include: uso do especificador '..' de diretório pai no nome do caminho** (afeta apenas /Wall /WX)  
  
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
  
-   **#pragma optimize() ultrapassa o fim do arquivo de cabeçalho** (afeta apenas /Wall /WX)  
  
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
  
-   **#pragma warning(push)** e **#pragma warning(pop) incompatíveis** (afeta apenas /Wall /WX)  
  
     As versões anteriores do compilador não detectavam a combinação de alterações de estado `#pragma warning(push)` com alterações de estado `#pragma warning(pop)` em um arquivo de origem diferente, o que é raramente pretendido. Esse comportamento antigo criava um risco do programa ser compilado com um conjunto de avisos habilitados diferentes do que o programador pretendia, resultando, possivelmente, em comportamento silencioso de tempo de execução incorreto. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C5031 opcional no local do `#pragma warning(pop)` correspondente, caso esteja habilitado. Esse aviso inclui uma observação que faz referência ao local do #pragma warning(push) correspondente.  
  
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
  
-   **#pragma warning(push) sem correspondência** (afeta apenas /Wall /WX)  
  
     As versões anteriores do compilador não detectavam alterações de estado `#pragma warning(push)` sem correspondência no final de uma unidade de tradução. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C5032 opcional no local do #pragma warning(push) sem correspondência, caso esteja habilitado. Esse aviso será emitido somente se não houver erros de compilação na unidade de tradução.  
  
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
  
-   **Avisos adicionais podem ser emitidos como resultado de um controle de estado de aviso #pragma aprimorado**  
  
     As versões anteriores do compilador controlavam as alterações de estado de aviso #pragma de forma insuficientemente adequada para emitir todos os avisos pretendidos. Esse comportamento criava um risco de que certos avisos seriam efetivamente suprimidos em circunstâncias diferentes das que o programador pretendia. Agora o compilador controla o estado de aviso #pragma com mais robustez – especialmente com relação às alterações de estado de aviso #pragma dentro de modelos – e, opcionalmente, emite novos avisos C5031 e C5032 que se destinam a ajudar o programador a localizar usos não intencionais de `#pragma warning(push)` e `#pragma warning(pop)`.  
  
     Como resultado do controle de alteração de estado de aviso #pragma aprimorado, os avisos que eram suprimidos de forma incorreta anteriormente ou os avisos relacionados a problemas anteriormente diagnosticados de forma incorreta, agora poderão ser emitidos.  
  
-   **Identificação aprimorada de código inacessível**  
  
     As alterações da Biblioteca Padrão do C++ e capacidade aprimorada para chamadas de função embutida em relação às versões anteriores do compilador podem permitir que o compilador comprove que determinado código está inacessível no momento. Esse novo comportamento pode resultar em emissões novas e mais frequentes de instâncias do aviso C4720.  
  
    ```Output  
    warning C4720: unreachable code  
    ```  
  
     Em muitos casos, esse aviso só pode ser emitido durante a compilação com otimizações habilitadas, já que as otimizações podem embutir mais chamadas de função, eliminar código redundante ou, caso contrário, possibilitar a determinação de que determinado código está inacessível. Observamos que novas instâncias do aviso C4720 ocorreram frequentemente em blocos try/catch, especialmente em relação ao uso de [std::find](assetId:///std::find?qualifyHint=False&autoUpgrade=True).  
  
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
  
##  <a name="VS_Update2"></a> Aprimoramentos de conformidade na Atualização 2  
  
-   **Erros e avisos adicionais podem ser emitidos como resultado do suporte parcial à expressão SFINAE**  
  
     As versões anteriores do compilador não analisavam determinados tipos de expressões dentro de especificadores `decltype` devido à falta de suporte para a expressão SFINAE. Esse comportamento antigo estava incorreto e não estava em conformidade com o padrão C++. Agora o compilador analisa essas expressões e tem suporte parcial à expressão SFINAE devido às melhorias contínuas de conformidade. Como resultado, o compilador emite avisos e erros encontrados nas expressões que as versões anteriores do compilador não analisavam.  
  
     Quando esse novo comportamento analisa uma expressão `decltype` que inclui um tipo que não ainda foi declarado, o compilador emite o erro de compilador C2039 como resultado.  
  
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
  
     Quando esse novo comportamento analisa uma expressão `decltype` em que está faltando um uso necessário da palavra-chave `typename` para especificar que um nome dependente é um tipo, o compilador emite aviso do compilador C4346 junto com o erro do compilador C2923.  
  
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
  
-   `volatile` **variáveis de membro impedem construtores e operadores de atribuição implicitamente definidos**  
  
     As versões anteriores do compilador permitiam que uma classe que tem variáveis de membro `volatile` tivesse construtores padrão copiar/mover e operadores de atribuição padrão copiar/mover gerados automaticamente. Esse comportamento antigo estava incorreto e não estava em conformidade com o padrão C++. Agora o compilador considera que uma classe que tem variáveis de membro voláteis tenha operadores de construção e de atribuição não triviais que impedem que as implementações padrão desses operadores sejam geradas automaticamente.  Quando essa classe é um membro de uma união (ou uma união anônima dentro de uma classe), os construtores copiar/mover e os operadores de atribuição copiar/mover da união (ou a classe que contém a união anônima) serão implicitamente definidos como excluídos. A tentativa de construir ou copiar a união (ou a classe que contém a união anônima) sem defini-los explicitamente é um erro e o compilador emitirá um erro de compilador C2280 como resultado.  
  
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
  
-   **Funções de membro estático não dão suporte a qualificadores cv.**  
  
     As versões anteriores do Visual C++ 2015 permitiam que funções de membro estático tivessem qualificadores cv. Esse comportamento era devido a uma regressão no Visual C++ 2015 e no Visual C++ 2015 Atualização 1. O Visual C++ 2013 e as versões anteriores do Visual C++ rejeitam o código escrito dessa maneira. O comportamento do Visual C++ 2015 e do Visual C++ 2015 Atualização 1 está incorreto e não está em conformidade com o padrão C++.  O Visual Studio 2015 Atualização 2 rejeita o código escrito dessa maneira e, em vez disso, emite o erro do compilador C2511.  
  
    ```Output  
    error C2511: 'void A::func(void) const': overloaded member function not found in 'A'  
    ```  
  
     Exemplo (antes)  
  
    ```  
    struct A  
    {  
      static void func();  
    };  
  
    void A::func() const {}  // C2511  
  
    ```  
  
     Exemplo (depois)  
  
    ```  
    struct A  
    {  
      static void func();  
    };  
  
    void A::func() {}  // removed const  
  
    ```  
  
-   **A declaração de encaminhamento de enum não é permitida no código do WinRT** (só afeta /ZW)  
  
     O código compilado para o WinRT (Windows Runtime) não permite que tipos `enum` sejam declarados de encaminhamento, da mesma forma que quando o código C++ gerenciado é compilado para o .NET Framework usando a opção de compilador /clr. Esse comportamento garante que o tamanho de uma enumeração seja sempre conhecido e seja projetado corretamente para o sistema de tipos WinRT. O compilador rejeita o código escrito dessa maneira e emite um erro do compilador C2599 junto com o erro do compilador C3197.  
  
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
  
-   **Operador new de não membro sobrecarregado e operador delete não podem ser declarados embutidos** (Nível 1 (/ W1) ativado por padrão)  
  
     As versões anteriores do compilador não emitem um aviso quando o operador new de não membro e as funções do operador delete são declarados embutidos. O código escrito dessa maneira é mal formado (não é necessário nenhum diagnóstico) e pode causar problemas de memória resultantes de operadores new e delete incompatíveis (especialmente quando usado em conjunto com desalocação dimensionada) que podem ser difíceis de diagnosticar.   Agora o compilador emite o aviso do compilador C4595 para ajudar a identificar o código escrito dessa forma.  
  
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
  
##  <a name="VS_Update3"></a> Aprimoramentos de conformidade na Atualização 3  
  
-   **std::is_convertable agora detecta a autoatribuição** (biblioteca padrão)  
  
     As versões anteriores das característica de tipo `std::is_convertable` não detectavam corretamente a autoatribuição de um tipo de classe quando seu construtor de cópia era excluído ou particular. Agora `std::is_convertable<>::value` está definido corretamente como `false` quando aplicado a um tipo de classe com um construtor de cópia particular ou excluído.  
  
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
  
     Nas versões anteriores do Visual C++, as asserções estáticas na parte inferior deste exemplo passam porque `std::is_convertable<>::value` foi definido incorretamente como `true`. Agora `std::is_convertable<>::value` está definido corretamente como `false`, fazendo com que as asserções estáticas falhem.  
  
-   **Construtores triviais de cópia e movimentação padronizados ou excluídos respeitam especificadores de acesso**  
  
     As versões anteriores do compilador não verificavam o especificador de acesso dos construtores triviais de cópia e movimentação padronizados ou excluídos antes de permitir que fossem chamados. Esse comportamento antigo estava incorreto e não estava em conformidade com o padrão C++. Em alguns casos, esse comportamento antigo criava um risco de geração silenciosa de código incorreto, resultando em um comportamento imprevisível do tempo de execução. Agora o compilador verifica o especificador de acesso dos construtores triviais de cópia e movimentação padronizados ou excluídos para determinar se podem ser chamados e se não puderem, emite um aviso do compilador C2248 como resultado.  
  
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
  
-   **Preterimento do suporte a código ATL atribuído** (Nível 1 (/ W1) ativado por padrão)  
  
     As versões anteriores do compilador ofereciam suporte ao código ATL atribuído. Como um passo seguinte da remoção do suporte ao código ATL atribuído que [começou no Visual C++ 2008](https://msdn.microsoft.com/library/bb384632\(v=vs.90\).aspx), o código ATL atribuído foi preterido. Agora o compilador emite o aviso do compilador C4467 para ajudar a identificar esse tipo de código preterido.  
  
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
  
-   **Arquivos de PCH (cabeçalho pré-compilado) e diretivas incompatíveis #include** (afeta apenas /Wall /WX)  
  
     As versões anteriores do compilador aceitavam diretivas `#include` incompatíveis em arquivos de origem entre compilações `-Yc` e `-Yu` ao usar arquivos de PCH (cabeçalho pré-compilado). O código escrito dessa maneira não é mais aceito pelo compilador.   Agora o compilador emite o aviso do compilador CC4598 para ajudar a identificar diretivas `#include` incompatíveis ao usar arquivos de PCH.  
  
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
  
-   **Arquivos de PCH (cabeçalho pré-compilado) e diretórios de inclusão incompatíveis** (afeta somente /Wall /WX)  
  
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