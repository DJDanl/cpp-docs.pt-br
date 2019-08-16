---
title: Classe IRunnableObjectImpl
ms.date: 11/04/2016
f1_keywords:
- IRunnableObjectImpl
- ATLCTL/ATL::IRunnableObjectImpl
- ATLCTL/ATL::IRunnableObjectImpl::GetRunningClass
- ATLCTL/ATL::IRunnableObjectImpl::IsRunning
- ATLCTL/ATL::IRunnableObjectImpl::LockRunning
- ATLCTL/ATL::IRunnableObjectImpl::Run
- ATLCTL/ATL::IRunnableObjectImpl::SetContainedObject
helpviewer_keywords:
- containers, running controls
- IRunnableObjectImpl class
- IRunnableObject, ATL implementation
- controls [ATL], running
- controls [C++], container running in ATL
ms.assetid: 305c7c3b-889e-49dd-aca1-34379c1b9931
ms.openlocfilehash: 6b1af7c21c6f5028ad6d3a228cb22650fa3cef42
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495659"
---
# <a name="irunnableobjectimpl-class"></a>Classe IRunnableObjectImpl

Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [IRunnableObject](/windows/win32/api/objidl/nn-objidl-irunnableobject) .

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IRunnableObjectImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IRunnableObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IRunnableObjectImpl::GetRunningClass](#getrunningclass)|Retorna o CLSID do controle em execução. A implementação da ATL define o CLSID como GUID_NULL e Retorna E_UNEXPECTED.|
|[IRunnableObjectImpl::IsRunning](#isrunning)|Determina se o controle está em execução. A implementação da ATL retorna TRUE.|
|[IRunnableObjectImpl::LockRunning](#lockrunning)|Bloqueia o controle no estado de execução. A implementação da ATL retorna S_OK.|
|[IRunnableObjectImpl::Run](#run)|Força o controle a ser executado. A implementação da ATL retorna S_OK.|
|[IRunnableObjectImpl::SetContainedObject](#setcontainedobject)|Indica que o controle está inserido. A implementação da ATL retorna S_OK.|

## <a name="remarks"></a>Comentários

A interface [IRunnableObject](/windows/win32/api/objidl/nn-objidl-irunnableobject) habilita um contêiner para determinar se um controle está em execução, forçá-lo a ser executado ou bloqueá-lo no estado de execução. Fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IRunnableObjectImpl`

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IRunnableObject`

`IRunnableObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="getrunningclass"></a>  IRunnableObjectImpl::GetRunningClass

Retorna o CLSID do controle em execução.

```
HRESULT GetRunningClass(LPCLSID lpClsid);
```

### <a name="return-value"></a>Valor de retorno

A implementação da ATL \* define *lpClsid* como GUID_NULL e Retorna E_UNEXPECTED.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject:: GetRunningClass](/windows/win32/api/objidl/nf-objidl-irunnableobject-getrunningclass) na SDK do Windows.

##  <a name="isrunning"></a>  IRunnableObjectImpl::IsRunning

Determina se o controle está em execução.

```
virtual BOOL IsRunning();
```

### <a name="return-value"></a>Valor de retorno

A implementação da ATL retorna TRUE.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject:: isexecute](/windows/win32/api/objidl/nf-objidl-irunnableobject-isrunning) no SDK do Windows.

##  <a name="lockrunning"></a>  IRunnableObjectImpl::LockRunning

Bloqueia o controle no estado de execução.

```
HRESULT LockRunning(BOOL fLock, BOOL fLastUnlockCloses);
```

### <a name="return-value"></a>Valor de retorno

A implementação da ATL retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject:: LockRunning](/windows/win32/api/objidl/nf-objidl-irunnableobject-lockrunning) na SDK do Windows.

##  <a name="run"></a>  IRunnableObjectImpl::Run

Força o controle a ser executado.

```
HRESULT Run(LPBINDCTX lpbc);
```

### <a name="return-value"></a>Valor de retorno

A implementação da ATL retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject:: Run](/windows/win32/api/objidl/nf-objidl-irunnableobject-run) no SDK do Windows.

##  <a name="setcontainedobject"></a>  IRunnableObjectImpl::SetContainedObject

Indica que o controle está inserido.

```
HRESULT SetContainedObject(BOOL fContained);
```

### <a name="return-value"></a>Valor de retorno

A implementação da ATL retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject::](/windows/win32/api/objidl/nf-objidl-irunnableobject-setcontainedobject) setcontainobject na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
