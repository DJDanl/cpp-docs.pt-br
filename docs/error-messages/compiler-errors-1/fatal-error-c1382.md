---
title: Erro fatal C1382
ms.date: 11/04/2016
f1_keywords:
- C1382
helpviewer_keywords:
- C1382
ms.assetid: 7a100f8c-3179-4927-a2f1-98de4c753850
ms.openlocfilehash: 2b7f6fd878f0d0ba6cde19a3a316a01c390e954a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50600587"
---
# <a name="fatal-error-c1382"></a>Erro fatal C1382

o arquivo PCH 'file' foi recompilado após 'obj' foi gerado. Recompile este objeto

Ao usar [/LTCG](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um arquivo. pch mais recente que um. obj CIL que aponta para ela. As informações no arquivo. obj CIL estão desatualizadas. Recrie o objeto.

C1382 também pode ocorrer se você compilar com **/Yc**, mas também passar fonte vários arquivos de código para o compilador.  Para resolver, não use **/Yc** ao passar fonte vários arquivos de código para o compilador.  Para obter mais informações, consulte [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md).