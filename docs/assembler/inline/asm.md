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
ms.openlocfilehash: de28e4c0fad6b89a62b4479c5c32f0b8606cf3af
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169625"
---
# <a name="__asm"></a>__asm

**Seção específica da Microsoft**

A palavra-chave `__asm` invoca o Assembler embutido e pode aparecer sempre C++ que um C ou uma instrução for legal. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo "bloco `__asm`" refere-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.

> [!NOTE]
> O C++ suporte Visual para a C++ palavra-chave Standard `asm` é limitado ao fato de que o compilador não gerará um erro na palavra-chave. No entanto, um bloco de `asm` não gerará nenhum código significativo. Use `__asm` em vez de `asm`.

## <a name="grammar"></a>Gramática

*ASM-bloquear*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__asm** *de instruções de assembly* **;** <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__asm {** *assembly-Instruction-List* **}** **;** <sub>aceitar</sub>

*lista de instruções de assembly*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de assembly* **;** <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*assembly-Instruction* **;** *assembly – instrução-List* **;** <sub>aceitar</sub>

## <a name="remarks"></a>Comentários

Se usado sem chaves, a palavra-chave `__asm` significa que o restante da linha é uma instrução de linguagem de assembly. Se usado com chaves, significa que cada linha entre as chaves é uma instrução de linguagem de assembly. Para compatibilidade com versões anteriores, `_asm` é um sinônimo para `__asm`.

Como a palavra-chave `__asm` é um separador de instrução, você pode colocar instruções de assembly na mesma linha.

Antes do Visual Studio 2005, a instrução

```cpp
__asm int 3
```

Não fazia com que o código nativo fosse gerado quando compilado com **/CLR**; o compilador converteu a instrução em uma instrução de interrupção de CLR.

`__asm int 3` agora resulta na geração de código nativo para a função. Se você quiser que uma função cause um ponto de interrupção em seu código e se desejar que a função seja compilada para MSIL, use [__debugbreak](../../intrinsics/debugbreak.md).

Para compatibilidade com versões anteriores, **_asm** é um sinônimo para **__asm** , a menos que a opção de compilador [/za \(desabilitar extensões de linguagem)](../../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

O fragmento de código a seguir é um bloco de `__asm` simples entre chaves:

```cpp
__asm {
   mov al, 2
   mov dx, 0xD007
   out dx, al
}
```

Como alternativa, você pode colocar `__asm` na frente de cada instrução de assemblies:

```cpp
__asm mov al, 2
__asm mov dx, 0xD007
__asm out dx, al
```

Como a palavra-chave `__asm` é um separador de instrução, você também pode colocar instruções de assembly na mesma linha:

```cpp
__asm mov al, 2   __asm mov dx, 0xD007   __asm out dx, al
```

Todos os três exemplos geram o mesmo código, mas o primeiro estilo (delimitador o bloco de `__asm` entre chaves) tem algumas vantagens. As chaves claramente separam o código do assembly C++ do C ou do código e evitam a repetição necessária da palavra-chave `__asm`. As chaves também podem impedir ambiguidades. Se você quiser colocar um C ou C++ uma instrução na mesma linha de um bloco de `__asm`, deverá colocar o bloco entre chaves. Sem as chaves, o compilador não pode determinar onde o código do assembly é interrompido C++ , e C ou instruções começam. Por fim, como o texto entre chaves tem o mesmo formato que o texto MASM comum, você pode facilmente cortar e colar texto de arquivos de origem MASM existentes.

Ao contrário das chaves em C C++e, as chaves que envolvem um bloco de `__asm` não afetam o escopo da variável. Você também pode aninhar blocos de `__asm`; o aninhamento não afeta o escopo da variável.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../../cpp/keywords-cpp.md)<br/>
[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
