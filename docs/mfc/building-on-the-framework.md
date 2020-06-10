---
title: Compilando no Framework
ms.date: 11/04/2016
helpviewer_keywords:
- application-specific classes [MFC]
- application framework [MFC], building applications
- applications [MFC]
- MFC, application development
ms.assetid: 883f0f19-866f-4221-8a3d-5607941dc8d0
ms.openlocfilehash: 2c171b223892c8bca1b32e18c57c09027558c192
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619726"
---
# <a name="building-on-the-framework"></a>Compilando no Framework

Sua função na configuração de um aplicativo com o MFC Framework é fornecer o código-fonte específico do aplicativo e conectar os componentes definindo quais mensagens e comandos eles respondem. Você usa a linguagem C++ e as técnicas C++ padrão para derivar suas próprias classes específicas de aplicativo daquelas fornecidas pela biblioteca de classes e para substituir e aumentar o comportamento da classe base.

Nos tópicos relacionados, as tabelas a seguir descrevem a sequência geral das operações que você normalmente seguirá e suas responsabilidades em comparação com as responsabilidades da estrutura:

- [Sequência para criar um aplicativo com a estrutura](sequence-of-operations-for-building-mfc-applications.md)

- [Sequência de operações para a criação de aplicativos OLE](sequence-of-operations-for-creating-ole-applications.md)

- [Sequência de operações para criação de controles ActiveX](sequence-of-operations-for-creating-activex-controls.md)

- [Sequência de operações para criação de aplicativos de banco de dados](sequence-of-operations-for-creating-database-applications.md)

Para a maior parte, você pode seguir essas tabelas como uma sequência de etapas para criar um aplicativo MFC, embora algumas das etapas sejam opções alternativas. Por exemplo, a maioria dos aplicativos usa um tipo de classe de exibição dos vários tipos disponíveis.

## <a name="see-also"></a>Consulte também

[Tópicos MFC gerais](general-mfc-topics.md)
