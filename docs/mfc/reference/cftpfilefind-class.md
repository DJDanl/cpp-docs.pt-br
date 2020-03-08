---
title: Classe CFtpFileFind
ms.date: 11/04/2016
f1_keywords:
- CFtpFileFind
- AFXINET/CFtpFileFind
- AFXINET/CFtpFileFind::CFtpFileFind
- AFXINET/CFtpFileFind::FindFile
- AFXINET/CFtpFileFind::FindNextFile
- AFXINET/CFtpFileFind::GetFileURL
helpviewer_keywords:
- CFtpFileFind [MFC], CFtpFileFind
- CFtpFileFind [MFC], FindFile
- CFtpFileFind [MFC], FindNextFile
- CFtpFileFind [MFC], GetFileURL
ms.assetid: 9667cf01-657f-4b11-b9db-f11e5a7b4e4c
ms.openlocfilehash: 2f4a394e29be135cac95edf6f504d8b066f53414
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866292"
---
# <a name="cftpfilefind-class"></a>Classe CFtpFileFind

Ajuda em pesquisas de arquivos da Internet de servidores FTP.

## <a name="syntax"></a>Sintaxe

```
class CFtpFileFind : public CFileFind
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CFtpFileFind::CFtpFileFind](#cftpfilefind)|Constrói um objeto `CFtpFileFind`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CFtpFileFind:: FindFile](#findfile)|Localiza um arquivo em um servidor FTP.|
|[CFtpFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|
|[CFtpFileFind::GetFileURL](#getfileurl)|Obtém a URL, incluindo o caminho, do arquivo encontrado.|

## <a name="remarks"></a>Comentários

`CFtpFileFind` inclui funções de membro que iniciam uma pesquisa, localizam um arquivo e retornam a URL ou outras informações descritivas sobre o arquivo.

Outras classes do MFC projetadas para a Internet e o arquivo local pesquisados incluem [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Junto com `CFtpFileFind`, essas classes fornecem um mecanismo contínuo para o cliente localizar arquivos específicos, independentemente do protocolo de servidor ou tipo de arquivo (um computador local ou um servidor remoto). Observe que não há nenhuma classe MFC para pesquisar em servidores HTTP porque o HTTP não oferece suporte à manipulação direta de arquivo necessária para pesquisas.

Para obter mais informações sobre como usar `CFtpFileFind` e outras classes WinInet, consulte o artigo [programação de Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O código a seguir demonstra como enumerar todos os arquivos no diretório atual do servidor FTP.

[!code-cpp[NVC_MFCWinInet#8](../../mfc/codesnippet/cpp/cftpfilefind-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFileFind](../../mfc/reference/cfilefind-class.md)

`CFtpFileFind`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXINET. h

##  <a name="cftpfilefind"></a>CFtpFileFind::CFtpFileFind

Essa função de membro é chamada para construir um objeto de `CFtpFileFind`.

```
explicit CFtpFileFind(
    CFtpConnection* pConnection,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pConnection*<br/>
Um ponteiro para um objeto `CFtpConnection`. Você pode obter uma conexão FTP chamando [CInternetSession:: GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection).

*dwContext*<br/>
O identificador de contexto para o objeto `CFtpFileFind`. Consulte **comentários** para obter mais informações sobre esse parâmetro.

### <a name="remarks"></a>Comentários

O valor padrão de *dwContext* é enviado pelo MFC para o objeto `CFtpFileFind` do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o objeto `CFtpFileFind`. Você pode substituir o padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status no objeto com o qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo na classe visão geral neste tópico.

##  <a name="findfile"></a>CFtpFileFind:: FindFile

Chame essa função de membro para localizar um arquivo FTP.

```
virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,
    DWORD dwFlags = INTERNET_FLAG_RELOAD);
```

### <a name="parameters"></a>Parâmetros

*pstrName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser localizado. Se for NULL, a chamada executará uma pesquisa curinga (*).

*dwFlags*<br/>
Os sinalizadores que descrevem como tratar essa sessão. Esses sinalizadores podem ser combinados com o operador OR ()&#124;e bit () e são os seguintes:

- INTERNET_FLAG_RELOAD obter os dados da transmissão, mesmo se ele estiver armazenado em cache localmente. Esse é o sinalizador padrão.

- INTERNET_FLAG_DONT_CACHE Não armazene em cache os dados, seja localmente ou em qualquer gateway.

- INTERNET_FLAG_RAW_DATA substituir o padrão para retornar os dados brutos (estruturas de [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para FTP).

- INTERNET_FLAG_SECURE protege as transações na transmissão com protocolo SSL ou PCT. Esse sinalizador é aplicável somente a solicitações HTTP.

- INTERNET_FLAG_EXISTING_CONNECT se possível, reutilize as conexões existentes para o servidor para novas solicitações de `FindFile` em vez de criar uma nova sessão para cada solicitação.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0. Para obter informações de erro estendidas, chame a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Depois de chamar `FindFile` para recuperar o primeiro arquivo FTP, você pode chamar [FindNextFile](#findnextfile) para recuperar arquivos FTP subsequentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo anterior neste tópico.

##  <a name="findnextfile"></a>CFtpFileFind::FindNextFile

Chame essa função de membro para continuar uma pesquisa de arquivo iniciada com uma chamada para a função de membro [FindFile](#findfile) .

```
virtual BOOL FindNextFile();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se houver mais arquivos; zero se o arquivo encontrado for o último no diretório ou se ocorreu um erro. Para obter informações de erro estendidas, chame a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Se o arquivo encontrado for o último arquivo no diretório ou se nenhum arquivo correspondente puder ser encontrado, a função `GetLastError` retornará ERROR_NO_MORE_FILES.

### <a name="remarks"></a>Comentários

Você deve chamar essa função pelo menos uma vez antes de chamar qualquer função de atributo (consulte [CFileFind:: FindNextFile](../../mfc/reference/cfilefind-class.md#findnextfile)).

`FindNextFile` encapsula a função [FindNextFile](/windows/win32/api/fileapi/nf-fileapi-findnextfilew)do Win32.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo anterior neste tópico.

##  <a name="getfileurl"></a>CFtpFileFind::GetFileURL

Chame essa função de membro para obter a URL do arquivo especificado.

```
CString GetFileURL() const;
```

### <a name="return-value"></a>Valor retornado

O arquivo e o caminho do localizador de recursos universal (URL).

### <a name="remarks"></a>Comentários

`GetFileURL` é semelhante à função de membro [CFileFind:: GetFilePath](../../mfc/reference/cfilefind-class.md#getfilepath), exceto pelo fato de que ela retorna a URL no formato `ftp://moose/dir/file.txt`.

## <a name="see-also"></a>Consulte também

[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
