---
title: Aviso LNK4086 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4086
dev_langs: C++
helpviewer_keywords: LNK4086
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: fcd701401c798d7126be4f4239ee533b14d90652
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4086"></a>Aviso LNK4086 (Ferramentas de Vinculador)
ponto de entrada 'function' não é stdcall com bytes 'número' argumentos; imagem não pode ser executada  
  
 O ponto de entrada para uma DLL deve ser `__stdcall`. O recompilar a função com o [/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) opção ou especifique `__stdcall` ou WINAPI quando você define a função.