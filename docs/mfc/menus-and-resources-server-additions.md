---
title: "Menus e recursos: adi&#231;&#245;es de servidor | Microsoft Docs"
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
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tabelas de teclas aceleradoras [C++], aplicativos de servidor"
  - "Macro IDP_OLE_INIT_FAILED"
  - "falha na inicialização de OLE"
  - "aplicativos de servidor OLE, menus e recursos"
  - "Servidores de edição visual OLE"
  - "recursos [MFC], aplicativos de servidor"
  - "aplicativos de servidor, tabela de aceleradores"
  - "aplicativos de servidor, Menus e recursos OLE"
  - "servidores, adições de menu"
  - "edição de cadeia de caracteres, aplicativos de edição visual"
  - "tabelas de cadeias de caracteres, aplicativos de edição visual"
  - "edição visual, menus e recursos de aplicativo"
ms.assetid: 56ce9e8d-8f41-4db8-8dee-e8b0702d057c
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Menus e recursos: adi&#231;&#245;es de servidor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica as alterações que precisam ser feitas nos menus e outros recursos em um aplicativo visual do servidor edition \(componente\).  Um aplicativo de servidor exige várias adições à estrutura de menu e outros recursos como o pode ser iniciado em um de três modos: suporte a seguir, inserido sozinho, ou no lugar.  Como descrito no artigo de [Menus e recursos \(OLE\)](../mfc/menus-and-resources-ole.md) , há um máximo de quatro conjuntos de menus.  Todos os quatro são usados para um aplicativo de servidor full\-scale MDI, quando apenas três são usados para um miniserver.  O assistente de aplicativo criará o layout do menu necessário para o tipo de servidor que você deseja.  Qualquer personalizaçaõ pode ser necessária.  
  
 Se você não usar o assistente de aplicativo, talvez você queira examinar HIERSVR.RC, o script de recursos para o aplicativo de exemplo [HIERSVR](../top/visual-cpp-samples.md)MFC, consulte como essas alterações são implementadas.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Adições de menu do servidor](#_core_server_menu_additions)  
  
-   [Adições da tabela de aceleração](#_core_server_application_accelerator_table_additions)  
  
-   [Adições da tabela de cadeia de caracteres](../mfc/menus-and-resources-container-additions.md)  
  
-   [Adições de Miniserver](#_core_mini.2d.server_additions)  
  
##  <a name="_core_server_menu_additions"></a> Adições de menu do servidor  
 Os aplicativos de servidor \(componente\) devem ter os recursos do menu adicionados para oferecer suporte à edição visual OLE.  Os menus usados quando o aplicativo é executado no modo autônomo não precisam ser alterados, mas você deve adicionar dois novos recursos no menu antes de criar o aplicativo: um para oferecer suporte à ativação local e um para dar suporte ao servidor que está completamente aberto.  Ambos os recursos do menu são usados por aplicativos completo e de miniserver.  
  
-   Para oferecer suporte à ativação no local, você deve criar um recurso de menu que seja muito semelhante ao recurso de menu usado quando executado em modo autônomo.  A diferença nesse menu é que os itens de Arquivo e da janela \(e alguns outros itens de menu que tratarem o aplicativo, e não os dados estão ausentes.\)  O aplicativo de contêiner fornecerá esses itens de menu.  Para obter mais informações sobre, e um exemplo, essa técnica menu\- mesclando, consulte o artigo [Menus e recursos: A mesclagem de menu](../mfc/menus-and-resources-menu-merging.md).  
  
-   Para dar suporte à ativação completamente aberta, você deve criar um recurso no menu quase idêntico ao recurso de menu usado quando executado em modo autônomo.  A única alteração para esse recurso no menu é que alguns itens estão reformulados para refletir o fato que o servidor está operando em um item inserido em um documento composto.  
  
 Além das alterações listadas neste artigo, seu arquivo de recurso precisa incluir AFXOLESV.RC, que é necessário para a implementação da biblioteca de classes do Microsoft.  Esse arquivo está em MFC \\ inclui o subdiretório.  
  
##  <a name="_core_server_application_accelerator_table_additions"></a> Adições da tabela de aceleração de aplicativo de servidor  
 Dois novos recursos de tabela de aceleração devem ser adicionados aos aplicativos de servidor; corresponde diretamente aos novos recursos no menu descritos anteriormente.  A primeira tabela de aceleração é usada quando o aplicativo para servidores é ativado no lugar.  Consiste de todas as entradas na tabela de aceleração de exibição com exceção associada aos menus de Arquivo e da janela.  
  
 A segunda tabela é quase uma cópia exata da tabela de aceleração de exibição.  Algumas das diferenças paralelas alterações feitas no menu completamente aberto mencionado em [Adições de menu do servidor](#_core_server_menu_additions).  
  
 Para obter um exemplo dessas alterações da tabela de aceleração, compare as tabelas de aceleração de **IDR\_HIERSVRTYPE\_SRVR\_IP** e de **IDR\_HIERSVRTYPE\_SRVR\_EMB** com **IDR\_MAINFRAME** no arquivo de HIERSVR.RC incluído no exemplo [HIERSVR](../top/visual-cpp-samples.md)MFC OLE.  Os aceleradores de Arquivo e da janela estão ausentes de tabela no e requerem cópias deless estão na tabela inserido.  
  
##  <a name="_core_string_table_additions_for_server_applications"></a> Adições da tabela de cadeia de caracteres para aplicativos de servidor  
 Apenas uma adição da tabela de cadeia de caracteres é necessária em um aplicativo de servidor — uma cadeia de caracteres para mostrar que a inicialização OLE DB falhou.  Como exemplo, aqui está a entrada de cadeia de caracteres\- tabela que o assistente do aplicativo gerenciar:  
  
|ID|Cadeia de caracteres|  
|--------|--------------------------|  
|**IDP\_OLE\_INIT\_FAILED**|Falha na inicialização da OLE.  Certifique\-se de que as bibliotecas do são a versão correta.|  
  
##  <a name="_core_mini.2d.server_additions"></a> Adições de Miniserver  
 As mesmas adições se aplicam a miniservers como aquelas listadas acima para servidores completo.  Como um miniserver não pode ser executado no modo autônomo, o menu principal é muito secundária.  O menu principal criado pelo assistente de aplicativo tem apenas um menu arquivo, contendo apenas a saída dos itens e aproximadamente.  Os menus e inseridos no local e os aceleradores para miniservers são os mesmos que os servidores para completo.  
  
## Consulte também  
 [Menus e recursos \(OLE\)](../mfc/menus-and-resources-ole.md)   
 [Menus e recursos: mescla de menu](../mfc/menus-and-resources-menu-merging.md)