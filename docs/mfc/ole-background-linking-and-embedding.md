---
title: 'tela de fundo OLE: vinculando e inserindo'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE embedded items [MFC]
- item types [MFC], defined
- item types [MFC]
- OLE [MFC], linked items
- linked items (OLE) [MFC]
- embedded objects [MFC]
- OLE items [MFC], types
ms.assetid: 11107711-eb96-4099-8f5c-7910bb3ecb75
ms.openlocfilehash: 6b6032d2e772728495d4ddb1dbfaa5daf7348b60
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619880"
---
# <a name="ole-background-linking-and-embedding"></a>tela de fundo OLE: vinculando e inserindo

O uso do comando Paste em um aplicativo de contêiner pode criar um componente inserido ou um item incorporado. Os dados de origem de um item inserido são armazenados como parte do documento OLE que o contém. Dessa forma, um arquivo de documento para um documento de processador de texto pode conter texto e também pode conter bitmaps, grafos, fórmulas ou qualquer outro tipo de dados.

O OLE fornece outra maneira de incorporar dados de outro aplicativo: criar um componente vinculado, um item vinculado ou um link. As etapas para criar um item vinculado são semelhantes àquelas para criar um item inserido, exceto pelo uso do comando Paste link em vez do comando Paste. Ao contrário de um componente incorporado, um componente vinculado armazena um caminho para os dados originais, que geralmente está em um arquivo separado.

Por exemplo, se você estiver trabalhando em um documento do processador de texto e criar um item vinculado a algumas células da planilha, os dados do item vinculado serão armazenados no documento da planilha original. O documento do processador de texto contém apenas as informações que especificam onde o item pode ser encontrado, ou seja, contém um link para o documento da planilha original. Quando você clica duas vezes nas células, o aplicativo de planilha é iniciado e o documento de planilha original é carregado de onde ele foi armazenado.

Cada item OLE, incorporado ou vinculado, tem um tipo associado a ele com base no aplicativo que o criou. Por exemplo, um item do Microsoft Paintbrush é um tipo de item e um item do Microsoft Excel é outro tipo. Alguns aplicativos, no entanto, podem criar mais de um tipo de item. Por exemplo, o Microsoft Excel pode criar itens de planilha, itens de gráfico e itens de folha de quadro. Cada um desses itens pode ser identificado exclusivamente pelo sistema usando um identificador de classe ou **CLSID**.

## <a name="see-also"></a>Consulte também

[tela de fundo OLE](ole-background.md)<br/>
[Tela de fundo OLE: contêineres e servidores](ole-background-containers-and-servers.md)<br/>
[Contêineres: itens clientes](containers-client-items.md)<br/>
[Servidores: itens de servidor](servers-server-items.md)
