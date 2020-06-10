---
title: Classes de modelo do documento
ms.date: 11/04/2016
helpviewer_keywords:
- document templates [MFC], classes
ms.assetid: 901749e9-8048-44a0-b5e2-361554650a73
ms.openlocfilehash: dffde80093f98fc1c81a6c20dfaf92b82e3b4c78
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618993"
---
# <a name="document-template-classes"></a>Classes de modelo do documento

Objetos de modelo de documento coordenam a criação de documentos, exibição e objetos de janela de quadro quando um novo documento ou uma nova exibição é criada.

[CDocTemplate](reference/cdoctemplate-class.md)<br/>
A classe base para modelos de documento. Você nunca usará essa classe diretamente; em vez disso, você usa uma das outras classes de modelo de documento derivadas desta classe.

[CMultiDocTemplate](reference/cmultidoctemplate-class.md)<br/>
Um modelo para documentos na interface de vários documentos (MDI). Os aplicativos MDI podem ter vários documentos abertos por vez.

[CSingleDocTemplate](reference/csingledoctemplate-class.md)<br/>
Um modelo para documentos na interface de documento único (SDI). Os aplicativos SDI têm apenas um documento aberto por vez.

## <a name="related-class"></a>Classe relacionada

[CCreateContext](reference/ccreatecontext-structure.md)<br/>
Uma estrutura passada por um modelo de documento para funções de criação de janela para coordenar a criação de objetos de documento, exibição e janela de quadro.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
