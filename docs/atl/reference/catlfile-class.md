---
title: Classe CAtlFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CAtlFile class
ms.assetid: 93ed160b-af2a-448c-9cbe-e5fa46c199bb
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5ba8aa0bc5544d8d541fecb87e2eb0108c2c5ebd
ms.lasthandoff: 02/25/2017

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
|[CAtlFile::Flush](#flush)|Chame esse método para limpar os buffers para o arquivo e fazer com que todos os dados armazenados em buffer a ser gravado no arquivo.|  
|[CAtlFile::GetOverlappedResult](#getoverlappedresult)|Chame esse método para obter os resultados de uma operação sobreposta no arquivo.|  
|[CAtlFile::GetPosition](#getposition)|Chame esse método para obter a posição do ponteiro de arquivo atual do arquivo.|  
|[CAtlFile::GetSize](#getsize)|Chame esse método para obter o tamanho em bytes do arquivo.|  
|[CAtlFile::LockRange](#lockrange)|Chame esse método para bloquear uma região do arquivo para impedir que outros processos de acessá-la.|  
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
 Use esta classe quando as necessidades de manipulação de arquivo são relativamente simples, mas mais de abstração que fornece a API do Windows é necessária, sem incluir dependências do MFC.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CHandle](../../atl/reference/chandle-class.md)  
  
 `CAtlFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlfile.h  
  
##  <a name="catlfile"></a>CAtlFile::CAtlFile  
 O construtor.  
  
```
CAtlFile() throw();
CAtlFile(CAtlTransactionManager* pTM = NULL) throw();
CAtlFile(CAtlFile& file) throw();
explicit CAtlFile(HANDLE hFile) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `file`  
 O objeto de arquivo.  
  
 `hFile`  
 O identificador de arquivo.  
  
 `pTM`  
 Ponteiro para objeto CAtlTransactionManager  
  
### <a name="remarks"></a>Comentários  
 O construtor de cópia transfere a propriedade do identificador do arquivo do original `CAtlFile` objeto para o objeto recém construído.  
  
##  <a name="create"></a>CAtlFile::Create  
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
 *szFilename*  
 O nome de arquivo.  
  
 `dwDesiredAccess`  
 O acesso desejado. Consulte `dwDesiredAccess` na [CreateFile](http://msdn.microsoft.com/library/windows/desktop/aa363858) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwShareMode`  
 O modo de compartilhamento. Consulte `dwShareMode` na **CreateFile**.  
  
 `dwCreationDisposition`  
 A disposição de criação. Consulte `dwCreationDisposition` na **CreateFile**.  
  
 `dwFlagsAndAttributes`  
 Os sinalizadores e atributos. Consulte `dwFlagsAndAttributes` na **CreateFile**.  
  
 `lpsa`  
 Os atributos de segurança. Consulte *lpSecurityAttributes* na **CreateFile**.  
  
 `hTemplateFile`  
 O arquivo de modelo. Consulte `hTemplateFile` na **CreateFile**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CreateFile](http://msdn.microsoft.com/library/windows/desktop/aa363858) para criar ou abrir o arquivo.  
  
##  <a name="flush"></a>CAtlFile::Flush  
 Chame esse método para limpar os buffers para o arquivo e fazer com que todos os dados armazenados em buffer a ser gravado no arquivo.  
  
```
HRESULT Flush() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [FlushFileBuffers](http://msdn.microsoft.com/library/windows/desktop/aa364439) liberar dados armazenados em buffer para o arquivo.  
  
##  <a name="getoverlappedresult"></a>CAtlFile::GetOverlappedResult  
 Chame esse método para obter os resultados de uma operação sobreposta no arquivo.  
  
```
HRESULT GetOverlappedResult(
    LPOVERLAPPED pOverlapped,
    DWORD& dwBytesTransferred,
    BOOL bWait) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOverlapped`  
 A estrutura sobreposta. Consulte `lpOverlapped` na [GetOverlappedResult](http://msdn.microsoft.com/library/windows/desktop/ms683209) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 *dwBytesTransferred*  
 Os bytes transferidos. Consulte *lpNumberOfBytesTransferred* em `GetOverlappedResult`.  
  
 `bWait`  
 A opção de espera. See `bWait` in `GetOverlappedResult`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [GetOverlappedResult](http://msdn.microsoft.com/library/windows/desktop/ms683209) para obter os resultados de uma operação sobreposta no arquivo.  
  
##  <a name="getposition"></a>CAtlFile::GetPosition  
 Chame esse método para obter a posição do ponteiro de arquivo atual.  
  
```
HRESULT GetPosition(ULONGLONG& nPos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 A posição em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [SetFilePointer](http://msdn.microsoft.com/library/windows/desktop/aa365541) para obter a posição do ponteiro de arquivo atual.  
  
##  <a name="getsize"></a>CAtlFile::GetSize  
 Chame esse método para obter o tamanho em bytes do arquivo.  
  
```
HRESULT GetSize(ULONGLONG& nLen) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLen`  
 O número de bytes no arquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [GetFileSize](http://msdn.microsoft.com/library/windows/desktop/aa364955) para obter o tamanho em bytes do arquivo.  
  
##  <a name="lockrange"></a>CAtlFile::LockRange  
 Chame esse método para bloquear uma região do arquivo para impedir que outros processos de acessá-la.  
  
```
HRESULT LockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 A posição do arquivo onde o bloqueio deve ser iniciada.  
  
 `nCount`  
 O comprimento do intervalo de bytes a serem bloqueados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [arquivo](http://msdn.microsoft.com/library/windows/desktop/aa365202) de bloquear uma região no arquivo. Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas nenhuma região sobreposto é permitido. Quando você desbloqueia uma região, usando [CAtlFile::UnlockRange](#unlockrange), o intervalo de bytes deve corresponder exatamente à região que anteriormente estava bloqueada. `LockRange`não mesclar regiões adjacentes; Se duas regiões bloqueadas são adjacentes, você deverá desbloquear cada um separadamente.  
  
##  <a name="m_ptm"></a>CAtlFile::m_pTM  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
```
CAtlTransactionManager* m_pTM;
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="read"></a>CAtlFile::Read  
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
 `pBuffer`  
 Ponteiro para o buffer que receberá os dados lidos do arquivo.  
  
 `nBufSize`  
 O tamanho do buffer em bytes.  
  
 `nBytesRead`  
 O número de bytes lidos.  
  
 `pOverlapped`  
 A estrutura sobreposta. Consulte `lpOverlapped` na [ReadFile](http://msdn.microsoft.com/library/windows/desktop/aa365467) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `pfnCompletionRoutine`  
 A rotina de conclusão. Consulte *lpCompletionRoutine* na [ReadFileEx](http://msdn.microsoft.com/library/windows/desktop/aa365468) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Os primeiros três formulários chamar [ReadFile](http://msdn.microsoft.com/library/windows/desktop/aa365467), a última [ReadFileEx](http://msdn.microsoft.com/library/windows/desktop/aa365468) para ler dados do arquivo. Use [CAtlFile::Seek](#seek) para mover o ponteiro do arquivo.  
  
##  <a name="seek"></a>CAtlFile::Seek  
 Chame esse método para mover o ponteiro do arquivo do arquivo.  
  
```
HRESULT Seek(
    LONGLONG nOffset,
    DWORD dwFrom = FILE_CURRENT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nOffset`  
 O deslocamento do ponto de partida fornecido pelo `dwFrom`.  
  
 `dwFrom`  
 O ponto de partida (FILE_BEGIN, FILE_CURRENT ou FILE_END).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [SetFilePointer](http://msdn.microsoft.com/library/windows/desktop/aa365541) para mover o ponteiro do arquivo.  
  
##  <a name="setsize"></a>CAtlFile::SetSize  
 Chame esse método para definir o tamanho do arquivo.  
  
```
HRESULT SetSize(ULONGLONG nNewLen) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewLen`  
 O novo tamanho do arquivo em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [SetFilePointer](http://msdn.microsoft.com/library/windows/desktop/aa365541) e [SetEndOfFile](http://msdn.microsoft.com/library/windows/desktop/aa365531) para definir o tamanho do arquivo. No retorno, o ponteiro é posicionado no final do arquivo.  
  
##  <a name="unlockrange"></a>CAtlFile::UnlockRange  
 Chame esse método para desbloquear uma região do arquivo.  
  
```
HRESULT UnlockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 A posição do arquivo onde o desbloqueio deve começar.  
  
 `nCount`  
 O comprimento do intervalo de bytes a ser desbloqueada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [UnlockFile](http://msdn.microsoft.com/library/windows/desktop/aa365715) para desbloquear uma região do arquivo.  
  
##  <a name="write"></a>CAtlFile::Write  
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
 `pBuffer`  
 O buffer que contém os dados a serem gravados no arquivo.  
  
 `nBufSize`  
 O número de bytes a serem transferidos do buffer.  
  
 `pOverlapped`  
 A estrutura sobreposta. Consulte `lpOverlapped` na [WriteFile](http://msdn.microsoft.com/library/windows/desktop/aa365747) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `pfnCompletionRoutine`  
 A rotina de conclusão. Consulte *lpCompletionRoutine* na [WriteFileEx](http://msdn.microsoft.com/library/windows/desktop/aa365748) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `pnBytesWritten`  
 Os bytes gravados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Os primeiros três formulários chamar [WriteFile](http://msdn.microsoft.com/library/windows/desktop/aa365747), as últimas chamadas [WriteFileEx](http://msdn.microsoft.com/library/windows/desktop/aa365748) para gravar dados no arquivo. Use [CAtlFile::Seek](#seek) para mover o ponteiro do arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de letreiro](../../visual-cpp-samples.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CHandle](../../atl/reference/chandle-class.md)

