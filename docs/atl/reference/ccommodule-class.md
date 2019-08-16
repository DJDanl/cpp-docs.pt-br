---
title: Classe CComModule
ms.date: 11/04/2016
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
ms.openlocfilehash: 53138081a6d712f775a2cc8f1e6905c45d95d34d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497117"
---
# <a name="ccommodule-class"></a>Classe CComModule

A partir do ATL 7,0 `CComModule` , é preterido: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CComModule : public _ATL_MODULE
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComModule::GetClassObject](#getclassobject)|Cria um objeto de um CLSID especificado. Somente para DLLs.|
|[CComModule::GetModuleInstance](#getmoduleinstance)|Retorna `m_hInst`.|
|[CComModule::GetResourceInstance](#getresourceinstance)|Retorna `m_hInstResource`.|
|[CComModule::GetTypeLibInstance](#gettypelibinstance)|Retorna `m_hInstTypeLib`.|
|[CComModule::Init](#init)|Inicializa membros de dados.|
|[CComModule::RegisterClassHelper](#registerclasshelper)|Insere o registro de classe padrão de um objeto no registro do sistema.|
|[CComModule::RegisterClassObjects](#registerclassobjects)|Registra o objeto de classe. Somente para EXEs.|
|[CComModule::RegisterServer](#registerserver)|Atualiza o registro do sistema para cada objeto no mapa de objetos.|
|[CComModule::RegisterTypeLib](#registertypelib)|Registra uma biblioteca de tipos.|
|[CComModule::RevokeClassObjects](#revokeclassobjects)|Revoga o objeto de classe. Somente para EXEs.|
|[CComModule::Term](#term)|Libera membros de dados.|
|[CComModule::UnregisterClassHelper](#unregisterclasshelper)|Remove o registro de classe padrão de um objeto do registro do sistema.|
|[CComModule::UnregisterServer](#unregisterserver)|Cancela o registro de cada objeto no mapa de objetos.|
|[CComModule::UpdateRegistryClass](#updateregistryclass)|Registra ou cancela o registro da classe padrão de um objeto.|
|[CComModule::UpdateRegistryFromResourceD](#updateregistryfromresourced)|Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto.|
|[CComModule::UpdateRegistryFromResourceS](#updateregistryfromresources)|Links estaticamente para o componente do registro ATL. Executa o script contido em um recurso especificado para registrar ou cancelar o registro de um objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComModule::m_csObjMap](#m_csobjmap)|Garante o acesso sincronizado às informações de mapa do objeto.|
|[CComModule::m_csTypeInfoHolder](#m_cstypeinfoholder)|Garante o acesso sincronizado às informações da biblioteca de tipos.|
|[CComModule::m_csWindowCreate](#m_cswindowcreate)|Garante o acesso sincronizado às informações de classe de janela e aos dados estáticos usados durante a criação da janela.|
|[CComModule::m_hInst](#m_hinst)|Contém o identificador para a instância do módulo.|
|[CComModule::m_hInstResource](#m_hinstresource)|Por padrão, o contém o identificador para a instância do módulo.|
|[CComModule::m_hInstTypeLib](#m_hinsttypelib)|Por padrão, o contém o identificador para a instância do módulo.|
|[CComModule::m_pObjMap](#m_pobjmap)|Aponta para o mapa de objeto mantido pela instância do módulo.|

## <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa classe foi preterida e os assistentes de geração de código ATL agora usam as classes derivadas [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e [CAtlModule](../../atl/reference/catlmodule-class.md) . Consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais informações. As informações a seguir são para uso com aplicativos criados com versões mais antigas do ATL. `CComModule`ainda é parte da ATL para a funcionalidade inversa.

`CComModule`implementa um módulo de servidor COM, permitindo que um cliente acesse os componentes do módulo. `CComModule`dá suporte a módulos DLL (em processo) e EXE (local).

Uma `CComModule` instância usa um mapa de objeto para manter um conjunto de definições de objeto de classe. Esse mapa de objeto é implementado como uma matriz `_ATL_OBJMAP_ENTRY` de estruturas e contém informações para:

- Inserindo e removendo descrições de objeto no registro do sistema.

- Criando uma instância de objetos por meio de uma fábrica de classes.

- Estabelecer a comunicação entre um cliente e o objeto raiz no componente.

- Executando o gerenciamento de tempo de vida de objetos de classe.

Quando você executa o ATL com AppWizard, o assistente gera `_Module`automaticamente uma instância global do `CComModule` ou uma classe derivada dela. Para obter mais informações sobre o assistente de projeto do ATL, consulte o artigo [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md).

Além disso, `CComModule`a ATL fornece [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md), que implementa um módulo de modelo de apartamento para EXEs e serviços do Windows. Derive seu módulo `CComAutoThreadModule` de quando desejar criar objetos em vários Apartments.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[CAtlModule](../../atl/reference/catlmodule-class.md)

[CAtlModuleT](../../atl/reference/catlmodulet-class.md)

`CComModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="getclassobject"></a>  CComModule::GetClassObject

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT GetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```

### <a name="parameters"></a>Parâmetros

*rclsid*<br/>
no O CLSID do objeto a ser criado.

*riid*<br/>
no O IID da interface solicitada.

*ppv*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *PPV* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.

`GetClassObject`Só está disponível para DLLs.

##  <a name="getmoduleinstance"></a>  CComModule::GetModuleInstance

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE GetModuleInstance() throw();
```

### <a name="return-value"></a>Valor de retorno

O HINSTANCE que identifica este módulo.

### <a name="remarks"></a>Comentários

Retorna o membro de dados [m_hInst](#m_hinst) .

##  <a name="getresourceinstance"></a>  CComModule::GetResourceInstance

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE GetResourceInstance() throw();
```

### <a name="return-value"></a>Valor de retorno

Um HINSTANCE.

### <a name="remarks"></a>Comentários

Retorna o membro de dados [m_hInstResource](#m_hinstresource) .

##  <a name="gettypelibinstance"></a>  CComModule::GetTypeLibInstance

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE GetTypeLibInstance() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um HINSTANCE.

### <a name="remarks"></a>Comentários

Retorna o membro de dados [m_hInstTypeLib](#m_hinsttypelib) .

##  <a name="init"></a>  CComModule::Init

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT Init(
    _ATL_OBJMAP_ENTRY* p,
    HINSTANCE h,
    const GUID* plibid = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
no Um ponteiro para uma matriz de entradas de mapa de objeto.

*h*<br/>
no O HINSTANCE passado para `DLLMain` ou `WinMain`.

*plibid*<br/>
no Um ponteiro para o LIBID da biblioteca de tipos associada ao projeto.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Inicializa todos os membros de dados.

##  <a name="m_csobjmap"></a>  CComModule::m_csObjMap

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CRITICAL_SECTION m_csObjMap;
```

### <a name="remarks"></a>Comentários

Garante o acesso sincronizado ao mapa de objetos.

##  <a name="m_cstypeinfoholder"></a>  CComModule::m_csTypeInfoHolder

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CRITICAL_SECTION m_csTypeInfoHolder;
```

### <a name="remarks"></a>Comentários

Garante o acesso sincronizado à biblioteca de tipos.

##  <a name="m_cswindowcreate"></a>  CComModule::m_csWindowCreate

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CRITICAL_SECTION m_csWindowCreate;
```

### <a name="remarks"></a>Comentários

Garante o acesso sincronizado às informações de classe de janela e aos dados estáticos usados durante a criação da janela.

##  <a name="m_hinst"></a>  CComModule::m_hInst

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE m_hInst;
```

### <a name="remarks"></a>Comentários

Contém o identificador para a instância do módulo.

O método [init](#init) define `m_hInst` para o identificador passado para `DLLMain` ou `WinMain`.

##  <a name="m_hinstresource"></a>  CComModule::m_hInstResource

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE m_hInstResource;
```

### <a name="remarks"></a>Comentários

Por padrão, o contém o identificador para a instância do módulo.

O método [init](#init) define `m_hInstResource` para o identificador passado para `DLLMain` ou `WinMain`. Você pode definir `m_hInstResource` explicitamente como o identificador para um recurso.

O método [GetResourceInstance](#getresourceinstance) retorna o identificador armazenado em `m_hInstResource`.

##  <a name="m_hinsttypelib"></a>  CComModule::m_hInstTypeLib

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HINSTANCE m_hInstTypeLib;
```

### <a name="remarks"></a>Comentários

Por padrão, o contém o identificador para a instância do módulo.

O método [init](#init) define `m_hInstTypeLib` para o identificador passado para `DLLMain` ou `WinMain`. Você pode definir `m_hInstTypeLib` explicitamente como o identificador para uma biblioteca de tipos.

O método [GetTypeLibInstance](#gettypelibinstance) retorna o identificador armazenado em `m_hInstTypeLib`.

##  <a name="m_pobjmap"></a>  CComModule::m_pObjMap

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
_ATL_OBJMAP_ENTRY* m_pObjMap;
```

### <a name="remarks"></a>Comentários

Aponta para o mapa de objeto mantido pela instância do módulo.

##  <a name="registerclasshelper"></a>  CComModule::RegisterClassHelper

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

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
no O CLSID do objeto a ser registrado.

*lpszProgID*<br/>
no O ProgID associado ao objeto.

*lpszVerIndProgID*<br/>
no O ProgID independente de versão associado ao objeto.

*nDescID*<br/>
no O identificador de um recurso de cadeia de caracteres para a descrição do objeto.

*dwFlags*<br/>
no Especifica o modelo de Threading a ser inserido no registro. Os valores possíveis são THREADFLAGS_APARTMENT, THREADFLAGS_BOTH ou AUTPRXFLAG.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Insere o registro de classe padrão de um objeto no registro do sistema.

O método [UpdateRegistryClass](#updateregistryclass) chama `RegisterClassHelper`.

##  <a name="registerclassobjects"></a>  CComModule::RegisterClassObjects

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw();
```

### <a name="parameters"></a>Parâmetros

*dwClsContext*<br/>
no Especifica o contexto no qual o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER. Para obter uma descrição desses valores, consulte [CLSCTX](/windows/win32/api/wtypesbase/ne-wtypesbase-clsctx) no SDK do Windows.

*dwFlags*<br/>
no Determina os tipos de conexão para o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE. Para obter uma descrição desses valores, consulte [REGCLS](/windows/win32/api/combaseapi/ne-combaseapi-regcls) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Registra um objeto de classe EXE com OLE para que outros aplicativos possam se conectar a ele. Esse método só está disponível para EXEs.

##  <a name="registerserver"></a>  CComModule::RegisterServer

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegTypeLib*<br/>
no Indica se a biblioteca de tipos será registrada. O valor padrão é FALSE.

*pCLSID*<br/>
no Aponta para o CLSID do objeto a ser registrado. Se for NULL (o valor padrão), todos os objetos no mapa de objetos serão registrados.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Dependendo do parâmetro *pCLSID* , o atualiza o registro do sistema para um único objeto de classe ou para todos os objetos no mapa de objetos.

Se *bRegTypeLib* for true, as informações da biblioteca de tipos também serão atualizadas.

Consulte [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para obter informações sobre como adicionar uma entrada ao mapa de objetos.

`RegisterServer`será chamado automaticamente por `DLLRegisterServer` para uma DLL ou por `WinMain` para um exe executado com a opção `/RegServer` de linha de comando.

##  <a name="registertypelib"></a>  CComModule::RegisterTypeLib

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RegisterTypeLib() throw();
HRESULT RegisterTypeLib(LPCTSTR lpszIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
no Cadeia de caracteres no `"\\N"`formato, `N` em que é o índice de inteiro do recurso TypeLib.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Adiciona informações sobre uma biblioteca de tipos ao registro do sistema.

Se a instância do módulo contiver várias bibliotecas de tipos, use a segunda versão desse método para especificar qual biblioteca de tipos deve ser usada.

##  <a name="revokeclassobjects"></a>  CComModule::RevokeClassObjects

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT RevokeClassObjects() throw();
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Remove o objeto de classe. Esse método só está disponível para EXEs.

##  <a name="term"></a>CComModule:: termo

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
void Term() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os membros de dados.

##  <a name="unregisterclasshelper"></a>  CComModule::UnregisterClassHelper

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
ATL_DEPRECATED HRESULT UnregisterClassHelper(
    const CLSID& clsid,
    LPCTSTR lpszProgID,
    LPCTSTR lpszVerIndProgID);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
no O CLSID do registro do objeto a ser cancelado.

*lpszProgID*<br/>
no O ProgID associado ao objeto.

*lpszVerIndProgID*<br/>
no O ProgID independente de versão associado ao objeto.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Remove o registro de classe padrão de um objeto do registro do sistema.

O método [UpdateRegistryClass](#updateregistryclass) chama `UnregisterClassHelper`.

##  <a name="unregisterserver"></a>  CComModule::UnregisterServer

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT UnregisterServer(const CLSID* pCLSID = NULL) throw ();
inline HRESULT UnregisterServer(BOOL bUnRegTypeLib, const CLSID* pCLSID = NULL) throw ();
```

### <a name="parameters"></a>Parâmetros

*bUnRegTypeLib*<br/>
Se for TRUE, a biblioteca de tipos também será cancelada.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser cancelado. Se NULL (o valor padrão), todos os objetos no mapa de objeto terão o registro cancelado.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Dependendo do parâmetro *pCLSID* , o cancela o registro de um único objeto de classe ou de todos os objetos no mapa de objetos.

`UnregisterServer`será chamado automaticamente por `DLLUnregisterServer` para uma DLL ou por `WinMain` para um exe executado com a opção `/UnregServer` de linha de comando.

Consulte [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para obter informações sobre como adicionar uma entrada ao mapa de objetos.

##  <a name="updateregistryclass"></a>  CComModule::UpdateRegistryClass

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

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
O CLSID do objeto a ser registrado ou cancelado.

*lpszProgID*<br/>
O ProgID associado ao objeto.

*lpszVerIndProgID*<br/>
O ProgID independente de versão associado ao objeto.

*nDescID*<br/>
O identificador do recurso de cadeia de caracteres para a descrição do objeto.

*szDesc*<br/>
Uma cadeia de caracteres que contém a descrição do objeto.

*dwFlags*<br/>
Especifica o modelo de Threading a ser inserido no registro. Os valores possíveis são THREADFLAGS_APARTMENT, THREADFLAGS_BOTH ou AUTPRXFLAG.

*bRegister*<br/>
Indica se o objeto deve ser registrado.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se *bRegister* for true, esse método inserirá o registro de classe padrão do objeto no registro do sistema.

Se *bRegister* for false, ele removerá o registro do objeto.

Dependendo do valor de *bRegister*, `UpdateRegistryClass` o chama [RegisterClassHelper](#registerclasshelper) ou [UnregisterClassHelper](#unregisterclasshelper).

Ao especificar a macro [DECLARE_REGISTRY](registry-macros.md#declare_registry) , `UpdateRegistryClass` será invocada automaticamente quando o mapa de objetos for processado.

##  <a name="updateregistryfromresourced"></a>  CComModule::UpdateRegistryFromResourceD

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

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
no Um nome de recurso.

*nResID*<br/>
no Uma ID de recurso.

*bRegister*<br/>
no Indica se o objeto deve ser registrado.

*pMapEntries*<br/>
no Um ponteiro para o mapa de substituição que armazena valores associados aos parâmetros substituíveis do script. O ATL usa `%MODULE%`automaticamente. Para usar parâmetros substituíveis adicionais, consulte os comentários para obter detalhes. Caso contrário, use o valor padrão nulo.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Executa o script contido no recurso especificado por *lpszRes* ou *nResID*.

Se *bRegister* for true, esse método registrará o objeto no registro do sistema; caso contrário, ele cancelará o registro do objeto.

Ao especificar a macro [DECLARE_REGISTRY_RESOURCE](registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](registry-macros.md#declare_registry_resourceid) , `UpdateRegistryFromResourceD` será invocada automaticamente quando o mapa do objeto for processado.

> [!NOTE]
>  Para substituir valores de substituição em tempo de execução, não especifique a macro DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID. Em vez disso, crie uma `_ATL_REGMAP_ENTRIES` matriz de estruturas, em que cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida `UpdateRegistryFromResourceD`, chame, passando a matriz para o parâmetro *pMapEntries* . Isso adiciona todos os valores de substituição nas `_ATL_REGMAP_ENTRIES` estruturas ao mapa de substituição do registrador.

> [!NOTE]
>  Para vincular estaticamente ao componente do registro ATL (registrador), consulte [UpdateRegistryFromResourceS](#updateregistryfromresources).

Para obter mais informações sobre parâmetros e scripts substituíveis, consulte o artigo [o componente do registro do ATL (registrador)](../../atl/atl-registry-component-registrar.md).

##  <a name="updateregistryfromresources"></a>  CComModule::UpdateRegistryFromResourceS

A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

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
no Um nome de recurso.

*nResID*<br/>
no Uma ID de recurso.

*bRegister*<br/>
no Indica se o script de recurso deve ser registrado.

*pMapEntries*<br/>
no Um ponteiro para o mapa de substituição que armazena valores associados aos parâmetros substituíveis do script. O ATL usa `%MODULE%`automaticamente. Para usar parâmetros substituíveis adicionais, consulte os comentários para obter detalhes. Caso contrário, use o valor padrão nulo.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Semelhante a [UpdateRegistryFromResourceD](#updateregistryfromresourced) , `UpdateRegistryFromResourceS` exceto cria um link estático para o componente de registro do ATL (registrador).

`UpdateRegistryFromResourceS`será invocado automaticamente quando o mapa do objeto for processado, desde que `#define _ATL_STATIC_REGISTRY` você adicione ao seu stdafx. h.

> [!NOTE]
>  Para substituir valores de substituição em tempo de execução, não especifique a macro [DECLARE_REGISTRY_RESOURCE](registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](registry-macros.md#declare_registry_resourceid) . Em vez disso, crie uma `_ATL_REGMAP_ENTRIES` matriz de estruturas, em que cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida `UpdateRegistryFromResourceS`, chame, passando a matriz para o parâmetro *pMapEntries* . Isso adiciona todos os valores de substituição nas `_ATL_REGMAP_ENTRIES` estruturas ao mapa de substituição do registrador.

Para obter mais informações sobre parâmetros e scripts substituíveis, consulte o artigo [o componente do registro do ATL (registrador)](../../atl/atl-registry-component-registrar.md).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
