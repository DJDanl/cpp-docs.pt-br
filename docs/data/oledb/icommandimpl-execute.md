---
title: 'Icommandimpl:: execute | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ICommandImpl::Execute
- ICommandImpl.Execute
dev_langs:
- C++
helpviewer_keywords:
- Execute method
ms.assetid: 033e0d4e-256b-4eed-9215-70e0bebb768c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8d4d24bbb7f7aad94210672ce9bbf0cc0c7d5414
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="icommandimplexecute"></a>ICommandImpl::Execute
Executa o comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Execute(IUnknown* pUnkOuter,  
   REFIID riid,  
   DBPARAMS* pParams,  
   DBROWCOUNT* pcRowsAffected,  
   IUnknown** ppRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [ICommand:: execute](https://msdn.microsoft.com/en-us/library/ms718095.aspx) no *referência do programador de OLE DB*.  
  
## <a name="remarks"></a>Comentários  
 A interface de saída solicitada será uma interface adquirida do objeto de conjunto de linhas que cria essa função.  
  
 **Executar** chamadas [CreateRowset](../../data/oledb/icommandimpl-createrowset.md). Substitua a implementação padrão para criar mais de um conjunto de linhas ou para fornecer suas próprias condições para a criação de conjuntos de linhas diferentes.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe ICommandImpl](../../data/oledb/icommandimpl-class.md)   
 [ICommandImpl::CancelExecution](../../data/oledb/icommandimpl-cancelexecution.md)