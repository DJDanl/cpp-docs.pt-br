---
title: Erro das Ferramentas de Vinculador LNK1223
ms.date: 11/04/2016
f1_keywords:
- LNK1223
helpviewer_keywords:
- LNK1223
ms.assetid: c4728c36-daee-462f-a1c7-8733dcdec88e
ms.openlocfilehash: 9c9d4c7224a7e65775354a86bd34fa9ea1b074af
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195026"
---
# <a name="linker-tools-error-lnk1223"></a>Erro das Ferramentas de Vinculador LNK1223

arquivo inválido ou corrompido: o arquivo contém contribuições .pdata inválidas

Para plataformas RISC que usam pdata, este erro ocorrerá se o compilador tiver emitido uma seção .pdata com entradas não classificadas.

Para corrigir esse problema, tente compilar sem [/GL (otimização do programa inteiro)](../../error-messages/tool-errors/linker-tools-error-lnk1223.md) habilitada. Corpos de função vazios também podem causar este erro em alguns casos.
