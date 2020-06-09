---
title: Clientes de automação
ms.date: 11/04/2016
helpviewer_keywords:
- clients, Automation
- Automation clients
- type libraries, Automation clients
- clients
ms.assetid: 84e34a79-06f6-4752-a33b-ae0ede1d8ecf
ms.openlocfilehash: 9c34f6fccd06635dfb686e6eb1f2cf895bb86989
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626078"
---
# <a name="automation-clients"></a>Clientes de automação

A automação possibilita que seu aplicativo manipule objetos implementados em outro aplicativo ou expor objetos para que possam ser manipulados. Um cliente de automação é um aplicativo que pode manipular objetos expostos pertencentes a outro aplicativo. O aplicativo que expõe os objetos é chamado de servidor de automação. O cliente manipula os objetos do aplicativo de servidor acessando as propriedades e funções dos objetos.

### <a name="types-of-automation-clients"></a>Tipos de clientes de automação

Há dois tipos de clientes de automação:

- Clientes que dinamicamente (em tempo de execução) adquirem informações sobre as propriedades e as operações do servidor.

- Clientes que possuem informações estáticas (fornecidas em tempo de compilação) que especificam as propriedades e as operações do servidor.

Os clientes do primeiro tipo adquirem informações sobre os métodos e as propriedades do servidor consultando o mecanismo do sistema OLE `IDispatch` . Embora seja adequado usar para clientes dinâmicos, `IDispatch` é difícil de usar para clientes estáticos, onde os objetos que estão sendo orientados devem ser conhecidos no momento da compilação. Para clientes vinculados estáticos, as classes do Microsoft Foundation fornecem a classe [COleDispatchDriver](reference/coledispatchdriver-class.md) .

Os clientes vinculados estáticos usam uma classe proxy que é vinculada estaticamente com o aplicativo cliente. Essa classe fornece um encapsulamento C++ de tipo seguro das propriedades e operações do aplicativo de servidor.

A classe `COleDispatchDriver` fornece o suporte principal para o lado do cliente de automação. Usando a caixa de diálogo **Adicionar novo item** , você cria uma classe derivada de `COleDispatchDriver` .

Em seguida, você especifica o arquivo de biblioteca de tipos que descreve as propriedades e funções do objeto do aplicativo do servidor. A caixa de diálogo Adicionar Item lê esse arquivo e cria a `COleDispatchDriver` classe-derivada, com funções de membro que seu aplicativo pode chamar para acessar os objetos do aplicativo do servidor em C++ de maneira segura de tipo. A funcionalidade adicional herdada do `COleDispatchDriver` simplifica o processo de chamar o servidor de automação adequado.

### <a name="handling-events-in-automation-clients"></a>Manipulando eventos em clientes de automação

Se você quiser manipular eventos em seu cliente de automação, precisará adicionar uma interface de coletor. O MFC fornece suporte ao Assistente para adicionar interfaces de coletor para controles ActiveX, mas não para outros servidores COM.

## <a name="see-also"></a>Consulte também

[Clientes de automação: usando bibliotecas de tipo](automation-clients-using-type-libraries.md)<br/>
[Automação](automation.md)<br/>
[Assistente de aplicativo do MFC](reference/mfc-application-wizard.md)
