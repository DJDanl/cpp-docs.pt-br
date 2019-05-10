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
ms.openlocfilehash: 43c7ae02e465ce8de2871d78e7ba604221aa7426
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65445907"
---
# <a name="asm"></a>__asm

**Seção específica da Microsoft**

O `__asm` palavra-chave invoca o assembler embutido e pode aparecer sempre que uma instrução C ou C++ é legal. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo "bloco `__asm`" refere-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.

> [!NOTE]
> Suporte do Visual C++ para o C++ padrão `asm` palavra-chave é limitado ao fato de que o compilador não gerará um erro sobre a palavra-chave. No entanto, um `asm` bloco não gerará nenhum código significativo. Use `__asm` em vez de `asm`.

## <a name="grammar"></a>Gramática

*asm-block*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__asm** *assembly-instruction* **;**<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**ASM {** *lista de instruções de assembly* **}** **;** <sub>otimizado</sub>

*lista de instruções de assembly*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*assembly-instruction* **;**<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*assembly-instruction* **;** *assembly-instruction-list* **;**<sub>opt</sub>

## <a name="remarks"></a>Comentários

Se usado sem chaves, o `__asm` palavra-chave significa que o resto da linha é uma instrução de linguagem de assembly. Se usado com chaves, significa que cada linha entre as chaves é uma instrução de linguagem de assembly. Para compatibilidade com versões anteriores, `_asm` é um sinônimo de `__asm`.

Uma vez que o `__asm` palavra-chave é um separador de instrução, você pode colocar instruções de assembly na mesma linha.

Antes do Visual Studio 2005, a instrução

```cpp
__asm int 3
```

código nativo a ser gerado quando compilado com não causou **/clr**; o compilador traduziu a instrução para uma instrução de interrupção de CLR.

`__asm int 3` Agora resulta na geração de código nativo para a função. Se você desejar uma função para fazer com que um ponto de interrupção em seu código e se você quiser que essa função seja compilada em MSIL, use [debugbreak](../../intrinsics/debugbreak.md).

Para compatibilidade com versões anteriores, **_asm** é um sinônimo de **ASM** , a menos que a opção de compilador [/Za \(desabilitar extensões de linguagem)](../../build/reference/za-ze-disable-language-extensions.md) for especificado.

## <a name="example"></a>Exemplo

O fragmento de código a seguir é uma simples `__asm` bloco entre chaves:

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

Porque o `__asm` palavra-chave é um separador de instrução, você também pode colocar instruções de assembly na mesma linha:

```cpp
__asm mov al, 2   __asm mov dx, 0xD007   __asm out dx, al
```

Todos os três exemplos geram o mesmo código, mas o primeiro estilo (colocando o `__asm` bloquear entre chaves) tem algumas vantagens. As chaves separar o código do assembly de código C ou C++ e evitar a repetição desnecessária de claramente o `__asm` palavra-chave. Chaves também podem evitar ambiguidades. Se você deseja colocar uma instrução C ou C++ na mesma linha como um `__asm` bloco, você deve incluir o bloco entre chaves. Sem os colchetes, o compilador não pode determinar onde código do assembly termina e instruções de C ou C++ começam. Por fim, como o texto entre chaves tem o mesmo formato de texto comum de MASM, você pode facilmente recortar e colar o texto de arquivos de origem existentes (MASM).

Ao contrário das chaves no C e C++, as chaves que incluem um `__asm` bloco não afetam o escopo da variável. Você também pode aninhar `__asm` blocos; o aninhamento não afeta o escopo da variável.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Palavras-chave](../../cpp/keywords-cpp.md)<br/>
[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>