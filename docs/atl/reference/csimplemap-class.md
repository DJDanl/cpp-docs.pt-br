---
title: Classe CSimpleMap | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CSimpleMap
- ATL.CSimpleMap
- CSimpleMap
dev_langs:
- C++
helpviewer_keywords:
- CSimpleMap class
ms.assetid: 61b06eb4-ae73-44b0-a305-0afb5a33e8b1
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: c02ef1d9d3fafebf38abaaa55d77511f4476a02f
ms.lasthandoff: 02/25/2017

---
# <a name="csimplemap-class"></a>Classe CSimpleMap
Esta classe oferece suporte para uma matriz de mapeamento simples.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class TKey, class TVal, class TEqual = CSimpleMapEqualHelper<TKey, TVal>>  
class CSimpleMap
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TKey`  
 O tipo de elemento de chave.  
  
 `TVal`  
 O tipo de elemento de valor.  
  
 `TEqual`  
 Um objeto de traço, definindo o teste de igualdade para elementos do tipo `T`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleMap::_ArrayElementType](#_arrayelementtype)|TypeDef para o tipo de valor.|  
|[CSimpleMap::_ArrayKeyType](#_arraykeytype)|TypeDef para o tipo de chave.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleMap::CSimpleMap](#csimplemap)|O construtor.|  
|[CSimpleMap:: ~ CSimpleMap](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleMap::Add](#add)|Adiciona uma chave e o valor associado à matriz de mapa.|  
|[CSimpleMap::FindKey](#findkey)|Localiza uma chave específica.|  
|[CSimpleMap::FindVal](#findval)|Localiza um valor específico.|  
|[CSimpleMap::GetKeyAt](#getkeyat)|Recupera a chave especificada.|  
|[CSimpleMap::GetSize](#getsize)|Retorna o número de entradas na matriz de mapeamento.|  
|[CSimpleMap::GetValueAt](#getvalueat)|Recupera o valor especificado.|  
|[CSimpleMap::Lookup](#lookup)|Retorna o valor associado com a chave especificada.|  
|[CSimpleMap::Remove](#remove)|Remove uma chave e valor correspondente.|  
|[CSimpleMap::RemoveAll](#removeall)|Remove todas as chaves e valores.|  
|[CSimpleMap::RemoveAt](#removeat)|Remove uma chave específica e o valor correspondente.|  
|[CSimpleMap::ReverseLookup](#reverselookup)|Retorna a chave associada com o valor especificado.|  
|[CSimpleMap::SetAt](#setat)|Define o valor associado com a chave especificada.|  
|[CSimpleMap::SetAtIndex](#setatindex)|Define a chave e valor específico.|  
  
## <a name="remarks"></a>Comentários  
 `CSimpleMap`fornece suporte para uma matriz de mapeamento simples de qualquer tipo determinado `T`, gerenciando uma matriz não ordenada de elementos-chave e seus valores associados.  
  
 O parâmetro `TEqual` fornece uma maneira de definir uma função de igualdade de dois elementos do tipo `T`. Criando uma classe semelhante ao [CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md), é possível alterar o comportamento do teste de igualdade para qualquer matriz especificada. Por exemplo, ao lidar com uma matriz de ponteiros, pode ser útil definir a igualdade como dependendo dos valores que de ponteiros de referência. A implementação padrão utiliza **operator==()**.  
  
 Ambos `CSimpleMap` e [CSimpleArray](../../atl/reference/csimplearray-class.md) são fornecidos para compatibilidade com ATL anterior libera e implementações de coleção mais completa e eficiente são fornecidas por [CAtlArray](../../atl/reference/catlarray-class.md) e [CAtlMap](../../atl/reference/catlmap-class.md).  
  
 Ao contrário das outras coleções de mapa na ATL e MFC, essa classe é implementada com uma matriz simple e pesquisas de pesquisa requerem uma pesquisa linear. `CAtlMap`deve ser usada quando a matriz contém um grande número de elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities&#91;](../../atl/codesnippet/cpp/csimplemap-class_1.cpp)]  
  
##  <a name="a-nameadda--csimplemapadd"></a><a name="add"></a>CSimpleMap::Add  
 Adiciona uma chave e o valor associado à matriz de mapa.  
  
```
BOOL Add(const TKey& key, const TVal& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave.  
  
 *Val*  
 O valor associado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se a chave e valor foram adicionado com êxito, FALSE caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Cada par de chave e valor adicionado faz com que o mapeamento de memória seja liberada e realocada, para garantir que os dados para cada sempre são armazenados contiguamente de matriz. Ou seja, o segundo elemento chave sempre diretamente segue o primeiro elemento chave na memória e assim por diante.  
  
##  <a name="a-namearrayelementtypea--csimplemaparrayelementtype"></a><a name="_arrayelementtype"></a>CSimpleMap::_ArrayElementType  
 Um typedef para o tipo de chave.  
  
```
typedef TVal _ArrayElementType;
```  
  
##  <a name="a-namearraykeytypea--csimplemaparraykeytype"></a><a name="_arraykeytype"></a>CSimpleMap::_ArrayKeyType  
 Um typedef para o tipo de valor.  
  
```
typedef TKey _ArrayKeyType;
```  
  
##  <a name="a-namecsimplemapa--csimplemapcsimplemap"></a><a name="csimplemap"></a>CSimpleMap::CSimpleMap  
 O construtor.  
  
```
CSimpleMap();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa os membros de dados.  
  
##  <a name="a-namedtora--csimplemapcsimplemap"></a><a name="dtor"></a>CSimpleMap:: ~ CSimpleMap  
 O destruidor.  
  
```
~CSimpleMap();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="a-namefindkeya--csimplemapfindkey"></a><a name="findkey"></a>CSimpleMap::FindKey  
 Localiza uma chave específica.  
  
```
int FindKey(const TKey& key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave para pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice da tecla se encontrado, caso contrário, retornará -1.  
  
##  <a name="a-namefindvala--csimplemapfindval"></a><a name="findval"></a>CSimpleMap::FindVal  
 Localiza um valor específico.  
  
```
int FindVal(const TVal& val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *Val*  
 O valor que deseja pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna que o índice do valor se ele for encontrado, retorna -1 caso contrário.  
  
##  <a name="a-namegetkeyata--csimplemapgetkeyat"></a><a name="getkeyat"></a>CSimpleMap::GetKeyAt  
 Recupera a chave no índice especificado.  
  
```
TKey& GetKeyAt(int nIndex) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice de chave para retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a chave referenciada pela `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 O índice passado por `nIndex` deve ser válido para o valor de retorno ser significativo.  
  
##  <a name="a-namegetsizea--csimplemapgetsize"></a><a name="getsize"></a>CSimpleMap::GetSize  
 Retorna o número de entradas na matriz de mapeamento.  
  
```
int GetSize() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de entradas (uma chave e o valor é uma entrada) na matriz de mapeamento.  
  
##  <a name="a-namegetvalueata--csimplemapgetvalueat"></a><a name="getvalueat"></a>CSimpleMap::GetValueAt  
 Recupera o valor no índice específico.  
  
```
TVal& GetValueAt(int nIndex) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do valor a ser retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor referenciado por `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 O índice passado por `nIndex` deve ser válido para o valor de retorno ser significativo.  
  
##  <a name="a-namelookupa--csimplemaplookup"></a><a name="lookup"></a>CSimpleMap::Lookup  
 Retorna o valor associado com a chave especificada.  
  
```
TVal Lookup(const TKey& key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor associado. Se nenhuma chave correspondente for encontrado, nulo será retornado.  
  
##  <a name="a-nameremovea--csimplemapremove"></a><a name="remove"></a>CSimpleMap::Remove  
 Remove uma chave e valor correspondente.  
  
```
BOOL Remove(const TKey& key);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se a chave e valor correspondente, foram removido com êxito, FALSE caso contrário.  
  
##  <a name="a-nameremovealla--csimplemapremoveall"></a><a name="removeall"></a>CSimpleMap::RemoveAll  
 Remove todas as chaves e valores.  
  
```
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Remove todas as chaves e valores do objeto de mapeamento de matriz.  
  
##  <a name="a-nameremoveata--csimplemapremoveat"></a><a name="removeat"></a>CSimpleMap::RemoveAt  
 Remove uma chave e o valor associado no índice especificado.  
  
```
BOOL RemoveAt(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice de chave e valor associado a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE se o índice especificado é um índice inválido.  
  
##  <a name="a-namereverselookupa--csimplemapreverselookup"></a><a name="reverselookup"></a>CSimpleMap::ReverseLookup  
 Retorna a chave associada com o valor especificado.  
  
```
TKey ReverseLookup(const TVal& val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *Val*  
 O valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a chave associada. Se nenhuma chave correspondente for encontrado, nulo será retornado.  
  
##  <a name="a-namesetata--csimplemapsetat"></a><a name="setat"></a>CSimpleMap::SetAt  
 Define o valor associado com a chave especificada.  
  
```
BOOL SetAt(const TKey& key, const TVal& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave.  
  
 *Val*  
 O novo valor para atribuir.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se a chave foi encontrada e o valor foi alterado com êxito, FALSO caso contrário.  
  
##  <a name="a-namesetatindexa--csimplemapsetatindex"></a><a name="setatindex"></a>CSimpleMap::SetAtIndex  
 Define a chave e valor em um índice especificado.  
  
```
BOOL SetAtIndex(  
    int nIndex,
    const TKey& key,
    const TVal& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice, fazendo referência a chave e valor de emparelhamento para alterar.  
  
 `key`  
 A nova chave.  
  
 *Val*  
 O novo valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se bem-sucedido, FALSE se o índice não era válido.  
  
### <a name="remarks"></a>Comentários  
 Atualiza a chave e o valor apontado por `nIndex`.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

