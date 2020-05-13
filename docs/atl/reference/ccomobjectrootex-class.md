---
title: Classe CcomObjectRootEx
ms.date: 11/04/2016
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
helpviewer_keywords:
- reference counting
ms.assetid: 894a3d7c-2daf-4fd0-8fa4-e6a05bcfb631
ms.openlocfilehash: 87e2d7dca81221f4fac2a5189ecb0effbdceddc2
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747911"
---
# <a name="ccomobjectrootex-class"></a>Classe CcomObjectRootEx

Esta classe fornece métodos para lidar com o gerenciamento da contagem de referência de objetos para objetos não agregados e agregados.

## <a name="syntax"></a>Sintaxe

```
template<class ThreadModel>
class CComObjectRootEx : public CComObjectRootBase
```

#### <a name="parameters"></a>Parâmetros

*Modelo de thread*<br/>
A classe cujos métodos implementam o modelo de rosca desejado. Você pode escolher explicitamente o modelo de rosca definindo *ThreadModel* para [CComSingleThreadModel,](../../atl/reference/ccomsinglethreadmodel-class.md) [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md)ou [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md). Você pode aceitar o modelo de segmento padrão do servidor definindo *ThreadModel* para [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel).

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Ccomobjectrootex](#ccomobjectrootex)|Construtor.|
|[Internaladdref](#internaladdref)|Incrementa a contagem de referência para um objeto não agregado.|
|[Internalrelease](#internalrelease)|Decreta a contagem de referência para um objeto não agregado.|
|[Bloqueio](#lock)|Se o modelo de rosca for multithreaded, obtém a propriedade de um objeto de seção crítica.|
|[Desbloquear](#unlock)|Se o modelo de rosca for multithreaded, liberaa a propriedade de um objeto de seção crítica.|

### <a name="ccomobjectrootbase-methods"></a>Métodos CComObjectRootBase

|||
|-|-|
|[Finalconstruct](#finalconstruct)|Substituir em sua classe para executar qualquer inicialização exigida pelo seu objeto.|
|[Finalrelease](#finalrelease)|Anular em sua classe para realizar qualquer limpeza exigida pelo seu objeto.|
|[OuterAddRef](#outeraddref)|Incrementa a contagem de referência para um objeto agregado.|
|[OuterQueryInterface](#outerqueryinterface)|Delegados para `IUnknown` o exterior de um objeto agregado.|
|[Liberação externa](#outerrelease)|Decreta a contagem de referência para um objeto agregado.|

### <a name="static-functions"></a>Funções estáticas

|||
|-|-|
|[Internalqueryinterface](#internalqueryinterface)|Delegados para `IUnknown` um objeto não agregado.|
|[Objectmain](#objectmain)|Chamado durante a inicialização e terminação do módulo para classes derivadas listadas no mapa do objeto.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[m_dwRef](#m_dwref)|Com `m_pOuterUnknown`parte de um sindicato. Usado quando o objeto não é agregado `AddRef` para `Release`manter a contagem de referência de e .|
|[m_pOuterUnknown](#m_pouterunknown)|Com `m_dwRef`parte de um sindicato. Usado quando o objeto é agregado para segurar um ponteiro para o desconhecido externo.|

## <a name="remarks"></a>Comentários

`CComObjectRootEx`lida com o gerenciamento da contagem de objetos para objetos não agregados e agregados. Ele mantém a contagem de referência do objeto se o objeto não estiver sendo agregado e mantém o ponteiro para o desconhecido externo se seu objeto está sendo agregado. Para objetos `CComObjectRootEx` agregados, os métodos podem ser usados para lidar com a falha do objeto interno para construir e para proteger o objeto externo da exclusão quando as interfaces internas são liberadas ou o objeto interno é excluído.

Uma classe que implementa um `CComObjectRootEx` servidor COM deve herdar ou [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md).

Se a definição de [DECLARE_POLY_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_poly_aggregatable) classe especificar a DECLARE_POLY_AGGREGATABLE `CComPolyObject<CYourClass>` `IClassFactory::CreateInstance` macro, a ATL criará uma instância de quando é chamada. Durante a criação, o valor do desconhecido externo é verificado. Se for NULO, `IUnknown` é implementado para um objeto não agregado. Se o desconhecido externo `IUnknown` não for NULO, é implementado para um objeto agregado.

Se sua classe não especificar a macro DECLARE_POLY_AGGREGATABLE, a ATL criará uma instância de `CAggComObject<CYourClass>` para objetos agregados ou uma instância de `CComObject<CYourClass>` para objetos não agregados.

A vantagem `CComPolyObject` de usar é `CComAggObject` que `CComObject` você evita ter ambos e em seu módulo para lidar com os casos agregados e não agregados. Um `CComPolyObject` único objeto lida com ambos os casos. Portanto, apenas uma cópia do vtable e uma cópia das funções existem em seu módulo. Se o seu vtable for grande, isso pode diminuir substancialmente o tamanho do seu módulo. No entanto, se o `CComPolyObject` seu vtable for pequeno, o uso pode resultar em um tamanho de `CComAggObject` módulo `CComObject`ligeiramente maior, porque não é otimizado para um objeto agregado ou não agregado, como são e .

Se o seu objeto for agregado, `CComAggObject` `CComPolyObject` [o IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) será implementado por ou . Essas classes `QueryInterface` `AddRef`delegam `CComObjectRootEx`, `OuterQueryInterface`e `OuterAddRef` `Release` ligam para o 's , e `OuterRelease` para encaminhar para o desconhecido exterior. Normalmente, você `CComObjectRootEx::FinalConstruct` sobrepor em sua classe para criar `CComObjectRootEx::FinalRelease` quaisquer objetos agregados e substituir para libertar quaisquer objetos agregados.

Se o objeto não `IUnknown` for agregado, será implementado por `CComObject` ou `CComPolyObject`. Neste caso, chamadas `QueryInterface` `AddRef`para `Release` , e `CComObjectRootEx`são `InternalQueryInterface`delegadas para 's , `InternalAddRef`e `InternalRelease` para realizar as operações reais.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomobjectrootexccomobjectrootex"></a><a name="ccomobjectrootex"></a>Ccomobjectrootex::Ccomobjectrootex

O construtor inicializa a contagem de referência para 0.

```
CComObjectRootEx();
```

## <a name="ccomobjectrootexfinalconstruct"></a><a name="finalconstruct"></a>Ccomobjectrootex::FinalConstruct

Você pode substituir este método em sua classe derivada para executar qualquer inicialização necessária para o seu objeto.

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso ou em um dos valores padrão de erro HRESULT.

### <a name="remarks"></a>Comentários

Por padrão, `CComObjectRootEx::FinalConstruct` basta retornar S_OK.

Há vantagens em realizar `FinalConstruct` a inicialização em vez de o construtor de sua classe:

- Você não pode retornar um código de status de um construtor, mas você pode retornar um HRESULT por meio do valor de `FinalConstruct`retorno. Quando objetos de sua classe estão sendo criados usando a fábrica de classe padrão fornecida pela ATL, esse valor de retorno é propagado de volta para o cliente COM, permitindo que você forneça informações detalhadas sobre erros.

- Você não pode chamar funções virtuais através do mecanismo de função virtual do construtor de uma classe. Chamar uma função virtual do construtor de uma classe resulta em uma chamada estáticamente resolvida para a função como ela é definida naquele ponto na hierarquia de herança. Chamadas para funções virtuais puras resultam em erros de linker.

   Sua classe não é a classe mais derivada na hierarquia de herança — ela conta com uma classe derivada fornecida pela ATL para fornecer algumas de suas funcionalidades. Há uma boa chance de que sua inicialização precise usar os recursos fornecidos por essa classe (isso certamente é verdade quando objetos da sua classe precisam agregar outros objetos), mas o construtor da sua classe não tem como acessar esses recursos. O código de construção da sua classe é executado antes que a classe mais derivada seja totalmente construída.

   No `FinalConstruct` entanto, é chamado imediatamente após a classe mais derivada ser totalmente construída, permitindo que você chame funções virtuais e use a implementação de contagem de referência fornecida pela ATL.

### <a name="example"></a>Exemplo

Normalmente, anular esse método na classe `CComObjectRootEx` derivada para criar quaisquer objetos agregados. Por exemplo:

[!code-cpp[NVC_ATL_COM#40](../../atl/codesnippet/cpp/ccomobjectrootex-class_1.h)]

Se a construção falhar, você pode retornar um erro. Você também pode usar a [DECLARE_PROTECT_FINAL_CONSTRUCT](aggregation-and-class-factory-macros.md#declare_protect_final_construct) de macro para proteger seu objeto externo de ser excluído se, durante a criação, o objeto agregado interno incrementar a contagem de referência e, em seguida, diminuir a contagem para 0.

Aqui está uma maneira típica de criar um agregado:

- Adicione `IUnknown` um ponteiro ao objeto de classe e inicialize-o para NULL no construtor.

- Anular `FinalConstruct` para criar o agregado.

- Use `IUnknown` o ponteiro definido como parâmetro para a [COM_INTERFACE_ENTRY_AGGREGATE](com-interface-entry-macros.md#com_interface_entry_aggregate) macro.

- Anular `FinalRelease` para soltar `IUnknown` o ponteiro.

## <a name="ccomobjectrootexfinalrelease"></a><a name="finalrelease"></a>Ccomobjectrootex::Finalrelease

Você pode substituir este método em sua classe derivada para realizar qualquer limpeza necessária para o seu objeto.

```cpp
void FinalRelease();
```

### <a name="remarks"></a>Comentários

Por padrão, `CComObjectRootEx::FinalRelease` não faz nada.

Realizar a limpeza `FinalRelease` é preferível adicionar código ao destruidor de sua classe, uma vez que o `FinalRelease` objeto ainda está totalmente construído no ponto em que é chamado. Isso permite que você acesse com segurança os métodos fornecidos pela classe mais derivada. Isso é particularmente importante para liberar quaisquer objetos agregados antes da exclusão.

## <a name="ccomobjectrootexinternaladdref"></a><a name="internaladdref"></a>Ccomobjectrootex::Internaladdref

Incrementa a contagem de referência de um objeto não agregado por 1.

```
ULONG InternalAddRef();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos e testes.

### <a name="remarks"></a>Comentários

Se o modelo de rosca for multithreaded, `InterlockedIncrement` é usado para evitar que mais de um segmento mude a contagem de referência ao mesmo tempo.

## <a name="ccomobjectrootexinternalqueryinterface"></a><a name="internalqueryinterface"></a>CComObjectRootEx::InternalQueryInterface

Recupera um ponteiro para a interface solicitada.

```
static HRESULT InternalQueryInterface(
    void* pThis,
    const _ATL_INTMAP_ENTRY* pEntries,
    REFIID iid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*Pthis*<br/>
[em] Um ponteiro para o objeto que contém o `QueryInterface`mapa COM de interfaces expostas a .

*entradas pEntries*<br/>
[em] Um ponteiro `_ATL_INTMAP_ENTRY` para a estrutura que acessa um mapa de interfaces disponíveis.

*Iid*<br/>
[em] O GUID da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface especificado em *iid*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

`InternalQueryInterface` somente lida com interfaces na tabela de mapa COM. Se o objeto estiver `InternalQueryInterface` agregado, não delege ao desconhecido externo. Você pode inserir interfaces na tabela de mapas COM com o [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) de macro ou uma de suas variantes.

## <a name="ccomobjectrootexinternalrelease"></a><a name="internalrelease"></a>Ccomobjectrootex::Internalrelease

Diminui a contagem de referência de um objeto não agregado por 1.

```
ULONG InternalRelease();
```

### <a name="return-value"></a>Valor retornado

Em construções não depuradas e depuradas, essa função retorna um valor que pode ser útil para diagnósticos ou testes. O valor exato devolvido depende de muitos fatores, como o sistema operacional utilizado, podendo, ou não, ser a contagem de referência.

### <a name="remarks"></a>Comentários

Se o modelo de rosca for multithreaded, `InterlockedDecrement` é usado para evitar que mais de um segmento mude a contagem de referência ao mesmo tempo.

## <a name="ccomobjectrootexlock"></a><a name="lock"></a>Ccomobjectrootex::bloqueio

Se o modelo de segmento for multithreaded, este método chama a função API Do Win32 [EnterCriticalSection](/windows/win32/api/synchapi/nf-synchapi-entercriticalsection), que espera até que o segmento possa assumir a propriedade do objeto de seção crítica obtido através de um membro de dados privado.

```cpp
void Lock();
```

### <a name="remarks"></a>Comentários

Quando o código protegido terminar de executar, o segmento deve chamar `Unlock` para liberar a propriedade da seção crítica.

Se o modelo de rosca for de um único fio, este método não faz nada.

## <a name="ccomobjectrootexm_dwref"></a><a name="m_dwref"></a>Ccomobjectrootex::m_dwRef

Parte de uma união que acessa quatro bytes de memória.

```
long m_dwRef;
```

### <a name="remarks"></a>Comentários

Com `m_pOuterUnknown`, parte de um sindicato:

```
union {
    long m_dwRef;
    IUnknown* m_pOuterUnknown;
};
```

Se o objeto não for agregado, a `AddRef` `Release` contagem `m_dwRef`de referência é acessada e armazenada em . Se o objeto for agregado, o ponteiro para o desconhecido externo será armazenado em [m_pOuterUnknown](#m_pouterunknown).

## <a name="ccomobjectrootexm_pouterunknown"></a><a name="m_pouterunknown"></a>Ccomobjectrootex::m_pOuterUnknown

Parte de uma união que acessa quatro bytes de memória.

```
IUnknown*
    m_pOuterUnknown;
```

### <a name="remarks"></a>Comentários

Com `m_dwRef`, parte de um sindicato:

```
union {
    long m_dwRef;
    IUnknown* m_pOuterUnknown;
};
```

Se o objeto for agregado, o ponteiro para `m_pOuterUnknown`o desconhecido externo será armazenado em . Se o objeto não for agregado, a `AddRef` `Release` contagem de referência é acessada e armazenada em [m_dwRef](#m_dwref).

## <a name="ccomobjectrootexobjectmain"></a><a name="objectmain"></a>Ccomobjectrootex::ObjectMain

Para cada classe listada no mapa do objeto, essa função é chamada uma vez quando o módulo é inicializado e novamente quando é encerrado.

```
static void WINAPI ObjectMain(bool bStarting);
```

### <a name="parameters"></a>Parâmetros

*bComeçando*<br/>
[fora] O valor é VERDADEIRO se a classe estiver sendo inicializada; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O valor do *parâmetro bStarting* indica se o módulo está sendo inicializado ou encerrado. A implementação `ObjectMain` padrão de não faz nada, mas você pode substituir essa função em sua classe para inicializar ou limpar os recursos que deseja alocar para a classe. Observe `ObjectMain` que é chamado antes de qualquer instância da classe ser solicitada.

`ObjectMain`é chamado a partir do ponto de entrada da DLL, de modo que o tipo de operação que a função de ponto de entrada pode executar é restrito. Para obter mais informações sobre essas restrições, consulte [DLLs e visual C++ comportamento de biblioteca de tempo de execução](../../build/run-time-library-behavior.md) e [DllMain](/windows/win32/Dlls/dllmain).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#41](../../atl/codesnippet/cpp/ccomobjectrootex-class_2.h)]

## <a name="ccomobjectrootexouteraddref"></a><a name="outeraddref"></a>Ccomobjectrootex::Outeraddref

Incrementa a contagem de referência do desconhecido externo de uma agregação.

```
ULONG OuterAddRef();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos e testes.

## <a name="ccomobjectrootexouterqueryinterface"></a><a name="outerqueryinterface"></a>CComObjectRootEx::OuterQueryInterface

Recupera um ponteiro indireto para a interface solicitada.

```
HRESULT OuterQueryInterface(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface especificado em *iid*, ou NULL se a agregação não suportar a interface.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomobjectrootexouterrelease"></a><a name="outerrelease"></a>Ccomobjectrootex::Liberação externa

Decreta a contagem de referência do desconhecido externo de uma agregação.

```
ULONG OuterRelease();
```

### <a name="return-value"></a>Valor retornado

Em construções não-depuradas, sempre retorna 0. Nas compilações de depuração, retorna um valor que pode ser útil para diagnósticos ou testes.

## <a name="ccomobjectrootexunlock"></a><a name="unlock"></a>CcomObjectrootEx::Desbloquear

Se o modelo de segmento for multithreaded, este método chama a função API Win32 [LeaveCriticalSection](/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection), que libera a propriedade do objeto de seção crítica obtido através de um membro de dados privado.

```cpp
void Unlock();
```

### <a name="remarks"></a>Comentários

Para obter a propriedade, `Lock`o segmento deve chamar . Cada chamada `Lock` requer uma `Unlock` chamada correspondente para liberar a propriedade da seção crítica.

Se o modelo de rosca for de um único fio, este método não faz nada.

## <a name="see-also"></a>Confira também

[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
