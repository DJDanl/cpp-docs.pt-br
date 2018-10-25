---
title: ASP, o Assistente de página componente Active Server ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.asp.asp
dev_langs:
- C++
helpviewer_keywords:
- ATL Active Server Page Component Wizard, ASP
ms.assetid: 4d8cafd6-5e12-4461-8911-29288896af3c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 210ef0d41cd0653718908b10ad64cd6004886c64
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50077745"
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

