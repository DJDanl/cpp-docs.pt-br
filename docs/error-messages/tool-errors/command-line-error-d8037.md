---
title: Erro D8037 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8037
helpviewer_keywords:
- D8037
ms.assetid: acddaaa0-bd84-426f-a37b-8f680b379c9d
ms.openlocfilehash: ed6778861c89bb9755087c4d58f094a57d5f760f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196853"
---
# <a name="command-line-error-d8037"></a>Erro D8037 (linha de comando)

Não é possível criar arquivo Il temporário; limpar diretório temporário de arquivos Il antigos

Não há espaço suficiente para criar arquivos intermediários de compilador temporários. Para corrigir esse erro, remova todos os arquivos MSIL antigos no diretório especificado pela variável de ambiente **tmp** . Esses arquivos estarão no formato _CL_hhhhhhhh. SS, em que h representa um dígito hexadecimal aleatório e SS representa o tipo de arquivo IL. Além disso, certifique-se de atualizar seu computador com os patches de sistema operacional mais recentes.

## <a name="see-also"></a>Confira também

[Erros de linha de comando D8000 a D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)<br/>
[Opções do compilador MSVC](../../build/reference/compiler-options.md)
