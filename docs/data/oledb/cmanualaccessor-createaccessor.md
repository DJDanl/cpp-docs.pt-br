---
title: 'Cmanualaccessor:: CreateAccessor | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CManualAccessor::CreateAccessor
- CreateAccessor
- ATL.CManualAccessor.CreateAccessor
- CManualAccessor.CreateAccessor
- CManualAccessor::CreateAccessor
dev_langs: C++
helpviewer_keywords: CreateAccessor method
ms.assetid: 594c8d6d-b49a-4818-a9a5-81c8115d4e42
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f313e6d2b13a03a91295c75d52e4e77d5dfda22b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmanualaccessorcreateaccessor"></a>CManualAccessor::CreateAccessor
Aloca memória para a coluna de estruturas de associação e inicializa os membros de dados de coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT CreateAccessor(   
   int nBindEntries,   
   void* pBuffer,   
   DBLENGTH nBufferSize    
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nBindEntries`  
 [in] Número de colunas. Esse número deve corresponder ao número de chamadas para o [cmanualaccessor:: Addbindentry](../../data/oledb/cmanualaccessor-addbindentry.md) função.  
  
 `pBuffer`  
 [in] Um ponteiro para o buffer em que as colunas de saída são armazenadas.  
  
 `nBufferSize`  
 [in] O tamanho do buffer em bytes.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
## <a name="remarks"></a>Comentários  
 Chamar essa função antes de chamar o `CManualAccessor::AddBindEntry` função.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)   
 [Exemplo de DBViewer](../../visual-cpp-samples.md)