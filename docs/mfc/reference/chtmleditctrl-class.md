---
title: Classe CHtmlEditCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
- CHtmlEditCtrl class
ms.assetid: 0fc4a238-b05f-4874-9edc-6a6701f064d9
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 4aca52508663e94ee9a1b55843ad05613aa40b0b
ms.lasthandoff: 02/25/2017

---
# <a name="chtmleditctrl-class"></a>Classe CHtmlEditCtrl
Fornece a funcionalidade do controle WebBrowser ActiveX em uma janela do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHtmlEditCtrl: public CWnd,   
    public CHtmlEditCtrlBase<CHtmlEditCtrl>  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditCtrl::CHtmlEditCtrl](#chtmleditctrl)|Constrói um objeto `CHtmlEditCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditCtrl::Create](#create)|Cria um controle WebBrowser ActiveX e anexa-o para o `CHtmlEditCtrl` objeto. Esta função coloca automaticamente o controle WebBrowser ActiveX no modo de edição.|  
|[CHtmlEditCtrl::GetDHtmlDocument](#getdhtmldocument)|Recupera o [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface no documento atualmente carregado no controle WebBrowser independente.|  
|[CHtmlEditCtrl::GetStartDocument](#getstartdocument)|Recupera a URL para um documento padrão para carregar no controle WebBrowser independente.|  
  
## <a name="remarks"></a>Comentários  
 Hospedado WebBrowser controle automaticamente é colocado em modo de edição após sua criação.  
  
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
 `lpszWindowName`  
 Esse parâmetro é usado.  
  
 `dwStyle`  
 Esse parâmetro é usado.  
  
 `rect`  
 Especifica o tamanho e a posição do controle.  
  
 `pParentWnd`  
 Especifica a janela pai do controle. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a identificação. do controle  
  
 `pContext`  
 Esse parâmetro é usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
##  <a name="getdhtmldocument"></a>CHtmlEditCtrl::GetDHtmlDocument  
 Recupera o [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface no documento atualmente carregado no controle WebBrowser independente  
  
```  
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppDocument`  
 A interface de documento.  
  
##  <a name="getstartdocument"></a>CHtmlEditCtrl::GetStartDocument  
 Recupera a URL para um documento padrão para carregar no controle WebBrowser independente.  
  
```  
virtual LPCTSTR GetStartDocument();
```  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)


