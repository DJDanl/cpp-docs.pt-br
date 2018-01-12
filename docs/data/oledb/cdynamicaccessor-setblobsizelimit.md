---
title: 'Cdynamicaccessor:: Setblobsizelimit | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDynamicAccessor::SetBlobSizeLimit
- SetBlobSizeLimit
- CDynamicAccessor.SetBlobSizeLimit
- ATL.CDynamicAccessor.SetBlobSizeLimit
- ATL::CDynamicAccessor::SetBlobSizeLimit
dev_langs: C++
helpviewer_keywords: SetBlobSizeLimit method
ms.assetid: fb8cb85d-f841-408e-a344-37895b10993f
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e5d683c06283c82e6117893e44def41d09300da0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdynamicaccessorsetblobsizelimit"></a>CDynamicAccessor::SetBlobSizeLimit
Define o tamanho máximo do BLOB em bytes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void SetBlobSizeLimit(  
   DBLENGTH nBlobSize   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nBlobSize`  
 Especifica o limite de tamanho do BLOB.  
  
## <a name="remarks"></a>Comentários  
 Define o tamanho máximo do BLOB em bytes. dados de coluna maiores do que esse valor são tratados como um BLOB. Alguns provedores oferecem tamanhos muito grandes para colunas (como 2 GB). Em vez de tentar alocar memória para uma coluna desse tamanho, normalmente seria tentar associar essas colunas como BLOBs. Dessa forma, você não precisa alocar toda a memória, mas você ainda pode ler todos os dados sem medo de truncamento. No entanto, há alguns casos em que você talvez queira forçar `CDynamicAccessor` para associar colunas grandes em seus tipos de dados nativos. Para fazer isso, chame `SetBlobSizeLimit` antes de chamar **abrir**.  
  
 O método de construtor [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) define o tamanho máximo do BLOB como um valor padrão de 8.000 bytes.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)