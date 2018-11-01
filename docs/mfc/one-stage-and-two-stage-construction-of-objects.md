---
title: Construção de objetos em um e dois estágios
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], creating graphic objects
- object creation [MFC], graphic objects
- objects [MFC], graphic objects
- one-stage and two-stage construction of objects [MFC]
ms.assetid: 5a1c410c-4a4b-4dd9-a2ec-ced831aa7f21
ms.openlocfilehash: bdfb7879bc926435bdcd72d6776646c449ffef80
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50623308"
---
# <a name="one-stage-and-two-stage-construction-of-objects"></a>Construção de objetos em um e dois estágios

Você pode escolher entre duas técnicas para criar objetos gráficos, como canetas e pincéis:

- *Construção de um estágio*: construção e inicializar o objeto em um estágio, tudo isso com o construtor.

- *Construção de dois estágios*: construção e inicializar o objeto em duas fases separadas. O construtor cria o objeto e inicializa-o uma função de inicialização.

Construção de dois estágios sempre é mais segura. Na construção de um estágio, o construtor pode lançar uma exceção se você fornecer argumentos incorretos ou falha de alocação de memória. Esse problema é evitado com a construção de dois estágios, embora seja necessário que verificar se há falha. Em ambos os casos, destruir o objeto é o mesmo processo.

> [!NOTE]
>  Essas técnicas se aplicam à criação de quaisquer objetos, os objetos gráficos não apenas.

## <a name="example-of-both-construction-techniques"></a>Exemplo de ambas as técnicas de construção

O exemplo a seguir breve mostra ambos os métodos de construção de um objeto pen:

[!code-cpp[NVC_MFCDocViewSDI#6](../mfc/codesnippet/cpp/one-stage-and-two-stage-construction-of-objects_1.cpp)]

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Objetos gráficos](../mfc/graphic-objects.md)

- [Selecionando um objeto gráfico em um contexto de dispositivo](../mfc/selecting-a-graphic-object-into-a-device-context.md)

- [Contextos de dispositivo](../mfc/device-contexts.md)

- [Desenhando em uma exibição](../mfc/drawing-in-a-view.md)

## <a name="see-also"></a>Consulte também

[Objetos gráficos](../mfc/graphic-objects.md)

