---
title: "Aparência, o Assistente de controle ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: vc.codewiz.class.atl.control.misc
dev_langs: C++
helpviewer_keywords: ATL Control Wizard, appearance
ms.assetid: cc16d7ff-74d7-4c15-9ebd-4b19201ff457
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 5c88248a97c67d551da1faa5bdeaf16bdf1b66c3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="appearance-atl-control-wizard"></a>Aparência, o Assistente de controle ATL
Insira "Resultados da pesquisa" Resumo aqui.  
  
 Use esta página do Assistente para identificar as opções de elemento de usuário adicionais para o controle. Esta página está disponível para controles identificados como **controles padrão** em **tipo de controle** no [opções, o Assistente de controle ATL](../../atl/reference/options-atl-control-wizard.md) página.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Exibir status**  
 Define a aparência do controle dentro do contêiner.  
  
-   **Opaco**: conjuntos a `VIEWSTATUS_OPAQUE` bit no [VIEWSTATUS](http://msdn.microsoft.com/library/windows/desktop/ms687201) enumeração e desenha o retângulo de controle inteiro é passado para o [CComControlBase::OnDraw](../../atl/reference/ccomcontrolbase-class.md#ondraw) método. O controle aparece completamente opaco e nenhum contêiner mostra atrás dos limites do controle.  
  
     Essa configuração ajuda o contêiner desenhar o controle mais rapidamente. Se essa opção não for selecionada, o controle pode conter partes transparentes.  
  
     Somente um controle opaco pode ter um plano de fundo sólido.  
  
-   Conjuntos de `VIEWSTATUS_SOLIDBKGND` bit no `VIEWSTATUS` enumeração. Plano de fundo do controle é exibido como uma cor sólida com nenhum padrão.  
  
     Essa opção estará disponível somente se o **opaco** também está selecionada.  
  
 **Adicionar um controle com base em**  
 Define o controle deve ser baseado em um tipo de controle do Windows adicionando um [CContainedWindow](ccontainedwindowt-class.md) membro de dados para a classe de implementação do controle. Ele também adiciona um mapa de mensagem e funções de manipulador de mensagem para lidar com mensagens do Windows para o controle. Escolha na lista o tipo de controle do Windows que você deseja criar, se houver.  

  
-   `Button`  
  
-   `ListBox`  
  
-   `SysAnimate32`  
  
-   `SysListView32`  
  
-   `ComboBox`  
  
-   `RichEdit`  
  
-   `SysDateTimePick32`  
  
-   `SysMonthCal32`  
  
-   `ComboBoxEx32`  
  
-   `ScrollBar`  
  
-   `SysHeader32`  
  
-   `SysTabControl32`  
  
-   `Edit`  
  
-   `Static`  
  
-   `SysIPAddress32`  
  
-   `SysTreeView32`  
  
 **Status Misc**  
 Define opções adicionais de aparência e comportamento do controle.  
  
-   **Invisível em tempo de execução**: define o controle seja invisível em tempo de execução. Você pode usar controles invisíveis para executar operações em segundo plano, como acionar eventos em intervalos regulares.  
  
-   **Age como botão**: define o `OLEMISC_ACTSLIKEBUTTON` bit no [OLEMISC](http://msdn.microsoft.com/library/windows/desktop/ms678497) enumeração para ativar um controle atuar como um botão. Se o contêiner foi marcado como site do cliente do controle como um botão padrão, esta opção permite que o controle de botão Exibir em si como um botão padrão pelo próprio desenho com um quadro mais espesso. Consulte [CComControlBase::GetAmbientDisplayAsDefault](../../atl/reference/ccomcontrolbase-class.md#getambientdisplayasdefault) para obter mais informações.  
  
-   **Age como rótulo**: define o `OLEMISC_ACTSLIKELABEL` bit no `OLEMISC` enumeração para ativar um controle substituir rótulo nativo do contêiner. O contêiner determina o que fazer com esse sinalizador, se algo.  
  
 **Outros**  
 Define opções de comportamento adicional para o controle.  
  
-   **Normalizado DC**: define o controle para criar um contexto de dispositivo normalizado quando ele é chamado para desenhar a próprio. Essa ação padroniza a aparência do controle, mas ele torna o desenho menos eficiente.  
  
-   **Somente a janela**: Especifica que o controle não pode ser sem janelas. Se você não selecionar essa opção, o controle será automaticamente sem janelas em contêineres que oferecem suporte a objetos sem janelas e é automaticamente em janelas em contêineres que não dão suporte a objetos sem janelas. Selecionar essa opção força o controle em janela, mesmo em contêineres com suporte para objetos sem janelas.  
  
-   **Inserível**: Selecione esta opção para que o controle seja exibido no **Inserir objeto** caixa de diálogo de aplicativos como Word e Excel. O controle pode ser inserido por qualquer aplicativo que oferece suporte a objetos inseridos por meio da caixa de diálogo.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md)   
 [SUBEDIT exemplo: Superclasse um controle padrão do Windows](http://msdn.microsoft.com/en-us/30e46bdc-ed92-417c-b6b8-359017265a7b)

