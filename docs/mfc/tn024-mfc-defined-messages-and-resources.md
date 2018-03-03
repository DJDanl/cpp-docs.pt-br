---
title: 'TN024: Mensagens definidas pelo MFC e recursos | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.messages
dev_langs:
- C++
helpviewer_keywords:
- resources [MFC]
- Windows messages [MFC], MFC-defined
- messages [MFC], MFC
- TN024
ms.assetid: c65353ce-8096-454b-ad22-1a7a1dd9a788
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 17aadfd089d6917cd8cded239287034026ff7ad3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn024-mfc-defined-messages-and-resources"></a>TN024: mensagens e recursos definidos pelo MFC
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve os formatos de recursos usados pelo MFC e mensagens internas do Windows. Essas informações explica a implementação do framework e irá ajudá-lo na depuração de seu aplicativo. Para sentir, mesmo que todas essas informações não são oficialmente suportadas, você pode usar algumas dessas informações para implementações avançadas.  
  
 Esta anotação contém os detalhes de implementação privada do MFC; todo o conteúdo está sujeitos a alterações no futuro. Mensagens do Windows privadas MFC têm significado no escopo de um aplicativo apenas, mas serão alterado no futuro para conter todo o sistema de mensagens.  
  
 As mensagens do Windows privadas intervalo do MFC e tipos de recursos estão no intervalo reservado de "sistema" reservou pelo Microsoft Windows. Atualmente, nem todos os números nos intervalos são usados e, no futuro, os novos números do intervalo podem ser usados. Os números usados atualmente podem ser alterados.  
  
 MFC Windows privadas mensagens estão no intervalo 0x360 -> 0x37F.  
  
 Recurso particular do MFC tipos estão no intervalo 0xF0 -> 0xFF.  
  
 **Mensagens do Windows privada MFC**  
  
 Essas mensagens do Windows são usadas no lugar de funções virtuais C++ onde relativamente acoplamento é necessário entre objetos de janela e onde uma função virtual de C++ não seria apropriada.  
  
 Essas mensagens particulares do Windows e estruturas de parâmetro associados são declaradas no cabeçalho MFC privado ' AFXPRIV. H'. Lembre-se que qualquer código que inclui esse cabeçalho pode ser confiam em comportamento não documentado e será provavelmente quebrará em futuras versões do MFC.  
  
 No caso raro de necessidade de lidar com uma dessas mensagens, você deve usar o `ON_MESSAGE` macros de mapa de mensagem e manipular a mensagem no formato WPARAM/LRESULT/LPARAM genérico.  
  
 **WM_QUERYAFXWNDPROC**  
  
 Esta mensagem é enviada para uma janela que está sendo criada. Isto é enviado como um método para determinar se o WndProc é muito cedo no processo de criação **AfxWndProc. AfxWndProc** retorna 1.  
  
|||  
|-|-|  
|wParam|Não usado|  
|lParam|Não usado|  
|retorna|1 se processadas pelo **AfxWndProc**|  
  
 **WM_SIZEPARENT**  
  
 Esta mensagem é enviada por uma janela do quadro para seus filhos imediatos durante o redimensionamento (**CFrameWnd::OnSize** chamadas `CFrameWnd::RecalcLayout` que chama `CWnd::RepositionBars`) para reposicionar as barras de controle em torno do lado do quadro. O **AFX_SIZEPARENTPARAMS** estrutura contém o retângulo de cliente disponíveis atual de pai e um HDWP (que pode ser NULL) com o qual chamar `DeferWindowPos` para minimizar redesenho.  
  
|||  
|-|-|  
|wParam|Não usado|  
|lParam|Endereço de um **AFX_SIZEPARENTPARAMS** estrutura|  
|retorna|Não usado (0)|  
  
 Ignorando a mensagem indica que a janela não fazem parte de layout.  
  
 **WM_SETMESSAGESTRING**  
  
 Esta mensagem é enviada para uma janela do quadro pedir a ele para atualizar a linha de mensagem na barra de status. Uma ID de cadeia de caracteres ou um LPCSTR pode ser especificado (mas não ambos).  
  
