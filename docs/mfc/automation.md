---
title: "Automação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b0204ab105b48350ea7fe934c28c5d5f95bea71f
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="automation"></a>Automação
Automação (anteriormente conhecida como automação OLE) possibilita que um aplicativo para manipular objetos implementados em outro aplicativo ou para expor os objetos para que eles podem ser manipulados.  
  
 Um [servidor de automação](../mfc/automation-servers.md) é um aplicativo (um tipo de servidor COM) que expõe sua funcionalidade por meio de interfaces COM para outros aplicativos, chamados [clientes de automação](../mfc/automation-clients.md). A exposição permite que os clientes de automação automatizar determinadas funções com acesso a objetos diretamente e usando os serviços que eles fornecem.  
  
 Clientes e servidores de automação usam interfaces COM que sempre são derivados de `IDispatch` levar e retornar um conjunto específico de tipos de dados chamado tipos de automação. Você pode automatizar qualquer objeto que expõe uma interface de automação, fornecendo os métodos e propriedades que você pode acessar de outros aplicativos. Automação está disponível para objetos COM e OLE. O objeto automatizado pode ser local ou remoto (em outro computador acessível pela rede); Portanto, há duas categorias de automação:  
  
-   Automação (local).  
  
-   Automação remota (em uma rede, usando COM distribuída ou DCOM).  
  
 Expondo objetos é benéfico quando os aplicativos fornecem funcionalidade útil para outros aplicativos. Por exemplo, um controle ActiveX é um tipo do servidor de automação. o aplicativo que hospeda o controle ActiveX é o cliente de automação do controle.  
  
 Como outro exemplo, um processador de texto pode expor sua funcionalidade de verificação ortográfica para outros programas. Exposição de objetos permite que fornecedores melhorar seus aplicativos usando a funcionalidade pronta de outros aplicativos. Dessa forma, automação aplica-se alguns dos princípios de programação orientada a objeto, como a capacidade de reutilização e encapsulamento, no nível dos próprios aplicativos.  
  
 Mais importante é o suporte de que automação fornece aos usuários e provedores de soluções. Expondo a funcionalidade do aplicativo por meio de uma interface comum e bem definida, automação torna possível criar soluções abrangentes em uma único geral linguagem de programação, como o Microsoft Visual Basic, em vez de usar diversas idiomas de macro específicas do aplicativo.  
  
 Muitos aplicativos comerciais, como Microsoft Excel e o Microsoft Visual C++ permitem automatizar grande parte de sua funcionalidade. Por exemplo, no Visual C++, você pode escrever macros de VBScript para automatizar compilações, aspectos do código de edição ou tarefas de depuração.  
  
##  <a name="_core_passing_parameters_in_automation"></a> Passando parâmetros de automação  
 Uma dificuldade durante a criação de métodos de automação está ajudando a fornecem um mecanismo de "seguro" uniforme para passar dados entre clientes e servidores de automação. Automação usa o **VARIANT** tipo para passar dados. O **VARIANT** tipo é uma união marcada. Ele tem um membro de dados para o valor (Esta é uma união anônima do C++) e um membro de dados que indica o tipo de informações armazenadas na União. O **VARIANT** tipo oferece suporte a vários tipos de dados padrão: inteiros de 2 e 4 bytes e valores booleanos, cadeias de caracteres e números de ponto flutuante de 4 e 8 bytes. Além disso, ele dá suporte a `HRESULT` (códigos de erro OLE), **moeda** (um ponto fixo tipo numérico), e **data** tipos (absoluta data e hora), bem como ponteiros para **IUnknown**  e `IDispatch` interfaces.  
  
 O **VARIANT** tipo é encapsulado no [COleVariant](../mfc/reference/colevariant-class.md) classe. O suporte **moeda** e **data** encapsuladas em classes de [COleCurrency](../mfc/reference/colecurrency-class.md) e [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) classes.  
  
## <a name="automation-samples"></a>Exemplos de automação  
  
-   [AUTOCLIK](../visual-cpp-samples.md) Use este exemplo para obter informações técnicas de automação e como uma base para aprender a automação remota.  
  
-   [ACDUAL](../visual-cpp-samples.md) adiciona interfaces duplas para um aplicativo de servidor de automação.  
  
-   [CALCDRIV](../visual-cpp-samples.md) aplicativo de cliente de automação orientando MFCCALC.  
  
-   [INPROC](../visual-cpp-samples.md) demonstra um aplicativo de servidor de automação em andamento.  
  
-   [IPDRIVE](../visual-cpp-samples.md) aplicativo de cliente de automação orientando INPROC.  
  
-   [MFCCALC](../visual-cpp-samples.md) demonstra um aplicativo de cliente de automação.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Clientes de automação](../mfc/automation-clients.md)  
  
-   [Servidores de automação](../mfc/automation-servers.md)  
  
-   [OLE](../mfc/ole-in-mfc.md)  
  
-   [Tecnologia ativa](../mfc/mfc-com.md)  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer  
  
-   [Adicionar uma classe de automação](../mfc/automation-servers.md)  
  
-   [Usar bibliotecas de tipo](../mfc/automation-clients-using-type-libraries.md)  
   
-   [Servidores de automação de acesso](../mfc/automation-servers.md)  
  
-   [Gravar clientes de automação em C++](../mfc/automation-clients.md)  
  
## <a name="see-also"></a>Consulte também  
 [MFC COM](../mfc/mfc-com.md)
