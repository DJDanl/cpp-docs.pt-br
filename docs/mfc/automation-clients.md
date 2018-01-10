---
title: "Clientes de automação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- clients, Automation
- Automation clients
- type libraries, Automation clients
- clients
ms.assetid: 84e34a79-06f6-4752-a33b-ae0ede1d8ecf
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9cfb6aae5c947d1f36019e548c72b22a3304aa12
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="automation-clients"></a>Clientes de automação
Automação torna possível para o seu aplicativo para manipular objetos implementados em outro aplicativo ou para expor os objetos para que eles podem ser manipulados. Um cliente de automação é um aplicativo que pode manipular objetos expostos que pertencem a outro aplicativo. O aplicativo que expõe objetos é chamado de servidor de automação. O cliente manipula os objetos do aplicativo de servidor acessando as funções e as propriedades desses objetos.  
  
### <a name="types-of-automation-clients"></a>Tipos de clientes de automação  
 Há dois tipos de clientes de automação:  
  
-   Clientes que adquirem informações sobre as propriedades e operações do servidor dinamicamente (em tempo de execução).  
  
-   Clientes que possuem informações estáticas (fornecidas no tempo de compilação) que especifica as propriedades e operações do servidor.  
  
 Os clientes do tipo primeiro adquirem informações sobre os métodos e propriedades do servidor consultando o sistema OLE `IDispatch` mecanismo. Embora seja adequado a ser usado para clientes dinâmicos, `IDispatch` é difícil de usar para clientes estáticos, onde os objetos que está sendo controlada por deve ser conhecida em tempo de compilação. Para clientes associadas ao estático, as Microsoft Foundation classes fornecem o [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md) classe.  
  
 Clientes de limite estáticos usam uma classe de proxy que está estaticamente vinculada com o aplicativo cliente. Essa classe fornece um encapsulamento de C++ fortemente tipado de operações e propriedades do aplicativo de servidor.  
  
 A classe `COleDispatchDriver` fornece o suporte principal para o lado do cliente de automação. Usando o `Add New Item` caixa de diálogo, você cria uma classe derivada de `COleDispatchDriver`.  
  
 Você, em seguida, especifique o arquivo de biblioteca de tipos que descrevem as propriedades e as funções do objeto do aplicativo de servidor. A caixa de diálogo Adicionar Item lê o arquivo e cria o `COleDispatchDriver`-derivado da classe, com funções de membro que seu aplicativo pode chamar para acessar objetos do aplicativo de servidor em C++ de uma maneira de tipo seguro. Funcionalidade adicional herdado de `COleDispatchDriver` simplifica o processo de chamada do servidor de automação adequado.  
  
### <a name="handling-events-in-automation-clients"></a>Manipulação de eventos em clientes de automação  
 Se você desejar tratar eventos no cliente de automação, você precisa adicionar uma interface de coletor. MFC fornece suporte do Assistente para adicionar as interfaces de coletor para controles ActiveX, mas não oferece suporte para outros servidores COM. Para obter informações sobre como adicionar uma interface do coletor em um cliente do MFC para interfaces de origem descrito por servidores COM, consulte como: criar uma Interface do coletor no cliente de COM MFC-Based (181845 KB) em [http://support.microsoft.com/default.aspxscid=kb;en-us; 181845](http://support.microsoft.com/default.aspxscid=kb;en-us;181845).  
  
## <a name="see-also"></a>Consulte também  
 [Clientes de automação: Usando bibliotecas de tipo](../mfc/automation-clients-using-type-libraries.md)   
 [Automação](../mfc/automation.md)   
 [Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md)

