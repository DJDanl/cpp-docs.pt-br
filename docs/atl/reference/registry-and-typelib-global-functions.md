---
title: "Funções globais do registro e TypeLib | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- RegistryDataExchange function, global functions
ms.assetid: d58b8a4e-975c-4417-8b34-d3c847f679b3
caps.latest.revision: 22
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
ms.openlocfilehash: 9d454f2eac1b29785fe40a480fc43c7c34a861a3
ms.lasthandoff: 02/25/2017

---
# <a name="registry-and-typelib-global-functions"></a>Registro e TypeLib funções globais
Essas funções fornecem suporte para carregar e registrar uma biblioteca de tipos.  
  
> [!IMPORTANT]
>  As funções listadas nas tabelas a seguir não podem ser usadas em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlRegisterTypeLib](#atlregistertypelib)|Essa função é chamada para registrar uma biblioteca de tipos.|  
|[AtlUnRegisterTypeLib](#atlunregistertypelib)|Essa função é chamada para cancelar o registro de uma biblioteca de tipos|  
|[AtlLoadTypeLib](#atlloadtypelib)|Essa função é chamada para carregar uma biblioteca de tipos.|  
|[AtlUpdateRegistryFromResourceD](#atlupdateregistryfromresourced)|Essa função é chamada para atualizar o Registro de recurso fornecido.|  
|[RegistryDataExchange](#registrydataexchange)|Essa função é chamada para ler do ou gravar no Registro do sistema. Chamando o [Macros de troca de dados de registro](../../atl/reference/registry-data-exchange-macros.md).|  
  
 Essas funções controlam qual nó no registro o programa usa para armazenar informações.  
  
|||  
|-|-|  
|[AtlGetPerUserRegistration](#atlgetperuserregistration)|Recupera o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AtlSetPerUserRegistration](#atlsetperuserregistration)|Define se o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** ( **HKCU**) nó.|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h

## <a name="a-nameatlgetperuserregistrationa-atlgetperuserregistration"></a><a name="atlgetperuserregistration"></a>AtlGetPerUserRegistration
Use esta função para determinar se o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** (**HKCU**) nó.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ATLINLINE ATLAPI AtlGetPerUserRegistration(bool* pEnabled);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `pEnabled`  
 `TRUE`indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava as informações de registro do nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se o método for bem-sucedido, caso contrário, o `HRESULT` código de erro se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Redirecionamento do registro não está habilitado por padrão. Se você habilitar essa opção, o acesso ao registro é redirecionado para **HKEY_CURRENT_USER\Software\Classes**.  
  
 O redirecionamento não é global. Somente as estruturas MFC e ATL são afetadas por esse redirecionamento do registro.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  

##  <a name="a-nameatlregistertypeliba--atlregistertypelib"></a><a name="atlregistertypelib"></a>AtlRegisterTypeLib  
 Essa função é chamada para registrar uma biblioteca de tipos.  
  
  
```
ATLAPI AtlRegisterTypeLib(HINSTANCE hInstTypeLib, LPCOLESTR lpszIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstTypeLib`  
 O identificador para a instância de módulo.  
  
 `lpszIndex`  
 Cadeia de caracteres no formato "\\\N", onde N é o índice de recurso da biblioteca de tipo inteiro. Pode ser NULL se nenhum índice é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar é utilizada por [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver) e [CAtlComModule::RegisterTypeLib](../../atl/reference/catlcommodule-class.md#registertypelib).  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h

## <a name="a-nameatlsetperuserregistrationa-atlsetperuserregistration"></a><a name="atlsetperuserregistration"></a>AtlSetPerUserRegistration
Define se o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** (**HKCU**) nó.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ATLINLINE ATLAPI AtlSetPerUserRegistration(bool bEnable);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava as informações de registro do nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se o método for bem-sucedido, caso contrário, o `HRESULT` código de erro se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Redirecionamento do registro não está habilitado por padrão. Se você habilitar essa opção, o acesso ao registro é redirecionado para **HKEY_CURRENT_USER\Software\Classes**.  
  
 O redirecionamento não é global. Somente as estruturas MFC e ATL são afetadas por esse redirecionamento do registro.  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  

##  <a name="a-nameatlunregistertypeliba--atlunregistertypelib"></a><a name="atlunregistertypelib"></a>AtlUnRegisterTypeLib  
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
 Cadeia de caracteres no formato "\\\N", onde N é o índice de recurso da biblioteca de tipo inteiro. Pode ser NULL se nenhum índice é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar é utilizada por [CAtlComModule::UnRegisterTypeLib](../../atl/reference/catlcommodule-class.md#unregistertypelib) e [AtlComModuleUnregisterServer](#atlcommoduleunregisterserver).  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h

##  <a name="a-nameatlloadtypeliba--atlloadtypelib"></a><a name="atlloadtypelib"></a>AtlLoadTypeLib  
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
 Cadeia de caracteres no formato "\\\N", onde N é o índice de recurso da biblioteca de tipo inteiro. Pode ser NULL se nenhum índice é necessário.  
  
 *pbstrPath*  
 No retorno bem-sucedido, contém o caminho completo do módulo associado com a biblioteca de tipos.  
  
 `ppTypeLib`  
 No retorno bem-sucedido, contém um ponteiro para um ponteiro para a biblioteca de tipos carregados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar é utilizada por [AtlRegisterTypeLib](#atlregistertypelib) e [AtlUnRegisterTypeLib](#atlunregistertypelib).  
  
##  <a name="a-nameatlupdateregistryfromresourceda--atlupdateregistryfromresourced"></a><a name="atlupdateregistryfromresourced"></a>AtlUpdateRegistryFromResourceD  
 Essa função foi substituída no Visual Studio 2013 e é removida no Visual Studio 2015.  
  
```
<removed>
```  
  
### <a name="parameters"></a>Parâmetros  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameregistrydataexchangea--registrydataexchange"></a><a name="registrydataexchange"></a>RegistryDataExchange  
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
 Um valor de enumeração que indica qual operação deve executar a função. Consulte a tabela na seção comentários para os valores permitidos.  
  
 `pItem`  
 Ponteiro para os dados que deve ser lida ou gravada no registro. Os dados também podem representar uma chave a ser excluído do registro. O valor padrão é NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 As macros [BEGIN_RDX_MAP](registry-data-exchange-macros.md#begin_rdx_map) e [END_RDX_MAP](registry-data-exchange-macros.md#end_rdx_map) expandir para uma função que chama `RegistryDataExchange`.  
  
 Os valores de enumeração possíveis que indicam que a operação a função deve executar são mostrados na tabela a seguir:  
  
|Valor de enumeração|Operação|  
|----------------|---------------|  
|eReadFromReg|Ler dados do registro.|  
|eWriteToReg|Grava dados no registro.|  
|eDeleteFromReg|Exclua a chave do registro.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também  
 [Funções](atl-functions.md)
 [Macros de troca de dados de registro](registry-data-exchange-macros.md)






