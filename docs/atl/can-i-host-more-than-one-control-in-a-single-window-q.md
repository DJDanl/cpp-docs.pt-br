---
title: "Eu hospedar mais de um controle em uma única janela? | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- controls [ATL], hosting multiple
- windows [C++], hosting multiple controls
ms.assetid: 3a967a1a-7e7e-42e3-8eed-f7bde912363f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: be87c0bad9ab250593847cc24d16158030040054
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="can-i-host-more-than-one-control-in-a-single-window"></a>Eu hospedar mais de um controle em uma única janela?
Não é possível hospedar mais de um controle em uma única janela host ATL. Cada janela do host foi projetada para manter o controle exatamente um por vez (Isso permite que um mecanismo simples para manipular propriedades ambiente por controle e reflexão de mensagem). No entanto, se você precisar que o usuário veja vários controles em uma única janela, é uma simples questão de criar várias janelas de host como filhos do que a janela.  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

