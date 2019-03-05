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
ms.openlocfilehash: f01734d4ec9de323325dc793756f421388542ef2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57302007"
---
# <a name="catlmodule-class"></a>Classe CAtlModule

Essa classe fornece métodos usados por várias classes de módulo ATL.

## <a name="syntax"></a>Sintaxe

```
class ATL_NO_VTABLE CAtlModule : public _ATL_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModule::CAtlModule](#catlmodule)|O construtor.|
|[CAtlModule:: ~ CAtlModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements)|Substitua este método para adicionar parâmetros ao mapa de substituição de componente de registro ATL (registrador).|
|[CAtlModule::AddTermFunc](#addtermfunc)|Adiciona uma nova função a ser chamado quando o módulo é encerrado.|
|[CAtlModule::GetGITPtr](#getgitptr)|Retorna o ponteiro de Interface Global.|
|[CAtlModule::GetLockCount](#getlockcount)|Retorna a contagem de bloqueio.|
|[CAtlModule::Lock](#lock)|Incrementa a contagem de bloqueio.|
|[CAtlModule::Term](#term)|Libera todos os membros de dados.|
|[CAtlModule::Unlock](#unlock)|Diminui a contagem de bloqueio.|
|[CAtlModule::UpdateRegistryFromResourceD](#updateregistryfromresourced)|Executa o script contido em um recurso especificado ao registrar ou cancelar o registro de um objeto.|
|[CAtlModule::UpdateRegistryFromResourceDHelper](#updateregistryfromresourcedhelper)|Esse método é chamado pelo `UpdateRegistryFromResourceD` para executar a atualização do registro.|
|[CAtlModule::UpdateRegistryFromResourceS](#updateregistryfromresources)|Executa o script contido em um recurso especificado ao registrar ou cancelar o registro de um objeto. Este método vincula estaticamente para o componente de registro ATL.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModule::m_libid](#m_libid)|Contém o GUID do módulo atual.|
|[CAtlModule::m_pGIT](#m_pgit)|Ponteiro para a tabela de Interface Global.|

## <a name="remarks"></a>Comentários

Essa classe é usada pelo [classe CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md), [classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md), e [classe CAtlServiceModuleT](../../atl/reference/catlservicemodulet-class.md) para fornecer suporte para aplicativos de DLL, aplicativos EXE, e Serviços de Windows, respectivamente.

Para obter mais informações sobre módulos em ATL, consulte [Classes de módulo ATL](../../atl/atl-module-classes.md).

Essa classe substitui o obsoletos [classe CComModule](../../atl/reference/ccommodule-class.md) usado em versões anteriores do ATL.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

`CAtlModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="addcommonrgsreplacements"></a>  CAtlModule::AddCommonRGSReplacements

Substitua este método para adicionar parâmetros ao mapa de substituição de componente de registro ATL (registrador).

```
virtual HRESULT AddCommonRGSReplacements(IRegistrarBase* /* pRegistrar*/) throw() = 0;
```

### <a name="parameters"></a>Parâmetros

*pRegistrar*<br/>
Reservado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Parâmetros substituíveis permitem que o cliente de um registrador especificar dados de tempo de execução. Para fazer isso, o registrador mantém um mapa de substituição no qual ele insere os valores associados com os parâmetros substituíveis em seu script. O registrador torna essas entradas em tempo de execução.

Consulte o tópico [usando parâmetros substituíveis (pré-processador do registrador The)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) para obter mais detalhes.

##  <a name="addtermfunc"></a>  CAtlModule::AddTermFunc

Adiciona uma nova função a ser chamado quando o módulo é encerrado.

```
HRESULT AddTermFunc(_ATL_TERMFUNC* pFunc, DWORD_PTR dw) throw();
```

### <a name="parameters"></a>Parâmetros

*pFunc*<br/>
Ponteiro para a função para adicionar.

*dw*<br/>
Dados definidos pelo usuário, passados para a função.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="catlmodule"></a>  CAtlModule::CAtlModule

O construtor.

```
CAtlModule() throw();
```

### <a name="remarks"></a>Comentários

Inicializa os membros de dados e inicia uma seção crítica em torno do thread do módulo.

##  <a name="dtor"></a>  CAtlModule:: ~ CAtlModule

O destruidor.

