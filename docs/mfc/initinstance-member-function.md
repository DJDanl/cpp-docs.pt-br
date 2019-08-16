---
title: Função de membro InitInstance
ms.date: 11/04/2016
f1_keywords:
- InitInstance
helpviewer_keywords:
- InitInstance method [MFC]
- applications [MFC], initializing
- MFC, initializing
- initializing MFC applications
ms.assetid: 4ef09267-ff7f-4c39-91a0-57454a264f83
ms.openlocfilehash: c1f83f794cc40fa7f4d290fa4a147fe9f7e074be
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508365"
---
# <a name="initinstance-member-function"></a>Função de membro InitInstance

O sistema operacional Windows permite executar mais de uma cópia, ou "instância", do mesmo aplicativo. `WinMain`chama [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) toda vez que uma nova instância do aplicativo é iniciada.

A implementação `InitInstance` padrão criada pelo assistente de aplicativo MFC executa as seguintes tarefas:

- Como sua ação central, o cria os modelos de documento que, por sua vez, criam documentos, exibições e janelas de quadros. Para obter uma descrição desse processo, consulte [criação de modelo de documento](../mfc/document-template-creation.md).

- Carrega opções de arquivo padrão de um arquivo. ini ou do registro do Windows, incluindo os nomes dos arquivos usados mais recentemente.

- Registra um ou mais modelos de documento.

- Para um aplicativo MDI, o cria uma janela de quadro principal.

- Processa a linha de comando para abrir um documento especificado na linha de comando ou para abrir um documento novo e vazio.

Você pode adicionar seu próprio código de inicialização ou modificar o código escrito pelo assistente.

> [!NOTE]
>  Os aplicativos MFC devem ser inicializados como STA (single-threaded apartment). Se você chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) em sua `InitInstance` substituição, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
