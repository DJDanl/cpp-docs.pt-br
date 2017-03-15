---
title: Classe CComObjectRootEx | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CComObjectRootEx
- ATL::CComObjectRootEx<ThreadModel>
- CComObjectRootEx
- ATL::CComObjectRootEx
- ATL.CComObjectRootEx<ThreadModel>
dev_langs:
- C++
helpviewer_keywords:
- reference counting
ms.assetid: 894a3d7c-2daf-4fd0-8fa4-e6a05bcfb631
caps.latest.revision: 20
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
translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: f3a6d26ddb4f612824f959ca3046531dc3bbf2a9
ms.lasthandoff: 02/25/2017

---
# <a name="ccomobjectrootex-class"></a>Classe CComObjectRootEx
Essa classe fornece métodos para lidar com o gerenciamento de contagem de referência de objeto para objetos agregados e agregados.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class ThreadModel>  
class CComObjectRootEx : public CComObjectRootBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ThreadModel`  
 A classe cujos métodos de implementam o modelo de threading desejado. Você pode escolher o modelo de threading explicitamente definindo `ThreadModel` para [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md), [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), ou [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md). Você pode aceitar o modelo de thread do servidor padrão definindo `ThreadModel` para [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel).  

  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CComObjectRootEx](#ccomobjectrootex)|Construtor.|  
|[InternalAddRef](#internaladdref)|Incrementa a contagem de referência para um objeto agregado.|  
|[InternalRelease](#internalrelease)|Diminui a contagem de referência para um objeto agregado.|  
|[Bloqueio](#lock)|Se o modelo de thread é multithreaded, obtém a propriedade de um objeto da seção crítica.|  
|[Desbloquear](#unlock)|Se o modelo de thread é multithreaded, libera a propriedade de um objeto da seção crítica.|  
  
### <a name="ccomobjectrootbase-methods"></a>Métodos de CComObjectRootBase  
  
|||  
|-|-|  
|[FinalConstruct](#finalconstruct)|Substituir em sua classe para realizar qualquer inicialização exigida pelo seu objeto.|  
|[FinalRelease](#finalrelease)|Substituir em sua classe para executar qualquer limpeza exigida pelo seu objeto.|  
|[OuterAddRef](#outeraddref)|Incrementa a contagem de referência para um objeto agregado.|  
|[OuterQueryInterface](#outerqueryinterface)|Delegados para externo **IUnknown** de um objeto agregado.|  
|[OuterRelease](#outerrelease)|Diminui a contagem de referência para um objeto agregado.|  
  
### <a name="static-functions"></a>Funções estáticas  
  
|||  
|-|-|  
|[InternalQueryInterface](#internalqueryinterface)|Delega para o **IUnknown** de um objeto agregado.|  
|[ObjectMain](#objectmain)|Chamado durante a inicialização do módulo e finalização para classes derivadas listado no mapa do objeto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_dwRef](#m_dwref)|Com `m_pOuterUnknown`, parte de uma união. Usado quando o objeto não é agregado para manter a contagem de referência de `AddRef` e **versão**.|  
|[m_pOuterUnknown](#m_pouterunknown)|Com `m_dwRef`, parte de uma união. Usado quando o objeto é agregado para armazenar um ponteiro para o externo desconhecido.|  
  
## <a name="remarks"></a>Comentários  
 `CComObjectRootEx`lida com gerenciamento de contagem de referência de objeto para objetos agregados e agregados. Ele contém a contagem de referência de objeto se o objeto não está sendo agregado e mantém o ponteiro para o externo desconhecido se o objeto está sendo agregado. Objetos agregados, `CComObjectRootEx` métodos podem ser usados para lidar com falhas do objeto interno para construir e proteger o objeto externo da exclusão quando forem lançadas interfaces internas ou o objeto interno é excluído.  
  
 Uma classe que implementa um servidor COM deve herdar de `CComObjectRootEx` ou [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md).  
  
 Se sua definição de classe especifica o [DECLARE_POLY_AGGREGATABLE](http://msdn.microsoft.com/library/7569e738-cfbc-4404-ba1d-78dcefa3bdb3) macro, ATL cria uma instância de **CComPolyObject\<CYourClass >** quando **IClassFactory** é chamado. Durante a criação, o valor de externo desconhecido é verificado. Se for **nulo**, **IUnknown** é implementada por um objeto agregado. Se o externo desconhecido não é **nulo**, **IUnknown** é implementada por um objeto agregado.  
  
 Se sua classe não especificar o `DECLARE_POLY_AGGREGATABLE` macro, ATL cria uma instância de **CAggComObject\<CYourClass >** para objetos agregados ou uma instância de **CComObject\<CYourClass >** para objetos agregados.  
  
 A vantagem de usar `CComPolyObject` é evitar ter que ambos `CComAggObject` e `CComObject` no módulo para tratar de casos agregados e agregados. Um único `CComPolyObject` ambos os casos alças do objeto. Portanto, apenas uma cópia do vtable e uma cópia das funções existem em seu módulo. Se seu vtable for grande, isso poderá diminuir substancialmente o tamanho do módulo. No entanto, se seu vtable for pequeno, usando `CComPolyObject` pode resultar em um tamanho ligeiramente maior do módulo porque ele não é otimizado para um objeto agregado ou agregado, como são `CComAggObject` e `CComObject`.  
  
 Se o objeto é agregado, [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) é implementado por `CComAggObject` ou `CComPolyObject`. Essas classes delegar `QueryInterface`, `AddRef`, e **versão** chama `CComObjectRootEx`do `OuterQueryInterface`, `OuterAddRef`, e `OuterRelease` para encaminhar para o externo desconhecido. Normalmente, você substituir `CComObjectRootEx::FinalConstruct` em sua classe para criar os objetos agregados e substituir `CComObjectRootEx::FinalRelease` liberar qualquer agregados objetos.  
  
 Se o objeto não é agregado, **IUnknown** é implementado por `CComObject` ou `CComPolyObject`. Nesse caso, chamadas para `QueryInterface`, `AddRef`, e **versão** são delegadas a `CComObjectRootEx`do `InternalQueryInterface`, `InternalAddRef`, e `InternalRelease` para executar as operações reais.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-nameccomobjectrootexa--ccomobjectrootexccomobjectrootex"></a><a name="ccomobjectrootex"></a>CComObjectRootEx::CComObjectRootEx  
 O construtor inicializa a contagem de referência como 0.  
  
```
CComObjectRootEx();
```  
  
##  <a name="a-namefinalconstructa--ccomobjectrootexfinalconstruct"></a><a name="finalconstruct"></a>CComObjectRootEx::FinalConstruct  
 Você pode substituir esse método em sua classe derivada para executar qualquer inicialização necessária para seu objeto.  
  
```
HRESULT FinalConstruct();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornar `S_OK` no sucesso ou um erro padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `CComObjectRootEx::FinalConstruct` simplesmente retorna `S_OK`.  
  
 Há vantagens em realizar a inicialização em `FinalConstruct` em vez do construtor da classe:  
  
