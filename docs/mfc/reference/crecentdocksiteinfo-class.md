---
title: Classe CRecentDockSiteInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CRecentDockSiteInfo
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::CleanUp
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::GetRecentDefaultPaneDivider
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::GetRecentDockedPercent
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::GetRecentDockedRect
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::GetRecentListOfPanes
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::GetRecentPaneContainer
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::GetRecentTabContainer
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::Init
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::IsRecentLeftPane
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::SaveListOfRecentPanes
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::SetInfo
- AFXRECENTDOCKSITEINFO/CRecentDockSiteInfo::StoreDockInfo
dev_langs:
- C++
helpviewer_keywords:
- CRecentDockSiteInfo [MFC], CleanUp
- CRecentDockSiteInfo [MFC], GetRecentDefaultPaneDivider
- CRecentDockSiteInfo [MFC], GetRecentDockedPercent
- CRecentDockSiteInfo [MFC], GetRecentDockedRect
- CRecentDockSiteInfo [MFC], GetRecentListOfPanes
- CRecentDockSiteInfo [MFC], GetRecentPaneContainer
- CRecentDockSiteInfo [MFC], GetRecentTabContainer
- CRecentDockSiteInfo [MFC], Init
- CRecentDockSiteInfo [MFC], IsRecentLeftPane
- CRecentDockSiteInfo [MFC], SaveListOfRecentPanes
- CRecentDockSiteInfo [MFC], SetInfo
- CRecentDockSiteInfo [MFC], StoreDockInfo
ms.assetid: 2dd14f95-d5a2-4461-a7a5-2c6c36a3a165
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43b632408d38af9f40cb50b12e9a9734df9245dd
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065610"
---
# <a name="crecentdocksiteinfo-class"></a>Classe CRecentDockSiteInfo

O `CRecentDockSiteInfo` é uma classe auxiliar que armazena informações de estado recente o [classe CPane](../../mfc/reference/cpane-class.md).

## <a name="syntax"></a>Sintaxe

```
class CRecentDockSiteInfo : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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

O `CRecentDockSiteInfo` é uma classe de gerenciamento de dados. Ele controla o último estado de um `CPane` conforme ela passa entre o que está sendo encaixado e flutuante. Quando um usuário clica duas vezes um painel encaixável flutuante, ela se torna encaixada. O painel encaixado de clicando duas vezes retorna ao seu local anterior, o tamanho e o estado. Da mesma forma, quando o painel estiver encaixado novamente ele retorna ao seu local de encaixe anterior. Essa classe de dados é o que torna isso possível. Já que os membros dessa classe armazenam informações de estado para o painel encaixado, eles não devem ser diretamente modificados pelo seu aplicativo.

Um `CRecentDockSiteInfo` objeto é criado sempre que um painel é criado. Cada `CPane` objeto tem uma variável de membro [CPane::m_recentDockInfo](../../mfc/reference/cpane-class.md#m_recentdockinfo), para armazenar essas informações.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CRecentDockSiteInfo](../../mfc/reference/crecentdocksiteinfo-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrecentDockSiteInfo.h

##  <a name="cleanup"></a>  CRecentDockSiteInfo::CleanUp

```
void CleanUp();
```

### <a name="remarks"></a>Comentários

##  <a name="crecentdocksiteinfo"></a>  CRecentDockSiteInfo::CRecentDockSiteInfo

```
CRecentDockSiteInfo(CPane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="getrecentdefaultpanedivider"></a>  CRecentDockSiteInfo::GetRecentDefaultPaneDivider

```
CPaneDivider* GetRecentDefaultPaneDivider();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getrecentdockedpercent"></a>  CRecentDockSiteInfo::GetRecentDockedPercent

```
int GetRecentDockedPercent(BOOL bForSlider);
```

### <a name="parameters"></a>Parâmetros

[in] *bForSlider*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getrecentdockedrect"></a>  CRecentDockSiteInfo::GetRecentDockedRect

```
CRect& GetRecentDockedRect(BOOL bForSlider);
```

### <a name="parameters"></a>Parâmetros

[in] *bForSlider*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getrecentlistofpanes"></a>  CRecentDockSiteInfo::GetRecentListOfPanes

```
CList<HWND, HWND>& GetRecentListOfPanes(BOOL bForSlider);
```

### <a name="parameters"></a>Parâmetros

[in] *bForSlider*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getrecentpanecontainer"></a>  CRecentDockSiteInfo::GetRecentPaneContainer

```
CPaneContainer* GetRecentPaneContainer(BOOL bForSlider);
```

### <a name="parameters"></a>Parâmetros

[in] *bForSlider*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getrecenttabcontainer"></a>  CRecentDockSiteInfo::GetRecentTabContainer

```
CPaneContainer* GetRecentTabContainer(BOOL bForSlider);
```

### <a name="parameters"></a>Parâmetros

[in] *bForSlider*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="init"></a>  CRecentDockSiteInfo::Init

```
void Init();
```

### <a name="remarks"></a>Comentários

##  <a name="isrecentleftpane"></a>  CRecentDockSiteInfo::IsRecentLeftPane

```
BOOL IsRecentLeftPane(BOOL bForSlider);
```

### <a name="parameters"></a>Parâmetros

[in] *bForSlider*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="operator_eq"></a>  CRecentDockSiteInfo::operator =

```
CRecentDockSiteInfo& operator=(CRecentDockSiteInfo& src);
```

### <a name="parameters"></a>Parâmetros

[in] *src*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="savelistofrecentpanes"></a>  CRecentDockSiteInfo::SaveListOfRecentPanes

```
void SaveListOfRecentPanes(CList<HWND,
    HWND>& lstOrg,
    BOOL bForSlider);
```

### <a name="parameters"></a>Parâmetros

[in] *CList < HWND*<br/>
[in] *lstOrg*<br/>
[in] *bForSlider*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setinfo"></a>  CRecentDockSiteInfo::SetInfo

```
virtual void SetInfo(
    BOOL bForSlider,
    CRecentDockSiteInfo& srcInfo);
```

### <a name="parameters"></a>Parâmetros

[in] *bForSlider*<br/>
[in] *srcInfo*<br/>

### <a name="remarks"></a>Comentários

##  <a name="storedockinfo"></a>  CRecentDockSiteInfo::StoreDockInfo

```
virtual void StoreDockInfo(
    CPaneContainer* pRecentContainer,
    CDockablePane* pTabbedBar = NULL);
```

### <a name="parameters"></a>Parâmetros

[in] *pRecentContainer*<br/>
[in] *pTabbedBar*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockSite](../../mfc/reference/cdocksite-class.md)
