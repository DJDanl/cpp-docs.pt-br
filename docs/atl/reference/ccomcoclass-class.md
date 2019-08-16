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
ms.openlocfilehash: 5b4e39fa4d93893d288bb8de03d8a71b671be087
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497379"
---
# <a name="ccomcoclass-class"></a>Classe CComCoClass

Essa classe fornece métodos para criar instâncias de uma classe e obter suas propriedades.

## <a name="syntax"></a>Sintaxe

```
template <class T, const CLSID* pclsid = &CLSID_NULL>
class CComCoClass
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `CComCoClass`.

*pclsid*<br/>
Um ponteiro para o CLSID do objeto.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCoClass::CreateInstance](#createinstance)|Auto-estática Cria uma instância da classe e as consultas para uma interface.|
|[CComCoClass::Error](#error)|Auto-estática Retorna informações de erro avançadas para o cliente.|
|[CComCoClass::GetObjectCLSID](#getobjectclsid)|Auto-estática Retorna o identificador de classe do objeto.|
|[CComCoClass::GetObjectDescription](#getobjectdescription)|Auto-estática Substituir para retornar a descrição do objeto.|

## <a name="remarks"></a>Comentários

`CComCoClass`fornece métodos para recuperar o CLSID de um objeto, definir informações de erro e criar instâncias da classe. Qualquer classe registrada no mapa de objetos deve ser derivada `CComCoClass`de.

`CComCoClass`também define a fábrica de classes padrão e o modelo de agregação para seu objeto. `CComCoClass`o usa as duas macros a seguir:

- [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory) Declara a fábrica de classes a ser [CComClassFactory](../../atl/reference/ccomclassfactory-class.md).

- [DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable) Declara que o objeto pode ser agregado.

Você pode substituir qualquer um desses padrões especificando outra macro na definição de sua classe. Por exemplo, para usar [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) em vez `CComClassFactory`de, especifique a macro [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) :

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/ccomcoclass-class_1.h)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="createinstance"></a>  CComCoClass::CreateInstance

Use essas `CreateInstance` funções para criar uma instância de um objeto com e recuperar um ponteiro de interface sem usar a API com.

```
template <class  Q>
static HRESULT CreateInstance( Q** pp);

