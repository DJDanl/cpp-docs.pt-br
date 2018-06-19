---
title: 'TN017: Destruindo objetos de janela | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.objects
dev_langs:
- C++
helpviewer_keywords:
- destroying windows
- TN017
- PostNcDestroy method [MFC]
ms.assetid: 5bf208a5-5683-439b-92a1-547c5ded26cd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c6bba255403d31e7a1fa03febb0c760d20cdc81c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33384297"
---
# <a name="tn017-destroying-window-objects"></a>TN017: destruindo objetos de janela
Esta anotação descreve o uso do [CWnd::PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy) método. Use este método se você deseja fazer alocação personalizada de `CWnd`-objetos derivados. Esta anotação também explica por que você deve usar [CWnd::DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow) destruir um objeto C++ do Windows em vez do `delete` operador.  
  
 Se você seguir as diretrizes neste tópico, você terá alguns problemas de limpeza. Esses problemas podem resultar de problemas, como esquecer de exclusão/liberar memória C++, esquecer de liberar recursos do sistema como `HWND`s ou liberando objetos muitas vezes.  
  
## <a name="the-problem"></a>O problema  
 Cada objeto do windows (objeto de uma classe derivada de `CWnd`) representa um objeto de C++ ambos e um `HWND`. Objetos C++ são alocados no heap do aplicativo e `HWND`s recursos do sistema são alocados pelo Gerenciador de janela. Como há várias maneiras de destruir um objeto de janela, devemos fornecer um conjunto de regras que impeçam o sistema vazamentos de memória ou recursos. Essas regras devem também impedir que objetos e identificadores do Windows que está sendo destruído a mais de uma vez.  
  
## <a name="destroying-windows"></a>Destruindo janelas  
 Esses são os dois modos permitidos de destruir um objeto do Windows:  
  
-   Chamando `CWnd::DestroyWindow` ou a API do Windows `DestroyWindow`.  
  
-   Excluindo explicitamente com o `delete` operador.  
  
 O primeiro caso é de longe as mais comuns. Nesse caso se aplica mesmo se seu código não chamar `DestroyWindow` diretamente. Quando o usuário diretamente fecha uma janela do quadro, essa ação gera o `WM_CLOSE` mensagem e a resposta padrão para esta mensagem é chamar `DestroyWindow.` quando uma janela pai é destruída, o Windows chama `DestroyWindow` para todos os seus filhos.  
  
 O segundo caso, o uso do `delete` operador em objetos do Windows, devem ser raros. A seguir estão alguns casos em que usar `delete` é a opção correta.  
  
