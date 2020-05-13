---
title: Classe CMultiPageDHtmlDialog
ms.date: 03/27/2019
f1_keywords:
- CMultiPageDHtmlDialog
- AFXDHTML/CMultiPageDHtmlDialog
- AFXDHTML/CMultiPageDHtmlDialog::CMultiPageDHtmlDialog
helpviewer_keywords:
- CMultiPageDHtmlDialog [MFC], CMultiPageDHtmlDialog
ms.assetid: 971accc1-824d-4df4-b4c1-b1a20e0f7e4f
ms.openlocfilehash: 89e4830c3b5c6cb663ca2d2935adaaae3f356958
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319659"
---
# <a name="cmultipagedhtmldialog-class"></a>Classe CMultiPageDHtmlDialog

Uma caixa de diálogo de várias páginas exibe várias páginas HTML sequencialmente e lida com os eventos de cada página.

## <a name="syntax"></a>Sintaxe

```
class CMultiPageDHtmlDialog : public CDHtmlDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cmultipagedhtmldiálogo::cmultipagedhtmldialog](#cmultipagedhtmldialog)|Constrói um objeto de diálogo DHTML de várias páginas (estilo assistente).|
|[cmultipagedhtmldiálogo::~cmultipagedhtmldialog](#_dtorcmultipagedhtmldialog)|Destrói um objeto de diálogo DHTML de várias páginas.|

## <a name="remarks"></a>Comentários

O mecanismo para fazer isso é um mapa de [evento DHTML e URL,](dhtml-event-maps.md)que contém mapas de eventos incorporados para cada página.

## <a name="example"></a>Exemplo

Este diálogo de várias páginas pressupõe três recursos HTML que definem funcionalidades simples semelhantes a assistentes. A primeira página tem um botão **Next,** a segunda um botão **Prev** e **Next** e a terceira um botão **Prev.** Quando um dos botões é pressionado, uma função do manipulador chama [CDHtmlDialog::LoadFromResource](../../mfc/reference/cdhtmldialog-class.md#loadfromresource) para carregar a nova página apropriada.

As partes pertinentes da declaração de classe (em CMyMultiPageDlg.h):

[!code-cpp[NVC_MFCDocView#181](../../mfc/codesnippet/cpp/cmultipagedhtmldialog-class_1.h)]

As partes pertinentes da implementação da classe (em CMyMultipageDlg.cpp):

[!code-cpp[NVC_MFCDocView#182](../../mfc/codesnippet/cpp/cmultipagedhtmldialog-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDHtmlSinkHandlerBase2`

`CDHtmlSinkHandlerBase1`

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CDHtmlSinkHandler`

[CWnd](../../mfc/reference/cwnd-class.md)

`CDHtmlEventSink`

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cdhtmldialog](../../mfc/reference/cdhtmldialog-class.md)

`CMultiPageDHtmlDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml.h

## <a name="cmultipagedhtmldialogcmultipagedhtmldialog"></a><a name="cmultipagedhtmldialog"></a>cmultipagedhtmldiálogo::cmultipagedhtmldialog

Constrói um objeto de diálogo DHTML de várias páginas (estilo assistente).

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

*lpszTemplateName*<br/>
A seqüência de seqüência de nulidade sumida é o nome de um recurso de modelo de caixa de diálogo.

*szHtmlResID*<br/>
A seqüência de terminadas nula que é o nome de um recurso HTML.

*Pparentwnd*<br/>
Um ponteiro para o objeto da janela pai ou proprietário (do tipo [CWnd)](../../mfc/reference/cwnd-class.md)ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

*Nidtemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

*nHtmlResID*<br/>
Contém o número de ID de um recurso HTML.

## <a name="cmultipagedhtmldialogcmultipagedhtmldialog"></a><a name="_dtorcmultipagedhtmldialog"></a>cmultipagedhtmldiálogo::~cmultipagedhtmldialog

Destrói um objeto de diálogo DHTML de várias páginas.

```
virtual ~CMultiPageDHtmlDialog();
```

## <a name="see-also"></a>Confira também

[Classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)
