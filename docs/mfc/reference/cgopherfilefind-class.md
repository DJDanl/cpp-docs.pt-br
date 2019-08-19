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
ms.openlocfilehash: 55c40fc04934f00ccb541a01cce611d9532bee1a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506183"
---
# <a name="cgopherfilefind-class"></a>Classe CGopherFileFind

Ajuda em pesquisas de arquivos da Internet de servidores Gopher.

> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind` eseusmembrosforampreteridasporquenãofuncionamnaplataformaWindowsXP,mascontinuarãofuncionando`CGopherLocator` em plataformas anteriores.

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
|[CGopherFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|
|[CGopherFileFind::GetCreationTime](#getcreationtime)|Obtém a hora em que o arquivo especificado foi criado.|
|[CGopherFileFind::GetLastAccessTime](#getlastaccesstime)|Obtém a hora em que o arquivo especificado foi acessado pela última vez.|
|[CGopherFileFind::GetLastWriteTime](#getlastwritetime)|Obtém a hora em que o arquivo especificado foi gravado pela última vez.|
|[CGopherFileFind::GetLength](#getlength)|Obtém o comprimento do arquivo encontrado, em bytes.|
|[CGopherFileFind::GetLocator](#getlocator)|Obter um `CGopherLocator` objeto.|
|[CGopherFileFind::GetScreenName](#getscreenname)|Obtém o nome de uma tela do Gopher.|
|[CGopherFileFind::IsDots](#isdots)|Testes para o diretório atual e marcadores de diretório pai durante a iteração por meio de arquivos.|

## <a name="remarks"></a>Comentários

`CGopherFileFind`inclui funções de membro que iniciam uma pesquisa, localizam um arquivo e retornam a URL de um arquivo.

Outras classes do MFC projetadas para a Internet e o arquivo local pesquisados incluem [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Juntamente com `CGopherFileFind`o, essas classes fornecem um mecanismo contínuo para o usuário encontrar arquivos específicos, independentemente do protocolo de servidor, tipo de arquivo ou local (um computador local ou um servidor remoto). Observe que não há nenhuma classe MFC para pesquisar em servidores HTTP porque o HTTP não oferece suporte à manipulação direta de arquivo exigida pelas pesquisas.

> [!NOTE]
> `CGopherFileFind`o não oferece suporte às seguintes funções de membro de sua classe base [CFileFind](../../mfc/reference/cfilefind-class.md):

- [GetRoot](../../mfc/reference/cfilefind-class.md#getroot)

- [GetFileName](../../mfc/reference/cfilefind-class.md#getfilename)

- [GetFilePath](../../mfc/reference/cfilefind-class.md#getfilepath)

- [GetFileTitle](../../mfc/reference/cfilefind-class.md#getfiletitle)

- [GetFileURL](../../mfc/reference/cfilefind-class.md#getfileurl)

Além disso, quando usado com `CGopherFileFind`, a função de membro `CFileFind` [ispontilhados](../../mfc/reference/cfilefind-class.md#isdots) é sempre false.

Para obter mais informações sobre como usar `CGopherFileFind` o e outras classes do Wininet, consulte o artigo [programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFileFind](../../mfc/reference/cfilefind-class.md)

`CGopherFileFind`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="cgopherfilefind"></a>  CGopherFileFind::CGopherFileFind

Essa função de membro é chamada para construir `CGopherFileFind` um objeto.

```
explicit CGopherFileFind(
    CGopherConnection* pConnection,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pConnection*<br/>
Um ponteiro para um objeto [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) .

*dwContext*<br/>
O identificador de contexto para a operação. Consulte **comentários** para obter mais informações sobre *dwContext*.

### <a name="remarks"></a>Comentários

O valor padrão para *dwContext* é enviado pelo MFC para o `CGopherFileFind` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o `CGopherFileFind` objeto. Ao construir um `CGopherFileFind` objeto, você pode substituir o padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status no objeto com o qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="findfile"></a>  CGopherFileFind::FindFile

Chame essa função de membro para localizar um arquivo gopher.

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
Uma referência a um objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) .

*pstrString*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo.

*dwFlags*<br/>
Os sinalizadores que descrevem como tratar essa sessão. Os sinalizadores válidos são:

- INTERNET_FLAG_RELOAD obter os dados do servidor remoto, mesmo se ele estiver armazenado em cache localmente.

- O INTERNET_FLAG_DONT_CACHE não armazena em cache os dados, seja localmente ou em qualquer gateway.

- INTERNET_FLAG_SECURE solicitar transações seguras na transmissão com protocolo SSL ou PCT. Esse sinalizador é aplicável somente a solicitações HTTP.

