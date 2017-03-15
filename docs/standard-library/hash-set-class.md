---
title: Classe hash_set | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- hash_set/stdext::hash_set
- std::hash_set
- std.hash_set
- stdext::hash_set
- hash_set
- stdext.hash_set
dev_langs:
- C++
helpviewer_keywords:
- hash_set class
ms.assetid: c765c06e-cbb6-48c2-93ca-d15468eb28d7
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: 2d0f3f67539ee7ea2b125f9116006cc2cdcc81c4
ms.lasthandoff: 02/25/2017

---
# <a name="hashset-class"></a>Classe hash_set
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 A classe de contêiner hash_set é uma extensão da Biblioteca Padrão C++ e é usada para o armazenamento e a recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e servem como os valores chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Key,   
    class Traits=hash_compare<Key, less<Key>>,   
    class Allocator=allocator<Key>>  
class hash_set  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Key`  
 O tipo de dados do elemento a ser armazenado no hash_set.  
  
 `Traits`  
 O tipo que inclui dois objetos de função: um da classe compare, que é um predicado binário capaz de comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa e uma função de hash, que é um predicado unário que mapeia valores chave dos elementos para inteiros sem sinal do tipo **size_t**. Esse argumento é opcional e `hash_compare`*<Key,* **less***\<Key> >* é o valor padrão.  
  
 `Allocator`  
 O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e a desalocação de memória do hash_set. Esse argumento é opcional e o valor padrão é **allocator***\<Key>.*  
  
## <a name="remarks"></a>Comentários  
 O hash_set é:  
  
-   Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado. Além disso, é um contêiner associativo simples, pois seus valores de elemento são seus valores de chave.  
  
-   Reversível, pois fornece um iterador bidirecional para acessar seus elementos.  
  
-   Com hash, pois seus elementos são agrupados em buckets com base no valor de uma função de hash aplicada aos valores chave dos elementos.  
  
-   Exclusivo no sentido de que cada um de seus elementos deve ter uma chave exclusiva. Uma vez que hash_set também é um contêiner associativo simples, seus elementos também são exclusivos.  
  
-   Uma classe de modelo, pois a funcionalidade fornecida por ela é genérica e, portanto, independente do tipo de dados específico contido como elementos ou chaves. Os tipos de dados a serem usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.  
  
 A principal vantagem do uso de hash em vez da classificação é a maior eficiência: um hash bem-sucedido executa inserções, exclusões e localizações em tempos médios constantes, em comparação com um tempo proporcional ao logaritmo do número de elementos no contêiner para técnicas de classificação. O valor de um elemento em um conjunto não pode ser alterado diretamente. Em vez disso, você deve excluir valores antigos e inserir elementos com novos valores.  
  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. Contêineres associativos com hash são otimizados para as operações de pesquisa, inserção e remoção. As funções membro que dão suporte explicitamente a essas operações são eficientes quando usadas com uma função de hash bem elaborada, executando-as em um tempo que é, em média, constante e não dependente do número de elementos no contêiner. Uma função de hash bem elaborada produz uma distribuição uniforme de valores em hash e minimiza o número de colisões, em que uma colisão deve ocorrer quando valores de chave distintos são mapeados para o mesmo valor em hash. No pior caso, com a pior função de hash possível, o número de operações será proporcional ao número de elementos na sequência (tempo linear).  
  
 O hash_set deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo. Os elementos de um hash_set são exclusivos e servem como suas próprias chaves de classificação. Um modelo para esse tipo de estrutura é uma lista ordenada de palavras, por exemplo, na qual as palavras podem ocorrer apenas uma vez. Se forem permitidas várias ocorrências das palavras, um hash_multiset seria a estrutura de contêiner apropriada. Se for preciso anexar valores a uma lista de palavras-chave exclusivas, um hash_map será uma estrutura apropriada para conter esses dados. Se, em vez disso, as chaves não forem exclusivas, um hash_multimap será o contêiner ideal.  
  
 O hash_set ordena a sequência que controla chamando um objeto **Traits** de hash armazenado do tipo [value_compare](#hash_set__value_compare). Esse objeto armazenado pode ser acessado chamando a função membro [key_comp](#hash_set__key_comp). Um objeto de função deve se comportar da mesma forma que um objeto da classe *hash_compare<Key, less\<Key> >.* Especificamente, para todos os valores de ` key` do tipo Key, a chamada Trait(` key`) produz uma distribuição de valores do tipo size_t.  
  
 De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão. Um predicado binário *f*( *x*, *y*) é um objeto de função que tem dois objetos de argumento x e y e um valor retornado de true ou false. Uma ordenação imposta em um hash_set será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo e se a equivalência for transitiva, em que dois objetos *x* e *y* são definidos para serem equivalentes quando *f*( *x*, *y*) e *f*( *y*, *x*) forem falsos. Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total (no sentido de que todos os elementos serão ordenados um em relação ao outro) e as chaves correspondentes não poderão ser diferenciadas uma da outra.  
  
 A ordem real dos elementos na sequência controlada depende da função de hash, da função de ordenação e do tamanho atual da tabela de hash armazenada no objeto de contêiner. Não é possível determinar o tamanho atual da tabela de hash, portanto, de modo geral, não é possível prever a ordem dos elementos na sequência controlada. A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.  
  
 O iterador fornecido pela classe hash_set é um iterador bidirecional, mas as funções membro de classe [insert](#hash_set__insert) e [hash_set](#hash_set__hash_set) têm versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que os garantidos pela classe de iteradores bidirecionais. Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade. Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador. Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência. Esse é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores [` first`, ` last`) no contexto de funções membro da classe.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[hash_set](#hash_set__hash_set)|Constrói um `hash_set` que está vazio ou que é uma cópia de todo ou parte de algum outro `hash_set`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#hash_set__allocator_type)|Um tipo que representa a classe `allocator` para o objeto `hash_set`.|  
|[const_iterator](#hash_set__const_iterator)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` no `hash_set`.|  
|[const_pointer](#hash_set__const_pointer)|Um tipo que fornece um ponteiro para um elemento `const` em um `hash_set`.|  
|[const_reference](#hash_set__const_reference)|Um tipo que fornece uma referência para um elemento `const` armazenado em um `hash_set` para leitura e execução de operações `const`.|  
|[const_reverse_iterator](#hash_set__const_reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` no `hash_set`.|  
|[difference_type](#hash_set__difference_type)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um `hash_set` em um intervalo entre os elementos apontado pelos iteradores.|  
|[iterator](#hash_set__iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um `hash_set`.|  
|[key_compare](#hash_set__key_compare)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `hash_set`.|  
|[key_type](#hash_set__key_type)|Um tipo que descreve um objeto armazenado como um elemento de um `hash_set` em sua capacidade como chave de classificação.|  
|[pointer](#hash_set__pointer)|Um tipo que fornece um ponteiro para um elemento em um `hash_set`.|  
|[reference](#hash_set__reference)|Um tipo que fornece uma referência a um elemento armazenado em um `hash_set`.|  
|[reverse_iterator](#hash_set__reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um `hash_set` invertido.|  
|[size_type](#hash_set__size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `hash_set`.|  
|[value_compare](#hash_set__value_compare)|Um tipo que fornece dois objetos de função, um predicado binário da classe compare que pode comparar dois valores de elemento de um `hash_set` para determinar sua ordem relativa, bem como um predicado unário que faz o hash dos elementos.|  
|[value_type](#hash_set__value_type)|Um tipo que descreve um objeto armazenado como um elemento de um `hash_set` em sua capacidade como um valor.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[begin](#hash_set__begin)|Retorna um iterador que trata do primeiro elemento no `hash_set`.|  
|[hash_set::cbegin](#hash_set__cbegin)|Retorna um iterador const que trata o primeiro elemento no `hash_set`.|  
|[hash_set::cend](#hash_set__cend)|Retorna um iterador const que trata o local após o último elemento em um `hash_set`.|  
|[clear](#hash_set__clear)|Apaga todos os elementos de um `hash_set`.|  
|[count](#hash_set__count)|Retorna o número de elementos em um `hash_set` cuja chave corresponde a uma chave especificada pelo parâmetro.|  
|[hash_set::crbegin](#hash_set__crbegin)|Retorna um iterador const que trata o primeiro elemento em um `hash_set` invertido.|  
|[hash_set::crend](#hash_set__crend)|Retorna um iterador const que trata o local após o último elemento em um `hash_set` invertido.|  
|[hash_set::emplace](#hash_set__emplace)|Insere um elemento construído adequadamente em um `hash_set`.|  
|[hash_set::emplace_hint](#hash_set__emplace_hint)|Insere um elemento construído adequadamente em um `hash_set`, com uma dica de posicionamento.|  
|[empty](#hash_set__empty)|Testa se `hash_set` está vazio.|  
|[end](#hash_set__end)|Retorna um iterador que trata o local após o último elemento em um `hash_set`.|  
|[equal_range](#hash_set__equal_range)|Retorna um par de iteradores, respectivamente, para o primeiro elemento em um `hash_set` com uma chave que é maior do que uma chave especificada e para o primeiro elemento no `hash_set` com uma chave igual ou maior que a chave.|  
|[erase](#hash_set__erase)|Remove um elemento ou um intervalo de elementos em um `hash_set` das posições especificadas ou remove elementos que correspondem a uma chave especificada.|  
|[find](#hash_set__find)|Retorna um iterador que trata do local de um elemento em um `hash_set` que tem uma chave equivalente a uma chave especificada.|  
|[get_allocator](#hash_set__get_allocator)|Retorna uma cópia do objeto `allocator` usada para construir o `hash_set`.|  
|[insert](#hash_set__insert)|Insere um elemento ou um intervalo de elementos em um `hash_set`.|  
|[key_comp](#hash_set__key_comp)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um `hash_set`.|  
|[lower_bound](#hash_set__lower_bound)|Retorna um iterador para o primeiro elemento em um `hash_set` com uma chave que é igual ou maior que uma chave especificada.|  
|[max_size](#hash_set__max_size)|Retorna o comprimento máximo do `hash_set`.|  
|[rbegin](#hash_set__rbegin)|Retorna um iterador que trata o primeiro elemento em um `hash_set` invertido.|  
|[rend](#hash_set__rend)|Retorna um iterador que trata o local após o último elemento em um `hash_set` invertido.|  
|[size](#hash_set__size)|Retorna o número de elementos no `hash_set`.|  
|[swap](#hash_set__swap)|Troca os elementos de dois `hash_set`s.|  
|[upper_bound](#hash_set__upper_bound)|Retorna um iterador para o primeiro elemento em um `hash_set` com uma chave que é igual ou maior que uma chave especificada.|  
|[value_comp](#hash_set__value_comp)|Recupera uma cópia do objeto de características de hash usado para fazer o hash e ordenar valores chave de elementos em um `hash_set`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[hash_set::operator=](#hash_set__operator_eq)|Substitui os elementos de um `hash_set` por uma cópia de outro `hash_set`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<hash_set>  
  
 **Namespace:** stdext  
  
##  <a name="a-namehashsetallocatortypea--hashsetallocatortype"></a><a name="hash_set__allocator_type"></a>  hash_set::allocator_type  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que representa a classe allocator do objeto hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::allocator_type allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 **allocator_type** é um sinônimo do parâmetro de modelo `Allocator`.  
  
 Para obter mais informações sobre `Allocator`, consulte a seção Comentários do tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [get_allocator](#hash_set__get_allocator) para obter um exemplo que usa `allocator_type`.  
  
##  <a name="a-namehashsetbegina--hashsetbegin"></a><a name="hash_set__begin"></a>  hash_set::begin  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador que trata o primeiro elemento no hash_set.  
  
```  
const_iterator begin() const;

iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional que trata do primeiro elemento no hash_set ou no local que sucede um hash_set vazio.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado de **begin** for atribuído a um `const_iterator`, os elementos no objeto hash_set não poderão ser modificados. Se o valor retornado de **begin** for atribuído a um **iterador**, os elementos no objeto hash_set poderão ser modificados.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_begin.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::iterator hs1_Iter;  
   hash_set <int>::const_iterator hs1_cIter;  
  
   hs1.insert( 1 );  
   hs1.insert( 2 );  
   hs1.insert( 3 );  
  
   hs1_Iter = hs1.begin( );  
   cout << "The first element of hs1 is " << *hs1_Iter << endl;  
  
   hs1_Iter = hs1.begin( );  
   hs1.erase( hs1_Iter );  
  
   // The following 2 lines would err because the iterator is const  
   // hs1_cIter = hs1.begin( );  
   // hs1.erase( hs1_cIter );  
  
   hs1_cIter = hs1.begin( );  
   cout << "The first element of hs1 is now " << *hs1_cIter << endl;  
}  
```  
  
```Output  
The first element of hs1 is 1  
The first element of hs1 is now 2  
```  
  
##  <a name="a-namehashsetcbegina--hashsetcbegin"></a><a name="hash_set__cbegin"></a>  hash_set::cbegin  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador const que trata o primeiro elemento no hash_set.  
  
```  
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional const que trata do primeiro elemento no [hash_set](../standard-library/hash-set-class.md) ou do local que sucede um `hash_set` vazio.  
  
### <a name="remarks"></a>Comentários  
 Com o valor retornado de `cbegin`, os elementos no objeto `hash_set` não podem ser modificados.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_cbegin.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::const_iterator hs1_cIter;  
  
   hs1.insert( 1 );  
   hs1.insert( 2 );  
   hs1.insert( 3 );  
  
   hs1_cIter = hs1.cbegin( );  
   cout << "The first element of hs1 is " << *hs1_cIter << endl;  
}  
```  
  
```Output  
The first element of hs1 is 1  
```  
  
##  <a name="a-namehashsetcenda--hashsetcend"></a><a name="hash_set__cend"></a>  hash_set::cend  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador const que trata do local após o último elemento em um hash_set.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional const que trata do local após o último elemento em um [hash_set](../standard-library/hash-set-class.md). Se o `hash_set` estiver vazio, então `hash_set::cend == hash_set::begin`.  
  
### <a name="remarks"></a>Comentários  
 `cend` é usado para testar se um iterador atingiu o fim de seu `hash_set`. O valor retornado por `cend` não deve ser desreferenciado.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_cend.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int> :: const_iterator hs1_cIter;  
  
   hs1.insert( 1 );  
   hs1.insert( 2 );  
   hs1.insert( 3 );  
  
   hs1_cIter = hs1.cend( );  
   hs1_cIter--;  
   cout << "The last element of hs1 is " << *hs1_cIter << endl;  
}  
```  
  
```Output  
The last element of hs1 is 3  
```  
  
##  <a name="a-namehashsetcleara--hashsetclear"></a><a name="hash_set__clear"></a>  hash_set::clear  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Apaga todos os elementos de um hash_set.  
  
```  
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_clear.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
  
   hs1.insert( 1 );  
   hs1.insert( 2 );  
  
   cout << "The size of the hash_set is initially " << hs1.size( )  
        << "." << endl;  
  
   hs1.clear( );  
   cout << "The size of the hash_set after clearing is "   
        << hs1.size( ) << "." << endl;  
}  
```  
  
```Output  
The size of the hash_set is initially 2.  
The size of the hash_set after clearing is 0.  
```  
  
##  <a name="a-namehashsetconstiteratora--hashsetconstiterator"></a><a name="hash_set__const_iterator"></a>  hash_set::const_iterator  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_iterator const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [begin](#hash_set__begin) para obter um exemplo que usa `const_iterator`.  
  
##  <a name="a-namehashsetconstpointera--hashsetconstpointer"></a><a name="hash_set__const_pointer"></a>  hash_set::const_pointer  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece um ponteiro para um elemento **const** em um hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.  
  
 Na maioria dos casos, um [const_iterador](#hash_set__const_iterator) deve ser usado para acessar os elementos em um objeto hash_set **const**.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
##  <a name="a-namehashsetconstreferencea--hashsetconstreference"></a><a name="hash_set__const_reference"></a>  hash_set::const_reference  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece uma referência a um elemento **const** armazenado em um hash_set para leitura e execução de operações **const**.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_const_ref.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
  
   // Declare and initialize a const_reference &Ref1   
   // to the 1st element  
   const int &Ref1 = *hs1.begin( );  
  
   cout << "The first element in the hash_set is "  
        << Ref1 << "." << endl;  
  
   // The following line would cause an error because the   
   // const_reference cannot be used to modify the hash_set  
   // Ref1 = Ref1 + 5;  
}  
```  
  
```Output  
The first element in the hash_set is 10.  
```  
  
##  <a name="a-namehashsetconstreverseiteratora--hashsetconstreverseiterator"></a><a name="hash_set__const_reverse_iterator"></a>  hash_set::const_reverse_iterator  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_reverse_iterator const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar no hash_set em ordem inversa.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [rend](#hash_set__rend) para obter um exemplo de como declarar e usar o `const_reverse_iterator`  
  
##  <a name="a-namehashsetcounta--hashsetcount"></a><a name="hash_set__count"></a>  hash_set::count  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna o número de elementos em um hash_set cuja chave corresponde a uma chave especificada pelo parâmetro.  
  
```  
size_type count(const Key& key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` key`  
 O valor dos elementos a serem correspondidos do hash_set.  
  
### <a name="return-value"></a>Valor de retorno  
 1 se o hash_set contiver um elemento cuja chave de classificação corresponde à chave de parâmetro.  
  
 0 se o hash_set não contiver um elemento com uma chave correspondente.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número de elementos no seguinte intervalo:  
  
 [ **lower_bound** (_ *Key* ), **upper_bound** (\_ *Key* ) ).  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  O exemplo a seguir demonstra o uso da função membro hash_set::count.  
  
```  
// hash_set_count.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
    using namespace stdext;  
    hash_set<int> hs1;  
    hash_set<int>::size_type i;  
  
    hs1.insert(1);  
    hs1.insert(1);  
  
    // Keys must be unique in hash_set, so duplicates are ignored.  
    i = hs1.count(1);  
    cout << "The number of elements in hs1 with a sort key of 1 is: "  
         << i << "." << endl;  
  
    i = hs1.count(2);  
    cout << "The number of elements in hs1 with a sort key of 2 is: "  
         << i << "." << endl;  
}  
```  
  
```Output  
The number of elements in hs1 with a sort key of 1 is: 1.  
The number of elements in hs1 with a sort key of 2 is: 0.  
```  
  
##  <a name="a-namehashsetcrbegina--hashsetcrbegin"></a><a name="hash_set__crbegin"></a>  hash_set::crbegin  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador const que trata do primeiro elemento em um hash_set invertido.  
  
```  
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional invertido const que trata do primeiro elemento em um [hash_set](../standard-library/hash-set-class.md) invertido ou que trata do que foi o último elemento do `hash_set` não invertido.  
  
### <a name="remarks"></a>Comentários  
 `crbegin` é usado com um hash_set invertido, assim como [hash_set::begin](#hash_set__begin) é usado com um hash_set.  
  
 Com o valor de retorno `crbegin`, o objeto `hash_set` não pode ser modificado.  
  
 `crbegin` pode ser usado para iterar em um `hash_set` no sentido inverso.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_crbegin.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::const_reverse_iterator hs1_crIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   hs1_crIter = hs1.crbegin( );  
   cout << "The first element in the reversed hash_set is "  
        << *hs1_crIter << "." << endl;  
}  
```  
  
```Output  
The first element in the reversed hash_set is 30.  
```  
  
##  <a name="a-namehashsetcrenda--hashsetcrend"></a><a name="hash_set__crend"></a>  hash_set::crend  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador const que trata do local após o último elemento em um hash_set invertido.  
  
```  
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional inverso const que trata da localização que vem após o último elemento em um [hash_set](../standard-library/hash-set-class.md) invertido (o local que precedeu o primeiro elemento no `hash_set` não invertido).  
  
### <a name="remarks"></a>Comentários  
 `crend` é usado com um `hash_set` invertido, assim como [hash_set::end](#hash_set__end) é usado com um `hash_set`.  
  
 Com o valor de retorno `crend`, o objeto `hash_set` não pode ser modificado.  
  
 `crend` pode ser usado para testar se um iterador inverso alcançou o final de sua `hash_set`.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_crend.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::const_reverse_iterator hs1_crIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   hs1_crIter = hs1.crend( );  
   hs1_crIter--;  
   cout << "The last element in the reversed hash_set is "  
        << *hs1_crIter << "." << endl;  
}  
```  
  
```Output  
The last element in the reversed hash_set is 10.  
```  
  
##  <a name="a-namehashsetdifferencetypea--hashsetdifferencetype"></a><a name="hash_set__difference_type"></a>  hash_set::difference_type  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um hash_set em um intervalo entre os elementos apontado pelos iteradores.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::difference_type difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 
          `difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. `difference_type` geralmente é usado para representar o número de elementos no intervalo [` first`, ` last`) entre os iteradores ` first` e ` last`, inclui o elemento apontado por ` first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por ` last`.  
  
 Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, que inclui a classe de iteradores bidirecionais com suporte por contêineres reversíveis como conjunto, subtração entre iteradores só tem suporte por iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório, como vetor ou deque.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_diff_type.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <hash_set>  
#include <algorithm>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
  
   hash_set <int> hs1;  
   hash_set <int>::iterator hs1_Iter, hs1_bIter, hs1_eIter;  
  
   hs1.insert( 20 );  
   hs1.insert( 10 );  
   hs1.insert( 20 );   // Won't insert as hash_set elements are unique  
  
   hs1_bIter = hs1.begin( );  
   hs1_eIter = hs1.end( );  
  
   hash_set <int>::difference_type   df_typ5, df_typ10, df_typ20;  
  
   df_typ5 = count( hs1_bIter, hs1_eIter, 5 );  
   df_typ10 = count( hs1_bIter, hs1_eIter, 10 );  
   df_typ20 = count( hs1_bIter, hs1_eIter, 20 );  
  
   // The keys, and hence the elements, of a hash_set are unique,  
   // so there is at most one of a given value  
   cout << "The number '5' occurs " << df_typ5  
        << " times in hash_set hs1.\n";  
   cout << "The number '10' occurs " << df_typ10  
        << " times in hash_set hs1.\n";  
   cout << "The number '20' occurs " << df_typ20  
        << " times in hash_set hs1.\n";  
  
   // Count the number of elements in a hash_set  
   hash_set <int>::difference_type  df_count = 0;  
   hs1_Iter = hs1.begin( );  
   while ( hs1_Iter != hs1_eIter)  
   {  
      df_count++;  
      hs1_Iter++;  
   }  
  
   cout << "The number of elements in the hash_set hs1 is: "   
        << df_count << "." << endl;  
}  
```  
  
```Output  
The number '5' occurs 0 times in hash_set hs1.  
The number '10' occurs 1 times in hash_set hs1.  
The number '20' occurs 1 times in hash_set hs1.  
The number of elements in the hash_set hs1 is: 2.  
```  
  
##  <a name="a-namehashsetemplacea--hashsetemplace"></a><a name="hash_set__emplace"></a>  hash_set::emplace  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Insere um elemento construído em um hash_set.  
  
```  
template <class ValTy>  
pair <iterator, bool>  
emplace(
    ValTy&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` val`|O valor de um elemento a ser inserido no [hash_set](../standard-library/hash-set-class.md), a menos que o `hash_set` já contenha o elemento ou, de modo geral, um elemento cuja chave seja ordenada de maneira equivalente.|  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro `emplace` retorna um par cujo componente `bool` retorna `true` se uma inserção tiver sido feita e `false` se o `hash_set` já contivesse um elemento cuja chave tinha um valor equivalente na ordenação e cujo componente do iterador retorna o endereço em que um novo elemento foi inserido ou onde o elemento já estava localizado.  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_emplace.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
#include <string>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set<string> hs3;  
   string str1("a");  
  
   hs3.emplace(move(str1));  
   cout << "After the emplace insertion, hs3 contains "  
      << *hs3.begin() << "." << endl;  
}  
```  
  
```Output  
After the emplace insertion, hs3 contains a.  
```  
  
##  <a name="a-namehashsetemplacehinta--hashsetemplacehint"></a><a name="hash_set__emplace_hint"></a>  hash_set::emplace_hint  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Insere um elemento construído em um hash_set.  
  
```  
template <class ValTy>  
iterator emplace(
    const_iterator _Where,  
    ValTy&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` val`|O valor de um elemento a ser inserido no [hash_set](../standard-library/hash-set-class.md), a menos que o `hash_set` já contenha o elemento ou, de modo geral, um elemento cuja chave seja ordenada de maneira equivalente.|  
|`_Where`|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (A inserção poderá ocorrer em um tempo constante amortizado, em vez de no tempo logarítmico, se o ponto de inserção seguir `_Where` imediatamente.)|  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro [hash_multiset::emplace](#hash_set__emplace) retorna um iterador que aponta para a posição em que o novo elemento foi inserido no `hash_set` ou em que o elemento existente com uma ordenação equivalente está localizado.  
  
### <a name="remarks"></a>Comentários  
 A inserção poderá ocorrer em um tempo constante amortizado, em vez de no tempo logarítmico, se o ponto de inserção seguir `_Where` imediatamente.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_emplace_hint.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
#include <string>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set<string> hs3;  
   string str1("a");  
  
   hs3.insert(hs3.begin(), move(str1));  
   cout << "After the emplace insertion, hs3 contains "  
      << *hs3.begin() << "." << endl;  
}  
```  
  
```Output  
After the emplace insertion, hs3 contains a.  
```  
  
##  <a name="a-namehashsetemptya--hashsetempty"></a><a name="hash_set__empty"></a>  hash_set::empty  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Testa se um hash_set está vazio.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o hash_set estiver vazio; **false** se o hash_set não estiver vazio.  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_empty.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1, hs2;  
   hs1.insert ( 1 );  
  
   if ( hs1.empty( ) )  
      cout << "The hash_set hs1 is empty." << endl;  
   else  
      cout << "The hash_set hs1 is not empty." << endl;  
  
   if ( hs2.empty( ) )  
      cout << "The hash_set hs2 is empty." << endl;  
   else  
      cout << "The hash_set hs2 is not empty." << endl;  
}  
```  
  
```Output  
The hash_set hs1 is not empty.  
The hash_set hs2 is empty.  
```  
  
##  <a name="a-namehashsetenda--hashsetend"></a><a name="hash_set__end"></a>  hash_set::end  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador que trata do local após o último elemento em um hash_set.  
  
```  
const_iterator end() const;

iterator end();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional que trata do local após o último elemento em um hash_set. Se o hash_set estiver vazio, então hash_set::end == hash_set::begin.  
  
### <a name="remarks"></a>Comentários  
 **end** é usado para testar se um iterador atingiu o fim de seu hash_set::end == hash_set::begin. O valor retornado por **end** não deve ser desreferenciado.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_end.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int> :: iterator hs1_Iter;  
   hash_set <int> :: const_iterator hs1_cIter;  
  
   hs1.insert( 1 );  
   hs1.insert( 2 );  
   hs1.insert( 3 );  
  
   hs1_Iter = hs1.end( );  
   hs1_Iter--;  
   cout << "The last element of hs1 is " << *hs1_Iter << endl;  
  
   hs1.erase( hs1_Iter );  
  
   // The following 3 lines would err because the iterator is const:  
   // hs1_cIter = hs1.end( );  
   // hs1_cIter--;  
   // hs1.erase( hs1_cIter );  
  
   hs1_cIter = hs1.end( );  
   hs1_cIter--;  
   cout << "The last element of hs1 is now " << *hs1_cIter << endl;  
}  
```  
  
```Output  
The last element of hs1 is 3  
The last element of hs1 is now 2  
```  
  
##  <a name="a-namehashsetequalrangea--hashsetequalrange"></a><a name="hash_set__equal_range"></a>  hash_set::equal_range  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um par de iteradores, respectivamente, para o primeiro elemento em um conjunto de hash com uma chave que é igual a uma chave especificada e para o primeiro elemento no conjunto de hash com uma chave maior que a chave.  
  
```  
pair <const_iterator, const_iterator> equal_range (const Key& key) const;

pair <iterator, iterator> equal_range (const Key& key);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` key`  
 A chave do argumento a ser comparada com a chave de classificação de um elemento do hash_set que está sendo pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um par de iteradores em que o primeiro é o [lower_bound](../standard-library/set-class.md#set__lower_bound) e o segundo é o [upper_bound](../standard-library/set-class.md#set__upper_bound) da chave.  
  
 Para acessar o primeiro iterador de um par pr retornado pela função membro, use `pr`. **first** e para desreferenciar o iterador de limite inferior, use \*( `pr`. **first**). Para acessar o segundo iterador de um par `pr` retornado pela função membro, use `pr`. **second** e para desreferenciar o iterador de limite superior, use \*( `pr`. **second**).  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_equal_range.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;   
   using namespace stdext;  
   typedef hash_set<int> IntHSet;  
   IntHSet hs1;  
   hash_set <int> :: const_iterator hs1_RcIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   pair <IntHSet::const_iterator, IntHSet::const_iterator> p1, p2;  
   p1 = hs1.equal_range( 20 );  
  
   cout << "The upper bound of the element with "  
        << "a key of 20 in the hash_set hs1 is: "  
        << *(p1.second) << "." << endl;  
  
   cout << "The lower bound of the element with "  
        << "a key of 20 in the hash_set hs1 is: "  
        << *(p1.first) << "." << endl;  
  
   // Compare the upper_bound called directly   
   hs1_RcIter = hs1.upper_bound( 20 );  
   cout << "A direct call of upper_bound( 20 ) gives "  
        << *hs1_RcIter << "," << endl  
        << "matching the 2nd element of the pair"  
        << " returned by equal_range( 20 )." << endl;  
  
   p2 = hs1.equal_range( 40 );  
  
   // If no match is found for the key,  
   // both elements of the pair return end( )  
   if ( ( p2.first == hs1.end( ) ) && ( p2.second == hs1.end( ) ) )  
      cout << "The hash_set hs1 doesn't have an element "  
           << "with a key greater than or equal to 40." << endl;  
   else  
      cout << "The element of hash_set hs1 with a key >= 40 is: "  
           << *(p1.first) << "." << endl;  
}  
```  
  
```Output  
The upper bound of the element with a key of 20 in the hash_set hs1 is: 30.  
The lower bound of the element with a key of 20 in the hash_set hs1 is: 20.  
A direct call of upper_bound( 20 ) gives 30,  
matching the 2nd element of the pair returned by equal_range( 20 ).  
The hash_set hs1 doesn't have an element with a key greater than or equal to 40.  
```  
  
##  <a name="a-namehashseterasea--hashseterase"></a><a name="hash_set__erase"></a>  hash_set::erase  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Remove um elemento ou um intervalo de elementos em um hash_set das posições especificadas ou remove elementos que correspondem a uma chave especificada.  
  
```  
iterator erase(iterator _Where);

iterator erase(iterator first, iterator last);

size_type erase(const key_type& key);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Where`  
 Posição do elemento a ser removido do hash_set.  
  
 ` first`  
 Posição do primeiro elemento removido do hash_set.  
  
 ` last`  
 Posição logo após o último elemento removido do hash_set.  
  
 ` key`  
 A chave dos elementos a serem removidos do hash_set.  
  
### <a name="return-value"></a>Valor de retorno  
 Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de qualquer elemento removido ou um ponteiro para o final do hash_set, se não houver tal elemento. Para a terceira função membro, o número de elementos que foram removidos do hash_set.  
  
### <a name="remarks"></a>Comentários  
 As funções membro nunca geram uma exceção.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  O exemplo a seguir demonstra o uso da função membro hash_set::erase.  
  
```  
// hash_set_erase.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    using namespace stdext;  
    hash_set<int> hs1, hs2, hs3;  
    hash_set<int>::iterator pIter, Iter1, Iter2;  
    int i;  
    hash_set<int>::size_type n;  
  
    for (i = 1; i < 5; i++)  
    {  
        hs1.insert (i);  
        hs2.insert (i * i);  
        hs3.insert (i - 1);  
    }  
  
    // The 1st member function removes an element at a given position  
    Iter1 = ++hs1.begin();  
    hs1.erase(Iter1);  
  
    cout << "After the 2nd element is deleted, the hash_set hs1 is:";  
    for (pIter = hs1.begin(); pIter != hs1.end(); pIter++)  
        cout << " " << *pIter;  
    cout << "." << endl;  
  
    // The 2nd member function removes elements  
    // in the range [ first,  last)  
    Iter1 = ++hs2.begin();  
    Iter2 = --hs2.end();  
    hs2.erase(Iter1, Iter2);  
  
    cout << "After the middle two elements are deleted, "  
         << "the hash_set hs2 is:";  
    for (pIter = hs2.begin(); pIter != hs2.end(); pIter++)  
        cout << " " << *pIter;  
    cout << "." << endl;  
  
    // The 3rd member function removes elements with a given  key  
    n = hs3.erase(2);  
  
    cout << "After the element with a key of 2 is deleted, "  
         << "the hash_set hs3 is:";  
    for (pIter = hs3.begin(); pIter != hs3.end(); pIter++)  
        cout << " " << *pIter;  
    cout << "." << endl;  
  
    // The 3rd member function returns the number of elements removed  
    cout << "The number of elements removed from hs3 is: "  
         << n << "." << endl;  
  
    // The dereferenced iterator can also be used to specify a key  
    Iter1 = ++hs3.begin();  
    hs3.erase(Iter1);  
  
    cout << "After another element (unique for hash_set) with a key "  
         << endl;  
    cout  << "equal to that of the 2nd element is deleted, "  
          << "the hash_set hs3 is:";  
    for (pIter = hs3.begin(); pIter != hs3.end(); pIter++)  
        cout << " " << *pIter;  
    cout << "." << endl;  
}  
```  
  
```Output  
After the 2nd element is deleted, the hash_set hs1 is: 1 3 4.  
After the middle two elements are deleted, the hash_set hs2 is: 16 4.  
After the element with a key of 2 is deleted, the hash_set hs3 is: 0 1 3.  
The number of elements removed from hs3 is: 1.  
After another element (unique for hash_set) with a key   
equal to that of the 2nd element is deleted, the hash_set hs3 is: 0 3.  
```  
  
##  <a name="a-namehashsetfinda--hashsetfind"></a><a name="hash_set__find"></a>  hash_set::find  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador que trata do local de um elemento em um hash_set que tem uma chave equivalente a uma chave especificada.  
  
```  
iterator find(const Key& key);

const_iterator find(const Key& key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` key`  
 A chave do argumento que deve corresponder à chave de classificação de um elemento do hash_set que está sendo pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **iterador** ou `const_iterator` que trata do local de um elemento equivalente à chave especificada ou que trata do local que sucede o último elemento no hash_set se nenhuma correspondência para a chave for encontrada.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um iterador que trata de um elemento no hash_set, cuja chave de classificação é **equivalente** à chave de argumento em um predicado binário que induz uma ordenação com base em uma relação de comparação do tipo "menor que".  
  
 Se o valor retornado de **find** for atribuído a `const_iterator`, o objeto hash_set não poderá ser modificado. Se o valor retornado de **find** for atribuído a um **iterador**, o objeto do hash_set poderá ser modificado.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_find.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int> :: const_iterator hs1_AcIter, hs1_RcIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   hs1_RcIter = hs1.find( 20 );  
   cout << "The element of hash_set hs1 with a key of 20 is: "  
        << *hs1_RcIter << "." << endl;  
  
   hs1_RcIter = hs1.find( 40 );  
  
   // If no match is found for the key, end( ) is returned  
   if ( hs1_RcIter == hs1.end( ) )  
      cout << "The hash_set hs1 doesn't have an element "  
           << "with a key of 40." << endl;  
   else  
      cout << "The element of hash_set hs1 with a key of 40 is: "  
           << *hs1_RcIter << "." << endl;  
  
   // The element at a specific location in the hash_set can be found   
   // by using a dereferenced iterator addressing the location  
   hs1_AcIter = hs1.end( );  
   hs1_AcIter--;  
   hs1_RcIter = hs1.find( *hs1_AcIter );  
   cout << "The element of hs1 with a key matching "  
        << "that of the last element is: "  
        << *hs1_RcIter << "." << endl;  
}  
```  
  
```Output  
The element of hash_set hs1 with a key of 20 is: 20.  
The hash_set hs1 doesn't have an element with a key of 40.  
The element of hs1 with a key matching that of the last element is: 30.  
```  
  
##  <a name="a-namehashsetgetallocatora--hashsetgetallocator"></a><a name="hash_set__get_allocator"></a>  hash_set::get_allocator  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna uma cópia do objeto alocador usado para construir o hash_set.  
  
```  
Allocator get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O alocador usado pelo hash_set para gerenciar a memória, que é o parâmetro de modelo `Allocator`.  
  
 Para obter mais informações sobre `Allocator`, consulte a seção Comentários do tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
### <a name="remarks"></a>Comentários  
 Alocadores para a classe hash_set especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_get_allocator.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
  
   // The following lines declare objects  
   // that use the default allocator.  
   hash_set <int, hash_compare <int, less<int> > > hs1;  
   hash_set <int,  hash_compare <int, greater<int> > > hs2;  
   hash_set <double, hash_compare <double,  
      less<double> >, allocator<double> > hs3;  
  
   hash_set <int, hash_compare <int,  
      greater<int> > >::allocator_type hs2_Alloc;  
   hash_set <double>::allocator_type hs3_Alloc;  
   hs2_Alloc = hs2.get_allocator( );  
  
   cout << "The number of integers that can be allocated"  
        << endl << "before free memory is exhausted: "  
        << hs1.max_size( ) << "." << endl;  
  
   cout << "The number of doubles that can be allocated"  
        << endl << "before free memory is exhausted: "  
        << hs3.max_size( ) <<  "." << endl;  
  
   // The following lines create a hash_set hs4  
   // with the allocator of hash_set hs1.  
   hash_set <int>::allocator_type hs4_Alloc;  
   hash_set <int> hs4;  
   hs4_Alloc = hs2.get_allocator( );  
  
   // Two allocators are interchangeable if  
   // storage allocated from each can be  
   // deallocated by the other  
   if( hs2_Alloc == hs4_Alloc )  
   {  
      cout << "The allocators are interchangeable."  
           << endl;  
   }  
   else  
   {  
      cout << "The allocators are not interchangeable."  
           << endl;  
   }  
}  
```  
  
##  <a name="a-namehashsethashseta--hashsethashset"></a><a name="hash_set__hash_set"></a>  hash_set::hash_set  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Constrói um `hash_set` que está vazio ou que é uma cópia de todo ou parte de algum outro `hash_set`.  
  
```  
hash_set();

explicit hash_set(
    const Traits& Comp);

hash_set(
    const Traits& Comp,  
    const Allocator& Al);

hash_set(
    const hash_set<Key, Traits, Allocator>& Right);

hash_set(
    hash_set&& Right);

hash_set(
    initializer_list<Type> IList);

hash_set(
    initializer_list<Type> IList,   
    const Compare& Comp);

hash_set(
    initializer_list<value_type> IList,   
    const Compare& Comp,   
    const Allocator& Al);

template <class InputIterator>  
hash_set(
 InputIterator First,  
    InputIterator Last);

template <class InputIterator>  
hash_set(
 InputIterator First,  
    InputIterator Last,  
    const Traits& Comp);

template <class InputIterator>  
hash_set(
 InputIterator First,  
    InputIterator Last,  
    const Traits& Comp,  
    const Allocator& Al);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Al`|A classe do alocador de armazenamento a ser usado para este objeto `hash_set`, cujo padrão é `Allocator`.|  
|`Comp`|A função de comparação do tipo `const Traits` usada para ordenar os elementos no `hash_set`, cujo padrão é `hash_compare`.|  
|`Right`|O `hash_set` do qual o `hash_set` construído é uma cópia.|  
|`First`|A posição do primeiro elemento no intervalo de elementos a serem copiados.|  
|`Last`|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um tipo de objeto de alocador que gerencia o armazenamento de memória para o `hash_set` e que, posteriormente, pode ser retornado ao chamar [hash_set::get_allocator](#hash_set__get_allocator). O parâmetro do alocador muitas vezes é omitido nas declarações de classe e nas macros de pré-processamento usadas para substituir os alocadores alternativos.  
  
 Todos os construtores inicializam seus hash_sets.  
  
 Todos os construtores armazenam um objeto de função do tipo `Traits`, que é usado para estabelecer uma ordem entre as chaves do `hash_set` e que, posteriormente, pode ser retornado ao chamar [hash_set::key_comp](#hash_set__key_comp). Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
 O primeiro construtor cria um `hash_set` inicial vazio, o segundo especifica o tipo de função de comparação (`Comp`) a ser usado para estabelecer a ordem dos elementos e o terceiro especifica explicitamente o tipo de alocador (`Al`) a ser usado. A palavra-chave `explicit` suprime determinados tipos de conversão do tipo automático.  
  
 O quarto e o quinto construtor especificam uma cópia do `hash_set``Right`.  
  
 O sexto, o sétimo e o oitavo construtores usam uma initializer_list para os elementos.  
  
 Os últimos construtores copiam o intervalo (`First`, `Last`) de um `hash_set` com clareza crescente para especificar o tipo de função de comparação da classe Traits e do alocador.  
  
 O oitavo construtor move o `hash_set``Right`.  
  
 A ordem real dos elementos de um contêiner `hash_set` depende da função de hash, da função de ordenação e do tamanho atual da tabela de hash e não pode, de modo geral, ser prevista como era possível com o contêiner do conjunto, em que foi determinada somente pela função de ordenação.  
  
##  <a name="a-namehashsetinserta--hashsetinsert"></a><a name="hash_set__insert"></a>  hash_set::insert  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Insere um elemento ou um intervalo de elementos em um `hash_set`.  
  
```  
pair<iterator, bool> insert(
    const value_type& Val);

iterator insert(
    iterator Where,  
    const value_type& Val);

void insert(
    initializer_list<value_type> IList)  
template <class InputIterator>  
void insert(
    InputIterator First,  
    InputIterator Last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Val`|O valor de um elemento a ser inserido no `hash_set`, a menos que o `hash_set` já contenha o elemento ou, de modo geral, um elemento cuja chave seja ordenada de maneira equivalente.|  
|`Where`|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (A inserção poderá ocorrer em um tempo constante amortizado, em vez de no tempo logarítmico, se o ponto de inserção seguir `_Where` imediatamente.)|  
|`First`|A posição do primeiro elemento a ser copiado de um `hash_set`.|  
|`Last`|A posição logo após o último elemento a ser copiado de um `hash_set`.|  
|`IList`|O initializer_list do qual copiar os elementos.|  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira função membro `insert` retorna um par cujo componente `bool` retorna `true` se uma inserção tiver sido feita e `false` se o `hash_set` já contivesse um elemento cuja chave tinha um valor equivalente na ordenação e cujo componente do iterador retorna o endereço em que um novo elemento foi inserido ou onde o elemento já estava localizado.  
  
 Para acessar o componente do iterador de um par `pr` retornado por essa função membro, use `pr.first` e, para desreferenciar, use `*(pr.first)`. Para acessar o componente `bool` de um par `pr` retornado por essa função membro, use `pr.second` e, para desreferenciar, use `*(pr.second)`.  
  
 A segunda função membro `insert` retorna um iterador que aponta para a posição em que o novo elemento foi inserido no `hash_set`.  
  
### <a name="remarks"></a>Comentários  
 A terceira função membro insere os elementos em uma initializer_list.  
  
 A terceira função membro insere a sequência de valores de elemento em um `hash_set` que corresponde a cada elemento tratado por um iterador no intervalo (`First`,`Last`) de um `hash_set` especificado.  
  
##  <a name="a-namehashsetiteratora--hashsetiterator"></a><a name="hash_set__iterator"></a>  hash_set::iterator  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::iterator iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **iterator** pode ser usado para modificar o valor de um elemento.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [begin](#hash_set__begin) que demonstra como declarar e usar o **iterator**.  
  
##  <a name="a-namehashsetkeycompa--hashsetkeycomp"></a><a name="hash_set__key_comp"></a>  hash_set::key_comp  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Recupera uma cópia do objeto de características de hash usado para fazer o hash e ordenar valores chave de elementos em um hash_set.  
  
```  
key_compare key_comp() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o objeto de função que um hash_set usa para ordenar seus elementos, que é o parâmetro de modelo `Traits`.  
  
 Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
### <a name="remarks"></a>Comentários  
 O objeto armazenado define a função membro:  
  
 **operador booliano**( **const Key&** _ *xVal*, **const Key&** \_ `yVal`);  
  
 que retornará **true** se `_xVal` preceder e não for igual a `_yVal` na ordem de classificação.  
  
 Observe que [key_compare](#hash_set__key_compare) e [value_compare](#hash_set__value_compare) são sinônimos do parâmetro de modelo **Traits**. Os dois tipos são fornecidos para as classes hash_set e hash_multiset, em que são idênticos, para compatibilidade com as classes hash_map e hash_multimap, em que são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_key_comp.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
  
   hash_set <int, hash_compare < int, less<int> > >hs1;  
   hash_set<int, hash_compare < int, less<int> > >::key_compare kc1  
          = hs1.key_comp( ) ;  
   bool result1 = kc1( 2, 3 ) ;  
   if( result1 == true )  
   {  
      cout << "kc1( 2,3 ) returns value of true, "  
           << "where kc1 is the function object of hs1."  
           << endl;  
   }  
   else  
   {  
      cout << "kc1( 2,3 ) returns value of false "  
           << "where kc1 is the function object of hs1."  
        << endl;  
   }  
  
   hash_set <int, hash_compare < int, greater<int> > > hs2;  
   hash_set<int, hash_compare < int, greater<int> > >::key_compare  
         kc2 = hs2.key_comp( ) ;  
   bool result2 = kc2( 2, 3 ) ;  
   if(result2 == true)  
   {  
      cout << "kc2( 2,3 ) returns value of true, "  
           << "where kc2 is the function object of hs2."  
           << endl;  
   }  
   else  
   {  
      cout << "kc2( 2,3 ) returns value of false, "  
           << "where kc2 is the function object of hs2."  
           << endl;  
   }  
}  
```  
  
##  <a name="a-namehashsetkeycomparea--hashsetkeycompare"></a><a name="hash_set__key_compare"></a>  hash_set::key_compare  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no hash_set.  
  
```  
typedef Traits key_compare;  
```  
  
### <a name="remarks"></a>Comentários  
 `key_compare` é um sinônimo do parâmetro de modelo `Traits`.  
  
 Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
 Observe que `key_compare` e [value_compare](#hash_set__value_compare) são sinônimos do parâmetro de modelo **Traits**. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [key_comp](#hash_set__key_comp) que demonstra como declarar e usar `key_compare`.  
  
##  <a name="a-namehashsetkeytypea--hashsetkeytype"></a><a name="hash_set__key_type"></a>  hash_set::key_type  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que descreve um objeto armazenado como um elemento de um hash_set em sua capacidade como uma chave de classificação.  
  
```  
typedef Key key_type;  
```  
  
### <a name="remarks"></a>Comentários  
 **key_type** é um sinônimo do parâmetro de modelo `Key`.  
  
 Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
 Observe que `key_type` e [value_type](#hash_set__value_type) são sinônimos do parâmetro de modelo **Key**. Os dois tipos são fornecidos para as classes hash_set e hash_multiset, em que são idênticos, para compatibilidade com as classes hash_map e hash_multimap, em que são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [value_type](#hash_set__value_type) para obter uma amostra de como declarar e usar `key_type`.  
  
##  <a name="a-namehashsetlowerbounda--hashsetlowerbound"></a><a name="hash_set__lower_bound"></a>  hash_set::lower_bound  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador para o primeiro elemento em um hash_set, com uma chave que é igual ou maior que uma chave especificada.  
  
```  
const_iterator lower_bound(const Key& key) const;

iterator lower_bound(const Key& key);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` key`  
 A chave do argumento a ser comparada com a chave de classificação de um elemento do hash_set que está sendo pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **iterador** ou `const_iterator` que aborda a localização de um elemento em um hash_set com uma chave, que é igual ou maior que a chave de argumento ou que trata do local que sucede o último elemento no hash_set, se nenhuma correspondência for encontrada para a chave.  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_lower_bound.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int> :: const_iterator hs1_AcIter, hs1_RcIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   hs1_RcIter = hs1.lower_bound( 20 );  
   cout << "The element of hash_set hs1 with a key of 20 is: "  
        << *hs1_RcIter << "." << endl;  
  
   hs1_RcIter = hs1.lower_bound( 40 );  
  
   // If no match is found for the key, end( ) is returned  
   if ( hs1_RcIter == hs1.end( ) )  
      cout << "The hash_set hs1 doesn't have an element "  
           << "with a key of 40." << endl;  
   else  
      cout << "The element of hash_set hs1 with a key of 40 is: "  
           << *hs1_RcIter << "." << endl;  
  
   // An element at a specific location in the hash_set can be found   
   // by using a dereferenced iterator that addresses the location  
   hs1_AcIter = hs1.end( );  
   hs1_AcIter--;  
   hs1_RcIter = hs1.lower_bound( *hs1_AcIter );  
   cout << "The element of hs1 with a key matching "  
        << "that of the last element is: "  
        << *hs1_RcIter << "." << endl;  
}  
```  
  
```Output  
The element of hash_set hs1 with a key of 20 is: 20.  
The hash_set hs1 doesn't have an element with a key of 40.  
The element of hs1 with a key matching that of the last element is: 30.  
```  
  
##  <a name="a-namehashsetmaxsizea--hashsetmaxsize"></a><a name="hash_set__max_size"></a>  hash_set::max_size  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna o tamanho máximo do hash_set.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho máximo possível do hash_set.  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_max_size.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::size_type i;  
  
   i = hs1.max_size( );  
   cout << "The maximum possible length "  
        << "of the hash_set is " << i << "." << endl;  
}  
```  
  
##  <a name="a-namehashsetoperatoreqa--hashsetoperator"></a><a name="hash_set__operator_eq"></a>  hash_set::operator=  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Substitui os elementos de hash_set por uma cópia de outro hash_set.  
  
```  
hash_set& operator=(const hash_set& right);

hash_set& operator=(hash_set&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` right`|O [hash_set](../standard-library/hash-set-class.md) que está sendo copiado para o `hash_set`.|  
  
### <a name="remarks"></a>Comentários  
 Após apagar os elementos existentes em um `hash_set`, `operator=` copiará ou moverá o conteúdo de ` right` para `hash_set`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_operator_as.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set<int> v1, v2, v3;  
   hash_set<int>::iterator iter;  
  
   v1.insert(10);  
  
   cout << "v1 = " ;  
   for (iter = v1.begin(); iter != v1.end(); iter++)  
      cout << iter << " ";  
   cout << endl;  
  
   v2 = v1;  
   cout << "v2 = ";  
   for (iter = v2.begin(); iter != v2.end(); iter++)  
      cout << iter << " ";  
   cout << endl;  
  
// move v1 into v2  
   v2.clear();  
   v2 = move(v1);  
   cout << "v2 = ";  
   for (iter = v2.begin(); iter != v2.end(); iter++)  
      cout << iter << " ";  
   cout << endl;  
}  
```  
  
##  <a name="a-namehashsetpointera--hashsetpointer"></a><a name="hash_set__pointer"></a>  hash_set::pointer  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece um ponteiro para um elemento em um hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **pointer** pode ser usado para modificar o valor de um elemento.  
  
 Na maioria dos casos, um [iterador](#hash_set__iterator) deve ser usado para acessar os elementos em um objeto hash_set.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
##  <a name="a-namehashsetrbegina--hashsetrbegin"></a><a name="hash_set__rbegin"></a>  hash_set::rbegin  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador que trata o primeiro elemento em um hash_set invertido.  
  
```  
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional invertido que trata do primeiro elemento em um hash_set invertido ou que trata do que foi o último elemento do hash_set não invertido.  
  
### <a name="remarks"></a>Comentários  
 `rbegin` é usado com um hash_set invertido, assim como [begin](#hash_set__begin) é usado com um hash_set.  
  
 Se o valor retornado de `rbegin` for atribuído a `const_reverse_iterator`, o objeto hash_set não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a `reverse_iterator`, o objeto hash_set poderá ser modificado.  
  
 `rbegin` pode ser usado para iterar em um hash_set no sentido reverso.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_rbegin.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::iterator hs1_Iter;  
   hash_set <int>::reverse_iterator hs1_rIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   hs1_rIter = hs1.rbegin( );  
   cout << "The first element in the reversed hash_set is "  
        << *hs1_rIter << "." << endl;  
  
   // begin can be used to start an iteration   
   // throught a hash_set in a forward order  
   cout << "The hash_set is: ";  
   for ( hs1_Iter = hs1.begin( ) ; hs1_Iter != hs1.end( );  
         hs1_Iter++ )  
      cout << *hs1_Iter << " ";  
   cout << endl;  
  
   // rbegin can be used to start an iteration   
   // throught a hash_set in a reverse order  
   cout << "The reversed hash_set is: ";  
   for ( hs1_rIter = hs1.rbegin( ) ; hs1_rIter != hs1.rend( );  
         hs1_rIter++ )  
      cout << *hs1_rIter << " ";  
   cout << endl;  
  
   // A hash_set element can be erased by dereferencing to its key   
   hs1_rIter = hs1.rbegin( );  
   hs1.erase ( *hs1_rIter );  
  
   hs1_rIter = hs1.rbegin( );  
   cout << "After the erasure, the first element "  
        << "in the reversed hash_set is "<< *hs1_rIter << "."  
        << endl;  
}  
```  
  
```Output  
The first element in the reversed hash_set is 30.  
The hash_set is: 10 20 30   
The reversed hash_set is: 30 20 10   
After the erasure, the first element in the reversed hash_set is 20.  
```  
  
##  <a name="a-namehashsetreferencea--hashsetreference"></a><a name="hash_set__reference"></a>  hash_set::reference  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece uma referência a um elemento armazenado em um hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::reference reference;  
```  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_reference.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
  
   // Declare and initialize a reference &Ref1 to the 1st element  
   int &Ref1 = *hs1.begin( );  
  
   cout << "The first element in the hash_set is "  
        << Ref1 << "." << endl;  
  
   // The value of the 1st element of the hash_set can be changed  
   // by operating on its (non-const) reference  
   Ref1 = Ref1 + 5;  
  
   cout << "The first element in the hash_set is now "  
        << *hs1.begin() << "." << endl;  
}  
```  
  
```Output  
The first element in the hash_set is 10.  
The first element in the hash_set is now 15.  
```  
  
##  <a name="a-namehashsetrenda--hashsetrend"></a><a name="hash_set__rend"></a>  hash_set::rend  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador que trata do local após o último elemento em um hash_set invertido.  
  
```  
const_reverse_iterator rend() const;

reverse_iterator rend();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador bidirecional inverso que trata do local que vem após o último elemento em um hash_set invertido (o local que precedeu o primeiro elemento no hash_set não invertido).  
  
### <a name="remarks"></a>Comentários  
 `rend` é usado com um hash_set invertido, assim como [end](#hash_set__end) é usado com um hash_set.  
  
 Se o valor retornado de `rend` for atribuído a `const_reverse_iterator`, o objeto hash_set não poderá ser modificado. Se o valor retornado de `rend` for atribuído a `reverse_iterator`, o objeto hash_set poderá ser modificado. O valor retornado por `rend` não deve ser desreferenciado.  
  
 `rend` pode ser usado para testar se um iterador inverso alcançou o final de seu hash_set.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_rend.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::iterator hs1_Iter;  
   hash_set <int>::reverse_iterator hs1_rIter;  
   hash_set <int>::const_reverse_iterator hs1_crIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   hs1_rIter = hs1.rend( );  
   hs1_rIter--;  
   cout << "The last element in the reversed hash_set is "  
        << *hs1_rIter << "." << endl;  
  
   // end can be used to terminate an iteration   
   // throught a hash_set in a forward order  
   cout << "The hash_set is: ";  
   for ( hs1_Iter = hs1.begin( ) ; hs1_Iter != hs1.end( );  
         hs1_Iter++ )  
      cout << *hs1_Iter << " ";  
   cout << "." << endl;  
  
   // rend can be used to terminate an iteration   
   // through a hash_set in a reverse order  
   cout << "The reversed hash_set is: ";  
   for ( hs1_rIter = hs1.rbegin( ) ; hs1_rIter != hs1.rend( );  
         hs1_rIter++ )  
      cout << *hs1_rIter << " ";  
   cout << "." << endl;  
  
   hs1_rIter = hs1.rend( );  
   hs1_rIter--;  
   hs1.erase ( *hs1_rIter );  
  
   hs1_rIter = hs1.rend( );  
   hs1_rIter--;  
   cout << "After the erasure, the last element in the "  
        << "reversed hash_set is " << *hs1_rIter << "."  
        << endl;  
}  
```  
  
```Output  
The last element in the reversed hash_set is 10.  
The hash_set is: 10 20 30 .  
The reversed hash_set is: 30 20 10 .  
After the erasure, the last element in the reversed hash_set is 20.  
```  
  
##  <a name="a-namehashsetreverseiteratora--hashsetreverseiterator"></a><a name="hash_set__reverse_iterator"></a>  hash_set::reverse_iterator  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um hash_set invertido.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::reverse_iterator reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `reverse_iterator` é usado para iterar pelo hash_set em ordem inversa.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [rbegin](#hash_set__rbegin) que demonstra como declarar e usar `reverse_iterator`.  
  
##  <a name="a-namehashsetsizea--hashsetsize"></a><a name="hash_set__size"></a>  hash_set::size  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna o número de elementos no hash_set.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do hash_set.  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_size.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int> :: size_type i;  
  
   hs1.insert( 1 );  
   i = hs1.size( );  
   cout << "The hash_set length is " << i << "." << endl;  
  
   hs1.insert( 2 );  
   i = hs1.size( );  
   cout << "The hash_set length is now " << i << "." << endl;  
}  
```  
  
```Output  
The hash_set length is 1.  
The hash_set length is now 2.  
```  
  
##  <a name="a-namehashsetsizetypea--hashsetsizetype"></a><a name="hash_set__size_type"></a>  hash_set::size_type  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo inteiro sem sinal que pode representar o número de elementos em um hash_set.  
  
```  
typedef list<typename Traits::value_type, typename Traits::allocator_type>::size_type size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [size](#hash_set__size) que demonstra como declarar e usar `size_type`  
  
##  <a name="a-namehashsetswapa--hashsetswap"></a><a name="hash_set__swap"></a>  hash_set::swap  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Troca os elementos de dois hash_sets.  
  
```  
void swap(hash_set& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O hash_set do argumento que fornece os elementos a serem trocados com o hash_set de destino.  
  
### <a name="remarks"></a>Comentários  
 A função membro não invalida referências, ponteiros ou iteradores que designam elementos nos dois hash_set cujos elementos são trocados.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_swap.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1, hs2, hs3;  
   hash_set <int>::iterator hs1_Iter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
   hs2.insert( 100 );  
   hs2.insert( 200 );  
   hs3.insert( 300 );  
  
   cout << "The original hash_set hs1 is:";  
   for ( hs1_Iter = hs1.begin( ); hs1_Iter != hs1.end( );  
         hs1_Iter++ )  
         cout << " " << *hs1_Iter;  
   cout   << "." << endl;  
  
   // This is the member function version of swap  
   hs1.swap( hs2 );  
  
   cout << "After swapping with hs2, list hs1 is:";  
   for ( hs1_Iter = hs1.begin( ); hs1_Iter != hs1.end( );  
         hs1_Iter++ )  
         cout << " " << *hs1_Iter;  
   cout  << "." << endl;  
  
   // This is the specialized template version of swap  
   swap( hs1, hs3 );  
  
   cout << "After swapping with hs3, list hs1 is:";  
   for ( hs1_Iter = hs1.begin( ); hs1_Iter != hs1.end( );  
         hs1_Iter++ )  
         cout << " " << *hs1_Iter;  
   cout   << "." << endl;  
}  
```  
  
```Output  
The original hash_set hs1 is: 10 20 30.  
After swapping with hs2, list hs1 is: 200 100.  
After swapping with hs3, list hs1 is: 300.  
```  
  
##  <a name="a-namehashsetupperbounda--hashsetupperbound"></a><a name="hash_set__upper_bound"></a>  hash_set::upper_bound  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Retorna um iterador para o primeiro elemento em um hash_set com uma chave que é maior que uma chave especificada.  
  
```  
const_iterator upper_bound(const Key& key) const;

iterator upper_bound(const Key& key);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` key`  
 A chave do argumento a ser comparada com a chave de classificação de um elemento do hash_set que está sendo pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **iterador** ou `const_iterator` que aborda a localização de um elemento em um hash_set com uma chave, que é igual ou maior que a chave de argumento ou que trata do local que sucede o último elemento no hash_set, se nenhuma correspondência for encontrada para a chave.  
  
### <a name="remarks"></a>Comentários  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_upper_bound.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int> :: const_iterator hs1_AcIter, hs1_RcIter;  
  
   hs1.insert( 10 );  
   hs1.insert( 20 );  
   hs1.insert( 30 );  
  
   hs1_RcIter = hs1.upper_bound( 20 );  
   cout << "The first element of hash_set hs1 with a key greater "  
        << "than 20 is: " << *hs1_RcIter << "." << endl;  
  
   hs1_RcIter = hs1.upper_bound( 30 );  
  
   // If no match is found for the key, end( ) is returned  
   if ( hs1_RcIter == hs1.end( ) )  
      cout << "The hash_set hs1 doesn't have an element "  
           << "with a key greater than 30." << endl;  
   else  
      cout << "The element of hash_set hs1 with a key > 40 is: "  
           << *hs1_RcIter << "." << endl;  
  
   // An element at a specific location in the hash_set can be found  
   // by using a dereferenced iterator addressing the location  
   hs1_AcIter = hs1.begin( );  
   hs1_RcIter = hs1.upper_bound( *hs1_AcIter );  
   cout << "The first element of hs1 with a key greater than "  
        << endl << "that of the initial element of hs1 is: "  
        << *hs1_RcIter << "." << endl;  
}  
```  
  
```Output  
The first element of hash_set hs1 with a key greater than 20 is: 30.  
The hash_set hs1 doesn't have an element with a key greater than 30.  
The first element of hs1 with a key greater than   
that of the initial element of hs1 is: 20.  
```  
  
##  <a name="a-namehashsetvaluecompa--hashsetvaluecomp"></a><a name="hash_set__value_comp"></a>  hash_set::value_comp  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Recupera uma cópia do objeto de comparação usado para ordenar valores de elemento em um hash_set.  
  
```  
value_compare value_comp() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o objeto de função que um hash_set usa para ordenar seus elementos, que é o parâmetro de modelo `Compare`.  
  
 Para obter mais informações sobre `Compare`, consulte a seção Comentários do tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
### <a name="remarks"></a>Comentários  
 O objeto armazenado define a função membro:  
  
 **operador booliano**( **const Key&** _ *xVal*, **const Key&** \_ `yVal`);  
  
 que retornará **true** se `_xVal` preceder e não for igual a `_yVal` na ordem de classificação.  
  
 Observe que [value_compare](../standard-library/set-class.md#set__value_compare) e [key_compare](../standard-library/set-class.md#set__key_compare) são sinônimos do parâmetro de modelo `Compare`. Os dois tipos são fornecidos para as classes hash_set e hash_multiset, em que são idênticos, para compatibilidade com as classes hash_map e hash_multimap, em que são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_value_comp.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
  
   hash_set <int, hash_compare < int, less<int> > > hs1;  
   hash_set <int, hash_compare < int, less<int> >  >::value_compare  
      vc1 = hs1.value_comp( );  
   bool result1 = vc1( 2, 3 );  
   if( result1 == true )  
   {  
      cout << "vc1( 2,3 ) returns value of true, "  
           << "where vc1 is the function object of hs1."  
           << endl;  
   }  
   else  
   {  
      cout << "vc1( 2,3 ) returns value of false, "  
           << "where vc1 is the function object of hs1."  
           << endl;  
   }  
  
   hash_set <int, hash_compare < int, greater<int> > > hs2;  
   hash_set<int, hash_compare < int, greater<int> > >::value_compare  
      vc2 = hs2.value_comp( );  
   bool result2 = vc2( 2, 3 );  
   if( result2 == true )  
   {  
      cout << "vc2( 2,3 ) returns value of true, "  
           << "where vc2 is the function object of hs2."  
           << endl;  
   }  
   else  
   {  
      cout << "vc2( 2,3 ) returns value of false, "  
           << "where vc2 is the function object of hs2."  
           << endl;  
   }  
}  
```  
  
##  <a name="a-namehashsetvaluecomparea--hashsetvaluecompare"></a><a name="hash_set__value_compare"></a>  hash_set::value_compare  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que fornece dois objetos de função, um predicado binário da classe compare que pode comparar dois valores de elemento de um hash_set para determinar sua ordem relativa, bem como um predicado unário que faz o hash dos elementos.  
  
```  
typedef key_compare value_compare;  
```  
  
### <a name="remarks"></a>Comentários  
 **value_compare** é um sinônimo do parâmetro de modelo `Traits`.  
  
 Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_set](../standard-library/hash-set-class.md).  
  
 Observe que [key_compare](#hash_set__key_compare) e **value_compare** são sinônimos do parâmetro de modelo **Traits**. Os dois tipos são fornecidos para as classes hash_set e hash_multiset, em que são idênticos, para compatibilidade com as classes hash_map e hash_multimap, em que são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [value_comp](#hash_set__value_comp) para obter um exemplo de como declarar e usar `value_compare`.  
  
##  <a name="a-namehashsetvaluetypea--hashsetvaluetype"></a><a name="hash_set__value_type"></a>  hash_set::value_type  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Um tipo que descreve um objeto armazenado como um elemento de um hash_set em sua capacidade como um valor.  
  
```  
typedef Key value_type;  
```  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_value_type.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1;  
   hash_set <int>::iterator hs1_Iter;  
  
   hash_set <int> :: value_type hsvt_Int;   // Declare value_type  
   hsvt_Int = 10;             // Initialize value_type  
  
   hash_set <int> :: key_type hskt_Int;   // Declare key_type  
   hskt_Int = 20;             // Initialize key_type  
  
   hs1.insert( hsvt_Int );         // Insert value into hs1  
   hs1.insert( hskt_Int );         // Insert key into hs1  
  
   // A hash_set accepts key_types or value_types as elements  
   cout << "The hash_set has elements:";  
   for ( hs1_Iter = hs1.begin( ) ; hs1_Iter != hs1.end( ); hs1_Iter++)  
      cout << " " << *hs1_Iter;  
   cout << "." << endl;  
}  
```  
  
```Output  
The hash_set has elements: 10 20.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)


