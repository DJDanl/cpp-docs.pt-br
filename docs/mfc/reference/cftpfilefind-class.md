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
ms.openlocfilehash: cf4afb4a683c2d0cf5f2977107d02ee300a53cb0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373750"
---
# <a name="cftpfilefind-class"></a>Classe CFtpFileFind

Auxilia nas pesquisas de arquivos da Internet de servidores FTP.

## <a name="syntax"></a>Sintaxe

```
class CFtpFileFind : public CFileFind
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CftpFileFind::CFtpFileFind](#cftpfilefind)|Constrói um objeto `CFtpFileFind`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CftpFileFind::FindFile](#findfile)|Encontra um arquivo em um servidor FTP.|
|[CftpFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|
|[CFtpFileFind::GetFileURL](#getfileurl)|Obtém a URL, incluindo o caminho, do arquivo encontrado.|

## <a name="remarks"></a>Comentários

`CFtpFileFind`inclui funções de membro que iniciam uma pesquisa, localizam um arquivo e retornam a URL ou outras informações descritivas sobre o arquivo.

Outras classes de MFC projetadas para Internet e arquivos locais pesquisados incluem [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Juntamente `CFtpFileFind`com, essas classes fornecem um mecanismo perfeito para o cliente encontrar arquivos específicos, independentemente do protocolo do servidor ou do tipo de arquivo (seja uma máquina local ou um servidor remoto). Observe que não há classe MFC para pesquisa em servidores HTTP porque http não suporta a manipulação direta de arquivos necessária para pesquisas.

Para obter mais informações `CFtpFileFind` sobre como usar e as outras classes wininet, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="example"></a>Exemplo

O código a seguir demonstra como enumerar todos os arquivos no diretório atual do servidor FTP.

[!code-cpp[NVC_MFCWinInet#8](../../mfc/codesnippet/cpp/cftpfilefind-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfilefind](../../mfc/reference/cfilefind-class.md)

`CFtpFileFind`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cftpfilefindcftpfilefind"></a><a name="cftpfilefind"></a>CftpFileFind::CFtpFileFind

Esta função membro é `CFtpFileFind` chamada para construir um objeto.

```
explicit CFtpFileFind(
    CFtpConnection* pConnection,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pConnection*<br/>
Um ponteiro para um objeto `CFtpConnection`. Você pode obter uma conexão FTP ligando para [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection).

*Dwcontext*<br/>
O identificador de `CFtpFileFind` contexto para o objeto. Consulte **Observações** para obter mais informações sobre este parâmetro.

### <a name="remarks"></a>Comentários

O valor padrão para *dwContext* é `CFtpFileFind` enviado pelo MFC para o `CFtpFileFind` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o objeto. Você pode substituir o padrão para definir o identificador de contexto a um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com o qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="example"></a>Exemplo

  Veja o exemplo na visão geral da classe no início deste tópico.

## <a name="cftpfilefindfindfile"></a><a name="findfile"></a>CftpFileFind::FindFile

Ligue para esta função de membro para encontrar um arquivo FTP.

```
virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,
    DWORD dwFlags = INTERNET_FLAG_RELOAD);
```

### <a name="parameters"></a>Parâmetros

*pstrName*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo para encontrar. Se NULA, a chamada realizará uma pesquisa curinga (*).

*dwFlags*<br/>
As bandeiras descrevendo como lidar com esta sessão. Essas bandeiras podem ser combinadas com o operador bitwise OR (&#124;) e são as seguintes:

- INTERNET_FLAG_RELOAD obter os dados do fio, mesmo que sejam armazenados em cache local. Esta é a bandeira padrão.

- INTERNET_FLAG_DONT_CACHE Não faça cache de dados, localmente ou em gateways.

- INTERNET_FLAG_RAW_DATA Substituir o padrão para retornar os dados brutos [(estruturas WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para FTP).

- INTERNET_FLAG_SECURE Segura transações no fio com Secure Sockets Layer ou PCT. Este sinalizador é aplicável apenas às solicitações HTTP.

- INTERNET_FLAG_EXISTING_CONNECT Se possível, reutilize as conexões existentes `FindFile` ao servidor para novas solicitações, em vez de criar uma nova sessão para cada solicitação.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Para obter informações de erro estendidas, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Depois `FindFile` de ligar para recuperar o primeiro arquivo FTP, você pode chamar [FindNextFile](#findnextfile) para recuperar arquivos FTP subseqüentes.

### <a name="example"></a>Exemplo

  Veja o exemplo anterior neste tópico.

## <a name="cftpfilefindfindnextfile"></a><a name="findnextfile"></a>CftpFileFind::FindNextFile

Ligue para esta função de membro para continuar uma pesquisa de arquivos iniciada com uma chamada para a função de membro [FindFile.](#findfile)

```
virtual BOOL FindNextFile();
```

### <a name="return-value"></a>Valor retornado

Não zero se houver mais arquivos; zero se o arquivo encontrado for o último no diretório ou se ocorreu um erro. Para obter informações de erro estendidas, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Se o arquivo encontrado for o último arquivo no diretório, ou `GetLastError` se nenhum arquivo correspondente for encontrado, a função retorna ERROR_NO_MORE_FILES.

### <a name="remarks"></a>Comentários

Você deve chamar essa função pelo menos uma vez antes de chamar qualquer função de atributo (consulte [CFileFind::FindNextFile](../../mfc/reference/cfilefind-class.md#findnextfile)).

`FindNextFile`envolve a função Win32 [FindNextFile](/windows/win32/api/fileapi/nf-fileapi-findnextfilew).

### <a name="example"></a>Exemplo

  Veja o exemplo anterior neste tópico.

## <a name="cftpfilefindgetfileurl"></a><a name="getfileurl"></a>CFtpFileFind::GetFileURL

Ligue para esta função de membro para obter a URL do arquivo especificado.

```
CString GetFileURL() const;
```

### <a name="return-value"></a>Valor retornado

O arquivo e o caminho do Url (Universal Resource Locator).

### <a name="remarks"></a>Comentários

`GetFileURL`é semelhante à função de membro [CFileFind::GetFilePath,](../../mfc/reference/cfilefind-class.md#getfilepath)exceto `ftp://moose/dir/file.txt`que ele retorna a URL no formulário .

## <a name="see-also"></a>Confira também

[Classe CFileFind](../../mfc/reference/cfilefind-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
