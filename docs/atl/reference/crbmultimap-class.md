---
title: Classe CRBMultiMap | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRBMultiMap
- ATLCOLL/ATL::CRBMultiMap
- ATLCOLL/ATL::CRBMultiMap::CRBMultiMap
- ATLCOLL/ATL::CRBMultiMap::FindFirstWithKey
- ATLCOLL/ATL::CRBMultiMap::GetNextValueWithKey
- ATLCOLL/ATL::CRBMultiMap::GetNextWithKey
- ATLCOLL/ATL::CRBMultiMap::Insert
- ATLCOLL/ATL::CRBMultiMap::RemoveKey
dev_langs: C++
helpviewer_keywords: CRBMultiMap class
ms.assetid: 94d3ec0c-3e30-4ab7-a101-d8da4fb8add3
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 79ef7fdd5799b01ec115befcd50bbe4625d48bea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crbmultimap-class"></a>Classe CRBMultiMap
Essa classe representa uma estrutura de mapeamento que permite que cada chave pode ser associado a mais de um valor, usando uma árvore binária vermelho-preto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename K,
         typename V, 
         class KTraits = CElementTraits<K>, 
         class VTraits = CElementTraits<V>>  
class CRBMultiMap : public CRBTree<K, V, KTraits, VTraits>
```    
  
#### <a name="parameters"></a>Parâmetros  
 `K`  
 O tipo de elemento de chave.  
  
 *V*  
 O tipo de elemento de valor.  
  
 `KTraits`  
 O código usado para copiar ou mover os elementos principais. Consulte [CElementTraits classe](../../atl/reference/celementtraits-class.md) para obter mais detalhes.  
  
 `VTraits`  
 O código usado para copiar ou mover os elementos de valor.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRBMultiMap::CRBMultiMap](#crbmultimap)|O construtor.|  
|[CRBMultiMap:: ~ CRBMultiMap](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRBMultiMap::FindFirstWithKey](#findfirstwithkey)|Chame este método para localizar a posição do primeiro elemento com uma determinada chave.|  
|[CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey)|Chame esse método para obter o valor associado com uma determinada chave e atualize o valor da posição.|  
|[CRBMultiMap::GetNextWithKey](#getnextwithkey)|Chame esse método para obter o elemento associado a uma determinada chave e atualize o valor da posição.|  
|[CRBMultiMap::Insert](#insert)|Chame este método para inserir um par de elemento no mapa.|  
|[CRBMultiMap::RemoveKey](#removekey)|Chame esse método para remover todos os elementos de chave/valor para uma determinada chave.|  
  
## <a name="remarks"></a>Comentários  
 `CRBMultiMap`fornece suporte para uma matriz de mapeamento de qualquer tipo determinado, gerenciando uma matriz ordenada de elementos chave e valores. Ao contrário de [CRBMap](../../atl/reference/crbmap-class.md) classe, cada chave pode ser associado a mais de um valor.  
  
 Os elementos (consistindo de uma chave e um valor) são armazenados em uma árvore binária estrutura, usando o [CRBMultiMap::Insert](#insert) método. Elementos podem ser removidos usando o [CRBMultiMap::RemoveKey](#removekey) método, que exclui todos os elementos que correspondem a chave especificada.  
  
 Percorrendo a árvore é possibilitado com métodos como [CRBTree::GetHeadPosition](../../atl/reference/crbtree-class.md#getheadposition), [CRBTree::GetNext](../../atl/reference/crbtree-class.md#getnext), e [CRBTree::GetNextValue](../../atl/reference/crbtree-class.md#getnextvalue). Acessando o potencialmente vários valores por chave é possível usar o [CRBMultiMap::FindFirstWithKey](#findfirstwithkey), [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey), e [CRBMultiMap::GetNextWithKey ](#getnextwithkey) métodos. Consulte o exemplo para [CRBMultiMap::CRBMultiMap](#crbmultimap) para obter uma ilustração isso na prática.  
  
 O `KTraits` e `VTraits` são classes de características que contêm qualquer código complementar necessário para copiar ou mover os elementos de parâmetros.  
  
 `CRBMultiMap`é derivado de [CRBTree](../../atl/reference/crbtree-class.md), que implementa uma árvore binária usando o algoritmo de vermelho-preto. Uma alternativa para `CRBMultiMap` e `CRBMap` é oferecida pelo [CAtlMap](../../atl/reference/catlmap-class.md) classe. Quando somente um pequeno número de elementos precisa ser armazenados, considere o uso de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe em vez disso.  
  
 Para obter uma discussão mais completa de várias classes de coleção e seus recursos e características de desempenho, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CRBTree](../../atl/reference/crbtree-class.md)  
  
 `CRBMultiMap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="crbmultimap"></a>CRBMultiMap::CRBMultiMap  
 O construtor.  
  
