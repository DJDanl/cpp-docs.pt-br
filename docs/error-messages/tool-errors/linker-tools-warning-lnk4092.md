---
title: Ferramentas de vinculador LNK4092 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4092
dev_langs:
- C++
helpviewer_keywords:
- LNK4092
ms.assetid: d569ec47-a338-40e1-940b-8a8061459acb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b9b47b347e11e640425bc7840a0f78a33e9e3b7e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46113416"
---
# <a name="linker-tools-warning-lnk4092"></a>Aviso LNK4092 (Ferramentas de Vinculador)

seção compartilhada 'seção' contém realocações; imagem não pode ser executada corretamente

O vinculador emite esse aviso sempre que houver uma seção compartilhada para avisá-lo de um problema potencialmente grave.

Uma maneira de compartilhar dados entre vários processos é para marcar uma seção como "compartilhado". No entanto, a marcação de uma seção como compartilhado pode causar problemas. Por exemplo, você tem uma DLL que contém as declarações como esta em uma seção de dados compartilhada:

```
int var = 1;
int *pvar = &var;
```

O vinculador não pode resolver `pvar` porque seu valor depende de onde a DLL é carregada na memória, portanto, ele coloca um registro de realocação na DLL. Quando a DLL é carregada na memória, o endereço do `var` pode ser resolvido e `pvar` atribuído. Se outro processo carrega a DLL mesma, mas não é possível carregá-lo no mesmo endereço, a realocação para o endereço do `var` será atualizado para o processo de segundo e o espaço de endereço do primeiro processo apontará para o endereço incorreto.