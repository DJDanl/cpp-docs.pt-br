---
title: "Objetos e origens de dados: manipula&#231;&#227;o | Microsoft Docs"
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
  - "Área de Transferência [C++], determinando formatos disponíveis"
  - "Área de Transferência [C++], transmitindo informações de formato"
  - "objetos de dados [C++], manipulando"
  - "fonte de dados [C++], operações de dados"
  - "fonte de dados [C++], determinando formatos disponíveis"
  - "fonte de dados [C++], inserindo dados"
  - "renderização atrasada [C++]"
  - "OLE [C++], objetos de dados"
  - "OLE [C++], fontes de dados"
ms.assetid: f7f27e77-bb5d-4131-b819-d71bf929ebaf
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Objetos e origens de dados: manipula&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Após um objeto de dados ou uma fonte de dados foi criado, você pode executar uma série de operações comuns nos dados, como inserir e removendo os dados, enumerando os formatos os dados estão em, e mais.  Este artigo descreve as técnicas necessárias para concluir as operações mais comuns.  Os tópicos incluem:  
  
-   [Inserindo dados em uma fonte de dados](#_core_inserting_data_into_a_data_source)  
  
-   [Determinando os formatos disponíveis em um objeto de dados](#_core_determining_the_formats_available_in_a_data_object)  
  
-   [Recuperando dados de um objeto de dados](#_core_retrieving_data_from_a_data_object)  
  
##  <a name="_core_inserting_data_into_a_data_source"></a> Inserindo dados em uma fonte de dados  
 Como os dados são inseridos em uma fonte de dados depende dos dados são fornecidos imediatamente ou sob demanda, e na metade é fornecido.  As possibilidades são como se segue.  
  
### Fornecendo dados imediatamente \(renderização imediata\)  
  
-   `COleDataSource::CacheGlobalData` chamada repetidamente para cada formato da área de transferência em que você estiver fornecendo dados.  Passe o formato da área de transferência sejam usados, um identificador para a memória que contêm dados e, opcionalmente, a uma estrutura de **FORMATETC** descrevendo os dados.  
  
     \- ou \-  
  
-   Se desejar trabalhar diretamente com estruturas de **STGMEDIUM** , chame `COleDataSource::CacheData` em vez de `COleDataSource::CacheGlobalData` na opção acima.  
  
### Fornecendo os dados sob demanda \(renderizar posteriores\)  
 Este é um tópico avançada.  
  
-   `COleDataSource::DelayRenderData` chamada repetidamente para cada formato da área de transferência em que você estiver fornecendo dados.  Passe o formato da área de transferência sejam usados e, opcionalmente, uma estrutura de **FORMATETC** que descrevem os dados.  Quando os dados são solicitados, a estrutura chamará `COleDataSource::OnRenderData`, que você deve substituir.  
  
     \- ou \-  
  
-   Se você usar um objeto de `CFile` para fornecer os dados, chame `COleDataSource::DelayRenderFileData` em vez de `COleDataSource::DelayRenderData` na opção anterior.  Quando os dados são solicitados, a estrutura chamará `COleDataSource::OnRenderFileData`, que você deve substituir.  
  
##  <a name="_core_determining_the_formats_available_in_a_data_object"></a> Determinando os formatos disponíveis em um objeto de dados  
 Antes que um aplicativo permite que o usuário cole dados nele, precisa saber se há formatos na área de transferência que pode lidar.  Para fazer isso, o aplicativo deve fazer o seguinte:  
  
1.  Crie um objeto de `COleDataObject` e uma estrutura de **FORMATETC** .  
  
2.  Chame a função de membro de `AttachClipboard` do objeto de dados para associar o objeto de dados com os dados na área de transferência.  
  
3.  Siga um destes procedimentos:  
  
    -   Chame a função de membro de `IsDataAvailable` do objeto de dados se houver apenas um ou dois formatos que você precisa.  Isso economizar tempo nos casos em que os dados na área de transferência significativamente mais suporte para formatos de seu aplicativo.  
  
         \- ou \-  
  
    -   Chame a função de membro de `BeginEnumFormats` do objeto de dados para iniciar a enumeração dos formatos disponíveis na área de transferência.  Chame `GetNextFormat` até que a área de transferência retorna um formato seus suporte do aplicativo ou não existam mais formato.  
  
 Se você estiver usando `ON_UPDATE_COMMAND_UI`, agora você pode habilitar a pasta e, possivelmente, para colar itens especiais no menu editar.  Para fazer isso, chame `CMenu::EnableMenuItem` ou `CCmdUI::Enable`.  Para obter mais informações sobre o que aplicativos de contêiner devem fazer com itens de menu e quando, consulte [Menus e recursos: Adições do contêiner](../mfc/menus-and-resources-container-additions.md).  
  
##  <a name="_core_retrieving_data_from_a_data_object"></a> Recuperando dados de um objeto de dados  
 Uma vez que você decidiu em um formato de dados, tudo que permanece é recuperar os dados do objeto de dados.  Para fazer isso, o usuário decidir onde colocar os dados, e o aplicativo chama a função apropriada.  Os dados estarão disponíveis em um dos seguintes: mídia  
  
|Médio|Função a ser chamada|  
|-----------|--------------------------|  
|Memória global \(`HGLOBAL`\)|`COleDataObject::GetGlobalData`|  
|Arquivo \(`CFile`\)|`COleDataObject::GetFileData`|  
|Estrutura de**STGMEDIUM** \(`IStorage`\)|`COleDataObject::GetData`|  
  
 Geralmente, o nome será especificado com o formato da área de transferência.  Por exemplo, um objeto de **CF\_EMBEDDEDSTRUCT** sempre está em um meio de `IStorage` que requer uma estrutura de **STGMEDIUM** .  Em virtude disso, você usaria `GetData` porque é único dessas funções que podem aceitar uma estrutura de **STGMEDIUM** .  
  
 Para os casos em que o formato da área de transferência está em um meio de `IStream` ou de `HGLOBAL` , a estrutura pode fornecer um ponteiro de `CFile` que faz referência aos dados.  O aplicativo pode usar a leitura do arquivo para obter os dados da mesma forma como ele pode importar dados de um arquivo.  Essencialmente, esta é a interface do lado do cliente para rotinas de `OnRenderData` e de `OnRenderFileData` na fonte de dados.  
  
 O usuário pode agora inserir dados no documento assim como para todos os outros dados no mesmo formato.  
  
### Que você deseja saber mais?  
  
-   [Arrastar e soltar](../mfc/drag-and-drop-ole.md)  
  
-   [Área de transferência](../mfc/clipboard.md)  
  
## Consulte também  
 [Objetos e origens de dados \(OLE\)](../mfc/data-objects-and-data-sources-ole.md)   
 [Classe de COleDataObject](../mfc/reference/coledataobject-class.md)   
 [Classe de COleDataSource](../mfc/reference/coledatasource-class.md)