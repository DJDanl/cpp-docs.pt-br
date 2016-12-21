---
title: "Menus e recursos: mescla de menu | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "coordenando layouts de menu"
  - "menus [C++], Aplicativos de documento OLE"
  - "mesclando barra de ferramentas e barra de status"
  - "Contêineres OLE, menus e recursos"
  - "barras de status, Aplicativos de documento OLE"
  - "barras de ferramentas [C++], Aplicativos de documento OLE"
  - "edição visual, menus e recursos de aplicativo"
ms.assetid: 80b6bb17-d830-4122-83f0-651fc112d4d1
caps.latest.revision: 9
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Menus e recursos: mescla de menu
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo detalha as etapas necessárias para que os aplicativos OLE do documento para lidar com a edição e a ativação in\-loco visuais corretamente.  O ativação in\-loco representa um desafio para aplicativos do contêiner e do servidor \(componente\).  O usuário permanecerá na mesma janela do quadro \(no contexto do documento contêiner\) mas está sendo executada realmente outro aplicativo \(servidor\).  Isso requer que a coordenação entre os recursos do contêiner e aplicativos para servidores.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Layouts de menu](#_core_menu_layouts)  
  
-   [Barras de ferramentas e barras de status](#_core_toolbars_and_status_bars)  
  
##  <a name="_core_menu_layouts"></a> Layouts de menu  
 A primeira etapa é coordenar layouts de menu.  Para obter mais informações, consulte a seção de **Menu Creation** em [Considerações de programação de menu](https://msdn.microsoft.com/en-us/library/ms647557.aspx) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
 Os aplicativos de contêiner deve criar um novo menu a ser usado somente quando os itens inseridos são ativados no lugar.  No mínimo, esse menu deve consistir na tabela a seguir, na ordem listada:  
  
1.  O menu arquivo idêntico a aquele usado quando os arquivos estiverem abertos. \(Nenhum outro item de menu é colocado em geral antes do próximo item.\)  
  
2.  Dois separadores consecutivos.  
  
3.  Menu janela idêntico a aquele usado quando os arquivos estiverem abertos \(apenas se o aplicativo de contêiner em um aplicativo MDI\).  Alguns aplicativos podem ter outros menus, como um menu de opções, que pertencem nesse grupo, que permanece no menu quando um item é inserido ativado no lugar.  
  
    > [!NOTE]
    >  Pode haver outros menus que afetam a exibição do documento contêiner, como o zoom.  Esses menus do contêiner são exibidas entre os dois separadores nesse recurso no menu.  
  
 Os aplicativos de servidor \(componente\) também devem criar um novo menu especificamente para o ativação local.  Deve ser usado como o menu quando os arquivos são abertos, mas sem itens de menu, como Arquivo e a janela que manipulam o documento de servidor em vez de dados.  Normalmente, esse menu consiste no seguinte:  
  
1.  Editar o menu idêntico a aquele usado quando os arquivos estiverem abertos.  
  
2.  Separador.  
  
3.  Objeto menus de edição, como o menu de quanto no aplicativo de exemplo de garrancho.  
  
4.  Separador.  
  
5.  Menu da ajuda.  
  
 Para obter um exemplo, consulte o layout de alguns dos menus in\-loco de exemplo para um contêiner e um servidor.  Os detalhes de cada item de menu foram removidos para fazer o torna de exemplo.  O menu no local do contêiner tem as seguintes entradas:  
  
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
  
 Os separadores consecutivos indicam onde a primeira parte do menu do servidor deve ir.  Observe agora o menu no local do servidor:  
  
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
  
 Os separadores aqui indicam onde o segundo grupo de itens de menu do contêiner deve ir.  A estrutura resultante no menu quando um objeto desse servidor é ativado no lugar dentro dos aspectos desse contêiner como este:  
  
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
  
 Como você pode ver, os separadores foram substituídos pelos grupos diferentes no menu de cada aplicativo.  
  
 As tabelas de aceleração associadas ao menu no local também devem ser fornecidas pelo aplicativo para servidores.  O contêiner incorporar\-os\-&z em suas próprias tabelas de aceleração.  
  
 Quando um item é inserido ativado no lugar, a estrutura carrega o menu no.  Solicita no aplicativo de servidor para seu o menu ativação local e inseri\-lo em que os separadores estão.  Isso é como os menus combinam.  Você verá menus do contêiner para operar no posicionamento do arquivo e na janela, e você verá menus do servidor para operar no item.  
  
##  <a name="_core_toolbars_and_status_bars"></a> Barras de ferramentas e barras de status  
 Os aplicativos de servidor devem criar uma nova barra de ferramentas e armazenar o bitmap em um arquivo separado.  Os aplicativos script gerado de aplicativo armazena este bitmap em um arquivo chamado ITOOLBAR.BMP.  A nova barra de ferramentas substitui a barra de ferramentas do aplicativo do contêiner quando o item do servidor é ativado no lugar, e deve conter os mesmos itens que a barra de ferramentas normal, mas remove os ícones que representam itens nos menus de Arquivo e da janela.  
  
 Essa barra de ferramentas é carregado em seu `COleIPFrameWnd`\- classe derivada, criada pelo assistente de aplicativo.  A barra de status é tratada pelo aplicativo do contêiner.  Para obter mais informações sobre a implementação do windows no local do quadro, consulte [Servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md).  
  
## Consulte também  
 [Menus e recursos \(OLE\)](../mfc/menus-and-resources-ole.md)   
 [Ativação](../mfc/activation-cpp.md)   
 [Servidores](../mfc/servers.md)   
 [Contêineres](../mfc/containers.md)