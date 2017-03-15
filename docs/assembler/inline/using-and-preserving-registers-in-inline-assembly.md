---
title: "Usando e preservando registros em assembly embutido | Microsoft Docs"
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
  - "Palavra-chave __asm [C++], valores de registro"
  - "assembly embutido, registros"
  - "preservando registros"
  - "registros, assembly embutido"
ms.assetid: dbcd7360-6f3e-4b22-9ee2-9f65ca6f2543
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando e preservando registros em assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Em geral, você não deve pressupor que um registro terá um valor fornecido quando um bloco de `__asm` inicia.  Os valores do registro não há garantia de ser preservados pelos blocos separados de `__asm` .  Se você termina um bloco de código em linha e inicia outro, você não pode confiar nos registros no segundo bloco para reter os valores do primeiro bloco.  Um bloco de `__asm` herda o que valores do registro resultados do fluxo de controle normal.  
  
 Se você usar `__fastcall` que chama a convenção, os argumentos da função do do compilador nos registros em vez de na pilha.  Isso pode criar problemas em funções com os blocos de `__asm` como uma função não tem nenhuma forma de afirmar que parâmetro está na qual registro.  Se a função ocorre receber um parâmetro em EAX e armazena imediatamente algo mais em EAX, o parâmetro original é perdido.  Além disso, você deve preservar o registro de ECX em qualquer função declarada com `__fastcall`.  
  
 Para evitar tais conflitos de registro, não use a convenção de `__fastcall` para as funções que contêm um bloco de `__asm` .  Se você especificar a convenção de `__fastcall` global com a opção de compilador de \/Gr, declarar cada função que contém um bloco de `__asm` com `__cdecl` ou `__stdcall`. \(O atributo de `__cdecl` informa o compilador para usar C que chama a convenção para aquela função.\) Se você não estiver compilando com \/Gr, evite declarar a função com o atributo de `__fastcall` .  
  
 Quando usar `__asm` para gravar a linguagem assembly no C\/C\+\+ funcionar, você não precisa preservar os registros de EAX, de EBX, de ECX, de EDX, de ESI, ou de EDI.  Por exemplo, no exemplo de POWER2.C em [Funções de gravação com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md), a função de `power2` não preserva o valor do registro de EAX.  No entanto, usar esses registros afetará a qualidade de código porque o alocador do registro não pode usar para armazenar os valores nos blocos de `__asm` .  Além disso, usando EBX, ESI ou EDI embutido no código do assembly, você força o compilador para salvar e restaurar esses registros no prólogo e em epílogo da função.  
  
 Você deve preservar outros registros que você usa \(como o DS, SS, SP, BP, e embandeiram registros\) para o escopo do bloco de `__asm` .  Você deve preservar registros ESP e de EBP a menos que você tenha alguma razão o modificar \(para alternar pilhas, por exemplo\).  Consulte também [Otimizando o assembly embutido](../../assembler/inline/optimizing-inline-assembly.md).  
  
 Alguns tipos de SSE exigem o alinhamento da pilha de oito bytes, forçando o compilador para emitir o código dinâmico de permissão com base em fila alinhamento.  Para poder acessar variáveis locais e os parâmetros de função após o alinhamento, o compilador mantém dois ponteiros do quadro.  Se o compilador executa a omissão \(FPO\) do ponteiro do quadro, usará o EBP e ESP.  Se o compilador não executa FPO, o usará EBX e EBP.  Para assegurar corretamente execuções de código, não modifique EBX no código de ASM se a função requer o alinhamento dinâmico de pilha porque pode alterar o ponteiro do quadro.  Mova os tipos alinhados oito bytes da função, ou evite usar EBX.  
  
> [!NOTE]
>  Se as alterações embutidas de código do assembly o sinalizador de direção usando as instruções de STD ou de CLD, você deve restaurar o sinalizador como seu valor original.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)