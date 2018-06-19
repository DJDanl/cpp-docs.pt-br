---
title: ASM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
f1_keywords:
- __asm
- __asm_cpp
dev_langs:
- C++
helpviewer_keywords:
- __asm keyword [C++], vs. asm blocks
- __asm keyword [C++]
ms.assetid: 77ff3bc9-a492-4b5e-85e1-fa4e414e79cd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 77e09f6af92839c6113c9c5ba375a1583bcf7149
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32052671"
---
# <a name="asm"></a>__asm
**Seção específica da Microsoft**  
  
 O `__asm` palavra-chave invoca o assembler embutido e pode aparecer sempre que uma instrução de C ou C++ é válida. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo "bloco `__asm`" refere-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.  
  
> [!NOTE]
>  Suporte do Visual C++ para o padrão C++ `asm` palavra-chave é limitada ao fato de que o compilador não irá gerar um erro, a palavra-chave. No entanto, um `asm` bloco não irá gerar qualquer código significativo. Use `__asm` em vez de `asm`.  
  
 Sintaxe:  
  
 ASM *assembly instrução* [;]  
  
 ASM { *lista de instruções de assembly* } [;]  
  
## <a name="grammar"></a>Gramática  
 `__asm`  `assembly-instruction`  `;`aceitar  
  
 `__asm {`  `assembly-instruction-list`  `};`aceitar  
  
 *lista de instruções de assembly*:  
 `assembly-instruction` `;`aceitar  
  
 `assembly-instruction` `;` `assembly-instruction-list` `;`aceitar  
  
 Se usado sem as chaves, o `__asm` palavra-chave significa que o restante da linha é uma instrução de linguagem assembly. Se usado com chaves, isso significa que cada linha entre as chaves é uma instrução de linguagem assembly. Para compatibilidade com versões anteriores, `_asm` é um sinônimo para `__asm`.  
  
 Desde o `__asm` palavra-chave é um separador de declaração, você pode colocar instruções assembly na mesma linha.  
  
 Antes de Visual C++ 2005, a instrução  
  
```  
__asm int 3  
```  
  
 não causava será gerado quando compilado com o código nativo **/clr**; o compilador convertido a instrução para uma instrução de quebra do CLR.  
  
 `__asm int 3` Agora resulta na geração de código nativo para a função. Se você deseja fazer com que um ponto de interrupção no seu código e se você desejar que essa função compilada para MSIL, use uma função [debugbreak](../../intrinsics/debugbreak.md).  
  
## <a name="example"></a>Exemplo  
 O fragmento de código a seguir é um simples `__asm` bloco entre chaves:  
  
```  
__asm {  
   mov al, 2  
   mov dx, 0xD007  
   out dx, al  
}  
```  
  
 Como alternativa, você pode colocar `__asm` na frente de cada instrução de assemblies:  
  
```  
__asm mov al, 2  
__asm mov dx, 0xD007  
__asm out dx, al  
```  
  
 Porque o `__asm` palavra-chave é um separador de declaração, você também pode colocar instruções assembly na mesma linha:  
  
```  
__asm mov al, 2   __asm mov dx, 0xD007   __asm out dx, al  
```  
  
 Todos os três exemplos geram o mesmo código, mas o primeiro estilo (colocando o `__asm` bloquear entre chaves) tem algumas vantagens. As chaves separar o código de assembly de código C ou C++ e evitar a repetição desnecessária de claramente o `__asm` palavra-chave. Chaves também podem impedir ambiguidades. Se você quiser colocar uma instrução de C ou C++ na mesma linha como um `__asm` bloco, você deverá colocar o bloco de chaves. Sem as chaves, o compilador não pode determinar onde começam a para de código de assembly e instruções C ou C++. Por fim, porque o texto entre chaves tem o mesmo formato que o texto MASM comum, você pode facilmente recortar e colar o texto existentes MASM dos arquivos de origem.  
  
 Ao contrário de chaves em C e C++, as chaves ao redor uma `__asm` bloco não afetam o escopo da variável. Você também pode aninhar `__asm` blocos; aninhamento não afeta o escopo da variável.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../../cpp/keywords-cpp.md)   
 [Assembler embutido](../../assembler/inline/inline-assembler.md)