---
title: Erro fatal C1047 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C1047
dev_langs: C++
helpviewer_keywords: C1047
ms.assetid: e1bbbc6b-a5bc-4c23-8203-488120a0ec78
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6ddc117d1e83c635bfbc644606c6c8c6032ff4f8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1047"></a>Erro fatal C1047
O arquivo de objeto ou de biblioteca 'file' foi criado com um compilador mais antigo que os demais objetos; recriar os objetos e bibliotecas antigas  
  
 C1047 é causado quando os arquivos de objeto ou bibliotecas criados com **/LTCG** são vinculados juntos, mas onde esses arquivos de objeto ou bibliotecas são criadas com versões diferentes do conjunto de ferramentas do Visual C++.  
  
 Isso pode acontecer se você começar a usar uma nova versão do compilador, mas não faça uma recompilação limpa os arquivos existentes do objeto ou bibliotecas.  
  
 Para resolver C1047, reconstrua todos os arquivos de objeto ou bibliotecas.