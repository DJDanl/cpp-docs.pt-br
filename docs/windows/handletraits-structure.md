---
title: Estrutura HANDLETraits | Microsoft Docs
ms.custom: ''
ms.date: 09/27/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::Close
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::GetInvalidValue
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits structure
- Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::Close method
- Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::GetInvalidValue method
ms.assetid: 22963e88-d857-4624-9182-7c986daff722
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 33181b2cf477c3f753eacf63110a426b36e62b31
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48235263"
---
# <a name="handletraits-structure"></a>Estrutura HANDLETraits

Define as características comuns de um identificador.

## <a name="syntax"></a>Sintaxe

```cpp
struct HANDLETraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ---------------------
`Type` | Um sinônimo de identificador.

### <a name="public-methods"></a>Métodos públicos

Nome                                              | Descrição
------------------------------------------------- | -----------------------------
[Handletraits:: Close](#close)                     | Fecha o identificador especificado.
[Handletraits:: Getinvalidvalue](#getinvalidvalue) | Representa um identificador inválido.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLETraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="close"></a>Handletraits:: Close

Fecha o identificador especificado.

```cpp
inline static bool Close(
   _In_ Type h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
O identificador para fechar.

### <a name="return-value"></a>Valor de retorno

`true` Se manipular *h* fechado com êxito; caso contrário, `false`.

## <a name="getinvalidvalue"></a>Handletraits:: Getinvalidvalue

Representa um identificador inválido.

```cpp
inline static HANDLE GetInvalidValue();
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna INVALID_HANDLE_VALUE. (INVALID_HANDLE_VALUE é definido pelo Windows).
