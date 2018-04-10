---
title: Classe CHwndRenderTarget | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- CHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget::CHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget::Attach
- AFXRENDERTARGET/CHwndRenderTarget::CheckWindowState
- AFXRENDERTARGET/CHwndRenderTarget::Create
- AFXRENDERTARGET/CHwndRenderTarget::Detach
- AFXRENDERTARGET/CHwndRenderTarget::GetHwnd
- AFXRENDERTARGET/CHwndRenderTarget::GetHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget::ReCreate
- AFXRENDERTARGET/CHwndRenderTarget::Resize
- AFXRENDERTARGET/CHwndRenderTarget::m_pHwndRenderTarget
dev_langs:
- C++
helpviewer_keywords:
- CHwndRenderTarget [MFC], CHwndRenderTarget
- CHwndRenderTarget [MFC], Attach
- CHwndRenderTarget [MFC], CheckWindowState
- CHwndRenderTarget [MFC], Create
- CHwndRenderTarget [MFC], Detach
- CHwndRenderTarget [MFC], GetHwnd
- CHwndRenderTarget [MFC], GetHwndRenderTarget
- CHwndRenderTarget [MFC], ReCreate
- CHwndRenderTarget [MFC], Resize
- CHwndRenderTarget [MFC], m_pHwndRenderTarget
ms.assetid: aa65b69f-7202-46ea-af81-ef325da0b840
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3f11f7e329b623639fb1441e4d9e18720a6b6b94
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chwndrendertarget-class"></a>Classe CHwndRenderTarget
Um wrapper para ID2D1HwndRenderTarget.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHwndRenderTarget : public CRenderTarget;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHwndRenderTarget::CHwndRenderTarget](#chwndrendertarget)|Constrói um objeto CHwndRenderTarget de HWND.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHwndRenderTarget::Attach](#attach)|Conexões existentes renderizam a interface para o objeto de destino|  
|[CHwndRenderTarget::CheckWindowState](#checkwindowstate)|Indica se o HWND associado a este destino de renderização é obstruído.|  
|[CHwndRenderTarget::Create](#create)|Cria um destino de renderização associado à janela|  
|[CHwndRenderTarget::Detach](#detach)|Desanexa a interface de destino de renderização do objeto|  
|[CHwndRenderTarget::GetHwnd](#gethwnd)|Retorna o HWND associado a esse destino de renderização.|  
|[CHwndRenderTarget::GetHwndRenderTarget](#gethwndrendertarget)|Interface de ID2D1HwndRenderTarget retorna.|  
|[CHwndRenderTarget::ReCreate](#recreate)|Recria em um destino de renderização associado à janela|  
|[CHwndRenderTarget::Resize](#resize)|Altera o tamanho de destino de renderização para o tamanho de pixel especificado|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHwndRenderTarget::operator ID2D1HwndRenderTarget *](#operator_id2d1hwndrendertarget_star)|Interface de ID2D1HwndRenderTarget retorna.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHwndRenderTarget::m_pHwndRenderTarget](#m_phwndrendertarget)|Um ponteiro para um objeto ID2D1HwndRenderTarget.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CRenderTarget](../../mfc/reference/crendertarget-class.md)  
  
 [CHwndRenderTarget](../../mfc/reference/chwndrendertarget-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="attach"></a>CHwndRenderTarget::Attach  
 Conexões existentes renderizam a interface para o objeto de destino  
  
```  
void Attach(ID2D1HwndRenderTarget* pTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTarget`  
 Interface de destino de renderização existente. Não pode ser NULL  
  
##  <a name="checkwindowstate"></a>CHwndRenderTarget::CheckWindowState  
 Indica se o HWND associado a este destino de renderização é obstruído.  
  
```  
D2D1_WINDOW_STATE CheckWindowState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica se o HWND associado a esse destino de renderização é obstruído.  
  
##  <a name="chwndrendertarget"></a>CHwndRenderTarget::CHwndRenderTarget  
 Constrói um objeto CHwndRenderTarget de HWND.  
  
```  
CHwndRenderTarget(HWND hwnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hwnd`  
 O HWND associado a esse destino de renderização  
  
##  <a name="create"></a>CHwndRenderTarget::Create  
 Cria um destino de renderização associado à janela  
  
```  
BOOL Create(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 O HWND associado a esse destino de renderização  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retornará FALSE  
  
##  <a name="detach"></a>CHwndRenderTarget::Detach  
 Desanexa a interface de destino de renderização do objeto  
  
```  
ID2D1HwndRenderTarget* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para desanexado renderizar a interface de destino.  
  
##  <a name="gethwnd"></a>CHwndRenderTarget::GetHwnd  
 Retorna o HWND associado a esse destino de renderização.  
  
```  
HWND GetHwnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O HWND associado a esse destino de renderização.  
  
##  <a name="gethwndrendertarget"></a>CHwndRenderTarget::GetHwndRenderTarget  
 Interface de ID2D1HwndRenderTarget retorna.  
  
```  
ID2D1HwndRenderTarget* GetHwndRenderTarget();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1HwndRenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="m_phwndrendertarget"></a>CHwndRenderTarget::m_pHwndRenderTarget  
 Um ponteiro para um objeto ID2D1HwndRenderTarget.  
  
```  
ID2D1HwndRenderTarget* m_pHwndRenderTarget;  
```  
  
##  <a name="operator_id2d1hwndrendertarget_star"></a>CHwndRenderTarget::operator ID2D1HwndRenderTarget *  
 Interface de ID2D1HwndRenderTarget retorna.  
  
```  
operator ID2D1HwndRenderTarget*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1HwndRenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="recreate"></a>CHwndRenderTarget::ReCreate  
 Recria em um destino de renderização associado à janela  
  
```  
BOOL ReCreate(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 O HWND associado a esse destino de renderização  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retornará FALSE.  
  
##  <a name="resize"></a>CHwndRenderTarget::Resize  
 Altera o tamanho de destino de renderização para o tamanho de pixel especificado  
  
```  
BOOL Resize(const CD2DSizeU& size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 O novo tamanho do destino de renderização em pixels do dispositivo  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retornará FALSE.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