|||  
|-|-|  
|wParam|Cadeia de caracteres de ID (ou zero)|  
|lParam|LPCSTR a cadeia de caracteres (ou NULL)|  
|retorna|Não usado (0)|  
  
 **WM_IDLEUPDATECMDUI**  
  
 Esta mensagem é enviada no tempo ocioso para implementar a atualização de tempo ocioso de manipuladores de interface do usuário do comando de atualização. Se a janela (geralmente uma barra de controle) manipula a mensagem, ele cria um `CCmdUI` objeto (ou um objeto de uma classe derivada) e chame **CCmdUI::DoUpdate** para cada "itens" na janela. Isso vai procurar por sua vez um `ON_UPDATE_COMMAND_UI` manipulador para os objetos na cadeia de manipulador de comandos.  
  
|||  
|-|-|  
|wParam|BOOL bDisableIfNoHandler|  
|lParam|Não usado (0)|  
|retorna|Não usado (0)|  
  
 *bDisableIfNoHandler* é diferente de zero para desativar o objeto de interface do usuário se não houver nenhum um `ON_UPDATE_COMMAND_UI` nem `ON_COMMAND` manipulador.  
  
 **WM_EXITHELPMODE**  
  
 Esta mensagem é enviada para um `CFrameWnd` modo para sair sensíveis ao contexto de Ajuda. O recebimento da mensagem encerra o loop modal iniciado por **CFrameWnd::OnContextHelp.**  
  
|||  
|-|-|  
|wParam|Não usado (0)|  
|lParam|Não usado (0)|  
|retorna|Não usado|  
  
 **WM_INITIALUPDATE**  
  
 Esta mensagem é enviada pelo modelo de documento para todos os descendentes de uma janela do quadro quando é seguro fazer a atualização inicial. Ele é mapeado para uma chamada para `CView::OnInitialUpdate` , mas pode ser usado em outros `CWnd`-derivadas de classes para outros da atualização.  
  
|||  
|-|-|  
|wParam|Não usado (0)|  
|lParam|Não usado (0)|  
|retorna|Não usado (0)|  
  
 **WM_RECALCPARENT**  
  
 Esta mensagem é enviada por uma exibição para sua janela pai (obtido por meio de `GetParent`) para forçar um recálculo de layout (normalmente, o pai chamará `RecalcLayout`). Isso é usado em aplicativos de servidor OLE em que é necessário para o quadro crescendo em tamanho à medida que aumenta de tamanho total do modo de exibição.  
  
 Se a janela pai processar essa mensagem, ele deve retornar TRUE e preencher o retângulo passado lParam com o novo tamanho da área cliente. Isso é usado em `CScrollView` para lidar adequadamente com barras de rolagem (local, em seguida, no lado de fora da janela quando eles são adicionados) quando um objeto de servidor está ativado no local.  
  
|||  
|-|-|  
|wParam|Não usado (0)|  
|lParam|LPRECT rectClient, pode ser NULL|  
|retorna|Retângulo TRUE se o novo cliente retornado, FALSO caso contrário|  
  
 **WM_SIZECHILD**  
  
 Esta mensagem é enviada por `COleResizeBar` para sua janela do proprietário (via `GetOwner`) quando o usuário o redimensiona a barra de redimensionamento com as alças de redimensionamento. `COleIPFrameWnd`responde a essa mensagem tentativa reposicionar a janela do quadro, como o usuário solicitou.  
  
 O novo retângulo fornecido nas coordenadas do cliente em relação a janela do quadro que contém a barra de redimensionamento é indicado pelo lParam.  
  
|||  
|-|-|  
|wParam|Não usado (0)|  
|lParam|RectNew LPRECT|  
|retorna|Não usado (0)|  
  
 **WM_DISABLEMODAL**  
  
 Esta mensagem é enviada para todas as janelas pop-up pertencentes a uma janela do quadro que está sendo desativada. A janela do quadro usa o resultado para determinar se deve ou não desabilitar a janela pop-up.  
  
 Você pode usar isso para realizar processamento especial na janela de pop-up quando o quadro entra em estado modal ou impedir que certos janelas pop-up obtendo desabilitado. Dicas de ferramenta usam esta mensagem para destruir si quando a janela do quadro entra em estado modal, por exemplo.  
  
