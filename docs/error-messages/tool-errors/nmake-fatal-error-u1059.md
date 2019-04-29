---
title: Erro fatal U1059 (NMAKE)
ms.date: 08/27/2018
f1_keywords:
- U1059
helpviewer_keywords:
- U1059
ms.assetid: b21d9198-9c63-40d0-b589-80e17294ce24
ms.openlocfilehash: 3c148bf2feb7ba12686e00b29f5bf90cb9f2f2d7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62367285"
---
# <a name="nmake-fatal-error-u1059"></a>Erro fatal U1059 (NMAKE)

> Erro de sintaxe: '}' ausente em dependente

Um caminho de pesquisa para um dependente foi especificado incorretamente. Um espaço de em existia no caminho ou a chave de fechamento (**}**) foi omitido.

A sintaxe para uma especificação de diretório para um dependente é

> **{** *directories* **}dependent**

em que *diretórios* Especifica um ou mais caminhos, cada um separado por ponto e vírgula (**;**). Não são permitidos espaços.

Se parte ou todo um caminho de pesquisa é substituído por uma macro, verifique se que nenhum espaço existe na expansão de macro.