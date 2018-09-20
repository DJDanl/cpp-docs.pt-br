---
title: 'TN070: Nomes de classe de janela MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.classes
dev_langs:
- C++
helpviewer_keywords:
- window class names [MFC]
- TN070 [MFC]
ms.assetid: 90617912-dd58-4a7c-9082-ced71736d7cd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 92dcc2509732472774a119dafb43174895247948
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46382512"
---
# <a name="tn070-mfc-window-class-names"></a>TN070: nomes de classe da janela MFC

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Windows MFC usam um nome de classe criada dinamicamente que reflete os recursos da janela. MFC gera nomes de classe dinamicamente para janelas de quadro, exibições e janelas de pop-up produzidas pelo aplicativo. Caixas de diálogo e controles produzidos por um aplicativo do MFC tem o nome fornecido pelo Windows para a classe de janela em questão.

Você pode substituir o nome de classe fornecido dinamicamente Registrando sua própria classe de janela e usá-lo em uma substituição de [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow). Seus nomes de classe fornecido pelo MFC se enquadra em uma das duas seguintes formas:

```
Afx:%x:%x
Afx:%x:%x:%x:%x:%x
```

Os dígitos hexadecimais que substituem o `%x` dados de caracteres são preenchidos a [WNDCLASS](https://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura. O MFC usa essa técnica, de modo que várias classes C++ que exigem idênticos **WNDCLASS** estruturas podem compartilhar a mesma classe de janela registrada. Ao contrário da maioria dos aplicativos Win32 simples, aplicativos MFC tem apenas um **WNDPROC**, portanto, você pode compartilhar facilmente **WNDCLASS** estruturas para economizar tempo e memória. Os valores de substituição para o `%x` caracteres mostrados acima são da seguinte maneira:

- **WNDCLASS.hInstance**

- **WNDCLASS.style**

- **WNDCLASS.hCursor**

- **WNDCLASS.hbrBackground**

- **WNDCLASS.hIcon**

O primeiro formulário (`Afx:%x:%x`) é usado quando **hCursor**, **hbrBackground**, e **hIcon** são todos **nulo**.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)<br/>
[TN020: convenções de nomenclatura e numeração de ID](../mfc/tn020-id-naming-and-numbering-conventions.md)

