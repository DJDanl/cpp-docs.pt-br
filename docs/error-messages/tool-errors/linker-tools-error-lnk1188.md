---
title: Ferramentas de vinculador LNK1188 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1188
dev_langs:
- C++
helpviewer_keywords:
- LNK1188
ms.assetid: 4af574b0-5b41-4580-9a37-52a634add995
caps.latest.revision: 6
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
ms.openlocfilehash: 407573e605e03aef29adfb81035d5f90b7608689
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1188"></a>Erro das Ferramentas de Vinculador LNK1188
BADFIXUPSECTION:: destino de correção inválido 'symbol'; possíveis seção comprimento de zero  
  
 Durante um link de VxD, o destino de uma realocação não tinha uma seção. Com LINK386 (uma versão mais antiga), um registro de grupo OMF (gerado por uma diretiva de grupo MASM) pode ter sido usado para combinar zero comprimento seção com outra seção de comprimento diferente de zero. Formato COFF não oferece suporte a diretiva de grupo e seções de comprimento zero. Quando o LINK converte automaticamente esse tipo de objetos OMF para COFF, esse erro pode ocorrer.
