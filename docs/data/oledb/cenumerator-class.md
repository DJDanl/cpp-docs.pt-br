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
ms.openlocfilehash: 6f85fafe213fa7e53f67fb6a3035f415235c8794
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49082443"
---
# <a name="cenumerator-class"></a>Classe CEnumerator

Usa um objeto de enumerador OLE DB que expõe o [ISourcesRowset](/previous-versions/windows/desktop/ms715969) interface para retornar um conjunto de linhas que descrevem todas as fontes de dados e enumeradores.  
  
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

*szSearchName*<br/>
[in] O nome a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  

**True** se o nome foi encontrado. Caso contrário, **falsos**.  
  
### <a name="remarks"></a>Comentários  

Esse nome é mapeado para o `SOURCES_NAME` membro a [ISourcesRowset](/previous-versions/windows/desktop/ms715969) interface.  
  
## <a name="getmoniker"></a> Cenumerator:: Getmoniker

Analisa o nome de exibição para extrair o componente da cadeia de caracteres que pode ser convertido em um identificador de origem.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetMoniker(LPMONIKER* ppMoniker) const throw();  

HRESULT GetMoniker(LPMONIKER* ppMoniker,   
   LPCTSTR lpszDisplayName) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*ppMoniker*<br/>
[out] O moniker analisada do nome de exibição ([cenumeratoraccessor:: M_szparsename](../../data/oledb/cenumeratoraccessor-m-szparsename.md)) da linha atual.  
  
*lpszDisplayName*<br/>
[in] O nome de exibição para analisar.  
  
### <a name="return-value"></a>Valor de retorno  

Um HRESULT padrão.  

## <a name="open"></a> Cenumerator:: Open

Associa o identificador de origem para o enumerador, se for especificado, então recupera o conjunto de linhas para o enumerador chamando [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200).  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Open(LPMONIKER pMoniker) throw();  

HRESULT Open(const CLSID* pClsid = & CLSID_OLEDB_ENUMERATOR) throw();  

HRESULT Open(const CEnumerator& enumerator) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*pMoniker*<br/>
[in] Um ponteiro para um identificador de origem para um enumerador.  
  
*pClsid*<br/>
[in] Um ponteiro para o `CLSID` de um enumerador.  
  
*enumerator*<br/>
[in] Uma referência a um enumerador.  
  
### <a name="return-value"></a>Valor de retorno  

Um HRESULT padrão.  
  
## <a name="see-also"></a>Consulte também  

[DBViewer](../../visual-cpp-samples.md)<br/>
[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)