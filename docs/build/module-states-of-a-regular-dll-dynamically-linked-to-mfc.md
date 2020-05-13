---
title: Estados de módulo de uma DLL MFC regular vinculada dinamicamente ao MFC
ms.date: 11/04/2016
helpviewer_keywords:
- regular MFC DLLs [C++], dynamically linked to MFC
- module states [C++]
- MFC DLLs [C++], regular MFC DLLs
- module states [C++], regular MFC DLLs dynamically linked to
- DLLs [C++], module states
ms.assetid: b4493e79-d25e-4b7f-a565-60de5b32c723
ms.openlocfilehash: cedce676f5586369446c9856fd33e4d16c237b27
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220585"
---
# <a name="module-states-of-a-regular-mfc-dll-dynamically-linked-to-mfc"></a>Estados de módulo de uma DLL MFC regular vinculada dinamicamente ao MFC

A capacidade de vincular dinamicamente uma DLL do MFC regular à DLL do MFC permite algumas configurações muito complicadas. Por exemplo, uma DLL do MFC regular e o executável que o utiliza podem vincular dinamicamente à DLL do MFC e a quaisquer DLLs de extensão do MFC.

Essa configuração apresenta um problema em relação aos dados globais do MFC, como o ponteiro para o objeto atual `CWinApp` e os mapas de identificadores.

Antes da versão 4,0 do MFC, esses dados globais residem na própria DLL do MFC e foram compartilhados por todos os módulos no processo. Como cada processo que usa uma DLL Win32 obtém sua própria cópia dos dados da DLL, esse esquema forneceu uma maneira fácil de controlar os dados por processo. Além disso, como o modelo AFXDLL presumiu que haveria apenas um `CWinApp` objeto e apenas um conjunto de identificadores no processo, esses itens poderiam ser rastreados na própria DLL do MFC.

Mas com a capacidade de vincular dinamicamente uma DLL do MFC regular à DLL do MFC, agora é possível ter dois ou mais `CWinApp` objetos em um processo — e também dois ou mais conjuntos de mapas de identificadores. Como o MFC controla quais deles devem estar usando?

A solução é fornecer a cada módulo (aplicativo ou DLL do MFC regular) sua própria cópia dessas informações de estado global. Assim, uma chamada para **AfxGetApp** na DLL do MFC regular retorna um ponteiro para o `CWinApp` objeto na DLL, não a que está no executável. Essa cópia por módulo dos dados globais do MFC é conhecida como um estado de módulo e é descrita em [MFC Tech Note 58](../mfc/tn058-mfc-module-state-implementation.md).

O procedimento de janela comum do MFC alterna automaticamente para o estado correto do módulo e, portanto, você não precisa se preocupar com os manipuladores de mensagens implementados em sua DLL do MFC regular. Mas, quando seu executável chama a DLL do MFC regular, você precisa definir explicitamente o estado atual do módulo como aquele para a DLL. Para fazer isso, use a macro **AFX_MANAGE_STATE** em cada função exportada da dll. Isso é feito adicionando a seguinte linha de código ao início das funções exportadas da DLL:

```
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
```

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Gerenciando os dados de estado dos módulos do MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC](extension-dlls-overview.md)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
