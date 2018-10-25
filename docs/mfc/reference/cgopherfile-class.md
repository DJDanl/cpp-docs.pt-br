---
title: Classe CGopherFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CGopherFile
- AFXINET/CGopherFile
- AFXINET/CGopherFile::CGopherFile
dev_langs:
- C++
helpviewer_keywords:
- CGopherFile [MFC], CGopherFile
ms.assetid: 3ca9898f-8cdb-4495-bbde-46d40100feda
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 083ed824ce8586295e398d32ed14e17f8d334358
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50080943"
---
# <a name="cgopherfile-class"></a>Classe CGopherFile

Fornece a funcionalidade para localizar e ler arquivos em um servidor gopher.

> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros foram preteridos porque eles não funcionam na plataforma Windows XP, mas eles continuarão a funcionar em plataformas anteriores.

## <a name="syntax"></a>Sintaxe

```
class CGopherFile : public CInternetFile
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CGopherFile::CGopherFile](#cgopherfile)|Constrói um objeto `CGopherFile`.|

## <a name="remarks"></a>Comentários

O serviço gopher não permite aos usuários gravar dados em um arquivo de gopher, porque esse serviço funciona principalmente como uma interface orientados por menus para localizar informações. O `CGopherFile` funções de membro `Write`, `WriteString`, e `Flush` não são implementadas para `CGopherFile`. Chamar essas funções em um `CGopherFile` do objeto, retorna um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para saber mais sobre como `CGopherFile` funciona com as outras classes de Internet do MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[CStdioFile](../../mfc/reference/cstdiofile-class.md)

[CInternetFile](../../mfc/reference/cinternetfile-class.md)

`CGopherFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

##  <a name="cgopherfile"></a>  CGopherFile::CGopherFile

Essa função membro é chamada para construir um `CGopherFile` objeto.

```
CGopherFile(
    HINTERNET hFile,
    CGopherLocator& refLocator,
    CGopherConnection* pConnection);

CGopherFile(
    HINTERNET hFile,
    HINTERNET hSession,
    LPCTSTR pstrLocator,
    DWORD dwLocLen,
    DWORD_PTR dwContext);
```

### <a name="parameters"></a>Parâmetros

*hFile*<br/>
Um identificador para um arquivo HINTERNET.

*refLocator*<br/>
Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.

*pConnection*<br/>
Um ponteiro para um [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) objeto.

*hSession*<br/>
Um identificador para a sessão atual da Internet.

*pstrLocator*<br/>
Um ponteiro para uma cadeia de caracteres usada para localizar o servidor de gopher. Ver [sessões de Gopher](cgopherlocator-class.md) para obter mais informações sobre localizadores gopher.

*dwLocLen*<br/>
Um DWORD que contém o número de bytes em *pstrLocator*.

*dwContext*<br/>
Um ponteiro para o identificador de contexto do arquivo que está sendo aberto.

### <a name="remarks"></a>Comentários

É necessário um `CGopherFile` objeto para ler de um arquivo durante uma sessão de Internet de gopher.

Você nunca criará um `CGopherFile` diretamente do objeto. Em vez disso, chame [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) para abrir um arquivo em um servidor gopher.

## <a name="see-also"></a>Consulte também

[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherLocator](../../mfc/reference/cgopherlocator-class.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)<br/>
[Classe CGopherConnection](../../mfc/reference/cgopherconnection-class.md)
