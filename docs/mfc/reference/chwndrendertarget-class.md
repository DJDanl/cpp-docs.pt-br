---
title: Classe CHwndRenderTarget | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHwndRenderTarget
- afxrendertarget/CHwndRenderTarget
dev_langs:
- C++
helpviewer_keywords:
- CHwndRenderTarget class
ms.assetid: aa65b69f-7202-46ea-af81-ef325da0b840
caps.latest.revision: 17
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 1af6795e89c995ba6b5a7b094f06b0aea776f561
ms.lasthandoff: 02/25/2017

---
# <a name="chwndrendertarget-class"></a>Classe CHwndRenderTarget
Um wrapper para ID2D1HwndRenderTarget.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHwndRenderTarget : public CRenderTarget;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHwndRenderTarget::CHwndRenderTarget](#chwndrendertarget)|Constrói um objeto CHwndRenderTarget de HWND.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHwndRenderTarget::Attach](#attach)|Conexões existentes renderizam a interface de destino para o objeto|  
|[CHwndRenderTarget::CheckWindowState](#checkwindowstate)|Indica se o HWND associado a esse destino de renderização é obstruído.|  
|[CHwndRenderTarget::Create](#create)|Cria um destino de renderização associado à janela|  
|[CHwndRenderTarget::Detach](#detach)|Desconecta a interface de destino de renderização do objeto|  
|[CHwndRenderTarget::GetHwnd](#gethwnd)|Retorna o HWND associado a esse destino de renderização.|  
|[CHwndRenderTarget::GetHwndRenderTarget](#gethwndrendertarget)|Interface de ID2D1HwndRenderTarget retorna.|  
|[CHwndRenderTarget::ReCreate](#recreate)|Cria um destino de renderização associado à janela novamente|  
|[CHwndRenderTarget::Resize](#resize)|Altera o tamanho do destino de renderização para o tamanho de pixel especificado|  
  
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
  
##  <a name="a-nameattacha--chwndrendertargetattach"></a><a name="attach"></a>CHwndRenderTarget::Attach  
 Conexões existentes renderizam a interface de destino para o objeto  
  
```  
void Attach(ID2D1HwndRenderTarget* pTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTarget`  
 Interface de destino de renderização existente. Não pode ser nulo  
  
##  <a name="a-namecheckwindowstatea--chwndrendertargetcheckwindowstate"></a><a name="checkwindowstate"></a>CHwndRenderTarget::CheckWindowState  
 Indica se o HWND associado a esse destino de renderização é obstruído.  
  
```  
D2D1_WINDOW_STATE CheckWindowState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica se o HWND associado a esse destino de renderização é obstruído.  
  
##  <a name="a-namechwndrendertargeta--chwndrendertargetchwndrendertarget"></a><a name="chwndrendertarget"></a>CHwndRenderTarget::CHwndRenderTarget  
 Constrói um objeto CHwndRenderTarget de HWND.  
  
```  
CHwndRenderTarget(HWND hwnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hwnd`  
 O HWND associado a esse destino de renderização  
  
##  <a name="a-namecreatea--chwndrendertargetcreate"></a><a name="create"></a>CHwndRenderTarget::Create  
 Cria um destino de renderização associado à janela  
  
```  
BOOL Create(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 O HWND associado a esse destino de renderização  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retornará FALSE  
  
##  <a name="a-namedetacha--chwndrendertargetdetach"></a><a name="detach"></a>CHwndRenderTarget::Detach  
 Desconecta a interface de destino de renderização do objeto  
  
```  
ID2D1HwndRenderTarget* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para desanexado renderizar a interface de destino.  
  
##  <a name="a-namegethwnda--chwndrendertargetgethwnd"></a><a name="gethwnd"></a>CHwndRenderTarget::GetHwnd  
 Retorna o HWND associado a esse destino de renderização.  
  
```  
HWND GetHwnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O HWND associado a esse destino de renderização.  
  
##  <a name="a-namegethwndrendertargeta--chwndrendertargetgethwndrendertarget"></a><a name="gethwndrendertarget"></a>CHwndRenderTarget::GetHwndRenderTarget  
 Interface de ID2D1HwndRenderTarget retorna.  
  
```  
ID2D1HwndRenderTarget* GetHwndRenderTarget();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1HwndRenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="a-namemphwndrendertargeta--chwndrendertargetmphwndrendertarget"></a><a name="m_phwndrendertarget"></a>CHwndRenderTarget::m_pHwndRenderTarget  
 Um ponteiro para um objeto ID2D1HwndRenderTarget.  
  
```  
ID2D1HwndRenderTarget* m_pHwndRenderTarget;  
```  
  
##  <a name="a-nameoperatorid2d1hwndrendertargetstara--chwndrendertargetoperator-id2d1hwndrendertarget"></a><a name="operator_id2d1hwndrendertarget_star"></a>CHwndRenderTarget::operator ID2D1HwndRenderTarget *  
 Interface de ID2D1HwndRenderTarget retorna.  
  
```  
operator ID2D1HwndRenderTarget*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1HwndRenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="a-namerecreatea--chwndrendertargetrecreate"></a><a name="recreate"></a>CHwndRenderTarget::ReCreate  
 Cria um destino de renderização associado à janela novamente  
  
```  
BOOL ReCreate(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 O HWND associado a esse destino de renderização  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retorna FALSE.  
  
##  <a name="a-nameresizea--chwndrendertargetresize"></a><a name="resize"></a>CHwndRenderTarget::Resize  
 Altera o tamanho do destino de renderização para o tamanho de pixel especificado  
  
```  
BOOL Resize(const CD2DSizeU& size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 O novo tamanho do destino de renderização em pixels do dispositivo  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retorna FALSE.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

