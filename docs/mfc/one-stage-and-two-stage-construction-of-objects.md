---
title: Construção de objetos em um e dois estágios
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], creating graphic objects
- object creation [MFC], graphic objects
- objects [MFC], graphic objects
- one-stage and two-stage construction of objects [MFC]
ms.assetid: 5a1c410c-4a4b-4dd9-a2ec-ced831aa7f21
ms.openlocfilehash: 07e006d5b326486c54f23990c604a7d2ee0e4c83
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625282"
---
# <a name="one-stage-and-two-stage-construction-of-objects"></a>Construção de objetos em um e dois estágios

Você tem uma opção entre duas técnicas para criar objetos gráficos, como canetas e pincéis:

- *Construção de um estágio*: Construa e inicialize o objeto em um estágio, tudo com o construtor.

- *Construção de dois*estágios: Construa e inicialize o objeto em dois estágios separados. O construtor cria o objeto e uma função de inicialização o inicializa.

A construção de dois estágios é sempre mais segura. Na construção de um estágio, o construtor pode lançar uma exceção se você fornecer argumentos incorretos ou a alocação de memória falhar. Esse problema é evitado pela construção de dois estágios, embora você precise verificar se há falhas. Em ambos os casos, destruir o objeto é o mesmo processo.

> [!NOTE]
> Essas técnicas se aplicam à criação de qualquer objeto, não apenas a objetos gráficos.

## <a name="example-of-both-construction-techniques"></a>Exemplo de ambas as técnicas de construção

O seguinte exemplo breve mostra os dois métodos de construção de um objeto Pen:

[!code-cpp[NVC_MFCDocViewSDI#6](codesnippet/cpp/one-stage-and-two-stage-construction-of-objects_1.cpp)]

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Objetos gráficos](graphic-objects.md)

- [Selecionando um objeto gráfico em um contexto de dispositivo](selecting-a-graphic-object-into-a-device-context.md)

- [Contextos de dispositivo](device-contexts.md)

- [Desenhando em uma exibição](drawing-in-a-view.md)

## <a name="see-also"></a>Consulte também

[Objetos gráficos](graphic-objects.md)
