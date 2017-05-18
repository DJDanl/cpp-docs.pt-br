---
title: Classe CMFCToolBarInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolBarInfo
- AFXTOOLBAR/CMFCToolBarInfo
- AFXTOOLBAR/CMFCToolBarInfo::m_uiColdResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiDisabledResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiHotResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiLargeColdResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiLargeDisabledResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiLargeHotResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiMenuDisabledResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiMenuResID
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarInfo class
ms.assetid: 6dc84482-eaaa-491f-aa5d-dd7a57886b46
caps.latest.revision: 22
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: a9e66ffa0b5a751a7e5711ed20927a6adcede45d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctoolbarinfo-class"></a>Classe CMFCToolBarInfo
Contém o recurso IDs de imagens da barra de ferramentas em vários estados. `CMFCToolBarInfo`é uma classe auxiliar que é usada como um parâmetro de [CMFCToolBar::LoadToolBarEx](../../mfc/reference/cmfctoolbar-class.md#loadtoolbarex) método.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarInfo  
```  
  
## <a name="members"></a>Membros  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarInfo::m_uiColdResID](#m_uicoldresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens da barra de ferramentas normais (frio).|  
|[CMFCToolBarInfo::m_uiDisabledResID](#m_uidisabledresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens da barra de ferramentas desativado.|  
|[CMFCToolBarInfo::m_uiHotResID](#m_uihotresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens da barra de ferramentas selecionada (ativa).|  
|[CMFCToolBarInfo::m_uiLargeColdResID](#m_uilargecoldresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens grandes e regular da barra de ferramentas.|  
|[CMFCToolBarInfo::m_uiLargeDisabledResID](#m_uilargedisabledresid)|ID do recurso do bitmap da barra de ferramentas que contém grande, desabilitado imagens da barra de ferramentas.|  
|[CMFCToolBarInfo::m_uiLargeHotResID](#m_uilargehotresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens grandes de ferramentas selecionado.|  
|[CMFCToolBarInfo::m_uiMenuDisabledResID](#m_uimenudisabledresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens de menu desativado.|  
|[CMFCToolBarInfo::m_uiMenuResID](#m_uimenuresid)|ID de recurso do bitmap da barra de ferramentas que contém o menu images.|  
  
## <a name="remarks"></a>Comentários  
 Um bitmap da barra de ferramentas inteira consiste em imagens pequena barra de ferramentas (botões) de tamanho fixo. Cada ID de recurso que é armazenado em uma `CMFCToolBarInfo` objeto é um bitmap que contém um conjunto completo de imagens de barra de ferramentas em um único estado (por exemplo, selecionado, desabilitado, grandes ou o menu images).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCToolBarInfo](../../mfc/reference/cmfctoolbarinfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbar. h  
  
##  <a name="m_uicoldresid"></a>CMFCToolBarInfo::m_uiColdResID  
 Especifica uma ID de recurso para todas as imagens de botão regular da barra de ferramentas.  
  
```  
UINT m_uiColdResID;  
```  
  
##  <a name="m_uidisabledresid"></a>CMFCToolBarInfo::m_uiDisabledResID  
 Especifica uma ID de recurso para as imagens disponíveis com o botão da barra de ferramentas.  
  
```  
UINT m_uiDisabledResID;  
```  
  
##  <a name="m_uihotresid"></a>CMFCToolBarInfo::m_uiHotResID  
 Especifica uma ID de recurso para todas as imagens de botão realçado da barra de ferramentas.  
  
```  
UINT m_uiHotResID  
```  
  
##  <a name="m_uilargecoldresid"></a>CMFCToolBarInfo::m_uiLargeColdResID  
 Especifica uma ID de recurso para todas as imagens grandes button normal de uma barra de ferramentas.  
  
```  
UINT m_uiLargeColdResID  
```  
  
##  <a name="m_uilargedisabledresid"></a>CMFCToolBarInfo::m_uiLargeDisabledResID  
 Especifica uma ID de recurso para todas as imagens de botões desabilitados grandes da barra de ferramentas.  
  
```  
UINT m_uiLargeDisabledResID;  
```  
  
##  <a name="m_uilargehotresid"></a>CMFCToolBarInfo::m_uiLargeHotResID  
 Especifica uma ID de recurso para todas as imagens realçadas grandes da barra de ferramentas.  
  
```  
UINT m_uiLargeHotResID;  
```  
  
##  <a name="m_uimenudisabledresid"></a>CMFCToolBarInfo::m_uiMenuDisabledResID  
 Especifica uma ID de recurso para as imagens disponíveis com o comando de uma barra de ferramentas.  
  
```  
UINT m_uiMenuDisabledResID;  
```  
  
##  <a name="m_uimenuresid"></a>CMFCToolBarInfo::m_uiMenuResID  
 Especifica uma ID de recurso para todas as imagens de item de menu regular da barra de ferramentas.  
  
```  
UINT m_uiMenuResID;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)

