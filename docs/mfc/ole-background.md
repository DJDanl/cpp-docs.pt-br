---
title: tela de fundo OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE, about OLE
ms.assetid: 5f654eb5-66b1-40c9-9215-bb85356a67f8
ms.openlocfilehash: f18614f7b156a1757df9dfaac9e4a0ad4f8209eb
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404288"
---
# <a name="ole-background"></a>tela de fundo OLE

OLE é um mecanismo que permite aos usuários criar e editar documentos que contêm itens ou "objetos" criados por vários aplicativos.

> [!NOTE]
> O OLE era originalmente um acrônimo para vinculação e inserção de objetos. No entanto, agora ele é conhecido como OLE. Partes do OLE não relacionadas ao vínculo e à incorporação agora fazem parte da tecnologia ativa.

Documentos OLE, historicamente chamados de documentos compostos, integram perfeitamente vários tipos de dados ou componentes. Clipes de som, planilhas e bitmaps são exemplos típicos de componentes encontrados em documentos OLE. O suporte ao OLE em seu aplicativo permite que os usuários usem documentos OLE sem se preocupar com a alternância entre os diferentes aplicativos; O OLE faz a alternância para você.

Você usa um aplicativo de contêiner para criar documentos compostos e um aplicativo de servidor ou aplicativo de componente para criar os itens dentro do documento de contêiner. Qualquer aplicativo que você escrever pode ser um contêiner, um servidor ou ambos.

O OLE incorpora muitos conceitos diferentes que funcionam para o objetivo da interação direta entre aplicativos. Essas áreas incluem o seguinte:

- vincular e inserir

   Vincular e inserir são os dois métodos para armazenar itens criados dentro de um documento OLE que foram criados em outro aplicativo. Para obter informações gerais sobre as diferenças entre os dois, consulte o artigo [plano de fundo OLE: vinculação e inserção](ole-background-linking-and-embedding.md). Para obter informações mais detalhadas, consulte os artigos [containers](containers.md) and [Servers](servers.md).

- Ativação in-loco (edição Visual)

   Ativar um item incorporado no contexto do documento de contêiner é chamado de ativação in-loco ou edição visual. A interface do aplicativo de contêiner é alterada para incorporar os recursos do aplicativo de componente que criou o item inserido. Itens vinculados nunca são ativados no local porque os dados reais do item estão contidos em um arquivo separado, fora do contexto do aplicativo que contém o link. Para obter mais informações sobre ativação in-loco, consulte o artigo [ativação](activation-cpp.md).

   > [!NOTE]
   > Vinculação e inserção e ativação in-loco fornecem os principais recursos de edição Visual OLE.

- A automação de automação permite que um aplicativo conduza outro aplicativo. O aplicativo de condução é conhecido como cliente de automação, e o aplicativo que está sendo orientado é conhecido como um servidor de automação ou um componente de automação. Para obter mais informações sobre automação, consulte os artigos [clientes de automação](automation-clients.md) e servidores de [automação](automation-servers.md).

   > [!NOTE]
   > A automação funciona em contextos de tecnologia OLE e ativo. Você pode automatizar qualquer objeto com base em COM.

- arquivos compostos

   Os arquivos compostos fornecem um formato de arquivo padrão que simplifica o armazenamento estruturado de documentos compostos para aplicativos OLE. Em um arquivo composto, os armazenamentos têm muitos recursos de diretórios e fluxos têm muitos recursos de arquivos. Essa tecnologia também é chamada de armazenamento estruturado. Para obter mais informações sobre arquivos compostos, consulte o artigo [contêineres: arquivos compostos](containers-compound-files.md).

- Transferência de Dados uniforme

   O Uniform Transferência de Dados (UDT) é um conjunto de interfaces que permite que os dados sejam enviados e recebidos de uma maneira padrão, independentemente do método real escolhido para transferir os dados. O UDT forma a base para transferências de dados por meio de arrastar e soltar. O UDT agora serve como base para a transferência de dados existente do Windows, como a área de transferência e o DDE (intercâmbio dinâmico de dados). Para obter mais informações sobre UDT, consulte o artigo [objetos de dados e fontes de dados (OLE)](data-objects-and-data-sources-ole.md).

- Arrastar e soltar

   O recurso arrastar e soltar é uma técnica de manipulação direta fácil de usar para transferir dados entre aplicativos, entre janelas em um aplicativo ou até mesmo em uma única janela em um aplicativo. Os dados a serem transferidos são selecionados e arrastados para o destino desejado. O recurso de arrastar e soltar baseia-se na transferência de dados uniforme. Para obter mais informações sobre arrastar e soltar, consulte o artigo [arrastar e soltar](drag-and-drop-ole.md).

- Component Object Model

   A Component Object Model (COM) fornece a infraestrutura usada quando objetos OLE se comunicam entre si. As classes OLE do MFC simplificam o COM para o programador. O COM faz parte da tecnologia ativa, pois objetos COM se baseiam em tecnologia OLE e ativa. Para obter mais informações sobre COM, consulte os tópicos de [Active Template Library (ATL)](../atl/active-template-library-atl-concepts.md) .

Alguns dos tópicos mais importantes do OLE são abordados nos seguintes artigos:

- [Tela de fundo OLE: vinculando e inserindo](ole-background-linking-and-embedding.md)

- [Tela de fundo OLE: contêineres e servidores](ole-background-containers-and-servers.md)

- [Tela de fundo OLE: estratégias de implementação](ole-background-implementation-strategies.md)

- [tela de fundo OLE: implementação MFC](ole-background-mfc-implementation.md)

Para obter informações gerais de OLE não encontradas nos artigos acima, [pesquise por OLE](https://docs.microsoft.com/search/?terms=ole) em Microsoft docs.

## <a name="see-also"></a>Confira também

[OLE](ole-in-mfc.md)
