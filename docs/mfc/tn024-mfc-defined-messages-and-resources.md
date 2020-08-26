---
title: 'TN024: mensagens e recursos definidos pelo MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- resources [MFC]
- Windows messages [MFC], MFC-defined
- messages [MFC], MFC
- TN024
ms.assetid: c65353ce-8096-454b-ad22-1a7a1dd9a788
ms.openlocfilehash: 9ad6827e4a46bb9f2ff3b02986a01737772e0858
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839212"
---
# <a name="tn024-mfc-defined-messages-and-resources"></a>TN024: mensagens e recursos definidos pelo MFC

> [!NOTE]
> A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

Esta observação descreve as mensagens internas do Windows e os formatos de recursos usados pelo MFC. Essas informações explicam a implementação da estrutura e ajudarão você a depurar seu aplicativo. Para o aventuraram, mesmo que todas essas informações não sejam oficialmente suportadas, você pode usar algumas dessas informações para implementações avançadas.

Esta nota contém detalhes de implementação privada do MFC; todo o conteúdo está sujeito a alterações no futuro. As mensagens do Windows privadas do MFC têm significado no escopo de um aplicativo somente, mas serão alteradas no futuro para conter mensagens de todo o sistema.

O intervalo de mensagens do Windows privadas do MFC e os tipos de recursos estão no intervalo de "sistema" reservado, separados pelo Microsoft Windows. Atualmente, nem todos os números nos intervalos são usados e, no futuro, podem ser usados novos números no intervalo. Os números usados no momento podem ser alterados.

As mensagens do Windows privadas do MFC estão no intervalo 0x360->0x37F.

Os tipos de recurso privados do MFC estão no intervalo 0xF0->0xFF.

**Mensagens do Windows privadas do MFC**

Essas mensagens do Windows são usadas no lugar de funções virtuais do C++ em que o acoplamento relativamente flexível é necessário entre os objetos do Windows e onde uma função virtual do C++ não seria apropriada.

Essas mensagens particulares do Windows e as estruturas de parâmetros associadas são declaradas no cabeçalho privado do MFC ' AFXPRIV. H '. Seja avisado de que qualquer código que inclua esse cabeçalho pode estar contando com comportamento não documentado e provavelmente será interrompido em versões futuras do MFC.

No caso raro de precisar lidar com uma dessas mensagens, você deve usar a macro ON_MESSAGE mapa de mensagens e manipular a mensagem no formato genérico LRESULT/WPARAM/LPARAM.

**WM_QUERYAFXWNDPROC**

Essa mensagem é enviada para uma janela que está sendo criada. Isso é enviado muito cedo no processo de criação como um método de determinar se o WndProc é **AfxWndProc. AfxWndProc** retorna 1.

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|Não usado|
|lParam|Não usado|
|retorna|1 se processado por **AfxWndProc**|

**WM_SIZEPARENT**

Essa mensagem é enviada por uma janela de quadro para seus filhos imediatos durante o redimensionamento ( `CFrameWnd::OnSize` chama `CFrameWnd::RecalcLayout` quais chamadas `CWnd::RepositionBars` ) para reposicionar as barras de controle ao lado do quadro. A estrutura de AFX_SIZEPARENTPARAMS contém o retângulo de cliente atual disponível do pai e um HDWP (que pode ser nulo) com o qual chamar `DeferWindowPos` para minimizar a repintura.

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|Não usado|
|lParam|Endereço de uma estrutura de AFX_SIZEPARENTPARAMS|
|retorna|Não usado (0)|

Ignorar a mensagem indica que a janela não faz parte do layout.

**WM_SETMESSAGESTRING**

Essa mensagem é enviada para uma janela do quadro para solicitar que ela atualize a linha da mensagem na barra de status. Uma ID de cadeia de caracteres ou um LPCSTR pode ser especificado (mas não ambos).

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|ID da cadeia de caracteres (ou zero)|
|lParam|LPCSTR para a cadeia de caracteres (ou NULL)|
|retorna|Não usado (0)|

