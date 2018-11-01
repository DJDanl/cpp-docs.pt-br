---
title: Erro de Build PRJ0006 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0006
helpviewer_keywords:
- PRJ0006
ms.assetid: ce092be4-1652-414f-8cb5-b97ef5841f89
ms.openlocfilehash: d62c774411fda80a3e94044b3272567177328ff5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50451553"
---
# <a name="project-build-error-prj0006"></a>Erro de Build PRJ0006 no Projeto

Não foi possível abrir o arquivo temporário 'arquivo'. Verifique se o arquivo existe e que o diretório não está protegido contra gravação.

Visual C++ não foi possível criar um arquivo temporário durante o processo de compilação. Motivos para isso:

- Nenhum diretório temporário.

- Diretório temporário de somente leitura.

- Espaço em disco.

- A pasta $ (IntDir) é somente leitura ou contém arquivos temporários que são somente leitura.

Esse erro também ocorrerá erro prj0007 na seguir: não foi possível criar o diretório de saída 'diretório'. Erro prj0007 no significa que não foi possível criar o diretório $ (IntDir), indicando a criação de arquivos temporariamente também falharão.

Arquivos temporários são criados sempre que você especificar:

- Um arquivo de resposta.

- Uma etapa de compilação personalizada.

- Um evento de build.