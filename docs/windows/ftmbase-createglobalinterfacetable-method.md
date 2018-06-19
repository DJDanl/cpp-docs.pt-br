---
title: 'Método: Createglobalinterfacetable | Microsoft Docs'
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
ms.openlocfilehash: 6b17749d5f20007e05f181de8f4e069d3fc736f0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33872387"
---
# <a name="ftmbasecreateglobalinterfacetable-method"></a>Método FtmBase::CreateGlobalInterfaceTable
Cria uma tabela de interface global (GIT).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static HRESULT CreateGlobalInterfaceTable(  
   __out IGlobalInterfaceTable **git  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `git`  
 Quando essa operação for concluída, um ponteiro para uma tabela de interface global.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o tópico "IGlobalInterfaceTable" subtópico "Interfaces COM" do tópico "Referência COM" na biblioteca MSDN.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)