---
title: __asm
ms.date: 10/09/2018
f1_keywords:
- __asm
- _asm
- __asm_cpp
helpviewer_keywords:
- __asm keyword [C++], vs. asm blocks
- __asm keyword [C++]
ms.assetid: 77ff3bc9-a492-4b5e-85e1-fa4e414e79cd
ms.openlocfilehash: 14a40bef5b2edba76fc130604414c45eee589bcd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192997"
---
# `__asm`

**Específico da Microsoft**

A **`__asm`** palavra-chave invoca o Assembler embutido e pode aparecer sempre que uma instrução C ou C++ for legal. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo " **`__asm`** Bloquear" refere-se a qualquer instrução ou grupo de instruções, seja ou não entre chaves.

> [!NOTE]
> Visual C++ suporte para a **`asm`** palavra-chave C++ padrão é limitado ao fato de que o compilador não irá gerar um erro na palavra-chave. No entanto, um **`asm`** bloco não gerará nenhum código significativo. Use **`__asm`** em vez de **`asm`** .

## <a name="grammar"></a>Gramática

*ASM-bloquear*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__asm`***instrução assembly* **`;`** <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__asm {`** lista de instruções de *assembly* **`}`** **`;`** <sub>aceitar</sub>

*lista de instruções de assembly*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução assembly* **`;`** <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução assembly* **`;`** lista de instruções de *assembly* **`;`** <sub>aceitar</sub>

## <a name="remarks"></a>Comentários

Se usado sem chaves, a **`__asm`** palavra-chave significa que o restante da linha é uma instrução de linguagem de assembly. Se usado com chaves, significa que cada linha entre as chaves é uma instrução de linguagem de assembly. Para compatibilidade com versões anteriores, **`_asm`** é um sinônimo do **`__asm`** .

Como a **`__asm`** palavra-chave é um separador de instrução, você pode colocar instruções de assembly na mesma linha.

Antes do Visual Studio 2005, a instrução

```cpp
__asm int 3
```

Não fazia com que o código nativo fosse gerado quando compilado com **/CLR**; o compilador converteu a instrução em uma instrução de interrupção de CLR.

`__asm int 3`Agora resulta na geração de código nativo para a função. Se você quiser que uma função cause um ponto de interrupção em seu código e se desejar que a função seja compilada para MSIL, use [__debugbreak](../../intrinsics/debugbreak.md).

Para compatibilidade com versões anteriores, **`_asm`** é um sinônimo para **`__asm`** , a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

O fragmento de código a seguir é um **`__asm`** bloco simples entre chaves:

```cpp
__asm {
   mov al, 2
   mov dx, 0xD007
   out dx, al
}
```

Como alternativa, você pode colocar **`__asm`** na frente de cada instrução de assembly:

```cpp
__asm mov al, 2
__asm mov dx, 0xD007
__asm out dx, al
```

Como a **`__asm`** palavra-chave é um separador de instrução, você também pode colocar instruções de assembly na mesma linha:

```cpp
__asm mov al, 2   __asm mov dx, 0xD007   __asm out dx, al
```

Todos os três exemplos geram o mesmo código, mas o primeiro estilo (colocar o **`__asm`** bloco entre chaves) tem algumas vantagens. As chaves claramente separam o código de assembly do código C ou C++ e evitam a repetição necessária da **`__asm`** palavra-chave. As chaves também podem impedir ambiguidades. Se você quiser colocar uma instrução C ou C++ na mesma linha de um **`__asm`** bloco, deverá colocar o bloco entre chaves. Sem as chaves, o compilador não pode determinar onde o código do assembly é interrompido e as instruções C ou C++ começam. Por fim, como o texto entre chaves tem o mesmo formato que o texto MASM comum, você pode facilmente cortar e colar texto de arquivos de origem MASM existentes.

Ao contrário das chaves em C e C++, as chaves que envolvem um **`__asm`** bloco não afetam o escopo da variável. Você também pode aninhar **`__asm`** blocos; o aninhamento não afeta o escopo da variável.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../../cpp/keywords-cpp.md)<br/>
[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
