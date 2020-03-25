---
title: Erro de Build PRJ0009 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0009
helpviewer_keywords:
- PRJ0009
ms.assetid: 89291778-cda4-495d-983f-ddcc06dfc98b
ms.openlocfilehash: d02325504b04a13cd15dee0bd70891bf5a63b62e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192948"
---
# <a name="project-build-error-prj0009"></a>Erro de Build PRJ0009 no Projeto

Não foi possível abrir o log de compilação para gravação.

**Verifique se o arquivo não está aberto por outro processo e não está protegido contra gravação.**

Depois de definir a propriedade **log de compilação** como **Sim** e executar uma compilação ou recompilação, o Visual C++ não pôde abrir o log de compilação no modo exclusivo.

Inspecione a configuração **log de compilação** abrindo a caixa de diálogo **Opções** (no menu **ferramentas** , clique no comando **Opções** ) e selecione **compilação do vc + +** na pasta **projetos** . O arquivo de compilação é chamado de BuildLog. htm e é gravado no diretório intermediário $ (IntDir).

Possíveis motivos para esse erro:

- Você está executando dois processos de Visual C++ e tentando criar a mesma configuração do mesmo projeto simultaneamente.

- O arquivo de log de compilação é aberto em um processo que bloqueia o arquivo.

- O usuário não tem permissão para criar um arquivo.

- O usuário atual não tem acesso de gravação ao arquivo BuildLog. htm.
