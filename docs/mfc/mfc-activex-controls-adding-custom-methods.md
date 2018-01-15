---
title: "Controles ActiveX MFC: Adicionando métodos personalizados | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], methods
- PtInCircle custom method [MFC]
ms.assetid: 8f8dc344-44a0-4021-8db5-4cdd3d700e18
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2f79d4c5f7407e3de12ccf180a68b2b22e35bf10
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-adding-custom-methods"></a>Controles ActiveX MFC: adicionando métodos personalizados
Métodos personalizados são diferentes de métodos de estoque que eles já não são implementados por `COleControl`. Você deve fornecer a implementação para cada método personalizado que você adicionar ao seu controle.  
  
 Um usuário de controle ActiveX pode chamar um método personalizado a qualquer momento para executar ações específicas para o controle. A entrada de mapa de expedição de métodos personalizados é da forma `DISP_FUNCTION`.  
  
##  <a name="_core_adding_a_custom_method_with_classwizard"></a>Adicionando um método personalizado com o Assistente para o método adicionar  
 O procedimento a seguir demonstra como adicionar o método personalizado PtInCircle ao código de esqueleto de um controle ActiveX. PtInCircle determina se as coordenadas passadas para o controle dentro ou fora do círculo. Este mesmo procedimento também pode ser usado para adicionar outros métodos personalizados. Substitua o nome do método personalizado e seus parâmetros para o nome do método PtInCircle e parâmetros.  
  
> [!NOTE]
>  Este exemplo usa o `InCircle` função do artigo eventos. Para obter mais informações sobre essa função, consulte o artigo [controles ActiveX MFC: adicionando eventos personalizados para um controle ActiveX](../mfc/mfc-activex-controls-adding-custom-events.md).  
  
#### <a name="to-add-the-ptincircle-custom-method-using-the-add-method-wizard"></a>Para adicionar o método personalizado PtInCircle usando o Assistente para adição de método  
  
1.  Carregar projeto do controle.  
  
2.  No modo de exibição de classe, expanda o nó de biblioteca de seu controle.  
  
3.  Para abrir o menu de atalho, clique com botão direito no nó de interface de seu controle (o segundo nó do nó de biblioteca).  
  
4.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar método**.  
  
     Isso abre o Assistente para adição de método.  
  
5.  No **nome do método** , digite `PtInCircle`.  
  
6.  No **nome interno** caixa, digite o nome da função interna do método ou usar o valor padrão (neste caso, `PtInCircle`).  
  
7.  No **tipo de retorno** , clique em **VARIANT_BOOL** para o tipo de retorno do método.  
  
8.  Usando o **tipo de parâmetro** e **nome do parâmetro** controles, adicionar um parâmetro chamado `xCoord` (tipo **OLE_XPOS_PIXELS**).  
  
9. Usando o **tipo de parâmetro** e **nome do parâmetro** controles, adicionar um parâmetro chamado `yCoord` (tipo **OLE_YPOS_PIXELS**).  
  
10. Clique em **Finalizar**.  
  
##  <a name="_core_classwizard_changes_for_custom_methods"></a>Adicionar Assistente altera o método para métodos personalizados  
 Quando você adiciona um método personalizado, o Assistente para adicionar método faz com que algumas alterações para o cabeçalho de classe de controle (. H) e implementação (. Arquivos CPP). A seguinte linha é adicionada à declaração de mapa de expedição no cabeçalho de classe de controle (. H) arquivo:  
  
 [!code-cpp[NVC_MFC_AxUI#18](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_1.h)]  
  
 Esse código declara um manipulador de método de expedição chamado `PtInCircle`. Esta função pode ser chamada pelo usuário de controle usando o nome externo PtInCircle.  
  
 A seguinte linha é adicionada para o controle. Arquivo IDL:  
  
 [!code-cpp[NVC_MFC_AxUI#19](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_2.idl)]  
  
 Essa linha atribui o método PtInCircle um número específico de ID, a posição do método na lista de métodos e propriedades de Assistente de adição de método. Como o Assistente para adicionar método foi usado para adicionar o método personalizado, a entrada para que ele foi adicionada automaticamente para o projeto. Arquivo IDL.  
  
 Além disso, a linha a seguir, localizado na implementação (. Arquivo CPP) da classe de controle, é adicionada ao mapa de expedição do controle:  
  
 [!code-cpp[NVC_MFC_AxUI#20](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_3.cpp)]  
  
 O `DISP_FUNCTION` macro o método PtInCircle é mapeado para a função do controle manipulador, `PtInCircle`, declara o tipo de retorno para ser **VARIANT_BOOL**e declara dois parâmetros de tipo **VTS_XPOS_PIXELS** e **VTS_YPOSPIXELS** a serem passados para `PtInCircle`.  
  
 Por fim, o Assistente para adicionar método adiciona a função de stub `CSampleCtrl::PtInCircle` na parte inferior da implementação do controle (. Arquivo CPP). Para `PtInCircle` para funcionar como mencionado anteriormente, ele deve ser modificado da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_AxUI#21](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Ícones do Pesquisador de Objetos e do Modo de Exibição de Classe](/visualstudio/ide/class-view-and-object-browser-icons)

