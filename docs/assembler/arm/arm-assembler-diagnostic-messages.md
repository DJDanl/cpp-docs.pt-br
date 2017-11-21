---
title: "Mensagens de diagnóstico do ARM Assembler | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 52b38267-6023-4bdc-a0ef-863362f48eec
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 6457e82928a5a705377b90e2acc0989768fcd9f1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="arm-assembler-diagnostic-messages"></a>Mensagens de diagnóstico do ARM Assembler
O assembler ARM Microsoft (*armasm*) emite erros e avisos de diagnósticos quando encontrá-las. Este artigo descreve as mensagens mais comumente encontrados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
filename(lineno) : [error|warning] Anum: message  
```  
  
## <a name="diagnostic-messages"></a>Mensagens de diagnóstico  
  
### <a name="errors"></a>Erros  
 A2193: essa instrução gera um comportamento imprevisível  
 A arquitetura ARM não garante o que acontece quando essa instrução é executada.  Para obter detalhes sobre os formulários bem definidos dessa instrução, consulte o [Manual de referência de arquitetura ARM](http://go.microsoft.com/fwlink/?LinkId=246464).  
  
```  
  
ADD r0, r8, pc         ; A2193: this instruction generates unpredictable behavior  
  
```  
  
 A2196: a instrução não pode ser codificada em 16 bits  
 A instrução especificada não pode ser codificada como uma instrução de prática de 16 bits.  Especifique uma instrução de 32 bits ou reorganizar o código para trazer o rótulo de destino para o intervalo de uma instrução de 16 bits.  
  
 O assembler pode tentar codificar uma ramificação de 16 bits e falhar com este erro, mesmo que uma ramificação de 32 bits é pode ser codificada. Você pode resolver esse problema usando o `.W` especificador marcar explicitamente a ramificação de 32 bits.  
  
```  
  
  ADD.N r0, r1, r2      ; A2196: instruction cannot be encoded in 16 bits  
  
  B.W label             ; OK  
  B.N label             ; A2196: instruction cannot be encoded in 16 bits  
  SPACE 10000  
label  
  
```  
  
 A2202: Sintaxe de instrução de pré-UAL não é permitido na região THUMB  
 Código de Thumb deve usar a sintaxe de linguagem unificado do Assembler (UAL).  A sintaxe antiga não é aceito  
  
```  
  
ADDEQS r0, r1         ; A2202: Pre-UAL instruction syntax not allowed in THUMB region  
ADDSEQ r0, r1         ; OK  
  
```  
  
 A2513: Rotação deve ser par  
 No modo ARM, há uma sintaxe alternativa para especificando constantes.  Em vez de escrever `#<const>`, você pode escrever `#<byte>,#<rot>`, que representa o valor constante que é obtido, girando o valor `<byte>` direita por `<rot>`.  Quando você usa esta sintaxe, você deve verificar o valor de `<rot>` mesmo.  
  
```  
  
MOV r0, #4, #2       ; OK  
MOV r0, #4, #1       ; A2513: Rotation must be even  
  
```  
  
 A2557: O número incorreto de bytes para write-back  
 Na estrutura de NEON carregar e armazenar instruções (`VLDn`, `VSTn`), há uma sintaxe alternativa para especificar o write-back para o registro de base.  Em vez de colocar um ponto de exclamação (!) depois do endereço, você pode especificar um valor imediato que indica o deslocamento a ser adicionado ao registro base.  Se você usar essa sintaxe, você deve especificar o número exato de bytes que foram carregados ou armazenados pela instrução.  
  
```  
  
VLD1.8 {d0-d3}, [r0]!         ; OK  
VLD1.8 {d0-d3}, [r0], #32     ; OK  
VLD1.8 {d0-d3}, [r0], #100    ; A2557: Incorrect number of bytes to write back  
  
```  
  
### <a name="warnings"></a>Avisos  
 A4228: Alinhamento de área; excede o valor de alinhamento alinhamento não garantido  
 O alinhamento especificado em uma `ALIGN` diretiva é maior do que o alinhamento de circunscrição `AREA`.  Como resultado, o assembler não pode garantir que o `ALIGN` diretiva será respeitada.  
  
 Para corrigir isso, você pode especificar o `AREA` diretiva um `ALIGN` atributo que é igual ou maior que o alinhamento desejado.  
  
```  
  
AREA |.myarea1|  
ALIGN 8           ; A4228: Alignment value exceeds AREA alignment; alignment not guaranteed  
  
AREA |.myarea2|,ALIGN=3  
ALIGN 8           ; OK  
  
```  
  
 A4508: O uso desta constante girado está obsoleto  
 No modo ARM, há uma sintaxe alternativa para especificando constantes.  Em vez de escrever `#<const>`, você pode escrever `#<byte>,#<rot>`, que representa o valor constante que é obtido, girando o valor `<byte>` direita por `<rot>`.  Em alguns contextos, ARM tiver substituído o uso de constantes girados. Nesses casos, usar o basic `#<const>` sintaxe em vez disso.  
  
```  
  
ANDS r0, r0, #1                ; OK  
ANDS r0, r0, #4, #2            ; A4508: Use of this rotated constant is deprecated  
  
```  
  
 A4509: Essa forma de instrução condicional é preterida  
 Essa forma de instrução condicional foi substituída pelo ARM na arquitetura do ARMv8. É recomendável que você altere o código para usar ramificações condicionais. Para ver quais instruções condicionais ainda têm suporte, consulte o [Manual de referência de arquitetura ARM](http://go.microsoft.com/fwlink/?LinkId=246464).  
  
 Esse aviso não é emitido quando o `-oldit` opção de linha de comando é usada.  
  
```  
  
ADDEQ r0, r1, r8              ; A4509: This form of conditional instruction is deprecated  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de linha de comando do Assembler ARM](../../assembler/arm/arm-assembler-command-line-reference.md)   
 [Diretivas do assembler ARM](../../assembler/arm/arm-assembler-directives.md)