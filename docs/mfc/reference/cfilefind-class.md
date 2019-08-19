---
title: Classe CFileFind
ms.date: 11/04/2016
f1_keywords:
- CFileFind
- AFX/CFileFind
- AFX/CFileFind::CFileFind
- AFX/CFileFind::Close
- AFX/CFileFind::FindFile
- AFX/CFileFind::FindNextFile
- AFX/CFileFind::GetCreationTime
- AFX/CFileFind::GetFileName
- AFX/CFileFind::GetFilePath
- AFX/CFileFind::GetFileTitle
- AFX/CFileFind::GetFileURL
- AFX/CFileFind::GetLastAccessTime
- AFX/CFileFind::GetLastWriteTime
- AFX/CFileFind::GetLength
- AFX/CFileFind::GetRoot
- AFX/CFileFind::IsArchived
- AFX/CFileFind::IsCompressed
- AFX/CFileFind::IsDirectory
- AFX/CFileFind::IsDots
- AFX/CFileFind::IsHidden
- AFX/CFileFind::IsNormal
- AFX/CFileFind::IsReadOnly
- AFX/CFileFind::IsSystem
- AFX/CFileFind::IsTemporary
- AFX/CFileFind::MatchesMask
- AFX/CFileFind::CloseContext
- AFX/CFileFind::m_pTM
helpviewer_keywords:
- CFileFind [MFC], CFileFind
- CFileFind [MFC], Close
- CFileFind [MFC], FindFile
- CFileFind [MFC], FindNextFile
- CFileFind [MFC], GetCreationTime
- CFileFind [MFC], GetFileName
- CFileFind [MFC], GetFilePath
- CFileFind [MFC], GetFileTitle
- CFileFind [MFC], GetFileURL
- CFileFind [MFC], GetLastAccessTime
- CFileFind [MFC], GetLastWriteTime
- CFileFind [MFC], GetLength
- CFileFind [MFC], GetRoot
- CFileFind [MFC], IsArchived
- CFileFind [MFC], IsCompressed
- CFileFind [MFC], IsDirectory
- CFileFind [MFC], IsDots
- CFileFind [MFC], IsHidden
- CFileFind [MFC], IsNormal
- CFileFind [MFC], IsReadOnly
- CFileFind [MFC], IsSystem
- CFileFind [MFC], IsTemporary
- CFileFind [MFC], MatchesMask
- CFileFind [MFC], CloseContext
- CFileFind [MFC], m_pTM
ms.assetid: 9990068c-b023-4114-9580-a50182d15240
ms.openlocfilehash: 2ec8c50a317a09e97a212e8cd7b9be1b58272af9
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506565"
---
# <a name="cfilefind-class"></a>Classe CFileFind

Executa pesquisas de arquivos locais e é a classe base para [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md), que executam pesquisas de arquivos da Internet.

## <a name="syntax"></a>Sintaxe

