---
title: "TN024: mensagens e recursos definidos pelo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.messages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mensagens [C++], MFC"
  - "recursos [MFC]"
  - "TN024"
  - "mensagens do Windows [C++], definido por MFC"
ms.assetid: c65353ce-8096-454b-ad22-1a7a1dd9a788
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN024: mensagens e recursos definidos pelo MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve as mensagens do windows e os formatos de recursos internos usados por MFC.  Essas informações explica a implementação da estrutura, e ajudam a depurar seu aplicativo.  Para o aventuroso, mesmo que todas essas informações é oficialmente sem suporte, você pode usar algumas dessas informações para implementações avançadas.  
  
 Essa observação contém detalhes de implementação particulares MFC; todo o conteúdo estão sujeitos a alteração no futuro.  As mensagens particulares do windows MFC têm significado no escopo de um aplicativo somente mas são alteradas posteriormente para conter as mensagens em todo o sistema.  
  
 O intervalo de mensagens particulares do windows MFC e os tipos de recursos estão no intervalo permitido de “system” reservado pelo Microsoft Windows.  Nem todos os números em intervalos são usados no momento e, no futuro, os novos números no intervalo podem ser usados.  Os números usados atualmente podem ser alterados.  
  
 As mensagens particulares do windows MFC estão no intervalo 0x360\-0x37F\>.  
  
 Os tipos do recurso particulares MFC estão no intervalo 0xF0\-0xFF\>.  
  
 **Mensagens particulares do windows MFC**  
  
 Essas mensagens do windows são usadas em vez de funções virtuais C\+\+ onde o envolvimento relativamente fraco é necessário entre objetos da janela e onde a função virtual c criando não seria apropriado.  
  
 Essas mensagens particulares do windows e estruturas de parâmetro associados forem declaradas no cabeçalho privadas “AFXPRIV.H” MFC.  Será avisado de que qualquer seu código que inclui o cabeçalho pode confiar no comportamento não documentado e interromper provavelmente em versões futuras de MFC.  
  
 Em casos raros necessidade de tratar uma dessas mensagens, você deve usar a macro da mensagem de `ON_MESSAGE` e tratar a mensagem no formato genérico de LRESULT\/WPARAM\/LPARAM.  
  
 **WM\_QUERYAFXWNDPROC**  
  
 Essa mensagem é enviada a uma janela que está sendo criada.  Isso é enviado muito no início do processo de criação como um método de determinar se o WndProc é retornará 1. **AfxWndProc.**de**AfxWndProc** .  
  
|||  
|-|-|  
|wParam|Não usado|  
|lParam|Não usado|  
|retorna|1 se processado por **AfxWndProc**|  
  
 **WM\_SIZEPARENT**  
  
 Essa mensagem é enviada por uma janela do quadro a seus filhos imediatos durante redimensionar \(**CFrameWnd::OnSize** chama `CFrameWnd::RecalcLayout` que chama `CWnd::RepositionBars`\) para reposicionar as barras de controle em torno do lado do quadro.  A estrutura de **AFX\_SIZEPARENTPARAMS** contém o retângulo disponível do cliente atual do pai e um HDWP \(que podem ser NULL\) para chamar com que `DeferWindowPos` para minimizar repintar.  
  
|||  
|-|-|  
|wParam|Não usado|  
|lParam|Endereço de uma estrutura de **AFX\_SIZEPARENTPARAMS**|  
|retorna|Não usado \(0\)|  
  
 Ignorar a mensagem indica que a janela não participa no layout.  
  
 **WM\_SETMESSAGESTRING**  
  
 Essa mensagem é enviada a uma janela do quadro para solicitar que atualiza a linha da mensagem na barra de status.  Uma ID de cadeia de caracteres ou um LPCSTR podem ser especificados \(mas não ambos\).  
  
|||  
|-|-|  
|wParam|ID da cadeia de caracteres \(ou zero\)|  
|lParam|LPCSTR para a cadeia de caracteres \(ou NULL\)|  
|retorna|Não usado \(0\)|  
  
 **WM\_IDLEUPDATECMDUI**  
  
 Essa mensagem é enviada no tempo ocioso implementar a atualização do tempo ocioso de manipuladores de interface de usuário de atualização comando.  Se a janela \(normalmente uma barra de controle\) controla a mensagem, cria um objeto de `CCmdUI` \(ou um objeto de uma classe derivada\) e chame **CCmdUI::DoUpdate** para cada um dos itens “” na janela.  Isso irá por sua vez para verificar se há um manipulador de `ON_UPDATE_COMMAND_UI` para os objetos na cadeia de comando\- manipulador.  
  
