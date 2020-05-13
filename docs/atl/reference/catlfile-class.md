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
ms.openlocfilehash: 83a0a89bf6e2e21be33cf8c6003228111eff5394
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168105"
---
# <a name="catlfile-class"></a>Classe CAtlFile

Essa classe fornece um wrapper fino em relação à API de manipulação de arquivos do Windows.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[CAtlFile:: criar](#create)|Chame esse método para criar ou abrir um arquivo.|
|[CAtlFile:: flush](#flush)|Chame esse método para limpar os buffers do arquivo e fazer com que todos os dados armazenados em buffer sejam gravados no arquivo.|
|[CAtlFile:: GetOverlappedResult](#getoverlappedresult)|Chame esse método para obter os resultados de uma operação sobreposta no arquivo.|
|[CAtlFile:: GetPosition](#getposition)|Chame esse método para obter a posição do ponteiro de arquivo atual do arquivo.|
|[CAtlFile::GetSize](#getsize)|Chame esse método para obter o tamanho em bytes do arquivo.|
|[CAtlFile::LockRange](#lockrange)|Chame esse método para bloquear uma região no arquivo para impedir que outros processos o acessem.|
|[CAtlFile:: ler](#read)|Chame esse método para ler dados de um arquivo que começa na posição indicada pelo ponteiro do arquivo.|
|[CAtlFile:: Seek](#seek)|Chame esse método para mover o ponteiro de arquivo do arquivo.|
|[CAtlFile:: SetSize](#setsize)|Chame esse método para definir o tamanho do arquivo.|
|[CAtlFile::UnlockRange](#unlockrange)|Chame esse método para desbloquear uma região do arquivo.|
|[CAtlFile:: Write](#write)|Chame esse método para gravar dados no arquivo, começando na posição indicada pelo ponteiro do arquivo.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFile:: m_pTM](#m_ptm)|Ponteiro para `CAtlTransactionManager` objeto|

## <a name="remarks"></a>Comentários

Use essa classe quando as necessidades de manipulação de arquivos forem relativamente simples, mas mais abstração do que a API do Windows fornece é necessária, sem incluir dependências do MFC.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CHandle](../../atl/reference/chandle-class.md)

`CAtlFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile. h

## <a name="catlfilecatlfile"></a><a name="catlfile"></a>CAtlFile::CAtlFile

O construtor.

```cpp
CAtlFile() throw();
CAtlFile(CAtlTransactionManager* pTM = NULL) throw();
CAtlFile(CAtlFile& file) throw();
explicit CAtlFile(HANDLE hFile) throw();
```

### <a name="parameters"></a>Parâmetros

*Grupo*<br/>
O objeto de arquivo.

*hFile*<br/>
O identificador do arquivo.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

O construtor de cópia transfere a propriedade do identificador de arquivo `CAtlFile` do objeto original para o objeto recém-criado.

## <a name="catlfilecreate"></a><a name="create"></a>CAtlFile:: criar

Chame esse método para criar ou abrir um arquivo.

```cpp
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
O nome do arquivo.

*dwDesiredAccess*<br/>
O acesso desejado. Consulte *dwDesiredAccess* em [CreateFile](/windows/win32/api/fileapi/nf-fileapi-createfilew) no SDK do Windows.

*dwShareMode*<br/>
O modo de compartilhamento. Consulte *dwShareMode* em `CreateFile`.

*dwCreationDisposition*<br/>
A disposição da criação. Consulte *dwCreationDisposition* em `CreateFile`.

*dwFlagsAndAttributes*<br/>
Os sinalizadores e atributos. Consulte *dwFlagsAndAttributes* em `CreateFile`.

*lpsa*<br/>
Os atributos de segurança. Consulte *lpSecurityAttributes* em `CreateFile`.

*hTemplateFile*<br/>
O arquivo de modelo. Consulte *hTemplateFile* em `CreateFile`.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [CreateFile](/windows/win32/api/fileapi/nf-fileapi-createfilew) para criar ou abrir o arquivo.

## <a name="catlfileflush"></a><a name="flush"></a>CAtlFile:: flush

Chame esse método para limpar os buffers do arquivo e fazer com que todos os dados armazenados em buffer sejam gravados no arquivo.

```cpp
HRESULT Flush() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [FlushFileBuffers](/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers) para liberar dados armazenados em buffer para o arquivo.

## <a name="catlfilegetoverlappedresult"></a><a name="getoverlappedresult"></a>CAtlFile:: GetOverlappedResult

Chame esse método para obter os resultados de uma operação sobreposta no arquivo.

```cpp
HRESULT GetOverlappedResult(
    LPOVERLAPPED pOverlapped,
    DWORD& dwBytesTransferred,
    BOOL bWait) throw();
```

### <a name="parameters"></a>Parâmetros

*pOverlapped*<br/>
A estrutura sobreposta. Consulte *lpOverlapped* em [GetOverlappedResult](/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) no SDK do Windows.

*dwBytesTransferred*<br/>
Os bytes transferidos. Consulte *lpNumberOfBytesTransferred* em `GetOverlappedResult`.

*bWait*<br/>
A opção de espera. Consulte *bWait* em `GetOverlappedResult`.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [GetOverlappedResult](/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) para obter os resultados de uma operação sobreposta no arquivo.

## <a name="catlfilegetposition"></a><a name="getposition"></a>CAtlFile:: GetPosition

Chame esse método para obter a posição atual do ponteiro do arquivo.

```cpp
HRESULT GetPosition(ULONGLONG& nPos) const throw();
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
A posição em bytes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [SetFilePointer](/windows/win32/api/fileapi/nf-fileapi-setfilepointer) para obter a posição atual do ponteiro do arquivo.

## <a name="catlfilegetsize"></a><a name="getsize"></a>CAtlFile::GetSize

Chame esse método para obter o tamanho em bytes do arquivo.

```cpp
HRESULT GetSize(ULONGLONG& nLen) const throw();
```

### <a name="parameters"></a>Parâmetros

*nLen*<br/>
O número de bytes no arquivo.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [GetFiles](/windows/win32/api/fileapi/nf-fileapi-getfilesize) para obter o tamanho em bytes do arquivo.

## <a name="catlfilelockrange"></a><a name="lockrange"></a>CAtlFile::LockRange

Chame esse método para bloquear uma região no arquivo para impedir que outros processos o acessem.

```cpp
HRESULT LockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
A posição no arquivo em que o bloqueio deve começar.

*nCount*<br/>
O comprimento do intervalo de bytes a ser bloqueado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [lockfile](/windows/win32/api/fileapi/nf-fileapi-lockfile) para bloquear uma região no arquivo. Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas não são permitidas regiões sobrepostas. Quando você desbloqueia uma região, usando [CAtlFile:: UnlockRange](#unlockrange), o intervalo de bytes deve corresponder exatamente à região que foi bloqueada anteriormente. `LockRange`não mescla regiões adjacentes; se duas regiões bloqueadas estiverem adjacentes, você deverá desbloquear cada uma separadamente.

## <a name="catlfilem_ptm"></a><a name="m_ptm"></a>CAtlFile:: m_pTM

Ponteiro para um `CAtlTransactionManager` objeto.

```cpp
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

## <a name="catlfileread"></a><a name="read"></a>CAtlFile:: ler

Chame esse método para ler dados de um arquivo que começa na posição indicada pelo ponteiro do arquivo.

```cpp
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
A estrutura sobreposta. Consulte *lpOverlapped* em [ReadFile](/windows/win32/api/fileapi/nf-fileapi-readfile) no SDK do Windows.

*pfnCompletionRoutine*<br/>
A rotina de conclusão. Consulte *lpCompletionRoutine* em [ReadFileEx](/windows/win32/api/fileapi/nf-fileapi-readfileex) na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Os três primeiros formulários chamam [ReadFile](/windows/win32/api/fileapi/nf-fileapi-readfile), o último [ReadFileEx](/windows/win32/api/fileapi/nf-fileapi-readfileex) para ler os dados do arquivo. Use [CAtlFile:: Seek](#seek) para mover o ponteiro do arquivo.

## <a name="catlfileseek"></a><a name="seek"></a>CAtlFile:: Seek

Chame esse método para mover o ponteiro de arquivo do arquivo.

```cpp
HRESULT Seek(
    LONGLONG nOffset,
    DWORD dwFrom = FILE_CURRENT) throw();
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
O deslocamento do ponto de partida fornecido por *dwFrom*.

*dwFrom*<br/>
O ponto de partida (FILE_BEGIN, FILE_CURRENT ou FILE_END).

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [SetFilePointer](/windows/win32/api/fileapi/nf-fileapi-setfilepointer) para mover o ponteiro do arquivo.

## <a name="catlfilesetsize"></a><a name="setsize"></a>CAtlFile:: SetSize

Chame esse método para definir o tamanho do arquivo.

```cpp
HRESULT SetSize(ULONGLONG nNewLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nNewLen*<br/>
O novo comprimento do arquivo em bytes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama [SetFilePointer](/windows/win32/api/fileapi/nf-fileapi-setfilepointer) e [SetEndOfFile](/windows/win32/api/fileapi/nf-fileapi-setendoffile) para definir o tamanho do arquivo. No retorno, o ponteiro do arquivo é posicionado no final do arquivo.

## <a name="catlfileunlockrange"></a><a name="unlockrange"></a>CAtlFile::UnlockRange

Chame esse método para desbloquear uma região do arquivo.

```cpp
HRESULT UnlockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
A posição no arquivo em que o desbloqueio deve começar.

*nCount*<br/>
O comprimento do intervalo de bytes a ser desbloqueado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama o [desbloqueiofile](/windows/win32/api/fileapi/nf-fileapi-unlockfile) para desbloquear uma região do arquivo.

## <a name="catlfilewrite"></a><a name="write"></a>CAtlFile:: Write

Chame esse método para gravar dados no arquivo, começando na posição indicada pelo ponteiro do arquivo.

```cpp
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
A estrutura sobreposta. Consulte *lpOverlapped* em [writefile](/windows/win32/api/fileapi/nf-fileapi-writefile) no SDK do Windows.

*pfnCompletionRoutine*<br/>
A rotina de conclusão. Consulte *lpCompletionRoutine* em [WriteFileEx](/windows/win32/api/fileapi/nf-fileapi-writefileex) na SDK do Windows.

*pnBytesWritten*<br/>
Os bytes gravados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Os três primeiros formulários chamam [WriteFile](/windows/win32/api/fileapi/nf-fileapi-writefile), o último chama [WriteFileEx](/windows/win32/api/fileapi/nf-fileapi-writefileex) para gravar dados no arquivo. Use [CAtlFile:: Seek](#seek) para mover o ponteiro do arquivo.

## <a name="see-also"></a>Confira também

[Exemplo de letreiro](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CHandle](../../atl/reference/chandle-class.md)
