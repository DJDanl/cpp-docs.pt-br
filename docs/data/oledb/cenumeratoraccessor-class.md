---
title: Classe CEnumeratorAccessor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::CEnumeratorAccessor
- CEnumeratorAccessor
- ATL.CEnumeratorAccessor
- CEnumeratorAccessor.m_bIsParent
- ATL::CEnumeratorAccessor::m_bIsParent
- m_bIsParent
- ATL.CEnumeratorAccessor.m_bIsParent
- CEnumeratorAccessor::m_bIsParent
- ATL::CEnumeratorAccessor::m_nType
- CEnumeratorAccessor.m_nType
- CEnumeratorAccessor::m_nType
- ATL.CEnumeratorAccessor.m_nType
- m_nType
- ATL::CEnumeratorAccessor::m_szDescription
- CEnumeratorAccessor.m_szDescription
- CEnumeratorAccessor::m_szDescription
- ATL.CEnumeratorAccessor.m_szDescription
- CEnumeratorAccessor::m_szName
- ATL.CEnumeratorAccessor.m_szName
- m_szName
- ATL::CEnumeratorAccessor::m_szName
- CEnumeratorAccessor.m_szName
- CEnumeratorAccessor::m_szParseName
- ATL::CEnumeratorAccessor::m_szParseName
- m_szParseName
- CEnumeratorAccessor.m_szParseName
- ATL.CEnumeratorAccessor.m_szParseName
dev_langs:
- C++
helpviewer_keywords:
- CEnumeratorAccessor class
- m_bIsParent
- m_nType
- m_szDescription
- m_szName
- m_szParseName
ms.assetid: 21e8e7ea-3511-4afe-b33f-d520f4ff82bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d87bcf20957b69577e709c8fcbd2c6a5f3c9b770
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46075900"
---
# <a name="cenumeratoraccessor-class"></a>Classe CEnumeratorAccessor

Usado pelo [CEnumerator](../../data/oledb/cenumerator-class.md) para acessar os dados do conjunto de linhas do enumerador.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CEnumeratorAccessor  
```  

## <a name="requirements"></a>Requisitos  

**Cabeçalho:** atldbcli.h  
  
## <a name="members"></a>Membros  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_bIsParent](#bisparent)|Uma variável que indica se o enumerador é um enumerador pai, se a linha é um enumerador.|  
|[m_nType](#ntype)|Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.|  
|[m_szDescription](#szdescription)|A descrição da fonte de dados ou enumerador.|  
|[m_szName](#szname)|O nome da fonte de dados ou enumerador.|  
|[m_szParseName](#szparsename)|Cadeia de caracteres para passar para [IParseDisplayName](/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) para obter um identificador de origem para a fonte de dados ou enumerador.|  
  
## <a name="remarks"></a>Comentários  

Esse conjunto de linhas consiste nas fontes de dados e enumeradores visíveis do enumerador atual.  
  
## <a name="bisparent"></a> Cenumeratoraccessor:: M_bisparent

Uma variável que indica se o enumerador é um enumerador pai, se a linha é um enumerador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
VARIANT_BOOL m_bIsParent;  
```  
  
### <a name="remarks"></a>Comentários  

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200\(v=vs.85\)) na *referência do programador DB OLE* para obter mais informações. 

## <a name="ntype"></a> Cenumeratoraccessor:: M_ntype

Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
USHORT m_nType;  
```  
  
### <a name="remarks"></a>Comentários  

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200\(v=vs.85\)) na *referência do programador DB OLE* para obter mais informações.

## <a name="szdescription"></a> Cenumeratoraccessor:: M_szdescription

A descrição da fonte de dados ou enumerador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
WCHAR m_szDescription[129];  
```  
  
### <a name="remarks"></a>Comentários  

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200\(v=vs.85\)) na *referência do programador DB OLE* para obter mais informações.

## <a name="szname"></a> Cenumeratoraccessor:: M_szname

O nome da fonte de dados ou enumerador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
WCHAR m_szName[129];  
```  
  
### <a name="remarks"></a>Comentários  

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200\(v=vs.85\)) na *referência do programador DB OLE* para obter mais informações.  

## <a name="szparsename"></a> Cenumeratoraccessor:: M_szparsename

Cadeia de caracteres para passar para [IParseDisplayName](/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) para obter um identificador de origem para a fonte de dados ou enumerador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
WCHAR m_szParseName[129];  
```  
  
### <a name="remarks"></a>Comentários  

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200\(v=vs.85\)) na *referência do programador DB OLE* para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)