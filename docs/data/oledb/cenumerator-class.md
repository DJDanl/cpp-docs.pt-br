---
title: Classe CEnumerator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CEnumerator
- CEnumerator::Find
- ATL::CEnumerator::Find
- ATL.CEnumerator.Find
- CEnumerator.Find
- GetMoniker
- CEnumerator.GetMoniker
- CEnumerator::GetMoniker
- ATL.CEnumerator.GetMoniker
- ATL::CEnumerator::GetMoniker
- ATL.CEnumerator.Open
- CEnumerator::Open
- ATL::CEnumerator::Open
- CEnumerator.Open
dev_langs:
- C++
helpviewer_keywords:
- CEnumerator class
- Find method
- GetMoniker method
- Open method
ms.assetid: 25805f1b-26e3-402f-af83-1b5fe5ddebf7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9f8af45082f8b861b177c4e214a69e9b15799dd7
ms.sourcegitcommit: b217daee32d3413cf33753d9b4dc35a0022b1bfa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2018
ms.locfileid: "39233367"
---
# <a name="cenumerator-class"></a>Classe CEnumerator
Usa um objeto de enumerador OLE DB que expõe o [ISourcesRowset](https://msdn.microsoft.com/library/ms715969.aspx) interface para retornar um conjunto de linhas que descrevem todas as fontes de dados e enumeradores.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CEnumerator :   
   public CAccessorRowset< CAccessor <CEnumeratorAccessor >>  
```  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Find](#find)|Pesquisa por meio de provedores disponíveis (fontes de dados) procurando um com o nome especificado.|  
|[GetMoniker](#getmoniker)|Recupera o `IMoniker` interface para o registro atual.|  
|[Abrir](#open)|Abre o enumerador.|  
  
## <a name="remarks"></a>Comentários  
 Você pode recuperar o `ISourcesRowset` dados indiretamente a partir dessa classe.  

## <a name="find"></a> Cenumerator:: Find
Procura por um nome especificado entre os provedores disponíveis.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      bool Find(TCHAR* szSearchName) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *szSearchName*  
 [in] O nome a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se o nome foi encontrado. Caso contrário, **falsos**.  
  
### <a name="remarks"></a>Comentários  
 Esse nome é mapeado para o `SOURCES_NAME` membro a [ISourcesRowset](https://msdn.microsoft.com/library/ms715969.aspx) interface.  
  
## <a name="getmoniker"></a> Cenumerator:: Getmoniker
Analisa o nome de exibição para extrair o componente da cadeia de caracteres que pode ser convertido em um identificador de origem.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetMoniker(LPMONIKER* ppMoniker) const throw();  


HRESULT GetMoniker(LPMONIKER* ppMoniker,   
   LPCTSTR lpszDisplayName) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *ppMoniker*  
 [out] O moniker analisada do nome de exibição ([cenumeratoraccessor:: M_szparsename](../../data/oledb/cenumeratoraccessor-m-szparsename.md)) da linha atual.  
  
 *lpszDisplayName*  
 [in] O nome de exibição para analisar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  

## <a name="open"></a> Cenumerator:: Open
Associa o identificador de origem para o enumerador, se for especificado, então recupera o conjunto de linhas para o enumerador chamando [ISourcesRowset:: Getsourcesrowset](https://msdn.microsoft.com/library/ms711200.aspx).  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Open(LPMONIKER pMoniker) throw();  


HRESULT Open(const CLSID* pClsid = & CLSID_OLEDB_ENUMERATOR) throw();  


HRESULT Open(const CEnumerator& enumerator) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pMoniker*  
 [in] Um ponteiro para um identificador de origem para um enumerador.  
  
 *pClsid*  
 [in] Um ponteiro para o `CLSID` de um enumerador.  
  
 *enumerator*  
 [in] Uma referência a um enumerador.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
## <a name="see-also"></a>Consulte também  
 [DBViewer](../../visual-cpp-samples.md)   
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)