---
title: Construção de objetos em um e dois estágios
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], creating graphic objects
- object creation [MFC], graphic objects
- objects [MFC], graphic objects
- one-stage and two-stage construction of objects [MFC]
ms.assetid: 5a1c410c-4a4b-4dd9-a2ec-ced831aa7f21
ms.openlocfilehash: 8f221ac6b63a06c65f932a695dfbf7b93ae7ac96
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375974"
---
# <a name="one-stage-and-two-stage-construction-of-objects"></a>Construção de objetos em um e dois estágios

Você tem uma escolha entre duas técnicas para criar objetos gráficos, como canetas e pincéis:

- *Construção em um estágio :* Construa e inicialize o objeto em um estágio, tudo com o construtor.

- *Construção em dois estágios*: Construa e inicialize o objeto em dois estágios separados. O construtor cria o objeto e uma função de inicialização o inicializa.

A construção em dois estágios é sempre mais segura. Na construção de um estágio, o construtor pode abrir uma exceção se você fornecer argumentos incorretos ou falha na alocação de memória. Esse problema é evitado pela construção em dois estágios, embora você tenha que verificar se há falha. Em ambos os casos, destruir o objeto é o mesmo processo.

> [!NOTE]
> Essas técnicas se aplicam à criação de quaisquer objetos, não apenas objetos gráficos.

## <a name="example-of-both-construction-techniques"></a>Exemplo de Ambas as Técnicas de Construção

O exemplo a seguir mostra ambos os métodos de construção de um objeto de caneta:

[!code-cpp[NVC_MFCDocViewSDI#6](../mfc/codesnippet/cpp/one-stage-and-two-stage-construction-of-objects_1.cpp)]

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Objetos gráficos](../mfc/graphic-objects.md)

- [Selecionando um objeto gráfico em um contexto de dispositivo](../mfc/selecting-a-graphic-object-into-a-device-context.md)

- [Contextos de dispositivo](../mfc/device-contexts.md)

- [Desenhando em uma exibição](../mfc/drawing-in-a-view.md)

## <a name="see-also"></a>Confira também

[Objetos gráficos](../mfc/graphic-objects.md)
