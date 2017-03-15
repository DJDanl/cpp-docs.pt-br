---
title: "Controles ActiveX MFC: serializando | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_wVerMinor"
  - "DoPropExchange"
  - "_wVerMajor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método DoPropExchange"
  - "Método ExchangeVersion"
  - "Método GetVersion"
  - "Controles ActiveX MFC, serializando"
  - "Controles ActiveX MFC, suporte a versões"
  - "controlando a versão de controles ActiveX"
  - "Constante global wVerMajor"
  - "Constante global wVerMinor"
ms.assetid: 9d57c290-dd8c-4853-b552-6f17f15ebedd
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: serializando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como serializar um controle ActiveX.  A serialização é o processo de leitura de ou de gravação em um meio do repositório persistente, como um arquivo em disco.  A biblioteca de \(MFC\) da classe do Microsoft fornece suporte interno para serialização na classe `CObject`.  `COleControl` estende esse suporte aos controles ActiveX com o uso de um mecanismo de troca da propriedade.  
  
 A serialização de controles ActiveX é implementada substituindo [COleControl::DoPropExchange](../Topic/COleControl::DoPropExchange.md).  Esses função, chamados durante as ações de carregar e salvar do objeto de controle, que armazena todas as propriedades implementaram com uma variável de membro ou uma variável de membro com notificação de alteração.  
  
 Os tópicos a seguir descrevem os problemas principais relacionadas a serializar um controle ActiveX:  
  
-   Implementando a função de `DoPropExchange` para serializar o objeto de controle  
  
