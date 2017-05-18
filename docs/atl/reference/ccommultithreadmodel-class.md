---
title: Classe CComMultiThreadModel | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComMultiThreadModel
- ATLBASE/ATL::CComMultiThreadModel
- ATLBASE/ATL::CComMultiThreadModel::AutoCriticalSection
- ATLBASE/ATL::CComMultiThreadModel::CriticalSection
- ATLBASE/ATL::CComMultiThreadModel::ThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModel::Decrement
- ATLBASE/ATL::CComMultiThreadModel::Increment
dev_langs:
- C++
helpviewer_keywords:
- ATL, multithreading
- CComMultiThreadModel class
- threading [ATL]
ms.assetid: db8f1662-2f7a-44b3-b341-ffbfb6e422a3
caps.latest.revision: 21
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 6dbfb33a717b23e8252c9bcb2fc11b4a6e420280
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ccommultithreadmodel-class"></a>Classe CComMultiThreadModel
`CComMultiThreadModel`fornece métodos de thread-safe para incrementar e diminuir o valor de uma variável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComMultiThreadModel
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComMultiThreadModel::AutoCriticalSection](#autocriticalsection)|Faz referência a classe [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md).|  
|[CComMultiThreadModel::CriticalSection](#criticalsection)|Faz referência a classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md).|  
|[CComMultiThreadModel::ThreadModelNoCS](#threadmodelnocs)|Faz referência a classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComMultiThreadModel::Decrement](#decrement)|(Estático) Diminui o valor da variável especificada de forma segura para thread.|  
|[CComMultiThreadModel::Increment](#increment)|(Estático) Incrementa o valor da variável especificada de forma segura para thread.|  
  
## <a name="remarks"></a>Comentários  
 Normalmente, você usa `CComMultiThreadModel` através de um dos dois `typedef` nomes [CComObjectThreadModel] (atl-typedefs.md #ccomobjectthreadmodel ou [CComGlobalsThreadModel] (atl-typedefs.md #ccomglobalsthreadmodel. A classe referenciada por cada `typedef` depende do modelo de threading usado, conforme mostrado na tabela a seguir:  
  
|typedef|Threading único|Apartment threading|Livre de threading|  
|-------------|----------------------|-------------------------|--------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S= `CComSingleThreadModel`; M =`CComMultiThreadModel`  
  
 `CComMultiThreadModel`em si define três `typedef` nomes. `AutoCriticalSection`e `CriticalSection` referência a classes que fornecem métodos para a obtenção e liberar a propriedade de uma seção crítica. `ThreadModelNoCS`referências de classe [CComMultiThreadModelNoCS(ccommultithreadmodelnocs-class.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="autocriticalsection"></a>CComMultiThreadModel::AutoCriticalSection  
 Ao usar `CComMultiThreadModel`, o `typedef` nome `AutoCriticalSection` faz referência a classe [CComAutoCriticalSection](ccomautocriticalsection-class.md), que fornece métodos para a obtenção e liberar a propriedade de um objeto da seção crítica.  
  
```
typedef CComAutoCriticalSection AutoCriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 [CComSingleThreadModel](ccomsinglethreadmodel-class.md) e [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md) também contêm definições de `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `AutoCriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComMultiThreadModel`|`CComCriticalSection`|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
  
 Além `AutoCriticalSection`, você pode usar o `typedef` nome [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 O código a seguir é modelado [CComObjectRootEx](ccomobjectrootex-class.md)e demonstra `AutoCriticalSection` que está sendo usado em um ambiente de threading.  
  

```cpp  
template<class ThreadModel>
class CMyAutoCritClass
{
public:
   typedef ThreadModel _ThreadModel;
   typedef typename _ThreadModel::AutoCriticalSection _CritSec;

   CMyAutoCritClass() : m_dwRef(0) {}

   ULONG InternalAddRef()
   {
      return _ThreadModel::Increment(&m_dwRef);
   }
   ULONG InternalRelease()
   {
      return _ThreadModel::Decrement(&m_dwRef);   
   }
   void Lock() { m_critsec.Lock( ); }
   void Unlock() { m_critsec.Unlock(); }

private:
   _CritSec m_critsec;
   LONG m_dwRef;
```  
  
 As tabelas a seguir mostram os resultados do `InternalAddRef` e `Lock` métodos, dependendo do **ThreadModel** parâmetro do modelo e o modelo de threading usado pelo aplicativo:  
  
### <a name="threadmodel--ccomobjectthreadmodel"></a>ThreadModel = CComObjectThreadModel  
  
|Método|Único ou um apartamento de Threading|Livre de Threading|  
|------------|-----------------------------------|--------------------|  
|`InternalAddRef`|O incremento não é thread-safe.|O incremento é thread-safe.|  
|`Lock`|Não faz nada; Há uma seção crítica para bloquear.|A seção crítica está bloqueada.|  
  
### <a name="threadmodel--ccomobjectthreadmodelthreadmodelnocs"></a>ThreadModel = CComObjectThreadModel::ThreadModelNoCS  
  
|Método|Único ou um apartamento de Threading|Livre de Threading|  
|------------|-----------------------------------|--------------------|  
|`InternalAddRef`|O incremento não é thread-safe.|O incremento é thread-safe.|  
|`Lock`|Não faz nada; Há uma seção crítica para bloquear.|Não faz nada; Há uma seção crítica para bloquear.|  
  
##  <a name="criticalsection"></a>CComMultiThreadModel::CriticalSection  
 Ao usar `CComMultiThreadModel`, o `typedef` nome `CriticalSection` faz referência a classe [CComCriticalSection](ccomcriticalsection-class.md), que fornece métodos para a obtenção e liberar a propriedade de um objeto da seção crítica.  
  
```
typedef CComCriticalSection CriticalSection;
```  
  
### <a name="remarks"></a>Comentários  
 [CComSingleThreadModel](ccomsinglethreadmodel-class.md) e [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md) também contêm definições de `CriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `CriticalSection`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComMultiThreadModel`|`CComCriticalSection`|  
|`CComSingleThreadModel`|`CComFakeCriticalSection`|  
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|  
  
 Além `CriticalSection`, você pode usar o `typedef` nome [AutoCriticalSection](#autocriticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](#autocriticalsection).  
  
##  <a name="decrement"></a>CComMultiThreadModel::Decrement  
 A função estática chama a função Win32 [InterlockedDecrement](http://msdn.microsoft.com/library/windows/desktop/ms683580), que diminui o valor da variável apontado por `p`.  
  
```
static ULONG WINAPI Decrement(LPLONG p) throw ();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Ponteiro para a variável a ser diminuída.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o resultado do decremento for 0, então `Decrement` retornará 0. Se o resultado de decremento é diferente de zero, o valor de retorno também é diferente de zero, mas pode não ser igual o resultado do decrement.  
  
### <a name="remarks"></a>Comentários  
 **InterlockedDecrement** impede que mais de um segmento simultaneamente usando essa variável.  
  
##  <a name="increment"></a>CComMultiThreadModel::Increment  
 A função estática chama a função Win32 [InterlockedIncrement](http://msdn.microsoft.com/library/windows/desktop/ms683614), que incrementa o valor da variável apontada por `p`.  
  
```
static ULONG WINAPI Increment(LPLONG p) throw ();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Ponteiro para a variável a ser incrementado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o resultado do incremento for 0, então **incremento** retornará 0. Se o resultado do incremento for diferente de zero, o valor de retorno também é diferente de zero, mas pode não ser igual o resultado do incremento.  
  
### <a name="remarks"></a>Comentários  
 **InterlockedIncrement** impede que mais de um segmento simultaneamente usando essa variável.  
  
##  <a name="threadmodelnocs"></a>CComMultiThreadModel::ThreadModelNoCS  
 Ao usar `CComMultiThreadModel`, o `typedef` nome `ThreadModelNoCS` faz referência a classe [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md).  
  
```
typedef CComMultiThreadModelNoCS ThreadModelNoCS;
```  
  
### <a name="remarks"></a>Comentários  
 `CComMultiThreadModelNoCS`fornece métodos de thread-safe para incrementar e decrementar uma variável; No entanto, ele não fornece uma seção crítica.  
  
 [CComSingleThreadModel](ccomsinglethreadmodel-class.md) e `CComMultiThreadModelNoCS` também contêm definições de `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe referenciada por `ThreadModelNoCS`:  
  
|Classe definida em|Classe referenciada|  
|----------------------|----------------------|  
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|  
|`CComSingleThreadModel`|`CComSingleThreadModel`|  
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|  
  
### <a name="example"></a>Exemplo  
 Consulte [CComMultiThreadModel::AutoCriticalSection](#autocriticalsection).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComSingleThreadModel](ccomsinglethreadmodel-class.md)   
 [Classe CComAutoCriticalSection](ccomautocriticalsection-class.md)   
 [Classe CComCriticalSection](ccomcriticalsection-class.md)   
 [Visão geral da classe](../atl-class-overview.md)

