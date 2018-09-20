---
title: Compilando no Framework | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- application-specific classes [MFC]
- application framework [MFC], building applications
- applications [MFC]
- MFC, application development
ms.assetid: 883f0f19-866f-4221-8a3d-5607941dc8d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4ca0ebd9bf03df8725c14df8d2aca1f7858b7b65
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396175"
---
# <a name="building-on-the-framework"></a>Compilando no Framework

Sua função na configuração de um aplicativo com a estrutura MFC é fornecer o código-fonte do aplicativo específico e para conectar os componentes definindo quais mensagens e comandos aos quais eles respondem. Use a linguagem C++ e as técnicas padrão do C++ para derivar suas próprias classes específicas do aplicativo daqueles fornecidos pela biblioteca de classes e para substituir e ampliar o comportamento da classe base.

Em tópicos relacionados, as tabelas a seguir descrevem a sequência geral de operações que você normalmente seguirá e suas responsabilidades versus responsabilidades da estrutura:

- [Sequência para a criação de um aplicativo com o Framework](../mfc/sequence-of-operations-for-building-mfc-applications.md)

- [Sequência de operações para a criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)

- [Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)

- [Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)

Geralmente, você pode seguir essas tabelas como uma sequência de etapas para criar um aplicativo MFC, embora algumas das etapas são opções alternativas. Por exemplo, a maioria dos aplicativos usar um tipo de classe de exibição de vários tipos disponíveis.

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

