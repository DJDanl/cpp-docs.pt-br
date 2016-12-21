---
title: "vetor classe 1 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::vector"
  - "vector"
  - "std.vector"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe vector"
ms.assetid: a3e0a8f8-7565-4fe0-93e4-e4d74ae1b70d
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vetor classe 1
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do vetor STL é uma classe de modelo de contêineres de sequência que organiza os elementos de um determinado tipo em uma organização linear e permite acesso aleatório rapidamente a qualquer elemento. Eles devem ser o contêiner preferencial para uma sequência de quando o desempenho de acesso aleatório é um fator determinante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type, class Allocator = allocator<Type>>  
class vector  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Tipo*  
 O tipo de dados do elemento a ser armazenado no vetor  
  
 `Allocator`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre o vetor alocação e desalocação de memória. Esse argumento é opcional e o valor padrão é **alocador***\< tipo>.*  
  
## <a name="remarks"></a>Comentários  
 Vetores permitem tempo constante inserções e exclusões no final da sequência. Inserindo ou excluindo elementos no meio de um vetor requer tempo linear. O desempenho da [classe deque](../standard-library/deque-class.md) contêiner é superior em relação a inserções e exclusões no início e no final de uma sequência. O [classe list](../standard-library/list-class.md) contêiner é superior em relação a inserções e exclusões em qualquer local dentro de uma sequência.  
  
 Realocação de vetor ocorre quando uma função de membro deve aumentar sequência contida no objeto vector além da sua capacidade de armazenamento atual. Outros inserções e exclusões podem alterar vários endereços de armazenamento dentro da sequência. Em todos esses casos, iteradores ou referências que apontem para partes alteradas da sequência de que se tornar inválidos. Se nenhuma realocação ocorre, somente iteradores e referências antes do ponto de inserção ou exclusão permanecem válidas.  
  
 O [vector \< bool> classe](../Topic/vector%3Cbool%3E%20Class.md) é uma especialização completa do vetor de classe de modelo para elementos do tipo bool com um alocador para o tipo subjacente usado pela especialização.  
  
 O [vector \< bool> referência a classe](../Topic/vector%3Cbool%3E%20Class.md#vector_lt_bool_gt___reference_class) é uma classe aninhada cujos objetos são capazes de fornecer referências a elementos (bits únicos) em um vetor \< bool> objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[vetor](#vector__vector)|Constrói um vetor de um tamanho específico ou com elementos de um valor específico ou com um determinado `allocator` ou como uma cópia de algum outro vetor.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#vector__allocator_type)|Um tipo que representa o `allocator` classe para o objeto de vetor.|  
|[const_iterator](#vector__const_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler um `const` elemento em um vetor.|  
|[const_pointer](#vector__const_pointer)|Um tipo que fornece um ponteiro para um `const` elemento em um vetor.|  
|[const_reference](#vector__const_reference)|Um tipo que fornece uma referência a um `const` elemento armazenado em um vetor para leitura e execução `const` operações.|  
|[const_reverse_iterator](#vector__const_reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer `const` elemento em vector.|  
|[difference_type](#vector__difference_type)|Um tipo que fornece a diferença entre os endereços dos dois elementos em um objeto vector.|  
|[iterador](#vector__iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor.|  
|[ponteiro](#vector__pointer)|Um tipo que fornece um ponteiro para um elemento em um vetor.|  
|[referência](#vector__reference)|Um tipo que fornece uma referência a um elemento armazenado em um vetor.|  
|[reverse_iterator](#vector__reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor invertido.|  
|[size_type](#vector__size_type)|Um tipo que conta o número de elementos em um objeto vector.|  
|[value_type](#vector__value_type)|Um tipo que representa o tipo de dados armazenado em um vetor.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[atribuir](#vector__assign)|Apaga um vetor e copia os elementos especificados para o vetor vazio.|  
|[em](#vector__at)|Retorna uma referência ao elemento em um local especificado no vetor.|  
|[Voltar](#vector__back)|Retorna uma referência para o último elemento de vetor.|  
|[começar](#vector__begin)|Retorna um iterador de acesso aleatório para o primeiro elemento no vetor.|  
|[capacidade](#vector__capacity)|Retorna o número de elementos que o vetor pode conter sem alocando mais armazenamento.|  
|[cbegin](#vector__cbegin)|Retorna um iterador const de acesso aleatório para o primeiro elemento no vetor.|  
|[cend](#vector__cend)|Retorna um iterador const de acesso aleatório que aponta além do fim do vetor.|  
|[crbegin](#vector__crbegin)|Retorna um iterador const para o primeiro elemento em um vetor invertido.|  
|[crend](#vector__crend)|Retorna um iterador const para o final de um vetor invertido.|  
|[Limpar](#vector__clear)|Apaga os elementos do vetor.|  
|[dados](#vector__data)|Retorna um ponteiro para o primeiro elemento no vetor.|  
|[emplace](#vector__emplace)|Insere um elemento construído no local para o vetor em uma posição especificada.|  
|[emplace_back](#vector__emplace_back)|Adiciona um elemento construído no local até o final do vetor.|  
|[vazio](#vector__empty)|Testa se o contêiner de vetor está vazio.|  
|[final](#vector__end)|Retorna um iterador de acesso aleatório que aponta para o final do vetor.|  
|[apagar](#vector__erase)|Remove um elemento ou um intervalo de elementos em um vetor de posições especificadas.|  
|[frente](#vector__front)|Retorna uma referência para o primeiro elemento em um vetor.|  
|[get_allocator](#vector__get_allocator)|Retorna um objeto para o `allocator` classe usada por um vector.|  
|[Inserir](#vector__insert)|Insere um elemento ou um número de elementos no vetor em uma posição especificada.|  
|[max_size](#vector__max_size)|Retorna o comprimento máximo do vetor.|  
|[pop_back](#vector__pop_back)|Exclui o elemento no final do vetor.|  
|[push_back](#vector__push_back)|Adicione um elemento ao final do vetor.|  
|[rbegin](#vector__rbegin)|Retorna um iterador para o primeiro elemento em um vetor invertido.|  
|[rend](#vector__rend)|Retorna um iterador no final de um vetor invertido.|  
|[reservar](#vector__reserve)|Reserva um comprimento mínimo de armazenamento para um objeto de vetor.|  
|[redimensionar](#vector__resize)|Especifica um novo tamanho para um vetor.|  
|[shrink_to_fit](#vector__shrink_to_fit)|Descartes de excesso de capacidade.|  
|[tamanho](#vector__size)|Retorna o número de elementos no vetor.|  
|[troca](#vector__swap)|Troca os elementos de dois vetores.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador &#91; &#93;](#vector__operator_at)|Retorna uma referência para o elemento de vetor em uma posição especificada.|  
|[operador =](#vector__operator_eq)|Substitui os elementos do vetor com uma cópia de outro vetor.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< vector>  
  
 **Namespace:** std  
  
##  <a name="a-namevectorallocatortypea-vectorallocatortype"></a><a name="vector__allocator_type"></a>  Vector:: allocator_type  
 Um tipo que representa a classe do alocador para o objeto de vetor.  
  
```  
typedef Allocator allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `allocator_type` é um sinônimo para o parâmetro de modelo **alocador.**  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [get_allocator](#vector__get_allocator) para obter um exemplo que usa `allocator_type`.  
  
##  <a name="a-namevectorassigna-vectorassign"></a><a name="vector__assign"></a>  Vector:: Assign  
 Apaga um vetor e copia os elementos especificados para o vetor vazio.  
  
```  
void assign(
    size_type Count,  
    const Type& Val);

void assign(
    initializer_list<Type> IList);

template <class InputIterator>  
void assign(
    InputIterator First,  
    InputIterator Last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `First`  
 Posição do primeiro elemento no intervalo de elementos a serem copiados.  
  
 `Last`  
 Posição do primeiro elemento além do intervalo de elementos a serem copiados.  
  
 `Count`  
 O número de cópias de um elemento que está sendo inserido no vetor.  
  
 `Val`  
 O valor do elemento que está sendo inserido no vetor.  
  
 `IList`  
 O initializer_list que contém os elementos para inserir.  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes em um vetor, atribuir qualquer inserções um intervalo especificado de elementos do vetor de original em um vetor ou inserções cópias de um novo elemento de um valor especificado em um vetor.  
  
### <a name="example"></a>Exemplo  
  
```  
/ vector_assign.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector<int> v1, v2, v3;  
  
    v1.push_back(10);  
    v1.push_back(20);  
    v1.push_back(30);  
    v1.push_back(40);  
    v1.push_back(50);  
  
    cout << "v1 = ";  
    for (auto& v : v1){  
        cout << v << " ";  
    }  
    cout << endl;  
  
    v2.assign(v1.begin(), v1.end());  
    cout << "v2 = ";  
    for (auto& v : v2){  
        cout << v << " ";  
    }  
    cout << endl;  
  
    v3.assign(7, 4);  
    cout << "v3 = ";  
    for (auto& v : v3){  
        cout << v << " ";  
    }  
    cout << endl;  
  
    v3.assign({ 5, 6, 7 });  
    for (auto& v : v3){  
        cout << v << " ";  
    }  
    cout << endl;  
}  
  
```  
  
##  <a name="a-namevectorata-vectorat"></a><a name="vector__at"></a>  Vector:: AT  
 Retorna uma referência ao elemento em um local especificado no vetor.  
  
```  
reference at(size_type _Pos);

const_reference at(size_type _Pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Pos`  
 O número de subscrito ou a posição do elemento de referência no vetor.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao elemento Subscrita no argumento. Se `_Off` for maior que o tamanho do vetor, **em** lança uma exceção.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno **em** é atribuído a um `const_reference`, o objeto de vetor não pode ser modificado. Se o valor de retorno **em** é atribuído a um **referência**, o objeto de vetor pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_at.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
  
   const int &i = v1.at( 0 );  
   int &j = v1.at( 1 );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="a-namevectorbacka-vectorback"></a><a name="vector__back"></a>  Vector:: back  
 Retorna uma referência para o último elemento de vetor.  
  
```  
reference back();

const_reference back() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O último elemento de vetor. Se o vetor está vazio, o valor de retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno **novamente** é atribuído a um `const_reference`, o objeto de vetor não pode ser modificado. Se o valor de retorno **novamente** é atribuído a um **referência**, o objeto de vetor pode ser modificado.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento em um vetor vazio.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_back.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 11 );  
  
   int& i = v1.back( );  
   const int& ii = v1.front( );  
  
   cout << "The last integer of v1 is " << i << endl;  
   i--;  
   cout << "The next-to-last integer of v1 is "<< ii << endl;  
}  
```  
  
##  <a name="a-namevectorbegina-vectorbegin"></a><a name="vector__begin"></a>  Vector:: begin  
 Retorna um iterador de acesso aleatório para o primeiro elemento no vetor.  
  
```  
const_iterator begin() const;

 
iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Trata o primeiro elemento em um iterador de acesso aleatório do `vector` ou para o local após um vazio `vector`. Você sempre deve comparar o valor retornado com [Vector:: end](#vector__end) para garantir que ele é válido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `begin` é atribuído a um [Vector:: const_iterator](#vector__const_iterator), o `vector` objeto não pode ser modificado. Se o valor de retorno de `begin` é atribuído a um [Vector:: Iterator](#vector__iterator), o `vector` objeto pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_begin.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector<int> c1;  
    vector<int>::iterator c1_Iter;  
    vector<int>::const_iterator c1_cIter;  
  
    c1.push_back(1);  
    c1.push_back(2);  
  
    cout << "The vector c1 contains elements:";  
    c1_Iter = c1.begin();  
    for (; c1_Iter != c1.end(); c1_Iter++)  
    {  
        cout << " " << *c1_Iter;  
    }  
    cout << endl;  
  
    cout << "The vector c1 now contains elements:";  
    c1_Iter = c1.begin();  
 *c1_Iter = 20;  
    for (; c1_Iter != c1.end(); c1_Iter++)  
    {  
        cout << " " << *c1_Iter;  
    }  
    cout << endl;  
  
    // The following line would be an error because iterator is const  
    // *c1_cIter = 200;  
}  
```  
  
```Output  
The vector c1 contains elements: 1 2  
The vector c1 now contains elements: 20 2  
```  
  
##  <a name="a-namevectorcapacitya-vectorcapacity"></a><a name="vector__capacity"></a>  Vector:: Capacity  
 Retorna o número de elementos que o vetor pode conter sem alocando mais armazenamento.  
  
```  
size_type capacity() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento atual de armazenamento alocada para o vetor.  
  
### <a name="remarks"></a>Comentários  
 A função de membro [redimensionar](#vector__resize) será mais eficiente se for alocada memória suficiente para acomodar. Use a função de membro [reservar](#vector__reserve) para especificar a quantidade de memória alocada.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_capacity.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
  
   v1.push_back( 1 );  
   cout << "The length of storage allocated is "  
        << v1.capacity( ) << "." << endl;  
  
   v1.push_back( 2 );  
   cout << "The length of storage allocated is now "  
        << v1.capacity( ) << "." << endl;  
}  
```  
  
```Output  
The length of storage allocated is 1.  
The length of storage allocated is now 2.  
```  
  
##  <a name="a-namevectorcbegina-vectorcbegin"></a><a name="vector__cbegin"></a>  Vector:: cbegin  
 Retorna um iterador `const` que trata o primeiro elemento no intervalo.  
  
```  
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório `const` que aponta o primeiro elemento do intervalo ou o local logo após o fim de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.  
  
 Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, ele é usado em conjunto com o [automático](../cpp/auto-cpp.md) Digite a palavra-chave de dedução, conforme mostrado no exemplo a seguir. No exemplo, considere `Container` para ser um modificáveis (não - `const`) contêiner de qualquer tipo que oferece suporte a `begin()` e `cbegin()`.  
  
```cpp  
 
auto i1 = Container.begin();
// i1 is Container<T>::iterator   
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator  
```  
  
##  <a name="a-namevectorcenda-vectorcend"></a><a name="vector__cend"></a>  Vector:: cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório `const` que aponta para além do fim do intervalo.  
  
### <a name="remarks"></a>Comentários  
 `cend` é usado para testar se um iterador passou do fim de seu intervalo.  
  
 Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, ele é usado em conjunto com o [automático](../cpp/auto-cpp.md) Digite a palavra-chave de dedução, conforme mostrado no exemplo a seguir. No exemplo, considere `Container` para ser um modificáveis (não - `const`) contêiner de qualquer tipo que oferece suporte a `end()` e `cend()`.  
  
```cpp  
 
auto i1 = Container.end();
// i1 is Container<T>::iterator   
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator  
```  
  
 O valor retornado por `cend` não deve ser desreferenciado.  
  
##  <a name="a-namevectorcleara-vectorclear"></a><a name="vector__clear"></a>  Vector  
 Apaga os elementos do vetor.  
  
```  
void clear();
```  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_clear.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "The size of v1 is " << v1.size( ) << endl;  
   v1.clear( );  
   cout << "The size of v1 after clearing is " << v1.size( ) << endl;  
}  
```  
  
```Output  
The size of v1 is 3  
The size of v1 after clearing is 0  
```  
  
##  <a name="a-namevectorconstiteratora-vectorconstiterator"></a><a name="vector__const_iterator"></a>  Vector:: const_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler um **const** elemento em um vetor.  
  
```  
typedef implementation-defined const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [novamente](#vector__back) para obter um exemplo que usa `const_iterator`.  
  
##  <a name="a-namevectorconstpointera-vectorconstpointer"></a><a name="vector__const_pointer"></a>  Vector:: const_pointer  
 Um tipo que fornece um ponteiro para um **const** elemento em um vetor.  
  
```  
typedef typename Allocator::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.  
  
 Um [iterador](#vector__iterator) é mais comumente usado para acessar um elemento de vetor.  
  
##  <a name="a-namevectorconstreferencea-vectorconstreference"></a><a name="vector__const_reference"></a>  Vector:: const_reference  
 Um tipo que fornece uma referência a um **const** elemento armazenado em um vetor para leitura e execução **const** operações.  
  
```  
typedef typename Allocator::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_reference` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_const_ref.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
  
   const vector <int> v2 = v1;  
   const int &i = v2.front( );  
   const int &j = v2.back( );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
  
   // The following line would cause an error as v2 is const  
   // v2.push_back( 30 );  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="a-namevectorconstreverseiteratora-vectorconstreverseiterator"></a><a name="vector__const_reverse_iterator"></a>  Vector:: const_reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer **const** elemento em vector.  
  
```  
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `const_reverse_iterator` não é possível modificar o valor de um elemento e é usado para iterar por meio de vetor em ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Consulte [rbegin](#vector__rbegin) para obter um exemplo de como declarar e usar um iterador.  
  
##  <a name="a-namevectorcrbegina-vectorcrbegin"></a><a name="vector__crbegin"></a>  Vector:: crbegin  
 Retorna um iterador const para o primeiro elemento em um vetor invertido.  
  
```  
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma constante invertido que trata o primeiro elemento em um invertido de iterador de acesso aleatório [vetor](../standard-library/vector-class.md) ou abordando o que foi o último elemento não invertida `vector`.  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `crbegin`, o objeto `vector` não pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_crbegin.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator v1_Iter;  
   vector <int>::const_reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   v1_Iter = v1.begin( );  
   cout << "The first element of vector is "  
        << *v1_Iter << "." << endl;  
  
   v1_rIter = v1.crbegin( );  
   cout << "The first element of the reversed vector is "  
        << *v1_rIter << "." << endl;  
}  
```  
  
```Output  
The first element of vector is 1.  
The first element of the reversed vector is 2.  
```  
  
##  <a name="a-namevectorcrenda-vectorcrend"></a><a name="vector__crend"></a>  Vector:: crend  
 Retorna um iterador const que trata o local após o último elemento em um vetor invertido.  
  
```  
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma constante invertido iterador de acesso aleatório que trata o local após o último elemento em um invertido [vetor](../standard-library/vector-class.md) (o local que precedeu o primeiro elemento não invertida `vector`).  
  
### <a name="remarks"></a>Comentários  
 `crend` é usado com um invertido `vector` tão [Vector:: cend](#vector__cend) é usado com um `vector`.  
  
 Com o valor de retorno `crend` (adequadamente diminuído), o `vector` objeto não pode ser modificado.  
  
 `crend` pode ser usado para testar se um iterador inverso alcançou o final de sua `vector`.  
  
 O valor retornado por `crend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_crend.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::const_reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )  
      cout << *v1_rIter << endl;  
}  
```  
  
```Output  
2  
1  
```  
  
##  <a name="a-namevectordataa-vectordata"></a><a name="vector__data"></a>  Vector:: data  
 Retorna um ponteiro para o primeiro elemento no vetor.  
  
```  
const_pointer data() const;

 
pointer data();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o primeiro elemento no [vetor](../standard-library/vector-class.md) ou para o local após um vazio `vector`.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_data.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector<int> c1;  
    vector<int>::pointer c1 ptr;  
    vector<int>::const_pointer c1_cPtr;  
  
    c1.push_back(1);  
    c1.push_back(2);  
  
    cout << "The vector c1 contains elements:";  
    c1_cPtr = c1.data();  
    for (size_t n = c1.size(); 0 < n; --n, c1_cPtr++)  
    {  
        cout << " " << *c1_cPtr;  
    }  
    cout << endl;  
  
    cout << "The vector c1 now contains elements:";  
    c1 ptr = c1.data();  
 *c1 ptr = 20;  
    for (size_t n = c1.size(); 0 < n; --n, c1 ptr++)  
    {  
        cout << " " << *c1 ptr;  
    }  
    cout << endl;  
}  
```  
  
```Output  
The vector c1 contains elements: 1 2  
The vector c1 now contains elements: 20 2  
```  
  
##  <a name="a-namevectordifferencetypea-vectordifferencetype"></a><a name="vector__difference_type"></a>  Vector:: difference_type  
 Um tipo que fornece a diferença entre dois iteradores que se referem a elementos no mesmo vetor.  
  
```  
typedef typename Allocator::difference_type difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 Um `difference_type` também pode ser descrito como o número de elementos entre dois ponteiros, como um ponteiro para um elemento contém o endereço.  
  
 Um [iterador](#vector__iterator) é mais comumente usado para acessar um elemento de vetor.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_diff_type.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <vector>  
#include <algorithm>  
  
int main( )  
{  
   using namespace std;  
  
   vector <int> c1;  
   vector <int>::iterator c1_Iter, c2_Iter;  
  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
   c1.push_back( 10 );  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
  
   c1_Iter = c1.begin( );  
   c2_Iter = c1.end( );  
  
   vector <int>::difference_type   df_typ1, df_typ2, df_typ3;  
  
   df_typ1 = count( c1_Iter, c2_Iter, 10 );  
   df_typ2 = count( c1_Iter, c2_Iter, 20 );  
   df_typ3 = count( c1_Iter, c2_Iter, 30 );  
   cout << "The number '10' is in c1 collection " << df_typ1 << " times.\n";  
   cout << "The number '20' is in c1 collection " << df_typ2 << " times.\n";  
   cout << "The number '30' is in c1 collection " << df_typ3 << " times.\n";  
}  
```  
  
```Output  
The number '10' is in c1 collection 1 times.  
The number '20' is in c1 collection 2 times.  
The number '30' is in c1 collection 3 times.  
```  
  
##  <a name="a-namevectoremplacea-vectoremplace"></a><a name="vector__emplace"></a>  Vector:: emplace  
 Insere um elemento construído no local para o vetor em uma posição especificada.  
  
```  
iterator emplace(
    const_iterator _Where,  
    Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|A posição do [vetor](../standard-library/vector-class.md) onde o primeiro elemento é inserido.|  
|` val`|O valor do elemento que está sendo inserido o `vector`.|  
  
### <a name="return-value"></a>Valor de retorno  
 A função retorna um iterador que aponta para a posição em que o novo elemento foi inserido para o `vector`.  
  
### <a name="remarks"></a>Comentários  
 Qualquer operação de inserção pode ser caro, consulte [classe vector](../standard-library/vector-class.md) para uma discussão sobre `vector` desempenho.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_emplace.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
// initialize a vector of vectors by moving v1  
   vector < vector <int> > vv1;  
  
   vv1.emplace( vv1.begin(), move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      {  
      cout << "vv1[0] =";  
      for (Iter = vv1[0].begin( ); Iter != vv1[0].end( ); Iter++ )  
         cout << " " << *Iter;  
      cout << endl;  
      }  
}  
```  
  
```Output  
v1 = 10 20 30  
vv1[0] = 10 20 30  
```  
  
##  <a name="a-namevectoremplacebacka-vectoremplaceback"></a><a name="vector__emplace_back"></a>  Vector:: emplace_back  
 Adiciona um elemento construído no local até o final do vetor.  
  
```  
template <class... Types>  
void emplace_back(Types&&... _Args);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Args`|Argumentos de construtor. A função infere que sobrecarga de construtor para chamar com base nos argumentos fornecidos.|  
  
### <a name="example"></a>Exemplo  
  
```cpp  
  
#include <vector>  
struct obj  
{  
   obj(int, double) {}  
};  
  
int main()  
{  
   std::vector<obj> v;  
   v.emplace_back(1, 3.14); // obj in created in place in the vector  
}  
  
```  
  
##  <a name="a-namevectoremptya-vectorempty"></a><a name="vector__empty"></a>  Vector:: Empty  
 Testa se o vetor está vazio.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se o vetor está vazio; **False** se o vetor não está vazio.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_empty.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
  
   if ( v1.empty( ) )  
      cout << "The vector is empty." << endl;  
   else  
      cout << "The vector is not empty." << endl;  
}  
```  
  
```Output  
The vector is not empty.  
```  
  
##  <a name="a-namevectorenda-vectorend"></a><a name="vector__end"></a>  Vector:: end  
 Retorna o iterador que ultrapassa o fim.  
  
```  
iterator end();

const_iterator end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O iterador ultrapassa o fim de vetor. Se o vetor está vazio, `vector::end() == vector::begin()`.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno **final** é atribuído a uma variável do tipo `const_iterator`, o objeto de vetor não pode ser modificado. Se o valor de retorno **final** é atribuído a uma variável do tipo **iterador**, o objeto de vetor pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_end.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
   vector <int>::iterator v1_Iter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   for ( v1_Iter = v1.begin( ) ; v1_Iter != v1.end( ) ; v1_Iter++ )  
      cout << *v1_Iter << endl;  
}  
```  
  
```Output  
1  
2  
```  
  
##  <a name="a-namevectorerasea-vectorerase"></a><a name="vector__erase"></a>  Erase  
 Remove um elemento ou um intervalo de elementos em um vetor de posições especificadas.  
  
```  
iterator erase(
    const_iterator _Where);

iterator erase(
    const_iterator first,  
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|Posição do elemento a ser removido do vetor.|  
|` first`|Posição do primeiro elemento removido do vetor.|  
|` last`|Posição imediatamente após o último elemento removido do vetor.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que designa o primeiro elemento restante além de quaisquer elementos removidos ou um ponteiro para o final do vetor se esse elemento não existir.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_erase.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
   v1.push_back( 40 );  
   v1.push_back( 50 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.erase( v1.begin( ) );  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.erase( v1.begin( ) + 1, v1.begin( ) + 3 );  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
}  
```  
  
```Output  
v1 = 10 20 30 40 50  
v1 = 20 30 40 50  
v1 = 20 50  
```  
  
##  <a name="a-namevectorfronta-vectorfront"></a><a name="vector__front"></a>  Vector  
 Retorna uma referência para o primeiro elemento em um vetor.  
  
```  
reference front();

const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o primeiro elemento no objeto vector. Se o vetor está vazio, o retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `front` for atribuído a `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor de retorno de `front` é atribuído a um **referência**, o objeto de vetor pode ser modificado.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento em um vetor vazio.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_front.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 11 );  
  
   int& i = v1.front( );  
   const int& ii = v1.front( );  
  
   cout << "The first integer of v1 is "<< i << endl;  
   // by incrementing i, we move the the front reference to the second element  
   i++;  
   cout << "Now, the first integer of v1 is "<< i << endl;  
}  
```  
  
##  <a name="a-namevectorgetallocatora-vectorgetallocator"></a><a name="vector__get_allocator"></a>  Vector:: get_allocator  
 Retorna uma cópia do objeto alocador usado para construir o vetor.  
  
```  
Allocator get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O alocador usado pelo vetor.  
  
### <a name="remarks"></a>Comentários  
 Alocadores para a classe vector especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner STL são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_get_allocator.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   // The following lines declare objects that use the default allocator.  
   vector<int> v1;  
   vector<int, allocator<int> > v2 = vector<int, allocator<int> >(allocator<int>( )) ;  
  
   // v3 will use the same allocator class as v1  
   vector <int> v3( v1.get_allocator( ) );  
  
   vector<int>::allocator_type xvec = v3.get_allocator( );  
   // You can now call functions on the allocator class used by vec  
}  
```  
  
##  <a name="a-namevectorinserta-vectorinsert"></a><a name="vector__insert"></a>  Vector:: Insert  
 Insere um elemento ou um número de elementos ou um intervalo de elementos no vetor em uma posição especificada.  
  
```  
iterator insert(
    const_iterator _Where,  
    const Type& val);

iterator insert(
    const_iterator _Where,  
    Type&& val);

void insert(
    const_iterator _Where,  
    size_type count,  
    const Type& val);

template <class InputIterator>  
void insert(
    const_iterator _Where,  
    InputIterator first,  
    InputIterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|A posição do vetor em que o primeiro elemento é inserido.|  
|` val`|O valor do elemento que está sendo inserido no vetor.|  
|` count`|O número de elementos sendo inseridos no vetor.|  
|` first`|A posição do primeiro elemento no intervalo de elementos a serem copiados.|  
|` last`|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|  
  
### <a name="return-value"></a>Valor de retorno  
 Os dois primeiros `insert` funções retornam um iterador que aponta para a posição em que o novo elemento foi inserido no vetor.  
  
### <a name="remarks"></a>Comentários  
 Qualquer operação de inserção pode ser caro, consulte [classe vector](../standard-library/vector-class.md) para uma discussão sobre `vector` desempenho.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_insert.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.insert( v1.begin( ) + 1, 40 );  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
   v1.insert( v1.begin( ) + 2, 4, 50 );  
  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.insert( v1.begin( )+1, v1.begin( )+2, v1.begin( )+4 );  
   cout << "v1 =";  
   for (Iter = v1.begin( ); Iter != v1.end( ); Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
// initialize a vector of vectors by moving v1  
   vector < vector <int> > vv1;  
  
   vv1.insert( vv1.begin(), move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      {  
      vector < vector <int> >::iterator Iter;  
      cout << "vv1[0] =";  
      for (Iter = vv1[0].begin( ); Iter != vv1[0].end( ); Iter++ )  
         cout << " " << *Iter;  
      cout << endl;  
      }  
}  
```  
  
```Output  
v1 = 10 20 30  
v1 = 10 40 20 30  
v1 = 10 40 50 50 50 50 20 30  
v1 = 10 50 50 40 50 50 50 50 20 30  
vv1[0] = 10 50 50 40 50 50 50 50 20 30  
```  
  
##  <a name="a-namevectoriteratora-vectoriterator"></a><a name="vector__iterator"></a>  Vector:: Iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **iterador** pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [Iniciar](#vector__begin).  
  
##  <a name="a-namevectormaxsizea-vectormaxsize"></a><a name="vector__max_size"></a>  Vector:: max_size  
 Retorna o comprimento máximo do vetor.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento máximo possível do vetor.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_max_size.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::size_type i;  
  
   i = v1.max_size( );     
   cout << "The maximum possible length of the vector is " << i << "." << endl;  
}  
```  
  
##  <a name="a-namevectoroperatorata-vectoroperator"></a><a name="vector__operator_at"></a>  [] Vector:: Operator  
 Retorna uma referência para o elemento de vetor em uma posição especificada.  
  
```  
reference operator[](size_type Pos);

const_reference operator[](size_type Pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Pos`|A posição do elemento de vetor.|  
  
### <a name="return-value"></a>Valor de retorno  
 Se a posição especificada for maior ou igual ao tamanho do contêiner, o resultado será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `operator[]` for atribuído a `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor de retorno de `operator[]` for atribuído a uma referência, o objeto de vetor poderá ser modificado.  
  
 Ao compilar com secure_scl 1 (controlado com [iterator_debug_level](../standard-library/iterator-debug-level.md)), um erro de tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites do vetor.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_op_ref.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
  
   int& i = v1[1];  
   cout << "The second integer of v1 is " << i << endl;  
}  
```  
  
##  <a name="a-namevectoroperatoreqa-vectoroperator"></a><a name="vector__operator_eq"></a>  Vector:: Operator =  
 Substitui os elementos do vetor com uma cópia de outro vetor.  
  
```  
vector& operator=(const vector& right);

vector& operator=(vector&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` right`|O [vetor](../standard-library/vector-class.md) sendo copiados para o `vector`.|  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes em um `vector`, `operator=` copia ou move o conteúdo de ` right` para o `vector`.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_operator_as.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector<int> v1, v2, v3;  
   vector<int>::iterator iter;  
  
   v1.push_back(10);  
   v1.push_back(20);  
   v1.push_back(30);  
   v1.push_back(40);  
   v1.push_back(50);  
  
   cout << "v1 = " ;  
   for (iter = v1.begin(); iter != v1.end(); iter++)  
      cout << *iter << " ";  
   cout << endl;  
  
   v2 = v1;  
   cout << "v2 = ";  
   for (iter = v2.begin(); iter != v2.end(); iter++)  
      cout << *iter << " ";  
   cout << endl;  
  
// move v1 into v2  
   v2.clear();  
   v2 = move(v1);  
   cout << "v2 = ";  
   for (iter = v2.begin(); iter != v2.end(); iter++)  
      cout << *iter << " ";  
   cout << endl;  
}  
```  
  
##  <a name="a-namevectorpointera-vectorpointer"></a><a name="vector__pointer"></a>  Vector:: Pointer  
 Um tipo que fornece um ponteiro para um elemento em um vetor.  
  
```  
typedef typename Allocator::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **ponteiro** pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_pointer.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector<int> v;  
   v.push_back( 11 );  
   v.push_back( 22 );  
  
   vector<int>::pointer ptr = &v[0];  
   cout << *ptr << endl;  
   ptr++;  
   cout << *ptr << endl;  
 *ptr = 44;  
   cout << *ptr << endl;  
}  
```  
  
```Output  
11  
22  
44  
```  
  
##  <a name="a-namevectorpopbacka-vectorpopback"></a><a name="vector__pop_back"></a>  Vector:: pop_back  
 Exclui o elemento no final do vetor.  
  
```  
void pop_back();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter um exemplo de código, consulte [vector:: push_back ()](#vector__push_back).  
  
##  <a name="a-namevectorpushbacka-vectorpushback"></a><a name="vector__push_back"></a>  Vector:: push_back  
 Adiciona um elemento ao final do vetor.  
  
```  
void push_back(const T& Val);

 
void push_back(T&& Val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Val`  
 O valor a ser atribuído ao elemento adicionado ao final do vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// compile with: /EHsc /W4  
#include <vector>  
#include <iostream>  
  
using namespace std;  
  
template <typename T> void print_elem(const T& t) {  
    cout << "(" << t << ") ";  
}  
  
template <typename T> void print_collection(const T& t) {  
    cout << "  " << t.size() << " elements: ";  
  
    for (const auto& p : t) {  
        print_elem(p);  
    }  
    cout << endl;  
}  
  
int main()  
{  
    vector<int> v;  
    for (int i = 0; i < 10; ++i) {  
        v.push_back(10 + i);  
    }  
  
    cout << "vector data: " << endl;  
    print_collection(v);  
  
    // pop_back() until it's empty, printing the last element as we go  
    while (v.begin() != v.end()) {   
        cout << "v.back(): "; print_elem(v.back()); cout << endl;  
        v.pop_back();  
    }  
}  
```  
  
##  <a name="a-namevectorrbegina-vectorrbegin"></a><a name="vector__rbegin"></a>  Vector:: rbegin  
 Retorna um iterador para o primeiro elemento em um vetor invertido.  
  
```  
reverse_iterator rbegin();

const_reverse_iterator rbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso trata o primeiro elemento em um vetor invertido ou abordando o que foi o último elemento no vetor não invertido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `rbegin` for atribuído a `const_reverse_iterator`, o objeto de vetor não poderá ser modificado. Se o valor de retorno de `rbegin` é atribuído a um `reverse_iterator`, o objeto de vetor pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_rbegin.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator v1_Iter;  
   vector <int>::reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   v1_Iter = v1.begin( );  
   cout << "The first element of vector is "  
        << *v1_Iter << "." << endl;  
  
   v1_rIter = v1.rbegin( );  
   cout << "The first element of the reversed vector is "  
        << *v1_rIter << "." << endl;  
}  
```  
  
```Output  
The first element of vector is 1.  
The first element of the reversed vector is 2.  
```  
  
##  <a name="a-namevectorreferencea-vectorreference"></a><a name="vector__reference"></a>  Vector:: Reference  
 Um tipo que fornece uma referência a um elemento armazenado em um vetor.  
  
```  
typedef typename Allocator::reference reference;  
```  
  
### <a name="example"></a>Exemplo  
  Consulte [em](#vector__at) para obter um exemplo de como usar **referência** na classe vector.  
  
##  <a name="a-namevectorrenda-vectorrend"></a><a name="vector__rend"></a>  Vector:: rend  
 Retorna um iterador que trata o local após o último elemento em um vetor invertido.  
  
```  
const_reverse_iterator rend() const;

reverse_iterator rend();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso que trata o local após o último elemento em um vetor invertido (o local que precedeu o primeiro elemento no vetor não invertido).  
  
### <a name="remarks"></a>Comentários  
 `rend` é usado com um vetor invertido tão [final](#vector__end) é usado com um vetor.  
  
 Se o valor de retorno de `rend` é atribuído a um `const_reverse_iterator`, em seguida, o objeto de vetor não pode ser modificado. Se o valor de retorno de `rend` é atribuído a um `reverse_iterator`, em seguida, o objeto de vetor pode ser modificado.  
  
 `rend` pode ser usado para testar a se um iterador inverso alcançou o final do seu vetor.  
  
 O valor retornado por `rend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_rend.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )  
      cout << *v1_rIter << endl;  
}  
```  
  
```Output  
2  
1  
```  
  
##  <a name="a-namevectorreservea-vectorreserve"></a><a name="vector__reserve"></a>  Vector:: Reserve  
 Reserva um comprimento mínimo de armazenamento para um objeto de vetor, Alocando espaço se necessário.  
  
```  
void reserve(size_type count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` count`  
 O comprimento mínimo de armazenamento a ser alocada para o vetor.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_reserve.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   //vector <int>::iterator Iter;  
  
   v1.push_back( 1 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
   v1.reserve( 20 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
}  
```  
  
```Output  
Current capacity of v1 = 1  
Current capacity of v1 = 20  
```  
  
##  <a name="a-namevectorresizea-vectorresize"></a><a name="vector__resize"></a>  Vector:: Resize  
 Especifica um novo tamanho para um vetor.  
  
```  
void resize(size_type Newsize);

void resize(size_type Newsize, Type Val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Newsize`  
 O novo tamanho do vetor.  
  
 `Val`  
 O valor de inicialização de novos elementos adicionados ao vetor, caso o novo tamanho seja maior que o tamanho original. Se o valor for omitido, os novos objetos usarão o construtor padrão.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho do contêiner for menor que o tamanho solicitado, `Newsize`, são adicionados os elementos ao vetor até ele atingir o tamanho solicitado. Se o tamanho do contêiner for maior que o tamanho solicitado, os elementos mais próximos do final do contêiner são excluídos até o contêiner chegar ao tamanho `Newsize`. Se o tamanho atual do contêiner for igual ao tamanho solicitado, nenhuma ação será realizada.  
  
 [tamanho](#vector__size) reflete o tamanho atual do vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vectorsizing.cpp  
// compile with: /EHsc /W4  
// Illustrates vector::reserve, vector::max_size,  
// vector::resize, vector::resize, and vector::capacity.  
//  
// Functions:  
//  
//    vector::max_size - Returns maximum number of elements vector could  
//                       hold.  
//  
//    vector::capacity - Returns number of elements for which memory has  
//                       been allocated.  
//  
//    vector::size - Returns number of elements in the vector.  
//  
//    vector::resize - Reallocates memory for vector, preserves its  
//                     contents if new size is larger than existing size.  
//  
//    vector::reserve - Allocates elements for vector to ensure a minimum  
//                      size, preserving its contents if the new size is  
//                      larger than existing size.  
//  
//    vector::push_back - Appends (inserts) an element to the end of a  
//                        vector, allocating memory for it if necessary.  
//  
//////////////////////////////////////////////////////////////////////  
  
// The debugger cannot handle symbols more than 255 characters long.  
// STL often creates symbols longer than that.  
// The warning can be disabled:  
//#pragma warning(disable:4786)  
  
#include <iostream>  
#include <vector>  
#include <string>  
  
using namespace std;  
  
template <typename C> void print(const string& s, const C& c) {  
    cout << s;  
  
    for (const auto& e : c) {  
        cout << e << " ";  
    }  
    cout << endl;  
}  
  
void printvstats(const vector<int>& v) {  
    cout << "   the vector's size is: " << v.size() << endl;  
    cout << "   the vector's capacity is: " << v.capacity() << endl;  
    cout << "   the vector's maximum size is: " << v.max_size() << endl;  
}  
  
int main()  
{  
    // declare a vector that begins with 0 elements.  
    vector<int> v;  
  
    // Show statistics about vector.  
    cout << endl << "After declaring an empty vector:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    // Add one element to the end of the vector.  
    v.push_back(-1);  
    cout << endl << "After adding an element:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    for (int i = 1; i < 10; ++i) {  
        v.push_back(i);  
    }  
    cout << endl << "After adding 10 elements:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    v.resize(6);  
    cout << endl << "After resizing to 6 elements without an initialization value:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    v.resize(9, 999);  
    cout << endl << "After resizing to 9 elements with an initialization value of 999:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    v.resize(12);  
    cout << endl << "After resizing to 12 elements without an initialization value:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    // Ensure there's room for at least 1000 elements.  
    v.reserve(1000);  
    cout << endl << "After vector::reserve(1000):" << endl;  
    printvstats(v);  
  
    // Ensure there's room for at least 2000 elements.  
    v.resize(2000);  
    cout << endl << "After vector::resize(2000):" << endl;  
    printvstats(v);  
}  
```  
  
##  <a name="a-namevectorreverseiteratora-vectorreverseiterator"></a><a name="vector__reverse_iterator"></a>  Vector:: reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor invertido.  
  
```  
typedef std::reverse_iterator<iterator> reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `reverse_iterator` é usado para iterar por meio de vetor em ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [rbegin](#vector__rbegin).  
  
##  <a name="a-namevectorshrinktofita-vectorshrinktofit"></a><a name="vector__shrink_to_fit"></a>  Vector:: shrink_to_fit  
 Descartes de excesso de capacidade.  
  
```  
void shrink_to_fit();
```  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_shrink_to_fit.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   //vector <int>::iterator Iter;  
  
   v1.push_back( 1 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
   v1.reserve( 20 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
   v1.shrink_to_fit();  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
}  
```  
  
```Output  
Current capacity of v1 = 1  
Current capacity of v1 = 20  
Current capacity of v1 = 1  
```  
  
##  <a name="a-namevectorsizea-vectorsize"></a><a name="vector__size"></a>  Vector  
 Retorna o número de elementos no vetor.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do vetor.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_size.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::size_type i;  
  
   v1.push_back( 1 );  
   i = v1.size( );  
   cout << "Vector length is " << i << "." << endl;  
  
   v1.push_back( 2 );  
   i = v1.size( );  
   cout << "Vector length is now " << i << "." << endl;  
}  
```  
  
```Output  
Vector length is 1.  
Vector length is now 2.  
```  
  
##  <a name="a-namevectorsizetypea-vectorsizetype"></a><a name="vector__size_type"></a>  Vector:: size_type  
 Um tipo que conta o número de elementos em um objeto vector.  
  
```  
typedef typename Allocator::size_type size_type;  
```  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [capacidade](#vector__capacity).  
  
##  <a name="a-namevectorswapa-vectorswap"></a><a name="vector__swap"></a>  Vector:: swap  
 Troca os elementos de dois vetores.  
  
```  
void swap(
    vector<Type, Allocator>& right);

friend void swap(
    vector<Type, Allocator>& left,  
    vector<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Um vetor de fornecer os elementos a ser trocado ou um vetor cujos elementos devem ser trocadas com aqueles do vetor de ` left`.  
  
 ` left`  
 Um vetor cujos elementos devem ser trocadas com aqueles do vetor de ` right`.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_swap.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1, v2;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
   v1.push_back( 3 );  
  
   v2.push_back( 10 );  
   v2.push_back( 20 );  
  
   cout << "The number of elements in v1 = " << v1.size( ) << endl;  
   cout << "The number of elements in v2 = " << v2.size( ) << endl;  
   cout << endl;  
  
   v1.swap( v2 );  
  
   cout << "The number of elements in v1 = " << v1.size( ) << endl;  
   cout << "The number of elements in v2 = " << v2.size( ) << endl;  
}  
```  
  
```Output  
The number of elements in v1 = 3  
The number of elements in v2 = 2  
  
The number of elements in v1 = 2  
The number of elements in v2 = 3  
```  
  
##  <a name="a-namevectorvaluetypea-vectorvaluetype"></a><a name="vector__value_type"></a>  Vector:: value_type  
 Um tipo que representa o tipo de dados armazenado em um vetor.  
  
```  
typedef typename Allocator::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `value_type` é um sinônimo para o parâmetro de modelo **tipo**.  
  
### <a name="example"></a>Exemplo  
  
```  
// vector_value_type.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector<int>::value_type AnInt;  
   AnInt = 44;  
   cout << AnInt << endl;  
}  
```  
  
```Output  
44  
```  
  
##  <a name="a-namevectorvectora-vectorvector"></a><a name="vector__vector"></a>  Vector:: Vector  
 Constrói um vetor de um tamanho específico ou com elementos de um valor específico ou com um alocador específico ou como uma cópia de todos ou parte de algum outro vetor.  
  
```  
vector();

explicit vector(
    const Allocator& Al);

explicit vector(
    size_type Count);

vector(
    size_type Count,  
    const Type& Val);

vector(
    size_type Count,  
    const Type& Val,  
    const Allocator& Al);

vector(
    const vector& Right);

vector(
    vector&& Right);

vector(
    initializer_list<Type> IList,  
    const _Allocator& Al);

template <class InputIterator>  
vector(
 InputIterator First,  
    InputIterator Last);

template <class InputIterator>  
vector(
 InputIterator First,  
    InputIterator Last,  
    const Allocator& Al);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Al`|A classe de alocador a ser usada com esse objeto. [get_allocator](#vector__get_allocator) retorna a classe do alocador do objeto.|  
|`Count`|O número de elementos no vetor construído.|  
|`Val`|O valor dos elementos no vetor construído.|  
|`Right`|O vetor de que o vetor construído é uma cópia.|  
|`First`|Posição do primeiro elemento no intervalo de elementos a serem copiados.|  
|`Last`|Posição do primeiro elemento além do intervalo de elementos a serem copiados.|  
|`IList`|O initializer_list que contém o elmeents para copiar.|  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto alocador ( `Al`) e inicializar o vetor.  
  
 Os primeiros dois construtores especificam um vetor inicial vazio. O segundo especifica explicitamente o tipo de alocador ( `Al`) a ser usado.  
  
 O terceiro construtor Especifica uma repetição de um número especificado ( `Count`) de elementos do valor padrão para a classe `Type`.  
  
 Os construtores quarto e quinto especificam a repetição de ( `Count`) elementos de valor `Val`.  
  
 O sexto construtor Especifica uma cópia do vetor de `Right`.  
  
 O sétimo construtor move o vetor de `Right`.  
  
 O oitavo construtor usa initializer_list para especificar os elementos.  
  
 Os construtores nono e décimo copiam o intervalo [ `First`, `Last`) de um vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_ctor.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector <int>::iterator v1_Iter, v2_Iter, v3_Iter, v4_Iter, v5_Iter, v6_Iter;  
  
    // Create an empty vector v0  
    vector <int> v0;  
  
    // Create a vector v1 with 3 elements of default value 0  
    vector <int> v1(3);  
  
    // Create a vector v2 with 5 elements of value 2  
    vector <int> v2(5, 2);  
  
    // Create a vector v3 with 3 elements of value 1 and with the allocator   
    // of vector v2  
    vector <int> v3(3, 1, v2.get_allocator());  
  
    // Create a copy, vector v4, of vector v2  
    vector <int> v4(v2);  
  
    // Create a new temporary vector for demonstrating copying ranges  
    vector <int> v5(5);  
    for (auto i : v5) {  
        v5[i] = i;  
    }  
  
    // Create a vector v6 by copying the range v5[ first,  last)  
    vector <int> v6(v5.begin() + 1, v5.begin() + 3);  
  
    cout << "v1 =";  
    for (auto& v : v1){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v2 =";  
    for (auto& v : v2){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v3 =";  
    for (auto& v : v3){  
        cout << " " << v;  
    }  
    cout << endl;  
    cout << "v4 =";  
    for (auto& v : v4){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v5 =";  
    for (auto& v : v5){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v6 =";  
    for (auto& v : v6){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    // Move vector v2 to vector v7  
    vector <int> v7(move(v2));  
    vector <int>::iterator v7_Iter;  
  
    cout << "v7 =";  
    for (auto& v : v7){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    vector<int> v8{ { 1, 2, 3, 4 } };  
    for (auto& v : v8){  
        cout << " " << v ;  
    }  
    cout << endl;  
}  
  
```  
  
```Output  
v1 = 0 0 0v2 = 2 2 2 2 2v3 = 1 1 1v4 = 2 2 2 2 2v5 = 0 1 2 3 4v6 = 1 2v7 = 2 2 2 2 21 2 3 4  
```  
  
## <a name="see-also"></a>Consulte também  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

