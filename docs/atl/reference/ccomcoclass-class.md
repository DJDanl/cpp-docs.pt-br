---
title: Classe CComCoClass
ms.date: 11/04/2016
f1_keywords:
- CComCoClass
- ATLCOM/ATL::CComCoClass
- ATLCOM/ATL::CComCoClass::CreateInstance
- ATLCOM/ATL::CComCoClass::Error
- ATLCOM/ATL::CComCoClass::GetObjectCLSID
- ATLCOM/ATL::CComCoClass::GetObjectDescription
helpviewer_keywords:
- CComCoClass class
- aggregation [C++], aggregation models
ms.assetid: 67cfefa4-8df9-47fa-ad58-2d1a1ae25762
ms.openlocfilehash: 11e724a982f3a2f404473dbdd34d848842cc8e14
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320833"
---
# <a name="ccomcoclass-class"></a>Classe CComCoClass

Esta classe fornece métodos para criar instâncias de uma classe e obter suas propriedades.

## <a name="syntax"></a>Sintaxe

```
template <class T, const CLSID* pclsid = &CLSID_NULL>
class CComCoClass
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `CComCoClass`.

*Pclsid*<br/>
Um ponteiro para o CLSID do objeto.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCoClass::CreateInstance](#createinstance)|(Estática) Cria uma instância da classe e consultas para uma interface.|
|[CComCoClass::Erro](#error)|(Estática) Devolve informações ricas de erro ao cliente.|
|[CComCoClass::GetObjectCLSID](#getobjectclsid)|(Estática) Retorna o identificador de classe do objeto.|
|[CComCoClass::GetObjectDescription](#getobjectdescription)|(Estática) Anular para devolver a descrição do objeto.|

## <a name="remarks"></a>Comentários

`CComCoClass`fornece métodos para recuperar o CLSID de um objeto, definir informações de erro e criar instâncias da classe. Qualquer classe registrada no mapa do objeto `CComCoClass`deve ser derivada de .

`CComCoClass`também define o modelo de fábrica de classe padrão e agregação para o seu objeto. `CComCoClass`usa as duas macros a seguir:

- [DECLARE_CLASSFACTORY DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory) Declara a fábrica de classe [como CComClassFactory](../../atl/reference/ccomclassfactory-class.md).

- [DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable) Declara que seu objeto pode ser agregado.

Você pode substituir qualquer um desses padrões especificando outra macro na definição de classe. Por exemplo, para usar [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) em vez de, `CComClassFactory`especificar a [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) macro:

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/ccomcoclass-class_1.h)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomcoclasscreateinstance"></a><a name="createinstance"></a>CComCoClass::CreateInstance

Use `CreateInstance` essas funções para criar uma instância de um objeto COM e recuperar um ponteiro de interface sem usar a API COM.

```
template <class  Q>
static HRESULT CreateInstance( Q** pp);

template <class  Q>
static HRESULT CreateInstance(IUnknown* punkOuter, Q** pp);
```

### <a name="parameters"></a>Parâmetros

*Q*<br/>
A interface COM que deve ser devolvida via *pp*.

*Punkouter*<br/>
[em] O desconhecido externo ou o controle desconhecido do agregado.

*Pp*<br/>
[fora] O endereço de uma variável ponteiro que recebe o ponteiro de interface solicitado se a criação for bem sucedida.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão. Consulte [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) no Windows SDK para obter uma descrição dos possíveis valores de retorno.

### <a name="remarks"></a>Comentários

Use a primeira sobrecarga desta função para a criação típica de objetos; use a segunda sobrecarga quando precisar agregar o objeto que está sendo criado.

A classe ATL que implementa o objeto COM necessário (ou seja, a classe usada como primeiro parâmetro de modelo para [CComCoClass](../../atl/reference/ccomcoclass-class.md)) deve estar no mesmo projeto que o código de chamada. A criação do objeto COM é realizada pela fábrica de classe registrada para esta classe ATL.

Essas funções são úteis para criar objetos que você impediu de serem creatable externamente usando a [macro OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO.](object-map-macros.md#object_entry_non_createable_ex_auto) Eles também são úteis em situações em que você deseja evitar a API COM por razões de eficiência.

Observe que a interface *Q* deve ter um IID associado a ele que pode ser recuperado usando o [operador __uuidof.](../../cpp/uuidof-operator.md)

### <a name="example"></a>Exemplo

No exemplo a `CDocument` seguir, está uma classe ATL gerada pelo assistente derivada `CComCoClass` disso que implementa a `IDocument` interface. A classe é registrada no mapa de objetos com a OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO macro para que os clientes não possam criar instâncias do documento usando [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance). `CApplication`é uma CoClass que fornece um método em uma de suas próprias interfaces COM para criar instâncias da classe de documentos. O código abaixo mostra como é fácil criar `CreateInstance` instâncias da `CComCoClass` classe de documento usando o membro herdado da classe base.

[!code-cpp[NVC_ATL_COM#11](../../atl/codesnippet/cpp/ccomcoclass-class_2.cpp)]

## <a name="ccomcoclasserror"></a><a name="error"></a>CComCoClass::Erro

Esta função estática `IErrorInfo` configura a interface para fornecer informações de erro ao cliente.

```
static HRESULT WINAPI Error(
    LPCOLESTR lpszDesc,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    LPCOLESTR lpszDesc,
    DWORD dwHelpID,
    LPCOLESTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    LPCSTR lpszDesc,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    LPCSTR lpszDesc,
    DWORD dwHelpID,
    LPCSTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    UINT nID,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0,
    HINSTANCE hInst = _AtlBaseModule.GetResourceInstance ());

