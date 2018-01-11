---
title: 'Cmanualaccessor:: Addbindentry | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CManualAccessor::AddBindEntry
- ATL.CManualAccessor.AddBindEntry
- CManualAccessor::AddBindEntry
- AddBindEntry
- CManualAccessor.AddBindEntry
dev_langs: C++
helpviewer_keywords: AddBindEntry method
ms.assetid: 8556dda9-dda1-4f67-96bc-6031e6c6a271
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 14a2fbae8ee29728d145b3ff8d20a02b4000b5a2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmanualaccessoraddbindentry"></a>CManualAccessor::AddBindEntry
Adiciona uma entrada de associação às colunas de saída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void AddBindEntry(  
   DBORDINAL nOrdinal,  
   DBTYPE wType,  
   DBLENGTH nColumnSize,  
   void* pData,  
   void* pLength = NULL,  
   void* pStatus = NULL   
) throw ( );  
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