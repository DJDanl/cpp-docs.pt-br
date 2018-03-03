---
title: Erro de Build prj0002 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0002
dev_langs:
- C++
helpviewer_keywords:
- PRJ0002
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 81d7f45fb2145d0f47716841a50c9320fd46833c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0002"></a>Erro de Build PRJ0002 no Projeto
resultado do erro retornado da linha de comando' '.  
  
 Um comando, ***linha de comando***, que foi formado da entrada do usuário no **páginas de propriedade** caixa de diálogo, retornada um código de erro, mas nenhuma informação será exibida na janela de saída.  
  
 A resolução para esse erro depende de qual ferramenta gerou o erro. De MIDL, você obterá uma ideia do que deu errado se /o (redirecionamento de saída) for definido.  
  
 Um arquivo em lotes, como uma etapa de compilação personalizada ou evento de compilação, o que não é informativo sobre condições de falha também pode ser o motivo para esse erro.