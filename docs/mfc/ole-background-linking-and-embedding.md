---
title: 'Plano de fundo OLE: Vinculando e inserindo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE embedded items [MFC]
- item types [MFC], defined
- item types [MFC]
- OLE [MFC], linked items
- linked items (OLE) [MFC]
- embedded objects [MFC]
- OLE items [MFC], types
ms.assetid: 11107711-eb96-4099-8f5c-7910bb3ecb75
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c5dc7a5770c98323187dbabcd8c2a7bb9eb652de
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347273"
---
# <a name="ole-background-linking-and-embedding"></a>tela de fundo OLE: vinculando e inserindo
Usando o comando Colar em um aplicativo de contêiner pode criar um componente incorporado ou item inserido. Os dados de origem para um item inserido são armazenados como parte do documento OLE que o contém. Dessa forma, um arquivo de documento para um documento do processador de texto pode conter texto e também pode conter bitmaps, gráficos, fórmulas ou qualquer outro tipo de dados.  
  
 OLE oferece uma maneira para incorporar dados de outro aplicativo: Criando um componente vinculado, ou o item vinculado ou um link. As etapas para criar um item vinculado são semelhantes aos usados para criar um item inserido, exceto pelo fato de você usar o comando Colar vínculo em vez do comando Colar. Ao contrário de um componente incorporado, um componente vinculado armazena um caminho para os dados originais, que é geralmente em um arquivo separado.  
  
 Por exemplo, se você estiver trabalhando em uma palavra documento de processador e cria um item vinculado a algumas células da planilha, os dados para o item vinculado são armazenados no documento original da planilha. O documento de processador de texto contém apenas as informações que especificam onde o item pode ser encontrado, ou seja, ele contém um link para o documento de planilha original. Quando você clicar duas vezes as células, o aplicativo de planilha é iniciado e o documento de planilha original será carregado a partir de onde ele foi armazenado.  
  
 Cada item OLE, se incorporado ou vinculado, tem um tipo associado com base no aplicativo que o criou. Por exemplo, um item de Microsoft Paintbrush é um tipo de item e um item do Microsoft Excel é outro tipo. No entanto, alguns aplicativos, podem criar mais de um tipo de item. Por exemplo, o Microsoft Excel pode criar itens de planilha, itens do gráfico e itens de folha de macro. Cada um desses itens pode ser identificada exclusivamente pelo sistema usando um identificador de classe ou **CLSID**.  
  
## <a name="see-also"></a>Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Plano de fundo OLE: Contêineres e servidores](../mfc/ole-background-containers-and-servers.md)   
 [Contêineres: Itens clientes](../mfc/containers-client-items.md)   
 [Servidores: itens de servidor](../mfc/servers-server-items.md)

