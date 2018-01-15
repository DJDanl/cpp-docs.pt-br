---
title: Classe CMFCToolBarInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
helpviewer_keywords:
- CMFCToolBarInfo [MFC], m_uiColdResID
- CMFCToolBarInfo [MFC], m_uiDisabledResID
- CMFCToolBarInfo [MFC], m_uiHotResID
- CMFCToolBarInfo [MFC], m_uiLargeColdResID
- CMFCToolBarInfo [MFC], m_uiLargeDisabledResID
- CMFCToolBarInfo [MFC], m_uiLargeHotResID
- CMFCToolBarInfo [MFC], m_uiMenuDisabledResID
- CMFCToolBarInfo [MFC], m_uiMenuResID
ms.assetid: 6dc84482-eaaa-491f-aa5d-dd7a57886b46
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c47be3ddb2302124b233c39aaf8bd829cd481d79
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[CMFCToolBarInfo::m_uiColdResID](#m_uicoldresid)|ID do recurso de bitmap a barra de ferramentas que contém imagens da barra de ferramentas (frio) normais.|  
|[CMFCToolBarInfo::m_uiDisabledResID](#m_uidisabledresid)|ID do recurso de bitmap a barra de ferramentas que contém imagens da barra de ferramentas desabilitado.|  
|[CMFCToolBarInfo::m_uiHotResID](#m_uihotresid)|ID do recurso de bitmap a barra de ferramentas que contém imagens da barra de ferramentas (ativa) selecionado.|  
|[CMFCToolBarInfo::m_uiLargeColdResID](#m_uilargecoldresid)|ID do recurso de bitmap a barra de ferramentas que contém imagens grandes, regular da barra de ferramentas.|  
|[CMFCToolBarInfo::m_uiLargeDisabledResID](#m_uilargedisabledresid)|ID do recurso do bitmap da barra de ferramentas que contém um grande, desabilitado imagens da barra de ferramentas.|  
|[CMFCToolBarInfo::m_uiLargeHotResID](#m_uilargehotresid)|ID do recurso do bitmap da barra de ferramentas que contém imagens da barra de ferramentas selecionado e grande.|  
|[CMFCToolBarInfo::m_uiMenuDisabledResID](#m_uimenudisabledresid)|ID do recurso de bitmap a barra de ferramentas que contém imagens de menu desativado.|  
|[CMFCToolBarInfo::m_uiMenuResID](#m_uimenuresid)|ID do recurso de bitmap a barra de ferramentas que contém imagens de menu.|  
  
## <a name="remarks"></a>Comentários  
 Um bitmap de barra de ferramentas inteira consiste em imagens de pequena barra de ferramentas (botões) de tamanho fixo. Cada ID de recurso que é armazenado em um `CMFCToolBarInfo` objeto é um bitmap que contém um conjunto completo de imagens de barra de ferramentas em um único estado (por exemplo, selecionado, desabilitado, grandes ou imagens de menu).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCToolBarInfo](../../mfc/reference/cmfctoolbarinfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbar.h  
  
##  <a name="m_uicoldresid"></a>CMFCToolBarInfo::m_uiColdResID  
 Especifica uma ID de recurso para todas as imagens regulares de botão da barra de ferramentas.  
  
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
 Especifica uma ID de recurso para todas as imagens de botão regular grande de uma barra de ferramentas.  
  
```  
UINT m_uiLargeColdResID  
```  
  
##  <a name="m_uilargedisabledresid"></a>CMFCToolBarInfo::m_uiLargeDisabledResID  
 Especifica uma ID de recurso para todas as imagens de botão desabilitado grande de uma barra de ferramentas.  
  
```  
UINT m_uiLargeDisabledResID;  
```  
  
##  <a name="m_uilargehotresid"></a>CMFCToolBarInfo::m_uiLargeHotResID  
 Especifica uma ID de recurso para todas as imagens realçadas grandes de uma barra de ferramentas.  
  
```  
UINT m_uiLargeHotResID;  
```  
  
##  <a name="m_uimenudisabledresid"></a>CMFCToolBarInfo::m_uiMenuDisabledResID  
 Especifica uma ID de recurso para as imagens disponíveis com o comando da barra de ferramentas.  
  
```  
UINT m_uiMenuDisabledResID;  
```  
  
##  <a name="m_uimenuresid"></a>CMFCToolBarInfo::m_uiMenuResID  
 Especifica uma ID de recurso para todas as imagens de item de menu comum de uma barra de ferramentas.  
  
```  
UINT m_uiMenuResID;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
