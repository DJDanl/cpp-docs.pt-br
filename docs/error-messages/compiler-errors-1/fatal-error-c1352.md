---
title: Erro fatal C1352
ms.date: 11/04/2016
f1_keywords:
- C1352
helpviewer_keywords:
- C1352
ms.assetid: d044e8b0-b6ef-4d57-8eb5-6254071be707
ms.openlocfilehash: 07bd0f28e35dd2992ca537dbe744d756cc2afe80
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203119"
---
# <a name="fatal-error-c1352"></a>Erro fatal C1352

MSIL inválido ou corrompido na função ' function ' do módulo ' file '

Um. netmodule foi passado para o compilador, mas o compilador detectou corrupção no arquivo.  Peça à pessoa que produziu o. netmodule para investigar.

O compilador não verifica arquivos. netmodule para todos os tipos de corrupção.  No entanto, ele verifica se todos os caminhos de controle em uma função contêm uma instrução return.

Para obter mais informações, consulte [arquivos. netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md).
