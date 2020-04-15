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
ms.openlocfilehash: 36ff3381447b46b28908522d65be9f34fe23addf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317394"
---
# <a name="atl-control-containment-faq"></a>Perguntas frequentes sobre contenção de controle ATL

## <a name="which-atl-classes-facilitate-activex-control-containment"></a>Quais classes da ATL facilitam a contenção de controle ActiveX?

O código de hospedagem de controle da ATL não exige que você use nenhuma classe ATL; você pode simplesmente criar uma janela **"AtlAxWin80"** e usar a API de hospedagem de controle, se necessário (para obter mais informações, consulte **O que é a API de hospedagem de controle ATL**. No entanto, as classes a seguir facilitam o uso dos recursos de contenção.

|Classe|Descrição|
|-----------|-----------------|
|[Caxwindow](../atl/reference/caxwindow-class.md)|Envolve uma janela **"AtlAxWin80",** fornecendo métodos para criar a janela, criar um controle e/ou anexar um controle à janela e recuperar ponteiros de interface no objeto host.|
|[Caxwindow2t](../atl/reference/caxwindow2t-class.md)|Envolve uma janela **"AtlAxWinLic80",** fornecendo métodos para criar a janela, criar um controle e/ou anexar um controle licenciado à janela e recuperar ponteiros de interface no objeto host.|
|[Ccomcompositecontrol](../atl/reference/ccomcompositecontrol-class.md)|Atua como uma classe base para classes de controle ActiveX com base em um recurso de diálogo. Esses controles podem conter outros controles ActiveX.|
|[Caxdialogimpl](../atl/reference/caxdialogimpl-class.md)|Atua como uma classe base para classes de diálogo com base em um recurso de diálogo. Essas diálogos podem conter controles ActiveX.|
|[Cwindow](../atl/reference/cwindow-class.md)|Fornece um método, [GetDlgControl,](../atl/reference/cwindow-class.md#getdlgcontrol)que retornará um ponteiro de interface em um controle, dado o ID de sua janela host. Além disso, os invólucros `CWindow` da API do Windows expostos geralmente facilitam o gerenciamento de janelas.|

## <a name="what-is-the-atl-control-hosting-api"></a>O que é a API de hospedagem de controles da ATL?

A API de hospedagem de controle da ATL é o conjunto de funções que permite que qualquer janela atue como um contêiner de controle ActiveX. Essas funções podem ser estáticamente ou dinamicamente ligadas ao seu projeto, uma vez que estão disponíveis como código fonte e expostas por ATL90.dll. As funções de hospedagem de controle estão listadas na tabela abaixo.

|Função|Descrição|
|--------------|-----------------|
|[AtlAxAttachControl](reference/composite-control-global-functions.md#atlaxattachcontrol)|Cria um objeto host, conecta-o à janela fornecida e anexa um controle existente.|
|[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)|Cria um objeto host, conecta-o à janela fornecida e carrega um controle.|
|[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante ao [AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol).|
|[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)|Cria um objeto host, conecta-o à janela fornecida e carrega um controle (também permite que os dissipadores de eventos sejam configurados).|
|[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante ao [AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic).|
|[AtlAxCreateDialog](reference/composite-control-global-functions.md#atlaxcreatedialog)|Cria uma caixa de diálogo modeless a partir de um recurso de diálogo e retorna a alça da janela.|
|[AtlAxDialogBox](reference/composite-control-global-functions.md#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um recurso de diálogo.|
|[AtlAxGetControl](reference/composite-control-global-functions.md#atlaxgetcontrol)|Retorna o ponteiro de interface **IUnknown** do controle hospedado em uma janela.|
|[AtlAxGetHost](reference/composite-control-global-functions.md#atlaxgethost)|Retorna o ponteiro de interface **IUnknown** do objeto host conectado a uma janela.|
|[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit)|Inicializa o código de hospedagem de controle.|
|[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm)|Desinicializa o código de hospedagem de controle.|

Os `HWND` parâmetros nas três primeiras funções devem ser uma janela existente de (quase) qualquer tipo. Se você chamar qualquer uma dessas três funções explicitamente (normalmente, você não precisa), não passe uma alça para uma janela que já está agindo como um host (se você fizer isso, o objeto hospedeiro existente não será liberado).

As primeiras sete funções chamam [AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) implicitamente.

> [!NOTE]
> A API de hospedagem de controle forma a base do suporte da ATL para a contenção de controle ActiveX. No entanto, geralmente há pouca necessidade de chamar essas funções diretamente se você tirar proveito ou fazer uso total das classes de invólucro da ATL. Para obter mais informações, consulte [Quais classes ATL facilitam a contenção de controle ActiveX](which-atl-classes-facilitate-activex-control-containment-q.md).

## <a name="what-is-atlaxwin100"></a>O que é AtlAxWin100?

`AtlAxWin100`é o nome de uma classe de janelas que ajuda a fornecer a funcionalidade de hospedagem de controle da ATL. Quando você cria uma instância dessa classe, o procedimento de janela usará automaticamente a API de hospedagem de controle para criar um objeto host associado à janela e carregá-lo com o controle que você especifica como o título da janela.

## <a name="when-do-i-need-to-call-atlaxwininit"></a>Quando é necessário chamar AtlAxWinInit?

[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) registra a classe de janela **"AtlAxWin80"** (mais algumas mensagens de janela personalizadas) então essa função deve ser chamada antes de tentar criar uma janela de host. No entanto, nem sempre você precisa chamar essa função explicitamente, já que as APIs de hospedagem (e as classes que as usam) muitas vezes chamam essa função para você. Não há mal nenhum em chamar essa função mais de uma vez.

## <a name="what-is-a-host-object"></a>O que é um objeto de host?

Um objeto host é um objeto COM que representa o recipiente de controle ActiveX fornecido pela ATL para uma janela específica. O objeto host subclassifica a janela do contêiner para que ele possa refletir mensagens para o controle, fornece as interfaces de contêiner necessárias para serem usadas pelo controle e expõe as interfaces [IAxWinHostWindow](../atl/reference/iaxwinhostwindow-interface.md) e [IAxWinAmbientDispatch](../atl/reference/iaxwinambientdispatch-interface.md) para permitir que você configure o ambiente do controle.

Você pode usar o objeto host para definir as propriedades ambientais do recipiente.

## <a name="can-i-host-more-than-one-control-in-a-single-window"></a>Posso hospedar mais de um controle em uma única janela?

Não é possível hospedar mais de um controle em uma única janela de host ATL. Cada janela do host é projetada para manter exatamente um controle de cada vez (isso permite um mecanismo simples para lidar com a reflexão de mensagens e propriedades ambientais por controle). No entanto, se você precisa que o usuário veja vários controles em uma única janela, é uma questão simples criar várias janelas de host como filhos dessa janela.

## <a name="can-i-reuse-a-host-window"></a>Posso reutilizar uma janela do host?

Não é recomendável que você reutilize janelas host. Para garantir a robustez do seu código, você deve vincular a vida útil da janela do seu host à vida de um único controle.

## <a name="when-do-i-need-to-call-atlaxwinterm"></a>Quando é necessário chamar AtlAxWinTerm?

[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm) não registra a classe de janela **"AtlAxWin80".** Você deve chamar essa função (se você não precisar mais criar janelas de host) depois que todas as janelas de host existentes foram destruídas. Se você não chamar essa função, a classe de janela será desregistrada automaticamente quando o processo terminar.

## <a name="hosting-activex-controls-using-atl-axhost"></a>Hospedando controles ActiveX usando AXHost ATL

A amostra nesta seção mostra como criar o AXHost e como hospedar um controle ActiveX usando várias funções ATL. Ele também mostra como acessar os eventos de controle e afundamento (usando [IDispEventImpl](../atl/reference/idispeventimpl-class.md)) a partir do controle que está hospedado. A amostra hospeda o controle Calendário em uma janela principal ou em uma janela de criança.

Observe a definição `USE_METHOD` do símbolo. Você pode alterar o valor deste símbolo para variar entre 1 e 8. O valor do símbolo determina como o controle será criado:

- Para valores numerados `USE_METHOD`uniformes de , a chamada para criar o host subclasses uma janela e converte-a em um host de controle. Para valores numerados ímpares, o código cria uma janela de criança que age como um host.

- Para valores `USE_METHOD` entre 1 e 4, o acesso ao controle e afundamento dos eventos são realizados na chamada que também cria o host. Valores entre 5 e 8 consultar o host para interfaces e ligar a pia.

Segue um resumo:

|USE_METHOD|Host|Controle de acesso e afundamento de eventos|Função demonstrada|
|-----------------|----------|--------------------------------------|---------------------------|
|1|Janela da criança|Um passo|CreateControlLicEx|
|2|Janela principal|Um passo|AtlAxCreateControlLicEx|
|3|Janela da criança|Um passo|Createcontrolex|
|4|Janela principal|Um passo|AtlAxCreateControlEx|
|5|Janela da criança|Várias etapas|CreateControlLic|
|6|Janela principal|Várias etapas|AtlAxCreateControlLic|
|7|Janela da criança|Várias etapas|CreateControl|
|8|Janela principal|Várias etapas|AtlAxCreateControl|

[!code-cpp[NVC_ATL_AxHost#1](../atl/codesnippet/cpp/hosting-activex-controls-using-atl-axhost_1.cpp)]

## <a name="see-also"></a>Confira também

[Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)<br/>
[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)<br/>
[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)<br/>
[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)<br/>
[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)<br/>
[Classe CAxWindow2T](../atl/reference/caxwindow2t-class.md)<br/>
[IAxWinHostWindowLic Interface](../atl/reference/iaxwinhostwindowlic-interface.md)
