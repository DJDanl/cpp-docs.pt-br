---
title: Map (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- cliext::map
dev_langs:
- C++
helpviewer_keywords:
- <map> header [STL/CLR]
- map class [STL/CLR]
- <cliext/map> header [STL/CLR]
ms.assetid: 8b0a7764-b5e4-4175-a802-82b72eb8662a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c90fcb415b186257cd2aef801867918b367413b6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="map-stlclr"></a>map (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `map` para gerenciar uma sequência de elementos como uma árvore equilibrada (quase) ordenada de nós, cada armazenamento de um elemento. Um elemento consiste em uma chave, para ordenar a sequência e um valor mapeado, o que vai ao longo da simultaneamente.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 em que:  
  
 `GKey`é o mesmo que `Key` , a menos que o último é um tipo de referência, caso em que é`Key^`  
  
 `GMapped`é o mesmo que `Mapped` , a menos que o último é um tipo de referência, caso em que é`Mapped^`  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class map  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        System::Collections::Generic::IDictionary<Gkey, GMapped>,  
        Microsoft::VisualC::StlClr::ITree<Gkey, GValue>  
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
|[map::const_iterator (STL/CLR)](../dotnet/map-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[map::const_reference (STL/CLR)](../dotnet/map-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[map::const_reverse_iterator (STL/CLR)](../dotnet/map-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[map::difference_type (STL/CLR)](../dotnet/map-difference-type-stl-clr.md)|O tipo de uma distância (possivelmente assinado) entre dois elementos.|  
|[map::generic_container (STL/CLR)](../dotnet/map-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[map::generic_iterator (STL/CLR)](../dotnet/map-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[map::generic_reverse_iterator (STL/CLR)](../dotnet/map-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[map::generic_value (STL/CLR)](../dotnet/map-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[map::iterator (STL/CLR)](../dotnet/map-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[map::key_compare (STL/CLR)](../dotnet/map-key-compare-stl-clr.md)|O representante de ordenação para duas chaves.|  
|[map::key_type (STL/CLR)](../dotnet/map-key-type-stl-clr.md)|O tipo de uma chave de classificação.|  
|[map::mapped_type (STL/CLR)](../dotnet/map-mapped-type-stl-clr.md)|O tipo do valor mapeado associado a cada chave.|  
|[map::reference (STL/CLR)](../dotnet/map-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[map::reverse_iterator (STL/CLR)](../dotnet/map-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[map::size_type (STL/CLR)](../dotnet/map-size-type-stl-clr.md)|O tipo de uma distância (negativo) entre dois elementos.|  
|[map::value_compare (STL/CLR)](../dotnet/map-value-compare-stl-clr.md)|O representante de ordenação para dois valores de elemento.|  
|[map::value_type (STL/CLR)](../dotnet/map-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[map::begin (STL/CLR)](../dotnet/map-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[map::clear (STL/CLR)](../dotnet/map-clear-stl-clr.md)|Remove todos os elementos.|  
|[map::count (STL/CLR)](../dotnet/map-count-stl-clr.md)|Contagens de elementos de correspondência de uma chave especificada.|  
|[map::empty (STL/CLR)](../dotnet/map-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[map::end (STL/CLR)](../dotnet/map-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[map::equal_range (STL/CLR)](../dotnet/map-equal-range-stl-clr.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[map::erase (STL/CLR)](../dotnet/map-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[map::find (STL/CLR)](../dotnet/map-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[map::insert (STL/CLR)](../dotnet/map-insert-stl-clr.md)|Adiciona elementos.|  
|[map::key_comp (STL/CLR)](../dotnet/map-key-comp-stl-clr.md)|Copia o delegado de ordenação de duas chaves.|  
|[map::lower_bound (STL/CLR)](../dotnet/map-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[map::make_value (STL/CLR)](../dotnet/map-make-value-stl-clr.md)|Constrói um objeto de valor.|  
|[map::map (STL/CLR)](../dotnet/map-map-stl-clr.md)|Constrói um objeto contêiner.|  
|[map::rbegin (STL/CLR)](../dotnet/map-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[map::rend (STL/CLR)](../dotnet/map-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[map::size (STL/CLR)](../dotnet/map-size-stl-clr.md)|Conta o número de elementos.|  
|[map::swap (STL/CLR)](../dotnet/map-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[map::to_array (STL/CLR)](../dotnet/map-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[map::upper_bound (STL/CLR)](../dotnet/map-upper-bound-stl-clr.md)|Localiza o final do intervalo que corresponde a uma chave especificada.|  
|[map::value_comp (STL/CLR)](../dotnet/map-value-comp-stl-clr.md)|Copia o delegado de ordenação de dois valores de elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[map::operator= (STL/CLR)](../dotnet/map-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[map::operator(STL/CLR)](../dotnet/map-operator-stl-clr.md)|Mapeia uma chave para seu valor mapeado associado.|  
|[operator!= (map) (STL/CLR)](../dotnet/operator-inequality-map-stl-clr.md)|Determina se um `map` objeto não é igual a outro `map` objeto.|  
|[operator< (map) (STL/CLR)](../dotnet/operator-less-than-map-stl-clr.md)|Determina se um `map` objeto é menor que outro `map` objeto.|  
|[operator<= (map) (STL/CLR)](../dotnet/operator-less-or-equal-map-stl-clr.md)|Determina se um `map` objeto é menor ou igual a outro `map` objeto.|  
|[operator== (map) (STL/CLR)](../dotnet/operator-equality-map-stl-clr.md)|Determina se um `map` objeto é igual a outro `map` objeto.|  
|[operator> (map) (STL/CLR)](../dotnet/operator-greater-than-map-stl-clr.md)|Determina se um `map` objeto é maior que outro `map` objeto.|  
|[operator>= (map) (STL/CLR)](../dotnet/operator-greater-or-equal-map-stl-clr.md)|Determina se um `map` objeto é maior que ou igual a outro `map` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|<xref:System.Collections.Generic.IDictionary%602>|Manter o grupo de {chave, valor} pares.|  
|ITree < chave, valor >|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência em que ele controla como os nós individuais. Ele insere elementos em uma árvore equilibrada (quase) que mantém ordenada alterando os links entre nós nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente, sem prejudicar elementos restantes.  
  
 O objeto classifica a sequência controla chamando um objeto de representante armazenado do tipo [Map:: key_compare (STL/CLR)](../dotnet/map-key-compare-stl-clr.md). Você pode especificar o objeto do representante armazenado quando você construir o mapa; Se você não especificar nenhum objeto do representante, o padrão é a comparação `operator<(key_type, key_type)`. Acessar esse objeto armazenado chamando a função de membro [Map:: key_comp (STL/CLR)](../dotnet/map-key-comp-stl-clr.md)`()`.  
  
 Esse é um objeto de representante deve impor uma ordenação fraca estrita nas chaves do tipo [Map:: key_type (STL/CLR)](../dotnet/map-key-type-stl-clr.md). Isso significa que, para qualquer duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)`Retorna o mesmo Boolean resultar em cada chamada.  
  
 Se `key_comp()(X, Y)` for true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` for true, em seguida, `X` deve ser ordenados antes `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` for true, em seguida, `X` e `Y` são deve ter ordenação equivalente.  
  
 Para qualquer elemento `X` que precede `Y` na sequência controlada, `key_comp()(Y, X)` é false. (Para o objeto do representante padrão, as chaves nunca diminuir em valor.) Ao contrário de classe de modelo [mapa](../dotnet/map-stl-clr.md), um objeto da classe de modelo `map` não requer que as chaves para todos os elementos sejam exclusivas. (Duas ou mais teclas podem ter ordenação equivalente).  
  
 Cada elemento contém uma chave e um valor mapeado. A sequência é representada de forma que permita a pesquisa, inserção e remoção de um elemento arbitrário com um número de operações proporcionais de logaritmo do número de elementos na sequência (logarítmica tempo). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
 Um mapa suporta iteradores bidirecional, o que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [Map:: end (STL/CLR)](../dotnet/map-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador de mapa para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento do mapa diretamente considerando sua posição numérica - que requer um iterador de acesso aleatório.  
  
 Um iterador de mapa armazena um identificador para seu nó de mapa associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador de mapa permanece válido desde que o nó de mapa associado está associado a alguns mapa. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/mapa >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [mapa](../dotnet/map-stl-clr.md)   
 [multiconjunto (STL/CLR)](../dotnet/multiset-stl-clr.md)   
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)