template <class  Q>
static HRESULT CreateInstance(IUnknown* punkOuter, Q** pp);
```

### <a name="parameters"></a>Parâmetros

*Q*<br/>
A interface COM que deve ser retornada via *PP*.

*punkOuter*<br/>
no O desconhecido externo ou controlando o desconhecido da agregação.

*pp*<br/>
fora O endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitado se a criação for realizada com sucesso.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão. Consulte [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) no SDK do Windows para obter uma descrição dos possíveis valores de retorno.

### <a name="remarks"></a>Comentários

Use a primeira sobrecarga dessa função para a criação típica de objeto; Use a segunda sobrecarga quando precisar agregar o objeto que está sendo criado.

A classe ATL que implementa o objeto COM necessário (ou seja, a classe usada como o primeiro parâmetro de modelo para [CComCoClass](../../atl/reference/ccomcoclass-class.md)) deve estar no mesmo projeto que o código de chamada. A criação do objeto COM é executada pela fábrica de classes registrada para esta classe ATL.

Essas funções são úteis para criar objetos que você impediu de ser externamente creatable usando a macro [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](object-map-macros.md#object_entry_non_createable_ex_auto) . Eles também são úteis em situações em que você deseja evitar a API COM por motivos de eficiência.

Observe que a interface *Q* deve ter um IID associado a ele que possa ser recuperado usando o operador [__uuidof](../../cpp/uuidof-operator.md) .

### <a name="example"></a>Exemplo

No exemplo a seguir, `CDocument` é uma classe ATL gerada por assistente derivada de `CComCoClass` que implementa a `IDocument` interface. A classe é registrada no mapa de objetos com a macro OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO para que os clientes não possam criar instâncias do documento usando [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance). `CApplication`é uma coclass que fornece um método em uma de suas próprias interfaces COM para criar instâncias da classe de documento. O código a seguir mostra como é fácil criar instâncias da classe de documento usando o `CreateInstance` membro herdado `CComCoClass` da classe base.

[!code-cpp[NVC_ATL_COM#11](../../atl/codesnippet/cpp/ccomcoclass-class_2.cpp)]

##  <a name="error"></a>  CComCoClass::Error

Essa função estática configura a `IErrorInfo` interface para fornecer informações de erro ao cliente.

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

*lpszDesc*<br/>
no A cadeia de caracteres que descreve o erro. A versão Unicode de `Error` especifica que *lpszDesc* é do tipo LPCOLESTR; a versão ANSI especifica um tipo de LPCSTR.

*iid*<br/>
no O IID da interface que define o erro ou GUID_NULL (o valor padrão) se o erro for definido pelo sistema operacional.

*hRes*<br/>
no O HRESULT que você deseja retornar ao chamador. O valor padrão é 0. Para obter mais detalhes sobre *hRes*, consulte comentários.

*nID*<br/>
no O identificador de recurso em que a cadeia de caracteres de descrição do erro é armazenada. Esse valor deve estar entre 0x0200 e 0xFFFF, inclusive. Em compilações de depuração, uma **declaração** resultará se *NID* não indexar uma cadeia de caracteres válida. Em builds de versão, a cadeia de caracteres de descrição do erro será definida como "erro desconhecido".

*dwHelpID*<br/>
no O identificador de contexto da ajuda para o erro.

*lpszHelpFile*<br/>
no O caminho e o nome do arquivo de ajuda que descreve o erro.

*hInst*<br/>
no O identificador para o recurso. Por padrão, esse parâmetro é `_AtlModule::GetResourceInstance`, em `_AtlModule` que é a instância global de [CAtlModule](../../atl/reference/catlmodule-class.md).

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Para chamar `Error`, o objeto deve implementar a `ISupportErrorInfo Interface` interface.

Se o parâmetro *hRes* for diferente de zero `Error` , o retornará o valor de *hRes*. Se *hRes* for zero, as quatro primeiras versões de `Error` retornam DISP_E_EXCEPTION. As duas últimas versões retornam o resultado da macro **MAKE_HRESULT (1, FACILITY_ITF,** *NID* **)** .

##  <a name="getobjectclsid"></a>  CComCoClass::GetObjectCLSID

Fornece uma maneira consistente de recuperar o CLSID do objeto.

```
static const CLSID& WINAPI GetObjectCLSID();
```

### <a name="return-value"></a>Valor de retorno

O identificador de classe do objeto.

##  <a name="getobjectdescription"></a>  CComCoClass::GetObjectDescription

Essa função estática recupera a descrição de texto para seu objeto de classe.

```
static LPCTSTR WINAPI GetObjectDescription();
```

### <a name="return-value"></a>Valor de retorno

A descrição do objeto de classe.

### <a name="remarks"></a>Comentários

A implementação padrão retorna NULL. Você pode substituir esse método pela macro [DECLARE_OBJECT_DESCRIPTION](object-map-macros.md#declare_object_description) . Por exemplo:

[!code-cpp[NVC_ATL_COM#12](../../atl/codesnippet/cpp/ccomcoclass-class_3.h)]

`GetObjectDescription`é chamado por `IComponentRegistrar::GetComponents`. `IComponentRegistrar`é uma interface de automação que permite registrar e cancelar o registro de componentes individuais em uma DLL. Quando você cria um objeto de registrador de componente com o assistente de projeto ATL, o assistente `IComponentRegistrar` implementa automaticamente a interface. `IComponentRegistrar`normalmente é usado pelo Microsoft Transaction Server.

Para obter mais informações sobre o assistente de projeto do ATL, consulte o artigo [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
