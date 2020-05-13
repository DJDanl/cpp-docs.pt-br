---
title: tela de fundo OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE, about OLE
ms.assetid: 5f654eb5-66b1-40c9-9215-bb85356a67f8
ms.openlocfilehash: f7d65f48c1af678f6626ba7d315ceb735d3e960a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364517"
---
# <a name="ole-background"></a>tela de fundo OLE

O Le é um mecanismo que permite aos usuários criar e editar documentos contendo itens ou "objetos" criados por vários aplicativos.

> [!NOTE]
> OLE era originalmente um acrônimo para Object Linking and Inbedding. No entanto, agora é referido como OLE. Partes do OLE não relacionadas à ligação e incorporação agora fazem parte da tecnologia Active.

Os documentos OLE, historicamente chamados de documentos compostos, integram perfeitamente vários tipos de dados ou componentes. Clipes de som, planilhas e bitmaps são exemplos típicos de componentes encontrados em documentos OLE. O suporte ao OLE em seu aplicativo permite que seus usuários usem documentos OLE sem se preocupar em alternar entre os diferentes aplicativos; OLE faz a troca para você.

Você usa um aplicativo de contêiner para criar documentos compostos e um aplicativo de servidor ou aplicativo de componentes para criar os itens dentro do documento do contêiner. Qualquer aplicativo que você escrever pode ser um contêiner, um servidor ou ambos.

A OLE incorpora muitos conceitos diferentes que todos trabalham em direção ao objetivo de interação perfeita entre aplicativos. Essas áreas incluem:

- vincular e inserir

   Vinculação e incorporação são os dois métodos para armazenar itens criados dentro de um documento OLE que foram criados em outro aplicativo. Para obter informações gerais sobre as diferenças entre os dois, consulte o artigo [OLE Background: Linking and Inbedding](../mfc/ole-background-linking-and-embedding.md). Para obter informações mais [detalhadas,](../mfc/servers.md)consulte os artigos [Containers](../mfc/containers.md) and Servers .

- Ativação no local (edição visual)

   Ativar um item incorporado no contexto do documento do contêiner é chamado de ativação no local ou edição visual. A interface do aplicativo de contêiner muda para incorporar os recursos do aplicativo de componentes que criou o item incorporado. Os itens vinculados nunca são ativados no local porque os dados reais do item estão contidos em um arquivo separado, fora do contexto do aplicativo que contém o link. Para obter mais informações sobre ativação no local, consulte o artigo [Ativação](../mfc/activation-cpp.md).

   > [!NOTE]
   > A vinculação e a incorporação e ativação no local fornecem as principais características da edição visual do OLE.

- Automação A automação permite que um aplicativo dirija outro aplicativo. O aplicativo de condução é conhecido como um cliente de automação, e o aplicativo que está sendo conduzido é conhecido como um servidor de automação ou componente de automação. Para obter mais informações sobre automação, consulte os artigos [Automação clientes](../mfc/automation-clients.md) e [servidores de automação.](../mfc/automation-servers.md)

   > [!NOTE]
   > A automação funciona tanto nos contextos de tecnologia OLE quanto Active. Você pode automatizar qualquer objeto com base no COM.

- arquivos compostos

   Os arquivos compostos fornecem um formato de arquivo padrão que simplifica o armazenamento estruturado de documentos compostos para aplicações OLE. Dentro de um arquivo composto, os armazenamentos têm muitos recursos de diretórios e fluxos têm muitos recursos de arquivos. Essa tecnologia também é chamada de armazenamento estruturado. Para obter mais informações sobre arquivos compostos, consulte o artigo [Containers: Compound Files](../mfc/containers-compound-files.md).

- Transferência uniforme de dados

   Uniform Data Transfer (UDT) é um conjunto de interfaces que permitem que os dados sejam enviados e recebidos de forma padrão, independentemente do método real escolhido para transferir os dados. O UDT forma a base para transferências de dados por arrastar e soltar. O UDT agora serve como base para a transferência de dados existente do Windows, como a Área de Transferência e o DDE (Dynamic Data Exchange). Para obter mais informações sobre a UDT, consulte o artigo [Data Objects and Data Sources (OLE)](../mfc/data-objects-and-data-sources-ole.md).

- Arrastar e soltar

   Arrastar e soltar é uma técnica fácil de usar e manipulação direta para transferir dados entre aplicativos, entre janelas dentro de um aplicativo ou mesmo dentro de uma única janela em um aplicativo. Os dados a serem transferidos são selecionados e arrastados para o destino desejado. Arrastar e soltar é baseado na transferência uniforme de dados. Para obter mais informações sobre arrastar e soltar, consulte o artigo [Arrastar e Soltar](../mfc/drag-and-drop-ole.md).

- Component Object Model

   O Modelo de Objeto Componente (COM) fornece a infra-estrutura usada quando os objetos OLE se comunicam entre si. As classes MFC OLE simplificam o COM para o programador. O COM faz parte da tecnologia Active, pois os objetos COM estão por trás tanto da tecnologia OLE quanto da Active. Para obter mais informações sobre o COM, consulte os tópicos da [Active Template Library (ATL).](../atl/active-template-library-atl-concepts.md)

Alguns dos tópicos mais importantes da OLE são abordados nos seguintes artigos:

- [Tela de fundo OLE: vinculando e inserindo](../mfc/ole-background-linking-and-embedding.md)

- [Tela de fundo OLE: contêineres e servidores](../mfc/ole-background-containers-and-servers.md)

- [Tela de fundo OLE: estratégias de implementação](../mfc/ole-background-implementation-strategies.md)

- [tela de fundo OLE: implementação MFC](../mfc/ole-background-mfc-implementation.md)

Para informações gerais de OLE não encontradas nos artigos acima, procure o OLE no MSDN.

## <a name="see-also"></a>Confira também

[OLE](../mfc/ole-in-mfc.md)
