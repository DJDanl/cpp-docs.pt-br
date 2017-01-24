---
title: "Melhorias de conformidade do compilador do Visual C++ 2015 | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: c4afde6f-3d75-40bf-986f-be57e3818e26
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Melhorias de conformidade do compilador do Visual C++ 2015
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No Visual C\+\+ 2015, aprimoramentos contínuos para conformidade do compilador, às vezes, podem alterar como o compilador compreende seu código\-fonte existente. Quando isso acontecer, você poderá encontrar erros de novos ou diferentes durante a compilação ou diferenças de comportamento até mesmo no código que criado anteriormente e pareceu executar corretamente.  
  
 Felizmente, essas diferenças têm pouco ou nenhum impacto sobre a maioria do código\-fonte e ao código\-fonte ou outras alterações são necessárias para resolver essas diferenças, correções geralmente são pequenos e direta. Incluímos muitos exemplos de código\-fonte anteriormente aceitável que talvez precise ser alterado *\(antes\)* e as correções para corrigi\-los *\(depois\)*.  
  
 Embora essas diferenças podem afetar seu código\-fonte ou outros artefatos de compilação, elas não afetam a compatibilidade binária entre atualizações de versões do Visual C\+\+. Um tipo mais graves de alteração, o  *alteração significativa* podem afetar a compatibilidade binária, mas esses tipos de quebras de compatibilidade binária ocorrerem somente entre versões principais do Visual C\+\+. Por exemplo, entre o Visual C\+\+ 2013 e Visual C\+\+ 2015. Para obter informações sobre as últimas alterações que ocorreram entre o Visual C\+\+ 2013 e Visual C\+\+ 2015, consulte [Alterações significativas no Visual C\+\+ 2015](../Topic/Visual%20C++%20change%20history%202003%20-%2020151.md).  
  
-   [Aprimoramentos de conformidade no Visual C\+\+ 2015](#VS_RTM)  
  
-   [Aprimoramentos de conformidade na atualização 1](#VS_Update1)  
  
-   [Aprimoramentos de conformidade na atualização 2](#VS_Update2)  
  
-   [Aprimoramentos de conformidade no atualização 3](#VS_Update3)  
  
##  <a name="VS_RTM"></a> Aprimoramentos de conformidade no Visual C\+\+ 2015  
  
-   Opção \/ZC:forScope\-  
  
     A opção de compilador **\/Zc:forScope\-** foi substituído e será removido em uma versão futura.  
  
    ```  
    Command line warning  D9035: option 'Zc:forScope-' has been deprecated and will be removed in a future release  
    ```  
  
     Normalmente, a opção foi usada para permitir que código não padrão que usa um loop variáveis após o ponto onde, segundo o padrão, eles devem ter saído do escopo. Era necessário quando você está compilando com a opção \/Za, desde sem \/Za, usando uma variável de loop após o final do loop sempre é permitido. Se você não se importa com conformidade com os padrões \(por exemplo, se seu código não se destina a portabilidade para outros compiladores\), você pode desativar a opção \/Za \(ou definir a propriedade de desabilitar extensões de linguagem como não\). Se você prefere escrever código portátil, compatível com os padrões, você deve reescrever o código para que ele está em conformidade com o padrão, movendo a declaração de tais variáveis para um ponto fora do loop.  
  
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
  
-   **Opção de compilador \/ZG**  
  
     A opção de compilador \/Zg \(gerar protótipos de função\) não está mais disponível. Essa opção de compilador anteriormente foi preterida.  
  
-   Não é possível executar testes de unidade com C \+ \+ \/ CLI na linha de comando com mstest.exe. Em vez disso, use vstest.console.exe. Consulte [Opções de linha de comando VSTest.Console.exe](../Topic/VSTest.Console.exe%20command-line%20options.md).  
  
-   **palavra\-chave mutável**  
  
     O `mutable` especificador de classe de armazenamento não é permitido em lugares onde anteriormente ele compilado sem erros. Agora, o compilador gera um erro C2071 \(classe de armazenamento inválido\). Segundo o padrão, o especificador mutável pode ser aplicado apenas a nomes de membros de dados de classe e não pode ser aplicado para nomes declarados static ou const e não pode ser aplicado para fazer referência a membros.  
  
     Por exemplo, considere o seguinte código:  
  
    ```  
    struct S {  
        mutable int &r;  
    };  
    ```  
  
     Versões anteriores do compilador do Visual C\+\+ aceitavam isso, mas agora o compilador fornece o seguinte erro:  
  
    ```Output  
    Erro C2071: 'S::r': classe de armazenamento inválido  
    ```  
  
     Para corrigir o erro, simplesmente remova a palavra\-chave mutável redundante.  
  
-   **char\_16\_t e char32\_t**  
  
     Você não pode usar `char16_t` ou `char32_t` como aliases em um typedef, porque esses tipos agora são tratados como internos. Era comum para os usuários e autores de biblioteca para definir char16\_t e char32\_t como aliases de uint16\_t e uint32\_t, respectivamente.  
  
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
  
     Para atualizar seu código, remova as declarações de typedef e renomear outros identificadores que entrarem em conflito com esses nomes.  
  
-   **Parâmetros de modelo sem tipo**  
  
     Certos tipos de código que envolve os parâmetros de modelo sem tipo agora é verificado corretamente para compatibilidade de tipo quando você fornecer argumentos de modelo explícitos. Por exemplo, o seguinte código compilado sem erros nas versões anteriores do Visual C\+\+.  
  
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
  
     O compilador atual corretamente apresentará um erro, porque o tipo de parâmetro de modelo não corresponde ao argumento de modelo \(o parâmetro é um ponteiro para um membro const, mas a função f é não const\):  
  
    ```Output  
    Erro C2893: falha de especializar Observação de 'void S2::f (void)' modelo de função: com a seguintes argumentos: Observação modelo: ' C = S1' Observação: ' função = S1::f'  
    ```  
  
     Para resolver esse erro em seu código, certifique\-se de que o tipo do argumento de modelo que você use coincide com o tipo declarado do parâmetro do modelo.  
  
-   **\_\_declspec\(align\)**  
  
     O compilador não aceita mais `__declspec(align)` em funções. Isso sempre foi ignorado, mas agora ele produz um erro do compilador.  
  
    ```  
    error C3323: 'alignas' and '__declspec(align)' are not allowed on function declarations  
    ```  
  
     Para corrigir esse problema, remova `__declspec(align)` da declaração de função. Uma vez que ele não teve efeito, removê\-la não altera nada.  
  
-   **Tratamento de exceção**  
  
     Há algumas alterações para a manipulação de exceção. Primeiro, os objetos de exceção precisam ser copiado ou móvel. O seguinte código compilado no [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], mas não é compilado no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)]:  
  
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
  
     O problema é que o construtor de cópia é particular, portanto o objeto não pode ser copiado, como acontece no curso normal de tratamento de exceção. O mesmo se aplica quando o construtor de cópia é declarado `explicit`.  
  
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
  
     Para atualizar seu código, certifique\-se de que o construtor de cópia para o objeto de exceção é público e marcado como não `explicit`.  
  
     Capturando uma exceção pelo valor também requer o objeto de exceção a ser copiado. O seguinte código compilado no [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], mas não é compilado no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)]:  
  
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
  
     Você pode corrigir esse problema alterando o tipo de parâmetro para o `catch` a uma referência.  
  
    ```  
    catch(D& d)  
    {  
    }  
    ```  
  
