---
title: Classe CAnimationManagerEventHandler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CAnimationManagerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::CAnimationManagerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::CreateInstance
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::OnManagerStatusChanged
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::SetAnimationController
dev_langs:
- C++
helpviewer_keywords:
- CAnimationManagerEventHandler [MFC], CAnimationManagerEventHandler
- CAnimationManagerEventHandler [MFC], CreateInstance
- CAnimationManagerEventHandler [MFC], OnManagerStatusChanged
- CAnimationManagerEventHandler [MFC], SetAnimationController
ms.assetid: 6089ec07-e661-4805-b227-823b4652aade
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 34ef63cf5c781348e873512c8b2f5bb190ae4976
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33358252"
---
# <a name="canimationmanagereventhandler-class"></a>Classe CAnimationManagerEventHandler
Implementa um retorno de chamada, que é chamado pela API de animação quando um status de um Gerenciador de animação é alterado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationManagerEventHandler : public CUIAnimationManagerEventHandlerBase<CAnimationManagerEventHandler>;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationManagerEventHandler::CAnimationManagerEventHandler](#canimationmanagereventhandler)|Constrói um objeto `CAnimationManagerEventHandler`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationManagerEventHandler::CreateInstance](#createinstance)|Cria uma instância de `CAnimationManagerEventHandler` objeto.|  
|[CAnimationManagerEventHandler::OnManagerStatusChanged](#onmanagerstatuschanged)|Chamado quando um status de Gerenciador de animação é alterado. (Substitui `CUIAnimationManagerEventHandlerBase::OnManagerStatusChanged`.)|  
|[CAnimationManagerEventHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para eventos de rota.|  
  
## <a name="remarks"></a>Comentários  
 Este manipulador de eventos é criado e passado para o método IUIAnimationManager::SetManagerEventHandler, quando você chamar CAnimationController::EnableAnimationManagerEvent.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationManagerEventHandlerBase`  
  
 `CAnimationManagerEventHandler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="canimationmanagereventhandler"></a>  CAnimationManagerEventHandler::CAnimationManagerEventHandler  
 [!INCLUDE[dev10_sp1required](../../mfc/reference/includes/dev10_sp1required_md.md)]  
  
 Constrói um objeto CAnimationManagerEventHandler.  
  
```  
CAnimationManagerEventHandler();
```  
  
##  <a name="createinstance"></a>  CAnimationManagerEventHandler::CreateInstance  
 [!INCLUDE[dev10_sp1required](../../mfc/reference/includes/dev10_sp1required_md.md)]  
  
 Cria uma instância do objeto CAnimationManagerEventHandler.  
  
```  
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CAnimationController* pAnimationController,  
    IUIAnimationManagerEventHandler** ppManagerEventHandler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAnimationController`  
 Um ponteiro para o controlador de animação, que irá receber eventos.  
  
 `ppManagerEventHandler`  
 Saída. Se o método for bem-sucedido ele contém um ponteiro para o objeto COM que tratará as atualizações de status para um Gerenciador de animação.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="onmanagerstatuschanged"></a>  CAnimationManagerEventHandler::OnManagerStatusChanged  
 [!INCLUDE[dev10_sp1required](../../mfc/reference/includes/dev10_sp1required_md.md)]  
  
 Chamado quando um status de Gerenciador de animação é alterado.  
  
```  
IFACEMETHOD(OnManagerStatusChanged)(
  UI_ANIMATION_MANAGER_STATUS newStatus,
  UI_ANIMATION_MANAGER_STATUS previousStatus);
```  
  
### <a name="parameters"></a>Parâmetros  
 `newStatus`  
 Novo status.  
  
 `previousStatus`  
 Status anterior.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre a implementação atual Retorna S_OK;  
  
##  <a name="setanimationcontroller"></a>  CAnimationManagerEventHandler::SetAnimationController  
 [!INCLUDE[dev10_sp1required](../../mfc/reference/includes/dev10_sp1required_md.md)]  
  
 Armazena um ponteiro para o controlador de animação para eventos de rota.  
  
```  
void SetAnimationController(CAnimationController* pAnimationController);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAnimationController`  
 Um ponteiro para o controlador de animação, que irá receber eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
