---
title: Interface IRegistrar
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
ms.openlocfilehash: e347bdba1656a53cd705123a26650dad50d3892f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78857126"
---
# <a name="iregistrar-interface"></a>Interface IRegistrar

Essa interface é definida em atliface. h e é usada internamente por funções de membro CAtlModule, como [UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced).

## <a name="syntax"></a>Sintaxe

```
typedef interface IRegistrar IRegistrar;
```

## <a name="remarks"></a>Comentários

Consulte o tópico [usando parâmetros substituíveis (o pré-processador do registrador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) para obter mais detalhes.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IRegistrar:: ResourceRegisterSz](#resourceregistersz)|Registra o recurso. |
|[IRegistrar:: ResourceUnregisterSz](#resourceunregistersz)| Cancela o registro do recurso.|
|[IRegistrar:: FileRegister](#fileregister)|Registra o arquivo.|
|[IRegistrar:: FileUnregister](#fileunregister)|Cancela o registro do arquivo.|
|[IRegistrar:: StringRegister](#stringregister)|Registra a cadeia de caracteres.|
|[IRegistrar:: StringUnregister](#stringunregister)|Cancela o registro da cadeia de caracteres|
|[IRegistrar:: ResourceRegister](#resourceregister)|Registra o recurso.|
|[IRegistrar:: ResourceUnregister](#resourceunregister)|Cancela o registro do recurso.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlifase. h

##  <a name="resourceregistersz"></a>IRegistrar:: ResourceRegisterSz

Registra o recurso.

```
virtual HRESULT STDMETHODCALLTYPE ResourceRegisterSz(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_z_ LPCOLESTR szID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

##  <a name="resourceunregistersz"></a>IRegistrar:: ResourceUnregisterSz

Cancela o registro do recurso.

```
virtual HRESULT STDMETHODCALLTYPE ResourceUnregisterSz(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_z_ LPCOLESTR szID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

##  <a name="fileregister"></a>IRegistrar:: FileRegister

Registra o arquivo.

```
virtual HRESULT STDMETHODCALLTYPE FileRegister(
    /* [in] */ _In_z_ LPCOLESTR fileName) = 0;
```

##  <a name="fileunregister"></a>IRegistrar:: FileUnregister

Cancela o registro do arquivo.

```
virtual HRESULT STDMETHODCALLTYPE FileUnregister(
    /* [in] */ _In_z_ LPCOLESTR fileName) = 0;
```

##  <a name="stringregister"></a>IRegistrar:: StringRegister

Registra os dados de cadeia de caracteres especificados.

```
virtual HRESULT STDMETHODCALLTYPE StringRegister(
    /* [in] */ _In_z_ LPCOLESTR data) = 0;
```

##  <a name="stringunregister"></a>IRegistrar:: StringUnregister

Cancela o registro dos dados de cadeia de caracteres especificados.

```
virtualHRESULT STDMETHODCALLTYPE StringUnregister(
    /* [in] */ _In_z_ LPCOLESTR data) = 0;
```

##  <a name="resourceregister"></a>IRegistrar:: ResourceRegister

Registra o recurso.

```
virtual HRESULT STDMETHODCALLTYPE ResourceRegister(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_ UINT nID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

##  <a name="resourceunregister"></a>IRegistrar:: ResourceUnregister

Cancela o registro do recurso.

```
virtualHRESULT STDMETHODCALLTYPE ResourceUnregister(
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_ UINT nID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```

## <a name="see-also"></a>Consulte também

[Usando parâmetros substituíveis (pré-processador do Registrador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)<br/>
[Componente de Registro (Registrador)](../../atl/atl-registry-component-registrar.md)
