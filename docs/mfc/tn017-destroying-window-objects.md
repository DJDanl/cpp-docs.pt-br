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
ms.openlocfilehash: 9802669468cbbba89f23b8ac127358d1fc15ec9f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370418"
---
# <a name="tn017-destroying-window-objects"></a>TN017: destruindo objetos de janela

Esta nota descreve o uso do método [CWnd::PostNcDestroy.](../mfc/reference/cwnd-class.md#postncdestroy) Use este método se quiser fazer `CWnd`alocação personalizada de objetos derivados. Esta nota também explica por que você deve usar [CWnd::DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow) para destruir um objeto C++ Windows em vez do operador **de exclusão.**

Se você seguir as diretrizes neste tópico, você terá poucos problemas de limpeza. Esses problemas podem resultar de problemas como esquecer de excluir/liberar a memória `HWND`C++, esquecer de liberar recursos do sistema como s ou liberar objetos muitas vezes.

## <a name="the-problem"></a>O problema

Cada objeto de janelas (objeto `CWnd`de uma classe derivada) representa `HWND`tanto um objeto C++ quanto um . Os objetos C++ são alocados `HWND`no heap do aplicativo e s são alocados em recursos do sistema pelo gerenciador de janelas. Como existem várias maneiras de destruir um objeto de janela, devemos fornecer um conjunto de regras que impedem vazamentos de recursos ou memória do sistema. Essas regras também devem impedir que objetos e alças do Windows sejam destruídos mais de uma vez.

## <a name="destroying-windows"></a>Destruindo o Windows

A seguir estão as duas maneiras permitidas de destruir um objeto do Windows:

- Chamando `CWnd::DestroyWindow` ou a `DestroyWindow`API do Windows .

- Excluindo explicitamente com o operador **de exclusão.**

O primeiro caso é de longe o mais comum. Este caso se aplica mesmo que `DestroyWindow` seu código não ligue diretamente. Quando o usuário fecha diretamente uma janela de quadro, essa ação gera a `DestroyWindow.` mensagem WM_CLOSE e a resposta `DestroyWindow` padrão a esta mensagem é ligar Quando uma janela pai é destruída, o Windows chama todos os seus filhos.

O segundo caso, o uso do operador de **exclusão** em objetos do Windows, deve ser raro. A seguir, alguns casos em que o uso de **exclusão** é a escolha correta.

## <a name="auto-cleanup-with-cwndpostncdestroy"></a>Limpeza automática com CWnd::PostNcDestroy

Quando o sistema destrói uma janela do Windows, a última mensagem do Windows enviada para a janela é WM_NCDESTROY. O `CWnd` manipulador padrão dessa mensagem é [CWnd::OnNcDestroy](../mfc/reference/cwnd-class.md#onncdestroy). `OnNcDestroy`irá separar `HWND` o objeto C++ e chamar `PostNcDestroy`a função virtual . Algumas classes anulam essa função para excluir o objeto C++.

A implementação `CWnd::PostNcDestroy` padrão de não faz nada, o que é apropriado para objetos de janela que são alocados no quadro de pilha ou incorporados em outros objetos. Isso não é apropriado para objetos de janela que foram projetados para serem alocados no heap sem outros objetos. Em outras palavras, não é apropriado para objetos de janela que não estão incorporados em outros objetos C++.

As classes projetadas para serem alocadas sozinhas `PostNcDestroy` no heap sobrepõem o método para executar uma **exclusão disso**. Esta declaração liberará qualquer memória associada ao objeto C++. Mesmo que `CWnd` o destructor padrão chame `DestroyWindow` se *m_hWnd* não for NULA, isso não leva a uma recursão infinita porque a alça será separada e NULL durante a fase de limpeza.

> [!NOTE]
> O sistema `CWnd::PostNcDestroy` geralmente liga depois de processá-lo o Windows WM_NCDESTROY mensagem e o `HWND` objeto da janela C++ não está mais conectado. O sistema também `CWnd::PostNcDestroy` chamará a implementação da maioria das chamadas [CWnd::Criar](../mfc/reference/cwnd-class.md#create) se ocorrer falha. As regras de limpeza automática são descritas mais tarde neste tópico.

## <a name="auto-cleanup-classes"></a>Aulas de Limpeza Automática

As seguintes classes não foram projetadas para limpeza automática. Eles são tipicamente incorporados em outros objetos C++ ou na pilha:

- Todos os controles`CStatic`padrão `CEdit` `CListBox`do Windows (, , e assim por diante).

- Quaisquer janelas de crianças derivadas diretamente (por `CWnd` exemplo, controles personalizados).

- Janelas de`CSplitterWnd`divisor ().

- Barras de controle padrão `CControlBar`(classes derivadas de , consulte [Nota Técnica 31](../mfc/tn031-control-bars.md) para habilitar a exclusão automática para objetos de barra de controle).

- Diálogos`CDialog`( ) projetadopara diálogos modais no quadro de pilha.

- Todos os diálogos `CFindReplaceDialog`padrão, exceto .

- As diálogos padrão criados pelo ClassWizard.

As seguintes classes são projetadas para limpeza automática. Eles são tipicamente alocados por si mesmos na pilha:

- Janelas de quadro principal (derivadas `CFrameWnd`direta ou indiretamente de ).

- Exibir janelas (derivadas direta `CView`ou indiretamente de ).

Se você quiser quebrar essas regras, `PostNcDestroy` você deve substituir o método em sua classe derivada. Para adicionar limpeza automática à sua classe, ligue para sua classe base e, em seguida, faça uma **exclusão disso**. Para remover a limpeza automática da `CWnd::PostNcDestroy` sua classe, ligue diretamente em vez do `PostNcDestroy` método da sua classe base direta.

O uso mais comum de alterar o comportamento de limpeza automática é criar uma caixa de diálogo modeless que pode ser alocada no heap.

## <a name="when-to-call-delete"></a>Quando chamar excluir

Recomendamos que `DestroyWindow` você ligue para destruir um objeto do Windows, seja o método C++ ou a API global. `DestroyWindow`

Não chame a `DestroyWindow` API global para destruir uma janela MDI Child. Em vez disso, `CWnd::DestroyWindow` você deve usar o método virtual.

Para objetos de janela C++ que não executam a limpeza automática, o `DestroyWindow` uso `CWnd::~CWnd` do operador **de exclusão** pode causar um vazamento de memória quando você tentar chamar o destruidor se o VTBL não apontar para a classe derivada corretamente. Isso ocorre porque o sistema não encontra o método de destruição apropriado para chamar. Usar `DestroyWindow` em vez de **excluir** evita esses problemas. Como isso pode ser um erro sutil, compilar no modo de depuração gerará o seguinte aviso se você estiver em risco.

```
Warning: calling DestroyWindow in CWnd::~CWnd
    OnDestroy or PostNcDestroy in derived class will not be called
```

No caso de objetos C++ Windows que realizam a `DestroyWindow`limpeza automática, você deve chamar . Se você usar o operador **de exclusão** diretamente, o alocador de memória diagnóstica do MFC irá notificá-lo de que você está liberando a memória duas vezes. As duas ocorrências são sua primeira chamada explícita e a chamada indireta para **excluí-la** na implementação de limpeza automática de `PostNcDestroy`.

Depois `DestroyWindow` de chamar um objeto de limpeza não automática, o objeto C++ ainda estará por perto, mas *m_hWnd* será NULL. Depois `DestroyWindow` de chamar um objeto de limpeza automática, o objeto C++ desaparecerá, liberado pelo operador `PostNcDestroy`de exclusão C++ na implementação de limpeza automática de .

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
