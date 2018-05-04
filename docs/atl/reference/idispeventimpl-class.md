---
title: Classe IDispEventImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IDispEventImpl
- ATLCOM/ATL::IDispEventImpl
- ATLCOM/ATL::IDispEventImpl::IDispEventImpl
- ATLCOM/ATL::IDispEventImpl::GetFuncInfoFromId
- ATLCOM/ATL::IDispEventImpl::GetIDsOfNames
- ATLCOM/ATL::IDispEventImpl::GetTypeInfo
- ATLCOM/ATL::IDispEventImpl::GetTypeInfoCount
- ATLCOM/ATL::IDispEventImpl::GetUserDefinedType
dev_langs:
- C++
helpviewer_keywords:
- IDispEventImpl class
ms.assetid: a64b5288-35cb-4638-aad6-2d15b1c7cf7b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7809a61fe39a4b4b913531de29e03c3eb440c418
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="idispeventimpl-class"></a>Classe IDispEventImpl
Essa classe fornece implementações do `IDispatch` métodos.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <UINT nID, class T,
    const IID* pdiid = &IID_NULL,
    const GUID* plibid = &GUID_NULL,
    WORD wMajor = 0,
    WORD wMinor = 0, 
    class tihclass = CcomTypeInfoHolder>  
class ATL_NO_VTABLE IDispEventImpl : public IDispEventSimpleImpl<nID, T, pdiid>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nID`  
 Um identificador exclusivo para o objeto de origem. Quando `IDispEventImpl` é a classe base para um controle composto, use a ID de recurso do controle independente desejado para este parâmetro. Em outros casos, use um inteiro positivo arbitrário.  
  
 `T`  
 Classe do usuário, que é derivado de `IDispEventImpl`.  
  
 `pdiid`  
 O ponteiro para o IID da dispinterface de eventos que implementada por esta classe. Esta interface deve ser definida na biblioteca de tipos indicada por `plibid`, `wMajor`, e `wMinor`.  
  
 `plibid`  
 Um ponteiro para a biblioteca de tipos que define a interface de Despache apontada pelo `pdiid`. Se **& GUID_NULL**, a biblioteca de tipos do objeto de origem de eventos será carregada.  
  
 `wMajor`  
 A versão principal da biblioteca de tipos. O valor padrão é 0.  
  
 `wMinor`  
 A versão secundária da biblioteca de tipos. O valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar as informações de tipo de `T`. O valor padrão é uma classe de tipo `CComTypeInfoHolder`; no entanto, você pode substituir esse parâmetro do modelo fornecendo uma classe de um tipo diferente de `CComTypeInfoHolder`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDispEventImpl::_tihclass](../../atl/reference/idispeventimpl-class.md)|A classe usada para gerenciar as informações de tipo. Por padrão, `CComTypeInfoHolder`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDispEventImpl::IDispEventImpl](#idispeventimpl)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDispEventImpl::GetFuncInfoFromId](#getfuncinfofromid)|Localiza o índice de função para o identificador de distribuição especificado.|  
|[IDispEventImpl::GetIDsOfNames](#getidsofnames)|Mapeia um único membro e um conjunto opcional de nomes de argumento para um conjunto correspondente de inteiro DISPIDs.|  
|[IDispEventImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações de tipo para um objeto.|  
|[IDispEventImpl::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo.|  
|[IDispEventImpl::GetUserDefinedType](#getuserdefinedtype)|Recupera o tipo básico de um tipo definido pelo usuário.|  
  
## <a name="remarks"></a>Comentários  
 `IDispEventImpl` Fornece uma maneira de implementar um dispinterface de eventos sem a necessidade de fornecer código de implementação para cada método/evento na interface. `IDispEventImpl` fornece implementações do `IDispatch` métodos. Você só precisa fornecer implementações para os eventos que você está interessado na manipulação.  
  
 `IDispEventImpl` funciona em conjunto com o mapa de coletor de eventos em sua classe para eventos de rota para a função de manipulador adequado. Para usar essa classe:  
  

 Adicionar um [SINK_ENTRY](composite-control-macros.md#sink_entry) ou [SINK_ENTRY_EX](composite-control-macros.md#sink_entry_ex) macro para o mapa de coletor de evento para cada evento em cada objeto que você deseja manipular. Ao usar `IDispEventImpl` como uma classe base de um controle composto, você pode chamar [AtlAdviseSinkMap](connection-point-global-functions.md#atladvisesinkmap) para estabelecer e interromper a conexão com as fontes de evento para todas as entradas do coletor de eventos de mapa. Em outros casos, ou para um controle maior, chame [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base. Chamar [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise) para interromper a conexão.  

  
 Você deve derivar de `IDispEventImpl` (usando um valor exclusivo para `nID`) para cada objeto para o qual você precisa tratar eventos. Você pode reutilizar a classe base por unadvising no objeto de uma fonte prestar consultoria para um objeto de fonte diferente, mas o número máximo de objetos de fonte que pode ser tratado por um único objeto de uma só vez é limitado pelo número de `IDispEventImpl` classes base.  
  
 `IDispEventImpl` fornece a mesma funcionalidade que [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md), exceto que ele obtém informações sobre a interface do tipo de uma biblioteca de tipos em vez de ter que ele fornecida como um ponteiro para um [_ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md) estrutura. Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipos que descreve a interface de eventos ou para evitar a sobrecarga associada usando a biblioteca de tipos.  
  
> [!NOTE]
> `IDispEventImpl` e `IDispEventSimpleImpl` fornecer sua própria implementação de **IUnknown:: QueryInterface** habilitar cada `IDispEventImpl` e `IDispEventSimpleImpl` classe para agir como uma identidade COM separada e ainda permitir acesso direto aos membros da classe de base o principal objeto COM.  
  
 Implementação de CE ATL de ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de métodos de manipuladores de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
 Para obter mais informações, consulte [IDispEventImpl suporte](../../atl/supporting-idispeventimpl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_IDispEvent`  
  
 `_IDispEventLocator`  
  
 [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)  
  
 `IDispEventImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getfuncinfofromid"></a>  IDispEventImpl::GetFuncInfoFromId  
 Localiza o índice de função para o identificador de distribuição especificado.  
  
```
HRESULT GetFuncInfoFromId(
    const IID& iid,
    DISPID dispidMember,
    LCID lcid,
    _ATL_FUNC_INFO& info);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 [in] Uma referência para a ID da função.  
  
 *dispidMember*  
 [in] A ID de expedição da função.  
  
 `lcid`  
 [in] O contexto de localidade da ID da função.  
  
 `info`  
 [in] A estrutura que indica como a função é chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="getidsofnames"></a>  IDispEventImpl::GetIDsOfNames  
 Um único membro e um conjunto opcional de nomes de argumento é mapeado para um conjunto correspondente de inteiro DISPIDs, que pode ser usado em chamadas subsequentes para [IDispatch:: Invoke](http://msdn.microsoft.com/en-us/964ade8e-9d8a-4d32-bd47-aa678912a54d).  
  
```
STDMETHOD(GetIDsOfNames)(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgdispid);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDispatch:: GetIDsOfNames](http://msdn.microsoft.com/en-us/6f6cf233-3481-436e-8d6a-51f93bf91619) no SDK do Windows.  
  
##  <a name="gettypeinfo"></a>  IDispEventImpl::GetTypeInfo  
 Recupera as informações do tipo de um objeto, que podem ser usadas para obter informações de tipo para uma interface.  
  
```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettypeinfocount"></a>  IDispEventImpl::GetTypeInfoCount  
 Retorna o número de interfaces de informações do tipo que um objeto fornece (0 ou 1).  
  
```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDispatch::GetTypeInfoCount](http://msdn.microsoft.com/en-us/da876d53-cb8a-465c-a43e-c0eb272e2a12) no SDK do Windows.  
  
##  <a name="getuserdefinedtype"></a>  IDispEventImpl::GetUserDefinedType  
 Recupera o tipo básico de um tipo definido pelo usuário.  
  
```
VARTYPE GetUserDefinedType(
    ITypeInfo* pTI,
    HREFTYPE hrt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTI`  
 [in] Um ponteiro para o [ITypeInfo](http://msdn.microsoft.com/en-us/f3356463-3373-4279-bae1-953378aa2680) interface que contém o tipo definido pelo usuário.  
  
 *hrt*  
 [in] Um identificador para a descrição do tipo a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de variante.  
  
### <a name="remarks"></a>Comentários  
 Consulte [ITypeInfo:: GetRefTypeInfo](http://msdn.microsoft.com/en-us/61d3b31d-6591-4e55-9e82-5246a168be00).  
  
##  <a name="idispeventimpl"></a>  IDispEventImpl::IDispEventImpl  
 O construtor. Armazena os valores dos parâmetros de modelo de classe `plibid`, `pdiid`, `wMajor`, e `wMinor`.  
  
```
IDispEventImpl();
```  
  
##  <a name="tihclass"></a>  IDispEventImpl::tihclass  
 Este typedef é uma instância de parâmetro do modelo de classe `tihclass`.  
  
```
typedef tihclass _tihclass;
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a classe é `CComTypeInfoHolder`. `CComTypeInfoHolder` gerencia as informações de tipo para a classe.  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)   
 [Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)   
 [Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)   
 [SINK_ENTRY](composite-control-macros.md#sink_entry)   
 [SINK_ENTRY_EX](composite-control-macros.md#sink_entry_ex)   
 [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)   
 [Visão geral da classe](../../atl/atl-class-overview.md)