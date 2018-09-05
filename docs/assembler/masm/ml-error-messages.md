---
title: Mensagens de erro ML | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
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
ms.openlocfilehash: 836daf438fa5a7f4c797b5b15ffab89720a7af98
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43675959"
---
# <a name="ml-error-messages"></a>Mensagens de erro ML

As mensagens de erro geradas por componentes MASM se enquadram em três categorias:

- **Erros fatais.** Elas indicam um problema grave que impede que o utilitário conclua seu processo normal.

- **Erros não fatais.** O utilitário pode concluir seu processo. Se isso acontecer, seu resultado não é provavelmente será o item desejado.

- **Avisos.** Essas mensagens indicam condições que podem impedir que você obter os resultados desejados.

Todas as mensagens de erro têm o seguinte formato:

> *O utilitário*: *Filename* (*linha*): {*Error_type*} (*código*): *Message_text*

em que:

*Utilitário*<br/>
O programa que enviou a mensagem de erro.

*Filename*<br/>
O arquivo que contém a condição de geração de erro.

*Linha*<br/>
A linha aproximada em que existe uma condição de erro.

*Error_type*<br/>
Fatal erro, erro ou aviso.

*Código*<br/>
O código de erro exclusivo com 5 ou 6 dígitos.

*Message_text*<br/>
Uma descrição curta e geral da condição de erro.

## <a name="see-also"></a>Consulte também

[Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)<br/>