---
title: hash_set (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_set
dev_langs:
- C++
helpviewer_keywords:
- <cliext/hash_set> header [STL/CLR]
- hash_set class [STL/CLR]
- <hash_set> header [STL/CLR]
ms.assetid: d110e356-ba3e-4e52-9e2d-d997bf975c96
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 63b43a116848ff67deb9c62c04849aa5afc6dbc1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="hashset-stlclr"></a>hash_set (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `hash_set` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada da tabela de armazenar um bidirecional vinculado a lista de nós e cada nó de armazenamento de um elemento. O valor de cada elemento é usado como uma chave para ordenar a sequência.  
  
 Na descrição abaixo, `GValue` é o mesmo que `GKey`, que é o mesmo que por sua vez `Key` , a menos que o último é um tipo de referência, caso em que é `Key^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Key>  
    ref class hash_set  
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
  
#### <a name="parameters"></a>Parâmetros  
 Chave  
 O tipo do componente principal de um elemento na sequência controlada.  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[hash_set::const_iterator (STL/CLR)](../dotnet/hash-set-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[hash_set::const_reference (STL/CLR)](../dotnet/hash-set-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[hash_set::const_reverse_iterator (STL/CLR)](../dotnet/hash-set-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[hash_set::difference_type (STL/CLR)](../dotnet/hash-set-difference-type-stl-clr.md)|O tipo de uma distância (possivelmente assinado) entre dois elementos.|  
|[hash_set::generic_container (STL/CLR)](../dotnet/hash-set-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[hash_set::generic_iterator (STL/CLR)](../dotnet/hash-set-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[hash_set::generic_reverse_iterator (STL/CLR)](../dotnet/hash-set-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[hash_set::generic_value (STL/CLR)](../dotnet/hash-set-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[hash_set::hasher (STL/CLR)](../dotnet/hash-set-hasher-stl-clr.md)|O representante de hash para uma chave.|  
|[hash_set::iterator (STL/CLR)](../dotnet/hash-set-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[hash_set::key_compare (STL/CLR)](../dotnet/hash-set-key-compare-stl-clr.md)|O representante de ordenação para duas chaves.|  
|[hash_set::key_type (STL/CLR)](../dotnet/hash-set-key-type-stl-clr.md)|O tipo de uma chave de classificação.|  
|[hash_set::reference (STL/CLR)](../dotnet/hash-set-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[hash_set::reverse_iterator (STL/CLR)](../dotnet/hash-set-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[hash_set::size_type (STL/CLR)](../dotnet/hash-set-size-type-stl-clr.md)|O tipo de uma distância (negativo) entre dois elementos.|  
|[hash_set::value_compare (STL/CLR)](../dotnet/hash-set-value-compare-stl-clr.md)|O representante de ordenação para dois valores de elemento.|  
|[hash_set::value_type (STL/CLR)](../dotnet/hash-set-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[hash_set::begin (STL/CLR)](../dotnet/hash-set-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[hash_set::bucket_count (STL/CLR)](../dotnet/hash-set-bucket-count-stl-clr.md)|Conta o número de buckets.|  
|[hash_set::clear (STL/CLR)](../dotnet/hash-set-clear-stl-clr.md)|Remove todos os elementos.|  
|[hash_set::count (STL/CLR)](../dotnet/hash-set-count-stl-clr.md)|Contagens de elementos de correspondência de uma chave especificada.|  
|[hash_set::empty (STL/CLR)](../dotnet/hash-set-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[hash_set::end (STL/CLR)](../dotnet/hash-set-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[hash_set::equal_range (STL/CLR)](../dotnet/hash-set-equal-range-stl-clr.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[hash_set::erase (STL/CLR)](../dotnet/hash-set-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[hash_set::find (STL/CLR)](../dotnet/hash-set-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[hash_set::hash_delegate (STL/CLR)](../dotnet/hash-set-hash-delegate-stl-clr.md)|Copia o delegado de hash para uma chave.|  
|[hash_set::hash_set (STL/CLR)](../dotnet/hash-set-hash-set-stl-clr.md)|Constrói um objeto contêiner.|  
|[hash_set::insert (STL/CLR)](../dotnet/hash-set-insert-stl-clr.md)|Adiciona elementos.|  
|[hash_set::key_comp (STL/CLR)](../dotnet/hash-set-key-comp-stl-clr.md)|Copia o delegado de ordenação de duas chaves.|  
|[hash_set::load_factor (STL/CLR)](../dotnet/hash-set-load-factor-stl-clr.md)|Conta a média de elementos por bucket.|  
|[hash_set::lower_bound (STL/CLR)](../dotnet/hash-set-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[hash_set::make_value (STL/CLR)](../dotnet/hash-set-make-value-stl-clr.md)|Constrói um objeto de valor.|  
|[hash_set::max_load_factor (STL/CLR)](../dotnet/hash-set-max-load-factor-stl-clr.md)|Obtém ou define o máximo de elementos por bucket.|  
|[hash_set::rbegin (STL/CLR)](../dotnet/hash-set-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[hash_set::rehash (STL/CLR)](../dotnet/hash-set-rehash-stl-clr.md)|Recria a tabela de hash.|  
|[hash_set::rend (STL/CLR)](../dotnet/hash-set-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[hash_set::size (STL/CLR)](../dotnet/hash-set-size-stl-clr.md)|Conta o número de elementos.|  
|[hash_set::swap (STL/CLR)](../dotnet/hash-set-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[hash_set::to_array (STL/CLR)](../dotnet/hash-set-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[hash_set::upper_bound (STL/CLR)](../dotnet/hash-set-upper-bound-stl-clr.md)|Localiza o final do intervalo que corresponde a uma chave especificada.|  
|[hash_set::value_comp (STL/CLR)](../dotnet/hash-set-value-comp-stl-clr.md)|Copia o delegado de ordenação de dois valores de elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[hash_set::operator= (STL/CLR)](../dotnet/hash-set-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
  
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
  
 Observe que o contêiner somente garante que elementos cujas chaves tem ordenação equivalente (e o hash para o mesmo valor de inteiro) são adjacentes em um bucket. Ao contrário de classe de modelo [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md), um objeto da classe de modelo `hash_set` garante que as chaves para todos os elementos sejam exclusivas. (Não há duas chaves tem ordenação equivalente).  
  
 O objeto determina quais bucket deve conter uma determinada chave de ordenação chamando um objeto de representante armazenado do tipo [hash_set::hasher (STL/CLR)](../dotnet/hash-set-hasher-stl-clr.md). Acessar esse objeto armazenado chamando a função de membro [hash_set::hash_delegate (STL/CLR)](../dotnet/hash-set-hash-delegate-stl-clr.md) `()` para obter um valor inteiro que depende do valor de chave. Você pode especificar o objeto do representante armazenado quando você construir o hash_set; Se você não especificar nenhum objeto do representante, o padrão é a função `System::Object::hash_value(key_type)`. Isso significa que, para todas as chaves `X` e `Y`:  
  
 `hash_delegate()(X)` Retorna o mesmo resultado de inteiro em cada chamada.  
  
 Se `X` e `Y` ter ordenação equivalente, em seguida, `hash_delegate()(X)` deve retornar o mesmo resultado de inteiro de `hash_delegate()(Y)`.  
  
 Cada elemento serve como uma chave e um valor. A sequência é representada de forma que permite a remoção de um elemento arbitrário com um número de operações que é independente do número de elementos na sequência (tempo constante)-- pelo menos no melhor dos casos, pesquisa e inserção. Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
 No entanto, se os valores de hash não são distribuídos uniformemente, uma tabela de hash pode deteriorar. Extremo – para uma função de hash que sempre retorna o mesmo valor – pesquisa, inserção e remoção são proporcionais ao número de elementos na sequência (tempo linear). O contêiner endeavors escolher uma função de hash razoável, o tamanho médio do bucket e tamanho da tabela de hash (número total de buckets), mas você pode substituir uma ou todas essas opções. Veja, por exemplo, as funções [hash_set::max_load_factor (STL/CLR)](../dotnet/hash-set-max-load-factor-stl-clr.md) e [hash_set::rehash (STL/CLR)](../dotnet/hash-set-rehash-stl-clr.md).  
  
 Um hash_set suporta iteradores bidirecional, o que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [hash_set:: end (STL/CLR)](../dotnet/hash-set-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador hash_set para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento hash_set diretamente considerando sua posição numérica - que requer um iterador de acesso aleatório.  
  
 Um iterador hash_set armazena um identificador para o nó hash_set associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador hash_set permanece válido desde que o nó hash_set associado seja associado a alguns hash_set. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_set](../dotnet/hash-set-stl-clr.md)   
 [hash_set](../dotnet/hash-set-stl-clr.md)   
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)