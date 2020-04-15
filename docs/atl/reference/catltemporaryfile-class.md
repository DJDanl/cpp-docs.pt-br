---
title: Classe catltemporaryfile
ms.date: 11/04/2016
f1_keywords:
- CAtlTemporaryFile
- ATLFILE/ATL::CAtlTemporaryFile
- ATLFILE/ATL::CAtlTemporaryFile::CAtlTemporaryFile
- ATLFILE/ATL::CAtlTemporaryFile::Close
- ATLFILE/ATL::CAtlTemporaryFile::Create
- ATLFILE/ATL::CAtlTemporaryFile::Flush
- ATLFILE/ATL::CAtlTemporaryFile::GetPosition
- ATLFILE/ATL::CAtlTemporaryFile::GetSize
- ATLFILE/ATL::CAtlTemporaryFile::HandsOff
- ATLFILE/ATL::CAtlTemporaryFile::HandsOn
- ATLFILE/ATL::CAtlTemporaryFile::LockRange
- ATLFILE/ATL::CAtlTemporaryFile::Read
- ATLFILE/ATL::CAtlTemporaryFile::Seek
- ATLFILE/ATL::CAtlTemporaryFile::SetSize
- ATLFILE/ATL::CAtlTemporaryFile::TempFileName
- ATLFILE/ATL::CAtlTemporaryFile::UnlockRange
- ATLFILE/ATL::CAtlTemporaryFile::Write
helpviewer_keywords:
- CAtlTemporaryFile class
ms.assetid: 05f0f2a5-94f6-4594-8dae-b114292ff5f9
ms.openlocfilehash: 605e4bcbe7208b18d8d1a50507e8e142a93bde5e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321316"
---
# <a name="catltemporaryfile-class"></a>Classe catltemporaryfile

