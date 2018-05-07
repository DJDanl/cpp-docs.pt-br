---
title: 'Cdynamicaccessor:: Setblobsizelimit | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicAccessor::SetBlobSizeLimit
- SetBlobSizeLimit
- CDynamicAccessor.SetBlobSizeLimit
- ATL.CDynamicAccessor.SetBlobSizeLimit
- ATL::CDynamicAccessor::SetBlobSizeLimit
dev_langs:
- C++
helpviewer_keywords:
- SetBlobSizeLimit method
ms.assetid: fb8cb85d-f841-408e-a344-37895b10993f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8731857507fa096d500a31f31a7c31ef4f94cfc6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdynamicaccessorsetblobsizelimit"></a>CDynamicAccessor::SetBlobSizeLimit
Define o tamanho máximo do BLOB em bytes.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      void SetBlobSizeLimit(DBLENGTH nBlobSize);  
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