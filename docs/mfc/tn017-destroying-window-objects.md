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
ms.openlocfilehash: 8286622ec8e7cb739e55a39ce42ed658395551ba
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407667"
---
# <a name="tn017-destroying-window-objects"></a>TN017: destruindo objetos de janela

Essa observação descreve o uso do [CWnd::PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy) método. Use esse método se você quiser fazer alocação personalizada de `CWnd`-objetos derivados. Essa observação também explica por que você deve usar [CWnd::DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow) destruir um objeto de C++ Windows em vez da **excluir** operador.

Se você seguir as diretrizes neste tópico, você terá alguns problemas de limpeza. Esses problemas podem resultar de problemas, como esquecer de exclusão/liberar memória em C++, esquecer de liberar recursos do sistema, como `HWND`s ou liberando objetos muitas vezes.

## <a name="the-problem"></a>O problema

Cada objeto do windows (objeto de uma classe derivada de `CWnd`) representa um objeto do C++ e um `HWND`. Objetos de C++ são alocados no heap do aplicativo e `HWND`s são alocados em recursos do sistema pelo Gerenciador de janela. Como há várias maneiras para destruir um objeto de janela, podemos deve fornecer um conjunto de regras que impeçam o sistema vazamentos de memória ou de recursos. Essas regras devem também impedir que objetos e identificadores do Windows que está sendo destruído a mais de uma vez.

## <a name="destroying-windows"></a>Destruindo o Windows

A seguir estão as duas maneiras permitidas para destruir um objeto do Windows:

- Chamando `CWnd::DestroyWindow` ou o Windows API `DestroyWindow`.

- Excluindo explicitamente com o **excluir** operador.

O primeiro caso é de longe as mais comuns. Nesse caso, se aplica mesmo se seu código não chama `DestroyWindow` diretamente. Quando o usuário diretamente fecha uma janela de quadro, essa ação gera a mensagem WM_CLOSE e a resposta padrão para esta mensagem é chamar `DestroyWindow.` quando uma janela pai é destruída, o Windows chama `DestroyWindow` para todos os seus filhos.

O segundo caso, o uso do **excluir** operador em objetos do Windows, deve ser rara. A seguir estão alguns casos em que usar **excluir** é a opção correta.

## <a name="auto-cleanup-with-cwndpostncdestroy"></a>Limpeza automática com CWnd::PostNcDestroy

Quando o sistema destrói uma janela do Windows, a última mensagem do Windows enviada para a janela é WM_NCDESTROY. O padrão `CWnd` manipulador para a mensagem é [CWnd:: Onncdestroy](../mfc/reference/cwnd-class.md#onncdestroy). `OnNcDestroy` desanexar o `HWND` C++ de objeto e chamar a função virtual `PostNcDestroy`. Algumas classes substituem essa função para excluir o objeto de C++.

A implementação padrão de `CWnd::PostNcDestroy` não faz nada, que é apropriado para objetos de janela que são alocados no quadro de pilha ou inseridos em outros objetos. Isso não é adequado para objetos de janela que são projetados para ser alocado no heap sem quaisquer outros objetos. Em outras palavras, não é apropriado para objetos de janela que não são inseridos em outros objetos C++.

As classes que são projetadas para ser alocado sozinho no heap de substituem os `PostNcDestroy` método para executar um **excluir este**. Esta instrução será libera qualquer memória associada ao objeto C++. Embora o padrão `CWnd` chamadas de destruidor `DestroyWindow` se *m_hWnd* é não-nulo, isso não resulta em recursão infinita porque o identificador será desanexado e nulo durante a fase de limpeza.

> [!NOTE]
>  O sistema normalmente chama `CWnd::PostNcDestroy` depois que ele processa a mensagem do Windows WM_NCDESTROY e o `HWND` e o objeto de janela C++ não estiver mais conectado. O sistema também chamará `CWnd::PostNcDestroy` na implementação da maioria [CWnd::Create](../mfc/reference/cwnd-class.md#create) chama se ocorrer falha. As regras de limpeza automática são descritas neste tópico.

## <a name="auto-cleanup-classes"></a>Classes de limpeza automática

As classes a seguir não são projetadas para limpeza automática. Normalmente, eles são inseridos em outros objetos C++ ou na pilha:

- Todos os controles padrão do Windows (`CStatic`, `CEdit`, `CListBox`e assim por diante).

- Todas as janelas filho derivam diretamente de `CWnd` (por exemplo, controles personalizados).

- Janelas separadoras (`CSplitterWnd`).

- Padrão de barras de controle (as classes derivadas `CControlBar`, consulte [31 de observação técnica](../mfc/tn031-control-bars.md) para habilitar a exclusão automática de objetos de controle de barra).

- Caixas de diálogo (`CDialog`) projetado para caixas de diálogo modais no quadro da pilha.

- O padrão todas as caixas de diálogo, exceto `CFindReplaceDialog`.

- As caixas de diálogo padrão criadas pelo ClassWizard.

As classes a seguir destinam-se a limpeza automática. Normalmente, eles são alocados por si mesmos no heap:

- Janelas de quadro principal (derivado direta ou indiretamente de `CFrameWnd`).

- Exibir as janelas (derivado direta ou indiretamente de `CView`).

Se você deseja interromper a essas regras, você deve substituir o `PostNcDestroy` método em sua classe derivada. Para adicionar a limpeza automática à sua classe, chame sua classe base e, em seguida, fazer uma **excluir este**. Para remover a limpeza automática de sua classe, chame `CWnd::PostNcDestroy` diretamente em vez do `PostNcDestroy` método de sua classe base direta.

O uso mais comum de alterar o comportamento de limpeza automática é criar uma caixa de diálogo sem janela restrita que pode ser alocada no heap.

## <a name="when-to-call-delete"></a>Quando a chamada de exclusão

É recomendável que você chame `DestroyWindow` destruir um objeto do Windows, o método do C++ ou global `DestroyWindow` API.

Não chame global `DestroyWindow` API para destruir uma janela filho MDI. Você deve usar o método virtual `CWnd::DestroyWindow` em vez disso.

Para objetos de janela C++ que não executam limpeza automática, usando o **exclua** operador pode causar um vazamento de memória quando você tentar chamar `DestroyWindow` no `CWnd::~CWnd` destruidor se VTBL não apontar para a classe derivada corretamente. Isso ocorre porque o sistema não localizou que apropriada destruir o método a ser chamado. Usando o `DestroyWindow` em vez de **excluir** evita esses problemas. Como isso pode ser um erro sutil, a compilação no modo de depuração gerará o seguinte aviso se estão em risco.

```
Warning: calling DestroyWindow in CWnd::~CWnd
    OnDestroy or PostNcDestroy in derived class will not be called
```

No caso de objetos do Windows C++ que executar a limpeza automática, você deve chamar `DestroyWindow`. Se você usar o **excluir** operador diretamente, o alocador de diagnóstico de memória do MFC avisará que você estiver liberando memória duas vezes. As duas ocorrências são sua primeira chamada explícita e a chamada indireta **excluir esta** na implementação de limpeza automática de `PostNcDestroy`.

Depois de chamar `DestroyWindow` em um objeto de limpeza não automática, o objeto de C++ ainda estará em torno de, mas *m_hWnd* será NULL. Depois de chamar `DestroyWindow` em um objeto de limpeza automática, o objeto de C++ desaparecerão, liberado pelo operador delete C++ na implementação de limpeza automática de `PostNcDestroy`.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