|||  
|-|-|  
|wParam|BDisableIfNoHandler de BOOL|  
|lParam|Não usado \(0\)|  
|retorna|Não usado \(0\)|  
  
 *o bDisableIfNoHandler* for diferente de zero desabilitar o objeto da interface do usuário se houver nem `ON_UPDATE_COMMAND_UI` nem um manipulador de `ON_COMMAND` .  
  
 **WM\_EXITHELPMODE**  
  
 Essa mensagem é postada em que `CFrameWnd` para sair do modo de ajuda contextual.  O recebimento da mensagem de término do loop modal iniciado por **CFrameWnd::OnContextHelp.**  
  
|||  
|-|-|  
|wParam|Não usado \(0\)|  
|lParam|Não usado \(0\)|  
|retorna|Não usado|  
  
 **WM\_INITIALUPDATE**  
  
 Essa mensagem será enviada pelo modelo de documento em todos os descendentes de uma janela do quadro quando é seguro para eles fazer a atualização inicial.  Mapeia a uma chamada a `CView::OnInitialUpdate` mas pode ser usada em outro `CWnd`\- classes derivadas para outro atualizar de uma captura.  
  
|||  
|-|-|  
|wParam|Não usado \(0\)|  
|lParam|Não usado \(0\)|  
|retorna|Não usado \(0\)|  
  
 **WM\_RECALCPARENT**  
  
 Essa mensagem é enviada por uma exibição à janela pai \(obtida por meio de `GetParent`\) para forçar um recálculo de layout \(geralmente, chamará o pai `RecalcLayout`\).  Isso é usado em aplicativos para servidores com OLE DB onde é necessário que o quadro cresça em tamanho como o tamanho total da exibição aumenta.  
  
 Se a janela pai processa esta mensagem deve retornar TRUE e preencher o RECT passado para o lParam com o novo tamanho da área do cliente.  Isso é usado em `CScrollView` para tratar corretamente as barras de rolagem \(local na parte externa na janela quando são adicionados\) quando um objeto de servidor é in\-loco ativado.  
  
|||  
|-|-|  
|wParam|Não usado \(0\)|  
|lParam|LPRECT rectClient, pode ser NULL|  
|retorna|Se RETIFIQUE novo cliente que o retângulo retornados, FALSE de outra forma|  
  
 **WM\_SIZECHILD**  
  
 Essa mensagem é enviada por `COleResizeBar` à janela do proprietário \(por meio de `GetOwner`\) quando o usuário redimensionar a barra redimensionar com as alças de redimensionamento.  `COleIPFrameWnd` responde a esta mensagem tentando reposicionar a janela do quadro como o usuário solicitou.  
  
 O novo retângulo, dado no cliente coordena em relação à janela do tableau que contém a barra redimensionar, é apontado por lParam.  
  
|||  
|-|-|  
|wParam|Não usado \(0\)|  
|lParam|RectNew de LPRECT|  
|retorna|Não usado \(0\)|  
  
 **WM\_DISABLEMODAL**  
  
 Essa mensagem é enviada a todos os janela pop\-up de propriedade de uma janela do tableau que está sendo desativada.  A janela do quadro usa o resultado para determinar se desabilitar a janela pop\-up.  
  
 Você pode usar isso para executar o processamento especial em seu janela pop\-up quando o quadro entrará em um estado modal ou mantenha determinados janela pop\-up de obter desabilitados.  Uso de Dicas essa mensagem destruir\-se quando a janela do quadro entrar em um estado modal, por exemplo.  
  
|||  
|-|-|  
|wParam|Não usado \(0\)|  
|lParam|Não usado \(0\)|  
|retorna|Diferente de zero para a desabilitação de **NOT** a janela, 0 indica que a janela será desabilitada|  
  
 **WM\_FLOATSTATUS**  
  
 Essa mensagem será enviada a todos os janela pop\-up de propriedade de uma janela do quadro quando o quadro é ativado ou desativado por outra janela de nível superior do quadro.  Isso é usado pela implementação de **MFS\_SYNCACTIVE** em `CMiniFrameWnd`, para manter a ativação desses janela pop\-up sincronizado com a ativação da janela de nível superior do quadro.  
  