-   **Literais de cadeia de caracteres seguidos de macros**  
  
     O compilador agora oferece suporte a literais definidos pelo usuário. Como conseqüência, os literais de cadeia de caracteres seguidos de macros sem qualquer intervenção espaço em branco são interpretados como literais definidos pelo usuário, que podem causar erros ou resultados inesperados. Por exemplo, nos compiladores anteriores o seguinte código compilado com êxito:  
  
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
  
     O compilador interpretado isso como uma cadeia de caracteres literal "hello" seguido por uma macro, que é expandida "there", e, em seguida, os literais de cadeia de caracteres de dois fossem concatenados em um. Em [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], o compilador interpreta como um literal definida pelo usuário, mas como não há nenhuma correspondência definidas pelo usuário literal x definido, ele gera um erro.  
  
    ```  
    error C3688: invalid literal suffix '_x'; literal operator or literal operator template 'operator ""_x' not found  
    note: Did you forget a space between the string literal and the prefix of the following string literal?  
  
    ```  
  
     Para corrigir esse problema, adicione um espaço entre o literal de cadeia de caracteres e a macro.  
  
-   **Literais de cadeia de caracteres adjacentes**  
  
     Da mesma forma para a versão anterior, devido a alterações na análise de cadeia de caracteres literais de cadeia de caracteres adjacentes \(qualquer um dos literais de cadeia de caracteres larga ou estreita\) sem nenhum espaço em branco foram interpretados como uma única cadeia de caracteres concatenada em versões anteriores do Visual C\+\+. Em [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], agora você deve adicionar espaço em branco entre as duas cadeias de caracteres. Por exemplo, o código a seguir deve ser alterado:  
  
    ```  
    char * str = "abc""def";  
    ```  
  
     Basta adicione um espaço entre as duas cadeias de caracteres.  
  
    ```  
    char * str = "abc" "def";  
    ```  
  
