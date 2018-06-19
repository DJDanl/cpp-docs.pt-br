---
title: Ferramentas de vinculador LNK1302 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1302
dev_langs:
- C++
helpviewer_keywords:
- LNK1302
ms.assetid: aea3c753-c2c4-4249-bbc3-f2d4f0164b5e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6aa84a411f91303c84acb44e2e6c0ab3d975e19f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299413"
---
# <a name="linker-tools-error-lnk1302"></a>Erro das Ferramentas de Vinculador LNK1302
apenas suporta vínculo seguro. netmodules; não é possível vincular. netmodule de arquivo  
  
 Um. netmodule (compilado com **/LN**) foi passado para o vinculador uma usuário tentar invocar a vinculação MSIL.  Um módulo de C++ é válido para MSIL vinculação se ele for compilado com **/CLR: safe**.  
  
 Para corrigir esse erro, compile com **/CLR: safe** para habilitar a vinculação MSIL ou passe o **/clr** ou **/clr: pure** arquivo. obj para o vinculador em vez do módulo.  
  
 Para saber mais, veja  
  
-   [/LN (criar módulo de MSIL)](../../build/reference/ln-create-msil-module.md)  
  
-   [Arquivos .netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md)