---
title: Classes de modelo do documento
ms.date: 11/04/2016
helpviewer_keywords:
- document templates [MFC], classes
ms.assetid: 901749e9-8048-44a0-b5e2-361554650a73
ms.openlocfilehash: 82b9ce4c242df7c85ada0722b2c1e993a0cf3f81
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446920"
---
# <a name="document-template-classes"></a>Classes de modelo do documento

Objetos de modelo de documento coordenam a criação de documentos, exibição e objetos de janela de quadro quando um novo documento ou uma nova exibição é criada.

[CDocTemplate](../mfc/reference/cdoctemplate-class.md)<br/>
A classe base para modelos de documento. Você nunca usará essa classe diretamente; em vez disso, você usa uma das outras classes de modelo de documento derivadas desta classe.

[CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md)<br/>
Um modelo para documentos na interface de vários documentos (MDI). Os aplicativos MDI podem ter vários documentos abertos por vez.

[CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md)<br/>
Um modelo para documentos na interface de documento único (SDI). Os aplicativos SDI têm apenas um documento aberto por vez.

## <a name="related-class"></a>Classe relacionada

[CCreateContext](../mfc/reference/ccreatecontext-structure.md)<br/>
Uma estrutura passada por um modelo de documento para funções de criação de janela para coordenar a criação de objetos de documento, exibição e janela de quadro.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
