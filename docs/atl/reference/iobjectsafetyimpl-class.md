---
title: Classe IObjectSafetyImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IObjectSafetyImpl
- ATLCTL/ATL::IObjectSafetyImpl
- ATLCTL/ATL::IObjectSafetyImpl::GetInterfaceSafetyOptions
- ATLCTL/ATL::IObjectSafetyImpl::SetInterfaceSafetyOptions
- ATLCTL/ATL::IObjectSafetyImpl::m_dwCurrentSafety
dev_langs:
- C++
helpviewer_keywords:
- controls [ATL], safe
- safe for scripting and initialization (controls)
- IObjectSafety, ATL implementation
- IObjectSafetyImpl class
ms.assetid: 64e32082-d910-4a8a-a5bf-ebed9145359d
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: cdcc008797e94988fb42fd6239603fa300a84233
ms.lasthandoff: 03/31/2017

---
# <a name="iobjectsafetyimpl-class"></a>Classe IObjectSafetyImpl
Essa classe fornece uma implementação padrão da `IObjectSafety` interface para permitir que um cliente recuperar e definir níveis de segurança de um objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T,DWORD dwSupportedSafety>  
class IObjectSafetyImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IObjectSafetyImpl`.  
  
 *dwSupportedSafety*  
 Especifica as opções de segurança com suporte para o controle. Pode ser um dos seguintes valores:  
  
- **INTERFACESAFE_FOR_UNTRUSTED_CALLER** a interface identificada pelo [SetInterfaceSafetyOptions](#setinterfacesafetyoptions) parâmetro `riid` devem ser feitas seguros para script.  
  
- **INTERFACESAFE_FOR_UNTRUSTED_DATA** a interface identificada pelo `SetInterfaceSafetyOptions` parâmetro `riid` devem ser feitas com segurança dados não confiáveis durante a inicialização.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectSafetyImpl::GetInterfaceSafetyOptions](#getinterfacesafetyoptions)|Recupera as opções de segurança com suporte pelo objeto, bem como as opções de segurança definidas no momento para o objeto.|  
|[IObjectSafetyImpl::SetInterfaceSafetyOptions](#setinterfacesafetyoptions)|Faz com que o objeto seguros para inicialização ou script.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectSafetyImpl::m_dwCurrentSafety](#m_dwcurrentsafety)|Armazena o nível de segurança atual do objeto.|  
  
## <a name="remarks"></a>Comentários  
 Classe `IObjectSafetyImpl` fornece uma implementação padrão de `IObjectSafety`. O `IObjectSafety` interface permite que um cliente recuperar e definir níveis de segurança de um objeto. Por exemplo, um navegador da web pode chamar **IObjectSafety::SetInterfaceSafetyOptions** para tornar um controle para inicialização ou seguros para script.  
  
 Observe que o uso de [IMPLEMENTED_CATEGORY](category-macros.md#implemented_category) macro com a **CATID_SafeForScripting** e **CATID_SafeForInitializing** categorias de componentes fornece uma maneira alternativa de especificar que um componente é seguro.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IObjectSafety`  
  
 `IObjectSafetyImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="getinterfacesafetyoptions"></a>IObjectSafetyImpl::GetInterfaceSafetyOptions  
 Recupera as opções de segurança com suporte pelo objeto, bem como as opções de segurança definidas no momento para o objeto.  
  
```
HRESULT GetInterfaceSafetyOptions(  
    REFIID riid,
    DWORD* pdwSupportedOptions,
    DWORD* pdwEnabledOptions);
```  
  
### <a name="remarks"></a>Comentários  
 A implementação retorna os valores apropriados para qualquer interface compatível com a implementação do objeto de **IUnknown:: QueryInterface**.  
  
> [!IMPORTANT]
>  Qualquer objeto que dá suporte a `IObjectSafety` é responsável por sua própria segurança e de qualquer objeto que ela delega. O programador deve levar em problemas de conta decorrentes da execução de código no contexto do usuário, scripts entre sites e executar a verificação de zona adequada.  
  
 Consulte [IObjectSafety::GetInterfaceSafetyOptions](https://msdn.microsoft.com/library/aa768223.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_dwcurrentsafety"></a>IObjectSafetyImpl::m_dwCurrentSafety  
 Armazena o nível de segurança atual do objeto.  
  
```
DWORD m_dwCurrentSafety;
```  
  
##  <a name="setinterfacesafetyoptions"></a>IObjectSafetyImpl::SetInterfaceSafetyOptions  
 Faz com que o objeto seguros para inicialização ou script definindo a [m_dwCurrentSafety](#m_dwcurrentsafety) membro para o valor apropriado.  
  
```
HRESULT SetInterfaceSafetyOptions(  
    REFIID riid,
    DWORD dwOptionsSetMask,
    DWORD dwEnabledOptions);
```  
  
### <a name="remarks"></a>Comentários  
 Retorna a implementação **E_NOINTERFACE** para qualquer interface não compatível com a implementação do objeto de **IUnknown:: QueryInterface**.  
  
> [!IMPORTANT]
>  Qualquer objeto que dá suporte a `IObjectSafety` é responsável por sua própria segurança e de qualquer objeto que ela delega. O programador deve levar em problemas de conta decorrentes da execução de código no contexto do usuário, scripts entre sites e executar a verificação de zona adequada.  
  
 Consulte [IObjectSafety::SetInterfaceSafetyOptions](https://msdn.microsoft.com/library/aa768225.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Interface IObjectSafety](https://msdn.microsoft.com/library/aa768224.aspx)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

