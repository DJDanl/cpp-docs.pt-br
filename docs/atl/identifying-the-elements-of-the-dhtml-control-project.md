---
title: Identificando os elementos do Projeto de Controle DHTML
ms.date: 11/19/2018
helpviewer_keywords:
- HTML controls, ATL support
- DHTML controls, ATL support
ms.assetid: b627547a-3768-4346-9900-4b7a21fb8e27
ms.openlocfilehash: 5fabdc815989c21bdf6b0932b9d6826e28d7012a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319502"
---
# <a name="identifying-the-elements-of-the-dhtml-control-project"></a>Identificando os elementos do Projeto de Controle DHTML

A maioria do código de controle DHTML é exatamente como o criado para qualquer controle ATL. Para uma compreensão básica do código genérico, trabalhe através do [tutorial ATL](../atl/active-template-library-atl-tutorial.md)e leia as seções [Criando um Projeto ATL](../atl/reference/creating-an-atl-project.md) e [Fundamentos de Objetos ATL COM](../atl/fundamentals-of-atl-com-objects.md).

Um controle DHTML é semelhante a qualquer controle ATL, exceto:

- Além das interfaces regulares que um controle implementa, ele implementa uma interface adicional que é usada para se comunicar entre o código C++ e a interface de usuário HTML (UI). A interface do usuário HTML chama para o código C++ usando esta interface.

- Ele cria um recurso HTML para a ui de controle.

- Ele permite o acesso ao modelo de `m_spBrowser`objeto DHTML através da variável member , que é um ponteiro inteligente do tipo [IWebBrowser2](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752127\(v=vs.85\)). Use este ponteiro para acessar qualquer parte do modelo de objeto DHTML.

O gráfico a seguir ilustra a relação entre seu DLL, o controle DHTML, o navegador da Web e o recurso HTML.

![Elementos de um projeto de controle DHTML](../atl/media/vc52en1.gif "Elementos de um projeto de controle DHTML")

> [!NOTE]
> Os nomes neste gráfico são espaços reservados. Os nomes do seu recurso HTML e as interfaces expostas no seu controle são baseados nos nomes que você atribui-los no Assistente de Controle ATL.

Neste gráfico, os elementos são:

- **Minha DLL** A DLL foi criada usando o Assistente de Projeto ATL.

- **Controle DHTML** (`m_spBrowser`) O controle DHTML, criado usando o Assistente de Objeto ATL. Este controle acessa o objeto do navegador da Web e `IWebBrowser2`seus métodos através da interface do objeto do navegador da Web, . O próprio controle expõe as duas interfaces a seguir, além das outras interfaces padrão necessárias para um controle.

  - `IDHCTL1`A interface exposta pelo controle para uso apenas pelo recipiente.

  - `IDHCTLUI1`A interface de despacho para comunicação entre o código C++ e a interface de usuário HTML. O navegador da Web usa a interface de despacho do controle para exibir o controle. Você pode chamar vários métodos desta interface de despacho a `window.external`partir da interface de usuário do controle invocando, seguido pelo nome do método nesta interface de despacho que você deseja invocar. Você acessaria `window.external` a partir de uma tag SCRIPT dentro do HTML que compõe a ui para este controle. Para obter mais informações sobre como invocar métodos externos no arquivo de recursos, consulte [Chamar código C++ do DHTML](../atl/calling-cpp-code-from-dhtml.md).

- **IDR_CTL1** O ID de recurso do recurso HTML. Seu nome de arquivo, neste caso, é DHCTL1UI.htm. O controle DHTML usa um recurso HTML que contém tags HTML padrão e comandos de despacho de janela externa que você pode editar usando o editor de texto.

- **Navegador da Web** O navegador da Web exibe a interface do usuário do controle, com base no HTML no recurso HTML. Um ponteiro para a `IWebBrowser2` interface do navegador da Web está disponível no controle DHTML para permitir o acesso ao modelo de objeto DHTML.

O Assistente de Controle ATL gera um controle com código padrão tanto no recurso HTML quanto no arquivo .cpp. Você pode compilar e executar o controle conforme gerado pelo assistente e, em seguida, exibir o controle no navegador da Web ou no ActiveX Control Test Container. A imagem abaixo mostra o controle ATL DHTML padrão com três botões exibidos no Recipiente de Teste:

![Controle ATL DHTML](../atl/media/vc52en2.gif "Controle ATL DHTML")

Consulte [Criando um controle ATL DHTML](../atl/creating-an-atl-dhtml-control.md) para começar a construir um controle DHTML. Consulte [Propriedades de teste e eventos com o contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

## <a name="see-also"></a>Confira também

[Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)
