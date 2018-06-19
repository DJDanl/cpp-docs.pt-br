---
title: Mensagens de erro ML | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- vc.errors.ml
dev_langs:
- C++
helpviewer_keywords:
- MASM (Microsoft Macro Assembler), ML error messages
ms.assetid: e7e164b3-6d65-4b5b-8925-bfbebc043523
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fbc2ae6388ad11a411850d03de421d2f6820fc03
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32057091"
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