---
title: Classe CBookmark | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CBookmark
- ATL::CBookmark<nSize>
- CBookmark
- ATL.CBookmark<nSize>
- ATL::CBookmark
- CBookmark<0>.CBookmark<0>
- CBookmark::CBookmark
- ATL.CBookmark.CBookmark
- CBookmark.CBookmark
- CBookmark
- ATL::CBookmark<0>::CBookmark<0>
- ATL.CBookmark<0>.CBookmark<0>
- CBookmark<0>::CBookmark<0>
- ATL::CBookmark::CBookmark
- ATL.CBookmark<0>.GetBuffer
- ATL.CBookmark.GetBuffer
- ATL::CBookmark<0>::GetBuffer
- ATL::CBookmark::GetBuffer
- CBookmark.GetBuffer
- ATL::CBookmark<nSize>::GetBuffer
- ATL.CBookmark<nSize>.GetBuffer
- CBookmark<0>.GetBuffer
- CBookmark<nSize>::GetBuffer
- CBookmark<0>::GetBuffer
- CBookmark<nSize>.GetBuffer
- CBookmark::GetBuffer
- CBookmark::GetSize
- ATL.CBookmark<nSize>.GetSize
- CBookmark<nSize>.GetSize
- CBookmark.GetSize
- ATL::CBookmark::GetSize
- CBookmark<0>::GetSize
- ATL::CBookmark<nSize>::GetSize
- ATL.CBookmark<0>.GetSize
- ATL::CBookmark<0>::GetSize
- ATL.CBookmark.GetSize
- CBookmark<0>.GetSize
- CBookmark<nSize>::GetSize
- CBookmark<0>::SetBookmark
- ATL.CBookmark<0>.SetBookmark
- CBookmark<0>.SetBookmark
- SetBookmark
- ATL::CBookmark::SetBookmark
- ATL::CBookmark<0>::SetBookmark
- CBookmark.SetBookmark
- ATL.CBookmark.SetBookmark
- CBookmark::SetBookmark
- CBookmark<0>::operator=
- CBookmark<0>.operator=
- ATL.CBookmark.operator=
- CBookmark::operator=
- ATL.CBookmark<0>.operator=
- ATL::CBookmark<0>::operator=
- CBookmark.operator=
- ATL::CBookmark::operator=
dev_langs:
- C++
helpviewer_keywords:
- CBookmark class
- CBookmark class, constructor
- GetBuffer method
- GetSize method
- SetBookmark method
- = operator, with OLE DB templates
- operator =, bookmarks
- operator=, bookmarks
ms.assetid: bc942f95-6f93-41d9-bb6e-bcdae4ae0b7a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7545a9a31ff9bd7426002ef97176c59dd308dd49
ms.sourcegitcommit: 7eadb968405bcb92ffa505e3ad8ac73483e59685
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/23/2018
ms.locfileid: "39209138"
---
# <a name="cbookmark-class"></a>Classe CBookmark
Contém um valor de indicador em seu buffer.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template < DBLENGTH nSize = 0 >  
class CBookmark : public CBookmarkBase
  
template <>  
class CBookmark< 0 > : public CBookmarkBase  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nSize*  
 O tamanho do buffer indicador em bytes. Quando *nSize* for zero, o buffer indicador será criado dinamicamente em tempo de execução.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CBookmark](#cbookmark)|O construtor|  
|[GetBuffer](#getbuffer)|Recupera o ponteiro para o buffer.|  
|[GetSize](#getsize)|Recupera o tamanho do buffer em bytes.|  
|[SetBookmark](#setbookmark)|Define o valor do indicador.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](#operator)|Atribui um `CBookmark` classe para outra.|  
  
## <a name="remarks"></a>Comentários  
 `CBookmark<0>` é uma especialização de modelo de `CBookmark`; o buffer é criado dinamicamente em tempo de execução.  

## <a name="cbookmark"></a> Cbookmark:: Cbookmark
O construtor.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      CBookmark();   

CBookmark(DBLENGTH nSize);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nSize*  
 [in] Tamanho do buffer indicador em bytes.  
  
### <a name="remarks"></a>Comentários  
 A primeira função define o buffer NULL e o tamanho do buffer como 0. A segunda função define o tamanho do buffer para *nSize*e o buffer para uma matriz de bytes *nSize* bytes.  
  
> [!NOTE]
>  Essa função só está disponível no `CBookmark<0>`. 
  
## <a name="getbuffer"></a> Cbookmark:: Getbuffer
Recupera o ponteiro para o buffer de indicador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
virtual BYTE* GetBuffer() const throw();  
  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o buffer de indicador. 

## <a name="getsize"></a> Cbookmark:: GetSize
Recupera o tamanho do buffer indicador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
virtual DBLENGTH GetSize() const throw();  
  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do buffer em bytes.  

## <a name="setbookmark"></a> Cbookmark:: Setbookmark
Copia o valor de indicador referenciado pelo *pBuffer* para o `CBookmark` armazenar em buffer e define o tamanho do buffer para *nSize*.  
  
### <a name="syntax"></a>Sintaxe  
  
```
HRESULT SetBookmark(DBLENGTH nSize,  
  BYTE* pBuffer) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nSize*  
 [in] O tamanho do buffer indicador.  
  
 *pBuffer*  
 [in] Um ponteiro para a matriz de bytes que contém o valor do indicador.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Essa função só está disponível no `CBookmark<0>`. 

## <a name="operator"></a> Cbookmark:: Operator =
Atribui um `CBookmark` objeto para outro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      CBookmark& operator =(const CBookmark& bookmark) throw();  
```  
  
### <a name="remarks"></a>Comentários  
 Esse operador é necessária somente em `CBookmark<0>`.   

## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)