---
title: 'TN003: Mapeamento de identificadores do Windows para objetos'
ms.date: 11/04/2016
f1_keywords:
- vc.mapping
helpviewer_keywords:
- TN003
- handle maps
- Windows handles to objects [MFC]
- mappings [MFC], Windows handles to objects
ms.assetid: fbea9f38-992c-4091-8dbc-f29e288617d6
ms.openlocfilehash: 45492963e1b686e03eb59c320fdc3d52d1534f7d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513530"
---
# <a name="tn003-mapping-of-windows-handles-to-objects"></a>TN003: Mapeamento de identificadores do Windows para objetos

Esta observação descreve as rotinas do MFC que dão suporte ao mapeamento C++ de identificadores de objeto do Windows para objetos do.

## <a name="the-problem"></a>O problema

Os objetos do Windows são normalmente representados por vários objetos de [identificadores](/windows/win32/WinProg/windows-data-types) que as classes C++ MFC encapsulam identificadores de objetos do Windows com objetos. As funções de encapsulamento de identificadores da biblioteca de classes do C++ MFC permitem localizar o objeto que está encapsulando o objeto do Windows que tem um identificador específico. No entanto, às vezes um objeto não C++ tem um objeto wrapper e, nessas ocasiões, o sistema cria um objeto temporário C++ para atuar como o wrapper.

Os objetos do Windows que usam mapas de identificador são os seguintes:

- HWND ([CWnd](../mfc/reference/cwnd-class.md) e `CWnd`classes derivadas)

- HDC ([CDC](../mfc/reference/cdc-class.md) e `CDC`classes derivadas)

- HMENU ([CMenu](../mfc/reference/cmenu-class.md))

- HPEN ([CGdiObject](../mfc/reference/cgdiobject-class.md))

- HBRUSH (`CGdiObject`)

- HFONT (`CGdiObject`)

- HBITMAP (`CGdiObject`)

- HPALETTE (`CGdiObject`)

- HRGN (`CGdiObject`)

- HIMAGELIST ([CImageList](../mfc/reference/cimagelist-class.md))

- SOQUETE ([CSocket](../mfc/reference/csocket-class.md))

Dado um identificador a qualquer um desses objetos, você pode encontrar o objeto MFC que encapsula o identificador chamando o método `FromHandle`estático. Por exemplo, dado um HWND chamado *HWND*, a linha a seguir retornará um ponteiro para o `CWnd` que encapsula o *HWND*:

```
CWnd::FromHandle(hWnd)
```

Se *HWND* não tiver um objeto wrapper específico, um temporário `CWnd` será criado para encapsular *HWND*. Isso possibilita obter um objeto válido C++ de qualquer identificador.

Depois de ter um objeto wrapper, você pode recuperar seu identificador de uma variável de membro público da classe wrapper. No caso de a `CWnd`, *m_hWnd* contém o HWND para esse objeto.

## <a name="attaching-handles-to-mfc-objects"></a>Anexando identificadores a objetos MFC

Dado um objeto Handle-wrapper recém-criado e um identificador a um objeto do Windows, você pode associar os dois chamando a `Attach` função como neste exemplo:

```
CWnd myWnd;
myWnd.Attach(hWnd);
```

Isso faz uma entrada no mapa permanente associando *myWnd* e *HWND*. Chamar `CWnd::FromHandle(hWnd)` agora retornará um ponteiro para *myWnd*. Quando *myWnd* for excluído, o destruidor destruirá automaticamente o *HWND* chamando a função [DestroyWindow](/windows/win32/api/winuser/nf-winuser-destroywindow) do Windows. Se isso não for desejado, o *HWND* deverá ser desanexado de *MyWnd* antes que *myWnd* seja destruído (normalmente ao deixar o escopo no qual *myWnd* foi definido). O `Detach` método faz isso.

```
myWnd.Detach();
```

## <a name="more-about-temporary-objects"></a>Mais sobre objetos temporários

Os objetos temporários são `FromHandle` criados sempre que o recebe um identificador que ainda não tem um objeto wrapper. Esses objetos temporários são desanexados de seu identificador e excluídos `DeleteTempMap` pelas funções. Por padrão, [CWinThread:: OnIdle](../mfc/reference/cwinthread-class.md#onidle) chama `DeleteTempMap` automaticamente cada classe que dá suporte a mapas de identificador temporários. Isso significa que você não pode assumir que um ponteiro para um objeto temporário será válido após o ponto de saída da função onde o ponteiro foi obtido.

## <a name="wrapper-objects-and-multiple-threads"></a>Objetos de wrapper e vários threads

Os objetos temporários e permanentes são mantidos por thread. Ou seja, um thread não pode acessar os objetos C++ de wrapper de outro thread, independentemente de ser temporário ou permanente.

Para passar esses objetos de um thread para outro, sempre envie-os como seu `HANDLE` tipo nativo. Passar um C++ objeto wrapper de um thread para outro geralmente causará resultados inesperados.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
