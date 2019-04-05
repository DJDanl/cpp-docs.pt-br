---
title: Erro D8037 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8037
helpviewer_keywords:
- D8037
ms.assetid: acddaaa0-bd84-426f-a37b-8f680b379c9d
ms.openlocfilehash: f9f099d1abb8529620c1b3a0bc14705463ca5cd0
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59021476"
---
# <a name="command-line-error-d8037"></a>Erro D8037 (linha de comando)

não é possível criar arquivo il temporário; Limpe diretório temp de arquivos il antigos

Não há espaço suficiente para criar arquivos intermediários de compilador temporário. Para corrigir esse erro, remova os arquivos antigos do MSIL no diretório especificado pela **TMP** variável de ambiente. Esses arquivos poderão ser de _CL_hhhhhhhh.ss o formulário, em que h representa um dígito hexadecimal aleatório e ss representa o tipo de arquivo IL. Além disso, certifique-se de atualizar o computador com os patches mais recentes do sistema operacional.

## <a name="see-also"></a>Consulte também

[Erros de linha de comando D8000 até D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)<br/>
[Opções do compilador MSVC](../../build/reference/compiler-options.md)