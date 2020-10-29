---
title: Classe FrontEndfile
description: A referência de classe de Frontfile do SDK do Application insights do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FrontEndFile
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7715a153df538eab94b8de5281a91d4f6b439ff9
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920652"
---
# <a name="frontendfile-class"></a>Classe FrontEndfile

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `FrontEndFile` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [FRONT_END_FILE](../event-table.md#front-end-file) .

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

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a `FrontEndFile` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[FrontEndFile](#front-end-file)

### <a name="functions"></a>Funções

[Caminho](#path)

## <a name="frontendfile"></a><a name="front-end-file"></a> FrontEndfile

```cpp
FrontEndFile(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [FRONT_END_FILE](../event-table.md#front-end-file) .

## <a name="path"></a><a name="path"></a> Path

```cpp
const char* Path() const;
```

### <a name="return-value"></a>Valor Retornado

O caminho absoluto para o arquivo, codificado em UTF-8.

::: moniker-end