**WM_IDLEUPDATECMDUI**

Essa mensagem é enviada em tempo ocioso para implementar a atualização de tempo ocioso de manipuladores de interface do usuário de atualização/comando. Se a janela (geralmente uma barra de controle) tratar a mensagem, ela criará um `CCmdUI` objeto (ou um objeto de uma classe derivada) e chamará `CCmdUI::DoUpdate` cada um dos "itens" na janela. Isso, por sua vez, verificará um manipulador de ON_UPDATE_COMMAND_UI para os objetos na cadeia de manipuladores de comandos.

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|BDisableIfNoHandler BOOL|
|lParam|Não usado (0)|
|retorna|Não usado (0)|

*bDisableIfNoHandler* é diferente de zero para desabilitar o objeto de interface do usuário se não houver um ON_UPDATE_COMMAND_UI nem um manipulador de ON_COMMAND.

**WM_EXITHELPMODE**

Esta mensagem é postada para `CFrameWnd` sair do modo de ajuda contextual. O recebimento dessa mensagem encerra o loop modal iniciado pelo `CFrameWnd::OnContextHelp` .

| Parâmetro e valor de retorno | Descrição |
|-|-|
|wParam|Não usado (0)|
|lParam|Não usado (0)|
|retorna|Não usado|

**WM_INITIALUPDATE**

Essa mensagem é enviada pelo modelo de documento para todos os descendentes de uma janela de quadro quando é seguro para que eles façam sua atualização inicial. Ele é mapeado para uma chamada para `CView::OnInitialUpdate` , mas pode ser usado em outras `CWnd` classes derivadas para outras atualizações de uma só imagem.

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|Não usado (0)|
|lParam|Não usado (0)|
|retorna|Não usado (0)|

**WM_RECALCPARENT**

Essa mensagem é enviada por uma exibição para sua janela pai (obtida via `GetParent` ) para forçar um recálculo de layout (normalmente, o pai chamará `RecalcLayout` ). Isso é usado em aplicativos de servidor OLE, onde é necessário que o quadro cresça em tamanho conforme o tamanho total da exibição aumenta.

Se a janela pai processar essa mensagem, ela deverá retornar TRUE e preencher o RECT passado em lParam com o novo tamanho da área do cliente. Isso é usado no `CScrollView` para lidar corretamente com as barras de rolagem (Coloque-as fora da janela quando elas são adicionadas) quando um objeto de servidor é ativado no local.

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|Não usado (0)|
|lParam|LPRECT rectClient, pode ser nulo|
|retorna|TRUE se o novo retângulo do cliente for retornado; caso contrário, FALSE|

**WM_SIZECHILD**

Essa mensagem é enviada pelo `COleResizeBar` para sua janela de proprietário (via `GetOwner` ) quando o usuário redimensiona a barra de redimensionamento com as alças de redimensionamento. `COleIPFrameWnd` responde a essa mensagem ao tentar reposicionar a janela do quadro conforme solicitado pelo usuário.

O novo retângulo, fornecido em coordenadas do cliente em relação à janela do quadro que contém a barra de redimensionamento, é apontado por lParam.

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|Não usado (0)|
|lParam|LPRECT rectNew|
|retorna|Não usado (0)|

**WM_DISABLEMODAL**

Essa mensagem é enviada a todas as janelas pop-up pertencentes a uma janela de quadro que está sendo desativada. A janela do quadro usa o resultado para determinar se deseja ou não desabilitar a janela pop-up.

Você pode usar isso para executar o processamento especial na janela pop-up quando o quadro entra em um estado modal ou para impedir que determinadas janelas pop-up sejam desabilitadas. As dicas de ferramenta usam essa mensagem para se destruir quando a janela do quadro entra em um estado modal, por exemplo.

| Parâmetros e valor de retorno | Descrição |
|-|-|
|wParam|Não usado (0)|
|lParam|Não usado (0)|
|retorna|Diferente de zero para **não** desabilitar a janela, 0 indica que a janela será desabilitada|

