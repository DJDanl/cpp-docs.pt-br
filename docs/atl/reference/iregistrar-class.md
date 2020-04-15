---
title: IRegistrar Interface
ms.date: 02/01/2017
f1_keywords:
- IRegistrar
- ATLIFASE/ATL::IRegistrar
- ATLIFASE/ATL::IRegistrar::ResourceRegisterSz
- ATLIFASE/ATL::IRegistrar::ResourceUnregisterSz
- ATLIFASE/ATL::IRegistrar::FileRegister
- ATLIFASE/ATL::IRegistrar::FileUnregister
- ATLIFASE/ATL::IRegistrar::StringRegister
- ATLIFASE/ATL::IRegistrar::StringUnregister
- ATLIFASE/ATL::IRegistrar::ResourceRegister
- ATLIFASE/ATL::IRegistrar::ResourceUnregister
helpviewer_keywords:
- Iregistrar Interface
ms.assetid: e88c04b7-0c93-4ae8-aeb9-ecd78f87421e
ms.openlocfilehash: 98943fe294322715723bd91207a6f3320ca1ffb3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329458"
---
# <a name="iregistrar-interface"></a>IRegistrar Interface

Esta interface é definida em atliface.h e é usada internamente por funções membros do CAtlModule, como [UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced).

## <a name="syntax"></a>Sintaxe

```
typedef interface IRegistrar IRegistrar;
```

## <a name="remarks"></a>Comentários

Consulte o tópico [Usando parâmetros substituíveis (pré-processador do registrador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) para obter mais detalhes.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iRegistrar::ResourceRegisterSz](#resourceregistersz)|Registra o recurso. |
|[iRegistrar::ResourceUnregisterSz](#resourceunregistersz)| Desregistra o recurso.|
|[iRegistrar::registro de arquivos](#fileregister)|Registra o arquivo.|
|[IRegistrar::ArquivoUnregister](#fileunregister)|Desregistra o arquivo.|
|[iRegistrar::registro de strings](#stringregister)|Registra a corda.|
|[IRegistrar::StringUnregister](#stringunregister)|Desregistra a string|
|[iRegistrar::Registro de recursos](#resourceregister)|Registra o recurso.|
|[IRegistrar::ResourceUnregister](#resourceunregister)|Desregistra o recurso.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlifase.h

## <a name="iregistrarresourceregistersz"></a><a name="resourceregistersz"></a>iRegistrar::ResourceRegisterSz

Registra o recurso.

```
virtual HRESULT STDMETHODCALLTYPE ResourceRegisterSz(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_z_ LPCOLESTR szID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

## <a name="iregistrarresourceunregistersz"></a><a name="resourceunregistersz"></a>iRegistrar::ResourceUnregisterSz

Desregistra o recurso.

```
virtual HRESULT STDMETHODCALLTYPE ResourceUnregisterSz(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_z_ LPCOLESTR szID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

## <a name="iregistrarfileregister"></a><a name="fileregister"></a>iRegistrar::registro de arquivos

Registra o arquivo.

```
virtual HRESULT STDMETHODCALLTYPE FileRegister(
    /* [in] */ _In_z_ LPCOLESTR fileName) = 0;
```

## <a name="iregistrarfileunregister"></a><a name="fileunregister"></a>IRegistrar::ArquivoUnregister

Desregistra o arquivo.

```
virtual HRESULT STDMETHODCALLTYPE FileUnregister(
    /* [in] */ _In_z_ LPCOLESTR fileName) = 0;
```

## <a name="iregistrarstringregister"></a><a name="stringregister"></a>iRegistrar::registro de strings

Registra os dados de seqüência especificados.

```
virtual HRESULT STDMETHODCALLTYPE StringRegister(
    /* [in] */ _In_z_ LPCOLESTR data) = 0;
```

## <a name="iregistrarstringunregister"></a><a name="stringunregister"></a>IRegistrar::StringUnregister

Desregistra os dados de seqüência especificados.

```
virtualHRESULT STDMETHODCALLTYPE StringUnregister(
    /* [in] */ _In_z_ LPCOLESTR data) = 0;
```

## <a name="iregistrarresourceregister"></a><a name="resourceregister"></a>iRegistrar::Registro de recursos

Registra o recurso.

```
virtual HRESULT STDMETHODCALLTYPE ResourceRegister(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_ UINT nID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

## <a name="iregistrarresourceunregister"></a><a name="resourceunregister"></a>IRegistrar::ResourceUnregister

Desregistra o recurso.

```
virtualHRESULT STDMETHODCALLTYPE ResourceUnregister(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_ UINT nID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

## <a name="see-also"></a>Confira também

[Usando parâmetros substituíveis (o pré-processador do registrador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)<br/>
[Componente de Registro (Registrador)](../../atl/atl-registry-component-registrar.md)
