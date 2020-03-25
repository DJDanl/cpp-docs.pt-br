---
title: Erro fatal CVT1100 (CVTRES)
ms.date: 11/04/2016
f1_keywords:
- CVT1100
helpviewer_keywords:
- CVT1100
ms.assetid: 886e88dd-5818-4b5f-84f2-d2a3d75f0aaf
ms.openlocfilehash: b7e67df24d41b1e8826673146fcc27fd93d143fd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196541"
---
# <a name="cvtres-fatal-error-cvt1100"></a>Erro fatal CVT1100 (CVTRES)

recurso duplicado — tipo: tipo, nome: nome, Idioma: idioma, sinalizadores: sinalizadores, tamanho: tamanho

O recurso fornecido foi especificado mais de uma vez.

Você pode obter esse erro se o vinculador estiver criando uma biblioteca de tipos e se você não especificou [/TLBID](../../build/reference/tlbid-specify-resource-id-for-typelib.md) e um recurso em seu projeto já usa 1. Nesse caso, especifique/TLBID e especifique outro número até 65535.
