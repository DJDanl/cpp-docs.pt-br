---
title: Macros de troca de dados do registro
ms.date: 11/04/2016
f1_keywords:
- atlplus/ATL::BEGIN_RDX_MAP
- atlplus/ATL::END_RDX_MAP
- atlplus/ATL::RDX_BINARY
- atlplus/ATL::RDX_CSTRING_TEXT
- atlplus/ATL::RDX_DWORD
- atlplus/ATL::RDX_TEXT
helpviewer_keywords:
- RegistryDataExchange function, macros
ms.assetid: c1bc5e79-2307-43d2-9d10-3a62ffadf473
ms.openlocfilehash: 507db77b525c526fe1cd47c7d75c34e15a6a0628
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834538"
---
# <a name="registry-data-exchange-macros"></a>Macros de troca de dados do registro

Essas macros executam operações de troca de dados de registro.

|Nome|Descrição|
|-|-|
|[BEGIN_RDX_MAP](#begin_rdx_map)|Marca o início do mapa de troca de dados do registro.|
|[END_RDX_MAP](#end_rdx_map)|Marca o final do mapa de troca de dados do registro.|
|[RDX_BINARY](#rdx_binary)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo BYTE.|
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo CString.|
|[RDX_DWORD](#rdx_dword)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo DWORD.|
|[RDX_TEXT](#rdx_text)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo TCHAR.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlplus. h

## <a name="begin_rdx_map"></a><a name="begin_rdx_map"></a> BEGIN_RDX_MAP

Marca o início do mapa de troca de dados do registro.

```
BEGIN_RDX_MAP
```

### <a name="remarks"></a>Comentários

As macros a seguir são usadas no mapa de troca de dados do registro para ler e gravar entradas no registro do sistema:

|Macro|Descrição|
|-----------|-----------------|
|[RDX_BINARY](#rdx_binary)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo BYTE.|
|[RDX_DWORD](#rdx_dword)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo DWORD.|
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo CString.|
|[RDX_TEXT](#rdx_text)|Associa a entrada de registro especificada a uma variável de membro especificada do tipo TCHAR.|

A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada sempre que seu código precisar trocar dados entre o registro do sistema e as variáveis especificadas no mapa RDX.

## <a name="end_rdx_map"></a><a name="end_rdx_map"></a> END_RDX_MAP

Marca o final do mapa de troca de dados do registro.

```
END_RDX_MAP
```

## <a name="rdx_binary"></a><a name="rdx_binary"></a> RDX_BINARY

Associa a entrada de registro especificada a uma variável de membro especificada do tipo BYTE.

```
RDX_BINARY(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>parâmetros

*ROOTKEY*<br/>
A raiz da chave do registro.

*chave*<br/>
A subchave do registro.

*valueName*<br/>
A chave do registro.

*associado*<br/>
A variável de membro a ser associada à entrada do Registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável de membro.

### <a name="remarks"></a>Comentários

Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro a uma determinada entrada do registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para executar o intercâmbio de dados entre o registro do sistema e as variáveis de membro no mapa RDX.

## <a name="rdx_cstring_text"></a><a name="rdx_cstring_text"></a> RDX_CSTRING_TEXT

Associa a entrada de registro especificada a uma variável de membro especificada do tipo CString.

```
RDX_CSTRING_TEXT(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>parâmetros

*ROOTKEY*<br/>
A raiz da chave do registro.

*chave*<br/>
A subchave do registro.

*valueName*<br/>
A chave do registro.

*associado*<br/>
A variável de membro a ser associada à entrada do Registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável de membro.

### <a name="remarks"></a>Comentários

Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro a uma determinada entrada do registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para executar o intercâmbio de dados entre o registro do sistema e as variáveis de membro no mapa RDX.

## <a name="rdx_dword"></a><a name="rdx_dword"></a> RDX_DWORD

Associa a entrada de registro especificada a uma variável de membro especificada do tipo DWORD.

```
RDX_DWORD(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>parâmetros

*ROOTKEY*<br/>
A raiz da chave do registro.

*chave*<br/>
A subchave do registro.

*valueName*<br/>
A chave do registro.

*associado*<br/>
A variável de membro a ser associada à entrada do Registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável de membro.

### <a name="remarks"></a>Comentários

Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro a uma determinada entrada do registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para executar o intercâmbio de dados entre o registro do sistema e as variáveis de membro no mapa RDX.

## <a name="rdx_text"></a><a name="rdx_text"></a> RDX_TEXT

Associa a entrada de registro especificada a uma variável de membro especificada do tipo TCHAR.

```
RDX_TEXT(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>parâmetros

*ROOTKEY*<br/>
A raiz da chave do registro.

*chave*<br/>
A subchave do registro.

*valueName*<br/>
A chave do registro.

*associado*<br/>
A variável de membro a ser associada à entrada do Registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável de membro.

### <a name="remarks"></a>Comentários

Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro a uma determinada entrada do registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para executar o intercâmbio de dados entre o registro do sistema e as variáveis de membro no mapa RDX.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange)
