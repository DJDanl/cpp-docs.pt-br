---
title: Perguntas frequentes sobre contenção de controle ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- hosting controls using ATL
- ActiveX control containers [C++], ATL control hosting
- ATL, hosting ActiveX controls
- ActiveX controls [C++], hosting
- controls [ATL]
ms.assetid: d4bdfbe0-82ca-4f2f-bb95-cb89bdcc9b53
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: af14755b9be9413feb3a519d09200577c9260c5a
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50053703"
---
# <a name="atl-control-containment-faq"></a>Perguntas frequentes sobre contenção de controle ATL

## <a name="which-atl-classes-facilitate-activex-control-containment"></a>Quais Classes da ATL facilitam a contenção de controle ActiveX?

Código de hospedagem de controles da ATL não exige que você usar quaisquer classes ATL; Você pode simplesmente criar uma **"AtlAxWin80"** janela e use a API de hospedagem de controles, se necessário (para obter mais informações, consulte **o que é a API de hospedagem de controles de ATL**. No entanto, as seguintes classes de tornam os recursos de contenção mais fácil de usar.

|Classe|Descrição|
|-----------|-----------------|
|[CAxWindow](../atl/reference/caxwindow-class.md)|Encapsula uma **"AtlAxWin80"** janela, fornecendo métodos para criar a janela, criando um controle de e/ou anexar um controle para a janela e recuperar ponteiros de interface no objeto de host.|
|[CAxWindow2T](../atl/reference/caxwindow2t-class.md)|Encapsula uma **"AtlAxWinLic80"** janela, fornecendo métodos para criar a janela, criando um controle de e/ou anexar um controle licenciado para a janela e recuperar ponteiros de interface no objeto de host.|
|[CComCompositeControl](../atl/reference/ccomcompositecontrol-class.md)|Atua como uma classe base para classes de controle ActiveX com base em um recurso de caixa de diálogo. Esses controles podem conter outros controles ActiveX.|
|[CAxDialogImpl](../atl/reference/caxdialogimpl-class.md)|Atua como uma classe base para classes de caixa de diálogo com base em um recurso de caixa de diálogo. Essas caixas de diálogo podem conter controles ActiveX.|
|[CWindow](../atl/reference/cwindow-class.md)|Fornece um método [GetDlgControl](../atl/reference/cwindow-class.md#getdlgcontrol), que retornará um ponteiro de interface em um controle, dado a ID de sua janela de host. Além disso, os wrappers de API do Windows é exposto pelo `CWindow` geralmente facilitar o gerenciamento de janela.|

## <a name="what-is-the-atl-control-hosting-api"></a>O que é a ATL API de hospedagem de controles?

ATL do controle de hospedagem API é o conjunto de funções que permite que qualquer janela atuar como um contêiner de controle ActiveX. Essas funções podem ser estaticamente ou dinamicamente vinculada ao seu projeto, pois eles estão disponíveis como código-fonte e expostos pelo ATL90.dll. As funções de hospedagem de controles são listadas na tabela a seguir.

|Função|Descrição|
|--------------|-----------------|
|[AtlAxAttachControl](reference/composite-control-global-functions.md#atlaxattachcontrol)|Cria um objeto de host, conecta-se à janela fornecida e anexa um controle existente.|
|[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)|Cria um objeto de host, conecta-se à janela fornecida e carrega um controle.|
|[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante à [AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol).|
|[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)|Cria um objeto de host, conecta-se à janela fornecida e, em seguida, carrega um controle (também permite que os coletores de eventos para ser configurado).|
|[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante à [AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic).|
|[AtlAxCreateDialog](reference/composite-control-global-functions.md#atlaxcreatedialog)|Cria uma caixa de diálogo sem janela restrita de um recurso de caixa de diálogo e retorna o identificador de janela.|
|[AtlAxDialogBox](reference/composite-control-global-functions.md#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um recurso de caixa de diálogo.|
|[AtlAxGetControl](reference/composite-control-global-functions.md#atlaxgetcontrol)|Retorna o **IUnknown** ponteiro de interface do controle hospedado em uma janela.|
|[AtlAxGetHost](reference/composite-control-global-functions.md#atlaxgethost)|Retorna o **IUnknown** ponteiro de interface do objeto de host conectado a uma janela.|
|[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit)|Inicializa o código de hospedagem de controles.|
|[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm)|Encerra o código de hospedagem de controles.|

O `HWND` parâmetros nas três primeiras funções devem ser uma janela existente de (quase) qualquer tipo. Se você chamar qualquer uma dessas três funções explicitamente (normalmente, você não precisará), não passe um identificador para uma janela que já está atuando como um host (se você fizer isso, o objeto de host existente não ser liberado).

As primeiras sete funções chamam [AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) implicitamente.

> [!NOTE]
>  A API de hospedagem de controles constitui a base do suporte do ATL para contenção de controle ActiveX. No entanto, geralmente há pouca necessidade de chamar essas funções diretamente se você tira proveito dos ou fazer uso integral de classes de wrapper do ATL. Para obter mais informações, consulte [quais Classes facilitar ActiveX contenção de controle ATL](which-atl-classes-facilitate-activex-control-containment-q.md).

## <a name="what-is-atlaxwin100"></a>O que é AtlAxWin100?

`AtlAxWin100` é o nome de uma classe de janela que ajuda a fornecer a funcionalidade de hospedagem de controles da ATL. Quando você cria uma instância dessa classe, o procedimento de janela usará automaticamente a API de hospedagem de controles para criar um objeto de host associado à janela e carregá-lo com o controle que você especificar como o título da janela.

## <a name="when-do-i-need-to-call-atlaxwininit"></a>Quando é necessário chamar AtlAxWinInit?

[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) registra o **"AtlAxWin80"** classe de janela (além de algumas mensagens de janela personalizados) para que essa função deve ser chamada antes de tentar criar uma janela de host. No entanto, sempre não precisa chamar essa função explicitamente, desde hospedagem APIs (e as classes que usá-los) geralmente chamar essa função para você. Não há nenhum prejuízo em chamar essa função com mais de uma vez.

## <a name="what-is-a-host-object"></a>O que é um objeto de Host?

Um objeto de host é um objeto COM que representa o contêiner de controle ActiveX fornecido pelo ATL para uma janela específica. O host do objeto subclasses de janela do contêiner que pode refletir mensagens para o controle, ele fornece as interfaces de contêiner necessárias a ser usado pelo controle e que ele expõe o [IAxWinHostWindow](../atl/reference/iaxwinhostwindow-interface.md) e [ IAxWinAmbientDispatch](../atl/reference/iaxwinambientdispatch-interface.md) interfaces para permitir que você configure o ambiente do controle.

Você pode usar o objeto de host para definir as propriedades de ambiente do contêiner.

## <a name="can-i-host-more-than-one-control-in-a-single-window"></a>Posso hospedar mais de um controle em uma única janela?

Não é possível hospedar mais de um controle em uma única janela de host do ATL. Cada janela de host foi desenvolvida para manter o controle exatamente um por vez (Isso permite um mecanismo simples para lidar com propriedades de ambiente reflexão e por controle de mensagem). No entanto, se você precisar que o usuário veja vários controles em uma única janela, é muito simples para criar várias janelas de host como filhos dessa janela.

## <a name="can-i-reuse-a-host-window"></a>Posso reutilizar uma janela de Host?

Não é recomendável que você reutilize o windows de host. Para garantir a robustez do seu código, você deve vincular o tempo de vida da janela do host para o tempo de vida de um único controle.

## <a name="when-do-i-need-to-call-atlaxwinterm"></a>Quando é necessário chamar AtlAxWinTerm?

[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm) cancela o registro a **"AtlAxWin80"** classe de janela. Você deve chamar essa função (se você não precisa criar host do windows), depois que todas as janelas existentes de host tenham sido destruídas. Se você não chamar essa função, a classe de janela será cancelada automaticamente quando o processo termina.

## <a name="hosting-activex-controls-using-atl-axhost"></a>Hospedando controles ActiveX usando AXHost ATL

O exemplo nesta seção mostra como criar AXHost e como hospedar um controle ActiveX usando várias funções ATL. Ele também mostra como acessar os eventos de controle e de coletor (usando [IDispEventImpl](../atl/reference/idispeventimpl-class.md)) do controle que está hospedado. O exemplo hospeda o controle de calendário em uma janela principal ou em uma janela filho.

Observe a definição do `USE_METHOD` símbolo. Você pode alterar o valor desse símbolo para variar entre 1 e 8. O valor do símbolo determina como o controle será criado:

- Para obter valores de par de `USE_METHOD`, a chamada para criar uma janela de subclasses de host e o converte em um host do controle. Para obter valores de número ímpar, o código cria uma janela filho que atua como um host.

- Para obter valores de `USE_METHOD` entre 1 e 4, acessar o controle e a coleta de eventos são realizadas na chamada que também cria o host. Os valores entre 5 e 8 o host para interfaces de consulta e o coletor de gancho.

Segue um resumo:

|USE_METHOD|Host|Controlar o acesso e recepção de evento|Função demonstrada|
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

## <a name="see-also"></a>Consulte também

[Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)<br/>
[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)<br/>
[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)<br/>
[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)<br/>
[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)<br/>
[Classe CAxWindow2T](../atl/reference/caxwindow2t-class.md)<br/>
[Interface IAxWinHostWindowLic](../atl/reference/iaxwinhostwindowlic-interface.md)