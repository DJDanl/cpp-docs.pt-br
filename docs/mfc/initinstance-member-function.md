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
ms.openlocfilehash: c96d009cf19981a475209233ee397af1cdcb352d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62219511"
---
# <a name="initinstance-member-function"></a>Função de membro InitInstance

O sistema operacional Windows permite que você execute mais de uma cópia ou "instância" do mesmo aplicativo. `WinMain` chamadas [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) sempre que uma nova instância do aplicativo é iniciado.

O padrão `InitInstance` implementação criada pelo Assistente de aplicativo MFC realiza as seguintes tarefas:

- Como sua ação central, cria os modelos de documento que por sua vez criem documentos, exibições e janelas de quadro. Para obter uma descrição desse processo, consulte [criação do modelo de documento](../mfc/document-template-creation.md).

- Carrega as opções de arquivo padrão de um arquivo. ini ou no registro do Windows, incluindo os nomes dos arquivos usados mais recentemente.

- Registra um ou mais modelos de documento.

- Para um aplicativo MDI, cria uma janela de quadro principal.

- Processa a linha de comando para abrir um documento especificado na linha de comando ou abrir um documento novo e vazio.

Você pode adicionar seu próprio código de inicialização ou modificar o código escrito pelo assistente.

> [!NOTE]
>  Aplicativos MFC devem ser inicializados como um compartimento de único thread (STA). Se você chamar [CoInitializeEx](/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) em seu `InitInstance` substituir, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
