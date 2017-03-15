---
title: "Inicializa&#231;&#227;o uniforme e delega&#231;&#227;o de construtores | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: aa4daa64-eaec-4a3c-ade4-d9325e31e9d4
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializa&#231;&#227;o uniforme e delega&#231;&#227;o de construtores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em C\+\+ moderno, você pode usar *a inicialização da chave* para qualquer tipo, sem o sinal de igualdade.  Além disso, você pode usar construtores de delegação para simplificar o código quando há vários construtores que executam trabalho semelhante.  
  
## Inicialização de chave  
 Você pode usar a inicialização da chave para qualquer classe, struct, ou união.  Se um tipo um construtor padrão, declarou implícita ou explicitamente, você pode usar a inicialização padrão de chave com chaves \(vazios\).  Por exemplo, a seguinte classe pode ser inicializada usando o padrão e inicialização não padrão da chave:  
  
```cpp  
#include <string>  
using namespace std;  
  
class class_a {  
public:  
    class_a() {}  
    class_a(string str) : m_string{ str } {}  
    class_a(string str, double dbl) : m_string{ str }, m_double{ dbl } {}  
double m_double;  
string m_string;  
};  
  
int main()  
{  
    class_a c1{};  
    class_a c1_1;  
  
    class_a c2{ "ww" };  
    class_a c2_1("xx");  
  
    // order of parameters is the same as the constructor  
    class_a c3{ "yy", 4.4 };  
    class_a c3_1("zz", 5.5);  
}  
  
```  
  
 Se uma classe tem os construtores não padrão, a ordem em que classificará os membros aparece em inicializador de chave é a ordem na qual os parâmetros correspondentes aparecem no construtor, não a ordem na qual os membros são declarados \(como com `class_a` no exemplo anterior\).  Caso contrário, se o tipo tem nenhum construtor declarado, a ordem na qual os membros são exibidos em inicializador de chave é igual à ordem em que são declarados; nesse caso, você pode inicializar o máximo como os membros públicos como desejar, mas não é possível ignorar nenhum membro.  O exemplo a seguir mostra a ordem que é usado na inicialização da chave quando não há construtor declarado:  
  
```cpp  
class class_d {  
public:  
    float m_float;  
    string m_string;  
    wchar_t m_char;  
};  
  
int main()  
{  
    class_d d1{};  
    class_d d1{ 4.5 };  
    class_d d2{ 4.5, "string" };  
    class_d d3{ 4.5, "string", 'c' };  
  
    class_d d4{ "string", 'c' }; // compiler error  
    class_d d5("string", 'c', 2.0 }; // compiler error  
}   
```  
  
 Se o construtor padrão é declarado explicitamente marcado como excluído, mas a inicialização da chave da opção não pode ser usada:  
  
```cpp  
class class_f {  
public:  
    class_f() = delete;  
    class_f(string x): m_string { x } {}  
    string m_string;  
};  
int main()  
{  
    class_f cf{ "hello" };  
    class_f cf1{}; // compiler error C2280: attempting to reference a deleted function  
}  
```  
  
 Você pode usar a inicialização da chave em qualquer lugar que você faria normalmente inicialização\- por exemplo, como um parâmetro de função ou um valor de retorno, ou com a palavra\-chave de `new` :  
  
```cpp  
class_d* cf = new class_d{4.5};  
kr->add_d({ 4.5 });  
return { 4.5 };  
  
```  
  
## construtores de initializer\_list  
 [initializer\_list Class](../standard-library/initializer-list-class.md) representa uma lista de objetos de um tipo especificado que pode ser usado em um construtor, e em outros contextos.  Você pode construir um initializer\_list usando a inicialização de chave:  
  
```cpp  
initializer_list<int> int_list{5, 6, 7};  
```  
  
> [!IMPORTANT]
>  Para usar essa classe, você deve incluir o cabeçalho de [\<initializer\_list\>](../standard-library/initializer-list.md) .  
  
 `initializer_list` pode ser copiado.  Nesse caso, os membros da nova lista são referências aos membros da lista original:  
  
```cpp  
initializer_list<int> ilist1{ 5, 6, 7 };  
initializer_list<int> ilist2( ilist1 );  
if (ilist1.begin() == ilist2.begin())  
    cout << "yes" << endl; // expect "yes"  
  
```  
  
 As classes do contêiner da biblioteca padrão, e também `string`, `wstring`, e `regex`, têm construtores de `initializer_list` .  Os exemplos a seguir mostram como fazer a inicialização da chave com estes construtores:  
  
