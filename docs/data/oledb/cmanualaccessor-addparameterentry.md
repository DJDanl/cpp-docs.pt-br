---
title: 'Cmanualaccessor:: Addparameterentry | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CManualAccessor::AddParameterEntry
- ATL.CManualAccessor.AddParameterEntry
- CManualAccessor.AddParameterEntry
- AddParameterEntry
- ATL::CManualAccessor::AddParameterEntry
dev_langs:
- C++
helpviewer_keywords:
- AddParameterEntry method
ms.assetid: 9048b164-052b-41b1-a861-227fc529e0b5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: cb97e841cf72abcf49ee2a57ccd78832e7fb95a3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33095935"
---
# <a name="cmanualaccessoraddparameterentry"></a>CManualAccessor::AddParameterEntry
Adiciona uma entrada de parâmetro para as estruturas de entrada de parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```
void AddParameterEntry(DBORDINAL nOrdinal,  
   DBTYPE wType,  DBLENGTH nColumnSize,  
   void* pData,  
   void* pLength = NULL,  
   void* pStatus = NULL,  
   DBPARAMIO eParamIO = DBPARAMIO_INPUT) throw ();  
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
 [CManualAccessor::AddBindEntry](../../data/oledb/cmanualaccessor-addbindentry.md)   
 [Exemplo de DBViewer](../../visual-cpp-samples.md)