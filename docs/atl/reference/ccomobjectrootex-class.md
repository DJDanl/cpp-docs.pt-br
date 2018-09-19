---
title: Classe CComObjectRootEx | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComObjectRootEx
- ATLCOM/ATL::CComObjectRootEx
- ATLCOM/ATL::InternalAddRef
- ATLCOM/ATL::InternalRelease
- ATLCOM/ATL::Lock
- ATLCOM/ATL::Unlock
- ATLCOM/ATL::FinalConstruct
- ATLCOM/ATL::FinalRelease
- ATLCOM/ATL::OuterAddRef
- ATLCOM/ATL::OuterQueryInterface
- ATLCOM/ATL::OuterRelease
- ATLCOM/ATL::InternalQueryInterface
- ATLCOM/ATL::ObjectMain
- ATLCOM/ATL::m_dwRef
- ATLCOM/ATL::m_pOuterUnknown
dev_langs:
- C++
helpviewer_keywords:
- reference counting
ms.assetid: 894a3d7c-2daf-4fd0-8fa4-e6a05bcfb631
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f24cf6cce5cdf268367f547e8a536dcdae7cc859
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46098947"
---
# <a name="ccomobjectrootex-class"></a>Classe CComObjectRootEx

Essa classe fornece métodos para lidar com o gerenciamento de contagem de referência de objeto para objetos não agregados e agregados.

## <a name="syntax"></a>Sintaxe

```
template<class ThreadModel>
class CComObjectRootEx : public CComObjectRootBase
```

#### <a name="parameters"></a>Parâmetros

