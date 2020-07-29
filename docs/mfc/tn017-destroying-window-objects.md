---
title: 'TN017: destruindo objetos de janela'
ms.date: 11/04/2016
f1_keywords:
- vc.objects
helpviewer_keywords:
- destroying windows
- TN017
- PostNcDestroy method [MFC]
ms.assetid: 5bf208a5-5683-439b-92a1-547c5ded26cd
ms.openlocfilehash: 2448a2661851f14fc6fe8747ca19495925442436
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226809"
---
# <a name="tn017-destroying-window-objects"></a>TN017: destruindo objetos de janela

Esta observação descreve o uso do método [CWnd::P ostncdestroy](../mfc/reference/cwnd-class.md#postncdestroy) . Use esse método se desejar fazer a alocação personalizada de `CWnd` objetos derivados. Esta observação também explica por que você deve usar [CWnd::D estroywindow](../mfc/reference/cwnd-class.md#destroywindow) para destruir um objeto C++ do Windows em vez do **`delete`** operador.

Se você seguir as diretrizes neste tópico, terá poucos problemas de limpeza. Esses problemas podem resultar de problemas como esquecer de excluir/liberar memória C++, esquecer de liberar recursos do sistema como `HWND` s ou liberar objetos muitas vezes.

## <a name="the-problem"></a>O problema

Cada objeto do Windows (objeto de uma classe derivada de `CWnd` ) representa um objeto C++ e um `HWND` . Os objetos C++ são alocados no heap do aplicativo e `HWND` os s são alocados em recursos do sistema pelo Gerenciador de janelas. Como há várias maneiras de destruir um objeto Window, devemos fornecer um conjunto de regras que impedem vazamentos de memória ou recursos do sistema. Essas regras também devem impedir que objetos e identificadores do Windows sejam destruídos mais de uma vez.

## <a name="destroying-windows"></a>Destruindo o Windows

A seguir estão as duas maneiras permitidas de destruir um objeto do Windows:

- Chamando `CWnd::DestroyWindow` o ou a API do Windows `DestroyWindow` .

- Excluindo explicitamente com o **`delete`** operador.

O primeiro caso é de longe o mais comum. Esse caso se aplica mesmo que seu código não chame `DestroyWindow` diretamente. Quando o usuário fecha diretamente uma janela de quadro, essa ação gera a WM_CLOSE mensagem e a resposta padrão a essa mensagem é chamar `DestroyWindow.` quando uma janela pai é destruída, o Windows chama `DestroyWindow` para todos os seus filhos.

O segundo caso, o uso do **`delete`** operador em objetos do Windows, deve ser raro. A seguir estão alguns casos em que **`delete`** o uso do é a opção correta.

## <a name="auto-cleanup-with-cwndpostncdestroy"></a>Limpeza automática com CWnd::P ostNcDestroy

Quando o sistema destrói uma janela do Windows, a última mensagem do Windows enviada para a janela é WM_NCDESTROY. O `CWnd` manipulador padrão para essa mensagem é [CWnd:: OnNcDestroy](../mfc/reference/cwnd-class.md#onncdestroy). `OnNcDestroy`desanexará o `HWND` do objeto C++ e chamará a função virtual `PostNcDestroy` . Algumas classes substituem essa função para excluir o objeto C++.

A implementação padrão de `CWnd::PostNcDestroy` não faz nada, que é apropriado para objetos de janela que são alocados no quadro de pilha ou inseridos em outros objetos. Isso não é apropriado para objetos de janela que são projetados para serem alocados no heap sem nenhum outro objeto. Em outras palavras, não é apropriado para objetos de janela que não estão inseridos em outros objetos C++.

Essas classes que são projetadas para serem alocadas sozinhas no heap substituem o `PostNcDestroy` método para executar uma **exclusão**. Essa instrução liberará qualquer memória associada ao objeto C++. Embora o `CWnd` destruidor padrão chame `DestroyWindow` se *M_HWND* não é nulo, isso não levará à recursão infinita porque o identificador será desanexado e nulo durante a fase de limpeza.

> [!NOTE]
> O sistema geralmente chama `CWnd::PostNcDestroy` depois de processar a mensagem do Windows WM_NCDESTROY e o `HWND` e o objeto de janela C++ não estão mais conectados. O sistema também chamará `CWnd::PostNcDestroy` na implementação da maioria das chamadas [CWnd:: Create](../mfc/reference/cwnd-class.md#create) se ocorrer uma falha. As regras de limpeza automática são descritas posteriormente neste tópico.

## <a name="auto-cleanup-classes"></a>Limpar classes automaticamente

As classes a seguir não foram projetadas para limpeza automática. Normalmente, eles são inseridos em outros objetos C++ ou na pilha:

- Todos os controles padrão do Windows ( `CStatic` ,, `CEdit` `CListBox` e assim por diante).

- Qualquer Windows filho derivado diretamente de `CWnd` (por exemplo, controles personalizados).

- Janelas de divisão ( `CSplitterWnd` ).

- Barras de controle padrão (classes derivadas de `CControlBar` , consulte a [Nota técnica 31](../mfc/tn031-control-bars.md) para habilitar a exclusão automática para objetos de barra de controle).

- Caixas de diálogo ( `CDialog` ) projetadas para caixas de diálogo modais no quadro de pilhas.

- Todas as caixas de diálogo padrão, exceto `CFindReplaceDialog` .

- As caixas de diálogo padrão criadas por ClassWizard.

As classes a seguir foram projetadas para limpeza automática. Normalmente, eles são alocados por si mesmos no heap:

- Janelas de quadro principal (derivadas direta ou indiretamente do `CFrameWnd` ).

- Exibir janelas (derivadas direta ou indiretamente do `CView` ).

Se você quiser interromper essas regras, você deve substituir o `PostNcDestroy` método em sua classe derivada. Para adicionar a limpeza automática à sua classe, chame sua classe base e, em seguida, faça uma **exclusão**. Para remover a limpeza automática de sua classe, chame `CWnd::PostNcDestroy` diretamente em vez do `PostNcDestroy` método de sua classe base direta.

O uso mais comum de alterar o comportamento de limpeza automática é criar uma caixa de diálogo sem janela restrita que possa ser alocada no heap.

## <a name="when-to-call-delete"></a>Quando chamar Delete

Recomendamos que você chame `DestroyWindow` para destruir um objeto do Windows, o método C++ ou a `DestroyWindow` API global.

Não chame a API global `DestroyWindow` para destruir uma janela filho MDI. Em vez disso, você deve usar o método virtual `CWnd::DestroyWindow` .

Para objetos de janela C++ que não executam a limpeza automática, usar o **`delete`** operador pode causar um vazamento de memória quando você tenta chamar `DestroyWindow` no `CWnd::~CWnd` destruidor se o VTBL não apontar para a classe derivada corretamente. Isso ocorre porque o sistema não pode encontrar o método Destroy apropriado para chamar. Usar `DestroyWindow` em vez de **`delete`** evitar esses problemas. Como esse pode ser um erro sutil, a compilação no modo de depuração gerará o seguinte aviso se você estiver em risco.

```
Warning: calling DestroyWindow in CWnd::~CWnd
    OnDestroy or PostNcDestroy in derived class will not be called
```

No caso de objetos C++ do Windows que executam a limpeza automática, você deve chamar `DestroyWindow` . Se você usar o **`delete`** operador diretamente, o alocador de memória de diagnóstico do MFC o notificará de que você está liberando a memória duas vezes. As duas ocorrências são sua primeira chamada explícita e a chamada indireta para **excluí-la** na implementação de limpeza automática do `PostNcDestroy` .

Depois de chamar `DestroyWindow` em um objeto de limpeza não automática, o objeto C++ ainda estará disponível, mas *M_HWND* será NULL. Depois de chamar `DestroyWindow` em um objeto de limpeza automática, o objeto c++ será removido, liberado pelo operador de exclusão de c++ na implementação de limpeza automática do `PostNcDestroy` .

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)
