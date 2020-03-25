---
title: Erro fatal C1382
ms.date: 11/04/2016
f1_keywords:
- C1382
helpviewer_keywords:
- C1382
ms.assetid: 7a100f8c-3179-4927-a2f1-98de4c753850
ms.openlocfilehash: 6ed70a81c4ae2028d09b694f325f83454e99a587
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203093"
---
# <a name="fatal-error-c1382"></a>Erro fatal C1382

o arquivo PCH ' file ' foi recriado porque ' obj ' foi gerado. Recompile este objeto

Ao usar [/LTCG](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um arquivo. pch que é mais novo do que um cil. obj que aponta para ele. As informações no arquivo CIL. obj estão desatualizadas. Recrie o objeto.

C1382 também pode ocorrer se você compilar with **/YC**, mas também passar vários arquivos de código-fonte para o compilador.  Para resolver, não use **/YC** ao passar vários arquivos de código-fonte para o compilador.  Para obter mais informações, consulte [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md).
