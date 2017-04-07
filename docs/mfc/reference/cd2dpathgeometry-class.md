---
title: Classe CD2DPathGeometry | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DPathGeometry
- AFXRENDERTARGET/CD2DPathGeometry
- AFXRENDERTARGET/CD2DPathGeometry::CD2DPathGeometry
- AFXRENDERTARGET/CD2DPathGeometry::Attach
- AFXRENDERTARGET/CD2DPathGeometry::Create
- AFXRENDERTARGET/CD2DPathGeometry::Destroy
- AFXRENDERTARGET/CD2DPathGeometry::Detach
- AFXRENDERTARGET/CD2DPathGeometry::GetFigureCount
- AFXRENDERTARGET/CD2DPathGeometry::GetSegmentCount
- AFXRENDERTARGET/CD2DPathGeometry::Open
- AFXRENDERTARGET/CD2DPathGeometry::Stream
- AFXRENDERTARGET/CD2DPathGeometry::m_pPathGeometry
dev_langs:
- C++
helpviewer_keywords:
- CD2DPathGeometry class
ms.assetid: 686216eb-5080-4242-ace5-8fa1ce96307c
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
ms.openlocfilehash: 1c1158e55bf12d44f34896dd6752c9b8706db636
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dpathgeometry-class"></a>Classe CD2DPathGeometry
Um wrapper para ID2D1PathGeometry.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DPathGeometry : public CD2DGeometry;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DPathGeometry::CD2DPathGeometry](#cd2dpathgeometry)|Constrói um objeto CD2DPathGeometry.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DPathGeometry::Attach](#attach)|Conexões existentes de interface de recursos para o objeto|  
|[CD2DPathGeometry::Create](#create)|Cria um CD2DPathGeometry. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DPathGeometry::Destroy](#destroy)|Destrói um objeto CD2DPathGeometry. (Substitui [CD2DGeometry::Destroy](../../mfc/reference/cd2dgeometry-class.md#destroy).)|  
|[CD2DPathGeometry::Detach](#detach)|Desconecta a interface do recurso do objeto|  
|[CD2DPathGeometry::GetFigureCount](#getfigurecount)|Recupera o número de valores no caminho da geometria.|  
|[CD2DPathGeometry::GetSegmentCount](#getsegmentcount)|Recupera o número de segmentos no caminho da geometria.|  
|[CD2DPathGeometry::Open](#open)|Recupera o coletor de geometria que é usado para preencher a geometria de caminho com figuras e segmentos.|  
|[CD2DPathGeometry::Stream](#stream)|Copia o conteúdo do caminho da geometria para o ID2D1GeometrySink especificado.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DPathGeometry::m_pPathGeometry](#m_ppathgeometry)|Um ponteiro para um ID2D1PathGeometry.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DGeometry](../../mfc/reference/cd2dgeometry-class.md)  
  
 `CD2DPathGeometry`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="attach"></a>CD2DPathGeometry::Attach  
 Conexões existentes de interface de recursos para o objeto  
  
```  
void Attach(ID2D1PathGeometry* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Interface de recursos existente. Não pode ser nulo  
  
##  <a name="cd2dpathgeometry"></a>CD2DPathGeometry::CD2DPathGeometry  
 Constrói um objeto CD2DPathGeometry.  
  
```  
CD2DPathGeometry(
    CRenderTarget* pParentTarget,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `bAutoDestroy`  
 Indica que o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="create"></a>CD2DPathGeometry::Create  
 Cria um CD2DPathGeometry.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>CD2DPathGeometry::Destroy  
 Destrói um objeto CD2DPathGeometry.  
  
```  
virtual void Destroy();
```  
  
##  <a name="detach"></a>CD2DPathGeometry::Detach  
 Desconecta a interface do recurso do objeto  
  
```  
ID2D1PathGeometry* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para interface de recursos separado.  
  
##  <a name="getfigurecount"></a>CD2DPathGeometry::GetFigureCount  
 Recupera o número de valores no caminho da geometria.  
  
```  
int GetFigureCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de valores no caminho da geometria.  
  
##  <a name="getsegmentcount"></a>CD2DPathGeometry::GetSegmentCount  
 Recupera o número de segmentos no caminho da geometria.  
  
```  
int GetSegmentCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de segmentos no caminho da geometria.  
  
##  <a name="m_ppathgeometry"></a>CD2DPathGeometry::m_pPathGeometry  
 Um ponteiro para um ID2D1PathGeometry.  
  
```  
ID2D1PathGeometry* m_pPathGeometry;  
```  
  
##  <a name="open"></a>CD2DPathGeometry::Open  
 Recupera o coletor de geometria que é usado para preencher a geometria de caminho com figuras e segmentos.  
  
```  
ID2D1GeometrySink* Open();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o ID2D1GeometrySink é usado para preencher a geometria de caminho com figuras e segmentos.  
  
##  <a name="stream"></a>CD2DPathGeometry::Stream  
 Copia o conteúdo do caminho da geometria para o ID2D1GeometrySink especificado.  
  
```  
BOOL Stream(ID2D1GeometrySink* geometrySink);
```  
  
### <a name="parameters"></a>Parâmetros  
 `geometrySink`  
 O coletor para que o conteúdo do caminho da geometria é copiado. Modificar esse coletor não altera o conteúdo do caminho da geometria.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retorna FALSE.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

