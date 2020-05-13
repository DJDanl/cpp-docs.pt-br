---
title: Classe CGopherFileFind
ms.date: 11/04/2016
f1_keywords:
- CGopherFileFind
- AFXINET/CGopherFileFind
- AFXINET/CGopherFileFind::CGopherFileFind
- AFXINET/CGopherFileFind::FindFile
- AFXINET/CGopherFileFind::FindNextFile
- AFXINET/CGopherFileFind::GetCreationTime
- AFXINET/CGopherFileFind::GetLastAccessTime
- AFXINET/CGopherFileFind::GetLastWriteTime
- AFXINET/CGopherFileFind::GetLength
- AFXINET/CGopherFileFind::GetLocator
- AFXINET/CGopherFileFind::GetScreenName
- AFXINET/CGopherFileFind::IsDots
helpviewer_keywords:
- CGopherFileFind [MFC], CGopherFileFind
- CGopherFileFind [MFC], FindFile
- CGopherFileFind [MFC], FindNextFile
- CGopherFileFind [MFC], GetCreationTime
- CGopherFileFind [MFC], GetLastAccessTime
- CGopherFileFind [MFC], GetLastWriteTime
- CGopherFileFind [MFC], GetLength
- CGopherFileFind [MFC], GetLocator
- CGopherFileFind [MFC], GetScreenName
- CGopherFileFind [MFC], IsDots
ms.assetid: 8465a979-6323-496d-ab4b-e81383fb999d
ms.openlocfilehash: 7a42b99c919abd9098bff1897c4c5febf443314d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373688"
---
# <a name="cgopherfilefind-class"></a>Classe CGopherFileFind

Auxilia nas pesquisas de arquivos da Internet de servidores gopher.

> [!NOTE]
> As `CGopherConnection`classes `CGopherFile` `CGopherFileFind`e `CGopherLocator` seus membros foram preteridos porque não trabalham na plataforma Windows XP, mas continuarão a trabalhar em plataformas anteriores.

## <a name="syntax"></a>Sintaxe