|||  
|-|-|  
|wParam|Não usado (0)|  
|lParam|Não usado (0)|  
|retorna|Diferente de zero para **não** desativar a janela, 0 indica que a janela será desabilitada|  
  
 **WM_FLOATSTATUS**  
  
 Esta mensagem é enviada para todas as janelas pop-up pertencentes a uma janela do quadro quando o quadro é ativado ou desativado por outra janela do quadro de nível superior. Isso é usado pela implementação de **MFS_SYNCACTIVE** em `CMiniFrameWnd`, para manter a ativação dessas janelas pop-up em sincronia com a ativação da janela do quadro de nível superior.  
  
|||  
|-|-|  
|wParam|É um dos seguintes valores:<br /><br /> **FS_SHOW**<br /><br /> **FS_HIDE**<br /><br /> **FS_ACTIVATE**<br /><br /> **FS_DEACTIVATE**<br /><br /> **FS_ENABLEFS_DISABLE**<br /><br /> **FS_SYNCACTIVE**|  
|lParam|Não usado (0)|  
  
 O valor de retorno deve ser diferente de zero se **FS_SYNCACTIVE** é definido e sincroniza a janela sua ativação com o quadro do pai. `CMiniFrameWnd`Retorna diferente de zero quando o estilo é definido como **MFS_SYNCACTIVE.**  
  
 Para obter mais informações, consulte a implementação de `CMiniFrameWnd`.  
  
## <a name="wmactivatetoplevel"></a>WM_ACTIVATETOPLEVEL  
 Esta mensagem é enviada para uma janela de nível superior quando uma janela em seu "grupo de nível superior" é ativada ou desativada. Uma janela é parte de um grupo de nível superior, se ela for uma janela de nível superior (nenhum pai ou proprietário) ou ele pertence a uma janela. Essa mensagem é semelhante em uso para **WM_ACTIVATEAPP,** , mas funciona em situações onde que pertencem a diferentes processos do windows é combinado em uma hierarquia de janela única (comum em aplicativos OLE).  
  
## <a name="wmcommandhelp-wmhelphittest-wmexithelpmode"></a>WM_COMMANDHELP, WM_HELPHITTEST, WM_EXITHELPMODE  
 Essas mensagens são usadas na implementação de ajuda contextual. Consulte [28 de observação técnica](../mfc/tn028-context-sensitive-help-support.md) para obter mais informações.  
  
## <a name="mfc-private-resource-formats"></a>Formatos de recurso particular MFC  
 Atualmente, o MFC define dois formatos de recurso particular: **RT_TOOLBAR** e **RT_DLGINIT**.  
  
## <a name="rttoolbar-resource-format"></a>Formato de recurso RT_TOOLBAR  
 A barra de ferramentas padrão fornecida pelo AppWizard baseia-se em uma **RT_TOOLBAR** recurso personalizado, que foi introduzido no MFC 4.0. Você pode editar esse recurso usando o editor de barra de ferramentas.  
  
## <a name="rtdlginit-resource-format"></a>Formato de recurso RT_DLGINIT  
 Um formato de recurso particular MFC é usado para armazenar informações de inicialização da caixa de diálogo extra. Isso inclui as cadeias de caracteres iniciais armazenadas em uma caixa de combinação. O formato desse recurso não foi projetado para ser editado manualmente, mas é tratado pelo Visual C++.  
  
 Visual C++ e isso **RT_DLGINIT** recursos não devem usar os recursos relacionados do MFC, pois há alternativa de API para usar as informações no recurso. Usando o Visual C++ torna muito mais fácil de escrever, manter e converter seu aplicativo a longo prazo.  
  
 A estrutura básica de um **RT_DLGINIT** recurso é o seguinte:  
  
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
  
 Isso é um formato muito geral, permitindo que quaisquer mensagens do Windows e o conteúdo dos dados. O editor de recursos do Visual C++ e MFC só oferecem suporte a um subconjunto limitado de mensagens do Windows: CB_ADDSTRING para as opções de lista iniciais para caixas de combinação (os dados são uma cadeia de caracteres de texto).  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