```
class CFileFind : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileFind::CFileFind](#cfilefind)|Constrói um objeto `CFileFind`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileFind::Close](#close)|Fecha a solicitação de pesquisa.|
|[CFileFind::FindFile](#findfile)|Pesquisa um nome de arquivo especificado em um diretório.|
|[CFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|
|[CFileFind::GetCreationTime](#getcreationtime)|Obtém a hora em que o arquivo foi criado.|
|[CFileFind::GetFileName](#getfilename)|Obtém o nome, incluindo a extensão, do arquivo encontrado|
|[CFileFind::GetFilePath](#getfilepath)|Obtém o caminho completo do arquivo encontrado.|
|[CFileFind::GetFileTitle](#getfiletitle)|Obtém o título do arquivo encontrado. O título não inclui a extensão.|
|[CFileFind::GetFileURL](#getfileurl)|Obtém a URL, incluindo o caminho do arquivo, do arquivo encontrado.|
|[CFileFind::GetLastAccessTime](#getlastaccesstime)|Obtém a hora em que o arquivo foi acessado pela última vez.|
|[CFileFind::GetLastWriteTime](#getlastwritetime)|Obtém a hora em que o arquivo foi alterado e salvo pela última vez.|
|[CFileFind::GetLength](#getlength)|Obtém o comprimento do arquivo encontrado, em bytes.|
|[CFileFind::GetRoot](#getroot)|Obtém o diretório raiz do arquivo encontrado.|
|[CFileFind::IsArchived](#isarchived)|Determina se o arquivo encontrado está arquivado.|
|[CFileFind::IsCompressed](#iscompressed)|Determina se o arquivo encontrado está compactado.|
|[CFileFind::IsDirectory](#isdirectory)|Determina se o arquivo encontrado é um diretório.|
|[CFileFind::IsDots](#isdots)|Determina se o nome do arquivo encontrado tem o nome "." ou "..", indicando que é, na verdade, um diretório.|
|[CFileFind::IsHidden](#ishidden)|Determina se o arquivo encontrado está oculto.|
|[CFileFind::IsNormal](#isnormal)|Determina se o arquivo encontrado é normal (em outras palavras, se não tem outros atributos).|
|[CFileFind::IsReadOnly](#isreadonly)|Determina se o arquivo encontrado é somente leitura.|
|[CFileFind::IsSystem](#issystem)|Determina se o arquivo encontrado é um arquivo de sistema.|
|[CFileFind::IsTemporary](#istemporary)|Determina se o arquivo encontrado é temporário.|
|[CFileFind::MatchesMask](#matchesmask)|Indica os atributos de arquivo desejados do arquivo a ser encontrado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CFileFind::CloseContext](#closecontext)|Fecha o arquivo especificado pelo identificador de pesquisa atual.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CFileFind::m_pTM](#m_ptm)|Ponteiro para um `CAtlTransactionManager` objeto.|

## <a name="remarks"></a>Comentários

`CFileFind`inclui funções de membro que iniciam uma pesquisa, localizam um arquivo e retornam o título, o nome ou o caminho do arquivo. Para pesquisas na Internet, a função de membro [GetFileURL](#getfileurl) retorna a URL do arquivo.

`CFileFind`é a classe base para duas outras classes MFC projetadas para Pesquisar tipos de servidor `CGopherFileFind` específicos: funciona especificamente com servidores Gopher `CFtpFileFind` e funciona especificamente com servidores FTP. Juntas, essas três classes fornecem um mecanismo contínuo para o cliente encontrar arquivos, independentemente do protocolo de servidor, do tipo de arquivo ou do local, em um computador local ou em um servidor remoto.

O código a seguir irá enumerar todos os arquivos no diretório atual, imprimindo o nome de cada arquivo:

[!code-cpp[NVC_MFCFiles#31](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_1.cpp)]

Para manter o exemplo simples, esse código usa a C++ classe de `cout` biblioteca padrão. A `cout` linha pode ser substituída por uma chamada `CListBox::AddString`para, por exemplo, em um programa com uma interface gráfica do usuário.

Para obter mais informações sobre como usar `CFileFind` o e outras classes do Wininet, consulte o artigo [programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CFileFind`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cfilefind"></a>  CFileFind::CFileFind

Essa função de membro é chamada quando `CFileFind` um objeto é construído.

```
CFileFind();
CFileFind(CAtlTransactionManager* pTM);
```

