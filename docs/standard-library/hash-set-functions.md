---
title: "Funções &lt;hash_set&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 557a0162-3728-4537-97dc-f9f6cc7ece94
caps.latest.revision: 7
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1238f4a4e75f13ccd660554de8c49646549bc2cc
ms.lasthandoff: 02/25/2017

---
# <a name="lthashsetgt-functions"></a>Funções &lt;hash_set&gt;
|||  
|-|-|  
|[swap](#swap)|[swap (hash_multiset)](#swap__hash_multiset_)|  
  
##  <a name="a-nameswapa--swap"></a><a name="swap"></a>  swap  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Troca os elementos de dois hash_sets.  
  
```
void swap(
    hash_set <Key, Traits, Allocator>& left,
    hash_set <Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O hash_set que fornece os elementos a serem trocados ou o hash_set cujos elementos deverão ser trocados pelos do hash_set `left`.  
  
 `left`  
 O hash_set cujos elementos serão trocados por aqueles do hash_set `right`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo `swap` é um algoritmo especializado na classe de contêiner hash_set para executar a função membro `left``.`[swap](../standard-library/hash-set-class.md#hash_set__swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo  
  
 **modelo \<classe T> void swap(T&, T&),**  
  
 na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de código da função de membro [hash_multiset::swap](../standard-library/hash-set-class.md#hash_set__swap) para obter um exemplo que usa a versão de modelo do `swap`.  
  
##  <a name="a-nameswaphashmultiseta--swap-hashmultiset"></a><a name="swap__hash_multiset_"></a>  swap (hash_multiset)  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Troca os elementos de dois hash_multisets.  
  
```
void swap(hash_multiset <Key, Traits, Allocator>& left, hash_multiset <Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O hash_multiset que fornece os elementos a serem trocados ou o hash_multiset cujos elementos deverão ser trocados pelos do hash_multiset `left`.  
  
 `left`  
 O hash_multiset cujos elementos serão trocados por aqueles do hash_multiset `right`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo `swap` é um algoritmo especializado na classe de contêiner hash_multiset para executar a função membro `left``.`[swap](../standard-library/hash-multiset-class.md#hash_multiset__swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo  
  
 **modelo \<classe T> void swap(T&, T&),**  
  
 na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de código da classe de membro [hash_multiset::swap](../standard-library/hash-multiset-class.md#hash_multiset__swap) para obter um exemplo que usa a versão de modelo do `swap`.  
  
## <a name="see-also"></a>Consulte também  
 [<hash_set>](../standard-library/hash-set.md)




