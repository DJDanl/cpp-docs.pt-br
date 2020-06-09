---
title: 'Contêineres: itens clientes'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE containers [MFC], client items
- client items and OLE containers
ms.assetid: 231528b5-0744-4f83-8897-083bf55ed087
ms.openlocfilehash: ad347c78fb6aa7af94b306a3edb538b9f740c305
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619014"
---
# <a name="containers-client-items"></a>Contêineres: itens clientes

Este artigo explica o que são itens de cliente e de quais classes seu aplicativo deve derivar seus itens de cliente.

Itens de cliente são itens de dados que pertencem a outro aplicativo que estão contidos no ou referenciados por um documento do aplicativo de contêiner OLE. Itens de cliente cujos dados estão contidos no documento são inseridos; aqueles cujos dados são armazenados em outro local referenciado pelo documento de contêiner são vinculados.

A classe Document em um aplicativo OLE é derivada da classe [COleDocument](reference/coledocument-class.md) em vez de `CDocument` . A `COleDocument` classe herda de `CDocument` toda a funcionalidade necessária para usar a arquitetura de documento/exibição na qual os aplicativos MFC são baseados. `COleDocument`também define uma interface que trata um documento como uma coleção de `CDocItem` objetos. Várias `COleDocument` funções de membro são fornecidas para adicionar, recuperar e excluir elementos dessa coleção.

Cada aplicativo de contêiner deve derivar pelo menos uma classe `COleClientItem` . Os objetos dessa classe representam itens, inseridos ou vinculados, no documento OLE. Esses objetos existem para a vida útil do documento que os contém, a menos que sejam excluídos do documento.

`CDocItem`é a classe base para `COleClientItem` e `COleServerItem` . Os objetos das classes derivadas desses dois atuam como intermediários entre o item OLE e os aplicativos cliente e servidor, respectivamente. Cada vez que um novo item OLE é adicionado ao documento, a estrutura MFC adiciona um novo objeto da classe derivada do seu aplicativo cliente `COleClientItem` à coleção de objetos do documento `CDocItem` .

## <a name="see-also"></a>Consulte também

[Contêineres](containers.md)<br/>
[Contêineres: arquivos compostos](containers-compound-files.md)<br/>
[Contêineres: emissões de interface do usuário](containers-user-interface-issues.md)<br/>
[Contêineres: funcionalidades avançadas](containers-advanced-features.md)<br/>
[Classe COleClientItem](reference/coleclientitem-class.md)<br/>
[Classe COleServerItem](reference/coleserveritem-class.md)
