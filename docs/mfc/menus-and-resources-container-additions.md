---
title: "Menus e recursos: adi&#231;&#245;es de cont&#234;iner | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IDP_OLE_INIT_FAILED"
  - "IDP_FAILED_TO_CREATE"
  - "VK_ESCAPE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tabelas de teclas aceleradoras [C++], aplicativos de contêiner"
  - "tabela de aceleradores de aplicativos [C++]"
  - "Tutorial CONTAIN"
  - "Macro IDP_FAILED_TO_CREATE"
  - "Macro IDP_OLE_INIT_FAILED"
  - "Item de menu Links"
  - "Contêineres OLE, menus e recursos"
  - "edição visual, menus e recursos de aplicativo"
  - "Chave VK_ESCAPE"
ms.assetid: 425448be-8ca0-412e-909a-a3a9ce845288
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Menus e recursos: adi&#231;&#245;es de cont&#234;iner
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica as alterações que precisam ser feitas nos menus e outros recursos em um aplicativo de contêiner visual de edição.  
  
 Em aplicativos de contêiner, dois tipos de alterações precisarem ser feitas: alterações em recursos existentes para dar suporte à edição visual OLE e a adição de novas recursos usados para a ativação local.  Se você usar o assistente de aplicativo para criar o aplicativo de contêiner, essas etapas serão executadas para você, mas podem exigir personalização.  
  
 Se você não usar o assistente de aplicativo, talvez você queira examinar OCLIENT.RC, o script de recursos para o aplicativo de exemplo de OCLIENT, consulte como essas alterações são implementadas.  Consulte o exemplo [OCLIENT](../top/visual-cpp-samples.md)MFC OLE.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Adições de menu do contêiner](#_core_container_menu_additions)  
  
-   [Adições da tabela de aceleração](#_core_container_application_accelerator_table_additions)  
  
-   [Adições da tabela de cadeia de caracteres](#_core_string_table_additions_for_container_applications)  
  
##  <a name="_core_container_menu_additions"></a> Adições de menu do contêiner  
 Você deve adicionar os seguintes itens ao menu editar:  
  
|Item|Finalidade|  
|----------|----------------|  
|**Novo objeto de inserção**|Abre a caixa de diálogo OLE do objeto de inserção para inserir um item vinculado ou inserido no documento.|  
|**Link de pasta**|Cola um link para o item na área de transferência no documento.|  
|**Verbo OLE**|Chama o verbo primário do item selecionado.  O texto desse item de menu é alterado para refletir o verbo primário do item selecionado.|  
|**Links**|Abre a caixa de diálogo OLE de Links de edição para alterar itens vinculados existentes.|  
  
 Além das alterações listadas neste artigo, o arquivo de origem deve incluir AFXOLECL.RC, que é necessário para a implementação da biblioteca de classes do Microsoft.  O novo objeto de inserção é a única adição necessário no menu.  Outros itens podem ser adicionados, mas as listadas aqui são mais comuns.  
  
 Você deve criar um novo menu para seu aplicativo de contêiner se você quer dar suporte a ativação in\-loco de itens contidos.  Esse menu consiste no mesmo menu arquivo e o menu pop\-up de janela usados quando os arquivos são abertos, mas tem dois separadores colocados entre eles.  Esses separadores são usados para indicar onde o item do servidor \(componente de aplicativo\) \(\) deve colocar os menus quando ativado no lugar.  Para obter mais informações sobre essa técnica menu\- mesclando, consulte [Menus e recursos: A mesclagem de menu](../mfc/menus-and-resources-menu-merging.md).  
  
##  <a name="_core_container_application_accelerator_table_additions"></a> Adições da tabela de aceleração do aplicativo de contêineres  
 As pequenas alterações nos recursos de tabela de aceleração de aplicativo de contêineres são necessárias se você estiver com suporte a ativação local.  A primeira alteração permite que o usuário pressione a tecla de escape \(ESC\) para cancelar o modo de edição no local.  Adicione a seguinte entrada à tabela de aceleração principal:  
  
|ID|Chave|Tipo|  
|--------|-----------|----------|  
|**ID\_CANCEL\_EDIT\_CNTR**|VK\_ESCAPE|**VIRTKEY**|  
  
 A segunda alteração é criar uma nova tabela de aceleração que corresponde ao novo recurso no menu criado para a ativação local.  Esta tabela tem entradas para os menus de Arquivo e da janela além da entrada de **VK\_ESCAPE** acima.  O exemplo a seguir é a tabela de aceleração criada para o ativação no local no exemplo [CONTÊINER](../top/visual-cpp-samples.md)MFC:  
  
|ID|Chave|Tipo|  
|--------|-----------|----------|  
|`ID_FILE_NEW`|CTRL\+N|**VIRTKEY**|  
|`ID_FILE_OPEN`|CTRL\+O|**VIRTKEY**|  
|**ID\_FILE\_SAVE**|CTRL\+S|**VIRTKEY**|  
|**ID\_FILE\_PRINT**|CTRL\+P|**VIRTKEY**|  
|**ID\_NEXT\_PANE**|VK\_F6|**VIRTKEY**|  
|**ID\_PREV\_PANE**|SHIFT\+VK\_F6|**VIRTKEY**|  
|**ID\_CANCEL\_EDIT\_CNTR**|VK\_ESCAPE|**VIRTKEY**|  
  
##  <a name="_core_string_table_additions_for_container_applications"></a> Adições da tabela de cadeia de caracteres para aplicativos de contêiner  
 A maioria das alterações nas tabelas de cadeia de caracteres para aplicativos de contêiner correspondem aos itens de menu adicionais mencionados em [Adições de menu do contêiner](#_core_container_menu_additions).  Fornecem o texto exibido na barra de status quando cada item de menu é exibido.  Como um exemplo, aqui estão as entradas de cadeia de caracteres\- tabela o assistente de aplicativo gerencie:  
  
|ID|Cadeia de caracteres|  
|--------|--------------------------|  
|**IDP\_OLE\_INIT\_FAILED**|Falha na inicialização da OLE.  Certifique\-se de que as bibliotecas do são a versão correta.|  
|**IDP\_FAILED\_TO\_CREATE**|Falha ao criar o objeto.  Certifique\-se de que o objeto é inserida no Registro do sistema.|  
  
## Consulte também  
 [Menus e recursos \(OLE\)](../mfc/menus-and-resources-ole.md)   
 [Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md)