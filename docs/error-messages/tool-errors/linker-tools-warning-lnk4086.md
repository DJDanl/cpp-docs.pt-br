---
title: Aviso LNK4086 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4086
dev_langs:
- C++
helpviewer_keywords:
- LNK4086
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b7b3ad3a8ceebf97ccdcf7a1d8079886f54a3984
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4086"></a>Aviso LNK4086 (Ferramentas de Vinculador)
ponto de entrada 'function' não é stdcall com bytes 'número' argumentos; imagem não pode ser executada  
  
 O ponto de entrada para uma DLL deve ser `__stdcall`. O recompilar a função com o [/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) opção ou especifique `__stdcall` ou WINAPI quando você define a função.