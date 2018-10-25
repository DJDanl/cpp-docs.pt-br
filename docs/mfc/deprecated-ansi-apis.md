---
title: APIs ANSI preteridas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, ANSI deprecated methods
ms.assetid: c7c5a6fd-95e4-4bee-b3d5-d3826c30947d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: acf27499e96cbdd93fdd6855966528f750a99f77
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50062246"
---
# <a name="deprecated-ansi-apis"></a>APIs ANSI preteridas

A biblioteca Microsoft Foundation Class (MFC) está migrando em direção a classes e métodos que se baseiam no conjunto de caracteres Unicode. Consequentemente, as versões ANSI de vários métodos MFC foram preteridas. Use as versões Unicode desses métodos em seus aplicativos futuros.

Começando com a controles comuns do Windows versão 6.1, que é fornecida no Windows Vista, os seguintes métodos de ANSI são preteridos.

## <a name="cbutton-class"></a>Classe CButton

```
AFX_ANSI_DEPRECATED BOOL GetIdealSize(LPSIZE psize) const;

AFX_ANSI_DEPRECATED BOOL GetImageList(PBUTTON_IMAGELIST pbuttonImagelist) const;

AFX_ANSI_DEPRECATED BOOL GetTextMargin(LPRECT pmargin) const;

AFX_ANSI_DEPRECATED BOOL SetImageList(PBUTTON_IMAGELIST pbuttonImagelist);

AFX_ANSI_DEPRECATED BOOL SetTextMargin(LPRECT pmargin);
```

## <a name="ccomboboxex-class"></a>Classe CComboBoxEx

```
AFX_ANSI_DEPRECATED HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

## <a name="cedit-class"></a>Classe CEdit

```
AFX_ANSI_DEPRECATED BOOL GetCueBanner(LPWSTR lpszText,
    int cchText) const;

AFX_ANSI_DEPRECATED BOOL SetCueBanner(LPCWSTR lpszText,
    BOOL fDrawIfFocused = FALSE);
```

## <a name="clinkctrl-class"></a>Classe CLinkCtrl

A classe inteira foi preterida.

## <a name="clistctrl-class"></a>Classe CListCtrl

```
AFX_ANSI_DEPRECATED void CancelEditLabel();

AFX_ANSI_DEPRECATED int EnableGroupView(BOOL fEnable);

AFX_ANSI_DEPRECATED int GetGroupInfo(int iGroupId,
    PLVGROUP pgrp) const;

AFX_ANSI_DEPRECATED void GetGroupMetrics(PLVGROUPMETRICS pGroupMetrics) const;

AFX_ANSI_DEPRECATED BOOL GetInsertMark(LPLVINSERTMARK lvim) const;

AFX_ANSI_DEPRECATED COLORREF GetInsertMarkColor() const;

AFX_ANSI_DEPRECATED int GetInsertMarkRect(LPRECT pRect) const;

AFX_ANSI_DEPRECATED COLORREF GetOutlineColor() const;

AFX_ANSI_DEPRECATED UINT GetSelectedColumn() const;

AFX_ANSI_DEPRECATED BOOL GetTileInfo(PLVTILEINFO pti) const;

AFX_ANSI_DEPRECATED BOOL GetTileViewInfo(PLVTILEVIEWINFO ptvi) const;

AFX_ANSI_DEPRECATED DWORD GetView() const;

AFX_ANSI_DEPRECATED BOOL HasGroup(int iGroupId) const;

AFX_ANSI_DEPRECATED int InsertGroup(int index,
    PLVGROUP pgrp);

AFX_ANSI_DEPRECATED void InsertGroupSorted(PLVINSERTGROUPSORTED pStructInsert);

AFX_ANSI_DEPRECATED int InsertMarkHitTest(LPPOINT pPoint,
    LPLVINSERTMARK lvim) const;

AFX_ANSI_DEPRECATED BOOL IsGroupViewEnabled() const;

AFX_ANSI_DEPRECATED void MoveGroup(int iGroupId,
    int toIndex);

AFX_ANSI_DEPRECATED void MoveItemToGroup(int idItemFrom,
    int idGroupTo);

AFX_ANSI_DEPRECATED void RemoveAllGroups();

AFX_ANSI_DEPRECATED int RemoveGroup(int iGroupId);

AFX_ANSI_DEPRECATED BOOL SetGroupInfo(int iGroupId,
    PLVGROUP pGroup);

AFX_ANSI_DEPRECATED void SetGroupMetrics(PLVGROUPMETRICS pGroupMetrics);

AFX_ANSI_DEPRECATED BOOL SetInfoTip(PLVSETINFOTIP plvInfoTip);

AFX_ANSI_DEPRECATED BOOL SetInsertMark(LPLVINSERTMARK lvim);

AFX_ANSI_DEPRECATED COLORREF SetInsertMarkColor(COLORREF color);

AFX_ANSI_DEPRECATED COLORREF SetOutlineColor(COLORREF color);

AFX_ANSI_DEPRECATED void SetSelectedColumn(int iCol);

AFX_ANSI_DEPRECATED BOOL SetTileInfo(PLVTILEINFO pti);

AFX_ANSI_DEPRECATED BOOL SetTileViewInfo(PLVTILEVIEWINFO ptvi);

AFX_ANSI_DEPRECATED DWORD SetView(int iView);

AFX_ANSI_DEPRECATED BOOL SortGroups(PFNLVGROUPCOMPARE _pfnGroupCompare,
    LPVOID _plv);
```

## <a name="crebarctrl-class"></a>Classe CReBarCtrl

```
AFX_ANSI_DEPRECATED void GetBandMargins(PMARGINS pMargins) const;

AFX_ANSI_DEPRECATED HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

## <a name="ctoolbarctrl-class"></a>Classe CToolBarCtrl

```
AFX_ANSI_DEPRECATED void GetMetrics(LPTBMETRICS ptbm) const;

AFX_ANSI_DEPRECATED void SetMetrics(LPTBMETRICS ptbm);

AFX_ANSI_DEPRECATED HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

## <a name="ctooltipctrl-class"></a>Classe CToolTipCtrl

```
AFX_ANSI_DEPRECATED HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

## <a name="see-also"></a>Consulte também

[Requisitos de build para controles comuns do Windows Vista](../mfc/build-requirements-for-windows-vista-common-controls.md)