```
~CAtlModule() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados.

##  <a name="getgitptr"></a>  CAtlModule::GetGITPtr

Recupera um ponteiro para a tabela de Interface Global.

```
virtual HRESULT GetGITPtr(IGlobalInterfaceTable** ppGIT) throw();
```

### <a name="parameters"></a>Parâmetros

*ppGIT*<br/>
Ponteiro para a variável que receberá o ponteiro para a tabela de Interface Global.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um código de erro em caso de falha. E_POINTER é retornada se *ppGIT* é igual a NULL.

### <a name="remarks"></a>Comentários

Se o objeto de tabela de Interface Global não existe, ele é criado e seu endereço é armazenado na variável membro [CAtlModule::m_pGIT](#m_pgit).

Em compilações de depuração, um erro de asserção ocorrerá se *ppGIT* é igual a NULL, ou se o ponteiro da tabela de Interface Global não pode ser obtido.

Ver [IGlobalInterfaceTable](/windows/desktop/api/objidl/nn-objidl-iglobalinterfacetable) para obter informações sobre a tabela de Interface Global.

##  <a name="getlockcount"></a>  CAtlModule::GetLockCount

Retorna a contagem de bloqueio.

```
virtual LONG GetLockCount() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a contagem de bloqueio. Esse valor pode ser útil para diagnóstico e depuração.

##  <a name="lock"></a>  CAtlModule::Lock

Incrementa a contagem de bloqueio.

```
virtual LONG Lock() throw();
```

### <a name="return-value"></a>Valor de retorno

Incrementa a contagem de bloqueio e retorna o valor atualizado. Esse valor pode ser útil para diagnóstico e depuração.

##  <a name="m_libid"></a>  CAtlModule::m_libid

Contém o GUID do módulo atual.

```
static GUID m_libid;
```

##  <a name="m_pgit"></a>  CAtlModule::m_pGIT

Ponteiro para a tabela de Interface Global.

```
IGlobalInterfaceTable* m_pGIT;
```

##  <a name="term"></a>  CAtlModule::Term

Libera todos os membros de dados.

```
void Term() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados. Este método é chamado pelo destruidor.

##  <a name="unlock"></a>  CAtlModule::Unlock

Diminui a contagem de bloqueio.

```
virtual LONG Unlock() throw();
```

### <a name="return-value"></a>Valor de retorno

Diminui a contagem de bloqueio e retorna o valor atualizado. Esse valor pode ser útil para diagnóstico e depuração.

##  <a name="updateregistryfromresourced"></a>  CAtlModule::UpdateRegistryFromResourceD

Executa o script contido em um recurso especificado ao registrar ou cancelar o registro de um objeto.

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
TRUE se o objeto deve ser registrado; FALSE caso contrário.

*pMapEntries*<br/>
Um ponteiro para o mapa de substituição armazenar valores associados com parâmetros substituíveis do script. ATL usa automaticamente o módulo %. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Executa o script contido no recurso especificado pela *lpszRes ou nResID*. Se *bRegistre-se participar* for TRUE, esse método registra o objeto no registro do sistema; caso contrário, ele remove o objeto do registro.

Para vincular estaticamente para o componente de registro ATL (registrador), consulte [CAtlModule::UpdateRegistryFromResourceS](#updateregistryfromresources).

Este método chama [CAtlModule::UpdateRegistryFromResourceDHelper](#updateregistryfromresourcedhelper) e [IRegistrar::ResourceUnregister](iregistrar-class.md#resourceunregister).

##  <a name="updateregistryfromresourcedhelper"></a>  CAtlModule::UpdateRegistryFromResourceDHelper

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
Um ponteiro para o mapa de substituição armazenar valores associados com parâmetros substituíveis do script. ATL usa automaticamente o módulo %. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método fornece a implementação de [CAtlModule::UpdateRegistryFromResourceD](#updateregistryfromresourced).

##  <a name="updateregistryfromresources"></a>  CAtlModule::UpdateRegistryFromResourceS

Executa o script contido em um recurso especificado ao registrar ou cancelar o registro de um objeto. Este método vincula estaticamente para o componente de registro ATL.

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
Um ponteiro para o mapa de substituição armazenar valores associados com parâmetros substituíveis do script. ATL usa automaticamente o módulo %. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Semelhante ao [CAtlModule::UpdateRegistryFromResourceD](#updateregistryfromresourced) exceto `CAtlModule::UpdateRegistryFromResourceS` cria um link estático para o componente de registro ATL (registrador).

## <a name="see-also"></a>Consulte também

[_ATL_MODULE](atl-typedefs.md#_atl_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)<br/>
[Componente de registro (Registrar)](../../atl/atl-registry-component-registrar.md)
