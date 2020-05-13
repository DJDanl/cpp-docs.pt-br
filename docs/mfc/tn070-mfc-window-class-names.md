---
title: 'TN070: nomes de classe da janela MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- window class names [MFC]
- TN070 [MFC]
ms.assetid: 90617912-dd58-4a7c-9082-ced71736d7cd
ms.openlocfilehash: ad43f5af5d2e90cb5fc2bc90f0909c2b495b4a4c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373491"
---
# <a name="tn070-mfc-window-class-names"></a>TN070: nomes de classe da janela MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

As janelas MFC usam um nome de classe criado dinamicamente que reflete as características da janela. O MFC gera nomes de classe dinamicamente para janelas de quadros, visualizações e janelas pop-up produzidas pelo aplicativo. Caixas de diálogo e controles produzidos por um aplicativo MFC têm o nome fornecido pelo Windows para a classe de janela em questão.

Você pode substituir o nome de classe fornecido dinamicamente registrando sua própria classe de janela e usando-a em uma substituição do [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow). Os nomes de classe fornecidos pelo MFC se encaixam em uma das duas formas a seguir:

```
Afx:%x:%x
Afx:%x:%x:%x:%x:%x
```

Os dígitos hexa `%x` que substituem os caracteres são preenchidos a partir de dados da estrutura [WNDCLASS.](/windows/win32/api/winuser/ns-winuser-wndclassw) O MFC usa essa técnica para que várias classes C++ que exijam estruturas **WNDCLASS** idênticas possam compartilhar a mesma classe de janela registrada. Ao contrário da maioria dos aplicativos Win32 simples, os aplicativos MFC têm apenas um **WNDPROC,** para que você possa facilmente compartilhar estruturas **WNDCLASS** para economizar tempo e memória. Os valores substituíveis para os `%x` caracteres mostrados acima são os seguintes:

- **WNDCLASS.hInstance**

- **WNDCLASS.style**

- **WNDCLASS.hCursor**

- **WNDCLASS.hbrBackground**

- **WNDCLASS.hIcon**

A primeira`Afx:%x:%x`forma ( ) é usada quando **hCursor**, **hbrBackground,** e **hIcon** são todos **NULOS**.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)<br/>
[TN020: convenções de nomenclatura de ID e numeração](../mfc/tn020-id-naming-and-numbering-conventions.md)
