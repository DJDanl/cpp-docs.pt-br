---
title: 'Menus e recursos: adições de servidor'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE visual editing servers [MFC]
- accelerator tables [MFC], server applications
- visual editing [MFC], application menus and resources
- server applications [MFC], accelerator table
- string tables [MFC], visual editing applications
- servers [MFC], menu additions
- resources [MFC], server applications
- OLE server applications [MFC], menus and resources
- string editing [MFC], visual editing applications
- IDP_OLE_INIT_FAILED macro [MFC]
- server applications [MFC], OLE menus and resources
- OLE initialization failure [MFC]
ms.assetid: 56ce9e8d-8f41-4db8-8dee-e8b0702d057c
ms.openlocfilehash: f67212dc7d4e2ab90421c7b2eee48acae4745940
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626178"
---
# <a name="menus-and-resources-server-additions"></a>Menus e recursos: adições de servidor

Este artigo explica as alterações que precisam ser feitas nos menus e outros recursos em um aplicativo de servidor de edição visual (componente). Um aplicativo de servidor requer muitas adições à estrutura do menu e a outros recursos, pois ele pode ser iniciado em um dos três modos: autônomo, inserido ou em vigor. Conforme descrito no artigo sobre [menus e recursos (OLE)](menus-and-resources-ole.md) , há um máximo de quatro conjuntos de menus. Todos os quatro são usados para um aplicativo MDI Full-Server, enquanto apenas três são usadas para um miniserver. O assistente de aplicativo criará o layout de menu necessário para o tipo de servidor desejado. Algumas personalizações podem ser necessárias.

Se você não usar o assistente de aplicativo, talvez você queira examinar HIERSVR. RC, o script de recurso para o aplicativo de exemplo do MFC [HIERSVR](../overview/visual-cpp-samples.md), para ver como essas alterações são implementadas.

Os tópicos abordados neste artigo incluem:

- [Adições de menu de servidor](#_core_server_menu_additions)

- [Adições de tabela de acelerador](#_core_server_application_accelerator_table_additions)

- [Adições de tabela de cadeia de caracteres](menus-and-resources-container-additions.md)

- [Adições de miniserver](#_core_mini.2d.server_additions)

## <a name="server-menu-additions"></a><a name="_core_server_menu_additions"></a>Adições de menu de servidor

Os aplicativos de servidor (componente) devem ter recursos de menu adicionados para dar suporte à edição Visual OLE. Os menus usados quando o aplicativo é executado no modo autônomo não precisam ser alterados, mas você deve adicionar dois novos recursos de menu antes de criar o aplicativo: um para dar suporte à ativação in-loco e outro para dar suporte totalmente ao servidor que está sendo aberto. Os dois recursos de menu são usados por aplicativos completos e miniservers.

- Para dar suporte à ativação in-loco, você deve criar um recurso de menu muito semelhante ao recurso de menu usado quando executado no modo autônomo. A diferença nesse menu é que os itens de arquivo e janela (e quaisquer outros itens de menu que lidam com o aplicativo e não os dados) estão ausentes. O aplicativo de contêiner fornecerá esses itens de menu. Para obter mais informações sobre o, e um exemplo de, essa técnica de mesclagem de menus, consulte o artigo [menus e recursos: mesclagem de menu](menus-and-resources-menu-merging.md).

- Para dar suporte à ativação totalmente aberta, você deve criar um recurso de menu praticamente idêntico ao recurso de menu usado quando executado no modo autônomo. A única modificação nesse recurso de menu é que alguns itens são refeitas para refletir o fato de que o servidor está operando em um item inserido em um documento composto.

Além das alterações listadas neste artigo, o arquivo de recursos precisa incluir AFXOLESV. RC, que é necessário para a implementação de biblioteca MFC. Esse arquivo está no subdiretório MFC\Include.

## <a name="server-application-accelerator-table-additions"></a><a name="_core_server_application_accelerator_table_additions"></a>Adições de tabelas do Server Application Accelerator

Dois novos recursos de tabela de acelerador devem ser adicionados aos aplicativos de servidor; Eles correspondem diretamente aos novos recursos de menu descritos anteriormente. A primeira tabela de acelerador é usada quando o aplicativo do servidor é ativado no local. Ele consiste em todas as entradas na tabela de acelerador de exibição, exceto aquelas vinculadas aos menus de arquivo e janela.

A segunda tabela é quase uma cópia exata da tabela de acelerador de exibição. Quaisquer alterações paralelas de diferenças feitas no menu totalmente aberto mencionado nas [adições de menu do servidor](#_core_server_menu_additions).

Para obter um exemplo dessas alterações na tabela aceleradora, compare as tabelas IDR_HIERSVRTYPE_SRVR_IP e IDR_HIERSVRTYPE_SRVR_EMB Accelerator com IDR_MAINFRAME no HIERSVR. Arquivo RC incluído no exemplo de OLE do MFC [HIERSVR](../overview/visual-cpp-samples.md). Os aceleradores de arquivo e janela estão ausentes da tabela in-loco e as cópias exatas deles estão na tabela incorporada.

## <a name="string-table-additions-for-server-applications"></a><a name="_core_string_table_additions_for_server_applications"></a>Adições de tabela de cadeia de caracteres para aplicativos de servidor

Somente uma adição de tabela de cadeia de caracteres é necessária em um aplicativo de servidor — uma cadeia de caracteres para significar que a inicialização OLE falhou. Por exemplo, aqui está a entrada da tabela de cadeia de caracteres que o assistente de aplicativo gera:

|ID|Cadeia de caracteres|
|--------|------------|
|IDP_OLE_INIT_FAILED|Falha na inicialização do OLE. Verifique se as bibliotecas OLE são da versão correta.|

## <a name="miniserver-additions"></a><a name="_core_mini.2d.server_additions"></a>Adições de miniserver

As mesmas adições se aplicam a miniservers como aquelas listadas acima para servidores completos. Como um miniserver não pode ser executado no modo autônomo, seu menu principal é muito menor. O menu principal criado pelo assistente de aplicativo tem apenas um menu File, contendo apenas os itens Exit e About. Os menus e Aceleradores incorporados e in-loco para miniservers são os mesmos dos servidores completos.

## <a name="see-also"></a>Consulte também

[Menus e recursos (OLE)](menus-and-resources-ole.md)<br/>
[Menus e recursos: mesclagem de menu](menus-and-resources-menu-merging.md)
