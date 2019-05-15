---
title: 'TN024: Recursos e as mensagens definidas pelo MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- resources [MFC]
- Windows messages [MFC], MFC-defined
- messages [MFC], MFC
- TN024
ms.assetid: c65353ce-8096-454b-ad22-1a7a1dd9a788
ms.openlocfilehash: 300819878bd7422dc8f3970493e303aa52346a58
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611427"
---
# <a name="tn024-mfc-defined-messages-and-resources"></a>TN024: Recursos e as mensagens definidas pelo MFC

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve as mensagens internas do Windows e os formatos de recurso usados pelo MFC. Essas informações explica a implementação do framework e irá ajudá-lo a depurar seu aplicativo. Para aventureiro, embora todas essas informações estão oficialmente sem suporte, você pode usar algumas dessas informações para implementações avançadas.

Esta nota contém detalhes de implementação privada do MFC. todo o conteúdo está sujeitos a alterações no futuro. Mensagens privadas de Windows MFC têm significado no escopo de um aplicativo apenas, mas serão alterado no futuro para conter todo o sistema de mensagens.

As mensagens de Windows privadas do intervalo do MFC e os tipos de recursos estão no intervalo reservado de "sistema" reservar pelo Microsoft Windows. No momento, nem todos os números nos intervalos são usados e, no futuro, os novos números no intervalo podem ser usados. Os números usados atualmente podem ser alterados.

Windows privadas MFC, as mensagens estão no intervalo 0x360 -> 0x37F.

Recurso particular do MFC tipos estão no intervalo 0xF0 -> 0xFF.

**Mensagens do MFC particulares Windows**

Essas mensagens do Windows são usadas no lugar de funções virtuais do C++ em que o acoplamento relativamente flexível é necessário entre objetos de janela e onde uma função virtual de C++ não seria apropriada.

Essas mensagens particulares do Windows e estruturas de parâmetro associado são declaradas no cabeçalho MFC privado ' AFXPRIV. H'. Lembre-se que qualquer código que inclui esse cabeçalho podem ser depender de comportamento não documentado e será provavelmente quebrará em futuras versões do MFC.

No caso raro de necessidade de lidar com uma dessas mensagens, você deve usar a macro de mapa de mensagem ON_MESSAGE e manipular a mensagem no formato genérico WPARAM/LRESULT/LPARAM.

**WM_QUERYAFXWNDPROC**

Esta mensagem é enviada para uma janela que está sendo criada. Isso é enviado muito cedo no processo de criação como um método para determinar se é o WndProc **AfxWndProc. AfxWndProc** retorna 1.

|||
|-|-|
|wParam|Não usado|
|lParam|Não usado|
|retorna|1 se processados pelo **AfxWndProc**|

**WM_SIZEPARENT**

Esta mensagem é enviada por uma janela de quadro para seus filhos imediatos durante o redimensionamento (`CFrameWnd::OnSize` chamadas `CFrameWnd::RecalcLayout` que chama `CWnd::RepositionBars`) para reposicionar as barras de controle em torno do lado do quadro. A estrutura AFX_SIZEPARENTPARAMS contém o retângulo atual do cliente disponíveis de pai e um HDWP (que pode ser nulo) com o qual chamar `DeferWindowPos` para minimizar o redesenho.

|||
|-|-|
|wParam|Não usado|
|lParam|Endereço de uma estrutura AFX_SIZEPARENTPARAMS|
|retorna|Não usado (0)|

Ignorando a mensagem indica que a janela não fazem parte de layout.

**WM_SETMESSAGESTRING**

Esta mensagem é enviada para uma janela do quadro para solicitar a ele para atualizar a linha de mensagem na barra de status. Uma ID de cadeia de caracteres ou um LPCSTR pode ser especificado (mas não ambos).

|||
|-|-|
|wParam|Cadeia de caracteres de ID (ou zero)|
|lParam|LPCSTR para a cadeia de caracteres (ou nulo)|
|retorna|Não usado (0)|

