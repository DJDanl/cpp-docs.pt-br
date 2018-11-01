---
title: Erro fatal CVT1100 (CVTRES)
ms.date: 11/04/2016
f1_keywords:
- CVT1100
helpviewer_keywords:
- CVT1100
ms.assetid: 886e88dd-5818-4b5f-84f2-d2a3d75f0aaf
ms.openlocfilehash: c7e65ccc79852ec99dd2406398fe1b3cdecacde7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50429296"
---
# <a name="cvtres-fatal-error-cvt1100"></a>Erro fatal CVT1100 (CVTRES)

Duplicar o recurso, tipo: tipo, nome: nome, idiomas: idiomas, sinalizadores: sinalizadores, tamanho: tamanho

O recurso determinado foi especificado mais de uma vez.

Você pode obter esse erro se o vinculador é criando uma biblioteca de tipos e você não especificou [/TLBID](../../build/reference/tlbid-specify-resource-id-for-typelib.md) e um recurso em seu projeto já usa 1. Nesse caso, especifique /TLBID e outro número até 65535.