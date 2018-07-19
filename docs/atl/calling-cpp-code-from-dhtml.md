---
title: Chamando código de C++ do DHTML | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DHTML, calling C++ code from
ms.assetid: 37329acd-4c22-40ca-a85a-b7480748f75f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f24c7c1e3cd6cd1b24d74fcc1eee3209562a138a
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37848958"
---
# <a name="calling-c-code-from-dhtml"></a>Chamando código C++ do DHTML
Um controle DHTML pode ser hospedado em um contêiner, como o contêiner de teste ou o Internet Explorer. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
 O contêiner hospedando o controle se comunica com o controle usando as interfaces de controle normal. DHTML usa a interface de expedição que termina com "Interface do usuário" para se comunicar com seus recursos HTML e seu código C++. Na [modificando o controle DHTML da ATL](../atl/modifying-the-atl-dhtml-control.md), você pode praticar adicionando os métodos sejam chamados por essas interfaces diferentes.  
  
 Para ver um exemplo de chamada de código C++ do DHTML, [criar um controle DHTML](../atl/creating-an-atl-dhtml-control.md) usando o Assistente de controle ATL e examine o código no arquivo de cabeçalho e no arquivo HTML.  
  
## <a name="declaring-webbrowser-methods-in-the-header-file"></a>Declarar métodos WebBrowser no arquivo de cabeçalho  
 Para invocar métodos de C++ da UI do DHTML, você deve adicionar métodos a interface de interface do usuário do seu controle. Por exemplo, o arquivo de cabeçalho criado pelo Assistente de controle do ATL contém o método do C++ `OnClick`, que é um membro da interface da interface do usuário do controle gerado pelo assistente.  
  
 Examinar `OnClick` no arquivo. h do controle:  
  
 [!code-cpp[NVC_ATL_COM#4](../atl/codesnippet/cpp/calling-cpp-code-from-dhtml_1.h)]  
  
 O primeiro parâmetro, *pdispBody*, é um ponteiro para a interface de expedição do objeto do corpo. O segundo parâmetro, *varColor*, identifica a cor a ser aplicada ao controle.  
  
## <a name="calling-c-code-in-the-html-file"></a>Chamando código C++ no arquivo HTML  
 Depois que você declarar os métodos WebBrowser no arquivo de cabeçalho, você pode chamar os métodos do arquivo HTML. Observe que no arquivo HTML que o Assistente de controle do ATL insere três métodos de expedição do Windows: três `OnClick` métodos que enviam mensagens para alterar a cor do plano de fundo do controle.  
  
 Examine um dos métodos no arquivo HTML:  
  
 `<BUTTON onclick='window.external.OnClick(theBody, "red");'>Red</BUTTON>`  
  
 No código HTML acima, o método externo de janela, `OnClick`, é chamado como parte da marca do botão. O método tem dois parâmetros: `theBody`, que faz referência ao corpo do documento HTML, e `"red"`, que indica que cor do plano de fundo do controle será alterado para vermelho quando o botão é clicado. O `Red` seguindo a marca é o rótulo do botão.  
  
 Ver [modificando o controle DHTML da ATL](../atl/modifying-the-atl-dhtml-control.md) para obter mais informações sobre como fornecer seus próprios métodos. Ver [identificando os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md) para obter mais informações sobre o arquivo HTML.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)

