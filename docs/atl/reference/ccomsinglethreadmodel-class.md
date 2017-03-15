---
title: Classe CComSingleThreadModel | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CComSingleThreadModel
- CComSingleThreadModel
- ATL::CComSingleThreadModel
dev_langs:
- C++
helpviewer_keywords:
- single-threaded applications
- CComSingleThreadModel class
- single-threaded applications, ATL
ms.assetid: e5dc30c7-405a-4ba4-8ae9-51937243fce8
caps.latest.revision: 19
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
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: ff5d8d2ced1d6fe0196888d8c746844ace8307f8
ms.lasthandoff: 02/25/2017

---
# <a name="ccomsinglethreadmodel-class"></a>Classe CComSingleThreadModel
Essa classe fornece métodos para incrementar e diminuir o valor de uma variável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComSingleThreadModel
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSingleThreadModel::AutoCriticalSection](#autocriticalsection)|Faz referência a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|  
|[CComSingleThreadModel::CriticalSection](#criticalsection)|Faz referência a classe `CComFakeCriticalSection`.|  
|[CComSingleThreadModel::ThreadModelNoCS](#threadmodelnocs)|Referências `CComSingleThreadModel`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSingleThreadModel::Decrement](#decrement)|Diminui o valor da variável especificada. Essa implementação não é thread-safe.|  
|[CComSingleThreadModel::Increment](#increment)|Incrementa o valor da variável especificada. Essa implementação não é thread-safe.|  
  
## <a name="remarks"></a>Comentários  
 `CComSingleThreadModel`fornece métodos para incrementar e diminuir o valor de uma variável. Ao contrário de [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md), esses métodos não são thread-safe.  

 Normalmente, você usa `CComSingleThreadModel` através de um dos dois `typedef` nomes ou [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel). A classe referenciada por cada `typedef` depende do modelo de threading usado, conforme mostrado na tabela a seguir:  

  
|typedef|Único modelo de threading|Modelo de apartment threading|Modelo de threading livre|  
|-------------|----------------------------|-------------------------------|--------------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S= `CComSingleThreadModel`; M =`CComMultiThreadModel`  
  
 `CComSingleThreadModel`em si define três `typedef` nomes. `ThreadModelNoCS`referências `CComSingleThreadModel`. `AutoCriticalSection`e `CriticalSection` referência a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados como adquirir e liberar a propriedade de uma seção crítica.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-nameautocriticalsectiona--ccomsinglethreadmodelautocriticalsection"></a><a name="autocriticalsection"></a>CComSingleThreadModel::AutoCriticalSection  
 Ao usar `CComSingleThreadModel`, o `typedef` nome `AutoCriticalSection` faz referência a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).  
  
```
typedef CComFakeCriticalSection AutoCriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.  
  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições de `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `AutoCriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
|`CComMultiThreadModel`|`CComAutoCriticalSection`|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
  
 Além `AutoCriticalSection`, você pode usar o `typedef` nome [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
##  <a name="a-namecriticalsectiona--ccomsinglethreadmodelcriticalsection"></a><a name="criticalsection"></a>CComSingleThreadModel::CriticalSection  
 Ao usar `CComSingleThreadModel`, o `typedef` nome `CriticalSection` faz referência a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).  
  
```
typedef CComFakeCriticalSection CriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.  
  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições de `CriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `CriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
|`CComMultiThreadModel`|`CComCriticalSection`|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
  
 Além `CriticalSection`, você pode usar o `typedef` nome [AutoCriticalSection](#autocriticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
##  <a name="a-namedecrementa--ccomsinglethreadmodeldecrement"></a><a name="decrement"></a>CComSingleThreadModel::Decrement  
 Decrementa essa função estática o valor da variável apontada por `p`.  
  
```
static ULONG WINAPI Decrement(LPLONG p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Ponteiro para a variável a ser diminuída.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado do decrement.  
  
##  <a name="a-nameincrementa--ccomsinglethreadmodelincrement"></a><a name="increment"></a>CComSingleThreadModel::Increment  
 Decrementa essa função estática o valor da variável apontada por `p`.  
  
```
static ULONG WINAPI Increment(LPLONG p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Ponteiro para a variável a ser incrementado.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado do incremento.  
  
##  <a name="a-namethreadmodelnocsa--ccomsinglethreadmodelthreadmodelnocs"></a><a name="threadmodelnocs"></a>CComSingleThreadModel::ThreadModelNoCS  
 Ao usar `CComSingleThreadModel`, o `typedef` nome `ThreadModelNoCS` simplesmente referencia `CComSingleThreadModel`.  
  
```
typedef CComSingleThreadModel ThreadModelNoCS;
```  
  
### <a name="remarks"></a>Comentários  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições de `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe referenciada por `ThreadModelNoCS`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComSingleThreadModel`|`CComSingleThreadModel`|  
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|  
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

