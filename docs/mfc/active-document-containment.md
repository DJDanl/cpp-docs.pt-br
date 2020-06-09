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
ms.openlocfilehash: 1c524d6890cd7b86bcae2c40d8c602e7b04e751b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623432"
---
# <a name="active-document-containment"></a>Contenção de documento ativa

A contenção de documentos ativos é uma tecnologia que fornece um único quadro no qual trabalhar com documentos, em vez de forçá-lo a criar e usar vários quadros de aplicativos para cada tipo de documento. Ele difere da tecnologia OLE básica no caso de OLE funcionar com objetos incorporados em um documento composto no qual apenas um único conteúdo pode estar ativo. Com o confinamento do documento ativo, você ativa um documento inteiro (ou seja, um aplicativo inteiro, incluindo menus, barras de ferramentas e assim por diante) dentro do contexto de um único quadro.

A tecnologia de contenção de documentos ativos foi desenvolvida originalmente para Microsoft Office implementar o Office Binder. No entanto, a tecnologia é flexível o suficiente para dar suporte a contêineres de documento ativos diferentes do Office Binder e pode dar suporte a servidores de documentos diferentes de aplicativos compatíveis com o Office e Office.

O aplicativo que hospeda documentos ativos é chamado de [contêiner de documento ativo](active-document-containers.md). Exemplos desses contêineres são o Microsoft Office Binder ou o Microsoft Internet Explorer.

A contenção de documento ativo é implementada como um conjunto de extensões para documentos OLE, a tecnologia de documentos compostos do OLE. As extensões são interfaces adicionais que permitem que um objeto inserido no local represente um documento inteiro em vez de uma única parte do conteúdo incorporado. Assim como acontece com documentos OLE, a contenção de documentos ativos usa um contêiner que fornece o espaço de exibição para documentos ativos e servidores que fornecem a interface do usuário e os recursos de manipulação para os próprios documentos ativos.

Um [servidor de documentos ativo](active-document-servers.md) é um aplicativo (como Word, Excel ou PowerPoint) que dá suporte a uma ou mais classes de documento ativas, em que cada objeto em si dá suporte a interfaces de extensão que permitem que o objeto seja ativado em um contêiner adequado.

Um [documento ativo](active-documents.md) (fornecido de um servidor de documentos ativo, como Word ou Excel) é essencialmente um documento convencional de dimensionamento completo que é inserido como um objeto dentro de outro contêiner de documento ativo. Ao contrário dos objetos incorporados, os documentos ativos têm controle total sobre suas páginas e a interface completa do aplicativo (com todos os seus comandos e ferramentas subjacentes) está disponível para o usuário para editá-los.

Um documento ativo é mais bem compreendido ao distingui-lo de um objeto OLE inserido padrão. Após a Convenção OLE, um objeto inserido é aquele que é exibido na página do documento que o possui e o documento é gerenciado por um contêiner OLE. O contêiner armazena os dados do objeto inserido com o restante do documento. No entanto, os objetos incorporados são limitados, pois não controlam a página na qual aparecem.

Os usuários de um aplicativo de contêiner de documento ativo podem criar documentos ativos (chamados de seções no Office Binder) usando seus aplicativos favoritos (desde que esses aplicativos estejam habilitados para o documento ativo), mas os usuários podem gerenciar o projeto resultante como uma única entidade, que pode ser nomeada, salva, impressa e assim por diante. Da mesma forma, um usuário de um navegador da Internet pode tratar toda a rede, bem como sistemas de arquivos locais, como uma única entidade de armazenamento de documentos com a capacidade de procurar os documentos nesse armazenamento a partir de um único local.

## <a name="sample-programs"></a>Programas de exemplo

- O exemplo [MFCBIND](../overview/visual-cpp-samples.md) ilustra a implementação de um aplicativo de contêiner de documento ativo.

## <a name="see-also"></a>Consulte também

[MFC COM](mfc-com.md)
