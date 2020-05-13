---
title: Classe CComModule
ms.date: 08/19/2019
f1_keywords:
- CComModule
- ATLBASE/ATL::CComModule
- ATLBASE/ATL::CComModule::GetClassObject
- ATLBASE/ATL::CComModule::GetModuleInstance
- ATLBASE/ATL::CComModule::GetResourceInstance
- ATLBASE/ATL::CComModule::GetTypeLibInstance
- ATLBASE/ATL::CComModule::Init
- ATLBASE/ATL::CComModule::RegisterClassHelper
- ATLBASE/ATL::CComModule::RegisterClassObjects
- ATLBASE/ATL::CComModule::RegisterServer
- ATLBASE/ATL::CComModule::RegisterTypeLib
- ATLBASE/ATL::CComModule::RevokeClassObjects
- ATLBASE/ATL::CComModule::Term
- ATLBASE/ATL::CComModule::UnregisterClassHelper
- ATLBASE/ATL::CComModule::UnregisterServer
- ATLBASE/ATL::CComModule::UpdateRegistryClass
- ATLBASE/ATL::CComModule::UpdateRegistryFromResourceD
- ATLBASE/ATL::CComModule::UpdateRegistryFromResourceS
- ATLBASE/ATL::CComModule::m_csObjMap
- ATLBASE/ATL::CComModule::m_csTypeInfoHolder
- ATLBASE/ATL::CComModule::m_csWindowCreate
- ATLBASE/ATL::CComModule::m_hInst
- ATLBASE/ATL::CComModule::m_hInstResource
- ATLBASE/ATL::CComModule::m_hInstTypeLib
- ATLBASE/ATL::CComModule::m_pObjMap
helpviewer_keywords:
- CComModule class
- DLL modules [C++], ATL
ms.assetid: f5face2c-8fd8-40e6-9ec3-54ab74701769
ms.openlocfilehash: 5e30f847ff99a80ab19b880728472a339fd4cbe5
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747932"
---
# <a name="ccommodule-class"></a>Classe CComModule

