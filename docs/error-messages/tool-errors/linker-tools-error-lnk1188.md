---
title: Erro das Ferramentas de Vinculador LNK1188
ms.date: 11/04/2016
f1_keywords:
- LNK1188
helpviewer_keywords:
- LNK1188
ms.assetid: 4af574b0-5b41-4580-9a37-52a634add995
ms.openlocfilehash: b18a93c7434ee3d66f42829f373bd916a65369bd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195169"
---
# <a name="linker-tools-error-lnk1188"></a>Erro das Ferramentas de Vinculador LNK1188

BADFIXUPSECTION:: ' Symbol ' de destino de correção inválido; possível seção de comprimento zero

Durante um link VxD, o destino de uma realocação não tinha uma seção. Com LINK386 (uma versão mais antiga), um registro de grupo OMF (gerado por uma diretiva de grupo MASM) pode ter sido usado para combinar a seção de comprimento zero com outra seção de comprimento diferente de zero. O formato COFF não oferece suporte à diretiva de grupo e a seções de comprimento zero. Quando o LINK converte automaticamente esse tipo de objetos OMF para COFF, esse erro pode ocorrer.
