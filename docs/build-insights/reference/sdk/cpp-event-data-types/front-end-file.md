---
title: Classe FrontEndFile
description: A referência da classe C++ Build Insights SDK FrontEndFile.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FrontEndFile
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c40137724279ea2fd615729db39f0ac5c907b79e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324751"
---
# <a name="frontendfile-class"></a>Classe FrontEndFile

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `FrontEndFile` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [FRONT_END_FILE.](../event-table.md#front-end-file)

## <a name="syntax"></a>Sintaxe

```cpp
class FrontEndFile : public Activity
{
public:
    FrontEndFile(const RawEvent& event);

    const char* Path() const;
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `FrontEndFile` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[FrontEndFile](#front-end-file)

### <a name="functions"></a>Funções

[Caminho](#path)

## <a name="frontendfile"></a><a name="front-end-file"></a>FrontEndFile

```cpp
FrontEndFile(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [FRONT_END_FILE.](../event-table.md#front-end-file)

## <a name="path"></a><a name="path"></a>Caminho

```cpp
const char* Path() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo, codificado em UTF-8.

::: moniker-end
