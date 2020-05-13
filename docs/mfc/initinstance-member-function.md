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
ms.openlocfilehash: 2cf5b266348e299fe761ba40bd2cfb849f02b9ab
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377189"
---
# <a name="initinstance-member-function"></a>Função de membro InitInstance

O sistema operacional Windows permite que você execute mais de uma cópia, ou "instância", do mesmo aplicativo. `WinMain`chama [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) toda vez que uma nova instância do aplicativo é iniciada.

A `InitInstance` implementação padrão criada pelo MFC Application Wizard executa as seguintes tarefas:

- Como ação central, cria os modelos de documentos que, por sua vez, criam documentos, visualizações e janelas de quadros. Para obter uma descrição deste processo, consulte [Criação de modelo de documento](../mfc/document-template-creation.md).

- Carrega opções de arquivo padrão de um arquivo .ini ou do registro do Windows, incluindo os nomes dos arquivos usados mais recentemente.

- Registra um ou mais modelos de documentos.

- Para uma aplicação MDI, cria uma janela de quadro principal.

- Processa a linha de comando para abrir um documento especificado na linha de comando ou para abrir um documento novo e vazio.

Você pode adicionar seu próprio código de inicialização ou modificar o código escrito pelo assistente.

> [!NOTE]
> As aplicações MFC devem ser inicializadas como apartamento com rosca única (STA). Se você chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) em sua `InitInstance` substituição, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

## <a name="see-also"></a>Confira também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
