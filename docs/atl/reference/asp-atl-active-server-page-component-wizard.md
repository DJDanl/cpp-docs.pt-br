---
title: ASP, o Assistente de componente de página Active Server ATL | Microsoft Docs
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
ms.openlocfilehash: dfe27a64a2086f08c5a29e2961d069771fdbc4e6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="asp-atl-active-server-page-component-wizard"></a>ASP, o Assistente de componente de página Active Server ATL
Use esta página do Assistente de componente do ATL Active Server página para especificar configurações opcionais para manipular informações e estados relacionados para o seu componente ASP.  
  
 **Métodos opcionais**  
 Adiciona os métodos opcionais do ASP, **OnStartPage** e **OnEndPage**, para o objeto. Essa opção deve ser selecionada para definir qualquer objetos intrínsecos do Active Server Pages. Por padrão, ele é selecionado.  
  
-   **OnStartPage/OnEndPage** [OnStartPage](https://msdn.microsoft.com/library/ms691624.aspx) é chamado da primeira vez que o script tenta acessar o objeto. **OnEndPage** é chamado quando o objeto for concluído o script de processamento.  
  
 **Objeto intrínseco**  
 Você deve selecionar o **OnStartPage/OnEndPage** opção para definir qualquer objetos intrínsecos do ASP.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Solicitação**|Fornece acesso para o Active Server Pages intrínseco **solicitação** objeto. O objeto de solicitação é usado para transmitir uma solicitação HTTP.|  
|**Resposta**|Fornece acesso para o Active Server Pages intrínseco **resposta** objeto. Em resposta a uma solicitação, o objeto Response envia informações ao navegador para exibir para o usuário.|  
|**Sessão**|Fornece acesso para o Active Server Pages intrínseco **sessão** objeto. O **sessão** objeto mantém informações sobre a sessão atual do usuário, incluindo a armazenar e recuperar informações de estado.|  
|**Aplicativo**|Fornece acesso para o Active Server Pages intrínseco **aplicativo** objeto. O **aplicativo** objeto gerencia o estado que é compartilhado por vários objetos do ASP.|  
|**Servidor**|Fornece acesso para o Active Server Pages intrínseco **Server** objeto. O **Server** objeto permite que você crie outros objetos do ASP.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de componente de página Active Server ATL](../../atl/reference/atl-active-server-page-component-wizard.md)   
 [Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)

