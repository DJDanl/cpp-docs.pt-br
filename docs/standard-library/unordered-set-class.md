---
title: Classe unordered_set | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- unordered_set
- std::unordered_set
- unordered_set/std::unordered_set
- std::unordered_set::allocator_type
- unordered_set/std::unordered_set::allocator_type
- std::unordered_set::const_iterator
- unordered_set/std::unordered_set::const_iterator
- std::unordered_set::const_local_iterator
- unordered_set/std::unordered_set::const_local_iterator
- std::unordered_set::const_pointer
- unordered_set/std::unordered_set::const_pointer
- std::unordered_set::const_reference
- unordered_set/std::unordered_set::const_reference
- std::unordered_set::difference_type
- unordered_set/std::unordered_set::difference_type
- std::unordered_set::hasher
- unordered_set/std::unordered_set::hasher
- std::unordered_set::iterator
- unordered_set/std::unordered_set::iterator
- std::unordered_set::key_equal
- unordered_set/std::unordered_set::key_equal
- std::unordered_set::key_type
- unordered_set/std::unordered_set::key_type
- std::unordered_set::local_iterator
- unordered_set/std::unordered_set::local_iterator
- std::unordered_set::pointer
- unordered_set/std::unordered_set::pointer
- std::unordered_set::reference
- unordered_set/std::unordered_set::reference
- std::unordered_set::size_type
- unordered_set/std::unordered_set::size_type
- std::unordered_set::value_type
- unordered_set/std::unordered_set::value_type
- std::unordered_set::begin
- unordered_set/std::unordered_set::begin
- std::unordered_set::bucket
- unordered_set/std::unordered_set::bucket
- std::unordered_set::bucket_count
- unordered_set/std::unordered_set::bucket_count
- std::unordered_set::bucket_size
- unordered_set/std::unordered_set::bucket_size
- std::unordered_set::cbegin
- unordered_set/std::unordered_set::cbegin
- std::unordered_set::cend
- unordered_set/std::unordered_set::cend
- std::unordered_set::clear
- unordered_set/std::unordered_set::clear
- std::unordered_set::count
- unordered_set/std::unordered_set::count
- std::unordered_set::emplace
- unordered_set/std::unordered_set::emplace
- std::unordered_set::emplace_hint
- unordered_set/std::unordered_set::emplace_hint
- std::unordered_set::empty
- unordered_set/std::unordered_set::empty
- std::unordered_set::end
- unordered_set/std::unordered_set::end
- std::unordered_set::equal_range
- unordered_set/std::unordered_set::equal_range
- std::unordered_set::erase
- unordered_set/std::unordered_set::erase
- std::unordered_set::find
- unordered_set/std::unordered_set::find
- std::unordered_set::get_allocator
- unordered_set/std::unordered_set::get_allocator
- std::unordered_set::hash_function
- unordered_set/std::unordered_set::hash_function
- std::unordered_set::insert
- unordered_set/std::unordered_set::insert
- std::unordered_set::key_eq
- unordered_set/std::unordered_set::key_eq
- std::unordered_set::load_factor
- unordered_set/std::unordered_set::load_factor
- std::unordered_set::max_bucket_count
- unordered_set/std::unordered_set::max_bucket_count
- std::unordered_set::max_load_factor
- unordered_set/std::unordered_set::max_load_factor
- std::unordered_set::max_size
- unordered_set/std::unordered_set::max_size
- std::unordered_set::rehash
- unordered_set/std::unordered_set::rehash
- std::unordered_set::size
- unordered_set/std::unordered_set::size
- std::unordered_set::swap
- unordered_set/std::unordered_set::swap
- std::unordered_set::unordered_set
- unordered_set/std::unordered_set::unordered_set
- std::unordered_set::operator=
- unordered_set/std::unordered_set::operator=
dev_langs:
- C++
helpviewer_keywords:
- unordered_set class
ms.assetid: ac08084e-05a7-48c0-9ae4-d40c529922dd
caps.latest.revision: 23
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: e41fbf26ba7a2209dac67965ac3a5e045bf93324
ms.lasthandoff: 02/25/2017

---
# <a name="unorderedset-class"></a>Classe unordered_set
A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos do tipo`const Key`. A sequência é ordenada sem muita rigidez por uma função de hash, que particiona a sequência em um conjunto ordenado de subsequências chamado bucket. Dentro de cada bucket uma função de comparação determina se um par de elementos tem ordenação equivalente. Cada elemento serve como uma chave de classificação e um valor. A sequência é representada de forma a permitir pesquisa, inserção e remoção de um elemento com um número arbitrário de operações que podem ser independentes do número de elementos na sequência (tempo constante), pelo menos quando todos os buckets forem de comprimento aproximadamente igual. No pior caso, quando todos os elementos estiverem em um bucket, o número de operações será proporcional ao número de elementos na sequência (tempo linear). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <
   class Key,  
   class Hash = std::hash<Key>,  
   class Pred = std::equal_to<Key>,  
   class Alloc = std::allocator<Key>>  
