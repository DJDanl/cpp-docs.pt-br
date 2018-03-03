---
title: Plano de fundo OLE | Microsoft Docs
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
- OLE, about OLE
ms.assetid: 5f654eb5-66b1-40c9-9215-bb85356a67f8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e40fb7d2e58fa672196853e1edb9d5577c2cb14a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ole-background"></a>tela de fundo OLE
OLE é um mecanismo que permite aos usuários criar e editar documentos que contêm itens ou "objetos" criado por vários aplicativos.  
  
> [!NOTE]
>  OLE foi originalmente o acrônimo de vinculação e incorporação de objetos. No entanto, ele é agora é referido como OLE. Partes de OLE não relacionadas ao vinculando e inserindo agora fazem parte da tecnologia ativa.  
  
 Documentos OLE, chamados historicamente documentos compostos, integram perfeitamente vários tipos de dados ou de componentes. Clipes de som, planilhas e bitmaps são exemplos típicos de componentes encontrados em documentos OLE. Suporte OLE em seu aplicativo permite que os usuários usem documentos OLE sem se preocupar sobre como alternar entre os diferentes aplicativos; A tecnologia OLE faz a alternância para você.  
  
 Você usar um aplicativo de contêiner para criar documentos compostos e um aplicativo de servidor ou aplicativo do componente para criar os itens no documento contêiner. Qualquer aplicativo que você escreve pode ser um contêiner, um servidor ou ambos.  
  
 OLE incorpora muitos conceitos diferentes que todos eles funcionam para atingir a meta de interação transparente entre aplicativos. Essas áreas incluem o seguinte:  
  
 Vinculando e inserindo  
 Vinculando e inserindo são os dois métodos para armazenar itens criados dentro de um documento OLE que foram criados em outro aplicativo. Para obter informações gerais sobre as diferenças entre os dois, consulte o artigo [plano de fundo OLE: vinculando e inserindo](../mfc/ole-background-linking-and-embedding.md). Para obter mais informações, consulte os artigos [contêineres](../mfc/containers.md) e [servidores](../mfc/servers.md).  
  
 Ativação no local (edição Visual)  
 Ativar um item inserido no contexto do documento contêiner é chamado de ativação no local ou a edição visual. Interface do aplicativo recipiente é alterado para incorporar os recursos de aplicativo do componente que criou o item inserido. Itens vinculados nunca são ativados em vigor porque os dados reais para o item estão contidos em um arquivo separado, fora do contexto do aplicativo que contém o link. Para obter mais informações sobre a ativação no local, consulte o artigo [ativação](../mfc/activation-cpp.md).  
  
> [!NOTE]
>  Vinculando e inserindo e ativação in-loco fornecem os principais recursos de edição visual de OLE.  
  
 Automação  
 A automação permite que um aplicativo para outro aplicativo de unidade. Um aplicativo é conhecido como um cliente de automação, e o aplicativo que está sendo controlada por é conhecido como um servidor de automação ou um componente de automação. Para obter mais informações sobre a automação, consulte os artigos [clientes de automação](../mfc/automation-clients.md) e [servidores de automação](../mfc/automation-servers.md).  
  
> [!NOTE]
>  Automação funciona em contextos de tecnologia OLE e ativo. Você pode automatizar qualquer objeto com base em COM.  
  
 Composta de arquivos  
 Arquivos compostos fornecem um formato de arquivo padrão que simplifica o armazenamento estruturado de documentos compostos para aplicativos OLE. Dentro de um arquivo composto, armazenamentos tem muitos recursos de diretórios e fluxos tem muitos recursos de arquivos. Essa tecnologia também é chamada de armazenamento estruturado. Para obter mais informações sobre arquivos compostos, consulte o artigo [contêineres: arquivos compostos](../mfc/containers-compound-files.md).  
  
 Transferência de dados uniforme  
 Transferência de dados uniforme (UDT) é um conjunto de interfaces que permitem que os dados sejam enviadas e recebidas de modo padrão, independentemente do método real escolhido para transferir os dados. Formulários UDT, com que a base de dados transfere arrastar e soltar. UDT agora serve como base para a transferência de dados de Windows existente, como a área de transferência e troca dinâmica de dados (DDE). Para obter mais informações sobre UDT, consulte o artigo [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md).  
  
 Arrastar e soltar  
 Arrastar e soltar é uma técnica fácil de usar, a manipulação direta para transferir dados entre aplicativos do windows em um aplicativo, ou mesmo dentro de uma única janela em um aplicativo. Os dados a serem transferidos estão selecionados e arrastados para o destino desejado. Arrastar e soltar é baseado na transferência de dados uniforme. Para obter mais informações sobre como arrastar e soltar, consulte o artigo [arrastar e soltar](../mfc/drag-and-drop-ole.md).  
  
 Modelo de objeto do componente  
 O modelo de objeto de componente (COM) fornece a infraestrutura usada quando os objetos OLE se comunicam entre si. As classes MFC OLE simplificam COM para o programador. COM faz parte da tecnologia ativa, porque os objetos subjacentes a tecnologia OLE e ativo. Para obter mais informações sobre COM, consulte o [biblioteca ATL (Active Template)](../atl/active-template-library-atl-concepts.md) tópicos.  
  
 Alguns dos tópicos mais importantes do OLE são discutidos nos seguintes artigos:  
  
-   [Tela de fundo OLE: vinculando e inserindo](../mfc/ole-background-linking-and-embedding.md)  
  
-   [Tela de fundo OLE: contêineres e servidores](../mfc/ole-background-containers-and-servers.md)  
  
-   [Tela de fundo OLE: estratégias de implementação](../mfc/ole-background-implementation-strategies.md)  
  
-   [Tela de fundo OLE: implementação de MFC](../mfc/ole-background-mfc-implementation.md)  
  
 Para obter informações gerais OLE não encontradas nos artigos acima, procure OLE no MSDN.  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)

