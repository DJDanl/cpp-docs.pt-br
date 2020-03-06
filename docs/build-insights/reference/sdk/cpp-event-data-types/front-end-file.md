---
title: Classe FrontEndfile
description: A C++ referência da classe de frontfile do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FrontEndFile
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 094b1326765e0e8edb00534ecb3d94c46702d4ec
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333282"
---
# <a name="frontendfile-class"></a>Classe FrontEndfile

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `FrontEndFile` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [FRONT_END_FILE](../event-table.md#front-end-file) .

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

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a classe `FrontEndFile` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[FrontEndfile](#front-end-file)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Path](#path)

## <a name="front-end-file"></a>FrontEndfile

```cpp
FrontEndFile(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [FRONT_END_FILE](../event-table.md#front-end-file) .

## <a name="path"></a> Path

```cpp
const char* Path() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo, codificado em UTF-8.

::: moniker-end
