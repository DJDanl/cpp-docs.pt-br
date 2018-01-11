---
title: multimapa (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::multimap
dev_langs: C++
helpviewer_keywords:
- <map> header [STL/CLR]
- <cliext/map> header [STL/CLR]
- multimap class [STL/CLR]
ms.assetid: 3dfe329d-a078-462a-b050-7999ce6110ad
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 2c42fc8d71871a70e3a2d3ffa93a78a4e42d2f53
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="multimap-stlclr"></a>multimapa (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `multimap` para gerenciar uma sequência de elementos como uma árvore equilibrada (quase) ordenada de nós, cada armazenamento de um elemento. Um elemento consiste em uma chave, para ordenar a sequência e um valor mapeado, o que vai ao longo da simultaneamente.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 em que:  
  
 `GKey`é o mesmo que `Key` , a menos que o último é um tipo de referência, caso em que é`Key^`  
  
 `GMapped`é o mesmo que `Mapped` , a menos que o último é um tipo de referência, caso em que é`Mapped^`  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class multimap  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
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
|[multimap::const_iterator (STL/CLR)](../dotnet/multimap-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[multimap::const_reference (STL/CLR)](../dotnet/multimap-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[multimap::const_reverse_iterator (STL/CLR)](../dotnet/multimap-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[multimap::difference_type (STL/CLR)](../dotnet/multimap-difference-type-stl-clr.md)|O tipo de uma distância (possivelmente assinado) entre dois elementos.|  
|[multimap::generic_container (STL/CLR)](../dotnet/multimap-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[multimap::generic_iterator (STL/CLR)](../dotnet/multimap-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[multimap::generic_reverse_iterator (STL/CLR)](../dotnet/multimap-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[multimap::generic_value (STL/CLR)](../dotnet/multimap-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[multimap::iterator (STL/CLR)](../dotnet/multimap-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[multimap::key_compare (STL/CLR)](../dotnet/multimap-key-compare-stl-clr.md)|O representante de ordenação para duas chaves.|  
|[multimap::key_type (STL/CLR)](../dotnet/multimap-key-type-stl-clr.md)|O tipo de uma chave de classificação.|  
|[multimap::mapped_type (STL/CLR)](../dotnet/multimap-mapped-type-stl-clr.md)|O tipo do valor mapeado associado a cada chave.|  
|[multimap::reference (STL/CLR)](../dotnet/multimap-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[multimap::reverse_iterator (STL/CLR)](../dotnet/multimap-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[multimap::size_type (STL/CLR)](../dotnet/multimap-size-type-stl-clr.md)|O tipo de uma distância (negativo) entre dois elementos.|  
|[multimap::value_compare (STL/CLR)](../dotnet/multimap-value-compare-stl-clr.md)|O representante de ordenação para dois valores de elemento.|  
|[multimap::value_type (STL/CLR)](../dotnet/multimap-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[multimap::begin (STL/CLR)](../dotnet/multimap-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[multimap::clear (STL/CLR)](../dotnet/multimap-clear-stl-clr.md)|Remove todos os elementos.|  
|[multimap::count (STL/CLR)](../dotnet/multimap-count-stl-clr.md)|Contagens de elementos de correspondência de uma chave especificada.|  
|[multimap::empty (STL/CLR)](../dotnet/multimap-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[multimap::end (STL/CLR)](../dotnet/multimap-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[multimap::equal_range (STL/CLR)](../dotnet/multimap-equal-range-stl-clr.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[multimap::erase (STL/CLR)](../dotnet/multimap-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[multimap::find (STL/CLR)](../dotnet/multimap-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[multimap::insert (STL/CLR)](../dotnet/multimap-insert-stl-clr.md)|Adiciona elementos.|  
|[multimap::key_comp (STL/CLR)](../dotnet/multimap-key-comp-stl-clr.md)|Copia o delegado de ordenação de duas chaves.|  
|[multimap::lower_bound (STL/CLR)](../dotnet/multimap-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[multimap::make_value (STL/CLR)](../dotnet/multimap-make-value-stl-clr.md)|Constrói um objeto de valor.|  
|[multimap::multimap (STL/CLR)](../dotnet/multimap-multimap-stl-clr.md)|Constrói um objeto contêiner.|  
|[multimap::rbegin (STL/CLR)](../dotnet/multimap-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[multimap::rend (STL/CLR)](../dotnet/multimap-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[multimap::size (STL/CLR)](../dotnet/multimap-size-stl-clr.md)|Conta o número de elementos.|  
|[multimap::swap (STL/CLR)](../dotnet/multimap-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[multimap::to_array (STL/CLR)](../dotnet/multimap-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[multimap::upper_bound (STL/CLR)](../dotnet/multimap-upper-bound-stl-clr.md)|Localiza o final do intervalo que corresponde a uma chave especificada.|  
|[multimap::value_comp (STL/CLR)](../dotnet/multimap-value-comp-stl-clr.md)|Copia o delegado de ordenação de dois valores de elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[multimap::operator= (STL/CLR)](../dotnet/multimap-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operator!= (multimap) (STL/CLR)](../dotnet/operator-inequality-multimap-stl-clr.md)|Determina se um `multimap` objeto não é igual a outro `multimap` objeto.|  
|[operator< (multimap) (STL/CLR)](../dotnet/operator-less-than-multimap-stl-clr.md)|Determina se um `multimap` objeto é menor que outro `multimap` objeto.|  
|[operator<= (multimap) (STL/CLR)](../dotnet/operator-less-or-equal-multimap-stl-clr.md)|Determina se um `multimap` objeto é menor ou igual a outro `multimap` objeto.|  
|[operator== (multimap) (STL/CLR)](../dotnet/operator-equality-multimap-stl-clr.md)|Determina se um `multimap` objeto é igual a outro `multimap` objeto.|  
|[operator> (multimap) (STL/CLR)](../dotnet/operator-greater-than-multimap-stl-clr.md)|Determina se um `multimap` objeto é maior que outro `multimap` objeto.|  
|[operator>= (multimap) (STL/CLR)](../dotnet/operator-greater-or-equal-multimap-stl-clr.md)|Determina se um `multimap` objeto é maior que ou igual a outro `multimap` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|ITree\<chave, valor >|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência em que ele controla como os nós individuais. Ele insere elementos em uma árvore equilibrada (quase) que mantém ordenada alterando os links entre nós nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente, sem prejudicar elementos restantes.  
  
 O objeto classifica a sequência controla chamando um objeto de representante armazenado do tipo [multimap:: key_compare (STL/CLR)](../dotnet/multimap-key-compare-stl-clr.md). Você pode especificar o objeto do representante armazenado quando você construir o multimap; Se você não especificar nenhum objeto do representante, o padrão é a comparação `operator<(key_type, key_type)`. Acessar esse objeto armazenado chamando a função de membro [multimap:: key_comp (STL/CLR)](../dotnet/multimap-key-comp-stl-clr.md)`()`.  
  
 Esse é um objeto de representante deve impor uma ordenação fraca estrita nas chaves do tipo [multimap:: key_type (STL/CLR)](../dotnet/multimap-key-type-stl-clr.md). Isso significa que, para qualquer duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)`Retorna o mesmo Boolean resultar em cada chamada.  
  
 Se `key_comp()(X, Y)` for true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` for true, em seguida, `X` deve ser ordenados antes `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` for true, em seguida, `X` e `Y` são deve ter ordenação equivalente.  
  
 Para qualquer elemento `X` que precede `Y` na sequência controlada, `key_comp()(Y, X)` é false. (Para o objeto do representante padrão, as chaves nunca diminuir em valor.) Ao contrário de classe de modelo [mapa (STL/CLR)](../dotnet/map-stl-clr.md), um objeto da classe de modelo `multimap` não requer que as chaves para todos os elementos sejam exclusivas. (Duas ou mais teclas podem ter ordenação equivalente).  
  
 Cada elemento contém uma chave e um valor mapeado. A sequência é representada de forma que permita a pesquisa, inserção e remoção de um elemento arbitrário com um número de operações proporcionais de logaritmo do número de elementos na sequência (logarítmica tempo). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
 Um multimap dá suporte a iteradores bidirecional, que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [multimap:: end (STL/CLR)](../dotnet/multimap-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador multimap para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento multimap diretamente considerando sua posição numérica - que requer um iterador de acesso aleatório.  
  
 Um iterador multimap armazena um identificador para o nó multimap associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador multimap permanece válido desde que seu nó multimap associado está associado a vários alguns mapeamentos. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/mapa >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_multimap (STL/CLR)](../dotnet/hash-multimap-stl-clr.md)   
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [multiconjunto (STL/CLR)](../dotnet/multiset-stl-clr.md)   
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)