---
title: 'Menus e recursos: adições de contêiner'
ms.date: 11/04/2016
f1_keywords:
- IDP_OLE_INIT_FAILED
- IDP_FAILED_TO_CREATE
- VK_ESCAPE
helpviewer_keywords:
- application accelerator table [MFC]
- VK_ESCAPE key [MFC]
- IDP_FAILED_TO_CREATE macro [MFC]
- visual editing, application menus and resources
- OLE containers [MFC], menus and resources
- accelerator tables [MFC], container applications
- IDP_OLE_INIT_FAILED macro [MFC]
- CONTAIN tutorial [MFC]
- Links menu item [MFC]
ms.assetid: 425448be-8ca0-412e-909a-a3a9ce845288
ms.openlocfilehash: c8da58316f471f7b7d26e142cc1dd1ccaa6ad8b5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364788"
---
# <a name="menus-and-resources-container-additions"></a>Menus e recursos: adições de contêiner

Este artigo explica as mudanças que precisam ser feitas nos menus e outros recursos em um aplicativo de contêiner de edição visual.

Nas aplicações de contêineres, dois tipos de alterações precisam ser feitas: modificações nos recursos existentes para suportar a edição visual do OLE e a adição de novos recursos utilizados para ativação no local. Se você usar o assistente do aplicativo para criar seu aplicativo de contêiner, essas etapas serão feitas para você, mas elas podem exigir alguma personalização.

Se você não usar o assistente do aplicativo, você pode querer olhar para OCLIENT. RC, o script de recursos para o aplicativo de amostra OCLIENT, para ver como essas alterações são implementadas. Consulte a amostra [OLE do](../overview/visual-cpp-samples.md)MFC OCLIENT .

Os tópicos abordados neste artigo incluem:

- [Adições do menu do contêiner](#_core_container_menu_additions)

- [Adições da tabela do acelerador](#_core_container_application_accelerator_table_additions)

- [Adições de tabela de cordas](#_core_string_table_additions_for_container_applications)

## <a name="container-menu-additions"></a><a name="_core_container_menu_additions"></a>Adições do menu do contêiner

Você deve adicionar os seguintes itens ao menu Editar:

|Item|Finalidade|
|----------|-------------|
|**Inserir novo objeto**|Abre a caixa de diálogo Inserir objeto oLE para inserir um item vinculado ou incorporado no documento.|
|**Link de colar**|Cole um link para o item na Área de Transferência no documento.|
|**Verbo OLE**|Chama o verbo principal do item selecionado. O texto deste item do menu muda para refletir o verbo principal do item selecionado.|
|**Links**|Abre a caixa de diálogo OLE Edit Links para alterar itens vinculados existentes.|

Além das alterações listadas neste artigo, seu arquivo de origem deve incluir AFXOLECL. RC, que é necessário para a implementação da Biblioteca de Classe da Microsoft Foundation. Inserir Novo objeto é a única adição de menu necessária. Outros itens podem ser adicionados, mas os listados aqui são os mais comuns.

Você deve criar um novo menu para o aplicativo de contêiner se quiser suportar a ativação no local de itens contidos. Este menu consiste no mesmo menu Arquivo e menus pop-up da janela usados quando os arquivos estão abertos, mas tem dois separadores colocados entre eles. Esses separadores são usados para indicar onde o item servidor (componente) (aplicativo) deve colocar seus menus quando ativado no lugar. Para obter mais informações sobre esta técnica de fusão de [menus, consulte Menus e Recursos: Fusão de menus](../mfc/menus-and-resources-menu-merging.md).

## <a name="container-application-accelerator-table-additions"></a><a name="_core_container_application_accelerator_table_additions"></a>Adições da tabela do acelerador de aplicativos de contêiner

Pequenas alterações nos recursos da tabela aceleradora de um aplicativo de contêiner são necessárias se você estiver suportando ativação no local. A primeira alteração permite que o usuário pressione a tecla de fuga (ESC) para cancelar o modo de edição no local. Adicione a seguinte entrada à tabela principal do acelerador:

|ID|Chave|Type|
|--------|---------|----------|
|ID_CANCEL_EDIT_CNTR|Vk_escape|**VIRTKEY**|

A segunda mudança é criar uma nova tabela de acelerador que corresponda ao novo recurso de menu criado para ativação no local. Esta tabela tem entradas para os menus Arquivo e Janela, além da entrada VK_ESCAPE acima. O exemplo a seguir é a tabela do acelerador criada para ativação no local no [RECIPIENTE](../overview/visual-cpp-samples.md)de amostra MFC :

|ID|Chave|Type|
|--------|---------|----------|
|Id_file_new|Ctrl+N|**VIRTKEY**|
|Id_file_open|Ctrl+O|**VIRTKEY**|
|Id_file_save|Ctrl+S|**VIRTKEY**|
|Id_file_print|CTRL+P|**VIRTKEY**|
|ID_NEXT_PANE|VK_F6|**VIRTKEY**|
|ID_PREV_PANE|SHIFT+VK_F6|**VIRTKEY**|
|ID_CANCEL_EDIT_CNTR|Vk_escape|**VIRTKEY**|

## <a name="string-table-additions-for-container-applications"></a><a name="_core_string_table_additions_for_container_applications"></a>Adições de tabela de cordas para aplicações de contêiner

A maioria das alterações nas tabelas de strings para aplicativos de contêiner correspondem aos itens adicionais do menu mencionados em [Adições de menu de contêiner](#_core_container_menu_additions). Eles fornecem o texto exibido na barra de status quando cada item do menu é exibido. Como exemplo, aqui estão as entradas de tabela de strings que o assistente de aplicativo gera:

|ID|String|
|--------|------------|
|IDP_OLE_INIT_FAILED|A inicialização do OLE falhou. Certifique-se de que as bibliotecas OLE são a versão correta.|
|IDP_FAILED_TO_CREATE|Falha ao criar objeto. Certifique-se de que o objeto está inserido no registro do sistema.|

## <a name="see-also"></a>Confira também

[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md)
