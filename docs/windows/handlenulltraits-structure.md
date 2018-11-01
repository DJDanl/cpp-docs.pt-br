---
title: Estrutura HANDLENullTraits
ms.date: 09/27/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::Close
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::GetInvalidValue
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::Close method
- Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::GetInvalidValue method
ms.assetid: 88a29a14-c516-40cb-a0ca-ee897a668623
ms.openlocfilehash: d70425f414b998eb67e3937c2c126dd3eda0c00d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50571360"
---
# <a name="handlenulltraits-structure"></a>Estrutura HANDLENullTraits

Define as características comuns de um identificador não inicializado.

## <a name="syntax"></a>Sintaxe

```cpp
struct HANDLENullTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ---------------------
`Type` | Um sinônimo de identificador.

### <a name="public-methods"></a>Métodos públicos

Nome                                                  | Descrição
----------------------------------------------------- | -----------------------------
[Handlenulltraits:: Close](#close)                     | Fecha o identificador especificado.
[Handlenulltraits:: Getinvalidvalue](#getinvalidvalue) | Representa um identificador inválido.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLENullTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="close"></a>Handlenulltraits:: Close

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

**Verdadeiro** se tratar *h* fechado com êxito; caso contrário, **false**.

## <a name="getinvalidvalue"></a>Handlenulltraits:: Getinvalidvalue

Representa um identificador inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna `nullptr`.
