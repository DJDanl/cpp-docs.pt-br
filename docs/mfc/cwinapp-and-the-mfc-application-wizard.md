---
title: CWinApp e o Assistente de Aplicativo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- application wizards [MFC], and CWinApp
- CWinApp class [MFC], and MFC Application Wizard
- MFC, wizards
ms.assetid: f8ac0491-3302-4e46-981d-0790624eb8a2
ms.openlocfilehash: f57b3b2b37a97093aa6d81b59a12c8cf023e3157
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622935"
---
# <a name="cwinapp-and-the-mfc-application-wizard"></a>CWinApp e o Assistente de Aplicativo MFC

Quando ele cria um aplicativo de esqueleto, o assistente de aplicativo MFC declara uma classe de aplicativo derivada de [CWinApp](reference/cwinapp-class.md). O assistente de aplicativo do MFC também gera um arquivo de implementação que contém os seguintes itens:

- Um mapa de mensagens para a classe de aplicativo.

- Um construtor de classe vazio.

- Uma variável que declara o único objeto e somente da classe.

- Uma implementação padrão de sua `InitInstance` função de membro.

A classe Application é colocada no cabeçalho do projeto e nos arquivos de origem principais. Os nomes da classe e dos arquivos criados são baseados no nome do projeto que você fornecer no assistente de aplicativo do MFC. A maneira mais fácil de exibir o código para essas classes é por meio de [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code).

As implementações padrão e o mapa de mensagens fornecidos são adequados para muitas finalidades, mas você pode modificá-las conforme necessário. O mais interessante dessas implementações é a `InitInstance` função membro. Normalmente, você adicionará código à implementação de esqueleto do `InitInstance` .

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](cwinapp-the-application-class.md)<br/>
[Funções de membro CWinApp substituíveis](overridable-cwinapp-member-functions.md)<br/>
[Serviços CWinApp especiais](special-cwinapp-services.md)
