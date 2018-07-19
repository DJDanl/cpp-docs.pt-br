---
title: Classe CComSingleThreadModel | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComSingleThreadModel
- ATLBASE/ATL::CComSingleThreadModel
- ATLBASE/ATL::CComSingleThreadModel::AutoCriticalSection
- ATLBASE/ATL::CComSingleThreadModel::CriticalSection
- ATLBASE/ATL::CComSingleThreadModel::ThreadModelNoCS
- ATLBASE/ATL::CComSingleThreadModel::Decrement
- ATLBASE/ATL::CComSingleThreadModel::Increment
dev_langs:
- C++
helpviewer_keywords:
- single-threaded applications
- CComSingleThreadModel class
- single-threaded applications, ATL
ms.assetid: e5dc30c7-405a-4ba4-8ae9-51937243fce8
author: mikeblome
ms.author: mblome
ms.openlocfilehash: af19ac34e6a21aeb16278957b4e3df533a607d23
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37883431"
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
|[CComSingleThreadModel::AutoCriticalSection](#autocriticalsection)|Referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|  
|[CComSingleThreadModel::CriticalSection](#criticalsection)|Referencia a classe `CComFakeCriticalSection`.|  
|[CComSingleThreadModel::ThreadModelNoCS](#threadmodelnocs)|Referências `CComSingleThreadModel`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSingleThreadModel::Decrement](#decrement)|Decrementa o valor da variável especificada. Essa implementação não é thread-safe.|  
|[CComSingleThreadModel::Increment](#increment)|Incrementa o valor da variável especificada. Essa implementação não é thread-safe.|  
  
## <a name="remarks"></a>Comentários  
 `CComSingleThreadModel` fornece métodos para incrementar e diminuir o valor de uma variável. Diferentemente [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md), esses métodos não são thread-safe.  

 Normalmente, você usa `CComSingleThreadModel` por meio de uma das duas **typedef** nomes tanto [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel). A classe referenciada por cada **typedef** depende do modelo de threading usado, conforme mostrado na tabela a seguir:  

  
|typedef|Modelo de threading único|Modelo de apartment threading|Modelo de threading livre|  
|-------------|----------------------------|-------------------------------|--------------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S = `CComSingleThreadModel`; M = `CComMultiThreadModel`  
  
 `CComSingleThreadModel` em si define três **typedef** nomes. `ThreadModelNoCS` referências `CComSingleThreadModel`. `AutoCriticalSection` e `CriticalSection` referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados como adquirir e liberar a propriedade de uma seção crítica.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="autocriticalsection"></a>  CComSingleThreadModel::AutoCriticalSection  
 Ao usar `CComSingleThreadModel`, o **typedef** nome `AutoCriticalSection` referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).  
  
```
typedef CComFakeCriticalSection AutoCriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 Porque `CComFakeCriticalSection` não oferece uma seção crítica, seus métodos não fazem nada.  
  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm as definições para `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `AutoCriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
|`CComMultiThreadModel`|`CComAutoCriticalSection`|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
  
 Além `AutoCriticalSection`, você pode usar o **typedef** nome [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 Ver [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
##  <a name="criticalsection"></a>  CComSingleThreadModel::CriticalSection  
 Ao usar `CComSingleThreadModel`, o **typedef** nome `CriticalSection` referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).  
  
```
typedef CComFakeCriticalSection CriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 Porque `CComFakeCriticalSection` não oferece uma seção crítica, seus métodos não fazem nada.  
  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm as definições para `CriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `CriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
|`CComMultiThreadModel`|`CComCriticalSection`|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
  
 Além `CriticalSection`, você pode usar o **typedef** nome [AutoCriticalSection](#autocriticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 Ver [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
##  <a name="decrement"></a>  CComSingleThreadModel::Decrement  
 Decrementa essa função estática o valor da variável apontada por *p*.  
  
```
static ULONG WINAPI Decrement(LPLONG p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *p*  
 [in] Ponteiro para a variável a ser diminuída.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado de decremento.  
  
##  <a name="increment"></a>  CComSingleThreadModel::Increment  
 Decrementa essa função estática o valor da variável apontada por *p*.  
  
```
static ULONG WINAPI Increment(LPLONG p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *p*  
 [in] Ponteiro para a variável a ser incrementado.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado do incremento.  
  
##  <a name="threadmodelnocs"></a>  CComSingleThreadModel::ThreadModelNoCS  
 Ao usar `CComSingleThreadModel`, o **typedef** nome `ThreadModelNoCS` simplesmente faz referência a `CComSingleThreadModel`.  
  
```
typedef CComSingleThreadModel ThreadModelNoCS;
```  
  
### <a name="remarks"></a>Comentários  
 [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm as definições para `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe referenciada por `ThreadModelNoCS`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComSingleThreadModel`|`CComSingleThreadModel`|  
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|  
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|  
  
### <a name="example"></a>Exemplo  
 Ver [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