static HRESULT Error(
    UINT nID,
    DWORD dwHelpID,
    LPCOLESTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0,
    HINSTANCE hInst = _AtlBaseModule.GetResourceInstance());
```

### <a name="parameters"></a>Parâmetros

*Lpszdesc*<br/>
[em] A seqüência descrevendo o erro. A versão Unicode de `Error` especifica que *lpszDesc* é do tipo LPCOLESTR; a versão ANSI especifica um tipo de LPCSTR.

*Iid*<br/>
[em] O IID da interface que define o erro ou GUID_NULL (o valor padrão) se o erro for definido pelo sistema operacional.

*Hres*<br/>
[em] O HRESULT que você deseja retornou ao chamador. O valor padrão é 0. Para obter mais detalhes sobre *hRes,* consulte Observações.

*nID*<br/>
[em] O identificador de recursos onde a seqüência de descrição de erro é armazenada. Esse valor deve ficar entre 0x0200 e 0xFFFF, inclusive. Nas compilações de depuração, um **ASSERT** resultará se *o nID* não indexar uma seqüência de string válida. Nas compilações de versão, a seqüência de descrição de erro será definida como "Erro desconhecido".

*dwHelpID*<br/>
[em] O identificador de contexto de ajuda para o erro.

*lpszHelpFile*<br/>
[em] O caminho e o nome do arquivo de ajuda descrevendo o erro.

*Hinst*<br/>
[em] A alça do recurso. Por padrão, este `_AtlModule::GetResourceInstance`parâmetro `_AtlModule` é , onde está a instância global do [CAtlModule](../../atl/reference/catlmodule-class.md).

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Para `Error`chamar, seu objeto `ISupportErrorInfo Interface` deve implementar a interface.

Se o parâmetro *hRes* não `Error` for zero, então retorne o valor de *hRes*. Se *hRes* é zero, então `Error` as quatro primeiras versões de retorno DISP_E_EXCEPTION. As duas últimas versões retornam o resultado do **MAKE_HRESULT macro( 1, FACILITY_ITF,** *nID* **).**

## <a name="ccomcoclassgetobjectclsid"></a><a name="getobjectclsid"></a>CComCoClass::GetObjectCLSID

Fornece uma maneira consistente de recuperar o CLSID do objeto.

```
static const CLSID& WINAPI GetObjectCLSID();
```

### <a name="return-value"></a>Valor retornado

O identificador de classe do objeto.

## <a name="ccomcoclassgetobjectdescription"></a><a name="getobjectdescription"></a>CComCoClass::GetObjectDescription

Esta função estática recupera a descrição do texto do objeto de classe.

```
static LPCTSTR WINAPI GetObjectDescription();
```

### <a name="return-value"></a>Valor retornado

A descrição do objeto da classe.

### <a name="remarks"></a>Comentários

A implementação padrão retorna NULL. Você pode substituir este método com a [DECLARE_OBJECT_DESCRIPTION](object-map-macros.md#declare_object_description) macro. Por exemplo:

[!code-cpp[NVC_ATL_COM#12](../../atl/codesnippet/cpp/ccomcoclass-class_3.h)]

`GetObjectDescription`é chamado `IComponentRegistrar::GetComponents`por . `IComponentRegistrar`é uma interface de Automação que permite registrar e descadastrar componentes individuais em uma DLL. Quando você cria um objeto Registrador de Componentes com o `IComponentRegistrar` Assistente de Projeto ATL, o assistente implementará automaticamente a interface. `IComponentRegistrar`é normalmente usado pelo Microsoft Transaction Server.

Para obter mais informações sobre o ASSISTENTE DE PROJETO ATL, consulte o artigo [Criando um Projeto ATL](../../atl/reference/creating-an-atl-project.md).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
