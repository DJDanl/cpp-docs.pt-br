---
title: Erro fatal C1352 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1352
dev_langs:
- C++
helpviewer_keywords:
- C1352
ms.assetid: d044e8b0-b6ef-4d57-8eb5-6254071be707
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f4f1f062e11651e4d851231e16569412f95b90d4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46042930"
---
# <a name="fatal-error-c1352"></a>Erro fatal C1352

MSIL inválido ou corrompido na função 'function' do módulo 'file'

Um. netmodule foi passado para o compilador, mas o compilador detectou corrupção no arquivo.  Peça à pessoa que produziu o. netmodule para investigar.

O compilador não verifica os arquivos. netmodule para todos os tipos de corrupção.  No entanto, ele, verifique todos os caminhos de controle em uma função contêm uma instrução return.

Para obter mais informações, consulte [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).