-   [Personalizando o processo de serialização](#_core_customizing_the_default_behavior_of_dopropexchange)  
  
-   [Implementando suporte da versão](#_core_implementing_version_support)  
  
##  <a name="_core_implementing_the_dopropexchange_function"></a> Implementando a função de DoPropExchange  
 Quando você usa o assistente de controle ActiveX para gerar o projeto de controle, várias funções padrão do manipulador são adicionadas automaticamente a classe de controle, incluindo a implementação padrão de [COleControl::DoPropExchange](../Topic/COleControl::DoPropExchange.md).  O exemplo a seguir mostra o código adicionado a classes criadas com o assistente do controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxUI#43](../mfc/codesnippet/CPP/mfc-activex-controls-serializing_1.cpp)]  
  
 Se você quiser fazer uma propriedade persistente, modifique `DoPropExchange` adicionando uma chamada à função de troca da propriedade.  O exemplo a seguir demonstra a serialização de uma propriedade booliana personalizado de CircleShape, onde a propriedade de CircleShape tem um valor padrão de **Verdadeiro**:  
  
 [!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/CPP/mfc-activex-controls-serializing_2.cpp)]  
[!code-cpp[NVC_MFC_AxSer#2](../mfc/codesnippet/CPP/mfc-activex-controls-serializing_3.cpp)]  
  
 A tabela a seguir lista as funções que possíveis de troca da propriedade você pode usar para serializar as propriedades de controle:  
  
|Funções de troca de propriedade|Finalidade|  
|-------------------------------------|----------------|  
|**PX\_Blob \(\)**|Serializa uma propriedade de dados \(BLOB\) de objeto binário grande\) do tipo.|  
|**PX\_Bool \(\)**|Serializa uma propriedade Booliana do tipo.|  
|**PX\_Color \(\)**|Serializa uma propriedade de cor do tipo.|  
|**PX\_Currency \(\)**|Serializa uma propriedade de **CY** tipo de moeda \(\).|  
|**PX\_Double \(\)**|Serializa uma propriedade de **double** do tipo.|  
|**PX\_Font \(\)**|Serializa uma propriedade do tipo de fonte.|  
|**PX\_Float \(\)**|Serializa uma propriedade de **float** do tipo.|  
|**PX\_IUnknown \(\)**|Serializa uma propriedade de tipo `LPUNKNOWN`.|  
|**PX\_Long \(\)**|Serializa uma propriedade de **long** do tipo.|  
|**PX\_Picture \(\)**|Serializa uma propriedade do tipo imagem.|  
|**PX\_Short \(\)**|Serializa uma propriedade de **short** do tipo.|  
|**PX\_String \(\)**|Serializa uma propriedade de `CString` do tipo.|  
|**PX\_ULong \(\)**|São serializados uma propriedade de **ULONG** do tipo.|  
|**PX\_UShort \(\)**|São serializados uma propriedade de **USHORT** do tipo.|  
  
 Para obter mais informações sobre essas funções de troca de propriedade, consulte [Persistência de controladores OLE](../mfc/reference/persistence-of-ole-controls.md)*na referência de MFC*.  
  
##  <a name="_core_customizing_the_default_behavior_of_dopropexchange"></a> Personalizando o comportamento padrão de DoPropExchange  
 A implementação padrão de **DoPropertyExchange** \(conforme mostrado no tópico anterior\) faz uma chamada à classe base `COleControl`.  Isso serializa o conjunto de propriedades suportadas automaticamente por `COleControl`, que usa mais espaço de armazenamento do que serializando somente as propriedades personalizadas do controle.  Remover essa chamada permite que seu objeto serializar apenas as propriedades que você considera importante.  Qualquer a propriedade de estoque indica que o controle implementou não será serializado ao salvar ou ao carregar o controle o objeto a menos que você adicione explicitamente chamadas de **PX\_** para eles.  
  
##  <a name="_core_implementing_version_support"></a> Implementando suporte da versão  
 O suporte para versão permite que um controle ActiveX revisado a seguir para adicionar novas propriedades persistentes, e ainda conseguirá detectar e carregar o estado persistente criado por uma versão anterior do controle.  Para fazer a versão de um controle disponível como parte dos dados persistentes, chame [COleControl::ExchangeVersion](../Topic/COleControl::ExchangeVersion.md) na função de `DoPropExchange` do controle.  Essa chamada é inserido automaticamente se o controle ActiveX foi criado usando o assistente de controle ActiveX.  Poderá ser descartado se o suporte da versão não é necessário.  No entanto, o custo no tamanho de controle são muito pequenos \(4 bytes\) para flexibilidade adicionada que o suporte da versão fornece.  
  
 Se o controle não foi criado com o assistente de controle ActiveX, adicione uma chamada a `COleControl::ExchangeVersion` inserindo a seguinte linha no início da função de `DoPropExchange` \(antes da chamada a `COleControl::DoPropExchange`\):  
  
 [!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/CPP/mfc-activex-controls-serializing_2.cpp)]  
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/CPP/mfc-activex-controls-serializing_4.cpp)]  
  
 Você pode usar qualquer `DWORD` como o número da versão.  Projetos gerados pelo uso **\_wVerMinor** e **\_wVerMajor** do assistente do controle ActiveX como padrão.  Essas constantes são gerais definidos no arquivo de implementação da classe do controle ActiveX do projeto.  No restante da função de `DoPropExchange` , você pode chamar [CPropExchange::GetVersion](../Topic/CPropExchange::GetVersion.md) a qualquer momento para recuperar a versão que você está salvando ou está recuperando.  
  
 No exemplo a seguir, a versão 1 deste controle de exemplo tem apenas uma propriedade “ReleaseDate”.  A versão 2 adiciona uma propriedade “OriginalDate”.  Se o controle for instruído para carregar o estado persistente da versão antiga, inicializa a variável de membro para a nova propriedade como um valor padrão.  
  
 [!code-cpp[NVC_MFC_AxSer#4](../mfc/codesnippet/CPP/mfc-activex-controls-serializing_5.cpp)]  
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/CPP/mfc-activex-controls-serializing_4.cpp)]  
  
 Por padrão, um controle “” converte dados antigos para o formato a última vez.  Por exemplo, se a versão 2 de um controle carrega os dados que foram salvos pela versão 1, gravará o formato da versão 2 quando é salvo novamente.  Se você desejar controle para salvar dados na última leitura de formato, passe **Falso** como um terceiro parâmetro ao chamar `ExchangeVersion`.  O terceiro parâmetro é opcional e é **Verdadeiro** por padrão.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)