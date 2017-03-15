---
title: "Fun&#231;&#245;es (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "declaradores, funções"
  - "argumentos padrão"
  - "padrões, arguments"
  - "definições de função"
  - "definições de função, sobre definições de função"
ms.assetid: 33ba01d5-75b5-48d2-8eab-5483ac7d2274
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma função é um bloco de código que executa uma operação.  Uma função pode, opcionalmente, definir parâmetros de entrada que permitem que os chamadores passar argumentos para a função.  Uma função opcionalmente pode retornar um valor como saída.  Funções são úteis para encapsular operações comuns em um único bloco reutilizável, de preferência com um nome que descreva claramente que a função faz.  A seguinte função aceita dois inteiros de um chamador e retorna seu soma. `a` e `b` são *parâmetros* do tipo `int`.  
  
```  
int sum(int a, int b)  
{  
    return a + b;  
}  
```  
  
 A função pode ser invocado, ou *chamado*, de qualquer número de lugares no programa.  Os valores que são passados para a função são o *argumentos*, cujos tipos devem ser compatíveis com os tipos de parâmetro na definição de função.  
  
```  
int main()  
{  
    int i = sum(10, 32);  
    int j = sum(i, 66);  
    cout << "The value of j is" << j << endl; // 108  
}  
```  
  
 Há um limite prático para comprimento de função, mas um bom design destina\-se para as funções que executam uma única tarefa bem definida.  Algoritmos complexos devem ser divididos em fáceis de entender mais simples funções sempre que possível.  
  
 Funções que são definidas no escopo da classe são chamadas de funções de membro.  Em C\+\+, ao contrário de outros idiomas, uma função também pode ser definida no escopo de namespace \(incluindo o namespace global implícito\).  Essas funções são chamadas *livre funções* ou *funções de membro não*; elas são usadas amplamente na biblioteca padrão.  
  
## Partes de uma declaração de função  
 Uma função mínima *declaração* consiste o tipo de retorno, o nome da função e lista de parâmetros \(que pode estar vazia\), junto com as palavras\-chave opcional que fornecem instruções adicionais para o compilador.  Uma definição de função consiste em uma declaração, mais o *corpo*, que é todo o código entre as chaves.  Uma declaração de função seguida por um ponto e vírgula pode aparecer em vários locais em um programa.  Deve aparecer antes de qualquer chamada para essa função em cada unidade de conversão.  A definição da função deve aparecer apenas uma vez no programa de acordo com uma definição de regra \(ODR\).  
  
 As peças necessárias de uma declaração de função são:  
  
1.  O tipo de retorno, que especifica o tipo do valor que a função retorna, ou  `void` se nenhum valor for retornado.  No C\+\+ 11, automática é um tipo de retorno válido que instrui o compilador a inferir o tipo da instrução de retorno.  No C\+\+ 14, decltype\(auto\) também é permitido.  Para obter mais informações, consulte dedução de tipo em tipos de retorno abaixo.  
  
2.  O nome da função, que deve começar com uma letra ou sublinhado e não pode conter espaços.  Em geral, sublinhados nos nomes de função de biblioteca padrão indicam funções de membro privado ou funções não\-membro que não são destinadas para usam seu código.  
  
3.  A lista de parâmetros, uma chave delimitado, separada por vírgulas conjunto de zero ou mais parâmetros que especificam o tipo e, opcionalmente, um nome local pelo qual os valores podem ser acessados dentro do corpo da função.  
  
 Partes opcionais de uma declaração de função são:  
  
1.  `constexpr`, que indica que o valor de retorno da função é um valor constante pode ser computado em tempo de compilação.  
  
    ```  
  
                  constexpr float exp(float x, int n)  
    {  
        return n == 0 ? 1 :  
            n % 2 == 0 ? exp(x * x, n / 2) :  
            exp(x * x, (n - 1) / 2) * x;  
    };  
    ```  
  
2.  Seu `linkage` especificação, `extern` ou `static`.  
  
    ```  
    Declare printf with C linkage.  
    extern "C" int printf( const char *fmt, ... );  
  
    ```  
  
     Para obter mais informações, consulte [Programa e ligação](../cpp/program-and-linkage-cpp.md).  
  
3.  `inline`, que instrui o compilador substitua todas as chamadas para a função com o código de função.  inlining pode ajudar o desempenho em cenários onde uma função executa rapidamente e é chamada repetidamente em uma seção crítica ao desempenho do código.  
  
    ```  
    inline double Account::GetBalance()  
    {  
        return balance;  
    }  
    ```  
  
     Para obter mais informações, consulte [Funções embutidas](../Topic/Inline%20Functions%20\(C++\).md).  
  
4.  `noexcept`, que especifica se a função pode gerar uma exceção.  No exemplo a seguir, a função não lança uma exceção se o `is_pod` expressão é avaliada como `true`.  
  
    ```  
    #include <type_traits>  
  
    template <typename T>  
    T copy_object(T& obj) noexcept(std::is_pod<T>) {...}  
    ```  
  
     Para obter mais informações, consulte [noexcept](../Topic/noexcept%20\(C++\).md).  
  
