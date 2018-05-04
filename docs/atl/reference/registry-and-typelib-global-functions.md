---
title: Funções globais do registro e TypeLib | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- RegistryDataExchange function, global functions
ms.assetid: d58b8a4e-975c-4417-8b34-d3c847f679b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb0a89ecf8bb81e515703abe819bb1edfbf80d59
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="registry-and-typelib-global-functions"></a>Funções globais do registro e TypeLib
Essas funções fornecem suporte para carregar e registrar uma biblioteca de tipos.  
  
> [!IMPORTANT]
>  As funções listadas nas tabelas a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AfxRegCreateKey](#afxrefcreatekey)|Cria a chave do Registro especificada.|
|[AfxRegDeleteKey](#afxrefdeletekey)|Exclui a chave do Registro especificada.|
|[AfxRegisterPreviewHandler](#afxregisterpreviewhandler)|Um auxiliar para registrar um manipulador de visualização.|
|[AfxUnregisterPreviewHandler](#afxunregisterpreviewhandler)| Um auxiliar para cancelar o registro de um manipulador de visualização. |
|[AtlRegisterTypeLib](#atlregistertypelib)|Essa função é chamada para registrar uma biblioteca de tipos.|  
|[AtlUnRegisterTypeLib](#atlunregistertypelib)|Essa função é chamada para cancelar o registro de uma biblioteca de tipos|  
|[AfxRegOpenKey](#afxregopenkey)|Abre a chave do Registro especificada.|
|[AfxRegOpenKeyEx](#afxregopenkeyex)|Abre a chave do Registro especificada.|
|[AtlLoadTypeLib](#atlloadtypelib)|Essa função é chamada para carregar uma biblioteca de tipos.|  
|[AtlUpdateRegistryFromResourceD](#atlupdateregistryfromresourced)|Essa função é chamada para atualizar o Registro de recurso fornecido.|  
|[RegistryDataExchange](#registrydataexchange)|Essa função é chamada para ler do ou gravar no Registro do sistema. Chamado pelo [Macros de troca de dados de registro](../../atl/reference/registry-data-exchange-macros.md).|  
  
 Essas funções controlam qual nó o programa usa para armazenar informações de registro.  
  
|||  
|-|-|  
|[AtlGetPerUserRegistration](#atlgetperuserregistration)|Recupera se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AtlSetPerUserRegistration](#atlsetperuserregistration)|Define se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase

## <a name="atlgetperuserregistration"></a> AtlGetPerUserRegistration
Use esta função para determinar se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** (**HKCU**) nó.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ATLINLINE ATLAPI AtlGetPerUserRegistration(bool* pEnabled);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `pEnabled`  
 `TRUE` indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava informações de registro para o nó de padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK` Se o método for bem-sucedido, caso contrário, o `HRESULT` código de erro se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Redirecionamento do registro não está habilitado por padrão. Se você habilitar essa opção, o acesso ao registro é redirecionado para **HKEY_CURRENT_USER\Software\Classes**.  
  
 O redirecionamento não é global. Somente as estruturas de MFC e ATL são afetadas por esse redirecionamento do registro.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  

 ## <a name="afxregcreatekey"></a> AfxRegCreateKey
 Cria a chave do Registro especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
LONG AFXAPI AfxRegCreateKey(HKEY hKey, LPCTSTR lpSubKey, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKey`  
 Um identificador para uma chave do Registro aberta.  
  
 `lpSubKey`  
 O nome de uma chave que essa função é aberta ou cria.  
  
 `phkResult`  
 Um ponteiro para uma variável que recebe um identificador para a chave aberto ou criado.  
  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito, o valor de retorno é ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido no Winerror. h.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  

## <a name="afxregdeletekey"></a> AfxRegDeleteKey
Exclui a chave do Registro especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
LONG AFXAPI AfxRegDeleteKey(HKEY hKey, LPCTSTR lpSubKey, CAtlTransactionManager* pTM = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKey`  
 Um identificador para uma chave do Registro aberta.  
  
 `lpSubKey`  
 O nome da chave a ser excluído.  
  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito, o valor de retorno é ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido no Winerror. h.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  

## <a name="afxregisterpreviewhandler"></a>
Um auxiliar para registrar um manipulador de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
BOOL AFXAPI AfxRegisterPreviewHandler(LPCTSTR lpszCLSID, LPCTSTR lpszShortTypeName, LPCTSTR lpszFilterExt);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszCLSID`  
 Especifica o CLSID do manipulador.  
  
 `lpszShortTypeName`  
 Especifica o ProgID do manipulador.  
  
 `lpszFilterExt`  
 Especifica a extensão de arquivo registrado com este manipulador.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h   

##  <a name="atlregistertypelib"></a>  AtlRegisterTypeLib  
 Essa função é chamada para registrar uma biblioteca de tipos.  
  
  
```
ATLAPI AtlRegisterTypeLib(HINSTANCE hInstTypeLib, LPCOLESTR lpszIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstTypeLib`  
 O identificador para a instância de módulo.  
  
 `lpszIndex`  
 Cadeia de caracteres no formato "\\\N", onde N é o índice inteiro do recurso de biblioteca de tipo. Pode ser NULL se nenhum índice é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar utilizada por [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver) e [CAtlComModule::RegisterTypeLib](../../atl/reference/catlcommodule-class.md#registertypelib).  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase

 ## <a name="afxregopenkey"></a> AfxRegOpenKey
 Abre a chave do Registro especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
LONG AFXAPI AfxRegOpenKey(HKEY hKey, LPCTSTR lpSubKey, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKey`  
 Um identificador para uma chave do Registro aberta.  
  
 `lpSubKey`  
 O nome de uma chave que essa função é aberta ou cria.  
  
 `phkResult`  
 Um ponteiro para uma variável que recebe um identificador para a chave criada.  
  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito, o valor de retorno é ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido no Winerror. h.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  

## <a name="afxregopenkeyex"></a>  AfxRegOpenKeyEx
Abre a chave do Registro especificada. 

### <a name="syntax"></a>Sintaxe  
  
```  
LONG AFXAPI AfxRegOpenKeyEx(HKEY hKey, LPCTSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, CAtlTransactionManager* pTM = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKey`  
 Um identificador para uma chave do Registro aberta.  
  
 `lpSubKey`  
 O nome de uma chave que essa função é aberta ou cria.  
  
 `ulOptions`  
 Esse parâmetro é reservado e deve ser zero.  
  
 `samDesired`  
 Uma máscara que especifica os direitos de acesso desejado para a chave.  
  
 `phkResult`  
 Um ponteiro para uma variável que recebe um identificador para a chave de abertura.  
  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito, o valor de retorno é ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido no Winerror. h.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  

 ## <a name="afxunregisterpreviewhandler"></a> AfxUnregisterPreviewHandler
 Um auxiliar para cancelar o registro de um manipulador de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
BOOL AFXAPI AfxUnRegisterPreviewHandler(LPCTSTR lpszCLSID);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszCLSID`  
 Especifica o CLSID do manipulador para cancelar seu registro.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  

## <a name="atlsetperuserregistration"></a> AtlSetPerUserRegistration
Define se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** (**HKCU**) nó.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ATLINLINE ATLAPI AtlSetPerUserRegistration(bool bEnable);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE` indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava informações de registro para o nó de padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK` Se o método for bem-sucedido, caso contrário, o `HRESULT` código de erro se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Redirecionamento do registro não está habilitado por padrão. Se você habilitar essa opção, o acesso ao registro é redirecionado para **HKEY_CURRENT_USER\Software\Classes**.  
  
 O redirecionamento não é global. Somente as estruturas de MFC e ATL são afetadas por esse redirecionamento do registro.  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  

##  <a name="atlunregistertypelib"></a>  AtlUnRegisterTypeLib  
 Essa função é chamada para cancelar o registro de uma biblioteca de tipos.  
  
### <a name="syntax"></a>Sintaxe  
```
ATLAPI AtlUnRegisterTypeLib(
    HINSTANCE hInstTypeLib, 
    LPCOLESTR lpszIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstTypeLib`  
 O identificador para a instância de módulo.  
  
 `lpszIndex`  
 Cadeia de caracteres no formato "\\\N", onde N é o índice inteiro do recurso de biblioteca de tipo. Pode ser NULL se nenhum índice é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar utilizada por [CAtlComModule::UnRegisterTypeLib](../../atl/reference/catlcommodule-class.md#unregistertypelib) e [AtlComModuleUnregisterServer](#atlcommoduleunregisterserver).  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase

##  <a name="atlloadtypelib"></a>  AtlLoadTypeLib  
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
 `hInstTypeLib`  
 Identificador para o módulo associado com a biblioteca de tipos.  
  
 `lpszIndex`  
 Cadeia de caracteres no formato "\\\N", onde N é o índice inteiro do recurso de biblioteca de tipo. Pode ser NULL se nenhum índice é necessário.  
  
 *pbstrPath*  
 No retorno bem-sucedido, contém o caminho completo do módulo associado com a biblioteca de tipos.  
  
 `ppTypeLib`  
 No retorno bem-sucedido, contém um ponteiro para um ponteiro para a biblioteca de tipos carregados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar utilizada por [AtlRegisterTypeLib](#atlregistertypelib) e [AtlUnRegisterTypeLib](#atlunregistertypelib).  
  
##  <a name="atlupdateregistryfromresourced"></a>  AtlUpdateRegistryFromResourceD  
 Essa função foi preterida no Visual Studio 2013 e será removida no Visual Studio 2015.  
  
```
<removed>
```  
  

  
##  <a name="registrydataexchange"></a>  RegistryDataExchange  
 Essa função é chamada para ler do ou gravar no Registro do sistema.  

### <a name="syntax"></a>Sintaxe  
```
HRESULT RegistryDataExchange(
    T* pT,
    enum RDXOperations rdxOp,
    void* pItem = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 Um ponteiro para o objeto atual.  
  
 *rdxOp*  
 Um valor de enumeração que indica qual operação a função deve ser executada. Consulte a tabela na seção comentários para os valores permitidos.  
  
 `pItem`  
 Ponteiro para os dados a ser lido ou gravado no registro. Os dados também podem representar uma chave a ser excluído do registro. O valor padrão é NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 As macros [BEGIN_RDX_MAP](registry-data-exchange-macros.md#begin_rdx_map) e [END_RDX_MAP](registry-data-exchange-macros.md#end_rdx_map) expandir para uma função que chama `RegistryDataExchange`.  
  
 Os valores de enumeração possíveis que indicam que a operação, a função deve executar são mostrados na tabela a seguir:  
  
|Valor de enumeração|Operação|  
|----------------|---------------|  
|eReadFromReg|Ler dados do registro.|  
|eWriteToReg|Grave dados no registro.|  
|eDeleteFromReg|Exclua a chave do registro.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase

## <a name="see-also"></a>Consulte também  
 [Funções](atl-functions.md) [Macros de troca de dados de registro](registry-data-exchange-macros.md)