-   **Novo posicionamento e delete**  
  
     Uma alteração foi feita para o operador de exclusão para colocá\-lo em conformidade com C\+\+ 14 padrão. Detalhes da alteração padrões podem ser encontrados em [C\+\+ dimensionados desalocação](http://isocpp.org/files/papers/n3778.html). As alterações de adicionar uma forma do operador de exclusão global que utiliza um parâmetro de tamanho. A alteração significativa é que, se você estava usando anteriormente um operador delete com a mesma assinatura \(para corresponder a um operador novo posicionamento\), você receberá um erro do compilador \(C2956, que ocorre no ponto em que o posicionamento novo for usado, já que é a posição no código onde o compilador tenta identificar um operador de exclusão correspondentes apropriado\).  
  
     A função `void operator delete(void *, size_t)` foi um operador de exclusão de posicionamento correspondente para a nova função de posicionamento "void \* operador new \(size\_t, size\_t\)" no C\+\+ 11. Com C \+ \+ 14 desalocação dimensionados, essa função de exclusão é agora um *função de desalocação usual* \(operador de exclusão global\). O padrão exige que, se o uso de um novo posicionamento procura uma função de exclusão correspondentes e localiza uma função de desalocação usual, o programa está mal formado.  
  
     Por exemplo, suponha que seu código define um novo posicionamento e uma exclusão de posicionamento:  
  
    ```  
    void * operator new(std::size_t, std::size_t);  
    void operator delete(void*, std::size_t) noexcept;  
  
    ```  
  
     O problema ocorre devido a correspondência em assinaturas de função entre um operador de exclusão de posicionamento que você definiu e o novo operador de exclusão de porte global. Considere se você pode usar um tipo diferente de size\_t diferente para qualquer posicionamento novo e excluir operadores.  Observe que o tipo do typedef size\_t é dependente de compilador; é um typedef para unsigned int no Visual C\+\+. Uma boa solução é usar um tipo enumerado como este:  
  
    ```  
    enum class my_type : size_t {};  
  
    ```  
  
     Em seguida, alterar sua definição de posicionamento novo e excluir para usar esse tipo como o segundo argumento, em vez de size\_t. Você também precisará atualizar as chamadas para o novo posicionamento para passar o novo tipo \(por exemplo, usando `static_cast<my_type>` para converter o valor inteiro\) e atualizar a definição de novo e excluir para converter para o tipo de inteiro. Você não precisa usar uma enumeração para isso. um tipo de classe com um membro size\_t também funcionaria.  
  
     Uma solução alternativa é que você poderá eliminar o posicionamento novo completamente. Se seu novo para implementar um pool de memória onde o argumento de posicionamento é o tamanho do objeto que está sendo alocado ou recurso de desalocação excluídos e tamanho pode ser adequado para substituir seu próprio código de pool de memória personalizado e elimine as funções de posicionamento e simplesmente usar seu próprio dois argumentos o código usa posicionamento Excluir operador em vez das funções de posicionamento.  
  
     Se você não quiser atualizar seu código imediatamente, você pode reverter para o comportamento antigo usando a opção de compilador \/Zc:sizedDealloc\-. Se você usar essa opção, as funções de exclusão de dois argumentos não existem e não causarem um conflito com seu operador de exclusão de posicionamento.  
  
-   **Membros de dados de união**  
  
     Membros de dados de uniões não podem ter tipos de referência. O seguinte código compilado com êxito no [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], mas gera um erro no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)].  
  
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
    Test.cpp(67): erro C2625: 'U2::i': membro de união ilegal; tipo ' int &' é test.cpp(70) de tipo de referência: erro C2625: 'U3::i': membro de união ilegal; tipo ' int &' é um tipo de referência  
    ```  
  
     Para resolver esse problema, altere os tipos de referência a um ponteiro ou um valor. Alterar o tipo de um ponteiro requer alterações no código que usa o campo de união. Alterar o código para um valor deve alterar os dados armazenados na união, que afeta outros campos como campos de tipos de união compartilham a mesma memória. Dependendo do tamanho do valor, ele também pode alterar o tamanho da união.  
  
-   Uniões anônimas são agora mais compatível com o padrão. Versões anteriores do compilador gerou um construtor explícito e o destruidor de uniões anônimas. Eles são excluídos no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)].  
  
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
  
     Para resolver esse problema, forneça suas próprias definições de e\/ou o construtor destruidor.  
  
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
  
-   **Uniões com estruturas anônimas**  
  
     Para estar de acordo com o padrão, o comportamento de tempo de execução foi alterado para membros de estruturas anônimas em uniões. O construtor para membros de estrutura anônima em uma união não implicitamente é chamado quando uma união é criada. Além disso, o destruidor para membros de estrutura anônima em uma união não implicitamente é chamado quando a união sai do escopo. Considere o código a seguir, em que uma união U contém uma estrutura anônima que contém um membro que é uma estrutura nomeada S que tem um destruidor.  
  
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
  
     Em [!INCLUDE[cpp_dev12_long](../build/reference/includes/cpp_dev12_long_md.md)], o construtor para S é chamado quando a união é criada e o destruidor para S é chamado quando a pilha de função f é limpo. Mas em [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], o construtor e destruidor não sejam chamados. O compilador dá um aviso sobre essa alteração de comportamento.  
  
    ```Output  
    Aviso C4587: 'U::s': alteração de comportamento: construtor não é implicitamente calledwarning C4588: 'U::s': alteração de comportamento: destruidor é chamado não implicitamente  
    ```  
  
     Para restaurar o comportamento original, nomeie a estrutura anônima. O comportamento de tempo de execução de estruturas não anônimos é o mesmo, independentemente da versão do compilador.  
  
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
  
     Como alternativa, tente mover o código do construtor e destruidor para novas funções e adicionar chamadas para essas funções do construtor e destruidor da união.  
  
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
  
     As alterações foram feitas para resolução de nomes de modelos. No C\+\+, ao considerar os candidatos para a resolução de nome, pode ser o caso de um ou mais nomes em consideração como correspondências possíveis produz uma instanciação de modelo inválido. Essas instanciações inválidas normalmente não causam erros de compilador, um princípio que é conhecido como SFINAE \(substituição é não um erro de falha\).  
  
     Agora, se SFINAE exige que o compilador para instanciar a especialização de um modelo de classe, os erros que ocorrem durante esse processo são erros de compilador. Nas versões anteriores, o compilador poderia ignorar esses erros. Por exemplo, considere o seguinte código:  
  
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
    type_traits(1110): erro C2139: tinha ': uma classe indefinida não é permitida como um argumento para a característica de tipo intrínseco de compilador is_base_of'... \t331.cpp(14): Observação: consulte declaração de vinda '... \t331.cpp(10): Observação: consulte a referência para a classe de modelo instanciação 'std::is_base_of < T, U >' está sendo compilado com [T = D, U = D]  
    ```  
  
     Isso ocorre porque no momento a primeira invocação do is\_base\_of seria a classe ' ainda não foi definido.  
  
     Nesse caso, a correção é não usar essas características de tipo até que a classe foi definida. Se você mover as definições de B e D para o início do arquivo de código, o erro seja resolvido. Se as definições em arquivos de cabeçalho, verifique a ordem das instruções include para os arquivos de cabeçalho certificar\-se de que nenhuma definição de classe é compiladas antes que os modelos problemáticos são usados.  
  
-   **Construtores de cópia**  
  
     Em ambos [!INCLUDE[vs_dev12](../atl-mfc-shared/includes/vs_dev12_md.md)] e [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)], o compilador gera um construtor de cópia para uma classe se essa classe tem um construtor de movimentação definidas pelo usuário, mas nenhum construtor de cópia definido pelo usuário. Em Dev14, esse construtor de cópia gerada implicitamente também é marcado "\= excluir".  
  