|||  
|-|-|  
|wParam|É um dos seguintes valores:<br /><br /> **FS\_SHOW**<br /><br /> **FS\_HIDE**<br /><br /> **FS\_ACTIVATE**<br /><br /> **FS\_DEACTIVATE**<br /><br /> **FS\_ENABLEFS\_DISABLE**<br /><br /> **FS\_SYNCACTIVE**|  
|lParam|Não usado \(0\)|  
  
 O valor de retorno deve ser diferente de zero se **FS\_SYNCACTIVE** é ajustado e a janela syncronizes a ativação com o quadro pai.  retorna`CMiniFrameWnd` diferente de zero quando o estilo for definido como **MFS\_SYNCACTIVE.**  
  
 Para obter mais informações, veja a implementação de `CMiniFrameWnd`.  
  
## WM\_ACTIVATETOPLEVEL  
 Essa mensagem é enviada a uma janela de nível superior quando uma janela “no grupo de nível superior” é ativada ou desativada.  Uma janela é parte de um grupo de nível superior se for uma janela de nível superior \(nenhum pai ou proprietário\), ou pertence essa janela.  Essa mensagem é semelhante ao usar a **WM\_ACTIVATEAPP,** mas os trabalhos em situações em que as janelas que pertencem aos processos diferentes são combinadas em uma única hierarquia da janela \(comum em aplicativos OLE\).  
  
## WM\_COMMANDHELP, WM\_HELPHITTEST, WM\_EXITHELPMODE  
 Essas mensagens são usadas na implementação da ajuda contextual.  Consulte os [Observação 28 técnica](../mfc/tn028-context-sensitive-help-support.md) para obter mais informações.  
  
## Formatos privados do recurso de MFC  
 Atualmente, o MFC define dois formatos privados de recursos: **RT\_TOOLBAR** e **RT\_DLGINIT**.  
  
## Formato de recurso de RT\_TOOLBAR  
 A barra de ferramentas padrão fornecida por AppWizard é baseada em um recurso personalizado de **RT\_TOOLBAR** , que é apresentado em MFC 4,0.  Você poderá editar esse recurso que usa o editor da barra de ferramentas.  
  
## Formato de recurso de RT\_DLGINIT  
 Um formato privado do recurso de MFC é usado para armazenar informações de inicialização adicional da caixa de diálogo.  Isso inclui as cadeias de caracteres devem ser armazenadas em uma caixa de combinação.  O formato desse recurso não foi criado para ser editado manualmente, mas é tratado pelo Visual C\+\+.  
  
 Visual C\+\+ e esse recurso de **RT\_DLGINIT** não são necessários para usar os recursos relacionados MFC como há uma alternativa API como usar informações do recurso.  Usar o Visual C\+\+ facilita o escrever, manter, e converter a longo prazo seu aplicativo.  
  
 A estrutura básica de um recurso de **RT\_DLGINIT** é a seguinte:  
  
```  
+---------------+                    \  
| Control ID    |   UINT             |  
+---------------+                    |  
| Message #     |   UINT             |  
+---------------+                    |  
|length of data |   DWORD            |  
+---------------+                    |   Repeated  
|   Data        |   Variable Length  |   for each control  
|   ...         |   and Format       |   and message  
+---------------+                    /  
|     0         |   BYTE  
+---------------+  
```  
  
 Uma seção repetida contém a ID do controle para o qual enviar a mensagem, a mensagem \(\# para enviar uma mensagem normal do windows\) e um comprimento variável de dados.  A mensagem do windows é enviada em um formato:  
  
```  
SendDlgItemMessage(<Control ID>, <Message #>, 0, &<Data>);  
```  
  
 Este é um formato muito geral, permitindo todas as mensagens do windows e conteúdo de dados.  O editor de recursos do Visual C\+\+ e MFC o oferecem suporte apenas a um subconjunto limitado de mensagens do windows: CB\_ADDSTRING para as opções lista\- iniciais para caixas de combinação \(os dados são uma cadeia de caracteres de texto\).  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)