---
title: "Diretivas Pragma e a palavra-chave __Pragma | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "#pragma"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretivas (#pragma), C/C++"
  - "Palavra-chave __pragma"
  - "diretivas pragma (#pragma)"
  - "diretivas pragma, C/C++"
  - "pragmas"
  - "pragmas, C/C++"
  - "pré-processador"
  - "pré-processador, pragmas"
ms.assetid: 9867b438-ac64-4e10-973f-c3955209873f
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretivas Pragma e a palavra-chave __Pragma
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As políticas de pragma especificam recursos de compilador específicos do computador ou da operação.  A palavra\-chave `__pragma`, que é específica do compilador da Microsoft, permite codificar políticas de pragma dentro de definições de macro.  
  
## Sintaxe  
  
```  
  
      #pragma token-string  
__pragma(token-string)  
```  
  
## Comentários  
 Cada implementação de C e C\+\+ oferece suporte a alguns recursos exclusivos para seu computador host ou sistema operacional.  Alguns programas, por exemplo, devem exercitar o controle preciso sobre as áreas de memória onde os dados são colocados ou para controlar a maneira como determinadas funções recebem parâmetros.  As políticas `#pragma` proporcionam uma maneira para que cada compilador ofereça recursos específicos de máquinas e sistemas operacionais enquanto mantém a compatibilidade geral com as linguagens C e C\+\+.  
  
 Os pragmas são específicos do computador ou do sistema operacional por definição e normalmente são diferentes para todos os compiladores.  Os pragmas podem ser usados em instruções condicionais para fornecerem nova funcionalidade de pré\-processador ou para fornecerem informações definidas pela implementação ao compilador.  
  
 `token-string` é uma série de caracteres que oferece uma instrução de compilador específica e argumentos, se houver.  A tecla de cerquilha \(**\#**\) deve ser o primeiro caractere que não seja espaço em branco na linha que contém o pragma; os caracteres de espaço em branco podem separar a tecla de cerquilha da palavra “pragma”.  Depois de `#pragma`, escreva qualquer texto que o conversor possa analisar, como tokens de pré\-processamento.  O argumento para `#pragma` está sujeito a uma expansão de macro.  
  
 Se o compilador encontrar um pragma que não reconhecer, ele emitirá um aviso e continuará a compilação.  
  
 Os compiladores C e C\+\+ da Microsoft reconhecem os seguintes pragmas:  
  
||||  
|-|-|-|  
|[alloc\_text](../preprocessor/alloc-text.md)|[auto\_inline](../preprocessor/auto-inline.md)|[bss\_seg](../preprocessor/bss-seg.md)|  
|[check\_stack](../preprocessor/check-stack.md)|[code\_seg](../preprocessor/code-seg.md)|[comment](../preprocessor/comment-c-cpp.md)|  
|[componente](../Topic/component.md)|[conform](../preprocessor/conform.md) <sup>1</sup>|[const\_seg](../preprocessor/const-seg.md)|  
|[data\_seg](../preprocessor/data-seg.md)|[preterido](../Topic/deprecated%20\(C-C++\).md)|[detect\_mismatch](../preprocessor/detect-mismatch.md)|  
|[fenv\_access](../preprocessor/fenv-access.md)|[float\_control](../Topic/float_control.md)|[fp\_contract](../preprocessor/fp-contract.md)|  
|[function](../preprocessor/function-c-cpp.md)|[hdrstop](../preprocessor/hdrstop.md)|[include\_alias](../preprocessor/include-alias.md)|  
|[init\_seg](../preprocessor/init-seg.md) <sup>1</sup>|[inline\_depth](../preprocessor/inline-depth.md)|[inline\_recursion](../preprocessor/inline-recursion.md)|  
|[intrinsic](../preprocessor/intrinsic.md)|[loop](../preprocessor/loop.md) <sup>1</sup>|[make\_public](../preprocessor/make-public.md)|  
|[gerenciado](../preprocessor/managed-unmanaged.md)|[mensagem](../Topic/message.md)||  
|[omp](../preprocessor/omp.md)|[uma vez](../preprocessor/once.md)||  
|[optimize](../preprocessor/optimize.md)|[pack](../preprocessor/pack.md)|[pointers\_to\_members](../Topic/pointers_to_members.md) <sup>1</sup>|  
|[pop\_macro](../Topic/pop_macro.md)|[push\_macro](../preprocessor/push-macro.md)|[region, endregion](../preprocessor/region-endregion.md)|  
|[runtime\_checks](../Topic/runtime_checks.md)|[section](../preprocessor/section.md)|[setlocale](../preprocessor/setlocale.md)|  
|[strict\_gs\_check](../preprocessor/strict-gs-check.md)|[não gerenciado](../preprocessor/managed-unmanaged.md)|[vtordisp](../Topic/vtordisp.md) <sup>1</sup>|  
|[warning](../preprocessor/warning.md)|||  
  
 1.  Com suporte apenas do compilador C\+\+.  
  
## Pragmas e opções do compilador  
 Alguns pragmas oferecem a mesma funcionalidade que as opções de compilador.  Quando um pragma está localizado no código\-fonte, ele substitui o comportamento especificado pela opção do compilador.  Por exemplo, se você especificou [\/Zp8](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md), pode substituir essa configuração do compilador para seções específicas do código com [pack](../preprocessor/pack.md):  
  
```  
cl /Zp8 ...  
  
<file> - packing is 8  
// ...  
#pragma pack(push, 1) - packing is now 1  
// ...  
#pragma pack(pop) - packing is 8  
</file>  
```  
  
## A palavra\-chave \_\_pragma\(\)  
 **específica da Microsoft**  
  
 O compilador também oferece suporte à palavra\-chave `__pragma`, que tem a mesma funcionalidade que a política `#pragma`, mas que pode ser usada integrada a uma definição de macro.  A política `#pragma` não pode ser usada em uma definição de macro porque o compilador interpreta o caractere de tecla de cerquilha \("\#"\) na política para ser o [operador stringizing \(\#\)](../preprocessor/stringizing-operator-hash.md).  
  
 O exemplo de código a seguir demonstra como a palavra\-chave `__pragma` pode ser usada em uma macro.  Esse código foi retirado do cabeçalho mfcdual.h no exemplo ACDUAL em "Exemplos de suporte a COM de compilador":  
  
```  
#define CATCH_ALL_DUAL \  
CATCH(COleException, e) \  
{ \  
_hr = e->m_sc; \  
} \  
AND_CATCH_ALL(e) \  
{ \  
__pragma(warning(push)) \  
__pragma(warning(disable:6246)) /*disable _ctlState prefast warning*/ \  
AFX_MANAGE_STATE(pThis->m_pModuleState); \  
__pragma(warning(pop)) \  
_hr = DualHandleException(_riidSource, e); \  
} \  
END_CATCH_ALL \  
return _hr; \  
```  
  
 **Fim de específico da Microsoft**  
  
## Consulte também  
 [Referência de pré\-processador C\/C\+\+](../preprocessor/c-cpp-preprocessor-reference.md)   
 [C Pragmas](../c-language/c-pragmas.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)