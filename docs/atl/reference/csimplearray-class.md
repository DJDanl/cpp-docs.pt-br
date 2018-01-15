---
title: Classe CSimpleArray | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleArray
- ATLSIMPCOLL/ATL::CSimpleArray
- ATLSIMPCOLL/ATL::CSimpleArray::CSimpleArray
- ATLSIMPCOLL/ATL::CSimpleArray::Add
- ATLSIMPCOLL/ATL::CSimpleArray::Find
- ATLSIMPCOLL/ATL::CSimpleArray::GetData
- ATLSIMPCOLL/ATL::CSimpleArray::GetSize
- ATLSIMPCOLL/ATL::CSimpleArray::Remove
- ATLSIMPCOLL/ATL::CSimpleArray::RemoveAll
- ATLSIMPCOLL/ATL::CSimpleArray::RemoveAt
- ATLSIMPCOLL/ATL::CSimpleArray::SetAtIndex
dev_langs: C++
helpviewer_keywords: CSimpleArray class
ms.assetid: ee0c9f39-b61c-4c18-bc43-4eada21dca3a
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9ea081d3868c1226638d01be9505eb9d0e01ed10
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="csimplearray-class"></a>Classe CSimpleArray
Essa classe fornece métodos para gerenciar uma matriz simples.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class TEqual = CSimpleArrayEqualHelper<T>>  
class CSimpleArray
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na matriz.  
  
 `TEqual`  
 Um objeto de característica, definindo o teste de igualdade para elementos do tipo `T`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleArray::CSimpleArray](#csimplearray)|O construtor para a matriz simple.|  
|[CSimpleArray:: ~ CSimpleArray](#dtor)|O destruidor da matriz simples.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleArray::Add](#add)|Adiciona um novo elemento na matriz.|  
|[CSimpleArray::Find](#find)|Localiza um elemento na matriz.|  
|[CSimpleArray::GetData](#getdata)|Retorna um ponteiro para os dados armazenados na matriz.|  
|[CSimpleArray::GetSize](#getsize)|Retorna o número de elementos armazenados na matriz.|  
|[CSimpleArray::Remove](#remove)|Remove um determinado elemento da matriz.|  
|[CSimpleArray::RemoveAll](#removeall)|Remove todos os elementos da matriz.|  
|[CSimpleArray::RemoveAt](#removeat)|Remove o elemento especificado da matriz.|  
|[CSimpleArray::SetAtIndex](#setatindex)|Define o elemento especificado na matriz.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleArray::operator\[\]](#operator_at)|Recupera um elemento da matriz.|  
|[CSimpleArray::operator =](#operator_eq)|Operador de atribuição.|  

  
## <a name="remarks"></a>Comentários  
 `CSimpleArray`fornece métodos para criar e gerenciar uma matriz simples, de qualquer tipo determinado `T`.  
  
 O parâmetro `TEqual` fornece uma maneira de definir uma função de igualdade de dois elementos do tipo `T`. Criando uma classe semelhante ao [CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md), é possível alterar o comportamento do teste de igualdade para qualquer matriz fornecida. Por exemplo, ao lidar com uma matriz de ponteiros, pode ser útil definir a igualdade como dependendo dos valores que de ponteiros de referenciam. A implementação padrão utiliza **operator=()**.  
  
 Ambos `CSimpleArray` e [CSimpleMap](../../atl/reference/csimplemap-class.md) são projetados para um pequeno número de elementos. [CAtlArray](../../atl/reference/catlarray-class.md) e [CAtlMap](../../atl/reference/catlmap-class.md) deve ser usada quando a matriz contém um grande número de elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#86](../../atl/codesnippet/cpp/csimplearray-class_1.cpp)]  
  
##  <a name="add"></a>CSimpleArray::Add  
 Adiciona um novo elemento na matriz.  
  
```
BOOL Add(const T& t);
```  
  
### <a name="parameters"></a>Parâmetros  
 *t*  
 O elemento a ser adicionado à matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se o elemento é adicionado com êxito para a matriz, FALSO caso contrário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#87](../../atl/codesnippet/cpp/csimplearray-class_2.cpp)]  
  
##  <a name="csimplearray"></a>CSimpleArray::CSimpleArray  
 O construtor para o objeto de matriz.  
  
```
CSimpleArray(const CSimpleArray<T, TEqual>& src);  
CSimpleArray();
```     
  
### <a name="parameters"></a>Parâmetros  
 *src*  
 Um objeto `CSimpleArray` existente.  
  
### <a name="remarks"></a>Comentários  
 Inicializa os membros de dados, criando um novo vazio `CSimpleArray` objeto ou uma cópia de um objeto existente `CSimpleArray` objeto.  
  
##  <a name="dtor"></a>CSimpleArray:: ~ CSimpleArray  
 O destruidor.  
  
```
~CSimpleArray();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="find"></a>CSimpleArray::Find  
 Localiza um elemento na matriz.  
  
```
int Find(const T& t) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *t*  
 O elemento a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice do elemento encontrado, ou -1 se o elemento não for encontrado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#88](../../atl/codesnippet/cpp/csimplearray-class_3.cpp)]  
  
##  <a name="getdata"></a>CSimpleArray::GetData  
 Retorna um ponteiro para os dados armazenados na matriz.  
  
```
T* GetData() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para os dados na matriz.  
  
##  <a name="getsize"></a>CSimpleArray::GetSize  
 Retorna o número de elementos armazenados na matriz.  
  
```
int GetSize() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos armazenados na matriz.  
  
##  <a name="operator_at"></a>CSimpleArray::operator\[\]  
 Recupera um elemento da matriz.  
  
```
T& operator[](int nindex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o elemento da matriz referenciado por `nIndex`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#89](../../atl/codesnippet/cpp/csimplearray-class_4.cpp)]  
  
##  <a name="operator_eq"></a>CSimpleArray::operator =  
 Operador de atribuição.  
  
```
CSimpleArray<T, TEqual>
& operator=(
    const CSimpleArray<T, TEqual>& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 *src*  
 A matriz a ser copiada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a atualização `CSimpleArray` objeto.  
  
### <a name="remarks"></a>Comentários  
 Copia todos os elementos do `CSimpleArray` objeto referenciado por *src* no objeto de matriz atual, substituindo todos os dados existentes.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#90](../../atl/codesnippet/cpp/csimplearray-class_5.cpp)]  
  
##  <a name="remove"></a>CSimpleArray::Remove  
 Remove um determinado elemento da matriz.  
  
```
BOOL Remove(const T& t);
```  
  
### <a name="parameters"></a>Parâmetros  
 *t*  
 Elemento a ser removido da matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se o elemento for encontrado e removido, FALSE caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Quando um elemento for removido, os elementos restantes na matriz são renumerados para preencher o espaço vazio.  
  
##  <a name="removeall"></a>CSimpleArray::RemoveAll  
 Remove todos os elementos da matriz.  
  
```
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Remove todos os elementos armazenados atualmente na matriz.  
  
##  <a name="removeat"></a>CSimpleArray::RemoveAt  
 Remove o elemento especificado da matriz.  
  
```
BOOL RemoveAtint nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice apontando para o elemento a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se o elemento foi removido, FALSO se o índice é inválido.  
  
### <a name="remarks"></a>Comentários  
 Quando um elemento for removido, os elementos restantes na matriz são renumerados para preencher o espaço vazio.  
  
##  <a name="setatindex"></a>CSimpleArray::SetAtIndex  
 Defina o elemento especificado na matriz.  
  
```
BOOL SetAtIndex(
    int nIndex,
    const T& t);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do elemento para alterar.  
  
 *t*  
 O valor a ser atribuído ao elemento especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se bem-sucedido e FALSO se o índice não era válido.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
