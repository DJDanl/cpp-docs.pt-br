---
title: Trabalho arquétipo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- Worker archetype
ms.assetid: 834145cd-09d3-4149-bc99-620e1871cbfb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cee9df0b137655fe66e68c189de756f15233a94d
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
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
  
## <a name="initialize"></a> WorkerArchetype::Initialize
Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passadas para `WorkerArchetype::Execute`.  
```
BOOL Initialize(void* pvParam) throw();
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pvParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Terminate` e `WorkerArchetype::Execute`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornar **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
## <a name="requesttype"></a> WorkerArchetype::RequestType
Um typedef para o tipo de item de trabalho que pode ser processada pela classe de trabalho.  
  
```  
typedef MyRequestType RequestType;    
```  
  
### <a name="remarks"></a>Comentários  
 Esse tipo deve ser usado como o primeiro parâmetro de `WorkerArchetype::Execute` e deve ser capaz de que está sendo convertido em um ULONG_PTR.  
  
## <a name="terminate"></a> WorkerArchetype::Terminate
Chamado para inicializar o objeto de trabalho depois que todas as solicitações foram passadas para `WorkerArchetype::Execute`).  
    
``` 
void Terminate(void* pvParam) throw();
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pvParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Initialize` e `WorkerArchetype::Execute`.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../../atl/active-template-library-atl-concepts.md)   
 [Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)



