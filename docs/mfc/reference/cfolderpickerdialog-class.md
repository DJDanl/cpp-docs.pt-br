---
title: Classe CFolderPickerDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxdlgs/CFolderPickerDialog
- CFolderPickerDialog
dev_langs:
- C++
helpviewer_keywords:
- CFolderPickerDialog class
ms.assetid: 8db01684-dd1d-4e9c-989e-07a2318a8156
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 0d020544a16056d3f4db538750ed5a16b54f9a51
ms.lasthandoff: 02/25/2017

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
 **Cabeçalho:** afxdlgs. h  
  
##  <a name="a-namecfolderpickerdialoga--cfolderpickerdialogcfolderpickerdialog"></a><a name="cfolderpickerdialog"></a>CFolderPickerDialog::CFolderPickerDialog  
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
  
##  <a name="a-namedtorcfolderpickerdialoga--cfolderpickerdialogcfolderpickerdialog"></a><a name="_dtorcfolderpickerdialog"></a>CFolderPickerDialog:: ~ CFolderPickerDialog  
 Destruidor.  
  
```  
virtual ~CFolderPickerDialog();
```  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

