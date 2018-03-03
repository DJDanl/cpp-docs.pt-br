---
title: "Identificação dos elementos do projeto de controle DHTML | Microsoft Docs"
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
- HTML controls, ATL support
- DHTML controls, ATL support
ms.assetid: b627547a-3768-4346-9900-4b7a21fb8e27
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 74b271f56fe7c8d3345ce53de06a18a2700175f2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="identifying-the-elements-of-the-dhtml-control-project"></a>Identificação dos elementos do projeto de controle DHTML
A maioria dos códigos de controle DHTML exatamente como esse é criado para qualquer controle ATL. Para obter uma compreensão básica do código genérico, leia o [tutorial da ATL](../atl/active-template-library-atl-tutorial.md), e leia as seções [criando um projeto de ATL](../atl/reference/creating-an-atl-project.md) e [Fundamentals de ATL COM objetos](../atl/fundamentals-of-atl-com-objects.md).  
  
 Um controle DHTML é semelhante a qualquer controle ATL, exceto:  
  
-   Além das interfaces normais de que implementa um controle, ele implementa uma interface adicional que é usada para comunicação entre o código C++ e a interface do usuário HTML (IU). A interface do usuário HTML chama o código C++ usando esta interface.  
  
-   Ele cria um recurso HTML para o controle de interface do usuário.  
  
-   Permitir acesso ao modelo de objeto DHTML através da variável de membro `m_spBrowser`, que é um ponteiro inteligente do tipo [IWebBrowser2](https://msdn.microsoft.com/library/aa752127.aspx). Use este ponteiro para acessar qualquer parte do modelo de objeto DHTML.  
  
 O gráfico a seguir ilustra o relacionamento entre sua DLL, o controle DHTML, o navegador da Web e o recurso HTML.  
  
 ![Elementos de um projeto de controle DHTML](../atl/media/vc52en1.gif "vc52en1")  
  
> [!NOTE]
>  Os nomes nesse gráfico são espaços reservados. Os nomes de recurso HTML e as interfaces expostas no seu controle baseiam-se nos nomes de que atribuí-los no Assistente de controle ATL.  
  
 Neste gráfico, os elementos são:  
  
-   **Minha DLL** criado usando o Assistente de projeto de ATL DLL.  
  
-   **Controle DHTML** (`m_spBrowser`) controle DHTML o, criado usando o Assistente de objeto ATL. Esse controle acessa o objeto de navegador da Web e seus métodos por meio da interface do objeto de navegador da Web, **IWebBrowser2**. O próprio controle expõe duas interfaces a seguir, além de outra interfaces padrão necessário para um controle.  
  
    -   **IDHCTL1** a interface exposta pelo controle para uso somente pelo contêiner.  
  
    -   **IDHCTLUI1** a interface de distribuição para comunicação entre o código C++ e a interface do usuário HTML. O navegador da Web usa a interface de Despache do controle para exibir o controle. Você pode chamar vários métodos desta interface de expedição da interface de usuário do controle invocando `window.external`, seguido pelo nome do método nesta interface de distribuição que você deseja invocar. Você acessaria `window.external` de uma marca SCRIPT em HTML que compõe a interface do usuário para este controle. Para obter mais informações sobre como invocar métodos externos no arquivo de recurso, consulte [chamar o código C++ de DHTML](../atl/calling-cpp-code-from-dhtml.md).  
  
-   **IDR_CTL1** a ID de recurso do recurso em HTML. Seu nome de arquivo, nesse caso, é DHCTL1UI.htm. O controle DHTML usa um recurso HTML que contém comandos de expedição de janela externa que você pode editar usando o editor de texto e marcas HTML padrão.  
  
-   **Navegador da Web** o navegador exibe interface do usuário do controle, com base em HTML no recurso HTML. Um ponteiro para o navegador **IWebBrowser2** interface está disponível no controle DHTML para permitir o acesso ao modelo de objeto DHTML.  
  
 O Assistente de controle ATL gera um controle com o código padrão no recurso em HTML e o arquivo. cpp. Você pode compilar e executar o controle como gerada pelo assistente e, em seguida, exibir o controle no navegador da Web ou o contêiner de teste do controle ActiveX. A figura abaixo mostra o padrão controle DHTML ATL com três botões exibidos no contêiner de teste:  
  
 ![Controle DHTML ATL](../atl/media/vc52en2.gif "vc52en2")  
  
 Consulte [criando um controle de DHTML ATL](../atl/creating-an-atl-dhtml-control.md) para começar a criação de um controle DHTML. Consulte [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)

