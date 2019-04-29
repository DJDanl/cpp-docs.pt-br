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
ms.openlocfilehash: 7818aa708a762f2a284be029a6c3f3facd971d9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374149"
---
# <a name="automation"></a>Automação

Automação (anteriormente conhecida como automação OLE) torna possível para um aplicativo para manipular objetos implementados em outro aplicativo ou para expor objetos para que eles podem ser manipulados.

Uma [servidor de automação](../mfc/automation-servers.md) é um aplicativo (um tipo de servidor COM) que expõe sua funcionalidade por meio de interfaces COM para outros aplicativos, chamados [clientes de automação](../mfc/automation-clients.md). A exposição permite que os clientes de automação automatizar determinadas funções diretamente acessando objetos e usando os serviços que eles fornecem.

Os clientes e servidores de automação usam interfaces COM que sempre são derivados de `IDispatch` e usam e retornam um conjunto específico de tipos de dados, chamados de tipos de automação. Você pode automatizar qualquer objeto que expõe uma interface de automação, fornecendo métodos e propriedades que você pode acessar de outros aplicativos. Automação está disponível para objetos OLE e COM. O objeto automatizado pode ser local ou remoto (em outro computador acessível em uma rede); Portanto, há duas categorias de automação:

- Automação (local).

- Automação remota (em uma rede, usando COM distribuída ou DCOM).

Expondo objetos é útil quando os aplicativos fornecem funcionalidade útil para outros aplicativos. Por exemplo, um controle ActiveX é um tipo do servidor de automação. o aplicativo que hospeda o controle ActiveX é o cliente de automação desse controle.

Como outro exemplo, um processador de texto pode expor sua funcionalidade de verificação ortográfica para outros programas. Exposição de objetos permite que os fornecedores aprimorar seus aplicativos usando a funcionalidade prontas para uso de outros aplicativos. Dessa forma, a automação se aplica alguns dos princípios da programação orientada a objeto, como capacidade de reutilização e encapsulamento, no nível de aplicativos em si.

Mais importante é o suporte de que automação fornece aos usuários e provedores de soluções. Expondo a funcionalidade do aplicativo por meio de uma interface comum e bem definida, automação torna possível criar soluções abrangentes em uma única geral linguagem de programação, como o Microsoft Visual Basic, em vez de usar diversas linguagens de macro específica do aplicativo.

Muitos aplicativos comerciais, como o Microsoft Excel e Microsoft Visual C++, permitem automatizar grande parte de sua funcionalidade. Por exemplo, no Visual C++, você pode gravar macros de VBScript para automatizar compilações, aspectos do código de edição ou tarefas de depuração.

##  <a name="_core_passing_parameters_in_automation"></a> Passando parâmetros na automação

Uma dificuldade na criação de métodos de automação está ajudando a fornecer um mecanismo uniforme "seguro" para passar dados entre clientes e servidores de automação. Automação usa o **VARIANT** tipo para passar dados. O **VARIANT** tipo é uma união com marcas de formatação. Ele tem um membro de dados para o valor (essa é uma união anônima do C++) e um membro de dados que indica o tipo de informações armazenadas na União. O **VARIANT** tipo dá suporte a vários tipos de dados padrão: inteiros de 2 e 4 bytes, números de ponto flutuante de 4 e 8 bytes, cadeias de caracteres e valores boolianos. Além disso, ele dá suporte a **HRESULT** (códigos de erro OLE), **moeda** (um ponto fixo tipo numérico), e **data** tipos (data e hora absolutas), bem como ponteiros para `IUnknown` e `IDispatch` interfaces.

O **VARIANT** tipo é encapsulado na [COleVariant](../mfc/reference/colevariant-class.md) classe. O suporte a **moeda** e **data** classes são encapsuladas no [COleCurrency](../mfc/reference/colecurrency-class.md) e [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) classes.

## <a name="automation-samples"></a>Exemplos de automação

- [AUTOCLIK](../overview/visual-cpp-samples.md) usar esse exemplo para aprender técnicas de automação e como uma base para a automação remota de aprendizado.

- [ACDUAL](../overview/visual-cpp-samples.md) adiciona interfaces dual a um aplicativo de servidor de automação.

- [CALCDRIV](../overview/visual-cpp-samples.md) orientando MFCCALC aplicativo cliente da automação.

- [INPROC](../overview/visual-cpp-samples.md) demonstra um aplicativo de servidor em processo de automação.

- [IPDRIVE](../overview/visual-cpp-samples.md) aplicativo de cliente de automação, orientando INPROC.

- [MFCCALC](../overview/visual-cpp-samples.md) demonstra um aplicativo de cliente de automação.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Clientes de automação](../mfc/automation-clients.md)

- [Servidores de automação](../mfc/automation-servers.md)

- [OLE](../mfc/ole-in-mfc.md)

- [Tecnologia ativa](../mfc/mfc-com.md)

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Adicione uma classe de automação](../mfc/automation-servers.md)

- [Usar bibliotecas de tipos](../mfc/automation-clients-using-type-libraries.md)

- [Servidores de automação de acesso](../mfc/automation-servers.md)

- [Clientes de automação de gravação em C++](../mfc/automation-clients.md)

## <a name="see-also"></a>Consulte também

[MFC COM](../mfc/mfc-com.md)
