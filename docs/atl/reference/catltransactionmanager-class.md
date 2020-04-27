---
title: Classe CAtlTransactionManager
ms.date: 11/04/2016
f1_keywords:
- CAtlTransactionManager
- ATLTRANSACTIONMANAGER/ATL::CAtlTransactionManager
- ATLTRANSACTIONMANAGER/ATL::Close
- ATLTRANSACTIONMANAGER/ATL::Commit
- ATLTRANSACTIONMANAGER/ATL::Create
- ATLTRANSACTIONMANAGER/ATL::CreateFile
- ATLTRANSACTIONMANAGER/ATL::DeleteFile
- ATLTRANSACTIONMANAGER/ATL::FindFirstFile
- ATLTRANSACTIONMANAGER/ATL::GetFileAttributes
- ATLTRANSACTIONMANAGER/ATL::GetFileAttributesEx
- ATLTRANSACTIONMANAGER/ATL::GetHandle
- ATLTRANSACTIONMANAGER/ATL::IsFallback
- ATLTRANSACTIONMANAGER/ATL::MoveFile
- ATLTRANSACTIONMANAGER/ATL::RegCreateKeyEx
- ATLTRANSACTIONMANAGER/ATL::RegDeleteKey
- ATLTRANSACTIONMANAGER/ATL::RegOpenKeyEx
- ATLTRANSACTIONMANAGER/ATL::Rollback
- ATLTRANSACTIONMANAGER/ATL::SetFileAttributes
- ATLTRANSACTIONMANAGER/ATL::m_bFallback
- ATLTRANSACTIONMANAGER/ATL::m_hTransaction
helpviewer_keywords:
- CAtlTransactionManager class
ms.assetid: b01732dc-1d16-4b42-bfac-b137fca2b740
ms.openlocfilehash: 968582feccd8ba9252ca009699eef6eae2c5c3d6
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82167819"
---
# <a name="catltransactionmanager-class"></a>Classe CAtlTransactionManager

