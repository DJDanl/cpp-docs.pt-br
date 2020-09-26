---
title: Perguntas frequentes sobre contenção de controle ATL
ms.date: 11/04/2016
helpviewer_keywords:
- hosting controls using ATL
- ActiveX control containers [C++], ATL control hosting
- ATL, hosting ActiveX controls
- ActiveX controls [C++], hosting
- controls [ATL]
ms.assetid: d4bdfbe0-82ca-4f2f-bb95-cb89bdcc9b53
ms.openlocfilehash: 693617589f157d352972485396777cec587a5b8f
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91352693"
---
# <a name="atl-control-containment-faq"></a>Perguntas frequentes sobre contenção de controle ATL

## <a name="which-atl-classes-facilitate-activex-control-containment"></a>Quais classes da ATL facilitam a contenção de controle ActiveX?

O código de Hospedagem de controle da ATL não exige que você use classes ATL; Você pode simplesmente criar uma janela **"AtlAxWin80"** e usar a API de Hospedagem de controle, se necessário (para obter mais informações, consulte **o que é a API de Hospedagem de controle ATL**. No entanto, as classes a seguir tornam os recursos de confinamento mais fáceis de usar.

|Classe|Descrição|
|-----------|-----------------|
|[CAxWindow](../atl/reference/caxwindow-class.md)|Encapsula uma janela **"AtlAxWin80"** , fornecendo métodos para criar a janela, criando um controle e/ou anexando um controle à janela e recuperando ponteiros de interface no objeto de host.|
|[CAxWindow2T](../atl/reference/caxwindow2t-class.md)|Encapsula uma janela **"AtlAxWinLic80"** , fornecendo métodos para criar a janela, criando um controle e/ou anexando um controle licenciado à janela e recuperando ponteiros de interface no objeto de host.|
|[CComCompositeControl](../atl/reference/ccomcompositecontrol-class.md)|Atua como uma classe base para classes de controle ActiveX com base em um recurso de caixa de diálogo. Esses controles podem conter outros controles ActiveX.|
|[CAxDialogImpl](../atl/reference/caxdialogimpl-class.md)|Atua como uma classe base para classes de caixa de diálogo com base em um recurso de caixa de diálogo. Essas caixas de diálogo podem conter controles ActiveX.|
|[CWindow](../atl/reference/cwindow-class.md)|Fornece um método, [GetDlgControl](../atl/reference/cwindow-class.md#getdlgcontrol), que retornará um ponteiro de interface em um controle, dado a ID de sua janela de host. Além disso, os wrappers de API do Windows expostos por `CWindow` geralmente facilitam o gerenciamento de janelas.|

## <a name="what-is-the-atl-control-hosting-api"></a>O que é a API de hospedagem de controles da ATL?

A API de Hospedagem de controle da ATL é o conjunto de funções que permite que qualquer janela atue como um contêiner de controle ActiveX. Essas funções podem ser vinculadas estática ou dinamicamente em seu projeto, pois estão disponíveis como código-fonte e expostas por ATL90.dll. As funções de Hospedagem de controle são listadas na tabela a seguir.

|Função|Descrição|
|--------------|-----------------|
|[AtlAxAttachControl](reference/composite-control-global-functions.md#atlaxattachcontrol)|Cria um objeto de host, conecta-o à janela fornecida e anexa um controle existente.|
|[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)|Cria um objeto de host, conecta-o à janela fornecida e, em seguida, carrega um controle.|
|[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e o hospeda na janela especificada, semelhante a [AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol).|
|[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)|Cria um objeto de host, conecta-o à janela fornecida e, em seguida, carrega um controle (também permite que os coletores de eventos sejam configurados).|
|[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa-o e o hospeda na janela especificada, semelhante a [AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic).|
|[AtlAxCreateDialog](reference/composite-control-global-functions.md#atlaxcreatedialog)|Cria uma caixa de diálogo sem janela restrita a partir de um recurso de caixa de diálogo e retorna o identificador de janela.|
|[AtlAxDialogBox](reference/composite-control-global-functions.md#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um recurso de caixa de diálogo.|
|[AtlAxGetControl](reference/composite-control-global-functions.md#atlaxgetcontrol)|Retorna o ponteiro de interface **IUnknown** do controle hospedado em uma janela.|
|[AtlAxGetHost](reference/composite-control-global-functions.md#atlaxgethost)|Retorna o ponteiro de interface **IUnknown** do objeto de host conectado a uma janela.|
|[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit)|Inicializa o código de Hospedagem de controle.|
|[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm)|Desinicializa o código de Hospedagem de controle.|

Os `HWND` parâmetros nas três primeiras funções devem ser uma janela existente de (quase) qualquer tipo. Se você chamar qualquer uma dessas três funções explicitamente (normalmente, não precisará), não passe um identificador para uma janela que já esteja agindo como um host (se você fizer isso, o objeto de host existente não será liberado).

As primeiras sete funções chamam [AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) implicitamente.

> [!NOTE]
> A API de Hospedagem de controle forma a base do suporte do ATL para a contenção do controle ActiveX. No entanto, geralmente há pouca necessidade de chamar essas funções diretamente se você aproveitar ou fazer uso completo das classes de wrapper da ATL. Para obter mais informações, consulte [quais classes ATL facilitam a contenção do controle ActiveX](#which-atl-classes-facilitate-activex-control-containment).

## <a name="what-is-atlaxwin100"></a>O que é AtlAxWin100?

`AtlAxWin100` é o nome de uma classe de janela que ajuda a fornecer a funcionalidade de Hospedagem de controle da ATL. Quando você cria uma instância dessa classe, o procedimento de janela usará automaticamente a API de Hospedagem de controle para criar um objeto de host associado à janela e carregá-lo com o controle que você especificar como o título da janela.

## <a name="when-do-i-need-to-call-atlaxwininit"></a>Quando é necessário chamar AtlAxWinInit?

[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) registra a classe de janela **"AtlAxWin80"** (mais algumas mensagens de janela personalizadas) para que essa função deva ser chamada antes de tentar criar uma janela de host. No entanto, você nem sempre precisa chamar essa função explicitamente, já que as APIs de hospedagem (e as classes que as usam) geralmente chamam essa função para você. Não há nenhum dano na chamada dessa função mais de uma vez.

## <a name="what-is-a-host-object"></a>O que é um objeto de host?

Um objeto de host é um objeto COM que representa o contêiner de controle ActiveX fornecido pela ATL para uma janela específica. O objeto host faz a subclasse do contêiner para que ele possa refletir mensagens para o controle, ele fornece as interfaces de contêiner necessárias para serem usadas pelo controle e expõe as interfaces [IAxWinHostWindow](../atl/reference/iaxwinhostwindow-interface.md) e [IAxWinAmbientDispatch](../atl/reference/iaxwinambientdispatch-interface.md) para permitir que você configure o ambiente do controle.

Você pode usar o objeto de host para definir as propriedades de ambiente do contêiner.

## <a name="can-i-host-more-than-one-control-in-a-single-window"></a>Posso hospedar mais de um controle em uma única janela?

Não é possível hospedar mais de um controle em uma única janela de host ATL. Cada janela de host é projetada para manter exatamente um controle de cada vez (isso permite um mecanismo simples para lidar com a reflexão de mensagens e as propriedades de ambiente por controle). No entanto, se você precisar que o usuário veja vários controles em uma única janela, é uma questão simples de criar várias janelas de host como filhas dessa janela.

## <a name="can-i-reuse-a-host-window"></a>Posso reutilizar uma janela do host?

Não é recomendável que você reutilize as janelas do host. Para garantir a robustez do seu código, você deve ligar o tempo de vida da janela do host ao tempo de vida de um único controle.

## <a name="when-do-i-need-to-call-atlaxwinterm"></a>Quando é necessário chamar AtlAxWinTerm?

[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm) cancela o registro da classe de janela **"AtlAxWin80"** . Você deve chamar essa função (se não precisar mais criar janelas de host) depois que todas as janelas de host existentes tiverem sido destruídas. Se você não chamar essa função, a classe Window terá o registro cancelado automaticamente quando o processo for encerrado.

## <a name="hosting-activex-controls-using-atl-axhost"></a>Hospedando controles ActiveX usando AXHost ATL

O exemplo nesta seção mostra como criar AXHost e como hospedar um controle ActiveX usando várias funções de ATL. Ele também mostra como acessar os eventos de controle e coletor (usando [IDispEventImpl](../atl/reference/idispeventimpl-class.md)) do controle hospedado. O exemplo hospeda o controle de calendário em uma janela principal ou em uma janela filho.

Observe a definição do `USE_METHOD` símbolo. Você pode alterar o valor desse símbolo para variar entre 1 e 8. O valor do símbolo determina como o controle será criado:

- Para valores de número par de `USE_METHOD` , a chamada para criar o host subclasses de uma janela e a converte em um host de controle. Para valores de números ímpares, o código cria uma janela filho que atua como um host.

- Para valores `USE_METHOD` entre 1 e 4, o acesso ao controle e ao coletor de eventos é realizado na chamada que também cria o host. Os valores entre 5 e 8 consultam o host para interfaces e interceptam o coletor.

Segue um resumo:

|USE_METHOD|Host|Controlar o acesso e o coletor de eventos|Função demonstrada|
|-----------------|----------|--------------------------------------|---------------------------|
|1|Janela filho|Uma etapa|CreateControlLicEx|
|2|Janela principal|Uma etapa|AtlAxCreateControlLicEx|
|3|Janela filho|Uma etapa|CreateControlEx|
|4|Janela principal|Uma etapa|AtlAxCreateControlEx|
|5|Janela filho|Várias etapas|CreateControlLic|
|6|Janela principal|Várias etapas|AtlAxCreateControlLic|
|7|Janela filho|Várias etapas|CreateControl|
|8|Janela principal|Várias etapas|AtlAxCreateControl|

[!code-cpp[NVC_ATL_AxHost#1](../atl/codesnippet/cpp/hosting-activex-controls-using-atl-axhost_1.cpp)]

## <a name="see-also"></a>Confira também

[Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)<br/>
[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)<br/>
[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)<br/>
[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)<br/>
[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)<br/>
[Classe CAxWindow2T](../atl/reference/caxwindow2t-class.md)<br/>
[Interface IAxWinHostWindowLic](../atl/reference/iaxwinhostwindowlic-interface.md)
