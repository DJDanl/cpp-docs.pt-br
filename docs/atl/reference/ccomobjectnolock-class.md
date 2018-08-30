---
title: Classe CComObjectNoLock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComObjectNoLock
- ATLCOM/ATL::CComObjectNoLock
- ATLCOM/ATL::CComObjectNoLock::CComObjectNoLock
- ATLCOM/ATL::CComObjectNoLock::AddRef
- ATLCOM/ATL::CComObjectNoLock::QueryInterface
- ATLCOM/ATL::CComObjectNoLock::Release
dev_langs:
- C++
helpviewer_keywords:
- CComObjectNoLock class
ms.assetid: 288c6506-7da8-4127-8d58-7f4bd779539a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 85332341e1a229ce5110153c0ad6195ef0ad42c4
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43208169"
---
# <a name="ccomobjectnolock-class"></a>Classe CComObjectNoLock
Essa classe implementa `IUnknown` para um objeto não agregado, mas não não incremento a módulo contagem de bloqueio no construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class Base>  
class CComObjectNoLock : public Base
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Base de dados de*  
 Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), como bem como qualquer outra interface para o qual você deseja dar suporte no objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObjectNoLock::CComObjectNoLock](#ccomobjectnolock)|Construtor.|  
|[CComObjectNoLock::~CComObjectNoLock](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObjectNoLock::AddRef](#addref)|Incrementa a contagem de referência no objeto.|  
|[CComObjectNoLock::QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada.|  
|[CComObjectNoLock::Release](#release)|Diminui a contagem de referência no objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComObjectNoLock` é semelhante à [CComObject](../../atl/reference/ccomobject-class.md) em que ele implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) para um objeto não agregado; no entanto, `CComObjectNoLock` conta de incrementar o bloqueio de módulo no construtor.  
  
 Usa o ATL `CComObjectNoLock` internamente para fábricas de classe. Em geral, você não usará essa classe diretamente.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComObjectNoLock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="addref"></a>  CComObjectNoLock::AddRef  
 Incrementa a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para diagnóstico ou teste.  
  
##  <a name="ccomobjectnolock"></a>  CComObjectNoLock::CComObjectNoLock  
 O construtor. Diferentemente [CComObject](../../atl/reference/ccomobject-class.md), não incrementa a contagem de bloqueios do módulo.  
  
```
CComObjectNoLock(void* = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 <em>void\*</em>  
 [in] Esse parâmetro sem nome não é usado. Ele existe para obter simetria com outros `CComXXXObjectXXX` construtores.  
  
##  <a name="dtor"></a>  CComObjectNoLock::~CComObjectNoLock  
 O destruidor.  
  
```
~CComObjectNoLock();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados e chama [FinalRelease](ccomobjectrootex-class.md#finalrelease).  

  
##  <a name="queryinterface"></a>  CComObjectNoLock::QueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 *IID*  
 [in] O identificador da interface que está sendo solicitado.  
  
 *ppvObject*  
 [out] Um ponteiro para o ponteiro de interface identificado pelo *iid*. Se o objeto não dá suporte a essa interface, *ppvObject* é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
##  <a name="release"></a>  CComObjectNoLock::Release  
 Diminui a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração, `Release` retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações sem depuração, `Release` sempre retorna 0.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
