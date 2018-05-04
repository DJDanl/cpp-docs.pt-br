---
title: Classe CAtlTemporaryFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CAtlTemporaryFile class
ms.assetid: 05f0f2a5-94f6-4594-8dae-b114292ff5f9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 49adcb572e355c62e6f21081eb033496e60e2369
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="catltemporaryfile-class"></a>Classe CAtlTemporaryFile
Essa classe fornece métodos para a criação e uso de um arquivo temporário.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlTemporaryFile
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile)|O construtor.|  
|[CAtlTemporaryFile:: ~ CAtlTemporaryFile](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlTemporaryFile::Close](#close)|Chame este método para fechar um arquivo temporário e excluir seu conteúdo ou armazená-los com o nome de arquivo especificado.|  
|[CAtlTemporaryFile::Create](#create)|Chame esse método para criar um arquivo temporário.|  
|[CAtlTemporaryFile::Flush](#flush)|Chame este método para forçar todos os dados restantes no buffer de arquivo a ser gravado para o arquivo temporário.|  
|[CAtlTemporaryFile::GetPosition](#getposition)|Chame este método para obter a posição do ponteiro de arquivo atual.|  
|[CAtlTemporaryFile::GetSize](#getsize)|Chame este método para obter o tamanho em bytes do arquivo temporário.|  
|[CAtlTemporaryFile::HandsOff](#handsoff)|Chame esse método para desassociar o arquivo a partir de `CAtlTemporaryFile` objeto.|  
|[CAtlTemporaryFile::HandsOn](#handson)|Chame esse método para abrir um arquivo temporário existente e posicionar o ponteiro no final do arquivo.|  
|[CAtlTemporaryFile::LockRange](#lockrange)|Chame esse método para bloquear uma região no arquivo para impedir que outros processos de acessá-lo.|  
|[CAtlTemporaryFile::Read](#read)|Chame este método para ler dados do arquivo temporário, iniciando na posição indicada pelo ponteiro de arquivo.|  
|[CAtlTemporaryFile::Seek](#seek)|Chame esse método para mover o ponteiro do arquivo do arquivo temporário.|  
|[CAtlTemporaryFile::SetSize](#setsize)|Chame este método para definir o tamanho do arquivo temporário.|  
|[CAtlTemporaryFile::TempFileName](#tempfilename)|Chame este método para retornar o nome de arquivo temporário.|  
|[CAtlTemporaryFile::UnlockRange](#unlockrange)|Chame este método para desbloquear uma região do arquivo temporário.|  
|[CAtlTemporaryFile::Write](#write)|Chame esse método para gravar dados para o arquivo temporário, iniciando na posição indicada pelo ponteiro de arquivo.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Identificador de CAtlTemporaryFile::operator](#operator_handle)|Retorna um identificador para o arquivo temporário.|  
  
## <a name="remarks"></a>Comentários  
 `CAtlTemporaryFile` é fácil criar e usar um arquivo temporário. O arquivo é automaticamente denominado aberto, fechado e excluído. Se o conteúdo do arquivo é necessário depois que o arquivo seja fechado, eles podem ser salvos em um novo arquivo com um nome especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlfile.h  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).  
  
##  <a name="catltemporaryfile"></a>  CAtlTemporaryFile::CAtlTemporaryFile  
 O construtor.  
  
```
CAtlTemporaryFile() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Um arquivo não estiver aberto, na verdade, até que uma chamada é feita para [CAtlTemporaryFile::Create](#create).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#73](../../atl/codesnippet/cpp/catltemporaryfile-class_1.cpp)]  
  
##  <a name="dtor"></a>  CAtlTemporaryFile:: ~ CAtlTemporaryFile  
 O destruidor.  
  
```
~CAtlTemporaryFile() throw();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de destruidor [CAtlTemporaryFile::Close](#close).  
  
##  <a name="close"></a>  CAtlTemporaryFile::Close  
 Chame este método para fechar um arquivo temporário e excluir seu conteúdo ou armazená-los com o nome de arquivo especificado.  
  
```
HRESULT Close(LPCTSTR szNewName = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *szNewName*  
 O nome para o novo arquivo armazenar o conteúdo do arquivo temporário. Se esse argumento for nulo, o conteúdo do arquivo temporário é excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).  
  
##  <a name="create"></a>  CAtlTemporaryFile::Create  
 Chame esse método para criar um arquivo temporário.  
  
```
HRESULT Create(LPCTSTR pszDir = NULL, DWORD dwDesiredAccess = GENERIC_WRITE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszDir`  
 O caminho para o arquivo temporário. Se for NULL, [GetTempPath](http://msdn.microsoft.com/library/windows/desktop/aa364992) será chamado para atribuir um caminho.  
  
 `dwDesiredAccess`  
 O acesso desejado. Consulte `dwDesiredAccess` na [CreateFile](http://msdn.microsoft.com/library/windows/desktop/aa363858) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).  
  
##  <a name="flush"></a>  CAtlTemporaryFile::Flush  
 Chame este método para forçar todos os dados restantes no buffer de arquivo a ser gravado para o arquivo temporário.  
  
```
HRESULT Flush() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao [CAtlTemporaryFile::HandsOff](#handsoff), exceto que o arquivo não está fechado.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).  
  
##  <a name="getposition"></a>  CAtlTemporaryFile::GetPosition  
 Chame este método para obter a posição do ponteiro de arquivo atual.  
  
```
HRESULT GetPosition(ULONGLONG& nPos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 A posição em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para alterar a posição do ponteiro de arquivo, use [CAtlTemporaryFile::Seek](#seek).  
  
##  <a name="getsize"></a>  CAtlTemporaryFile::GetSize  
 Chame este método para obter o tamanho em bytes do arquivo temporário.  
  
```
HRESULT GetSize(ULONGLONG& nLen) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLen`  
 O número de bytes no arquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
##  <a name="handsoff"></a>  CAtlTemporaryFile::HandsOff  
 Chame esse método para desassociar o arquivo a partir de `CAtlTemporaryFile` objeto.  
  
```
HRESULT HandsOff() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `HandsOff` e [CAtlTemporaryFile::HandsOn](#handson) são usados para desassociar o arquivo do objeto e anexe-o se necessário. `HandsOff` forçará todos os dados restantes no buffer de arquivo a ser gravado para o arquivo temporário e, em seguida, feche o arquivo. Se você deseja fechar e excluir permanentemente o arquivo, ou se você deseja fechar e manter o conteúdo do arquivo com um determinado nome, use [CAtlTemporaryFile::Close](#close).  
  
##  <a name="handson"></a>  CAtlTemporaryFile::HandsOn  
 Chame esse método para abrir um arquivo temporário existente e posicionar o ponteiro no final do arquivo.  
  
```
HRESULT HandsOn() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 [CAtlTemporaryFile::HandsOff](#handsoff) e `HandsOn` são usados para desassociar o arquivo do objeto e anexe-o se necessário.  
  
##  <a name="lockrange"></a>  CAtlTemporaryFile::LockRange  
 Chame este método para bloquear uma região em que o arquivo temporário para impedir que outros processos de acessá-lo.  
  
```
HRESULT LockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 A posição do arquivo onde o bloqueio deve ser iniciada.  
  
 `nCount`  
 O comprimento do intervalo de bytes a ser bloqueada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas nenhuma região sobreposto é permitido. Para desbloquear com êxito uma região, use [CAtlTemporaryFile::UnlockRange](#unlockrange), garantir o intervalo de bytes corresponde exatamente à região que anteriormente estava bloqueada. `LockRange` não mesclar regiões adjacentes; Se duas regiões bloqueadas são adjacentes, você deve desbloquear cada uma separadamente.  
  
##  <a name="operator_handle"></a>  Identificador de CAtlTemporaryFile::operator  
 Retorna um identificador para o arquivo temporário.  
  
```  
operator HANDLE() throw();
```  
  
##  <a name="read"></a>  CAtlTemporaryFile::Read  
 Chame este método para ler dados do arquivo temporário, iniciando na posição indicada pelo ponteiro de arquivo.  
  
```
HRESULT Read(
    LPVOID pBuffer,
    DWORD nBufSize,
    DWORD& nBytesRead) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBuffer`  
 Ponteiro para o buffer que receberá os dados lidos do arquivo.  
  
 `nBufSize`  
 O tamanho do buffer em bytes.  
  
 `nBytesRead`  
 O número de bytes lidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlFile::Read](../../atl/reference/catlfile-class.md#read). Para alterar a posição do ponteiro do arquivo, chame [CAtlTemporaryFile::Seek](#seek).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).  
  
##  <a name="seek"></a>  CAtlTemporaryFile::Seek  
 Chame esse método para mover o ponteiro do arquivo do arquivo temporário.  
  
```
HRESULT Seek(LONGLONG nOffset, DWORD dwFrom = FILE_CURRENT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nOffset`  
 O deslocamento, em bytes, do ponto de partida fornecido por *dwFrom.*  
  
 `dwFrom`  
 O ponto de partida (FILE_BEGIN, FILE_CURRENT ou FILE_END).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlFile::Seek](../../atl/reference/catlfile-class.md#seek). Para obter a posição atual do ponteiro de arquivo, chame [CAtlTemporaryFile::GetPosition](#getposition).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).  
  
##  <a name="setsize"></a>  CAtlTemporaryFile::SetSize  
 Chame este método para definir o tamanho do arquivo temporário.  
  
```
HRESULT SetSize(ULONGLONG nNewLen) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewLen`  
 O novo tamanho do arquivo em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlFile::SetSize](../../atl/reference/catlfile-class.md#setsize). No retorno, o ponteiro do arquivo é posicionado no final do arquivo.  
  
##  <a name="tempfilename"></a>  CAtlTemporaryFile::TempFileName  
 Chame este método para retornar o nome de arquivo temporário.  
  
```
LPCTSTR TempFileName() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o `LPCTSTR` apontando para o nome do arquivo.  
  
### <a name="remarks"></a>Comentários  
 O nome do arquivo é gerado no [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile) com uma chamada para o [GetTempFile](http://msdn.microsoft.com/library/windows/desktop/aa364991)função do SDK do Windows. A extensão de arquivo sempre será "TFR" para o arquivo temporário.  
  
##  <a name="unlockrange"></a>  CAtlTemporaryFile::UnlockRange  
 Chame este método para desbloquear uma região do arquivo temporário.  
  
```
HRESULT UnlockRange(ULONGLONG nPos, ULONGLONG nCount) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 A posição do arquivo onde o desbloqueio deve ser iniciada.  
  
 `nCount`  
 O comprimento do intervalo de bytes a ser desbloqueada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlFile::UnlockRange](../../atl/reference/catlfile-class.md#unlockrange).  
  
##  <a name="write"></a>  CAtlTemporaryFile::Write  
 Chame esse método para gravar dados para o arquivo temporário, iniciando na posição indicada pelo ponteiro de arquivo.  
  
```
HRESULT Write(  
    LPCVOID pBuffer,
    DWORD nBufSize,
    DWORD* pnBytesWritten = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBuffer`  
 O buffer que contém os dados a serem gravados no arquivo.  
  
 `nBufSize`  
 O número de bytes a serem transferidos do buffer.  
  
 `pnBytesWritten`  
 O número de bytes gravados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlFile::Write](../../atl/reference/catlfile-class.md#write).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](#catltemporaryfile).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CAtlFile](../../atl/reference/catlfile-class.md)
