---
title: Opções, assistente de controle ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.control.options
helpviewer_keywords:
- ATL Control Wizard, options
ms.assetid: 4607c51a-992d-433e-9281-919c6f519a3d
ms.openlocfilehash: 481c97fe7621e9592317f629c2cf87f2f719d5d1
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506912"
---
# <a name="options-atl-control-wizard"></a>Opções, assistente de controle ATL

Use esta página do assistente para definir o tipo de controle que você está criando e o nível de suporte de interface que ele contém.

## <a name="uielement-list"></a>Lista de elementos de interface do usuário

### <a name="control-type"></a>Tipo de controle

O tipo de controle que você deseja criar.

- **Controle padrão**: um controle ActiveX.

- **Controle composto**: um controle ActiveX que pode conter (semelhante a uma caixa de diálogo) outros controles ActiveX ou controles do Windows. Um controle composto inclui o seguinte:

  - Um modelo para a caixa de diálogo que implementa o controle composto.

  - Um recurso personalizado, registro, que registra automaticamente o controle composto quando invocado.

  - Uma classe C++ que implementa o controle composto.

  - Uma interface COM, exposta pelo controle composto.

  - Uma página de teste HTML que contém o controle composto.

    Por padrão, esse controle define [CComControlBase:: m_bWindowOnly](../../atl/reference/ccomcontrolbase-class.md#m_bwindowonly) como true, para indicar que esse é um controle em janela. Ele implementa um mapa do coletor. Para obter mais informações, consulte [suporte para controle DHTML](../../atl/atl-support-for-dhtml-controls.md).

- **Controle DHTML**: um controle DHTML ATL especifica a interface do usuário, usando HTML. A classe de interface do usuário DHTML contém um mapa COM. Por padrão, esse controle define [CComControlBase:: m_bWindowOnly](../../atl/reference/ccomcontrolbase-class.md#m_bwindowonly) como true, para indicar que esse é um controle em janela.

   Para obter mais informações, consulte [identificando os elementos do projeto de controle DHTML](../../atl/identifying-the-elements-of-the-dhtml-control-project.md).

### <a name="minimal-control"></a>Controle mínimo

O oferece suporte apenas às interfaces que são absolutamente necessárias para a maioria dos contêineres. Você pode definir o **mínimo** de controle para qualquer um dos tipos de controle: você pode criar um controle padrão mínimo, um controle de composição mínimo ou um controle DHTML mínimo.

### <a name="aggregation"></a>Agregação

Adiciona suporte à agregação para o controle que você está criando. Para obter mais informações, consulte [agregação](../../atl/aggregation.md).

- **Sim**: Crie um controle que possa ser agregado.

- **Não**: Crie um controle que não possa ser agregado.

- **Somente**: Crie um controle que só pode ser instanciado por meio de agregação.

### <a name="threading-model"></a>Modelo de threading

Especifica que o modelo de Threading usado pelo controle.

- **Único**: o controle será executado somente no thread com primário.

- **Apartment**: o controle pode ser criado em qualquer single thread apartment. O padrão.

### <a name="interface"></a>Interface

O tipo de interface que esse controle expõe ao contêiner.

- **Dual**: cria uma interface que expõe propriedades e métodos por meio `IDispatch` de e diretamente por meio de VTBL.

- **Personalizado**: cria uma interface que expõe métodos diretamente por meio de um VTBL.

   Se você selecionar **personalizado**, poderá especificar que o controle é **compatível com a automação**. Se você selecionar **compatível com automação**, o assistente adicionará o atributo [oleautomation](../../windows/attributes/oleautomation.md) à interface em IDL, e a interface poderá ser empacotada pelo marshaler universal no oleaut32.dll. Consulte [detalhes de marshaling](/windows/win32/com/marshaling-details) no SDK do Windows para obter mais informações.

   Além disso, se você selecionar a **automação compatível**, todos os parâmetros de todos os métodos no controle deverão ser compatíveis com a variante.

### <a name="support"></a>Suporte

Define suporte variado adicional para o controle.

- **Pontos de conexão**: habilita pontos de conexão para o objeto, fazendo com que a classe do objeto derive de [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md) e permitindo que ele exponha uma interface de origem.

- **Licenciado**: adiciona suporte ao controle para [Licenciamento](/windows/win32/com/licensing). Os controles licenciados só poderão ser hospedados se o computador cliente tiver a licença correta.

## <a name="see-also"></a>Consulte também

[Assistente de controle da ATL](../../atl/reference/atl-control-wizard.md)
