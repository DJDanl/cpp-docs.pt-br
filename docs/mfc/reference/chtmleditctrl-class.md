---
title: Classe CHtmlEditCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4cc8cdc389edc8abbc424ec8277f759e7f3d81bb
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37338562"
---
# <a name="chtmleditctrl-class"></a>Classe CHtmlEditCtrl
Fornece a funcionalidade do controle WebBrowser ActiveX em uma janela MFC.  
  
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
|[CHtmlEditCtrl::GetDHtmlDocument](#getdhtmldocument)|Recupera o [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface no documento atualmente carregado no controle WebBrowser independente.|  
|[CHtmlEditCtrl::GetStartDocument](#getstartdocument)|Recupera a URL para um documento padrão a ser carregado no controle WebBrowser independente.|  
  
## <a name="remarks"></a>Comentários  
 Modo de edição WebBrowser hospedado controle é colocado automaticamente em após sua criação.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CHtmlEditCtrlBase](../../mfc/reference/chtmleditctrlbase-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CHtmlEditCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxhtml.h  
  
##  <a name="chtmleditctrl"></a>  CHtmlEditCtrl::CHtmlEditCtrl  
 Constrói um objeto `CHtmlEditCtrl`.  
  
```  
CHtmlEditCtrl();
```  
  
##  <a name="create"></a>  CHtmlEditCtrl::Create  
 Cria um controle WebBrowser ActiveX e anexa-o para o `CHtmlEditCtrl` objeto. O WebBrowser ActiveX controle automaticamente navega para um documento padrão e, em seguida, é colocado no modo de edição por essa função.  
  
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
 *lpszWindowName*  
 Esse parâmetro não está em uso.  
  
 *dwStyle*  
 Esse parâmetro não está em uso.  
  
 *Rect*  
 Especifica o tamanho e a posição do controle.  
  
 *pParentWnd*  
 Especifica a janela pai do controle. Ele não deve ser NULL.  
  
 *nID*  
 Especifica a ID. do controle  
  
 *pContext*  
 Esse parâmetro não está em uso.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
##  <a name="getdhtmldocument"></a>  CHtmlEditCtrl::GetDHtmlDocument  
 Recupera o [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface no documento atualmente carregado no controle WebBrowser independente  
  
```  
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppDocument*  
 A interface de documento.  
  
##  <a name="getstartdocument"></a>  CHtmlEditCtrl::GetStartDocument  
 Recupera a URL para um documento padrão a ser carregado no controle WebBrowser independente.  
  
```  
virtual LPCTSTR GetStartDocument();
```  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

