---
title: Erro do compilador C2220
ms.date: 11/04/2016
f1_keywords:
- C2220
helpviewer_keywords:
- C2220
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
ms.openlocfilehash: c4fdac833e69e748dd29b9cf772c167fc1dbbd00
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80206655"
---
# <a name="compiler-error-c2220"></a>Erro do compilador C2220

aviso tratado como erro-nenhum arquivo de objeto gerado

[/WX](../../build/reference/compiler-option-warning-level.md) informa o compilador para tratar todos os avisos como erros. Como ocorreu um erro, nenhum objeto ou arquivo executável foi gerado.

Esse erro só aparece quando o sinalizador **/WX** é definido e um aviso ocorre durante a compilação. Para corrigir esse erro, você deve eliminar todos os avisos em seu projeto.

### <a name="to-fix-use-one-of-the-following-techniques"></a>Para corrigir, use uma das técnicas a seguir

- Corrija os problemas que causam avisos em seu projeto.

- Compile em um nível de aviso inferior — por exemplo, use **/w3** em vez de **/W4**.

- Use um pragma de [aviso](../../preprocessor/warning.md) para desabilitar ou suprimir um aviso específico.

- Não use **/WX** para compilar.
