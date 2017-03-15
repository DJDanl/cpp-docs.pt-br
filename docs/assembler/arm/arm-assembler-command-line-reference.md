---
title: "ARM Assembler Command-Line Reference | Microsoft Docs"
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
ms.assetid: f7b89478-1ab5-4995-8cde-a805f0462c45
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ARM Assembler Command-Line Reference
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este artigo fornece informações de linha de comando sobre o montador de ARM Microsoft  *armasm*, que compila Thumb ARMv7 assembly idioma para a implementação da Microsoft de formato de arquivo de objeto \(COFF\) comuns.  O vinculador pode vincular código COFF com código de objeto que é produzido pelo montador ARM ou pelo compilador C, juntamente com as bibliotecas de objeto criado pelo bibliotecário.  
  
## Sintaxe  
  
```  
armasm [[options]] sourcefile objectfile  
```  
  
```  
armasm [[options]] -o objectfile sourcefile  
```  
  
#### Parâmetros  
 `options`  
 \-erros`filename`  
 Redirecionar mensagens de erro e aviso para `filename`.  
  
 \-i`dir[;dir]`  
 Adicione o caminho de pesquisa incluir diretórios especificados.  
  
 \-Predefinir`directive`  
 Especifica uma diretiva de DOCUMENTOSDE, SETL ou conjuntos predefinir um símbolo.  Example: **armasm.exe \-predefine "COUNT SETA 150" source.asm**.  Para obter mais informações, consulte o [guia de ferramentas do ARM montador](http://go.microsoft.com/fwlink/?LinkId=246102).  
  
 nowarn\-  
 Desative todas as mensagens de aviso.  
  
 \-Ignorar`warning`  
 Desative o aviso especificado.  Para obter valores possíveis, consulte a seção sobre os avisos.  
  
 \-Ajuda  
 Imprima a mensagem de ajuda de linha de comando.  
  
 \-máquina`machine`  
 Especifique o tipo de máquina definido no cabeçalho PE.  Os valores possíveis para `machine` são:   
**ARM**— Define o tipo de máquina para IMAGE\_FILE\_MACHINE\_ARMNT.  Este é o padrão.   
**THUMB**— Define o tipo de máquina para IMAGE\_FILE\_MACHINE\_THUMB.  
  
 \-oldit  
 Gerar ARMv7 estilo blocos IT.  Por padrão, compatível com ARMv8 IT blocos são gerados.  
  
 \-via`filename`  
 Leia os argumentos de linha de comando adicionais do `filename`.  
  
 \-16  
 Monte fonte como 16 bits instruções de prática.  Este é o padrão.  
  
 \-32  
 Monte fonte como instruções do ARM de 32 bits.  
  
 \-g  
 Gere informações de depuração.  
  
 \-errorReport:`option`  
 Especifique como interno assembler erros são relatados à Microsoft.  Os valores possíveis para `option` são:   
**none**— Não envie relatórios.   
**prompt**— Solicita ao usuário para enviar relatórios imediatamente.   
**queue**— Solicita ao usuário para enviar relatórios no próximo logon de admin.  Este é o padrão.   
**send**— Envie automaticamente relatórios.  
  
 `sourcefile`  
 O nome do arquivo de origem.  
  
 `objectfile`  
 O nome do arquivo do objeto \(saída\).  
  
 O exemplo a seguir demonstra como usar armasm em um cenário típico.  Primeiro, use armasm para criar um arquivo de origem \(.asm\) de linguagem assembly para um arquivo de objeto \(. obj\).  Em seguida, usar o compilador c da linha de comando CL para compilar um arquivo de origem \(c\) e também especificar a opção de vinculador para vincular o arquivo de objeto do ARM.  
  
 **armasm myasmcode.asm \-o myasmcode.obj**  
  
 **cl myccode.c \/link myasmcode.obj**  
  
## Consulte também  
 [ARM Assembler Diagnostic Messages](../../assembler/arm/arm-assembler-diagnostic-messages.md)   
 [ARM Assembler Directives](../../assembler/arm/arm-assembler-directives.md)