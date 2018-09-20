---
title: 'Tela de fundo OLE: Vinculando e inserindo | Microsoft Docs'
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
ms.openlocfilehash: 2d4456e5210b2ec1e142c7ddeddd7b0e7fab9f31
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46445900"
---
# <a name="ole-background-linking-and-embedding"></a>tela de fundo OLE: vinculando e inserindo

Usando o comando Colar em um aplicativo de contêiner pode criar um componente incorporado, ou o item inserido. Os dados de origem para um item inserido são armazenados como parte do documento OLE que o contém. Dessa forma, um arquivo de documento para um documento do processador de texto pode conter texto e também pode conter bitmaps, gráficos, fórmulas ou qualquer outro tipo de dados.

A OLE fornece outra maneira de incorporar dados de outro aplicativo: Criando um componente vinculado, ou o item vinculado ou um link. As etapas para a criação de um item vinculado são semelhantes àquelas para a criação de um item inserido, exceto pelo fato de você usar o comando Colar vínculo em vez do comando Colar. Ao contrário de um componente incorporado, o componente vinculado armazena um caminho para os dados originais, que é geralmente em um arquivo separado.

Por exemplo, se você estiver trabalhando em uma palavra de documento do processador e criar um item vinculado a algumas células da planilha, os dados para o item vinculado são armazenados no documento original da planilha. O documento de processador de texto contém apenas as informações de especificação de onde o item pode ser encontrado, ou seja, ele contém um link para o documento de planilha original. Quando você clica duas vezes as células, o aplicativo de planilha é iniciado e o documento de planilha original é carregado a partir de onde ele foi armazenado.

Todos os itens OLE, se incorporado ou vinculado, tem um tipo associado a ele com base no aplicativo que o criou. Por exemplo, um item do Microsoft Paintbrush é um tipo de item e um item do Microsoft Excel é outro tipo. No entanto, alguns aplicativos, podem criar mais de um tipo de item. Por exemplo, o Microsoft Excel pode criar itens de planilha, itens do gráfico e itens de folha de macro. Cada um desses itens pode ser identificada exclusivamente pelo sistema usando um identificador de classe ou **CLSID**.

## <a name="see-also"></a>Consulte também

[Tela de fundo OLE](../mfc/ole-background.md)<br/>
[Tela de fundo OLE: contêineres e servidores](../mfc/ole-background-containers-and-servers.md)<br/>
[Contêineres: itens clientes](../mfc/containers-client-items.md)<br/>
[Servidores: itens de servidor](../mfc/servers-server-items.md)

