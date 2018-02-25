---
title: 'Csession:: Open | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CSession::Open
- CSession::Open
- CSession.Open
- ATL.CSession.Open
dev_langs:
- C++
helpviewer_keywords:
- Open method
ms.assetid: c2050c2c-9817-4857-be49-189f346968f6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7ab796d19c45959aac608de5097e9112bd8543e2
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="csessionopen"></a>CSession::Open
Abre uma nova sessão para o objeto de fonte de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Open(const CDataSource& ds,  
   DBPROPSET *pPropSet = NULL,  
   ULONG ulPropSets = 0) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ds`  
 [in] A fonte de dados para o qual a sessão está para ser aberto.  
  
 *pPropSet*  
 [in] Um ponteiro para uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas contendo propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx) no *referência do programador de OLE DB* no SDK do Windows.  
  
 `ulPropSets`  
 [in] O número de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas passado a *pPropSet* argumento.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Você deve abrir o objeto de fonte de dados usando [cdatasource:: Open](../../data/oledb/cdatasource-open.md) antes de passá-lo para `CSession::Open`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSession](../../data/oledb/csession-class.md)