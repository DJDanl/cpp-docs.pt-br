---
title: Estrutura CreatorMap
ms.date: 09/21/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreatorMap
- implements/Microsoft::WRL::Details::CreatorMap
- module/Microsoft::WRL::Details::CreatorMap::activationId
- module/Microsoft::WRL::Details::CreatorMap::factoryCache
- module/Microsoft::WRL::Details::CreatorMap::factoryCreator
- module/Microsoft::WRL::Details::CreatorMap::serverName
helpviewer_keywords:
- Microsoft::WRL::Details::CreatorMap structure
- Microsoft::WRL::Details::CreatorMap::activationId data member
- Microsoft::WRL::Details::CreatorMap::factoryCache data member
- Microsoft::WRL::Details::CreatorMap::factoryCreator data member
- Microsoft::WRL::Details::CreatorMap::serverName data member
ms.assetid: 94e40927-90c3-4107-bca3-3ad2dc4beda9
ms.openlocfilehash: 98afce8096ee514fc8576bb80074b73acdd658e6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582436"
---
# <a name="creatormap-structure"></a>Estrutura CreatorMap

Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct CreatorMap;
```

## <a name="remarks"></a>Comentários

Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.

`CreatorMap` contém as seguintes informações:

- Como inicializar, registrar e cancelar o registro de objetos.

- Como comparar os dados de ativação, dependendo de uma fábrica COM ou tempo de execução do Windows clássico.

- Informações sobre o nome de cache e o servidor de fábrica para uma interface.

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                                          | Descrição
--------------------------------------------- | ------------------------------------------------------------------------------------------------------
[Creatormap:: Activationid](#activationid)     | Representa uma ID de objeto é identificada por uma ID de classe do COM clássico ou um nome de tempo de execução do Windows.
[Creatormap:: Factorycache](#factorycache)     | Armazena o ponteiro para o cache de fábrica para o `CreatorMap`.
[Creatormap:: Factorycreator](#factorycreator) | Cria uma fábrica para especificado `CreatorMap`.
[Creatormap:: servername](#servername)         | Armazena o nome do servidor para o `CreatorMap`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CreatorMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL::Details

## <a name="activationid"></a>Creatormap:: Activationid

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
union {
   const IID* clsid;
   const wchar_t* (*getRuntimeName)();
} activationId;
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Uma ID de interface.

*getRuntimeName*<br/>
Uma função que recupera o nome do tempo de execução do Windows de um objeto.

### <a name="remarks"></a>Comentários

Representa uma ID de objeto é identificada por uma ID de classe do COM clássico ou um nome de tempo de execução do Windows.

## <a name="factorycache"></a>Creatormap:: Factorycache

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
FactoryCache* factoryCache;
```

### <a name="remarks"></a>Comentários

Armazena o ponteiro para o cache de fábrica para o `CreatorMap`.

## <a name="factorycreator"></a>Creatormap:: Factorycreator

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
HRESULT (*factoryCreator)(
   unsigned int* currentflags,
   const CreatorMap* entry,
   REFIID iidClassFactory,
IUnknown** factory);
```

### <a name="parameters"></a>Parâmetros

*currentflags*<br/>
Um dos [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.

*entry*<br/>
Um CreatorMap.

*iidClassFactory*<br/>
A ID de interface de uma fábrica de classes.

*fábrica*<br/>
Quando a operação for concluída, o endereço de uma fábrica de classes.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Cria uma fábrica para o CreatorMap especificado.

## <a name="servername"></a>Creatormap:: servername

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
const wchar_t* serverName;
```

### <a name="remarks"></a>Comentários

Armazena o nome do servidor para o CreatorMap.
