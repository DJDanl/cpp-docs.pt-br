---
title: Classe CAtlModule
ms.date: 11/04/2016
f1_keywords:
- CAtlModule
- ATLBASE/ATL::CAtlModule
- ATLBASE/ATL::CAtlModule::CAtlModule
- ATLBASE/ATL::CAtlModule::AddCommonRGSReplacements
- ATLBASE/ATL::CAtlModule::AddTermFunc
- ATLBASE/ATL::CAtlModule::GetGITPtr
- ATLBASE/ATL::CAtlModule::GetLockCount
- ATLBASE/ATL::CAtlModule::Lock
- ATLBASE/ATL::CAtlModule::Term
- ATLBASE/ATL::CAtlModule::Unlock
- ATLBASE/ATL::CAtlModule::UpdateRegistryFromResourceD
- ATLBASE/ATL::CAtlModule::UpdateRegistryFromResourceDHelper
- ATLBASE/ATL::CAtlModule::UpdateRegistryFromResourceS
- ATLBASE/ATL::CAtlModule::m_libid
- ATLBASE/ATL::CAtlModule::m_pGIT
helpviewer_keywords:
- CAtlModule class
ms.assetid: 63fe02f1-4c4b-4e7c-ae97-7ad7b4252415
ms.openlocfilehash: 798e94aed3bbd98108866ce0a1810485bd68699b
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78857128"
---
# <a name="catlmodule-class"></a>Classe CAtlModule

Essa classe fornece métodos usados por várias classes de módulo ATL.

## <a name="syntax"></a>Sintaxe

```
class ATL_NO_VTABLE CAtlModule : public _ATL_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAtlModule::CAtlModule](#catlmodule)|O construtor.|
|[CAtlModule:: ~ CAtlModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements)|Substitua esse método para adicionar parâmetros ao mapa de substituição do componente de registro do ATL (registrador).|
|[CAtlModule::AddTermFunc](#addtermfunc)|Adiciona uma nova função a ser chamada quando o módulo é encerrado.|
|[CAtlModule::GetGITPtr](#getgitptr)|Retorna o ponteiro de interface global.|
|[CAtlModule::GetLockCount](#getlockcount)|Retorna a contagem de bloqueios.|
|[CAtlModule:: Lock](#lock)|Incrementa a contagem de bloqueios.|
|[CAtlModule:: termo](#term)|Libera todos os membros de dados.|
|[CAtlModule:: desbloquear](#unlock)|Diminui a contagem de bloqueio.|
|[CAtlModule::UpdateRegistryFromResourceD](#updateregistryfromresourced)|Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto.|
|[CAtlModule::UpdateRegistryFromResourceDHelper](#updateregistryfromresourcedhelper)|Esse método é chamado pelo `UpdateRegistryFromResourceD` para executar a atualização do registro.|
|[CAtlModule::UpdateRegistryFromResourceS](#updateregistryfromresources)|Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto. Esse método é vinculado estaticamente ao componente de registro do ATL.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAtlModule:: m_libid](#m_libid)|Contém o GUID do módulo atual.|
|[CAtlModule:: m_pGIT](#m_pgit)|Ponteiro para a tabela de interface global.|

## <a name="remarks"></a>Comentários

Essa classe é usada pela classe [CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md), [classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)e [classe CAtlServiceModuleT](../../atl/reference/catlservicemodulet-class.md) para fornecer suporte para aplicativos dll, aplicativos exe e serviços do Windows, respectivamente.

Para obter mais informações sobre módulos na ATL, consulte [classes de módulo do ATL](../../atl/atl-module-classes.md).

Essa classe substitui a [classe CComModule](../../atl/reference/ccommodule-class.md) obsoleta usada em versões anteriores do ATL.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

`CAtlModule`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlbase. h

##  <a name="addcommonrgsreplacements"></a>CAtlModule::AddCommonRGSReplacements

Substitua esse método para adicionar parâmetros ao mapa de substituição do componente de registro do ATL (registrador).

```
virtual HRESULT AddCommonRGSReplacements(IRegistrarBase* /* pRegistrar*/) throw() = 0;
```

### <a name="parameters"></a>Parâmetros

*pRegistrar*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Os parâmetros substituíveis permitem que o cliente do registrador especifique dados de tempo de execução. Para fazer isso, o registrador mantém um mapa de substituição no qual ele insere os valores associados aos parâmetros substituíveis em seu script. O registrador faz essas entradas em tempo de execução.

Consulte o tópico [usando parâmetros substituíveis (o pré-processador do registrador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) para obter mais detalhes.

##  <a name="addtermfunc"></a>CAtlModule::AddTermFunc

Adiciona uma nova função a ser chamada quando o módulo é encerrado.

```
HRESULT AddTermFunc(_ATL_TERMFUNC* pFunc, DWORD_PTR dw) throw();
```

### <a name="parameters"></a>Parâmetros

*pFunc*<br/>
Ponteiro para a função a ser adicionada.

*dw*<br/>
Dados definidos pelo usuário, passados para a função.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="catlmodule"></a>CAtlModule::CAtlModule

O construtor.

```
CAtlModule() throw();
```

### <a name="remarks"></a>Comentários

Inicializa membros de dados e inicia uma seção crítica em volta do thread do módulo.

##  <a name="dtor"></a>CAtlModule:: ~ CAtlModule

O destruidor.

```
~CAtlModule() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados.

##  <a name="getgitptr"></a>CAtlModule::GetGITPtr

Recupera um ponteiro para a tabela de interface global.

