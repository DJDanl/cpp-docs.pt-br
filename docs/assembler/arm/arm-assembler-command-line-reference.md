---
title: Referência de linha de comando do assembler ARM
description: Guia de referência para as opções de linha de comando do Microsoft ARM Assembler.
ms.date: 02/09/2020
ms.assetid: f7b89478-1ab5-4995-8cde-a805f0462c45
ms.openlocfilehash: a63273e8d21e7a28574ec79d62c15f29ee59cd50
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77257373"
---
# <a name="arm-assembler-command-line-reference"></a>Referência de linha de comando do assembler ARM

Este artigo fornece informações de linha de comando sobre o Microsoft ARM Assembler, **armasm**. **armasm** monta a linguagem de assembly ARMv7 Thumb na implementação da Microsoft do formato de arquivo de objeto comum (COFF). O vinculador pode vincular objetos de código COFF produzidos pelo compilador do ARM e do C. Ele pode vincular-se a bibliotecas de objetos criadas pelo bibliotecário.

## <a name="syntax"></a>Sintaxe

> **`armasm`** [*opções*] *source_file* *object_file*\
> **`armasm`** [*opções*] **`-o`** *object_file* *source_file*

### <a name="parameters"></a>parâmetros

*opções*\
Uma combinação de zero ou mais das seguintes opções:

- **`-errors`** *nome de arquivo*\
   Redirecione mensagens de erro e aviso para *nome de arquivo*.

- **`-i`** *dir*[ **`;`** <em>dir</em>] \
   Adicione os diretórios especificados ao caminho de pesquisa de inclusão.

- \ de *diretiva* **`-predefine`**
   Especifique uma diretiva SETA, SETL ou define para predefinir um símbolo. \
   Exemplo: `armasm.exe -predefine "COUNT SETA 150" source.asm`\
   Para obter mais informações, consulte o [Guia de referência do compilador ARM armasm](http://infocenter.arm.com/help/topic/com.arm.doc.dui0802b/index.html).

- **`-nowarn`**\
   Desabilite todas as mensagens de aviso.

- *aviso* de`-ignore`\
   Desabilitar o aviso especificado. Para obter os valores possíveis, consulte a seção sobre avisos.

- **`-help`**\
   Imprima a mensagem de ajuda de linha de comando.

- *máquina*`-machine`\
   Especifique o tipo de computador a ser definido no cabeçalho PE.  Os valores possíveis para o *computador* são: \
   **ARM**— define o tipo de computador como IMAGE_FILE_MACHINE_ARMNT. Essa opção é o padrão. \
   **Thumb**— define o tipo de computador como IMAGE_FILE_MACHINE_THUMB.

- **`-oldit`**\
   Gerar blocos de ti de estilo ARMv7.  Por padrão, blocos de ti compatíveis com ARMv8 são gerados.

- **`-via`** *nome de arquivo*\
   Ler argumentos de linha de comando adicionais do *nome do arquivo*.

- **`-16`**\
   Reúna a origem como instruções de Thumb de 16 bits.  Essa é a opção padrão.

- **`-32`**\
   Reúna a origem como instruções do ARM de 32 bits.

- **`-g`**\
   Gerar informações de depuração.

- **`-errorReport:`** *opção*\
   Essa opção foi preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

*source_file*\
O nome do arquivo de origem.

*object_file*\
O nome do arquivo de objeto (saída).

## <a name="remarks"></a>Comentários

O exemplo a seguir demonstra como usar o armasm em um cenário típico. Primeiro, use armasm para criar um arquivo de origem de linguagem de assembly (. asm) para um arquivo de objeto (. obj). Em seguida, use o compilador C de linha de comando CL para compilar um arquivo de origem (. C) e também especificar a opção de vinculador para vincular o arquivo de objeto ARM.

```cmd
armasm myasmcode.asm -o myasmcode.obj
cl myccode.c /link myasmcode.obj
```

## <a name="see-also"></a>Confira também

[Mensagens de diagnóstico do ARM assembler](../../assembler/arm/arm-assembler-diagnostic-messages.md)\
[Diretivas do ARM Assembler](../../assembler/arm/arm-assembler-directives.md)
