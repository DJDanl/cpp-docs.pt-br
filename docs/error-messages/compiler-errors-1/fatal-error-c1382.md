---
title: Erro fatal C1382 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: error-reference
f1_keywords:
- C1382
dev_langs:
- C++
helpviewer_keywords:
- C1382
ms.assetid: 7a100f8c-3179-4927-a2f1-98de4c753850
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 923cc957dd136147a6c749f5ebf9508ca7e2052d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1382"></a>Erro fatal C1382
o arquivo PCH 'file' foi recompilado após 'obj' foi gerado. Recompile este objeto  
  
 Ao usar [/LTCG](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um arquivo. pch mais recente que um. obj CIL que aponte para ela. As informações no arquivo. obj CIL estão desatualizadas. Recrie o objeto.  
  
 C1382 também pode ocorrer se você compilar com **/Yc**, mas também passar fonte vários arquivos de código para o compilador.  Para resolver, não use **/Yc** ao passar fonte vários arquivos de código para o compilador.  Para obter mais informações, consulte [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md).