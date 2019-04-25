---
title: Referência de linha de comando do assembler ARM
ms.date: 08/30/2018
ms.assetid: f7b89478-1ab5-4995-8cde-a805f0462c45
ms.openlocfilehash: f49b59a81fbe5f11c0f219d1e1fe83a4ee811c7a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62162129"
---
# <a name="arm-assembler-command-line-reference"></a>Referência de linha de comando do assembler ARM

Este artigo fornece informações de linha de comando sobre o assembler Microsoft ARM, *armasm*, que compila o Thumb ARMv7 linguagem de assembly para a implementação da Microsoft do Common COFF Object File Format (). O vinculador pode vincular o código COFF com código de objeto que é produzido pelo assembler do ARM ou pelo compilador C, junto com as bibliotecas de objetos que são criados pelo bibliotecário.

## <a name="syntax"></a>Sintaxe

> **armasm** [*opções*] *sourcefile* *objectfile*
> **armasm** [*opções *] **-o** *objectfile* *sourcefile*

### <a name="parameters"></a>Parâmetros

*options*<br/>
Uma combinação de zero ou mais das seguintes opções:

- **-errors** *filename*<br/>
   Redirecionamento de erro e mensagens de advertência *filename*.

- **-i** *dir*[**;**<em>dir</em>]<br/>
   Adicione diretórios especificados ao caminho de pesquisa de inclusão.

- **-predefine** *directive*<br/>
   Especifique uma diretiva definidas, SETL ou conjuntos para predefinir um símbolo.<br/>
   Exemplo: **armasm.exe-predefinir source.asm "Contagem de definidas 150"**<br/>
   Para obter mais informações, consulte o [compilador ARM armasm guia de referência](http://infocenter.arm.com/help/topic/com.arm.doc.dui0802b/index.html).

- **-nowarn**<br/>
   Desabilite todas as mensagens de aviso.

- **-ignore** *warning*<br/>
   Desabilite o aviso especificado. Para os valores possíveis, consulte a seção sobre os avisos.

- **ajuda**<br/>
   Imprima a mensagem de ajuda de linha de comando.

- **-machine** *machine*<br/>
   Especifique o tipo de máquina para definir no cabeçalho PE.  Os valores possíveis para *machine* são:<br/>
   **ARM**— define o tipo de máquina para IMAGE_FILE_MACHINE_ARMNT. Esse é o padrão.<br/>
   **THUMB**— define o tipo de máquina para IMAGE_FILE_MACHINE_THUMB.

- **-oldit**<br/>
   Gerar estilo ARMv7 blocos IT.  Por padrão, compatível com ARMv8 IT blocos são gerados.

- **-via** *filename*<br/>
   Ler argumentos de linha de comando adicionais do *filename*.

- **-16**<br/>
   Monte o código-fonte como instruções de Thumb de 16 bits.  Esse é o padrão.

- **-32**<br/>
   Monte o código-fonte como instruções ARM de 32 bits.

- **-g**<br/>
   Gere informações de depuração.

- **-errorReport:** *option*<br/>
   Especifique o assembler interno como erros são relatados à Microsoft.  Os valores possíveis para *opção* são:<br/>
   **nenhum**— não enviar relatórios.<br/>
   **prompt**— solicitar ao usuário para enviar relatórios imediatamente.<br/>
   **fila**— solicitar ao usuário a enviar relatórios no próximo logon de administrador. Esse é o padrão.<br/>
   **Enviar**— enviar automaticamente relatórios.

*sourcefile*<br/>
O nome do arquivo de origem.

*objectfile*<br/>
O nome do arquivo de objeto (saída).

## <a name="remarks"></a>Comentários

O exemplo a seguir demonstra como usar armasm em um cenário típico. Primeiro, use armasm para criar um arquivo de origem (ASM) de linguagem de assembly para um arquivo de objeto (. obj). Em seguida, usar o compilador C da linha de comando CL para compilar um arquivo de origem. (c) e também especificar a opção de vinculador para vincular o arquivo de objeto do ARM.

**armasm myasmcode.asm -o myasmcode.obj**

**cl myccode.c /link myasmcode.obj**

## <a name="see-also"></a>Consulte também

[Mensagens de diagnóstico do assembler ARM](../../assembler/arm/arm-assembler-diagnostic-messages.md)<br/>
[Diretivas do assembler ARM](../../assembler/arm/arm-assembler-directives.md)<br/>
