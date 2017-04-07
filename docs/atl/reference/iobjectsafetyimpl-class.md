---
title: Classe IObjectSafetyImpl | Documentos do Microsoft
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: cff5995555cd069855f9d7becb9eb8367e80c920
ms.lasthandoff: 02/25/2017

---
# <a name="iobjectsafetyimpl-class"></a>Classe IObjectSafetyImpl
Essa classe fornece uma implementação padrão da `IObjectSafety` interface para permitir que um cliente recuperar e definir níveis de segurança de um objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T,DWORD dwSupportedSafety>  
class IObjectSafetyImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IObjectSafetyImpl`.  
  
 *dwSupportedSafety*  
 Especifica as opções de segurança com suporte para o controle. Pode ser um dos seguintes valores:  
  
- **INTERFACESAFE_FOR_UNTRUSTED_CALLER** a interface identificada pelo [SetInterfaceSafetyOptions](#setinterfacesafetyoptions) parâmetro `riid` deve ser feita seguros para script.  
  
- **INTERFACESAFE_FOR_UNTRUSTED_DATA** a interface identificada pelo `SetInterfaceSafetyOptions` parâmetro `riid` deve ser feita para dados não confiáveis durante a inicialização.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectSafetyImpl::GetInterfaceSafetyOptions](#getinterfacesafetyoptions)|Recupera as opções de segurança com suporte do objeto, bem como as opções de segurança definidas no momento para o objeto.|  
|[IObjectSafetyImpl::SetInterfaceSafetyOptions](#setinterfacesafetyoptions)|Torna o objeto seguro para inicialização ou script.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectSafetyImpl::m_dwCurrentSafety](#m_dwcurrentsafety)|Armazena o nível de segurança atual do objeto.|  
  
## <a name="remarks"></a>Comentários  
 Classe `IObjectSafetyImpl` fornece uma implementação padrão de `IObjectSafety`. O `IObjectSafety` interface permite que um cliente recuperar e definir níveis de segurança de um objeto. Por exemplo, um navegador da web pode chamar **IObjectSafety::SetInterfaceSafetyOptions** para fazer um controle seguro para scripts ou seguro para inicialização.  
  
 Observe que o uso de [IMPLEMENTED_CATEGORY](http://msdn.microsoft.com/library/d898ef34-5684-4709-beb9-7114ddd96674) macro com a **CATID_SafeForScripting** e **CATID_SafeForInitializing** categorias de componente fornece uma maneira alternativa de especificar que um componente é seguro.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IObjectSafety`  
  
 `IObjectSafetyImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="getinterfacesafetyoptions"></a>IObjectSafetyImpl::GetInterfaceSafetyOptions  
 Recupera as opções de segurança com suporte do objeto, bem como as opções de segurança definidas no momento para o objeto.  
  
```
HRESULT GetInterfaceSafetyOptions(  
    REFIID riid,
    DWORD* pdwSupportedOptions,
    DWORD* pdwEnabledOptions);
```  
  
### <a name="remarks"></a>Comentários  
 A implementação retorna os valores apropriados para qualquer interface suportada pela implementação do objeto de **IUnknown:: QueryInterface**.  
  
> [!IMPORTANT]
>  Qualquer objeto que oferece suporte a `IObjectSafety` é responsável por sua própria segurança e de qualquer objeto delega. O programador deve levar em problemas de conta decorrentes de executar código no contexto do usuário, scripts entre sites e executar a verificação de zona adequada.  
  
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
 Retorna a implementação **E_NOINTERFACE** para qualquer interface que não são suportado pela implementação do objeto de **IUnknown:: QueryInterface**.  
  
> [!IMPORTANT]
>  Qualquer objeto que oferece suporte a `IObjectSafety` é responsável por sua própria segurança e de qualquer objeto delega. O programador deve levar em problemas de conta decorrentes de executar código no contexto do usuário, scripts entre sites e executar a verificação de zona adequada.  
  
 Consulte [IObjectSafety::SetInterfaceSafetyOptions](https://msdn.microsoft.com/library/aa768225.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Interface IObjectSafety](https://msdn.microsoft.com/library/aa768224.aspx)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

