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
ms.openlocfilehash: 378c8634e00935c622f0bf5d06a4f6c50cc60cb6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321431"
---
# <a name="catlmodule-class"></a>Classe CAtlModule

Esta classe fornece métodos usados por várias classes de móduloATL.

## <a name="syntax"></a>Sintaxe

```
class ATL_NO_VTABLE CAtlModule : public _ATL_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModule::CAtlModule](#catlmodule)|O construtor.|
|[CAtlModule::~CAtlModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements)|Substitua este método para adicionar parâmetros ao mapa de substituição do Registro ATL (Registrador).|
|[CAtlModule::AddTermFunc](#addtermfunc)|Adiciona uma nova função a ser chamada quando o módulo terminar.|
|[CAtlModule::GetGITPtr](#getgitptr)|Retorna o Ponteiro de Interface Global.|
|[CAtlModule::GetLockCount](#getlockcount)|Retorna a contagem de bloqueios.|
|[CAtlModule::Bloqueio](#lock)|Incrementa a contagem de bloqueios.|
|[CAtlModule::Term](#term)|Libera todos os membros de dados.|
|[CAtlModule::Unlock](#unlock)|Diminui a contagem de bloqueio.|
|[CAtlModule::AtualizaçãoRegistroDeRecursoD](#updateregistryfromresourced)|Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto.|
|[CAtlModule::AtualizaçãoRegistroDeRecursoDeRecursosHelper](#updateregistryfromresourcedhelper)|Este método é `UpdateRegistryFromResourceD` chamado para realizar a atualização do registro.|
|[CAtlModule::AtualizaçãoRegistroDeRecursos](#updateregistryfromresources)|Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto. Este método é vinculado estáticamente ao componente de registro ATL.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModule::m_libid](#m_libid)|Contém o GUID do módulo atual.|
|[CAtlModule::m_pGIT](#m_pgit)|Ponteiro para a tabela de interface global.|

## <a name="remarks"></a>Comentários

Esta classe é usada por [CAtlDllModuleT Class,](../../atl/reference/catldllmodulet-class.md) [CAtlExeModuleT Class](../../atl/reference/catlexemodulet-class.md)e [CAtlServiceModuleT Class](../../atl/reference/catlservicemodulet-class.md) para fornecer suporte para aplicativos DLL, aplicativos EXE e serviços Windows, respectivamente.

Para obter mais informações sobre módulos em ATL, consulte [ATL Module Classes](../../atl/atl-module-classes.md).

Esta classe substitui a obsoleta [Classe CComModule](../../atl/reference/ccommodule-class.md) usada em versões anteriores do ATL.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

`CAtlModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catlmoduleaddcommonrgsreplacements"></a><a name="addcommonrgsreplacements"></a>CAtlModule::AddCommonRGSReplacements

Substitua este método para adicionar parâmetros ao mapa de substituição do Registro ATL (Registrador).

```
virtual HRESULT AddCommonRGSReplacements(IRegistrarBase* /* pRegistrar*/) throw() = 0;
```

### <a name="parameters"></a>Parâmetros

*pRegistrador*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Os parâmetros substituíveis permitem que o cliente do Registrador especifique dados de tempo de execução. Para isso, o Registrador mantém um mapa de substituição no qual ele insere os valores associados aos parâmetros substituíveis em seu script. O Registrador faz essas entradas em tempo de execução.