```
explicit CRBMultiMap(size_t nBlockSize = 10) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 O tamanho do bloco.  
  
### <a name="remarks"></a>Comentários  
 O `nBlockSize` parâmetro é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem as chamadas para rotinas de alocação de memória, mas usam mais recursos. O padrão será alocar espaço para elementos de 10 por vez.  
  
 Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#85](../../atl/codesnippet/cpp/crbmultimap-class_1.cpp)]  
  
##  <a name="dtor"></a>CRBMultiMap:: ~ CRBMultiMap  
 O destruidor.  
  
```
~CRBMultiMap() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
 Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.  
  
##  <a name="findfirstwithkey"></a>CRBMultiMap::FindFirstWithKey  
 Chame este método para localizar a posição do primeiro elemento com uma determinada chave.  
  
```
POSITION FindFirstWithKey(KINARGTYPE key) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Especifica a chave que identifica o elemento a ser localizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a chave for encontrada, NULL caso contrário, retorna a posição do primeiro elemento de chave/valor.  
  
### <a name="remarks"></a>Comentários  
 Uma chave de `CRBMultiMap` pode ter um ou mais valores associados. Esse método fornecerá o valor da posição do primeiro valor (que pode, na verdade, ser o único valor) associado a essa chave particular. O valor da posição retornado, em seguida, pode ser usado com [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey) ou [CRBMultiMap::GetNextWithKey](#getnextwithkey) para obter o valor e atualizar a posição.  
  
 Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CRBMultiMap::CRBMultiMap](#crbmultimap).  
  
##  <a name="getnextvaluewithkey"></a>CRBMultiMap::GetNextValueWithKey  
 Chame esse método para obter o valor associado com uma determinada chave e atualize o valor da posição.  
  
```
const V& GetNextValueWithKey(
    POSITION& pos,
    KINARGTYPE key) const throw();
V& GetNextValueWithKey(
    POSITION& pos,
    KINARGTYPE key) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O valor da posição, obtido com a chamada para [CRBMultiMap::FindFirstWithKey](#findfirstwithkey) ou [CRBMultiMap::GetNextWithKey](#getnextwithkey), ou uma chamada anterior para `GetNextValueWithKey`.  
  
 `key`  
 Especifica a chave que identifica o elemento a ser localizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o par de elemento associado com a chave especificada.  
  
### <a name="remarks"></a>Comentários  
 O valor da posição é atualizado para apontar para o próximo valor associado à chave. Se não existem mais valores, o valor da posição é definido como NULL.  
  
 Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CRBMultiMap::CRBMultiMap](#crbmultimap).  
  
##  <a name="getnextwithkey"></a>CRBMultiMap::GetNextWithKey  
 Chame esse método para obter o elemento associado a uma determinada chave e atualize o valor da posição.  
  
```
const CPair* GetNextWithKey(
    POSITION& pos,
    KINARGTYPE key) const throw();
CPair* GetNextWithKey(
    POSITION& pos,
    KINARGTYPE key) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O valor da posição, obtido com a chamada para [CRBMultiMap::FindFirstWithKey](#findfirstwithkey) ou [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey), ou uma chamada anterior para `GetNextWithKey`.  
  
 `key`  
 Especifica a chave que identifica o elemento a ser localizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o próximo [CRBTree::CPair classe](crbtree-class.md#cpair_class) elemento associado com a chave especificada.  
  
### <a name="remarks"></a>Comentários  
 O valor da posição é atualizado para apontar para o próximo valor associado à chave. Se não existem mais valores, o valor da posição é definido como NULL.  
  
 Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.  
  
##  <a name="insert"></a>CRBMultiMap::Insert  
 Chame este método para inserir um par de elemento no mapa.  
  
```
POSITION Insert(KINARGTYPE key, VINARGTYPE value) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 O valor da chave para adicionar ao `CRBMultiMap` objeto.  
  
 *value*  
 O valor a ser adicionado para o `CRBMultiMap` objeto, associado a `key`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a posição do par chave/valor de elemento no `CRBMultiMap` objeto.  
  
### <a name="remarks"></a>Comentários  
 Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CRBMultiMap::CRBMultiMap](#crbmultimap).  
  
##  <a name="removekey"></a>CRBMultiMap::RemoveKey  
 Chame esse método para remover todos os elementos de chave/valor para uma determinada chave.  
  
```
size_t RemoveKey(KINARGTYPE key) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Especifica a chave que identifica o elemento (s) a ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de valores associados com a chave especificada.  
  
### <a name="remarks"></a>Comentários  
 `RemoveKey`Exclui todos os elementos de chave/valor que tenha uma chave que corresponde a `key`.  
  
 Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CRBMultiMap::CRBMultiMap](#crbmultimap).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRBTree](../../atl/reference/crbtree-class.md)   
 [Classe CAtlMap](../../atl/reference/catlmap-class.md)   
 [Classe CRBMap](../../atl/reference/crbmap-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
