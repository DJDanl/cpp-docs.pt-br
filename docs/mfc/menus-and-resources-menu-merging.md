---
title: 'Menus e recursos: mesclagem de Menu | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- status bars [MFC], OLE document applications
- visual editing [MFC], application menus and resources
- coordinating menu layouts [MFC]
- OLE containers [MFC], menus and resources
- toolbars [MFC], OLE document applications
- merging toolbar and status bar [MFC]
- menus [MFC], OLE document applications
ms.assetid: 80b6bb17-d830-4122-83f0-651fc112d4d1
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c686d461a3052feb4a55cf7948b58102f10ac1f1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="menus-and-resources-menu-merging"></a>Menus e recursos: mescla de menu
Este artigo detalha as etapas necessárias para aplicativos de documento OLE tratar a edição visual e ativação no local corretamente. Ativação no local representa um desafio para o contêiner e o servidor de aplicativos (componente). O usuário permanece na mesma janela do quadro (dentro do contexto do documento contêiner), mas está realmente executando outro aplicativo (o servidor). Isso exige a coordenação entre os recursos do contêiner e o servidor de aplicativos.  
  
 Os tópicos abordados neste artigo incluem:  
  
- [Layouts de menu](#_core_menu_layouts)  
  
- [Barras de ferramentas e barras de Status](#_core_toolbars_and_status_bars)  
  
##  <a name="_core_menu_layouts"></a>Layouts de menu  
 A primeira etapa é coordenar os layouts de menu. Para obter mais informações, consulte o **criação** seção [considerações de programação do Menu](https://msdn.microsoft.com/library/ms647557.aspx) no SDK do Windows.  
  
 Aplicativos de contêiner devem criar um novo menu a ser usado somente quando itens incorporados são ativados em vigor. No mínimo, este menu deve consistir a seguir, na ordem listada:  
  
1.  Menu Arquivo idêntico àquele usado quando os arquivos estiverem abertos. (Normalmente a nenhum outro item de menu é colocado antes do próximo item.)  
  
2.  Dois separadores consecutivos.  
  
3.  Menu Janela idêntico àquele usado quando os arquivos estiverem abertos (somente se o aplicativo de contêiner em um aplicativo MDI). Alguns aplicativos podem ter outros menus, como um menu de opções, que pertencem a esse grupo, que permanecerá no menu quando um item inserido é ativado em vigor.  
  
    > [!NOTE]
    >  Pode haver outros menus que afetam o modo de exibição do documento contêiner, como o Zoom. Esses menus do contêiner aparecem entre os dois separadores nesse recurso de menu.  
  
 Aplicativos de servidor (componente) também devem criar um novo menu especificamente para ativação no local. Ele deve ser como o menu usado quando os arquivos estiverem abertos, mas sem itens de menu, como arquivos e janela que manipulam o documento em vez dos dados do servidor. Normalmente, esse menu consiste no seguinte:  
  
1.  Edite menu idêntico àquele usado quando os arquivos estiverem abertos.  
  
2.  Separador.  
  
3.  Edição de menus, como o menu de caneta no aplicativo de amostra Rabisco do objeto.  
  
4.  Separador.  
  
5.  Menu de Ajuda.  
  
 Por exemplo, examine o layout de alguns menus no local de exemplo para um contêiner e um servidor. Os detalhes de cada item de menu foram removidos para tornar o exemplo mais claro. Menu de local do contêiner tem as seguintes entradas:  
  
```  
IDR_CONTAINERTYPE_CNTR_IP MENU PRELOAD DISCARDABLE   
BEGIN  
    POPUP "&File C1"  
    MENUITEM SEPARATOR  
    POPUP "&Zoom C2"  
    MENUITEM SEPARATOR  
    POPUP "&Options C3"  
    POPUP "&Window C3"  
END  
```  
  
 Os separadores de consecutivos indicam onde a primeira parte do menu do servidor deve ir. Agora examine o menu de local do servidor:  
  
```  
IDR_SERVERTYPE_SRVR_IP MENU PRELOAD DISCARDABLE   
BEGIN  
    POPUP "&Edit S1"  
    MENUITEM SEPARATOR  
    POPUP "&Format S2"  
    MENUITEM SEPARATOR  
    POPUP "&Help S3"  
END  
```  
  
 Os separadores aqui indicam onde o segundo grupo de itens de menu do contêiner deve ir. A estrutura de menu resultante quando um objeto desse servidor está ativado no lugar dentro desse contêiner tem esta aparência:  
  
```  
BEGIN  
    POPUP "&File C1"  
    POPUP "&Edit S1"  
    POPUP "&Zoom C2"  
    POPUP "&Format S2"  
    POPUP "&Options C3  
    POPUP "&Window C3"  
    POPUP "&Help S3"  
END  
```  
  
 Como você pode ver, os separadores foram substituídos com os diferentes grupos de menu de cada aplicativo.  
  
 Tabelas de teclas aceleradoras associadas com o menu local também devem ser fornecidas pelo aplicativo de servidor. O contêiner será incorporá-las ao seus próprio tabelas de teclas aceleradoras.  
  
 Quando um item inserido é ativado em vigor, o framework carrega menu no local. Em seguida, ele solicita que o aplicativo de servidor para seu menu de ativação no local e o insere onde estão os separadores. Isso é como combinam os menus. Obter menus do contêiner para a operação no posicionamento de arquivos e janela e obter menus do servidor para a operação no item.  
  
##  <a name="_core_toolbars_and_status_bars"></a>Barras de ferramentas e barras de Status  
 Aplicativos de servidor devem criar uma nova barra de ferramentas e armazenar seu bitmap em um arquivo separado. Os aplicativos gerados pelo Assistente de aplicativo armazenam esse bitmap em um arquivo chamado ITOOLBAR. BMP. Nova barra de ferramentas substitui a barra de ferramentas do aplicativo recipiente quando o item do servidor está ativado no local e deve conter os mesmos itens como a barra de ferramentas normal, mas remover ícones que representam os itens nos menus do arquivo e a janela.  
  
 Essa barra de ferramentas é carregada em seu `COleIPFrameWnd`-derivado da classe, criado para você pelo Assistente de aplicativo. A barra de status é tratada pelo aplicativo recipiente. Para obter mais informações sobre a implementação de janelas com moldura no local, consulte [servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md).  
  
## <a name="see-also"></a>Consulte também  
 [Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)   
 [Ativação](../mfc/activation-cpp.md)   
 [Servidores](../mfc/servers.md)   
 [Contêineres](../mfc/containers.md)

