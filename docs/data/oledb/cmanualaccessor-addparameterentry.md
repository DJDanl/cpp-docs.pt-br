---
title: 'Cmanualaccessor:: Addparameterentry | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CManualAccessor::AddParameterEntry
- ATL.CManualAccessor.AddParameterEntry
- CManualAccessor.AddParameterEntry
- AddParameterEntry
- ATL::CManualAccessor::AddParameterEntry
dev_langs: C++
helpviewer_keywords: AddParameterEntry method
ms.assetid: 9048b164-052b-41b1-a861-227fc529e0b5
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 66c88bf072cbae6c86949d52ded121dd694c0e97
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmanualaccessoraddparameterentry"></a>CManualAccessor::AddParameterEntry
Adiciona uma entrada de parâmetro para as estruturas de entrada de parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void AddParameterEntry(  
   DBORDINAL nOrdinal,  
   DBTYPE wType,  
   DBLENGTH nColumnSize,  
   void* pData,  
   void* pLength = NULL,  
   void* pStatus = NULL,  
   DBPARAMIO eParamIO = DBPARAMIO_INPUT   
) throw ( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) no *referência do programador de OLE DB*.  
  
 `nOrdinal`  
 [in] Número do parâmetro.  
  
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
  
 *eParamIO*  
 [in] Especifica se o parâmetro ao qual a associação está associada é um parâmetro de entrada, entrada/saída ou saído.  
  
## <a name="remarks"></a>Comentários  
 Para usar essa função, você deve primeiro chamar [CreateParameterAccessor](../../data/oledb/cmanualaccessor-createparameteraccessor.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)   
 [Cmanualaccessor:: Addbindentry](../../data/oledb/cmanualaccessor-addbindentry.md)   
 [Exemplo de DBViewer](../../visual-cpp-samples.md)