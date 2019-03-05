---
title: Classes de modelo do documento
ms.date: 11/04/2016
f1_keywords:
- vc.classes.document
helpviewer_keywords:
- document templates [MFC], classes
ms.assetid: 901749e9-8048-44a0-b5e2-361554650a73
ms.openlocfilehash: 2589bc8f04e791f73529af91ffb148c2c717cd08
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57294571"
---
# <a name="document-template-classes"></a>Classes de modelo do documento

Objetos de modelo de documento coordenam a criação de documento, exibição e objetos de janela de quadro quando um novo documento ou exibição é criada.

[CDocTemplate](../mfc/reference/cdoctemplate-class.md)<br/>
A classe base para modelos de documento. Você nunca usará essa classe diretamente. em vez disso, use uma das outras classes de modelo de documento que deriva dessa classe.

[CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md)<br/>
Um modelo para documentos em que a interface de documentos múltiplos (MDI). Aplicativos MDI podem ter vários documentos aberta ao mesmo tempo.

[CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md)<br/>
Um modelo para documentos na interface de documento único (SDI). Aplicativos SDI tem apenas um documento aberto por vez.

## <a name="related-class"></a>Classe relacionada

[CCreateContext](../mfc/reference/ccreatecontext-structure.md)<br/>
Uma estrutura é passado por um modelo de documento para as funções de criação da janela para coordenar a criação de objetos de documento, a exibição e a janela do quadro.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
