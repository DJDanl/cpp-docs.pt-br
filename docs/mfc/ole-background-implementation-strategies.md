---
title: 'Tela de fundo OLE: estratégias de implementação'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE [MFC], development strategy
- OLE applications [MFC], implementing OLE
- applications [OLE], implementing OLE
ms.assetid: 0875ddae-99df-488c-82c6-164074a81058
ms.openlocfilehash: 90517f9b37872dd7de0ce1a2d08da94c93e6f8f8
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619898"
---
# <a name="ole-background-implementation-strategies"></a>Tela de fundo OLE: estratégias de implementação

Dependendo do seu aplicativo, há quatro estratégias de implementação possíveis para a adição de suporte a OLE:

- Você está escrevendo um novo aplicativo.

   Essa situação geralmente requer o mínimo de trabalho. Você executa o assistente de aplicativo do MFC e seleciona recursos avançados ou suporte a documentos compostos para criar um aplicativo de esqueleto. Para obter informações sobre essas opções e o que elas fazem, consulte o artigo [criando um programa exe do MFC](reference/mfc-application-wizard.md).

- Você tem um programa escrito com o biblioteca MFC versão 2,0 ou superior que não dá suporte a OLE.

   Crie um novo aplicativo com o assistente de aplicativo do MFC conforme mencionado anteriormente e, em seguida, copie e cole o código do novo aplicativo em seu aplicativo existente. Isso funcionará para servidores, contêineres ou aplicativos automatizados. Consulte o exemplo de [rabisco](../overview/visual-cpp-samples.md) do MFC para obter um exemplo dessa estratégia.

- Você tem um programa de biblioteca MFC que implementa o suporte à versão 1,0 do OLE.

   Consulte a [Nota técnica do MFC 41](tn041-mfc-ole1-migration-to-mfc-ole-2.md) para essa estratégia de conversão.

- Você tem um aplicativo que não foi escrito usando o MFC e que pode ou não ter implementado o suporte a OLE.

   Essa situação requer mais trabalho. Uma abordagem é criar um novo aplicativo, como na primeira estratégia, e, em seguida, copiar e colar o código existente nele. Se o código existente for escrito em C, talvez seja necessário modificá-lo para que ele possa compilar como código C++. Se o seu código C chamar a API do Windows, você não precisará alterá-la para usar as classes do Microsoft Foundation. Provavelmente, essa abordagem exigirá uma reestruturação do seu programa para dar suporte à arquitetura de documento/exibição usada pelas versões 2,0 e superiores do MFC. Para obter mais informações sobre essa arquitetura, consulte a [Nota técnica 25](tn025-document-view-and-frame-creation.md).

Depois de decidir sobre uma estratégia, leia os artigos [contêineres](containers.md) ou [servidores](servers.md) (dependendo do tipo de aplicativo que você está gravando) ou examine os programas de exemplo, ou ambos. Os exemplos de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md) mostram como implementar os vários aspectos de contêineres e servidores, respectivamente. Em vários pontos em todos esses artigos, você será citado em determinadas funções nesses exemplos como exemplos das técnicas que estão sendo discutidas.

## <a name="see-also"></a>Consulte também

[tela de fundo OLE](ole-background.md)<br/>
[Contêineres: implementando um contêiner](containers-implementing-a-container.md)<br/>
[Servidores: implementando um servidor](servers-implementing-a-server.md)<br/>
[Assistente de aplicativo do MFC](reference/mfc-application-wizard.md)
