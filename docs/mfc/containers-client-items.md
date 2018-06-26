---
title: 'Contêineres: Itens clientes | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE containers [MFC], client items
- client items and OLE containers
ms.assetid: 231528b5-0744-4f83-8897-083bf55ed087
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2a7b498ed1ddc3a3d040abde6ebcb7e27615b801
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929337"
---
# <a name="containers-client-items"></a>Contêineres: itens clientes
Este artigo explica o que são itens de cliente e de classes de que seu aplicativo deve derivar seus itens de cliente.  
  
 Itens de cliente são itens de dados que pertencem a outro aplicativo que são contidos em ou referenciado pelo documento do aplicativo recipiente OLE. Itens de cliente cujos dados estão contidos dentro do documento são incorporados. aqueles cujos dados são armazenados em outro local referenciado pelo documento contêiner estão vinculados.  
  
 A classe de documento em um aplicativo OLE é derivada da classe [COleDocument](../mfc/reference/coledocument-class.md) , em vez de `CDocument`. O `COleDocument` classe herda de `CDocument` todos os recursos necessários para usar a arquitetura de documento/exibição na qual MFC aplicativos se baseiam. `COleDocument` também define uma interface que trata de um documento como uma coleção de `CDocItem` objetos. Vários `COleDocument` funções de membro são fornecidas para adicionar, recuperar e excluir os elementos da coleção.  
  
 Cada aplicativo de contêiner deve derivar de pelo menos uma classe de `COleClientItem`. Objetos dessa classe representam os itens, incorporado ou vinculado no documento OLE. Esses objetos existem durante a vida útil do documento que os contém, a menos que eles são excluídos do documento.  
  
 `CDocItem` é a classe base para `COleClientItem` e `COleServerItem`. Objetos de classes derivadas desses dois atuam como intermediários entre o item OLE e os aplicativos cliente e servidor, respectivamente. Cada vez que um novo item OLE é adicionado ao documento, a estrutura MFC adiciona um novo objeto de seu aplicativo de cliente `COleClientItem`-classe derivada a coleção do documento de `CDocItem` objetos.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: Arquivos compostos](../mfc/containers-compound-files.md)   
 [Contêineres: Problemas de Interface do usuário](../mfc/containers-user-interface-issues.md)   
 [Contêineres: Funcionalidades avançadas](../mfc/containers-advanced-features.md)   
 [Classe COleClientItem](../mfc/reference/coleclientitem-class.md)   
 [Classe COleServerItem](../mfc/reference/coleserveritem-class.md)