##  <a name="VS_Update1"></a> Aprimoramentos de conformidade na atualização 1  
  
-   **Classes base virtuais privadas e herança indireta**  
  
     Versões anteriores do compilador permitiam uma classe derivada chame membro funções de seu *indiretamente derivado*`private virtual` classes base. Esse comportamento antigo estava incorreto e não de acordo com o padrão C\+\+. O compilador não aceita código escrito dessa maneira e emite o erro do compilador C2280 como resultado.  
  
    ```Output  
    Erro C2280: ' void * S3::__delDtor(unsigned int)': tentativa de fazer referência a uma função excluída  
    ```  
  
     Exemplo \(antes\)  
  
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
  
     Exemplo \(após\)  
  
    ```cpp  
    class base;  // as above  
  
    class middle: protected virtual base {};  
    class top: public virtual middle {};  
  
    void destroy(top *p)  
    {  
        delete p;  
    }  
    ```  
  
     \- ou \-  
  
    ```  
    class base;  // as above  
  
    class middle: private virtual base {};  
    class top: public virtual middle, private virtual bottom {};  
  
    void destroy(top *p)  
    {  
        delete p;  
    }  
    ```  
  
-   **Operador sobrecarregado novo e operador delete**  
  
     Versões anteriores do compilador permitiam não\-membro `operator new` e não\-membro `operator delete` seja declarado estático e ser declarados em namespaces diferentes o namespace global.  Esse comportamento antigo criado um risco de que o programa não chama o `new` ou `delete` implementação do operador que o programador pretendia, resultando no comportamento de tempo de execução incorreta silenciosa. O compilador não aceita código escrito dessa maneira e emite o erro do compilador C2323 em vez disso.  
  
    ```Output  
    Erro C2323: 'operator new': operador não-membro novo ou excluir funções não podem ser declaradas static ou em um namespace diferente do namespace global.  
    ```  
  
     Exemplo \(antes\)  
  
    ```cpp  
  
    static inline void * __cdecl operator new(size_t cb, const std::nothrow_t&)  // error C2323  
    ```  
  
     Exemplo \(após\)  
  
    ```cpp  
  
    void * __cdecl operator new(size_t cb, const std::nothrow_t&)  // removed 'static inline'  
    ```  
  
     Além disso, embora o compilador não fornece um diagnóstico específico, embutido operador novo é considerado malformados.  
  
-   **Chamar ' operador *tipo*\(\) ' \(conversão definida pelo usuário\) em tipos sem classe**  
  
     Versões anteriores do compilador permitido ' operador *tipo*\(\) ' seja chamado em tipos de classe não ignorando silenciosamente ele. Esse comportamento antigo criado um risco de geração de código de incorreto silenciosa, resultando em um comportamento imprevisível do tempo de execução. O compilador não aceita código escrito dessa maneira e emite o erro do compilador C2228 em vez disso.  
  
    ```Output  
    Erro C2228: à esquerda ' Operator tipo' deve ter a classe/estrutura/união  
    ```  
  
     Exemplo \(antes\)  
  
    ```cpp  
    typedef int index_t;  
  
    void bounds_check(index_t index);  
  
    void login(int column)  
    {  
        bounds_check(column.operator index_t());  // error C2228  
    }  
    ```  
  
     Exemplo \(após\)  
  
    ```cpp  
    typedef int index_t;  
  
    void bounds_check(index_t index);  
  
    void login(int column)  
    {  
        bounds_check(column);  // removed cast to 'index_t', 'index_t' is an alias of 'int'  
    }  
    ```  
  
-   **Typename redundante em especificadores de tipo elaborados**  
  
     Versões anteriores do compilador permitido `typename` em um especificadores de tipo elaborado; código escrito dessa maneira é semanticamente incorreto. O compilador não aceita código escrito dessa maneira e emite o erro do compilador C3406 em vez disso.  
  
    ```Output  
    Erro C3406: 'typename' não pode ser usado em um especificador de tipo elaborado  
    ```  
  
     Exemplo \(antes\)  
  
    ```cpp  
    template <typename class T>  
    class container;  
    ```  
  
     Exemplo \(após\)  
  
    ```cpp  
    template <class T>  // alternatively, could be 'template <typename T>'; 'typename' is not elaborating a type specifier in this case  
    class container;  
    ```  
  
