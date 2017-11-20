---
title: "Referência de linha de comando do Assembler ARM | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: f7b89478-1ab5-4995-8cde-a805f0462c45
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1bb9bbdd6deb0a8e459f2f2b8d5b6188c7517e6c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="arm-assembler-command-line-reference"></a>Referência de linha de comando do assembler ARM
Este artigo fornece informações de linha de comando sobre assembler ARM Microsoft, *armasm*, que compila ARMv7 Thumb linguagem de assembly para a implementação da Microsoft do formato de arquivo de objeto (COFF) comum. O vinculador poderá vincular código COFF com o código de objeto que é produzido por do assembler ARM ou pelo compilador C, junto com as bibliotecas de objetos que são criados pelo bibliotecário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
armasm [[options]] sourcefile objectfile  
```  
  
```  
armasm [[options]] -o objectfile sourcefile  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `options`  
 -erros`filename`  
 Redirecionamento de mensagens de erro e aviso para `filename`.  
  
 -i`dir[;dir]`  
 Adicione as pastas especificadas para o caminho de pesquisa de inclusão.  
  
 -Predefinir`directive`  
 Especifique uma diretiva SETA, SETL ou conjuntos para predefinir um símbolo. Exemplo: **armasm.exe-predefinir "" contagem de SETA 150 source.asm**. Para obter mais informações, consulte o [guia de ferramentas do ARM assembler](http://go.microsoft.com/fwlink/?LinkId=246102).  
  
 -nowarn  
 Desabilite todas as mensagens de aviso.  
  
 -Ignorar`warning`  
 Desabilite o aviso especificado. Para os valores possíveis, consulte a seção sobre os avisos.  
  
 -Ajuda  
 Imprima a mensagem de ajuda de linha de comando.  
  
 -machine`machine`  
 Especifique o tipo de máquina para definir o cabeçalho PE.  Os valores possíveis para `machine` são:  
**ARM**— define o tipo de máquina para IMAGE_FILE_MACHINE_ARMNT. Esse é o padrão.   
**THUMB**— define o tipo de máquina para IMAGE_FILE_MACHINE_THUMB.  
  
 -oldit  
 Gerar estilo ARMv7 blocos IT.  Por padrão, compatível com ARMv8 IT blocos são gerados.  
  
 -por meio de`filename`  
 Ler argumentos de linha de comando adicionais do `filename`.  
  
 -16  
 Monte a origem como instruções de prática de 16 bits.  Esse é o padrão.  
  
 -32  
 Monte a origem como instruções de ARM de 32 bits.  
  
 -g  
 Gere informações de depuração.  
  
 -errorReport:`option`  
 Especifique como interno assembler erros são relatados à Microsoft.  Os valores possíveis para `option` são:   
**nenhum**— não enviar relatórios.   
**prompt**— solicitar ao usuário para enviar relatórios imediatamente.   
**fila**— avisa o usuário para enviar relatórios no próximo logon de administrador. Esse é o padrão.   
**Enviar**— enviar automaticamente relatórios.  
  
 `sourcefile`  
 O nome do arquivo de origem.  
  
 `objectfile`  
 O nome do arquivo de objeto (saída).  
  
 O exemplo a seguir demonstra como usar armasm em um cenário típico. Primeiro, use armasm para criar um arquivo de origem. (ASM) de linguagem de assembly para um arquivo de objeto (. obj). Em seguida, usar o compilador C da linha de comando CL para compilar um arquivo de origem (c) e também especificar a opção de vinculador para vincular o arquivo de objeto do ARM.  
  
 **armasm myasmcode.asm -o myasmcode.obj**  
  
 **Cl myccode.c /link myasmcode.obj**  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de diagnóstico do ARM Assembler](../../assembler/arm/arm-assembler-diagnostic-messages.md)   
 [Diretivas do assembler ARM](../../assembler/arm/arm-assembler-directives.md)