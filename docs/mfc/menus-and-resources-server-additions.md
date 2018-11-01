---
title: 'Menus e recursos: adições de servidor'
ms.date: 11/04/2016
f1_keywords:
- IDP_OLE_INIT_FAILED
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
ms.openlocfilehash: 8b4e7787029fc9401ece02860f09b8159f086afe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50592574"
---
# <a name="menus-and-resources-server-additions"></a>Menus e recursos: adições de servidor

Este artigo explica as alterações que precisam ser feitas para os menus e outros recursos em um aplicativo de servidor (componente) de edição visual. Um aplicativo de servidor requer muitas adições à estrutura do menu e outros recursos, porque ele pode ser iniciado em um dos três modos: espera sozinho, incorporado, ou em vigor. Conforme descrito na [Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md) do artigo, há um máximo de quatro conjuntos de menus. Todos os quatro são usados para um aplicativo de servidor completo MDI, enquanto apenas três são usados para um miniserver. O Assistente de aplicativo criará o layout de menu necessários para o tipo de servidor que você deseja. Alguma personalização pode ser necessária.

Se você não usar o Assistente de aplicativo, você talvez queira examinar HIERSVR. RC, o script de recurso para o aplicativo de exemplo do MFC [HIERSVR](../visual-cpp-samples.md), para ver como essas alterações são implementadas.

Os tópicos abordados neste artigo incluem:

- [Adições de Menu de servidor](#_core_server_menu_additions)

- [Adições de tabela do acelerador](#_core_server_application_accelerator_table_additions)

- [Adições de tabela de cadeia de caracteres](../mfc/menus-and-resources-container-additions.md)

- [Adições de miniserver](#_core_mini.2d.server_additions)

##  <a name="_core_server_menu_additions"></a> Adições de Menu de servidor

Aplicativos de servidor (componente) devem ter recursos de menu adicionados para dar suporte à edição visual do OLE. Os menus usados quando o aplicativo é executado no modo autônomo não precisam ser alteradas, mas você deve adicionar dois novos recursos de menu antes de compilar o aplicativo: uma para dar suporte à ativação no local e outra para suportar o servidor que está sendo totalmente aberta. Ambos os recursos de menu são usados por aplicativos e miniserver de completo.

- Para dar suporte à ativação in-loco, você deve criar um recurso de menu que é muito semelhante ao recurso de menu usado quando executado no modo autônomo. A diferença nesse menu é que os itens de arquivo e a janela (e outros itens de menu que lidam com o aplicativo e não os dados) estão ausentes. O aplicativo de contêiner fornecerá esses itens de menu. Para obter mais informações sobre e um exemplo, essa técnica de mesclagem de menu, consulte o artigo [Menus e recursos: mesclagem de Menu](../mfc/menus-and-resources-menu-merging.md).

- Para dar suporte à ativação totalmente aberta, você deve criar um recurso de menu quase idêntico para o recurso de menu usado quando executado no modo autônomo. A única modificação a esse recurso de menu é que alguns itens são reformuladas para refletir o fato de que o servidor está operando em um item inserido em um documento composto.

Além das alterações listadas neste artigo, seu arquivo de recurso precisa incluir AFXOLESV. RC, que é necessário para a implementação de biblioteca Microsoft Foundation Class. Esse arquivo está no subdiretório MFC\Include.

##  <a name="_core_server_application_accelerator_table_additions"></a> Adições de tabela do acelerador de aplicativo de servidor

Dois novos recursos de tabela do acelerador devem ser adicionados aos aplicativos de servidor; eles correspondem diretamente aos novos recursos de menu descritos anteriormente. A primeira tabela accelerator é usada quando o aplicativo de servidor é ativado em vigor. Ele consiste em todas as entradas na tabela de Aceleradores do modo de exibição, exceto aquelas vinculadas para o arquivo e a janela de menus.

A segunda tabela é quase uma cópia exata da tabela de Aceleradores do modo de exibição. Quaisquer diferenças em paralelo as alterações feitas no menu totalmente aberto mencionado na [adições de Menu de servidor](#_core_server_menu_additions).

Para obter um exemplo dessas alterações de tabela do acelerador, compare as tabelas de acelerador IDR_HIERSVRTYPE_SRVR_IP e IDR_HIERSVRTYPE_SRVR_EMB com IDR_MAINFRAME no HIERSVR. Arquivo RC incluído o exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md). Os aceleradores de arquivo e janela estão ausentes da tabela no local e cópias exatas de que eles estão na tabela inserida.

##  <a name="_core_string_table_additions_for_server_applications"></a> Adições de tabela de cadeia de caracteres para aplicativos de servidor

Adição de tabela apenas uma cadeia de caracteres é necessária em um aplicativo de servidor — uma cadeia de caracteres para indicar que houve falha na inicialização do OLE. Por exemplo, aqui está a entrada da tabela de cadeia de caracteres que o Assistente de aplicativo gera:

|ID|Cadeia de Caracteres|
|--------|------------|
|IDP_OLE_INIT_FAILED|Falha na inicialização do OLE. Certifique-se de que as bibliotecas OLE são da versão correta.|

##  <a name="_core_mini.2d.server_additions"></a> Adições de miniserver

As adições mesmas se aplicam para miniservers como aqueles listados acima para servidores de completo. Porque um miniserver não pode ser executado no modo autônomo, o menu principal é muito menor. O menu principal, criado pelo Assistente de aplicativo tem apenas um menu de arquivo, que contém apenas os itens de saída e em sobre. Menus incorporados e no local e aceleradores para miniservers são as mesmas para servidores de completo.

## <a name="see-also"></a>Consulte também

[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Menus e recursos: mesclagem de menu](../mfc/menus-and-resources-menu-merging.md)