### <a name="parameters"></a>Parâmetros

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetFileName](#getfilename).

##  <a name="close"></a>  CFileFind::Close

Chame essa função de membro para encerrar a pesquisa, redefinir o contexto e liberar todos os recursos.

```
void Close();
```

### <a name="remarks"></a>Comentários

Depois de `Close`chamar, você não precisa criar uma nova `CFileFind` instância antes de chamar [FindFile](#findfile) para iniciar uma nova pesquisa.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetFileName](#getfilename).

##  <a name="closecontext"></a>  CFileFind::CloseContext

Fecha o arquivo especificado pelo identificador de pesquisa atual.

```
virtual void CloseContext();
```

### <a name="remarks"></a>Comentários

Fecha o arquivo especificado pelo valor atual do identificador de pesquisa. Substitua essa função para alterar o comportamento padrão.

Você deve chamar as funções [FindFile](#findfile) ou [FindNextFile](#findnextfile) pelo menos uma vez para recuperar um identificador de pesquisa válido. As `FindFile` funções `FindNextFile` e usam o identificador de pesquisa para localizar arquivos com nomes que correspondem a um determinado nome.

##  <a name="findfile"></a>  CFileFind::FindFile

Chame essa função de membro para abrir uma pesquisa de arquivo.

```
virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,
    DWORD dwUnused = 0);
```

### <a name="parameters"></a>Parâmetros

*pstrName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser localizado. Se você passar NULL para *pstrName*, `FindFile` o fará uma pesquisa curinga (\**.).

*dwUnused*<br/>
Reservado para tornar `FindFile` polimórfico com classes derivadas. Precisa ser 0.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Para obter informações de erro estendidas, chame a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Depois de `FindFile` chamar para iniciar a pesquisa de arquivo, chame [FindNextFile](#findnextfile) para recuperar os arquivos subsequentes. Você deve chamar `FindNextFile` pelo menos uma vez antes de chamar qualquer uma das seguintes funções de membro de atributo:

- [GetCreationTime](#getcreationtime)

- [GetFileName](#getfilename)

- [GetFileTitle](#getfiletitle)

- [GetFilePath](#getfilepath)

- [GetFileURL](#getfileurl)

- [GetLastAccessTime](#getlastaccesstime)

- [GetLastWriteTime](#getlastwritetime)

- [GetLength](#getlength)

- [GetRoot](#getroot)

- [Isarquivado](#isarchived)

- [IsCompressed](#iscompressed)

- [IsDirectory](#isdirectory)

- [IsDots](#isdots)

- [IsHidden](#ishidden)

- [IsNormal](#isnormal)

- [IsReadOnly](#isreadonly)

- [IsSystem](#issystem)

- [IsTemporary](#istemporary)

- [MatchesMask](#matchesmask)

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind::](#isdirectory)IsDirectory.

##  <a name="findnextfile"></a>  CFileFind::FindNextFile

Chame essa função de membro para continuar uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).

```
virtual BOOL FindNextFile();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se houver mais arquivos; zero se o arquivo encontrado for o último no diretório ou se ocorreu um erro. Para obter informações de erro estendidas, chame a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Se o arquivo encontrado for o último arquivo no diretório ou se nenhum arquivo correspondente puder ser encontrado, a `GetLastError` função retornará ERROR_NO_MORE_FILES.

### <a name="remarks"></a>Comentários

Você deve chamar `FindNextFile` pelo menos uma vez antes de chamar qualquer uma das seguintes funções de membro de atributo:

- [GetCreationTime](#getcreationtime)

- [GetFileName](#getfilename)

- [GetFileTitle](#getfiletitle)

- [GetFilePath](#getfilepath)

- [GetFileURL](#getfileurl)

- [GetLastAccessTime](#getlastaccesstime)

- [GetLastWriteTime](#getlastwritetime)

- [GetLength](#getlength)

- [GetRoot](#getroot)

- [Isarquivado](#isarchived)

- [IsCompressed](#iscompressed)

- [IsDirectory](#isdirectory)

- [IsDots](#isdots)

- [IsHidden](#ishidden)

- [IsNormal](#isnormal)

- [IsReadOnly](#isreadonly)

- [IsSystem](#issystem)

- [IsTemporary](#istemporary)

- [MatchesMask](#matchesmask)

`FindNextFile`encapsula a função do Win32 [FindNextFile](/windows/win32/api/fileapi/nf-fileapi-findnextfilew).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind::](#isdirectory)IsDirectory.

##  <a name="getcreationtime"></a>  CFileFind::GetCreationTime

Chame essa função de membro para obter a hora em que o arquivo especificado foi criado.

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

Diferente de zero, se for bem-sucedido; 0 se não for bem-sucedida. `GetCreationTime`retornará 0 somente se [FindNextFile](#findnextfile) nunca tiver sido chamado neste `CFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetCreationTime`de chamar.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de data/hora retornado por essa função. Essa função pode retornar o mesmo valor retornado por outras funções de carimbo de data/hora se o sistema de arquivos ou servidor subjacente não oferecer suporte à manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre os formatos de hora. Em alguns sistemas operacionais, a hora retornada está no fuso horário local para o computador. o arquivo está localizado. Consulte a API do Win32 [FileTimeToLocalFileTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="getfilename"></a>  CFileFind::GetFileName

Chame essa função de membro para obter o nome do arquivo encontrado.

```
virtual CString GetFileName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome do arquivo mais recentemente encontrado.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar GetFileName.

`GetFileName`é uma das três `CFileFind` funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles variam:

- `GetFileName`Retorna o nome do arquivo, incluindo a extensão. Por exemplo, chamar `GetFileName` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o nome de arquivo *MyFile. txt*.

- [GetFilePath](#getfilepath) retorna o caminho inteiro para o arquivo. Por exemplo, chamar `GetFilePath` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o caminho do arquivo *c:\myhtml\myfile.txt*.

- [GetFileTitle](#getfiletitle) retorna o nome do arquivo, excluindo a extensão do arquivo. Por exemplo, chamar `GetFileTitle` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o título do arquivo *MyFile*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#32](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_2.cpp)]

##  <a name="getfilepath"></a>  CFileFind::GetFilePath

Chame essa função de membro para obter o caminho completo do arquivo especificado.

```
virtual CString GetFilePath() const;
```

### <a name="return-value"></a>Valor de retorno

O caminho do arquivo especificado.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetFilePath`de chamar.

`GetFilePath`é uma das três `CFileFind` funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles variam:

- [GetFileName](#getfilename) retorna o nome do arquivo, incluindo a extensão. Por exemplo, chamar `GetFileName` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o nome de arquivo *MyFile. txt*.

- `GetFilePath`Retorna o caminho inteiro para o arquivo. Por exemplo, chamar `GetFilePath` para gerar uma mensagem de usuário sobre o `c:\myhtml\myfile.txt` arquivo retorna o caminho `c:\myhtml\myfile.txt`do arquivo.

- [GetFileTitle](#getfiletitle) retorna o nome do arquivo, excluindo a extensão do arquivo. Por exemplo, chamar `GetFileTitle` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o título do arquivo *MyFile*.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetFileName](#getfilename).

##  <a name="getfiletitle"></a>  CFileFind::GetFileTitle

Chame essa função de membro para obter o título do arquivo encontrado.

```
virtual CString GetFileTitle() const;
```

### <a name="return-value"></a>Valor de retorno

O título do arquivo.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetFileTitle`de chamar.

`GetFileTitle`é uma das três `CFileFind` funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles variam:

- [GetFileName](#getfilename) retorna o nome do arquivo, incluindo a extensão. Por exemplo, chamar `GetFileName` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o nome de arquivo *MyFile. txt*.

- [GetFilePath](#getfilepath) retorna o caminho inteiro para o arquivo. Por exemplo, chamar `GetFilePath` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o caminho do arquivo *c:\myhtml\myfile.txt*.

- `GetFileTitle`Retorna o nome do arquivo, excluindo a extensão do arquivo. Por exemplo, chamar `GetFileTitle` para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o título do arquivo *MyFile*.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetFileName](#getfilename).

##  <a name="getfileurl"></a>  CFileFind::GetFileURL

Chame essa função de membro para recuperar a URL especificada.

```
virtual CString GetFileURL() const;
```

### <a name="return-value"></a>Valor de retorno

A URL completa.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetFileURL`de chamar.

`GetFileURL`é semelhante à função de membro [GetFilePath](#getfilepath), exceto pelo fato de que ela retorna a URL `file://path`no formulário. Por exemplo, chamar `GetFileURL` para obter a URL completa para *MyFile. txt* retorna a URL `file://c:\myhtml\myfile.txt`.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetFileName](#getfilename).

##  <a name="getlastaccesstime"></a>  CFileFind::GetLastAccessTime

Chame essa função de membro para obter a hora em que o arquivo especificado foi acessado pela última vez.

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

Diferente de zero, se for bem-sucedido; 0 se não for bem-sucedida. `GetLastAccessTime`retornará 0 somente se [FindNextFile](#findnextfile) nunca tiver sido chamado neste `CFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetLastAccessTime`de chamar.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de data/hora retornado por essa função. Essa função pode retornar o mesmo valor retornado por outras funções de carimbo de data/hora se o sistema de arquivos ou servidor subjacente não oferecer suporte à manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre os formatos de hora. Em alguns sistemas operacionais, a hora retornada está no fuso horário local para o computador. o arquivo está localizado. Consulte a API do Win32 [FileTimeToLocalFileTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="getlastwritetime"></a>  CFileFind::GetLastWriteTime

Chame essa função de membro para obter a última vez em que o arquivo foi alterado.

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

Diferente de zero, se for bem-sucedido; 0 se não for bem-sucedida. `GetLastWriteTime`retornará 0 somente se [FindNextFile](#findnextfile) nunca tiver sido chamado neste `CFileFind` objeto.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetLastWriteTime`de chamar.

> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de data/hora retornado por essa função. Essa função pode retornar o mesmo valor retornado por outras funções de carimbo de data/hora se o sistema de arquivos ou servidor subjacente não oferecer suporte à manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre os formatos de hora. Em alguns sistemas operacionais, a hora retornada está no fuso horário local para o computador. o arquivo está localizado. Consulte a API do Win32 [FileTimeToLocalFileTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="getlength"></a>  CFileFind::GetLength

Chame essa função de membro para obter o comprimento do arquivo encontrado, em bytes.

```
ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento do arquivo encontrado, em bytes.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetLength`de chamar.

`GetLength`usa o [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) de estrutura do Win32 para obter e retornar o valor do tamanho do arquivo, em bytes.

> [!NOTE]
>  A partir do MFC 7,0 `GetLength` , dá suporte a tipos inteiros de 64 bits. O código existente anteriormente criado com essa versão mais recente da biblioteca pode resultar em avisos de truncamento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#33](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_3.cpp)]

##  <a name="getroot"></a>  CFileFind::GetRoot

Chame essa função de membro para obter a raiz do arquivo encontrado.

```
virtual CString GetRoot() const;
```

### <a name="return-value"></a>Valor de retorno

A raiz da pesquisa ativa.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `GetRoot`de chamar.

Essa função de membro retorna o especificador de unidade e o nome do caminho usado para iniciar uma pesquisa. Por exemplo, chamar [FindFile](#findfile) com `*.dat` resultados retornando uma cadeia de `GetRoot` caracteres vazia. `c:\windows\system\*.dll`Passando um caminho, como, para `FindFile` resultados `GetRoot` retornando `c:\windows\system\`.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetFileName](#getfilename).

##  <a name="isarchived"></a>  CFileFind::IsArchived

Chame essa função de membro para determinar se o arquivo encontrado está arquivado.

```
BOOL IsArchived() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os aplicativos marcam um arquivo morto, que deve ser submetido a backup ou removido, com FILE_ATTRIBUTE_ARCHIVE, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) .

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsArchived`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="iscompressed"></a>  CFileFind::IsCompressed

Chame essa função de membro para determinar se o arquivo encontrado está compactado.

```
BOOL IsCompressed() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo compactado é marcado com FILE_ATTRIBUTE_COMPRESSED, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) . Para um arquivo, esse atributo indica que todos os dados no arquivo estão compactados. Para um diretório, esse atributo indica que a compactação é o padrão para arquivos e subdiretórios recém-criados.

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsCompressed`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="isdirectory"></a>  CFileFind::IsDirectory

Chame essa função de membro para determinar se o arquivo encontrado é um diretório.

```
BOOL IsDirectory() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo que é um diretório é marcado com FILE_ATTRIBUTE_DIRECTORY um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) .

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsDirectory`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

Este pequeno programa recursivamente todos os diretórios em C:\ unidade e imprime o nome do diretório.

[!code-cpp[NVC_MFCFiles#34](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_4.cpp)]

##  <a name="isdots"></a>  CFileFind::IsDots

Chame essa função de membro para testar o diretório atual e os marcadores de diretório pai durante a iteração por meio de arquivos.

```
virtual BOOL IsDots() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo encontrado tiver o nome "." ou "..", que indica que o arquivo encontrado é, na verdade, um diretório. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsDots`de chamar.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind::](#isdirectory)IsDirectory.

##  <a name="ishidden"></a>  CFileFind::IsHidden

Chame essa função de membro para determinar se o arquivo encontrado está oculto.

```
BOOL IsHidden() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Arquivos ocultos, que são marcados com FILE_ATTRIBUTE_HIDDEN, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) . Um arquivo oculto não está incluído em uma listagem de diretório comum.

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsHidden`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="isnormal"></a>  CFileFind::IsNormal

Chame essa função de membro para determinar se o arquivo encontrado é um arquivo normal.

```
BOOL IsNormal() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Arquivos marcados com FILE_ATTRIBUTE_NORMAL, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) . Um arquivo normal não tem nenhum outro atributo definido. Todos os outros atributos de arquivo substituem esse atributo.

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsNormal`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="isreadonly"></a>  CFileFind::IsReadOnly

Chame essa função de membro para determinar se o arquivo encontrado é somente leitura.

```
BOOL IsReadOnly() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo somente leitura é marcado com FILE_ATTRIBUTE_READONLY, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) . Os aplicativos podem ler esse arquivo, mas não podem gravar nele nem excluí-lo.

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsReadOnly`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="issystem"></a>  CFileFind::IsSystem

Chame essa função de membro para determinar se o arquivo encontrado é um arquivo de sistema.

```
BOOL IsSystem() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo de sistema é marcado com FILE_ATTRIBUTE_SYSTEM,, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) . Um arquivo de sistema faz parte do, ou é usado exclusivamente pelo sistema operacional.

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsSystem`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="istemporary"></a>  CFileFind::IsTemporary

Chame essa função de membro para determinar se o arquivo encontrado é um arquivo temporário.

```
BOOL IsTemporary() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo temporário é marcado com FILE_ATTRIBUTE_TEMPORARY, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) . Um arquivo temporário é usado para armazenamento temporário. Os aplicativos devem gravar no arquivo somente se for absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem ser liberada para a mídia porque o arquivo será excluído em breve.

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `IsTemporary`de chamar.

Consulte a função membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFileFind:: GetLength](#getlength).

##  <a name="m_ptm"></a>  CFileFind::m_pTM

Ponteiro para um `CAtlTransactionManager` objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

##  <a name="matchesmask"></a>  CFileFind::MatchesMask

Chame essa função de membro para testar os atributos de arquivo no arquivo encontrado.

```
virtual BOOL MatchesMask(DWORD dwMask) const;
```

### <a name="parameters"></a>Parâmetros

*dwMask*<br/>
Especifica um ou mais atributos de arquivo, identificados na estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) , para o arquivo encontrado. Para pesquisar vários atributos, use o&#124;operador OR Qualquer combinação dos seguintes atributos é aceitável:

- FILE_ATTRIBUTE_ARCHIVE o arquivo é um arquivo morto. Os aplicativos usam esse atributo para marcar arquivos para backup ou remoção.

- FILE_ATTRIBUTE_COMPRESSED o arquivo ou diretório está compactado. Para um arquivo, isso significa que todos os dados no arquivo estão compactados. Para um diretório, isso significa que a compactação é o padrão para arquivos e subdiretórios recém-criados.

- FILE_ATTRIBUTE_DIRECTORY o arquivo é um diretório.

- FILE_ATTRIBUTE_NORMAL o arquivo não tem nenhum outro atributo definido. Esse atributo é válido somente se usado sozinho. Todos os outros atributos de arquivo substituem esse atributo.

- FILE_ATTRIBUTE_HIDDEN o arquivo está oculto. Ele não deve ser incluído em uma listagem de diretório comum.

- FILE_ATTRIBUTE_READONLY o arquivo é somente leitura. Os aplicativos podem ler o arquivo, mas não podem gravar nele nem excluí-lo.

- FILE_ATTRIBUTE_SYSTEM o arquivo é parte do ou é usado exclusivamente pelo sistema operacional.

- FILE_ATTRIBUTE_TEMPORARY o arquivo está sendo usado para armazenamento temporário. Os aplicativos devem gravar no arquivo somente se for absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem ser liberada para a mídia porque o arquivo será excluído em breve.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Para obter informações de erro estendidas, chame a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes `MatchesMask`de chamar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#35](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_5.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpFileFind](../../mfc/reference/cftpfilefind-class.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
