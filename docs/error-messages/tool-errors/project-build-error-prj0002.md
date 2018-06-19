---
title: Erro de Build prj0002 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0002
dev_langs:
- C++
helpviewer_keywords:
- PRJ0002
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 54e1870ce9137ba172f848a499dd31133119eea0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33318270"
---
# <a name="project-build-error-prj0002"></a>Erro de Build PRJ0002 no Projeto
resultado do erro retornado da linha de comando' '.  
  
 Um comando, ***linha de comando***, que foi formado da entrada do usuário no **páginas de propriedade** caixa de diálogo, retornada um código de erro, mas nenhuma informação será exibida na janela de saída.  
  
 A resolução para esse erro depende de qual ferramenta gerou o erro. De MIDL, você obterá uma ideia do que deu errado se /o (redirecionamento de saída) for definido.  
  
 Um arquivo em lotes, como uma etapa de compilação personalizada ou evento de compilação, o que não é informativo sobre condições de falha também pode ser o motivo para esse erro.