*ThreadModel*<br/>
A classe cujos métodos implementam o modelo de threading desejado. Você pode escolher o modelo de threading explicitamente definindo *ThreadModel* à [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md), [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), ou [ CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md). Você pode aceitar o modelo de thread do servidor padrão, definindo *ThreadModel* à [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel).  

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CComObjectRootEx](#ccomobjectrootex)|Construtor.|
|[InternalAddRef](#internaladdref)|Incrementa a contagem de referência para um objeto não agregada.|
|[InternalRelease](#internalrelease)|Diminui a contagem de referência para um objeto não agregado.|
|[Bloqueio](#lock)|Se o modelo de thread é multithreaded, obtém a propriedade de um objeto de seção crítica.|
|[desbloquear](#unlock)|Se o modelo de thread é multithreaded, libera a propriedade de um objeto de seção crítica.|

### <a name="ccomobjectrootbase-methods"></a>Métodos de CComObjectRootBase

|||
|-|-|
|[FinalConstruct](#finalconstruct)|Substituir em sua classe para executar qualquer inicialização exigida pelo seu objeto.|
|[FinalRelease](#finalrelease)|Substituir em sua classe para realizar qualquer limpeza exigida pelo seu objeto.|
|[OuterAddRef](#outeraddref)|Incrementa a contagem de referência para um objeto agregado.|
|[OuterQueryInterface](#outerqueryinterface)|Delegados para externo `IUnknown` de um objeto agregado.|
|[OuterRelease](#outerrelease)|Diminui a contagem de referência para um objeto agregado.|

### <a name="static-functions"></a>Funções estáticas

|||
|-|-|
|[InternalQueryInterface](#internalqueryinterface)|Delega para o `IUnknown` de um objeto não agregado.|
|[ObjectMain](#objectmain)|Chamado durante a inicialização do módulo e encerramento para classes derivadas listado no mapa de objetos.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_dwRef](#m_dwref)|Com `m_pOuterUnknown`, que faz parte de uma união. Usado quando o objeto não é agregado para manter a contagem de referência de `AddRef` e `Release`.|
|[m_pOuterUnknown](#m_pouterunknown)|Com `m_dwRef`, que faz parte de uma união. Usado quando o objeto for agregado para armazenar um ponteiro para o externo desconhecido.|

## <a name="remarks"></a>Comentários

`CComObjectRootEx` lida com gerenciamento de contagem de referência de objeto para objetos não agregados e agregados. Ele armazena a contagem de referência de objeto, se seu objeto não está sendo agregado e mantém o ponteiro para o externo desconhecido se o objeto está sendo agregado. Para objetos agregados, `CComObjectRootEx` métodos podem ser usados para tratar a falha do objeto interno para construir e proteger o objeto externo quando as interfaces internas são liberadas após a exclusão ou o objeto interno é excluído.

Uma classe que implementa um servidor COM deve herdar de `CComObjectRootEx` ou [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md).

Se sua definição de classe especifica o [DECLARE_POLY_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_poly_aggregatable) macro, ATL cria uma instância de `CComPolyObject<CYourClass>` quando `IClassFactory::CreateInstance` é chamado. Durante a criação, o valor do externo desconhecido é verificado. Se for NULL, `IUnknown` é implementada para um objeto não agregado. Se o externo desconhecido não for nulo, `IUnknown` é implementada para um objeto agregado.

Se sua classe não especificar a macro DECLARE_POLY_AGGREGATABLE, ATL cria uma instância de `CAggComObject<CYourClass>` para objetos agregados ou uma instância de `CComObject<CYourClass>` para objetos não agregados.

A vantagem de usar `CComPolyObject` é que você evite ter dois `CComAggObject` e `CComObject` em seu módulo para tratar de casos agregados e não agregados. Um único `CComPolyObject` objeto lida com ambos os casos. Portanto, apenas uma cópia de vtable e uma cópia das funções existem em seu módulo. Se seu vtable for grande, isso pode diminuir substancialmente o tamanho do módulo. No entanto, se seu vtable for pequeno, usando `CComPolyObject` pode resultar em um tamanho de módulo ligeiramente maior porque ele não é otimizado para um objeto agregado ou não agregado, que estejam `CComAggObject` e `CComObject`.

Se o objeto for agregado, [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) é implementada por `CComAggObject` ou `CComPolyObject`. Essas classes delegar `QueryInterface`, `AddRef`, e `Release` chama `CComObjectRootEx`do `OuterQueryInterface`, `OuterAddRef`, e `OuterRelease` para encaminhar para o externo desconhecido. Normalmente, você substitui `CComObjectRootEx::FinalConstruct` em sua classe para criar todos os objetos agregados e substituir `CComObjectRootEx::FinalRelease` liberar todos agregados objetos.

Se o objeto não é agregado, `IUnknown` é implementado por `CComObject` ou `CComPolyObject`. Nesse caso, chamadas para `QueryInterface`, `AddRef`, e `Release` são delegadas a `CComObjectRootEx`do `InternalQueryInterface`, `InternalAddRef`, e `InternalRelease` para executar as operações reais.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="ccomobjectrootex"></a>  CComObjectRootEx::CComObjectRootEx

O construtor inicializa a contagem de referência como 0.

```
CComObjectRootEx();
```

##  <a name="finalconstruct"></a>  CComObjectRootEx::FinalConstruct

Você pode substituir esse método em sua classe derivada para executar qualquer inicialização necessária para seu objeto.

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor de retorno

Retorne S_OK no êxito ou um do erro padrão valores HRESULT.

### <a name="remarks"></a>Comentários

Por padrão, `CComObjectRootEx::FinalConstruct` simplesmente retorna S_OK.

Há vantagens em realizar a inicialização em `FinalConstruct` em vez do construtor da sua classe:

- Você não pode retornar um código de status de um construtor, mas você pode retornar um HRESULT por meio de `FinalConstruct`do valor de retorno. Quando objetos de sua classe estão sendo criados usando a fábrica de classes padrão fornecida pelo ATL, esse valor de retorno é propagado de volta para o cliente COM, permitindo que você forneça informações de erro detalhadas.

- Você não pode chamar funções virtuais por meio do mecanismo do construtor de uma classe de função virtual. Chamar uma função virtual do construtor de uma classe resulta em uma chamada estaticamente resolvida para a função que ele está definido nesse ponto na hierarquia de herança. Chamadas para funções virtuais puras resultam em erros de vinculador.

     Sua classe não é a classe mais derivada na hierarquia de herança — ele se baseia em uma classe derivada fornecida pelo ATL para fornecer algumas das suas funcionalidades. Há uma boa chance de que sua inicialização precisará usar os recursos fornecidos pela classe (Isso é certamente verdadeiro quando objetos de sua classe precisam agregar outros objetos), mas o construtor em sua classe não tem nenhuma maneira de acessar esses recursos. O código de construção para a sua classe é executado antes que a classe mais derivada está totalmente construída.

     No entanto, `FinalConstruct` é chamado imediatamente depois de mais derivado classe está totalmente construído, permitindo que você chamar funções virtuais e usar a implementação de contagem de referência fornecida pela ATL.

### <a name="example"></a>Exemplo

Normalmente, substitua este método na classe derivada de `CComObjectRootEx` criar qualquer agregados objetos. Por exemplo:

[!code-cpp[NVC_ATL_COM#40](../../atl/codesnippet/cpp/ccomobjectrootex-class_1.h)]

Se a construção falhar, você pode retornar um erro. Você também pode usar a macro [DECLARE_PROTECT_FINAL_CONSTRUCT](aggregation-and-class-factory-macros.md#declare_protect_final_construct) proteger seu objeto externo de ser excluído se, durante a criação, o objeto agregado interno incrementa a contagem de referência, em seguida, diminui a contagem como 0.

Aqui está uma maneira comum de criar uma agregação:

- Adicionar um `IUnknown` ponteiro para sua classe de objeto e inicializá-lo como NULL no construtor.

- Substituir `FinalConstruct` para criar a agregação.

- Use o `IUnknown` ponteiro definido como o parâmetro para o [COM_INTERFACE_ENTRY_AGGREGATE](com-interface-entry-macros.md#com_interface_entry_aggregate) macro.

- Substituir `FinalRelease` para liberar o `IUnknown` ponteiro.

##  <a name="finalrelease"></a>  CComObjectRootEx::FinalRelease

Você pode substituir esse método em sua classe derivada para realizar qualquer limpeza necessária para seu objeto.

```
void FinalRelease();
```

### <a name="remarks"></a>Comentários

Por padrão, `CComObjectRootEx::FinalRelease` não faz nada.

Executar limpeza na `FinalRelease` é preferível a adicionar código para o destruidor de sua classe, pois o objeto é construído ainda totalmente no ponto em que `FinalRelease` é chamado. Isso permite que você acesse com segurança os métodos fornecidos pela classe mais derivada. Isso é particularmente importante para liberar todos os objetos agregados antes da exclusão.

##  <a name="internaladdref"></a>  CComObjectRootEx::InternalAddRef

Incrementa a contagem de referência de um objeto não agregada em 1.

```
ULONG InternalAddRef();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser úteis para diagnóstico e teste.

### <a name="remarks"></a>Comentários

Se o modelo de thread é multithreaded, `InterlockedIncrement` é usado para impedir que mais de um thread altere a contagem de referência ao mesmo tempo.

##  <a name="internalqueryinterface"></a>  CComObjectRootEx::InternalQueryInterface

Recupera um ponteiro para a interface solicitada.

```
static HRESULT InternalQueryInterface(
    void* pThis,
    const _ATL_INTMAP_ENTRY* pEntries,
    REFIID iid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*pEsse*<br/>
[in] Um ponteiro para o objeto que contém o mapa COM interfaces expostas a `QueryInterface`.

*pEntries*<br/>
[in] Um ponteiro para o `_ATL_INTMAP_ENTRY` estrutura que acessa um mapa das interfaces disponíveis.

*IID*<br/>
[in] O GUID da interface que está sendo solicitado.

*ppvObject*<br/>
[out] Um ponteiro para o ponteiro de interface especificado na *iid*, ou nulo se a interface não foi encontrada.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

`InternalQueryInterface` somente lida com interfaces na tabela de mapa COM. Se o objeto for agregado, `InternalQueryInterface` não delegar para o externo desconhecido. Você pode inserir interfaces na tabela de mapa COM a macro [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) ou uma de suas variantes.

##  <a name="internalrelease"></a>  CComObjectRootEx::InternalRelease

Diminui a contagem de referência de um objeto não agregado em 1.

```
ULONG InternalRelease();
```

### <a name="return-value"></a>Valor de retorno

Em ambos não são de depuração e compilações de depuração, essa função retorna um valor que pode ser útil para diagnóstico ou teste. O valor exato retornado depende de muitos fatores, como o sistema operacional usado e pode ou não ser, ser a contagem de referência.

### <a name="remarks"></a>Comentários

Se o modelo de thread é multithreaded, `InterlockedDecrement` é usado para impedir que mais de um thread altere a contagem de referência ao mesmo tempo.

##  <a name="lock"></a>  CComObjectRootEx::Lock

Se o modelo de thread é multithreaded, este método chama a função de API do Win32 [EnterCriticalSection](/windows/desktop/api/synchapi/nf-synchapi-entercriticalsection), que aguarda até que o thread pode assumir a propriedade do objeto de seção crítica obtidos por meio de um membro de dados particulares.

```
void Lock();
```

### <a name="remarks"></a>Comentários

Quando o código protegido termina a execução, o thread deve chamar `Unlock` para liberar a propriedade da seção crítica.

Se o modelo de thread é single-threaded, esse método não fará nada.

##  <a name="m_dwref"></a>  CComObjectRootEx::m_dwRef

Parte de uma união que acessa quatro bytes de memória.

```
long m_dwRef;
```

### <a name="remarks"></a>Comentários

Com `m_pOuterUnknown`, que faz parte de uma união:  

```
union {
    long m_dwRef;
    IUnknown* m_pOuterUnknown;
};
```

Se o objeto não é agregado, a contagem de referência é acessado por `AddRef` e `Release` são armazenados em `m_dwRef`. Se o objeto for agregado, o ponteiro para o externo desconhecido é armazenado no [m_pOuterUnknown](#m_pouterunknown).

##  <a name="m_pouterunknown"></a>  CComObjectRootEx::m_pOuterUnknown

Parte de uma união que acessa quatro bytes de memória.

```
IUnknown*
    m_pOuterUnknown;
```

### <a name="remarks"></a>Comentários

Com `m_dwRef`, que faz parte de uma união:

```
union {
    long m_dwRef;
    IUnknown* m_pOuterUnknown;
};
```

Se o objeto for agregado, o ponteiro para o externo desconhecido é armazenado em `m_pOuterUnknown`. Se o objeto não é agregado, a contagem de referência é acessado por `AddRef` e `Release` é armazenado em [m_dwRef](#m_dwref).

##  <a name="objectmain"></a>  CComObjectRootEx::ObjectMain

Para cada classe listado no mapa de objetos, essa função é chamada depois que quando o módulo é inicializado, e novamente quando ele é encerrado.

```
static void WINAPI ObjectMain(bool bStarting);
```

### <a name="parameters"></a>Parâmetros

*bStarting*<br/>
[out] O valor será TRUE se a classe está sendo inicializada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O valor de *bStarting* parâmetro indica se o módulo está sendo inicializado ou encerrada. A implementação padrão de `ObjectMain` não faz nada, mas você pode substituir essa função em sua classe para inicializá-la ou limpar os recursos que você deseja alocar para a classe. Observe que `ObjectMain` é chamado antes que todas as instâncias da classe são solicitadas.

`ObjectMain` é chamado de ponto de entrada da DLL, portanto, o tipo de operação que a função de ponto de entrada pode executar é restrito. Para obter mais informações sobre essas restrições, consulte [DLLs e Visual C++ comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md) e [DllMain](/windows/desktop/Dlls/dllmain).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#41](../../atl/codesnippet/cpp/ccomobjectrootex-class_2.h)]

##  <a name="outeraddref"></a>  CComObjectRootEx::OuterAddRef

Incrementa a contagem de referência do desconhecido de uma agregação externa.

```
ULONG OuterAddRef();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser úteis para diagnóstico e teste.

##  <a name="outerqueryinterface"></a>  CComObjectRootEx::OuterQueryInterface

Recupera um ponteiro indireto para a interface solicitada.

```
HRESULT OuterQueryInterface(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
[in] O GUID da interface que está sendo solicitado.

*ppvObject*<br/>
[out] Um ponteiro para o ponteiro de interface especificado na *iid*, ou nulo se a agregação não suporta a interface.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="outerrelease"></a>  CComObjectRootEx::OuterRelease

Diminui a contagem de referência do desconhecido de uma agregação externo.

```
ULONG OuterRelease();
```

### <a name="return-value"></a>Valor de retorno

Em compilações sem depuração, sempre retorna 0. Em compilações de depuração, retorna um valor que pode ser úteis para diagnóstico ou teste.

##  <a name="unlock"></a>  CComObjectRootEx::Unlock

Se o modelo de thread é multithreaded, este método chama a função de API do Win32 [LeaveCriticalSection](/windows/desktop/api/synchapi/nf-synchapi-leavecriticalsection), que libera a propriedade do objeto de seção crítica obtidos por meio de um membro de dados particulares.

```
void Unlock();
```

### <a name="remarks"></a>Comentários

Para obter a propriedade, o thread deve chamar `Lock`. Cada chamada para `Lock` requer uma chamada correspondente para `Unlock` para liberar a propriedade da seção crítica.

Se o modelo de thread é single-threaded, esse método não fará nada.

## <a name="see-also"></a>Consulte também

[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