- INTERNET_FLAG_USE_EXISTING se possível, reutilize as conexões existentes para o servidor para `FindFile` novas solicitações, em vez de criar uma nova sessão para cada solicitação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Para obter informações de erro estendidas, chame a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Depois de `FindFile` chamar para recuperar o primeiro objeto Gopher, você pode chamar [FindNextFile](#findnextfile) para recuperar arquivos Gopher subsequentes.

##  <a name="findnextfile"></a>  CGopherFileFind::FindNextFile

Chame essa função de membro para continuar uma pesquisa de arquivo iniciada com uma chamada para [CGopherFileFind:: FindFile](#findfile).

```
virtual BOOL FindNextFile();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se houver mais arquivos; zero se o arquivo encontrado for o último no diretório ou se ocorreu um erro. Para obter informações de erro estendidas, chame a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Se o arquivo encontrado for o último arquivo no diretório ou se nenhum arquivo correspondente puder ser encontrado, a `GetLastError` função retornará ERROR_NO_MORE_FILES.

##  <a name="getcreationtime"></a>  CGopherFileFind::GetCreationTime

Obtém a hora de criação para o arquivo atual.

```
virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;
virtual BOOL GetCreationTime(CTime& refTime) const;
```

### <a name="parameters"></a>Parâmetros

*pTimeStamp*<br/>
Um ponteiro para uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) que contém a hora em que o arquivo foi criado.

*refTime*<br/>
Uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) .

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; 0 se não for bem-sucedida. `GetCreationTime`retornará 0 somente se [FindNextFile](#findnextfile) nunca tiver sido chamado neste `CGopherFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetCreationTime`de chamar.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de data/hora retornado por essa função. Essa função pode retornar o mesmo valor retornado por outras funções de carimbo de data/hora se o sistema de arquivos ou servidor subjacente não oferecer suporte à manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre os formatos de hora. Em alguns sistemas operacionais, a hora retornada está no fuso horário local para o computador. o arquivo está localizado. Consulte a API do Win32 [FileTimeToLocalFileTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

##  <a name="getlastaccesstime"></a>  CGopherFileFind::GetLastAccessTime

Obtém a hora em que o arquivo especificado foi acessado pela última vez.

```
virtual BOOL GetLastAccessTime(CTime& refTime) const;
virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;
```

### <a name="parameters"></a>Parâmetros

*refTime*<br/>
Uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) .

*pTimeStamp*<br/>
Um ponteiro para uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) que contém a hora em que o arquivo foi acessado pela última vez.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; 0 se não for bem-sucedida. `GetLastAccessTime`retornará 0 somente se [FindNextFile](#findnextfile) nunca tiver sido chamado neste `CGopherFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetLastAccessTime`de chamar.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de data/hora retornado por essa função. Essa função pode retornar o mesmo valor retornado por outras funções de carimbo de data/hora se o sistema de arquivos ou servidor subjacente não oferecer suporte à manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre os formatos de hora. Em alguns sistemas operacionais, a hora retornada está no fuso horário local para o computador. o arquivo está localizado. Consulte a API do Win32 [FileTimeToLocalFileTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

##  <a name="getlastwritetime"></a>  CGopherFileFind::GetLastWriteTime

Obtém a última vez em que o arquivo foi alterado.

```
virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;
virtual BOOL GetLastWriteTime(CTime& refTime) const;
```

### <a name="parameters"></a>Parâmetros

*pTimeStamp*<br/>
Um ponteiro para uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) que contém a hora em que o arquivo foi gravado pela última vez.

*refTime*<br/>
Uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) .

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; 0 se não for bem-sucedida. `GetLastWriteTime`retornará 0 somente se [FindNextFile](#findnextfile) nunca tiver sido chamado neste `CGopherFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetLastWriteTime`de chamar.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de data/hora retornado por essa função. Essa função pode retornar o mesmo valor retornado por outras funções de carimbo de data/hora se o sistema de arquivos ou servidor subjacente não oferecer suporte à manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre os formatos de hora. Em alguns sistemas operacionais, a hora retornada está no fuso horário local para o computador. o arquivo está localizado. Consulte a API do Win32 [FileTimeToLocalFileTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

##  <a name="getlength"></a>  CGopherFileFind::GetLength

Chame essa função de membro para obter o comprimento, em bytes, do arquivo encontrado.

```
virtual ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento, em bytes, do arquivo encontrado.

### <a name="remarks"></a>Comentários

`GetLength`usa o [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) de estrutura do Win32 para obter o valor do tamanho do arquivo em bytes.

> [!NOTE]
>  A partir do MFC 7,0 `GetLength` , dá suporte a tipos inteiros de 64 bits. O código existente anteriormente criado com essa versão mais recente da biblioteca pode resultar em avisos de truncamento.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [testcfile:: GetLength](../../mfc/reference/cfile-class.md#getlength) (a implementação da classe base).

##  <a name="getlocator"></a>  CGopherFileFind::GetLocator

Chame essa função de membro para obter o objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) que o [FindFile](#findfile) usa para localizar o arquivo gopher.

```
CGopherLocator GetLocator() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto `CGopherLocator`.

##  <a name="getscreenname"></a>  CGopherFileFind::GetScreenName

Chame essa função de membro para obter o nome da tela do Gopher.

```
CString GetScreenName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome da tela do Gopher.

##  <a name="isdots"></a>  CGopherFileFind::IsDots

Testes para o diretório atual e marcadores de diretório pai durante a iteração por meio de arquivos.

```
virtual BOOL IsDots() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo encontrado tiver o nome "." ou "..", que indica que o arquivo encontrado é, na verdade, um diretório. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsDots`de chamar.

## <a name="see-also"></a>Consulte também

[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpFileFind](../../mfc/reference/cftpfilefind-class.md)<br/>
[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
