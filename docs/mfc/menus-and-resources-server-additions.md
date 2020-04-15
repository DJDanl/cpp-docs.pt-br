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
ms.openlocfilehash: 8366cd8b0376766b7914c94a24cef6598761a805
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375982"
---
# <a name="menus-and-resources-server-additions"></a>Menus e recursos: adições de servidor

Este artigo explica as alterações que precisam ser feitas nos menus e outros recursos em um aplicativo de servidor de edição visual (componente). Um aplicativo de servidor requer muitas adições à estrutura do menu e outros recursos porque ele pode ser iniciado em um dos três modos: ficar sozinho, incorporado ou no lugar. Conforme descrito no artigo [Menus and Resources (OLE),](../mfc/menus-and-resources-ole.md) existem no máximo quatro conjuntos de menus. Todos os quatro são usados para um aplicativo de servidor completo MDI, enquanto apenas três são usados para um miniservidor. O assistente de aplicativo criará o layout do menu necessário para o tipo de servidor que você deseja. Alguma personalização pode ser necessária.

Se você não usar o assistente do aplicativo, você pode querer olhar para HIERSVR. RC, o script de recursos do aplicativo de amostra MFC [HIERSVR](../overview/visual-cpp-samples.md), para ver como essas alterações são implementadas.

Os tópicos abordados neste artigo incluem:

- [Adições do menu do servidor](#_core_server_menu_additions)

- [Adições da tabela do acelerador](#_core_server_application_accelerator_table_additions)

- [Adições de tabela de cordas](../mfc/menus-and-resources-container-additions.md)

- [Adições de miniservidor](#_core_mini.2d.server_additions)

## <a name="server-menu-additions"></a><a name="_core_server_menu_additions"></a>Adições do menu do servidor

Os aplicativos do servidor (componente) devem ter recursos de menu adicionados para suportar a edição visual do OLE. Os menus usados quando o aplicativo é executado no modo autônomo não precisam ser alterados, mas você deve adicionar dois novos recursos de menu antes de criar o aplicativo: um para suportar a ativação no local e outro para suportar que o servidor esteja totalmente aberto. Ambos os recursos do menu são usados por aplicativos completos e miniservidores.

- Para suportar a ativação no local, você deve criar um recurso de menu muito semelhante ao recurso de menu usado quando executado no modo autônomo. A diferença neste menu é que os itens Arquivo e Janela (e quaisquer outros itens do menu que lidam com o aplicativo, e não os dados) estão faltando. A aplicação do contêiner fornecerá esses itens do menu. Para obter mais informações e um exemplo dessa técnica de fusão de menus, consulte o artigo [Menus e Recursos: Menumerging .](../mfc/menus-and-resources-menu-merging.md)

- Para suportar a ativação totalmente aberta, você deve criar um recurso de menu quase idêntico ao recurso de menu usado quando executado no modo autônomo. A única modificação neste recurso de menu é que alguns itens são reformulados para refletir o fato de que o servidor está operando em um item incorporado em um documento composto.

Além das alterações listadas neste artigo, seu arquivo de recursos precisa incluir AFXOLESV. RC, que é necessário para a implementação da Biblioteca de Classe da Microsoft Foundation. Este arquivo está no subdiretório MFC\Incluir.

## <a name="server-application-accelerator-table-additions"></a><a name="_core_server_application_accelerator_table_additions"></a>Adições da tabela do acelerador de aplicativos do servidor

Dois novos recursos da tabela do acelerador devem ser adicionados aos aplicativos do servidor; eles correspondem diretamente aos novos recursos do menu descritos anteriormente. A primeira tabela do acelerador é usada quando o aplicativo do servidor é ativado no lugar. Ele consiste em todas as entradas na tabela do acelerador da exibição, exceto aquelas vinculadas aos menus Arquivo e Janela.

A segunda tabela é quase uma cópia exata da tabela do acelerador da vista. Quaisquer diferenças de alterações paralelas feitas no menu totalmente aberto mencionado [suscitado suscitado suscitado suscitados](#_core_server_menu_additions)no Menu de Adições do Servidor .

Para um exemplo dessas mudanças na tabela do acelerador, compare as tabelas de acelerador IDR_HIERSVRTYPE_SRVR_IP e IDR_HIERSVRTYPE_SRVR_EMB com IDR_MAINFRAME no HIERSVR. Arquivo RC incluído na amostra DeRFC [OLE HIERSVR](../overview/visual-cpp-samples.md). Os aceleradores de arquivo e janela estão faltando na tabela no lugar e cópias exatas deles estão na tabela incorporada.

## <a name="string-table-additions-for-server-applications"></a><a name="_core_string_table_additions_for_server_applications"></a>Adições de tabela de strings para aplicativos de servidor

Apenas uma adição de tabela de strings é necessária em um aplicativo de servidor — uma string para significar que a inicialização do OLE falhou. Como exemplo, aqui está a entrada de tabela de strings que o assistente de aplicativo gera:

|ID|String|
|--------|------------|
|IDP_OLE_INIT_FAILED|A inicialização do OLE falhou. Certifique-se de que as bibliotecas OLE são a versão correta.|

## <a name="miniserver-additions"></a><a name="_core_mini.2d.server_additions"></a>Adições de miniservidor

As mesmas adições se aplicam a miniservidores como os listados acima para servidores completos. Como um miniservidor não pode ser executado no modo autônomo, seu menu principal é muito menor. O menu principal criado pelo assistente do aplicativo tem apenas um menu Arquivo, contendo apenas os itens Saída e Sobre. Menus e aceleradores incorporados e no local para miniservidores são os mesmos dos servidores completos.

## <a name="see-also"></a>Confira também

[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Menus e recursos: mesclagem de menu](../mfc/menus-and-resources-menu-merging.md)
