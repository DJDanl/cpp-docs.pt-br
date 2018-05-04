---
title: Suporte ATL para controles DHTML | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- HTML controls, ATL support
- DHTML controls, ATL support
- DHTML controls
ms.assetid: 4ba98098-da5d-4362-96ad-8372f816c307
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f57fc841ba2eb3473ccb866df7333ebd24583d40
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="atl-support-for-dhtml-controls"></a>Suporte do ATL para controles DHTML
Usando a ATL, você pode criar um controle com a funcionalidade de DHTML (HTML dinâmico). Um controle DHTML ATL:  
  
-   Hospede o controle WebBrowser.  
  
-   Especifica o uso de HTML, a interface do usuário (IU) do controle DHTML.  
  
-   Acessa o objeto de WebBrowser e seus métodos por meio de sua interface [IWebBrowser2](https://msdn.microsoft.com/library/aa752127.aspx).  
  
-   Gerencia a comunicação entre o código C++ e HTML.  
  
 Um controle DHTML é semelhante a qualquer outro controle ATL, exceto o controle DHTML inclui uma interface de expedição adicionais. Consulte a figura em [identificação dos elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md) para obter uma ilustração das interfaces fornecido no projeto de DHTML padrão.  
  
 Você pode exibir o controle DHTML ATL em um navegador da Web ou outro contêiner, como o contêiner de teste do controle ActiveX.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Identificando os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md)  
 Descreve os elementos de um projeto de controle DHTML.  
  
 [Chamando código C++ do DHTML](../atl/calling-cpp-code-from-dhtml.md)  
 Fornece um exemplo de código C++ de chamada de um controle DHTML.  
  
 [Criando um controle DHTML da ATL](../atl/creating-an-atl-dhtml-control.md)  
 Lista as etapas para criar um controle DHTML.  
  
 [Testando o controle DHTML da ATL](../atl/testing-the-atl-dhtml-control.md)  
 Mostra como criar e testar o projeto de controle DHTML inicial.  
  
 [Modificando o controle DHTML da ATL](../atl/modifying-the-atl-dhtml-control.md)  
 Mostra como adicionar algumas funcionalidades para o controle.  
  
 [Testando o controle DHTML alterado do ATL](../atl/testing-the-modified-atl-dhtml-control.md)  
 Mostra como criar e testar a funcionalidade do controle adicionado.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

