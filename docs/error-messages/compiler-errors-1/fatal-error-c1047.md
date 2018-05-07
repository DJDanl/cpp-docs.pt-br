---
title: Erro fatal C1047 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1047
dev_langs:
- C++
helpviewer_keywords:
- C1047
ms.assetid: e1bbbc6b-a5bc-4c23-8203-488120a0ec78
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce88321173ee2c8cc286f18d8ab8f1bf5ec98e13
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1047"></a>Erro fatal C1047
O arquivo de objeto ou de biblioteca 'file' foi criado com um compilador mais antigo que os demais objetos; recriar os objetos e bibliotecas antigas  
  
 C1047 é causado quando os arquivos de objeto ou bibliotecas criados com **/LTCG** são vinculados juntos, mas onde esses arquivos de objeto ou bibliotecas são criadas com versões diferentes do conjunto de ferramentas do Visual C++.  
  
 Isso pode acontecer se você começar a usar uma nova versão do compilador, mas não faça uma recompilação limpa os arquivos existentes do objeto ou bibliotecas.  
  
 Para resolver C1047, reconstrua todos os arquivos de objeto ou bibliotecas.