-   Você não pode retornar um código de status de um construtor, mas você pode retornar um `HRESULT` por meio de `FinalConstruct`do valor de retorno. Quando objetos de sua classe estão sendo criados usando a fábrica de classes padrão fornecida pelo ATL, esse valor de retorno é propagado de volta para o cliente de COM, permitindo que você fornecer informações de erro detalhadas.  
  
-   Você não pode chamar funções virtuais por meio do mecanismo do construtor de uma classe de função virtual. Chamar uma função virtual do construtor de uma classe resulta em uma chamada resolvida estaticamente para a função como definido nesse ponto na hierarquia de herança. Chamadas a funções virtuais puras resultam em erros de vinculador.  
  
     A classe não é a classe mais derivada na hierarquia de herança — ele se baseia em uma classe derivada fornecida pelo ATL para fornecer algumas das suas funcionalidades. Há uma boa chance de que sua inicialização precisará usar os recursos fornecidos pela classe (Isso é certamente verdadeiro quando objetos de sua classe precisam agregar outros objetos), mas o construtor em sua classe não tem nenhuma maneira de acessar esses recursos. O código de construção para a sua classe é executado antes que a classe mais derivada é totalmente construída.  
  
     No entanto, `FinalConstruct` é chamado imediatamente depois de mais derivado classe totalmente é construída, permitindo que você chamar funções virtuais e usar a implementação de contagem de referência fornecida pela ATL.  
  
