---
title: Ferramentas de vinculador LNK1302 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1302
dev_langs:
- C++
helpviewer_keywords:
- LNK1302
ms.assetid: aea3c753-c2c4-4249-bbc3-f2d4f0164b5e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2a5b9201608d6d457288c7ade9376147da08bcb9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1302"></a>Erro das Ferramentas de Vinculador LNK1302
apenas suporta vínculo seguro. netmodules; não é possível vincular. netmodule de arquivo  
  
 Um. netmodule (compilado com **/LN**) foi passado para o vinculador uma usuário tentar invocar a vinculação MSIL.  Um módulo de C++ é válido para MSIL vinculação se ele for compilado com **/CLR: safe**.  
  
 Para corrigir esse erro, compile com **/CLR: safe** para habilitar a vinculação MSIL ou passe o **/clr** ou **/clr: pure** arquivo. obj para o vinculador em vez do módulo.  
  
 Para saber mais, veja  
  
-   [/LN (Criar módulo MSIL)](../../build/reference/ln-create-msil-module.md)  
  
-   [Arquivos .netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md)