class unordered_set;  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Key`|O tipo principal.|  
|`Hash`|O tipo de objeto da função de hash.|  
|`Pred`|O tipo de objeto da função de comparação de igualdade.|  
|`Alloc`|A classe do alocador.|  
  
## <a name="members"></a>Membros  
  
|||  
|-|-|  
|Definição do tipo|Descrição|  
|[unordered_set::allocator_type](#unordered_set__allocator_type)|O tipo de um distribuidor para gerenciar o armazenamento.|  
|[unordered_set::const_iterator](#unordered_set__const_iterator)|O tipo de um iterador de constante para a sequência controlada.|  
|[unordered_set::const_local_iterator](#unordered_set__const_local_iterator)|O tipo de um iterador de bucket de constante para a sequência controlada.|  
|[unordered_set::const_pointer](#unordered_set__const_pointer)|O tipo de um ponteiro de constante para um elemento.|  
|[unordered_set::const_reference](#unordered_set__const_reference)|O tipo de uma referência de constante para um elemento.|  
|[unordered_set::difference_type](#unordered_set__difference_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[unordered_set::hasher](#unordered_set__hasher)|O tipo de função de hash.|  
|[unordered_set::iterator](#unordered_set__iterator)|O tipo de um iterador para a sequência controlada.|  
|[unordered_set::key_equal](#unordered_set__key_equal)|O tipo da função de comparação.|  
|[unordered_set::key_type](#unordered_set__key_type)|O tipo de uma chave de classificação.|  
|[unordered_set::local_iterator](#unordered_set__local_iterator)|O tipo de um iterador de bucket para a sequência controlada.|  
|[unordered_set::pointer](#unordered_set__pointer)|O tipo de um ponteiro para um elemento.|  
|[unordered_set::reference](#unordered_set__reference)|O tipo de uma referência para um elemento.|  
|[unordered_set::size_type](#unordered_set__size_type)|O tipo de uma distância sem sinal entre dois elementos.|  
|[unordered_set::value_type](#unordered_set__value_type)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[unordered_set::begin](#unordered_set__begin)|Designa o início da sequência controlada.|  
|[unordered_set::bucket](#unordered_set__bucket)|Obtém o número de buckets de um valor de chave.|  
|[unordered_set::bucket_count](#unordered_set__bucket_count)|Obtém o número de buckets.|  
|[unordered_set::bucket_size](#unordered_set__bucket_size)|Obtém o tamanho de um bucket.|  
|[unordered_set::cbegin](#unordered_set__cbegin)|Designa o início da sequência controlada.|  
|[unordered_set::cend](#unordered_set__cend)|Designa o fim da sequência controlada.|  
|[unordered_set::clear](#unordered_set__clear)|Remove todos os elementos.|  
|[unordered_set::count](#unordered_set__count)|Localiza o número de elementos que correspondem a uma chave especificada.|  
|[unordered_set::emplace](#unordered_set__emplace)|Adiciona um elemento construído no lugar.|  
|[unordered_set::emplace_hint](#unordered_set__emplace_hint)|Adiciona um elemento construído no lugar, com dica.|  
|[unordered_set::empty](#unordered_set__empty)|Testa se nenhum elemento está presente.|  
|[unordered_set::end](#unordered_set__end)|Designa o fim da sequência controlada.|  
|[unordered_set::equal_range](#unordered_set__equal_range)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[unordered_set::erase](#unordered_set__erase)|Remove os elementos em posições especificadas.|  
|[unordered_set::find](#unordered_set__find)|Localiza um elemento que corresponde a uma chave especificada.|  
|[unordered_set::get_allocator](#unordered_set__get_allocator)|Obtém o objeto de alocador armazenado.|  
|[unordered_set::hash_function](#unordered_set__hash_function)|Obtém o objeto armazenado da função de hash.|  
|[unordered_set::insert](#unordered_set__insert)|Adiciona elementos.|  
|[unordered_set::key_eq](#unordered_set__key_eq)|Obtém o objeto armazenado da função de comparação.|  
|[unordered_set::load_factor](#unordered_set__load_factor)|Conta a média de elementos por bucket.|  
|[unordered_set::max_bucket_count](#unordered_set__max_bucket_count)|Obtém o número máximo de buckets.|  
|[unordered_set::max_load_factor](#unordered_set__max_load_factor)|Obtém ou define o máximo de elementos por bucket.|  
|[unordered_set::max_size](#unordered_set__max_size)|Obtém o tamanho máximo da sequência controlada.|  
|[unordered_set::rehash](#unordered_set__rehash)|Recria a tabela de hash.|  
|[unordered_set::size](#unordered_set__size)|Conta o número de elementos.|  
|[unordered_set::swap](#unordered_set__swap)|Alterna o conteúdo de dois contêineres.|  
|[unordered_set::unordered_set](#unordered_set__unordered_set)|Constrói um objeto contêiner.|  
  
|||  
|-|-|  
|Operadores|Descrição|  
|[unordered_set::operator=](#unordered_set__operator_eq)|Copia uma tabela de hash.|  
  
## <a name="remarks"></a>Comentários  
 O objeto ordena a sequência que ele controla chamando dois objetos armazenados, um objeto de função de comparação do tipo [unordered_set::key_equal](#unordered_set__key_equal) e um objeto de função de hash do tipo [unordered_set::hasher](#unordered_set__hasher). Você acessa o primeiro objeto armazenado chamando a função membro [unordered_set::key_eq](#unordered_set__key_eq)`()`; e acessa o segundo objeto armazenado chamando a função membro [unordered_set::hash_function](#unordered_set__hash_function)`()`. Especificamente, para todos os valores `X` e `Y` do tipo `Key`, a chamada `key_eq()(X, Y)` retornará verdadeiro somente se os dois valores de argumento tiverem ordem equivalente; a chamada `hash_function()(keyval)` resulta em uma distribuição de valores do tipo `size_t`. Diferentemente da classe de modelo [unordered_multiset Class](../standard-library/unordered-multiset-class.md), um objeto da classe de modelo `unordered_set` garante que `key_eq()(X, Y)` seja sempre falsa para um dos dois elementos da sequência controlada. (As chaves são exclusivas.)  
  
 O objeto também armazena um fator de carga máximo, que especifica o número máximo médio desejado de elementos por bucket. Se a inserção de um elemento fizer com que [unordered_set::load_factor](#unordered_set__load_factor)`()` exceda o fator de carga máximo, o contêiner aumentará o número de buckets e recriará a tabela de hash conforme a necessidade.  
  
 A ordem real de elementos na sequência controlada depende da função de hash, da função de comparação, da ordem de inserção, do fator máximo de carga e do número atual de buckets. Você não pode fazer uma previsão geral da ordem dos elementos na sequência controlada. No entanto, você sempre terá certeza de que qualquer subconjunto de elementos que tenha ordem equivalente será adjacente na sequência de controle.  
  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado de alocador do tipo [unordered_set::allocator_type](#unordered_set__allocator_type). Esse objeto de alocador deve ter a mesma interface externa que um objeto da classe de modelo`allocator`. Observe que o objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<unordered_set>  
  
 **Namespace:** std  
  
##  <a name="a-nameunorderedsetallocatortypea--unorderedsetallocatortype"></a><a name="unordered_set__allocator_type"></a>  unordered_set::allocator_type  
 O tipo de um distribuidor para gerenciar o armazenamento.  
  
```  
typedef Alloc allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo`Alloc`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_allocator_type.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
typedef std::allocator<std::pair<const char, int> > Myalloc;  
int main()  
{  
Myset c1;  
  
Myset::allocator_type al = c1.get_allocator();  
std::cout << "al == std::allocator() is "  
<< std::boolalpha << (al == Myalloc()) << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
al == std::allocator() is true  
```  
  
##  <a name="a-nameunorderedsetbegina--unorderedsetbegin"></a><a name="unordered_set__begin"></a>  unordered_set::begin  
 Designa o início da sequência controlada ou um bucket.  
  
```  
 
iterator begin();

const_iterator begin() const;

 
local_iterator begin(size_type nbucket);

const_local_iterator begin(size_type nbucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`nbucket`|O número de bucket.|  
  
### <a name="remarks"></a>Comentários  
 As duas primeiras funções membro retornam um iterador de encaminhamento que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia). As duas últimas funções membro retornam um iterador de encaminhamento que aponta para o primeiro elemento do bucket`nbucket` (ou imediatamente após o fim de um bucket vazio).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// unordered_set_begin.cpp  
// compile using: cl.exe /EHsc /nologo /W4 /MTd  
#include <unordered_set>  
#include <iostream>  
  
using namespace std;  
  
typedef unordered_set<char> MySet;  
  
int main()  
{  
MySet c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents using range-based for  
for (auto it : c1) {  
cout << " [" << it << "]";  
}  
  
cout << endl;  
  
// display contents using explicit for  
for (MySet::const_iterator it = c1.begin(); it != c1.end(); ++it) {  
cout << " [" << *it << "]";  
}  
  
cout << std::endl;  
  
// display first two items  
MySet::iterator it2 = c1.begin();  
cout << " [" << *it2 << "]";  
++it2;  
cout << " [" << *it2 << "]";  
cout << endl;  
  
// display bucket containing 'a'  
MySet::const_local_iterator lit = c1.begin(c1.bucket('a'));  
cout << " [" << *lit << "]";  
  
return (0);  
}  
  
```  
  
```Output  
  
[a] [b] [c]                                   
  
[a] [b] [c]                                  
  
[a] [b]                                   
  
[a]  
  
```  
  
##  <a name="a-nameunorderedsetbucketa--unorderedsetbucket"></a><a name="unordered_set__bucket"></a>  unordered_set::bucket  
 Obtém o número de buckets de um valor de chave.  
  
```  
size_type bucket(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor de chave a ser mapeado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número de bucket atualmente correspondente ao valor da chave`keyval`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_bucket.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// display buckets for keys  
Myset::size_type bs = c1.bucket('a');  
std::cout << "bucket('a') == " << bs << std::endl;  
std::cout << "bucket_size(" << bs << ") == " << c1.bucket_size(bs)  
<< std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
bucket('a') == 7  
bucket_size(7) == 1  
```  
  
##  <a name="a-nameunorderedsetbucketcounta--unorderedsetbucketcount"></a><a name="unordered_set__bucket_count"></a>  unordered_set::bucket_count  
 Obtém o número de buckets.  
  
```  
size_type bucket_count() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número atual de buckets.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_bucket_count.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect current parameters  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// change max_load_factor and redisplay  
c1.max_load_factor(0.10f);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// rehash and redisplay  
c1.rehash(100);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_bucket_count() == 128  
max_load_factor() == 0.1  
```  
  
##  <a name="a-nameunorderedsetbucketsizea--unorderedsetbucketsize"></a><a name="unordered_set__bucket_size"></a>  unordered_set::bucket_size  
 Obtém o tamanho de um bucket  
  
```  
size_type bucket_size(size_type nbucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `nbucket`  
 O número de bucket.  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam o tamanho do número de bucket`nbucket`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_bucket_size.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// display buckets for keys  
Myset::size_type bs = c1.bucket('a');  
std::cout << "bucket('a') == " << bs << std::endl;  
std::cout << "bucket_size(" << bs << ") == " << c1.bucket_size(bs)  
<< std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
bucket('a') == 7  
bucket_size(7) == 1  
```  
  
##  <a name="a-nameunorderedsetcbegina--unorderedsetcbegin"></a><a name="unordered_set__cbegin"></a>  unordered_set::cbegin  
 Retorna um iterador `const` que trata o primeiro elemento no intervalo.  
  
```  
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso por avanço `const` que aponta o primeiro elemento do intervalo ou o local logo após o fim de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).  
  
### <a name="remarks"></a>Comentários  
 Com o valor retornado `cbegin`, os elementos do intervalo não podem ser modificados.  
  
 Você pode usar essa função membro no lugar da função membro `begin()`, de modo a assegurar que o valor retornado seja `const_iterator`. Normalmente, ela é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere que `Container` será um contêiner (não `const`) modificável de qualquer tipo que dá suporte a `begin()` e `cbegin()`.  
  
```cpp  
auto i1 = Container.begin();
// i1 isContainer<T>::iterator  
auto i2 = Container.cbegin();

// i2 isContainer<T>::const_iterator  
```  
  
##  <a name="a-nameunorderedsetcenda--unorderedsetcend"></a><a name="unordered_set__cend"></a>  unordered_set::cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `const` iterador de acesso por avanço que aponta para além do fim do intervalo.  
  
### <a name="remarks"></a>Comentários  
 `cend` é usado para testar se um iterador passou do fim de seu intervalo.  
  
 Você pode usar essa função membro no lugar da função membro `end()`, de modo a assegurar que o valor retornado seja `const_iterator`. Normalmente, ela é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere que `Container` será um contêiner (não `const`) modificável de qualquer tipo que dá suporte a `end()` e `cend()`.  
  
```cpp  
auto i1 = Container.end();
// i1 isContainer<T>::iterator  
auto i2 = Container.cend();

// i2 isContainer<T>::const_iterator  
```  
  
 O valor retornado por `cend` não deve ser desreferenciado.  
  
##  <a name="a-nameunorderedsetcleara--unorderedsetclear"></a><a name="unordered_set__clear"></a>  unordered_set::clear  
 Remove todos os elementos.  
  
```  
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de função membro [unordered_set::erase](#unordered_set__erase)`(` [unordered_set::begin](#unordered_set__begin)`(),` [unordered_set::end](#unordered_set__end)`())`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_clear.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// clear the container and reinspect  
c1.clear();  
std::cout << "size == " << c1.size() << std::endl;  
std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;  
std::cout << std::endl;  
  
c1.insert('d');  
c1.insert('e');  
  
// display contents " [e] [d]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
std::cout << "size == " << c1.size() << std::endl;  
std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
size == 0  
empty() == true  
  
[e] [d]  
size == 2  
empty() == false  
```  
  
##  <a name="a-nameunorderedsetconstiteratora--unorderedsetconstiterator"></a><a name="unordered_set__const_iterator"></a>  unordered_set::const_iterator  
 O tipo de um iterador de constante para a sequência controlada.  
  
```  
typedef T1 const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de encaminhamento constante para a sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T1`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_const_iterator.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
[c] [b] [a]  
```  
  
##  <a name="a-nameunorderedsetconstlocaliteratora--unorderedsetconstlocaliterator"></a><a name="unordered_set__const_local_iterator"></a>  unordered_set::const_local_iterator  
 O tipo de um iterador de bucket de constante para a sequência controlada.  
  
```  
typedef T5 const_local_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de encaminhamento constante para um bucket. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T5`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_const_local_iterator.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect bucket containing 'a'  
Myset::const_local_iterator lit = c1.begin(c1.bucket('a'));  
std::cout << " [" << *lit << "]";  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
[a]  
  
```  
  
##  <a name="a-nameunorderedsetconstpointera--unorderedsetconstpointer"></a><a name="unordered_set__const_pointer"></a>  unordered_set::const_pointer  
 O tipo de um ponteiro de constante para um elemento.  
  
```  
typedef Alloc::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um ponteiro constante para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_const_pointer.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::iterator it = c1.begin();  
it != c1.end(); ++it)  
{  
Myset::const_pointer p = &*it;  
std::cout << " [" << *p << "]";  
}  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
[c] [b] [a]  
```  
  
##  <a name="a-nameunorderedsetconstreferencea--unorderedsetconstreference"></a><a name="unordered_set__const_reference"></a>  unordered_set::const_reference  
 O tipo de uma referência de constante para um elemento.  
  
```  
typedef Alloc::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como uma referência constante para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_const_reference.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::iterator it = c1.begin();  
it != c1.end(); ++it)  
{  
Myset::const_reference ref = *it;  
std::cout << " [" << ref << "]";  
}  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
[c] [b] [a]  
```  
  
##  <a name="a-nameunorderedsetcounta--unorderedsetcount"></a><a name="unordered_set__count"></a>  unordered_set::count  
 Localiza o número de elementos que correspondem a uma chave especificada.  
  
```  
size_type count(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número de elementos no intervalo delimitado por[unordered_set::equal_range](#unordered_set__equal_range)`(keyval)`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_count.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
std::cout << "count('A') == " << c1.count('A') << std::endl;  
std::cout << "count('b') == " << c1.count('b') << std::endl;  
std::cout << "count('C') == " << c1.count('C') << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
count('A') == 0  
count('b') == 1  
count('C') == 0  
```  
  
##  <a name="a-nameunorderedsetdifferencetypea--unorderedsetdifferencetype"></a><a name="unordered_set__difference_type"></a>  unordered_set::difference_type  
 O tipo de uma distância com sinal entre dois elementos.  
  
```  
typedef T3 difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro com sinal descreve um objeto que pode representar a diferença entre os endereços de dois elementos quaisquer na sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T3`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_difference_type.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// compute positive difference  
Myset::difference_type diff = 0;  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
++diff;  
std::cout << "end()-begin() == " << diff << std::endl;  
  
// compute negative difference  
diff = 0;  
for (Myset::const_iterator it = c1.end();  
it != c1.begin(); --it)  
--diff;  
std::cout << "begin()-end() == " << diff << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
end()-begin() == 3  
begin()-end() == -3  
```  
  
##  <a name="a-nameunorderedsetemplacea--unorderedsetemplace"></a><a name="unordered_set__emplace"></a>  unordered_set::emplace  
 Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada).  
  
```  
 
template <class... Args>  
pair<iterator, bool>  
emplace(
Args&&... args);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`args`|Os argumentos encaminhados para criar um elemento a ser inserido no unordered_set, a menos que ele já contenha um elemento cujo valor seja ordenado de maneira equivalente.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um `pair` cujo componente `bool` retornará verdadeiro se uma inserção já tiver sido feita e falso se `unordered_set` já contivesse um elemento cuja chave tinha um valor equivalente na ordenação e cujo componente do iterador retorna o endereço em que um novo elemento foi inserido ou onde o elemento já estava localizado.  
  
 Para acessar o componente do iterador de um par `pr` retornado por essa função membro, use `pr.first` e, para desreferenciar, use `*(pr.first)`. Para acessar o componente `bool` de um par `pr` retornado por essa função membro, use `pr.second`.  
  
### <a name="remarks"></a>Comentários  
 Nenhum iterador ou referência será invalidada por essa função.  
  
 Durante a inserção, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o contêiner não será modificado. Se a exceção for lançada na função hash, o resultado é indefinido.  
  
 Para obter um exemplo de código, consulte [set::emplace](../standard-library/set-class.md#set__emplace).  
  
##  <a name="a-nameunorderedsetemplacehinta--unorderedsetemplacehint"></a><a name="unordered_set__emplace_hint"></a>  unordered_set::emplace_hint  
 Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada), com uma dica de posicionamento.  
  
```  
 
template <class... Args>  
iterator emplace_hint(
const_iteratorwhere,  
Args&&... args);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`args`|Os argumentos encaminhados para criar um elemento a ser inserido no unordered_set, a menos que o unordered_set já contenha esse elemento ou, de modo geral, que ele já contenha um elemento cuja chave seja ordenada de maneira equivalente.|  
|`where`|Uma dica relacionada ao local do qual se começa a procurar pelo ponto de inserção correto.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o elemento recém-inserido.  
  
 Se a inserção tiver falhado porque o elemento já existe, ele retornará um iterador para o elemento existente.  
  
### <a name="remarks"></a>Comentários  
 Nenhum iterador ou referência será invalidada por essa função.  
  
 Durante a inserção, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o contêiner não será modificado. Se a exceção for lançada na função hash, o resultado é indefinido.  
  
 Para obter um exemplo de código, consulte[set::emplace_hint](../standard-library/set-class.md#set__emplace_hint).  
  
##  <a name="a-nameunorderedsetemptya--unorderedsetempty"></a><a name="unordered_set__empty"></a>  unordered_set::empty  
 Testa se nenhum elemento está presente.  
  
```  
bool empty() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna verdadeiro para uma sequência controlada vazia.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_empty.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// clear the container and reinspect  
c1.clear();  
std::cout << "size == " << c1.size() << std::endl;  
std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;  
std::cout << std::endl;  
  
c1.insert('d');  
c1.insert('e');  
  
// display contents " [e] [d]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
std::cout << "size == " << c1.size() << std::endl;  
std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
size == 0  
empty() == true  
  
[e] [d]  
size == 2  
empty() == false  
```  
  
##  <a name="a-nameunorderedsetenda--unorderedsetend"></a><a name="unordered_set__end"></a>  unordered_set::end  
 Designa o fim da sequência controlada.  
  
```  
 
iterator end();

const_iterator end() const;

 
local_iterator end(size_type nbucket);

const_local_iterator end(size_type nbucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`nbucket`|O número de bucket.|  
  
### <a name="remarks"></a>Comentários  
 As duas primeiras funções membro retornam um iterador de encaminhamento que aponta para logo além do fim da sequência. As duas últimas funções membro retornam um iterador de encaminhamento que aponta para logo além do fim do bucket `nbucket`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_set__unordered_set_end.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect last two items " [a] [b]"  
Myset::iterator it2 = c1.end();  
--it2;  
std::cout << " [" << *it2 << "]";  
--it2;  
std::cout << " [" << *it2 << "]";  
std::cout << std::endl;  
  
// inspect bucket containing 'a'  
Myset::const_local_iterator lit = c1.end(c1.bucket('a'));  
--lit;  
std::cout << " [" << *lit << "]";  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
[a] [b]  
[a]  
  
```  
  
##  <a name="a-nameunorderedsetequalrangea--unorderedsetequalrange"></a><a name="unordered_set__equal_range"></a>  unordered_set::equal_range  
 Localiza o intervalo que corresponde a uma chave especificada.  
  
```  
 
std::pair<iterator, iterator>  
equal_range(const Key& keyval);

std::pair<const_iterator, const_iterator>  
equal_range(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um par de iteradores `X` que `[X.first, X.second)` delimitam apenas os elementos da sequência controlada que tenha ordem equivalente com `keyval`. Se esses elementos não existirem, ambos os iteradores são `end()`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_equal_range.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// display results of failed search  
std::pair<Myset::iterator, Myset::iterator> pair1 =  
c1.equal_range('x');  
std::cout << "equal_range('x'):";  
for (; pair1.first != pair1.second; ++pair1.first)  
std::cout << " [" << *pair1.first << "]";  
std::cout << std::endl;  
  
// display results of successful search  
pair1 = c1.equal_range('b');  
std::cout << "equal_range('b'):";  
for (; pair1.first != pair1.second; ++pair1.first)  
std::cout << " [" << *pair1.first << "]";  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
equal_range('x'):  
equal_range('b'): [b]  
  
```  
  
##  <a name="a-nameunorderedseterasea--unorderedseterase"></a><a name="unordered_set__erase"></a>  unordered_set::erase  
 Remove um elemento ou um intervalo de elementos em um unordered_set das posições especificadas ou remove elementos que correspondem a uma chave especificada.  
  
```  
 
iterator erase(const_iteratorWhere);

iterator erase(
const_iteratorFirst, const_iteratorLast);

size_type erase(
const key_type& Key);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Where`  
 A posição do elemento a ser removido.  
  
 `First`  
 A posição do primeiro elemento a ser removido.  
  
 `Last`  
 A posição logo após o último elemento a ser removido.  
  
 `Key`  
 O valor de chave dos elementos a serem removidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou um elemento que será o final do unordered_set, se esse elemento não existir.  
  
 Para a terceira função membro, ele retorna o número de elementos que foram removidos do unordered_set.  
  
### <a name="remarks"></a>Comentários  
 Para obter um exemplo de código, consulte [set::erase](../standard-library/set-class.md#set__erase).  
  
##  <a name="a-nameunorderedsetfinda--unorderedsetfind"></a><a name="unordered_set__find"></a>  unordered_set::find  
 Localiza um elemento que corresponde a uma chave especificada.  
  
```  
const_iterator find(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna[unordered_set::equal_range](#unordered_set__equal_range)`(keyval).first`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_find.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// try to find and fail  
std::cout << "find('A') == "  
<< std::boolalpha << (c1.find('A') != c1.end()) << std::endl;  
  
// try to find and succeed  
Myset::iterator it = c1.find('b');  
std::cout << "find('b') == "  
<< std::boolalpha << (it != c1.end())  
<< ": [" << *it << "]" << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
find('A') == false  
find('b') == true: [b]  
  
```  
  
##  <a name="a-nameunorderedsetgetallocatora--unorderedsetgetallocator"></a><a name="unordered_set__get_allocator"></a>  unordered_set::get_allocator  
 Obtém o objeto de alocador armazenado.  
  
```  
Alloc get_allocator() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o objeto alocador armazenado.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_get_allocator.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
typedef std::allocator<std::pair<const char, int> > Myalloc;  
int main()  
{  
Myset c1;  
  
Myset::allocator_type al = c1.get_allocator();  
std::cout << "al == std::allocator() is "  
<< std::boolalpha << (al == Myalloc()) << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
al == std::allocator() is true  
```  
  
##  <a name="a-nameunorderedsethashfunctiona--unorderedsethashfunction"></a><a name="unordered_set__hash_function"></a>  unordered_set::hash_function  
 Obtém o objeto armazenado da função de hash.  
  
```  
Hash hash_function() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o objeto da função hash armazenado.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_hash_function.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
Myset::hasher hfn = c1.hash_function();  
std::cout << "hfn('a') == " << hfn('a') << std::endl;  
std::cout << "hfn('b') == " << hfn('b') << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
hfn('a') == 1630279  
hfn('b') == 1647086  
```  
  
##  <a name="a-nameunorderedsethashera--unorderedsethasher"></a><a name="unordered_set__hasher"></a>  unordered_set::hasher  
 O tipo de função de hash.  
  
```  
typedef Hash hasher;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo`Hash`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_hasher.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
Myset::hasher hfn = c1.hash_function();  
std::cout << "hfn('a') == " << hfn('a') << std::endl;  
std::cout << "hfn('b') == " << hfn('b') << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
hfn('a') == 1630279  
hfn('b') == 1647086  
```  
  
##  <a name="a-nameunorderedsetinserta--unorderedsetinsert"></a><a name="unordered_set__insert"></a>  unordered_set::insert  
 Insere um elemento ou um intervalo de elementos em um unordered_set.  
  
```  
 
// (1) single element  
pair<iterator, bool> insert(
const value_type& Val);

 
// (2) single element, perfect forwarded  
template <class ValTy>  
pair<iterator, bool>  
insert(
ValTy&& Val);

 
// (3) single element with hint  
iterator insert(
const_iterator Where,  
const value_type& Val);

 
// (4) single element, perfect forwarded, with hint  
template <class ValTy>  
iterator insert(
const_iterator Where,  
ValTy&& Val);

 
// (5) range  
template <class InputIterator>  
void insert(
InputIterator First,  
InputIterator Last);

 
// (6) initializer list  
void insert(
initializer_list<value_type>  
IList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Val`|O valor de um elemento a ser inserido no unordered_set, a menos que ele já contenha um elemento cuja chave seja ordenada de maneira equivalente.|  
|`Where`|O local a partir do qual se começa a procurar pelo ponto de inserção correto.|  
|`ValTy`|O parâmetro de modelo que especifica o tipo de argumento que o unordered_set pode usar para construir um elemento de [value_type](../standard-library/map-class.md#map__value_type) e aperfeiçoar/encaminhar `Val` como argumento.|  
|`First`|A posição do primeiro elemento a ser copiado.|  
|`Last`|A posição imediatamente após o último elemento a ser copiado.|  
|`InputIterator`|Argumento da função de modelo que atende aos requisitos de um [iterador de entrada](../standard-library/input-iterator-tag-struct.md) que aponta para elementos de um tipo que pode ser usado para construir objetos [value_type](../standard-library/map-class.md#map__value_type).|  
|`IList`|A [initializer_list](../standard-library/initializer-list.md) da qual os elementos serão copiados.|  
  
### <a name="return-value"></a>Valor de retorno  
 As funções membro de elemento único, (1) e (2), retornam um [par](../standard-library/pair-structure.md) cujo `bool` componente é verdadeiro se uma inserção tiver sido feita e falso se o unordered_set já contiver um elemento cuja chave possua um valor equivalente na ordenação. O componente do iterador do par de valores retornados apontará para o elemento recém-inserido, se o componente `bool` for verdadeiro ou para o elemento existente, se o componente `bool` for falso.  
  
 As funções do membro de elemento único com dica, (3) e (4), retornam um iterador que aponta para a posição em que o novo elemento foi inserido no unordered_set ou, se um elemento com uma chave equivalente já existir, para o elemento existente.  
  
### <a name="remarks"></a>Comentários  
 Nenhum iterador, ponteiro ou referência é invalidado por essa função.  
  
 Durante a inserção de apenas um elemento, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o estado do contêiner não é modificado. Se a exceção for lançada na função hash, o resultado é indefinido. Durante a inserção de vários elementos, se uma exceção for lançada, o contêiner será deixado em um estado não especificado, mas válido.  
  
 Para acessar o componente do iterador de um `pair``pr` que é retornado pelas funções membro de elemento único, consulte `pr.first`; para desreferenciar o iterador dentro do par retornado, use `*pr.first`, que oferece um elemento. Para acessar o componente `bool`, use `pr.second`. Para obter um exemplo, consulte o código de amostra mais adiante neste artigo.  
  
 O [value_type](../standard-library/map-class.md#map__value_type) de um contêiner é um typedef que pertence ao contêiner e, para o conjunto, `unordered_set<V>::value_type` é do tipo `const V`.  
  
 A função membro de intervalo (5) insere a sequência de valores de elemento em um unordered_set que corresponde a cada elemento tratado por um iterador no intervalo `[First, Last)`; portanto, `Last` não é inserido. A função membro do contêiner `end()` faz referência à posição imediatamente após o último elemento no contêiner; por exemplo, a instrução `s.insert(v.begin(), v.end());` tenta inserir todos os elementos de `v` em `s`. Apenas elementos com valores únicos no intervalo são inseridos; as duplicatas são ignoradas. Para observar quais elementos são rejeitados, use as versões de elemento único de `insert`.  
  
 A função membro da lista do inicializador (6) usa um [initializer_list](../standard-library/initializer-list.md) para copiar elementos em um unordered_set.  
  
 Para inserir um elemento criado no local, ou seja, sem a realização de operações de cópia ou movimentação, consulte [set::emplace](../standard-library/set-class.md#set__emplace) e[set::emplace_hint](../standard-library/set-class.md#set__emplace_hint).  
  
 Para obter um exemplo de código, consulte [set::insert](../standard-library/set-class.md#set__insert).  
  
##  <a name="a-nameunorderedsetiteratora--unorderedsetiterator"></a><a name="unordered_set__iterator"></a>  unordered_set::iterator  
 Um tipo que fornece uma constante [iterador de avanço](../standard-library/forward-iterator-tag-struct.md) que pode ler os elementos em um unordered_set.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [begin](../standard-library/set-class.md#set__begin) para obter um exemplo de como declarar e usar um **iterador**.  
  
##  <a name="a-nameunorderedsetkeyeqa--unorderedsetkeyeq"></a><a name="unordered_set__key_eq"></a>  unordered_set::key_eq  
 Obtém o objeto armazenado da função de comparação.  
  
```  
Pred key_eq() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o objeto da função de comparação armazenado.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_key_eq.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
Myset::key_equal cmpfn = c1.key_eq();  
std::cout << "cmpfn('a', 'a') == "  
<< std::boolalpha << cmpfn('a', 'a') << std::endl;  
std::cout << "cmpfn('a', 'b') == "  
<< std::boolalpha << cmpfn('a', 'b') << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
cmpfn('a', 'a') == true  
cmpfn('a', 'b') == false  
```  
  
##  <a name="a-nameunorderedsetkeyequala--unorderedsetkeyequal"></a><a name="unordered_set__key_equal"></a>  unordered_set::key_equal  
 O tipo da função de comparação.  
  
```  
typedef Pred key_equal;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo`Pred`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_key_equal.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
Myset::key_equal cmpfn = c1.key_eq();  
std::cout << "cmpfn('a', 'a') == "  
<< std::boolalpha << cmpfn('a', 'a') << std::endl;  
std::cout << "cmpfn('a', 'b') == "  
<< std::boolalpha << cmpfn('a', 'b') << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
cmpfn('a', 'a') == true  
cmpfn('a', 'b') == false  
```  
  
##  <a name="a-nameunorderedsetkeytypea--unorderedsetkeytype"></a><a name="unordered_set__key_type"></a>  unordered_set::key_type  
 O tipo de uma chave de classificação.  
  
```  
typedef Key key_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo`Key`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_key_type.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// add a value and reinspect  
Myset::key_type key = 'd';  
Myset::value_type val = key;  
c1.insert(val);  
  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
[d] [c] [b] [a]  
  
```  
  
##  <a name="a-nameunorderedsetloadfactora--unorderedsetloadfactor"></a><a name="unordered_set__load_factor"></a>  unordered_set::load_factor  
 Conta a média de elementos por bucket.  
  
```  
float load_factor() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna `(float)`[unordered_set::size](#unordered_set__size)`() / (float)`[unordered_set::bucket_count](#unordered_set__bucket_count)`()`, o número médio de elementos por bucket.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_load_factor.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect current parameters  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// change max_load_factor and redisplay  
c1.max_load_factor(0.10f);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// rehash and redisplay  
c1.rehash(100);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_bucket_count() == 128  
max_load_factor() == 0.1  
```  
  
##  <a name="a-nameunorderedsetlocaliteratora--unorderedsetlocaliterator"></a><a name="unordered_set__local_iterator"></a>  unordered_set::local_iterator  
 O tipo de um iterador de bucket.  
  
```  
typedef T4 local_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de encaminhamento para um bucket. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T4`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_local_iterator.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect bucket containing 'a'  
Myset::local_iterator lit = c1.begin(c1.bucket('a'));  
std::cout << " [" << *lit << "]";  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
[a]  
  
```  
  
##  <a name="a-nameunorderedsetmaxbucketcounta--unorderedsetmaxbucketcount"></a><a name="unordered_set__max_bucket_count"></a>  unordered_set::max_bucket_count  
 Obtém o número máximo de buckets.  
  
```  
size_type max_bucket_count() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número máximo de buckets permitidos no momento.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_max_bucket_count.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect current parameters  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// change max_load_factor and redisplay  
c1.max_load_factor(0.10f);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// rehash and redisplay  
c1.rehash(100);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_bucket_count() == 128  
max_load_factor() == 0.1  
```  
  
##  <a name="a-nameunorderedsetmaxloadfactora--unorderedsetmaxloadfactor"></a><a name="unordered_set__max_load_factor"></a>  unordered_set::max_load_factor  
 Obtém ou define o máximo de elementos por bucket.  
  
```  
 
float max_load_factor() const;

 
void max_load_factor(float factor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `factor`  
 O novo fator de carga máxima.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna o fator de carga máxima armazenado. A segunda função membro substitui o fator de carga máxima armazenado com `factor`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_max_load_factor.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect current parameters  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// change max_load_factor and redisplay  
c1.max_load_factor(0.10f);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// rehash and redisplay  
c1.rehash(100);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_bucket_count() == "  
<< c1.max_bucket_count() << std::endl;  
std::cout << "max_load_factor() == "  
<< c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_bucket_count() == 128  
max_load_factor() == 0.1  
```  
  
##  <a name="a-nameunorderedsetmaxsizea--unorderedsetmaxsize"></a><a name="unordered_set__max_size"></a>  unordered_set::max_size  
 Obtém o tamanho máximo da sequência controlada.  
  
```  
size_type max_size() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência mais longa que o objeto pode controlar.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_max_size.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
std::cout << "max_size() == " << c1.max_size() << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
max_size() == 4294967295  
```  
  
##  <a name="a-nameunorderedsetoperatoreqa--unorderedsetoperator"></a><a name="unordered_set__operator_eq"></a>  unordered_set::operator=  
 Copia uma tabela de hash.  
  
```  
 
unordered_set& operator=(const unordered_set& right);

unordered_set& operator=(unordered_set&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` right`|O [unordered_set](../standard-library/unordered-set-class.md) que está sendo copiado para o `unordered_set`.|  
  
### <a name="remarks"></a>Comentários  
 Após apagar os elementos existentes em um `unordered_set`, `operator=` copiará ou moverá o conteúdo de ` right` para `unordered_set`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// unordered_set_operator_as.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
int main( )  
{  
using namespace std;  
unordered_set<int> v1, v2, v3;  
unordered_set<int>::iterator iter;  
  
v1.insert(10);  
  
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
  
##  <a name="a-nameunorderedsetpointera--unorderedsetpointer"></a><a name="unordered_set__pointer"></a>  unordered_set::pointer  
 O tipo de um ponteiro para um elemento.  
  
```  
typedef Alloc::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um ponteiro para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_pointer.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::iterator it = c1.begin();  
it != c1.end(); ++it)  
{  
Myset::key_type key = *it;  
Myset::pointer p = &key;  
std::cout << " [" << *p << "]";  
}  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
[c] [b] [a]  
```  
  
##  <a name="a-nameunorderedsetreferencea--unorderedsetreference"></a><a name="unordered_set__reference"></a>  unordered_set::reference  
 O tipo de uma referência para um elemento.  
  
```  
typedef Alloc::reference reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como uma referência para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_reference.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::iterator it = c1.begin();  
it != c1.end(); ++it)  
{  
Myset::key_type key = *it;  
Myset::reference ref = key;  
std::cout << " [" << ref << "]";  
}  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
[c] [b] [a]  
```  
  
##  <a name="a-nameunorderedsetrehasha--unorderedsetrehash"></a><a name="unordered_set__rehash"></a>  unordered_set::rehash  
 Recria a tabela de hash.  
  
```  
void rehash(size_type nbuckets);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nbuckets`  
 O número solicitado de buckets.  
  
### <a name="remarks"></a>Comentários  
 A função membro altera o número de buckets para que seja pelo menos `nbuckets` e recria a tabela de hash, conforme necessário.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_rehash.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// inspect current parameters  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_load_factor() == " << c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// change max_load_factor and redisplay  
c1.max_load_factor(0.10f);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_load_factor() == " << c1.max_load_factor() << std::endl;  
std::cout << std::endl;  
  
// rehash and redisplay  
c1.rehash(100);  
std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;  
std::cout << "load_factor() == " << c1.load_factor() << std::endl;  
std::cout << "max_load_factor() == " << c1.max_load_factor() << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
bucket_count() == 8  
load_factor() == 0.375  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_load_factor() == 0.1  
```  
  
##  <a name="a-nameunorderedsetsizea--unorderedsetsize"></a><a name="unordered_set__size"></a>  unordered_set::size  
 Conta o número de elementos.  
  
```  
size_type size() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_size.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// clear the container and reinspect  
c1.clear();  
std::cout << "size == " << c1.size() << std::endl;  
std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;  
std::cout << std::endl;  
  
c1.insert('d');  
c1.insert('e');  
  
// display contents " [e] [d]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
std::cout << "size == " << c1.size() << std::endl;  
std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
size == 0  
empty() == true  
  
[e] [d]  
size == 2  
empty() == false  
```  
  
##  <a name="a-nameunorderedsetsizetypea--unorderedsetsizetype"></a><a name="unordered_set__size_type"></a>  unordered_set::size_type  
 O tipo de uma distância sem sinal entre dois elementos.  
  
```  
typedef T2 size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro sem sinal descreve um objeto que pode representar o tamanho de qualquer sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T2`.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_size_type.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
Myset::size_type sz = c1.size();  
  
std::cout << "size == " << sz << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
size == 0  
```  
  
##  <a name="a-nameunorderedsetswapa--unorderedsetswap"></a><a name="unordered_set__swap"></a>  unordered_set::swap  
 Alterna o conteúdo de dois contêineres.  
  
```  
void swap(unordered_set& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O contêiner para alternância.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca as sequências controladas entre `*this` e `right`. Se [unordered_set::get_allocator](#unordered_set__get_allocator)`() == right.get_allocator()`, ele faz isso em tempo constante, ele gerará uma exceção apenas como resultado de copiar o objeto armazenado do tipo `Tr` e invalida sem referências, ponteiros ou iteradores que designam elementos em duas sequências de controlado. Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_swap.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
Myset c2;  
  
c2.insert('d');  
c2.insert('e');  
c2.insert('f');  
  
c1.swap(c2);  
  
// display contents " [f] [e] [d]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
swap(c1, c2);  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
[f] [e] [d]  
[c] [b] [a]  
  
```  
  
##  <a name="a-nameunorderedsetunorderedseta--unorderedsetunorderedset"></a><a name="unordered_set__unordered_set"></a>  unordered_set::unordered_set  
 Constrói um objeto contêiner.  
  
```  
 
unordered_set(
const unordered_set& Right);

explicit unordered_set(
size_typebucket_count = N0,  
const Hash& Hash = Hash(),  
const Comp& Comp = Comp(),  
const Allocator& Al = Alloc());

unordered_set(
unordered_set&& Right);

unordered_set(
initializer_list<Type> IList);

unordered_set(
initializer_list<Type> IList, size_typebucket_count);

unordered_set(
initializer_list<Type> IList,  
size_typebucket_count,  
const Hash& Hash);

unordered_set(
initializer_list<Type> IList,  
size_typebucket_count,  
const Hash& Hash,  
const Comp& Comp);

unordered_set(
initializer_list<Type> IList,  
size_typebucket_count,  
const Hash& Hash,  
const Comp& Comp,  
const Allocator& Al);

template <class InputIterator>  
unordered_set(
InputIteratorfirst,  
InputIteratorlast,  
size_typebucket_count = N0,  
const Hash& Hash = Hash(),  
const Comp& Comp = Comp(),  
const Allocator& Al = Alloc());
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`InputIterator`|O tipo de iterador.|  
|`Al`|O objeto de alocador a ser armazenado.|  
|`Comp`|O objeto de função de comparação a ser armazenado.|  
|`Hash`|O objeto de função de hash a ser armazenado.|  
|`bucket_count`|O número mínimo de buckets.|  
|`Right`|O contêiner a ser copiado.|  
|`IList`|A initializer_list que contém os elementos a serem copiados.|  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor especifica uma cópia da sequência controlada por `Right`. O segundo construtor especifica uma sequência controlada vazia. O terceiro construtor especifica uma cópia da sequência movendo`Right` O quarto construtor até o oitavo usam um initializer_list para especificar elementos a serem copiados. O nono construtor insere a sequência dos valores `[first, last)` do elemento.  
  
 Todos os construtores também inicializam vários valores armazenados. Para o construtor de cópia, os valores são obtidos de `Right`. Caso contrário:  
  
 O número mínimo de buckets será o argumento `bucket_count`, se ele estiver presente. Caso contrário, o mínimo é um valor padrão descrito aqui como valor `N0` definido na implementação.  
  
 O objeto de função de hash será o argumento `Hash`, se ele estiver presente. Caso contrário, o objeto é `Hash()`.  
  
 O objeto de função de comparação será o argumento `Comp`, se estiver presente; caso contrário, será `Comp()`.  
  
 O objeto de alocador será o argumento `Al`, se estiver presente; caso contrário, será `Alloc()`.  
  
##  <a name="a-nameunorderedsetvaluetypea--unorderedsetvaluetype"></a><a name="unordered_set__value_type"></a>  unordered_set::value_type  
 O tipo de um elemento.  
  
```  
typedef Key value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  Â  
  
```  
  
// std__unordered_set__unordered_set_value_type.cpp  
// compile with: /EHsc  
#include <unordered_set>  
#include <iostream>  
  
typedef std::unordered_set<char> Myset;  
int main()  
{  
Myset c1;  
  
c1.insert('a');  
c1.insert('b');  
c1.insert('c');  
  
// display contents " [c] [b] [a]"  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
// add a value and reinspect  
Myset::key_type key = 'd';  
Myset::value_type val = key;  
c1.insert(val);  
  
for (Myset::const_iterator it = c1.begin();  
it != c1.end(); ++it)  
std::cout << " [" << *it << "]";  
std::cout << std::endl;  
  
return (0);  
}  
  
```  
  
```Output  
  
[c] [b] [a]  
[d] [c] [b] [a]  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [<unordered_set>](../standard-library/unordered-set.md)   
 [Contêineres](../cpp/containers-modern-cpp.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)


