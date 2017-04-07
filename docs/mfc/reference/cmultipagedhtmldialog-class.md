---
title: Classe CMultiPageDHtmlDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMultiPageDHtmlDialog
- AFXDHTML/CMultiPageDHtmlDialog
- AFXDHTML/CMultiPageDHtmlDialog::CMultiPageDHtmlDialog
dev_langs:
- C++
helpviewer_keywords:
- CMultiPageDHtmlDialog class
ms.assetid: 971accc1-824d-4df4-b4c1-b1a20e0f7e4f
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
ms.openlocfilehash: c00af20731b2c47a0074366722da3f4a0711ef85
ms.lasthandoff: 02/25/2017

---
# <a name="cmultipagedhtmldialog-class"></a>Classe CMultiPageDHtmlDialog
Uma caixa de diálogo de Multipágina exibe várias páginas HTML sequencialmente e trata os eventos de cada página.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMultiPageDHtmlDialog : public CDHtmlDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMultiPageDHtmlDialog::CMultiPageDHtmlDialog](#cmultipagedhtmldialog)|Constrói um objeto de caixa de diálogo com várias páginas (estilo de assistente) DHTML.|  
|[CMultiPageDHtmlDialog:: ~ CMultiPageDHtmlDialog](#cmultipagedhtmldialog__~cmultipagedhtmldialog)|Destrói um objeto de caixa de diálogo DHTML várias páginas.|  
  
## <a name="remarks"></a>Comentários  
 O mecanismo para fazer isso é uma [mapa de evento DHTML e URL](http://msdn.microsoft.com/en-us/2a7332f0-79d7-46e4-b816-0a618c46777a), que contém [incorporado mapas de evento](http://msdn.microsoft.com/library/5346210f-f8b7-4e28-9d2c-d9d7fd42421d) para cada página.  
  
## <a name="example"></a>Exemplo  
 Essa caixa de diálogo de Multipágina assume três recursos HTML que definem a funcionalidade de assistente simples. A primeira página tem uma `Next` botão, o segundo um **Prev** e `Next` botão e a terceira um **Prev** botão. Quando um dos botões é pressionado, chama uma função de manipulador [CDHtmlDialog::LoadFromResource](../../mfc/reference/cdhtmldialog-class.md#loadfromresource) para carregar a nova página apropriada.  
  
 As partes relevantes da declaração de classe (em CMyMultiPageDlg.h):  
  
 [!code-cpp[NVC_MFCDocView&#181;](../../mfc/codesnippet/cpp/cmultipagedhtmldialog-class_1.h)]  
  
 As partes relevantes da implementação de classe (em CMyMultipageDlg.cpp):  
  
 [!code-cpp[NVC_MFCDocView&#182;](../../mfc/codesnippet/cpp/cmultipagedhtmldialog-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDHtmlSinkHandlerBase2`  
  
 `CDHtmlSinkHandlerBase1`  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CDHtmlSinkHandler`  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CDHtmlEventSink`  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)  
  
 `CMultiPageDHtmlDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdhtml.h  
  
##  <a name="cmultipagedhtmldialog"></a>CMultiPageDHtmlDialog::CMultiPageDHtmlDialog  
 Constrói um objeto de caixa de diálogo com várias páginas (estilo de assistente) DHTML.  
  
```  
CMultiPageDHtmlDialog(
    LPCTSTR lpszTemplateName,  
    LPCTSTR szHtmlResID = NULL,  
    CWnd* pParentWnd = NULL);

 
CMultiPageDHtmlDialog(
    UINT nIDTemplate,  
    UINT nHtmlResID = 0,  
    CWnd* pParentWnd = NULL);  
  
CMultiPageDHtmlDialog();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTemplateName`  
 A sequência terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.  
  
 `szHtmlResID`  
 A sequência terminada em nulo que é o nome de um recurso HTML.  
  
 `pParentWnd`  
 Um ponteiro para o objeto de janela pai ou proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, janela de pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
 `nIDTemplate`  
 Contém o número de identificação de um recurso de modelo de caixa de diálogo.  
  
 `nHtmlResID`  
 Contém o número de identificação de um recurso HTML.  
  
##  <a name="_dtorcmultipagedhtmldialog"></a>CMultiPageDHtmlDialog:: ~ CMultiPageDHtmlDialog  
 Destrói um objeto de caixa de diálogo DHTML várias páginas.  
  
```  
virtual ~CMultiPageDHtmlDialog();
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)

