---
title: "TN017: destruindo objetos de janela | Microsoft Docs"
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
  - "vc.objects"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "destruindo janelas"
  - "Método PostNcDestroy"
  - "TN017"
ms.assetid: 5bf208a5-5683-439b-92a1-547c5ded26cd
caps.latest.revision: 15
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN017: destruindo objetos de janela
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve o uso do método de [CWnd::PostNcDestroy](../Topic/CWnd::PostNcDestroy.md) .  Use este método se você deseja fazer a alocação personalizado de `CWnd`\- objetos derivados.  Essa observe também explica como você deve usar [CWnd::DestroyWindow](../Topic/CWnd::DestroyWindow.md) destruir o windows para c criando objetos em vez do operador de `delete` .  
  
 Se você siga as diretrizes deste tópico, você terá alguns problemas de limpeza.  Esses problemas podem resultar de problemas como o esquecimento excluir\/memória livre C\+\+, o esquecimento liberar recursos do sistema como `HWND`s, ou liberar objetos muitas vezes.  
  
## O problema  
 Cada objeto do windows \(objeto de uma classe derivada de ambos os `CWnd`\) representa o objeto c criando e `HWND`.  Os objetos C\+\+ são atribuídos no heap de aplicativo e `HWND`s é atribuído nos recursos do sistema pelo gerenciador de janela.  Como há várias maneiras de destruir um objeto da janela, devemos fornecer um conjunto de regras que impedem o recurso do sistema ou os possíveis vazamentos de memória.  Essas regras também devem evitar que os objetos e as alças do windows serem destruídos mais de uma vez.  
  
## Janelas de destruição  
 Os seguintes são as duas maneiras permitidas de destruir um objeto do windows:  
  
-   `CWnd::DestroyWindow` chamada ou a API do windows `DestroyWindow`.  
  
-   Excluindo explicitamente com o operador de `delete` .  
  
 Os primeiros casos são muito mais comuns.  Esses casos se aplicam mesmo se seu código não chama `DestroyWindow` diretamente.  Quando o usuário fecha diretamente uma janela do quadro, essa ação gerencia a mensagem de `WM_CLOSE` , e a resposta padrão para esta mensagem é chamar `DestroyWindow.` quando uma janela pai é destruída o windows, chama `DestroyWindow` para todos os seus filhos.  
  
 Os segundos casos, o uso do operador de `delete` no objeto, devem ser raros.  Estes são alguns casos em que são `delete` usando a opção correta.  
  
## Auto clean\-up com CWnd::PostNcDestroy  
 Quando o sistema destrói uma janela do windows, a última mensagem do enviada à janela é `WM_NCDESTROY`.  O manipulador de `CWnd` padrão para essa mensagem é [CWnd::OnNcDestroy](../Topic/CWnd::OnNcDestroy.md).  `OnNcDestroy` desanexará `HWND` do objeto C\+\+ e chamará a função `PostNcDestroy`virtual.  Algumas classes substituem essa função para excluir o objeto C\+\+.  
  
 A implementação padrão de `CWnd::PostNcDestroy` não fará nada, que é apropriado para os objetos da janela que são atribuídos no quadro de pilhas ou inseridos em outros objetos.  Isso não é apropriado para os objetos da janela que são criados para serem alocados no heap sem nenhum outros objetos.  Em outras palavras não é apropriado para os objetos da janela que não são inseridos em outros objetos C\+\+.  
  
 Essas classes que são projetadas para serem atribuídas na substituição de heap o método de `PostNcDestroy` para executar `delete this`.  Essa instrução liberará toda a memória associada ao objeto C\+\+.  Mesmo que o destruidor de `CWnd` da opção exige `DestroyWindow``m_hWnd` se for não NULL, isso não resulta na recursão infinita como o identificador será NULL e desanexada durante a fase de limpeza.  
  
