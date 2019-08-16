---
title: 'TN070: Nomes de classe de janela do MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- window class names [MFC]
- TN070 [MFC]
ms.assetid: 90617912-dd58-4a7c-9082-ced71736d7cd
ms.openlocfilehash: 1d9b5de07bcc2545df6294557d1ac9f9d29e856c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513349"
---
# <a name="tn070-mfc-window-class-names"></a>TN070: Nomes de classe de janela do MFC

> [!NOTE]
>  A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

As janelas do MFC usam um nome de classe criado dinamicamente que reflete os recursos da janela. O MFC gera nomes de classe dinamicamente para janelas de quadro, exibições e janelas pop-up produzidas pelo aplicativo. Caixas de diálogo e controles produzidos por um aplicativo MFC têm o nome fornecido pelo Windows para a classe de janela em questão.

Você pode substituir o nome de classe fornecido dinamicamente registrando sua própria classe de janela e usando-o em uma substituição de [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow). Seus nomes de classe fornecidos pelo MFC se ajustam a uma das duas formas a seguir:

```
Afx:%x:%x
Afx:%x:%x:%x:%x:%x
```

Os dígitos hexadecimais que substituem `%x` os caracteres são preenchidos de dados da estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) . O MFC usa essa técnica para que C++ várias classes que exigem estruturas **WNDCLASS** idênticas possam compartilhar a mesma classe de janela registrada. Ao contrário dos aplicativos Win32 mais simples, os aplicativos MFC têm apenas um **WndProc**, portanto, você pode facilmente compartilhar estruturas **WNDCLASS** para economizar tempo e memória. Os valores substituíveis para `%x` os caracteres mostrados acima são os seguintes:

- **WNDCLASS.hInstance**

- **WNDCLASS.style**

- **WNDCLASS.hCursor**

- **WNDCLASS.hbrBackground**

- **WNDCLASS.hIcon**

O primeiro formulário (`Afx:%x:%x`) é usado quando **hCursor**, **hbrBackground**e **HICON** são todos **nulos**.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)<br/>
[TN020: convenções de nomenclatura de ID e numeração](../mfc/tn020-id-naming-and-numbering-conventions.md)
