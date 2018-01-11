---
title: Classe CRowset | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CRowset<TAccessor>
- CRowset
- ATL::CRowset
- ATL::CRowset<TAccessor>
- ATL.CRowset
dev_langs: C++
helpviewer_keywords: CRowset class
ms.assetid: b0228a90-b8dd-47cc-b397-8d4c15c1e7f4
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3b0d46ac3164f7f609e8a8a8099d500d04d91bf1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crowset-class"></a>Classe CRowset
Encapsula um objeto de conjunto de linhas do OLE DB e vários relacionados interfaces e fornece métodos de manipulação de dados do conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class TAccessor = CAccessorBase>  
class CRowset  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 Uma classe de acessador. O padrão é `CAccessorBase`.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddRefRows](../../data/oledb/crowset-addrefrows.md)|Incrementa a contagem de referência associado com a linha atual.|  
|[Fechar](../../data/oledb/crowset-close.md)|Versões de linhas e atual `IRowset` interface.|  
|[Compare](../../data/oledb/crowset-compare.md)|Compara dois indicadores usando [IRowsetLocate::Compare](https://msdn.microsoft.com/en-us/library/ms709539.aspx).|  
|[CRowset](../../data/oledb/crowset-crowset.md)|Cria um novo `CRowset` de objeto e (opcionalmente) associa-o com um **IRowset** interface fornecida como um parâmetro.|  
|[Excluir](../../data/oledb/crowset-delete.md)|Exclui linhas do conjunto de linhas usando [IRowsetChange:DeleteRows](https://msdn.microsoft.com/en-us/library/ms724362.aspx).|  
|[FindNextRow](../../data/oledb/crowset-findnextrow.md)|Localiza a próxima linha correspondente após o indicador especificado.|  
|[GetApproximatePosition](../../data/oledb/crowset-getapproximateposition.md)|Retorna a posição aproximada de uma linha correspondente a um indicador.|  
|[GetData](../../data/oledb/crowset-getdata.md)|Recupera dados da cópia do conjunto de linhas da linha.|  
|[GetDataHere](../../data/oledb/crowset-getdatahere.md)|Recupera dados de buffer especificado.|  
|[GetOriginalData](../../data/oledb/crowset-getoriginaldata.md)|Recupera os dados obtidos de mais recentemente ou transmitida para a fonte de dados, ignorando as alterações pendentes.|  
|[GetRowStatus](../../data/oledb/crowset-getrowstatus.md)|Retorna o status de todas as linhas.|  
|[Inserir](../../data/oledb/crowset-insert.md)|Cria e insere uma nova linha usando [IRowsetChange:InsertRow](https://msdn.microsoft.com/en-us/library/ms716921.aspx).|  
|[IsSameRow](../../data/oledb/crowset-issamerow.md)|Compara a linha especificada com a linha atual.|  
|[MoveFirst](../../data/oledb/crowset-movefirst.md)|Reposiciona o local de busca de Avançar para a posição inicial.|  
|[MoveLast](../../data/oledb/crowset-movelast.md)|Move para o último registro.|  
|[MoveNext](../../data/oledb/crowset-movenext.md)|Busca dados na próxima linha sequencial ou um número especificado de posições após a próxima linha.|  
|[MovePrev](../../data/oledb/crowset-moveprev.md)|Move para o registro anterior.|  
|[MoveToBookmark](../../data/oledb/crowset-movetobookmark.md)|Busca a linha marcada por um indicador ou uma linha em um deslocamento especificado desse indicador.|  
|[MoveToRatio](../../data/oledb/crowset-movetoratio.md)|Busca de linhas a partir de uma posição fracionária no conjunto de linhas.|  
|[ReleaseRows](../../data/oledb/crowset-releaserows.md)|Chamadas [IRowset:: Releaserows](https://msdn.microsoft.com/en-us/library/ms719771.aspx) para liberar o identificador da linha atual.|  
|[SetData](../../data/oledb/crowset-setdata.md)|Define valores de dados em uma ou mais colunas de uma linha usando [IRowsetChange:SetData](https://msdn.microsoft.com/en-us/library/ms721232.aspx).|  
|[Desfazer](../../data/oledb/crowset-undo.md)|Desfaz todas as alterações feitas desde a última busca uma linha ou [atualização](../../data/oledb/crowset-update.md).|  
|[Atualizar](../../data/oledb/crowset-update.md)|Transmite todas as alterações feitas na linha atual desde a última busca ou atualização pendentes.|  
|[UpdateAll](../../data/oledb/crowset-updateall.md)|Transmite todas as alterações feitas a todas as linhas desde a última busca ou atualização pendentes.|  
  
## <a name="remarks"></a>Comentários  
 No OLE DB, um conjunto de linhas é o objeto por meio dos quais um programa define e recupera os dados.  
  
 Essa classe não pode ser instanciado, mas em vez disso é passado como um parâmetro de modelo para `CTable` ou `CCommand` (`CRowset` é o padrão).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de DBViewer](../../visual-cpp-samples.md)   
 [Exemplo multiRead](../../visual-cpp-samples.md)   
 [Exemplo de atributos multiRead](../../visual-cpp-samples.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)