---
title: Automação
ms.date: 11/04/2016
helpviewer_keywords:
- Automation servers, about Automation servers
- clients, Automation
- programmatic control [MFC]
- properties [MFC], Automation
- MFC, COM support
- OLE Automation
- Automation
- servers [MFC], Automation
- Automation clients
- sample applications [MFC], Automation
- methods [MFC]
- passing parameters, Automation
- Automation method [MFC]
- Automation, passing parameters
- Automation property [MFC]
- MFC COM, Automation
- methods [MFC], Automation
ms.assetid: 329117f0-c1aa-4680-a901-bfb71277dfba
ms.openlocfilehash: e9320ccf7a21c6110c51366fa8af96596512a4a7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370818"
---
# <a name="automation"></a>Automação

A automação (anteriormente conhecida como Automação OLE) permite que um aplicativo manipule objetos implementados em outro aplicativo ou exponha objetos para que possam ser manipulados.

Um [servidor de automação](../mfc/automation-servers.md) é um aplicativo (um tipo de servidor COM) que expõe sua funcionalidade através de interfaces COM para outros aplicativos, chamados [clientes de Automação](../mfc/automation-clients.md). A exposição permite que os clientes de Automação automatizem determinadas funções acessando diretamente objetos e usando os serviços que fornecem.

Servidores de automação e clientes usam interfaces `IDispatch` COM que são sempre derivadas e pegam e retornam um conjunto específico de tipos de dados chamados tipos de automação. Você pode automatizar qualquer objeto que exponha uma interface de Automação, fornecendo métodos e propriedades que você pode acessar de outros aplicativos. A automação está disponível para objetos OLE e COM. O objeto automatizado pode ser local ou remoto (em outra máquina acessível em uma rede); portanto, existem duas categorias de automação:

- Automação (local).

- Automação remota (em uma rede, usando COM distribuído ou DCOM).

Expor objetos é benéfico quando os aplicativos fornecem funcionalidade útil a outros aplicativos. Por exemplo, um controle ActiveX é um tipo de servidor de automação; o aplicativo que hospeda o controle ActiveX é o cliente de automação desse controle.

Como outro exemplo, um processador de texto pode expor sua funcionalidade de verificação ortodial a outros programas. A exposição de objetos permite que os fornecedores melhorem seus aplicativos usando a funcionalidade pronta de outros aplicativos. Dessa forma, a Automação aplica alguns dos princípios da programação orientada a objetos, como reutilização e encapsulamento, ao nível das próprias aplicações.

Mais importante é o suporte que a Automação fornece aos usuários e provedores de soluções. Ao expor a funcionalidade do aplicativo através de uma interface comum e bem definida, a Automação permite criar soluções abrangentes em uma única linguagem de programação geral, como o Microsoft Visual Basic, em vez de em diversas linguagens macro específicas de aplicativos.

Muitos aplicativos comerciais, como o Microsoft Excel e o Microsoft Visual C++, permitem automatizar grande parte de suas funcionalidades. Por exemplo, no Visual C++, você pode escrever macros VBScript para automatizar compilações, aspectos da edição de código ou depuração de tarefas.

## <a name="passing-parameters-in-automation"></a><a name="_core_passing_parameters_in_automation"></a>Passando parâmetros na automação

Uma dificuldade na criação de métodos de automação está ajudando a fornecer um mecanismo "seguro" uniforme para passar dados entre servidores de automação e clientes. A automação usa o tipo **VARIANT** para passar dados. O tipo **VARIANT** é uma união marcada. Ele tem um membro de dados para o valor (este é um sindicato C++ anônimo) e um membro de dados indicando o tipo de informação armazenada no sindicato. O tipo **VARIANT** suporta uma série de tipos de dados padrão: inteiros de 2 e 4 bytes, números de ponto flutuante de 4 e 8 bytes, strings e valores booleanos. Além disso, ele suporta os tipos **HRESULT** (códigos de erro OLE), **CURRENCY** (um tipo numérico de ponto `IUnknown` `IDispatch` fixo) e **DATE** (data e hora absolutas), bem como ponteiros e interfaces.

O tipo **VARIANT** é encapsulado na classe [COleVariant.](../mfc/reference/colevariant-class.md) As classes **DE MOEDA** e **DATE** de suporte estão encapsuladas nas classes [COleCurrency](../mfc/reference/colecurrency-class.md) e [COleDateTime.](../atl-mfc-shared/reference/coledatetime-class.md)

## <a name="automation-samples"></a>Amostras de automação

- [AUTOCLIK](../overview/visual-cpp-samples.md) Use esta amostra para aprender técnicas de automação e como base para aprender automação remota.

- [ACDUAL](../overview/visual-cpp-samples.md) Adiciona interfaces duplas a um aplicativo de servidor de automação.

- [CALCDRIV](../overview/visual-cpp-samples.md) Aplicativo cliente de automação que conduz o MFCCALC.

- [INPROC](../overview/visual-cpp-samples.md) Demonstra um aplicativo de servidor de automação em processo.

- [IPDRIVE](../overview/visual-cpp-samples.md) Automação de aplicativos clientes que conduzem o INPROC.

- [MFCCALC](../overview/visual-cpp-samples.md) Demonstra um aplicativo cliente de Automação.

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Clientes de automação](../mfc/automation-clients.md)

- [Servidores de automação](../mfc/automation-servers.md)

- [OLE](../mfc/ole-in-mfc.md)

- [Tecnologia ativa](../mfc/mfc-com.md)

## <a name="what-do-you-want-to-do"></a>O que você quer fazer?

- [Adicionar uma classe de automação](../mfc/automation-servers.md)

- [Use bibliotecas de tipo](../mfc/automation-clients-using-type-libraries.md)

- [Servidores de automação de acesso](../mfc/automation-servers.md)

- [Escrever clientes de automação em C++](../mfc/automation-clients.md)

## <a name="see-also"></a>Confira também

[MFC COM](../mfc/mfc-com.md)