### <a name="example"></a>Exemplo  
 Normalmente, substitui esse método na classe derivada de `CComObjectRootEx` criar qualquer agregados objetos. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM&40;](../../atl/codesnippet/cpp/ccomobjectrootex-class_1.h)]  
  
 Se a construção falhar, você pode retornar um erro. Você também pode usar a macro [DECLARE_PROTECT_FINAL_CONSTRUCT](http://msdn.microsoft.com/library/2d2e5ddc-057a-43ca-87c8-d3477a8193a0) proteger seu objeto externo de ser excluído se, durante a criação do objeto interno agregado incrementa a contagem de referência e diminui a contagem como 0.  
  
 Aqui está uma forma comum de criar uma agregação:  
  
-   Adicionar uma **IUnknown** ponteiro para sua classe de objeto e inicializá-la para **nulo** no construtor.  
  
-   Substituir `FinalConstruct` para criar a agregação.  
  
-   Use o **IUnknown** ponteiro definido como o parâmetro para o [COM_INTERFACE_ENTRY_AGGREGATE](http://msdn.microsoft.com/library/c671fa40-a57b-4797-ae88-c9762dabd4dc) macro.  
  
-   Substituir `FinalRelease` para liberar o **IUnknown** ponteiro.  
  
##  <a name="a-namefinalreleasea--ccomobjectrootexfinalrelease"></a><a name="finalrelease"></a>CComObjectRootEx::FinalRelease  
 Você pode substituir esse método em sua classe derivada para executar qualquer limpeza exigida para o objeto.  
  
```
void FinalRelease();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `CComObjectRootEx::FinalRelease` não faz nada.  
  
 Executar limpeza na `FinalRelease` é preferível a adicionar código para o destruidor de sua classe, desde que o objeto for construído ainda totalmente no ponto em que `FinalRelease` é chamado. Isso permite acessar com segurança os métodos fornecidos pela classe mais derivada. Isso é particularmente importante para liberar todos os objetos agregados antes da exclusão.  
  
##  <a name="a-nameinternaladdrefa--ccomobjectrootexinternaladdref"></a><a name="internaladdref"></a>CComObjectRootEx::InternalAddRef  
 Incrementa a contagem de referência de um objeto agregado em 1.  
  
```
ULONG InternalAddRef();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para o diagnóstico e teste.  
  
### <a name="remarks"></a>Comentários  
 Se o modelo de thread é multithreaded, **InterlockedIncrement** é usado para impedir que mais de um thread altere a contagem de referência ao mesmo tempo.  
  
##  <a name="a-nameinternalqueryinterfacea--ccomobjectrootexinternalqueryinterface"></a><a name="internalqueryinterface"></a>CComObjectRootEx::InternalQueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
static HRESULT InternalQueryInterface(
    void* pThis,
    const _ATL_INTMAP_ENTRY* pEntries,
    REFIID iid,
    void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pThis`  
 [in] Um ponteiro para o objeto que contém o mapa COM interfaces expostas a `QueryInterface`.  
  
 `pEntries`  
 [in] Um ponteiro para o **_ATL_INTMAP_ENTRY** estrutura que acessa um mapa das interfaces disponíveis.  
  
 `iid`  
 [in] O GUID da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface especificado em `iid`, ou **nulo** se a interface não for encontrada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 `InternalQueryInterface` somente lida com interfaces na tabela de mapa COM. Se o objeto é agregado, `InternalQueryInterface` delegue para o externo desconhecido. Você pode inserir interfaces na tabela de mapa COM a macro [COM_INTERFACE_ENTRY](http://msdn.microsoft.com/library/19dcb768-2e1f-4b8d-a618-453a01a4bd00) ou uma de suas variantes.  
  
##  <a name="a-nameinternalreleasea--ccomobjectrootexinternalrelease"></a><a name="internalrelease"></a>CComObjectRootEx::InternalRelease  
 Diminui a contagem de referência de um objeto agregado por 1.  
  
```
ULONG InternalRelease();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em ambos não depuração e compilações de depuração, esta função retorna um valor que pode ser útil para o diagnóstico ou teste. O valor retornado depende de muitos fatores, como o sistema operacional usado e pode ou não, ser a contagem de referência.  
  
### <a name="remarks"></a>Comentários  
 Se o modelo de thread é multithreaded, **InterlockedDecrement** é usado para impedir que mais de um thread altere a contagem de referência ao mesmo tempo.  
  
##  <a name="a-namelocka--ccomobjectrootexlock"></a><a name="lock"></a>CComObjectRootEx::Lock  
 Se o modelo de thread é multithreaded, esse método chama a função de API do Win32 [EnterCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms682608), que aguarda até que o thread pode assumir a propriedade do objeto de seção crítica obtido por meio de um membro de dados particulares.  
  
```
void Lock();
```  
  
### <a name="remarks"></a>Comentários  
 Quando o código protegido conclui a execução, o thread deve chamar `Unlock` Libere a propriedade da seção crítica.  
  
 Se o modelo de thread é single-threaded, esse método não fará nada.  
  
##  <a name="a-namemdwrefa--ccomobjectrootexmdwref"></a><a name="m_dwref"></a>CComObjectRootEx::m_dwRef  
 Parte de uma união que acessa os quatro bytes de memória.  
  
```
long m_dwRef;
```  
  
### <a name="remarks"></a>Comentários  
 Com `m_pOuterUnknown`, parte de uma união:  
  
 `union`  
  
 `{`  
  
 `long m_dwRef;`  
  
 `IUnknown* m_pOuterUnknown;`  
  
 `};`  
  
 Se o objeto não é agregado, a contagem de referência é acessado por `AddRef` e **versão** é armazenado em `m_dwRef`. Se o objeto é agregado, o ponteiro para o externo desconhecido é armazenado em [m_pOuterUnknown](#m_pouterunknown).  
  
##  <a name="a-namempouterunknowna--ccomobjectrootexmpouterunknown"></a><a name="m_pouterunknown"></a>CComObjectRootEx::m_pOuterUnknown  
 Parte de uma união que acessa os quatro bytes de memória.  
  
```
IUnknown*
    m_pOuterUnknown;
```     
  
### <a name="remarks"></a>Comentários  
 Com `m_dwRef`, parte de uma união:  
  
 `union`  
  
 `{`  
  
 `long m_dwRef;`  
  
 `IUnknown* m_pOuterUnknown;`  
  
 `};`  
  
 Se o objeto é agregado, o ponteiro para o externo desconhecido é armazenado em `m_pOuterUnknown`. Se o objeto não é agregado, a contagem de referência é acessado por `AddRef` e **versão** é armazenado em [m_dwRef](#m_dwref).  
  
##  <a name="a-nameobjectmaina--ccomobjectrootexobjectmain"></a><a name="objectmain"></a>CComObjectRootEx::ObjectMain  
 Para cada classe listado no [mapa objetos](http://msdn.microsoft.com/en-us/b57619cc-534f-4b8f-bfd4-0c12f937202f), essa função é chamada uma vez quando o módulo é inicializado, e novamente quando ele é encerrado.  
  
```
static void WINAPI ObjectMain(bool bStarting);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bStarting`  
 [out] O valor é **true** se a classe está sendo iniciado; caso contrário **false**.  
  
### <a name="remarks"></a>Comentários  
 O valor de `bStarting` parâmetro indica se o módulo está sendo inicializado ou encerrado. A implementação padrão de `ObjectMain` não faz nada, mas você pode substituir essa função em sua classe para inicializar ou limpar os recursos que você deseja alocar para a classe. Observe que `ObjectMain` é chamado antes de todas as instâncias da classe são solicitadas.  
  
 `ObjectMain`é chamado de ponto de entrada da DLL, então o tipo de operação que pode executar a função de ponto de entrada é restrito. Para obter mais informações sobre essas restrições, consulte [comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md) e [DllMain](http://msdn.microsoft.com/library/windows/desktop/ms682583).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&41;](../../atl/codesnippet/cpp/ccomobjectrootex-class_2.h)]  
  
##  <a name="a-nameouteraddrefa--ccomobjectrootexouteraddref"></a><a name="outeraddref"></a>CComObjectRootEx::OuterAddRef  
 Incrementa a contagem de referência do desconhecido externa de uma agregação.  
  
```
ULONG OuterAddRef();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para o diagnóstico e teste.  
  
##  <a name="a-nameouterqueryinterfacea--ccomobjectrootexouterqueryinterface"></a><a name="outerqueryinterface"></a>CComObjectRootEx::OuterQueryInterface  
 Recupera um ponteiro indireto para a interface solicitada.  
  
```
HRESULT OuterQueryInterface(REFIID iid, void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 [in] O GUID da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface especificado em `iid`, ou **nulo** se a agregação não suporta a interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos padrão `HRESULT` valores.  
  
##  <a name="a-nameouterreleasea--ccomobjectrootexouterrelease"></a><a name="outerrelease"></a>CComObjectRootEx::OuterRelease  
 Diminui a contagem de referência do desconhecido externo de uma agregação.  
  
```
ULONG OuterRelease();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração não, sempre retorna 0. Em compilações de depuração, retorna um valor que pode ser útil para o diagnóstico ou teste.  
  
##  <a name="a-nameunlocka--ccomobjectrootexunlock"></a><a name="unlock"></a>CComObjectRootEx::Unlock  
 Se o modelo de thread é multithreaded, esse método chama a função de API do Win32 [LeaveCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms684169), qual propriedade de versões do objeto de seção crítica obtido por meio de um membro de dados particulares.  
  
```
void Unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter a propriedade, o thread deve chamar `Lock`. Cada chamada para `Lock` requer uma chamada correspondente para `Unlock` Libere a propriedade da seção crítica.  
  
 Se o modelo de thread é single-threaded, esse método não fará nada.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