## <a name="auto-cleanup-with-cwndpostncdestroy"></a>Limpeza automática com CWnd::PostNcDestroy  
 Quando o sistema destruir uma janela do Windows, a última mensagem de Windows enviada para a janela é `WM_NCDESTROY`. O padrão `CWnd` manipulador para essa mensagem é [CWnd::OnNcDestroy](../mfc/reference/cwnd-class.md#onncdestroy). `OnNcDestroy` desanexará o `HWND` de C++ de objeto e chamar a função virtual `PostNcDestroy`. Algumas classes substituem essa função para excluir o objeto de C++.  
  
 A implementação padrão de `CWnd::PostNcDestroy` não faz nada, que é apropriado para os objetos de janela que estão alocados no quadro de pilha ou inseridos em outros objetos. Isso não é adequado para objetos de janela que são projetados para ser alocado no heap sem qualquer outro objeto. Em outras palavras, não é apropriado para os objetos de janela que não são inseridos em outros objetos C++.  
  
 As classes que são projetadas para ser alocado sozinho no heap substituem o `PostNcDestroy` método para executar um `delete this`. Essa instrução irá liberar qualquer memória associada ao objeto de C++. Embora o padrão `CWnd` chamadas de destruidor `DestroyWindow` se `m_hWnd` é não nulo, isso não levar a recursão infinita porque o identificador será desanexado e nulo durante a fase de limpeza.  
  
> [!NOTE]
>  O sistema normalmente chama `CWnd::PostNcDestroy` depois que ele processa as janelas `WM_NCDESTROY` mensagem e o `HWND` e o objeto de janela C++ não está mais conectado. O sistema também chamará `CWnd::PostNcDestroy` na implementação da maioria [CWnd::Create](../mfc/reference/cwnd-class.md#create) chama se ocorrer falha. As regras de limpeza automática são descritas neste tópico.  
  
## <a name="auto-cleanup-classes"></a>Classes de limpeza automática  
 As classes a seguir não são projetadas para a limpeza automática. Normalmente, eles são inseridos em outros objetos C++ ou na pilha:  
  
-   Todos os controles padrão do Windows (`CStatic`, `CEdit`, `CListBox`e assim por diante).  
  
-   Todas as janelas filho derivam diretamente do `CWnd` (por exemplo, controles personalizados).  
  
-   Janelas separadoras (`CSplitterWnd`).  
  
-   Padrão de barras de controle (classes derivadas de `CControlBar`, consulte [31 de observação técnica](../mfc/tn031-control-bars.md) para habilitar a exclusão automática de objetos da barra de controle).  
  
-   Caixas de diálogo (`CDialog`) projetado para caixas de diálogo modais no quadro de pilha.  
  
-   O padrão todas as caixas de diálogo exceto `CFindReplaceDialog`.  
  
-   As caixas de diálogo padrão criadas pelo ClassWizard.  
  
 As classes a seguir destinam-se a limpeza automática. Normalmente, eles são alocados por si mesmos no heap:  
  
-   Janelas de quadro principal (derivado direta ou indiretamente de `CFrameWnd`).  
  
-   Exibir janelas (derivado direta ou indiretamente de `CView`).  
  
 Se você deseja desfazer essas regras, você deve substituir o `PostNcDestroy` método na classe derivada. Para adicionar a limpeza automática para sua classe, chame a classe base e, em seguida, fazer uma `delete this`. Para remover a limpeza automática de sua classe, chame `CWnd::PostNcDestroy` diretamente em vez do `PostNcDestroy` método de sua classe base direta.  
  
 O uso mais comum de alterar o comportamento de limpeza automática é criar uma caixa de diálogo sem janela restrita que pode ser alocada no heap.  
  
## <a name="when-to-call-delete"></a>Quando a chamada de exclusão  
 É recomendável que você chamar `DestroyWindow` destruir um objeto do Windows, o método do C++ ou global `DestroyWindow` API.  
  
 Não chame global `DestroyWindow` API para destruir uma janela filho MDI. Você deve usar o método virtual `CWnd::DestroyWindow` em vez disso.  
  
 Para objetos de janela do C++ que não executam a limpeza automática, usando o `delete` operador pode causar um vazamento de memória quando você tentar chamar `DestroyWindow` no `CWnd::~CWnd` destruidor se o VTBL não aponta para a classe derivada corretamente. Isso ocorre porque o sistema não é possível localizar o que método chamar destroy apropriada. Usando `DestroyWindow` em vez de `delete` evita esses problemas. Como isso pode ser um erro sutil, compilação no modo de depuração irá gerar o seguinte aviso se você está em risco.  
  
```  
Warning: calling DestroyWindow in CWnd::~CWnd  
    OnDestroy or PostNcDestroy in derived class will not be called  
```  
  
 No caso de objetos do Windows do C++ que executar a limpeza automática, você deve chamar `DestroyWindow`. Se você usar o `delete` operador diretamente, o alocador de diagnóstico de memória do MFC avisará que você está liberando memória duas vezes. As duas ocorrências são a primeira chamada explícita e a chamada indireta para `delete this` na implementação a limpeza automática de `PostNcDestroy`.  
  
 Depois de chamar `DestroyWindow` em um objeto de limpeza não automática, o objeto C++ continuará, mas `m_hWnd` será NULL. Depois de chamar `DestroyWindow` em um objeto de limpeza automática, o objeto C++ serão excluído, liberada pelo operador delete C++ na implementação a limpeza automática de `PostNcDestroy`.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

