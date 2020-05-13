---
title: 'TN024: mensagens e recursos definidos pelo MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- resources [MFC]
- Windows messages [MFC], MFC-defined
- messages [MFC], MFC
- TN024
ms.assetid: c65353ce-8096-454b-ad22-1a7a1dd9a788
ms.openlocfilehash: 24bcacd46b839babe9c9c89facb1cc56d18c0ee5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370359"
---
# <a name="tn024-mfc-defined-messages-and-resources"></a>TN024: mensagens e recursos definidos pelo MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve as mensagens internas do Windows e os formatos de recursos usados pelo MFC. Essas informações explicam a implementação do framework e o ajudarão a depurar seu aplicativo. Para os aventureiros, mesmo que todas essas informações não tenham suporte oficial, você pode usar algumas dessas informações para implementações avançadas.

Esta nota contém detalhes de implementação privada do MFC; todos os conteúdos estão sujeitos a alterações no futuro. As mensagens privadas do Windows mfc têm significado no escopo de apenas um aplicativo, mas mudarão no futuro para conter mensagens em todo o sistema.

The range of MFC private Windows messages and resource types are in the reserved "system" range set aside by Microsoft Windows. Atualmente, nem todos os números nas faixas são usados e, no futuro, novos números na faixa podem ser usados. Os números usados atualmente podem ser alterados.

As mensagens privadas do Windows MFC estão no intervalo 0x360->0x37F.

Os tipos de recursos privados MFC estão na faixa 0xF0->0xFF.

**Mensagens privadas do Windows Do MFC**

Essas mensagens do Windows são usadas no lugar de funções virtuais C++, onde é necessário um acoplamento relativamente solto entre objetos de janela e onde uma função virtual C++ não seria apropriada.

Essas mensagens privadas do Windows e estruturas de parâmetros associados são declaradas no cabeçalho privado MFC 'AFXPRIV. H'. Esteja avisado de que qualquer um de seus códigos que inclua este cabeçalho pode estar confiando em comportamento não documentado e provavelmente quebrará em versões futuras do MFC.

No caso raro de precisar lidar com uma dessas mensagens, você deve usar a macro do mapa de ON_MESSAGE e manusear a mensagem no formato genérico LRESULT/WPARAM/LPARAM.

**WM_QUERYAFXWNDPROC**

Esta mensagem é enviada para uma janela que está sendo criada. Isso é enviado muito cedo no processo de criação como um método de determinar se o WndProc é **AfxWndProc. AfxWndProc** retorna 1.

|||
|-|-|
|wParam|Não usado|
|lParam|Não usado|
|retorna|1 se processado por **AfxWndProc**|

**WM_SIZEPARENT**

Esta mensagem é enviada por uma janela de`CFrameWnd::OnSize` quadro `CFrameWnd::RecalcLayout` para `CWnd::RepositionBars`seus filhos imediatos durante o redimensionamento ( chamadas que chama ) para reposicionar as barras de controle ao redor da lateral do quadro. A estrutura AFX_SIZEPARENTPARAMS contém o retângulo de cliente disponível atual do pai e `DeferWindowPos` um HDWP (que pode ser NULO) com o qual chamar para minimizar a repintura.

|||
|-|-|
|wParam|Não usado|
|lParam|Endereço de uma estrutura AFX_SIZEPARENTPARAMS|
|retorna|Não utilizado (0)|

Ignorar a mensagem indica que a janela não faz parte do layout.

**WM_SETMESSAGESTRING**

Esta mensagem é enviada para uma janela de quadro para pedir que atualize a linha de mensagem na barra de status. Um ID de seqüência ou um LPCSTR podem ser especificados (mas não ambos).

|||
|-|-|
|wParam|ID de string (ou zero)|
|lParam|LPCSTR para a seqüência (ou NULL)|
|retorna|Não utilizado (0)|

**Wm_idleupdatecmdui**

