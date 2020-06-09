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
ms.openlocfilehash: a082a75ef0292e190e597f29be0cdc0bd0b497ef
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626234"
---
# <a name="menus-and-resources-container-additions"></a>Menus e recursos: adições de contêiner

Este artigo explica as alterações que precisam ser feitas nos menus e outros recursos em um aplicativo de contêiner de edição visual.

Em aplicativos de contêiner, dois tipos de alterações precisam ser feitos: modificações em recursos existentes para dar suporte à edição Visual OLE e adição de novos recursos usados para ativação in-loco. Se você usar o assistente de aplicativo para criar seu aplicativo de contêiner, essas etapas serão executadas para você, mas podem exigir alguma personalização.

Se você não usar o assistente de aplicativo, talvez você queira examinar OCLIENT. RC, o script de recurso para o aplicativo de exemplo OCLIENT, para ver como essas alterações são implementadas. Consulte o exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md).

Os tópicos abordados neste artigo incluem:

- [Adições de menu de contêiner](#_core_container_menu_additions)

- [Adições de tabela de acelerador](#_core_container_application_accelerator_table_additions)

- [Adições de tabela de cadeia de caracteres](#_core_string_table_additions_for_container_applications)

## <a name="container-menu-additions"></a><a name="_core_container_menu_additions"></a>Adições de menu de contêiner

Você deve adicionar os seguintes itens ao menu Editar:

|Item|Finalidade|
|----------|-------------|
|**Inserir novo objeto**|Abre a caixa de diálogo objeto OLE INSERT para inserir um item vinculado ou inserido no documento.|
|**Colar link**|Cola um link para o item na área de transferência no documento.|
|**Verbo OLE**|Chama o verbo principal do item selecionado. O texto desse item de menu é alterado para refletir o verbo primário do item selecionado.|
|**Vincule**|Abre a caixa de diálogo links do OLE Edit para alterar itens vinculados existentes.|

Além das alterações listadas neste artigo, o arquivo de origem deve incluir AFXOLECL. RC, que é necessário para a implementação de biblioteca MFC. Inserir novo objeto é a única adição de menu necessária. Outros itens podem ser adicionados, mas os listados aqui são os mais comuns.

Você deve criar um novo menu para seu aplicativo de contêiner se desejar oferecer suporte à ativação in-loco de itens contidos. Esse menu consiste no mesmo menu de arquivo e nos menus pop-up de janela usados quando os arquivos estão abertos, mas têm dois separadores colocados entre eles. Esses separadores são usados para indicar onde o item de servidor (componente) (aplicativo) deve posicionar seus menus quando ativados no local. Para obter mais informações sobre essa técnica de mesclagem de menus, consulte [menus e recursos: mesclagem de menu](menus-and-resources-menu-merging.md).

## <a name="container-application-accelerator-table-additions"></a><a name="_core_container_application_accelerator_table_additions"></a>Adições de tabelas do Application Accelerator do contêiner

Alterações pequenas nos recursos da tabela de acelerador de um aplicativo de contêiner são necessárias se você estiver dando suporte à ativação in-loco. A primeira alteração permite que o usuário pressione a tecla escape (ESC) para cancelar o modo de edição in-loco. Adicione a seguinte entrada à tabela principal do acelerador:

|ID|Chave|Digite|
|--------|---------|----------|
|ID_CANCEL_EDIT_CNTR|VK_ESCAPE|**VIRTKEY**|

A segunda alteração é criar uma nova tabela de acelerador que corresponda ao novo recurso de menu criado para ativação in-loco. Esta tabela tem entradas para os menus arquivo e janela, além da entrada VK_ESCAPE acima. O exemplo a seguir é a tabela aceleradora criada para ativação in-loco no [contêiner](../overview/visual-cpp-samples.md)de exemplo do MFC:

|ID|Chave|Digite|
|--------|---------|----------|
|ID_FILE_NEW|Ctrl+N|**VIRTKEY**|
|ID_FILE_OPEN|Ctrl+O|**VIRTKEY**|
|ID_FILE_SAVE|Ctrl+S|**VIRTKEY**|
|ID_FILE_PRINT|CTRL+P|**VIRTKEY**|
|ID_NEXT_PANE|VK_F6|**VIRTKEY**|
|ID_PREV_PANE|SHIFT + VK_F6|**VIRTKEY**|
|ID_CANCEL_EDIT_CNTR|VK_ESCAPE|**VIRTKEY**|

## <a name="string-table-additions-for-container-applications"></a><a name="_core_string_table_additions_for_container_applications"></a>Adições de tabela de cadeia de caracteres para aplicativos de contêiner

A maioria das alterações em tabelas de cadeia de caracteres para aplicativos de contêiner corresponde aos itens de menu adicionais mencionados em [adições de menu de contêiner](#_core_container_menu_additions). Eles fornecem o texto exibido na barra de status quando cada item de menu é exibido. Por exemplo, aqui estão as entradas da tabela de cadeia de caracteres que o assistente de aplicativo gera:

|ID|Cadeia de caracteres|
|--------|------------|
|IDP_OLE_INIT_FAILED|Falha na inicialização do OLE. Verifique se as bibliotecas OLE são da versão correta.|
|IDP_FAILED_TO_CREATE|Falha ao criar objeto. Certifique-se de que o objeto seja inserido no registro do sistema.|

## <a name="see-also"></a>Consulte também

[Menus e recursos (OLE)](menus-and-resources-ole.md)<br/>
[Menus e recursos: adições de servidor](menus-and-resources-server-additions.md)