-   **Dedução de tipo de matrizes de uma lista de inicializadores**  
  
     Versões anteriores do compilador não oferecia suporte a dedução de tipo de matrizes de uma lista de inicializadores. O compilador agora oferece suporte a essa forma de dedução de tipo e, como resultado, chamadas para modelos de função usando listas de inicializadores podem agora ser ambíguas ou uma sobrecarga diferente pode ser escolhida que nas versões anteriores do compilador. Para resolver esses problemas, o programa agora deve especificar explicitamente a sobrecarga que o programador pretendia.  
  
     Quando esse novo comportamento faz com que a resolução de sobrecarga de considerar um candidato adicional é igualmente tão bom quanto o candidato histórico, a chamada se torna ambígua e o compilador emite o erro do compilador C2668 como resultado.  
  
    ```Output  
    Erro C2668: 'função': chamada ambígua para função sobrecarregada.  
    ```  
  
     Exemplo 1: Chamada ambígua para uma função sobrecarregada \(antes\)  
  
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
  
     Exemplo 1: chamada ambígua para uma função sobrecarregada \(após\)  
  
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
  
     Quando esse novo comportamento faz com que a resolução de sobrecarga de considerar um candidato adicional que é uma correspondência melhor do que o candidato histórico, a chamada sem ambigüidade resolve para o novo candidato, causar uma alteração no comportamento do programa provavelmente será diferente do programador pretendido.  
  
     Exemplo 2: alterar a resolução de sobrecarga \(antes\)  
  
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
  
     Exemplo 2: alterar a resolução de sobrecarga \(após\)  
  
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
  
     Uma versão anterior do compilador removido previamente existente avisos relacionados a `switch` instruções; esses avisos agora foram restaurados. O compilador agora emitirá avisos restaurados e agora são emitidos avisos relacionados a casos específicos \(incluindo o caso padrão\) na linha que contém o caso ofensivo, em vez de na última linha da instrução switch. Como resultado de emissão agora esses avisos em linhas diferentes do que no passado, avisos anteriormente suprimidos usando `#pragma warning(disable:####)` não pode ser suprimido conforme o esperado. Para suprimir esses avisos conforme o esperado, talvez seja necessário mover o `#pragma warning(disable:####)` diretriz para uma linha acima do primeiro caso potencialmente ofensivos. A seguir estão os avisos restaurados.  
  
    ```Output  
    Aviso C4060: instrução switch contém sem rótulos 'casos' ou 'default'  
    ```  
  
    ```Output  
    Aviso C4061: enumerador 'bit1'no comutador de enum'sinalizadores' não é tratado explicitamente por um rótulo case  
    ```  
  
    ```Output  
    Aviso C4062: enumerador 'bit1'no comutador de enum'sinalizadores' não é tratado  
    ```  
  
    ```Output  
    Aviso C4063: caso 'bit32'não é um valor válido para a opção de enum'sinalizadores'  
    ```  
  
    ```Output  
    Aviso C4064: opção de enum incompleta 'sinalizadores'  
    ```  
  
    ```Output  
    Aviso C4065: instrução switch contém 'padrão', mas sem rótulos 'case'  
    ```  
  
    ```Output  
    Aviso C4808: caso 'valor'não é um valor válido para a condição de comutador do tipo'bool'  
    ```  
  
    ```Output  
    Aviso C4809: a instrução switch tem rótulo redundante 'default'; recebem todas as possíveis rótulos 'case'  
    ```  
  
     Exemplo de C4063 \(antes\)  
  
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
  
     Exemplo de C4063 \(após\)  
  
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
  
     São fornecidos exemplos dos outros avisos restaurados em sua documentação.  
  
-   **\#include: uso do especificador do diretório pai '.. ' no caminho** \(\/Wall \/WX afeta somente\)  
  
     Versões anteriores do compilador não detectou o uso do especificador de diretório pai '.. ' no caminho de  `#include` diretivas. Código escrito dessa maneira geralmente se destina a incluir cabeçalhos que existem fora do projeto usando caminhos relativos de projeto incorretamente. Esse comportamento antigo criado um risco de que o programa foi compilado, incluindo um arquivo de origem diferente que o programador pretendido, ou que esses caminhos relativos não seria portáteis para outros ambientes de compilação. Agora o compilador detecta e notifica o programador de código escrito dessa maneira e emite um aviso C4464, do compilador opcional se habilitado.  
  
    ```Output  
    Aviso C4464: relativo ao caminho de inclusão contém '.. '  
    ```  
  
     Exemplo \(antes\)  
  
    ```cpp  
    #include "..\headers\C4426.h"  // emits warning C4464  
    ```  
  
     Exemplo \(após\)  
  
    ```cpp  
    #include "C4426.h"  // add absolute path to 'headers\' to your project's include directories  
    ```  
  
     Além disso, embora o compilador não dá um diagnóstico específico, também é recomendável que o especificador do diretório pai ".." Observação deve ser usada para especificar seu projeto diretórios de inclusão.  
  
-   **\#pragma optimize\(\) ultrapassa o fim do arquivo de cabeçalho** \(\/Wall \/WX afeta somente\)  
  
     Versões anteriores do compilador não detectou alterações nas configurações de sinalizador de otimização que escapam de um arquivo de cabeçalho incluído dentro de uma unidade de conversão. O compilador agora detecta e notifica o programador de código escrito dessa maneira e emite um aviso C4426 no local do ofensivo do compilador opcional `#include`, se habilitado. Esse aviso é emitido apenas se as alterações estão em conflito com os sinalizadores de otimização definido pelos argumentos de linha de comando para o compilador.  
  
    ```Output  
    Aviso C4426: alterados após incluir o cabeçalho, os sinalizadores de otimização pode ser devido a #pragma optimize()  
    ```  
  
     Exemplo \(antes\)  
  
    ```cpp  
    // C4426.h  
    #pragma optimize("g", off)  
    ...  
    // C4426.h ends  
  
    // C4426.cpp  
    #include "C4426.h"  // warning C4426  
    ```  
  
     Exemplo \(após\)  
  
    ```cpp  
    // C4426.h  
    #pragma optimize("g", off)  
    ...  
    #pragma optimize("", on)  // restores optimization flags set via command-line arguments  
    // C4426.h ends  
  
    // C4426.cpp  
    #include "C4426.h"  
    ```  
  
