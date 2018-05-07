---
title: Classes de modelo de documento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.document
dev_langs:
- C++
helpviewer_keywords:
- document templates [MFC], classes
ms.assetid: 901749e9-8048-44a0-b5e2-361554650a73
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d9958484633dd736426fc91321d0964abf0ad7e1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="document-template-classes"></a>Classes de modelo do documento
Objetos de modelo de documento coordenam a criação de documento, exibição e objetos de janela do quadro quando um novo documento ou exibição é criada.  
  
 [CDocTemplate](../mfc/reference/cdoctemplate-class.md)  
 A classe base para modelos de documento. Você nunca usará essa classe diretamente. em vez disso, use uma das outras classes de modelo de documento derivadas dessa classe.  
  
 [CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md)  
 Um modelo para documentos de interface de documentos múltiplos (MDI). Aplicativos MDI podem ter vários documentos aberta ao mesmo tempo.  
  
 [CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md)  
 Um modelo para documentos na interface de documento único (SDI). Aplicativos SDI tem apenas um documento aberto por vez.  
  
## <a name="related-class"></a>Classe relacionada  
 [CCreateContext](../mfc/reference/ccreatecontext-structure.md)  
 Uma estrutura são passados por um modelo de documento para as funções de criação de janela para coordenar a criação de objetos de documento, a exibição e a janela do quadro.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

