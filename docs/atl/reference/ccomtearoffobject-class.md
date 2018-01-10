---
title: Classe CComTearOffObject | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComTearOffObject
- ATLCOM/ATL::CComTearOffObject
- ATLCOM/ATL::CComTearOffObject::CComTearOffObject
- ATLCOM/ATL::CComTearOffObject::AddRef
- ATLCOM/ATL::CComTearOffObject::QueryInterface
- ATLCOM/ATL::CComTearOffObject::Release
- ATLCOM/ATL::CComTearOffObjectBase
- ATLCOM/ATL::m_pOwner
dev_langs: C++
helpviewer_keywords:
- tear-off interfaces, ATL
- tear-off interfaces
- CComTearOffObject class
ms.assetid: d974b598-c6b2-42b1-8360-9190d9d0fbf3
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 80be7d80af5a6c8fa2c47bc0e853020663f2ceae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomtearoffobject-class"></a>Classe CComTearOffObject
Essa classe implementa uma interface destacável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class Base>
class CComTearOffObject : public Base
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Base`  
 Sua classe destacável derivado `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacável para dar suporte.  
  
 ATL implementa interfaces destacável em duas fases — o `CComTearOffObjectBase` métodos controlam a contagem de referência e `QueryInterface`, enquanto `CComTearOffObject` implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509).  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComTearOffObject::CComTearOffObject](#ccomtearoffobject)|O construtor.|  
|[CComTearOffObject:: ~ CComTearOffObject](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComTearOffObject::AddRef](#addref)|Incrementa a contagem de referência para um `CComTearOffObject` objeto.|  
|[CComTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada em sua classe destacável ou a classe do proprietário.|  
|[CComTearOffObject::Release](#release)|Diminui a contagem de referência para um `CComTearOffObject` de objeto e destrói a ele.|  
  
### <a name="ccomtearoffobjectbase-methods"></a>Métodos de CComTearOffObjectBase  
  
|||  
|-|-|  
|[CComTearOffObjectBase](#ccomtearoffobjectbase)|Construtor.|  
  
### <a name="ccomtearoffobjectbase-data-members"></a>Membros de dados de CComTearOffObjectBase  
  
|||  
|-|-|  
|[m_pOwner](#m_powner)|Um ponteiro para um `CComObject` derivado da classe proprietário.|  
  
## <a name="remarks"></a>Comentários  
 `CComTearOffObject`implementa uma interface destacável como um objeto separado que é instanciado quando essa interface é consultado para. O destacável é excluído quando sua contagem de referência se torna zero. Normalmente, você pode criar uma interface destacável para uma interface que raramente é usada, pois usar um destacável salva um ponteiro vtable em todas as instâncias do objeto principal.  
  
 Você deve derivar a classe que implementa o destacável de `CComTearOffObjectBase` e de quaisquer interfaces que você deseja que o seu objeto destacável para dar suporte. `CComTearOffObjectBase`é transformado em modelo na classe do proprietário e no modelo de thread. A classe do proprietário é a classe do objeto para o qual um destacável está sendo implementada. Se você não especificar um modelo de thread, o modelo de thread padrão será usado.  
  
 Você deve criar um mapa de COM para a sua classe destacável. Quando ATL instancia o destacável, ele criará **CComTearOffObject\<CYourTearOffClass >** ou **CComCachedTearOffObject\<CYourTearOffClass >**.  
  
 Por exemplo, no exemplo de PAGER, a `CBeeper2` classe é a classe destacável e `CBeeper` classe é a classe do proprietário:  
  
 [!code-cpp[NVC_ATL_COM#43](../../atl/codesnippet/cpp/ccomtearoffobject-class_1.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComTearOffObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="addref"></a>CComTearOffObject::AddRef  
 Incrementa a contagem de referência de `CComTearOffObject` objeto por um.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para diagnóstico e de teste.  
  
##  <a name="ccomtearoffobject"></a>CComTearOffObject::CComTearOffObject  
 O construtor.  
  
```
CComTearOffObject(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 [in] Ponteiro será convertido em um ponteiro para um **CComObject\<proprietário >** objeto.  
  
### <a name="remarks"></a>Comentários  
 Incrementa a contagem de referência do proprietário em um.  
  
##  <a name="dtor"></a>CComTearOffObject:: ~ CComTearOffObject  
 O destruidor.  
  
```
~CComTearOffObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados, chamadas FinalRelease e diminui o módulo de contagem de bloqueio.  
  
##  <a name="ccomtearoffobjectbase"></a>CComTearOffObject::CComTearOffObjectBase  
 O construtor.  
  
```
CComTearOffObjectBase();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa o [m_pOwner](#m_powner) membro **nulo**.  
  
##  <a name="m_powner"></a>CComTearOffObject::m_pOwner  
 Um ponteiro para um [CComObject](../../atl/reference/ccomobject-class.md) objeto derivado de *proprietário*.  
  
```
CComObject<Owner>* m_pOwner;
```  
  
### <a name="parameters"></a>Parâmetros  
 *Proprietário*  
 [in] A classe para a qual um destacável está sendo implementada.  
  
### <a name="remarks"></a>Comentários  
 O ponteiro é inicializado como **nulo** durante a construção.  
  
##  <a name="queryinterface"></a>CComTearOffObject::QueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 [in] O IID da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface identificado por `iid`, ou **nulo** se a interface não foi encontrada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Consultas primeiro para as interfaces na sua classe destacável. Se a interface não estiver lá, consultas para a interface no objeto do proprietário. Se a interface solicitada é **IUnknown**, retorna o **IUnknown** do proprietário.  
  
##  <a name="release"></a>CComTearOffObject::Release  
 Diminui a contagem de referência por um e, se a contagem de referência for zero, exclui o `CComTearOffObject`.  
  
```
STDMETHOD_ULONG Release();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração não, sempre retorna zero. Compilações de depuração, retorna um valor que pode ser útil para um diagnóstico ou teste.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
