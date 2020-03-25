---
title: Erro PRJ0006 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0006
helpviewer_keywords:
- PRJ0006
ms.assetid: ce092be4-1652-414f-8cb5-b97ef5841f89
ms.openlocfilehash: 816355276a203adba1401841ce02eb94a18085b6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192777"
---
# <a name="project-build-error-prj0006"></a>Erro PRJ0006 (compilação de projeto)

Não foi possível abrir o arquivo temporário ' file '. Verifique se o arquivo existe e se o diretório não está protegido contra gravação.

O C++ Visual não pôde criar um arquivo temporário durante o processo de compilação. Os erros são causados pelos seguintes motivos:

- Nenhum diretório temporário.

- Diretório temporário somente leitura.

- Sem espaço em disco.

- A pasta $ (IntDir) é somente leitura ou contém arquivos temporários que são somente leitura.

Esse erro também ocorrerá após o erro PRJ0007: não foi possível criar o diretório de saída ' Directory '. Erro PRJ0007 significa que o diretório $ (IntDir) não pôde ser criado, indicando que a criação de arquivos temporários também falhará.

Os arquivos temporários são criados sempre que você especifica:

- Um arquivo de resposta.

- Uma etapa de compilação personalizada.

- Um evento de compilação.