**WM_FLOATSTATUS**

Essa mensagem é enviada a todas as janelas pop-up pertencentes a uma janela de quadro quando o quadro é ativado ou desativado por outra janela de quadro de nível superior. Isso é usado pela implementação de MFS_SYNCACTIVE no `CMiniFrameWnd` , para manter a ativação dessas janelas pop-up em sincronia com a ativação da janela de quadro de nível superior.

| Parâmetros | Descrição |
|-|-|
|wParam|É um dos seguintes valores:<br /><br /> FS_SHOW<br /><br /> FS_HIDE<br /><br /> FS_ACTIVATE<br /><br /> FS_DEACTIVATE<br /><br /> FS_ENABLEFS_DISABLE<br /><br /> FS_SYNCACTIVE|
|lParam|Não usado (0)|

O valor de retorno deverá ser diferente de zero se FS_SYNCACTIVE estiver definido e a janela syncronizes sua ativação com o quadro pai. `CMiniFrameWnd` Retorna um valor diferente de zero quando o estilo é definido como MFS_SYNCACTIVE.

Para obter mais informações, consulte a implementação de `CMiniFrameWnd` .

## <a name="wm_activatetoplevel"></a>WM_ACTIVATETOPLEVEL

Essa mensagem é enviada para uma janela de nível superior quando uma janela em seu "grupo de nível superior" é ativada ou desativada. Uma janela faz parte de um grupo de nível superior se é uma janela de nível superior (sem pai ou proprietário) ou pertence a tal janela. Essa mensagem é semelhante em uso para WM_ACTIVATEAPP, mas funciona em situações em que as janelas que pertencem a diferentes processos são misturadas em uma única hierarquia de janela (comum em aplicativos OLE).

## <a name="wm_commandhelp-wm_helphittest-wm_exithelpmode"></a>WM_COMMANDHELP, WM_HELPHITTEST, WM_EXITHELPMODE

Essas mensagens são usadas na implementação de ajuda contextual. Veja a [Observação técnica 28](../mfc/tn028-context-sensitive-help-support.md) para obter mais informações.

## <a name="mfc-private-resource-formats"></a>Formatos de recurso privados do MFC

Atualmente, o MFC define dois formatos de recursos privados: RT_TOOLBAR e RT_DLGINIT.

## <a name="rt_toolbar-resource-format"></a>Formato de recurso RT_TOOLBAR

A barra de ferramentas padrão fornecida pelo AppWizard é baseada em um RT_TOOLBAR recurso personalizado, que foi introduzido no MFC 4,0. Você pode editar esse recurso usando o editor de barra de ferramentas.

## <a name="rt_dlginit-resource-format"></a>Formato de recurso RT_DLGINIT

Um formato de recurso privado do MFC é usado para armazenar informações adicionais de inicialização da caixa de diálogo. Isso inclui as cadeias de caracteres iniciais armazenadas em uma caixa de combinação. O formato desse recurso não foi projetado para ser editado manualmente, mas é manipulado pelo Visual C++.

Visual C++ e esse RT_DLGINIT recurso não são necessários para usar os recursos relacionados do MFC, pois há uma alternativa de API ao uso das informações no recurso. O uso de Visual C++ torna muito mais fácil escrever, manter e traduzir seu aplicativo a longo prazo.

A estrutura básica de um recurso de RT_DLGINIT é a seguinte:

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

Uma seção repetida contém a ID de controle para a qual enviar a mensagem, a mensagem # a enviar (uma mensagem normal do Windows) e um comprimento variável de dados. A mensagem do Windows é enviada em um formato:

```
SendDlgItemMessage(<Control ID>, <Message #>, 0, &<Data>);
```

Esse é um formato muito geral, permitindo qualquer mensagem do Windows e conteúdo de dados. O editor de recursos Visual C++ e o MFC só dão suporte a um subconjunto limitado de mensagens do Windows: CB_ADDSTRING para a lista inicial – opções para caixas de combinação (os dados são uma cadeia de caracteres de texto).

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)
