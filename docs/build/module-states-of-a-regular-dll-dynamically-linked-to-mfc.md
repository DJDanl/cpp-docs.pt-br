---
title: Estados de módulo de uma DLL MFC Regular vinculada dinamicamente ao MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- regular MFC DLLs [C++], dynamically linked to MFC
- module states [C++]
- MFC DLLs [C++], regular MFC DLLs
- module states [C++], regular MFC DLLs dynamically linked to
- DLLs [C++], module states
ms.assetid: b4493e79-d25e-4b7f-a565-60de5b32c723
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d458c445930896fb04cb339c7191f649be542faf
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717022"
---
# <a name="module-states-of-a-regular-mfc-dll-dynamically-linked-to-mfc"></a>Estados de módulo de uma DLL MFC Regular vinculada dinamicamente ao MFC

A capacidade de vincular dinamicamente uma DLL MFC regular para a DLL do MFC permite que algumas configurações que são muito complicadas. Por exemplo, uma DLL MFC regular e o executável que a utiliza podem ambos vincular dinamicamente para a DLL do MFC e para qualquer extensão de MFC.

Essa configuração apresenta um problema em relação os dados globais do MFC, como o ponteiro para a atual `CWinApp` mapas de identificador de objeto.

Antes de MFC versão 4.0, esses dados globais residiam na DLL MFC em si e foi compartilhados por todos os módulos no processo. Como cada processo usando uma DLL Win32 obtém sua própria cópia dos dados da DLL, esse esquema fornecido uma maneira fácil de controlar os dados por processo. Além disso, porque o modelo AFXDLL presumidamente que deveria haver apenas um `CWinApp` mapas no processo de identificador de objeto e apenas um conjunto de, esses itens pode ser controlados na DLL MFC em si.

Mas com a capacidade de vincular dinamicamente uma DLL MFC regular para a DLL do MFC, é possível ter duas ou mais `CWinApp` objetos em um processo — e também dois ou mais conjuntos de mapas de identificador. Como MFC manter controle sobre quais devem usar?

A solução é fornecer sua própria cópia dessas informações de estado global de cada módulo (aplicativo ou DLL MFC regular). Portanto, uma chamada para **AfxGetApp** regulares DLL do MFC retorna um ponteiro para o `CWinApp` objeto na DLL, não aquele do executável. Essa cópia por módulo dos dados globais MFC é conhecida como um estado de módulo e é descrita em [MFC Tech Observação 58](../mfc/tn058-mfc-module-state-implementation.md).

O procedimento de janela comuns do MFC alterna automaticamente para o estado do módulo correto, portanto, você não precisará preocupar quaisquer manipuladores de mensagens implementados na DLL MFC regular. Mas, quando seu executável se chama a DLL MFC regular, você precisa definir explicitamente o estado atual do módulo para aquele para a DLL. Para fazer isso, use o **AFX_MANAGE_STATE** macro em todas as funções exportadas da DLL. Isso é feito adicionando a seguinte linha de código para o início das funções exportadas da DLL:

```
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
```

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão de MFC](../build/extension-dlls-overview.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)