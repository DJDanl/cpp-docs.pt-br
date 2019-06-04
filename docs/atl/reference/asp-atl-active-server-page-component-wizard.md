---
title: ASP, o Assistente de componente de página de servidor ativo do ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.asp.asp
helpviewer_keywords:
- ATL Active Server Page Component Wizard, ASP
ms.assetid: 4d8cafd6-5e12-4461-8911-29288896af3c
ms.openlocfilehash: b88dffe2874d29918315af65c6ea093c24695f97
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66503405"
---
# <a name="asp-atl-active-server-page-component-wizard"></a>ASP, o Assistente de componente de página de servidor ativo do ATL

Use esta página do Assistente de componentes do ATL Active Server página para especificar configurações opcionais para lidar com informações e estado relacionado para seu componente ASP.

- **Métodos opcionais**

   Adiciona os métodos opcionais do ASP, **OnStartPage** e **OnEndPage**, para seu objeto. Essa opção deve ser selecionada para definir quaisquer objetos intrínsecos do Active Server Pages. Por padrão, ele é selecionado.

- **OnStartPage/OnEndPage**

   [OnStartPage](/previous-versions//ms691624\(v=vs.85\)) é chamado na primeira vez em que o script tenta acessar o objeto. **OnEndPage** é chamado quando o objeto é concluído o script de processamento.

- **Objeto intrínseco**

   Você deve selecionar o **OnStartPage/OnEndPage** opção de definir quaisquer objetos intrínsecos de ASP.

|Opção|Descrição|
|------------|-----------------|
|**Solicitação**|Fornece acesso para o Active Server Pages intrínseco **solicitar** objeto. O objeto de solicitação é usado para transmitir uma solicitação HTTP.|
|**Resposta**|Fornece acesso para o Active Server Pages intrínseco **resposta** objeto. Em resposta a uma solicitação, o objeto de resposta envia informações ao navegador para exibir para o usuário.|
|**Sessão**|Fornece acesso para o Active Server Pages intrínseco **sessão** objeto. O **sessão** objeto mantém informações sobre a sessão atual do usuário, incluindo a armazenar e recuperar informações de estado.|
|**Aplicativo**|Fornece acesso para o Active Server Pages intrínseco **aplicativo** objeto. O **aplicativo** objeto gerencia o estado é compartilhado entre vários objetos de ASP.|
|**Servidor**|Fornece acesso para o Active Server Pages intrínseco **Server** objeto. O **Server** objeto permite que você crie outros objetos ASP.|

## <a name="see-also"></a>Consulte também

[Assistente do componente Active Server Page da ATL](../../atl/reference/atl-active-server-page-component-wizard.md)<br/>
[Componente Active Server Page da ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)
