---
title: "MASM for x64 (ml64.exe) | Microsoft Docs"
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
helpviewer_keywords: 
  - "ml64.exe"
  - "ml"
ms.assetid: 89059103-f372-4968-80ea-0c7f90bb9c91
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# MASM for x64 (ml64.exe)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

ml64.exe é o montador que aceita [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] linguagem assembly.  Para obter informações sobre opções do compilador ml64.exe, consulte [ML and ML64 Command\-Line Reference](../../assembler/masm/ml-and-ml64-command-line-reference.md).  
  
 ASM in\-line não há suporte para [!INCLUDE[vcprx64](../Token/vcprx64_md.md)].  Use intrínsecos MASM ou compilador \([x64 Intrinsics](http://msdn.microsoft.com/pt-br/5d1f5d3e-156e-4ebf-932e-fd09be7ced62)\).  
  
 As duas soluções alternativas são um conjunto separado com MASM \(que suporta totalmente o x64\) e intrínsecos do compilador.  Adicionamos muitas intrínsecos para permitir que os clientes façam usar instruções especiais\-função \(ex.:  privilegiado, verificação e teste de bit, sincronizadas, etc …\) em como fechar para várias plataformas maneira possível.  
  
## Diretivas específicas de ml64  
 Use as seguintes diretivas com ml64.exe:  
  
-   [.ALLOCSTACK](../Topic/.ALLOCSTACK.md)  
  
-   [.ENDPROLOG](../Topic/.ENDPROLOG.md)  
  
-   [.PUSHFRAME](../../assembler/masm/dot-pushframe.md)  
  
-   [.PUSHREG](../Topic/.PUSHREG.md)  
  
-   [.SAVEREG](../../assembler/masm/dot-savereg.md)  
  
-   [.SAVEXMM128](../../assembler/masm/dot-savexmm128.md)  
  
-   [.SETFRAME](../../assembler/masm/dot-setframe.md)  
  
 Além disso, o [PROC](../../assembler/masm/proc.md) diretiva foi atualizada para uso com o ml64.exe.  
  
## Modo de endereço de 32 bits \(substituição de tamanho de endereço\)  
 MASM emitirá a substituição de tamanho do endereço 0x67, se um operando de memória inclui registros de 32 bits.  Por exemplo, os exemplos a seguir fazem a substituição de tamanho do endereço a ser emitido:  
  
```  
mov rax, QWORD PTR [ecx]  
mov eax, DWORD PTR [ecx*2+r10d]  
mov eax, DWORD PTR [ecx*2+r10d+0100h]  
prefetch [eax]  
movnti rax, QWORD PTR [r8d]  
```  
  
 MASM pressupõe que se um deslocamento de 32 bits aparecerá sozinho, como um operando de memória, o endereçamento de 64 bits destina\-se.  Atualmente, não há nenhum suporte para endereçamento de 32 bits com tais operandos.  
  
 Finalmente, a combinação de tamanhos de registro dentro de um operando de memória, conforme demonstrado no código a seguir, irá gerar um erro.  
  
```  
mov eax, DWORD PTR [rcx*2+r10d]  
mov eax, DWORD PTR [ecx*2+r10+0100h]  
```  
  
## Consulte também  
 [Microsoft Macro Assembler Reference](../../assembler/masm/microsoft-macro-assembler-reference.md)