Esta mensagem é enviada em tempo ocioso para implementar a atualização em tempo ocioso dos manipuladores de iu de comando de atualização. Se a janela (geralmente uma barra de controle) `CCmdUI` manuseie a mensagem, ela `CCmdUI::DoUpdate` criará um objeto (ou um objeto de uma classe derivada) e chamará cada um dos "itens" da janela. Isso, por sua vez, verificará se há um manipulador ON_UPDATE_COMMAND_UI para os objetos na cadeia de comando-handler.

|||
|-|-|
|wParam|BOOL bDisableIfNoHandler|
|lParam|Não utilizado (0)|
|retorna|Não utilizado (0)|

*bDisableIfNoHandler* não é zero para desativar o objeto de ia de urna se não houver nem um manipulador de ON_UPDATE_COMMAND_UI nem ON_COMMAND.

**WM_EXITHELPMODE**

Esta mensagem é `CFrameWnd` postada em um modo de ajuda sensível ao contexto. O recebimento desta mensagem encerra o `CFrameWnd::OnContextHelp`ciclo modal iniciado por .

|||
|-|-|
|wParam|Não utilizado (0)|
|lParam|Não utilizado (0)|
|retorna|Não usado|

**WM_INITIALUPDATE**

Esta mensagem é enviada pelo modelo de documento para todos os descendentes de uma janela de quadro quando é seguro para eles fazerem sua atualização inicial. Ele mapeia `CView::OnInitialUpdate` para uma chamada, mas pode ser usado em outras `CWnd`classes derivadas para outra atualização de um tiro.

|||
|-|-|
|wParam|Não utilizado (0)|
|lParam|Não utilizado (0)|
|retorna|Não utilizado (0)|

**WM_RECALCPARENT**

Esta mensagem é enviada por uma exibição `GetParent`à janela pai (obtida via ) `RecalcLayout`para forçar um recálculo de layout (geralmente, o pai ligará ). Isso é usado em aplicativos de servidor OLE onde é necessário que o quadro cresça em tamanho à medida que o tamanho total da visualização cresce.

Se a janela pai processa essa mensagem, ela deve retornar TRUE e preencher o RECT passado em iParam com o novo tamanho da área do cliente. Isso é `CScrollView` usado para manusear corretamente o scrollbars (coloque então na parte externa da janela quando eles forem adicionados) quando um objeto de servidor estiver ativado no local.

|||
|-|-|
|wParam|Não utilizado (0)|
|lParam|Rect LPRECTClient, pode ser NULO|
|retorna|VERDADE se o novo retângulo do cliente retornou, FALSO de outra forma|

**WM_SIZECHILD**

Esta mensagem `COleResizeBar` é enviada para `GetOwner`a janela do proprietário (via ) quando o usuário redimensiona a barra de redimensionamento com as alças de redimensionamento. `COleIPFrameWnd`responde a esta mensagem tentando reposicionar a janela do quadro como o usuário solicitou.

O novo retângulo, dado nas coordenadas do cliente em relação à janela do quadro que contém a barra de redimensionamento, é apontado por lParam.

|||
|-|-|
|wParam|Não utilizado (0)|
|lParam|Rect LPRECTNovo|
|retorna|Não utilizado (0)|

**WM_DISABLEMODAL**

Esta mensagem é enviada para todas as janelas pop-up de propriedade de uma janela de quadro que está sendo desativada. A janela do quadro usa o resultado para determinar se desabilita ou não a janela pop-up.

Você pode usar isso para realizar processamento especial em sua janela pop-up quando o quadro entra em um estado modal ou para evitar que certas janelas pop-up fiquem desativadas. As dicas de ferramentas usam essa mensagem para se destruir quando a janela do quadro entra em estado modal, por exemplo.

|||
|-|-|
|wParam|Não utilizado (0)|
|lParam|Não utilizado (0)|
|retorna|Não-zero para **NÃO** desativar a janela, 0 indica que a janela será desativada|

**WM_FLOATSTATUS**

Esta mensagem é enviada para todas as janelas pop-up de propriedade de uma janela de quadro quando o quadro é ativado ou desativado por outra janela de quadro de nível superior. Isso é usado pela implementação de MFS_SYNCACTIVE em `CMiniFrameWnd`, para manter a ativação dessas janelas pop-up em sincronia com a ativação da janela de quadro de nível superior.

