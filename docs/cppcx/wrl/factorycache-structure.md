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
ms.openlocfilehash: 7196363567dffa43844bbbd1de76934a317302d1
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58783907"
---
# <a name="factorycache-structure"></a>Estrutura FactoryCache

Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct FactoryCache;
```

## <a name="remarks"></a>Comentários

Contém o local de uma fábrica de classes e um valor que identifica um registrado wrt ou objeto de classe COM.

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                              | Descrição
--------------------------------- | ------------------------------------------------------------------------------------------------------------------------------
[FactoryCache::cookie](#cookie)   | Contém um valor que identifica um objeto de classe de tempo de execução do Windows ou COM registrado e é usado posteriormente para cancelar o registro do objeto.
[FactoryCache::factory](#factory) | Aponta para uma fábrica de classes de tempo de execução do Windows ou COM.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FactoryCache`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL::Details

## <a name="cookie"></a>FactoryCache::cookie

Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.

```cpp
union {
   WINRT_REGISTRATION_COOKIE winrt;
   DWORD com;
} cookie;
```

### <a name="remarks"></a>Comentários

Contém um valor que identifica um objeto de classe de tempo de execução do Windows ou COM registrado e é usado posteriormente para cancelar o registro do objeto.

## <a name="factory"></a>FactoryCache::factory

Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.

```cpp
IUnknown* factory;
```

### <a name="remarks"></a>Comentários

Aponta para uma fábrica de classes de tempo de execução do Windows ou COM.
