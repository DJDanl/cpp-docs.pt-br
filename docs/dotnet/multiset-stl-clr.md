---
title: multiconjunto (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::multiset
dev_langs:
- C++
helpviewer_keywords:
- <cliext/set> header [STL/CLR]
- <set> header [STL/CLR]
- multiset class [STL/CLR]
ms.assetid: 7c46e2b4-cd88-49b7-a9e6-63ad5ae7feb5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 3e01ec2d9c426d6b95b12fe0db9e5a2e328ae1cc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="multiset-stlclr"></a>multiset (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `multiset` para gerenciar uma sequência de elementos como uma árvore equilibrada (quase) ordenada de nós, cada armazenamento de um elemento.  
  
 Na descrição abaixo, `GValue` é o mesmo que `GKey`, que é o mesmo que por sua vez `Key` , a menos que o último é um tipo de referência, caso em que é `Key^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Key>  
    ref class multiset  
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
|[multiset::const_iterator (STL/CLR)](../dotnet/multiset-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[multiset::const_reference (STL/CLR)](../dotnet/multiset-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[multiset::const_reverse_iterator (STL/CLR)](../dotnet/multiset-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[multiset::difference_type (STL/CLR)](../dotnet/multiset-difference-type-stl-clr.md)|O tipo de uma distância (possivelmente assinado) entre dois elementos.|  
|[multiset::generic_container (STL/CLR)](../dotnet/multiset-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[multiset::generic_iterator (STL/CLR)](../dotnet/multiset-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[multiset::generic_reverse_iterator (STL/CLR)](../dotnet/multiset-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[multiset::generic_value (STL/CLR)](../dotnet/multiset-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[multiset::iterator (STL/CLR)](../dotnet/multiset-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[multiset::key_compare (STL/CLR)](../dotnet/multiset-key-compare-stl-clr.md)|O representante de ordenação para duas chaves.|  
|[multiset::key_type (STL/CLR)](../dotnet/multiset-key-type-stl-clr.md)|O tipo de uma chave de classificação.|  
|[multiset::reference (STL/CLR)](../dotnet/multiset-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[multiset::reverse_iterator (STL/CLR)](../dotnet/multiset-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[multiset::size_type (STL/CLR)](../dotnet/multiset-size-type-stl-clr.md)|O tipo de uma distância (negativo) entre dois elementos.|  
|[multiset::value_compare (STL/CLR)](../dotnet/multiset-value-compare-stl-clr.md)|O representante de ordenação para dois valores de elemento.|  
|[multiset::value_type (STL/CLR)](../dotnet/multiset-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[multiset::begin (STL/CLR)](../dotnet/multiset-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[multiset::clear (STL/CLR)](../dotnet/multiset-clear-stl-clr.md)|Remove todos os elementos.|  
|[multiset::count (STL/CLR)](../dotnet/multiset-count-stl-clr.md)|Contagens de elementos de correspondência de uma chave especificada.|  
|[multiset::empty (STL/CLR)](../dotnet/multiset-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[multiset::end (STL/CLR)](../dotnet/multiset-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[multiset::equal_range (STL/CLR)](../dotnet/multiset-equal-range-stl-clr.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[multiset::erase (STL/CLR)](../dotnet/multiset-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[multiset::find (STL/CLR)](../dotnet/multiset-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[multiset::insert (STL/CLR)](../dotnet/multiset-insert-stl-clr.md)|Adiciona elementos.|  
|[multiset::key_comp (STL/CLR)](../dotnet/multiset-key-comp-stl-clr.md)|Copia o delegado de ordenação de duas chaves.|  
|[multiset::lower_bound (STL/CLR)](../dotnet/multiset-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[multiset::make_value (STL/CLR)](../dotnet/multiset-make-value-stl-clr.md)|Constrói um objeto de valor.|  
|[multiset::multiset (STL/CLR)](../dotnet/multiset-multiset-stl-clr.md)|Constrói um objeto contêiner.|  
|[multiset::rbegin (STL/CLR)](../dotnet/multiset-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[multiset::rend (STL/CLR)](../dotnet/multiset-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[multiset::size (STL/CLR)](../dotnet/multiset-size-stl-clr.md)|Conta o número de elementos.|  
|[multiset::swap (STL/CLR)](../dotnet/multiset-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[multiset::to_array (STL/CLR)](../dotnet/multiset-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[multiset::upper_bound (STL/CLR)](../dotnet/multiset-upper-bound-stl-clr.md)|Localiza o final do intervalo que corresponde a uma chave especificada.|  
|[multiset::value_comp (STL/CLR)](../dotnet/multiset-value-comp-stl-clr.md)|Copia o delegado de ordenação de dois valores de elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[multiset::operator= (STL/CLR)](../dotnet/multiset-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operator!= (multiset) (STL/CLR)](../dotnet/operator-inequality-multiset-stl-clr.md)|Determina se um `multiset` objeto não é igual a outro `multiset` objeto.|  
|[operator< (multiset) (STL/CLR)](../dotnet/operator-less-than-multiset-stl-clr.md)|Determina se um `multiset` objeto é menor que outro `multiset` objeto.|  
|[operator<= (multiset) (STL/CLR)](../dotnet/operator-less-or-equal-multiset-stl-clr.md)|Determina se um `multiset` objeto é menor ou igual a outro `multiset` objeto.|  
|[operator== (multiset) (STL/CLR)](../dotnet/operator-equality-multiset-stl-clr.md)|Determina se um `multiset` objeto é igual a outro `multiset` objeto.|  
|[operator> (multiset) (STL/CLR)](../dotnet/operator-greater-than-multiset-stl-clr.md)|Determina se um `multiset` objeto é maior que outro `multiset` objeto.|  
|[operator>= (multiset) (STL/CLR)](../dotnet/operator-greater-or-equal-multiset-stl-clr.md)|Determina se um `multiset` objeto é maior que ou igual a outro `multiset` objeto.|  
  
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
  
 O objeto classifica a sequência controla chamando um objeto de representante armazenado do tipo [multiset:: key_compare (STL/CLR)](../dotnet/multiset-key-compare-stl-clr.md). Você pode especificar o objeto do representante armazenado quando você construir o multiconjunto; Se você não especificar nenhum objeto do representante, o padrão é a comparação `operator<(key_type, key_type)`. Acessar esse objeto armazenado chamando a função de membro [multiset:: key_comp (STL/CLR)](../dotnet/multiset-key-comp-stl-clr.md)`()`.  
  
 Esse é um objeto de representante deve impor uma ordenação fraca estrita nas chaves do tipo [multiset:: key_type (STL/CLR)](../dotnet/multiset-key-type-stl-clr.md). Isso significa que, para qualquer duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` Retorna o mesmo Boolean resultar em cada chamada.  
  
 Se `key_comp()(X, Y)` for true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` for true, em seguida, `X` deve ser ordenados antes `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` for true, em seguida, `X` e `Y` são deve ter ordenação equivalente.  
  
 Para qualquer elemento `X` que precede `Y` na sequência controlada, `key_comp()(Y, X)` é false. (Para o objeto do representante padrão, as chaves nunca diminuir em valor.) Ao contrário de classe de modelo [definido (STL/CLR)](../dotnet/set-stl-clr.md), um objeto da classe de modelo `multiset` não requer que as chaves para todos os elementos sejam exclusivas. (Duas ou mais teclas podem ter ordenação equivalente).  
  
 Cada elemento serve como um ey e um valor. A sequência é representada de forma que permita a pesquisa, inserção e remoção de um elemento arbitrário com um número de operações proporcionais de logaritmo do número de elementos na sequência (logarítmica tempo). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
 Um multiconjunto suporta iteradores bidirecional, o que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [multiset:: end (STL/CLR)](../dotnet/multiset-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador multiset para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento multiset diretamente considerando sua posição numérica - que requer um iterador de acesso aleatório.  
  
 Um iterador multiset armazena um identificador para o nó multiset associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador multiset permanece válido desde que o nó multiset associado está associado a alguns multiset. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [multiset](../dotnet/multiset-stl-clr.md)   
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)