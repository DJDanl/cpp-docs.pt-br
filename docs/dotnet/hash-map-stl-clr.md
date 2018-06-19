---
title: hash_map (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_map
dev_langs:
- C++
helpviewer_keywords:
- <cliext/hash_map> header [STL/CLR]
- <hash_map> header [STL/CLR]
- hash_map class [STL/CLR]
ms.assetid: c3cfc69b-04c6-42ae-a30e-0eda953fe883
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ad09cf718e2e76cbed99c5628a3eafc5104ad03f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33111797"
---
# <a name="hashmap-stlclr"></a>hash_map (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `hash_map` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada da tabela de armazenar um bidirecional vinculado a lista de nós e cada nó de armazenamento de um elemento. Um elemento consiste em uma chave, para ordenar a sequência e um valor mapeado, o que vai ao longo da simultaneamente.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 em que:  
  
 `GKey` é o mesmo que `Key` , a menos que o último é um tipo de referência, caso em que é `Key^`  
  
 `GMapped` é o mesmo que `Mapped` , a menos que o último é um tipo de referência, caso em que é `Mapped^`  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class hash_map  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        System::Collections::Generic::IDictionary<Gkey, GMapped>,  
        Microsoft::VisualC::StlClr::IHash<Gkey, GValue>  
    { ..... };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Chave  
 O tipo do componente principal de um elemento na sequência controlada.  
  
 Mapeado  
 O tipo do componente adicional de um elemento na sequência controlada.  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[hash_map::const_iterator (STL/CLR)](../dotnet/hash-map-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[hash_map::const_reference (STL/CLR)](../dotnet/hash-map-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[hash_map::const_reverse_iterator (STL/CLR)](../dotnet/hash-map-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[hash_map::difference_type (STL/CLR)](../dotnet/hash-map-difference-type-stl-clr.md)|O tipo de uma distância (possivelmente assinado) entre dois elementos.|  
|[hash_map::generic_container (STL/CLR)](../dotnet/hash-map-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[hash_map::generic_iterator (STL/CLR)](../dotnet/hash-map-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[hash_map::generic_reverse_iterator (STL/CLR)](../dotnet/hash-map-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[hash_map::generic_value (STL/CLR)](../dotnet/hash-map-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[hash_map::hasher (STL/CLR)](../dotnet/hash-map-hasher-stl-clr.md)|O representante de hash para uma chave.|  
|[hash_map::iterator (STL/CLR)](../dotnet/hash-map-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[hash_map::key_compare (STL/CLR)](../dotnet/hash-map-key-compare-stl-clr.md)|O representante de ordenação para duas chaves.|  
|[hash_map::key_type (STL/CLR)](../dotnet/hash-map-key-type-stl-clr.md)|O tipo de uma chave de classificação.|  
|[hash_map::mapped_type (STL/CLR)](../dotnet/hash-map-mapped-type-stl-clr.md)|O tipo do valor mapeado associado a cada chave.|  
|[hash_map::reference (STL/CLR)](../dotnet/hash-map-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[hash_map::reverse_iterator (STL/CLR)](../dotnet/hash-map-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[hash_map::size_type (STL/CLR)](../dotnet/hash-map-size-type-stl-clr.md)|O tipo de uma distância (negativo) entre dois elementos.|  
|[hash_map::value_compare (STL/CLR)](../dotnet/hash-map-value-compare-stl-clr.md)|O representante de ordenação para dois valores de elemento.|  
|[hash_map::value_type (STL/CLR)](../dotnet/hash-map-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[hash_map::begin (STL/CLR)](../dotnet/hash-map-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[hash_map::bucket_count (STL/CLR)](../dotnet/hash-map-bucket-count-stl-clr.md)|Conta o número de buckets.|  
|[hash_map::clear (STL/CLR)](../dotnet/hash-map-clear-stl-clr.md)|Remove todos os elementos.|  
|[hash_map::count (STL/CLR)](../dotnet/hash-map-count-stl-clr.md)|Contagens de elementos de correspondência de uma chave especificada.|  
|[hash_map::empty (STL/CLR)](../dotnet/hash-map-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[hash_map::end (STL/CLR)](../dotnet/hash-map-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[hash_map::equal_range (STL/CLR)](../dotnet/hash-map-equal-range-stl-clr.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[hash_map::erase (STL/CLR)](../dotnet/hash-map-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[hash_map::find (STL/CLR)](../dotnet/hash-map-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[hash_map::hash_delegate (STL/CLR)](../dotnet/hash-map-hash-delegate-stl-clr.md)|Copia o delegado de hash para uma chave.|  
|[hash_map::hash_map (STL/CLR)](../dotnet/hash-map-hash-map-stl-clr.md)|Constrói um objeto contêiner.|  
|[hash_map::insert (STL/CLR)](../dotnet/hash-map-insert-stl-clr.md)|Adiciona elementos.|  
|[hash_map::key_comp (STL/CLR)](../dotnet/hash-map-key-comp-stl-clr.md)|Copia o delegado de ordenação de duas chaves.|  
|[hash_map::load_factor (STL/CLR)](../dotnet/hash-map-load-factor-stl-clr.md)|Conta a média de elementos por bucket.|  
|[hash_map::lower_bound (STL/CLR)](../dotnet/hash-map-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[hash_map::make_value (STL/CLR)](../dotnet/hash-map-make-value-stl-clr.md)|Constrói um objeto de valor.|  
|[hash_map::max_load_factor (STL/CLR)](../dotnet/hash-map-max-load-factor-stl-clr.md)|Obtém ou define o máximo de elementos por bucket.|  
|[hash_map::rbegin (STL/CLR)](../dotnet/hash-map-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[hash_map::rehash (STL/CLR)](../dotnet/hash-map-rehash-stl-clr.md)|Recria a tabela de hash.|  
|[hash_map::rend (STL/CLR)](../dotnet/hash-map-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[hash_map::size (STL/CLR)](../dotnet/hash-map-size-stl-clr.md)|Conta o número de elementos.|  
|[hash_map::swap (STL/CLR)](../dotnet/hash-map-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[hash_map::to_array (STL/CLR)](../dotnet/hash-map-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[hash_map::upper_bound (STL/CLR)](../dotnet/hash-map-upper-bound-stl-clr.md)|Localiza o final do intervalo que corresponde a uma chave especificada.|  
|[hash_map::value_comp (STL/CLR)](../dotnet/hash-map-value-comp-stl-clr.md)|Copia o delegado de ordenação de dois valores de elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[hash_map::operator= (STL/CLR)](../dotnet/hash-map-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[hash_map::operator(STL/CLR)](../dotnet/hash-map-operator-stl-clr.md)|Mapeia uma chave para seu valor mapeado associado.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|<xref:System.Collections.Generic.IDictionary%602>|Manter o grupo de {chave, valor} pares.|  
|IHash < chave, valor >|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência em que ele controla como nós individuais em uma lista vinculada bidirecional. Para agilizar o acesso, o objeto também mantém uma matriz de comprimento variável de ponteiros na lista (a tabela de hash), gerenciar com eficiência a lista inteira como uma sequência de sublistas, ou buckets. Ele insere elementos em uma partição que mantém ordenada alterando os links entre nós nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente, sem prejudicar elementos restantes.  
  
 O objeto classifica cada bucket controla chamando um objeto de representante armazenado do tipo [hash_set:: key_compare (STL/CLR)](../dotnet/hash-set-key-compare-stl-clr.md). Você pode especificar o objeto do representante armazenado quando você construir o hash_set; Se você não especificar nenhum objeto do representante, o padrão é a comparação `operator<=(key_type, key_type)`.  
  
 Acessar o objeto do representante armazenado chamando a função de membro [hash_set:: key_comp (STL/CLR)](../dotnet/hash-set-key-comp-stl-clr.md)`()`. Esse é um objeto de representante deve definir equivalente a ordem entre as chaves do tipo [hash_set:: key_type (STL/CLR)](../dotnet/hash-set-key-type-stl-clr.md). Isso significa que, para qualquer duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` Retorna o mesmo Boolean resultar em cada chamada.  
  
 Se `key_comp()(X, Y) && key_comp()(Y, X)` for true, em seguida, `X` e `Y` são deve ter ordenação equivalente.  
  
 Qualquer regra de ordenação que se comporta como `operator<=(key_type, key_type)`, `operator>=(key_type, key_type)` ou `operator==(key_type, key_type)` define eqivalent ordenação.  
  
 Observe que o contêiner somente garante que elementos cujas chaves tem ordenação equivalente (e o hash para o mesmo valor de inteiro) são adjacentes em um bucket. Ao contrário de classe de modelo [hash_multimap (STL/CLR)](../dotnet/hash-multimap-stl-clr.md), um objeto da classe de modelo `hash_map` garante que as chaves para todos os elementos sejam exclusivas. (Não há duas chaves tem ordenação equivalente).  
  
 O objeto determina quais bucket deve conter uma determinada chave de ordenação chamando um objeto de representante armazenado do tipo [hash_set::hasher (STL/CLR)](../dotnet/hash-set-hasher-stl-clr.md). Acessar esse objeto armazenado chamando a função de membro [hash_set::hash_delegate (STL/CLR)](../dotnet/hash-set-hash-delegate-stl-clr.md) `()` para obter um valor inteiro que depende do valor de chave. Você pode especificar o objeto do representante armazenado quando você construir o hash_set; Se você não especificar nenhum objeto do representante, o padrão é a função `System::Object::hash_value(key_type)`. Isso significa que, para todas as chaves `X` e `Y`:  
  
 `hash_delegate()(X)` Retorna o mesmo resultado de inteiro em cada chamada.  
  
 Se `X` e `Y` ter ordenação equivalente, em seguida, `hash_delegate()(X)` deve retornar o mesmo resultado de inteiro de `hash_delegate()(Y)`.  
  
 Cada elemento contém uma chave e um valor mapeado. A sequência é representada de forma que permite a remoção de um elemento arbitrário com um número de operações que é independente do número de elementos na sequência (tempo constante)-- pelo menos no melhor dos casos, pesquisa e inserção. Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
 No entanto, se os valores de hash não são distribuídos uniformemente, uma tabela de hash pode deteriorar. Extremo – para uma função de hash que sempre retorna o mesmo valor – pesquisa, inserção e remoção são proporcionais ao número de elementos na sequência (tempo linear). O contêiner endeavors escolher uma função de hash razoável, o tamanho médio do bucket e tamanho da tabela de hash (número total de buckets), mas você pode substituir uma ou todas essas opções. Veja, por exemplo, as funções [hash_set::max_load_factor (STL/CLR)](../dotnet/hash-set-max-load-factor-stl-clr.md) e [hash_set::rehash (STL/CLR)](../dotnet/hash-set-rehash-stl-clr.md).  
  
 Um hash_map suporta iteradores bidirecional, o que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [hash_map:: end (STL/CLR)](../dotnet/hash-map-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador hash_map para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento hash_map diretamente considerando sua posição numérica - que requer um iterador de acesso aleatório.  
  
 Um iterador hash_map armazena um identificador para o nó hash_map associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador hash_map permanece válido desde que o nó hash_map associado seja associado a alguns hash_map. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_map >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map](../dotnet/hash-map-stl-clr.md)   
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [multimapa (STL/CLR)](../dotnet/multimap-stl-clr.md)   
 [multiconjunto (STL/CLR)](../dotnet/multiset-stl-clr.md)   
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)