A classe CAtlTransactionManager fornece um wrapper para funções de KTM (kernel Transaction Manager).

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
class CAtlTransactionManager;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[~ CAtlTransactionManager](#dtor)|Destruidor CAtlTransactionManager.|
|[CAtlTransactionManager](#catltransactionmanager)|Construtor CAtlTransactionManager.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Fechar](#close)|Fecha um identificador de transação.|
|[Confirmar](#commit)|Solicita que a transação seja confirmada.|
|[Criar](#create)|Cria o identificador de transação.|
|[CreateFile](#createfile)|Cria ou abre um arquivo, fluxo de arquivos ou diretório como uma operação transacionada.|
|[DeleteFile](#deletefile)|Exclui um arquivo existente como uma operação transacionada.|
|[FindFirstFile](#findfirstfile)|Pesquisa um diretório para um arquivo ou subdiretório como uma operação transacionada.|
|[GetFileAttributes](#getfileattributes)|Recupera atributos do sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.|
|[GetFileAttributesEx](#getfileattributesex)|Recupera atributos do sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.|
|[GetHandle](#gethandle)|Retorna o identificador da transação.|
|[Isfallback](#isfallback)|Determina se as chamadas de fallback estão habilitadas.|
|[MoveFile](#movefile)|Move um arquivo existente ou um diretório, incluindo seus filhos, como uma operação transacionada.|
|[RegCreateKeyEx](#regcreatekeyex)|Cria a chave do Registro especificada e a associa a uma transação. Se a chave já existir, a função a abrirá.|
|[RegDeleteKey](#regdeletekey)|Exclui uma subchave e seus valores da exibição específica da plataforma especificada do registro como uma operação transacionada.|
|[Falha em RegOpenKeyEx](#regopenkeyex)|Abre a chave do Registro especificada e a associa a uma transação.|
|[Versão](#rollback)|Solicita que a transação seja revertida.|
|[SetFileAttributes](#setfileattributes)|Define os atributos de um arquivo ou diretório como uma operação transacionada.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[m_bFallback](#m_bfallback)|TRUE se houver suporte para fallback; Caso contrário, FALSE.|
|[m_hTransaction](#m_htransaction)|O identificador da transação.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ATL:: CAtlTransactionManager](../../atl/reference/catltransactionmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltransactionmanager. h

## <a name="catltransactionmanager"></a><a name="dtor"></a>~ CAtlTransactionManager

Destruidor CAtlTransactionManager.

```cpp
virtual ~CAtlTransactionManager();
```

### <a name="remarks"></a>Comentários

No processamento normal, a transação é automaticamente confirmada e fechada. Se o destruidor for chamado durante um desenrolamento de exceção, a transação será revertida e fechada.

## <a name="catltransactionmanager"></a><a name="catltransactionmanager"></a>CAtlTransactionManager

Construtor CAtlTransactionManager.

```cpp
CAtlTransactionManager(BOOL bFallback = TRUE, BOOL bAutoCreateTransaction = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bFallback*<br/>
VERDADEIRO indica o fallback de suporte. Se a função transacionada falhar, a classe chamará automaticamente a função "não transacionada". FALSE indica que não há chamadas de "fallback".

*bAutoCreateTransaction*<br/>
VERDADEIRO indica que o manipulador de transações é criado automaticamente no construtor. FALSE indica que não é.

### <a name="remarks"></a>Comentários

## <a name="close"></a><a name="close"></a>Inclui

Fecha o identificador de transação.

```cpp
inline BOOL Close();
```

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `CloseHandle` função. O método é chamado automaticamente no destruidor.

## <a name="commit"></a><a name="commit"></a>Compromisso

Solicita que a transação seja confirmada.

```cpp
inline BOOL Commit();
```

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `CommitTransaction` função. O método é chamado automaticamente no destruidor.

## <a name="create"></a><a name="create"></a>Criada

Cria o identificador de transação.

```cpp
inline BOOL Create();
```

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `CreateTransaction` função. Verifique se ele é

## <a name="createfile"></a><a name="createfile"></a>CreateFile

Cria ou abre um arquivo, fluxo de arquivos ou diretório como uma operação transacionada.

```cpp
inline HANDLE CreateFile(
    LPCTSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome de um objeto a ser criado ou aberto.

*dwDesiredAccess*<br/>
O acesso ao objeto, que pode ser resumido como leitura, gravação, ambos ou nenhum (zero). Os valores usados com mais frequência são GENERIC_READ, GENERIC_WRITE ou ambos: GENERIC_READ &#124; GENERIC_WRITE.

*dwShareMode*<br/>
O modo de compartilhamento de um objeto, que pode ser lido, gravado, ambos, excluído, todos eles ou nenhum: 0, FILE_SHARE_DELETE, FILE_SHARE_READ FILE_SHARE_WRITE.

*lpSecurityAttributes*<br/>
Um ponteiro para uma estrutura de SECURITY_ATTRIBUTES que contém um descritor de segurança opcional e também determina se o identificador retornado pode ou não ser herdado por processos filho. O parâmetro pode ser nulo.

*dwCreationDisposition*<br/>
Uma ação a ser executada em arquivos que existem e não existem. Esse parâmetro deve ser um dos seguintes valores, que não podem ser combinados: CREATE_ALWAYS, CREATE_NEW, OPEN_ALWAYS, OPEN_EXISTING ou TRUNCATE_EXISTING.

*dwFlagsAndAttributes*<br/>
Os atributos e sinalizadores de arquivo. Esse parâmetro pode incluir qualquer combinação dos atributos de arquivo disponíveis (FILE_ATTRIBUTE_ *). Todos os outros atributos de arquivo substituem FILE_ATTRIBUTE_NORMAL. Esse parâmetro também pode conter combinações de sinalizadores (FILE_FLAG_\*) para controle de comportamento de buffer, modos de acesso e outros sinalizadores de finalidade especial. Eles são combinados com qualquer\* valor de FILE_ATTRIBUTE_.

*hTemplateFile*<br/>
Um identificador válido para um arquivo de modelo com o direito de acesso GENERIC_READ. O arquivo de modelo fornece atributos de arquivo e atributos estendidos para o arquivo que está sendo criado. Esse parâmetro pode ser nulo.

### <a name="return-value"></a>Valor retornado

Retorna um identificador que pode ser usado para acessar o objeto.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `CreateFileTransacted` função.

## <a name="deletefile"></a><a name="deletefile"></a>DeleteFile

Exclui um arquivo existente como uma operação transacionada.

```cpp
inline BOOL DeleteFile(LPCTSTR lpFileName);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo a ser excluído.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `DeleteFileTransacted` função.

## <a name="findfirstfile"></a><a name="findfirstfile"></a>FindFirstFile

Pesquisa um diretório para um arquivo ou subdiretório como uma operação transacionada.

```cpp
inline HANDLE FindFirstFile(
    LPCTSTR lpFileName,
    WIN32_FIND_DATA* pNextInfo);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O diretório ou caminho e o nome do arquivo a ser pesquisado. Esse parâmetro pode incluir caracteres curinga, como um asterisco (*) ou um ponto de interrogação ().

*pNextInfo*<br/>
Um ponteiro para a estrutura de WIN32_FIND_DATA que recebe informações sobre um arquivo ou subdiretório encontrado.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será um identificador de pesquisa usado em `FindNextFile` uma `FindClose`chamada subsequente para ou. Se a função falhar ou falhar em localizar arquivos da cadeia de caracteres de pesquisa no parâmetro *lpFileName* , o valor de retorno será INVALID_HANDLE_VALUE.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `FindFirstFileTransacted` função.

## <a name="getfileattributes"></a><a name="getfileattributes"></a>GetFileAttributes

Recupera atributos do sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.

```cpp
inline DWORD GetFileAttributes(LPCTSTR lpFileName);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo ou diretório.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `GetFileAttributesTransacted` função.

## <a name="getfileattributesex"></a><a name="getfileattributesex"></a>GetFileAttributesEx

Recupera atributos do sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.

```cpp
inline BOOL GetFileAttributesEx(
    LPCTSTR lpFileName,
    GET_FILEEX_INFO_LEVELS fInfoLevelId,
    LPVOID lpFileInformation);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo ou diretório.

*fInfoLevelId*<br/>
O nível das informações de atributo a recuperar.

*lpFileInformation*<br/>
Um ponteiro para um buffer que recebe as informações de atributo. O tipo de informação de atributo que é armazenado nesse buffer é determinado pelo valor de *fInfoLevelId*. Se o parâmetro *fInfoLevelId* for GetFileExInfoStandard, esse parâmetro apontará para uma estrutura de WIN32_FILE_ATTRIBUTE_DATA.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `GetFileAttributesTransacted` função.

## <a name="gethandle"></a><a name="gethandle"></a>GetHandle

Retorna o identificador da transação.

```cpp
HANDLE GetHandle() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o identificador de transação para uma classe. Retornará NULL se o `CAtlTransactionManager` não estiver anexado a um identificador.

### <a name="remarks"></a>Comentários

## <a name="isfallback"></a><a name="isfallback"></a>Isfallback

Determina se as chamadas de fallback estão habilitadas.

```cpp
BOOL IsFallback() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE é a classe que oferece suporte a chamadas de fallback. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="m_bfallback"></a><a name="m_bfallback"></a>m_bFallback

TRUE se houver suporte para fallback; Caso contrário, FALSE.

```cpp
BOOL m_bFallback;
```

### <a name="remarks"></a>Comentários

## <a name="m_htransaction"></a><a name="m_htransaction"></a>m_hTransaction

O identificador da transação.

```cpp
HANDLE m_hTransaction;
```

### <a name="remarks"></a>Comentários

## <a name="movefile"></a><a name="movefile"></a>Move

Move um arquivo existente ou um diretório, incluindo seus filhos, como uma operação transacionada.

```cpp
inline BOOL MoveFile(LPCTSTR lpOldFileName, LPCTSTR lpNewFileName);
```

### <a name="parameters"></a>Parâmetros

*lpOldFileName*<br/>
O nome atual do arquivo ou diretório existente no computador local.

*lpNewFileName*<br/>
O novo nome para o arquivo ou diretório. Esse nome ainda não deve existir. Um novo arquivo pode estar em um sistema de arquivos ou unidade diferente. Um novo diretório deve estar na mesma unidade.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `MoveFileTransacted` função.

## <a name="regcreatekeyex"></a><a name="regcreatekeyex"></a>RegCreateKeyEx

Cria a chave do Registro especificada e a associa a uma transação. Se a chave já existir, a função a abrirá.

```cpp
inline LSTATUS RegCreateKeyEx(
    HKEY hKey,
    LPCTSTR lpSubKey,
    DWORD dwReserved,
    LPTSTR lpClass,
    DWORD dwOptions,
    REGSAM samDesired,
    CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    PHKEY phkResult,
    LPDWORD lpdwDisposition);
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
Um identificador para uma chave de registro aberta.

*lpSubKey*<br/>
O nome de uma subchave que essa função abre ou cria.

*dwReserved*<br/>
Esse parâmetro é reservado e deve ser zero.

*lpClass*<br/>
A classe definida pelo usuário dessa chave. Esse parâmetro pode ser ignorado. Esse parâmetro pode ser nulo.

*dwOptions*<br/>
Esse parâmetro pode ser um dos seguintes valores: REG_OPTION_BACKUP_RESTORE, REG_OPTION_NON_VOLATILE ou REG_OPTION_VOLATILE.

*samDesired*<br/>
Uma máscara que especifica os direitos de acesso para a chave.

*lpSecurityAttributes*<br/>
Ponteiro para uma estrutura SECURITY_ATTRIBUTES que determina se o indicador retornado pode ser herdado por processos filhos. Se *lpSecurityAttributes* for NULL, o identificador não poderá ser herdado.

*phkResult*<br/>
Um ponteiro para uma variável que recebe um identificador para a chave aberta ou criada. Se a chave não for uma das chaves do registro predefinidas, `RegCloseKey` chame a função depois de terminar de usar o identificador.

*lpdwDisposition*<br/>
Um ponteiro para uma variável que recebe um dos seguintes valores de disposição: REG_CREATED_NEW_KEY ou REG_OPENED_EXISTING_KEY.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `RegCreateKeyTransacted` função.

## <a name="regdeletekey"></a><a name="regdeletekey"></a>RegDeleteKey

Exclui uma subchave e seus valores da exibição específica da plataforma especificada do registro como uma operação transacionada.

```cpp
inline LSTATUS RegDeleteKeyEx(HKEY hKey, LPCTSTR lpSubKey);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*hKey*|Um identificador para uma chave de registro aberta.|
|*lpSubKey*|O nome da chave a ser excluída.|

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `RegDeleteKeyTransacted` função.

## <a name="regopenkeyex"></a><a name="regopenkeyex"></a>Falha em RegOpenKeyEx

Abre a chave do Registro especificada e a associa a uma transação.

```cpp
inline LSTATUS RegOpenKeyEx(
    HKEY hKey,
    LPCTSTR lpSubKey,
    DWORD ulOptions,
    REGSAM samDesired,
    PHKEY phkResult);
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
Um identificador para uma chave de registro aberta.

*lpSubKey*<br/>
O nome da subchave do registro a ser aberta.

*ulOptions*<br/>
Esse parâmetro é reservado e deve ser zero.

*samDesired*<br/>
Uma máscara que especifica os direitos de acesso para a chave.

*phkResult*<br/>
Um ponteiro para uma variável que recebe um identificador para a chave aberta ou criada. Se a chave não for uma das chaves do registro predefinidas, `RegCloseKey` chame a função depois de terminar de usar o identificador.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h

### <a name="remarks"></a>Comentários

Esse wrapper chama a `RegOpenKeyTransacted` função.

## <a name="rollback"></a><a name="rollback"></a>Versão

Solicita que a transação seja revertida.

```cpp
inline BOOL Rollback();
```

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse wrapper chama a `RollbackTransaction` função.

## <a name="setfileattributes"></a><a name="setfileattributes"></a>SetFileAttributes

Define os atributos de um arquivo ou diretório como uma operação transacionada.

```cpp
inline BOOL SetFileAttributes(LPCTSTR lpFileName, DWORD dwAttributes);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo ou diretório.

*dwAttributes*<br/>
Os atributos de arquivo a serem definidos para o arquivo. Para obter mais informações, consulte [SetFileAttributesTransacted](/windows/win32/api/winbase/nf-winbase-setfileattributestransactedw).

### <a name="remarks"></a>Comentários

Esse wrapper chama a `SetFileAttributesTransacted` função.

## <a name="see-also"></a>Confira também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
