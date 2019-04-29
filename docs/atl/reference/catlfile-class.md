---
title: Classe CAtlFile
ms.date: 11/04/2016
f1_keywords:
- CAtlFile
- ATLFILE/ATL::CAtlFile
- ATLFILE/ATL::CAtlFile::CAtlFile
- ATLFILE/ATL::CAtlFile::Create
- ATLFILE/ATL::CAtlFile::Flush
- ATLFILE/ATL::CAtlFile::GetOverlappedResult
- ATLFILE/ATL::CAtlFile::GetPosition
- ATLFILE/ATL::CAtlFile::GetSize
- ATLFILE/ATL::CAtlFile::LockRange
- ATLFILE/ATL::CAtlFile::Read
- ATLFILE/ATL::CAtlFile::Seek
- ATLFILE/ATL::CAtlFile::SetSize
- ATLFILE/ATL::CAtlFile::UnlockRange
- ATLFILE/ATL::CAtlFile::Write
- ATLFILE/ATL::CAtlFile::m_pTM
helpviewer_keywords:
- CAtlFile class
ms.assetid: 93ed160b-af2a-448c-9cbe-e5fa46c199bb
ms.openlocfilehash: 0faae50afcd26948bdcb4d4333efb25d5cca33ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62260220"
---
# <a name="catlfile-class"></a>Classe CAtlFile

