---
title: Controles de caixa de diálogo e tipos de variáveis | Microsoft Docs
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
ms.openlocfilehash: f2fbae37072f50898181334a9059a7dc9c6a83a9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="dialog-box-controls-and-variable-types"></a>Controles da caixa de diálogo e tipos de variável
Você pode usar o [Assistente para adição de variável de membro](../ide/add-member-variable-wizard.md) para adicionar uma variável de membro a um controle de caixa de diálogo criado usando MFC. O tipo de controle para que você adicione a variável de membro determina as opções que aparecem na caixa de diálogo.  
  
 A tabela a seguir descreve todos os tipos de controle de caixa de diálogo com suporte no MFC e [Editor de caixa de diálogo](../windows/dialog-editor.md)e os tipos disponíveis e valores.  
  
|Controle|Tipo de controle|Tipo de variável de controle|Tipo de variável de valor|Valores mínimos/máximos (somente tipo de valor)|  
|-------------|------------------|---------------------------|-------------------------|-----------------------------------------|  
|Controle de animação|SysAnimate32|[CAnimateCtrl](../mfc/reference/canimatectrl-class.md)|Nenhum; apenas controle|N/D|  
|Botão|BOTÃO|[CButton](../mfc/reference/cbutton-class.md)|Nenhum; apenas controle|N/D|  
|Caixa de seleção|SELEÇÃO|[CButton](../mfc/reference/cbutton-class.md)|**BOOL**|Valor mínimo/máximo do valor|  
|Caixa de combinação|CAIXA DE COMBINAÇÃO|[CComboBox](../mfc/reference/ccombobox-class.md)|[CString](../atl-mfc-shared/reference/cstringt-class.md)|Caracteres de max|  
|Controle de seletor de tempo de data|SysDateTimePick32|[CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)|[CTime](../atl-mfc-shared/reference/ctime-class.md)|Valor mínimo/máximo do valor|  
|Caixa de edição|EDITAR|[CEdit](../mfc/reference/cedit-class.md)|`CString`, int, UINT, long, DWORD, float, double, BYTE, short, BOOL, `COleDateTime`, ou **COleCurrency**|Valor do mínimo valor/máx; Alguns caracteres máximo de suporte|  
|Controle de tecla de acesso|msctls_hotkey32|[CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)|Nenhum; apenas controle|N/D|  
|Caixa de listagem|CAIXA DE LISTAGEM|[CListBox](../mfc/reference/clistbox-class.md)|`CString`|Caracteres de max|  
|Controle de lista|SysListView32|[CListCtrl](../mfc/reference/clistctrl-class.md)|Nenhum; apenas controle|N/D|  
|Controle de calendário mensal|SysMonthCal32|[CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)|`CTime`|Valor mínimo/máximo do valor|  
|Controle de progresso|msctls_progress32|[CProgressCtrl](../mfc/reference/cprogressctrl-class.md)|Nenhum; apenas controle|N/D|  
|Controle Rich Editar 2|RichEdit20A|[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)|`CString`|Caracteres de max|  
|Controle Rich Edit|RICHEDIT|`CRichEditCtrl`|`CString`|Caracteres de max|  
|Barra de rolagem (vertical ou horizontal|BARRA DE ROLAGEM|[CScrollBar](../mfc/reference/cscrollbar-class.md)|`int`|Valor mínimo/máximo do valor|  
|Controle deslizante|msctls_trackbar32|[CSliderCtrl](../mfc/reference/csliderctrl-class.md)|`int`|Valor mínimo/máximo do valor|  
|Controle de rotação|msctls_updown32|[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)|Nenhum; apenas controle|N/D|  
|Controle de guia|SysTabControl32|[CTabCtrl](../mfc/reference/ctabctrl-class.md)|Nenhum; apenas controle|N/D|  
|Controle de árvore|SysTreeView32|[CTreeCtrl](../mfc/reference/ctreectrl-class.md)|Nenhum; apenas controle|N/D|  
  
## <a name="see-also"></a>Consulte também  
 [Adicionar uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)