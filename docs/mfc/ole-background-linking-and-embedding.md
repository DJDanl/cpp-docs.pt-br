---
title: "Plano de fundo OLE: vinculando e inserindo | Microsoft Docs"
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
  - "objetos inseridos [C++]"
  - "tipos de item"
  - "tipos de item, definido"
  - "itens vinculados (OLE) [C++]"
  - "itens inseridos OLE"
  - "Itens OLE, tipos"
  - "OLE, itens vinculados"
ms.assetid: 11107711-eb96-4099-8f5c-7910bb3ecb75
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Plano de fundo OLE: vinculando e inserindo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usar o comando da pasta em um aplicativo de contêiner pode criar um componente inserida, ou o item inserido.  Os dados de origem para um item inserido são armazenados como parte do documento OLE que o contém.  Dessa forma, um arquivo de documento para um documento de tratamento de textos pode conter texto e também pode conter bitmaps, gráficos, fórmulas, ou qualquer outro tipo de dados.  
  
 OLE fornece uma outra maneira de inserir dados de outro aplicativo: criação de um componente vinculado, ou item vinculado, ou um link.  As etapas para criar um item vinculado são semelhantes para criar um item inserido, exceto que você usa o comando de link de pasta em vez de comando da pasta.  Ao contrário de um componente inserida, um componente vinculado armazena um caminho para os dados originais, que são frequentemente em um arquivo separado.  
  
 Por exemplo, se você estiver trabalhando em um documento de tratamento de textos e cria um item vinculado a algumas células na planilha, os dados para o item vinculado são armazenados no documento original da planilha.  O documento de tratamento de textos contém apenas as informações que especifica onde o item pode ser localizado, ou seja, contém um link para o documento original da planilha.  Quando você clicar duas vezes nas células, o aplicativo de planilha é iniciado e o documento original da planilha é carregado de onde foi armazenado.  
  
 Cada item OLE, se inserido ou vinculado, tem um tipo associado a ele com base no aplicativo que o criou.  Por exemplo, um item de pincel do Microsoft é um tipo de item, e um item do Microsoft Excel é outro tipo.  Alguns aplicativos, porém, podem criar mais de um tipo de item.  Por exemplo, Microsoft Excel pode criar itens da planilha, itens do gráfico, e itens de macrosheet.  Cada um desses itens pode ser identificada exclusivamente pelo sistema usando um identificador ou **CLSID**da classe.  
  
## Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Plano de fundo OLE: contêineres e servidores](../mfc/ole-background-containers-and-servers.md)   
 [Contêineres: itens clientes](../mfc/containers-client-items.md)   
 [Servidores: itens de servidor](../mfc/servers-server-items.md)