---
title: 'Contêineres: Itens de cliente'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE containers [MFC], client items
- client items and OLE containers
ms.assetid: 231528b5-0744-4f83-8897-083bf55ed087
ms.openlocfilehash: 0c7f4a63cb9a31b52be2d3574ddad29313df6a4d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62153353"
---
# <a name="containers-client-items"></a>Contêineres: Itens de cliente

Este artigo explica quais são os itens de cliente e de classes de que seu aplicativo deve derivar seus itens de cliente.

Itens de cliente são itens de dados que pertencem a outro aplicativo que estão contidos na ou referenciado pelo documento do aplicativo contêiner OLE. Itens de cliente cujos dados estão contidos dentro do documento são inseridos; aqueles cujos dados são armazenados em outro local referenciado pelo documento contêiner são vinculados.

A classe de documento em um aplicativo OLE é derivada da classe [COleDocument](../mfc/reference/coledocument-class.md) , em vez de `CDocument`. O `COleDocument` classe herda de `CDocument` todas as funcionalidades necessárias para usar a arquitetura de documento/exibição na qual MFC aplicativos se baseiam. `COleDocument` também define uma interface que trata de um documento como uma coleção de `CDocItem` objetos. Vários `COleDocument` funções de membro são fornecidas para adicionar, recuperar e excluir os elementos da coleção.

Cada aplicativo de contêiner deve derivar de pelo menos uma classe de `COleClientItem`. Objetos dessa classe representam os itens, inseridos ou vinculados no documento OLE. Esses objetos existem durante a vida útil do documento que os contém, a menos que eles são excluídos do documento.

`CDocItem` é a classe base para `COleClientItem` e `COleServerItem`. Objetos de classes derivadas desses dois atuam como intermediários entre o item OLE e aplicativos cliente e servidor, respectivamente. Sempre que um novo item OLE é adicionado ao documento, a estrutura MFC adiciona um novo objeto do seu aplicativo de cliente `COleClientItem`-classe derivada para a coleção do documento de `CDocItem` objetos.

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Contêineres: arquivos compostos](../mfc/containers-compound-files.md)<br/>
[Contêineres: problemas da interface do usuário](../mfc/containers-user-interface-issues.md)<br/>
[Contêineres: recursos avançados](../mfc/containers-advanced-features.md)<br/>
[Classe COleClientItem](../mfc/reference/coleclientitem-class.md)<br/>
[Classe COleServerItem](../mfc/reference/coleserveritem-class.md)