Esta classe fornece métodos para a criação e o uso de um arquivo temporário.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlTemporaryFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile)|O construtor.|
|[CAtlTemporaryFile::~CAtlTemporaryFile](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlTemporaryFile::Close](#close)|Chame este método para fechar um arquivo temporário e excluir seu conteúdo ou armazená-lo sob o nome do arquivo especificado.|
|[CAtlTemporaryFile::Criar](#create)|Chame este método para criar um arquivo temporário.|
|[CAtlTemporaryFile::Flush](#flush)|Chame este método para forçar que quaisquer dados restantes no buffer de arquivo sejam gravados no arquivo temporário.|
|[CAtlTemporaryFile::GetPosition](#getposition)|Chame este método para obter a posição atual do ponteiro do arquivo.|
|[CAtlTemporaryFile::GetSize](#getsize)|Chame este método para obter o tamanho em bytes do arquivo temporário.|
|[CAtlTemporaryFile::HandsOff](#handsoff)|Chame este método para desassociar `CAtlTemporaryFile` o arquivo do objeto.|
|[CAtlTemporaryFile::HandsOn](#handson)|Chame este método para abrir um arquivo temporário existente e posicionar o ponteiro no final do arquivo.|
|[CAtlTemporaryFile::LockRange](#lockrange)|Chame este método para bloquear uma região no arquivo para evitar que outros processos o acessem.|
|[CAtlTemporaryFile::Read](#read)|Chame este método para ler dados do arquivo temporário a partir da posição indicada pelo ponteiro do arquivo.|
|[CAtlTemporaryFile::Buscar](#seek)|Chame este método para mover o ponteiro de arquivo do arquivo temporário.|
|[CAtlTemporaryFile::SetSize](#setsize)|Chame este método para definir o tamanho do arquivo temporário.|
|[CAtlTemporaryFile::TempFileName](#tempfilename)|Chame este método para retornar o nome do arquivo temporário.|
|[CAtlTemporaryFile::UnlockRange](#unlockrange)|Chame este método para desbloquear uma região do arquivo temporário.|
|[CAtlTemporaryFile::Write](#write)|Chame este método para gravar dados para o arquivo temporário a partir da posição indicada pelo ponteiro do arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlTemporaryFile::manipulação do operador](#operator_handle)|Devolve uma alça ao arquivo temporário.|

## <a name="remarks"></a>Comentários

`CAtlTemporaryFile`facilita a criação e o uso de um arquivo temporário. O arquivo é automaticamente nomeado, aberto, fechado e excluído. Se o conteúdo do arquivo for necessário após o fechamento do arquivo, eles podem ser salvos em um novo arquivo com um nome especificado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile.h

## <a name="example"></a>Exemplo

Veja o exemplo de [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).

## <a name="catltemporaryfilecatltemporaryfile"></a><a name="catltemporaryfile"></a>CAtlTemporaryFile::CAtlTemporaryFile

O construtor.

```
CAtlTemporaryFile() throw();
```

### <a name="remarks"></a>Comentários

Um arquivo não é realmente aberto até que uma chamada seja feita para [CAtlTemporaryFile::Create](#create).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#73](../../atl/codesnippet/cpp/catltemporaryfile-class_1.cpp)]

## <a name="catltemporaryfilecatltemporaryfile"></a><a name="dtor"></a>CAtlTemporaryFile::~CAtlTemporaryFile

O destruidor.

```
~CAtlTemporaryFile() throw();
```

### <a name="remarks"></a>Comentários

O destruidor chama [CAtlTemporaryFile:::Close](#close).

## <a name="catltemporaryfileclose"></a><a name="close"></a>CAtlTemporaryFile::Close

Chame este método para fechar um arquivo temporário e excluir seu conteúdo ou armazená-lo sob o nome do arquivo especificado.

```
HRESULT Close(LPCTSTR szNewName = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*szNewName*<br/>
O nome do novo arquivo para armazenar o conteúdo do arquivo temporário. Se esse argumento for NULO, o conteúdo do arquivo temporário será excluído.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).

## <a name="catltemporaryfilecreate"></a><a name="create"></a>CAtlTemporaryFile::Criar

Chame este método para criar um arquivo temporário.

```
HRESULT Create(LPCTSTR pszDir = NULL, DWORD dwDesiredAccess = GENERIC_WRITE) throw();
```

### <a name="parameters"></a>Parâmetros

*pszDir*<br/>
O caminho para o arquivo temporário. Se isso for NULO, [o GetTempPath](/windows/win32/api/fileapi/nf-fileapi-gettemppathw) será chamado para atribuir um caminho.

*dwDesiredAccess*<br/>
O acesso desejado. Consulte *dwDesiredAccess* in [CreateFile](/windows/win32/api/fileapi/nf-fileapi-createfilew) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).

## <a name="catltemporaryfileflush"></a><a name="flush"></a>CAtlTemporaryFile::Flush

Chame este método para forçar que quaisquer dados restantes no buffer de arquivo sejam gravados no arquivo temporário.

```
HRESULT Flush() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Semelhante a [CAtlTemporaryFile::HandsOff](#handsoff), exceto que o arquivo não está fechado.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).

## <a name="catltemporaryfilegetposition"></a><a name="getposition"></a>CAtlTemporaryFile::GetPosition

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

Para alterar a posição do ponteiro do arquivo, use [CAtlTemporaryFile::Seek](#seek).

## <a name="catltemporaryfilegetsize"></a><a name="getsize"></a>CAtlTemporaryFile::GetSize

Chame este método para obter o tamanho em bytes do arquivo temporário.

```
HRESULT GetSize(ULONGLONG& nLen) const throw();
```

### <a name="parameters"></a>Parâmetros

*nLen*<br/>
O número de bytes no arquivo.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catltemporaryfilehandsoff"></a><a name="handsoff"></a>CAtlTemporaryFile::HandsOff

Chame este método para desassociar `CAtlTemporaryFile` o arquivo do objeto.

```
HRESULT HandsOff() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

`HandsOff`e [CAtlTemporaryFile::HandsOn](#handson) são usados para desassociar o arquivo do objeto e reanexá-lo se necessário. `HandsOff`forçará todos os dados restantes no buffer de arquivo a serem gravados no arquivo temporário e, em seguida, fechará o arquivo. Se você quiser fechar e excluir o arquivo permanentemente, ou se você quiser fechar e reter o conteúdo do arquivo com um nome determinado, use [CAtlTemporaryFile::Close](#close).

## <a name="catltemporaryfilehandson"></a><a name="handson"></a>CAtlTemporaryFile::HandsOn

Chame este método para abrir um arquivo temporário existente e posicionar o ponteiro no final do arquivo.

```
HRESULT HandsOn() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

[CAtlTemporaryFile::HandsOff](#handsoff) `HandsOn` e são usados para desassociar o arquivo do objeto e reanexá-lo se necessário.

## <a name="catltemporaryfilelockrange"></a><a name="lockrange"></a>CAtlTemporaryFile::LockRange

Chame este método para bloquear uma região no arquivo temporário para evitar que outros processos o acessem.

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

Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas não são permitidas regiões sobrepostas. Para desbloquear uma região com sucesso, use [CAtlTemporaryFile::UnlockRange](#unlockrange), garantindo que o intervalo de bytes corresponda exatamente à região que estava bloqueada anteriormente. `LockRange`não mescla regiões adjacentes; se duas regiões bloqueadas estiverem adjacentes, você deve desbloquear cada uma separadamente.

## <a name="catltemporaryfileoperator-handle"></a><a name="operator_handle"></a>CAtlTemporaryFile::manipulação do operador

Devolve uma alça ao arquivo temporário.

```
operator HANDLE() throw();
```

## <a name="catltemporaryfileread"></a><a name="read"></a>CAtlTemporaryFile::Read

Chame este método para ler dados do arquivo temporário a partir da posição indicada pelo ponteiro do arquivo.

```
HRESULT Read(
    LPVOID pBuffer,
    DWORD nBufSize,
    DWORD& nBytesRead) throw();
```

### <a name="parameters"></a>Parâmetros

*pBuffer*<br/>
Ponteiro para o buffer que receberá os dados lidos do arquivo.

*nBufSize*<br/>
O tamanho do buffer em bytes.

*nBytesRead*<br/>
O número de bytes lidos.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chamadas [CAtlFile:::Read](../../atl/reference/catlfile-class.md#read). Para alterar a posição do ponteiro do arquivo, ligue [para CAtlTemporaryFile:::Buscar](#seek).

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).

## <a name="catltemporaryfileseek"></a><a name="seek"></a>CAtlTemporaryFile::Buscar

Chame este método para mover o ponteiro de arquivo do arquivo temporário.

```
HRESULT Seek(LONGLONG nOffset, DWORD dwFrom = FILE_CURRENT) throw();
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
O deslocamento, em bytes, do ponto de partida dado por *dwFrom.*

*Dwfrom*<br/>
O ponto de partida (FILE_BEGIN, FILE_CURRENT ou FILE_END).

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chamadas [CAtlFile:::Buscar](../../atl/reference/catlfile-class.md#seek). Para obter a posição atual do ponteiro do arquivo, ligue [para CAtlTemporaryFile::GetPosition](#getposition).

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).

## <a name="catltemporaryfilesetsize"></a><a name="setsize"></a>CAtlTemporaryFile::SetSize

Chame este método para definir o tamanho do arquivo temporário.

```
HRESULT SetSize(ULONGLONG nNewLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nNewLen*<br/>
O novo comprimento do arquivo em bytes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chamadas [CAtlFile::SetSize](../../atl/reference/catlfile-class.md#setsize). No retorno, o ponteiro do arquivo é posicionado no final do arquivo.

## <a name="catltemporaryfiletempfilename"></a><a name="tempfilename"></a>CAtlTemporaryFile::TempFileName

Chame este método para retornar o nome do arquivo temporário.

```
LPCTSTR TempFileName() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o LPCTSTR apontando para o nome do arquivo.

### <a name="remarks"></a>Comentários

O nome do arquivo é gerado em [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile) com uma chamada para a função [GetTempFile](/windows/win32/api/fileapi/nf-fileapi-gettempfilenamew)Windows SDK. A extensão do arquivo será sempre "TFR" para o arquivo temporário.

## <a name="catltemporaryfileunlockrange"></a><a name="unlockrange"></a>CAtlTemporaryFile::UnlockRange

Chame este método para desbloquear uma região do arquivo temporário.

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

Chamadas [CAtlFile::UnlockRange](../../atl/reference/catlfile-class.md#unlockrange).

## <a name="catltemporaryfilewrite"></a><a name="write"></a>CAtlTemporaryFile::Write

Chame este método para gravar dados para o arquivo temporário a partir da posição indicada pelo ponteiro do arquivo.

```
HRESULT Write(
    LPCVOID pBuffer,
    DWORD nBufSize,
    DWORD* pnBytesWritten = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*pBuffer*<br/>
O buffer contendo os dados a serem gravados no arquivo.

*nBufSize*<br/>
O número de bytes a serem transferidos do buffer.

*pnBytesEscrito*<br/>
O número de bytes gravados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chamadas [CAtlFile:::Write](../../atl/reference/catlfile-class.md#write).

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CAtlFile](../../atl/reference/catlfile-class.md)
