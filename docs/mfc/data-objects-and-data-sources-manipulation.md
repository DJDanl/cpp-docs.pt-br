---
title: "Objetos de dados e fontes de dados: manipulação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- data objects [MFC], manipulating
- data sources [MFC], data operations
- data sources [MFC], inserting data
- Clipboard [MFC], determining available formats
- OLE [MFC], data objects
- Clipboard [MFC], passing format information
- data sources [MFC], determining available formats
- delayed rendering [MFC]
- OLE [MFC], data sources
ms.assetid: f7f27e77-bb5d-4131-b819-d71bf929ebaf
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 40bd83b2e472ff1b1e5d277c27a801b0750fb160
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="data-objects-and-data-sources-manipulation"></a>Objetos e origens de dados: manipulação
Depois que um objeto de dados ou fonte de dados tiver sido criado, você pode executar várias operações comuns nos dados, como inserção e remoção de dados, enumerando os formatos de que dados se encontra e muito mais. Este artigo descreve as técnicas necessárias para concluir as operações mais comuns. Os tópicos incluem:  
  
-   [Inserindo dados em uma fonte de dados](#_core_inserting_data_into_a_data_source)  
  
-   [Determinando os formatos disponíveis em um objeto de dados](#_core_determining_the_formats_available_in_a_data_object)  
  
-   [Recuperando dados de um objeto de dados](#_core_retrieving_data_from_a_data_object)  
  
##  <a name="_core_inserting_data_into_a_data_source"></a>Inserindo dados em uma fonte de dados  
 Como os dados são inseridos em uma fonte de dados depende se os dados são fornecidos imediatamente ou sob demanda e em qual médio é fornecido. As possibilidades são da seguinte maneira.  
  
### <a name="supplying-data-immediately-immediate-rendering"></a>Fornecendo dados imediatamente (renderização imediata)  
  
-   Chamar `COleDataSource::CacheGlobalData` repetidamente para cada formato de área de transferência no qual você está fornecendo os dados. Passe o formato de área de transferência a ser usada, um identificador para a memória que contém os dados e, opcionalmente, um **FORMATETC** estrutura que descreve os dados.  
  
     -ou-  
  
-   Se você quiser trabalhar diretamente com **STGMEDIUM** estruturas, chame `COleDataSource::CacheData` em vez de `COleDataSource::CacheGlobalData` na opção acima.  
  
### <a name="supplying-data-on-demand-delayed-rendering"></a>Fornece dados sob demanda (renderização atrasada)  
 Este é um tópico avançado.  
  
-   Chamar `COleDataSource::DelayRenderData` repetidamente para cada formato de área de transferência no qual você está fornecendo os dados. Passe o formato de área de transferência a ser usado e, opcionalmente, um **FORMATETC** estrutura que descreve os dados. Quando os dados são solicitados, a estrutura chamará `COleDataSource::OnRenderData`, que você deve substituir.  
  
     -ou-  
  
-   Se você usar um `CFile` objeto para fornecer os dados, chame `COleDataSource::DelayRenderFileData` em vez de `COleDataSource::DelayRenderData` na opção anterior. Quando os dados são solicitados, a estrutura chamará `COleDataSource::OnRenderFileData`, que você deve substituir.  
  
##  <a name="_core_determining_the_formats_available_in_a_data_object"></a>Determinando os formatos disponíveis em um objeto de dados  
 Antes de um aplicativo permite que o usuário colar dados ele, ele precisa saber se há formatos na área de transferência que pode manipular. Para fazer isso, seu aplicativo deve fazer o seguinte:  
  
1.  Criar um `COleDataObject` objeto e um **FORMATETC** estrutura.  
  
2.  Chamar o objeto de dados `AttachClipboard` a função de membro para associar o objeto de dados com os dados na área de transferência.  
  
3.  Realize um dos seguintes procedimentos:  
  
    -   Chamar o objeto de dados `IsDataAvailable` função de membro, se houver apenas um ou dois formatos é necessário. Isso economizará tempo nos casos em que os dados na área de transferência oferece suporte aos formatos significativamente mais que seu aplicativo.  
  
         -ou-  
  
    -   Chamar o objeto de dados `BeginEnumFormats` a função de membro para enumerar os formatos disponíveis na área de transferência. Em seguida, chamar `GetNextFormat` até retorna a área de transferência dá suporte a um formato de seu aplicativo ou não há mais formatos.  
  
 Se você estiver usando `ON_UPDATE_COMMAND_UI`, agora você pode habilitar a colar e, possivelmente, itens de colar especial no menu Editar. Para fazer isso, chame `CMenu::EnableMenuItem` ou `CCmdUI::Enable`. Para obter mais informações sobre o contêiner aplicativos devem fazer com itens de menu e quando, consulte [Menus e recursos: adições de contêiner](../mfc/menus-and-resources-container-additions.md).  
  
##  <a name="_core_retrieving_data_from_a_data_object"></a>Recuperando dados de um objeto de dados  
 Depois de ter decidido em um formato de dados, tudo o que resta é recuperar os dados do objeto de dados. Para fazer isso, o usuário decidir onde colocar os dados e o aplicativo chama a função apropriada. Os dados estarão disponíveis em um dos meios a seguir:  
  
|Médio|Função a ser chamada|  
|------------|----------------------|  
|Memória global (`HGLOBAL`)|`COleDataObject::GetGlobalData`|  
|Arquivo (`CFile`)|`COleDataObject::GetFileData`|  
|**STGMEDIUM** estrutura (`IStorage`)|`COleDataObject::GetData`|  
  
 Normalmente, a mídia será especificada junto com seu formato de área de transferência. Por exemplo, um **CF_EMBEDDEDSTRUCT** objeto estará sempre em uma `IStorage` médio que requer um **STGMEDIUM** estrutura. Portanto, você usaria `GetData` porque ele é o único dessas funções que pode aceitar um **STGMEDIUM** estrutura.  
  
 Para casos em que o formato de área de transferência está em um `IStream` ou `HGLOBAL` médio, a estrutura pode fornecer um `CFile` ponteiro que faz referência a dados. O aplicativo pode usar para obter os dados em grande parte da mesma maneira como ele pode importar dados de um arquivo de leitura de arquivo. Essencialmente, essa é a interface de cliente para o `OnRenderData` e `OnRenderFileData` rotinas na fonte de dados.  
  
 O usuário pode agora inserir dados no documento, assim como todos os outros dados no mesmo formato.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Arrastar e soltar](../mfc/drag-and-drop-ole.md)  
  
-   [Área de transferência](../mfc/clipboard.md)  
  
## <a name="see-also"></a>Consulte também  
 [Objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md)   
 [Classe COleDataObject](../mfc/reference/coledataobject-class.md)   
 [Classe COleDataSource](../mfc/reference/coledatasource-class.md)
