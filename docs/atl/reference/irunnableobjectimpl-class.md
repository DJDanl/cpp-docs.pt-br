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
ms.openlocfilehash: 2843c0c25a5c104ffbdff72255ac5d85cf53b1ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329455"
---
# <a name="irunnableobjectimpl-class"></a>Classe IRunnableObjectImpl

Essa classe `IUnknown` implementa e fornece uma implementação padrão da interface [IRunnableObject.](/windows/win32/api/objidl/nn-objidl-irunnableobject)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IRunnableObjectImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IRunnableObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IRunnableObjectImpl::GetRunningClass](#getrunningclass)|Retorna o CLSID do controle de execução. A implementação atl define o CLSID para GUID_NULL e retorna E_UNEXPECTED.|
|[IRunnableObjectImpl::IsRunning](#isrunning)|Determina se o controle está funcionando. A implementação ATL retorna TRUE.|
|[IRunnableObjectImpl::LockRunning](#lockrunning)|Bloqueia o controle no estado de execução. A implementação da ATL retorna S_OK.|
|[IRunnableObjectImpl::Run](#run)|Força o controle a correr. A implementação da ATL retorna S_OK.|
|[IRunnableObjectImpl::SetContainedObject](#setcontainedobject)|Indica que o controle está embutido. A implementação da ATL retorna S_OK.|

## <a name="remarks"></a>Comentários

A interface [IRunnableObject](/windows/win32/api/objidl/nn-objidl-irunnableobject) permite que um contêiner determine se um controle está sendo executado, force-o a executá-lo ou bloqueie-o no estado em execução. A `IRunnableObjectImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IRunnableObject`

`IRunnableObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="irunnableobjectimplgetrunningclass"></a><a name="getrunningclass"></a>IRunnableObjectImpl::GetRunningClass

Retorna o CLSID do controle de execução.

```
HRESULT GetRunningClass(LPCLSID lpClsid);
```

### <a name="return-value"></a>Valor retornado

A implementação \* atl define *lpClsid* para GUID_NULL e retorna E_UNEXPECTED.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject::GetRunningClass](/windows/win32/api/objidl/nf-objidl-irunnableobject-getrunningclass) no Windows SDK.

## <a name="irunnableobjectimplisrunning"></a><a name="isrunning"></a>IRunnableObjectImpl::IsRunning

Determina se o controle está funcionando.

```
virtual BOOL IsRunning();
```

### <a name="return-value"></a>Valor retornado

A implementação ATL retorna TRUE.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject::IsRunning](/windows/win32/api/objidl/nf-objidl-irunnableobject-isrunning) in the Windows SDK.

## <a name="irunnableobjectimpllockrunning"></a><a name="lockrunning"></a>IRunnableObjectImpl::LockRunning

Bloqueia o controle no estado de execução.

```
HRESULT LockRunning(BOOL fLock, BOOL fLastUnlockCloses);
```

### <a name="return-value"></a>Valor retornado

A implementação da ATL retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject::LockRunning](/windows/win32/api/objidl/nf-objidl-irunnableobject-lockrunning) in the Windows SDK.

## <a name="irunnableobjectimplrun"></a><a name="run"></a>IRunnableObjectImpl::Run

Força o controle a correr.

```
HRESULT Run(LPBINDCTX lpbc);
```

### <a name="return-value"></a>Valor retornado

A implementação da ATL retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject::Execute](/windows/win32/api/objidl/nf-objidl-irunnableobject-run) no Windows SDK.

## <a name="irunnableobjectimplsetcontainedobject"></a><a name="setcontainedobject"></a>IRunnableObjectImpl::SetContainedObject

Indica que o controle está embutido.

```
HRESULT SetContainedObject(BOOL fContained);
```

### <a name="return-value"></a>Valor retornado

A implementação da ATL retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IRunnableObject::SetContainedObject](/windows/win32/api/objidl/nf-objidl-irunnableobject-setcontainedobject) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
