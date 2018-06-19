---
title: Chamar o código C++ de DHTML | Microsoft Docs
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
ms.openlocfilehash: f9e369396c68a041dc5fe027802859c6071e50e8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32355455"
---
# <a name="calling-c-code-from-dhtml"></a>Chamando código C++ de DHTML
Um controle DHTML pode ser hospedado em um contêiner, como o contêiner de teste ou o Internet Explorer. Consulte [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
 O contêiner que hospeda o controle se comunica com o controle usando as interfaces de controle normal. DHTML usa a interface de despacho que termina com "UI" para se comunicar com o código do C++ e o recurso HTML. Em [modificando o controle DHTML ATL](../atl/modifying-the-atl-dhtml-control.md), você pode praticar a adição de métodos para ser chamado por essas interfaces diferentes.  
  
 Para ver um exemplo de chamar o código C++ de DHTML, [criar um controle DHTML](../atl/creating-an-atl-dhtml-control.md) usando o Assistente de controle ATL e examine o código no arquivo de cabeçalho e no arquivo HTML.  
  
## <a name="declaring-webbrowser-methods-in-the-header-file"></a>Declarando métodos WebBrowser no arquivo de cabeçalho  
 Para invocar métodos de C++ de UI do DHTML, você deve adicionar métodos de interface de interface do usuário do controle. Por exemplo, o arquivo de cabeçalho criado pelo Assistente de controle ATL contém o método do C++ `OnClick`, que é um membro da interface da interface do usuário do controle geradas pelo assistente.  
  
 Examine `OnClick` no arquivo do controle. h:  
  
 [!code-cpp[NVC_ATL_COM#4](../atl/codesnippet/cpp/calling-cpp-code-from-dhtml_1.h)]  
  
 O primeiro parâmetro, `pdispBody`, é um ponteiro para a interface de Despache do objeto do corpo. O segundo parâmetro, `varColor`, identifica a cor a ser aplicada ao controle.  
  
## <a name="calling-c-code-in-the-html-file"></a>Chamando código C++ no arquivo HTML  
 Depois de ter declarado os métodos de WebBrowser no arquivo de cabeçalho, você pode chamar os métodos do arquivo HTML. Aviso no arquivo HTML que o Assistente de controle ATL insere três métodos de distribuição do Windows: três `OnClick` métodos que enviar mensagens para alterar a cor de plano de fundo do controle.  
  
 Examine um dos métodos no arquivo HTML:  
  
 `<BUTTON onclick='window.external.OnClick(theBody, "red");'>Red</BUTTON>`  
  
 No código HTML acima, o método externo de janela, `OnClick`, é chamado como parte da marca do botão. O método tem dois parâmetros: `theBody`, que referencia o corpo do documento HTML, e `"red"`, que indica qual cor de plano de fundo do controle será alterado para vermelho quando o botão é clicado. O `Red` após a marca é o rótulo do botão.  
  
 Consulte [modificando o controle DHTML ATL](../atl/modifying-the-atl-dhtml-control.md) para obter mais informações sobre como fornecer seus próprios métodos. Consulte [identificação dos elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md) para obter mais informações sobre o arquivo HTML.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)

