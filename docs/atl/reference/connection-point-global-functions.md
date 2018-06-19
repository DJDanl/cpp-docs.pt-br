---
title: Funções globais do ponto de Conexão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlAdvise
- atlbase/ATL::AtlUnadvise
- atlbase/ATL::AtlAdviseSinkMap
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], global functions
ms.assetid: bcb4bf50-2155-4e20-b8bb-f2908b03a6e7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7dc6cd11cb1f04ba877524cd1ae6134a7dd93d09
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32362785"
---
# <a name="connection-point-global-functions"></a>Funções globais do ponto de Conexão
Essas funções fornecem suporte para pontos de conexão e do coletor de mapas.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AtlAdvise](#atladvise)|Cria uma conexão entre o ponto de conexão de um objeto e o coletor de um cliente.|  
|[AtlUnadvise](#atlunadvise)|Encerra a conexão estabelecida por meio de `AtlAdvise`.|  
|[AtlAdviseSinkMap](#atladvisesinkmap)|Aconselha ou unadvises entradas em um mapa de coletor de eventos.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
   
##  <a name="atladvise"></a>  AtlAdvise  
 Cria uma conexão entre o ponto de conexão de um objeto e o coletor de um cliente.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados o tempo de execução do Windows.  
  
```
HRESULT    AtlAdvise(
    IUnknown* pUnkCP,
    IUnknown* pUnk,
    const IID& iid,
    LPDWORD pdw);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkCP`  
 [in] Um ponteiro para o **IUnknown** do objeto cliente deseja se conectar com.  
  
 *pUnk*  
 [in] Um ponteiro para o cliente **IUnknown**.  
  
 `iid`  
 [in] O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface gerenciada pelo ponto de conexão de saída.  
  
 `pdw`  
 [out] Um ponteiro para o cookie que identifica exclusivamente a conexão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 O coletor implementa a interface de saída com suporte pelo ponto de conexão. O cliente usa o `pdw` cookie para remover a conexão, passando-o para [AtlUnadvise](#atlunadvise).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#91](../../atl/codesnippet/cpp/connection-point-global-functions_1.cpp)]  
  
##  <a name="atlunadvise"></a>  AtlUnadvise  
 Encerra a conexão estabelecida por meio de [AtlAdvise](#atladvise).  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados o tempo de execução do Windows.  
  
```
HRESULT    AtlUnadvise(
    IUnknown* pUnkCP,
    const IID& iid,
    DWORD dw);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkCP`  
 [in] Um ponteiro para o **IUnknown** do objeto que o cliente está conectado com.  
  
 `iid`  
 [in] O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface gerenciada pelo ponto de conexão de saída.  
  
 `dw`  
 [in] O cookie que identifica exclusivamente a conexão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#96](../../atl/codesnippet/cpp/connection-point-global-functions_2.cpp)]  
  
##  <a name="atladvisesinkmap"></a>  AtlAdviseSinkMap  
 Chame essa função para recomendar ou não recomendar todas as entradas no mapa de eventos do coletor do objeto.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados o tempo de execução do Windows.  
  
```
HRESULT AtlAdviseSinkMap(T* pT, bool bAdvise);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 [in] Um ponteiro para o objeto que contém o mapa de coletor.  
  
 `bAdvise`  
 [in] **true** se todas as entradas de coletor devem ser avisado; **false** se todas as entradas de coletor devem ser unadvised.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#92](../../atl/codesnippet/cpp/connection-point-global-functions_3.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)   
 [Macros de ponto de conexão](../../atl/reference/connection-point-macros.md)