```
virtual HRESULT GetGITPtr(IGlobalInterfaceTable** ppGIT) throw();
```

### <a name="parameters"></a>Parâmetros

*ppGIT*<br/>
Ponteiro para a variável que receberá o ponteiro para a tabela de interface global.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um código de erro em caso de falha. E_POINTER será retornado se *ppGIT* for igual a NULL.

### <a name="remarks"></a>Comentários

Se o objeto da tabela de interface global não existir, ele será criado e seu endereço será armazenado na variável de membro [CAtlModule:: m_pGIT](#m_pgit).

Em compilações de depuração, ocorrerá um erro de asserção se *ppGIT* for igual a NULL ou se o ponteiro de tabela de interface global não puder ser obtido.

Consulte [IGlobalInterfaceTable](/windows/win32/api/objidl/nn-objidl-iglobalinterfacetable) para obter informações sobre a tabela de interface global.

##  <a name="getlockcount"></a>CAtlModule::GetLockCount

Retorna a contagem de bloqueios.

```
virtual LONG GetLockCount() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a contagem de bloqueios. Esse valor pode ser útil para diagnóstico e depuração.

##  <a name="lock"></a>CAtlModule:: Lock

Incrementa a contagem de bloqueios.

```
virtual LONG Lock() throw();
```

### <a name="return-value"></a>Valor retornado

Incrementa a contagem de bloqueios e retorna o valor atualizado. Esse valor pode ser útil para diagnóstico e depuração.

##  <a name="m_libid"></a>CAtlModule:: m_libid

Contém o GUID do módulo atual.

```
static GUID m_libid;
```

##  <a name="m_pgit"></a>CAtlModule:: m_pGIT

Ponteiro para a tabela de interface global.

```
IGlobalInterfaceTable* m_pGIT;
```

##  <a name="term"></a>CAtlModule:: termo

Libera todos os membros de dados.

```
void Term() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados. Esse método é chamado pelo destruidor.

##  <a name="unlock"></a>CAtlModule:: desbloquear

Diminui a contagem de bloqueio.

```
virtual LONG Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Decrementa a contagem de bloqueios e retorna o valor atualizado. Esse valor pode ser útil para diagnóstico e depuração.

##  <a name="updateregistryfromresourced"></a>CAtlModule::UpdateRegistryFromResourceD

Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto.

```
HRESULT WINAPI UpdateRegistryFromResourceD(
    UINT nResID,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();

HRESULT WINAPI UpdateRegistryFromResourceD(
    LPCTSTR lpszRes,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszRes*<br/>
Um nome de recurso.

*nResID*<br/>
Uma ID de recurso.

*bRegister*<br/>
TRUE se o objeto deve ser registrado; Caso contrário, FALSE.

*pMapEntries*<br/>
Um ponteiro para o mapa de substituição que armazena valores associados aos parâmetros substituíveis do script. A ATL usa automaticamente% MODULE%. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule:: AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão nulo.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Executa o script contido no recurso especificado por *lpszRes ou nResID*. Se *bRegister* for true, esse método registrará o objeto no registro do sistema; caso contrário, ele removerá o objeto do registro.

Para vincular estaticamente ao componente do registro ATL (registrador), consulte [CAtlModule:: UpdateRegistryFromResourceS](#updateregistryfromresources).

Esse método chama [CAtlModule:: UpdateRegistryFromResourceDHelper](#updateregistryfromresourcedhelper) e [IRegistrar:: ResourceUnregister](iregistrar-class.md#resourceunregister).

##  <a name="updateregistryfromresourcedhelper"></a>CAtlModule::UpdateRegistryFromResourceDHelper

Esse método é chamado pelo `UpdateRegistryFromResourceD` para executar a atualização do registro.

```
inline HRESULT WINAPI UpdateRegistryFromResourceDHelper(
    LPCOLESTR lpszRes,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszRes*<br/>
Um nome de recurso.

*bRegister*<br/>
Indica se o objeto deve ser registrado.

*pMapEntries*<br/>
Um ponteiro para o mapa de substituição que armazena valores associados aos parâmetros substituíveis do script. A ATL usa automaticamente% MODULE%. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule:: AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão nulo.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método fornece a implementação de [CAtlModule:: UpdateRegistryFromResourceD](#updateregistryfromresourced).

##  <a name="updateregistryfromresources"></a>CAtlModule::UpdateRegistryFromResourceS

Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto. Esse método é vinculado estaticamente ao componente de registro do ATL.

```
HRESULT WINAPI UpdateRegistryFromResourceS(
    UINT nResID,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();

HRESULT WINAPI UpdateRegistryFromResourceS(
    LPCTSTR lpszRes,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*nResID*<br/>
Uma ID de recurso.

*lpszRes*<br/>
Um nome de recurso.

*bRegister*<br/>
Indica se o script de recurso deve ser registrado.

*pMapEntries*<br/>
Um ponteiro para o mapa de substituição que armazena valores associados aos parâmetros substituíveis do script. A ATL usa automaticamente% MODULE%. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule:: AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão nulo.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Semelhante a [CAtlModule:: UpdateRegistryFromResourceD](#updateregistryfromresourced) , exceto `CAtlModule::UpdateRegistryFromResourceS` cria um link estático para o componente do registro ATL (registrador).

## <a name="see-also"></a>Consulte também

[_ATL_MODULE](atl-typedefs.md#_atl_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)<br/>
[Componente de Registro (Registrador)](../../atl/atl-registry-component-registrar.md)
