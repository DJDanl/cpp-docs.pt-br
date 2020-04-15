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
ms.openlocfilehash: f01aa84593afed5a4f2f102da7d161ad42917080
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373882"
---
# <a name="cfilefind-class"></a>Classe CFileFind

Executa pesquisas de arquivos locais e é a classe base de [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFtpFileFind,](../../mfc/reference/cftpfilefind-class.md)que realizam pesquisas de arquivos da Internet.

## <a name="syntax"></a>Sintaxe

```
class CFileFind : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CfileFind::CfileFind](#cfilefind)|Constrói um objeto `CFileFind`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CfileFind::Fechar](#close)|Fecha o pedido de busca.|
|[CfileFind::FindFile](#findfile)|Pesquisa um diretório para obter um nome de arquivo especificado.|
|[CfileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|
|[CfileFind::getCreationTime](#getcreationtime)|Fica a hora que o arquivo foi criado.|
|[CfileFind::GetFileName](#getfilename)|Obtém o nome, incluindo a extensão, do arquivo encontrado|
|[CfileFind::GetFilePath](#getfilepath)|Pega todo o caminho do arquivo encontrado.|
|[CfileFind::GetFileTitle](#getfiletitle)|Obtém o título do arquivo encontrado. O título não inclui a extensão.|
|[CfileFind::GetFileURL](#getfileurl)|Obtém a URL, incluindo o caminho do arquivo, do arquivo encontrado.|
|[CfileFind::GetLastAccessTime](#getlastaccesstime)|Fica a hora que o arquivo foi acessado pela última vez.|
|[CfileFind::getLastWriteTime](#getlastwritetime)|Fica a hora em que o arquivo foi alterado pela última vez e salvo.|
|[CfileFind::GetLength](#getlength)|Obtém o comprimento do arquivo encontrado, em bytes.|
|[CFileFind::GetRoot](#getroot)|Obtém o diretório raiz do arquivo encontrado.|
|[CFileFind::IsArchived](#isarchived)|Determina se o arquivo encontrado está arquivado.|
|[CFileFind::IsCompactd](#iscompressed)|Determina se o arquivo encontrado está comprimido.|
|[CFileFind::IsDirectory](#isdirectory)|Determina se o arquivo encontrado é um diretório.|
|[CFileFind::IsDots](#isdots)|Determina se o nome do arquivo encontrado tem o nome "." ou "..", indicando que é realmente um diretório.|
|[CfileFind::IsHidden](#ishidden)|Determina se o arquivo encontrado está oculto.|
|[cfilefind::isnormal](#isnormal)|Determina se o arquivo encontrado é normal (em outras palavras, não tem outros atributos).|
|[CfileFind::IsReadOnly](#isreadonly)|Determina se o arquivo encontrado é somente leitura.|
|[CFileFind::IsSystem](#issystem)|Determina se o arquivo encontrado é um arquivo do sistema.|
|[CfileFind::isTemporary](#istemporary)|Determina se o arquivo encontrado é temporário.|
|[CfileFind::MatchesMask](#matchesmask)|Indica os atributos de arquivo desejados do arquivo a serem encontrados.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CfileFind::CloseContext](#closecontext)|Fecha o arquivo especificado pelo cabo de pesquisa atual.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CfileFind::m_pTM](#m_ptm)|Ponteiro para `CAtlTransactionManager` um objeto.|

## <a name="remarks"></a>Comentários

`CFileFind`inclui funções de membro que iniciam uma pesquisa, localizam um arquivo e retornam o título, nome ou caminho do arquivo. Para pesquisas na Internet, a função de membro [GetFileURL](#getfileurl) retorna a URL do arquivo.

`CFileFind`é a classe base para duas outras classes `CGopherFileFind` de MFC projetadas para `CFtpFileFind` pesquisar determinados tipos de servidor: funciona especificamente com servidores gopher e funciona especificamente com servidores FTP. Juntas, essas três classes fornecem um mecanismo perfeito para que o cliente encontre arquivos, independentemente do protocolo do servidor, do tipo de arquivo ou da localização, em uma máquina local ou em um servidor remoto.

O código a seguir enumerará todos os arquivos do diretório atual, imprimindo o nome de cada arquivo:

[!code-cpp[NVC_MFCFiles#31](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_1.cpp)]

Para manter o exemplo simples, este código `cout` usa a classe C++ Standard Library. A `cout` linha poderia ser substituída `CListBox::AddString`por uma chamada para, por exemplo, em um programa com uma interface gráfica de usuário.

Para obter mais informações `CFileFind` sobre como usar e as outras classes wininet, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CFileFind`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cfilefindcfilefind"></a><a name="cfilefind"></a>CfileFind::CfileFind

