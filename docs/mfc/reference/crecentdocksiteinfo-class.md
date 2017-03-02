---
title: Classe CRecentDockSiteInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRecentDockSiteInfo
dev_langs:
- C++
helpviewer_keywords:
- CRecentDockSiteInfo class
ms.assetid: 2dd14f95-d5a2-4461-a7a5-2c6c36a3a165
caps.latest.revision: 26
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
ms.openlocfilehash: ae700ae78485ca4e5cfd68da0d0ae1448d1f1d5d
ms.lasthandoff: 02/25/2017

---
# <a name="crecentdocksiteinfo-class"></a>Classe CRecentDockSiteInfo
O `CRecentDockSiteInfo` classe é uma classe auxiliar que armazena informações de estado recentes para o [CPane classe](../../mfc/reference/cpane-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRecentDockSiteInfo : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CRecentDockSiteInfo::CRecentDockSiteInfo`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRecentDockSiteInfo::CleanUp](#cleanup)||  
|[CRecentDockSiteInfo::GetRecentDefaultPaneDivider](#getrecentdefaultpanedivider)||  
|[CRecentDockSiteInfo::GetRecentDockedPercent](#getrecentdockedpercent)||  
|[CRecentDockSiteInfo::GetRecentDockedRect](#getrecentdockedrect)||  
|[CRecentDockSiteInfo::GetRecentListOfPanes](#getrecentlistofpanes)||  
|[CRecentDockSiteInfo::GetRecentPaneContainer](#getrecentpanecontainer)||  
|[CRecentDockSiteInfo::GetRecentTabContainer](#getrecenttabcontainer)||  
|[CRecentDockSiteInfo::Init](#init)||  
|[CRecentDockSiteInfo::IsRecentLeftPane](#isrecentleftpane)||  
|[CRecentDockSiteInfo::operator =](#operator_eq)||  
|[CRecentDockSiteInfo::SaveListOfRecentPanes](#savelistofrecentpanes)||  
|[CRecentDockSiteInfo::SetInfo](#setinfo)||  
|[CRecentDockSiteInfo::StoreDockInfo](#storedockinfo)||  
  
## <a name="remarks"></a>Comentários  
 O `CRecentDockSiteInfo` classe é uma classe de gerenciamento de dados. Controla o último estado de um `CPane` como ela faz a transição entre sendo encaixado e flutuante. Quando um usuário clicar duas vezes um painel acoplável flutuante, ele ficará encaixado. Double clicando em painel encaixado retorna ao seu local anterior, o tamanho e o estado. Da mesma forma, quando o painel está encaixado novamente ele retorna para o local de encaixe anterior. Essa classe de dados é o que torna isso possível. Já que os membros dessa classe armazenam informações de estado para o painel encaixado, eles não devem ser diretamente modificados pelo seu aplicativo.  
  
 Um `CRecentDockSiteInfo` objeto é criado sempre que um painel é criado. Cada `CPane` objeto tem uma variável de membro, [CPane::m_recentDockInfo](../../mfc/reference/cpane-class.md#m_recentdockinfo), para armazenar essas informações.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CRecentDockSiteInfo](../../mfc/reference/crecentdocksiteinfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrecentDockSiteInfo.h  
  
##  <a name="a-namecleanupa--crecentdocksiteinfocleanup"></a><a name="cleanup"></a>CRecentDockSiteInfo::CleanUp  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void CleanUp();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecrecentdocksiteinfoa--crecentdocksiteinfocrecentdocksiteinfo"></a><a name="crecentdocksiteinfo"></a>CRecentDockSiteInfo::CRecentDockSiteInfo  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CRecentDockSiteInfo(CPane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentdefaultpanedividera--crecentdocksiteinfogetrecentdefaultpanedivider"></a><a name="getrecentdefaultpanedivider"></a>CRecentDockSiteInfo::GetRecentDefaultPaneDivider  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CPaneDivider* GetRecentDefaultPaneDivider();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentdockedpercenta--crecentdocksiteinfogetrecentdockedpercent"></a><a name="getrecentdockedpercent"></a>CRecentDockSiteInfo::GetRecentDockedPercent  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
int GetRecentDockedPercent(BOOL bForSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bForSlider`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentdockedrecta--crecentdocksiteinfogetrecentdockedrect"></a><a name="getrecentdockedrect"></a>CRecentDockSiteInfo::GetRecentDockedRect  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CRect& GetRecentDockedRect(BOOL bForSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bForSlider`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentlistofpanesa--crecentdocksiteinfogetrecentlistofpanes"></a><a name="getrecentlistofpanes"></a>CRecentDockSiteInfo::GetRecentListOfPanes  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CList<HWND, HWND>& GetRecentListOfPanes(BOOL bForSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bForSlider`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentpanecontainera--crecentdocksiteinfogetrecentpanecontainer"></a><a name="getrecentpanecontainer"></a>CRecentDockSiteInfo::GetRecentPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CPaneContainer* GetRecentPaneContainer(BOOL bForSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bForSlider`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecenttabcontainera--crecentdocksiteinfogetrecenttabcontainer"></a><a name="getrecenttabcontainer"></a>CRecentDockSiteInfo::GetRecentTabContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CPaneContainer* GetRecentTabContainer(BOOL bForSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bForSlider`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameinita--crecentdocksiteinfoinit"></a><a name="init"></a>CRecentDockSiteInfo::Init  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void Init();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisrecentleftpanea--crecentdocksiteinfoisrecentleftpane"></a><a name="isrecentleftpane"></a>CRecentDockSiteInfo::IsRecentLeftPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsRecentLeftPane(BOOL bForSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bForSlider`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameoperatoreqa--crecentdocksiteinfooperator-"></a><a name="operator_eq"></a>CRecentDockSiteInfo::operator =  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CRecentDockSiteInfo& operator=(CRecentDockSiteInfo& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesavelistofrecentpanesa--crecentdocksiteinfosavelistofrecentpanes"></a><a name="savelistofrecentpanes"></a>CRecentDockSiteInfo::SaveListOfRecentPanes  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SaveListOfRecentPanes(CList<HWND,  
    HWND>& lstOrg,  
    BOOL bForSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CList<HWND`  
 [in] `lstOrg`  
 [in] `bForSlider`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetinfoa--crecentdocksiteinfosetinfo"></a><a name="setinfo"></a>CRecentDockSiteInfo::SetInfo  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void SetInfo(
    BOOL bForSlider,  
    CRecentDockSiteInfo& srcInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bForSlider`  
 [in] `srcInfo`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namestoredockinfoa--crecentdocksiteinfostoredockinfo"></a><a name="storedockinfo"></a>CRecentDockSiteInfo::StoreDockInfo  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void StoreDockInfo(
    CPaneContainer* pRecentContainer,  
    CDockablePane* pTabbedBar = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pRecentContainer`  
 [in] `pTabbedBar`  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe de CDockSite](../../mfc/reference/cdocksite-class.md)