```
class CGopherFileFind : public CFileFind
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherFileFind::CGopherFileFind](#cgopherfilefind)|Constrói um objeto `CGopherFileFind`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherFileFind::FindFile](#findfile)|Encontra um arquivo em um servidor gopher.|
|[CGopherFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|
|[CGopherFileFind::GetCreationTime](#getcreationtime)|Obtém a hora em que o arquivo especificado foi criado.|
|[CGopherFileFind::GetLastAccessTime](#getlastaccesstime)|Obtém a hora em que o arquivo especificado foi acessado pela última vez.|
|[CGopherFileFind::GetLastWriteTime](#getlastwritetime)|Fica a hora em que o arquivo especificado foi escrito pela última vez.|
|[CGopherFileFind::GetLength](#getlength)|Obtém o comprimento do arquivo encontrado, em bytes.|
|[CGopherFileFind::GetLocator](#getlocator)|Pegue `CGopherLocator` um objeto.|
|[CGopherFileFind::GetScreenName](#getscreenname)|Recebe o nome de uma tela de gopher.|
|[CGopherFileFind::IsDots](#isdots)|Testes para os marcadores de diretório e diretório pai atuais enquanto itera através de arquivos.|

## <a name="remarks"></a>Comentários

`CGopherFileFind`inclui funções de membro que iniciam uma pesquisa, localizam um arquivo e retornam a URL de um arquivo.

Outras classes de MFC projetadas para internet e arquivos locais pesquisados incluem [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Juntamente `CGopherFileFind`com, essas classes fornecem um mecanismo perfeito para que o usuário encontre arquivos específicos, independentemente do protocolo do servidor, tipo de arquivo ou localização (seja uma máquina local ou um servidor remoto).) Observe que não há classe MFC para pesquisa em servidores HTTP porque http não suporta a manipulação direta de arquivos exigida pelas pesquisas.

> [!NOTE]
> `CGopherFileFind`não suporta as seguintes funções de membro de sua classe base [CFileFind:](../../mfc/reference/cfilefind-class.md)

- [GetRoot](../../mfc/reference/cfilefind-class.md#getroot)

- [GetFileName](../../mfc/reference/cfilefind-class.md#getfilename)

- [Getfilepath](../../mfc/reference/cfilefind-class.md#getfilepath)

- [Getfiletitle](../../mfc/reference/cfilefind-class.md#getfiletitle)

- [Getfileurl](../../mfc/reference/cfilefind-class.md#getfileurl)

Além disso, quando `CGopherFileFind`usado `CFileFind` com , a função de membro [IsDots](../../mfc/reference/cfilefind-class.md#isdots) é sempre FALSA.

Para obter mais informações `CGopherFileFind` sobre como usar e as outras classes wininet, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfilefind](../../mfc/reference/cfilefind-class.md)

`CGopherFileFind`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cgopherfilefindcgopherfilefind"></a><a name="cgopherfilefind"></a>CGopherFileFind::CGopherFileFind

Esta função membro é `CGopherFileFind` chamada para construir um objeto.

```
explicit CGopherFileFind(
    CGopherConnection* pConnection,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pConnection*<br/>
Um ponteiro para um objeto [CGopherConnection.](../../mfc/reference/cgopherconnection-class.md)

*Dwcontext*<br/>
O identificador de contexto para a operação. Consulte **Observações** para obter mais informações sobre *o dwContext*.

### <a name="remarks"></a>Comentários

O valor padrão para *dwContext* é `CGopherFileFind` enviado pelo MFC para o `CGopherFileFind` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o objeto. Quando você `CGopherFileFind` constrói um objeto, você pode substituir o padrão para definir o identificador de contexto a um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com o qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="cgopherfilefindfindfile"></a><a name="findfile"></a>CGopherFileFind::FindFile

Ligue para esta função de membro para encontrar um arquivo gopher.

```
virtual BOOL FindFile(
    CGopherLocator& refLocator,
    LPCTSTR pstrString,
    DWORD dwFlags = INTERNET_FLAG_RELOAD);

virtual BOOL FindFile(
    LPCTSTR pstrString,
    DWORD dwFlags = INTERNET_FLAG_RELOAD);
```

### <a name="parameters"></a>Parâmetros

*árbitro*<br/>
Uma referência a um objeto [CGopherLocator.](../../mfc/reference/cgopherlocator-class.md)

*pstrString*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo.

*dwFlags*<br/>
As bandeiras descrevendo como lidar com esta sessão. As bandeiras válidas são:

- INTERNET_FLAG_RELOAD obter os dados do servidor remoto, mesmo que sejam armazenados em cache local.

- INTERNET_FLAG_DONT_CACHE Não faça cache de dados, localmente ou em gateways.

- INTERNET_FLAG_SECURE Solicite transações seguras no fio com a Secure Sockets Layer ou PCT. Este sinalizador é aplicável apenas às solicitações HTTP.

- INTERNET_FLAG_USE_EXISTING Se possível, reutilize as conexões existentes `FindFile` ao servidor para novas solicitações, em vez de criar uma nova sessão para cada solicitação.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Para obter informações de erro estendidas, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Depois `FindFile` de ligar para recuperar o primeiro objeto gopher, você pode chamar [FindNextFile](#findnextfile) para recuperar arquivos gopher subseqüentes.

## <a name="cgopherfilefindfindnextfile"></a><a name="findnextfile"></a>CGopherFileFind::FindNextFile

Chame esta função de membro para continuar uma pesquisa de arquivo iniciada com uma chamada para [CGopherFileFind::FindFile](#findfile).

```
virtual BOOL FindNextFile();
```

### <a name="return-value"></a>Valor retornado

Não zero se houver mais arquivos; zero se o arquivo encontrado for o último no diretório ou se ocorreu um erro. Para obter informações de erro estendidas, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Se o arquivo encontrado for o último arquivo no diretório, ou `GetLastError` se nenhum arquivo correspondente for encontrado, a função retorna ERROR_NO_MORE_FILES.

## <a name="cgopherfilefindgetcreationtime"></a><a name="getcreationtime"></a>CGopherFileFind::GetCreationTime

Obtém o tempo de criação do arquivo atual.

```
virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;
virtual BOOL GetCreationTime(CTime& refTime) const;
```

### <a name="parameters"></a>Parâmetros

*pTimeStamp*<br/>
Um ponteiro para uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) contendo a hora em que o arquivo foi criado.

*refTime*<br/>
Uma referência a um objeto [CTime.](../../atl-mfc-shared/reference/ctime-class.md)

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; 0 se não tiver sucesso. `GetCreationTime`retorna 0 somente se [FindNextFile](#findnextfile) nunca `CGopherFileFind` foi chamado neste objeto.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetCreationTime`.

> [!NOTE]
> Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por esta função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de tempo se o sistema de arquivos ou servidor subjacente não suportar a manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre formatos de tempo. Em alguns sistemas operacionais, o tempo retornado é no fuso horário local para a máquina onde o arquivo está localizado. Consulte a API Do [Arquivo Win32TimeToLocalLocalTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

## <a name="cgopherfilefindgetlastaccesstime"></a><a name="getlastaccesstime"></a>CGopherFileFind::GetLastAccessTime

Obtém a hora em que o arquivo especificado foi acessado pela última vez.

```
virtual BOOL GetLastAccessTime(CTime& refTime) const;
virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;
```

### <a name="parameters"></a>Parâmetros

*refTime*<br/>
Uma referência a um objeto [CTime.](../../atl-mfc-shared/reference/ctime-class.md)

*pTimeStamp*<br/>
Um ponteiro para uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) contendo a hora em que o arquivo foi acessado pela última vez.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; 0 se não tiver sucesso. `GetLastAccessTime`retorna 0 somente se [FindNextFile](#findnextfile) nunca `CGopherFileFind` foi chamado neste objeto.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetLastAccessTime`.

> [!NOTE]
> Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por esta função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de tempo se o sistema de arquivos ou servidor subjacente não suportar a manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre formatos de tempo. Em alguns sistemas operacionais, o tempo retornado é no fuso horário local para a máquina onde o arquivo está localizado. Consulte a API Do [Arquivo Win32TimeToLocalLocalTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

## <a name="cgopherfilefindgetlastwritetime"></a><a name="getlastwritetime"></a>CGopherFileFind::GetLastWriteTime

Fica da última vez que o arquivo foi alterado.

```
virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;
virtual BOOL GetLastWriteTime(CTime& refTime) const;
```

### <a name="parameters"></a>Parâmetros

*pTimeStamp*<br/>
Um ponteiro para uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) contendo a hora em que o arquivo foi gravado pela última vez.

*refTime*<br/>
Uma referência a um objeto [CTime.](../../atl-mfc-shared/reference/ctime-class.md)

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; 0 se não tiver sucesso. `GetLastWriteTime`retorna 0 somente se [FindNextFile](#findnextfile) nunca `CGopherFileFind` foi chamado neste objeto.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetLastWriteTime`.

> [!NOTE]
> Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por esta função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de tempo se o sistema de arquivos ou servidor subjacente não suportar a manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre formatos de tempo. Em alguns sistemas operacionais, o tempo retornado é no fuso horário local para a máquina onde o arquivo está localizado. Consulte a API Do [Arquivo Win32TimeToLocalLocalTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

## <a name="cgopherfilefindgetlength"></a><a name="getlength"></a>CGopherFileFind::GetLength

Chame esta função de membro para obter o comprimento, em bytes, do arquivo encontrado.

```
virtual ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento, em bytes, do arquivo encontrado.

### <a name="remarks"></a>Comentários

`GetLength`usa a estrutura Win32 [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter o valor do tamanho do arquivo em bytes.

> [!NOTE]
> A partir do MFC `GetLength` 7.0, suporta tipos inteiros de 64 bits. O código anteriormente existente construído com esta versão mais recente da biblioteca pode resultar em avisos de truncamento.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFile::GetLength](../../mfc/reference/cfile-class.md#getlength) (a implementação da classe base).

## <a name="cgopherfilefindgetlocator"></a><a name="getlocator"></a>CGopherFileFind::GetLocator

Chame esta função de membro para obter o objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) que [findFile](#findfile) usa para encontrar o arquivo gopher.

```
CGopherLocator GetLocator() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto `CGopherLocator` .

## <a name="cgopherfilefindgetscreenname"></a><a name="getscreenname"></a>CGopherFileFind::GetScreenName

Chame esta função de membro para obter o nome da tela gopher.

```
CString GetScreenName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da tela gopher.

## <a name="cgopherfilefindisdots"></a><a name="isdots"></a>CGopherFileFind::IsDots

Testes para os marcadores de diretório e diretório pai atuais enquanto itera através de arquivos.

```
virtual BOOL IsDots() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o arquivo encontrado tiver o nome "." ou "..", o que indica que o arquivo encontrado é na verdade um diretório. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsDots`.

## <a name="see-also"></a>Confira também

[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpFileFind](../../mfc/reference/cftpfilefind-class.md)<br/>
[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