Esta função membro é `CFileFind` chamada quando um objeto é construído.

```
CFileFind();
CFileFind(CAtlTransactionManager* pTM);
```

### <a name="parameters"></a>Parâmetros

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetFileName](#getfilename).

## <a name="cfilefindclose"></a><a name="close"></a>CfileFind::Fechar

Chame essa função de membro para finalizar a pesquisa, redefinir o contexto e liberar todos os recursos.

```
void Close();
```

### <a name="remarks"></a>Comentários

Depois `Close`de ligar, você não `CFileFind` precisa criar uma nova instância antes de ligar para [findFile](#findfile) para iniciar uma nova pesquisa.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetFileName](#getfilename).

## <a name="cfilefindclosecontext"></a><a name="closecontext"></a>CfileFind::CloseContext

Fecha o arquivo especificado pelo cabo de pesquisa atual.

```
virtual void CloseContext();
```

### <a name="remarks"></a>Comentários

Fecha o arquivo especificado pelo valor atual da alça de pesquisa. Anular essa função para alterar o comportamento padrão.

Você deve chamar as funções [FindFile](#findfile) ou [FindNextFile](#findnextfile) pelo menos uma vez para recuperar uma alça de pesquisa válida. As `FindFile` `FindNextFile` funções e as funções usam a alça de pesquisa para localizar arquivos com nomes que correspondem a um determinado nome.

## <a name="cfilefindfindfile"></a><a name="findfile"></a>CfileFind::FindFile

Ligue para esta função de membro para abrir uma pesquisa de arquivos.

```
virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,
    DWORD dwUnused = 0);
```

### <a name="parameters"></a>Parâmetros

*pstrName*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo para encontrar. Se você passar NULL para `FindFile` *pstrName,* faça\*uma pesquisa curinga (*. )

*dwUnused*<br/>
Reservado para `FindFile` fazer polimórfico com classes derivadas. Deve ser 0.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Para obter informações de erro estendidas, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Depois `FindFile` de ligar para iniciar a pesquisa de arquivos, ligue para [FindNextFile](#findnextfile) para recuperar arquivos subseqüentes. Você deve `FindNextFile` ligar pelo menos uma vez antes de chamar qualquer uma das seguintes funções de membro de atributo:

- [GetCreationTime](#getcreationtime)

- [GetFileName](#getfilename)

- [Getfiletitle](#getfiletitle)

- [Getfilepath](#getfilepath)

- [Getfileurl](#getfileurl)

- [Getlastaccesstime](#getlastaccesstime)

- [Getlastwritetime](#getlastwritetime)

- [Getlength](#getlength)

- [GetRoot](#getroot)

- [IsArchived](#isarchived)

- [IsCompressed](#iscompressed)

- [Isdirectory](#isdirectory)

- [IsDots](#isdots)

- [IsHidden](#ishidden)

- [Isnormal](#isnormal)

- [Isreadonly](#isreadonly)

- [IsSystem](#issystem)

- [Istemporary](#istemporary)

- [Máscara de Fósforos](#matchesmask)

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind:IsDirectory](#isdirectory).

## <a name="cfilefindfindnextfile"></a><a name="findnextfile"></a>CfileFind::FindNextFile

Ligue para esta função de membro para continuar uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).

```
virtual BOOL FindNextFile();
```

### <a name="return-value"></a>Valor retornado

Não zero se houver mais arquivos; zero se o arquivo encontrado for o último no diretório ou se ocorreu um erro. Para obter informações de erro estendidas, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Se o arquivo encontrado for o último arquivo no diretório, ou `GetLastError` se nenhum arquivo correspondente for encontrado, a função retorna ERROR_NO_MORE_FILES.

### <a name="remarks"></a>Comentários

Você deve `FindNextFile` ligar pelo menos uma vez antes de chamar qualquer uma das seguintes funções de membro de atributo:

- [GetCreationTime](#getcreationtime)

- [GetFileName](#getfilename)

- [Getfiletitle](#getfiletitle)

- [Getfilepath](#getfilepath)

- [Getfileurl](#getfileurl)

- [Getlastaccesstime](#getlastaccesstime)

- [Getlastwritetime](#getlastwritetime)

- [Getlength](#getlength)

- [GetRoot](#getroot)

- [IsArchived](#isarchived)

- [IsCompressed](#iscompressed)

- [Isdirectory](#isdirectory)

- [IsDots](#isdots)

- [IsHidden](#ishidden)

- [Isnormal](#isnormal)

- [Isreadonly](#isreadonly)

- [IsSystem](#issystem)

- [Istemporary](#istemporary)

- [Máscara de Fósforos](#matchesmask)

`FindNextFile`envolve a função Win32 [FindNextFile](/windows/win32/api/fileapi/nf-fileapi-findnextfilew).

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind:IsDirectory](#isdirectory).

## <a name="cfilefindgetcreationtime"></a><a name="getcreationtime"></a>CfileFind::getCreationTime

Ligue para esta função de membro para obter a hora em que o arquivo especificado foi criado.

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

Não zero se bem sucedido; 0 se não tiver sucesso. `GetCreationTime`retorna 0 somente se [FindNextFile](#findnextfile) nunca `CFileFind` foi chamado neste objeto.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetCreationTime`.

> [!NOTE]
> Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por esta função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de tempo se o sistema de arquivos ou servidor subjacente não suportar a manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre formatos de tempo. Em alguns sistemas de operação, o tempo devolvido é no fuso horário local para a máquina onde o arquivo está localizado. Consulte a API Do [Arquivo Win32TimeToLocalLocalTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindgetfilename"></a><a name="getfilename"></a>CfileFind::GetFileName

Ligue para esta função de membro para obter o nome do arquivo encontrado.

```
virtual CString GetFileName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do arquivo mais recenteencontrado.

### <a name="remarks"></a>Comentários

Você deve ligar para [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar GetFileName.

`GetFileName`é uma `CFileFind` das três funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles variam:

- `GetFileName`retorna o nome do arquivo, incluindo a extensão. Por exemplo, `GetFileName` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o nome do arquivo *myfile.txt*.

- [GetFilePath](#getfilepath) retorna todo o caminho para o arquivo. Por exemplo, `GetFilePath` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o caminho do arquivo *c:\myhtml\myfile.txt*.

- [GetFileTitle](#getfiletitle) retorna o nome do arquivo, excluindo a extensão do arquivo. Por exemplo, `GetFileTitle` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o título do arquivo *myfile*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#32](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_2.cpp)]

## <a name="cfilefindgetfilepath"></a><a name="getfilepath"></a>CfileFind::GetFilePath

Ligue para esta função de membro para obter o caminho completo do arquivo especificado.

```
virtual CString GetFilePath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho do arquivo especificado.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetFilePath`.

`GetFilePath`é uma `CFileFind` das três funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles variam:

- [GetFileName](#getfilename) retorna o nome do arquivo, incluindo a extensão. Por exemplo, `GetFileName` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o nome do arquivo *myfile.txt*.

- `GetFilePath`retorna todo o caminho para o arquivo. Por exemplo, `GetFilePath` ligar para gerar uma `c:\myhtml\myfile.txt` mensagem `c:\myhtml\myfile.txt`de usuário sobre o arquivo retorna o caminho do arquivo .

- [GetFileTitle](#getfiletitle) retorna o nome do arquivo, excluindo a extensão do arquivo. Por exemplo, `GetFileTitle` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o título do arquivo *myfile*.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetFileName](#getfilename).

## <a name="cfilefindgetfiletitle"></a><a name="getfiletitle"></a>CfileFind::GetFileTitle

Ligue para esta função de membro para obter o título do arquivo encontrado.

```
virtual CString GetFileTitle() const;
```

### <a name="return-value"></a>Valor retornado

O título do arquivo.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetFileTitle`.

`GetFileTitle`é uma `CFileFind` das três funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles variam:

- [GetFileName](#getfilename) retorna o nome do arquivo, incluindo a extensão. Por exemplo, `GetFileName` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o nome do arquivo *myfile.txt*.

- [GetFilePath](#getfilepath) retorna todo o caminho para o arquivo. Por exemplo, `GetFilePath` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o caminho do arquivo *c:\myhtml\myfile.txt*.

- `GetFileTitle`retorna o nome do arquivo, excluindo a extensão do arquivo. Por exemplo, `GetFileTitle` chamar para gerar uma mensagem de usuário sobre o arquivo *c:\myhtml\myfile.txt* retorna o título do arquivo *myfile*.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetFileName](#getfilename).

## <a name="cfilefindgetfileurl"></a><a name="getfileurl"></a>CfileFind::GetFileURL

Ligue para esta função de membro para recuperar a URL especificada.

```
virtual CString GetFileURL() const;
```

### <a name="return-value"></a>Valor retornado

A URL completa.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetFileURL`.

`GetFileURL`é semelhante à função de membro [GetFilePath,](#getfilepath)exceto `file://path`que ele retorna a URL no formulário . Por exemplo, `GetFileURL` ligar para obter a URL completa para `file://c:\myhtml\myfile.txt` *myfile.txt* retorna a URL .

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetFileName](#getfilename).

## <a name="cfilefindgetlastaccesstime"></a><a name="getlastaccesstime"></a>CfileFind::GetLastAccessTime

Ligue para esta função de membro para obter o tempo que o arquivo especificado foi acessado pela última vez.

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

Não zero se bem sucedido; 0 se não tiver sucesso. `GetLastAccessTime`retorna 0 somente se [FindNextFile](#findnextfile) nunca `CFileFind` foi chamado neste objeto.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetLastAccessTime`.

> [!NOTE]
> Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por esta função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de tempo se o sistema de arquivos ou servidor subjacente não suportar a manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre formatos de tempo. Em alguns sistemas de operação, o tempo devolvido é no fuso horário local para a máquina onde o arquivo está localizado. Consulte a API Do [Arquivo Win32TimeToLocalLocalTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindgetlastwritetime"></a><a name="getlastwritetime"></a>CfileFind::getLastWriteTime

Ligue para esta função de membro para obter a última vez que o arquivo foi alterado.

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

Não zero se bem sucedido; 0 se não tiver sucesso. `GetLastWriteTime`retorna 0 somente se [FindNextFile](#findnextfile) nunca `CFileFind` foi chamado neste objeto.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetLastWriteTime`.

> [!NOTE]
> Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por esta função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de tempo se o sistema de arquivos ou servidor subjacente não suportar a manutenção do atributo de tempo. Consulte a estrutura [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter informações sobre formatos de tempo. Em alguns sistemas de operação, o tempo devolvido é no fuso horário local para a máquina onde o arquivo está localizado. Consulte a API Do [Arquivo Win32TimeToLocalLocalTime](/windows/win32/api/fileapi/nf-fileapi-filetimetolocalfiletime) para obter mais informações.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindgetlength"></a><a name="getlength"></a>CfileFind::GetLength

Ligue para esta função de membro para obter o comprimento do arquivo encontrado, em bytes.

```
ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento do arquivo encontrado, em bytes.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetLength`.

`GetLength`usa a estrutura Win32 [WIN32_FIND_DATA](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para obter e devolver o valor do tamanho do arquivo, em bytes.

> [!NOTE]
> A partir do MFC `GetLength` 7.0, suporta tipos inteiros de 64 bits. O código anteriormente existente construído com esta versão mais recente da biblioteca pode resultar em avisos de truncamento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#33](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_3.cpp)]

## <a name="cfilefindgetroot"></a><a name="getroot"></a>CFileFind::GetRoot

Ligue para esta função de membro para obter a raiz do arquivo encontrado.

```
virtual CString GetRoot() const;
```

### <a name="return-value"></a>Valor retornado

A raiz da busca ativa.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `GetRoot`.

Esta função de membro retorna o especificador da unidade e o nome do caminho usado para iniciar uma pesquisa. Por exemplo, chamar `*.dat` [FindFile](#findfile) com resultados no `GetRoot` retorno de uma seqüência de string vazia. Passando por um `c:\windows\system\*.dll`caminho, `FindFile` `GetRoot` como, `c:\windows\system\`para os resultados retornando.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetFileName](#getfilename).

## <a name="cfilefindisarchived"></a><a name="isarchived"></a>CFileFind::IsArchived

Ligue para esta função de membro para determinar se o arquivo encontrado está arquivado.

```
BOOL IsArchived() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os aplicativos marcam um arquivo de arquivo, que deve ser feito backup ou removido, com FILE_ATTRIBUTE_ARCHIVE, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw)

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsArchived`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindiscompressed"></a><a name="iscompressed"></a>CFileFind::IsCompactd

Ligue para esta função de membro para determinar se o arquivo encontrado está comprimido.

```
BOOL IsCompressed() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo compactado é marcado com FILE_ATTRIBUTE_COMPRESSED, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) Para um arquivo, este atributo indica que todos os dados do arquivo são compactados. Para um diretório, este atributo indica que a compactação é o padrão para arquivos e subdiretórios recém-criados.

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsCompressed`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindisdirectory"></a><a name="isdirectory"></a>CFileFind::IsDirectory

Ligue para esta função de membro para determinar se o arquivo encontrado é um diretório.

```
BOOL IsDirectory() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo que é um diretório é marcado com FILE_ATTRIBUTE_DIRECTORY um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw)

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsDirectory`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

Este pequeno programa reamaldiçoa todos os diretórios do C:\ unidade e imprime o nome do diretório.

[!code-cpp[NVC_MFCFiles#34](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_4.cpp)]

## <a name="cfilefindisdots"></a><a name="isdots"></a>CFileFind::IsDots

Chame esta função de membro para testar os marcadores atuais do diretório e do diretório pai enquanto itera através de arquivos.

```
virtual BOOL IsDots() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o arquivo encontrado tiver o nome "." ou "..", o que indica que o arquivo encontrado é na verdade um diretório. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsDots`.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind:IsDirectory](#isdirectory).

## <a name="cfilefindishidden"></a><a name="ishidden"></a>CfileFind::IsHidden

Ligue para esta função de membro para determinar se o arquivo encontrado está oculto.

```
BOOL IsHidden() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Arquivos ocultos, que são marcados com FILE_ATTRIBUTE_HIDDEN, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) Um arquivo oculto não está incluído em uma listagem de diretório comum.

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsHidden`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindisnormal"></a><a name="isnormal"></a>cfilefind::isnormal

Ligue para esta função de membro para determinar se o arquivo encontrado é um arquivo normal.

```
BOOL IsNormal() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Arquivos marcados com FILE_ATTRIBUTE_NORMAL, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) Um arquivo normal não tem outros atributos definidos. Todos os outros atributos de arquivo sobrepõem esse atributo.

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsNormal`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindisreadonly"></a><a name="isreadonly"></a>CfileFind::IsReadOnly

Ligue para esta função de membro para determinar se o arquivo encontrado é somente leitura.

```
BOOL IsReadOnly() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo somente leitura é marcado com FILE_ATTRIBUTE_READONLY, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) Os aplicativos podem ler esse arquivo, mas não podem gravá-lo ou excluí-lo.

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsReadOnly`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindissystem"></a><a name="issystem"></a>CFileFind::IsSystem

Ligue para esta função de membro para determinar se o arquivo encontrado é um arquivo do sistema.

```
BOOL IsSystem() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo do sistema é marcado com FILE_ATTRIBUTE_SYSTEM, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) Um arquivo de sistema faz parte ou é usado exclusivamente pelo sistema operacional.

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsSystem`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindistemporary"></a><a name="istemporary"></a>CfileFind::isTemporary

Ligue para esta função de membro para determinar se o arquivo encontrado é um arquivo temporário.

```
BOOL IsTemporary() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um arquivo temporário é marcado com FILE_ATTRIBUTE_TEMPORARY, um atributo de arquivo identificado na estrutura [WIN32_FIND_DATA.](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) Um arquivo temporário é usado para armazenamento temporário. Os aplicativos devem escrever para o arquivo somente se absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem ser liberado para a mídia porque o arquivo será excluído em breve.

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `IsTemporary`.

Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa de atributos de arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFileFind::GetLength](#getlength).

## <a name="cfilefindm_ptm"></a><a name="m_ptm"></a>CfileFind::m_pTM

Ponteiro para `CAtlTransactionManager` um objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

## <a name="cfilefindmatchesmask"></a><a name="matchesmask"></a>CfileFind::MatchesMask

Chame esta função de membro para testar os atributos do arquivo no arquivo encontrado.

```
virtual BOOL MatchesMask(DWORD dwMask) const;
```

### <a name="parameters"></a>Parâmetros

*Dwmask*<br/>
Especifica um ou mais atributos de arquivo, identificados na estrutura [WIN32_FIND_DATA,](/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataw) para o arquivo encontrado. Para pesquisar vários atributos, use o operador bitwise OR (&#124;). Qualquer combinação dos seguintes atributos é aceitável:

- FILE_ATTRIBUTE_ARCHIVE O arquivo é um arquivo de arquivo. Os aplicativos usam esse atributo para marcar arquivos para backup ou remoção.

- FILE_ATTRIBUTE_COMPRESSED O arquivo ou diretório é compactado. Para um arquivo, isso significa que todos os dados do arquivo são compactados. Para um diretório, isso significa que a compactação é o padrão para arquivos e subdiretórios recém-criados.

- FILE_ATTRIBUTE_DIRECTORY O arquivo é um diretório.

- FILE_ATTRIBUTE_NORMAL O arquivo não tem outros atributos definidos. Este atributo só é válido se usado sozinho. Todos os outros atributos de arquivo sobrepõem esse atributo.

- FILE_ATTRIBUTE_HIDDEN o arquivo está escondido. Não deve ser incluído em uma listagem de diretório comum.

- FILE_ATTRIBUTE_READONLY O arquivo é apenas lido. Os aplicativos podem ler o arquivo, mas não podem gravá-lo ou excluí-lo.

- FILE_ATTRIBUTE_SYSTEM O arquivo faz parte ou é usado exclusivamente pelo sistema operacional.

- FILE_ATTRIBUTE_TEMPORARY O arquivo está sendo usado para armazenamento temporário. Os aplicativos devem escrever para o arquivo somente se absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem ser liberado para a mídia porque o arquivo será excluído em breve.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Para obter informações de erro estendidas, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Você deve ligar para [findNextFile](#findnextfile) pelo menos uma vez antes de ligar `MatchesMask`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#35](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_5.cpp)]

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpFileFind](../../mfc/reference/cftpfilefind-class.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
