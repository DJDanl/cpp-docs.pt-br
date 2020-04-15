---
title: Macros de troca de dados de registro
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
ms.openlocfilehash: a7d580e4907cec40f97c0cead616665fff7b8a01
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326063"
---
# <a name="registry-data-exchange-macros"></a>Macros de troca de dados de registro

Essas macros executam operações de Troca de Dados de Registro.

|||
|-|-|
|[Begin_rdx_map](#begin_rdx_map)|Marca o início do mapa de Troca de Dados de Registro.|
|[End_rdx_map](#end_rdx_map)|Marca o fim do mapa de Troca de Dados de Registro.|
|[RDX_BINARY](#rdx_binary)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo BYTE.|
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo CString.|
|[RDX_DWORD](#rdx_dword)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo DWORD.|
|[RDX_TEXT](#rdx_text)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo TCHAR.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlplus.h

## <a name="begin_rdx_map"></a><a name="begin_rdx_map"></a>Begin_rdx_map

Marca o início do mapa de Troca de Dados de Registro.

```
BEGIN_RDX_MAP
```

### <a name="remarks"></a>Comentários

As seguintes macros são usadas no mapa Registry Data Exchange para ler e gravar entradas no registro do sistema:

|Macro|Descrição|
|-----------|-----------------|
|[RDX_BINARY](#rdx_binary)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo BYTE.|
|[RDX_DWORD](#rdx_dword)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo DWORD.|
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo CString.|
|[RDX_TEXT](#rdx_text)|Associa a entrada de registro especificada com uma variável de membro especificada do tipo TCHAR.|

A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função membro de mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada sempre que seu código precisar trocar dados entre o registro do sistema e as variáveis especificadas no mapa RDX.

## <a name="end_rdx_map"></a><a name="end_rdx_map"></a>End_rdx_map

Marca o fim do mapa de Troca de Dados de Registro.

```
END_RDX_MAP
```

## <a name="rdx_binary"></a><a name="rdx_binary"></a>RDX_BINARY

Associa a entrada de registro especificada com uma variável de membro especificada do tipo BYTE.

```
RDX_BINARY(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>Parâmetros

*rootkey*<br/>
A raiz da chave do registro.

*Subchave*<br/>
A subchave do registro.

*Valuename*<br/>
A chave do registro.

*Membro*<br/>
A variável membro para associar-se com a entrada de registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável membro.

### <a name="remarks"></a>Comentários

Esta macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro com uma determinada entrada de registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função membro de mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para realizar a troca de dados entre o registro do sistema e as variáveis membros no mapa RDX.

## <a name="rdx_cstring_text"></a><a name="rdx_cstring_text"></a>RDX_CSTRING_TEXT

Associa a entrada de registro especificada com uma variável de membro especificada do tipo CString.

```
RDX_CSTRING_TEXT(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>Parâmetros

*rootkey*<br/>
A raiz da chave do registro.

*Subchave*<br/>
A subchave do registro.

*Valuename*<br/>
A chave do registro.

*Membro*<br/>
A variável membro para associar-se com a entrada de registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável membro.

### <a name="remarks"></a>Comentários

Esta macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro com uma determinada entrada de registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função membro de mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para realizar a troca de dados entre o registro do sistema e as variáveis membros no mapa RDX.

## <a name="rdx_dword"></a><a name="rdx_dword"></a>RDX_DWORD

Associa a entrada de registro especificada com uma variável de membro especificada do tipo DWORD.

```
RDX_DWORD(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>Parâmetros

*rootkey*<br/>
A raiz da chave do registro.

*Subchave*<br/>
A subchave do registro.

*Valuename*<br/>
A chave do registro.

*Membro*<br/>
A variável membro para associar-se com a entrada de registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável membro.

### <a name="remarks"></a>Comentários

Esta macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro com uma determinada entrada de registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função membro de mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para realizar a troca de dados entre o registro do sistema e as variáveis membros no mapa RDX.

## <a name="rdx_text"></a><a name="rdx_text"></a>RDX_TEXT

Associa a entrada de registro especificada com uma variável de membro especificada do tipo TCHAR.

```
RDX_TEXT(
    rootkey,
    subkey,
    valuename,
    member,
    member_size )
```

### <a name="parameters"></a>Parâmetros

*rootkey*<br/>
A raiz da chave do registro.

*Subchave*<br/>
A subchave do registro.

*Valuename*<br/>
A chave do registro.

*Membro*<br/>
A variável membro para associar-se com a entrada de registro especificada.

*member_size*<br/>
O tamanho, em bytes, da variável membro.

### <a name="remarks"></a>Comentários

Esta macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro com uma determinada entrada de registro. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função membro de mesmo nome criada pelas macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usada para realizar a troca de dados entre o registro do sistema e as variáveis membros no mapa RDX.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange)
