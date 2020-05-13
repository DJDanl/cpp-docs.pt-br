---
title: Classe CGopherFile
ms.date: 11/04/2016
f1_keywords:
- CGopherFile
- AFXINET/CGopherFile
- AFXINET/CGopherFile::CGopherFile
helpviewer_keywords:
- CGopherFile [MFC], CGopherFile
ms.assetid: 3ca9898f-8cdb-4495-bbde-46d40100feda
ms.openlocfilehash: e157a4509fe30b814a1834690a675906ac82afe7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373702"
---
# <a name="cgopherfile-class"></a>Classe CGopherFile

Fornece a funcionalidade para encontrar e ler arquivos em um servidor gopher.

> [!NOTE]
> As `CGopherConnection`classes `CGopherFile` `CGopherFileFind`e `CGopherLocator` seus membros foram preteridos porque não trabalham na plataforma Windows XP, mas continuarão a trabalhar em plataformas anteriores.

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

O serviço gopher não permite que os usuários escrevam dados em um arquivo gopher porque este serviço funciona principalmente como uma interface orientada por menu para encontrar informações. As `CGopherFile` funções `Write` `WriteString`do `Flush` membro , `CGopherFile`e não são implementadas para . Chamar essas funções `CGopherFile` em um objeto, retorna uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para saber mais `CGopherFile` sobre como funciona as outras aulas de Internet do MFC, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Cstdiofile](../../mfc/reference/cstdiofile-class.md)

[Cinternetfile](../../mfc/reference/cinternetfile-class.md)

`CGopherFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cgopherfilecgopherfile"></a><a name="cgopherfile"></a>CGopherFile::CGopherFile

Esta função membro é `CGopherFile` chamada para construir um objeto.

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

*Hfile*<br/>
Uma alça para um arquivo HINTERNET.

*árbitro*<br/>
Uma referência a um objeto [CGopherLocator.](../../mfc/reference/cgopherlocator-class.md)

*pConnection*<br/>
Um ponteiro para um objeto [CGopherConnection.](../../mfc/reference/cgopherconnection-class.md)

*hSession*<br/>
Uma alça para a sessão atual da Internet.

*pstrLocator*<br/>
Um ponteiro para uma seqüência usada para localizar o servidor gopher. Consulte [o Gopher Sessions](cgopherlocator-class.md) para obter mais informações sobre localizadores de gopher.

*dwLocLen*<br/>
Um DWORD contendo o número de bytes no *pstrLocator*.

*Dwcontext*<br/>
Um ponteiro para o identificador de contexto do arquivo que está sendo aberto.

### <a name="remarks"></a>Comentários

Você precisa `CGopherFile` de um objeto para ler de um arquivo durante uma sessão de Internet gopher.

Você nunca `CGopherFile` cria um objeto diretamente. Em vez disso, ligue para [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) para abrir um arquivo em um servidor gopher.

## <a name="see-also"></a>Confira também

[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherLocator](../../mfc/reference/cgopherlocator-class.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)<br/>
[Classe CGopherConnection](../../mfc/reference/cgopherconnection-class.md)
