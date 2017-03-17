---
title: Classe IDispEventImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 22
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 235955f8573ae7e430be3de2a96efdd7496d15de
ms.lasthandoff: 02/25/2017

---
# <a name="idispeventimpl-class"></a>Classe IDispEventImpl
Essa classe fornece implementações do `IDispatch` métodos.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
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
 Um identificador exclusivo para o objeto de origem. Quando `IDispEventImpl` é a classe base para um controle composto, use a ID de recurso do controle independente desejado para esse parâmetro. Em outros casos, use um inteiro positivo arbitrário.  
  
 `T`  
 Classe do usuário, que é derivado de `IDispEventImpl`.  
  
 `pdiid`  
 O ponteiro para o IID da dispinterface de eventos implementada por esta classe. Essa interface deve ser definida na biblioteca do tipo indicada por `plibid`, `wMajor`, e `wMinor`.  
  
 `plibid`  
 Um ponteiro para a biblioteca de tipos que define a interface de expedição apontada por `pdiid`. Se **< / GUID_NULL**, a biblioteca de tipos do objeto de fonte de eventos será carregada.  
  
 `wMajor`  
 A versão principal da biblioteca de tipos. O valor padrão é 0.  
  
 `wMinor`  
 A versão secundária da biblioteca de tipos. O valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar as informações de tipo de `T`. O valor padrão é uma classe do tipo `CComTypeInfoHolder`; no entanto, você pode substituir esse parâmetro do modelo, fornecendo uma classe de um tipo diferente de `CComTypeInfoHolder`.  
  
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
|[IDispEventImpl::GetIDsOfNames](#getidsofnames)|Mapeia um único membro e um conjunto opcional de nomes de argumentos para um conjunto correspondente de DISPIDs inteiro.|  
|[IDispEventImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações de tipo para um objeto.|  
|[IDispEventImpl::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo.|  
|[IDispEventImpl::GetUserDefinedType](#getuserdefinedtype)|Recupera o tipo básico de um tipo definido pelo usuário.|  
  
## <a name="remarks"></a>Comentários  
 `IDispEventImpl`Fornece uma maneira de implementar um dispinterface de eventos sem exigir que você forneça o código de implementação para cada método/evento nessa interface. `IDispEventImpl`fornece implementações do `IDispatch` métodos. Você só precisará fornecer implementações para que você está interessado na manipulação de eventos.  
  
 `IDispEventImpl`funciona em conjunto com o [mapa coletor de evento](http://msdn.microsoft.com/library/32542b3d-ac43-4139-8ac4-41c48481744f) em sua classe para eventos de rota para a função de manipulador apropriado. Para usar essa classe:  
  

 Adicionar uma [SINK_ENTRY](http://msdn.microsoft.com/library/33a5fff6-5248-47c0-8cf4-8bdf760e86e5) ou [SINK_ENTRY_EX](http://msdn.microsoft.com/library/e1d14342-838f-4791-ac2f-5dae2801c1ac) macro para o mapa de coletor de evento para cada evento em cada objeto que você deseja manipular. Ao usar `IDispEventImpl` como uma classe base de um controle composto, você pode chamar [AtlAdviseSinkMap](http://msdn.microsoft.com/library/0757a6af-3de3-4179-8b4f-ccd137d919b4) para estabelecer e quebrar a conexão com fontes de eventos para todas as entradas de coletor de eventos de mapa. Em outros casos, ou para obter maior controle, chame [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base. Chamar [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise) para quebrar a conexão.  

  
 Você deve derivar de `IDispEventImpl` (usando um valor exclusivo para `nID`) para cada objeto para o qual você precisa manipular eventos. Você pode reutilizar a classe base por unadvising no objeto de uma fonte, em seguida, avisando em relação a um objeto de fonte diferente, mas o número máximo de objetos de fonte que pode ser tratado por um único objeto de uma só vez é limitado pelo número de `IDispEventImpl` classes base.  
  
 `IDispEventImpl`fornece a mesma funcionalidade que [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md), exceto que ele obtém informações sobre a interface de tipo de uma biblioteca de tipos em vez de ter que ela fornecida como um ponteiro para um [_ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md) estrutura. Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipos que descreve a interface de eventos ou para evitar a sobrecarga associada usando a biblioteca de tipos.  
  
> [!NOTE]
> `IDispEventImpl`e `IDispEventSimpleImpl` fornecer sua própria implementação de **IUnknown:: QueryInterface** habilitando cada `IDispEventImpl` e `IDispEventSimpleImpl` classe para agir como uma identidade separada do COM e ainda permitir acesso direto a membros de classe no objeto principal COM base.  
  
 Implementação de CE ATL do ActiveX evento coletores somente oferece suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
 Para obter mais informações, consulte [IDispEventImpl suporte](../../atl/supporting-idispeventimpl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_IDispEvent`  
  
 `_IDispEventLocator`  
  
 [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)  
  
 `IDispEventImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getfuncinfofromid"></a>IDispEventImpl::GetFuncInfoFromId  
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
  
##  <a name="getidsofnames"></a>IDispEventImpl::GetIDsOfNames  
 Mapeia um único membro e um conjunto opcional de nomes de argumentos para um conjunto correspondente de inteiro DISPIDs, que pode ser usado em chamadas subsequentes para [IDispatch:: Invoke](http://msdn.microsoft.com/en-us/964ade8e-9d8a-4d32-bd47-aa678912a54d).  
  
```
STDMETHOD(GetIDsOfNames)(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgdispid);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDispatch::GetIDsOfNames](http://msdn.microsoft.com/en-us/6f6cf233-3481-436e-8d6a-51f93bf91619) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="gettypeinfo"></a>IDispEventImpl::GetTypeInfo  
 Recupera as informações do tipo de um objeto, que podem ser usadas para obter informações de tipo para uma interface.  
  
```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettypeinfocount"></a>IDispEventImpl::GetTypeInfoCount  
 Retorna o número de interfaces de informações do tipo que um objeto fornece (0 ou 1).  
  
```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDispatch::GetTypeInfoCount](http://msdn.microsoft.com/en-us/da876d53-cb8a-465c-a43e-c0eb272e2a12) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getuserdefinedtype"></a>IDispEventImpl::GetUserDefinedType  
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
  
##  <a name="idispeventimpl"></a>IDispEventImpl::IDispEventImpl  
 O construtor. Armazena os valores dos parâmetros de modelo de classe `plibid`, `pdiid`, `wMajor`, e `wMinor`.  
  
```
IDispEventImpl();
```  
  
##  <a name="tihclass"></a>IDispEventImpl::tihclass  
 Este typedef é uma instância de parâmetro do modelo de classe `tihclass`.  
  
```
typedef tihclass _tihclass;
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a classe é `CComTypeInfoHolder`. `CComTypeInfoHolder`gerencia as informações de tipo para a classe.  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)   
 [Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)   
 [Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)   
 [SINK_ENTRY](http://msdn.microsoft.com/library/33a5fff6-5248-47c0-8cf4-8bdf760e86e5)   
 [SINK_ENTRY_EX](http://msdn.microsoft.com/library/e1d14342-838f-4791-ac2f-5dae2801c1ac)   
 [SINK_ENTRY_INFO](http://msdn.microsoft.com/library/1a0ae260-2c82-4926-a537-db01e5f206a7)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
