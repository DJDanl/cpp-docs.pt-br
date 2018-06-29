---
title: hash_multimap (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_multimap
- cliext::hash_multimap::begin
- cliext::hash_multimap::bucket_count
- cliext::hash_multimap::clear
- cliext::hash_multimap::const_iterator
- cliext::hash_multimap::const_reference
- cliext::hash_multimap::const_reverse_iterator
- cliext::hash_multimap::count
- cliext::hash_multimap::difference_type
- cliext::hash_multimap::empty
- cliext::hash_multimap::end
- cliext::hash_multimap::equal_range
- cliext::hash_multimap::erase
- cliext::hash_multimap::find
- cliext::hash_multimap::generic_container
- cliext::hash_multimap::generic_iterator
- cliext::hash_multimap::generic_reverse_iterator
- cliext::hash_multimap::generic_value
- cliext::hash_multimap::hash_delegate
- cliext::hash_multimap::hash_multimap
- cliext::hash_multimap::hasher
- cliext::hash_multimap::insert
- cliext::hash_multimap::iterator
- cliext::hash_multimap::key_comp
- cliext::hash_multimap::key_compare
- cliext::hash_multimap::key_type
- cliext::hash_multimap::load_factor
- cliext::hash_multimap::lower_bound
- cliext::hash_multimap::make_value
- cliext::hash_multimap::mapped_type
- cliext::hash_multimap::max_load_factor
- cliext::hash_multimap::operator=
- cliext::hash_multimap::rbegin
- cliext::hash_multimap::reference
- cliext::hash_multimap::rehash
- cliext::hash_multimap::rend
- cliext::hash_multimap::reverse_iterator
- cliext::hash_multimap::size
- cliext::hash_multimap::size_type
- cliext::hash_multimap::swap
- cliext::hash_multimap::to_array
- cliext::hash_multimap::upper_bound
- cliext::hash_multimap::value_comp
- cliext::hash_multimap::value_compare
- cliext::hash_multimap::value_type
dev_langs:
- C++
helpviewer_keywords:
- hash_multimap class [STL/CLR]
- <cliext/hash_map> header [STL/CLR]
- <hash_map> header [STL/CLR]
- begin member [STL/CLR]
- begin member [STL/CLR]
- bucket_count member [STL/CLR]
- clear member [STL/CLR]
- const_iterator member [STL/CLR]
- const_reference member [STL/CLR]
- const_reverse_iterator member [STL/CLR]
- count member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- end member [STL/CLR]
- equal_range member [STL/CLR]
- erase member [STL/CLR]
- find member [STL/CLR]
- generic_container member [STL/CLR]
- generic_iterator member [STL/CLR]
- generic_reverse_iterator member [STL/CLR]
- generic_value member [STL/CLR]
- hash_delegate member [STL/CLR]
- hash_multimap member [STL/CLR]
- hasher member [STL/CLR]
- insert member [STL/CLR]
- iterator member [STL/CLR]
- key_comp member [STL/CLR]
- key_compare member [STL/CLR]
- key_type member [STL/CLR]
- load_factor member [STL/CLR]
- lower_bound member [STL/CLR]
- make_value member [STL/CLR]
- mapped_type member [STL/CLR]
- max_load_factor member [STL/CLR]
- operator= member [STL/CLR]
- rbegin member [STL/CLR]
- reference member [STL/CLR]
- rehash member [STL/CLR]
- rend member [STL/CLR]
- reverse_iterator member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- swap member [STL/CLR]
- to_array member [STL/CLR]
- upper_bound member [STL/CLR]
- value_comp member [STL/CLR]
- value_compare member [STL/CLR]
- value_type member [STL/CLR]
ms.assetid: cd78687b-8a05-48e0-9d22-8b8194ae3b0b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: d78b03bea823dfcbb9df61fb40681c4ef66b49e7
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37079884"
---
# <a name="hashmultimap-stlclr"></a>hash_multimap (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `hash_multimap` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada da tabela de armazenar um bidirecional vinculado a lista de nós e cada nó de armazenamento de um elemento. Um elemento consiste em uma chave, para ordenar a sequência e um valor mapeado, o que vai ao longo da simultaneamente.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 em que:  
  
 `GKey` é o mesmo que `Key` , a menos que o último é um tipo de referência, caso em que é `Key^`  
  
 `GMapped` é o mesmo que `Mapped` , a menos que o último é um tipo de referência, caso em que é `Mapped^`  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class hash_multimap  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        Microsoft::VisualC::StlClr::IHash<Gkey, GValue>  
    { ..... };  
```  
  
### <a name="parameters"></a>Parâmetros  
 Chave  
 O tipo do componente principal de um elemento na sequência controlada.  
  
 Mapeado  
 O tipo do componente adicional de um elemento na sequência controlada.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_map >  
  
 **Namespace:** cliext  

## <a name="declarations"></a>Declarações  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[hash_multimap::const_iterator (STL/CLR)](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|  
|[hash_multimap::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|  
|[hash_multimap::const_reverse_iterator (STL/CLR)](#const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[hash_multimap::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância (possivelmente assinado) entre dois elementos.|  
|[hash_multimap::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o contêiner.|  
|[hash_multimap::generic_iterator (STL/CLR)](#generic_iterator)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[hash_multimap::generic_reverse_iterator (STL/CLR)](#generic_reverse_iterator)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[hash_multimap::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[hash_multimap::hasher (STL/CLR)](#hasher)|O representante de hash para uma chave.|  
|[hash_multimap::iterator (STL/CLR)](#iterator)|O tipo de um iterador para a sequência controlada.|  
|[hash_multimap::key_compare (STL/CLR)](#key_compare)|O representante de ordenação para duas chaves.|  
|[hash_multimap::key_type (STL/CLR)](#key_type)|O tipo de uma chave de classificação.|  
|[hash_multimap::mapped_type (STL/CLR)](#mapped_type)|O tipo do valor mapeado associado a cada chave.|  
|[hash_multimap::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|  
|[hash_multimap::reverse_iterator (STL/CLR)](#reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|  
|[hash_multimap::size_type (STL/CLR)](#size_type)|O tipo de uma distância (negativo) entre dois elementos.|  
|[hash_multimap::value_compare (STL/CLR)](#value_compare)|O representante de ordenação para dois valores de elemento.|  
|[hash_multimap::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[hash_multimap::begin (STL/CLR)](#begin)|Designa o início da sequência controlada.|  
|[hash_multimap::bucket_count (STL/CLR)](#bucket_count)|Conta o número de buckets.|  
|[hash_multimap::clear (STL/CLR)](#clear)|Remove todos os elementos.|  
|[hash_multimap::count (STL/CLR)](#count)|Contagens de elementos de correspondência de uma chave especificada.|  
|[hash_multimap::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|  
|[hash_multimap::end (STL/CLR)](#end)|Designa o fim da sequência controlada.|  
|[hash_multimap::equal_range (STL/CLR)](#equal_range)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[hash_multimap::erase (STL/CLR)](#erase)|Remove os elementos em posições especificadas.|  
|[hash_multimap::find (STL/CLR)](#find)|Localiza um elemento que corresponde a uma chave especificada.|  
|[hash_multimap::hash_delegate (STL/CLR)](#hash_delegate)|Copia o delegado de hash para uma chave.|  
|[hash_multimap::hash_multimap (STL/CLR)](#hash_multimap)|Constrói um objeto contêiner.|  
|[hash_multimap::insert (STL/CLR)](#insert)|Adiciona elementos.|  
|[hash_multimap::key_comp (STL/CLR)](#key_comp)|Copia o delegado de ordenação de duas chaves.|  
|[hash_multimap::load_factor (STL/CLR)](#load_factor)|Conta a média de elementos por bucket.|  
|[hash_multimap::lower_bound (STL/CLR)](#lower_bound)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[hash_multimap::make_value (STL/CLR)](#make_value)|Constrói um objeto de valor.|  
|[hash_multimap::max_load_factor (STL/CLR)](#max_load_factor)|Obtém ou define o máximo de elementos por bucket.|  
|[hash_multimap::rbegin (STL/CLR)](#rbegin)|Designa o início da sequência controlada invertida.|  
|[hash_multimap::rehash (STL/CLR)](#rehash)|Recria a tabela de hash.|  
|[hash_multimap::rend (STL/CLR)](#rend)|Designa o fim da sequência controlada invertida.|  
|[hash_multimap::size (STL/CLR)](#size)|Conta o número de elementos.|  
|[hash_multimap::swap (STL/CLR)](#swap)|Alterna o conteúdo de dois contêineres.|  
|[hash_multimap::to_array (STL/CLR)](#to_array)|Copia uma nova matriz sequência controlada.|  
|[hash_multimap::upper_bound (STL/CLR)](#upper_bound)|Localiza o final do intervalo que corresponde a uma chave especificada.|  
|[hash_multimap::value_comp (STL/CLR)](#value_comp)|Copia o delegado de ordenação de dois valores de elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[hash_multimap::operator= (STL/CLR)](#op)|Substitui a sequência controlada.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|IHash\<chave, valor >|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência em que ele controla como nós individuais em uma lista vinculada bidirecional. Para agilizar o acesso, o objeto também mantém uma matriz de comprimento variável de ponteiros na lista (a tabela de hash), gerenciar com eficiência a lista inteira como uma sequência de sublistas, ou buckets. Ele insere elementos em uma partição que mantém ordenada alterando os links entre nós nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente, sem prejudicar elementos restantes.  
  
 O objeto classifica cada bucket controla chamando um objeto de representante armazenado do tipo [hash_set:: key_compare (STL/CLR)](../dotnet/hash-set-key-compare-stl-clr.md). Você pode especificar o objeto do representante armazenado quando você construir o hash_set; Se você não especificar nenhum objeto do representante, o padrão é a comparação `operator<=(key_type, key_type)`.  
  
 Acessar o objeto do representante armazenado chamando a função de membro [hash_set:: key_comp (STL/CLR)](../dotnet/hash-set-key-comp-stl-clr.md)`()`. Esse é um objeto de representante deve definir equivalente a ordem entre as chaves do tipo [hash_set:: key_type (STL/CLR)](../dotnet/hash-set-key-type-stl-clr.md). Isso significa que, para qualquer duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` Retorna o mesmo Boolean resultar em cada chamada.  
  
 Se `key_comp()(X, Y) && key_comp()(Y, X)` for true, em seguida, `X` e `Y` são deve ter ordenação equivalente.  
  
 Qualquer regra de ordenação que se comporta como `operator<=(key_type, key_type)`, `operator>=(key_type, key_type)` ou `operator==(key_type, key_type)` define eqivalent ordenação.  
  
 Observe que o contêiner somente garante que elementos cujas chaves tem ordenação equivalente (e o hash para o mesmo valor de inteiro) são adjacentes em um bucket. Ao contrário de classe de modelo [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md), um objeto da classe de modelo `hash_multimap` não requer que as chaves para todos os elementos sejam exclusivas. (Duas ou mais teclas podem ter ordenação equivalente).  
  
 O objeto determina quais bucket deve conter uma determinada chave de ordenação chamando um objeto de representante armazenado do tipo [hash_set::hasher (STL/CLR)](../dotnet/hash-set-hasher-stl-clr.md). Acessar esse objeto armazenado chamando a função de membro [hash_set::hash_delegate (STL/CLR)](../dotnet/hash-set-hash-delegate-stl-clr.md) `()` para obter um valor inteiro que depende do valor de chave. Você pode especificar o objeto do representante armazenado quando você construir o hash_set; Se você não especificar nenhum objeto do representante, o padrão é a função `System::Object::hash_value(key_type)`. Isso significa que, para todas as chaves `X` e `Y`:  
  
 `hash_delegate()(X)` Retorna o mesmo resultado de inteiro em cada chamada.  
  
 Se `X` e `Y` ter ordenação equivalente, em seguida, `hash_delegate()(X)` deve retornar o mesmo resultado de inteiro de `hash_delegate()(Y)`.  
  
 Cada elemento contém uma chave e um valor mapeado. A sequência é representada de forma que permite a remoção de um elemento arbitrário com um número de operações que é independente do número de elementos na sequência (tempo constante)-- pelo menos no melhor dos casos, pesquisa e inserção. Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
 No entanto, se os valores de hash não são distribuídos uniformemente, uma tabela de hash pode deteriorar. Extremo – para uma função de hash que sempre retorna o mesmo valor – pesquisa, inserção e remoção são proporcionais ao número de elementos na sequência (tempo linear). O contêiner endeavors escolher uma função de hash razoável, o tamanho médio do bucket e tamanho da tabela de hash (número total de buckets), mas você pode substituir uma ou todas essas opções. Veja, por exemplo, as funções [hash_set::max_load_factor (STL/CLR)](../dotnet/hash-set-max-load-factor-stl-clr.md) e [hash_set::rehash (STL/CLR)](../dotnet/hash-set-rehash-stl-clr.md).  
  
 Um hash_multimap suporta iteradores bidirecional, o que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [hash_multimap:: end (STL/CLR)](../dotnet/hash-multimap-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador hash_multimap para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento hash_multimap diretamente considerando sua posição numérica - que requer um iterador de acesso aleatório.  
  
 Um iterador hash_multimap armazena um identificador para o nó hash_multimap associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador hash_multimap permanece válido desde que o nó hash_multimap associado seja associado a alguns hash_multimap. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  

## <a name="members"></a>Membros

## <a name="begin"></a> hash_multimap:: Begin (STL/CLR)
Designa o início da sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator begin();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador bidirecional que designa o primeiro elemento da sequência controlada ou logo após o fim de uma sequência vazia. Você pode usá-lo para obter um iterador que designa o `current` pode alterá-início da sequência controlada, mas seu status se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_begin.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect first two items   
    Myhash_multimap::iterator it = c1.begin();   
    System::Console::WriteLine("*begin() = [{0} {1}]",   
        it->first, it->second);   
    ++it;   
    System::Console::WriteLine("*++begin() = [{0} {1}]",   
        it->first, it->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
*begin() = [a 1]  
*++begin() = [b 2]  
```  

## <a name="bucket_count"></a> hash_multimap::bucket_count (STL/CLR)
Conta o número de buckets.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
int bucket_count();  
```  
  
### <a name="remarks"></a>Comentários  
 As funções de membro retorna o número atual de recipientes. Você pode usá-lo para determinar o tamanho da tabela de hash.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_bucket_count.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1 = gcnew Myhash_multimap;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect current parameters   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.25f);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// rehash and redisplay   
    c1.rehash(100);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 4  
  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 0.25  
  
bucket_count() = 128  
load_factor() = 0.0234375  
max_load_factor() = 0.25  
```  

## <a name="clear"></a> hash_multimap:: Clear (STL/CLR)
Remove todos os elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void clear();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro efetivamente chama [hash_multimap:: Erase (STL/CLR)](../dotnet/hash-multimap-erase-stl-clr.md) `(` [hash_multimap:: Begin (STL/CLR)](../dotnet/hash-multimap-begin-stl-clr.md) `(),` [hash_multimap:: end (STL/CLR) ](../dotnet/hash-multimap-end-stl-clr.md)`())`. Você pode usá-lo para garantir que a sequência controlada está vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_clear.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
  
// display contents " [a 1] [b 2]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    c1.clear();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
size() = 0  
 [a 1] [b 2]  
size() = 0  
```  

## <a name="const_iterator"></a> hash_multimap:: const_iterator (STL/CLR)
O tipo de um iterador de constante para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T2 const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T2` que pode servir como um iterador de constante bidirecional para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_const_iterator.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    Myhash_multimap::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        System::Console::Write(" [{0} {1}]", cit->first, cit->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
```  

## <a name="const_reference"></a> hash_multimap:: const_reference (STL/CLR)
O tipo de uma referência de constante para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef value_type% const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência constante a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_const_reference.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    Myhash_multimap::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        {   // get a const reference to an element   
        Myhash_multimap::const_reference cref = *cit;   
        System::Console::Write(" [{0} {1}]", cref->first, cref->second);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
``` 

## <a name="const_reverse_iterator"></a> hash_multimap:: const_reverse_iterator (STL/CLR)
O tipo de um iterador inverso constante para sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T4 const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T4` que pode servir como um constante iterador inverso para sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_const_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]" reversed   
    Myhash_multimap::const_reverse_iterator crit = c1.rbegin();   
    for (; crit != c1.rend(); ++crit)   
        System::Console::Write(" [{0} {1}]", crit->first, crit->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[c 3] [b 2] [a 1]  
```  

## <a name="count"></a> hash_multimap:: Count (STL/CLR)
Localiza o número de elementos que correspondem a uma chave especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
size_type count(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna o número de elementos na sequência controlada que têm uma ordenação equivalente com `key`. Usado para determinar o número de elementos que estão na sequência controlada no momento e que correspondem a uma chave especificada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_count.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("count(L'A') = {0}", c1.count(L'A'));   
    System::Console::WriteLine("count(L'b') = {0}", c1.count(L'b'));   
    System::Console::WriteLine("count(L'C') = {0}", c1.count(L'C'));   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
count(L'A') = 0  
count(L'b') = 1  
count(L'C') = 0  
```  
  
## <a name="difference_type"></a> hash_multimap:: difference_type (STL/CLR)
Os tipos de uma distância assinado entre dois elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef int difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elementos possivelmente negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_difference_type.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// compute positive difference   
    Myhash_multimap::difference_type diff = 0;   
    for (Myhash_multimap::iterator it = c1.begin(); it != c1.end(); ++it)   
        ++diff;   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
  
// compute negative difference   
    diff = 0;   
    for (Myhash_multimap::iterator it = c1.end(); it != c1.begin(); --it)   
        --diff;   
    System::Console::WriteLine("begin()-end() = {0}", diff);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
end()-begin() = 3  
begin()-end() = -3  
``` 

## <a name="empty"></a> hash_multimap:: Empty (STL/CLR)
Testa se nenhum elemento está presente.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool empty();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [hash_multimap:: Size (STL/CLR)](../dotnet/hash-multimap-size-stl-clr.md)`() == 0`. Você pode usá-lo para testar se o hash_multimap está vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_empty.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
size() = 3  
empty() = False  
size() = 0  
empty() = True  
```   

## <a name="end"></a> hash_multimap:: end (STL/CLR)
Designa o fim da sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator end();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador bidirecional que aponta logo após o fim da sequência controlada. Você pode usá-lo para obter um iterador que designa o fim da sequência controlada; seu status alteração não se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_end.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect last two items   
    Myhash_multimap::iterator it = c1.end();   
    --it;   
    --it;   
    System::Console::WriteLine("*-- --end() = [{0} {1}]",   
        it->first, it->second);   
    ++it;   
    System::Console::WriteLine("*--end() = [{0} {1}]",   
        it->first, it->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
*-- --end() = [b 2]  
*--end() = [c 3]  
```  

## <a name="equal_range"></a> hash_multimap:: equal_range (STL/CLR)
Localiza o intervalo que corresponde a uma chave especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
cliext::pair<iterator, iterator> equal_range(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um par de iteradores `cliext::pair<iterator, iterator>(` [hash_multimap:: lower_bound (STL/CLR)](../dotnet/hash-multimap-lower-bound-stl-clr.md) `(key),` [hash_multimap:: upper_bound (STL/CLR)](../dotnet/hash-multimap-upper-bound-stl-clr.md)`(key))`. Você pode usá-lo para determinar o intervalo de elementos que correspondem a uma chave especificada no momento na sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_equal_range.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
typedef Myhash_multimap::pair_iter_iter Pairii;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// display results of failed search   
    Pairii pair1 = c1.equal_range(L'x');   
    System::Console::WriteLine("equal_range(L'x') empty = {0}",   
        pair1.first == pair1.second);   
  
// display results of successful search   
    pair1 = c1.equal_range(L'b');   
    for (; pair1.first != pair1.second; ++pair1.first)   
        System::Console::Write(" [{0} {1}]",   
            pair1.first->first, pair1.first->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
equal_range(L'x') empty = True  
 [b 2]  
```  

## <a name="erase"></a> hash_multimap:: Erase (STL/CLR)
Remove os elementos em posições especificadas.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
bool erase(key_type key)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Primeiro  
 Início do intervalo a ser apagado.  
  
 key  
 Valor de chave para apagar.  
  
 last  
 Fim do intervalo a ser apagado.  
  
 onde  
 Elemento apagar.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro remove o elemento de sequência controlada apontada pelo `where`e retorna um iterador que designa o primeiro elemento restantes além do elemento removido, ou [hash_multimap:: end (STL/CLR)](../dotnet/hash-multimap-end-stl-clr.md) `()` se esse elemento não existe. Você pode usá-lo para remover um único elemento.  
  
 A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`) e retorna um iterador que designa o primeiro elemento restantes além de quaisquer elementos removidos, ou `end()` se esse elemento não existe. Você pode usá-lo para remover a zero ou mais elementos contíguos.  
  
 A terceira função do membro remove um elemento de sequência controlada cuja chave tem ordenação equivalente para `key`e retorna uma contagem do número de elementos removidos. Você pode usá-lo para remover e contagem de todos os elementos que correspondem a uma chave especificada.  
  
 A eliminação de cada elemento demora proporcional de logaritmo do número de elementos na sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// cliext_hash_multimap_erase.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    cliext::hash_multimap<wchar_t, int> c1;   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'a', 1));   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'b', 2));   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (cliext::hash_multimap<wchar_t, int>::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// erase an element and reinspect   
    cliext::hash_multimap<wchar_t, int>::iterator it =   
        c1.erase(c1.begin());   
    System::Console::WriteLine("erase(begin()) = [{0} {1}]",   
        it->first, it->second);   
  
// add elements and display " b c d e"   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'd', 4));   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'e', 5));   
    for each (cliext::hash_multimap<wchar_t, int>::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// erase all but end   
    it = c1.end();   
    it = c1.erase(c1.begin(), --it);   
    System::Console::WriteLine("erase(begin(), end()-1) = [{0} {1}]",   
        it->first, it->second);   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// erase end   
    System::Console::WriteLine("erase(L'x') = {0}", c1.erase(L'x'));   
    System::Console::WriteLine("erase(L'e') = {0}", c1.erase(L'e'));   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
erase(begin()) = [b 2]  
 [b 2] [c 3] [d 4] [e 5]  
erase(begin(), end()-1) = [e 5]  
size() = 1  
erase(L'x') = 0  
erase(L'e') = 1  
```  
  
## <a name="find"></a> hash_multimap:: Find (STL/CLR)
Localiza um elemento que corresponde a uma chave especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator find(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 Se pelo menos um elemento na sequência controlada tem ordenação equivalente com `key`, a função de membro retorna um iterador designar um desses elementos; caso contrário, ele retorna [hash_multimap:: end (STL/CLR)](../dotnet/hash-multimap-end-stl-clr.md) `()`. Você pode usá-lo para localizar um elemento no momento na sequência controlada que corresponde a uma chave especificada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_find.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("find {0} = {1}",   
        L'A', c1.find(L'A') != c1.end());   
  
    Myhash_multimap::iterator it = c1.find(L'b');   
    System::Console::WriteLine("find {0} = [{1} {2}]",   
        L'b', it->first, it->second);   
  
    System::Console::WriteLine("find {0} = {1}",   
        L'C', c1.find(L'C') != c1.end());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
find A = False  
find b = [b 2]  
find C = False  
```  

## <a name="generic_container"></a> hash_multimap::generic_container (STL/CLR)
O tipo da interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::  
    IHash<GKey, GValue>  
    generic_container;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_generic_container.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct a generic container   
    Myhash_multimap::generic_container^ gc1 = %c1;   
    for each (Myhash_multimap::value_type elem in gc1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    gc1->insert(Myhash_multimap::make_value(L'd', 4));   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// modify original and display generic   
    c1.insert(Myhash_multimap::make_value(L'e', 5));   
    for each (Myhash_multimap::value_type elem in gc1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
[a 1] [b 2] [c 3]  
[a 1] [b 2] [c 3] [d 4]  
[a 1] [b 2] [c 3] [d 4] [e 5]  
```  

## <a name="generic_iterator"></a> hash_multimap::generic_iterator (STL/CLR)
O tipo de um iterador para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::Generic::  
    ContainerBidirectionalIterator<generic_value>  
    generic_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um iterador genérico que pode ser usado com a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_generic_iterator.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct a generic container   
    Myhash_multimap::generic_container^ gc1 = %c1;   
    for each (Myhash_multimap::value_type elem in gc1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// get an element and display it   
    Myhash_multimap::generic_iterator gcit = gc1->begin();   
    Myhash_multimap::generic_value gcval = *gcit;   
    System::Console::Write(" [{0} {1}]", gcval->first, gcval->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
[a 1] [b 2] [c 3]  
[a 1]  
```  

## <a name="generic_reverse_iterator"></a> hash_multimap::generic_reverse_iterator (STL/CLR)
O tipo de um iterador inverso para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::Generic::  
    ReverseRandomAccessIterator<generic_value>  
    generic_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um iterador inverso genérico que pode ser usado com a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// cliext_hash_multimap_generic_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct a generic container   
    Myhash_multimap::generic_container^ gc1 = %c1;   
    for each (Myhash_multimap::value_type elem in gc1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// get an element and display it   
    Myhash_multimap::generic_reverse_iterator gcit = gc1->rbegin();   
    Myhash_multimap::generic_value gcval = *gcit;   
    System::Console::WriteLine(" [{0} {1}]", gcval->first, gcval->second);   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
[a 1] [b 2] [c 3]  
[c 3]  
``` 

## <a name="generic_value"></a> hash_multimap::generic_value (STL/CLR)
O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef GValue generic_value;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenados para uso com a interface genérica para esta classe de contêiner do modelo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_generic_value.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct a generic container   
    Myhash_multimap::generic_container^ gc1 = %c1;   
    for each (Myhash_multimap::value_type elem in gc1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// get an element and display it   
    Myhash_multimap::generic_iterator gcit = gc1->begin();   
    Myhash_multimap::generic_value gcval = *gcit;   
    System::Console::WriteLine(" [{0} {1}]", gcval->first, gcval->second);   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
[a 1] [b 2] [c 3]  
[a 1]  
```  

## <a name="hash_delegate"></a> hash_multimap::hash_delegate (STL/CLR)
Localiza um elemento que corresponde a uma chave especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
hasher^ hash_delegate();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna o representante usado para converter um valor de chave para um número inteiro. Você pode usá-lo para uma chave de hash.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_hash_delegate.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    Myhash_multimap::hasher^ myhash = c1.hash_delegate();   
  
    System::Console::WriteLine("hash(L'a') = {0}", myhash(L'a'));   
    System::Console::WriteLine("hash(L'b') = {0}", myhash(L'b'));   
    return (0);   
    }  
  
```  
  
```Output  
hash(L'a') = 1616896120  
hash(L'b') = 570892832  
```   

## <a name="hash_multimap"></a> hash_multimap:: hash_multimap (STL/CLR)
Constrói um objeto contêiner.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
hash_multimap();  
explicit hash_multimap(key_compare^ pred);  
hash_multimap(key_compare^ pred, hasher^ hashfn);  
hash_multimap(hash_multimap<Key, Mapped>% right);  
hash_multimap(hash_multimap<Key, Mapped>^ right);  
template<typename InIter>  
    hash_multimaphash_multimap(InIter first, InIter last);  
template<typename InIter>  
    hash_multimap(InIter first, InIter last,  
        key_compare^ pred);  
template<typename InIter>  
    hash_multimap(InIter first, InIter last,  
        key_compare^ pred, hasher^ hashfn);  
hash_multimap(System::Collections::Generic::IEnumerable<GValue>^ right);  
hash_multimap(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred);  
hash_multimap(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred, hasher^ hashfn);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Primeiro  
 Início do intervalo a ser inserido.  
  
 hashfn  
 Função para chaves de mapeamento para buckets de hash.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 Pred  
 Ordenação de predicado para sequência controlada.  
  
 direita  
 Objeto ou intervalo a inserir.  
  
### <a name="remarks"></a>Comentários  
 O construtor:  
  
 `hash_multimap();`  
  
 inicializa a sequência controlada com nenhum elemento com o padrão de ordenação predicado `key_compare()`e com a função de hash padrão. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o padrão de ordenação de função de predicado e hash.  
  
 O construtor:  
  
 `explicit hash_multimap(key_compare^ pred);`  
  
 inicializa a sequência controlada com nenhum elemento, com o predicado ordenação `pred`e com a função de hash padrão. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o predicado de ordenação especificado e a função de hash padrão.  
  
 O construtor:  
  
 `hash_multimap(key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com nenhum elemento, com o predicado ordenação `pred`e com a função de hash `hashfn`. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com a função de predicado e hash ordenação especificada.  
  
 O construtor:  
  
 `hash_multimap(hash_multimap<Key, Mapped>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`), com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto hash_multimap `right`com o predicado de classificação padrão e a função de hash.  
  
 O construtor:  
  
 `hash_multimap(hash_multimap<Key, Mapped>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`), com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto hash_multimap `right`com o predicado de classificação padrão e a função de hash.  
  
 O construtor:  
  
 `template<typename InIter> hash_multimap(InIter first, InIter last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência, de sequência controlada com o padrão de ordenação de função de predicado e hash.  
  
 O construtor:  
  
 `template<typename InIter> hash_multimap(InIter first, InIter last, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o predicado ordenação `pred`e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência, com o predicado de ordenação especificado e a função de hash padrão de sequência controlada.  
  
 O construtor:  
  
 `template<typename InIter> hash_multimap(InIter first, InIter last, key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o predicado ordenação `pred`e com a função de hash `hashfn`. Você pode usá-lo para fazer uma cópia de outra sequência, com a função especificada e ordenação de predicado e hash de sequência controlada.  
  
 O construtor:  
  
 `hash_multimap(System::Collections::Generic::IEnumerable<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com o padrão de ordenação de função de predicado e hash de sequência controlada.  
  
 O construtor:  
  
 `hash_multimap(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado ordenação `pred`e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com a função de hash padrão e o predicado de ordenação especificado de sequência controlada.  
  
 O construtor:  
  
 `hash_multimap(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado ordenação `pred`e com a função de hash `hashfn`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com a função de predicado e hash ordenação especificada de sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_construct.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
int myfun(wchar_t key)   
    { // hash a key   
    return (key ^ 0xdeadbeef);   
    }   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
// construct an empty container   
    Myhash_multimap c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Myhash_multimap c2 = cliext::greater_equal<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    c2.insert(c1.begin(), c1.end());   
    for each (Myhash_multimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an ordering rule and hash function   
    Myhash_multimap c2h(cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_multimap::hasher(&myfun));   
    System::Console::WriteLine("size() = {0}", c2h.size());   
  
    c2h.insert(c1.begin(), c1.end());   
    for each (Myhash_multimap::value_type elem in c2h)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Myhash_multimap c3(c1.begin(), c1.end());   
    for each (Myhash_multimap::value_type elem in c3)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Myhash_multimap c4(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>());   
    for each (Myhash_multimap::value_type elem in c4)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule and hash function   
    Myhash_multimap c4h(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_multimap::hasher(&myfun));   
    for each (Myhash_multimap::value_type elem in c4h)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    Myhash_multimap c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Myhash_multimap::value_type>^)%c3);   
    for each (Myhash_multimap::value_type elem in c5)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule   
    Myhash_multimap c6(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Myhash_multimap::value_type>^)%c3,   
                cliext::greater_equal<wchar_t>());   
    for each (Myhash_multimap::value_type elem in c6)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule and hash function   
    Myhash_multimap c6h(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Myhash_multimap::value_type>^)%c3,   
                cliext::greater_equal<wchar_t>(),   
                gcnew Myhash_multimap::hasher(&myfun));   
    for each (Myhash_multimap::value_type elem in c6h)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Myhash_multimap c7(c4);   
    for each (Myhash_multimap::value_type elem in c7)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    Myhash_multimap c8(%c3);   
    for each (Myhash_multimap::value_type elem in c8)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
size() = 0  
 [a 1] [b 2] [c 3]  
size() = 0  
 [a 1] [b 2] [c 3]  
size() = 0  
 [c 3] [b 2] [a 1]  
  
 [a 1] [b 2] [c 3]  
 [a 1] [b 2] [c 3]  
 [c 3] [b 2] [a 1]  
  
 [a 1] [b 2] [c 3]  
 [a 1] [b 2] [c 3]  
 [c 3] [b 2] [a 1]  
  
 [a 1] [b 2] [c 3]  
 [a 1] [b 2] [c 3]  
```  

## <a name="hasher"></a> hash_multimap::hasher (STL/CLR)
O representante de hash para uma chave.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
Microsoft::VisualC::StlClr::UnaryDelegate<GKey, int>  
    hasher;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um delegado que converte um valor de chave em um inteiro.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_hasher.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    Myhash_multimap::hasher^ myhash = c1.hash_delegate();   
  
    System::Console::WriteLine("hash(L'a') = {0}", myhash(L'a'));   
    System::Console::WriteLine("hash(L'b') = {0}", myhash(L'b'));   
    return (0);   
    }  
  
```  
  
```Output  
hash(L'a') = 1616896120  
hash(L'b') = 570892832  
``` 

## <a name="insert"></a> hash_multimap:: Insert (STL/CLR)
Adiciona elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator insert(value_type val);  
iterator insert(iterator where, value_type val);  
template<typename InIter>  
    void insert(InIter first, InIter last);  
void insert(System::Collections::Generic::IEnumerable<value_type>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 direita  
 Enumeração para inserir.  
  
 Val  
 Valor da chave a ser inserido.  
  
 onde  
 Onde no contêiner para inserir (dica).  
  
### <a name="remarks"></a>Comentários  
 Cada uma das funções membro insere uma sequência especificada por operandos restantes.  
  
 A primeira função de membro insere um elemento com o valor `val`e retorna um iterador que designa o elemento recentemente inserido. Você pode usá-lo para inserir um único elemento.  
  
 A segunda função de membro insere um elemento com o valor `val`usando `where` como uma dica (para melhorar o desempenho) e retorna um iterador que designa o elemento recentemente inserido. Você pode usá-lo para inserir um único elemento que pode ser adjacente a um elemento que você sabe.  
  
 A terceira função do membro insere a sequência [`first`, `last`). Você pode usá-lo para inserir zero ou mais elementos copiados de outra sequência.  
  
 A função de membro quarta insere a sequência designada pelo `right`. Você pode usá-lo para inserir uma sequência descrita por um enumerador.  
  
 Cada inserção de elemento demora proporcional de logaritmo do número de elementos na sequência controlada. Inserção pode ocorrer em tempo de constante amortizado, no entanto, considerando uma dica que designa um elemento adjacente ao ponto de inserção.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_insert.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert a single value, unique and duplicate   
    Myhash_multimap::iterator it =   
        c1.insert(Myhash_multimap::make_value(L'x', 24));   
    System::Console::WriteLine("insert([L'x' 24]) = [{0} {1}]",   
        it->first, it->second);   
  
    it = c1.insert(Myhash_multimap::make_value(L'b', 2));   
    System::Console::WriteLine("insert([L'b' 2]) = [{0} {1}]",   
        it->first, it->second);   
  
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert a single value with hint   
    it = c1.insert(c1.begin(), Myhash_multimap::make_value(L'y', 25));   
    System::Console::WriteLine("insert(begin(), [L'y' 25]) = [{0} {1}]",   
        it->first, it->second);   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert an iterator range   
    Myhash_multimap c2;   
    it = c1.end();   
    c2.insert(c1.begin(), --it);   
    for each (Myhash_multimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert an enumeration   
    Myhash_multimap c3;   
    c3.insert(   // NOTE: cast is not needed   
        (System::Collections::Generic::   
            IEnumerable<Myhash_multimap::value_type>^)%c1);   
    for each (Myhash_multimap::value_type elem in c3)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
insert([L'x' 24]) = [x 24]  
insert([L'b' 2]) = [b 2]  
 [a 1] [b 2] [b 2] [c 3] [x 24]  
insert(begin(), [L'y' 25]) = [y 25]  
 [a 1] [b 2] [b 2] [c 3] [x 24] [y 25]  
 [a 1] [b 2] [b 2] [c 3] [x 24]  
 [a 1] [b 2] [b 2] [c 3] [x 24] [y 25]  
```  
 
## <a name="iterator"></a> hash_multimap:: Iterator (STL/CLR)
O tipo de um iterador para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T1 iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T1` que pode servir como um iterador bidirecional para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_iterator.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    Myhash_multimap::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        System::Console::Write(" [{0} {1}]", it->first, it->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
``` 

## <a name="key_comp"></a> hash_multimap:: key_comp (STL/CLR)
Copia o delegado de ordenação de duas chaves.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
key_compare^key_comp();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna o delegado de classificação usado para ordenar a sequência controlada. Use-o para comparar duas chaves.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_key_comp.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    Myhash_multimap::key_compare^ kcomp = c1.key_comp();   
  
    System::Console::WriteLine("compare(L'a', L'a') = {0}",   
        kcomp(L'a', L'a'));   
    System::Console::WriteLine("compare(L'a', L'b') = {0}",   
        kcomp(L'a', L'b'));   
    System::Console::WriteLine("compare(L'b', L'a') = {0}",   
        kcomp(L'b', L'a'));   
    System::Console::WriteLine();   
  
// test a different ordering rule   
    Myhash_multimap c2 = cliext::greater<wchar_t>();   
    kcomp = c2.key_comp();   
  
    System::Console::WriteLine("compare(L'a', L'a') = {0}",   
        kcomp(L'a', L'a'));   
    System::Console::WriteLine("compare(L'a', L'b') = {0}",   
        kcomp(L'a', L'b'));   
    System::Console::WriteLine("compare(L'b', L'a') = {0}",   
        kcomp(L'b', L'a'));   
    return (0);   
    }  
  
```  
  
```Output  
compare(L'a', L'a') = True  
compare(L'a', L'b') = True  
compare(L'b', L'a') = False  
  
compare(L'a', L'a') = False  
compare(L'a', L'b') = False  
compare(L'b', L'a') = True  
```  
   
## <a name="key_compare"></a> hash_multimap:: key_compare (STL/CLR)
O representante de ordenação para duas chaves.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
Microsoft::VisualC::StlClr::BinaryDelegate<GKey, GKey, bool>  
    key_compare;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o representante que determina a ordem de seus argumentos de chave.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_key_compare.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    Myhash_multimap::key_compare^ kcomp = c1.key_comp();   
  
    System::Console::WriteLine("compare(L'a', L'a') = {0}",   
        kcomp(L'a', L'a'));   
    System::Console::WriteLine("compare(L'a', L'b') = {0}",   
        kcomp(L'a', L'b'));   
    System::Console::WriteLine("compare(L'b', L'a') = {0}",   
        kcomp(L'b', L'a'));   
    System::Console::WriteLine();   
  
// test a different ordering rule   
    Myhash_multimap c2 = cliext::greater<wchar_t>();   
    kcomp = c2.key_comp();   
  
    System::Console::WriteLine("compare(L'a', L'a') = {0}",   
        kcomp(L'a', L'a'));   
    System::Console::WriteLine("compare(L'a', L'b') = {0}",   
        kcomp(L'a', L'b'));   
    System::Console::WriteLine("compare(L'b', L'a') = {0}",   
        kcomp(L'b', L'a'));   
    return (0);   
    }  
  
```  
  
```Output  
compare(L'a', L'a') = True  
compare(L'a', L'b') = True  
compare(L'b', L'a') = False  
  
compare(L'a', L'a') = False  
compare(L'a', L'b') = False  
compare(L'b', L'a') = True  
``` 

## <a name="key_type"></a> hash_multimap:: key_type (STL/CLR)
O tipo de uma chave de classificação.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Key key_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Key`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_key_type.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]" using key_type   
    for (Myhash_multimap::iterator it = c1.begin(); it != c1.end(); ++it)   
        {   // store element in key_type object   
        Myhash_multimap::key_type val = it->first;   
  
        System::Console::Write(" {0}", val);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```   

## <a name="load_factor"></a> hash_multimap::load_factor (STL/CLR)
Conta a média de elementos por bucket.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
float load_factor();  
```  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de membro `(float)` [hash_multimap:: Size (STL/CLR)](../dotnet/hash-multimap-size-stl-clr.md) `() /` [hash_multimap::bucket_count (STL/CLR)](../dotnet/hash-multimap-bucket-count-stl-clr.md)`()`. Você pode usá-lo para determinar o tamanho médio de bucket.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_load_factor.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1 = gcnew Myhash_multimap;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect current parameters   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.25f);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// rehash and redisplay   
    c1.rehash(100);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 4  
  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 0.25  
  
bucket_count() = 128  
load_factor() = 0.0234375  
max_load_factor() = 0.25  
```  

## <a name="lower_bound"></a> hash_multimap:: lower_bound (STL/CLR)
Localiza o início do intervalo que corresponde a uma chave especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator lower_bound(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função de membro determina o primeiro elemento `X` na sequência controlada coloca em hash para o mesmo bucket como `key` e tem ordenação equivalente ao `key`. Se esse elemento não existe, ele retorna [hash_multimap:: end (STL/CLR)](../dotnet/hash-multimap-end-stl-clr.md)`()`; caso contrário, ele retorna um iterador que designa `X`. Você pode usá-lo para localizar o início de uma sequência de elementos no momento na sequência controlada que correspondem a uma chave especificada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_lower_bound.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("lower_bound(L'x')==end() = {0}",   
        c1.lower_bound(L'x') == c1.end());   
  
    Myhash_multimap::iterator it = c1.lower_bound(L'a');   
    System::Console::WriteLine("*lower_bound(L'a') = [{0} {1}]",   
        it->first, it->second);   
    it = c1.lower_bound(L'b');   
    System::Console::WriteLine("*lower_bound(L'b') = [{0} {1}]",   
        it->first, it->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
lower_bound(L'x')==end() = True  
*lower_bound(L'a') = [a 1]  
*lower_bound(L'b') = [b 2]  
```  

## <a name="make_value"></a> hash_multimap::make_value (STL/CLR)
Constrói um objeto de valor.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static value_type make_value(key_type key, mapped_type mapped);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 Valor da chave a ser usado.  
  
 mapeado  
 Valor mapeado para pesquisar.  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um `value_type` objeto cuja chave `key` e cujo valor mapeado é `mapped`. Você pode usá-lo para compor um objeto adequado para uso com várias outras funções de membro.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_make_value.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
``` 

## <a name="mapped_type"></a> hash_multimap:: mapped_type (STL/CLR)
O tipo de um valor mapeado associado a cada chave.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef Mapped mapped_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Mapped`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_mapped_type.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]" using mapped_type   
    for (Myhash_multimap::iterator it = c1.begin(); it != c1.end(); ++it)   
        {   // store element in mapped_type object   
        Myhash_multimap::mapped_type val = it->second;   
  
        System::Console::Write(" {0}", val);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
1 2 3  
```  

## <a name="max_load_factor"></a> hash_multimap::max_load_factor (STL/CLR)
Obtém ou define o máximo de elementos por bucket.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
float max_load_factor();  
void max_load_factor(float new_factor);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 new_factor  
 Novo valor máximo carregar fator para armazenar.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro retorna o fator de carga máxima armazenado atual. Você pode usá-lo para determinar o tamanho máximo de bucket médio.  
  
 A segunda função de membro substitui o fator de carga máxima de armazenamento com `new_factor`. Nenhum refazendo o hash automática ocorre até subsequentes de inserção.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_max_load_factor.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1 = gcnew Myhash_multimap;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect current parameters   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.25f);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// rehash and redisplay   
    c1.rehash(100);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 4  
  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 0.25  
  
bucket_count() = 128  
load_factor() = 0.0234375  
max_load_factor() = 0.25  
``` 

## <a name="op"></a> hash_multimap::Operator = (STL/CLR)
Substitui a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
hash_multimap<Key, Mapped>% operator=(hash_multimap<Key, Mapped>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 O contêiner a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 As cópias de operador de membro `right` para o objeto, em seguida, retorna `*this`. Você pode usá-lo para substituir a sequência controlada por uma cópia da sequência controlada em `right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_operator_as.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myhash_multimap c2;   
    c2 = c1;   
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
[a 1] [b 2] [c 3]  
```  

## <a name="rbegin"></a> hash_multimap:: rbegin (STL/CLR)
Designa o início da sequência controlada invertida.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reverse_iterator rbegin();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador inverso que designa o último elemento da sequência controlada ou logo após o início de uma sequência vazia. Portanto, ele designa o `beginning` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` pode alterá-início da sequência controlada visto na ordem inversa, mas seu status se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_rbegin.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect first two items in reversed sequence   
    Myhash_multimap::reverse_iterator rit = c1.rbegin();   
    System::Console::WriteLine("*rbegin() = [{0} {1}]",   
        rit->first, rit->second);   
    ++rit;   
    System::Console::WriteLine("*++rbegin() = [{0} {1}]",   
        rit->first, rit->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
*rbegin() = [c 3]  
*++rbegin() = [b 2]  
```  

## <a name="reference"></a> hash_multimap:: Reference (STL/CLR)
O tipo de uma referência para um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef value_type% reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma referência a um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_reference.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    Myhash_multimap::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        {   // get a reference to an element   
        Myhash_multimap::reference ref = *it;   
        System::Console::Write(" [{0} {1}]", ref->first, ref->second);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
```  
   
## <a name="rehash"></a> hash_multimap::rehash (STL/CLR)
Recria a tabela de hash.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void rehash();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro recria a tabela de hash, garantindo que [hash_multimap::load_factor (STL/CLR)](../dotnet/hash-multimap-load-factor-stl-clr.md) `() <=` [hash_multimap::max_load_factor (STL/CLR)](../dotnet/hash-multimap-max-load-factor-stl-clr.md). Caso contrário, a tabela de hash aumenta de tamanho, conforme necessário após uma inserção. (Ele nunca diminui de tamanho automaticamente.) Você pode usá-lo para ajustar o tamanho da tabela de hash.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_rehash.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1 = gcnew Myhash_multimap;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect current parameters   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.25f);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    System::Console::WriteLine();   
  
// rehash and redisplay   
    c1.rehash(100);   
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());   
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());   
    System::Console::WriteLine("max_load_factor() = {0}",   
        c1.max_load_factor());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 4  
  
bucket_count() = 16  
load_factor() = 0.1875  
max_load_factor() = 0.25  
  
bucket_count() = 128  
load_factor() = 0.0234375  
max_load_factor() = 0.25  
``` 

## <a name="rend"></a> hash_multimap:: rend (STL/CLR)
Designa o fim da sequência controlada invertida.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reverse_iterator rend();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador inverso que aponta logo após o início da sequência controlada. Portanto, ele designa o `end` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` final da sequência controlada visto na ordem inversa, mas seu status pode alterar se altera o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_rend.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect first two items in reversed sequence   
    Myhash_multimap::reverse_iterator rit = c1.rend();   
    --rit;   
    --rit;   
    System::Console::WriteLine("*-- --rend() = [{0} {1}]",   
        rit->first, rit->second);   
    ++rit;   
    System::Console::WriteLine("*--rend() = [{0} {1}]",   
        rit->first, rit->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
*-- --rend() = [b 2]  
*--rend() = [a 1]  
``` 

## <a name="reverse_iterator"></a> hash_multimap:: reverse_iterator (STL/CLR)
O tipo de um iterador inverso para a sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef T3 reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T3` que pode servir como um iterador inverso para sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]" reversed   
    Myhash_multimap::reverse_iterator rit = c1.rbegin();   
    for (; rit != c1.rend(); ++rit)   
        System::Console::Write(" [{0} {1}]", rit->first, rit->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[c 3] [b 2] [a 1]  
```   

## <a name="size"></a> hash_multimap:: Size (STL/CLR)
Conta o número de elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
size_type size();  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência controlada. Você pode usá-lo para determinar o número de elementos no momento na sequência controlada. Se você se preocupa se a sequência tem tamanho diferente de zero, consulte [hash_multimap:: Empty (STL/CLR)](../dotnet/hash-multimap-empty-stl-clr.md)`()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_size.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0} after clearing", c1.size());   
  
// add elements and clear again   
    c1.insert(Myhash_multimap::make_value(L'd', 4));   
    c1.insert(Myhash_multimap::make_value(L'e', 5));   
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
size() = 0 after clearing  
size() = 2 after adding 2  
```   

## <a name="size_type"></a> hash_multimap:: size_type (STL/CLR)
O tipo de uma distância assinado entre dois elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef int size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma contagem de elementos não-negativo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_size_type.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// compute positive difference   
    Myhash_multimap::size_type diff = 0;   
    for (Myhash_multimap::iterator it = c1.begin(); it != c1.end(); ++it)   
        ++diff;   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
end()-begin() = 3  
```  

## <a name="swap"></a> hash_multimap:: swap (STL/CLR)
Alterna o conteúdo de dois contêineres.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void swap(hash_multimap<Key, Mapped>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 Contêiner com o qual trocar conteúdos.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca as sequências controladas entre `this` e `right`. Isso é feito no tempo constante e ele não lança exceções. Você pode usá-lo como uma maneira rápida de trocar o conteúdo de dois contêineres.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_swap.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct another container with repetition of values   
    Myhash_multimap c2;   
    c2.insert(Myhash_multimap::make_value(L'd', 4));   
    c2.insert(Myhash_multimap::make_value(L'e', 5));   
    c2.insert(Myhash_multimap::make_value(L'f', 6));   
    for each (Myhash_multimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// swap and redisplay   
    c1.swap(c2);   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
    for each (Myhash_multimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
[d 4] [e 5] [f 6]  
[d 4] [e 5] [f 6]  
[a 1] [b 2] [c 3]  
```  

## <a name="to_array"></a> hash_multimap::to_array (STL/CLR)
Copia uma nova matriz sequência controlada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
cli::array<value_type>^ to_array();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna uma matriz que contém a sequência controlada. Você pode usá-lo para obter uma cópia da sequência controlada no formulário de matriz.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_to_array.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// copy the container and modify it   
    cli::array<Myhash_multimap::value_type>^ a1 = c1.to_array();   
  
    c1.insert(Myhash_multimap::make_value(L'd', 4));   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// display the earlier array copy   
    for each (Myhash_multimap::value_type elem in a1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3] [d 4]  
[a 1] [b 2] [c 3]  
```  
  
## <a name="upper_bound"></a> hash_multimap:: upper_bound (STL/CLR)
Localiza o final do intervalo que corresponde a uma chave especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
iterator upper_bound(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função de membro determina o último elemento `X` na sequência controlada coloca em hash para o mesmo bucket como `key` e tem ordenação equivalente ao `key`. Se esse elemento não existe, ou se `X` é o último elemento na sequência controlada, ele retorna [hash_multimap:: end (STL/CLR)](../dotnet/hash-multimap-end-stl-clr.md)`()`; caso contrário, ele retorna um iterador que designa o primeiro elemento além `X`. Você pode usá-lo para localizar o final de uma sequência de elementos no momento na sequência controlada que correspondem a uma chave especificada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_upper_bound.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("upper_bound(L'x')==end() = {0}",   
        c1.upper_bound(L'x') == c1.end());   
  
    Myhash_multimap::iterator it = c1.upper_bound(L'a');   
    System::Console::WriteLine("*upper_bound(L'a') = [{0} {1}]",   
        it->first, it->second);   
    it = c1.upper_bound(L'b');   
    System::Console::WriteLine("*upper_bound(L'b') = [{0} {1}]",   
        it->first, it->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
upper_bound(L'x')==end() = True  
*upper_bound(L'a') = [b 2]  
*upper_bound(L'b') = [c 3]  
```  

## <a name="value_comp"></a> hash_multimap:: value_comp (STL/CLR)
Copia o delegado de ordenação de dois valores de elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
value_compare^ value_comp();  
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna o delegado de classificação usado para ordenar a sequência controlada. Você pode usá-lo para comparar dois valores de elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_value_comp.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_map<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    Myhash_multimap::value_compare^ kcomp = c1.value_comp();   
  
    System::Console::WriteLine("compare([L'a', 1], [L'a', 1]) = {0}",   
        kcomp(Myhash_multimap::make_value(L'a', 1),   
            Myhash_multimap::make_value(L'a', 1)));   
    System::Console::WriteLine("compare([L'a', 1], [L'b', 2]) = {0}",   
        kcomp(Myhash_multimap::make_value(L'a', 1),   
            Myhash_multimap::make_value(L'b', 2)));   
    System::Console::WriteLine("compare([L'b', 2], [L'a', 1]) = {0}",   
        kcomp(Myhash_multimap::make_value(L'b', 2),   
            Myhash_multimap::make_value(L'a', 1)));   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
compare([L'a', 1], [L'a', 1]) = True  
compare([L'a', 1], [L'b', 2]) = True  
compare([L'b', 2], [L'a', 1]) = False  
``` 

## <a name="value_compare"></a> hash_multimap::value_compare (STL/CLR)
O representante de ordenação para dois valores de elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
Microsoft::VisualC::StlClr::BinaryDelegate<generic_value, generic_value, bool>  
    value_compare;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o representante que determina a ordem de seus argumentos de valor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_value_compare.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_map<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    Myhash_multimap::value_compare^ kcomp = c1.value_comp();   
  
    System::Console::WriteLine("compare([L'a', 1], [L'a', 1]) = {0}",   
        kcomp(Myhash_multimap::make_value(L'a', 1),   
            Myhash_multimap::make_value(L'a', 1)));   
    System::Console::WriteLine("compare([L'a', 1], [L'b', 2]) = {0}",   
        kcomp(Myhash_multimap::make_value(L'a', 1),   
            Myhash_multimap::make_value(L'b', 2)));   
    System::Console::WriteLine("compare([L'b', 2], [L'a', 1]) = {0}",   
        kcomp(Myhash_multimap::make_value(L'b', 2),   
            Myhash_multimap::make_value(L'a', 1)));   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
compare([L'a', 1], [L'a', 1]) = True  
compare([L'a', 1], [L'b', 2]) = True  
compare([L'b', 2], [L'a', 1]) = False  
```   

## <a name="value_type"></a> hash_multimap:: value_type (STL/CLR)
O tipo de um elemento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef generic_value value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de `generic_value`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// cliext_hash_multimap_value_type.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]" using value_type   
    for (Myhash_multimap::iterator it = c1.begin(); it != c1.end(); ++it)   
        {   // store element in value_type object   
        Myhash_multimap::value_type val = *it;   
        System::Console::Write(" [{0} {1}]", val->first, val->second);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
```  
