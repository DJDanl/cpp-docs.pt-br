---
title: Classe IRowsetLocateImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IRowsetLocateImpl
- ATL.IRowsetLocateImpl.Compare
- IRowsetLocateImpl::Compare
- IRowsetLocateImpl.Compare
- ATL::IRowsetLocateImpl::Compare
- GetRowsAt
- IRowsetLocateImpl.GetRowsAt
- ATL::IRowsetLocateImpl::GetRowsAt
- IRowsetLocateImpl::GetRowsAt
- ATL.IRowsetLocateImpl.GetRowsAt
- IRowsetLocateImpl::GetRowsByBookmark
- IRowsetLocateImpl.GetRowsByBookmark
- GetRowsByBookmark
- IRowsetLocateImpl::Hash
- IRowsetLocateImpl.Hash
- m_rgBookmarks
- IRowsetLocateImpl::m_rgBookmarks
- ATL.IRowsetLocateImpl.m_rgBookmarks
- ATL::IRowsetLocateImpl::m_rgBookmarks
- IRowsetLocateImpl.m_rgBookmarks
dev_langs:
- C++
helpviewer_keywords:
- providers, bookmarks
- IRowsetLocateImpl class
- bookmarks, OLE DB
- Compare method
- GetRowsAt method
- GetRowsByBookmark method
- Hash method
- m_rgbookmarks
ms.assetid: a8aa3149-7ce8-4976-a680-2da193fd3234
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0cb4531f1a86d61b72363669d0f722f8dcf204d3
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39338383"
---
# <a name="irowsetlocateimpl-class"></a>Classe IRowsetLocateImpl
Implementa o OLE DB [IRowsetLocate](https://msdn.microsoft.com/library/ms721190.aspx) interface, que busca linhas arbitrárias em um conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <  
   class T,   
   class RowsetInterface,   
   class RowClass = CSimpleRow,   
   class MapClass = CAtlMap < RowClass::KeyType, RowClass* >,   
   class BookmarkKeyType = LONG,   
   class BookmarkType = LONG,   
   class BookmarkMapClass = CAtlMap < RowClass::KeyType, RowClass* >>  
class ATL_NO_VTABLE IRowsetLocateImpl : public IRowsetImpl<  
       T,   
       RowsetInterface,   
       RowClass,   
       MapClass>  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Uma classe derivada de `IRowsetLocateImpl`.  
  
 *RowsetInterface*  
 Uma classe derivada de `IRowsetImpl`.  
  
 *RowClass*  
 A unidade de armazenamento para o `HROW`.  
  
 *MapClass*  
 A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.  
  
 *BookmarkKeyType*  
 O tipo de indicador, como um longo período ou uma cadeia de caracteres. Indicadores comuns devem ter um comprimento de pelo menos dois bytes. (Comprimento de byte único é reservado para o banco de dados OLE [indicadores padrão](https://msdn.microsoft.com/library/ms712954.aspx)`DBBMK_FIRST`, `DBBMK_LAST`, e `DBBMK_INVALID`.)  
  
 *BookmarkType*  
 O mecanismo de mapeamento para manter as relações de dados de indicador.  
  
 *BookmarkMapClass*  
 A unidade de armazenamento para todos os identificadores de linha mantidos pelo indicador.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[Compare](#compare)|Compara dois indicadores.|  
|[GetRowsAt](#getrowsat)|Busca linhas começando com a linha especificada por um deslocamento de um indicador.|  
|[GetRowsByBookmark](#getrowsbybookmark)|Busque as linhas que correspondem aos indicadores especificados.|  
|[hash](#hash)|Retorna o hash valores para os indicadores especificados.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_rgBookmarks](#rgbookmarks)|Uma matriz de indicadores.|  
  
## <a name="remarks"></a>Comentários  
 `IRowsetLocateImpl` é a implementação de modelos OLE DB do [IRowsetLocate](https://msdn.microsoft.com/library/ms721190.aspx) interface. `IRowsetLocate` é usado para buscar linhas arbitrárias em um conjunto de linhas. Um conjunto de linhas que não implementa essa interface é um `sequential` conjunto de linhas. Quando `IRowsetLocate` está presente em um conjunto de linhas, a coluna 0 é o indicador das linhas; lendo esta coluna irá obter um valor de indicador que pode ser usado para reposicionar na mesma linha.  
  
 `IRowsetLocateImpl` é usado para implementar o suporte a indicadores em provedores. Os indicadores são espaços reservados (índices de um conjunto de linhas) que permitem que o consumidor retornar rapidamente a uma linha, permitindo o acesso aos dados de alta velocidade. O provedor determina o que é podem indicadores exclusivamente identificar uma linha. Usando `IRowsetLocateImpl` métodos, você pode comparar os indicadores, linhas de busca por deslocarem, em busca de linhas por indicador e retornam valores de hash de indicadores.  
  
 Para dar suporte a indicadores de OLE DB em um conjunto de linhas, verifique o conjunto de linhas herdam dessa classe.  
  
 Para obter informações sobre como implementar o suporte a indicadores, consulte [provedor oferecer suporte a indicadores](../../data/oledb/provider-support-for-bookmarks.md) na *guia do programador do Visual C++* e [indicadores](https://msdn.microsoft.com/library/ms709728.aspx) no *Referência do programador do OLE DB* na plataforma do SDK.  

## <a name="compare"></a> Irowsetlocateimpl:: Compare
Compara dois indicadores.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (Compare )(HCHAPTER /* hReserved */,  
   DBBKMARK cbBookmark1,  
   const BYTE* pBookmark1,  
   DBBKMARK cbBookmark2,  
   const BYTE* pBookmark2,  
   DBCOMPARE* pComparison);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IRowsetLocate::Compare](https://msdn.microsoft.com/library/ms709539.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 Qualquer um dos indicadores podem ser um padrão definido pelo OLE DB [indicador padrão](https://msdn.microsoft.com/library/ms712954.aspx) (`DBBMK_FIRST`, `DBBMK_LAST`, ou `DBBMK_INVALID`). O valor retornado na `pComparison` indica a relação entre os dois indicadores:  
  
-   DBCOMPARE_LT (`cbBookmark1` está antes `cbBookmark2`.)  
  
-   DBCOMPARE_EQ (`cbBookmark1` é igual a `cbBookmark2`.)  
  
-   DBCOMPARE_GT (`cbBookmark1` após `cbBookmark2`.)  
  
-   DBCOMPARE_NE (os indicadores são iguais e não ordenados).  
  
-   DBCOMPARE_NOTCOMPARABLE (não não possível comparar os indicadores.) 

## <a name="getrowsat"></a> Irowsetlocateimpl:: Getrowsat
Busca linhas começando com a linha especificada por um deslocamento de um indicador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (GetRowsAt )(HWATCHREGION /* hReserved1 */,  
   HCHAPTER hReserved2,  
   DBBKMARK cbBookmark,  
   const BYTE* pBookmark,  
   DBROWOFFSET lRowsOffset,  
   DBROWCOUNT cRows,  
   DBCOUNTITEM* pcRowsObtained,  
   HROW** prghRows);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [irowsetlocate:: Getrowsat](https://msdn.microsoft.com/library/ms723031.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 Para buscar da posição do cursor, em vez disso, use [IRowset::GetRowsAt](https://msdn.microsoft.com/library/ms723031.aspx).  
  
 `IRowsetLocateImpl::GetRowsAt` não altera a posição do cursor. 

## <a name="getrowsbybookmark"></a> Irowsetlocateimpl:: Getrowsbybookmark
Busca de uma ou mais linhas que correspondem aos indicadores especificados.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (GetRowsByBookmark )(HCHAPTER /* hReserved */,  
   DBCOUNTITEM cRows,  
   const DBBKMARK rgcbBookmarks[],  
   const BYTE* rgpBookmarks,  
   HROW rghRows[],  
   DBROWSTATUS* rgRowStatus[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hReserved*  
 [in] Corresponde ao *hChapter* parâmetro [irowsetlocate:: Getrowsbybookmark](https://msdn.microsoft.com/library/ms725420.aspx).  
  
 Para outros parâmetros, consulte [irowsetlocate:: Getrowsbybookmark](https://msdn.microsoft.com/library/ms725420.aspx) na *referência do programador DB OLE*.  
  
### <a name="remarks"></a>Comentários  
 O indicador pode ser um valor que você define ou OLE DB [indicadores padrão](https://msdn.microsoft.com/library/ms712954.aspx) (`DBBMK_FIRST` ou `DBBMK_LAST`). Não altera a posição do cursor.  

## <a name="hash"></a> Irowsetlocateimpl:: hash
Retorna o hash valores para os indicadores especificados.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (Hash )(HCHAPTER /* hReserved */,  
   DBBKMARK cbBookmarks,  
   const DBBKMARK* rgcbBookmarks[],  
   const BYTE* rgpBookmarks[],  
   DBHASHVALUE rgHashValues[],  
   DBROWSTATUS rgBookmarkStatus[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hReserved*  
 [in] Corresponde ao *hChapter* parâmetro [IRowsetLocate::Hash](https://msdn.microsoft.com/library/ms709697.aspx).  
  
 Para outros parâmetros, consulte [IRowsetLocate::Hash](https://msdn.microsoft.com/library/ms709697.aspx) na *referência do programador DB OLE*.  

## <a name="rgbookmarks"></a> Irowsetlocateimpl:: M_rgbookmarks
Uma matriz de indicadores.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
CAtlArray<DBROWCOUNT> m_rgBookmarks;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [IRowsetLocate:IRowset](https://msdn.microsoft.com/library/ms721190.aspx)   
 [Suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md)   
 [Indicadores](https://msdn.microsoft.com/library/ms709728.aspx)