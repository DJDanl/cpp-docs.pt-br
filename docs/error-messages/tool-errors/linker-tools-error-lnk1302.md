---
title: Ferramentas de vinculador LNK1302 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1302
dev_langs:
- C++
helpviewer_keywords:
- LNK1302
ms.assetid: aea3c753-c2c4-4249-bbc3-f2d4f0164b5e
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 27d38e221ff68265e1c5c45528f2be53e60e3bbe
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1302"></a>Erro das Ferramentas de Vinculador LNK1302
só há suporte para vinculação netmodules seguros; não é possível vincular. netmodule de arquivo  
  
 Um. netmodule (compilado com **/LN**) foi passado para o vinculador em uma tentativa de usuário para invocar a vinculação MSIL.  O módulo do C++ é válido para MSIL vinculando se ele for compilado com **/CLR: safe**.  
  
 Para corrigir esse erro, compilar com **/CLR: safe** para habilitar vinculação MSIL ou passe o **/clr** ou **/clr: puro** arquivo. obj para o vinculador em vez do módulo.  
  
 Para saber mais, veja  
  
-   [/LN (Criar módulo MSIL)](../../build/reference/ln-create-msil-module.md)  
  
-   [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md)
