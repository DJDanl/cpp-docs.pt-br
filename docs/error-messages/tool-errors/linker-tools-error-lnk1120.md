---
title: Erros das ferramentas do Vinculador LNK1120
description: Descreve o erro do vinculador LNK1120, que relata o número de erros de símbolos externos não resolvidos no link.
ms.date: 10/31/2019
f1_keywords:
- LNK1120
helpviewer_keywords:
- LNK1120
ms.assetid: 56aa7d36-921f-4daf-b44d-cca0d4fb1b51
ms.openlocfilehash: 21a1ede07a69cdc065dd897715e243115529600d
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626577"
---
# <a name="linker-tools-error-lnk1120"></a>Erros das ferramentas do Vinculador LNK1120

> *número* de externos não resolvidos

Erro LNK1120 relata o número de erros de [símbolos externos não resolvidos](linker-tools-error-lnk2001.md#what-is-an-unresolved-external-symbol) no link atual.

Cada símbolo externo não resolvido primeiro é relatado por um erro [LNK2001](linker-tools-error-lnk2001.md) ou [LNK2019](linker-tools-error-lnk2019.md) . A mensagem LNK1120 vem por último e mostra a contagem de erros de símbolo não resolvido.

> [!IMPORTANT]
> **Você não precisa corrigir esse erro.** Esse erro desaparece quando você corrige todos os erros do vinculador LNK2001 e LNK2019 antes dele na saída da compilação. Sempre corrija os problemas que começam no primeiro erro relatado. Erros posteriores podem ser causados por versões anteriores e desaparecem quando os erros anteriores são corrigidos.