A partir do ATL `CComModule` 7.0, é preterido: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CComModule : public _ATL_MODULE
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComModule::GetClassObject](#getclassobject)|Cria um objeto de um CLSID especificado. Somente para DLLs.|
|[CComModule::getModuleInstance](#getmoduleinstance)|Retorna `m_hInst`.|
|[CComModule::GetResourceInstance](#getresourceinstance)|Retorna `m_hInstResource`.|
|[CComModule::gettypelibinstance](#gettypelibinstance)|Retorna `m_hInstTypeLib`.|
|[CComModule::Init](#init)|Inicializa membros de dados.|
|[CComModule::RegisterClassHelper](#registerclasshelper)|Insere o registro padrão de classe de um objeto no registro do sistema.|
|[CComModule::RegisterClassObjects](#registerclassobjects)|Registra o objeto da classe. Somente para EXEs.|
|[CComModule::RegisterServer](#registerserver)|Atualiza o registro do sistema para cada objeto no mapa do objeto.|
|[CComModule::RegisterTypeLib](#registertypelib)|Registra uma biblioteca de tipos.|
|[CComModule::RevokeClassObjects](#revokeclassobjects)|Revoga o objeto da classe. Somente para EXEs.|
|[CComModule::Term](#term)|Libera membros de dados.|
|[CComModule::UnregisterClassHelper](#unregisterclasshelper)|Remove o registro padrão de classe de um objeto do registro do sistema.|
|[CComModule::UnregisterServer](#unregisterserver)|Desregistra cada objeto no mapa do objeto.|
|[CComModule::AtualizaçãoDoregistroClasse](#updateregistryclass)|Registra ou desregistra o registro padrão de classe de um objeto.|
|[CComModule::AtualizaçãoRegistroDerecursos](#updateregistryfromresourced)|Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto.|
|[CcomModule::atualizaçãoRegistroderecursos](#updateregistryfromresources)|Links estáticamente para o componente de registro ATL. Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComModule::m_csObjMap](#m_csobjmap)|Garante acesso sincronizado às informações do mapa do objeto.|
|[CComModule::m_csTypeInfoHolder](#m_cstypeinfoholder)|Garante acesso sincronizado às informações da biblioteca do tipo.|
|[CComModule::m_csWindowCreate](#m_cswindowcreate)|Garante acesso sincronizado às informações da classe da janela e aos dados estáticos usados durante a criação da janela.|
|[CComModule::m_hInst](#m_hinst)|Contém a alça na instância do módulo.|
|[CComModule::m_hInstResource](#m_hinstresource)|Por padrão, contém a alça na instância do módulo.|
|[CComModule::m_hInstTypeLib](#m_hinsttypelib)|Por padrão, contém a alça na instância do módulo.|
|[CComModule::m_pObjMap](#m_pobjmap)|Aponta para o mapa do objeto mantido pela instância do módulo.|

## <a name="remarks"></a>Comentários

> [!NOTE]
> Esta classe é depreciada, e os assistentes de geração de código ATL agora usam as classes derivadas [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e [CAtlModule.](../../atl/reference/catlmodule-class.md) Consulte [atl module classes](../../atl/atl-module-classes.md) para obter mais informações. As informações a seguir são para uso com aplicativos criados com versões mais antigas do ATL. `CComModule`ainda faz parte do ATL para capacidade inversa.

`CComModule`implementa um módulo de servidor COM, permitindo que um cliente acesse os componentes do módulo. `CComModule`suporta módulos DLL (em processo) e EXE (local).

Uma `CComModule` instância usa um mapa de objeto para manter um conjunto de definições de objeto de classe. Este mapa de objetos `_ATL_OBJMAP_ENTRY` é implementado como uma matriz de estruturas e contém informações para:

- Inserindo e removendo descrições de objetos no registro do sistema.

- Instanciar objetos através de uma fábrica de classe.

- Estabelecer comunicação entre um cliente e o objeto raiz no componente.

- Executando o gerenciamento vitalício de objetos de classe.

Quando você executa o APPWizard ATL `_Module`COM, o `CComModule` assistente gera automaticamente , uma instância global ou uma classe derivada dele. Para obter mais informações sobre o ASSISTENTE DE PROJETO ATL, consulte o artigo [Criando um Projeto ATL](../../atl/reference/creating-an-atl-project.md).

Além disso, a `CComModule`ATL fornece [CComAutoThreadModule,](../../atl/reference/ccomautothreadmodule-class.md)que implementa um módulo de modelo de apartamento para exes e serviços Windows. Obtenha seu `CComAutoThreadModule` módulo de quando você deseja criar objetos em vários apartamentos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[Catlmodule](../../atl/reference/catlmodule-class.md)

[Catlmodulet](../../atl/reference/catlmodulet-class.md)

`CComModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccommodulegetclassobject"></a><a name="getclassobject"></a>CComModule::GetClassObject

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT GetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```

### <a name="parameters"></a>Parâmetros

*Rclsid*<br/>
[em] O CLSID do objeto a ser criado.

*riid*<br/>
[em] O IID da interface solicitada.

*Ppv*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não suportar essa interface, *o ppv* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para este objeto.

`GetClassObject`só está disponível para DLLs.

## <a name="ccommodulegetmoduleinstance"></a><a name="getmoduleinstance"></a>CComModule::getModuleInstance

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE GetModuleInstance() throw();
```

### <a name="return-value"></a>Valor retornado

O HINSTANCE que identifica este módulo.

### <a name="remarks"></a>Comentários

Retorna o membro de dados [m_hInst.](#m_hinst)

## <a name="ccommodulegetresourceinstance"></a><a name="getresourceinstance"></a>CComModule::GetResourceInstance

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE GetResourceInstance() throw();
```

### <a name="return-value"></a>Valor retornado

Um HINSTANCE.

### <a name="remarks"></a>Comentários

Retorna o membro de dados [m_hInstResource.](#m_hinstresource)

## <a name="ccommodulegettypelibinstance"></a><a name="gettypelibinstance"></a>CComModule::gettypelibinstance

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE GetTypeLibInstance() const throw();
```

### <a name="return-value"></a>Valor retornado

Um HINSTANCE.

### <a name="remarks"></a>Comentários

Retorna o membro de dados [m_hInstTypeLib.](#m_hinsttypelib)

## <a name="ccommoduleinit"></a><a name="init"></a>CComModule::Init

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT Init(
    _ATL_OBJMAP_ENTRY* p,
    HINSTANCE h,
    const GUID* plibid = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Um ponteiro para uma matriz de entradas de mapa de objetos.

*H*<br/>
[em] O HINSTANCE `DLLMain` passou `WinMain`para ou .

*plibid*<br/>
[em] Um ponteiro para o LIBID da biblioteca do tipo associado ao projeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Inicializa todos os membros de dados.

## <a name="ccommodulem_csobjmap"></a><a name="m_csobjmap"></a>CComModule::m_csObjMap

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CRITICAL_SECTION m_csObjMap;
```

### <a name="remarks"></a>Comentários

Garante o acesso sincronizado ao mapa do objeto.

## <a name="ccommodulem_cstypeinfoholder"></a><a name="m_cstypeinfoholder"></a>CComModule::m_csTypeInfoHolder

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CRITICAL_SECTION m_csTypeInfoHolder;
```

### <a name="remarks"></a>Comentários

Garante acesso sincronizado à biblioteca do tipo.

## <a name="ccommodulem_cswindowcreate"></a><a name="m_cswindowcreate"></a>CComModule::m_csWindowCreate

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CRITICAL_SECTION m_csWindowCreate;
```

### <a name="remarks"></a>Comentários

Garante acesso sincronizado às informações da classe da janela e aos dados estáticos usados durante a criação da janela.

## <a name="ccommodulem_hinst"></a><a name="m_hinst"></a>CComModule::m_hInst

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE m_hInst;
```

### <a name="remarks"></a>Comentários

Contém a alça na instância do módulo.

O método [Init](#init) define `m_hInst` para `DLLMain` `WinMain`a alça passada para ou .

## <a name="ccommodulem_hinstresource"></a><a name="m_hinstresource"></a>CComModule::m_hInstResource

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE m_hInstResource;
```

### <a name="remarks"></a>Comentários

Por padrão, contém a alça na instância do módulo.

O método [Init](#init) define `m_hInstResource` para `DLLMain` `WinMain`a alça passada para ou . Você pode explicitamente `m_hInstResource` definir a alça para um recurso.

O método [GetResourceInstance](#getresourceinstance) retorna `m_hInstResource`a alça armazenada em .

## <a name="ccommodulem_hinsttypelib"></a><a name="m_hinsttypelib"></a>CComModule::m_hInstTypeLib

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE m_hInstTypeLib;
```

### <a name="remarks"></a>Comentários

Por padrão, contém a alça na instância do módulo.

O método [Init](#init) define `m_hInstTypeLib` para `DLLMain` `WinMain`a alça passada para ou . Você pode explicitamente `m_hInstTypeLib` definir a alça para uma biblioteca de tipos.

O método [GetTypeLibInstance](#gettypelibinstance) retorna `m_hInstTypeLib`a alça armazenada em .

## <a name="ccommodulem_pobjmap"></a><a name="m_pobjmap"></a>CComModule::m_pObjMap

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
_ATL_OBJMAP_ENTRY* m_pObjMap;
```

### <a name="remarks"></a>Comentários

Aponta para o mapa do objeto mantido pela instância do módulo.

## <a name="ccommoduleregisterclasshelper"></a><a name="registerclasshelper"></a>CComModule::RegisterClassHelper

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
ATL_DEPRECATED HRESULT RegisterClassHelper(
    const CLSID& clsid,
    LPCTSTR lpszProgID,
    LPCTSTR lpszVerIndProgID,
    UINT nDescID,
    DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[em] O CLSID do objeto a ser registrado.

*lpszProgID*<br/>
[em] O ProgID associado ao objeto.

*lpszVerIndProgID*<br/>
[em] O ProgID independente da versão associado ao objeto.

*nDescID*<br/>
[em] O identificador de um recurso de seqüência para a descrição do objeto.

*dwFlags*<br/>
[em] Especifica o modelo de rosca para inserir no registro. Os valores possíveis são THREADFLAGS_APARTMENT, THREADFLAGS_BOTH ou AUTPRXFLAG.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Insere o registro padrão de classe de um objeto no registro do sistema.

O método [UpdateRegistryClass](#updateregistryclass) chama `RegisterClassHelper`.

## <a name="ccommoduleregisterclassobjects"></a><a name="registerclassobjects"></a>CComModule::RegisterClassObjects

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw();
```

### <a name="parameters"></a>Parâmetros

*Dwclscontext*<br/>
[em] Especifica o contexto em que o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER. Para obter uma descrição desses valores, consulte [CLSCTX](/windows/win32/api/wtypesbase/ne-wtypesbase-clsctx) no SDK do Windows.

*dwFlags*<br/>
[em] Determina os tipos de conexão com o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE. Para obter uma descrição desses valores, consulte [REGCLS](/windows/win32/api/combaseapi/ne-combaseapi-regcls) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Registra um objeto de classe EXE com OLE para que outros aplicativos possam se conectar a ele. Este método só está disponível para EXEs.

## <a name="ccommoduleregisterserver"></a><a name="registerserver"></a>CComModule::RegisterServer

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegtypelib*<br/>
[em] Indica se a biblioteca do tipo será registrada. O valor padrão é FALSE.

*Pclsid*<br/>
[em] Aponta para o CLSID do objeto a ser registrado. Se NULL (o valor padrão), todos os objetos no mapa do objeto serão registrados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Dependendo do parâmetro *pCLSID,* atualiza o registro do sistema para um objeto de classe única ou para todos os objetos no mapa do objeto.

Se *bRegTypeLib* for TRUE, as informações da biblioteca do tipo também serão atualizadas.

Consulte [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para obter informações sobre como adicionar uma entrada ao mapa do objeto.

`RegisterServer`será chamado automaticamente `DLLRegisterServer` por um DLL `WinMain` ou por uma `/RegServer` execução EXE com a opção de linha de comando.

## <a name="ccommoduleregistertypelib"></a><a name="registertypelib"></a>CComModule::RegisterTypeLib

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RegisterTypeLib() throw();
HRESULT RegisterTypeLib(LPCTSTR lpszIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
[em] String no `"\\N"`formato `N` , onde está o índice inteiro do recurso TYPELIB.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Adiciona informações sobre uma biblioteca de tipo ao registro do sistema.

Se a instância do módulo contiver várias bibliotecas de tipo, use a segunda versão deste método para especificar qual biblioteca de tipo deve ser usada.

## <a name="ccommodulerevokeclassobjects"></a><a name="revokeclassobjects"></a>CComModule::RevokeClassObjects

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RevokeClassObjects() throw();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Remove o objeto de classe. Este método só está disponível para EXEs.

## <a name="ccommoduleterm"></a><a name="term"></a>CComModule::Term

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```cpp
void Term() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados.

## <a name="ccommoduleunregisterclasshelper"></a><a name="unregisterclasshelper"></a>CComModule::UnregisterClassHelper

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
ATL_DEPRECATED HRESULT UnregisterClassHelper(
    const CLSID& clsid,
    LPCTSTR lpszProgID,
    LPCTSTR lpszVerIndProgID);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[em] O CLSID do objeto não registrado.

*lpszProgID*<br/>
[em] O ProgID associado ao objeto.

*lpszVerIndProgID*<br/>
[em] O ProgID independente da versão associado ao objeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Remove o registro padrão de classe de um objeto do registro do sistema.

O método [UpdateRegistryClass](#updateregistryclass) chama `UnregisterClassHelper`.

## <a name="ccommoduleunregisterserver"></a><a name="unregisterserver"></a>CComModule::UnregisterServer

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT UnregisterServer(const CLSID* pCLSID = NULL) throw ();
inline HRESULT UnregisterServer(BOOL bUnRegTypeLib, const CLSID* pCLSID = NULL) throw ();
```

### <a name="parameters"></a>Parâmetros

*bunRegtypelib*<br/>
Se TRUE, a biblioteca do tipo também não será registrada.

*Pclsid*<br/>
Aponta para o CLSID do objeto não registrado. Se NULL (o valor padrão), todos os objetos no mapa do objeto não serão registrados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Dependendo do parâmetro *pCLSID,* não registra um objeto de classe única ou todos os objetos no mapa do objeto.

`UnregisterServer`será chamado automaticamente `DLLUnregisterServer` por um DLL `WinMain` ou por uma `/UnregServer` execução EXE com a opção de linha de comando.

Consulte [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para obter informações sobre como adicionar uma entrada ao mapa do objeto.

## <a name="ccommoduleupdateregistryclass"></a><a name="updateregistryclass"></a>CComModule::AtualizaçãoDoregistroClasse

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
ATL_DEPRECATED HRESULT UpdateRegistryClass(
    const CLSID& clsid,
    LPCTSTR lpszProgID,
    LPCTSTR lpszVerIndProgID,
    UINT nDescID,
    DWORD dwFlags,
    BOOL bRegister);

ATL_DEPRECATED HRESULT UpdateRegistryClass(
    const CLSID& clsid,
    LPCTSTR lpszProgID,
    LPCTSTR lpszVerIndProgID,
    LPCTSTR szDesc,
    DWORD dwFlags,
    BOOL bRegister);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
O CLSID do objeto a ser registrado ou não registrado.

*lpszProgID*<br/>
O ProgID associado ao objeto.

*lpszVerIndProgID*<br/>
O ProgID independente da versão associado ao objeto.

*nDescID*<br/>
O identificador do recurso string para a descrição do objeto.

*szDesc*<br/>
Uma seqüência contendo a descrição do objeto.

*dwFlags*<br/>
Especifica o modelo de rosca para inserir no registro. Os valores possíveis são THREADFLAGS_APARTMENT, THREADFLAGS_BOTH ou AUTPRXFLAG.

*Bregister*<br/>
Indica se o objeto deve ser registrado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se *bRegister* for TRUE, este método insere o registro de classe padrão do objeto no registro do sistema.

Se *bRegister* for FALSE, ele removerá o registro do objeto.

Dependendo do valor do `UpdateRegistryClass` *bRegister,* chamadas de [RegisterClassHelper](#registerclasshelper) ou [UnregisterClassHelper](#unregisterclasshelper).

Ao especificar [DECLARE_REGISTRY](registry-macros.md#declare_registry) a `UpdateRegistryClass` DECLARE_REGISTRY macro, será invocado automaticamente quando o mapa do objeto for processado.

## <a name="ccommoduleupdateregistryfromresourced"></a><a name="updateregistryfromresourced"></a>CComModule::AtualizaçãoRegistroDerecursos

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
virtual HRESULT UpdateRegistryFromResourceD(
    LPCTSTR lpszRes,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();

virtual HRESULT UpdateRegistryFromResourceD(
    UINT nResID,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw ();
```

### <a name="parameters"></a>Parâmetros

*lpszRes*<br/>
[em] Um nome de recurso.

*nResID*<br/>
[em] Uma id de recurso.

*Bregister*<br/>
[em] Indica se o objeto deve ser registrado.

*Pmapentries*<br/>
[em] Um ponteiro para o mapa de substituição armazenando valores associados aos parâmetros substituíveis do script. AtL usa `%MODULE%`automaticamente . Para usar parâmetros substituíveis adicionais, consulte as Observações para obter detalhes. Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Executa o script contido no recurso especificado por *lpszRes* ou *nResID*.

Se *bRegister* for TRUE, este método registrará o objeto no registro do sistema; caso contrário, ele desregistra o objeto.

Ao especificar a [DECLARE_REGISTRY_RESOURCE](registry-macros.md#declare_registry_resource) `UpdateRegistryFromResourceD` ou [DECLARE_REGISTRY_RESOURCEID](registry-macros.md#declare_registry_resourceid) macro, será invocado automaticamente quando o mapa do objeto for processado.

> [!NOTE]
> Para substituir os valores de substituição no tempo de execução, não especifique a DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID macro. Em vez disso, `_ATL_REGMAP_ENTRIES` crie uma matriz de estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado no tempo de execução. Em `UpdateRegistryFromResourceD`seguida, chame , passando a matriz para o parâmetro *pMapEntries.* Isso adiciona todos os `_ATL_REGMAP_ENTRIES` valores de substituição nas estruturas ao mapa de substituição do Registrador.

> [!NOTE]
> Para vincular estáticamente ao Registrador (Registro de Registro ATL), consulte [UpdateRegistryFromResourceS](#updateregistryfromresources).

Para obter mais informações sobre parâmetros substituíveis e scripting, consulte o artigo [The ATL Registry Component (Register)](../../atl/atl-registry-component-registrar.md).

## <a name="ccommoduleupdateregistryfromresources"></a><a name="updateregistryfromresources"></a>CcomModule::atualizaçãoRegistroderecursos

A partir do ATL `CComModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
virtual HRESULT UpdateRegistryFromResourceS(
    LPCTSTR lpszRes,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();

virtual HRESULT UpdateRegistryFromResourceS(
    UINT nResID,
    BOOL bRegister,
    struct _ATL_REGMAP_ENTRY* pMapEntries = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszRes*<br/>
[em] Um nome de recurso.

*nResID*<br/>
[em] Uma id de recurso.

*Bregister*<br/>
[em] Indica se o script de recursos deve ser registrado.

*Pmapentries*<br/>
[em] Um ponteiro para o mapa de substituição armazenando valores associados aos parâmetros substituíveis do script. AtL usa `%MODULE%`automaticamente . Para usar parâmetros substituíveis adicionais, consulte as Observações para obter detalhes. Caso contrário, use o valor padrão NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Semelhante ao [UpdateRegistryFromResourceD,](#updateregistryfromresourced) exceto `UpdateRegistryFromResourceS` cria um link estático para o Registrador (Registrador) do Registro ATL.

`UpdateRegistryFromResourceS`será invocado automaticamente quando seu mapa de objeto for `#define _ATL_STATIC_REGISTRY` processado, desde que você adicione ao seu *pch.h* (*stdafx.h* no Visual Studio 2017 e anterior).

> [!NOTE]
> Para substituir os valores de substituição no tempo de execução, não especifique a [DECLARE_REGISTRY_RESOURCE](registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](registry-macros.md#declare_registry_resourceid) macro. Em vez disso, `_ATL_REGMAP_ENTRIES` crie uma matriz de estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado no tempo de execução. Em `UpdateRegistryFromResourceS`seguida, chame , passando a matriz para o parâmetro *pMapEntries.* Isso adiciona todos os `_ATL_REGMAP_ENTRIES` valores de substituição nas estruturas ao mapa de substituição do Registrador.

Para obter mais informações sobre parâmetros substituíveis e scripting, consulte o artigo [The ATL Registry Component (Register)](../../atl/atl-registry-component-registrar.md).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
