---
title: Classe CHtmlEditCtrl
ms.date: 11/04/2016
f1_keywords:
- CHtmlEditCtrl
- AFXHTML/CHtmlEditCtrl
- AFXHTML/CHtmlEditCtrl::CHtmlEditCtrl
- AFXHTML/CHtmlEditCtrl::Create
- AFXHTML/CHtmlEditCtrl::GetDHtmlDocument
- AFXHTML/CHtmlEditCtrl::GetStartDocument
helpviewer_keywords:
- CHtmlEditCtrl [MFC], CHtmlEditCtrl
- CHtmlEditCtrl [MFC], Create
- CHtmlEditCtrl [MFC], GetDHtmlDocument
- CHtmlEditCtrl [MFC], GetStartDocument
ms.assetid: 0fc4a238-b05f-4874-9edc-6a6701f064d9
ms.openlocfilehash: 05063c62e9f7a5d88d3fecde842f979725200f98
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366850"
---
# <a name="chtmleditctrl-class"></a>Classe CHtmlEditCtrl

Fornece a funcionalidade do controle WebBrowser ActiveX em uma janela MFC.

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

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHtmlEditCtrl::Criar](#create)|Cria um controle ActiveX do WebBrowser `CHtmlEditCtrl` e o anexa ao objeto. Esta função coloca automaticamente o controle WebBrowser ActiveX no modo de edição.|
|[ChtmlEditCtrl::GetDHtmlDocument](#getdhtmldocument)|Recupera a interface [IHTMLDocument2](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752574\(v=vs.85\)) no documento atualmente carregado no controle do WebBrowser contido.|
|[ChtmlEditCtrl::GetStartDocument](#getstartdocument)|Recupera a URL em um documento padrão para carregar no controle do WebBrowser contido.|

## <a name="remarks"></a>Comentários

O controle do WebBrowser hospedado é automaticamente colocado no modo de edição depois de criado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Chtmleditctrlbase](../../mfc/reference/chtmleditctrlbase-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CHtmlEditCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxhtml.h

## <a name="chtmleditctrlchtmleditctrl"></a><a name="chtmleditctrl"></a>CHtmlEditCtrl::CHtmlEditCtrl

Constrói um objeto `CHtmlEditCtrl`.

```
CHtmlEditCtrl();
```

## <a name="chtmleditctrlcreate"></a><a name="create"></a>CHtmlEditCtrl::Criar

Cria um controle ActiveX do WebBrowser `CHtmlEditCtrl` e o anexa ao objeto. O controle WebBrowser ActiveX navega automaticamente para um documento padrão e, em seguida, é colocado no modo de edição por esta função.

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

*lpszWindowName*<br/>
Esse parâmetro não está em uso.

*Dwstyle*<br/>
Esse parâmetro não está em uso.

*Rect*<br/>
Especifica o tamanho e a posição do controle.

*Pparentwnd*<br/>
Especifica a janela pai do controle. Não deve ser NULO.

*nID*<br/>
Especifica a id do controle.

*pContext*<br/>
Esse parâmetro não está em uso.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="chtmleditctrlgetdhtmldocument"></a><a name="getdhtmldocument"></a>ChtmlEditCtrl::GetDHtmlDocument

Recupera a interface [IHTMLDocument2](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752574\(v=vs.85\)) no documento atualmente carregado no controle do WebBrowser contido

```
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;
```

### <a name="parameters"></a>Parâmetros

*ppDocument*<br/>
A interface do documento.

## <a name="chtmleditctrlgetstartdocument"></a><a name="getstartdocument"></a>ChtmlEditCtrl::GetStartDocument

Recupera a URL em um documento padrão para carregar no controle do WebBrowser contido.

```
virtual LPCTSTR GetStartDocument();
```

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