5.  \(Somente para funções de membro\) Os qualificadores cv, que especifica se a função é `const` ou `volatile`.  
  
6.  \(Funções de membro apenas\) `virtual`, `override`, ou `final`.  `virtual` Especifica que uma função pode ser substituída em uma classe derivada.  `override` significa que uma função em uma classe derivada é substituindo uma função virtual.  `final` significa que uma função não pode ser substituída adicional em qualquer classe derivada.  Para obter mais informações, consulte [Funções virtuais](../cpp/virtual-functions.md).  
  
7.  \(funções de membro apenas\) `static` aplicado a um membro da função significa que a função não está associada a qualquer instância do objeto da classe.  
  
8.  \(Somente para funções de membro não estático\) O qualificador ref, que especifica para o compilador qual sobrecarga de uma função para escolher quando o parâmetro de objeto implícito \(\* isso\) é um rvalue referência vs.  uma referência de lvalue.  
  
 A figura a seguir mostra as partes de uma definição de função.  A área sombreada é o corpo da função.  
  
 ![Partes de definição de função](../cpp/media/vc38ru1.png "vc38RU1")  
Partes de uma definição de função  
  
## Definições de função  
 Variáveis declaradas no corpo são chamadas de variáveis locais ou locais.  Eles saem do escopo quando a função será encerrado; Portanto, uma função nunca deve retornar uma referência a um local\!  
  
## Modelos de função  
 Um modelo de função é semelhante a um modelo de classe; ele gera funções concretas com base nos argumentos de modelo.  Em muitos casos, o modelo é capaz de inferir os argumentos de tipo e, portanto, não é necessário especificá\-los explicitamente.  
  
```  
template<typename Lhs, typename Rhs>  
auto Add2(const Lhs& lhs, const Rhs& rhs)  
{  
    return lhs + rhs;  
}  
  
auto a = Add2(3.13, 2.895); // a is a double  
auto b = Add2(string{ "Hello" }, string{ " World" }); // b is a std::string  
```  
  
 Para obter mais informações, consulte [modelos de função](../cpp/function-templates.md)  
  
## Parâmetros de função e argumentos  
 Uma função possui uma lista de parâmetros separados por vírgulas de zero ou mais tipos, cada um deles tem um nome pelo qual ele pode ser acessado dentro do corpo da função.  Um modelo de função pode especificar parâmetros adicionais de tipo ou valor.  O chamador passa os argumentos que são valores concretos cujos tipos são compatíveis com a lista de parâmetros.  
  
 Por padrão, os argumentos são passados para a função por valor, o que significa que a função recebe uma cópia do objeto que está sendo passado.  Para objetos grandes, fazer uma cópia pode ser caro e nem sempre é necessário.  Para fazer com argumentos a serem passados por referência \(especificamente a referência de lvalue\), adicione uma referência quaitifer para o parâmetro:  
  
```  
void DoSomething(std::string& input){...}  
```  
  
 Quando uma função modifica um argumento que é passado por referência, ele modifica o objeto original, não uma cópia local.  Para impedir que uma função modificando um argumento, qualifique o parâmetro como const &:  
  
```  
void DoSomething(const std::string& input){...}  
```  
  
 **C\+\+ 11:**  lide explicitamente os argumentos são passados por referência de rvalue ou referência de lvalue, use um comercial duplo no parâmetro para indicar uma referência universal:  
  
```  
void DoSomething(const std::string&& input){...}  
```  
  
 Uma função declarada com a palavra\-chave única `void` no parâmetro de lista de declarações não utiliza argumentos, contanto que a palavra\-chave `void` é o primeiro e o único membro da lista de declaração de argumentos.  Os argumentos do tipo `void` em qualquer outro lugar da lista gera erros.  Por exemplo:  
  
```  
  
// OK same as GetTickCount()  
long GetTickCount( void );   
```  
  
 Embora seja ilegal especificar um argumento `void`, exceto conforme descrito aqui, os tipos derivados do tipo `void` \(como ponteiros para `void` e matrizes de `void`\) podem aparecer em qualquer lugar na lista de declarações de argumentos.  
  
### Argumentos padrão  
 O último parâmetro ou parâmetros em uma assinatura de função podem ser atribuídos um argumento padrão, o que significa que o chamador pode omitir o argumento ao chamar a função, a menos que desejam especificar algum outro valor.  
  
