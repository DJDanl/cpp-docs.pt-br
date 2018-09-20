---
title: 'TN003: Mapeamento de Windows identificadores para objetos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mapping
dev_langs:
- C++
helpviewer_keywords:
- TN003
- handle maps
- Windows handles to objects [MFC]
- mappings [MFC], Windows handles to objects
ms.assetid: fbea9f38-992c-4091-8dbc-f29e288617d6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 38381583f06e145de8edd256416c4cb1b3378f85
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46383578"
---
# <a name="tn003-mapping-of-windows-handles-to-objects"></a>TN003: mapeamento de identificadores do Windows para objetos

Essa observação descreve o MFC rotinas que dão suporte a mapeamento Windows identificadores para objetos C++ do objeto.

## <a name="the-problem"></a>O problema

Objetos do Windows normalmente são representados por vários [MANIPULAR](/windows/desktop/WinProg/windows-data-types) objetos de classes do MFC a encapsulam identificadores de objeto do Windows com objetos C++. O identificador de quebra automática de funções da biblioteca de classes MFC permitem que você localizar o objeto de C++ que está encapsulando o objeto do Windows que tem um identificador específico. No entanto, às vezes, um objeto não tem um objeto de wrapper do C++ e nesses momentos, o sistema cria um objeto temporário para atuar como um wrapper em C++.

Os objetos do Windows que usam mapas de identificador são da seguinte maneira:

- HWND ([CWnd](../mfc/reference/cwnd-class.md) e `CWnd`-as classes derivadas)

- HDC ([CDC](../mfc/reference/cdc-class.md) e `CDC`-as classes derivadas)

- HMENU ([CMenu](../mfc/reference/cmenu-class.md))

- HPEN ([CGdiObject](../mfc/reference/cgdiobject-class.md))

- HBRUSH (`CGdiObject`)

- HFONT (`CGdiObject`)

- HBITMAP (`CGdiObject`)

- HPALETTE (`CGdiObject`)

- HRGN (`CGdiObject`)

- HIMAGELIST ([CImageList](../mfc/reference/cimagelist-class.md))

- SOQUETE ([CSocket](../mfc/reference/csocket-class.md))

Dado um identificador para qualquer um desses objetos, você pode encontrar o objeto do MFC que encapsula o identificador chamando o método estático `FromHandle`. Por exemplo, dado um HWND chamado *hWnd*, a linha a seguir retornará um ponteiro para o `CWnd` que encapsula *hWnd*:

```
CWnd::FromHandle(hWnd)
```

Se *hWnd* não tem um objeto de wrapper específico, um temporário `CWnd` é criado para encapsular *hWnd*. Isso torna possível obter um objeto válido do C++ a partir de qualquer identificador.

Depois de ter um objeto wrapper, você pode recuperar seu identificador de uma variável de membro público da classe wrapper. No caso de uma `CWnd`, *m_hWnd* contém o HWND para esse objeto.

## <a name="attaching-handles-to-mfc-objects"></a>Anexando identificadores para objetos MFC

Dado um objeto recém-criado de wrapper de identificador e um identificador para um objeto do Windows, você pode associar os dois, chamando o `Attach` de função, como neste exemplo:

```
CWnd myWnd;
myWnd.Attach(hWnd);
```

Isso torna uma entrada na associação de mapa permanente *myWnd* e *hWnd*. Chamando `CWnd::FromHandle(hWnd)` agora retornará um ponteiro para *myWnd*. Quando *myWnd* é excluído, o destruidor automaticamente destruirá *hWnd* chamando o Windows [DestroyWindow](/windows/desktop/api/winuser/nf-winuser-destroywindow) função. Se isso não for desejado, *hWnd* deve ser desanexado do *myWnd* antes *myWnd* é destruído (normalmente ao deixar o escopo no qual *myWnd*foi definido). O `Detach` método faz isso.

```
myWnd.Detach();
```

## <a name="more-about-temporary-objects"></a>Mais informações sobre objetos temporários

Objetos temporários são criados sempre que `FromHandle` recebe um identificador que não tem um objeto de wrapper. Esses objetos temporários são desanexados de seu identificador e excluídos pelo `DeleteTempMap` funções. Por padrão [CWinThread::OnIdle](../mfc/reference/cwinthread-class.md#onidle) automaticamente chama `DeleteTempMap` para cada classe que dá suporte a mapas de identificador temporário. Isso significa que você não pode assumir que um ponteiro para um objeto temporário será válido após o ponto de saída da função de onde o ponteiro foi obtido.

## <a name="wrapper-objects-and-multiple-threads"></a>Objetos wrapper e vários Threads

Objetos temporários e permanentes são mantidos em uma base por thread. Ou seja, um thread não pode acessar objetos de wrapper de C++ de outro thread, independentemente de ser temporário ou permanente.

Para passar esses objetos de um thread para outro, sempre enviá-los como seu nativo `HANDLE` tipo. Passando um objeto de wrapper do C++ de um thread para outro geralmente fará com que resultados inesperados.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