**WM_IDLEUPDATECMDUI**

Esta mensagem é enviada em tempo ocioso para implementar a atualização de tempo ocioso de manipuladores de interface do usuário do comando de atualização. Se a janela (normalmente, uma barra de controle) manipula a mensagem, ele cria um `CCmdUI` objeto (ou um objeto de uma classe derivada) e chamar `CCmdUI::DoUpdate` para cada um dos "itens" na janela. Isso por sua vez verificará se há um manipulador de ON_UPDATE_COMMAND_UI para os objetos na cadeia de manipulador de comandos.

|||
|-|-|
|wParam|BOOL bDisableIfNoHandler|
|lParam|Não usado (0)|
|retorna|Não usado (0)|

*bDisableIfNoHandler* é diferente de zero para desabilitar o objeto de interface do usuário se há um ON_UPDATE_COMMAND_UI nem um manipulador de ON_COMMAND.

**WM_EXITHELPMODE**

Essa mensagem é postada para um `CFrameWnd` modo que sair sensíveis ao contexto de Ajuda. O recebimento da mensagem encerra o loop restrito de iniciada pelo `CFrameWnd::OnContextHelp`.

|||
|-|-|
|wParam|Não usado (0)|
|lParam|Não usado (0)|
|retorna|Não usado|

**WM_INITIALUPDATE**

Esta mensagem é enviada pelo modelo de documento para todos os descendentes de uma janela de quadro quando é seguro para que eles possam fazer a atualização inicial. Ele é mapeado para uma chamada para `CView::OnInitialUpdate` , mas pode ser usado em outros `CWnd`-classes para a outra atualização propagandas derivadas.

|||
|-|-|
|wParam|Não usado (0)|
|lParam|Não usado (0)|
|retorna|Não usado (0)|

**WM_RECALCPARENT**

Esta mensagem é enviada por um modo de exibição à sua janela pai (obtido por meio `GetParent`) para forçar um recálculo de layout (normalmente, o pai chamará `RecalcLayout`). Isso é usado em aplicativos de servidor OLE em que é necessário para o quadro a crescer em tamanho à medida que aumenta de tamanho total da exibição.

Se a janela pai processar essa mensagem, ele deve retornar TRUE e preencher o RECT passado lParam com o novo tamanho da área de cliente. Isso é usado em `CScrollView` para lidar adequadamente com barras de rolagem (local, em seguida, no lado de fora da janela quando eles forem adicionados) quando um objeto de servidor é ativado no local.

|||
|-|-|
|wParam|Não usado (0)|
|lParam|LPRECT rectClient, pode ser NULL|
|retorna|Retângulo TRUE se o novo cliente retornado; FALSO caso contrário|

**WM_SIZECHILD**

Esta mensagem é enviada pela `COleResizeBar` à sua janela de proprietário (por meio de `GetOwner`) quando o usuário redimensiona a barra de redimensionamento com as alças de redimensionamento. `COleIPFrameWnd` responde a essa mensagem, a tentativa de reposicionar a janela do quadro, como o usuário solicitou.

O novo retângulo fornecido em coordenadas de cliente relativa à janela do quadro que contém a barra de redimensionamento é apontado pelo lParam.

|||
|-|-|
|wParam|Não usado (0)|
|lParam|RectNew LPRECT|
|retorna|Não usado (0)|

**WM_DISABLEMODAL**

Esta mensagem é enviada para todas as janelas pop-up pertencentes a uma janela do quadro que está sendo desativada. A janela de quadro usa o resultado para determinar se deve ou não desabilitar a janela pop-up.

Você pode usar isso para executar um processamento especial na sua janela pop-up quando o quadro entra em um estado modal ou para impedir que determinadas janelas pop-up sendo desabilitado. Dicas de ferramentas usam esta mensagem para destroem a próprios quando a janela do quadro entra em um estado modal, por exemplo.

|||
|-|-|
|wParam|Não usado (0)|
|lParam|Não usado (0)|
|retorna|Diferente de zero a **não** desativar a janela, 0 indica que a janela será desabilitada|

