---
title: CDynamicAccessor::CDynamicAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDynamicAccessor::CDynamicAccessor
- ATL::CDynamicAccessor::CDynamicAccessor
- ATL.CDynamicAccessor.CDynamicAccessor
- CDynamicAccessor.CDynamicAccessor
dev_langs:
- C++
helpviewer_keywords:
- CDynamicAccessor class, constructor
ms.assetid: bf40fe81-2c85-473e-9075-51ad9b060b39
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ce33fd4aa64114a0b4465bb3272f74ef2ccf8258
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdynamicaccessorcdynamicaccessor"></a>CDynamicAccessor::CDynamicAccessor
Cria e inicializa o `CDynamicAccessor` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      CDynamicAccessor(DBBLOBHANDLINGENUM eBlobHandling = DBBLOBHANDLING_DEFAULT,   
   DBLENGTH nBlobSize = 8000);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `eBlobHandling`  
 Especifica como os dados de objeto binário grande (BLOB) deve ser tratada. O valor padrão é **DBBLOBHANDLING_DEFAULT**. Consulte [SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md) para obter uma descrição de **DBBLOBHANDLINGENUM** valores.  
  
 `nBlobSize`  
 O tamanho máximo do BLOB em bytes. dados de coluna sobre esse valor são tratados como um BLOB. O valor padrão é de 8.000. Consulte [SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md) para obter detalhes.  
  
## <a name="remarks"></a>Comentários  
 Se você usar o construtor para inicializar o `CDynamicAccessor` do objeto, você pode especificar como ele associará BLOBs. BLOBs podem conter dados binários como código de gráficos, som ou compilado. O comportamento padrão é tratar mais de 8.000 bytes de colunas como BLOBs e tentar associá-las para um `ISequentialStream` objeto. No entanto, você pode especificar um valor diferente para o tamanho do BLOB.  
  
 Você também pode especificar como `CDynamicAccessor` lida com dados de coluna que qualificam-se como dados BLOB: pode lidar com dados BLOB da maneira padrão; ignorar (não vincular) dados BLOB; ou ele pode associar dados BLOB em memória alocada pelo provedor.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)