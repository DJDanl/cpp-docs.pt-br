---
title: "Objetos e origens de dados: cria&#231;&#227;o e destrui&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos de dados [C++], criando"
  - "objetos de dados [C++], destruindo"
  - "objetos de fonte de dados [C++], criando"
  - "objetos de fonte de dados [C++], destruindo"
  - "fonte de dados [C++], e objetos de dados"
  - "fonte de dados [C++], criando"
  - "fonte de dados [C++], destruindo"
  - "fonte de dados [C++], função"
  - "destruindo objetos de dados"
  - "destruição [C++], objetos de dados"
  - "destruição [C++], fontes de dados"
  - "criação de objeto [C++], objetos de fonte de dados"
ms.assetid: ac216d54-3ca5-4ce7-850d-cd1f6a90d4f1
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Objetos e origens de dados: cria&#231;&#227;o e destrui&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conforme explicado no artigo [objetos de dados e fontes de dados \(OLE\)](../mfc/data-objects-and-data-sources-ole.md), objetos de dados e fontes de dados representam os dois lados de uma transferência de dados.  Este artigo explica quando criar e destruir a esses objetos e fontes para realizar suas transferências de dados corretamente, inclusive:  
  
-   [Criando objetos de dados](#_core_creating_data_objects)  
  
-   [Destruindo objetos de dados](#_core_destroying_data_objects)  
  
-   [Criar fontes de dados](#_core_creating_data_sources)  
  
-   [Destruição de fontes de dados](#_core_destroying_data_sources)  
  
##  <a name="_core_creating_data_objects"></a> Criando objetos de dados  
 Objetos de dados são usados pelo aplicativo de destino – o cliente ou no servidor.  Um objeto de dados no aplicativo de destino é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino.  Um objeto de dados no aplicativo de destino é usado para acessar e interagir com os dados na fonte de dados.  
  
 Há duas situações comuns em que um objeto de dados é necessária.  A primeira situação é quando dados são descartados em seu aplicativo usando arrastar e soltar.  A segunda situação é quando colar ou Colar especial é escolhido no menu Editar.  
  
 Em uma situação de arrastar e soltar, você não precisa criar um objeto de dados.  Um ponteiro para um objeto de dados existente será passado para o `OnDrop` função.  Esse objeto de dados é criado pela estrutura como parte da operação de arrastar e soltar e também será destruído por ele.  Isso nem sempre é o caso quando colar é feita por outro método.  Para obter mais informações, consulte [destruindo objetos de dados](#_core_destroying_data_objects).  
  
 Se o aplicativo está executando uma operação de especial de colar ou colar, você deverá criar um `COleDataObject` objeto e chamar seu `AttachClipboard` função de membro.  Isso associa o objeto de dados com os dados na área de transferência.  Em seguida, você pode usar esse objeto de dados em sua função de colar.  
  
##  <a name="_core_destroying_data_objects"></a> Destruindo objetos de dados  
 Se você seguir o esquema descrito em [Criando objetos de dados](#_core_creating_data_objects), destruindo objetos de dados é um aspecto trivial de transferências de dados.  O objeto de dados que foi criado em sua função colar será destruído pelo MFC quando a função colar retornar.  
  
 Se você seguir outro método de manipulação de operações de colagem, verifique se que o objeto de dados é destruído depois que a operação de colagem for concluída.  Até que o objeto de dados é destruído, será impossível para qualquer aplicativo com êxito copiar dados para a área de transferência.  
  
##  <a name="_core_creating_data_sources"></a> Criar fontes de dados  
 Fontes de dados são usados pela fonte de transferência de dados, que pode ser o cliente ou no lado do servidor de transferência de dados.  Uma fonte de dados no aplicativo de origem é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino.  Um objeto de dados no aplicativo de destino é usado para interagir com os dados na fonte de dados.  
  
 Fontes de dados são criados quando um aplicativo precisa copiar dados para a área de transferência.  Um cenário típico é executado como esta:  
  
1.  O usuário seleciona alguns dados.  
  
2.  O usuário escolhe **cópia** \(ou **Recortar**\) do **Editar** menu ou inicia uma operação de arrastar e soltar.  
  
3.  Dependendo do design do programa, o aplicativo cria uma uma `COleDataSource` objeto ou um objeto de uma classe derivada de `COleDataSource`.  
  
4.  Os dados selecionados são inseridos na fonte de dados chamando uma das funções de `COleDataSource::CacheData` ou `COleDataSource::DelayRenderData` grupos.  
  
5.  O aplicativo chama o `SetClipboard` função de membro \(ou a `DoDragDrop` a função de membro se esta é uma operação de arrastar e soltar\) que pertence ao objeto criado na etapa 3.  
  
6.  Se esse for um **Recortar** operação ou `DoDragDrop` retorna `DROPEFFECT_MOVE`, os dados selecionados na etapa 1 for excluídos do documento.  
  
 Este cenário é implementado pelos exemplos MFC OLE [OCLIENT](../top/visual-cpp-samples.md) e [HIERSVR](../top/visual-cpp-samples.md).  No código\-fonte para cada aplicativo `CView`\-derivado da classe para todos menos para o `GetClipboardData` e `OnGetClipboardData` funções.  Essas duas funções estão em ambos os `COleClientItem` ou `COleServerItem`\-derivadas implementações da classe.  Esses programas de exemplo fornecem um bom exemplo de como implementar esses conceitos.  
  
 Uma outra situação em que você talvez queira criar um `COleDataSource` objeto ocorre se você estiver modificando o comportamento padrão de uma operação de arrastar e soltar.  Para obter mais informações, consulte o [arrastar e soltar: Personalizando](../Topic/Drag%20and%20Drop:%20Customizing.md) artigo.  
  
##  <a name="_core_destroying_data_sources"></a> Destruição de fontes de dados  
 Fontes de dados devem ser destruídos pelo aplicativo atualmente é responsável por eles.  Em situações onde você transferir a fonte de dados para OLE, como chamar [COleDataSource::DoDragDrop](../Topic/COleDataSource::DoDragDrop.md), é necessário chamar **pDataSrc \-\> InternalRelease**.  Por exemplo:  
  
 [!CODE [NVC_MFCListView#1](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCListView#1)]  
  
 Se você não tiver enviado sua fonte de dados para OLE, em seguida, você é responsável por destruí\-lo, assim como acontece com qualquer objeto de C\+\+ típico.  
  
 Para obter mais informações, consulte [arrastar e soltar](../mfc/drag-and-drop-ole.md), [área de transferência](../mfc/clipboard.md), e [fontes de dados e objetos de manipulação de dados](../mfc/data-objects-and-data-sources-manipulation.md).  
  
## Consulte também  
 [Objetos e origens de dados \(OLE\)](../mfc/data-objects-and-data-sources-ole.md)   
 [Classe de COleDataObject](../mfc/reference/coledataobject-class.md)   
 [Classe de COleDataSource](../mfc/reference/coledatasource-class.md)