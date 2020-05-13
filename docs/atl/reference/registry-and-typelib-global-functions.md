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
ms.openlocfilehash: 69df927ddd04c19d10703854aa8c8948894309d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326088"
---
# <a name="registry-and-typelib-global-functions"></a>Funções globais de registro e TypeLib

Essas funções fornecem suporte para carregar e registrar uma biblioteca de tipos.

> [!IMPORTANT]
> As funções listadas nas tabelas a seguir não podem ser usadas em aplicativos executados no Tempo de execução do Windows.

|||
|-|-|
|[AfxRegCreateKey](#afxregcreatekey)|Cria a chave de registro especificada.|
|[AfxRegDeleteKey](#afxregdeletekey)|Exclui a chave de registro especificada.|
|[AfxRegisterPreviewHandler](#afxregisterpreviewhandler)|Um ajudante para registrar um manipulador de visualização.|
|[AfxUnregisterPreviewHandler](#afxunregisterpreviewhandler)| Um ajudante para cancelar o registro de um manipulador de visualização. |
|[AtlRegisterTypeLib](#atlregistertypelib)|Essa função é chamada para registrar uma biblioteca de tipos.|
|[AtlUnRegisterTypeLib](#atlunregistertypelib)|Esta função é chamada para cancelar o registro de uma biblioteca de tipos|
|[AfxRegOpenKey](#afxregopenkey)|Abre a chave de registro especificada.|
|[AfxRegOpenKeyEx](#afxregopenkeyex)|Abre a chave de registro especificada.|
|[AtlLoadTypeLib](#atlloadtypelib)|Essa função é chamada para carregar uma biblioteca de tipos.|
|[AtlUpdateRegistryFromResourceD](#atlupdateregistryfromresourced)|Essa função é chamada para atualizar o Registro de recurso fornecido.|
|[RegistryDataExchange](#registrydataexchange)|Essa função é chamada para ler do ou gravar no Registro do sistema. Chamado pelas [Macros de Troca de Dados de Registro](../../atl/reference/registry-data-exchange-macros.md).|

Essas funções controlam qual nó no registro que o programa usa para armazenar informações.

|||
|-|-|
|[AtlGetPerUserRegistration](#atlgetperuserregistration)|Recupera se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** **(HKCU).**|
|[AtlSetPerUserRegistration](#atlsetperuserregistration)|Define se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** **(HKCU).**|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atlgetperuserregistration"></a><a name="atlgetperuserregistration"></a>AtlGetPerUserRegistration

Use esta função para determinar se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** (**HKCU).**

### <a name="syntax"></a>Sintaxe

```
ATLINLINE ATLAPI AtlGetPerUserRegistration(bool* pEnabled);
```

### <a name="parameters"></a>Parâmetros

*pEnabled*<br/>
[fora] TRUE indica que as informações do registro são direcionadas ao nó **HKCU;** FALSE indica que o aplicativo grava informações de registro para o nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem sucedido, caso contrário, o código de erro HRESULT se ocorrer um erro.

### <a name="remarks"></a>Comentários

O redirecionamento do registro não é habilitado por padrão. Se você habilitar essa opção, o acesso ao registro será redirecionado para **HKEY_CURRENT_USER\Software\Classes**.

O redirecionamento não é global. Apenas as estruturas MFC e ATL são afetadas por esse redirecionamento de registro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="afxregcreatekey"></a><a name="afxregcreatekey"></a>AfxRegCreatekey

Cria a chave de registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegCreateKey(HKEY hKey, LPCTSTR lpSubKey, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hkey*<br/>
Uma alça para uma chave de registro aberta.

*lpSubKey*<br/>
O nome de uma chave que esta função abre ou cria.

*phkResult*<br/>
Um ponteiro para uma variável que recebe uma alça para a tecla aberta ou criada.

*Ptm*<br/>
Ponteiro para `CAtlTransactionManager` um objeto.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro não zero definido em Winerror.h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpriv.h

## <a name="afxregdeletekey"></a><a name="afxregdeletekey"></a>AfxRegDeletekey

Exclui a chave de registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegDeleteKey(HKEY hKey, LPCTSTR lpSubKey, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hkey*<br/>
Uma alça para uma chave de registro aberta.

*lpSubKey*<br/>
O nome da chave a ser excluído.

*Ptm*<br/>
Ponteiro para `CAtlTransactionManager` um objeto.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro não zero definido em Winerror.h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpriv.h

## <a name="afxregisterpreviewhandler"></a>

Um ajudante para registrar um manipulador de visualização.

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
Especifica a extensão de arquivo registrada neste manipulador.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="atlregistertypelib"></a><a name="atlregistertypelib"></a>AtlRegisterTypeLib

Essa função é chamada para registrar uma biblioteca de tipos.

```
ATLAPI AtlRegisterTypeLib(HINSTANCE hInstTypeLib, LPCOLESTR lpszIndex);
```

### <a name="parameters"></a>Parâmetros

*hInstTypeLib*<br/>
A alça para a instância do módulo.

*lpszIndex*<br/>
String no formato\\"\N", onde N é o índice inteiro do recurso de biblioteca do tipo. Pode ser NULO se nenhum índice for necessário.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esta função auxiliar é utilizada por [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver) e [CAtlComModule::RegisterTypeLib](../../atl/reference/catlcommodule-class.md#registertypelib).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="afxregopenkey"></a><a name="afxregopenkey"></a>AfxRegOpenkey

Abre a chave de registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegOpenKey(HKEY hKey, LPCTSTR lpSubKey, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hkey*<br/>
Uma alça para uma chave de registro aberta.

*lpSubKey*<br/>
O nome de uma chave que esta função abre ou cria.

*phkResult*<br/>
Um ponteiro para uma variável que recebe uma alça para a tecla criada.

*Ptm*<br/>
Ponteiro para `CAtlTransactionManager` um objeto.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro não zero definido em Winerror.h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpriv.h

## <a name="afxregopenkeyex"></a><a name="afxregopenkeyex"></a>AfxRegOpenKeyEx

Abre a chave de registro especificada.

### <a name="syntax"></a>Sintaxe

```
LONG AFXAPI AfxRegOpenKeyEx(HKEY hKey, LPCTSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hkey*<br/>
Uma alça para uma chave de registro aberta.

*lpSubKey*<br/>
O nome de uma chave que esta função abre ou cria.

*ulOptions*<br/>
Este parâmetro é reservado e deve ser zero.

*samDesired*<br/>
Uma máscara que especifica os direitos de acesso desejados à chave.

*phkResult*<br/>
Um ponteiro para uma variável que recebe uma alça para a tecla aberta.

*Ptm*<br/>
Ponteiro para `CAtlTransactionManager` um objeto.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro não zero definido em Winerror.h.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpriv.h

## <a name="afxunregisterpreviewhandler"></a><a name="afxunregisterpreviewhandler"></a>AfxUnregisterPreviewHandler

Um ajudante para cancelar o registro de um manipulador de visualização.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxUnRegisterPreviewHandler(LPCTSTR lpszCLSID);
```

### <a name="parameters"></a>Parâmetros

*lpszCLSID*<br/>
Especifica o CLSID do manipulador para não ser registrado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="atlsetperuserregistration"></a><a name="atlsetperuserregistration"></a>AtlSetPerUserRegistration

Define se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** **(HKCU).**

### <a name="syntax"></a>Sintaxe

```
ATLINLINE ATLAPI AtlSetPerUserRegistration(bool bEnable);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE indica que as informações do registro são direcionadas ao nó **HKCU;** FALSE indica que o aplicativo grava informações de registro para o nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem sucedido, caso contrário, o código de erro HRESULT se ocorrer um erro.

### <a name="remarks"></a>Comentários

O redirecionamento do registro não é habilitado por padrão. Se você habilitar essa opção, o acesso ao registro será redirecionado para **HKEY_CURRENT_USER\Software\Classes**.

O redirecionamento não é global. Apenas as estruturas MFC e ATL são afetadas por esse redirecionamento de registro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atlunregistertypelib"></a><a name="atlunregistertypelib"></a>AtlUnRegisterTypeLib

Essa função é chamada para cancelar o registro de uma biblioteca de tipos.

### <a name="syntax"></a>Sintaxe

```
ATLAPI AtlUnRegisterTypeLib(
    HINSTANCE hInstTypeLib,
    LPCOLESTR lpszIndex);
```

### <a name="parameters"></a>Parâmetros

*hInstTypeLib*<br/>
A alça para a instância do módulo.

*lpszIndex*<br/>
String no formato\\"\N", onde N é o índice inteiro do recurso de biblioteca do tipo. Pode ser NULO se nenhum índice for necessário.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esta função de ajudante é utilizada pelo [CAtlComModule::UnRegisterTypeLib](../../atl/reference/catlcommodule-class.md#unregistertypelib) e [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atlloadtypelib"></a><a name="atlloadtypelib"></a>AtlLoadTypeLib

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
Manuseie o módulo associado à biblioteca do tipo.

*lpszIndex*<br/>
String no formato\\"\N", onde N é o índice inteiro do recurso de biblioteca do tipo. Pode ser NULO se nenhum índice for necessário.

*pbstrPath*<br/>
No retorno bem-sucedido, contém o caminho completo do módulo associado à biblioteca do tipo.

*ppTypeLib*<br/>
No retorno bem-sucedido, contém um ponteiro para um ponteiro para a biblioteca do tipo carregado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esta função auxiliar é utilizada por [AtlRegisterTypeLib](#atlregistertypelib) e [AtlUnRegisterTypeLib](#atlunregistertypelib).

## <a name="atlupdateregistryfromresourced"></a><a name="atlupdateregistryfromresourced"></a>AtlUpdateRegistryFromResourceD

Esta função foi preterida no Visual Studio 2013 e removida no Visual Studio 2015.

```
<removed>
```

## <a name="registrydataexchange"></a><a name="registrydataexchange"></a>Registrydataexchange

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
Um valor enum que indica qual operação a função deve executar. Veja a tabela na seção Observações para os valores permitidos.

*Pitem*<br/>
Ponteiro para os dados que devem ser lidos ou escritos para o registro. Os dados também podem representar uma chave a ser excluída do registro. O valor padrão é NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

As macros [BEGIN_RDX_MAP](registry-data-exchange-macros.md#begin_rdx_map) e [END_RDX_MAP](registry-data-exchange-macros.md#end_rdx_map) se `RegistryDataExchange`expandem para uma função que chama .

Os possíveis valores de enum que indicam a operação que a função deve executar são mostrados na tabela a seguir:

|Valor enum|Operação|
|----------------|---------------|
|eReadFromReg|Leia os dados do registro.|
|eWriteToReg|Escreva dados para o registro.|
|eDeleteFromReg|Exclua a chave do registro.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="see-also"></a>Confira também

[Funções](atl-functions.md)<br/>
[Macros de troca de dados de registro](registry-data-exchange-macros.md)
