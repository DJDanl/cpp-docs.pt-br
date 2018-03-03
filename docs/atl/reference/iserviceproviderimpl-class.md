---
title: Classe IServiceProviderImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IServiceProviderImpl
- ATLCOM/ATL::IServiceProviderImpl
- ATLCOM/ATL::IServiceProviderImpl::QueryService
dev_langs:
- C++
helpviewer_keywords:
- IServiceProviderImpl class
- IServiceProvider interface, ATL implementation
ms.assetid: 251254d3-c4ce-40d7-aee0-3d676d1d72f2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4946a88e6bf6767de0e3965670f94b91d1ddaf90
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iserviceproviderimpl-class"></a>Classe IServiceProviderImpl
Essa classe fornece uma implementação padrão da `IServiceProvider` interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE IServiceProviderImpl : public IServiceProvider
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IServiceProviderImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IServiceProviderImpl::QueryService](#queryservice)|Cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.|  
  
## <a name="remarks"></a>Comentários  
 O `IServiceProvider` interface localiza um serviço especificado pelo seu GUID e retorna o ponteiro de interface para a interface solicitada no serviço. Classe `IServiceProviderImpl` fornece uma implementação padrão desta interface.  
  
 **IServiceProviderImpl** Especifica um método: [QueryService](#queryservice), que cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.  
  
 `IServiceProviderImpl`usa um mapa de serviço, começando com [BEGIN_SERVICE_MAP](service-map-macros.md#begin_service_map) e terminando com [END_SERVICE_MAP](service-map-macros.md#end_service_map).  
  
 O mapa de serviço contém duas entradas: [SERVICE_ENTRY](service-map-macros.md#service_entry), que indica uma id de serviço especificado (SID) com suporte pelo objeto, e [SERVICE_ENTRY_CHAIN](service-map-macros.md#service_entry_chain), que chama `QueryService` cadeia para outro objeto.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IServiceProvider`  
  
 `IServiceProviderImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="queryservice"></a>IServiceProviderImpl::QueryService  
 Cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.  
  
```
STDMETHOD(QueryService)(
    REFGUID guidService,
    REFIID riid,
    void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 [IN]`guidService`  
 Ponteiro para um identificador de serviço (SID).  
  
 [IN]`riid`  
 Identificador da interface para o qual o chamador é obter acesso.  
  
 [OUT]`ppvObj`  
 Ponteiro indireto para a interface solicitada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornado `HRESULT` valor é um dos seguintes:  
  
|Valor retornado|Significado|  
|------------------|-------------|  
|S_OK|O serviço foi criou ou recuperado com êxito.|  
|E_INVALIDARG|Um ou mais argumentos são inválidos.|  
|E_OUTOFMEMORY|Memória é insuficiente para criar o serviço.|  
|E_UNEXPECTED|Erro desconhecido.|  
|E_NOINTERFACE|A interface solicitada não é parte do serviço ou o serviço é desconhecido.|  
  
### <a name="remarks"></a>Comentários  
 `QueryService`Retorna um ponteiro indireto para a interface solicitada no serviço especificado. O chamador é responsável pela liberação ponteiro this quando ele não é mais necessário.  
  
 Quando você chama `QueryService`, passar o identificador de serviços ( `guidService`) e um identificador de interface ( `riid`). O `guidService` Especifica o serviço ao qual você deseja acesso, e o `riid` identifica uma interface que faz parte do serviço. Em troca, você receberá um ponteiro indireto à interface.  
  
 O objeto que implementa a interface também pode implementar interfaces que são parte de outros serviços. Considere o seguinte:  
  
-   Algumas dessas interfaces podem ser opcionais. Nem todas as interfaces definidas na descrição do serviço estão necessariamente presentes em cada implementação do serviço ou em cada objeto retornado.  
  
-   Diferentemente de chamadas para `QueryInterface`, passar um identificador de serviço diferentes não significa necessariamente que um objeto diferente de modelo de objeto de componente (COM) será retornado.  
  
-   O objeto retornado pode ter interfaces adicionais que não fazem parte da definição do serviço.  
  
 Dois serviços diferentes, como SID_SMyService e SID_SYourService, podem ambos especificar o uso da interface do mesmo, embora a implementação da interface talvez não tenham nada em comum entre os dois serviços. Isso funciona, porque uma chamada para `QueryService` (SID_SMyService, IID_IDispatch) pode retornar um objeto diferente de `QueryService` (SID_SYourService, IID_IDispatch). Identidade do objeto não será considerada quando você especifica um identificador de serviço diferente.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
