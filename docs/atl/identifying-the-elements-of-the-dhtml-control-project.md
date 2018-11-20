---
title: Identificando os elementos do projeto de controle DHTML
ms.date: 11/19/2018
helpviewer_keywords:
- HTML controls, ATL support
- DHTML controls, ATL support
ms.assetid: b627547a-3768-4346-9900-4b7a21fb8e27
ms.openlocfilehash: e38b94e200754ce9dd37df2bfb17dfaa32cafe49
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175698"
---
# <a name="identifying-the-elements-of-the-dhtml-control-project"></a>Identificando os elementos do projeto de controle DHTML

A maioria dos códigos de controle DHTML exatamente como esse é criada para qualquer controle do ATL. Para obter uma compreensão básica do código genérico, trabalhar com o [tutorial da ATL](../atl/active-template-library-atl-tutorial.md), e leia as seções [criando um projeto ATL](../atl/reference/creating-an-atl-project.md) e [conceitos básicos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md).

Um controle DHTML é semelhante a qualquer controle da ATL, exceto:

- Além das interfaces regulares que implementa um controle, ele implementa uma interface adicional que é usada para comunicação entre o código C++ e a interface do usuário HTML (UI). A interface do usuário HTML chama código C++ usando esta interface.

- Ele cria um recurso HTML para o controle da interface do usuário.

- Ele permite o acesso ao modelo de objeto DHTML por meio da variável de membro `m_spBrowser`, que é um ponteiro inteligente do tipo [IWebBrowser2](https://msdn.microsoft.com/library/aa752127.aspx). Use esse ponteiro para acessar qualquer parte do modelo de objeto DHTML.

O gráfico a seguir ilustra o relacionamento entre sua DLL, o controle DHTML, o navegador da Web e o recurso HTML.

![Elementos de um projeto de controle DHTML](../atl/media/vc52en1.gif "elementos de um projeto de controle DHTML")

> [!NOTE]
>  Os nomes nesse gráfico são espaços reservados. Os nomes de seus recursos HTML e as interfaces expostas no seu controle baseiam-se nos nomes de que atribuí-los no Assistente de controle de ATL.

Neste gráfico, os elementos são:

- **Minha DLL** criadas usando o Assistente de projeto de ATL DLL.

- **Controle DHTML** (`m_spBrowser`) controle o DHTML, criado usando o Assistente de objeto ATL. Esse controle acessa o objeto de navegador da Web e seus métodos por meio da interface do objeto de navegador da Web, `IWebBrowser2`. O próprio controle expõe duas interfaces a seguir, além de outras interfaces padrão necessárias para um controle.

   - `IDHCTL1` A interface exposta pelo controle para uso somente pelo contêiner.

   - `IDHCTLUI1` A interface de expedição para comunicação entre o código C++ e a interface do usuário HTML. O navegador da Web usa a interface de expedição do controle para exibir o controle. Você pode chamar vários métodos dessa interface de expedição de interface do usuário do controle invocando `window.external`, seguido pelo nome do método nesta interface de expedição que você deseja invocar. Você acessaria `window.external` de uma marca SCRIPT dentro do HTML que compõe a interface do usuário para este controle. Para obter mais informações sobre como invocar métodos externos no arquivo de recurso, consulte [chamar o código de C++ do DHTML](../atl/calling-cpp-code-from-dhtml.md).

- **IDR_CTL1** a ID de recurso do recurso em HTML. Seu nome de arquivo, nesse caso, é DHCTL1UI.htm. O controle DHTML usa um recurso HTML que contém marcas HTML padrão e comandos de expedição de janela externa que você pode editar usando o editor de texto.

- **Navegador da Web** navegador da Web exibe da interface do usuário do controle, com base em HTML no recurso de HTML. Um ponteiro para o navegador da Web `IWebBrowser2` interface está disponível no controle DHTML para permitir o acesso ao modelo de objeto DHTML.

O Assistente de controle do ATL gera um controle com o código padrão no recurso em HTML e o arquivo. cpp. Você pode compilar e executar o controle como gerada pelo assistente e, em seguida, o controle de exibição no navegador da Web ou o contêiner de teste do controle ActiveX. A figura abaixo mostra o padrão controle DHTML da ATL com três botões exibidos no contêiner de teste:

![Controle DHTML da ATL](../atl/media/vc52en2.gif "controle DHTML da ATL")

Ver [criando um controle de DHTML da ATL](../atl/creating-an-atl-dhtml-control.md) para começar a criação de um controle DHTML. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

## <a name="see-also"></a>Consulte também

[Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)

