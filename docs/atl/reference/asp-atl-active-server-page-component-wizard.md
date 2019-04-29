---
title: ASP, o Assistente de componente de página de servidor ativo do ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.asp.asp
helpviewer_keywords:
- ATL Active Server Page Component Wizard, ASP
ms.assetid: 4d8cafd6-5e12-4461-8911-29288896af3c
ms.openlocfilehash: efc82edf00a9bb2f2facbd883ef88f1d093e0133
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62261319"
---
# <a name="asp-atl-active-server-page-component-wizard"></a>ASP, o Assistente de componente de página de servidor ativo do ATL

Use esta página do Assistente de componentes do ATL Active Server página para especificar configurações opcionais para lidar com informações e estado relacionado para seu componente ASP.

- **Métodos opcionais**

   Adiciona os métodos opcionais do ASP, **OnStartPage** e **OnEndPage**, para seu objeto. Essa opção deve ser selecionada para definir quaisquer objetos intrínsecos do Active Server Pages. Por padrão, ele é selecionado.

- **OnStartPage/OnEndPage**

   [OnStartPage](https://msdn.microsoft.com/library/ms691624.aspx) é chamado na primeira vez em que o script tenta acessar o objeto. **OnEndPage** é chamado quando o objeto é concluído o script de processamento.

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
[Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)
