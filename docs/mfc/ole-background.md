---
title: tela de fundo OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE, about OLE
ms.assetid: 5f654eb5-66b1-40c9-9215-bb85356a67f8
ms.openlocfilehash: 2501373c2ff5904343a6522e4fb18663f5de3843
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62186583"
---
# <a name="ole-background"></a>tela de fundo OLE

OLE é um mecanismo que permite aos usuários criar e editar documentos que contêm itens ou "objetos" criado por vários aplicativos.

> [!NOTE]
>  OLE foi originalmente um acrônimo para vinculação e incorporação de objetos. No entanto, ele é agora chamado de OLE. Partes do OLE não relacionadas à vinculação e incorporação agora fazem parte da tecnologia do Active Directory.

Documentos OLE, chamados historicamente documentos compostos, integram perfeitamente vários tipos de dados ou componentes. Clipes de som, planilhas e bitmaps são exemplos típicos de componentes encontrados em documentos OLE. Suporte a OLE em seu aplicativo permite que os usuários usem documentos OLE sem se preocupar sobre como alternar entre os diferentes aplicativos; OLE faz a alternância para você.

Você usar um aplicativo de contêiner para criar documentos compostos e um aplicativo de servidor ou aplicativo de componente para criar os itens dentro do documento contêiner. Qualquer aplicativo que você escreve pode ser um contêiner, um servidor ou ambos.

OLE incorpora muitos conceitos diferentes que funcionam para atingir a meta de interação transparente entre aplicativos. Essas áreas incluem o seguinte:

- Vinculação e incorporação

   Vinculação e incorporação são os dois métodos para armazenar os itens criados dentro de um documento OLE que foram criados em outro aplicativo. Para obter informações gerais sobre as diferenças entre os dois, consulte o artigo [plano de fundo OLE: Vinculação e incorporação](../mfc/ole-background-linking-and-embedding.md). Para obter mais informações, consulte os artigos [recipientes](../mfc/containers.md) e [servidores](../mfc/servers.md).

- Ativação in-loco (edição Visual)

   Ativar um item inserido no contexto do documento contêiner é chamado de ativação no local ou a edição visual. Interface do aplicativo de contêiner é alterado para incorporar os recursos do aplicativo do componente que criou o item inserido. Itens vinculados nunca são ativados em vigor porque os dados reais para o item estão contidos em um arquivo separado, fora do contexto do aplicativo que contém o link. Para obter mais informações sobre a ativação in-loco, consulte o artigo [ativação](../mfc/activation-cpp.md).

   > [!NOTE]
   > Vinculação e incorporação e ativação in-loco fornecem os principais recursos de edição visual do OLE.

- Automação de automação permite que um aplicativo direcionar o outro aplicativo. O aplicativo condução é conhecido como um cliente de automação e o aplicativo que está sendo controlado por é conhecido como um servidor de automação ou o componente de automação. Para obter mais informações sobre a automação, consulte os artigos [clientes de automação](../mfc/automation-clients.md) e [servidores de automação](../mfc/automation-servers.md).

   > [!NOTE]
   > Automação funciona em contextos de tecnologia OLE e o Active Directory. Você pode automatizar qualquer objeto com base em COM.

- Composta de arquivos

   Arquivos compostos fornecem um formato de arquivo padrão que simplifica o armazenamento estruturado de documentos compostos para aplicativos OLE. Dentro de um arquivo composto, armazenamentos tem muitos recursos de diretórios e fluxos têm muitos recursos de arquivos. Essa tecnologia também é chamada de armazenamento estruturado. Para obter mais informações sobre arquivos compostos, consulte o artigo [contêineres: Composta arquivos](../mfc/containers-compound-files.md).

- Transferência uniforme de dados

   Transferência de dados uniforme (UDT) é um conjunto de interfaces que permitem que os dados sejam enviadas e recebidas de uma maneira padrão, independentemente do método real escolhido para transferir os dados. Formulários UDT, com que a base de dados transfere arrastar e soltar. Agora, o UDT serve como base para a transferência de dados de Windows existente, como a área de transferência e troca dinâmica de dados (DDE). Para obter mais informações sobre o UDT, consulte o artigo [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md).

- Arrastar e soltar

   Arrastar e soltar é uma técnica fácil de usar, a manipulação direta para transferir dados entre aplicativos, entre janelas dentro de um aplicativo, ou mesmo dentro de uma única janela em um aplicativo. Os dados a serem transferidos estão selecionados e arrastados para o destino desejado. Arrastar e soltar se baseia na transferência de dados uniforme. Para obter mais informações sobre o arrastar e soltar, consulte o artigo [arrastar e soltar](../mfc/drag-and-drop-ole.md).

- Modelo de objeto de componente

   O modelo de objeto de componente (COM) fornece a infraestrutura usada quando os objetos OLE se comunicam entre si. As classes OLE do MFC para simplificar COM para o programador. COM é parte da tecnologia do Active Directory, como objetos COM subjacentes a tecnologia OLE e o Active Directory. Para obter mais informações sobre o COM, consulte o [biblioteca ATL (Active Template)](../atl/active-template-library-atl-concepts.md) tópicos.

Alguns dos tópicos mais importantes do OLE são abordados nos seguintes artigos:

- [Tela de fundo OLE: vincular e inserir](../mfc/ole-background-linking-and-embedding.md)

- [Tela de fundo OLE: contêineres e servidores](../mfc/ole-background-containers-and-servers.md)

- [Tela de fundo OLE: estratégias de implementação](../mfc/ole-background-implementation-strategies.md)

- [Tela de fundo OLE: implementação do MFC](../mfc/ole-background-mfc-implementation.md)

Para informações gerais de OLE não encontradas nos artigos acima, pesquise por OLE no MSDN.

## <a name="see-also"></a>Consulte também

[OLE](../mfc/ole-in-mfc.md)
