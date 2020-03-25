---
title: Erro fatal U1059 (NMAKE)
ms.date: 08/27/2018
f1_keywords:
- U1059
helpviewer_keywords:
- U1059
ms.assetid: b21d9198-9c63-40d0-b589-80e17294ce24
ms.openlocfilehash: 33be3312e1f0aaa7f1e8aad64b44ea9aefd25346
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182832"
---
# <a name="nmake-fatal-error-u1059"></a>Erro fatal U1059 (NMAKE)

> erro de sintaxe: '} ' ausente no dependente

Um caminho de pesquisa para um dependente foi especificado incorretamente. Um espaço existia no caminho ou a chave de fechamento ( **}** ) foi omitida.

A sintaxe para uma especificação de diretório para um dependente é

> **{** *diretórios* **} dependentes**

onde os *diretórios* especificam um ou mais caminhos, cada um separado por um ponto-e-vírgula ( **;** ). Nenhum espaço é permitido.

Se parte ou todo um caminho de pesquisa for substituído por uma macro, certifique-se de que não existam espaços na expansão da macro.
