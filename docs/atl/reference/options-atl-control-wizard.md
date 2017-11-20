---
title: "Opções, o Assistente de controle ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: vc.codewiz.class.atl.control.options
dev_langs: C++
helpviewer_keywords: ATL Control Wizard, options
ms.assetid: 4607c51a-992d-433e-9281-919c6f519a3d
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 314f0c7675212ad1f453da189d6483fc9b8284c4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="options-atl-control-wizard"></a>Opções de Assistente de controle ATL
Insira "Resultados da pesquisa" Resumo aqui.  
  
 Use esta página do Assistente para definir o tipo de controle que você está criando e o nível de suporte de interface que ele contém.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Tipo de controle**  
 O tipo de controle que você deseja criar.  
  
-   **Padrão de controle: um controle ActiveX.**  
  
-   **Controle composto**: um controle ActiveX que pode conter (semelhante a uma caixa de diálogo) outros controles ActiveX ou controles do Windows. Um controle composto inclui o seguinte:  
  
    -   Um modelo para a caixa de diálogo que implementa o controle composto.  
  
    -   Um recurso personalizado do registro, que registra automaticamente o controle composto quando invocado.  
  
    -   Uma classe C++ que implementa o controle composto.  
  
    -   Uma interface COM expostos pelo controle composto.  
  
    -   Uma página de teste HTML que contém o controle composto.  
  
     Por padrão, esse controle define [CComControlBase::m_bWindowOnly](../../atl/reference/ccomcontrolbase-class.md#m_bwindowonly) como true, para indicar que este é um controle com janela. Ele implementa um mapa de coletor. Para obter mais informações, consulte [suporte para controle DHTML](../../atl/atl-support-for-dhtml-controls.md).  
  
-   **Controle DHTML**: controle DHTML de ATL um Especifica a interface do usuário, usando HTML. A classe DHTML UI contém um mapa de COM. Por padrão, esse controle define [CComControlBase::m_bWindowOnly](../../atl/reference/ccomcontrolbase-class.md#m_bwindowonly) como true, para indicar que este é um controle com janela.  
  
     Para obter mais informações, consulte [identificação dos elementos do projeto de controle DHTML](../../atl/identifying-the-elements-of-the-dhtml-control-project.md).  
  
 **Controle mínimo**  
 Oferece suporte a apenas as interfaces que são absolutamente necessário à maioria dos contêineres. Você pode definir **controle mínimo** para qualquer um dos tipos de controle: você pode criar um controle padrão mínimo, um controle composto mínimo ou um controle DHTML mínimo.  
  
 **Agregação**  
 Adiciona o suporte de agregação para o controle que você está criando. Para obter mais informações, consulte [agregação](../../atl/aggregation.md).  
  
-   **Sim**: criar um controle que pode ser agregado.  
  
-   **Não**: criar um controle que não pode ser agregado.  
  
-   **Somente**: criar um controle que pode ser instanciado somente por meio de agregação.  
  
 **Modelo de Threading**  
 Especifica que o modelo de threading usado pelo controle.  
  
-   **Único**: O controle será executado somente no thread COM primário.  
  
-   **Apartment**: O controle pode ser criado em qualquer single thread apartment. O padrão.  
  
 **Interface**  
 O tipo de interface que expõe este controle para o contêiner.  
  
-   **Duplo**: cria uma interface que expõe propriedades e métodos por meio de `IDispatch` e diretamente por meio de VTBL.  
  
-   **Personalizar**: cria uma interface que expõe métodos diretamente por meio de um VTBL.  
  
     Se você selecionar **personalizado**, em seguida, você pode especificar que o controle é **compatível com a automação**. Se você selecionar **compatível com a automação**, em seguida, o assistente adiciona o [oleautomation](../../windows/oleautomation.md) de atributo na interface em IDL, e a interface pode ser empacotada pelo empacotador universal no oleaut32.dll. Consulte [Marshaling detalhes](http://msdn.microsoft.com/library/windows/desktop/ms692621) no SDK do Windows para obter mais informações.  
  
     Além disso, se você selecionar **compatível com a automação**, em seguida, todos os parâmetros para todos os métodos no controle devem ser **VARIANT** compatível.  
  
 **Suporte**  
 Define o suporte a diverso adicional para o controle.  
  
-   **Pontos de Conexão**: permite que os pontos de conexão para seu objeto fazendo a classe do objeto derivam [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md) e permitindo que ele expõe uma interface de origem.  
  
-   **Licenciado**: adiciona o suporte para o controle para [licenciamento](http://msdn.microsoft.com/library/windows/desktop/ms690543). Controles licenciados só podem ser hospedados, se o computador cliente tem a licença correta.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de Controle da ATL](../../atl/reference/atl-control-wizard.md)

