---
title: Classe CMultiPageDHtmlDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMultiPageDHtmlDialog
- AFXDHTML/CMultiPageDHtmlDialog
- AFXDHTML/CMultiPageDHtmlDialog::CMultiPageDHtmlDialog
dev_langs:
- C++
helpviewer_keywords:
- CMultiPageDHtmlDialog [MFC], CMultiPageDHtmlDialog
ms.assetid: 971accc1-824d-4df4-b4c1-b1a20e0f7e4f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 51e9b34252b2a3fa7d097914360b9ee24baa8301
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37850859"
---
# <a name="cmultipagedhtmldialog-class"></a>Classe CMultiPageDHtmlDialog
Uma caixa de diálogo várias páginas exibe várias páginas HTML em sequência e trata os eventos de cada página.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMultiPageDHtmlDialog : public CDHtmlDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMultiPageDHtmlDialog::CMultiPageDHtmlDialog](#cmultipagedhtmldialog)|Constrói um objeto de caixa de diálogo várias páginas (estilo de assistente) DHTML.|  
|[CMultiPageDHtmlDialog:: ~ CMultiPageDHtmlDialog](#cmultipagedhtmldialog__~cmultipagedhtmldialog)|Destrói um objeto de caixa de diálogo DHTML várias páginas.|  
  
## <a name="remarks"></a>Comentários  
 O mecanismo para fazer isso é um [mapa de evento DHTML e URL](dhtml-event-maps.md), que contém inseridos mapas de evento para cada página.  
  
## <a name="example"></a>Exemplo  
 Essa caixa de diálogo de Multipágina assume três recursos HTML que definem a funcionalidade de assistente como simple. A primeira página tem um **próxima** botão, o segundo um **Prev** e **próxima** botão e a terceira um **Prev** botão. Quando um dos botões é pressionado, uma função de manipulador chama [CDHtmlDialog::LoadFromResource](../../mfc/reference/cdhtmldialog-class.md#loadfromresource) para carregar a nova página apropriada.  
  
 As partes pertinentes de declaração de classe (em CMyMultiPageDlg.h):  
  
 [!code-cpp[NVC_MFCDocView#181](../../mfc/codesnippet/cpp/cmultipagedhtmldialog-class_1.h)]  
  
 As partes pertinentes da implementação da classe (em CMyMultipageDlg.cpp):  
  
 [!code-cpp[NVC_MFCDocView#182](../../mfc/codesnippet/cpp/cmultipagedhtmldialog-class_2.cpp)]  
  
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
  
##  <a name="cmultipagedhtmldialog"></a>  CMultiPageDHtmlDialog::CMultiPageDHtmlDialog  
 Constrói um objeto de caixa de diálogo várias páginas (estilo de assistente) DHTML.  
  
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
 *lpszTemplateName*  
 A cadeia terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.  
  
 *szHtmlResID*  
 A cadeia terminada em nulo que é o nome de um recurso HTML.  
  
 *pParentWnd*  
 Um ponteiro para o objeto de janela pai ou o proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela do pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
 *nIDTemplate*  
 Contém o número de identificação de um recurso de modelo de caixa de diálogo.  
  
 *nHtmlResID*  
 Contém o número de identificação de um recurso HTML.  
  
##  <a name="_dtorcmultipagedhtmldialog"></a>  CMultiPageDHtmlDialog:: ~ CMultiPageDHtmlDialog  
 Destrói um objeto de caixa de diálogo DHTML várias páginas.  
  
```  
virtual ~CMultiPageDHtmlDialog();
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)
