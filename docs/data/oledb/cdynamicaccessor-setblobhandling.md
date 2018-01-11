---
title: 'Cdynamicaccessor:: Setblobhandling | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDynamicAccessor::SetBlobHandling
- CDynamicAccessor.SetBlobHandling
- ATL::CDynamicAccessor::SetBlobHandling
- SetBlobHandling
- ATL.CDynamicAccessor.SetBlobHandling
dev_langs: C++
helpviewer_keywords: SetBlobHandling method
ms.assetid: fa8b0bb3-a21b-4d64-aeef-e79bf61d079c
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 02b9be4b187f55d9bfb8f3ee5e572f682742f538
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdynamicaccessorsetblobhandling"></a>CDynamicAccessor::SetBlobHandling
Define o BLOB de tratamento de valor para a linha atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      bool SetBlobHandling(  
   DBBLOBHANDLINGENUM eBlobHandling   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `eBlobHandling`  
 Especifica como os dados BLOB deve ser tratada. Pode usar os seguintes valores:  
  
-   **DBBLOBHANDLING_DEFAULT**: lidar com dados de coluna maiores do que `nBlobSize` (conforme definido por `SetBlobSizeLimit`) como dados BLOB e recuperá-lo por meio de um `ISequentialStream` ou `IStream` objeto. Esta opção tentará associar cada coluna que contém dados maiores do que `nBlobSize` ou listados como **DBTYPE_IUNKNOWN** como dados BLOB.  
  
-   **DBBLOBHANDLING_NOSTREAMS**: lidar com dados de coluna maiores do que `nBlobSize` (conforme definido pelo `SetBlobSizeLimit`) como dados BLOB e recuperá-lo por meio de referência na memória alocada pelo provedor, a propriedade do consumidor. Essa opção é útil para tabelas que têm mais de uma coluna BLOB e o provedor oferece suporte a apenas um `ISequentialStream` objeto por acessador.  
  
-   **DBBLOBHANDLING_SKIP**: ignorar (não vincular) colunas qualificadas como contendo BLOBs (o acessador não associar ou recuperar o valor da coluna, mas ainda recuperará o status da coluna e o comprimento).  
  
## <a name="remarks"></a>Comentários  
 Você deve chamar `SetBlobHandling` antes de chamar **abrir**.  
  
 O método de construtor [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) define o BLOB de tratamento de valor para **DBBLOBHANDLING_DEFAULT**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)