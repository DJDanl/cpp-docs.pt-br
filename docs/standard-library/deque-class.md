---
title: "Classe deque | Microsoft Docs"
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
  - "std.deque"
  - "deque"
  - "std::deque"
  - "deque/std::deque"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe deque, sobre a classe deque"
  - "Classe deque"
ms.assetid: 64842ee5-057a-4063-8c16-4267a0332584
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe deque
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Organiza os elementos de um determinado tipo em uma organização linear e, como um vetor, permite o acesso rápido aleatório a qualquer elemento e eficiente inserção e exclusão na parte posterior do contêiner. No entanto, ao contrário de um vetor de `deque` classe também dá suporte à inserção eficiente e exclusão na frente do contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```unstlib  
template <class Type,   
    class Allocator =allocator<Type>>  
class deque  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Type`  
 O tipo de dados do elemento a ser armazenado no deque.  
  
 `Allocator`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre o deque alocação e desalocação de memória. Esse argumento é opcional e o valor padrão é **alocador \< tipo>***.*  
  
## <a name="remarks"></a>Comentários  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. [Vetores](../standard-library/vector-class.md) deve ser o contêiner preferencial para gerenciar uma sequência quando o acesso aleatório a qualquer elemento é um fator determinante e inserções ou exclusões de elementos apenas são necessárias no final de uma sequência. O desempenho do contêiner de lista é superior ao eficiente inserções e exclusões (em tempo constante) em qualquer local dentro da sequência é um fator determinante. Essas operações no meio da sequência exigem cópias de elemento e atribuições proporcionais ao número de elementos na sequência (tempo linear).  
  
 Realocação de deque ocorre quando uma função de membro deve inserir ou apagar elementos da sequência:  
  
