---
title: Classe CSimpleMap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CSimpleMap
- ATLSIMPCOLL/ATL::CSimpleMap
- ATLSIMPCOLL/ATL::CSimpleMap::_ArrayElementType
- ATLSIMPCOLL/ATL::CSimpleMap::_ArrayKeyType
- ATLSIMPCOLL/ATL::CSimpleMap::CSimpleMap
- ATLSIMPCOLL/ATL::CSimpleMap::Add
- ATLSIMPCOLL/ATL::CSimpleMap::FindKey
- ATLSIMPCOLL/ATL::CSimpleMap::FindVal
- ATLSIMPCOLL/ATL::CSimpleMap::GetKeyAt
- ATLSIMPCOLL/ATL::CSimpleMap::GetSize
- ATLSIMPCOLL/ATL::CSimpleMap::GetValueAt
- ATLSIMPCOLL/ATL::CSimpleMap::Lookup
- ATLSIMPCOLL/ATL::CSimpleMap::Remove
- ATLSIMPCOLL/ATL::CSimpleMap::RemoveAll
- ATLSIMPCOLL/ATL::CSimpleMap::RemoveAt
- ATLSIMPCOLL/ATL::CSimpleMap::ReverseLookup
- ATLSIMPCOLL/ATL::CSimpleMap::SetAt
- ATLSIMPCOLL/ATL::CSimpleMap::SetAtIndex
dev_langs:
- C++
helpviewer_keywords:
- CSimpleMap class
ms.assetid: 61b06eb4-ae73-44b0-a305-0afb5a33e8b1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 415ce3c0d6b060ffc71aa448656cf9ad45a3e7bb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32365263"
---
# <a name="csimplemap-class"></a>Classe CSimpleMap
Essa classe fornece suporte para uma matriz de mapeamento simples.  
  
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
 Um objeto de característica, definindo o teste de igualdade para elementos do tipo `T`.  
  
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
 `CSimpleMap` fornece suporte para uma matriz de mapeamento simples de qualquer tipo determinado `T`, gerenciando uma matriz não ordenada de elementos chave e seus valores associados.  
  
 O parâmetro `TEqual` fornece uma maneira de definir uma função de igualdade de dois elementos do tipo `T`. Criando uma classe semelhante ao [CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md), é possível alterar o comportamento do teste de igualdade para qualquer matriz fornecida. Por exemplo, ao lidar com uma matriz de ponteiros, pode ser útil definir a igualdade como dependendo dos valores que de ponteiros de referenciam. A implementação padrão utiliza **operator==()**.  
  
 Ambos `CSimpleMap` e [CSimpleArray](../../atl/reference/csimplearray-class.md) são fornecidos para compatibilidade com ATL anterior libera e implementações de coleção mais completa e eficiente são fornecidas pelo [CAtlArray](../../atl/reference/catlarray-class.md) e [ CAtlMap](../../atl/reference/catlmap-class.md).  
  
 Ao contrário de outras coleções de mapa na ATL e MFC, essa classe é implementada com uma matriz simple e pesquisas de pesquisa requerem uma pesquisa linear. `CAtlMap` deve ser usada quando a matriz contém um grande número de elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#91](../../atl/codesnippet/cpp/csimplemap-class_1.cpp)]  
  
##  <a name="add"></a>  CSimpleMap::Add  
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
 Retorna VERDADEIRO se a chave e valor foram adicionado com êxito, FALSE caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Cada par de chave e valor adicionado faz com que o mapeamento de memória a ser liberado e realocada, para garantir que os dados para cada sempre são armazenados contiguamente de matriz. Ou seja, o segundo elemento chave sempre logo após o primeiro elemento chave na memória e assim por diante.  
  
##  <a name="_arrayelementtype"></a>  CSimpleMap::_ArrayElementType  
 Um typedef para o tipo de chave.  
  
```
typedef TVal _ArrayElementType;
```  
  
##  <a name="_arraykeytype"></a>  CSimpleMap::_ArrayKeyType  
 Um typedef para o tipo de valor.  
  
```
typedef TKey _ArrayKeyType;
```  
  
##  <a name="csimplemap"></a>  CSimpleMap::CSimpleMap  
 O construtor.  
  
```
CSimpleMap();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa os membros de dados.  
  
##  <a name="dtor"></a>  CSimpleMap:: ~ CSimpleMap  
 O destruidor.  
  
```
~CSimpleMap();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="findkey"></a>  CSimpleMap::FindKey  
 Localiza uma chave específica.  
  
```
int FindKey(const TKey& key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave a ser pesquisada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice da tecla se encontrada, caso contrário, retornará -1.  
  
##  <a name="findval"></a>  CSimpleMap::FindVal  
 Localiza um valor específico.  
  
```
int FindVal(const TVal& val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *Val*  
 O valor pelo qual pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna que o índice do valor se ele for encontrado, caso contrário retornará -1.  
  
##  <a name="getkeyat"></a>  CSimpleMap::GetKeyAt  
 Recupera a chave no índice especificado.  
  
```
TKey& GetKeyAt(int nIndex) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice da chave a ser retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a chave referenciada por `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 O índice passado por `nIndex` deve ser válido para o valor de retorno para que seja significativo.  
  
##  <a name="getsize"></a>  CSimpleMap::GetSize  
 Retorna o número de entradas na matriz de mapeamento.  
  
```
int GetSize() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de entradas (uma chave e o valor é uma entrada) na matriz de mapeamento.  
  
##  <a name="getvalueat"></a>  CSimpleMap::GetValueAt  
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
 O índice passado por `nIndex` deve ser válido para o valor de retorno para que seja significativo.  
  
##  <a name="lookup"></a>  CSimpleMap::Lookup  
 Retorna o valor associado com a chave especificada.  
  
```
TVal Lookup(const TKey& key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor associado. Se nenhuma chave correspondente for encontrado, NULL será retornado.  
  
##  <a name="remove"></a>  CSimpleMap::Remove  
 Remove uma chave e valor correspondente.  
  
```
BOOL Remove(const TKey& key);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a chave e valor correspondente, foi removido com êxito, FALSE caso contrário.  
  
##  <a name="removeall"></a>  CSimpleMap::RemoveAll  
 Remove todas as chaves e valores.  
  
```
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Remove todas as chaves e valores do objeto de mapeamento de matriz.  
  
##  <a name="removeat"></a>  CSimpleMap::RemoveAt  
 Remove uma chave e o valor associado no índice especificado.  
  
```
BOOL RemoveAt(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice da chave e valor associado a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de sucesso, FALSO se o índice especificado é um índice inválido.  
  
##  <a name="reverselookup"></a>  CSimpleMap::ReverseLookup  
 Retorna a chave associada com o valor especificado.  
  
```
TKey ReverseLookup(const TVal& val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *Val*  
 O valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a chave associada. Se nenhuma chave correspondente for encontrado, NULL será retornado.  
  
##  <a name="setat"></a>  CSimpleMap::SetAt  
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
 Retorna VERDADEIRO se a chave foi encontrada e o valor foi alterado com êxito, FALSE caso contrário.  
  
##  <a name="setatindex"></a>  CSimpleMap::SetAtIndex  
 Define a chave e valor em um índice especificado.  
  
```
BOOL SetAtIndex(  
    int nIndex,
    const TKey& key,
    const TVal& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice, a chave e valor para alterar o emparelhamento de referência.  
  
 `key`  
 A nova chave.  
  
 *Val*  
 O novo valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se bem-sucedido e FALSO se o índice não era válido.  
  
### <a name="remarks"></a>Comentários  
 Atualiza a chave e o valor apontado por `nIndex`.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
