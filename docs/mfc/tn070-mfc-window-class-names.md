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
ms.openlocfilehash: c66c434503bbd2c6d7ee1b0557fa73d843e0caaa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tn070-mfc-window-class-names"></a>TN070: nomes de classe da janela MFC
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Windows MFC usam um nome de classe criada dinamicamente que reflete os recursos da janela. MFC gera nomes de classe dinamicamente para janelas de quadro, exibições e janelas pop-up produzidas pelo aplicativo. Caixas de diálogo e controles produzidos por um aplicativo MFC tem o nome fornecido pelo Windows para a classe de janela em questão.  
  
 Você pode substituir o nome de classe fornecido dinamicamente Registrando sua própria classe de janela e usá-lo em uma substituição de [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow). Seus nomes de classe MFC fornecido se enquadra em uma das duas seguintes formas:  
  
```  
Afx:%x:%x  
Afx:%x:%x:%x:%x:%x  
```  
  
 Os dígitos hexadecimais que substituem o `%x` de dados de caracteres são preenchidos a [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura. MFC usa essa técnica para que várias classes C++ que exigem idênticos **WNDCLASS** estruturas podem compartilhar a mesma classe de janela registrado. Ao contrário da maioria dos aplicativos Win32 simples, aplicativos MFC tem apenas um **WNDPROC**, portanto, você pode compartilhar facilmente **WNDCLASS** estruturas para economizar tempo e memória. Os valores de substituição para o `%x` caracteres mostrados acima são os seguintes:  
  
- **WNDCLASS.hInstance**  
  
- **WNDCLASS.style**  
  
- **WNDCLASS.hCursor**  
  
- **WNDCLASS.hbrBackground**  
  
- **WNDCLASS.hIcon**  
  
 O primeiro formulário (`Afx:%x:%x`) é usado quando **hCursor**, **hbrBackground**, e **hIcon** são todos **nulo**.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)   
 [TN020: convenções de nomenclatura e numeração de ID](../mfc/tn020-id-naming-and-numbering-conventions.md)

