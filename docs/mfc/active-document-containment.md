---
title: "Contenção de documentos ativos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- active documents [MFC], containers
- containers [MFC], active document
- MFC, COM support
- active document containers [MFC], about active document containers
- MFC COM, active document containment
ms.assetid: b8dfa74b-75ce-47df-b75e-fc87b7f7d687
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 16c0311c3eedc13cbc47214b44fc8810dee3eecd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="active-document-containment"></a>Contenção de documento ativa
Contenção de documentos ativos é uma tecnologia que fornece uma única estrutura na qual trabalhar com documentos, em vez de forçá-lo a criar e usar várias estruturas de aplicativo para cada tipo de documento. Ele difere de tecnologia OLE básica OLE funciona com objetos inseridos dentro de um documento composto no qual apenas uma única parte do conteúdo pode estar ativa. Com contenção de documentos ativos, você pode ativar um documento inteiro (isto é, um aplicativo inteiro, incluindo associados de menus, barras de ferramentas e assim por diante) dentro do contexto de uma única estrutura.  
  
 A tecnologia de confinamento do documento ativo foi originalmente desenvolvida para o Microsoft Office implementar o Office Binder. No entanto, a tecnologia é flexível o suficiente para dar suporte a contêineres de documentos ativos que não sejam Office Binder e pode dar suporte a servidores de documentos que não sejam aplicativos do Office e compatível com o Office.  
  
 O aplicativo que hospeda documentos ativos é chamado um [contêiner de documento ativo](../mfc/active-document-containers.md). Exemplos de tais contêineres são o Microsoft Office Binder ou Microsoft Internet Explorer.  
  
 Contenção de documentos ativos é implementada como um conjunto de extensões para OLE documentos, a tecnologia de documento composto de OLE. As extensões são interfaces adicionais que permitem que um objeto pode ser incorporado no local representar um documento inteiro em vez de uma única parte do conteúdo incorporado. Assim como acontece com documentos OLE, a contenção de documentos ativos usa um contêiner que fornece o espaço de exibição de documentos ativos e servidores que fornecem o usuário funcionalidades de interface e manipulação para os próprios documentos ativos.  
  
 Um [server documento ativo](../mfc/active-document-servers.md) é um aplicativo (como Word, Excel ou PowerPoint) que dá suporte a uma ou mais classes de documento ativo, onde cada objeto em si é compatível com as interfaces de extensão que permitem que o objeto a ser ativado em um contêiner adequado.  
  
 Um [documento ativo](../mfc/active-documents.md) (fornecido de um servidor do documento ativo como o Word ou Excel) é essencialmente um documento de escala, convencional que será inserido como um objeto em outro contêiner de documento ativo. Ao contrário de objetos inseridos, documentos ativos tem total controle sobre suas páginas e a interface completa do aplicativo (com todas as suas subjacente comandos e ferramentas) está disponível para o usuário para editá-los.  
  
 Um documento ativo é melhor entendido pelo diferenciá-lo de um objeto inserido OLE padrão. A seguir a convenção OLE, um objeto inserido é aquele que é exibido dentro da página do documento que ele pertence e o documento é gerenciado por um contêiner OLE. O contêiner armazena os dados do objeto inserido com o restante do documento. No entanto, objetos inseridos são limitados em que eles não controlam a página em que aparecem.  
  
 Os usuários de um aplicativo de contêiner do documento ativo podem criar documentos ativos (chamados de seções no Office Binder) usando seus aplicativos favoritos (desde que esses aplicativos são documento ativo habilitado), mas os usuários podem gerenciar o projeto resultante como um entidade única, que pode ser exclusivamente nomeada, salvo, impressos, e assim por diante. Da mesma forma, um usuário de um navegador da Internet pode tratar toda a rede, bem como os sistemas de arquivos local, como uma entidade de armazenamento único documento com a capacidade de procurar documentos que o armazenamento de um único local.  
  
## <a name="sample-programs"></a>Programas de exemplo  
  
-   O [MFCBIND](../visual-cpp-samples.md) exemplo ilustra a implementação de um aplicativo de contêiner do documento ativo.  
  
## <a name="see-also"></a>Consulte também  
 [MFC COM](../mfc/mfc-com.md)

