---
title: Classe CHtmlEditCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHtmlEditCtrl
- AFXHTML/CHtmlEditCtrl
- AFXHTML/CHtmlEditCtrl::CHtmlEditCtrl
- AFXHTML/CHtmlEditCtrl::Create
- AFXHTML/CHtmlEditCtrl::GetDHtmlDocument
- AFXHTML/CHtmlEditCtrl::GetStartDocument
dev_langs:
- C++
helpviewer_keywords:
- CHtmlEditCtrl [MFC], CHtmlEditCtrl
- CHtmlEditCtrl [MFC], Create
- CHtmlEditCtrl [MFC], GetDHtmlDocument
- CHtmlEditCtrl [MFC], GetStartDocument
ms.assetid: 0fc4a238-b05f-4874-9edc-6a6701f064d9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f3ea794bfcb3d7e62a53ed8423918e5448990dae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chtmleditctrl-class"></a>Classe CHtmlEditCtrl
Fornece a funcionalidade do controle ActiveX do WebBrowser em uma janela do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHtmlEditCtrl: public CWnd,   
    public CHtmlEditCtrlBase<CHtmlEditCtrl>  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditCtrl::CHtmlEditCtrl](#chtmleditctrl)|Constrói um objeto `CHtmlEditCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditCtrl::Create](#create)|Cria um controle WebBrowser ActiveX e anexa-o para o `CHtmlEditCtrl` objeto. Essa função automaticamente coloca o controle WebBrowser ActiveX no modo de edição.|  
|[CHtmlEditCtrl::GetDHtmlDocument](#getdhtmldocument)|Recupera o [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface no documento atualmente carregados no controle do WebBrowser independente.|  
|[CHtmlEditCtrl::GetStartDocument](#getstartdocument)|Recupera a URL para um documento padrão para carregar no controle do WebBrowser independente.|  
  
## <a name="remarks"></a>Comentários  
 O WebBrowser hospedado controle é colocado automaticamente em modo de edição depois que ele é criado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CHtmlEditCtrlBase](../../mfc/reference/chtmleditctrlbase-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CHtmlEditCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxhtml.h  
  
##  <a name="chtmleditctrl"></a>CHtmlEditCtrl::CHtmlEditCtrl  
 Constrói um objeto `CHtmlEditCtrl`.  
  
```  
CHtmlEditCtrl();
```  
  
##  <a name="create"></a>CHtmlEditCtrl::Create  
 Cria um controle WebBrowser ActiveX e anexa-o para o `CHtmlEditCtrl` objeto. O WebBrowser ActiveX automaticamente navega para um documento padrão de controle e, em seguida, é colocado no modo de edição por essa função.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    int nID,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszWindowName`  
 Esse parâmetro não está em uso.  
  
 `dwStyle`  
 Esse parâmetro não está em uso.  
  
 `rect`  
 Especifica o tamanho e a posição do controle.  
  
 `pParentWnd`  
 Especifica a janela pai do controle. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a identificação. do controle  
  
 `pContext`  
 Esse parâmetro não está em uso.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
##  <a name="getdhtmldocument"></a>CHtmlEditCtrl::GetDHtmlDocument  
 Recupera o [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface no documento atualmente carregados no controle do WebBrowser independente  
  
```  
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppDocument`  
 A interface de documento.  
  
##  <a name="getstartdocument"></a>CHtmlEditCtrl::GetStartDocument  
 Recupera a URL para um documento padrão para carregar no controle do WebBrowser independente.  
  
```  
virtual LPCTSTR GetStartDocument();
```  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

