---
title: Classe CHtmlEditDoc
ms.date: 11/04/2016
f1_keywords:
- CHtmlEditDoc
- AFXHTML/CHtmlEditDoc
- AFXHTML/CHtmlEditDoc::CHtmlEditDoc
- AFXHTML/CHtmlEditDoc::GetView
- AFXHTML/CHtmlEditDoc::IsModified
- AFXHTML/CHtmlEditDoc::OpenURL
helpviewer_keywords:
- CHtmlEditDoc [MFC], CHtmlEditDoc
- CHtmlEditDoc [MFC], GetView
- CHtmlEditDoc [MFC], IsModified
- CHtmlEditDoc [MFC], OpenURL
ms.assetid: b2cca61f-e5d6-4099-b0d1-46bf85f0bd64
ms.openlocfilehash: 8b500f651da1a73040fdb0469f2f023babe25e85
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352169"
---
# <a name="chtmleditdoc-class"></a>Classe CHtmlEditDoc

Com [CHtmlEditView,](../../mfc/reference/chtmleditview-class.md)fornece a funcionalidade da plataforma de edição do WebBrowser dentro do contexto da arquitetura de exibição de documentos Do MFC.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CHtmlEditDoc : public CDocument
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHtmlEditDoc::CHtmlEditDoc](#chtmleditdoc)|Constrói um objeto `CHtmlEditDoc`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHtmlEditDoc::GetView](#getview)|Recupera o `CHtmlEditView` objeto anexado a este documento.|
|[ChtmlEditDoc::IsModified](#ismodified)|Retorna se o controle webBrowser da exibição associada contém um documento que foi modificado pelo usuário.|
|[CHtmlEditDoc::OpenURL](#openurl)|Abre uma URL.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocument](../../mfc/reference/cdocument-class.md)

`CHtmlEditDoc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxhtml.h

## <a name="chtmleditdocchtmleditdoc"></a><a name="chtmleditdoc"></a>CHtmlEditDoc::CHtmlEditDoc

Constrói um objeto `CHtmlEditDoc`.

```
CHtmlEditDoc();
```

## <a name="chtmleditdocgetview"></a><a name="getview"></a>CHtmlEditDoc::GetView

Recupera o objeto [CHtmlEditView](../../mfc/reference/chtmleditview-class.md) anexado a este documento.

```
virtual CHtmlEditView* GetView() const;
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para `CHtmlEditView` o objeto do documento.

## <a name="chtmleditdocismodified"></a><a name="ismodified"></a>ChtmlEditDoc::IsModified

Retorna se o controle webBrowser da exibição associada contém um documento que foi modificado pelo usuário.

```
virtual BOOL IsModified();
```

## <a name="chtmleditdocopenurl"></a><a name="openurl"></a>CHtmlEditDoc::OpenURL

Abre uma URL.

```
virtual BOOL OpenURL(LPCTSTR lpszURL);
```

### <a name="parameters"></a>Parâmetros

*Lpszurl*<br/>
A URL para abrir.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="see-also"></a>Confira também

[Amostra de HTMLEdit](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
