---
title: "Arquétipo trabalho | Documentos do Microsoft"
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
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 046160644cca3bd23e4293a3c52692d2b4c94cd5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="worker-archetype"></a>Arquétipo de trabalho
Classes que estão em conformidade com a *trabalho* arquétipo fornecer o código para processar os itens de trabalho em fila em um pool de threads.  
  
 **Implementação**  
  
 Para implementar uma classe em conformidade com esta arquétipo, a classe deve fornecer os seguintes recursos:  
  
|Método|Descrição|  
|------------|-----------------|  
|[Inicializar](#initialize)|Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passadas para [Execute](#execute).|  
|[Executar](#execute)|Chamado para processar um item de trabalho.|  
|[Encerrar](#terminate)|Chamado para inicializar o objeto de trabalho depois que todas as solicitações foram passadas ao [Execute](#execute).|  
  
|DefTipo|Descrição|  
|-------------|-----------------|  
|[RequestType](#requesttype)|Um typedef para o tipo de item de trabalho que pode ser processada pela classe de trabalho.|  
  
 Um típico *trabalho* classe tem esta aparência:  
  
 [!code-cpp[NVC_ATL_Utilities&#137;](../../atl/codesnippet/cpp/worker-archetype_1.cpp)]  
  
 **Implementações existentes**  
  
 Essas classes estão em conformidade com esta arquétipo:  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações do pool de threads e as passa para um objeto de trabalho que é criado e destruído para cada solicitação.|  
  
 **Use**  
  
 Esses parâmetros de modelo espera que a classe de acordo com essa arquétipo:  
  
|Nome do parâmetro|Usado por|  
|--------------------|-------------|  
|*Trabalho*|[CThreadPool](../../atl/reference/cthreadpool-class.md)|  
|*Trabalho*|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|  
  
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
 O item de trabalho a serem processados. O item de trabalho é do mesmo tipo como `RequestType`.  
  
 `pvWorkerParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também passado para `WorkerArchetype::Initialize` e `Terminate`.  
  
 `pOverlapped`  
 Um ponteiro para o [OVERLAPPED](http://msdn.microsoft.com/library/windows/desktop/ms684342) estrutura usada para criar a fila na qual trabalho enfileirados itens.  
  
## <a name="initialize"></a>WorkerArchetype::Initialize
Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passadas para `WorkerArchetype::Execute`.  
```
BOOL Initialize(void* pvParam) throw();
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pvParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também passado para `WorkerArchetype::Terminate` e `WorkerArchetype::Execute`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornar **TRUE** com êxito, **FALSE** em caso de falha.  
  
## <a name="requesttype"></a>WorkerArchetype::RequestType
Um typedef para o tipo de item de trabalho que pode ser processada pela classe de trabalho.  
  
```  
typedef MyRequestType RequestType;    
```  
  
### <a name="remarks"></a>Comentários  
 Esse tipo deve ser usado como o primeiro parâmetro de `WorkerArchetype::Execute` e deve ser capaz de que está sendo convertido em um ULONG_PTR.  
  
## <a name="terminate"></a>WorkerArchetype::Terminate
Chamado para inicializar o objeto de trabalho depois que todas as solicitações foram passadas ao `WorkerArchetype::Execute`).  
    
``` 
void Terminate(void* pvParam) throw();
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pvParam`  
 Um parâmetro personalizado compreendido pela classe de trabalho. Também passado para `WorkerArchetype::Initialize` e `WorkerArchetype::Execute`.  
  
## <a name="see-also"></a>Consulte também  
 [Arquétipos](../../atl/reference/atl-archetypes.md)   
 [Conceitos](../../atl/active-template-library-atl-concepts.md)   
 [Componentes da área de trabalho COM de ATL](../../atl/atl-com-desktop-components.md)




