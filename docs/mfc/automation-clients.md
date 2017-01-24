---
title: "Clientes de automa&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Clientes de automação"
  - "clientes"
  - "clientes, Automação"
  - "bibliotecas de tipo, Clientes de automação"
ms.assetid: 84e34a79-06f6-4752-a33b-ae0ede1d8ecf
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Clientes de automa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A automação possibilita para que seu aplicativo manipule os objetos implementados em outro aplicativo, ou expõe objetos para que possam ser manipulados.  Um cliente de automação é um aplicativo que pode manipular expõe os objetos que pertencem a um outro aplicativo.  O aplicativo que expõe objetos é chamado servidor de automação.  O cliente manipula os objetos de aplicativo de servidor acessando as propriedades e as funções desses objetos.  
  
### Tipos de clientes de automação  
 Há dois tipos de clientes de automação:  
  
-   Clientes que \(dinamicamente em tempo de execução\) adquira informações sobre as propriedades e o funcionamento do servidor.  
  
-   Clientes que possuem informações estáticas \(fornecida em tempo de compilação\) que especifica as propriedades e o funcionamento do servidor.  
  
 Os clientes do primeiro tipo adquirem informações sobre os métodos e as propriedades do servidor consultando o mecanismo de OLE `IDispatch` do sistema.  Embora seja suficiente usar para clientes dinâmicos, `IDispatch` é difícil de ser usada para os clientes estáticos, onde os objetos que estão sendo por devem ser conhecidos em tempo de compilação.  Para clientes associados estáticos, as classes do Microsoft fornecem a classe de [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md) .  
  
 Os clientes associados estáticos usam uma classe de proxy que está vinculada estatisticamente com o aplicativo cliente.  Esta classe fornece uma encapsulamento fortemente tipado C\+\+ propriedades e as operações de aplicativo de servidor.  
  
 A classe `COleDispatchDriver` fornece suporte principal para o lado do cliente de automação.  Usando a caixa de diálogo `Add New Item` , você cria uma classe derivada de `COleDispatchDriver`.  
  
 Você especifica o arquivo de biblioteca de tipos que descreve as propriedades e as funções do objeto de aplicativo de servidor.  A caixa de diálogo do item adicionar ler este arquivo e cria `COleDispatchDriver`\- classe derivada, com funções de membro que seu aplicativo pode chamar para acessar os objetos de aplicativo de servidor em C\+\+ de uma maneira fortemente tipado.  A funcionalidade adicional herdada de `COleDispatchDriver` simplifica o processo do servidor apropriado de automação.  
  
### Eventos de manipulação de clientes de automação  
 Se você quiser tratar eventos no cliente de automação, você precisa adicionar uma interface de coletor.  MFC O fornece suporte do assistente para adicionar interfaces de coletor para controles ActiveX, mas não oferece suporte para outros servidores COM.  Para obter mais informações sobre como adicionar uma interface de coletor em um cliente de MFC para as interfaces de origem descritas por servidores COM, consulte HOWTO: Crie uma interface de coletor no cliente MFC\- baseado em COM \(KB 181845\) em [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;181845](http://support.microsoft.com/default.aspx?scid=kb;en-us;181845).  
  
## Consulte também  
 [Clientes de automação: usando bibliotecas de tipo](../Topic/Automation%20Clients:%20Using%20Type%20Libraries.md)   
 [Automação](../mfc/automation.md)   
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)