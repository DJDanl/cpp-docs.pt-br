---
title: Classe IRowsetLocateImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IRowsetLocateImpl
dev_langs:
- C++
helpviewer_keywords:
- providers, bookmarks
- IRowsetLocateImpl class
- bookmarks, OLE DB
ms.assetid: a8aa3149-7ce8-4976-a680-2da193fd3234
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 27af767c9104159d6c398db226a5a45a36e01e2f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="irowsetlocateimpl-class"></a>Classe IRowsetLocateImpl
Implementa o OLE DB [IRowsetLocate](https://msdn.microsoft.com/en-us/library/ms721190.aspx) interface, que busca linhas arbitrárias de um conjunto de linhas.  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada de `IRowsetLocateImpl`.  
  
 `RowsetInterface`  
 Uma classe derivada de `IRowsetImpl`.  
  
 `RowClass`  
 A unidade de armazenamento para o **HROW**.  
  
 `MapClass`  
 A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.  
  
 `BookmarkKeyType`  
 O tipo de indicador, como uma LONGA ou uma cadeia de caracteres. Indicadores comuns devem ter um comprimento de pelo menos dois bytes. (Comprimento de byte único é reservado para o OLE DB [indicadores padrão](https://msdn.microsoft.com/en-us/library/ms712954.aspx)**DBBMK_FIRST**, **DBBMK_LAST**, e **DBBMK_INVALID**.)  
  
 `BookmarkType`  
 O mecanismo de mapeamento para manter as relações de dados de indicador.  
  
 `BookmarkMapClass`  
 A unidade de armazenamento para todos os identificadores de linha mantidos pelo indicador.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[Compare](../../data/oledb/irowsetlocateimpl-compare.md)|Compara dois indicadores.|  
|[GetRowsAt](../../data/oledb/irowsetlocateimpl-getrowsat.md)|Busca de linhas que começam com a linha especificada por um deslocamento de um indicador.|  
|[GetRowsByBookmark](../../data/oledb/irowsetlocateimpl-getrowsbybookmark.md)|Busque as linhas que correspondem os marcadores especificados.|  
|[Hash](../../data/oledb/irowsetlocateimpl-hash.md)|Retorna o hash valores para os indicadores especificados.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_rgBookmarks](../../data/oledb/irowsetlocateimpl-m-rgbookmarks.md)|Uma matriz de indicadores.|  
  
## <a name="remarks"></a>Comentários  
 `IRowsetLocateImpl` é a implementação de modelos OLE DB do [IRowsetLocate](https://msdn.microsoft.com/en-us/library/ms721190.aspx) interface. `IRowsetLocate` é usado para buscar linhas arbitrárias em um conjunto de linhas. Um conjunto de linhas que não implementa essa interface é um `sequential` conjunto de linhas. Quando `IRowsetLocate` está presente em um conjunto de linhas, a coluna 0 é o indicador para as linhas; ler esta coluna obterá um valor de indicador que pode ser usado para reposicionar na mesma linha.  
  
 `IRowsetLocateImpl` é usado para implementar o suporte a indicadores em provedores. Os indicadores são espaços reservados (índices de um conjunto de linhas) que permitem que o consumidor retornar rapidamente a uma linha, permitindo o acesso aos dados de alta velocidade. O provedor determina quais indicadores exclusivamente podem identificar uma linha. Usando `IRowsetLocateImpl` métodos, você pode comparar indicadores, linhas de busca por deslocarem busca linhas por indicador e retornam valores de hash de indicadores.  
  
 Para dar suporte a indicadores de OLE DB em um conjunto de linhas, verifique o conjunto de linhas herdar desta classe.  
  
 Para obter informações sobre como implementar o suporte a indicadores, consulte [provedor oferecer suporte a indicadores](../../data/oledb/provider-support-for-bookmarks.md) no *guia do programador do Visual C++* e [indicadores](https://msdn.microsoft.com/en-us/library/ms709728.aspx) no *Referência do programador de OLE DB* na plataforma SDK.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [IRowsetLocate:IRowset](https://msdn.microsoft.com/en-us/library/ms721190.aspx)   
 [Suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md)   
 [Indicadores](https://msdn.microsoft.com/en-us/library/ms709728.aspx)