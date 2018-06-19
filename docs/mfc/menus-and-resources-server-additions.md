---
title: 'Menus e recursos: adições de servidor | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- IDP_OLE_INIT_FAILED
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 86b941820b439afc8b914142b412995df30f109c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33351345"
---
# <a name="menus-and-resources-server-additions"></a>Menus e recursos: adições de servidor
Este artigo explica as alterações que precisam ser feitas para os menus e outros recursos em um aplicativo de servidor (componente) de edição visual. Um aplicativo de servidor requer várias adições para a estrutura de menus e outros recursos porque ela pode ser iniciada em um dos três modos: autônomo sozinho, inseridos, ou no local. Conforme descrito no [Menus e recursos OLE](../mfc/menus-and-resources-ole.md) artigo, há um máximo de quatro conjuntos de menus. Todos os quatro são usados para um aplicativo de servidor completo MDI, enquanto apenas três são usados para um miniserver. O Assistente de aplicativo criará o layout do menu necessários para o tipo de servidor que você deseja. Alguma personalização pode ser necessária.  
  
 Se você não usar o Assistente de aplicativo, convém examinar HIERSVR. RC, o script de recurso para o aplicativo de exemplo do MFC [HIERSVR](../visual-cpp-samples.md)para ver como essas alterações são implementadas.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Adições de Menu do servidor](#_core_server_menu_additions)  
  
-   [Adições de tabela de teclas aceleradoras](#_core_server_application_accelerator_table_additions)  
  
-   [Adições de tabela de cadeia de caracteres](../mfc/menus-and-resources-container-additions.md)  
  
-   [Adições de miniserver](#_core_mini.2d.server_additions)  
  
##  <a name="_core_server_menu_additions"></a> Adições de Menu do servidor  
 Aplicativos de servidor (componente) devem ter recursos do menu adicionados para oferecer suporte de edição visual OLE. Os menus usados quando o aplicativo é executado no modo autônomo não precisam ser alteradas, mas você deve adicionar dois novos recursos de menu antes de compilar o aplicativo: uma para dar suporte a ativação no local e outra para suportar o servidor está totalmente aberta. Ambos os recursos do menu são usados por aplicativos miniserver e completo.  
  
-   Para dar suporte à ativação no local, você deve criar um recurso de menu que é muito semelhante ao recurso de menu usado quando executado no modo autônomo. A diferença nesse menu é que os itens de arquivo e de janela (e outros itens de menu que lidam com o aplicativo e não os dados) estão ausentes. O aplicativo de contêiner deverá fornecer esses itens de menu. Para obter mais informações sobre e um exemplo, essa técnica de mesclagem de menus, consulte o artigo [Menus e recursos: mesclagem de Menu](../mfc/menus-and-resources-menu-merging.md).  
  
-   Para dar suporte à ativação totalmente aberta, você deve criar um recurso de menu quase idêntico para o recurso de menu usado quando executado no modo autônomo. A modificação somente para esse recurso de menu é que alguns itens são reformuladas para refletir o fato de que o servidor está operando em um item inserido em um documento composto.  
  
 Além das alterações listadas neste artigo, o arquivo de recurso precisa incluir AFXOLESV. RC, que é necessário para a implementação de biblioteca Microsoft Foundation Class. Esse arquivo está no subdiretório MFC\Include.  
  
##  <a name="_core_server_application_accelerator_table_additions"></a> Adições de tabela de acelerador de aplicativo de servidor  
 Dois novos recursos de tabela do acelerador devem ser adicionados para aplicativos de servidor. eles correspondem diretamente para os novos recursos de menu descritos anteriormente. A primeira tabela de teclas aceleradoras é usada quando o aplicativo do servidor é ativado em vigor. Ele consiste em todas as entradas na tabela de Aceleradores do modo de exibição exceto aqueles vinculado para o arquivo e a janela de menus.  
  
 A segunda tabela é quase uma cópia exata da tabela de Aceleradores do modo de exibição. As diferenças paralelo as alterações feitas no menu aberto totalmente mencionado na [adições de Menu do Server](#_core_server_menu_additions).  
  
 Para obter um exemplo dessas alterações de tabela de teclas aceleradoras, compare o **IDR_HIERSVRTYPE_SRVR_IP** e **IDR_HIERSVRTYPE_SRVR_EMB** accelerator tabelas com **IDR_MAINFRAME** em HIERSVR. Arquivo RC incluído no MFC OLE exemplo [HIERSVR](../visual-cpp-samples.md). Os aceleradores de arquivo e a janela estão faltando na tabela no local e são cópias exatas de-los na tabela inserida.  
  
##  <a name="_core_string_table_additions_for_server_applications"></a> Adições de tabela de cadeia de caracteres para aplicativos de servidor  
 Adição de tabela apenas uma cadeia de caracteres é necessária em um aplicativo do servidor — uma cadeia de caracteres para indicar que houve falha na inicialização OLE. Por exemplo, aqui está a entrada da tabela de cadeia de caracteres que gera o Assistente de aplicativo:  
  
|ID|Cadeia de Caracteres|  
|--------|------------|  
|**IDP_OLE_INIT_FAILED**|Falha na inicialização de OLE. Certifique-se de que as bibliotecas OLE são da versão correta.|  
  
##  <a name="_core_mini.2d.server_additions"></a> Adições de miniserver  
 Aplicam as mesmas adições para miniservers listados acima para servidores completo. Como um miniserver não pode ser executado no modo autônomo, o menu principal é muito menor. O menu principal criado pelo Assistente de aplicativo tem apenas um menu de arquivo, que contém apenas os itens de saída e sobre. Menus incorporados e no local e aceleradores para miniservers são as mesmas para servidores completo.  
  
## <a name="see-also"></a>Consulte também  
 [Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)   
 [Menus e recursos: mesclagem de menu](../mfc/menus-and-resources-menu-merging.md)

