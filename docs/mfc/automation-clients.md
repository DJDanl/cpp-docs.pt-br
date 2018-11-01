---
title: Clientes de automação
ms.date: 11/04/2016
helpviewer_keywords:
- clients, Automation
- Automation clients
- type libraries, Automation clients
- clients
ms.assetid: 84e34a79-06f6-4752-a33b-ae0ede1d8ecf
ms.openlocfilehash: 30511ec6c9f0e00f4cec51e00f85ea5e32453327
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50465488"
---
# <a name="automation-clients"></a>Clientes de automação

Automação torna possível para seu aplicativo para manipular objetos implementados em outro aplicativo ou para expor objetos para que eles podem ser manipulados. Um cliente de automação é um aplicativo que pode manipular objetos expostos que pertence a outro aplicativo. O aplicativo que expõe os objetos é chamado o servidor de automação. O cliente manipula os objetos do aplicativo de servidor acessando as funções e as propriedades desses objetos.

### <a name="types-of-automation-clients"></a>Tipos de clientes de automação

Há dois tipos de clientes de automação:

- Clientes que adquirem informações sobre as propriedades e operações do servidor dinamicamente (no tempo de execução).

- Clientes que possuem informações estáticas (fornecidas no tempo de compilação) que especifica as propriedades e operações do servidor.

Os clientes do primeiro tipo adquirem informações sobre os métodos e propriedades do servidor consultando o sistema OLE `IDispatch` mecanismo. Embora seja adequada a ser usado para clientes dinâmicos, `IDispatch` é difícil de usar para clientes estáticos, onde os objetos que está sendo controlado por deve ser conhecido no tempo de compilação. Para estático associado ao clientes, as Microsoft Foundation classes fornecem as [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md) classe.

Clientes associados estáticos usam uma classe proxy que está vinculada estaticamente com o aplicativo cliente. Essa classe fornece um encapsulamento da C++ fortemente tipada de operações e propriedades do aplicativo de servidor.

A classe `COleDispatchDriver` fornece o suporte principal para o lado do cliente de automação. Usando o **Adicionar Novo Item** caixa de diálogo, você cria uma classe derivada de `COleDispatchDriver`.

Você, em seguida, especifique o arquivo de biblioteca de tipos que descreve as propriedades e funções de objeto do aplicativo de servidor. A caixa de diálogo Adicionar Item lê esse arquivo e cria o `COleDispatchDriver`-derivado da classe, com funções de membro que seu aplicativo pode chamar para acessar objetos do aplicativo de servidor em C++ de uma maneira fortemente tipada. Funcionalidade adicional herdado de `COleDispatchDriver` simplifica o processo de chamada do servidor de automação apropriado.

### <a name="handling-events-in-automation-clients"></a>Manipulação de eventos em clientes de automação

Se você quiser manipular eventos em seu cliente de automação, você precisará adicionar uma interface de coletor. MFC fornece suporte do Assistente para adicionar interfaces de coletor para controles ActiveX, mas não dão suporte para outros servidores COM.

## <a name="see-also"></a>Consulte também

[Clientes de automação: usando bibliotecas de tipo](../mfc/automation-clients-using-type-libraries.md)<br/>
[Automação](../mfc/automation.md)<br/>
[Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md)

