---
title: Erro de ferramentas do vinculador LNK1352
description: O erro das ferramentas do vinculador LNK1352 ocorre quando uma mesclagem de seção sem suporte é tentada.
ms.date: 09/10/2019
f1_keywords:
- LNK1352
helpviewer_keywords:
- LNK1352
ms.openlocfilehash: 38f773bfd669529dfb1ada9c7bb59e6f0962c9c7
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908378"
---
# <a name="linker-tools-error-lnk1352"></a>Erro de ferramentas do vinculador LNK1352

> '*section_name_1*' e '*section_name_2*' não podem ser mesclados em seções diferentes

## <a name="remarks"></a>Comentários

O vinculador detectou uma mesclagem de seção que não é permitida, porque *section_name_1* e *section_name_2* devem ser mesclados na mesma seção. Por exemplo, esse erro ocorre se o vinculador detectar uma tentativa de Mesclar `.stls` a seção e `.tls` a seção em seções diferentes.

### <a name="to-correct-this-error"></a>Para corrigir este erro

Verifique a opção [/Merge](../../build/reference/merge-combine-sections.md) na linha de comando do vinculador para esse problema.

## <a name="see-also"></a>Consulte também

[Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)
