---
title: Aviso LNK4092 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4092
helpviewer_keywords:
- LNK4092
ms.assetid: d569ec47-a338-40e1-940b-8a8061459acb
ms.openlocfilehash: 706ab843f4b079b507033af76a7f407816fce820
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183352"
---
# <a name="linker-tools-warning-lnk4092"></a>Aviso LNK4092 (Ferramentas de Vinculador)

a seção gravável compartilhada ' section ' contém realocações; a imagem pode não ser executada corretamente

O vinculador emite esse aviso sempre que você tem uma seção compartilhada para avisá-lo de um problema potencialmente sério.

Uma maneira de compartilhar dados entre vários processos é marcar uma seção como "compartilhado". No entanto, marcar uma seção como compartilhada pode causar problemas. Por exemplo, você tem uma DLL que contém declarações como esta em uma seção de dados compartilhados:

```
int var = 1;
int *pvar = &var;
```

O vinculador não pode resolver `pvar` porque seu valor depende de onde a DLL está carregada na memória e, portanto, coloca um registro de realocação na DLL. Quando a DLL é carregada na memória, o endereço de `var` pode ser resolvido e `pvar` atribuído. Se outro processo carregar a mesma DLL, mas não puder carregá-la no mesmo endereço, a realocação do endereço de `var` será atualizada para o segundo processo e o espaço de endereço do primeiro processo apontará para o endereço errado.