```cpp  
vector<int> v1{ 9, 10, 11 };   
map<int, string> m1{ {1, "a"}, {2, "b"} };  
string s{ 'a', 'b', 'c' };   
regex rgx{'x', 'y', 'z'};   
```  
  
## Delegando construtores  
 Muitas classes têm vários construtores que fazem semelhante coisa\- por exemplo, para validar parâmetros:  
  
```cpp  
class class_c {  
public:  
    int max;  
    int min;  
    int middle;  
  
    class_c() {}  
    class_c(int my_max) {   
        max = my_max > 0 ? my_max : 10;   
    }  
    class_c(int my_max, int my_min) {   
        max = my_max > 0 ? my_max : 10;  
        min = my_min > 0 && my_min < max ? my_min : 1;  
    }  
    class_c(int my_max, int my_min, int my_middle) {  
        max = my_max > 0 ? my_max : 10;  
        min = my_min > 0 && my_min < max ? my_min : 1;  
        middle = my_middle < max && my_middle > min ? my_middle : 5;  
    }  
};  
```  
  
 Você pode reduzir o código repetitivo adicionando uma função que faça qualquer validação, mas o código para `class_c` seria mais fácil de entender e manter se um construtor pode delegar qualquer de trabalho para outro.  Para adicionar construtores de delegação, use a sintaxe de `constructor (. . .) : constructor (. . .)` :  
  
```cpp  
class class_c {  
public:  
    int max;  
    int min;  
    int middle;  
  
    class_c(int my_max) {   
        max = my_max > 0 ? my_max : 10;   
    }  
    class_c(int my_max, int my_min) : class_c(my_max) {   
        min = my_min > 0 && my_min < max ? my_min : 1;  
    }  
    class_c(int my_max, int my_min, int my_middle) : class_c (my_max, my_min){  
        middle = my_middle < max && my_middle > min ? my_middle : 5;  
}  
};  
int main() {  
  
    class_c c1{ 1, 3, 2 };  
}  
  
```  
  
 Enquanto avança com o exemplo anterior, observe que as chamadas de `class_c(int, int, int)` do primeiro o construtor `class_c(int, int)`, que por sua vez `class_c(int)`.  Cada um dos construtores executa somente o trabalho que não são executadas pelos outros construtores.  
  
 O primeiro construtor que é chamado inicializa o objeto de forma que todos os membros a serem inicializados nesse ponto.  Não é possível fazer a inicialização do membro em um construtor que delega a outro construtor, como mostrado a seguir:  
  
```cpp  
class class_a {  
public:  
    class_a() {}  
    // member initialization here, no delegate  
    class_a(string str) : m_string{ str } {}  
  
    //can’t do member initialization here  
    // error C3511: a call to a delegating constructor shall be the only member-initializer  
    class_a(string str, double dbl) : class_a(str) , m_double{ dbl } {}  
  
    // only member assignment  
    class_a(string str, double dbl) : class_a(str) { m_double = dbl; }  
    double m_double{ 1.0 };  
    string m_string;  
};  
  
```  
  
 O exemplo a seguir mostra o uso de inicializadores do membro de dados que não sejam estáticos.  Observe que se houver um construtor também inicializa um membro de dados específico, o inicializador do membro será substituído:  
  
```cpp  
class class_a {  
public:  
    class_a() {}  
    class_a(string str) : m_string{ str } {}  
    class_a(string str, double dbl) : class_a(str) { m_double = dbl; }  
    double m_double{ 1.0 };  
    string m_string{ m_double < 10.0 ? "alpha" : "beta" };  
};  
  
int main() {  
    class_a a{ "hello", 2.0 };  //expect a.m_double == 2.0, a.m_string == "hello"  
    int y = 4;  
}  
```  
  
 A sintaxe de delegação do construtor não impede a criação acidental de chamadas Constructor2 do construtor recursion\-Constructor1 que chama Constructor1\-and que nenhum erro é gerado até que haja um estouro de pilha.  É sua responsabilidade evitar ciclos.  
  
```cpp  
class class_f{  
public:  
    int max;  
    int min;  
  
    // don't do this  
    class_f() : class_f(6, 3){ }  
    class_f(int my_max, int my_min) : class_f() { }  
};  
```