Essa classe fornece um wrapper estreito ao redor do Windows API de manipulação de arquivos.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlFile : public CHandle
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFile::CAtlFile](#catlfile)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFile::Create](#create)|Chame esse método para criar ou abrir um arquivo.|
|[CAtlFile::Flush](#flush)|Chame esse método para limpar os buffers para o arquivo e fazer com que todos os dados armazenados em buffer sejam gravados no arquivo.|
|[CAtlFile::GetOverlappedResult](#getoverlappedresult)|Chame esse método para obter os resultados de uma operação sobreposta no arquivo.|
|[CAtlFile::GetPosition](#getposition)|Chame esse método para obter a posição atual do ponteiro de arquivo do arquivo.|
|[CAtlFile::GetSize](#getsize)|Chame esse método para obter o tamanho em bytes do arquivo.|
|[CAtlFile::LockRange](#lockrange)|Chame esse método para bloquear uma região no arquivo para impedir que outros processos de acessá-la.|
|[CAtlFile::Read](#read)|Chame esse método para ler dados de um arquivo começando na posição indicada pelo ponteiro de arquivo.|
|[CAtlFile::Seek](#seek)|Chame esse método para mover o ponteiro do arquivo do arquivo.|
|[CAtlFile::SetSize](#setsize)|Chame esse método para definir o tamanho do arquivo.|
|[CAtlFile::UnlockRange](#unlockrange)|Chame esse método para desbloquear uma região do arquivo.|
|[CAtlFile::Write](#write)|Chame esse método para gravar dados no arquivo começando na posição indicada pelo ponteiro de arquivo.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFile::m_pTM](#m_ptm)|Ponteiro para `CAtlTransactionManager` objeto|

## <a name="remarks"></a>Comentários

Use esta classe quando as necessidades de manipulação de arquivos são relativamente simples, mas mais de abstração que fornece a API do Windows é necessária, sem incluir as dependências do MFC.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CHandle](../../atl/reference/chandle-class.md)

`CAtlFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile.h

##  <a name="catlfile"></a>  CAtlFile::CAtlFile

O construtor.

```
CAtlFile() throw();
CAtlFile(CAtlTransactionManager* pTM = NULL) throw();
CAtlFile(CAtlFile& file) throw();
explicit CAtlFile(HANDLE hFile) throw();
```

### <a name="parameters"></a>Parâmetros

*file*<br/>
O objeto de arquivo.

*hFile*<br/>
O identificador de arquivo.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

O construtor de cópia transfere a propriedade do identificador de arquivo do original `CAtlFile` objeto para o objeto recentemente construído.

##  <a name="create"></a>  CAtlFile::Create

Chame esse método para criar ou abrir um arquivo.

```
HRESULT Create(
    LPCTSTR szFilename,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL,
    LPSECURITY_ATTRIBUTES lpsa = NULL,
    HANDLE hTemplateFile = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*szFilename*<br/>
O nome de arquivo.

*dwDesiredAccess*<br/>
O acesso desejado. Ver *dwDesiredAccess* na [CreateFile](/windows/desktop/api/fileapi/nf-fileapi-createfilea) no SDK do Windows.

*dwShareMode*<br/>
O modo de compartilhamento. Ver *dwShareMode* em `CreateFile`.

*dwCreationDisposition*<br/>
A disposição de criação. Ver *dwCreationDisposition* em `CreateFile`.

*dwFlagsAndAttributes*<br/>
Os sinalizadores e atributos. Ver *dwFlagsAndAttributes* em `CreateFile`.

*lpsa*<br/>
Os atributos de segurança. Ver *lpSecurityAttributes* em `CreateFile`.

*hTemplateFile*<br/>
O arquivo de modelo. Ver *hTemplateFile* em `CreateFile`.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [CreateFile](/windows/desktop/api/fileapi/nf-fileapi-createfilea) para criar ou abrir o arquivo.

##  <a name="flush"></a>  CAtlFile::Flush

Chame esse método para limpar os buffers para o arquivo e fazer com que todos os dados armazenados em buffer sejam gravados no arquivo.

```
HRESULT Flush() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [FlushFileBuffers](/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers) liberar dados armazenados em buffer para o arquivo.

##  <a name="getoverlappedresult"></a>  CAtlFile::GetOverlappedResult

Chame esse método para obter os resultados de uma operação sobreposta no arquivo.

```
HRESULT GetOverlappedResult(
    LPOVERLAPPED pOverlapped,
    DWORD& dwBytesTransferred,
    BOOL bWait) throw();
```

### <a name="parameters"></a>Parâmetros

*pOverlapped*<br/>
A estrutura sobreposta. Ver *lpOverlapped* na [GetOverlappedResult](/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) no SDK do Windows.

*dwBytesTransferred*<br/>
Os bytes transferidos. Ver *lpNumberOfBytesTransferred* em `GetOverlappedResult`.

*bWait*<br/>
A opção de espera. Ver *bWait* em `GetOverlappedResult`.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [GetOverlappedResult](/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) para obter os resultados de uma operação sobreposta no arquivo.

##  <a name="getposition"></a>  CAtlFile::GetPosition

Chame esse método para obter a posição atual do ponteiro de arquivo.

```
HRESULT GetPosition(ULONGLONG& nPos) const throw();
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
A posição em bytes.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [SetFilePointer](/windows/desktop/api/fileapi/nf-fileapi-setfilepointer) para obter a posição atual do ponteiro de arquivo.

##  <a name="getsize"></a>  CAtlFile::GetSize

Chame esse método para obter o tamanho em bytes do arquivo.

```
HRESULT GetSize(ULONGLONG& nLen) const throw();
```

### <a name="parameters"></a>Parâmetros

*nLen*<br/>
O número de bytes no arquivo.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [GetFileSize](/windows/desktop/api/fileapi/nf-fileapi-getfilesize) para obter o tamanho em bytes do arquivo.

##  <a name="lockrange"></a>  CAtlFile::LockRange

Chame esse método para bloquear uma região no arquivo para impedir que outros processos de acessá-la.

```
HRESULT LockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
A posição no arquivo em que o bloqueio deve começar.

*nCount*<br/>
O comprimento do intervalo de bytes a ser bloqueado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [arquivo](/windows/desktop/api/fileapi/nf-fileapi-lockfile) bloquear uma região no arquivo. Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas não há regiões sobrepostas são permitidos. Quando você desbloqueia uma região, usando [CAtlFile::UnlockRange](#unlockrange), o intervalo de bytes deve corresponder exatamente à região que foi bloqueado anteriormente. `LockRange` não mescla regiões adjacentes; Se duas regiões bloqueadas forem adjacentes, você deve desbloquear cada uma separadamente.

##  <a name="m_ptm"></a>  CAtlFile::m_pTM

Ponteiro para um `CAtlTransactionManager` objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

##  <a name="read"></a>  CAtlFile::Read

Chame esse método para ler dados de um arquivo começando na posição indicada pelo ponteiro de arquivo.

```
HRESULT Read(
    LPVOID pBuffer,
    DWORD nBufSize) throw();

HRESULT Read(
    LPVOID pBuffer,
    DWORD nBufSize,
    DWORD& nBytesRead) throw();

HRESULT Read(
    LPVOID pBuffer,
    DWORD nBufSize,
    LPOVERLAPPED pOverlapped) throw();

HRESULT Read(
    LPVOID pBuffer,
    DWORD nBufSize,
    LPOVERLAPPED pOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE pfnCompletionRoutine) throw();
```

### <a name="parameters"></a>Parâmetros

*pBuffer*<br/>
Ponteiro para o buffer que receberá os dados lidos do arquivo.

*nBufSize*<br/>
O tamanho do buffer em bytes.

*nBytesRead*<br/>
O número de bytes lidos.

*pOverlapped*<br/>
A estrutura sobreposta. Ver *lpOverlapped* na [ReadFile](/windows/desktop/api/fileapi/nf-fileapi-readfile) no SDK do Windows.

*pfnCompletionRoutine*<br/>
A rotina de conclusão. Ver *lpCompletionRoutine* na [ReadFileEx](/windows/desktop/api/fileapi/nf-fileapi-readfileex) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

As primeiras três formas de chamar [ReadFile](/windows/desktop/api/fileapi/nf-fileapi-readfile), a última [ReadFileEx](/windows/desktop/api/fileapi/nf-fileapi-readfileex) para ler dados do arquivo. Use [CAtlFile::Seek](#seek) para mover o ponteiro do arquivo.

##  <a name="seek"></a>  CAtlFile::Seek

Chame esse método para mover o ponteiro do arquivo do arquivo.

```
HRESULT Seek(
    LONGLONG nOffset,
    DWORD dwFrom = FILE_CURRENT) throw();
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
O deslocamento do ponto de partida fornecido pelo *dwFrom*.

*dwFrom*<br/>
O ponto de partida (FILE_BEGIN, FILE_CURRENT ou FILE_END).

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [SetFilePointer](/windows/desktop/api/fileapi/nf-fileapi-setfilepointer) para mover o ponteiro do arquivo.

##  <a name="setsize"></a>  CAtlFile::SetSize

Chame esse método para definir o tamanho do arquivo.

```
HRESULT SetSize(ULONGLONG nNewLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nNewLen*<br/>
O novo tamanho do arquivo em bytes.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [SetFilePointer](/windows/desktop/api/fileapi/nf-fileapi-setfilepointer) e [SetEndOfFile](/windows/desktop/api/fileapi/nf-fileapi-setendoffile) para definir o tamanho do arquivo. No retorno, o ponteiro do arquivo é posicionado no final do arquivo.

##  <a name="unlockrange"></a>  CAtlFile::UnlockRange

Chame esse método para desbloquear uma região do arquivo.

```
HRESULT UnlockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
A posição no arquivo em que o desbloqueio deve começar.

*nCount*<br/>
O comprimento do intervalo de bytes seja desbloqueada.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas [UnlockFile](/windows/desktop/api/fileapi/nf-fileapi-unlockfile) para desbloquear uma região do arquivo.

##  <a name="write"></a>  CAtlFile::Write

Chame esse método para gravar dados no arquivo começando na posição indicada pelo ponteiro de arquivo.

```
HRESULT Write(
    LPCVOID pBuffer,
    DWORD nBufSize,
    LPOVERLAPPED pOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE pfnCompletionRoutine) throw();

HRESULT Write(
    LPCVOID pBuffer,
    DWORD nBufSize,
    DWORD* pnBytesWritten = NULL) throw();

HRESULT Write(
    LPCVOID pBuffer,
    DWORD nBufSize,
    LPOVERLAPPED pOverlapped) throw();
```

### <a name="parameters"></a>Parâmetros

*pBuffer*<br/>
O buffer que contém os dados a serem gravados no arquivo.

*nBufSize*<br/>
O número de bytes a serem transferidos do buffer.

*pOverlapped*<br/>
A estrutura sobreposta. Ver *lpOverlapped* na [WriteFile](/windows/desktop/api/fileapi/nf-fileapi-writefile) no SDK do Windows.

*pfnCompletionRoutine*<br/>
A rotina de conclusão. Ver *lpCompletionRoutine* na [WriteFileEx](/windows/desktop/api/fileapi/nf-fileapi-writefileex) no SDK do Windows.

*pnBytesWritten*<br/>
Os bytes gravados.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

As primeiras três formas de chamar [WriteFile](/windows/desktop/api/fileapi/nf-fileapi-writefile), as chamadas a última [WriteFileEx](/windows/desktop/api/fileapi/nf-fileapi-writefileex) para gravar dados no arquivo. Use [CAtlFile::Seek](#seek) para mover o ponteiro do arquivo.

## <a name="see-also"></a>Consulte também

[Exemplo de letreiro](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CHandle](../../atl/reference/chandle-class.md)
