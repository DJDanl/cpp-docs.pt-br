---
title: Erro das LNK1188 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1188
dev_langs:
- C++
helpviewer_keywords:
- LNK1188
ms.assetid: 4af574b0-5b41-4580-9a37-52a634add995
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 36b31590d94d809c16ed64d16071db0919f60238
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46098934"
---
# <a name="linker-tools-error-lnk1188"></a>Erro das Ferramentas de Vinculador LNK1188

BADFIXUPSECTION:: alvo de conserto inválido 'symbol'; possíveis seção de comprimento de zero

Durante um link de VxD, o destino de uma realocação não tinha uma seção. Com LINK386 (uma versão mais antiga), um registro de grupo OMF (gerado por uma diretiva de grupo (MASM)) pode ter sido usado para combinar a seção de tamanho zero com outra seção de comprimento diferente de zero. Formato COFF não oferece suporte a diretiva de grupo e a seções de comprimento zero. Quando o LINK converte automaticamente esse tipo de objeto OMF para COFF, esse erro pode ocorrer.