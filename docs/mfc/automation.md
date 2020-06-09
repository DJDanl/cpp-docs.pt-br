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
ms.openlocfilehash: e5790be14f26f59c2b51b339c8bee7c5eca7d692
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616520"
---
# <a name="automation"></a>Automação

A automação (anteriormente conhecida como automação OLE) possibilita que um aplicativo manipule objetos implementados em outro aplicativo ou exponha objetos para que possam ser manipulados.

Um [servidor de automação](automation-servers.md) é um aplicativo (um tipo de servidor com) que expõe sua funcionalidade por meio de interfaces com a outros aplicativos, chamados de [clientes de automação](automation-clients.md). A exposição permite que os clientes de automação automatizem determinadas funções acessando diretamente os objetos e usando os serviços que eles fornecem.

Servidores de automação e clientes usam interfaces COM que são sempre derivadas de `IDispatch` e levam e retornam um conjunto específico de tipos de dados chamados de tipos de automação. Você pode automatizar qualquer objeto que expõe uma interface de automação, fornecendo métodos e propriedades que você pode acessar de outros aplicativos. A automação está disponível para objetos OLE e COM. O objeto automatizado pode ser local ou remoto (em outro computador acessível em uma rede); Portanto, há duas categorias de automação:

- Automação (local).

- Automação remota (em uma rede, usando COM distribuída ou DCOM).

Expor objetos é benéfico quando os aplicativos fornecem funcionalidade útil para outros aplicativos. Por exemplo, um controle ActiveX é um tipo de servidor de automação; o aplicativo que hospeda o controle ActiveX é o cliente de automação desse controle.

Como outro exemplo, um processador de texto pode expor sua funcionalidade de verificação ortográfica para outros programas. A exposição de objetos permite que os fornecedores aprimorem seus aplicativos usando a funcionalidade pronta de outros aplicativos. Dessa forma, a automação aplica alguns dos princípios da programação orientada a objeto, como reutilização e encapsulamento, no nível dos próprios aplicativos.

O mais importante é que a automação de suporte fornece aos usuários e aos provedores de soluções. Ao expor a funcionalidade do aplicativo por meio de uma interface comum e bem definida, a automação possibilita a criação de soluções abrangentes em uma única linguagem de programação geral, como o Microsoft Visual Basic, em vez de diversas linguagens de macro específicas do aplicativo.

Muitos aplicativos comerciais, como o Microsoft Excel e o Microsoft Visual C++, permitem que você automatize grande parte de suas funcionalidades. Por exemplo, no Visual C++, você pode escrever macros do VBScript para automatizar compilações, aspectos de edição de código ou tarefas de depuração.

## <a name="passing-parameters-in-automation"></a><a name="_core_passing_parameters_in_automation"></a>Passando parâmetros na automação

Uma dificuldade na criação de métodos de automação é ajudar a fornecer um mecanismo "seguro" uniforme para passar dados entre servidores de automação e clientes. A automação usa o tipo **Variant** para passar dados. O tipo de **variante** é uma União marcada. Ele tem um membro de dados para o valor (trata-se de uma União de C++ anônima) e um membro de dados que indica o tipo de informações armazenadas na União. O tipo **Variant** oferece suporte a vários tipos de dados padrão: inteiros de 2 e 4 bytes, números de ponto flutuante de 4 e 8 bytes, cadeias de caracteres e valores Boolianos. Além disso, ele dá suporte aos tipos **HRESULT** (códigos de erro OLE), **moeda** (um tipo numérico de ponto fixo) e **Data** (data e hora absoluta), bem como ponteiros para `IUnknown` e `IDispatch` interfaces.

O tipo **Variant** é encapsulado na classe [COleVariant](reference/colevariant-class.md) . A **moeda** de suporte e as classes de **Data** são encapsuladas nas classes [COleCurrency](reference/colecurrency-class.md) e [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) .

## <a name="automation-samples"></a>Amostras de automação

- [AUTOCLIK](../overview/visual-cpp-samples.md) Use este exemplo para aprender técnicas de automação e como uma base para aprender a automação remota.

- [ACDUAL](../overview/visual-cpp-samples.md) Adiciona interfaces duplas a um aplicativo de servidor de automação.

- [CALCDRIV](../overview/visual-cpp-samples.md) Aplicativo cliente de automação que conduz MFCCALC.

- [InProc](../overview/visual-cpp-samples.md) Demonstra um aplicativo de servidor de automação em processo.

- [IPDRIVE](../overview/visual-cpp-samples.md) Aplicativo cliente de automação conduzindo a INPROC.

- [MFCCALC](../overview/visual-cpp-samples.md) Demonstra um aplicativo cliente de automação.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Clientes de automação](automation-clients.md)

- [Servidores de automação](automation-servers.md)

- [OLE](ole-in-mfc.md)

- [Tecnologia ativa](mfc-com.md)

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Adicionar uma classe de automação](automation-servers.md)

- [Usar bibliotecas de tipos](automation-clients-using-type-libraries.md)

- [Servidores de automação de acesso](automation-servers.md)

- [Gravar clientes de automação em C++](automation-clients.md)

## <a name="see-also"></a>Consulte também

[MFC COM](mfc-com.md)
