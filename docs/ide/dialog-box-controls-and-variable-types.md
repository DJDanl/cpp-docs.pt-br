---
title: Controles de caixa de diálogo e tipos de variável | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dialog box controls, member variables
- dialog box controls, variable types
- variables, dialog box control member variables
ms.assetid: f9cd9cea-45a6-4349-8358-e5efbcdcff76
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6914ab8b5838ee6bc5bb7a74004ed986efe2fcda
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373981"
---
# <a name="dialog-box-controls-and-variable-types"></a>Controles da caixa de diálogo e tipos de variável

Use o [Assistente de Adição de Variável de Membro](../ide/add-member-variable-wizard.md) para adicionar uma variável de membro a um controle de caixa de diálogo criado usando o MFC. O tipo de controle ao qual você adiciona a variável de membro determina as opções exibidas na caixa de diálogo.

A tabela a seguir descreve todos os tipos de controle de caixa de diálogo compatíveis com o MFC e o [Editor de Caixas de Diálogo](../windows/dialog-editor.md), bem como seus tipos e valores disponíveis.

|Controle|Tipo de controle|Tipo de variável de controle|Tipo de variável de valor|Valores mín./máx. (somente tipo de valor)|
|-------------|------------------|---------------------------|-------------------------|-----------------------------------------|
|Controle de animação|SysAnimate32|[CAnimateCtrl](../mfc/reference/canimatectrl-class.md)|Nenhum; somente controle|N/D|
|Botão|BUTTON|[CButton](../mfc/reference/cbutton-class.md)|Nenhum; somente controle|N/D|
|Caixa de seleção|CHECK|[CButton](../mfc/reference/cbutton-class.md)|**BOOL**|Valor mín./valor máx.|
|Caixa de combinação|COMBOBOX|[CComboBox](../mfc/reference/ccombobox-class.md)|[CString](../atl-mfc-shared/reference/cstringt-class.md)|Número máx. de caracteres|
|Controle de seletor de data e hora|SysDateTimePick32|[CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)|[CTime](../atl-mfc-shared/reference/ctime-class.md)|Valor mín./valor máx.|
|Caixa de edição|EDIT|[CEdit](../mfc/reference/cedit-class.md)|`CString`, int, UINT, long, DWORD, float, double, BYTE, short, BOOL, `COleDateTime` ou **COleCurrency**|Valor mín./valor máx.; alguns dão suporte ao número máximo de caracteres|
|Controle de tecla de acesso|msctls_hotkey32|[CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)|Nenhum; somente controle|N/D|
|Caixa de listagem|LISTBOX|[CListBox](../mfc/reference/clistbox-class.md)|`CString`|Número máx. de caracteres|
|Controle de lista|SysListView32|[CListCtrl](../mfc/reference/clistctrl-class.md)|Nenhum; somente controle|N/D|
|Controle de calendário mensal|SysMonthCal32|[CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)|`CTime`|Valor mín./valor máx.|
|Controle de progresso|msctls_progress32|[CProgressCtrl](../mfc/reference/cprogressctrl-class.md)|Nenhum; somente controle|N/D|
|Controle de Rich Edit 2|RichEdit20A|[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)|`CString`|Número máx. de caracteres|
|Controle de Rich Edit|RICHEDIT|`CRichEditCtrl`|`CString`|Número máx. de caracteres|
|Barra de rolagem (vertical ou horizontal)|SCROLLBAR|[CScrollBar](../mfc/reference/cscrollbar-class.md)|`int`|Valor mín./valor máx.|
|Controle deslizante|msctls_trackbar32|[CSliderCtrl](../mfc/reference/csliderctrl-class.md)|`int`|Valor mín./valor máx.|
|Controle de giro|msctls_updown32|[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)|Nenhum; somente controle|N/D|
|Controle guia|SysTabControl32|[CTabCtrl](../mfc/reference/ctabctrl-class.md)|Nenhum; somente controle|N/D|
|Controle de árvore|SysTreeView32|[CTreeCtrl](../mfc/reference/ctreectrl-class.md)|Nenhum; somente controle|N/D|

## <a name="see-also"></a>Consulte também

[Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)