|||
|-|-|
|wParam|É um dos seguintes valores:<br /><br /> FS_SHOW<br /><br /> FS_HIDE<br /><br /> FS_ACTIVATE<br /><br /> FS_DEACTIVATE<br /><br /> FS_ENABLEFS_DISABLE<br /><br /> FS_SYNCACTIVE|
|lParam|Não utilizado (0)|

O valor de retorno não deve ser zero se FS_SYNCACTIVE estiver definido e a janela sincronizar sua ativação com o quadro pai. `CMiniFrameWnd`retorna não-zero quando o estilo é definido como MFS_SYNCACTIVE.

Para obter mais informações, `CMiniFrameWnd`consulte a implementação de .

## <a name="wm_activatetoplevel"></a>WM_ACTIVATETOPLEVEL

Esta mensagem é enviada para uma janela de nível superior quando uma janela em seu "grupo de alto nível" é ativada ou desativada. Uma janela faz parte de um grupo de alto nível se for uma janela de alto nível (sem pai ou proprietário), ou se for propriedade de tal janela. Esta mensagem é semelhante em uso para WM_ACTIVATEAPP, mas funciona em situações em que janelas pertencentes a diferentes processos são misturadas em uma única hierarquia de janelas (comum em aplicações OLE).

## <a name="wm_commandhelp-wm_helphittest-wm_exithelpmode"></a>WM_COMMANDHELP, WM_HELPHITTEST WM_EXITHELPMODE

Essas mensagens são usadas na implementação de ajuda sensível ao contexto. Consulte a [Nota Técnica 28](../mfc/tn028-context-sensitive-help-support.md) para obter mais informações.

## <a name="mfc-private-resource-formats"></a>Formatos de recursos privados do MFC

Atualmente, o MFC define dois formatos de recursos privados: RT_TOOLBAR e RT_DLGINIT.

## <a name="rt_toolbar-resource-format"></a>formato de recurso RT_TOOLBAR

A barra de ferramentas padrão fornecida pelo AppWizard é baseada em um recurso personalizado RT_TOOLBAR, que foi introduzido no MFC 4.0. Você pode editar este recurso usando o editor da barra de ferramentas.

## <a name="rt_dlginit-resource-format"></a>formato de recurso RT_DLGINIT

Um formato de recurso privado do MFC é usado para armazenar informações extras de inicialização de diálogo. Isso inclui as seqüências iniciais armazenadas em uma caixa de combinação. O formato deste recurso não foi projetado para ser editado manualmente, mas é manuseado pelo Visual C++.

O Visual C++ e este recurso RT_DLGINIT não são necessários para usar os recursos relacionados do MFC, uma vez que existem alternativas de API para usar as informações no recurso. O uso do Visual C++ torna muito mais fácil escrever, manter e traduzir sua aplicação a longo prazo.

A estrutura básica de um recurso RT_DLGINIT é a seguinte:

```
+---------------+    \
| Control ID    |   UINT             |
+---------------+    |
| Message #     |   UINT             |
+---------------+    |
|length of data |   DWORD            |
+---------------+    |   Repeated
|   Data        |   Variable Length  |   for each control
|   ...         |   and Format       |   and message
+---------------+    /
|     0         |   BYTE
+---------------+
```

Uma seção repetida contém o ID de controle para enviar a mensagem, a mensagem # para enviar (uma mensagem normal do Windows) e um comprimento variável de dados. A mensagem do Windows é enviada em um formulário:

```
SendDlgItemMessage(<Control ID>, <Message #>, 0, &<Data>);
```

Este é um formato muito geral, permitindo qualquer mensagem do Windows e conteúdo de dados. O editor de recursos Visual C++ e o MFC só suportam um subconjunto limitado de mensagens do Windows: CB_ADDSTRING para as opções iniciais de lista para caixas de combinação (os dados são uma seqüência de texto).

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
