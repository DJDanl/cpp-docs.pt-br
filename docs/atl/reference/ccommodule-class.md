---
title: Classe CComModule | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CComModule class
- DLL modules [C++], ATL
ms.assetid: f5face2c-8fd8-40e6-9ec3-54ab74701769
caps.latest.revision: 23
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: 893efea83bd0d84813a70ec39e5d50fde47dd732
ms.contentlocale: pt-br
ms.lasthandoff: 03/31/2017

---
# <a name="ccommodule-class"></a>Classe CComModule
A partir de ATL 7.0, `CComModule` foi preterido: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComModule : public _ATL_MODULE
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComModule::GetClassObject](#getclassobject)|Cria um objeto de um CLSID especificado. Para DLLs.|  
|[CComModule::GetModuleInstance](#getmoduleinstance)|Retorna `m_hInst`.|  
|[CComModule::GetResourceInstance](#getresourceinstance)|Retorna `m_hInstResource`.|  
|[CComModule::GetTypeLibInstance](#gettypelibinstance)|Retorna `m_hInstTypeLib`.|  
|[CComModule](#init)|Inicializa a membros de dados.|  
|[CComModule::RegisterClassHelper](#registerclasshelper)|Insere um registro de classe padrão de um objeto no registro do sistema.|  
|[CComModule::RegisterClassObjects](#registerclassobjects)|Registra o objeto de classe. Para EXEs.|  
|[CComModule::RegisterServer](#registerserver)|Atualiza o registro do sistema para cada objeto no mapa do objeto.|  
|[CComModule::RegisterTypeLib](#registertypelib)|Registra uma biblioteca de tipos.|  
|[CComModule::RevokeClassObjects](#revokeclassobjects)|Revoga o objeto da classe. Para EXEs.|  
|[CComModule:: Term](#term)|Membros de dados de versões.|  
|[CComModule::UnregisterClassHelper](#unregisterclasshelper)|Remove o registro de classe padrão de um objeto do registro do sistema.|  
|[CComModule::UnregisterServer](#unregisterserver)|Cancela o registro de cada objeto no mapa do objeto.|  
|[CComModule::UpdateRegistryClass](#updateregistryclass)|Registra ou cancela o registro de registro de classe padrão de um objeto.|  
|[CComModule::UpdateRegistryFromResourceD](#updateregistryfromresourced)|Executa o script contido em um recurso especificado ao registrar ou cancelar o registro de um objeto.|  
|[CComModule::UpdateRegistryFromResourceS](#updateregistryfromresources)|Estaticamente links para o componente de registro ATL. Executa o script contido em um recurso especificado ao registrar ou cancelar o registro de um objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComModule::m_csObjMap](#m_csobjmap)|Garante o acesso sincronizado as informações de mapa do objeto.|  
|[CComModule::m_csTypeInfoHolder](#m_cstypeinfoholder)|Garante o acesso sincronizado as informações de biblioteca de tipo.|  
|[CComModule::m_csWindowCreate](#m_cswindowcreate)|Garante o acesso sincronizado para obter informações de classe de janela e dados estáticos usados durante a criação de janela.|  
|[CComModule::m_hInst](#m_hinst)|Contém o identificador para a instância de módulo.|  
|[CComModule::m_hInstResource](#m_hinstresource)|Por padrão, contém o identificador para a instância de módulo.|  
|[CComModule::m_hInstTypeLib](#m_hinsttypelib)|Por padrão, contém o identificador para a instância de módulo.|  
|[CComModule::m_pObjMap](#m_pobjmap)|Aponta para o mapa de objetos mantidos pela instância do módulo.|  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Essa classe foi substituída e os assistentes de geração de código ATL agora usam o [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e [CAtlModule](../../atl/reference/catlmodule-class.md) classes derivadas. Consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais informações. As informações a seguir são para uso com aplicativos criados com versões mais antigas do ATL `CComModule`ainda é parte da ATL para versões anteriores recurso.  
  
 `CComModule`implementa um módulo COM de servidor, permitindo que um cliente acessar os componentes do módulo. `CComModule`dá suporte a DLL (em processo) e módulos EXE (locais).  
  
 Um `CComModule` instância usa um mapa de objeto para manter um conjunto de definições de classe de objeto. Este mapa de objeto é implementado como uma matriz de `_ATL_OBJMAP_ENTRY` estruturas e contém informações para:  
  
-   Inserindo e removendo descrições de objeto no registro do sistema.  
  
-   Instanciando objetos por meio de uma fábrica de classes.  
  
-   Estabelecer a comunicação entre um cliente e o objeto raiz no componente.  
  
-   Executar o gerenciamento de vida útil de objetos de classe.  
  
 Quando você executa o ATL COM AppWizard, o assistente gera automaticamente `_Module`, uma instância global do `CComModule` ou uma classe derivada. Para obter mais informações sobre o Assistente de projeto de ATL, consulte o artigo [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md).  
  
 Além `CComModule`, ATL fornece [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md), que implementa um módulo do modelo-apartamento para serviços executáveis e do Windows. Derivar o módulo de `CComAutoThreadModule` quando você deseja criar objetos em vários apartments.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_MODULE](atl-typedefs.md#_atl_module)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 `CComModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="getclassobject"></a>CComModule::GetClassObject  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT GetClassObject(  
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rclsid`  
 [in] O CLSID do objeto a ser criado.  
  
 `riid`  
 [in] O IID da interface solicitada.  
  
 `ppv`  
 [out] Um ponteiro para o ponteiro de interface identificado por `riid`. Se o objeto não oferece suporte a essa interface, `ppv` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Cria um objeto com o CLSID especificado e recupera um ponteiro de interface para este objeto.  
  
 `GetClassObject`só está disponível para DLLs.  
  
##  <a name="getmoduleinstance"></a>CComModule::GetModuleInstance  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HINSTANCE GetModuleInstance() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `HINSTANCE` identifica este módulo.  
  
### <a name="remarks"></a>Comentários  
 Retorna o [m_hInst](#m_hinst) membro de dados.  
  
##  <a name="getresourceinstance"></a>CComModule::GetResourceInstance  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HINSTANCE GetResourceInstance() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HINSTANCE`.  
  
### <a name="remarks"></a>Comentários  
 Retorna o [m_hInstResource](#m_hinstresource) membro de dados.  
  
##  <a name="gettypelibinstance"></a>CComModule::GetTypeLibInstance  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HINSTANCE GetTypeLibInstance() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HINSTANCE`.  
  
### <a name="remarks"></a>Comentários  
 Retorna o [m_hInstTypeLib](#m_hinsttypelib) membro de dados.  
  
##  <a name="init"></a>CComModule  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT Init(
    _ATL_OBJMAP_ENTRY* p,
    HINSTANCE h,
    const GUID* plibid = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Um ponteiro para uma matriz de entradas de mapa do objeto.  
  
 `h`  
 [in] O `HINSTANCE` passado para **DLLMain** ou `WinMain`.  
  
 `plibid`  
 [in] Um ponteiro para a ID da biblioteca do tipo de biblioteca associado ao projeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Inicializa todos os membros de dados.  
  
##  <a name="m_csobjmap"></a>CComModule::m_csObjMap  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
CRITICAL_SECTION m_csObjMap;
```  
  
### <a name="remarks"></a>Comentários  
 Garante o acesso sincronizado ao mapa do objeto.  
  
##  <a name="m_cstypeinfoholder"></a>CComModule::m_csTypeInfoHolder  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
CRITICAL_SECTION m_csTypeInfoHolder;
```  
  
### <a name="remarks"></a>Comentários  
 Garante o acesso sincronizado para a biblioteca de tipos.  
  
##  <a name="m_cswindowcreate"></a>CComModule::m_csWindowCreate  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
CRITICAL_SECTION m_csWindowCreate;
```  
  
### <a name="remarks"></a>Comentários  
 Garante acesso sincronizado a informações de classe de janela e dados estáticos usados durante a criação de janela.  
  
##  <a name="m_hinst"></a>CComModule::m_hInst  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HINSTANCE m_hInst;
```  
  
### <a name="remarks"></a>Comentários  
 Contém o identificador para a instância de módulo.  
  
 O [Init](#init) método conjuntos `m_hInst` o identificador passado para **DLLMain** ou `WinMain`.  
  
##  <a name="m_hinstresource"></a>CComModule::m_hInstResource  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HINSTANCE m_hInstResource;
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, contém o identificador para a instância de módulo.  
  
 O [Init](#init) método conjuntos `m_hInstResource` o identificador passado para **DLLMain** ou `WinMain`. Você pode definir explicitamente `m_hInstResource` para o identificador para um recurso.  
  
 O [GetResourceInstance](#getresourceinstance) método retorna o identificador armazenado em `m_hInstResource`.  
  
##  <a name="m_hinsttypelib"></a>CComModule::m_hInstTypeLib  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HINSTANCE m_hInstTypeLib;
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, contém o identificador para a instância de módulo.  
  
 O [Init](#init) método conjuntos `m_hInstTypeLib` o identificador passado para **DLLMain** ou `WinMain`. Você pode definir explicitamente `m_hInstTypeLib` para o identificador para uma biblioteca de tipos.  
  
 O [GetTypeLibInstance](#gettypelibinstance) método retorna o identificador armazenado em `m_hInstTypeLib`.  
  
##  <a name="m_pobjmap"></a>CComModule::m_pObjMap  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
_ATL_OBJMAP_ENTRY* m_pObjMap;
```  
  
### <a name="remarks"></a>Comentários  
 Aponta para o mapa de objetos mantidos pela instância do módulo.  
  
##  <a name="registerclasshelper"></a>CComModule::RegisterClassHelper  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
ATL_DEPRECATED HRESULT RegisterClassHelper(  
    const CLSID& clsid,
    LPCTSTR lpszProgID,
    LPCTSTR lpszVerIndProgID,
    UINT nDescID,
    DWORD dwFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 [in] O CLSID do objeto a ser registrado.  
  
 `lpszProgID`  
 [in] O ProgID associado ao objeto.  
  
 `lpszVerIndProgID`  
 [in] O ProgID e independentes de versão associado ao objeto.  
  
 `nDescID`  
 [in] O identificador de um recurso de cadeia de caracteres para a descrição do objeto.  
  
 `dwFlags`  
 [in] Especifica o modelo de threading para entrar no registro. Os valores possíveis são **THREADFLAGS_APARTMENT**, **THREADFLAGS_BOTH**, ou **AUTPRXFLAG**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Insere um registro de classe padrão de um objeto no registro do sistema.  
  
 O [UpdateRegistryClass](#updateregistryclass) chamadas de método `RegisterClassHelper`.  
  
##  <a name="registerclassobjects"></a>CComModule::RegisterClassObjects  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwClsContext`  
 [in] Especifica o contexto no qual o objeto de classe é para ser executado. Os valores possíveis são **CLSCTX_INPROC_SERVER**, **CLSCTX_INPROC_HANDLER**, ou **CLSCTX_LOCAL_SERVER**. Para obter uma descrição destes valores, consulte [CLSCTX](http://msdn.microsoft.com/library/windows/desktop/ms693716) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwFlags`  
 [in] Determina os tipos de conexão para o objeto de classe. Os valores possíveis são **REGCLS_SINGLEUSE**, **REGCLS_MULTIPLEUSE**, ou **REGCLS_MULTI_SEPARATE**. Para obter uma descrição destes valores, consulte [REGCLS](http://msdn.microsoft.com/library/windows/desktop/ms679697) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Registra um objeto de classe EXE OLE para que outros aplicativos possam se conectar a ele. Esse método só está disponível para execuções.  
  
##  <a name="registerserver"></a>CComModule::RegisterServer  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,  
    const CLSID* pCLSID = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegTypeLib`  
 [in] Indica se a biblioteca de tipos será registrada. O valor padrão é **FALSE**.  
  
 `pCLSID`  
 [in] Aponta para o CLSID do objeto a ser registrado. Se **nulo** (o valor padrão), todos os objetos no mapa de objeto serão registrados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Dependendo do `pCLSID` parâmetro, atualiza o registro do sistema para um objeto de classe individual ou para todos os objetos no mapa do objeto.  
  
 Se `bRegTypeLib` é **TRUE**, as informações do tipo biblioteca também serão atualizadas.  
  
 Consulte [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para obter informações sobre como adicionar uma entrada para o mapa de objeto.  
  
 `RegisterServer`será chamado automaticamente pelo **DLLRegisterServer** para uma DLL ou por `WinMain` para um EXE executar com o **/RegServer** opção de linha de comando.  
  
##  <a name="registertypelib"></a>CComModule::RegisterTypeLib  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT RegisterTypeLib() throw();
HRESULT RegisterTypeLib(LPCTSTR lpszIndex) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszIndex`  
 [in] Cadeia de caracteres no formato `"\\N"`, onde `N` é o índice inteiro do recurso TYPELIB.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Adiciona informações sobre uma biblioteca de tipos para o registro do sistema.  
  
 Se a instância do módulo contém várias bibliotecas de tipo, use a segunda versão desse método para especificar qual biblioteca de tipo deve ser usada.  
  
##  <a name="revokeclassobjects"></a>CComModule::RevokeClassObjects  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT RevokeClassObjects() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Remove o objeto de classe. Esse método só está disponível para execuções.  
  
##  <a name="term"></a>CComModule:: Term  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
void Term() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os membros de dados.  
  
##  <a name="unregisterclasshelper"></a>CComModule::UnregisterClassHelper  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
ATL_DEPRECATED HRESULT UnregisterClassHelper(  
    const CLSID& clsid,
    LPCTSTR lpszProgID,
    LPCTSTR lpszVerIndProgID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 [in] O CLSID do objeto a ser cancelado.  
  
 `lpszProgID`  
 [in] O ProgID associado ao objeto.  
  
 `lpszVerIndProgID`  
 [in] O ProgID e independentes de versão associado ao objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Remove o registro de classe padrão de um objeto do registro do sistema.  
  
 O [UpdateRegistryClass](#updateregistryclass) chamadas de método `UnregisterClassHelper`.  
  
##  <a name="unregisterserver"></a>CComModule::UnregisterServer  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT UnregisterServer(const CLSID* pCLSID = NULL) throw ();
inline HRESULT UnregisterServer(BOOL bUnRegTypeLib, const CLSID* pCLSID = NULL) throw ();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bUnRegTypeLib`  
 Se **TRUE**, a biblioteca de tipos também foi cancelada.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser cancelado. Se **nulo** (o valor padrão), todos os objetos no mapa de objeto será cancelados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Dependendo do `pCLSID` cancela o registro do parâmetro, um objeto de classe único ou todos os objetos no mapa do objeto.  
  
 `UnregisterServer`será chamado automaticamente pelo **DLLUnregisterServer** para uma DLL ou por `WinMain` para um EXE executar com o **/UnregServer** opção de linha de comando.  
  
 Consulte [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para obter informações sobre como adicionar uma entrada para o mapa de objeto.  
  
##  <a name="updateregistryclass"></a>CComModule::UpdateRegistryClass  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
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
 `clsid`  
 O CLSID do objeto a ser registrado ou não registrado.  
  
 `lpszProgID`  
 O ProgID associado ao objeto.  
  
 `lpszVerIndProgID`  
 O ProgID e independentes de versão associado ao objeto.  
  
 `nDescID`  
 O identificador do recurso de cadeia de caracteres para a descrição do objeto.  
  
 `szDesc`  
 Uma cadeia de caracteres que contém a descrição do objeto.  
  
 `dwFlags`  
 Especifica o modelo de threading para entrar no registro. Os valores possíveis são **THREADFLAGS_APARTMENT**, **THREADFLAGS_BOTH**, ou **AUTPRXFLAG**.  
  
 `bRegister`  
 Indica se o objeto deve ser registrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Se `bRegister` é **TRUE**, esse método insere o registro de classe padrão do objeto no registro do sistema.  
  
 Se `bRegister` é **FALSE**, ele remove o registro do objeto.  
  
 Dependendo do valor de `bRegister`, `UpdateRegistryClass` chama o [RegisterClassHelper](#registerclasshelper) ou [UnregisterClassHelper](#unregisterclasshelper).  
  
 Especificando o [DECLARE_REGISTRY](registry-macros.md#declare_registry) macro `UpdateRegistryClass` será automaticamente invocado quando o mapa de objeto for processado.  
  
##  <a name="updateregistryfromresourced"></a>CComModule::UpdateRegistryFromResourceD  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
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
 `lpszRes`  
 [in] Um nome de recurso.  
  
 `nResID`  
 [in] Uma ID de recurso.  
  
 `bRegister`  
 [in] Indica se o objeto deve ser registrado.  
  
 `pMapEntries`  
 [in] Um ponteiro para o mapa de substituição armazenar valores associados aos parâmetros substituíveis do script. ATL usa automaticamente `%MODULE%`. Para usar parâmetros substituíveis adicionais, consulte os comentários para obter detalhes. Caso contrário, use o **nulo** valor padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Executa o script contido no recurso especificado pela `lpszRes` ou `nResID`.  
  
 Se `bRegister` é **TRUE**, este método registra o objeto no registro do sistema; caso contrário, ele cancela o registro do objeto.  
  
 Especificando o [DECLARE_REGISTRY_RESOURCE](registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](registry-macros.md#declare_registry_resourceid) macro `UpdateRegistryFromResourceD` será automaticamente invocado quando o mapa de objeto for processado.  
  
> [!NOTE]
>  Para substituir valores de substituição em tempo de execução, não especifique o `DECLARE_REGISTRY_RESOURCE` ou `DECLARE_REGISTRY_RESOURCEID` macro. Em vez disso, crie uma matriz de **_ATL_REGMAP_ENTRIES** estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame `UpdateRegistryFromResourceD`, passando uma matriz o `pMapEntries` parâmetro. Isso adiciona todos os valores de substituição no **_ATL_REGMAP_ENTRIES** estruturas para o mapa de substituição do registrador.  
  
> [!NOTE]
>  Para vincular estaticamente para o componente de registro ATL (Registrar), consulte [UpdateRegistryFromResourceS](#updateregistryfromresources).  
  
 Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (Registrar)](../../atl/atl-registry-component-registrar.md).  
  
##  <a name="updateregistryfromresources"></a>CComModule::UpdateRegistryFromResourceS  
 A partir de ATL 7.0, `CComModule` é obsoleta: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
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
 `lpszRes`  
 [in] Um nome de recurso.  
  
 `nResID`  
 [in] Uma ID de recurso.  
  
 `bRegister`  
 [in] Indica se o script de recurso deve ser registrado.  
  
 `pMapEntries`  
 [in] Um ponteiro para o mapa de substituição armazenar valores associados aos parâmetros substituíveis do script. ATL usa automaticamente `%MODULE%`. Para usar parâmetros substituíveis adicionais, consulte os comentários para obter detalhes. Caso contrário, use o **nulo** valor padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao [UpdateRegistryFromResourceD](#updateregistryfromresourced) exceto `UpdateRegistryFromResourceS` cria um link estático para o componente de registro ATL (Registrar).  
  
 `UpdateRegistryFromResourceS`será invocado automaticamente quando o mapa de objeto é processado, desde que você adicionar `#define _ATL_STATIC_REGISTRY` para seu Stdafx. h.  
  
> [!NOTE]
>  Para substituir valores de substituição em tempo de execução, não especifique o [DECLARE_REGISTRY_RESOURCE](registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](registry-macros.md#declare_registry_resourceid) macro. Em vez disso, crie uma matriz de **_ATL_REGMAP_ENTRIES** estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame `UpdateRegistryFromResourceS`, passando uma matriz o `pMapEntries` parâmetro. Isso adiciona todos os valores de substituição no **_ATL_REGMAP_ENTRIES** estruturas para o mapa de substituição do registrador.  
  
 Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (Registrar)](../../atl/atl-registry-component-registrar.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

