---
title: Ferramentas de vinculador LNK1188 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1188
dev_langs: C++
helpviewer_keywords: LNK1188
ms.assetid: 4af574b0-5b41-4580-9a37-52a634add995
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 81d2988742eb9e8cd6aef134510ac8272d3dd27c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1188"></a>Erro das Ferramentas de Vinculador LNK1188
BADFIXUPSECTION:: alvo de conserto inválido 'symbol'; possíveis seção de comprimento igual a zero  
  
 Durante um link VxD, o destino de uma realocação não tinha uma seção. Com LINK386 (uma versão mais antiga), um registro de grupo OMF (gerado por uma diretiva de grupo MASM) pode ter sido usado para combinar a seção de tamanho zero com outra seção de comprimento diferente de zero. Formato COFF não dá suporte a diretiva de grupo e seções de comprimento zero. Quando o LINK automaticamente esse tipo de objeto OMF em COFF, esse erro pode ocorrer.