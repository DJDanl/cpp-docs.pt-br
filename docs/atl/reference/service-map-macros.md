---
title: "Macros de mapa de serviço | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: ca02a125-454a-4cf6-aac2-1c5585025ed4
caps.latest.revision: 16
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: eea45a3315237c77eff0231d485111cefb8557cc
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="service-map-macros"></a>Macros de mapa de serviço
Essas macros definem entradas e mapas de serviço.  
  
|||  
|-|-|  
|[BEGIN_SERVICE_MAP](#begin_service_map)|Marca o início de um mapa de serviço ATL.|  
|[END_SERVICE_MAP](#end_service_map)|Marca o fim de um mapa de serviço ATL.|  
|[SERVICE_ENTRY](#service_entry)|Indica que o objeto oferece suporte a uma ID de serviço específico.|  
|[SERVICE_ENTRY_CHAIN](#service_entry_chain)|Instrui o [IServiceProviderImpl::QueryService](#queryservice) cadeia para o objeto especificado.|  

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
 Use o mapa de serviço para implementar a funcionalidade do provedor de serviço em seu objeto COM. Primeiro, você deve derivar a classe de [IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md). Há dois tipos de entradas:  
  
- [SERVICE_ENTRY](#service_entry) indica suporte SIDs de serviço especificado.  
  
- [SERVICE_ENTRY_CHAIN](#service_entry_chain) instrui [IServiceProviderImpl::QueryService](#queryservice) para vincular a outro objeto especificado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&#57;](../../atl/codesnippet/cpp/service-map-macros_1.h)]  
  
##  <a name="end_service_map"></a>END_SERVICE_MAP  
 Marca o fim do mapa de serviço.  
  
```
END_SERVICE_MAP()
```  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_SERVICE_MAP](#begin_service_map).  
  
##  <a name="service_entry"></a>SERVICE_ENTRY  
 Indica que o objeto oferece suporte a id de serviço especificada por *SID*.  
  
```
SERVICE_ENTRY( SID )
```  
  
### <a name="parameters"></a>Parâmetros  
 *SID*  
 Identificação do serviço.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_SERVICE_MAP](#begin_service_map).  
  
##  <a name="service_entry_chain"></a>SERVICE_ENTRY_CHAIN  
 Instrui o [IServiceProviderImpl::QueryService](#queryservice) cadeia para o objeto especificado pelo `punk`.  
  
```
SERVICE_ENTRY_CHAIN( punk )
```  
  
### <a name="parameters"></a>Parâmetros  
 `punk`  
 Um ponteiro para o **IUnknown** interface à qual a cadeia.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_SERVICE_MAP](#begin_service_map).  
  
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
 Identificador de interface para que o chamador obter acesso.  
  
 [OUT]`ppvObj`  
 Ponteiro indireto para a interface solicitada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornado `HRESULT` valor é um dos seguintes:  
  
|Valor retornado|Significado|  
|------------------|-------------|  
|S_OK|O serviço foi criado com êxito ou recuperado.|  
|E_INVALIDARG|Um ou mais argumentos são inválidos.|  
|E_OUTOFMEMORY|Memória é insuficiente para criar o serviço.|  
|E_UNEXPECTED|Erro desconhecido.|  
|E_NOINTERFACE|A interface solicitada não é parte do serviço ou o serviço é desconhecido.|  
  
### <a name="remarks"></a>Comentários  
 `QueryService`Retorna um ponteiro indireto para a interface solicitada no serviço especificado. O chamador é responsável por liberar esse ponteiro quando ele não é mais necessário.  
  
 Quando você chama `QueryService`, passar o identificador de serviços ( `guidService`) e um identificador de interface ( `riid`). O `guidService` Especifica o serviço ao qual você deseja acesso, e o `riid` identifica uma interface que é parte do serviço. Em troca, você recebe um ponteiro indireto à interface.  
  
 O objeto que implementa a interface também pode implementar interfaces que fazem parte de outros serviços. Considere o seguinte:  
  
-   Algumas dessas interfaces podem ser opcionais. Nem todas as interfaces definidas na descrição do serviço estão necessariamente presentes em todas as implementações do serviço ou em cada objeto retornado.  
  
-   Diferentemente de chamadas para `QueryInterface`, passar um identificador de serviço diferentes não significa necessariamente que um objeto diferente do modelo de objeto de componente (COM) é retornado.  
  
-   O objeto retornado pode ter interfaces adicionais que não fazem parte da definição do serviço.  
  
 Dois serviços diferentes, como SID_SMyService e SID_SYourService, podem especificam o uso da mesma interface, mesmo que a implementação da interface pode ter nada em comum entre os dois serviços. Isso funciona, porque uma chamada para `QueryService` (SID_SMyService, IID_IDispatch) pode retornar um objeto diferente de `QueryService` (SID_SYourService, IID_IDispatch). Identidade do objeto não é considerada quando você especifica um identificador de serviço diferentes.  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

