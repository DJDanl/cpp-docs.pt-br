---
title: Eu hospedar mais de um controle em uma única janela? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [ATL], hosting multiple
- windows [C++], hosting multiple controls
ms.assetid: 3a967a1a-7e7e-42e3-8eed-f7bde912363f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ceb9444b6371e261115bbf52ef5a249100772d1f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356418"
---
# <a name="can-i-host-more-than-one-control-in-a-single-window"></a>Eu hospedar mais de um controle em uma única janela?
Não é possível hospedar mais de um controle em uma única janela host ATL. Cada janela do host foi projetada para manter o controle exatamente um por vez (Isso permite que um mecanismo simples para manipular propriedades ambiente por controle e reflexão de mensagem). No entanto, se você precisar que o usuário veja vários controles em uma única janela, é uma simples questão de criar várias janelas de host como filhos do que a janela.  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

