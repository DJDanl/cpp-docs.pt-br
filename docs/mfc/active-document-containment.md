---
title: Contenção de documento ativa
ms.date: 11/04/2016
helpviewer_keywords:
- active documents [MFC], containers
- containers [MFC], active document
- MFC, COM support
- active document containers [MFC], about active document containers
- MFC COM, active document containment
ms.assetid: b8dfa74b-75ce-47df-b75e-fc87b7f7d687
ms.openlocfilehash: 22111a8b2f7048d9f62d9e3e2f6c270fdc9bace3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612375"
---
# <a name="active-document-containment"></a>Contenção de documento ativa

Contenção de documento ativa é uma tecnologia que fornece um único quadro no qual trabalhar com documentos, em vez de forçá-lo a criar e usar várias estruturas de aplicativo para cada tipo de documento. Ele difere de tecnologia básica do OLE OLE funciona com objetos inseridos dentro de um documento composto no qual apenas uma única parte do conteúdo pode estar ativa. Com confinamento do documento ativo, você pode ativar um documento inteiro (ou seja, um aplicativo inteiro, incluindo o associado de menus, barras de ferramentas e assim por diante) dentro do contexto de um único quadro.

A tecnologia de confinamento do documento ativo foi originalmente desenvolvida para o Microsoft Office implementar o Office Binder. No entanto, a tecnologia é flexível o suficiente para dar suporte a contêineres de documento ativo além do Office Binder e pode dar suporte a servidores de documentos que não sejam aplicativos do Office e compatível com o Office.

O aplicativo que hospeda documentos ativos é chamado de um [contêiner de documento ativo](../mfc/active-document-containers.md). Exemplos de tais contêineres são o Microsoft Office Binder ou o Microsoft Internet Explorer.

Contenção de documento ativa é implementada como um conjunto de extensões para OLE documentos, a tecnologia de documento composto de OLE. As extensões são interfaces adicionais que permitem que um objeto pode ser incorporado, no local representar um documento inteiro em vez de uma única parte do conteúdo incorporado. Assim como acontece com documentos OLE, confinamento do documento ativo usa um contêiner que fornece o espaço de exibição de documentos ativos e servidores que fornecem recursos de interface e a manipulação do usuário para os próprios documentos Active Directory.

Uma [servidor de documento ativo](../mfc/active-document-servers.md) é um aplicativo (como Word, Excel ou PowerPoint) que dá suporte a uma ou mais classes de documento ativo, onde cada objeto em si oferece suporte as interfaces de extensão que permitem que o objeto a ser ativado em um contêiner adequado.

Uma [documento ativo](../mfc/active-documents.md) (fornecido de um servidor de documento ativo como o Word ou Excel) é, essencialmente, um documento de grande escala, convencional que é inserido como um objeto dentro de outro contêiner de documento ativo. Ao contrário de objetos inseridos, documentos ativos têm controle completo sobre suas páginas e a interface completa do aplicativo (com todos os seus subjacente comandos e ferramentas) está disponível para o usuário para editá-los.

Um documento ativo é mais bem entendido por fazer a distinção de um objeto inserido do OLE padrão. Seguir a convenção do OLE, um objeto inserido é aquele que é exibido dentro da página do documento que ele pertence e o documento é gerenciado por um contêiner OLE. O contêiner armazena os dados do objeto inserido com o restante do documento. No entanto, objetos incorporados são limitados em que eles não controlam a página na qual elas aparecem.

Os usuários de um aplicativo de contêiner do documento ativo podem criar documentos ativos (chamados de seções no Office Binder) usando seus aplicativos favoritos (desde que esses aplicativos são habilitado de documento ativo), mas os usuários podem gerenciar o projeto resultante como um entidade única, que pode ser um nome exclusivo, salva, impresso, e assim por diante. Da mesma forma, um usuário de um navegador da Internet pode tratar a toda a rede, bem como sistemas de arquivos locais, como uma entidade de armazenamento único documento com a capacidade de procurar os documentos em que o armazenamento em um único local.

## <a name="sample-programs"></a>Programas de exemplo

- O [MFCBIND](../visual-cpp-samples.md) exemplo ilustra a implementação de um aplicativo de contêiner do documento ativo.

## <a name="see-also"></a>Consulte também

[MFC COM](../mfc/mfc-com.md)

