---
title: 'Caccessorbase:: Releaseaccessors | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CAccessorBase::ReleaseAccessors
- CAccessorBase.ReleaseAccessors
- ReleaseAccessors
dev_langs:
- C++
helpviewer_keywords:
- ReleaseAccessors method
ms.assetid: f08bc88e-0552-4a9c-9c65-b4061094649a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1c73035e27b1f896891630cd9b4d9a135b3c4758
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33093655"
---
# <a name="caccessorbasereleaseaccessors"></a>CAccessorBase::ReleaseAccessors
Libera os acessadores criados pela classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT ReleaseAccessors(IUnknown* pUnk);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Um ponteiro para um **IUnknown** interface para o objeto COM que os acessadores tem sido criados.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Chamado a partir do [caccessorrowset:: Close](../../data/oledb/caccessorrowset-close.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAccessorBase](../../data/oledb/caccessorbase-class.md)