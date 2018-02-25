---
title: 'Ctable:: Open | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CTable.Open
- ATL::CTable::Open
- CTable::Open
- CTable.Open
dev_langs:
- C++
helpviewer_keywords:
- Open method
ms.assetid: 5d006d95-74d7-4e2b-b243-a33bc53b5455
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d727af84dfeae77ab08e57f2f3a11120f9f88631
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ctableopen"></a>CTable::Open
Abre a tabela.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Open(const CSession& session,  
   LPCWSTR wszTableName,  
   DBPROPSET* pPropSet = NULL,  
   ULONG ulPropSets = 0) throw ();  


HRESULT Open(const CSession& session,  
   LPCSTR szTableName,  
   DBPROPSET* pPropSet = NULL,  
   ULONG ulPropSets = 0) throw ();  


HRESULT Open(const CSession& session,  
   DBID& dbid,  
   DBPROPSET* pPropSet = NULL,  
   ULONG ulPropSets = 0) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `session`  
 [in] A sessão para o qual a tabela é aberta.  
  
 *wszTableName*  
 [in] O nome da tabela para abrir, passado como uma cadeia de caracteres Unicode.  
  
 *szTableName*  
 [in] O nome da tabela para abrir, passado como uma cadeia de caracteres ANSI.  
  
 *dbid*  
 [in] O **DBID** da tabela para abrir.  
  
 *pPropSet*  
 [in] Um ponteiro para uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas contendo propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx) no *referência do programador de OLE DB* no SDK do Windows. O valor padrão de NULL não especifica que nenhuma propriedade.  
  
 `ulPropSets`  
 [in] O número de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas passado a *pPropSet* argumento.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais detalhes, consulte [IOpenRowset:: OPENROWSET](https://msdn.microsoft.com/en-us/library/ms716724.aspx) no *referência do programador de DB OLE*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CTable](../../data/oledb/ctable-class.md)