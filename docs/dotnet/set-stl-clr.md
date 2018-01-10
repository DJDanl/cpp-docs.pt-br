---
title: Definir (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::set
dev_langs: C++
helpviewer_keywords:
- <cliext/set> header [STL/CLR]
- <set> header [STL/CLR]
- set class [STL/CLR]
ms.assetid: 27d3628c-741a-43a7-bef1-5085536f679e
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9624f08c54629657e7f52c2c688d2083aa557a56
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="set-stlclr"></a>set (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `set` para gerenciar uma sequência de elementos como uma árvore equilibrada (quase) ordenada de nós, cada armazenamento de um elemento.  
  
 Na descrição abaixo, `GValue` é o mesmo que `GKey`, que é o mesmo que por sua vez `Key` , a menos que o último é um tipo de referência, caso em que é `Key^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Key>  
    ref class set  
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
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[set::const_iterator (STL/CLR)](../dotnet/set-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[set::const_reference (STL/CLR)](../dotnet/set-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[set::const_reverse_iterator (STL/CLR)](../dotnet/set-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[set::difference_type (STL/CLR)](../dotnet/set-difference-type-stl-clr.md)|O tipo de uma distância (possivelmente assinado) entre dois elementos.|  
|[set::generic_container (STL/CLR)](../dotnet/set-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[set::generic_iterator (STL/CLR)](../dotnet/set-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[set::generic_reverse_iterator (STL/CLR)](../dotnet/set-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[set::generic_value (STL/CLR)](../dotnet/set-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[set::iterator (STL/CLR)](../dotnet/set-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[set::key_compare (STL/CLR)](../dotnet/set-key-compare-stl-clr.md)|O representante de ordenação para duas chaves.|  
|[set::key_type (STL/CLR)](../dotnet/set-key-type-stl-clr.md)|O tipo de uma chave de classificação.|  
|[set::reference (STL/CLR)](../dotnet/set-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[set::reverse_iterator (STL/CLR)](../dotnet/set-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[set::size_type (STL/CLR)](../dotnet/set-size-type-stl-clr.md)|O tipo de uma distância (negativo) entre dois elementos.|  
|[set::value_compare (STL/CLR)](../dotnet/set-value-compare-stl-clr.md)|O representante de ordenação para dois valores de elemento.|  
|[set::value_type (STL/CLR)](../dotnet/set-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[set::begin (STL/CLR)](../dotnet/set-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[set::clear (STL/CLR)](../dotnet/set-clear-stl-clr.md)|Remove todos os elementos.|  
|[set::count (STL/CLR)](../dotnet/set-count-stl-clr.md)|Contagens de elementos de correspondência de uma chave especificada.|  
|[set::empty (STL/CLR)](../dotnet/set-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[set::end (STL/CLR)](../dotnet/set-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[set::equal_range (STL/CLR)](../dotnet/set-equal-range-stl-clr.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[set::erase (STL/CLR)](../dotnet/set-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[set::find (STL/CLR)](../dotnet/set-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[set::insert (STL/CLR)](../dotnet/set-insert-stl-clr.md)|Adiciona elementos.|  
|[set::key_comp (STL/CLR)](../dotnet/set-key-comp-stl-clr.md)|Copia o delegado de ordenação de duas chaves.|  
|[set::lower_bound (STL/CLR)](../dotnet/set-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[set::make_value (STL/CLR)](../dotnet/set-make-value-stl-clr.md)|Constrói um objeto de valor.|  
|[set::rbegin (STL/CLR)](../dotnet/set-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[set::rend (STL/CLR)](../dotnet/set-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[set::set (STL/CLR)](../dotnet/set-set-stl-clr.md)|Constrói um objeto contêiner.|  
|[set::size (STL/CLR)](../dotnet/set-size-stl-clr.md)|Conta o número de elementos.|  
|[set::swap (STL/CLR)](../dotnet/set-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[set::to_array (STL/CLR)](../dotnet/set-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[set::upper_bound (STL/CLR)](../dotnet/set-upper-bound-stl-clr.md)|Localiza o final do intervalo que corresponde a uma chave especificada.|  
|[set::value_comp (STL/CLR)](../dotnet/set-value-comp-stl-clr.md)|Copia o delegado de ordenação de dois valores de elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[set::operator= (STL/CLR)](../dotnet/set-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operator!= (set) (STL/CLR)](../dotnet/operator-inequality-set-stl-clr.md)|Determina se um `set` objeto não é igual a outro `set` objeto.|  
|[operator< (set) (STL/CLR)](../dotnet/operator-less-than-set-stl-clr.md)|Determina se um `set` objeto é menor que outro `set` objeto.|  
|[operator<= (set) (STL/CLR)](../dotnet/operator-less-or-equal-set-stl-clr.md)|Determina se um `set` objeto é menor ou igual a outro `set` objeto.|  
|[operator== (set) (STL/CLR)](../dotnet/operator-equality-set-stl-clr.md)|Determina se um `set` objeto é igual a outro `set` objeto.|  
|[operator> (set) (STL/CLR)](../dotnet/operator-greater-than-set-stl-clr.md)|Determina se um `set` objeto é maior que outro `set` objeto.|  
|[operator>= (set) (STL/CLR)](../dotnet/operator-greater-or-equal-set-stl-clr.md)|Determina se um `set` objeto é maior que ou igual a outro `set` objeto.|  
  
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
  
 O objeto classifica a sequência controla chamando um objeto de representante armazenado do tipo [set:: key_compare (STL/CLR)](../dotnet/set-key-compare-stl-clr.md). Você pode especificar o objeto do representante armazenado quando você construir o conjunto; Se você não especificar nenhum objeto do representante, o padrão é a comparação `operator<(key_type, key_type)`. Acessar esse objeto armazenado chamando a função de membro [key_comp (STL/CLR)](../dotnet/set-key-comp-stl-clr.md)`()`.  
  
 Esse é um objeto de representante deve impor uma ordenação fraca estrita nas chaves do tipo [set:: key_type (STL/CLR)](../dotnet/set-key-type-stl-clr.md). Isso significa que, para qualquer duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)`Retorna o mesmo Boolean resultar em cada chamada.  
  
 Se `key_comp()(X, Y)` for true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` for true, em seguida, `X` deve ser ordenados antes `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` for true, em seguida, `X` e `Y` são deve ter ordenação equivalente.  
  
 Para qualquer elemento `X` que precede `Y` na sequência controlada, `key_comp()(Y, X)` é false. (Para o objeto do representante padrão, as chaves nunca diminuir em valor.) Ao contrário de classe de modelo [definir](../dotnet/set-stl-clr.md), um objeto da classe de modelo `set` não requer que as chaves para todos os elementos sejam exclusivas. (Duas ou mais teclas podem ter ordenação equivalente).  
  
 Cada elemento serve como um ey e um valor. A sequência é representada de forma que permita a pesquisa, inserção e remoção de um elemento arbitrário com um número de operações proporcionais de logaritmo do número de elementos na sequência (logarítmica tempo). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
 Um conjunto suporta iteradores bidirecional, o que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [set:: end (STL/CLR)](../dotnet/set-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador de conjunto para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de conjunto fornecido diretamente sua posição numérica - que requer um iterador de acesso aleatório.  
  
 Um iterador de conjunto armazena um identificador para seu nó de conjunto associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador de conjunto permanece válido desde que o nó do conjunto associado está associado um conjunto. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [definir](../dotnet/set-stl-clr.md)   
 [definir](../dotnet/set-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)