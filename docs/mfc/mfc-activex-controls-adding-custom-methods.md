---
title: "Controles ActiveX MFC: adicionando m&#233;todos personalizados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Controles ActiveX MFC, métodos"
  - "Método personalizado PtInCircle"
ms.assetid: 8f8dc344-44a0-4021-8db5-4cdd3d700e18
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: adicionando m&#233;todos personalizados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os métodos personalizados são diferentes dos métodos de estoque que não são implementados já por `COleControl`.  Você deve fornecer uma implementação para cada método personalizado que você adiciona ao controle.  
  
 Um usuário do controle ActiveX pode chamar um método personalizado a qualquer momento para executar ações controle\- específicas.  A entrada do mapa de distribuição para métodos personalizados é do formato `DISP_FUNCTION`.  
  
##  <a name="_core_adding_a_custom_method_with_classwizard"></a> Adicionando um método personalizado com o assistente de método add  
 O procedimento a seguir demonstra como adicionar o método personalizado PtInCircle a um código de esqueleto de controle ActiveX.  PtInCircle determina se as coordenadas são transmitidas ao controle dentro ou fora do círculo.  Esse mesmo procedimento também pode ser usado para adicionar outros métodos personalizados.  Substituir seu nome personalizado do método e seus parâmetros para o nome e os parâmetros do método de PtInCircle.  
  
> [!NOTE]
>  Este exemplo usa a função de `InCircle` de eventos do artigo.  Para obter mais informações sobre essa função, consulte o artigo [Controles ActiveX MFC: Adicionando eventos personalizados a um controle ActiveX](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Custom%20Events.md).  
  
#### Para adicionar o método personalizado de PtInCircle usando o assistente de método add  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar método**.  
  
     Isso abre o assistente do método ser adicionado.  
  
5.  Na caixa de **Nome do Método** , digite `PtInCircle`.  
  
6.  Na caixa de **Nome interno** , digite o nome da função interna do método ou use o valor padrão \(nesse caso, `PtInCircle`\).  
  
7.  Na caixa de **Tipo de retorno** , clique **VARIANT\_BOOL** para o tipo de retorno do método.  
  
8.  Usando os controles de **Tipo de parâmetro** e de **Nome do parâmetro** , adicione um parâmetro denominado `xCoord` \(tipo **OLE\_XPOS\_PIXELS**\).  
  
9. Usando os controles de **Tipo de parâmetro** e de **Nome do parâmetro** , adicione um parâmetro denominado `yCoord` \(tipo **OLE\_YPOS\_PIXELS**\).  
  
10. Clique em **Concluir**.  
  
##  <a name="_core_classwizard_changes_for_custom_methods"></a> Adicionar alterações do assistente do método para métodos personalizados  
 Quando você adiciona um método personalizado, o assistente do método adicionar fazer algumas alterações ao cabeçalho da classe de controle \(. H\) e arquivos de implementação \(.CPP\).  A seguinte linha é adicionada à declaração do mapa de distribuição no cabeçalho da classe de controle \(. H\) arquivo:  
  
 [!code-cpp[NVC_MFC_AxUI#18](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-methods_1.h)]  
  
 Esse código a seguir declara um método chamado `PtInCircle`manipulador de distribuição.  Esta função pode ser chamada pelo usuário de controle que usa o nome externo PtInCircle.  
  
 A seguinte linha é adicionada ao arquivo de .IDL de controle:  
  
 [!code-cpp[NVC_MFC_AxUI#19](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-methods_2.idl)]  
  
 Essa linha atribui ao método de um PtInCircle o número de identificação específico, a posição do método em métodos do assistente do método adicionar e as propriedades a seguir.  Porque o assistente do método adicionar foi usado para adicionar o método personalizado, a entrada para o qual foi acrescentada automaticamente ao arquivo de .IDL do projeto.  
  
 Além disso, a seguinte linha, localizada no arquivo de implementação\) \(.CPP da classe de controle, é adicionada ao mapa de expedição de controle:  
  
 [!code-cpp[NVC_MFC_AxUI#20](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-methods_3.cpp)]  
  
 A macro de `DISP_FUNCTION` mapeia o método PtInCircle à função de manipulador de controle, `PtInCircle`, declara o tipo de retorno para ser **VARIANT\_BOOL**, e declaram dois parâmetros do tipo **VTS\_XPOS\_PIXELS** e **VTS\_YPOSPIXELS** a serem transmitidos a `PtInCircle`.  
  
 Finalmente, o assistente do método adicionar adiciona a função `CSampleCtrl::PtInCircle` de stub para a parte inferior do arquivo de implementação de controle \(.CPP\).  Para que `PtInCircle` funcione como indicado previamente, deve ser modificado como segue:  
  
 [!code-cpp[NVC_MFC_AxUI#21](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-methods_4.cpp)]  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Exibição de classe ícones do Pesquisador de Objetos](../Topic/Class%20View%20and%20Object%20Browser%20Icons.md)