---
title: 'Tela de fundo OLE: Estratégias de implementação'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE [MFC], development strategy
- OLE applications [MFC], implementing OLE
- applications [OLE], implementing OLE
ms.assetid: 0875ddae-99df-488c-82c6-164074a81058
ms.openlocfilehash: 83a1089ecaaaa9bd0dd1d928cd3d1869e5017a4a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58774380"
---
# <a name="ole-background-implementation-strategies"></a>Tela de fundo OLE: Estratégias de implementação

Dependendo do seu aplicativo, há quatro estratégias de implementação possível para adicionar suporte ao OLE:

- Você está escrevendo um novo aplicativo.

   Essa situação geralmente requer menos trabalho. Execute o Assistente de aplicativo do MFC e selecione recursos avançados ou suporte de documento composto para criar um aplicativo de esqueleto. Para obter informações sobre essas opções e o que fazer, consulte o artigo [criando um programa do MFC EXE](../mfc/reference/mfc-application-wizard.md).

- Você tem um programa escrito com a biblioteca Microsoft Foundation Class versão 2.0 ou superior que não dá suporte a OLE.

   Criar um novo aplicativo com o Assistente de aplicativo do MFC como mencionado anteriormente e, em seguida, copie e cole o código do novo aplicativo em seu aplicativo existente. Isso funcionará para servidores, contêineres ou aplicativos automatizados. Consulte o MFC [RABISCO](../overview/visual-cpp-samples.md) exemplo para obter um exemplo dessa estratégia.

- Você tem um programa de biblioteca Microsoft Foundation Class que implementa o suporte da versão 1.0 de OLE.

   Ver [41 de observação técnica MFC](../mfc/tn041-mfc-ole1-migration-to-mfc-ole-2.md) para essa estratégia de conversão.

- Você tem um aplicativo que não foi escrito usando o Microsoft Foundation Classes e que podem ou não pode ter implementado suporte OLE.

   Essa situação requer mais trabalho. Uma abordagem é criar um novo aplicativo, como a primeira estratégia e, em seguida, copie e cole o código existente nele. Se seu código existente é escrito em C, em seguida, você precisa modificá-lo para que ele pode compilar como código C++. Se seu código C chama a API do Windows, não é necessário alterá-lo para usar as Microsoft Foundation classes. Essa abordagem provavelmente exigirá alguma reestruturação do seu programa para dar suporte à arquitetura de documento/exibição usada por versões 2.0 e mais recente do que o Microsoft Foundation Classes. Para obter mais informações sobre essa arquitetura, consulte [25 de observação técnica](../mfc/tn025-document-view-and-frame-creation.md).

Depois de decidir uma estratégia, você deve ler o [recipientes](../mfc/containers.md) ou [servidores](../mfc/servers.md) artigos (dependendo do tipo de aplicativo que você está escrevendo) ou examinar as amostras de programas, ou ambos. Os exemplos de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md) mostram como implementar os vários aspectos de contêineres e servidores, respectivamente. Em vários pontos ao longo desses artigos, você será chamada para determinadas funções nesses exemplos como exemplos das técnicas que está sendo discutidos.

## <a name="see-also"></a>Consulte também

[Tela de fundo OLE](../mfc/ole-background.md)<br/>
[Contêineres: Implementando um contêiner](../mfc/containers-implementing-a-container.md)<br/>
[servidores: Implementação de um servidor](../mfc/servers-implementing-a-server.md)<br/>
[Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md)