> [!NOTE]
>  O sistema chama em geral `CWnd::PostNcDestroy` depois que processa a mensagem de `WM_NCDESTROY` do windows e `HWND` e o objeto da janela C\+\+ está conectado não.  O sistema também chamará `CWnd::PostNcDestroy` na implementação da maioria das chamadas de [CWnd::Create](../Topic/CWnd::Create.md) se a falha.  As regras de limpeza automática são descritas posteriormente neste tópico.  
  
## Classes de limpeza automática  
 As classes a seguir não são criadas para a limpeza automática.  Normalmente são inseridos em outros objetos C\+\+ ou na pilha:  
  
-   Todos os controles do windows \(padrão de`CStatic`, `CEdit`, `CListBox`, e assim por diante\).  
  
-   Algumas janelas filho derivadas diretamente de `CWnd` \(por exemplo, controla personalizados\).  
  
-   Janelas de divisão \(`CSplitterWnd`\).  
  
-   Barras de controle padrão \(classes derivadas de `CControlBar`, consulte [Observação 31 técnica](../mfc/tn031-control-bars.md) para habilitar o automaticamente DELETE para objetos da barra de controle\).  
  
-   Caixas de diálogo \(`CDialog`\) criado para caixas de diálogo modais no quadro de pilha.  
  
-   Todas as caixas de diálogo do padrão exceptuam `CFindReplaceDialog`.  
  
-   As caixas de diálogo padrão criadas por ClassWizard.  
  
 As classes a seguir são criadas para a limpeza automática.  São atribuídos normalmente específica no heap:  
  
-   Janelas de quadro principal \(derivadas diretamente ou indiretamente de `CFrameWnd`\).  
  
-   Janelas de exibição \(derivadas diretamente ou indiretamente de `CView`\).  
  
 Para interromper essas regras, você deve substituir o método de `PostNcDestroy` em sua classe derivada.  Para adicionar a limpeza automática a sua classe, chame a sua classe base e faça `delete this`.  Para remover a limpeza automática da sua classe, chame `CWnd::PostNcDestroy` diretamente em vez do método de `PostNcDestroy` da sua classe base direta.  
  
 O uso mais comum de alterar o comportamento automático de limpeza é criar uma caixa de diálogo modeless que pode ser atribuída no heap.  
  
## Quando chamar a exclusão  
 Recomendamos que você chama `DestroyWindow` para destruir um objeto do windows, o método C\+\+ ou `DestroyWindow` global API.  
  
 Não chame `DestroyWindow` global API para destruição uma janela filho MDI.  Você deve usar o método virtual `CWnd::DestroyWindow` em vez disso.  
  
 Para os objetos da janela C\+\+ que não executam a limpeza automática, usar o operador de `delete` pode causar um vazamento de memória quando você tentar chamar `DestroyWindow` em destruidor de `CWnd::~CWnd` se o VTBL não aponta corretamente a classe derivada.  Isso ocorre porque o sistema não pôde localizar o apropriado destrói o método para chamar.  Usar `DestroyWindow` em vez de `delete` evitar esses problemas.  Como esse pode ser um erro sutil, compile no modo de depuração gerará o seguinte aviso se você está em risco.  
  
```  
Warning: calling DestroyWindow in CWnd::~CWnd  
   OnDestroy or PostNcDestroy in derived class will not be called  
```  
  
 No caso de objetos do windows C\+\+ que executa a limpeza automática, você deve chamar `DestroyWindow`.  Se você usar o operador de `delete` diretamente, o alocador de diagnóstico de memória MFC notificá\-lo\-á que você está liberando memória duas vezes em.  As duas ocorrências são seu primeiro chamada explícita e a chamada indireto a `delete this` na implementação de limpeza automática de `PostNcDestroy`.  
  
 Depois de chamar `DestroyWindow` em um objeto de não\-automóvel\- limpeza, o objeto do C\+\+ ainda estará em relação a, mas `m_hWnd` será NULL.  Depois de chamar `DestroyWindow` em um objeto de limpeza automática, o objeto será C\+\+ ido, liberado pelo operador delete C\+\+ na implementação de limpeza automática de `PostNcDestroy`.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)