-   Se um elemento é inserido em uma sequência vazia ou se um elemento é apagado para deixar uma sequência vazia, em seguida, iteradores anteriormente retornado pelo [começar](#deque__begin) e [final](#deque__end) se tornar inválidos.  
  
-   Se um elemento é inserido na primeira posição do deque, então todos os iteradores, mas nenhuma referência, que designa elementos existentes se tornar inválidos.  
  
-   Se um elemento é inserido no final do deque, em seguida, [final](#deque__end) e todos os iteradores, mas nenhuma referência, que designa elementos existentes se tornar inválidos.  
  
-   Se um elemento é apagado na frente de deque, somente o iterador e referências ao elemento apagado se tornar inválidas.  
  
-   Se o último elemento é apagado do final do deque, somente esse iterador para o elemento final e referências ao elemento apagado se tornar inválidas.  
  
 Caso contrário, inserir ou apagar um elemento invalida todas as referências e iteradores.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[deque](#deque__deque)|Constrói um `deque.` vários construtores são fornecidos para configurar o conteúdo do novo `deque` maneiras diferentes: vazio; carregado com um número especificado de elementos vazios; conteúdo movidos ou copiados de outro `deque`; conteúdo copiado ou movido por meio de um iterador; e um elemento é copiado para o `deque`` count` vezes. Alguns dos construtores habilitá-lo usando um personalizado `allocator` para criar elementos.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#deque__allocator_type)|Um tipo que representa a classe `allocator` para o objeto `deque`.|  
|[const_iterator](#deque__const_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler os elementos de `deque` como `const`|  
|[const_pointer](#deque__const_pointer)|Um tipo que fornece um ponteiro para um elemento em um `deque` como um `const.`|  
|[const_reference](#deque__const_reference)|Um tipo que fornece uma referência a um elemento em um `deque` para leitura e outras operações como um `const.`|  
|[const_reverse_iterator](#deque__const_reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler os elementos de `deque` como `const`. O deque é exibido na ordem inversa. Para obter mais informações, consulte [classe reverse_iterator](../standard-library/reverse-iterator-class.md)|  
|[difference_type](#deque__difference_type)|Um tipo que fornece a diferença entre dois iteradores de acesso aleatório que se referem a elementos no mesmo `deque`.|  
|[iterador](#deque__iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um `deque`.|  
|[ponteiro](#deque__pointer)|Um tipo que fornece um ponteiro para um elemento em um `deque`.|  
|[referência](#deque__reference)|Um tipo que fornece uma referência a um elemento armazenado em um `deque`.|  
|[reverse_iterator](#deque__reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar um elemento em um `deque`. O deque é exibido na ordem inversa.|  
|[size_type](#deque__size_type)|Um tipo que conta o número de elementos em um `deque`.|  
|[value_type](#deque__value_type)|Um tipo que representa o tipo de dados armazenado em um `deque`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[atribuir](#deque__assign)|Apaga os elementos de um `deque` e copia uma nova sequência de elementos para o destino `deque`.|  
|[em](#deque__at)|Retorna uma referência ao elemento em um local especificado no `deque`.|  
|[Voltar](#deque__back)|Retorna uma referência para o último elemento do `deque`.|  
|[começar](#deque__begin)|Retorna um iterador de acesso aleatório que trata o primeiro elemento no `deque`.|  
|[deque:: cbegin](#deque__cbegin)|Retorna um iterador const para o primeiro elemento no `deque`.|  
|[deque:: cend](#deque__cend)|Retorna um acesso aleatório `const` iterador que aponta além do fim do `deque`.|  
|[Limpar](#deque__clear)|Apaga todos os elementos de um `deque`.|  
|[deque:: crbegin](#deque__crbegin)|Retorna um iterador const de acesso aleatório para o primeiro elemento em uma `deque` exibidas na ordem inversa.|  
|[deque:: crend](#deque__crend)|Retorna um iterador const de acesso aleatório para o primeiro elemento em uma `deque` exibidas na ordem inversa.|  
|[deque:: emplace](#deque__emplace)|Insere um elemento construído adequadamente na `deque` em uma posição especificada.|  
|[deque:: emplace_back](#deque__emplace_back)|Adiciona um elemento construído no lugar ao final do `deque`.|  
|[deque:: emplace_front](#deque__emplace_front)|Adiciona um elemento construído no local para o início do `deque`.|  
|[vazio](#deque__empty)|Retorna `true` se o `deque` contém zero elementos e `false` se ele contém um ou mais elementos.|  
|[final](#deque__end)|Retorna um iterador de acesso aleatório que aponta além do fim do `deque`.|  
|[apagar](#deque__erase)|Remove um elemento ou um intervalo de elementos em uma `deque` das posições especificadas.|  
|[frente](#deque__front)|Retorna uma referência para o primeiro elemento em um `deque`.|  
|[get_allocator](#deque__get_allocator)|Retorna uma cópia do objeto `allocator` que é usada para construir o `deque`.|  
|[Inserir](#deque__insert)|Insere um elemento, vários elementos ou um intervalo de elementos para o `deque` em uma posição especificada.|  
|[max_size](#deque__max_size)|Retorna o comprimento máximo possível do `deque`.|  
|[pop_back](#deque__pop_back)|Apaga o elemento no final de `deque`.|  
|[pop_front](#deque__pop_front)|Apaga o elemento no início de `deque`.|  
|[push_back](#deque__push_back)|Adiciona um elemento ao final de `deque`.|  
|[push_front](#deque__push_front)|Adiciona um elemento ao início do `deque`.|  
|[rbegin](#deque__rbegin)|Retorna um iterador de acesso aleatório para o primeiro elemento em um invertido `deque`.|  
|[rend](#deque__rend)|Retorna um iterador de acesso aleatório que aponta além do último elemento em um invertido `deque`.|  
|[redimensionar](#deque__resize)|Especifica um novo tamanho para um `deque`.|  
|[deque:: shrink_to_fit](#deque__shrink_to_fit)|Descartes de excesso de capacidade.|  
|[tamanho](#deque__size)|Retorna o número de elementos no `deque`.|  
|[troca](#deque__swap)|Troca os elementos de dois `deque`s.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador &#91; &#93;](#deque__operator_at)|Retorna uma referência para o `deque` elemento em uma posição especificada.|  
|[deque:: Operator =](#deque__operator_eq)|Substitui os elementos do `deque` com uma cópia de outro `deque`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: \< deque>  
  
##  <a name="a-namedequeallocatortypea-dequeallocatortype"></a><a name="deque__allocator_type"></a>  deque:: allocator_type  
 Um tipo que representa a classe do alocador do objeto deque.  
  
```  
typedef Allocator allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 **allocator_type** é um sinônimo para o parâmetro de modelo **alocador**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [get_allocator](#deque__get_allocator).  
  
##  <a name="a-namedequeassigna-dequeassign"></a><a name="deque__assign"></a>  Assign  
 Apaga os elementos de um deque e copia um novo conjunto de elementos para o deque de destino.  
  
```  
template <class InputIterator>  
void assign(
    InputIterator First,  
    InputIterator Last);

void assign(
    size_type Count,  
    const Type& Val);

void assign(
    initializer_list<Type>  
IList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `First`  
 Posição do primeiro elemento no intervalo de elementos a serem copiados de deque de argumento.  
  
 `Last`  
 Posição do primeiro elemento além do intervalo de elementos a serem copiados de deque de argumento.  
  
 `Count`  
 O número de cópias de um elemento que está sendo inserido o deque.  
  
 `Val`  
 O valor do elemento que está sendo inserido o deque.  
  
 `IList`  
 O initializer_list que está sendo inserido o deque.  
  
### <a name="remarks"></a>Comentários  
 Depois que todos os elementos existentes de deque de destino serão apagados, `assign` ou insere um intervalo especificado de elementos do deque original ou de alguns outro deque deque de destino ou insere cópias de um novo elemento de um valor especificado de deque de destino.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_assign.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
#include <initializer_list>  
  
int main()  
{  
    using namespace std;  
    deque <int> c1, c2;  
    deque <int>::const_iterator cIter;  
  
    c1.push_back(10);  
    c1.push_back(20);  
    c1.push_back(30);  
    c2.push_back(40);  
    c2.push_back(50);  
    c2.push_back(60);  
  
    deque<int> d1{ 1, 2, 3, 4 };  
    initializer_list<int> iList{ 5, 6, 7, 8 };  
    d1.assign(iList);  
  
    cout << "d1 = ";  
    for (int i : d1)  
        cout << i;  
    cout << endl;  
  
    cout << "c1 =";  
    for (int i : c1)  
        cout << i;  
    cout << endl;  
  
    c1.assign(++c2.begin(), c2.end());  
    cout << "c1 =";  
    for (int i : c1)  
        cout << i;  
    cout << endl;  
  
    c1.assign(7, 4);  
    cout << "c1 =";  
    for (int i : c1)  
        cout << i;  
    cout << endl;  
  
}  
  
```  
  
```Output  
d1 = 5678c1 =102030c1 =5060c1 =4444444  
```  
  
##  <a name="a-namedequeata-dequeat"></a><a name="deque__at"></a>  deque:: AT  
 Retorna uma referência ao elemento em um local especificado no deque.  
  
```  
reference at(size_type _Pos);

const_reference at(size_type _Pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Pos`  
 O subscrito (ou número da posição) do elemento para fazer referência ao deque.  
  
### <a name="return-value"></a>Valor de retorno  
 Se `_Pos` for maior que o tamanho do deque, **em** lança uma exceção.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno **em** é atribuído a um `const_reference`, o objeto deque não pode ser modificado. Se o valor de retorno **em** é atribuído a um **referência**, o objeto deque pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_at.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
  
   const int& i = c1.at( 0 );  
   int& j = c1.at( 1 );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="a-namedequebacka-dequeback"></a><a name="deque__back"></a>  deque:: back  
 Retorna uma referência para o último elemento do deque.  
  
```  
reference back();

const_reference back() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O último elemento do deque. Se o deque estiver vazia, o valor de retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno **novamente** é atribuído a um `const_reference`, o objeto deque não pode ser modificado. Se o valor de retorno **novamente** é atribuído a um **referência**, o objeto deque pode ser modificado.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento em um deque vazio.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_back.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 11 );  
  
   int& i = c1.back( );  
   const int& ii = c1.front( );  
  
   cout << "The last integer of c1 is " << i << endl;  
   i--;  
   cout << "The next-to-last integer of c1 is " << ii << endl;  
}  
```  
  
```Output  
The last integer of c1 is 11  
The next-to-last integer of c1 is 10  
```  
  
##  <a name="a-namedequebegina-dequebegin"></a><a name="deque__begin"></a>  deque  
 Retorna um iterador que trata o primeiro elemento no deque.  
  
```  
const_iterator begin() const;

iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório trata o primeiro elemento no deque ou para o local após um deque vazio.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno **começar** é atribuído a um `const_iterator`, o objeto deque não pode ser modificado. Se o valor de retorno **começar** é atribuído a um **iterador**, o objeto deque pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_begin.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
   deque <int>::const_iterator c1_cIter;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
  
   c1_Iter = c1.begin( );  
   cout << "The first element of c1 is " << *c1_Iter << endl;  
  
 *c1_Iter = 20;  
   c1_Iter = c1.begin( );  
   cout << "The first element of c1 is now " << *c1_Iter << endl;  
  
   // The following line would be an error because iterator is const  
   // *c1_cIter = 200;  
}  
```  
  
```Output  
The first element of c1 is 1  
The first element of c1 is now 20  
```  
  
##  <a name="a-namedequecbegina-dequecbegin"></a><a name="deque__cbegin"></a>  deque:: cbegin  
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
  
##  <a name="a-namedequecenda-dequecend"></a><a name="deque__cend"></a>  deque:: cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que aponta para além do fim do intervalo.  
  
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
  
##  <a name="a-namedequecleara-dequeclear"></a><a name="deque__clear"></a>  deque:: Clear  
 Apaga todos os elementos de um deque.  
  
```  
void clear();
```  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_clear.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   cout << "The size of the deque is initially " << c1.size( ) << endl;  
   c1.clear( );  
   cout << "The size of the deque after clearing is " << c1.size( ) << endl;  
}  
```  
  
```Output  
The size of the deque is initially 3  
The size of the deque after clearing is 0  
```  
  
##  <a name="a-namedequeconstiteratora-dequeconstiterator"></a><a name="deque__const_iterator"></a>  deque:: const_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler um **const** elemento o deque.  
  
```  
typedef implementation-defined const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [novamente](#deque__back).  
  
##  <a name="a-namedequeconstpointera-dequeconstpointer"></a><a name="deque__const_pointer"></a>  deque:: const_pointer  
 Fornece um ponteiro para um `const` elemento em um deque.  
  
```unstlib  
typedef typename Allocator::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento. Um [iterador](#deque__iterator) é mais comumente usado para acessar um elemento deque.  
  
##  <a name="a-namedequeconstreferencea-dequeconstreference"></a><a name="deque__const_reference"></a>  deque:: const_reference  
 Um tipo que fornece uma referência a um **const** elemento armazenado em um deque para leitura e execução **const** operações.  
  
```  
typedef typename Allocator::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_reference` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_const_ref.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
  
   const deque <int> c2 = c1;  
   const int &i = c2.front( );  
   const int &j = c2.back( );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
  
   // The following line would cause an error as c2 is const  
   // c2.push_back( 30 );  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="a-namedequeconstreverseiteratora-dequeconstreverseiterator"></a><a name="deque__const_reverse_iterator"></a>  deque:: const_reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer **const** elemento o deque.  
  
```  
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `const_reverse_iterator` não é possível modificar o valor de um elemento e é usado para iterar deque na ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [rbegin](#deque__rbegin) para obter um exemplo de como declarar e usar um iterador.  
  
##  <a name="a-namedequecrbegina-dequecrbegin"></a><a name="deque__crbegin"></a>  deque:: crbegin  
 Retorna um iterador const para o primeiro elemento em um deque invertido.  
  
```  
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma constante invertido que trata o primeiro elemento em um invertido de iterador de acesso aleatório [deque](../standard-library/deque-class.md) ou abordando o que foi o último elemento não invertida `deque`.  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `crbegin`, o objeto `deque` não pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_crbegin.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   deque <int>::iterator v1_Iter;  
   deque <int>::const_reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   v1_Iter = v1.begin( );  
   cout << "The first element of deque is "  
        << *v1_Iter << "." << endl;  
  
   v1_rIter = v1.crbegin( );  
   cout << "The first element of the reversed deque is "  
        << *v1_rIter << "." << endl;  
}  
```  
  
```Output  
The first element of deque is 1.  
The first element of the reversed deque is 2.  
```  
  
##  <a name="a-namedequecrenda-dequecrend"></a><a name="deque__crend"></a>  deque:: crend  
 Retorna um iterador const que trata o local após o último elemento em um deque invertido.  
  
```  
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma constante invertido iterador de acesso aleatório que trata o local após o último elemento em um invertido [deque](../standard-library/deque-class.md) (o local que precedeu o primeiro elemento no deque não invertida).  
  
### <a name="remarks"></a>Comentários  
 `crend` é usado com um invertido `deque` tão [array::cend](../standard-library/array-class-stl.md#array__cend) é usado com um `deque`.  
  
 Com o valor de retorno `crend` (adequadamente diminuído), o `deque` objeto não pode ser modificado.  
  
 `crend` pode ser usado para testar a se um iterador inverso alcançou o final do seu deque.  
  
 O valor retornado por `crend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_crend.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   deque <int>::const_reverse_iterator v1_rIter;  
  
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
  
##  <a name="a-namedequedequea-dequedeque"></a><a name="deque__deque"></a>  deque:: deque  
 Constrói um deque de um tamanho específico, ou com elementos de um valor específico, ou com um alocador específico ou como uma cópia de todos ou parte de alguns outro deque.  
  
```  
deque();

explicit deque(
    const Allocator& Al);

explicit deque(
    size_type Count);

deque(
    size_type Count,  
    const Type& Val);

deque(
    size_type Count,  
    const Type& Val,  
    const Allocator& Al);

deque(
    const deque& Right);

template <class InputIterator>  
deque(
 InputIterator First,  
    InputIterator Last);

template <class InputIterator>  
deque(
 InputIterator First,  
    InputIterator Last,  
    const Allocator& Al);

deque(
    initializer_list<value_type>  
IList,  
    const Allocator& Al);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Al`|A classe de alocador a ser usada com esse objeto.|  
|`Count`|O número de elementos no deque construído.|  
|`Val`|O valor dos elementos no deque construído.|  
|`Right`|O deque dos quais o deque construído é uma cópia.|  
|`First`|Posição do primeiro elemento no intervalo de elementos a serem copiados.|  
|`Last`|Posição do primeiro elemento além do intervalo de elementos a serem copiados.|  
|`IList`|O initializer_list a ser copiado.|  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto alocador ( `Al`) e inicializar o deque.  
  
 Os primeiros dois construtores especificam uma deque inicial vazia; o outro também especifica o tipo de alocador ( `_Al`) a ser usado.  
  
 O terceiro construtor Especifica uma repetição de um número especificado ( ` count`) de elementos do valor padrão para a classe `Type`.  
  
 Os construtores quarto e quinto especificam a repetição de ( `Count`) elementos de valor ` val`.  
  
 O sexto construtor Especifica uma cópia do deque `Right`.  
  
 Os sétimo e oitavo construtores copiam o intervalo `[First, Last)` de um deque.  
  
 O sétimo construtor move o deque `Right`.  
  
 O oitavo construtor copia o conteúdo de um initializer_list.  
  
 Nenhum dos construtores executa realocações provisórias.  
  
### <a name="example"></a>Exemplo  
  
```  
/ compile with: /EHsc  
#include <deque>  
#include <iostream>  
#include <forward_list>  
  
int main()  
{  
    using namespace std;  
  
    forward_list<int> f1{ 1, 2, 3, 4 };  
  
    f1.insert_after(f1.begin(), { 5, 6, 7, 8 });  
  
    deque <int>::iterator c1_Iter, c2_Iter, c3_Iter, c4_Iter, c5_Iter, c6_Iter;  
  
    // Create an empty deque c0  
    deque <int> c0;  
  
    // Create a deque c1 with 3 elements of default value 0  
    deque <int> c1(3);  
  
    // Create a deque c2 with 5 elements of value 2  
    deque <int> c2(5, 2);  
  
    // Create a deque c3 with 3 elements of value 1 and with the   
    // allocator of deque c2  
    deque <int> c3(3, 1, c2.get_allocator());  
  
    // Create a copy, deque c4, of deque c2  
    deque <int> c4(c2);  
  
    // Create a deque c5 by copying the range c4[ first,  last)  
    c4_Iter = c4.begin();  
    c4_Iter++;  
    c4_Iter++;  
    deque <int> c5(c4.begin(), c4_Iter);  
  
    // Create a deque c6 by copying the range c4[ first,  last) and   
    // c2 with the allocator of deque  
    c4_Iter = c4.begin();  
    c4_Iter++;  
    c4_Iter++;  
    c4_Iter++;  
    deque <int> c6(c4.begin(), c4_Iter, c2.get_allocator());  
  
    // Create a deque c8 by copying the contents of an initializer_list  
    // using brace initialization  
    deque<int> c8({ 1, 2, 3, 4 });  
  
    initializer_list<int> iList{ 5, 6, 7, 8 };  
    deque<int> c9( iList);  
  
    cout << "c1 = ";  
    for (int i : c1)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c2 = ";  
    for (int i : c2)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c3 = ";  
    for (int i : c3)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c4 = ";  
    for (int i : c4)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c5 = ";  
    for (int i : c5)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c6 = ";  
    for (int i : c6)  
        cout << i << " ";  
    cout << endl;  
  
    // Move deque c6 to deque c7  
    deque <int> c7(move(c6));  
    deque <int>::iterator c7_Iter;  
  
    cout << "c7 =";  
    for (int i : c7)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c8 = ";  
    for (int i : c8)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c9 = ";  
    for (int i : c9)  
        cout << i << " ";  
    cout << endl;  
  
    int x = 3;  
}  
// deque_deque.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
    using namespace std;  
   deque <int>::iterator c1_Iter, c2_Iter, c3_Iter, c4_Iter, c5_Iter, c6_Iter;  
  
    // Create an empty deque c0  
    deque <int> c0;  
  
    // Create a deque c1 with 3 elements of default value 0  
    deque <int> c1( 3 );  
  
    // Create a deque c2 with 5 elements of value 2  
    deque <int> c2( 5, 2 );  
  
    // Create a deque c3 with 3 elements of value 1 and with the   
    // allocator of deque c2  
    deque <int> c3( 3, 1, c2.get_allocator( ) );  
  
    // Create a copy, deque c4, of deque c2  
    deque <int> c4( c2 );  
  
    // Create a deque c5 by copying the range c4[ first,  last)  
    c4_Iter = c4.begin( );  
    c4_Iter++;  
    c4_Iter++;  
    deque <int> c5( c4.begin( ), c4_Iter );  
  
    // Create a deque c6 by copying the range c4[ first,  last) and   
    // c2 with the allocator of deque  
    c4_Iter = c4.begin( );  
   c4_Iter++;  
   c4_Iter++;  
   c4_Iter++;  
   deque <int> c6( c4.begin( ), c4_Iter, c2.get_allocator( ) );  
  
    // Create a deque c8 by copying the contents of an initializer_list  
    // using brace initialization  
    deque<int> c8({ 1, 2, 3, 4 });  
  
        initializer_list<int> iList{ 5, 6, 7, 8 };  
    deque<int> c9( iList);  
  
    cout << "c1 = ";  
    for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
        cout << *c1_Iter << " ";  
    cout << endl;  
  
    cout << "c2 = ";  
    for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )  
        cout << *c2_Iter << " ";  
    cout << endl;  
  
    cout << "c3 = ";  
    for ( c3_Iter = c3.begin( ); c3_Iter != c3.end( ); c3_Iter++ )  
        cout << *c3_Iter << " ";  
    cout << endl;  
  
    cout << "c4 = ";  
    for ( c4_Iter = c4.begin( ); c4_Iter != c4.end( ); c4_Iter++ )  
        cout << *c4_Iter << " ";  
    cout << endl;  
  
    cout << "c5 = ";  
    for ( c5_Iter = c5.begin( ); c5_Iter != c5.end( ); c5_Iter++ )  
        cout << *c5_Iter << " ";  
    cout << endl;  
  
    cout << "c6 = ";  
    for ( c6_Iter = c6.begin( ); c6_Iter != c6.end( ); c6_Iter++ )  
        cout << *c6_Iter << " ";  
    cout << endl;  
  
    // Move deque c6 to deque c7  
    deque <int> c7( move(c6) );  
    deque <int>::iterator c7_Iter;  
  
    cout << "c7 =" ;  
    for ( c7_Iter = c7.begin( ) ; c7_Iter != c7.end( ) ; c7_Iter++ )  
        cout << " " << *c7_Iter;  
    cout << endl;  
  
    cout << "c8 = ";  
    for (int i : c8)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c9 = ";  
    or (int i : c9)  
        cout << i << " ";  
    cout << endl;  
}  
```  
  
##  <a name="a-namedequedifferencetypea-dequedifferencetype"></a><a name="deque__difference_type"></a>  deque:: difference_type  
 Um tipo que fornece a diferença entre dois iteradores que se referem a elementos dentro do mesmo deque.  
  
```  
typedef typename Allocator::difference_type difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 Um `difference_type` também pode ser descrito como o número de elementos entre dois ponteiros.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_diff_type.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <deque>  
#include <algorithm>  
  
int main( )   
{  
   using namespace std;  
  
   deque <int> c1;  
   deque <int>::iterator c1_Iter, c2_Iter;  
  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
   c1.push_back( 10 );  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
  
   c1_Iter = c1.begin( );  
   c2_Iter = c1.end( );  
  
   deque <int>::difference_type df_typ1, df_typ2, df_typ3;  
  
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
  
##  <a name="a-namedequeemplacea-dequeemplace"></a><a name="deque__emplace"></a>  deque:: emplace  
 Insere um elemento construído adequadamente em deque em uma posição especificada.  
  
```  
iterator emplace(
    const_iterator _Where,  
    Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|A posição do [deque](../standard-library/deque-class.md) onde o primeiro elemento é inserido.|  
|` val`|O valor do elemento que está sendo inserido o `deque`.|  
  
### <a name="return-value"></a>Valor de retorno  
 A função retorna um iterador que aponta para a posição em que o novo elemento foi inserido no deque.  
  
### <a name="remarks"></a>Comentários  
 Qualquer operação de inserção pode ser caro, consulte `deque` para obter uma discussão de `deque` desempenho.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_emplace.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   deque <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
// initialize a deque of deques by moving v1  
   deque < deque <int> > vv1;  
  
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
  
##  <a name="a-namedequeemplacebacka-dequeemplaceback"></a><a name="deque__emplace_back"></a>  deque:: emplace_back  
 Adiciona um elemento construído no lugar ao final do deque.  
  
```  
void emplace_back(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` val`|O elemento adicionado ao final de [deque](../standard-library/deque-class.md).|  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_emplace_back.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
  
   v1.push_back( 1 );  
   if ( v1.size( ) != 0 )  
      cout << "Last element: " << v1.back( ) << endl;  
  
   v1.push_back( 2 );  
   if ( v1.size( ) != 0 )  
      cout << "New last element: " << v1.back( ) << endl;  
  
// initialize a deque of deques by moving v1  
   deque < deque <int> > vv1;  
  
   vv1.emplace_back( move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      cout << "Moved last element: " << vv1[0].back( ) << endl;  
}  
```  
  
```Output  
Last element: 1  
New last element: 2  
Moved last element: 2  
```  
  
##  <a name="a-namedequeemplacefronta-dequeemplacefront"></a><a name="deque__emplace_front"></a>  deque:: emplace_front  
 Adiciona um elemento construído no lugar ao final do deque.  
  
```  
void emplace_front(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` val`|O elemento adicionado ao início do [deque](../standard-library/deque-class.md).|  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_emplace_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
  
   v1.push_back( 1 );  
   if ( v1.size( ) != 0 )  
      cout << "Last element: " << v1.back( ) << endl;  
  
   v1.push_back( 2 );  
   if ( v1.size( ) != 0 )  
      cout << "New last element: " << v1.back( ) << endl;  
  
// initialize a deque of deques by moving v1  
   deque < deque <int> > vv1;  
  
   vv1.emplace_front( move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      cout << "Moved last element: " << vv1[0].back( ) << endl;  
}  
```  
  
```Output  
Last element: 1  
New last element: 2  
Moved last element: 2  
```  
  
##  <a name="a-namedequeemptya-dequeempty"></a><a name="deque__empty"></a>  deque:: Empty  
 Testa se um deque está vazio.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se o deque está vazia; **False** se o deque não está vazio.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_empty.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   if ( c1.empty( ) )  
      cout << "The deque is empty." << endl;  
   else  
      cout << "The deque is not empty." << endl;  
}  
```  
  
```Output  
The deque is not empty.  
```  
  
##  <a name="a-namedequeenda-dequeend"></a><a name="deque__end"></a>  deque:: end  
 Retorna um iterador que trata o local após o último elemento em um deque.  
  
```  
const_iterator end() const;

iterator end();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que trata o local após o último elemento em um deque. Se o deque está vazio e deque:: end = = deque.  
  
### <a name="remarks"></a>Comentários  
 **final** é usado para testar se um iterador atingiu o final de seu deque.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_end.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1_Iter = c1.end( );  
   c1_Iter--;  
   cout << "The last integer of c1 is " << *c1_Iter << endl;  
  
   c1_Iter--;  
 *c1_Iter = 400;  
   cout << "The new next-to-last integer of c1 is " << *c1_Iter << endl;  
  
   // If a const iterator had been declared instead with the line:  
   // deque <int>::const_iterator c1_Iter;  
   // an error would have resulted when inserting the 400  
  
   cout << "The deque is now:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
}  
```  
  
```Output  
The last integer of c1 is 30  
The new next-to-last integer of c1 is 400  
The deque is now: 10 400 30  
```  
  
##  <a name="a-namedequeerasea-dequeerase"></a><a name="deque__erase"></a>  deque  
 Remove um elemento ou um intervalo de elementos em um deque das posições especificadas.  
  
```  
iterator erase(iterator _Where);

iterator erase(iterator first, iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Where`  
 Posição do elemento a ser removido do deque.  
  
 ` first`  
 Posição do primeiro elemento removido o deque.  
  
 ` last`  
 Posição imediatamente após o último elemento removido o deque.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que designa o primeiro elemento restante além de quaisquer elementos removidos ou um ponteiro para o final do deque se esse elemento não existir.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre **apagar**, consulte [deque e deque:: Clear](../misc/deque-erase-and-deque-clear.md).  
  
 **apagar** nunca gera uma exceção.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_erase.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator Iter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
   c1.push_back( 40 );  
   c1.push_back( 50 );  
   cout << "The initial deque is: ";  
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )  
      cout << *Iter << " ";  
   cout << endl;  
   c1.erase( c1.begin( ) );  
   cout << "After erasing the first element, the deque becomes:  ";  
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )  
      cout << *Iter << " ";  
   cout << endl;  
   Iter = c1.begin( );  
   Iter++;  
   c1.erase( Iter, c1.end( ) );  
   cout << "After erasing all elements but the first, deque becomes: ";  
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )  
      cout << *Iter << " ";  
   cout << endl;  
}  
```  
  
```Output  
The initial deque is: 10 20 30 40 50   
After erasing the first element, the deque becomes:  20 30 40 50   
After erasing all elements but the first, deque becomes: 20   
```  
  
##  <a name="a-namedequefronta-dequefront"></a><a name="deque__front"></a>  deque  
 Retorna uma referência para o primeiro elemento em um deque.  
  
```  
reference front();

const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o deque estiver vazia, o retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `front` é atribuído a um `const_reference`, o objeto deque não pode ser modificado. Se o valor de retorno de `front` é atribuído a um **referência**, o objeto deque pode ser modificado.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento em um deque vazio.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 11 );  
  
   int& i = c1.front( );  
   const int& ii = c1.front( );  
  
   cout << "The first integer of c1 is " << i << endl;  
   i++;  
   cout << "The second integer of c1 is " << ii << endl;  
}  
```  
  
```Output  
The first integer of c1 is 10  
The second integer of c1 is 11  
```  
  
##  <a name="a-namedequegetallocatora-dequegetallocator"></a><a name="deque__get_allocator"></a>  deque:: get_allocator  
 Retorna uma cópia do objeto alocador usado para construir o deque.  
  
```  
Allocator get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O alocador usado pelo deque.  
  
### <a name="remarks"></a>Comentários  
 Alocadores para a classe deque especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner STL são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_get_allocator.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   // The following lines declare objects that use the default allocator.  
   deque <int> c1;  
   deque <int, allocator<int> > c2 = deque <int, allocator<int> >( allocator<int>( ) );  
  
   // c3 will use the same allocator class as c1  
   deque <int> c3( c1.get_allocator( ) );  
  
   deque <int>::allocator_type xlst = c1.get_allocator( );  
   // You can now call functions on the allocator class used by c1  
}  
```  
  
##  <a name="a-namedequeinserta-dequeinsert"></a><a name="deque__insert"></a>  deque:: Insert  
 Insere um elemento ou um número de elementos ou um intervalo de elementos em deque em uma posição especificada.  
  
```  
iterator insert(
    const_iterator Where,  
    const Type& Val);

iterator insert(
    const_iterator Where,  
    Type&& Val);

void insert(
    iterator Where,  
    size_type Count,  
    const Type& Val);

template <class InputIterator>  
void insert(
    iterator Where,  
    InputIterator First,  
    InputIterator Last);

iterator insert(
    iterator Where,initializer_list<Type>  
IList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Where`|Posição de deque de destino em que o primeiro elemento é inserido.|  
|`Val`|O valor do elemento que está sendo inserido o deque.|  
|`Count`|O número de elementos que estão sendo inseridos o deque.|  
|`First`|A posição do primeiro elemento no intervalo de elementos em deque o argumento a ser copiado.|  
|`Last`|A posição do primeiro elemento além do intervalo de elementos em deque o argumento a ser copiado.|  
|`IList`|O initializer_list de elementos para inserir.|  
  
### <a name="return-value"></a>Valor de retorno  
 As duas primeiras insert retornarão um iterador que aponta para a posição em que o novo elemento foi inserido no deque.  
  
### <a name="remarks"></a>Comentários  
 Qualquer operação de inserção pode ser cara.  
  
##  <a name="a-namedequeiteratora-dequeiterator"></a><a name="deque__iterator"></a>  deque:: Iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um deque.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **iterador** pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [Iniciar](#deque__begin).  
  
##  <a name="a-namedequemaxsizea-dequemaxsize"></a><a name="deque__max_size"></a>  deque:: max_size  
 Retorna o comprimento máximo do deque.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento máximo possível do deque.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_max_size.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::size_type i;  
  
   i = c1.max_size( );  
   cout << "The maximum possible length of the deque is " << i << "." << endl;  
}  
```  
  
##  <a name="a-namedequeoperatorata-dequeoperator"></a><a name="deque__operator_at"></a>  [] deque:: Operator  
 Retorna uma referência ao elemento deque em uma posição especificada.  
  
```  
reference operator[](size_type _Pos);

const_reference operator[](size_type _Pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Pos`  
 A posição do elemento deque seja referenciado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao elemento cuja posição é especificada no argumento. Se a posição especificada é maior que o tamanho do deque, o resultado será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `operator[]` é atribuído a um `const_reference`, o objeto deque não pode ser modificado. Se o valor de retorno de `operator[]` é atribuído a um **referência**, o objeto deque pode ser modificado.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites do deque.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_op_ref.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   cout << "The first integer of c1 is " << c1[0] << endl;  
   int& i = c1[1];  
   cout << "The second integer of c1 is " << i << endl;  
  
}  
```  
  
```Output  
The first integer of c1 is 10  
The second integer of c1 is 20  
```  
  
##  <a name="a-namedequeoperatoreqa-dequeoperator"></a><a name="deque__operator_eq"></a>  deque:: Operator =  
 Substitui os elementos desse deque usando os elementos de deque de outro.  
  
```  
deque& operator=(const deque& right);

deque& operator=(deque&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` right`|O deque que fornece o novo conteúdo.|  
  
### <a name="remarks"></a>Comentários  
 A primeira substituição copia elementos para este deque de ` right`, a origem da atribuição. A segunda substituição move elementos para este deque de ` right`.  
  
 Elementos que estão contidos nesse deque antes de executa o operador são removidos.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_operator_as.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
using namespace std;  
  
typedef deque<int> MyDeque;  
  
template<typename MyDeque> struct S;  
  
template<typename MyDeque> struct S<MyDeque&> {  
  static void show( MyDeque& d ) {  
    MyDeque::const_iterator iter;  
    for (iter = d.cbegin(); iter != d.cend(); iter++)  
       cout << *iter << " ";  
    cout << endl;  
  }  
};  
  
template<typename MyDeque> struct S<MyDeque&&> {  
  static void show( MyDeque&& d ) {  
    MyDeque::const_iterator iter;  
    for (iter = d.cbegin(); iter != d.cend(); iter++)  
       cout << *iter << " ";  
cout << " via unnamed rvalue reference " << endl;  
  }  
};  
  
int main( )  
{  
   MyDeque d1, d2;  
  
   d1.push_back(10);  
   d1.push_back(20);  
   d1.push_back(30);  
   d1.push_back(40);  
   d1.push_back(50);  
  
   cout << "d1 = " ;  
   S<MyDeque&>::show( d1 );  
  
   d2 = d1;  
   cout << "d2 = ";  
   S<MyDeque&>::show( d2 );  
  
   cout << "     ";  
   S<MyDeque&&>::show ( move< MyDeque& > (d1) );  
 }  
```  
  
##  <a name="a-namedequepointera-dequepointer"></a><a name="deque__pointer"></a>  deque:: Pointer  
 Fornece um ponteiro para um elemento em um [deque](../standard-library/deque-class.md).  
  
```unstlib  
typedef typename Allocator::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **ponteiro** pode ser usado para modificar o valor de um elemento. Um [iterador](#deque__iterator) é mais comumente usado para acessar um elemento deque.  
  
##  <a name="a-namedequepopbacka-dequepopback"></a><a name="deque__pop_back"></a>  deque:: pop_back  
 Exclui o elemento no final o deque.  
  
```  
void pop_back();
```  
  
### <a name="remarks"></a>Comentários  
 O último elemento não deve ser vazio. `pop_back` Nunca gera uma exceção.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_pop_back.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   cout << "The first element is: " << c1.front( ) << endl;  
   cout << "The last element is: " << c1.back( ) << endl;  
  
   c1.pop_back( );  
   cout << "After deleting the element at the end of the deque, the "  
      "last element is: " << c1.back( ) << endl;  
}  
```  
  
```Output  
The first element is: 1  
The last element is: 2  
After deleting the element at the end of the deque, the last element is: 1  
```  
  
##  <a name="a-namedequepopfronta-dequepopfront"></a><a name="deque__pop_front"></a>  deque:: pop_front  
 Exclui o elemento no começo do deque.  
  
```  
void pop_front();
```  
  
### <a name="remarks"></a>Comentários  
 O primeiro elemento não deve ser vazio. `pop_front` Nunca gera uma exceção.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_pop_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   cout << "The first element is: " << c1.front( ) << endl;  
   cout << "The second element is: " << c1.back( ) << endl;  
  
   c1.pop_front( );  
   cout << "After deleting the element at the beginning of the "  
      "deque, the first element is: " << c1.front( ) << endl;  
}  
```  
  
```Output  
The first element is: 1  
The second element is: 2  
After deleting the element at the beginning of the deque, the first element is: 2  
```  
  
##  <a name="a-namedequepushbacka-dequepushback"></a><a name="deque__push_back"></a>  deque  
 Adiciona um elemento ao final do deque.  
  
```  
void push_back(const Type& val);

void push_back(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` val`|O elemento adicionado ao final do deque.|  
  
### <a name="remarks"></a>Comentários  
 Se uma exceção for lançada, o deque é deixada inalterada e a exceção será emitida novamente.  
  
##  <a name="a-namedequepushfronta-dequepushfront"></a><a name="deque__push_front"></a>  push_front  
 Adiciona um elemento ao início do deque.  
  
```  
    void push_front(const Type& val);

void push_front(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` val`|O elemento adicionado ao início do deque.|  
  
### <a name="remarks"></a>Comentários  
 Se uma exceção for lançada, o deque é deixada inalterada e a exceção será emitida novamente.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_push_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
#include <string>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_front( 1 );  
   if ( c1.size( ) != 0 )  
      cout << "First element: " << c1.front( ) << endl;  
  
   c1.push_front( 2 );  
   if ( c1.size( ) != 0 )  
      cout << "New first element: " << c1.front( ) << endl;  
  
// move initialize a deque of strings  
   deque <string> c2;  
   string str("a");  
  
   c2.push_front( move( str ) );  
   cout << "Moved first element: " << c2.front( ) << endl;  
}  
```  
  
```Output  
First element: 1  
New first element: 2  
Moved first element: a  
```  
  
##  <a name="a-namedequerbegina-dequerbegin"></a><a name="deque__rbegin"></a>  rbegin  
 Retorna um iterador para o primeiro elemento em um deque invertido.  
  
```  
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso trata o primeiro elemento em um deque invertido ou abordando o que foi o último elemento o deque não invertida.  
  
### <a name="remarks"></a>Comentários  
 `rbegin` é usado com um deque invertido tão [começar](#deque__begin) é usado com um deque.  
  
 Se o valor de retorno de `rbegin` é atribuído a um `const_reverse_iterator`, o objeto deque não pode ser modificado. Se o valor de retorno de `rbegin` é atribuído a um `reverse_iterator`, o objeto deque pode ser modificado.  
  
 `rbegin` pode ser usado para iterar um deque com versões anteriores.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_rbegin.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
   deque <int>::reverse_iterator c1_rIter;  
  
   // If the following line had replaced the line above, an error   
   // would have resulted in the line modifying an element   
   // (commented below) because the iterator would have been const  
   // deque <int>::const_reverse_iterator c1_rIter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1_rIter = c1.rbegin( );  
   cout << "Last element in the deque is " << *c1_rIter << "." << endl;  
  
   cout << "The deque contains the elements: ";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << *c1_Iter << " ";  
   cout << "in that order.";  
   cout << endl;  
  
   // rbegin can be used to iterate through a deque in reverse order  
   cout << "The reversed deque is: ";  
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )  
      cout << *c1_rIter << " ";  
   cout << endl;  
  
   c1_rIter = c1.rbegin( );  
 *c1_rIter = 40;  // This would have caused an error if a   
                    // const_reverse iterator had been declared as   
                    // noted above  
   cout << "Last element in deque is now " << *c1_rIter << "." << endl;  
}  
```  
  
```Output  
Last element in the deque is 30.  
The deque contains the elements: 10 20 30 in that order.  
The reversed deque is: 30 20 10   
Last element in deque is now 40.  
```  
  
##  <a name="a-namedequereferencea-dequereference"></a><a name="deque__reference"></a>  deque:: Reference  
 Um tipo que fornece uma referência a um elemento armazenado em um deque.  
  
```  
typedef typename Allocator::reference reference;  
```  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_reference.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
  
   const int &i = c1.front( );  
   int &j = c1.back( );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="a-namedequerenda-dequerend"></a><a name="deque__rend"></a>  deque:: rend  
 Retorna um iterador que trata o local após o último elemento em um deque invertido.  
  
```  
const_reverse_iterator rend() const;

reverse_iterator rend();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso que trata o local após o último elemento em um deque invertida (o local que precedeu o primeiro elemento no deque não invertida).  
  
### <a name="remarks"></a>Comentários  
 `rend` é usado com um deque invertido tão [final](#deque__end) é usado com um deque.  
  
 Se o valor de retorno de `rend` é atribuído a um `const_reverse_iterator`, o objeto deque não pode ser modificado. Se o valor de retorno de `rend` é atribuído a um `reverse_iterator`, o objeto deque pode ser modificado.  
  
 `rend` pode ser usado para testar se um iterador inverso alcançou o final do seu deque.  
  
 O valor retornado por `rend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_rend.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
   deque <int>::reverse_iterator c1_rIter;  
   // If the following line had replaced the line above, an error  
   // would have resulted in the line modifying an element  
   // (commented below) because the iterator would have been const  
   // deque <int>::const_reverse_iterator c1_rIter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1_rIter = c1.rend( );  
   c1_rIter --; // Decrementing a reverse iterator moves it forward   
                // in the deque (to point to the first element here)  
   cout << "The first element in the deque is: " << *c1_rIter << endl;  
  
   cout << "The deque is: ";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << *c1_Iter << " ";  
   cout << endl;  
  
   // rend can be used to test if an iteration is through all of   
   // the elements of a reversed deque  
   cout << "The reversed deque is: ";  
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )  
      cout << *c1_rIter << " ";  
   cout << endl;  
  
   c1_rIter = c1.rend( );  
   c1_rIter--; // Decrementing the reverse iterator moves it backward   
               // in the reversed deque (to the last element here)  
 *c1_rIter = 40; // This modification of the last element would   
                   // have caused an error if a const_reverse   
                   // iterator had been declared (as noted above)  
   cout << "The modified reversed deque is: ";  
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )  
      cout << *c1_rIter << " ";  
   cout << endl;  
}  
```  
  
```Output  
The first element in the deque is: 10  
The deque is: 10 20 30   
The reversed deque is: 30 20 10   
The modified reversed deque is: 30 20 40   
```  
  
##  <a name="a-namedequeresizea-dequeresize"></a><a name="deque__resize"></a>  deque:: Resize  
 Especifica um novo tamanho para um deque.  
  
```  
void resize(size_type _Newsize);

void resize(size_type _Newsize, Type val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Newsize`  
 O novo tamanho do deque.  
  
 ` val`  
 O valor dos novos elementos a serem adicionados ao deque se o novo tamanho for maior que o tamanho original. Se o valor for omitido, os novos elementos recebem o valor padrão para a classe.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho do deque é menor que o tamanho solicitado, `_Newsize`, os elementos são adicionados para o deque até atingir o tamanho solicitado.  
  
 Se o tamanho do deque for maior que o tamanho solicitado, os elementos mais próximos ao final do deque são excluídos até que o deque atinge o tamanho `_Newsize`.  
  
 Se o tamanho atual do deque é o mesmo que o tamanho solicitado, nenhuma ação é executada.  
  
 [tamanho](#deque__size) reflete o tamanho atual do deque.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_resize.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{   
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1.resize( 4,40 );  
   cout << "The size of c1 is: " << c1.size( ) << endl;  
   cout << "The value of the last element is " << c1.back( ) << endl;  
  
   c1.resize( 5 );  
   cout << "The size of c1 is now: " << c1.size( ) << endl;  
   cout << "The value of the last element is now " << c1.back( ) << endl;  
  
   c1.resize( 2 );  
   cout << "The reduced size of c1 is: " << c1.size( ) << endl;  
   cout << "The value of the last element is now " << c1.back( ) << endl;  
}  
```  
  
```Output  
The size of c1 is: 4  
The value of the last element is 40  
The size of c1 is now: 5  
The value of the last element is now 0  
The reduced size of c1 is: 2  
The value of the last element is now 20  
```  
  
##  <a name="a-namedequereverseiteratora-dequereverseiterator"></a><a name="deque__reverse_iterator"></a>  deque:: reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar um elemento em um deque invertido.  
  
```  
typedef std::reverse_iterator<iterator> reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `reverse_iterator` é usado para percorrer o deque.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para rbegin.  
  
##  <a name="a-namedequeshrinktofita-dequeshrinktofit"></a><a name="deque__shrink_to_fit"></a>  deque:: shrink_to_fit  
 Descartes de excesso de capacidade.  
  
```  
void shrink_to_fit();
```  
  
### <a name="remarks"></a>Comentários  
 Não há nenhuma maneira portátil para determinar se `shrink_to_fit` reduz o armazenamento usado por um [deque](../standard-library/deque-class.md).  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_shrink_to_fit.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   //deque <int>::iterator Iter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
   cout << "Current size of v1 = "   
      << v1.size( ) << endl;  
   v1.shrink_to_fit();  
   cout << "Current size of v1 = "   
      << v1.size( ) << endl;  
}  
```  
  
```Output  
Current size of v1 = 1  
Current size of v1 = 1  
```  
  
##  <a name="a-namedequesizea-dequesize"></a><a name="deque__size"></a>  deque  
 Retorna o número de elementos no deque.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento atual do deque.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_size.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::size_type i;  
  
   c1.push_back( 1 );  
   i = c1.size( );  
   cout << "The deque length is " << i << "." << endl;  
  
   c1.push_back( 2 );  
   i = c1.size( );  
   cout << "The deque length is now " << i << "." << endl;  
}  
```  
  
```Output  
The deque length is 1.  
The deque length is now 2.  
```  
  
##  <a name="a-namedequesizetypea-dequesizetype"></a><a name="deque__size_type"></a>  deque:: size_type  
 Um tipo que conta o número de elementos em um deque.  
  
```  
typedef typename Allocator::size_type size_type;  
```  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [tamanho](#deque__size).  
  
##  <a name="a-namedequeswapa-dequeswap"></a><a name="deque__swap"></a>  deque:: swap  
 Troca os elementos de dois deques.  
  
```  
void swap(deque<Type, Allocator>& right);

friend void swap(deque<Type, Allocator>& left, deque<Type, Allocator>& right) template <class Type, class Allocator>  
void swap(deque<Type, Allocator>& left, deque<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O deque fornecendo os elementos a ser trocado ou o deque cujos elementos devem ser trocadas com aqueles o deque ` left`.  
  
 ` left`  
 Um deque cujos elementos devem ser trocadas com aqueles o deque ` right`.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_swap.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1, c2, c3;  
   deque <int>::iterator c1_Iter;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   c1.push_back( 3 );  
   c2.push_back( 10 );  
   c2.push_back( 20 );  
   c3.push_back( 100 );  
  
   cout << "The original deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
  
   c1.swap( c2 );  
  
   cout << "After swapping with c2, deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
  
   swap( c1,c3 );  
  
   cout << "After swapping with c3, deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
  
   swap<>(c1, c2);  
   cout << "After swapping with c2, deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
}  
```  
  
```Output  
The original deque c1 is: 1 2 3  
After swapping with c2, deque c1 is: 10 20  
After swapping with c3, deque c1 is: 100  
After swapping with c2, deque c1 is: 1 2 3  
```  
  
##  <a name="a-namedequevaluetypea-dequevaluetype"></a><a name="deque__value_type"></a>  deque:: value_type  
 Um tipo que representa o tipo de dados armazenado em um deque.  
  
```  
typedef typename Allocator::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `value_type` é um sinônimo para o parâmetro de modelo **tipo**.  
  
### <a name="example"></a>Exemplo  
  
```  
// deque_value_type.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
int main( )   
{  
   using namespace std;  
   deque<int>::value_type AnInt;  
   AnInt = 44;  
   cout << AnInt << endl;  
}  
```  
  
```Output  
44  
```  
  
## <a name="see-also"></a>Consulte também  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