**WM_FLOATSTATUS**

Esta mensagem é enviada para todas as janelas pop-up pertencentes a uma janela de quadro quando o quadro é ativado ou desativado por outra janela do quadro de nível superior. Isso é usado pela implementação do MFS_SYNCACTIVE em `CMiniFrameWnd`, para manter a ativação das janelas pop-up em sincronia com a ativação da janela do quadro de nível superior.

|||
|-|-|
|wParam|É um dos seguintes valores:<br /><br /> FS_SHOW<br /><br /> FS_HIDE<br /><br /> FS_ACTIVATE<br /><br /> FS_DEACTIVATE<br /><br /> FS_ENABLEFS_DISABLE<br /><br /> FS_SYNCACTIVE|
|lParam|Não usado (0)|

O valor de retorno deve ser diferente de zero se FS_SYNCACTIVE está definida e a janela sincroniza sua ativação com o quadro principal. `CMiniFrameWnd` Retorna não zero quando o estilo é definido como MFS_SYNCACTIVE.

Para obter mais informações, consulte a implementação de `CMiniFrameWnd`.

## <a name="wmactivatetoplevel"></a>WM_ACTIVATETOPLEVEL

Esta mensagem é enviada para uma janela de nível superior quando uma janela em seu "grupo de nível superior" é ativada ou desativada. Uma janela é parte de um grupo de nível superior, se for uma janela de nível superior (nenhum pai ou proprietário), ou se ele pertence a essa janela. Esta mensagem é semelhante ao uso de WM_ACTIVATEAPP, mas funciona em situações em que a que pertencem a diferentes processos do windows são combinados em uma hierarquia de única janela (comum em aplicativos OLE).

## <a name="wmcommandhelp-wmhelphittest-wmexithelpmode"></a>WM_COMMANDHELP, WM_HELPHITTEST, WM_EXITHELPMODE

Essas mensagens são usadas na implementação de ajuda contextual. Consulte a [nota técnica 28](../mfc/tn028-context-sensitive-help-support.md) para obter mais informações.

## <a name="mfc-private-resource-formats"></a>Formatos de recurso particular MFC

Atualmente, o MFC define dois formatos de recurso privado: RT_TOOLBAR e RT_DLGINIT.

## <a name="rttoolbar-resource-format"></a>Formato de recurso RT_TOOLBAR

A barra de ferramentas padrão fornecida pelo AppWizard baseia-se em um recurso RT_TOOLBAR personalizado, que foi introduzido no MFC 4.0. Você pode editar esse recurso usando o editor de barra de ferramentas.

## <a name="rtdlginit-resource-format"></a>Formato de recurso RT_DLGINIT

Um formato de recurso privado MFC é usado para armazenar informações de inicialização extra da caixa de diálogo. Isso inclui as cadeias de caracteres inicias armazenadas em uma caixa de combinação. O formato desse recurso não foi projetado para ser editado manualmente, mas é tratada pelo Visual C++.

O Visual C++ e esse recurso RT_DLGINIT não são necessários para usar os recursos relacionados do MFC, pois há alternativa de API para usar as informações no recurso. Usando o Visual C++ torna muito mais fácil de escrever, manter e converter seu aplicativo a longo prazo.

A estrutura básica de um recurso RT_DLGINIT é da seguinte maneira:

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

Uma seção repetida contém a ID de controle para enviar a mensagem, a mensagem # para enviar (uma mensagem normal do Windows) e um comprimento variável de dados. A mensagem do Windows é enviada em um formulário:

```
SendDlgItemMessage(<Control ID>, <Message #>, 0, &<Data>);
```

Este é um formato muito geral, permitindo que quaisquer mensagens de Windows e o conteúdo dos dados. O editor de recursos do Visual C++ e MFC suportam apenas um subconjunto limitado de mensagens do Windows: CB_ADDSTRING para as opções lista iniciais para as caixas de combinação (os dados são uma cadeia de caracteres de texto).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
