---
title: 'Cmanualaccessor:: Addbindentry | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CManualAccessor::AddBindEntry
- ATL.CManualAccessor.AddBindEntry
- CManualAccessor::AddBindEntry
- AddBindEntry
- CManualAccessor.AddBindEntry
dev_langs:
- C++
helpviewer_keywords:
- AddBindEntry method
ms.assetid: 8556dda9-dda1-4f67-96bc-6031e6c6a271
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1e99e9822b60152fc8daa6f101bcca2ea7e60c25
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cmanualaccessoraddbindentry"></a>CManualAccessor::AddBindEntry
Adiciona uma entrada de associação às colunas de saída.  
  
## <a name="syntax"></a>Sintaxe  
  
```
void AddBindEntry(DBORDINAL nOrdinal,  
   DBTYPE wType,  DBLENGTH nColumnSize,  
   void* pData,  
   void* pLength = NULL,  
   void* pStatus = NULL) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) no *referência do programador de OLE DB*.  
  
 `nOrdinal`  
 [in] Número de coluna.  
  
 `wType`  
 [in] Tipo de dados.  
  
 `nColumnSize`  
 [in] Tamanho de coluna em bytes.  
  
 `pData`  
 [in] Um ponteiro para os dados da coluna armazenados no buffer.  
  
 `pLength`  
 [in] Um ponteiro para o tamanho do campo, se necessário.  
  
 `pStatus`  
 [in] Um ponteiro para a variável a ser associado ao status de coluna, se necessário.  
  
## <a name="remarks"></a>Comentários  
 Para usar essa função, você deve primeiro chamar [CreateAccessor](../../data/oledb/cmanualaccessor-createaccessor.md). Não é possível adicionar mais entradas do que o número de colunas especificado em `CreateAccessor`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)   
 [Exemplo de DBViewer](../../visual-cpp-samples.md)