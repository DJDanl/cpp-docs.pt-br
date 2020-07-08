---
title: /Gh (habilitar função de gancho _penter)
description: Descreve a opção de compilador/GH para chamar a função de _penter fornecida.
ms.date: 07/06/2020
f1_keywords:
- _penter
helpviewer_keywords:
- /Gh compiler option [C++]
- Gh compiler option [C++]
- _penter function
- -Gh compiler option [C++]
ms.assetid: 1510a082-8a0e-486e-a309-6add814b494f
ms.openlocfilehash: 96597d964e6a341aa25f4d52d34974949eb7b096
ms.sourcegitcommit: 85d96eeb1ce41d9e1dea947f65ded672e146238b
ms.contentlocale: pt-BR
ms.lasthandoff: 07/07/2020
ms.locfileid: "86058575"
---
# <a name="gh-enable-_penter-hook-function"></a>/Gh (habilitar função de gancho _penter)

Faz uma chamada para a `_penter` função no início de cada método ou função.

## <a name="syntax"></a>Sintaxe

> **`/Gh`**

## <a name="remarks"></a>Comentários

A `_penter` função não faz parte de nenhuma biblioteca. Cabe a você fornecer uma definição para `_penter` .

A menos que você planeje chamar explicitamente `_penter` , não precisa fornecer um protótipo. A função deve enviar por push o conteúdo de todos os registros na entrada e retirar o conteúdo inalterado na saída. Ele deve aparecer como se tivesse o seguinte protótipo:

```cpp
void __declspec(naked) __cdecl _penter( void );
```

Essa declaração não está disponível para projetos de 64 bits.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra a **Configuration Properties**página de propriedades de  >  linha de comando**C/C++** Properties  >  **Command Line** .

1. Insira a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="example"></a>Exemplo

O código a seguir, quando compilado com **/GH**, mostra como `_penter` é chamado duas vezes; uma vez ao inserir a função `main` e uma vez ao inserir a função `x` . O exemplo consiste em dois arquivos de origem, que você compila separadamente.

```cpp
// local_penter.cpp
// compile with: cl /EHsc /c local_penter.cpp
// processor: x86
#include <stdio.h>

extern "C" void __declspec(naked) __cdecl _penter( void ) {
   _asm {
      push eax
      push ebx
      push ecx
      push edx
      push ebp
      push edi
      push esi
    }

   printf_s("\nIn a function!");

   _asm {
      pop esi
      pop edi
      pop ebp
      pop edx
      pop ecx
      pop ebx
      pop eax
      ret
    }
}
```

```cpp
// Gh_compiler_option.cpp
// compile with: cl /EHsc /Gh Gh_compiler_option.cpp local_penter.obj
// processor: x86
#include <stdio.h>

void x() {}

int main() {
   x();
}
```

Quando executado, a `_penter` função local é chamada na entrada para `main` e `x` :

```Output

In a function!
In a function!
```

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[`/GH`(Habilitar função de gancho de _pexit)](gh-enable-pexit-hook-function.md)
