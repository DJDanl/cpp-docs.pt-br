---
title: Classe CComMultiThreadModelNoCS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComMultiThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS::AutoCriticalSection
- ATLBASE/ATL::CComMultiThreadModelNoCS::CriticalSection
- ATLBASE/ATL::CComMultiThreadModelNoCS::ThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS::Decrement
- ATLBASE/ATL::CComMultiThreadModelNoCS::Increment
dev_langs: C++
helpviewer_keywords:
- ATL, multithreading
- CComMultiThreadModelNoCS class
- threading [ATL]
ms.assetid: 2b3f7a45-fd72-452c-aaf3-ccdaa621c821
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f1f0b531942e281236c65ef9a2e1ad3d3f669bbe
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ccommultithreadmodelnocs-class"></a>Classe CComMultiThreadModelNoCS
`CComMultiThreadModelNoCS`fornece métodos de thread-safe para incrementar e decrementar o valor de uma variável, sem bloqueio de seção crítica ou funcionalidade de desbloqueio.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComMultiThreadModelNoCS
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComMultiThreadModelNoCS::AutoCriticalSection](#autocriticalsection)|Referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|  
|[CComMultiThreadModelNoCS::CriticalSection](#criticalsection)|Referencia a classe `CComFakeCriticalSection`.|  
|[CComMultiThreadModelNoCS::ThreadModelNoCS](#threadmodelnocs)|Referencia a classe `CComMultiThreadModelNoCS`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComMultiThreadModelNoCS::Decrement](#decrement)|(Estático) Diminui o valor da variável especificada de uma forma thread-safe.|  
|[CComMultiThreadModelNoCS::Increment](#increment)|(Estático) Incrementa o valor da variável especificada de uma forma thread-safe.|  
  
## <a name="remarks"></a>Comentários  
 `CComMultiThreadModelNoCS`é semelhante a [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) em que ele fornece métodos de thread-safe para incrementar e decrementar uma variável. No entanto, ao fazer referência a uma classe de seção crítica por meio de `CComMultiThreadModelNoCS`, métodos, como `Lock` e `Unlock` não fará nada.  
  
 Normalmente, você usa `CComMultiThreadModelNoCS` por meio de `ThreadModelNoCS` `typedef` nome. Isso `typedef` é definido em `CComMultiThreadModelNoCS`, `CComMultiThreadModel`, e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md).  
  
> [!NOTE]
>  Global `typedef` nomes [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) e [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel) não fazem referência a `CComMultiThreadModelNoCS`.  
  
 Além `ThreadModelNoCS`, `CComMultiThreadModelNoCS` define `AutoCriticalSection` e `CriticalSection`. Esses dois últimos `typedef` nomes de referência [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados como adquirir e liberar uma seção crítica.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="autocriticalsection"></a>CComMultiThreadModelNoCS::AutoCriticalSection  
 Ao usar `CComMultiThreadModelNoCS`, o `typedef` nome `AutoCriticalSection` referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).  
  
```
typedef CComFakeCriticalSection AutoCriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.  
  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm definições de `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `AutoCriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
|`CComMultiThreadModel`|`CComAutoCriticalSection`|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
  
 Além `AutoCriticalSection`, você pode usar o `typedef` nome [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
##  <a name="criticalsection"></a>CComMultiThreadModelNoCS::CriticalSection  
 Ao usar `CComMultiThreadModelNoCS`, o `typedef` nome `CriticalSection` referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).  
  
```
typedef CComFakeCriticalSection CriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.  
  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm definições de `CriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `CriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
|`CComMultiThreadModel`|`CComCriticalSection`|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
  
 Além `CriticalSection`, você pode usar o `typedef` nome `AutoCriticalSection`. Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
##  <a name="decrement"></a>CComMultiThreadModelNoCS::Decrement  
 Função estática chama a função Win32 [InterlockedDecrement](http://msdn.microsoft.com/library/windows/desktop/ms683580), que diminui o valor da variável apontado pelo `p`.  
  
```
static ULONG WINAPI Decrement(LPLONG p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Ponteiro para a variável para ser diminuída.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o resultado de decremento for 0, em seguida, `Decrement` retornará 0. Se o resultado de decremento é diferente de zero, o valor de retorno também é diferente de zero, mas pode não ser igual a diminuir o resultado.  
  
### <a name="remarks"></a>Comentários  
 **InterlockedDecrement** impede que mais de um segmento simultaneamente usando essa variável.  
  
##  <a name="increment"></a>CComMultiThreadModelNoCS::Increment  
 Função estática chama a função Win32 [InterlockedIncrement](http://msdn.microsoft.com/library/windows/desktop/ms683614), que incrementa o valor da variável apontada pelo `p`.  
  
```
static ULONG WINAPI Increment(LPLONG p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Ponteiro para a variável a ser incrementado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o resultado do incremento for 0, em seguida, **incremento** retornará 0. Se o resultado do incremento for diferente de zero, o valor de retorno também é diferente de zero, mas pode não ser igual o resultado do incremento.  
  
### <a name="remarks"></a>Comentários  
 **InterlockedIncrement** impede que mais de um segmento simultaneamente usando essa variável.  
  
##  <a name="threadmodelnocs"></a>CComMultiThreadModelNoCS::ThreadModelNoCS  
 Ao usar `CComMultiThreadModelNoCS`, o `typedef` nome `ThreadModelNoCS` simplesmente referencia `CComMultiThreadModelNoCS`.  
  
```
typedef CComMultiThreadModelNoCS ThreadModelNoCS;
```  
  
### <a name="remarks"></a>Comentários  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm definições de `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe referenciada por `ThreadModelNoCS`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|  
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|  
|`CComSingleThreadModel`|`CComSingleThreadModel`|  
  
 Observe que a definição de `ThreadModelNoCS` na `CComMultiThreadModelNoCS` oferece simetria com `CComMultiThreadModel` e `CComSingleThreadModel`. Por exemplo, suponha que o código de exemplo `CComMultiThreadModel::AutoCriticalSection` declarado seguintes `typedef`:  
  
 [!code-cpp[NVC_ATL_COM#37](../../atl/codesnippet/cpp/ccommultithreadmodelnocs-class_1.h)]  
  
 Independentemente da classe especificada para `ThreadModel` (como `CComMultiThreadModelNoCS`), `_ThreadModel` resolve adequadamente.  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)