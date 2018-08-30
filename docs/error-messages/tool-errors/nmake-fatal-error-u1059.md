---
title: NMAKE Erro Fatal U1059 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1059
dev_langs:
- C++
helpviewer_keywords:
- U1059
ms.assetid: b21d9198-9c63-40d0-b589-80e17294ce24
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8b54919398c757bfe05f747ff57341f31decfc61
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43200784"
---
# <a name="nmake-fatal-error-u1059"></a>Erro fatal U1059 (NMAKE)

> Erro de sintaxe: '}' ausente em dependente

Um caminho de pesquisa para um dependente foi especificado incorretamente. Um espaço de em existia no caminho ou a chave de fechamento (**}**) foi omitido.

A sintaxe para uma especificação de diretório para um dependente é

> **{** *diretórios* **} dependentes**

em que *diretórios* Especifica um ou mais caminhos, cada um separado por ponto e vírgula (**;**). Não são permitidos espaços.

Se parte ou todo um caminho de pesquisa é substituído por uma macro, verifique se que nenhum espaço existe na expansão de macro.