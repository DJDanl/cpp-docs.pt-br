---
title: "ASP, o Assistente de componente de página do Active Server ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.asp.asp
dev_langs:
- C++
helpviewer_keywords:
- ATL Active Server Page Component Wizard, ASP
ms.assetid: 4d8cafd6-5e12-4461-8911-29288896af3c
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8652215b98738a2482a9f71b8f48b45ee1ff644b
ms.lasthandoff: 02/25/2017

---
# <a name="asp-atl-active-server-page-component-wizard"></a>ASP, o Assistente de componente de página do Active Server ATL
Use esta página do Assistente de componentes do ATL Active Server página para especificar configurações opcionais para manipulação de estado relacionadas ao componente ASP e informações.  
  
 **Métodos opcionais**  
 Adiciona os métodos opcionais do ASP, **OnStartPage** e **OnEndPage**, para o objeto. Essa opção deve ser selecionada para definir quaisquer objetos intrínsecos do Active Server Pages. Por padrão, ele é selecionado.  
  
-   **OnStartPage/OnEndPage** [OnStartPage](https://msdn.microsoft.com/library/ms691624.aspx) é chamado na primeira vez em que o script tenta acessar o objeto. **OnEndPage** é chamado quando o objeto for concluído o script de processamento.  
  
 **Objeto intrínseco**  
 Você deve selecionar o **OnStartPage/OnEndPage** opção de definir quaisquer objetos intrínsecos do ASP.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Solicitação**|Fornece acesso para o Active Server Pages intrínseco **solicitação** objeto. O objeto de solicitação é usado para passar uma solicitação HTTP.|  
|**Resposta**|Fornece acesso para o Active Server Pages intrínseco **resposta** objeto. Em resposta a uma solicitação, o objeto de resposta envia informações para o navegador para exibir para o usuário.|  
|**Sessão**|Fornece acesso para o Active Server Pages intrínseco **sessão** objeto. O **sessão** objeto mantém informações sobre a sessão atual do usuário, incluindo a armazenar e recuperar informações de estado.|  
|**Aplicativo**|Fornece acesso para o Active Server Pages intrínseco **aplicativo** objeto. O **aplicativo** objeto gerencia o estado que é compartilhado entre vários objetos ASP.|  
|**Servidor**|Fornece acesso para o Active Server Pages intrínseco **Server** objeto. O **Server** objeto permite que você crie outros objetos ASP.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de componente de página do Active Server ATL](../../atl/reference/atl-active-server-page-component-wizard.md)   
 [Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)


