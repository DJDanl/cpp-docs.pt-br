---
title: Opções, o Assistente de controle ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.control.options
dev_langs:
- C++
helpviewer_keywords:
- ATL Control Wizard, options
ms.assetid: 4607c51a-992d-433e-9281-919c6f519a3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a1fa026ecb0b25c17a793c31c3f64dcd0186f0e1
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37880084"
---
# <a name="options-atl-control-wizard"></a>Opções, Assistente de controle ATL
Insira "Resultados da pesquisa" Resumo aqui.  
  
 Use esta página do Assistente para definir o tipo de controle que você está criando e o nível de suporte de interface que ele contém.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Tipo de controle**  
 O tipo de controle que você deseja criar.  
  
-   **Controle padrão: um controle ActiveX.**  
  
-   **Controle de composição**: um controle ActiveX que pode conter (semelhante a uma caixa de diálogo) outros controles ActiveX ou controles do Windows. Um controle composto inclui o seguinte:  
  
    -   Um modelo para a caixa de diálogo que implementa o controle de composição.  
  
    -   Um recurso personalizado, registro, que registra automaticamente o controle composto quando invocado.  
  
    -   Uma classe C++ que implementa o controle de composição.  
  
    -   Uma interface COM, exposta pelo controle de composição.  
  
    -   Uma página de teste HTML que contém o controle de composição.  
  
     Por padrão, esse controle define [CComControlBase::m_bWindowOnly](../../atl/reference/ccomcontrolbase-class.md#m_bwindowonly) como true, para indicar que este é um controle da janela. Ele implementa um mapa coletor. Para obter mais informações, consulte [suporte para controle DHTML](../../atl/atl-support-for-dhtml-controls.md).  
  
-   **Controle DHTML**: controle de um DHTML da ATL Especifica a interface do usuário, usando HTML. A classe de UI DHTML contém um mapa COM. Por padrão, esse controle define [CComControlBase::m_bWindowOnly](../../atl/reference/ccomcontrolbase-class.md#m_bwindowonly) como true, para indicar que este é um controle da janela.  
  
     Para obter mais informações, consulte [identificando os elementos do projeto de controle DHTML](../../atl/identifying-the-elements-of-the-dhtml-control-project.md).  
  
 **Controle mínimo**  
 Dá suporte a apenas as interfaces que são absolutamente necessários para a maioria dos contêineres. Você pode definir **controle mínimo** para qualquer um dos tipos de controle: você pode criar um controle padrão mínimo, um controle de composição mínimo ou um controle DHTML mínimo.  
  
 **Agregação**  
 Adiciona o suporte de agregação para o controle que você está criando. Para obter mais informações, consulte [agregação](../../atl/aggregation.md).  
  
-   **Sim**: criar um controle que pode ser agregado.  
  
-   **Não**: criar um controle que não pode ser agregado.  
  
-   **Somente**: criar um controle que pode ser instanciado apenas por meio de agregação.  
  
 **Modelo de Threading**  
 Especifica que o modelo de threading usado pelo controle.  
  
-   **Único**: O controle será executado somente no thread COM primário.  
  
-   **Apartment**: O controle pode ser criado em qualquer apartment de thread único. O padrão.  
  
 **Interface**  
 O tipo de interface que para o contêiner expõe a esse controle.  
  
-   **Dupla**: cria uma interface que expõe propriedades e métodos por meio de `IDispatch` e diretamente por meio de VTBL.  
  
-   **Personalizado**: cria uma interface que expõe métodos diretamente por meio de um VTBL.  
  
     Se você selecionar **personalizado**, em seguida, você pode especificar que o controle está **compatível com a automação**. Se você selecionar **compatível com a automação**, em seguida, o assistente adiciona as [oleautomation](../../windows/oleautomation.md) de atributo na interface em IDL, e a interface pode ser empacotada pelo empacotador universal em oleaut32.dll. Ver [Marshaling detalhes](http://msdn.microsoft.com/library/windows/desktop/ms692621) no SDK do Windows para obter mais informações.  
  
     Além disso, se você selecionar **compatível com a automação**, em seguida, todos os parâmetros para todos os métodos no controle devem ser VARIANT compatível.  
  
 **Suporte**  
 Define o suporte a diverso adicional para o controle.  
  
-   **Pontos de Conexão**: permite que os pontos de conexão para seu objeto, fazendo a classe do seu objeto derivam [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md) e permitindo que ele expõe uma interface de origem.  
  
-   **Licenciado**: adiciona suporte para o controle para [licenciamento](http://msdn.microsoft.com/library/windows/desktop/ms690543). Controles licenciados só podem ser hospedados, se o computador cliente tem a licença correta.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de Controle da ATL](../../atl/reference/atl-control-wizard.md)

