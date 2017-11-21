---
title: "Macros de mapa de serviço | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlcom/ATL::BEGIN_SERVICE_MAP
- atlcom/ATL::END_SERVICE_MAP
- atlcom/ATL::SERVICE_ENTRY
- atlcom/ATL::SERVICE_ENTRY_CHAIN
dev_langs: C++
ms.assetid: ca02a125-454a-4cf6-aac2-1c5585025ed4
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: fb8ee6db5f75a71e11a0b3dbdbca1bc6c077c3a9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="service-map-macros"></a>Macros de mapa de serviço
Essas macros definem entradas e mapas de serviço.  
  
|||  
|-|-|  
|[BEGIN_SERVICE_MAP](#begin_service_map)|Marca o início de um mapa de serviço ATL.|  
|[END_SERVICE_MAP](#end_service_map)|Marca o fim de um mapa de serviço ATL.|  
|[SERVICE_ENTRY](#service_entry)|Indica que o objeto oferece suporte a uma ID de serviço específico.|  
|[SERVICE_ENTRY_CHAIN](#service_entry_chain)|Instrui o [IServiceProviderImpl::QueryService](#queryservice) cadeia ao objeto especificado.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
   
##  <a name="begin_service_map"></a>BEGIN_SERVICE_MAP  
 Marca o início do mapa de serviço.  
  
```
BEGIN_SERVICE_MAP(theClass)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 [in] Especifica a classe que contém o mapa de serviço.  
  
### <a name="remarks"></a>Comentários  
 Use o mapa de serviço para implementar a funcionalidade de provedor de serviço em seu objeto COM. Primeiro, você deve derivar a classe de [IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md). Há dois tipos de entradas:  
  
- [SERVICE_ENTRY](#service_entry) indica suporte para SIDs de serviço especificado.  
  
- [SERVICE_ENTRY_CHAIN](#service_entry_chain) instrui [IServiceProviderImpl::QueryService](#queryservice) para vincular a outro objeto especificado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#57](../../atl/codesnippet/cpp/service-map-macros_1.h)]  
  
##  <a name="end_service_map"></a>END_SERVICE_MAP  
 Marca o fim do mapa de serviço.  
  
```
END_SERVICE_MAP()
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [BEGIN_SERVICE_MAP](#begin_service_map).  
  
##  <a name="service_entry"></a>SERVICE_ENTRY  
 Indica que o objeto oferece suporte a id de serviço especificada pelo *SID*.  
  
```
SERVICE_ENTRY( SID )
```  
  
### <a name="parameters"></a>Parâmetros  
 *SID*  
 A ID de serviço.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [BEGIN_SERVICE_MAP](#begin_service_map).  
  
##  <a name="service_entry_chain"></a>SERVICE_ENTRY_CHAIN  
 Instrui o [IServiceProviderImpl::QueryService](#queryservice) a cadeia para o objeto especificado pelo `punk`.  
  
```
SERVICE_ENTRY_CHAIN( punk )
```  
  
### <a name="parameters"></a>Parâmetros  
 `punk`  
 Um ponteiro para o **IUnknown** interface para o qual a cadeia.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [BEGIN_SERVICE_MAP](#begin_service_map).  
  
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
 [Macros](../../atl/reference/atl-macros.md)
