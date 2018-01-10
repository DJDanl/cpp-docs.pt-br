---
title: 'Crowset:: Findnextrow | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CRowset.FindNextRow
- CRowset<TAccessor>.FindNextRow
- ATL::CRowset::FindNextRow
- CRowset::FindNextRow
- CRowset<TAccessor>::FindNextRow
- CRowset.FindNextRow
- ATL.CRowset<TAccessor>.FindNextRow
- ATL::CRowset<TAccessor>::FindNextRow
- FindNextRow
dev_langs: C++
helpviewer_keywords: FindNextRow method
ms.assetid: 36484df9-3625-4f15-bf69-db73a8d91c55
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 08dd2a80040c4affb89b19dfff3b22103b4e9547
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crowsetfindnextrow"></a>CRowset::FindNextRow
Localiza a próxima linha correspondente após o indicador especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT FindNextRow(   
   DBCOMPAREOP op,   
   BYTE* pData,   
   DBTYPE wType,   
   DBLENGTH nLength,   
   BYTE bPrecision,   
   BYTE bScale,   
   BOOL bSkipCurrent = TRUE,   
   CBookmarkBase* pBookmark = NULL    
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `op`  
 [in] A operação a ser usado na comparação de valores de linha. Para obter valores, consulte [irowsetfind:: Findnextrow](https://msdn.microsoft.com/en-us/library/ms723091.aspx).  
  
 `pData`  
 [in] Um ponteiro para o valor a ser correspondido.  
  
 `wType`  
 [in] Indica o tipo de dados da parte de valor do buffer. Para obter informações sobre indicadores de tipo, consulte [tipos de dados](https://msdn.microsoft.com/en-us/library/ms723969.aspx) no *referência do programador de DB OLE* no SDK do Windows.  
  
 `nLength`  
 [in] O comprimento, em bytes, da estrutura de dados de consumidor alocado para o valor de dados. Para obter detalhes, consulte a descrição do **cbMaxLen** na [estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) no *referência do programador DB OLE.*  
  
 `bPrecision`  
 [in] A precisão máxima usada ao obter dados. Usado somente se `wType` é `DBTYPE_NUMERIC`. Para obter mais informações, consulte [conversões envolvendo DBTYPE_NUMERIC ou DBTYPE_DECIMAL](https://msdn.microsoft.com/en-us/library/ms719714.aspx) no *referência do programador de DB OLE*.  
  
 `bScale`  
 [in] A escala usada ao obter dados. Usado somente se `wType` é `DBTYPE_NUMERIC` ou **DBTYPE_DECIMAL**. Para obter mais informações, consulte [conversões envolvendo DBTYPE_NUMERIC ou DBTYPE_DECIMAL](https://msdn.microsoft.com/en-us/library/ms719714.aspx) no *referência do programador de DB OLE*.  
  
 *bSkipCurrent*  
 [in] O número de linhas do indicador no qual iniciar uma pesquisa.  
  
 `pBookmark`  
 [in] O indicador de posição na qual iniciar a pesquisa.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Esse método requer que a interface opcional **IRowsetFind**, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetFind** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
 Para obter informações sobre como usar indicadores em clientes, consulte [usando indicadores](../../data/oledb/using-bookmarks.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)   
 [Estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)