-   **Incompatíveis \#pragma warning\(push\)** e **\#pragma warning\(pop\)** \(\/Wall \/WX afeta somente\)  
  
     Versões anteriores do compilador não detectou `#pragma warning(push)` muda de estado sendo combinados com `#pragma warning(pop)` estado alterações em um arquivo de origem diferente, que raramente se destina. Esse comportamento antigo criado um risco de que o programa deve ser compilado com um conjunto diferente de avisos habilitado que o programador pretendido, possivelmente, resultando no comportamento de tempo de execução incorreta silenciosa. O compilador agora detecta e notifica o programador de código escrito dessa maneira e emite um aviso C5031 ao local onde a correspondência do compilador opcional `#pragma warning(pop)`, se habilitado. Esse aviso inclui uma observação a fazer referência ao local do warning\(push\) \#pragma correspondente.  
  
    ```Output  
    Aviso C5031: #pragma warning(pop): incompatibilidade de probabilidade, popping o estado de aviso enviado em outro arquivo  
    ```  
  
     Exemplo \(antes\)  
  
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
  
     Exemplo \(após\)  
  
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
  
     Embora incomum, às vezes é intencional código escrito dessa maneira. Código escrito dessa maneira é sensível às alterações na `#include` ordem; quando possível, recomendamos que os arquivos de código fonte gerenciar o estado de aviso de forma independente.  
  
-   **\#Pragma warning\(push\)** \(\/Wall \/WX afeta somente\)  
  
     Versões anteriores do compilador não detectou incomparável `#pragma warning(push)` alterações no final de uma unidade de conversão de estado. Agora o compilador detecta e notifica o programador de código escrito dessa maneira e emite um aviso C5032 no local do warning\(push\) \#pragma incomparável, do compilador opcional se habilitado. Esse aviso é emitido somente se não houver nenhum erro de compilação na unidade de tradução.  
  
    ```Output  
    Aviso C5032: detectado warning(push) #pragma com nenhuma warning(pop) #pragma correspondente  
    ```  
  
     Exemplo \(antes\)  
  
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
  
     Exemplo \(após\)  
  
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
  
-   **Avisos adicionais podem ser emitidos como resultado de rastreamento de estado de aviso \#pragma aprimorada**  
  
     Versões anteriores do compilador rastreadas \#pragma aviso alterações de estado insuficientemente bem ao problema que tudo isso avisos. Esse comportamento criado um risco que certos avisos suprimidos seriam efetivamente em circunstâncias diferentes que o programador pretendido. O compilador agora controla o estado de aviso \#pragma mais robustez – especialmente com relação às alterações de estado de aviso \#pragma dentro de modelos – e, opcionalmente, emite avisos novo C5031 e C5032 que se destinam a ajudar o programador Localizar usos não intencionais de `#pragma warning(push)` e `#pragma warning(pop)`.  
  
     Como resultado \#pragma aprimorado, rastreamento, avisos suprimidos anteriormente incorretamente ou avisos relacionados a problemas anteriormente misdiagnosed de alteração de estado de aviso agora pode ser emitido.  
  
