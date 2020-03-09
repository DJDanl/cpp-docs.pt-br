---
title: Funções globais de registro e TypeLib
ms.date: 03/27/2019
f1_keywords:
- atlbase/ATL::AtlGetPerUserRegistration
- afxpriv/ATL::AfxRegCreateKey
- afxpriv/ATL::AfxRegDeleteKey
- atlbase/ATL::AtlRegisterTypeLib
- afxpriv/ATL::AfxRegOpenKey
- afxpriv/ATL::AfxRegOpenKeyEx
- afxdisp/ATL::AfxUnregisterPreviewHandler
- atlbase/ATL::AtlSetPerUserRegistration
- atlbase/ATL::AtlUnRegisterTypeLib
- atlbase/ATL::AtlLoadTypeLib
- atlbase/ATL::AtlUpdateRegistryFromResourceD
- atlbase/ATL::RegistryDataExchange
helpviewer_keywords:
- RegistryDataExchange function, global functions
ms.assetid: d58b8a4e-975c-4417-8b34-d3c847f679b3
ms.openlocfilehash: c5fdaceb47b6cd09dd9d66f26af1337a8dc6bbae
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78863144"
---
# <a name="registry-and-typelib-global-functions"></a>Funções globais de registro e TypeLib

Essas funções fornecem suporte para carregar e registrar uma biblioteca de tipos.

