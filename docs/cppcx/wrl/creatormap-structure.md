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
ms.openlocfilehash: 1527f81694d1d809d585f3f6504c0e6433a2c26b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372610"
---
# <a name="creatormap-structure"></a>Estrutura CreatorMap

Suporta a infra-estrutura da Biblioteca de Modelos C++ do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct CreatorMap;
```

## <a name="remarks"></a>Comentários

Contém informações sobre como inicializar, registrar e não registrar objetos.

`CreatorMap` contém as seguintes informações:

- Como inicializar, registrar e descadastrar objetos.

- Como comparar dados de ativação dependendo de uma fábrica clássica de COM ou Windows Runtime.

- Informações sobre o cache de fábrica e o nome do servidor para uma interface.

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                                          | Descrição
--------------------------------------------- | ------------------------------------------------------------------------------------------------------
[CriadorMap::ativaçãoId](#activationid)     | Representa um ID de objeto que é identificado por um ID clássico da classe COM ou por um nome de tempo de execução do Windows.
[CriadorMap::cache de fábrica](#factorycache)     | Armazena o ponteiro para o `CreatorMap`cache da fábrica para o .
[CriadorMap::factoryCreator](#factorycreator) | Cria uma fábrica para `CreatorMap`o especificado .
[CriadorMap::servidorNome](#servername)         | Armazena o nome `CreatorMap`do servidor para o .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CreatorMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="creatormapactivationid"></a><a name="activationid"></a>CriadorMap::ativaçãoId

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
union {
   const IID* clsid;
   const wchar_t* (*getRuntimeName)();
} activationId;
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Um ID de interface.

*getRuntimeName*<br/>
Uma função que recupera o nome de tempo de execução do Windows de um objeto.

### <a name="remarks"></a>Comentários

Representa um ID de objeto que é identificado por um ID clássico da classe COM ou por um nome de tempo de execução do Windows.

## <a name="creatormapfactorycache"></a><a name="factorycache"></a>CriadorMap::cache de fábrica

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
FactoryCache* factoryCache;
```

### <a name="remarks"></a>Comentários

Armazena o ponteiro para o `CreatorMap`cache da fábrica para o .

## <a name="creatormapfactorycreator"></a><a name="factorycreator"></a>CriadorMap::factoryCreator

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
HRESULT (*factoryCreator)(
   unsigned int* currentflags,
   const CreatorMap* entry,
   REFIID iidClassFactory,
IUnknown** factory);
```

### <a name="parameters"></a>Parâmetros

*bandeiras atuais*<br/>
Um dos enumeradores [RuntimeClassType.](runtimeclasstype-enumeration.md)

*Entrada*<br/>
Um Mapa dos Criadores.

*iidClassFactory*<br/>
O ID de interface de uma fábrica de classe.

*fábrica*<br/>
Quando a operação for concluída, o endereço de uma fábrica de classe.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Cria uma fábrica para o CreatorMap especificado.

## <a name="creatormapservername"></a><a name="servername"></a>CriadorMap::servidorNome

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
const wchar_t* serverName;
```

### <a name="remarks"></a>Comentários

Armazena o nome do servidor para o CriadorMap.
