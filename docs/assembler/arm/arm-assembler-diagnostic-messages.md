---
title: "ARM Assembler Diagnostic Messages | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 52b38267-6023-4bdc-a0ef-863362f48eec
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ARM Assembler Diagnostic Messages
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O montador Microsoft ARM \(*armasm*\) emite diagnóstico avisos e erros quando encontra\-los.  Este artigo descreve as mensagens mais comumente encontrados.  
  
## Sintaxe  
  
```  
  
filename(lineno) : [error|warning] Anum: message  
```  
  
## Mensagens de diagnóstico  
  
### Erros  
 A2193: essa instrução gera um comportamento imprevisível  
 A arquitetura ARM não pode garantir o que acontece quando essa instrução é executada.  Para obter detalhes sobre os formulários bem definidos nesta instrução, consulte o [Manual de referência do ARM arquitetura](http://go.microsoft.com/fwlink/?LinkId=246464).  
  
```  
  
ADD r0, r8, pc         ; A2193: this instruction generates unpredictable behavior  
  
```  
  
 A2196: a instrução não pode ser codificada de 16 bits  
 A instrução especificada não pode ser codificada como uma instrução de prática de 16 bits.  Especifique uma instrução de 32 bits ou reorganizar o código para trazer o rótulo de destino para o intervalo de uma instrução de 16 bits.  
  
 O montador talvez tente codificar uma ramificação em 16 bits e falhar com este erro, mesmo que uma ramificação de 32 bits é encodable.  Você pode resolver esse problema usando o `.W` especificador marcar explicitamente a ramificação como 32 bits.  
  
```  
  
  ADD.N r0, r1, r2      ; A2196: instruction cannot be encoded in 16 bits  
  
  B.W label             ; OK  
  B.N label             ; A2196: instruction cannot be encoded in 16 bits  
  SPACE 10000  
label  
  
```  
  
 A2202: Sintaxe de instrução de Pre\-UAL não é permitido na região do POLEGAR  
 Código Thumb deve usar a sintaxe do idioma de Unificação de montador \(UAL\).  A sintaxe antiga não é aceito  
  
```  
  
ADDEQS r0, r1         ; A2202: Pre-UAL instruction syntax not allowed in THUMB region  
ADDSEQ r0, r1         ; OK  
  
```  
  
 A2513: Rotação deve ser par  
 No modo de ARM, há uma sintaxe alternativa para especificar constantes.  Em vez de escrever `#<const>`, você pode escrever `#<byte>,#<rot>`, que representa o valor da constante que é obtido girando o valor `<byte>` direita por `<rot>`.  Quando você usar essa sintaxe, você deve fazer o valor de `<rot>` mesmo.  
  
```  
  
MOV r0, #4, #2       ; OK  
MOV r0, #4, #1       ; A2513: Rotation must be even  
  
```  
  
 A2557: Número incorreto de bytes a gravar novamente  
 A estrutura de NÉON carregar e armazenar instruções \(`VLDn`, `VSTn`\), há uma sintaxe alternativa para especificação de write\-back para o registro de base.  Em vez de colocar um ponto de exclamação \(\!\) depois do endereço, você pode especificar um valor imediato indica o deslocamento a ser adicionado ao registro base.  Se você usar essa sintaxe, você deve especificar o número exato de bytes carregados ou armazenados pela instrução.  
  
```  
  
VLD1.8 {d0-d3}, [r0]!         ; OK  
VLD1.8 {d0-d3}, [r0], #32     ; OK  
VLD1.8 {d0-d3}, [r0], #100    ; A2557: Incorrect number of bytes to write back  
  
```  
  
### Avisos  
 A4228: O valor do alinhamento excede o alinhamento da área; Não há garantido de alinhamento  
 O alinhamento especificado em um `ALIGN` diretiva é maior do que o alinhamento do circunscrito `AREA`.  Como resultado, o montador não garante que o `ALIGN` diretiva será respeitada.  
  
 Para corrigir isso, você pode especificar o `AREA` diretiva uma `ALIGN` atributo é igual ou maior que o alinhamento desejado.  
  
```  
  
AREA |.myarea1|  
ALIGN 8           ; A4228: Alignment value exceeds AREA alignment; alignment not guaranteed  
  
AREA |.myarea2|,ALIGN=3  
ALIGN 8           ; OK  
  
```  
  
 A4508: O uso dessa constante girado é preterido  
 No modo de ARM, há uma sintaxe alternativa para especificar constantes.  Em vez de escrever `#<const>`, você pode escrever `#<byte>,#<rot>`, que representa o valor da constante que é obtido girando o valor `<byte>` direita por `<rot>`.  Em alguns contextos, ARM tem substituído o uso de constantes girados.  Nesses casos, usar o basic `#<const>` sintaxe em vez disso.  
  
```  
  
ANDS r0, r0, #1                ; OK  
ANDS r0, r0, #4, #2            ; A4508: Use of this rotated constant is deprecated  
  
```  
  
 A4509: Essa forma de instrução condicional é substituída  
 Essa forma de instrução condicional foi substituída pelo ARM na arquitetura ARMv8.  Recomendamos que você altere o código para usar ramificações condicionais.  Para ver quais instruções condicionais ainda são suportadas, consulte o [Manual de referência do ARM arquitetura](http://go.microsoft.com/fwlink/?LinkId=246464).  
  
 Este aviso não é emitido quando o  `- oldit` opção de linha de comando é usada.  
  
```  
  
ADDEQ r0, r1, r8              ; A4509: This form of conditional instruction is deprecated  
  
```  
  
## Consulte também  
 [ARM Assembler Command\-Line Reference](../../assembler/arm/arm-assembler-command-line-reference.md)   
 [ARM Assembler Directives](../../assembler/arm/arm-assembler-directives.md)