```  
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
  
 Para obter mais informações, consulte [argumentos padrão](../Topic/Default%20Arguments.md) e [argumentos padrão para modelos de classe](../Topic/Default%20Arguments%20for%20Class%20Templates.md).  
  
## Tipos de retorno de função  
 Uma função não pode retornar outra função, ou uma matriz interna; No entanto, ele pode retornar ponteiros para esses tipos, ou um *lambda*, que produz um objeto de função.  Exceto para esses casos, uma função pode retornar um valor de qualquer tipo que está no escopo, ou não poderá retornar nenhum valor, nesse caso o tipo de retorno, é `void`.  
  
### Tipos de retorno à direita  
 Um tipo de retorno "comum" está localizado no lado esquerdo da assinatura de função.  Um *à direita de tipo de retorno* está localizado no lado mais à direita da assinatura e é precedido pelo operador \-\>.  Tipos de retorno à direita são especialmente úteis em modelos de função quando o tipo do valor de retorno depende de parâmetros de modelo.  
  
```  
template<typename Lhs, typename Rhs>  
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)  
{  
    return lhs + rhs;   
}  
```  
  
 Quando `auto` é usado em conjunto com um tipo de retorno à direita, ele serve como um espaço reservado para qualquer expressão decltype produz e não realiza dedução de tipo.  
  
###  <a name="type_deduction"></a> Dedução de tipo em tipos de retorno \(C \+ \+ 14\)  
 No C\+\+ 14, você pode usar `auto` para instruir o compilador a inferir o tipo de retorno do corpo da função sem precisar fornecer um tipo de retorno à direita.  Observe que `auto` sempre deduz um retorno por valor.  Use `auto&&` para instruir o compilador a deduzir uma referência.  
  
 Neste exemplo, `auto` ser deduzida como uma cópia do valor não constante da soma das lhs e rhs.  
  
```  
template<typename Lhs, typename Rhs>  
auto Add2(const Lhs& lhs, const Rhs& rhs)  
{  
    return lhs + rhs; //returns a non-const object by value  
}  
```  
  
 Observe que `auto` também não preserva o const\-ness do tipo deduz por ele.  Para funções cujo valor de retorno precisa preservar o const\-ness ou ref a qualidade dos seus argumentos de encaminhamento, você pode usar o `decltype(auto)` palavra\-chave, que usa o `decltype` inferência de tipos de regras e preserva todas as informações de tipo.  `decltype(auto)` pode ser usado como um valor de retorno comum no lado esquerdo ou como um valor de retorno à direita.  
  
 O exemplo a seguir \(com base no código de [N3493](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2013/n3493.html)\), mostra `decltype(auto)` sendo usados para habilitar o encaminhamento perfeito dos argumentos de função em um tipo de retorno não é conhecido até que o modelo é instanciado.  
  
```  
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
  
## Variáveis locais de função  
 Uma variável é declarada dentro de um corpo de função é chamada uma *variável local* ou simplesmente um *local*.  Locais de não\-estático só são visíveis dentro do corpo da função e, se eles são declarados na pilha saem do escopo quando a função for encerrada.  Quando você criar uma variável local e retorná\-lo por valor, o compilador normalmente pode executar a otimização de valor de retorno para evitar operações de cópia desnecessárias.  Se você retornar uma variável local por referência, o compilador emitirá um aviso como qualquer tentativa de usar essa referência pelo chamador ocorrerá depois que o local foi destruída.  
  
 Os objetos estáticos locais são destruídos durante o término especificado por `atexit`.  Se um objeto estático não foi construído porque o fluxo de programa do controle ignorou a declaração dele, nenhuma tentativa de destruição de objeto será feita.  
  
### Variáveis locais estáticas  
 No C\+\+ uma variável local pode ser declarada como estática.  A variável só é visível dentro do corpo de função, mas existe uma única cópia da variável para todas as instâncias da função.  
  
## Ponteiros de função  
 C\+\+ oferece suporte a ponteiros de função da mesma maneira que a linguagem C.  No entanto uma alternativa mais tipo seguro é geralmente usam um objeto de função.  
  
 É recomendável que `typedef` seja usado para declarar um alias para o tipo de ponteiro de função se for declarar uma função que retorna um tipo de ponteiro de função.  Por exemplo  
  
```  
typedef int (*fp)(int);  
fp myFunction(char* s); // function returning function pointer  
```  
  
 Se isso não for feito, a sintaxe adequada para a declaração de função pode ser deduzida da sintaxe do declarador para o ponteiro de função substituindo o identificador \(`fp` no exemplo acima\) pelo nome das funções e a lista de argumentos, como segue:  
  
```  
int (*myFunction(char* s))(int);  
```  
  
 A declaração anterior é equivalente à declaração que usa typedef acima.  
  
## Consulte também  
 [Sobrecarga de função](../cpp/function-overloading.md)   
 [Funções com listas de argumentos variáveis](../cpp/functions-with-variable-argument-lists-cpp.md)   
 [Funções explicitamente usadas como padrão e excluídas](../Topic/Explicitly%20Defaulted%20and%20Deleted%20Functions.md)   
 [Pesquisa de nome dependente do argumento \(Koenig\) em funções](../Topic/Argument-Dependent%20Name%20\(Koenig\)%20Lookup%20on%20Functions.md)   
 [Argumentos padrão](../Topic/Default%20Arguments.md)   
 [Funções embutidas](../Topic/Inline%20Functions%20\(C++\).md)