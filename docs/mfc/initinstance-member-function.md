---
title: Função de membro InitInstance | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- InitInstance
dev_langs:
- C++
helpviewer_keywords:
- InitInstance method [MFC]
- applications [MFC], initializing
- MFC, initializing
- initializing MFC applications
ms.assetid: 4ef09267-ff7f-4c39-91a0-57454a264f83
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bc9d1d1ff35755a966591e6f46f7742ddfa59e08
ms.sourcegitcommit: d3c41b16bf05af2149090e996d8e71cd6cd55c7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48890017"
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