-   **Identificação aprimorada de código inacessível**  
  
     Alterações de biblioteca padrão C\+\+ e maior capacidade de chamadas de função embutida em relação às versões anteriores do compilador podem permitir que o compilador provar que determinados códigos agora está inacessível. Esse novo comportamento pode resultar em novos e mais frequentemente emitido instâncias de aviso C4720.  
  
    ```Output  
    Aviso C4720: código inacessível  
    ```  
  
     Em muitos casos, esse aviso só pode ser emitido durante a compilação com otimizações habilitadas, desde otimizações pode inline mais chamadas de função, eliminar o código supérfluo ou caso contrário tornam possível determinar que certos tipos de código está inacessível. Temos observado que novas instâncias de aviso C4720 frequentemente ocorreram em blocos try\/catch, especialmente em relação ao uso de [std::find](assetId:///std::find?qualifyHint=False&autoUpgrade=True).  
  
     Exemplo \(antes\)  
  
    ```cpp  
    try   
    {   
        auto iter = std::find(v.begin(), v.end(), 5);   
    }   
    catch(…)   
    {   
        do_something();  // ok   
    }  
    ```  
  
     Exemplo \(após\)  
  
    ```cpp  
    try   
    {   
        auto iter = std::find(v.begin(), v.end(), 5);   
    }   
    catch(…)   
    {   
        do_something();  // warning C4702: unreachable code  
    }  
    ```  
  
##  <a name="VS_Update2"></a> Aprimoramentos de conformidade na atualização 2  
  
-   **Erros e avisos adicionais podem ser emitidos como resultado da expressão SFINAE suporte parcial**  
  
     Versões anteriores do compilador não foram analisada determinados tipos de expressões dentro `decltype` especificadores devido à falta de suporte para a expressão SFINAE. Esse comportamento antigo estava incorreto e não de acordo com o padrão C\+\+. Agora, o compilador analisa essas expressões e tem suporte parcial a expressão SFINAE devido a melhorias contínuas de conformidade. Como resultado, o compilador agora emitirá avisos e erros encontrados nas expressões que versões anteriores do compilador não foram analisada.  
  
     Quando esse novo comportamento analisa um `decltype` expressão que inclui um tipo que não ainda foi declarado, o compilador emite o erro do compilador C2039 como resultado.  
  
    ```Output  
    erro C2039: 'type': não é um membro de 'namespace global '  
    ```  
  
     Exemplo 1: uso de um tipo não declarado \(antes\)  
  
    ```cpp  
    struct s1  
    {  
      template <typename T>  
      auto f() -> decltype(s2<T>::type::f());  // error C2039  
  
      template<typename>  
      struct s2 {};  
    }  
    ```  
  
     Exemplo 1 \(após\)  
  
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
  
     Quando esse novo comportamento analisa um `decltype` expressão que está faltando um uso necessário o `typename` palavra\-chave para especificar um nome dependente é um tipo, o compilador emite aviso C4346 junto com o erro do compilador C2923 do compilador.  
  
    ```Output  
    Aviso C4346: ' S2 < T >:: tipo ': nome dependente não é um tipo  
    ```  
  
    ```Output  
    Erro C2923: 's1': ' S2 < T >:: tipo ' não é um argumento de tipo de modelo válido para o parâmetro ' t '  
    ```  
  
     Exemplo 2: nome dependente não é um tipo \(antes\)  
  
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
  
     Exemplo 2 \(após\)  
  
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
  
-   `volatile` **variáveis de membro impedir definidas implicitamente construtores e operadores de atribuição**  
  
     Versões anteriores do compilador permitiam uma classe que tem `volatile` variáveis de membro para ter padrão copiar\/mover construtores e padrão de operadores de atribuição de copiar\/mover gerados automaticamente. Esse comportamento antigo estava incorreto e não de acordo com o padrão C\+\+. Agora, o compilador considera uma classe que tem variáveis de membro volátil não triviais construção e operadores de atribuição que impede que as implementações padrão desses operadores gerados automaticamente.  Quando essa classe é um membro de uma união \(ou uma união anônima dentro de uma classe\), os construtores de copiar\/mover e copiar\/mover operadores de atribuição de união \(ou a classe que contém a união de unonymous\) serão implicitamente definidos como excluído. A tentativa de construir ou copie a união \(ou classe que contém a união anônima\) sem definir explicitamente\-los é um erro e o erro do compilador do compilador problemas C2280 como resultado.  
  
    ```Output  
    Erro C2280: 'B::B(const B &)': tentativa de fazer referência a uma função excluída  
    ```  
  
     Exemplo \(antes\)  
  
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
  
     Exemplo \(após\)  
  
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
  
     Versões anteriores do Visual C\+\+ 2015 permitiam funções de membro estático com qualificadores cv. Esse comportamento ocorre devido a uma regressão em Visual C\+\+ 2015 e Visual C\+\+ 2015 Update 1; Visual C\+\+ 2013 e versões anteriores do Visual C\+\+ rejeitam código escrito dessa maneira. O comportamento do Visual C\+\+ 2015 e atualização 1 do Visual C\+\+ 2015 está incorreto e não de acordo com o C\+\+ padrão.  Atualização 2 do Visual Studio 2015 rejeita código escrito dessa maneira e emite o erro do compilador C2511 em vez disso.  
  
    ```Output  
    Erro C2511: 'void A::func(void) const': função de membro não encontrada em 'A' sobrecarregada  
    ```  
  
     Exemplo \(antes\)  
  
    ```  
    struct A  
    {  
      static void func();  
    };  
  
    void A::func() const {}  // C2511  
  
    ```  
  
     Exemplo \(após\)  
  
    ```  
    struct A  
    {  
      static void func();  
    };  
  
    void A::func() {}  // removed const  
  
    ```  
  
-   **Declaração de encaminhamento de enum não é permitida no código do WinRT** \(só afeta \/ZW\)  
  
     Código compilado para não permitir que o tempo de execução do Windows \(WinRT\) `enum` tipos para ser declarados, da mesma forma que quando o código C\+\+ gerenciado é compilado para o .net Framework usando o compilador \/clr alterna. Esse comportamento é garante que o tamanho de uma enumeração sempre é conhecido e pode ser projetado corretamente no sistema de tipos WinRT. O compilador rejeita código escrito dessa maneira e emite um erro do compilador C2599 junto com o erro do compilador C3197.  
  
    ```Output  
    Erro C2599: 'CustomEnum': não é permitida a declaração de encaminhamento de um enum do WinRT  
    ```  
  
    ```Output  
    Erro C3197: 'public': só pode ser usado em definições  
    ```  
  
     Exemplo \(antes\)  
  
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
  
     Exemplo \(após\)  
  
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
  
-   **Operador de não\-membro sobrecarregado novo e operador delete não podem ser declarados embutidos** \(nível 1 \(\/ W1\) ativado por padrão\)  
  
     Versões anteriores do compilador não emite um aviso quando o operador de não\-membro novo e funções do operador delete são declaradas embutidos. Código escrito dessa maneira é malformada \(nenhum diagnóstico necessário\) e pode causar problemas resultantes do novo incompatíveis e excluir operadores \(especialmente quando usado em conjunto com tamanho desalocação\) que podem ser difíceis de diagnosticar de memória.   O compilador agora emitirá C4595 para ajudar a identificar código escrito dessa forma de aviso do compilador.  
  
    ```Output  
    Aviso C4595: 'operator new': operador não-membro novo ou excluir funções não podem ser declaradas embutidos  
    ```  
  
     Exemplo \(antes\)  
  
    ```cpp  
  
              inline void* operator new(size_t sz)  // warning C4595  
    {  
      ...  
    }  
    ```  
  
     Exemplo \(após\)  
  
    ```cpp  
  
              void* operator new(size_t sz)  // removed inline  
    {  
      ...  
    }  
    ```  
  
     Corrigir o código escrito dessa maneira pode exigir que as definições de operador ser movidos para fora de um arquivo de cabeçalho e em um arquivo de origem correspondente.  
  
##  <a name="VS_Update3"></a> Aprimoramentos de conformidade no atualização 3  
  
-   **std::is\_convertable agora detecta atribuição Self**  \(biblioteca padrão\)  
  
     Versões anteriores do `std::is_convertable` característica de tipo não detecta corretamente a atribuição de um tipo de classe ao seu construtor de cópia é excluído ou privada. Agora, `std::is_convertable<>::value` está definida corretamente `false` quando aplicado a um tipo de classe com um construtor de cópia particular ou excluído.  
  
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
  
     Nas versões anteriores do Visual C\+\+, as asserções estáticas na parte inferior deste exemplo passam porque `std::is_convertable<>::value` foi definido incorretamente como `true`. Agora, `std::is_convertable<>::value` está definida corretamente `false`, fazendo com que as asserções estáticas falhar.  
  
-   **Assume o padrão ou excluído cópia trivial e mover especificadores de acesso de aspecto de construtores**  
  
     Versões anteriores do compilador não verificar o especificador de acesso de cópia trivial padronizado ou excluído e construtores move antes de permitir a ser chamado. Esse comportamento antigo estava incorreto e não de acordo com o padrão C\+\+. Em alguns casos, esse comportamento antigo criado um risco de geração de código de incorreto silenciosa, resultando em um comportamento imprevisível do tempo de execução. Agora, o compilador verifica se o especificador de acesso de cópia trivial padronizado ou excluído e move construtores para determinar se ele pode ser chamado e se não, problemas aviso do compilador C2248 como resultado.  
  
    ```Output  
    Erro C2248: 'S::S' não é membro do acesso privado declarado na classe do '  
    ```  
  
     Exemplo \(antes\)  
  
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
  
     Exemplo \(após\)  
  
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
  
-   **Reprovação do suporte a código ATL atribuída** \(nível 1 \(\/ W1\) ativado por padrão\)  
  
     Versões anteriores do compilador suportada atribuído código ATL. Como a próxima fase do suporte ATL atribuída a remoção código que [começou no Visual C\+\+ 2008](https://msdn.microsoft.com/library/bb384632\(v=vs.90\).aspx), atribuído código ATL foi preterido. O compilador agora emitirá C4467 para ajudar a identificar esse tipo de código obsoleto de aviso do compilador.  
  
    ```Output  
    Aviso C4467: uso de atributos da ATL é preterido  
    ```  
  
     Se você quiser continuar usando código ATL atribuído até que o suporte será removido do compilador, você pode desativar esse aviso, passando o `/Wv:18` ou `/wd:4467` argumentos de linha de comando para o compilador ou adicionando  `#pragma warning(disable:4467)` em seu código\-fonte.  
  
     Exemplo 1 \(antes\)  
  
    ```cpp  
  
              [uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")]  
    class A {};  
    ```  
  
     Exemplo 1 \(após\)  
  
    ```cpp  
  
    __declspec(uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")) A {};  
  
    ```  
  
     Às vezes, talvez você precise ou deseja criar um IDL arquivo para evitar o uso preterido atributos ATL, como no código de exemplo abaixo  
  
     Exemplo 2 \(antes\)  
  
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
  
     Primeiro, crie o arquivo \*.idl; o arquivo vc140.idl gerado pode ser usado para obter um arquivo \*.idl que contém as interfaces e as anotações.  
  
     Em seguida, adicione uma etapa MIDL à sua compilação para certificar\-se de que as definições de interface de C\+\+ são geradas.  
  
     Exemplo 2 IDL \(após\)  
  
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
  
     Implementação de exemplo 2 \(após\)  
  
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
  
-   **Arquivos de cabeçalho \(PCH\) pré\-compilados e incompatíveis \#include diretivas** \(\/Wall \/WX afeta somente\)  
  
     Versões anteriores do compilador aceitas incompatíveis `#include` diretivas em arquivos de origem entre `- Yc` e `- Yu` pré\-compilados de compilações ao usar arquivos de cabeçalho \(PCH\). Código escrito dessa maneira não é aceito pelo compilador.   O compilador agora CC4598 para ajudar a identificar de aviso do compilador de problemas incompatíveis `#include` diretivas ao usar arquivos PCH.  
  
    ```Output  
    Aviso C4598: 'b.h': arquivo de cabeçalho incluído especificado para Ycc.h na posição 2 não corresponde ao Yuc.h nessa posição  
    ```  
  
     Exemplo \(antes\):  
  
     X.cpp \(\-Ycc.h\)  
  
    ```cpp  
    #include "a.h"  
    #include "b.h"  
    #include "c.h"  
    ```  
  
     Z.cpp \(\-Yuc.h\)  
  
    ```cpp  
    #include "b.h"  
    #include "a.h"  // mismatched order relative to X.cpp  
    #include "c.h"  
    ```  
  
     Exemplo \(após\)  
  
     X.cpp \(\-Ycc.h\)  
  
    ```cpp  
    #include "a.h"  
    #include "b.h"   
    #include "c.h"  
    ```  
  
     Z.cpp \(\-Yuc.h\)  
  
    ```cpp  
    #include "a.h"  
    #include "b.h" // matched order relative to X.cpp  
    #include "c.h"  
    ```  
  
-   **Arquivos de cabeçalho \(PCH\) pré\-compilados e incompatíveis diretórios de inclusão** \(\/Wall \/WX afeta somente\)  
  
     Diretório de inclusão de versões anteriores do compilador aceitado incompatíveis \(`-I`\) argumentos de linha de comando para o compilador entre `- Yc` e `- Yu` pré\-compilados de compilações ao usar arquivos de cabeçalho \(PCH\). Código escrito dessa maneira não é aceito pelo compilador.   O compilador agora CC4599 para ajudar a identificar de aviso do compilador de problemas incompatíveis incluir diretório \(`-I`\) argumentos de linha de comando ao usar arquivos PCH.  
  
    ```Output  
    Aviso C4599: '-I..' : especificado para Ycc.h na posição 1 não corresponde ao Yuc.h nessa posição  
    ```  
  
     Exemplo \(antes\)  
  
    ```ms-dos  
    cl /c /Wall /Ycc.h -I.. X.cpp  
    cl /c /Wall /Yuc.h Z.cpp  
    ```  
  
     Exemplo \(após\)  
  
    ```ms-dos  
    cl /c /Wall /Ycc.h -I.. X.cpp  
    cl /c /Wall /Yuc.h -I.. Z.cpp  
    ```