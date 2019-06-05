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
ms.openlocfilehash: bced5a95f65713915a1f06094bfe059db79aab2d
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66503637"
---
# <a name="cgopherfilefind-class"></a>Classe CGopherFileFind

Auxílios em pesquisas de arquivos de Internet de servidores gopher.

> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros foram preteridos porque eles não funcionam na plataforma Windows XP, mas eles continuarão a funcionar em plataformas anteriores.

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
|[CGopherFileFind::FindFile](#findfile)|Localiza um arquivo em um servidor gopher.|
|[CGopherFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior a [FindFile](#findfile).|
|[CGopherFileFind::GetCreationTime](#getcreationtime)|Obtém a hora em que o arquivo especificado foi criado.|
|[CGopherFileFind::GetLastAccessTime](#getlastaccesstime)|Obtém a hora em que o arquivo especificado foi acessado pela última vez.|
|[CGopherFileFind::GetLastWriteTime](#getlastwritetime)|Obtém a hora em que o arquivo especificado foi gravado pela última vez.|
|[CGopherFileFind::GetLength](#getlength)|Obtém o tamanho do arquivo encontrado, em bytes.|
|[CGopherFileFind::GetLocator](#getlocator)|Obtenha um `CGopherLocator` objeto.|
|[CGopherFileFind::GetScreenName](#getscreenname)|Obtém o nome de uma tela de gopher.|
|[CGopherFileFind::IsDots](#isdots)|Testes para os marcadores de Active directory e o pai atuais durante a iteração por meio de arquivos.|

## <a name="remarks"></a>Comentários

`CGopherFileFind` inclui funções de membro que iniciar uma pesquisa, localize um arquivo e URL de um arquivo de retorno.

Outras classes do MFC projetados para a Internet e o arquivo local pesquisadas incluem [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Junto com `CGopherFileFind`, essas classes fornecem um mecanismo perfeito para o usuário encontre arquivos específicos, independentemente do protocolo de servidor, tipo de arquivo ou local (um computador local ou um servidor remoto.) Observe que não há nenhuma classe do MFC para pesquisa em servidores HTTP, como HTTP não dá suporte a manipulação direta do arquivo exigida pelas pesquisas.

> [!NOTE]
> `CGopherFileFind` não suporta as seguintes funções de membro de sua classe base [CFileFind](../../mfc/reference/cfilefind-class.md):

- [GetRoot](../../mfc/reference/cfilefind-class.md#getroot)

- [GetFileName](../../mfc/reference/cfilefind-class.md#getfilename)

- [GetFilePath](../../mfc/reference/cfilefind-class.md#getfilepath)

- [GetFileTitle](../../mfc/reference/cfilefind-class.md#getfiletitle)

- [GetFileURL](../../mfc/reference/cfilefind-class.md#getfileurl)

Além disso, quando usado com `CGopherFileFind`, o `CFileFind` função de membro [IsDots](../../mfc/reference/cfilefind-class.md#isdots) é sempre FALSE.

Para obter mais informações sobre como usar `CGopherFileFind` e as outras classes WinInet, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFileFind](../../mfc/reference/cfilefind-class.md)

`CGopherFileFind`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

##  <a name="cgopherfilefind"></a>  CGopherFileFind::CGopherFileFind

Essa função membro é chamada para construir um `CGopherFileFind` objeto.

```
explicit CGopherFileFind(
    CGopherConnection* pConnection,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pConnection*<br/>
Um ponteiro para um [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) objeto.

*dwContext*<br/>
O identificador de contexto para a operação. Ver **Remarks** para obter mais informações sobre *dwContext*.

### <a name="remarks"></a>Comentários

O valor padrão para *dwContext* é enviado pelo MFC para o `CGopherFileFind` objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CGopherFileFind` objeto. Quando você constrói um `CGopherFileFind` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: O WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="findfile"></a>  CGopherFileFind::FindFile

Chame essa função de membro para localizar um arquivo de gopher.

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

*refLocator*<br/>
Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.

*pstrString*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo.

*dwFlags*<br/>
Os sinalizadores que descrevem como lidar com esta sessão. Os sinalizadores válidos são:

- INTERNET_FLAG_RELOAD obter os dados do servidor remoto, mesmo se ela é armazenada em cache localmente.

- INTERNET_FLAG_DONT_CACHE não armazenar em cache os dados, localmente ou em todos os gateways.

- Solicitar INTERNET_FLAG_SECURE transações seguras durante a transmissão com Secure Sockets Layer ou PERC Esse sinalizador é aplicável somente a solicitações HTTP.

- INTERNET_FLAG_USE_EXISTING se possível, reutilize as conexões existentes para o servidor para o novo `FindFile` solicitações, em vez de criar uma nova sessão para cada solicitação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Para obter outras informações de erro, chame a função Win32 [GetLastError](/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Depois de chamar `FindFile` para recuperar o primeiro objeto gopher, você pode chamar [FindNextFile](#findnextfile) para recuperar os arquivos subsequentes gopher.

##  <a name="findnextfile"></a>  CGopherFileFind::FindNextFile

Chame essa função de membro para continuar uma pesquisa de arquivo iniciada com uma chamada para [CGopherFileFind::FindFile](#findfile).

```
virtual BOOL FindNextFile();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se não houver mais arquivos; zero se o arquivo encontrado é o último no diretório ou se ocorreu um erro. Para obter outras informações de erro, chame a função Win32 [GetLastError](/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Se o arquivo encontrado é o último arquivo no diretório, ou se nenhuma correspondência de arquivos podem ser encontrados, o `GetLastError` função retorna ERROR_NO_MORE_FILES.

##  <a name="getcreationtime"></a>  CGopherFileFind::GetCreationTime

Obtém a hora de criação para o arquivo atual.

```
virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;
virtual BOOL GetCreationTime(CTime& refTime) const;
```

### <a name="parameters"></a>Parâmetros

*pTimeStamp*<br/>
Um ponteiro para um [FILETIME](/windows/desktop/api/minwinbase/ns-minwinbase-filetime) estrutura que contém a hora em que o arquivo foi criado.

*refTime*<br/>
Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; 0 se não for bem-sucedido. `GetCreationTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CGopherFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetCreationTime`.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não oferece suporte a manter o atributo de tempo. Consulte a [Win32_FIND_DATA](/windows/desktop/api/minwinbase/ns-minwinbase-_win32_find_dataa) estrutura para obter informações sobre formatos de hora. Em alguns sistemas operacionais, a hora retornada está no tempo de zona local para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime) API para obter mais informações.

##  <a name="getlastaccesstime"></a>  CGopherFileFind::GetLastAccessTime

Obtém a hora em que o arquivo especificado foi acessado pela última vez.

```
virtual BOOL GetLastAccessTime(CTime& refTime) const;
virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;
```

### <a name="parameters"></a>Parâmetros

*refTime*<br/>
Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.

*pTimeStamp*<br/>
Um ponteiro para um [FILETIME](/windows/desktop/api/minwinbase/ns-minwinbase-filetime) estrutura que contém a hora em que o arquivo foi acessado pela última vez.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; 0 se não for bem-sucedido. `GetLastAccessTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CGopherFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetLastAccessTime`.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não oferece suporte a manter o atributo de tempo. Consulte a [Win32_FIND_DATA](/windows/desktop/api/minwinbase/ns-minwinbase-_win32_find_dataa) estrutura para obter informações sobre formatos de hora. Em alguns sistemas operacionais, a hora retornada está no tempo de zona local para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime) API para obter mais informações.

##  <a name="getlastwritetime"></a>  CGopherFileFind::GetLastWriteTime

Obtém a última vez em que o arquivo foi alterado.

```
virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;
virtual BOOL GetLastWriteTime(CTime& refTime) const;
```

### <a name="parameters"></a>Parâmetros

*pTimeStamp*<br/>
Um ponteiro para um [FILETIME](/windows/desktop/api/minwinbase/ns-minwinbase-filetime) estrutura que contém a hora em que o arquivo foi gravado pela última vez.

*refTime*<br/>
Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; 0 se não for bem-sucedido. `GetLastWriteTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CGopherFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetLastWriteTime`.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não oferece suporte a manter o atributo de tempo. Consulte a [Win32_FIND_DATA](/windows/desktop/api/minwinbase/ns-minwinbase-_win32_find_dataa) estrutura para obter informações sobre formatos de hora. Em alguns sistemas operacionais, a hora retornada está no tempo de zona local para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime) API para obter mais informações.

##  <a name="getlength"></a>  CGopherFileFind::GetLength

Chame essa função de membro para obter o comprimento, em bytes, do arquivo encontrado.

```
virtual ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento, em bytes, do arquivo encontrado.

### <a name="remarks"></a>Comentários

`GetLength` usa a estrutura do Win32 [WIN32_FIND_DATA](/windows/desktop/api/minwinbase/ns-minwinbase-_win32_find_dataa) para obter o valor do tamanho do arquivo em bytes.

> [!NOTE]
>  A partir do MFC 7.0 `GetLength` dá suporte a tipos de inteiro de 64 bits. Código previamente existentes criado com essa versão mais recente da biblioteca pode resultar em avisos de truncamento.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFile::GetLength](../../mfc/reference/cfile-class.md#getlength) (a implementação de classe base).

##  <a name="getlocator"></a>  CGopherFileFind::GetLocator

Chame essa função de membro para obter o [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) do objeto [FindFile](#findfile) usa para localizar o arquivo de gopher.

```
CGopherLocator GetLocator() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto `CGopherLocator`.

##  <a name="getscreenname"></a>  CGopherFileFind::GetScreenName

Chame essa função de membro para obter o nome da tela gopher.

```
CString GetScreenName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome da tela gopher.

##  <a name="isdots"></a>  CGopherFileFind::IsDots

Testes para os marcadores de Active directory e o pai atuais durante a iteração por meio de arquivos.

```
virtual BOOL IsDots() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo localizado tem o nome "."ou"..", que indica que o arquivo encontrado é, na verdade, um diretório. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsDots`.

## <a name="see-also"></a>Consulte também

[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpFileFind](../../mfc/reference/cftpfilefind-class.md)<br/>
[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
