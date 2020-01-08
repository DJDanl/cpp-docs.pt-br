---
title: Mensagens de erro ML
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- vc.errors.ml
helpviewer_keywords:
- MASM (Microsoft Macro Assembler), ML error messages
ms.assetid: e7e164b3-6d65-4b5b-8925-bfbebc043523
ms.openlocfilehash: 1b065433a1a6baf9bf2631aeb2f53421f8efb83b
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75312619"
---
# <a name="ml-error-messages"></a>Mensagens de erro ML

As mensagens de erro geradas pelos componentes MASM se enquadram em três categorias:

- **Erros fatais.** Eles indicam um problema grave que impede o utilitário de concluir seu processo normal.

- **Erros não fatais.** O utilitário pode concluir seu processo. Se tiver, seu resultado provavelmente não será o que você deseja.

- **:|.** Essas mensagens indicam condições que podem impedi-lo de obter os resultados desejados.

Todas as mensagens de erro têm o seguinte formato:

> *Utilitário*: *nome de arquivo* (*linha*): {*Error_type*} (*código*): *Message_text*

em que:

\ do *utilitário*
O programa que enviou a mensagem de erro.

*Nome de arquivo*\
O arquivo que contém a condição de geração de erros.

\ de *linha*
A linha aproximada em que existe a condição de erro.

*Error_type*\
Erro fatal, erro ou aviso.

*Código*\
O código de erro exclusivo de 5 ou 6 dígitos.

*Message_text*\
Uma descrição breve e geral da condição de erro.

## <a name="see-also"></a>Veja também

[Referência do Microsoft Macro Assembler](microsoft-macro-assembler-reference.md)
