---
title: "Trabalho arquétipo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- Worker archetype
ms.assetid: 834145cd-09d3-4149-bc99-620e1871cbfb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 44f275568df9b4f8200a3fac1d77520bab38e8d1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="worker-archetype"></a>Trabalho arquétipo
Classes de acordo com o *trabalho* arquétipo fornecer o código para processar os itens de trabalho em fila em um pool de threads.  
  
 **Implementação**  
  
 Para implementar uma classe em conformidade com esta arquétipo, a classe deve fornecer os seguintes recursos:  
  
|Método|Descrição|  
|------------|-----------------|  
|[Initialize](#initialize)|Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passadas para [Execute](#execute).|  
|[Executar](#execute)|Chamado para processar um item de trabalho.|  
|[Encerrar](#terminate)|Chamado para inicializar o objeto de trabalho depois que todas as solicitações foram passadas para [Execute](#execute).|  
  
|DefTipo|Descrição|  
|-------------|-----------------|  
|[RequestType](#requesttype)|Um typedef para o tipo de item de trabalho que pode ser processada pela classe de trabalho.|  
  
 Um típico *trabalho* classe tem esta aparência:  
  
 [!code-cpp[NVC_ATL_Utilities#137](../../atl/codesnippet/cpp/worker-archetype_1.cpp)]  
  
 **Implementações existentes**  
  
 Essas classes estão em conformidade com esta arquétipo:  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações do pool de threads e as transmite para um objeto de trabalho que é criado e destruído para cada solicitação.|  
  
 **Use**  
  
 Esses parâmetros de modelo espera que a classe de acordo com essa arquétipo:  
  
|Nome do parâmetro|Usado por|  
|--------------------|-------------|  
|*Operador*|[CThreadPool](../../atl/reference/cthreadpool-class.md)|  
|*Operador*|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
## <a name="execute"></a>WorkerArchetype::Execute
Chamado para processar um item de trabalho.  
  
  
  
```  
void Execute(
    RequestType request,  
    void* pvWorkerParam,  
    OVERLAPPED* pOverlapped);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `request`  
 O item de trabalho a ser processado. O item de trabalho é o mesmo tipo da `RequestType`.  
  
 `pvWorkerParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Initialize` e `Terminate`.  
  
 `pOverlapped`  
 Um ponteiro para o [OVERLAPPED](http://msdn.microsoft.com/library/windows/desktop/ms684342) estrutura usada para criar a fila em que o trabalho enfileirados itens.  
  
## <a name="initialize"></a>WorkerArchetype::Initialize
Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passadas para `WorkerArchetype::Execute`.  
```
BOOL Initialize(void* pvParam) throw();
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pvParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Terminate` e `WorkerArchetype::Execute`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornar **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
## <a name="requesttype"></a>WorkerArchetype::RequestType
Um typedef para o tipo de item de trabalho que pode ser processada pela classe de trabalho.  
  
```  
typedef MyRequestType RequestType;    
```  
  
### <a name="remarks"></a>Comentários  
 Esse tipo deve ser usado como o primeiro parâmetro de `WorkerArchetype::Execute` e deve ser capaz de que está sendo convertido em um ULONG_PTR.  
  
## <a name="terminate"></a>WorkerArchetype::Terminate
Chamado para inicializar o objeto de trabalho depois que todas as solicitações foram passadas para `WorkerArchetype::Execute`).  
    
``` 
void Terminate(void* pvParam) throw();
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pvParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Initialize` e `WorkerArchetype::Execute`.  
  
## <a name="see-also"></a>Consulte também  
 [Arquétipos](../../atl/reference/atl-archetypes.md)   
 [Conceitos](../../atl/active-template-library-atl-concepts.md)   
 [Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)



