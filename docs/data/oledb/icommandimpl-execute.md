---
title: 'Icommandimpl:: execute | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ICommandImpl::Execute
- ICommandImpl.Execute
dev_langs: C++
helpviewer_keywords: Execute method
ms.assetid: 033e0d4e-256b-4eed-9215-70e0bebb768c
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 965a344b55b6d290f112970ff357f383fefcd630
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="icommandimplexecute"></a>ICommandImpl::Execute
Executa o comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT Execute(  
   IUnknown* pUnkOuter,  
   REFIID riid,  
   DBPARAMS* pParams,  
   DBROWCOUNT* pcRowsAffected,  
   IUnknown** ppRowset   
);  
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