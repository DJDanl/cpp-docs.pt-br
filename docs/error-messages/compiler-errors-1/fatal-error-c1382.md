---
title: Erro fatal C1382 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1382
dev_langs:
- C++
helpviewer_keywords:
- C1382
ms.assetid: 7a100f8c-3179-4927-a2f1-98de4c753850
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 07c6af1209faface96585224cbd08b4e35101478
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33229249"
---
# <a name="fatal-error-c1382"></a>Erro fatal C1382
o arquivo PCH 'file' foi recompilado após 'obj' foi gerado. Recompile este objeto  
  
 Ao usar [/LTCG](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um arquivo. pch mais recente que um. obj CIL que aponte para ela. As informações no arquivo. obj CIL estão desatualizadas. Recrie o objeto.  
  
 C1382 também pode ocorrer se você compilar com **/Yc**, mas também passar fonte vários arquivos de código para o compilador.  Para resolver, não use **/Yc** ao passar fonte vários arquivos de código para o compilador.  Para obter mais informações, consulte [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md).