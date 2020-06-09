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
ms.openlocfilehash: 0a458f19f956bb1092cc76acd587bc467f25325e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625579"
---
# <a name="initinstance-member-function"></a>Função de membro InitInstance

O sistema operacional Windows permite executar mais de uma cópia, ou "instância", do mesmo aplicativo. `WinMain`chama [InitInstance](reference/cwinapp-class.md#initinstance) toda vez que uma nova instância do aplicativo é iniciada.

A `InitInstance` implementação padrão criada pelo assistente de aplicativo MFC executa as seguintes tarefas:

- Como sua ação central, o cria os modelos de documento que, por sua vez, criam documentos, exibições e janelas de quadros. Para obter uma descrição desse processo, consulte [criação de modelo de documento](document-template-creation.md).

- Carrega opções de arquivo padrão de um arquivo. ini ou do registro do Windows, incluindo os nomes dos arquivos usados mais recentemente.

- Registra um ou mais modelos de documento.

- Para um aplicativo MDI, o cria uma janela de quadro principal.

- Processa a linha de comando para abrir um documento especificado na linha de comando ou para abrir um documento novo e vazio.

Você pode adicionar seu próprio código de inicialização ou modificar o código escrito pelo assistente.

> [!NOTE]
> Os aplicativos MFC devem ser inicializados como STA (single-threaded apartment). Se você chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) em sua `InitInstance` substituição, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](cwinapp-the-application-class.md)
