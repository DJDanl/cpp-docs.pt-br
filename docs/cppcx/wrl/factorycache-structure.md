---
title: Estrutura FactoryCache
ms.date: 09/21/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::FactoryCache
- module/Microsoft::WRL::Details::FactoryCache::cookie
- module/Microsoft::WRL::Details::FactoryCache::factory
helpviewer_keywords:
- Microsoft::WRL::Details::FactoryCache structure
- Microsoft::WRL::Details::FactoryCache::cookie data member
- Microsoft::WRL::Details::FactoryCache::factory data member
ms.assetid: 624544e6-0989-47f6-a3e9-edb60e1ee6d4
ms.openlocfilehash: 507d35179b9fa86399e56b18171800f41eaf1f10
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371485"
---
# <a name="factorycache-structure"></a>Estrutura FactoryCache

Suporta a infra-estrutura da Biblioteca de Modelos C++ do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct FactoryCache;
```

## <a name="remarks"></a>Comentários

Contém a localização de uma fábrica de classe e um valor que identifica um objeto de classe WRT ou COM registrado.

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                              | Descrição
--------------------------------- | ------------------------------------------------------------------------------------------------------------------------------
[Cache de fábrica::cookie](#cookie)   | Contém um valor que identifica um objeto de classe Com ou Runtime do Windows registrado e é usado posteriormente para cancelar o registro do objeto.
[Cache de fábrica::fábrica](#factory) | Aponta para uma fábrica de classe Com ou Com do Windows Runtime.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FactoryCache`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="factorycachecookie"></a><a name="cookie"></a>Cache de fábrica::cookie

Suporta a infra-estrutura da Biblioteca de Modelos C++ do Windows e não se destina a ser usado diretamente do seu código.

```cpp
union {
   WINRT_REGISTRATION_COOKIE winrt;
   DWORD com;
} cookie;
```

### <a name="remarks"></a>Comentários

Contém um valor que identifica um objeto de classe Com ou Runtime do Windows registrado e é usado posteriormente para cancelar o registro do objeto.

## <a name="factorycachefactory"></a><a name="factory"></a>Cache de fábrica::fábrica

Suporta a infra-estrutura da Biblioteca de Modelos C++ do Windows e não se destina a ser usado diretamente do seu código.

```cpp
IUnknown* factory;
```

### <a name="remarks"></a>Comentários

Aponta para uma fábrica de classe Com ou Com do Windows Runtime.
