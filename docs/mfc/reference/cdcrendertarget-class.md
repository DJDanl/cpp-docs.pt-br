---
title: Classe CDCRenderTarget | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxrendertarget/CDCRenderTarget
- CDCRenderTarget
dev_langs:
- C++
helpviewer_keywords:
- CDCRenderTarget class
ms.assetid: aa8059c9-08e6-49e4-9b8c-00fa54077a61
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 2bbd62b06f4287904fce49f8a6ce9900476b07c0
ms.lasthandoff: 02/25/2017

---
# <a name="cdcrendertarget-class"></a>Classe CDCRenderTarget
Um wrapper para ID2D1DCRenderTarget.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDCRenderTarget : public CRenderTarget;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDCRenderTarget::CDCRenderTarget](#cdcrendertarget)|Constrói um objeto CDCRenderTarget.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDCRenderTarget::Attach](#attach)|Conexões existentes renderizam a interface de destino para o objeto|  
|[CDCRenderTarget::BindDC](#binddc)|Associa o destino de renderização para o contexto de dispositivo para que ele emite comandos de desenho|  
|[CDCRenderTarget::Create](#create)|Cria um CDCRenderTarget.|  
|[CDCRenderTarget::Detach](#detach)|Desconecta a interface de destino de renderização do objeto|  
|[CDCRenderTarget::GetDCRenderTarget](#getdcrendertarget)|Interface de ID2D1DCRenderTarget retorna|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDCRenderTarget::operator ID2D1DCRenderTarget *](#operator_id2d1dcrendertarget_star)|Interface de ID2D1DCRenderTarget retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDCRenderTarget::m_pDCRenderTarget](#m_pdcrendertarget)|Um ponteiro para um objeto ID2D1DCRenderTarget.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CRenderTarget](../../mfc/reference/crendertarget-class.md)  
  
 [CDCRenderTarget](../../mfc/reference/cdcrendertarget-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="a-nameattacha--cdcrendertargetattach"></a><a name="attach"></a>CDCRenderTarget::Attach  
 Conexões existentes renderizam a interface de destino para o objeto  
  
```  
void Attach(ID2D1DCRenderTarget* pTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTarget`  
 Interface de destino de renderização existente. Não pode ser nulo  
  
##  <a name="a-namebinddca--cdcrendertargetbinddc"></a><a name="binddc"></a>CDCRenderTarget::BindDC  
 Associa o destino de renderização para o contexto de dispositivo para que ele emite comandos de desenho  
  
```  
BOOL BindDC(
    const CDC& dc,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dc`  
 O contexto de dispositivo para o qual o destino de renderização emite comandos de desenho  
  
 `rect`  
 As dimensões do identificador para um contexto de dispositivo (HDC) ao qual o destino de renderização é acoplado  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retorna FALSE.  
  
##  <a name="a-namecdcrendertargeta--cdcrendertargetcdcrendertarget"></a><a name="cdcrendertarget"></a>CDCRenderTarget::CDCRenderTarget  
 Constrói um objeto CDCRenderTarget.  
  
```  
CDCRenderTarget();
```  
  
##  <a name="a-namecreatea--cdcrendertargetcreate"></a><a name="create"></a>CDCRenderTarget::Create  
 Cria um CDCRenderTarget.  
  
```  
BOOL Create(const D2D1_RENDER_TARGET_PROPERTIES& props);
```  
  
### <a name="parameters"></a>Parâmetros  
 `props`  
 O modo de renderização, formato de pixel, opções de comunicação remota, informações de DPI e o suporte a DirectX mínimo necessário para a renderização de hardware.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retorna FALSE.  
  
##  <a name="a-namedetacha--cdcrendertargetdetach"></a><a name="detach"></a>CDCRenderTarget::Detach  
 Desconecta a interface de destino de renderização do objeto  
  
```  
ID2D1DCRenderTarget* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para desanexado renderizar a interface de destino.  
  
##  <a name="a-namegetdcrendertargeta--cdcrendertargetgetdcrendertarget"></a><a name="getdcrendertarget"></a>CDCRenderTarget::GetDCRenderTarget  
 Interface de ID2D1DCRenderTarget retorna  
  
```  
ID2D1DCRenderTarget* GetDCRenderTarget();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1DCRenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="a-namempdcrendertargeta--cdcrendertargetmpdcrendertarget"></a><a name="m_pdcrendertarget"></a>CDCRenderTarget::m_pDCRenderTarget  
 Um ponteiro para um objeto ID2D1DCRenderTarget.  
  
```  
ID2D1DCRenderTarget* m_pDCRenderTarget;  
```  
  
##  <a name="a-nameoperatorid2d1dcrendertargetstara--cdcrendertargetoperator-id2d1dcrendertarget"></a><a name="operator_id2d1dcrendertarget_star"></a>CDCRenderTarget::operator ID2D1DCRenderTarget *  
 Interface de ID2D1DCRenderTarget retorna  
  
```  
operator ID2D1DCRenderTarget*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1DCRenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

