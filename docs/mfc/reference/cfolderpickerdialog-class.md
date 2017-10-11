---
title: Classe CFolderPickerDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CFolderPickerDialog
- AFXDLGS/CFolderPickerDialog
- AFXDLGS/CFolderPickerDialog::CFolderPickerDialog
dev_langs:
- C++
helpviewer_keywords:
- CFolderPickerDialog [MFC], CFolderPickerDialog
ms.assetid: 8db01684-dd1d-4e9c-989e-07a2318a8156
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 2ca0f618006345d0d36650655a4e62d721b4d4d4
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cfolderpickerdialog-class"></a>Classe CFolderPickerDialog
Classe CFolderPickerDialog implementa CFileDialog no modo do seletor de pasta.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFolderPickerDialog : public CFileDialog;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFolderPickerDialog:: ~ CFolderPickerDialog](#cfolderpickerdialog__~cfolderpickerdialog)|Destruidor.|  
|[CFolderPickerDialog::CFolderPickerDialog](#cfolderpickerdialog)|Construtor.|  
  
## <a name="remarks"></a>Comentários  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [CFileDialog](../../mfc/reference/cfiledialog-class.md)  
  
 `CFolderPickerDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
##  <a name="cfolderpickerdialog"></a>CFolderPickerDialog::CFolderPickerDialog  
 Construtor.  
  
```  
explicit CFolderPickerDialog(
    LPCTSTR lpszFolder = NULL,  
    DWORD dwFlags = 0,  
    CWnd* pParentWnd = NULL,  
    DWORD dwSize = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFolder`  
 Pasta inicial.  
  
 `dwFlags`  
 Uma combinação de um ou mais sinalizadores que permitem que você personalize a caixa de diálogo.  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai ou o proprietário do objeto de caixa de diálogo.  
  
 `dwSize`  
 O tamanho da estrutura OPENFILENAME.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="_dtorcfolderpickerdialog"></a>CFolderPickerDialog:: ~ CFolderPickerDialog  
 Destruidor.  
  
```  
virtual ~CFolderPickerDialog();
```  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

