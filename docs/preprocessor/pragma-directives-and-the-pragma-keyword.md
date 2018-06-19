---
title: Diretivas pragma e a palavra-chave pragma | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '#pragma'
dev_langs:
- C++
helpviewer_keywords:
- '#pragma directives, C/C++'
- __pragma keyword
- pragma directives, C/C++
- pragmas, C/C++
- preprocessor
- pragmas
- preprocessor, pragmas
- pragma directives (#pragma)
ms.assetid: 9867b438-ac64-4e10-973f-c3955209873f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b20a476e1701f58782b97f986ee6c3d4b310b566
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33846227"
---
# <a name="pragma-directives-and-the-pragma-keyword"></a>Diretivas Pragma e a palavra-chave __Pragma
As políticas de pragma especificam recursos de compilador específicos do computador ou da operação. A palavra-chave `__pragma`, que é específica do compilador da Microsoft, permite codificar políticas de pragma dentro de definições de macro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      #pragma token-string  
__pragma(token-string)  
```  
  
## <a name="remarks"></a>Comentários  
 Cada implementação de C e C++ oferece suporte a alguns recursos exclusivos para seu computador host ou sistema operacional. Alguns programas, por exemplo, devem exercitar o controle preciso sobre as áreas de memória onde os dados são colocados ou para controlar a maneira como determinadas funções recebem parâmetros. As políticas `#pragma` proporcionam uma maneira para que cada compilador ofereça recursos específicos de máquinas e sistemas operacionais enquanto mantém a compatibilidade geral com as linguagens C e C++.  
  
 Os pragmas são específicos do computador ou do sistema operacional por definição e normalmente são diferentes para todos os compiladores. Os pragmas podem ser usados em instruções condicionais para fornecerem nova funcionalidade de pré-processador ou para fornecerem informações definidas pela implementação ao compilador.  
  
 `token-string` é uma série de caracteres que oferece uma instrução de compilador específica e argumentos, se houver. O sinal de número (**#**) deve ser o primeiro caractere que não esteja em branco na linha que contém o pragma; caracteres de espaço em branco pode separar o sinal de número e a palavra "pragma". Depois de `#pragma`, escreva qualquer texto que o conversor possa analisar, como tokens de pré-processamento. O argumento para `#pragma` está sujeito a uma expansão de macro.  
  
 Se o compilador encontrar um pragma que não reconhecer, ele emitirá um aviso e continuará a compilação.  
  
 Os compiladores C e C++ da Microsoft reconhecem os seguintes pragmas:  
  
||||  
|-|-|-|  
|[alloc_text](../preprocessor/alloc-text.md)|[auto_inline](../preprocessor/auto-inline.md)|[bss_seg](../preprocessor/bss-seg.md)|  
|[check_stack](../preprocessor/check-stack.md)|[code_seg](../preprocessor/code-seg.md)|[comment](../preprocessor/comment-c-cpp.md)|  
|[componente](../preprocessor/component.md)|[está de acordo com](../preprocessor/conform.md) <sup>1</sup>|[const_seg](../preprocessor/const-seg.md)|  
|[data_seg](../preprocessor/data-seg.md)|[preterido](../preprocessor/deprecated-c-cpp.md)|[detect_mismatch](../preprocessor/detect-mismatch.md)|  
|[fenv_access](../preprocessor/fenv-access.md)|[float_control](../preprocessor/float-control.md)|[fp_contract](../preprocessor/fp-contract.md)|  
|[function](../preprocessor/function-c-cpp.md)|[hdrstop](../preprocessor/hdrstop.md)|[include_alias](../preprocessor/include-alias.md)|  
|[init_seg](../preprocessor/init-seg.md) <sup>1</sup>|[inline_depth](../preprocessor/inline-depth.md)|[inline_recursion](../preprocessor/inline-recursion.md)|  
|[intrinsic](../preprocessor/intrinsic.md)|[loop](../preprocessor/loop.md) <sup>1</sup>|[make_public](../preprocessor/make-public.md)|  
|[Gerenciado](../preprocessor/managed-unmanaged.md)|[message](../preprocessor/message.md)||  
|[omp](../preprocessor/omp.md)|[uma vez](../preprocessor/once.md)||  
|[otimizar](../preprocessor/optimize.md)|[pack](../preprocessor/pack.md)|[pointers_to_members](../preprocessor/pointers-to-members.md) <sup>1</sup>|  
|[pop_macro](../preprocessor/pop-macro.md)|[push_macro](../preprocessor/push-macro.md)|[region, endregion](../preprocessor/region-endregion.md)|  
|[runtime_checks](../preprocessor/runtime-checks.md)|[seção](../preprocessor/section.md)|[setlocale](../preprocessor/setlocale.md)|  
|[strict_gs_check](../preprocessor/strict-gs-check.md)|[não gerenciado](../preprocessor/managed-unmanaged.md)|[vtordisp](../preprocessor/vtordisp.md) <sup>1</sup>|  
|[warning](../preprocessor/warning.md)|||  
  
 1. Com suporte apenas do compilador C++.  
  
## <a name="pragmas-and-compiler-options"></a>Pragmas e opções do compilador  
 Alguns pragmas oferecem a mesma funcionalidade que as opções de compilador. Quando um pragma está localizado no código-fonte, ele substitui o comportamento especificado pela opção do compilador. Por exemplo, se você especificou [/Zp8](../build/reference/zp-struct-member-alignment.md), você pode substituir essa configuração de compilador seções específicas do código com [pacote](../preprocessor/pack.md):  
  
```  
cl /Zp8 ...  
  
<file> - packing is 8  
// ...  
#pragma pack(push, 1) - packing is now 1  
// ...  
#pragma pack(pop) - packing is 8  
</file>  
```  
  
## <a name="the-pragma-keyword"></a>A palavra-chave __pragma()  
 **Específico da Microsoft**  
  
 O compilador também oferece suporte à palavra-chave `__pragma`, que tem a mesma funcionalidade que a política `#pragma`, mas que pode ser usada integrada a uma definição de macro. O `#pragma` diretiva não pode ser usada em uma definição de macro porque o compilador interpreta o caractere de sinal de número ('#') na diretiva para ser o [operador stringizing (#)](../preprocessor/stringizing-operator-hash.md).  
  
 O exemplo de código a seguir demonstra como a palavra-chave `__pragma` pode ser usada em uma macro. Esse código foi retirado do cabeçalho mfcdual.h no exemplo ACDUAL em "Exemplos de suporte a COM de compilador":  
  
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
  
 **Encerrar específicas da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Referência de pré-processador C/C++](../preprocessor/c-cpp-preprocessor-reference.md)   
 [Pragmas de C](../c-language/c-pragmas.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)