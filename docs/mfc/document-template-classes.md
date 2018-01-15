---
title: Classes de modelo de documento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.document
dev_langs: C++
helpviewer_keywords: document templates [MFC], classes
ms.assetid: 901749e9-8048-44a0-b5e2-361554650a73
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bbaccd12daf156d4a15f5cd18c31b5b230fe86db
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

