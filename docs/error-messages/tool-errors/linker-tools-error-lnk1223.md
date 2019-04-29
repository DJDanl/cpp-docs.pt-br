---
title: Erro das Ferramentas de Vinculador LNK1223
ms.date: 11/04/2016
f1_keywords:
- LNK1223
helpviewer_keywords:
- LNK1223
ms.assetid: c4728c36-daee-462f-a1c7-8733dcdec88e
ms.openlocfilehash: 331521c357389c2f7c1aa786969154a2b747ffe5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62242812"
---
# <a name="linker-tools-error-lnk1223"></a>Erro das Ferramentas de Vinculador LNK1223

arquivo inválido ou corrompido: o arquivo contém contribuições .pdata inválidas

Para plataformas RISC que usam pdata, este erro ocorrerá se o compilador tiver emitido uma seção .pdata com entradas não classificadas.

Para corrigir esse problema, tente compilar sem [/GL (otimização de programa inteiro)](../../error-messages/tool-errors/linker-tools-error-lnk1223.md) habilitado. Corpos de função vazios também podem causar este erro em alguns casos.