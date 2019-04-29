---
title: 'Menus e recursos: Adições de contêiner'
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
ms.openlocfilehash: b1a74fef743592d3d052226dac926fc7ddc58578
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62363460"
---
# <a name="menus-and-resources-container-additions"></a>Menus e recursos: Adições de contêiner

Este artigo explica as alterações que precisam ser feitas para os menus e outros recursos em um aplicativo de contêiner de edição visual.

Em aplicativos de contêiner, os dois tipos de alterações precisam ser feitas: modificações aos recursos existentes para dar suporte à edição visual do OLE e adição de novos recursos usada para ativação no local. Se você usar o Assistente de aplicativo para criar seu aplicativo de contêiner, essas etapas serão executadas para você, mas eles podem exigir alguma personalização.

Se você não usar o Assistente de aplicativo, você talvez queira examinar OCLIENT. RC, o script de recurso para o aplicativo de exemplo OCLIENT, para ver como essas alterações são implementadas. Consulte a amostra OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md).

Os tópicos abordados neste artigo incluem:

- [Adições de Menu do contêiner](#_core_container_menu_additions)

- [Adições de tabela do acelerador](#_core_container_application_accelerator_table_additions)

- [Adições de tabela de cadeia de caracteres](#_core_string_table_additions_for_container_applications)

##  <a name="_core_container_menu_additions"></a> Adições de Menu do contêiner

Você deve adicionar os itens a seguir para o menu Editar:

|Item|Finalidade|
|----------|-------------|
|**Inserir novo objeto**|Abre a caixa de diálogo Inserir objeto OLE para inserir um item vinculado ou inserido no documento.|
|**Paste Link**|Cola um link para o item na área de transferência no documento.|
|**OLE Verb**|Chama o verbo de principal do item selecionado. O texto desse item de menu muda para refletir o verbo primário do item selecionado.|
|**Links**|Abre a caixa de diálogo Editar Links do OLE para alterar os itens vinculados existentes.|

Além das alterações listadas neste artigo, seu arquivo de origem deve incluir AFXOLECL. RC, que é necessário para a implementação de biblioteca Microsoft Foundation Class. Inserir novo objeto é a adição de apenas menu necessária. Outros itens podem ser adicionados, mas os listados aqui são as mais comuns.

Você deve criar um novo menu para seu aplicativo de contêiner, se você quiser dar suporte à ativação no local de itens contidos. Esse menu consiste no mesmo menu de arquivo e os menus pop-up da janela usadas quando os arquivos estiverem abertos, mas ele tem dois separadores colocadas entre elas. Esses separadores são usados para indicar onde o item do servidor (componente) (aplicativo) deve colocar seus menus quando ativado em vigor. Para obter mais informações sobre essa técnica de mesclagem de menu, consulte [Menus e recursos: A mesclagem de menu](../mfc/menus-and-resources-menu-merging.md).

##  <a name="_core_container_application_accelerator_table_additions"></a> Adições de tabela do acelerador de aplicativo de contêiner

Pequenas alterações em recursos de tabela do acelerador do aplicativo de contêiner são necessárias se você estiver dando suporte à ativação no local. A primeira alteração permite que o usuário pressione a tecla de escape (ESC) para cancelar o modo de edição in-loco. Adicione a seguinte entrada à tabela principal de acelerador:

|ID|Chave|Tipo|
|--------|---------|----------|
|ID_CANCEL_EDIT_CNTR|VK_ESCAPE|**VIRTKEY**|

A segunda alteração é criar uma nova tabela do acelerador correspondente para o novo recurso de menu criado para ativação no local. Esta tabela tem entradas para os menus de arquivo e janela além da entrada VK_ESCAPE acima. O exemplo a seguir é a tabela de aceleradores criada para a ativação in-loco no exemplo de MFC [CONTÊINER](../overview/visual-cpp-samples.md):

|ID|Chave|Tipo|
|--------|---------|----------|
|ID_FILE_NEW|CTRL+N|**VIRTKEY**|
|ID_FILE_OPEN|CTRL+O|**VIRTKEY**|
|ID_FILE_SAVE|CTRL+S|**VIRTKEY**|
|ID_FILE_PRINT|CTRL + P|**VIRTKEY**|
|ID_NEXT_PANE|VK_F6|**VIRTKEY**|
|ID_PREV_PANE|SHIFT+VK_F6|**VIRTKEY**|
|ID_CANCEL_EDIT_CNTR|VK_ESCAPE|**VIRTKEY**|

##  <a name="_core_string_table_additions_for_container_applications"></a> Adições de tabela de cadeia de caracteres para aplicativos de contêiner

A maioria das alterações às tabelas de cadeia de caracteres para aplicativos de contêiner corresponde aos itens de menu adicionais mencionados [adições de Menu do contêiner](#_core_container_menu_additions). Eles fornecem o texto exibido na barra de status quando cada item de menu é exibido. Por exemplo, aqui estão as entradas de tabela de cadeia de caracteres que o Assistente de aplicativo gera:

|ID|Cadeia de Caracteres|
|--------|------------|
|IDP_OLE_INIT_FAILED|Falha na inicialização do OLE. Certifique-se de que as bibliotecas OLE são da versão correta.|
|IDP_FAILED_TO_CREATE|Falha ao criar o objeto. Certifique-se de que o objeto é inserido no registro do sistema.|

## <a name="see-also"></a>Consulte também

[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md)
