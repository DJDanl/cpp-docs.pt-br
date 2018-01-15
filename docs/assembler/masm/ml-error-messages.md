---
title: Mensagens de erro ML | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.errors.ml
dev_langs: C++
helpviewer_keywords: MASM (Microsoft Macro Assembler), ML error messages
ms.assetid: e7e164b3-6d65-4b5b-8925-bfbebc043523
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1fa5933c9c676b76ebe342ffa848e7b40926da08
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ml-error-messages"></a>Mensagens de erro ML
As mensagens de erro geradas por componentes MASM se enquadram em três categorias:  
  
-   **Erros fatais.** Eles indicam um problema grave que impede que o utilitário de concluir o processo normal.  
  
-   **Erros não fatais.** O utilitário pode concluir seu processo. Se isso acontecer, o resultado não é provável de ser aquele que você deseja.  
  
-   **Avisos.** Essas mensagens indicam condições que podem impedir a obter os resultados desejados.  
  
 Todas as mensagens de erro têm o seguinte formato:  
  
```  
  
Utility: Filename (Line) : [Error_type} (Code): Message_text  
```  
  
 em que:  
  
 `Utility`  
 O programa que enviou a mensagem de erro.  
  
 *Filename*  
 O arquivo que contém a condição de geração de erro.  
  
 *Linha*  
 A linha aproximada onde existe uma condição de erro.  
  
 *Error_type*  
 Fatal erro, erro ou aviso.  
  
 *Código*  
 O código de erro exclusivo com 5 ou 6 dígitos.  
  
 `Message_text`  
 Uma descrição curta e geral da condição de erro.  
  
## <a name="see-also"></a>Consulte também  
 [Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)