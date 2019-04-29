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
ms.openlocfilehash: 031d72903d72af77f6929072e4605d32d81585a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62260048"
---
# <a name="catltransactionmanager-class"></a>Classe CAtlTransactionManager

Classe CAtlTransactionManager fornece um wrapper para as funções de transação KTM (Kernel Manager).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlTransactionManager;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[~CAtlTransactionManager](#dtor)|Destruidor CAtlTransactionManager.|
|[CAtlTransactionManager](#catltransactionmanager)|Construtor CAtlTransactionManager.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Fechar](#close)|Um fecha o identificador de transação.|
|[Confirmação](#commit)|Solicita que a transação ser confirmada.|
|[criar](#create)|Cria o identificador de transação.|
|[CreateFile](#createfile)|Cria ou abre um arquivo, o fluxo de arquivos ou o diretório como uma operação transacionada.|
|[DeleteFile](#deletefile)|Exclui um arquivo existente como uma operação transacionada.|
|[FindFirstFile](#findfirstfile)|Pesquisa um diretório para um arquivo ou subdiretório como uma operação transacionada.|
|[GetFileAttributes](#getfileattributes)|Recupera atributos de sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.|
|[GetFileAttributesEx](#getfileattributesex)|Recupera atributos de sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.|
|[GetHandle](#gethandle)|Retorna o identificador de transação.|
|[IsFallback](#isfallback)|Determina se as chamadas de fallback estão habilitadas.|
|[MoveFile](#movefile)|Move um arquivo existente ou um diretório, incluindo seus filhos, como uma operação transacionada.|
|[RegCreateKeyEx](#regcreatekeyex)|Cria a chave do registro especificado e associa-o uma transação. Se a chave já existir, a função é aberta.|
|[RegDeleteKey](#regdeletekey)|Exclui uma subchave e seus valores do modo de exibição específico de plataforma especificado do registro como uma operação transacionada.|
|[RegOpenKeyEx](#regopenkeyex)|Abre a chave do Registro especificada e a associa com uma transação.|
|[Reversão](#rollback)|Solicitações que a transação ser revertida.|
|[SetFileAttributes](#setfileattributes)|Define os atributos para um arquivo ou diretório como uma operação transacionada.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[m_bFallback](#m_bfallback)|TRUE se o fallback é suportado; FALSE caso contrário.|
|[m_hTransaction](#m_htransaction)|O identificador de transação.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ATL::CAtlTransactionManager](../../atl/reference/catltransactionmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltransactionmanager.h

##  <a name="dtor"></a>  ~CAtlTransactionManager

Destruidor CAtlTransactionManager.

```
virtual ~CAtlTransactionManager();
```

### <a name="remarks"></a>Comentários

No processamento normal, a transação é confirmada automaticamente e fechada. Se o destruidor é chamado durante um desenrolamento de exceção, a transação é revertida e fechada.

##  <a name="catltransactionmanager"></a>  CAtlTransactionManager

Construtor CAtlTransactionManager.

```
CAtlTransactionManager(BOOL bFallback = TRUE, BOOL bAutoCreateTransaction = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bFallback*<br/>
TRUE indica que o fallback de suporte. Se a função transacionada falhar, a classe chama automaticamente a função "não transacionado". FALSE não indica que nenhuma chamada "fallback".

*bAutoCreateTransaction*<br/>
TRUE indica que o manipulador de transações é criado automaticamente no construtor. FALSE indica que não é.

### <a name="remarks"></a>Comentários

##  <a name="close"></a>  Fechar

Fecha o identificador de transação.

```
inline BOOL Close();
```

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este wrapper chama o `CloseHandle` função. O método é chamado automaticamente no destruidor.

##  <a name="commit"></a>  Confirmação

Solicita que a transação ser confirmada.

```
inline BOOL Commit();
```

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este wrapper chama o `CommitTransaction` função. O método é chamado automaticamente no destruidor.

##  <a name="create"></a>  criar

Cria o identificador de transação.

```
inline BOOL Create();
```

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este wrapper chama o `CreateTransaction` função. Verifique a existência

##  <a name="createfile"></a>  CreateFile

Cria ou abre um arquivo, o fluxo de arquivos ou o diretório como uma operação transacionada.

```
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
O acesso ao objeto, que pode ser resumido como leitura, gravação, ambos ou nenhum (zero). Os valores mais comumente usados são GENERIC_READ, GENERIC_WRITE ou ambos: GENERIC_READ &#124; GENERIC_WRITE.

*dwShareMode*<br/>
O modo de compartilhamento de um objeto, que pode ser de leitura, gravação, ambos, excluir, todos eles, ou nenhum: 0, FILE_SHARE_DELETE, FILE_SHARE_READ, FILE_SHARE_WRITE.

*lpSecurityAttributes*<br/>
Um ponteiro para uma estrutura SECURITY_ATTRIBUTES que contém um descritor de segurança opcional e também determina se o identificador retornado pode ser herdado por processos filhos. O parâmetro pode ser NULL.

*dwCreationDisposition*<br/>
Uma ação a ser tomada em arquivos que existem e não existem. Esse parâmetro deve ser um dos valores a seguir, que não podem ser combinados: CREATE_ALWAYS, CREATE_NEW, OPEN_ALWAYS, OPEN_EXISTING ou TRUNCATE_EXISTING.

*dwFlagsAndAttributes*<br/>
Os atributos de arquivo e sinalizadores. Esse parâmetro pode incluir qualquer combinação dos atributos de arquivo disponível (FILE_ATTRIBUTE_ *). Todos os outros atributos de arquivo substituem FILE_ATTRIBUTE_NORMAL. Esse parâmetro também pode conter combinações dos sinalizadores (FILE_FLAG_\*) para controle do comportamento de buffer, acessar os modos e outros sinalizadores de finalidade especial. Elas são combinadas com qualquer FILE_ATTRIBUTE_\* valores.

*hTemplateFile*<br/>
Um identificador válido para um arquivo de modelo com o direito de acesso GENERIC_READ. O arquivo de modelo fornece os atributos de arquivo e os atributos estendidos para o arquivo que está sendo criado. Esse parâmetro pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Retorna um identificador que pode ser usado para acessar o objeto.

### <a name="remarks"></a>Comentários

Este wrapper chama o `CreateFileTransacted` função.

##  <a name="deletefile"></a>  DeleteFile

Exclui um arquivo existente como uma operação transacionada.

```
inline BOOL DeleteFile(LPCTSTR lpFileName);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo a ser excluído.

### <a name="remarks"></a>Comentários

Este wrapper chama o `DeleteFileTransacted` função.

##  <a name="findfirstfile"></a>  FindFirstFile

Pesquisa um diretório para um arquivo ou subdiretório como uma operação transacionada.

```
inline HANDLE FindFirstFile(
    LPCTSTR lpFileName,
    WIN32_FIND_DATA* pNextInfo);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O diretório ou caminho e o nome do arquivo a ser pesquisado. Esse parâmetro pode incluir caracteres curinga, como um asterisco (*) ou um (do ponto de interrogação).

*pNextInfo*<br/>
Um ponteiro para a estrutura WIN32_FIND_DATA que recebe informações sobre um subdiretório ou arquivo encontrado.

### <a name="return-value"></a>Valor de retorno

Se a função for bem-sucedida, o valor retornado é um identificador de pesquisa usado em uma chamada subsequente para `FindNextFile` ou `FindClose`. Se a função falhar ou se não conseguir localizar os arquivos da cadeia de pesquisa na *lpFileName* parâmetro, o valor de retorno será INVALID_HANDLE_VALUE.

### <a name="remarks"></a>Comentários

Este wrapper chama o `FindFirstFileTransacted` função.

##  <a name="getfileattributes"></a>  GetFileAttributes

Recupera atributos de sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.

```
inline DWORD GetFileAttributes(LPCTSTR lpFileName);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo ou diretório.

### <a name="remarks"></a>Comentários

Este wrapper chama o `GetFileAttributesTransacted` função.

##  <a name="getfileattributesex"></a>  GetFileAttributesEx

Recupera atributos de sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.

```
inline BOOL GetFileAttributesEx(
    LPCTSTR lpFileName,
    GET_FILEEX_INFO_LEVELS fInfoLevelId,
    LPVOID lpFileInformation);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo ou diretório.

*fInfoLevelId*<br/>
O nível de informações de atributo devem ser recuperadas.

*lpFileInformation*<br/>
Um ponteiro para um buffer que recebe as informações de atributo. O tipo de informações de atributo que são armazenados nesse buffer é determinado pelo valor de *fInfoLevelId*. Se o *fInfoLevelId* GetFileExInfoStandard do parâmetro é, em seguida, este parâmetro aponta para uma estrutura WIN32_FILE_ATTRIBUTE_DATA.

### <a name="remarks"></a>Comentários

Este wrapper chama o `GetFileAttributesTransacted` função.

##  <a name="gethandle"></a>  GetHandle

Retorna o identificador de transação.

```
HANDLE GetHandle() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o identificador de transação para uma classe. Retorna NULL se o `CAtlTransactionManager` não está anexado a um identificador.

### <a name="remarks"></a>Comentários

##  <a name="isfallback"></a>  IsFallback

Determina se as chamadas de fallback estão habilitadas.

```
BOOL IsFallback() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE é as chamadas de fallback dá suporte à classe. FALSE caso contrário.

### <a name="remarks"></a>Comentários

##  <a name="m_bfallback"></a>  m_bFallback

TRUE se o fallback é suportado; FALSE caso contrário.

```
BOOL m_bFallback;
```

### <a name="remarks"></a>Comentários

##  <a name="m_htransaction"></a>  m_hTransaction

O identificador de transação.

```
HANDLE m_hTransaction;
```

### <a name="remarks"></a>Comentários

##  <a name="movefile"></a>  MoveFile

Move um arquivo existente ou um diretório, incluindo seus filhos, como uma operação transacionada.

```
inline BOOL MoveFile(LPCTSTR lpOldFileName, LPCTSTR lpNewFileName);
```

### <a name="parameters"></a>Parâmetros

*lpOldFileName*<br/>
O nome atual do arquivo ou diretório existente no computador local.

*lpNewFileName*<br/>
O novo nome para o arquivo ou diretório. Esse nome não deve existir. Um novo arquivo pode ser em um sistema de arquivos diferente ou a unidade. Um novo diretório deve estar na mesma unidade.

### <a name="remarks"></a>Comentários

Este wrapper chama o `MoveFileTransacted` função.

##  <a name="regcreatekeyex"></a>  RegCreateKeyEx

Cria a chave do registro especificado e associa-o uma transação. Se a chave já existir, a função é aberta.

```
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
Um identificador para uma chave do Registro aberta.

*lpSubKey*<br/>
O nome de uma subchave que essa função abre ou cria.

*dwReserved*<br/>
Esse parâmetro é reservado e deve ser zero.

*lpClass*<br/>
A classe definida pelo usuário dessa chave. Esse parâmetro pode ser ignorado. Esse parâmetro pode ser NULL.

*dwOptions*<br/>
Esse parâmetro pode ser um dos seguintes valores: REG_OPTION_BACKUP_RESTORE, REG_OPTION_NON_VOLATILE ou REG_OPTION_VOLATILE.

*samDesired*<br/>
Uma máscara que especifica os direitos de acesso para a chave.

*lpSecurityAttributes*<br/>
Ponteiro para uma estrutura SECURITY_ATTRIBUTES que determina se o identificador retornado pode ser herdado por processos filhos. Se *lpSecurityAttributes* for NULL, o identificador não pode ser herdado.

*phkResult*<br/>
Um ponteiro para uma variável que recebe um identificador para a chave aberto ou criado. Se a chave não é uma das chaves de registro predefinidos, chame o `RegCloseKey` depois que você terminar de usar o identificador de função.

*lpdwDisposition*<br/>
Um ponteiro para uma variável que recebe um dos seguintes valores de disposição: REG_CREATED_NEW_KEY ou REG_OPENED_EXISTING_KEY.

### <a name="return-value"></a>Valor de retorno

Se a função for bem-sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido em Winerror. h.

### <a name="remarks"></a>Comentários

Este wrapper chama o `RegCreateKeyTransacted` função.

##  <a name="regdeletekey"></a>  RegDeleteKey

Exclui uma subchave e seus valores do modo de exibição específico de plataforma especificado do registro como uma operação transacionada.

```
inline LSTATUS RegDeleteKeyEx(HKEY hKey, LPCTSTR lpSubKey);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*hKey*|Um identificador para uma chave do Registro aberta.|
|*lpSubKey*|O nome da chave a ser excluído.|

### <a name="return-value"></a>Valor de retorno

Se a função for bem-sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido em Winerror. h.

### <a name="remarks"></a>Comentários

Este wrapper chama o `RegDeleteKeyTransacted` função.

##  <a name="regopenkeyex"></a>  RegOpenKeyEx

Abre a chave do Registro especificada e a associa com uma transação.

```
inline LSTATUS RegOpenKeyEx(
    HKEY hKey,
    LPCTSTR lpSubKey,
    DWORD ulOptions,
    REGSAM samDesired,
    PHKEY phkResult);
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
Um identificador para uma chave do Registro aberta.

*lpSubKey*<br/>
O nome da subchave do registro a ser aberto.

*ulOptions*<br/>
Esse parâmetro é reservado e deve ser zero.

*samDesired*<br/>
Uma máscara que especifica os direitos de acesso para a chave.

*phkResult*<br/>
Um ponteiro para uma variável que recebe um identificador para a chave aberto ou criado. Se a chave não é uma das chaves de registro predefinidos, chame o `RegCloseKey` depois que você terminar de usar o identificador de função.

### <a name="return-value"></a>Valor de retorno

Se a função for bem-sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido em Winerror. h

### <a name="remarks"></a>Comentários

Este wrapper chama o `RegOpenKeyTransacted` função.

##  <a name="rollback"></a>  Rollback

Solicitações que a transação ser revertida.

```
inline BOOL Rollback();
```

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este wrapper chama o `RollbackTransaction` função.

##  <a name="setfileattributes"></a>  SetFileAttributes

Define os atributos para um arquivo ou diretório como uma operação transacionada.

```
inline BOOL SetFileAttributes(LPCTSTR lpFileName, DWORD dwAttributes);
```

### <a name="parameters"></a>Parâmetros

*lpFileName*<br/>
O nome do arquivo ou diretório.

*dwAttributes*<br/>
Os atributos de arquivo a ser definido para o arquivo. Para obter mais informações, consulte [SetFileAttributesTransacted](/windows/desktop/api/winbase/nf-winbase-setfileattributestransacteda).

### <a name="remarks"></a>Comentários

Este wrapper chama o `SetFileAttributesTransacted` função.

## <a name="see-also"></a>Consulte também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
