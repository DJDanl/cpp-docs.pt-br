---
title: 'Método ftmbase:: Createglobalinterfacetable | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::CreateGlobalInterfaceTable
dev_langs:
- C++
helpviewer_keywords:
- CreateGlobalInterfaceTable method
ms.assetid: bb82a0c5-22b9-4844-9204-7922033d8b07
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ae65169ac3f315aed170ba8dfc42b16fb4e9b328
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39641311"
---
# <a name="ftmbasecreateglobalinterfacetable-method"></a>Método FtmBase::CreateGlobalInterfaceTable
Cria uma tabela de interface global (GIT).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
static HRESULT CreateGlobalInterfaceTable(  
   __out IGlobalInterfaceTable **git  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Git*  
 Quando essa operação for concluída, um ponteiro para uma tabela de interface global.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o `IGlobalInterfaceTable` tópico na **Interfaces COM** subtópico a **referência COM** tópico na biblioteca MSDN.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)