> [!IMPORTANT]
>  As funções listadas nas tabelas a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|||
|-|-|
|[AfxRegCreateKey](#afxregcreatekey)|Cria a chave do Registro especificada.|
|[AfxRegDeleteKey](#afxregdeletekey)|Exclui a chave do Registro especificada.|
|[AfxRegisterPreviewHandler](#afxregisterpreviewhandler)|Um auxiliar para registrar um Gerenciador de visualização.|
|[AfxUnregisterPreviewHandler](#afxunregisterpreviewhandler)| Um auxiliar para cancelar o registro de um Gerenciador de visualização. |
|[AtlRegisterTypeLib](#atlregistertypelib)|Essa função é chamada para registrar uma biblioteca de tipos.|
|[AtlUnRegisterTypeLib](#atlunregistertypelib)|Esta função é chamada para cancelar o registro de uma biblioteca de tipos|
|[AfxRegOpenKey](#afxregopenkey)|Abre a chave do Registro especificada.|
|[AfxRegOpenKeyEx](#afxregopenkeyex)|Abre a chave do Registro especificada.|
|[AtlLoadTypeLib](#atlloadtypelib)|Essa função é chamada para carregar uma biblioteca de tipos.|
|[AtlUpdateRegistryFromResourceD](#atlupdateregistryfromresourced)|Essa função é chamada para atualizar o Registro de recurso fornecido.|
|[RegistryDataExchange](#registrydataexchange)|Essa função é chamada para ler do ou gravar no Registro do sistema. Chamado pelas [macros de troca de dados do registro](../../atl/reference/registry-data-exchange-macros.md).|

Essas funções controlam qual nó do registro o programa usa para armazenar informações.

|||
|-|-|
|[AtlGetPerUserRegistration](#atlgetperuserregistration)|Recupera se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** ( **HKCU**).|
|[AtlSetPerUserRegistration](#atlsetperuserregistration)|Define se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** ( **HKCU**).|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="atlgetperuserregistration"></a>AtlGetPerUserRegistration

Use essa função para determinar se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** (**HKCU**).

### <a name="syntax"></a>Sintaxe

```
ATLINLINE ATLAPI AtlGetPerUserRegistration(bool* pEnabled);
```

### <a name="parameters"></a>Parâmetros

*pEnabled*<br/>
fora VERDADEIRO indica que as informações do registro são direcionadas para o nó **HKCU** ; FALSE indica que o aplicativo grava informações de registro no nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem-sucedido, caso contrário, o código de erro HRESULT ocorrerá se ocorrer um erro.

### <a name="remarks"></a>Comentários

O redirecionamento do registro não está habilitado por padrão. Se você habilitar essa opção, o acesso ao registro será redirecionado para **HKEY_CURRENT_USER \software\classes**.

O redirecionamento não é global. Somente as estruturas MFC e ATL são afetadas por esse redirecionamento de registro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="afxregcreatekey"></a>AfxRegCreateKey

Cria a chave do Registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegCreateKey(HKEY hKey, LPCTSTR lpSubKey, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
Um identificador para uma chave de registro aberta.

*lpSubKey*<br/>
O nome de uma chave que essa função abre ou cria.

*phkResult*<br/>
Um ponteiro para uma variável que recebe um identificador para a chave aberta ou criada.

*pTM*<br/>
Ponteiro para um objeto `CAtlTransactionManager`.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXPRIV. h

## <a name="afxregdeletekey"></a>AfxRegDeleteKey

Exclui a chave do Registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegDeleteKey(HKEY hKey, LPCTSTR lpSubKey, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
Um identificador para uma chave de registro aberta.

*lpSubKey*<br/>
O nome da chave a ser excluída.

*pTM*<br/>
Ponteiro para um objeto `CAtlTransactionManager`.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXPRIV. h

## <a name="afxregisterpreviewhandler"></a>

Um auxiliar para registrar um Gerenciador de visualização.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxRegisterPreviewHandler(LPCTSTR lpszCLSID, LPCTSTR lpszShortTypeName, LPCTSTR lpszFilterExt);
```

### <a name="parameters"></a>Parâmetros

*lpszCLSID*<br/>
Especifica o CLSID do manipulador.

*lpszShortTypeName*<br/>
Especifica o ProgID do manipulador.

*lpszFilterExt*<br/>
Especifica a extensão de arquivo registrada com este manipulador.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="atlregistertypelib"></a>AtlRegisterTypeLib

Essa função é chamada para registrar uma biblioteca de tipos.

```
ATLAPI AtlRegisterTypeLib(HINSTANCE hInstTypeLib, LPCOLESTR lpszIndex);
```

### <a name="parameters"></a>Parâmetros

*hInstTypeLib*<br/>
O identificador para a instância do módulo.

*lpszIndex*<br/>
Cadeia de caracteres no formato "\\\n", em que N é o índice de inteiro do recurso de biblioteca de tipos. Poderá ser NULL se nenhum índice for necessário.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Essa função auxiliar é utilizada por [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver) e [CAtlComModule:: RegisterTypeLib](../../atl/reference/catlcommodule-class.md#registertypelib).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="afxregopenkey"></a>AfxRegOpenKey

Abre a chave do Registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegOpenKey(HKEY hKey, LPCTSTR lpSubKey, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
Um identificador para uma chave de registro aberta.

*lpSubKey*<br/>
O nome de uma chave que essa função abre ou cria.

*phkResult*<br/>
Um ponteiro para uma variável que recebe um identificador para a chave criada.

*pTM*<br/>
Ponteiro para um objeto `CAtlTransactionManager`.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXPRIV. h

## <a name="afxregopenkeyex"></a>AfxRegOpenKeyEx

Abre a chave do Registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegOpenKeyEx(HKEY hKey, LPCTSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*hKey*<br/>
Um identificador para uma chave de registro aberta.

*lpSubKey*<br/>
O nome de uma chave que essa função abre ou cria.

*ulOptions*<br/>
Esse parâmetro é reservado e deve ser zero.

*samDesired*<br/>
Uma máscara que especifica os direitos de acesso desejados à chave.

*phkResult*<br/>
Um ponteiro para uma variável que recebe um identificador para a chave aberta.

*pTM*<br/>
Ponteiro para um objeto `CAtlTransactionManager`.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXPRIV. h

## <a name="afxunregisterpreviewhandler"></a>AfxUnregisterPreviewHandler

Um auxiliar para cancelar o registro de um Gerenciador de visualização.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxUnRegisterPreviewHandler(LPCTSTR lpszCLSID);
```

### <a name="parameters"></a>Parâmetros

*lpszCLSID*<br/>
Especifica o CLSID do manipulador a ser cancelado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="atlsetperuserregistration"></a>AtlSetPerUserRegistration

Define se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** (**HKCU**).

### <a name="syntax"></a>Sintaxe

```
ATLINLINE ATLAPI AtlSetPerUserRegistration(bool bEnable);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no VERDADEIRO indica que as informações do registro são direcionadas para o nó **HKCU** ; FALSE indica que o aplicativo grava informações de registro no nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem-sucedido, caso contrário, o código de erro HRESULT ocorrerá se ocorrer um erro.

### <a name="remarks"></a>Comentários

O redirecionamento do registro não está habilitado por padrão. Se você habilitar essa opção, o acesso ao registro será redirecionado para **HKEY_CURRENT_USER \software\classes**.

O redirecionamento não é global. Somente as estruturas MFC e ATL são afetadas por esse redirecionamento de registro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="atlunregistertypelib"></a>AtlUnRegisterTypeLib

Essa função é chamada para cancelar o registro de uma biblioteca de tipos.

### <a name="syntax"></a>Sintaxe

```
ATLAPI AtlUnRegisterTypeLib(
    HINSTANCE hInstTypeLib,
    LPCOLESTR lpszIndex);
```

### <a name="parameters"></a>Parâmetros

*hInstTypeLib*<br/>
O identificador para a instância do módulo.

*lpszIndex*<br/>
Cadeia de caracteres no formato "\\\n", em que N é o índice de inteiro do recurso de biblioteca de tipos. Poderá ser NULL se nenhum índice for necessário.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Essa função auxiliar é utilizada por [CAtlComModule:: UnRegisterTypeLib](../../atl/reference/catlcommodule-class.md#unregistertypelib) e [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="atlloadtypelib"></a>AtlLoadTypeLib

Essa função é chamada para carregar uma biblioteca de tipos.

### <a name="syntax"></a>Sintaxe

```
ATLINLINE ATLAPI AtlLoadTypeLib(
    HINSTANCE hInstTypeLib,
    LPCOLESTR lpszIndex,
    BSTR* pbstrPath,
    ITypeLib** ppTypeLib);
```

### <a name="parameters"></a>Parâmetros

*hInstTypeLib*<br/>
Identificador para o módulo associado à biblioteca de tipos.

*lpszIndex*<br/>
Cadeia de caracteres no formato "\\\n", em que N é o índice de inteiro do recurso de biblioteca de tipos. Poderá ser NULL se nenhum índice for necessário.

*pbstrPath*<br/>
No retorno bem-sucedido, contém o caminho completo do módulo associado à biblioteca de tipos.

*ppTypeLib*<br/>
No retorno bem-sucedido, contém um ponteiro para um ponteiro para a biblioteca de tipos carregada.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Essa função auxiliar é utilizada por [AtlRegisterTypeLib](#atlregistertypelib) e [AtlUnRegisterTypeLib](#atlunregistertypelib).

##  <a name="atlupdateregistryfromresourced"></a>AtlUpdateRegistryFromResourceD

Essa função foi preterida em Visual Studio 2013 e é removida no Visual Studio 2015.

```
<removed>
```

##  <a name="registrydataexchange"></a>RegistryDataExchange

Essa função é chamada para ler do ou gravar no Registro do sistema.

### <a name="syntax"></a>Sintaxe

```
HRESULT RegistryDataExchange(
    T* pT,
    enum RDXOperations rdxOp,
    void* pItem = NULL);
```

### <a name="parameters"></a>Parâmetros

*pT*<br/>
Um ponteiro para o objeto atual.

*rdxOp*<br/>
Um valor de enumeração que indica qual operação a função deve executar. Consulte a tabela na seção comentários para obter os valores permitidos.

*pItem*<br/>
Ponteiro para os dados que serão lidos ou gravados no registro. Os dados também podem representar uma chave a ser excluída do registro. O valor padrão é NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

As macros [BEGIN_RDX_MAP](registry-data-exchange-macros.md#begin_rdx_map) e [END_RDX_MAP](registry-data-exchange-macros.md#end_rdx_map) se expandem para uma função que chama `RegistryDataExchange`.

Os valores de enumeração possíveis que indicam a operação que a função deve executar são mostrados na tabela a seguir:

|Valor de enumeração|Operação|
|----------------|---------------|
|eReadFromReg|Ler dados do registro.|
|eWriteToReg|Gravar dados no registro.|
|eDeleteFromReg|Exclua a chave do registro.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Veja também

[Funções](atl-functions.md)<br/>
[Macros de troca de dados de Registro](registry-data-exchange-macros.md)
