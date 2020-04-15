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
ms.openlocfilehash: 39f323874ccde5178722235b9beb34c2572407a1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318971"
---
# <a name="catlfile-class"></a>Classe CAtlFile

Esta classe fornece um invólucro fino em torno da API de manipulação de arquivos do Windows.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[CAtlFile::Criar](#create)|Chame este método para criar ou abrir um arquivo.|
|[CAtlFile::Flush](#flush)|Chame este método para limpar os buffers para o arquivo e fazer com que todos os dados protegidos sejam gravados no arquivo.|
|[CAtlFile::GetSobreadoResultado](#getoverlappedresult)|Chame este método para obter os resultados de uma operação sobreposta no arquivo.|
|[CAtlFile::GetPosition](#getposition)|Chame este método para obter a posição atual do ponteiro do arquivo a partir do arquivo.|
|[CAtlFile::GetSize](#getsize)|Chame este método para obter o tamanho em bytes do arquivo.|
|[CAtlFile::LockRange](#lockrange)|Chame este método para bloquear uma região no arquivo para evitar que outros processos o acessem.|
|[CAtlFile::Read](#read)|Chame este método para ler dados de um arquivo que começa na posição indicada pelo ponteiro do arquivo.|
|[CAtlFile::Buscar](#seek)|Chame este método para mover o ponteiro de arquivo do arquivo.|
|[CAtlFile::SetSize](#setsize)|Chame este método para definir o tamanho do arquivo.|
|[CAtlFile::UnlockRange](#unlockrange)|Chame este método para desbloquear uma região do arquivo.|
|[CAtlFile::Write](#write)|Chame este método para gravar dados para o arquivo a partir da posição indicada pelo ponteiro do arquivo.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFile::m_pTM](#m_ptm)|Ponteiro `CAtlTransactionManager` para objeto|

## <a name="remarks"></a>Comentários

Use esta classe quando as necessidades de manipulação de arquivos são relativamente simples, mas é necessário mais abstração do que a API do Windows fornece, sem incluir dependências de MFC.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Chandle](../../atl/reference/chandle-class.md)

`CAtlFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile.h

## <a name="catlfilecatlfile"></a><a name="catlfile"></a>CAtlFile::CAtlFile

O construtor.

```
CAtlFile() throw();
CAtlFile(CAtlTransactionManager* pTM = NULL) throw();
CAtlFile(CAtlFile& file) throw();
explicit CAtlFile(HANDLE hFile) throw();
```

### <a name="parameters"></a>Parâmetros

*Arquivo*<br/>
O objeto de arquivo.

*Hfile*<br/>
O cabo do arquivo.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

O construtor de cópias transfere a `CAtlFile` propriedade da alça do arquivo do objeto original para o objeto recém-construído.

## <a name="catlfilecreate"></a><a name="create"></a>CAtlFile::Criar

Chame este método para criar ou abrir um arquivo.

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
O nome do arquivo.

*dwDesiredAccess*<br/>
O acesso desejado. Consulte *dwDesiredAccess* in [CreateFile](/windows/win32/api/fileapi/nf-fileapi-createfilew) no Windows SDK.

*Dwsharemode*<br/>
O modo de compartilhar. Consulte *dwShareMode* em `CreateFile`.

*Dwcreationdisposition*<br/>
A disposição de criação. Consulte *dwCreationDisposition* in `CreateFile`.

*Dwflagsandattributes*<br/>
As bandeiras e atributos. Consulte *dwFlagsAndAttributes* em `CreateFile`.

*LPSA*<br/>
Os atributos de segurança. Consulte *lpSecurityAttributes* em `CreateFile`.

*hTemplateFile*<br/>
O arquivo de modelo. Consulte *hTemplateFile* in `CreateFile`.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chamadas [CriarArquivo](/windows/win32/api/fileapi/nf-fileapi-createfilew) para criar ou abrir o arquivo.

## <a name="catlfileflush"></a><a name="flush"></a>CAtlFile::Flush

Chame este método para limpar os buffers para o arquivo e fazer com que todos os dados protegidos sejam gravados no arquivo.

```
HRESULT Flush() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama [FlushFileBuffers](/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers) para liberar dados protegidos no arquivo.

## <a name="catlfilegetoverlappedresult"></a><a name="getoverlappedresult"></a>CAtlFile::GetSobreadoResultado

Chame este método para obter os resultados de uma operação sobreposta no arquivo.

```
HRESULT GetOverlappedResult(
    LPOVERLAPPED pOverlapped,
    DWORD& dwBytesTransferred,
    BOOL bWait) throw();
```

### <a name="parameters"></a>Parâmetros

*pSobreposição*<br/>
A estrutura sobreposta. Veja *lpSobreposição* em [GetOverlappedResult](/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) no Windows SDK.

*dwBytestransferidos*<br/>
Os bytes transferidos. Consulte *lpNumberOfBytesTransferido* em `GetOverlappedResult`.

*bAguarde*<br/>
A opção de espera. Veja *bWait* in `GetOverlappedResult`.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chamadas [GetSobrepedResult](/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) para obter os resultados de uma operação sobreposta no arquivo.

## <a name="catlfilegetposition"></a><a name="getposition"></a>CAtlFile::GetPosition

Chame este método para obter a posição atual do ponteiro do arquivo.

```
HRESULT GetPosition(ULONGLONG& nPos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
A posição em bytes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama [SetFilePointer](/windows/win32/api/fileapi/nf-fileapi-setfilepointer) para obter a posição atual do ponteiro do arquivo.

## <a name="catlfilegetsize"></a><a name="getsize"></a>CAtlFile::GetSize

Chame este método para obter o tamanho em bytes do arquivo.

```
HRESULT GetSize(ULONGLONG& nLen) const throw();
```

### <a name="parameters"></a>Parâmetros

*nLen*<br/>
O número de bytes no arquivo.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama [GetFileSize](/windows/win32/api/fileapi/nf-fileapi-getfilesize) para obter o tamanho em bytes do arquivo.

## <a name="catlfilelockrange"></a><a name="lockrange"></a>CAtlFile::LockRange

Chame este método para bloquear uma região no arquivo para evitar que outros processos o acessem.

```
HRESULT LockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
A posição no arquivo onde o bloqueio deve começar.

*Ncount*<br/>
O comprimento do byte a ser bloqueado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama [LockFile](/windows/win32/api/fileapi/nf-fileapi-lockfile) para bloquear uma região no arquivo. Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas não são permitidas regiões sobrepostas. Quando você desbloquear uma região, usando [CAtlFile::UnlockRange](#unlockrange), o intervalo de bytes deve corresponder exatamente à região que estava bloqueada anteriormente. `LockRange`não mescla regiões adjacentes; se duas regiões bloqueadas estiverem adjacentes, você deve desbloquear cada uma separadamente.

## <a name="catlfilem_ptm"></a><a name="m_ptm"></a>CAtlFile::m_pTM

Ponteiro para `CAtlTransactionManager` um objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

## <a name="catlfileread"></a><a name="read"></a>CAtlFile::Read

Chame este método para ler dados de um arquivo que começa na posição indicada pelo ponteiro do arquivo.

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

*pSobreposição*<br/>
A estrutura sobreposta. Veja *lpSobreposição* em [ReadFile](/windows/win32/api/fileapi/nf-fileapi-readfile) no Windows SDK.

*pfnConclusãoRotina*<br/>
A rotina de conclusão. Consulte *lpCompletionRoutine* in [ReadFileEx](/windows/win32/api/fileapi/nf-fileapi-readfileex) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Os três primeiros formulários chamam [ReadFile](/windows/win32/api/fileapi/nf-fileapi-readfile), o último [ReadFileEx](/windows/win32/api/fileapi/nf-fileapi-readfileex) para ler dados do arquivo. Use [CAtlFile:::Procure](#seek) mover o ponteiro do arquivo.

## <a name="catlfileseek"></a><a name="seek"></a>CAtlFile::Buscar

Chame este método para mover o ponteiro de arquivo do arquivo.

```
HRESULT Seek(
    LONGLONG nOffset,
    DWORD dwFrom = FILE_CURRENT) throw();
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
O deslocamento do ponto de partida dado por *dwFrom*.

*Dwfrom*<br/>
O ponto de partida (FILE_BEGIN, FILE_CURRENT ou FILE_END).

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama [SetFilePointer](/windows/win32/api/fileapi/nf-fileapi-setfilepointer) para mover o ponteiro do arquivo.

## <a name="catlfilesetsize"></a><a name="setsize"></a>CAtlFile::SetSize

Chame este método para definir o tamanho do arquivo.

```
HRESULT SetSize(ULONGLONG nNewLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nNewLen*<br/>
O novo comprimento do arquivo em bytes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama [SetFilePointer](/windows/win32/api/fileapi/nf-fileapi-setfilepointer) e [SetEndOfFile](/windows/win32/api/fileapi/nf-fileapi-setendoffile) para definir o tamanho do arquivo. No retorno, o ponteiro do arquivo é posicionado no final do arquivo.

## <a name="catlfileunlockrange"></a><a name="unlockrange"></a>CAtlFile::UnlockRange

Chame este método para desbloquear uma região do arquivo.

```
HRESULT UnlockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
A posição no arquivo onde o desbloqueio deve começar.

*Ncount*<br/>
O comprimento do intervalo de byte a ser desbloqueado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama [UnlockFile](/windows/win32/api/fileapi/nf-fileapi-unlockfile) para desbloquear uma região do arquivo.

## <a name="catlfilewrite"></a><a name="write"></a>CAtlFile::Write

Chame este método para gravar dados para o arquivo a partir da posição indicada pelo ponteiro do arquivo.

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
O buffer contendo os dados a serem gravados no arquivo.

*nBufSize*<br/>
O número de bytes a serem transferidos do buffer.

*pSobreposição*<br/>
A estrutura sobreposta. Veja *lpSobreposição* no [WriteFile](/windows/win32/api/fileapi/nf-fileapi-writefile) no Windows SDK.

*pfnConclusãoRotina*<br/>
A rotina de conclusão. Consulte *lpCompletionRoutine* in [WriteFileEx](/windows/win32/api/fileapi/nf-fileapi-writefileex) no Windows SDK.

*pnBytesEscrito*<br/>
Os bytes escritos.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Os três primeiros formulários chamam [WriteFile](/windows/win32/api/fileapi/nf-fileapi-writefile), as últimas chamadas [WriteFileEx](/windows/win32/api/fileapi/nf-fileapi-writefileex) para gravar dados no arquivo. Use [CAtlFile:::Procure](#seek) mover o ponteiro do arquivo.

## <a name="see-also"></a>Confira também

[Amostra de letreiro](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CHandle](../../atl/reference/chandle-class.md)
