---
title: Erro fatal C1047 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1047
dev_langs:
- C++
helpviewer_keywords:
- C1047
ms.assetid: e1bbbc6b-a5bc-4c23-8203-488120a0ec78
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b848f874f382e3d4f944a7eb372db9dcc5011f59
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1047"></a>Erro fatal C1047
O arquivo de objeto ou de biblioteca 'file' foi criado com um compilador mais antigo que os demais objetos; recriar os objetos e bibliotecas antigas  
  
 C1047 é causado quando os arquivos de objeto ou bibliotecas criados com **/LTCG** são vinculados juntos, mas onde esses arquivos de objeto ou bibliotecas são criadas com versões diferentes do conjunto de ferramentas do Visual C++.  
  
 Isso pode acontecer se você começar a usar uma nova versão do compilador, mas não faça uma recompilação limpa os arquivos existentes do objeto ou bibliotecas.  
  
 Para resolver C1047, reconstrua todos os arquivos de objeto ou bibliotecas.