Consulte o tópico [Usando parâmetros substituíveis (pré-processador do registrador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) para obter mais detalhes.

## <a name="catlmoduleaddtermfunc"></a><a name="addtermfunc"></a>CAtlModule::AddTermFunc

Adiciona uma nova função a ser chamada quando o módulo terminar.

```
HRESULT AddTermFunc(_ATL_TERMFUNC* pFunc, DWORD_PTR dw) throw();
```

### <a name="parameters"></a>Parâmetros

*pFunc*<br/>
Ponteiro para a função para adicionar.

*dw*<br/>
Dados definidos pelo usuário, passados para a função.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlmodulecatlmodule"></a><a name="catlmodule"></a>CAtlModule::CAtlModule

O construtor.

```
CAtlModule() throw();
```

### <a name="remarks"></a>Comentários

Inicializa os membros de dados e inicia uma seção crítica em torno do segmento do módulo.

## <a name="catlmodulecatlmodule"></a><a name="dtor"></a>CAtlModule::~CAtlModule

O destruidor.

```
~CAtlModule() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados.

## <a name="catlmodulegetgitptr"></a><a name="getgitptr"></a>CAtlModule::GetGITPtr

Recupera um ponteiro para a Tabela de Interface Global.

```
virtual HRESULT GetGITPtr(IGlobalInterfaceTable** ppGIT) throw();
```

### <a name="parameters"></a>Parâmetros

*ppGIT*<br/>
Ponteiro para a variável que receberá o ponteiro para a Tabela de Interface Global.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um código de erro sobre a falha. E_POINTER é devolvido se *ppGIT* for igual a NULL.

### <a name="remarks"></a>Comentários

Se o objeto Global Interface Table não existir, ele será criado e seu endereço será armazenado na variável [membro CAtlModule::m_pGIT](#m_pgit).

Nas compilações de depuração, um erro de afirmação ocorrerá se *o ppGIT* for igual a NULL ou se o ponteiro da Tabela de Interface Global não puder ser obtido.

Consulte [IGlobalInterfaceTable](/windows/win32/api/objidl/nn-objidl-iglobalinterfacetable) para obter informações sobre a Tabela de Interface Global.

## <a name="catlmodulegetlockcount"></a><a name="getlockcount"></a>CAtlModule::GetLockCount

Retorna a contagem de bloqueios.

```
virtual LONG GetLockCount() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a contagem de bloqueios. Este valor pode ser útil para diagnósticos e depuração.

## <a name="catlmodulelock"></a><a name="lock"></a>CAtlModule::Bloqueio

Incrementa a contagem de bloqueios.

```
virtual LONG Lock() throw();
```

### <a name="return-value"></a>Valor retornado

Incrementa a contagem de bloqueios e retorna o valor atualizado. Este valor pode ser útil para diagnósticos e depuração.

## <a name="catlmodulem_libid"></a><a name="m_libid"></a>CAtlModule::m_libid

Contém o GUID do módulo atual.

```
static GUID m_libid;
```

## <a name="catlmodulem_pgit"></a><a name="m_pgit"></a>CAtlModule::m_pGIT

Ponteiro para a tabela de interface global.

```
IGlobalInterfaceTable* m_pGIT;
```

## <a name="catlmoduleterm"></a><a name="term"></a>CAtlModule::Term

Libera todos os membros de dados.

```
void Term() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados. Este método é chamado pelo destruidor.

## <a name="catlmoduleunlock"></a><a name="unlock"></a>CAtlModule::Unlock

Diminui a contagem de bloqueio.

```
virtual LONG Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Decreta a contagem de bloqueios e devolve o valor atualizado. Este valor pode ser útil para diagnósticos e depuração.

## <a name="catlmoduleupdateregistryfromresourced"></a><a name="updateregistryfromresourced"></a>CAtlModule::AtualizaçãoRegistroDeRecursoD

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
Uma id de recurso.

*Bregister*<br/>
VERDADEIRO se o objeto deve ser registrado; FALSO de outra forma.

*Pmapentries*<br/>
Um ponteiro para o mapa de substituição armazenando valores associados aos parâmetros substituíveis do script. A ATL usa automaticamente %MODULE%. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Executa o script contido no recurso especificado por *lpszRes ou nResID*. Se *bRegister* for TRUE, este método registrará o objeto no registro do sistema; caso contrário, ele remove o objeto do registro.

Para vincular estáticamente ao Registrador (Registro de Registro ATL), consulte [CAtlModule::UpdateRegistryFromResourceS](#updateregistryfromresources).

Este método chama [CAtlModule::UpdateRegistryFromResourceDHelper](#updateregistryfromresourcedhelper) e [IRegistrar::ResourceUnregister](iregistrar-class.md#resourceunregister).

## <a name="catlmoduleupdateregistryfromresourcedhelper"></a><a name="updateregistryfromresourcedhelper"></a>CAtlModule::AtualizaçãoRegistroDeRecursoDeRecursosHelper

Este método é `UpdateRegistryFromResourceD` chamado para realizar a atualização do registro.

```
inline HRESULT WINAPI UpdateRegistryFromResourceDHelper(
    LPCOLESTR lpszRes,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszRes*<br/>
Um nome de recurso.

*Bregister*<br/>
Indica se o objeto deve ser registrado.

*Pmapentries*<br/>
Um ponteiro para o mapa de substituição armazenando valores associados aos parâmetros substituíveis do script. A ATL usa automaticamente %MODULE%. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método fornece a implementação do [CAtlModule::UpdateRegistryFromResourceD](#updateregistryfromresourced).

## <a name="catlmoduleupdateregistryfromresources"></a><a name="updateregistryfromresources"></a>CAtlModule::AtualizaçãoRegistroDeRecursos

Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto. Este método é vinculado estáticamente ao componente de registro ATL.

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
Uma id de recurso.

*lpszRes*<br/>
Um nome de recurso.

*Bregister*<br/>
Indica se o script de recursos deve ser registrado.

*Pmapentries*<br/>
Um ponteiro para o mapa de substituição armazenando valores associados aos parâmetros substituíveis do script. A ATL usa automaticamente %MODULE%. Para usar parâmetros substituíveis adicionais, consulte [CAtlModule::AddCommonRGSReplacements](#addcommonrgsreplacements). Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Semelhante ao [CAtlModule::UpdateRegistryFromResourceD](#updateregistryfromresourced) exceto `CAtlModule::UpdateRegistryFromResourceS` cria um link estático para o Registrador (Registrador) do Registro ATL.

## <a name="see-also"></a>Confira também

[_ATL_MODULE](atl-typedefs.md#_atl_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)<br/>
[Componente de Registro (Registrador)](../../atl/atl-registry-component-registrar.md)
